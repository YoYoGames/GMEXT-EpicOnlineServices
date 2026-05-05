#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_p2p.h>

#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>
#include <mutex>

using namespace gm::wire;
using namespace gm_structs;
using namespace gm_enums;

// ============================================================
// Internal helpers / state
// ============================================================

struct EOSAsyncCallbackContext
{
    GMFunction callback;
};

struct EOSNotifyCallbackContext
{
    GMFunction callback;
};

static EOS_HP2P eos_p2p_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetP2PInterface(p) : nullptr;
}

static EOS_ProductUserId eos_product_user_id_from_string_internal(std::string_view id)
{
    std::string v(id);
    if (v.empty()) return nullptr;
    return EOS_ProductUserId_FromString(v.c_str());
}

static std::string eos_product_user_id_to_string_internal(EOS_ProductUserId id)
{
    if (!id) return std::string();
    char buf[64] = {};
    int32_t len = (int32_t)sizeof(buf);
    if (EOS_ProductUserId_ToString(id, buf, &len) != EOS_EResult::EOS_Success)
        return std::string();
    return std::string(buf);
}

// ---- Base64 ----

static const char k_b64_chars[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static std::string base64_encode(const void* data, size_t len)
{
    const auto* src = static_cast<const uint8_t*>(data);
    std::string out;
    out.reserve(((len + 2) / 3) * 4);
    for (size_t i = 0; i < len; i += 3) {
        uint32_t b = (uint32_t)src[i] << 16;
        if (i + 1 < len) b |= (uint32_t)src[i + 1] << 8;
        if (i + 2 < len) b |= src[i + 2];
        out += k_b64_chars[(b >> 18) & 0x3f];
        out += k_b64_chars[(b >> 12) & 0x3f];
        out += (i + 1 < len) ? k_b64_chars[(b >> 6) & 0x3f] : '=';
        out += (i + 2 < len) ? k_b64_chars[b & 0x3f] : '=';
    }
    return out;
}

static std::vector<uint8_t> base64_decode(std::string_view encoded)
{
    static const int8_t lut[256] = {
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,62,-1,-1,-1,63,
        52,53,54,55,56,57,58,59,60,61,-1,-1,-1,-1,-1,-1,
        -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,
        15,16,17,18,19,20,21,22,23,24,25,-1,-1,-1,-1,-1,
        -1,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
        41,42,43,44,45,46,47,48,49,50,51,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
        -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
    };
    std::vector<uint8_t> out;
    out.reserve((encoded.size() / 4) * 3);
    uint32_t buf = 0;
    int bits = 0;
    for (char c : encoded) {
        if (c == '=') break;
        int8_t v = lut[(uint8_t)c];
        if (v < 0) continue;
        buf = (buf << 6) | (uint32_t)v;
        bits += 6;
        if (bits >= 8) {
            bits -= 8;
            out.push_back((uint8_t)(buf >> bits));
            buf &= (1u << bits) - 1u;
        }
    }
    return out;
}

// ---- Notify callback storage ----

static std::mutex g_notify_mutex;
static std::unordered_map<uint64_t, EOSNotifyCallbackContext*> g_connection_request_callbacks;
static std::unordered_map<uint64_t, EOSNotifyCallbackContext*> g_connection_established_callbacks;
static std::unordered_map<uint64_t, EOSNotifyCallbackContext*> g_connection_interrupted_callbacks;
static std::unordered_map<uint64_t, EOSNotifyCallbackContext*> g_connection_closed_callbacks;
static std::unordered_map<uint64_t, EOSNotifyCallbackContext*> g_packet_queue_full_callbacks;

// ---- SocketId helpers ----

static void eos_p2p_fill_socket_id(EOS_P2P_SocketId& out_socket, std::string_view socket_name)
{
    out_socket.ApiVersion = EOS_P2P_SOCKETID_API_LATEST;
    std::string name(socket_name);
    if (name.size() >= EOS_P2P_SOCKETID_SOCKETNAME_SIZE)
        name.resize(EOS_P2P_SOCKETID_SOCKETNAME_SIZE - 1);
    // memcpy with null-terminator
    std::fill(std::begin(out_socket.SocketName), std::end(out_socket.SocketName), '\0');
    if (!name.empty())
        std::copy(name.begin(), name.end(), out_socket.SocketName);
}

// ============================================================
// Native callbacks
// ============================================================

static void EOS_CALL eos_p2p_query_nat_type_callback_native(const EOS_P2P_OnQueryNATTypeCompleteInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicP2PQueryNATTypeCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    out.nat_type = (gm_enums::EpicNATType)data->NATType;
    ctx->callback.call(out);
    delete ctx;
}

static void EOS_CALL eos_p2p_connection_request_callback_native(const EOS_P2P_OnIncomingConnectionRequestInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSNotifyCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicP2PConnectionRequestCallbackInfo out{};
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.remote_user_id = eos_product_user_id_to_string_internal(data->RemoteUserId);
    out.socket_name = data->SocketId ? std::string(data->SocketId->SocketName) : std::string();
    ctx->callback.call(out);
}

static void EOS_CALL eos_p2p_connection_established_callback_native(const EOS_P2P_OnPeerConnectionEstablishedInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSNotifyCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicP2PConnectionEstablishedCallbackInfo out{};
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.remote_user_id = eos_product_user_id_to_string_internal(data->RemoteUserId);
    out.socket_name = data->SocketId ? std::string(data->SocketId->SocketName) : std::string();
    out.connection_type = (gm_enums::EpicConnectionEstablishedType)data->ConnectionType;
    out.network_type = (gm_enums::EpicNetworkConnectionType)data->NetworkType;
    ctx->callback.call(out);
}

static void EOS_CALL eos_p2p_connection_interrupted_callback_native(const EOS_P2P_OnPeerConnectionInterruptedInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSNotifyCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicP2PConnectionInterruptedCallbackInfo out{};
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.remote_user_id = eos_product_user_id_to_string_internal(data->RemoteUserId);
    out.socket_name = data->SocketId ? std::string(data->SocketId->SocketName) : std::string();
    ctx->callback.call(out);
}

static void EOS_CALL eos_p2p_connection_closed_callback_native(const EOS_P2P_OnRemoteConnectionClosedInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSNotifyCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicP2PConnectionClosedCallbackInfo out{};
    out.local_user_id = eos_product_user_id_to_string_internal(data->LocalUserId);
    out.remote_user_id = eos_product_user_id_to_string_internal(data->RemoteUserId);
    out.socket_name = data->SocketId ? std::string(data->SocketId->SocketName) : std::string();
    out.reason = (gm_enums::EpicConnectionClosedReason)data->Reason;
    ctx->callback.call(out);
}

static void EOS_CALL eos_p2p_packet_queue_full_callback_native(const EOS_P2P_OnIncomingPacketQueueFullInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSNotifyCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicP2PIncomingPacketQueueFullCallbackInfo out{};
    out.packet_queue_max_size_bytes = (int64_t)data->PacketQueueMaxSizeBytes;
    out.packet_queue_current_size_bytes = (int64_t)data->PacketQueueCurrentSizeBytes;
    out.overflow_packet_local_user_id = eos_product_user_id_to_string_internal(data->OverflowPacketLocalUserId);
    out.overflow_packet_channel = (int64_t)data->OverflowPacketChannel;
    out.overflow_packet_size_bytes = (int64_t)data->OverflowPacketSizeBytes;
    ctx->callback.call(out);
}

// ============================================================
// EOS P2P — Packet send/receive
// ============================================================

gm_enums::EpicResult eos_p2p_send_packet(
    std::string_view local_user_id,
    std::string_view remote_user_id,
    std::string_view socket_name,
    int64_t channel,
    std::string_view data,
    bool allow_delayed_delivery,
    gm_enums::EpicPacketReliability reliability,
    bool disable_auto_accept_connection)
{
    EOS_GUARD_RET((gm_enums::EpicResult)EOS_EResult::EOS_InvalidState);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) {
        eos_set_last_error("EOS P2P interface unavailable.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidState;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    EOS_ProductUserId remote_user = eos_product_user_id_from_string_internal(remote_user_id);

    if (!local_user || !remote_user) {
        eos_set_last_error("EOS_P2P_SendPacket: invalid user id.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::vector<uint8_t> packet_data = base64_decode(data);

    EOS_P2P_SocketId socket_id{};
    eos_p2p_fill_socket_id(socket_id, socket_name);

    EOS_P2P_SendPacketOptions opts{};
    opts.ApiVersion = EOS_P2P_SENDPACKET_API_LATEST;
    opts.LocalUserId = local_user;
    opts.RemoteUserId = remote_user;
    opts.SocketId = &socket_id;
    opts.Channel = (uint8_t)(channel & 0xFF);
    opts.DataLengthBytes = (uint32_t)packet_data.size();
    opts.Data = packet_data.empty() ? nullptr : packet_data.data();
    opts.bAllowDelayedDelivery = allow_delayed_delivery ? EOS_TRUE : EOS_FALSE;
    opts.Reliability = (EOS_EPacketReliability)reliability;
    opts.bDisableAutoAcceptConnection = disable_auto_accept_connection ? EOS_TRUE : EOS_FALSE;

    EOS_EResult result = EOS_P2P_SendPacket(p2p, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_P2P_SendPacket failed.");
    }
    return (gm_enums::EpicResult)result;
}

int64_t eos_p2p_get_next_received_packet_size(std::string_view local_user_id, int64_t channel)
{
    EOS_GUARD_RET(-1);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) {
        eos_set_last_error("EOS P2P interface unavailable.");
        return -1;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_P2P_GetNextReceivedPacketSize: invalid local_user_id.");
        return -1;
    }

    uint8_t channel_val = (uint8_t)(channel & 0xFF);
    const uint8_t* channel_ptr = (channel >= 0 && channel <= 255) ? &channel_val : nullptr;

    EOS_P2P_GetNextReceivedPacketSizeOptions opts{};
    opts.ApiVersion = EOS_P2P_GETNEXTRECEIVEDPACKETSIZE_API_LATEST;
    opts.LocalUserId = local_user;
    opts.RequestedChannel = channel_ptr;

    uint32_t out_size = 0;
    EOS_EResult result = EOS_P2P_GetNextReceivedPacketSize(p2p, &opts, &out_size);
    if (result == EOS_EResult::EOS_NotFound)
        return -1;
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_P2P_GetNextReceivedPacketSize failed.");
        return -1;
    }
    return (int64_t)out_size;
}

gm_structs::EpicP2PReceivedPacket eos_p2p_receive_packet(
    std::string_view local_user_id,
    int64_t max_data_size_bytes,
    int64_t channel)
{
    gm_structs::EpicP2PReceivedPacket out{};
    EOS_GUARD_RET(out);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) {
        eos_set_last_error("EOS P2P interface unavailable.");
        return out;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_P2P_ReceivePacket: invalid local_user_id.");
        return out;
    }

    uint8_t channel_val = (uint8_t)(channel & 0xFF);
    const uint8_t* channel_ptr = (channel >= 0 && channel <= 255) ? &channel_val : nullptr;

    if (max_data_size_bytes <= 0)
        max_data_size_bytes = EOS_P2P_MAX_PACKET_SIZE;

    std::vector<uint8_t> buf((size_t)max_data_size_bytes);

    EOS_P2P_ReceivePacketOptions opts{};
    opts.ApiVersion = EOS_P2P_RECEIVEPACKET_API_LATEST;
    opts.LocalUserId = local_user;
    opts.MaxDataSizeBytes = (uint32_t)max_data_size_bytes;
    opts.RequestedChannel = channel_ptr;

    EOS_ProductUserId peer_id = nullptr;
    EOS_P2P_SocketId socket_id{};
    uint8_t out_channel = 0;
    uint32_t bytes_written = 0;

    EOS_EResult result = EOS_P2P_ReceivePacket(p2p, &opts, &peer_id, &socket_id, &out_channel, buf.data(), &bytes_written);
    if (result == EOS_EResult::EOS_NotFound)
        return out;
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_P2P_ReceivePacket failed.");
        return out;
    }

    out.peer_id = eos_product_user_id_to_string_internal(peer_id);
    out.socket_name = std::string(socket_id.SocketName);
    out.channel = (int64_t)out_channel;
    out.data = base64_encode(buf.data(), (size_t)bytes_written);
    out.bytes_written = (int64_t)bytes_written;
    return out;
}

// ============================================================
// EOS P2P — Connection management
// ============================================================

gm_enums::EpicResult eos_p2p_accept_connection(
    std::string_view local_user_id,
    std::string_view remote_user_id,
    std::string_view socket_name)
{
    EOS_GUARD_RET((gm_enums::EpicResult)EOS_EResult::EOS_InvalidState);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) {
        eos_set_last_error("EOS P2P interface unavailable.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidState;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    EOS_ProductUserId remote_user = eos_product_user_id_from_string_internal(remote_user_id);
    if (!local_user || !remote_user) {
        eos_set_last_error("EOS_P2P_AcceptConnection: invalid user id.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_P2P_SocketId socket_id{};
    eos_p2p_fill_socket_id(socket_id, socket_name);

    EOS_P2P_AcceptConnectionOptions opts{};
    opts.ApiVersion = EOS_P2P_ACCEPTCONNECTION_API_LATEST;
    opts.LocalUserId = local_user;
    opts.RemoteUserId = remote_user;
    opts.SocketId = &socket_id;

    EOS_EResult result = EOS_P2P_AcceptConnection(p2p, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_P2P_AcceptConnection failed.");
    }
    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_p2p_close_connection(
    std::string_view local_user_id,
    std::string_view remote_user_id,
    std::string_view socket_name)
{
    EOS_GUARD_RET((gm_enums::EpicResult)EOS_EResult::EOS_InvalidState);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) {
        eos_set_last_error("EOS P2P interface unavailable.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidState;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    EOS_ProductUserId remote_user = eos_product_user_id_from_string_internal(remote_user_id);
    if (!local_user || !remote_user) {
        eos_set_last_error("EOS_P2P_CloseConnection: invalid user id.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_P2P_SocketId socket_id{};
    eos_p2p_fill_socket_id(socket_id, socket_name);

    EOS_P2P_CloseConnectionOptions opts{};
    opts.ApiVersion = EOS_P2P_CLOSECONNECTION_API_LATEST;
    opts.LocalUserId = local_user;
    opts.RemoteUserId = remote_user;
    opts.SocketId = socket_name.empty() ? nullptr : &socket_id;

    EOS_EResult result = EOS_P2P_CloseConnection(p2p, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_P2P_CloseConnection failed.");
    }
    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_p2p_close_connections(std::string_view local_user_id, std::string_view socket_name)
{
    EOS_GUARD_RET((gm_enums::EpicResult)EOS_EResult::EOS_InvalidState);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) {
        eos_set_last_error("EOS P2P interface unavailable.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidState;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_P2P_CloseConnections: invalid local_user_id.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_P2P_SocketId socket_id{};
    eos_p2p_fill_socket_id(socket_id, socket_name);

    EOS_P2P_CloseConnectionsOptions opts{};
    opts.ApiVersion = EOS_P2P_CLOSECONNECTIONS_API_LATEST;
    opts.LocalUserId = local_user;
    opts.SocketId = &socket_id;

    EOS_EResult result = EOS_P2P_CloseConnections(p2p, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_P2P_CloseConnections failed.");
    }
    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_p2p_clear_packet_queue(
    std::string_view local_user_id,
    std::string_view remote_user_id,
    std::string_view socket_name)
{
    EOS_GUARD_RET((gm_enums::EpicResult)EOS_EResult::EOS_InvalidState);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) {
        eos_set_last_error("EOS P2P interface unavailable.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidState;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    EOS_ProductUserId remote_user = eos_product_user_id_from_string_internal(remote_user_id);
    if (!local_user || !remote_user) {
        eos_set_last_error("EOS_P2P_ClearPacketQueue: invalid user id.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_P2P_SocketId socket_id{};
    eos_p2p_fill_socket_id(socket_id, socket_name);

    EOS_P2P_ClearPacketQueueOptions opts{};
    opts.ApiVersion = EOS_P2P_CLEARPACKETQUEUE_API_LATEST;
    opts.LocalUserId = local_user;
    opts.RemoteUserId = remote_user;
    opts.SocketId = &socket_id;

    EOS_EResult result = EOS_P2P_ClearPacketQueue(p2p, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_P2P_ClearPacketQueue failed.");
    }
    return (gm_enums::EpicResult)result;
}

// ============================================================
// EOS P2P — NAT type
// ============================================================

void eos_p2p_query_nat_type(const GMFunction& callback)
{
    EOS_GUARD();

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) {
        eos_set_last_error("EOS P2P interface unavailable.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_P2P_QueryNATTypeOptions opts{};
    opts.ApiVersion = EOS_P2P_QUERYNATTYPE_API_LATEST;

    EOS_P2P_QueryNATType(p2p, &opts, ctx, &eos_p2p_query_nat_type_callback_native);
}

gm_enums::EpicNATType eos_p2p_get_nat_type()
{
    EOS_GUARD_RET((gm_enums::EpicNATType)EOS_ENATType::EOS_NAT_Unknown);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) {
        eos_set_last_error("EOS P2P interface unavailable.");
        return (gm_enums::EpicNATType)EOS_ENATType::EOS_NAT_Unknown;
    }

    EOS_P2P_GetNATTypeOptions opts{};
    opts.ApiVersion = EOS_P2P_GETNATTYPE_API_LATEST;

    EOS_ENATType nat_type = EOS_ENATType::EOS_NAT_Unknown;
    EOS_EResult result = EOS_P2P_GetNATType(p2p, &opts, &nat_type);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_P2P_GetNATType failed.");
    }
    return (gm_enums::EpicNATType)nat_type;
}

// ============================================================
// EOS P2P — Relay control
// ============================================================

gm_enums::EpicResult eos_p2p_set_relay_control(gm_enums::EpicRelayControl relay_control)
{
    EOS_GUARD_RET((gm_enums::EpicResult)EOS_EResult::EOS_InvalidState);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) {
        eos_set_last_error("EOS P2P interface unavailable.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidState;
    }

    EOS_P2P_SetRelayControlOptions opts{};
    opts.ApiVersion = EOS_P2P_SETRELAYCONTROL_API_LATEST;
    opts.RelayControl = (EOS_ERelayControl)relay_control;

    EOS_EResult result = EOS_P2P_SetRelayControl(p2p, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_P2P_SetRelayControl failed.");
    }
    return (gm_enums::EpicResult)result;
}

gm_enums::EpicRelayControl eos_p2p_get_relay_control()
{
    EOS_GUARD_RET((gm_enums::EpicRelayControl)EOS_ERelayControl::EOS_RC_AllowRelays);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) {
        eos_set_last_error("EOS P2P interface unavailable.");
        return (gm_enums::EpicRelayControl)EOS_ERelayControl::EOS_RC_AllowRelays;
    }

    EOS_P2P_GetRelayControlOptions opts{};
    opts.ApiVersion = EOS_P2P_GETRELAYCONTROL_API_LATEST;

    EOS_ERelayControl relay = EOS_ERelayControl::EOS_RC_AllowRelays;
    EOS_EResult result = EOS_P2P_GetRelayControl(p2p, &opts, &relay);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_P2P_GetRelayControl failed.");
    }
    return (gm_enums::EpicRelayControl)relay;
}

// ============================================================
// EOS P2P — Port range
// ============================================================

gm_enums::EpicResult eos_p2p_set_port_range(int64_t port, int64_t max_additional_ports_to_try)
{
    EOS_GUARD_RET((gm_enums::EpicResult)EOS_EResult::EOS_InvalidState);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) {
        eos_set_last_error("EOS P2P interface unavailable.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidState;
    }

    EOS_P2P_SetPortRangeOptions opts{};
    opts.ApiVersion = EOS_P2P_SETPORTRANGE_API_LATEST;
    opts.Port = (uint16_t)(port & 0xFFFF);
    opts.MaxAdditionalPortsToTry = (uint16_t)(max_additional_ports_to_try & 0xFFFF);

    EOS_EResult result = EOS_P2P_SetPortRange(p2p, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_P2P_SetPortRange failed.");
    }
    return (gm_enums::EpicResult)result;
}

gm_structs::EpicP2PPortRange eos_p2p_get_port_range()
{
    gm_structs::EpicP2PPortRange out{};
    EOS_GUARD_RET(out);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) {
        eos_set_last_error("EOS P2P interface unavailable.");
        return out;
    }

    EOS_P2P_GetPortRangeOptions opts{};
    opts.ApiVersion = EOS_P2P_GETPORTRANGE_API_LATEST;

    uint16_t out_port = 0;
    uint16_t out_additional = 0;
    EOS_EResult result = EOS_P2P_GetPortRange(p2p, &opts, &out_port, &out_additional);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_P2P_GetPortRange failed.");
        return out;
    }
    out.port = (int64_t)out_port;
    out.num_additional_ports_to_try = (int64_t)out_additional;
    return out;
}

// ============================================================
// EOS P2P — Packet queue size
// ============================================================

gm_enums::EpicResult eos_p2p_set_packet_queue_size(int64_t incoming_max_bytes, int64_t outgoing_max_bytes)
{
    EOS_GUARD_RET((gm_enums::EpicResult)EOS_EResult::EOS_InvalidState);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) {
        eos_set_last_error("EOS P2P interface unavailable.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidState;
    }

    EOS_P2P_SetPacketQueueSizeOptions opts{};
    opts.ApiVersion = EOS_P2P_SETPACKETQUEUESIZE_API_LATEST;
    opts.IncomingPacketQueueMaxSizeBytes = (uint64_t)incoming_max_bytes;
    opts.OutgoingPacketQueueMaxSizeBytes = (uint64_t)outgoing_max_bytes;

    EOS_EResult result = EOS_P2P_SetPacketQueueSize(p2p, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_P2P_SetPacketQueueSize failed.");
    }
    return (gm_enums::EpicResult)result;
}

gm_structs::EpicP2PPacketQueueInfo eos_p2p_get_packet_queue_info()
{
    gm_structs::EpicP2PPacketQueueInfo out{};
    EOS_GUARD_RET(out);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) {
        eos_set_last_error("EOS P2P interface unavailable.");
        return out;
    }

    EOS_P2P_GetPacketQueueInfoOptions opts{};
    opts.ApiVersion = EOS_P2P_GETPACKETQUEUEINFO_API_LATEST;

    EOS_P2P_PacketQueueInfo info{};
    EOS_EResult result = EOS_P2P_GetPacketQueueInfo(p2p, &opts, &info);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_P2P_GetPacketQueueInfo failed.");
        return out;
    }
    out.incoming_packet_queue_max_size_bytes = (int64_t)info.IncomingPacketQueueMaxSizeBytes;
    out.incoming_packet_queue_current_size_bytes = (int64_t)info.IncomingPacketQueueCurrentSizeBytes;
    out.incoming_packet_queue_current_packet_count = (int64_t)info.IncomingPacketQueueCurrentPacketCount;
    out.outgoing_packet_queue_max_size_bytes = (int64_t)info.OutgoingPacketQueueMaxSizeBytes;
    out.outgoing_packet_queue_current_size_bytes = (int64_t)info.OutgoingPacketQueueCurrentSizeBytes;
    out.outgoing_packet_queue_current_packet_count = (int64_t)info.OutgoingPacketQueueCurrentPacketCount;
    return out;
}

// ============================================================
// EOS P2P — Notifications
// ============================================================

uint64_t eos_p2p_add_notify_peer_connection_request(
    std::string_view local_user_id,
    std::string_view socket_name,
    const GMFunction& callback)
{
    EOS_GUARD_RET(0);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) {
        eos_set_last_error("EOS P2P interface unavailable.");
        return 0;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_P2P_AddNotifyPeerConnectionRequest: invalid local_user_id.");
        return 0;
    }

    EOS_P2P_SocketId socket_id{};
    eos_p2p_fill_socket_id(socket_id, socket_name);

    auto* ctx = new EOSNotifyCallbackContext{callback};

    EOS_P2P_AddNotifyPeerConnectionRequestOptions opts{};
    opts.ApiVersion = EOS_P2P_ADDNOTIFYPEERCONNECTIONREQUEST_API_LATEST;
    opts.LocalUserId = local_user;
    opts.SocketId = socket_name.empty() ? nullptr : &socket_id;

    EOS_NotificationId id = EOS_P2P_AddNotifyPeerConnectionRequest(
        p2p, &opts, ctx, &eos_p2p_connection_request_callback_native);

    if (id == EOS_INVALID_NOTIFICATIONID) {
        delete ctx;
        eos_set_last_error("EOS_P2P_AddNotifyPeerConnectionRequest returned invalid ID.");
        return 0;
    }

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    g_connection_request_callbacks[(uint64_t)id] = ctx;
    return (uint64_t)id;
}

void eos_p2p_remove_notify_peer_connection_request(uint64_t notification_id)
{
    EOS_GUARD();

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) { eos_set_last_error("EOS P2P interface unavailable."); return; }

    EOS_P2P_RemoveNotifyPeerConnectionRequest(p2p, (EOS_NotificationId)notification_id);

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    auto it = g_connection_request_callbacks.find(notification_id);
    if (it != g_connection_request_callbacks.end()) {
        delete it->second;
        g_connection_request_callbacks.erase(it);
    }
}

uint64_t eos_p2p_add_notify_peer_connection_established(
    std::string_view local_user_id,
    std::string_view socket_name,
    const GMFunction& callback)
{
    EOS_GUARD_RET(0);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) { eos_set_last_error("EOS P2P interface unavailable."); return 0; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_P2P_AddNotifyPeerConnectionEstablished: invalid local_user_id.");
        return 0;
    }

    EOS_P2P_SocketId socket_id{};
    eos_p2p_fill_socket_id(socket_id, socket_name);

    auto* ctx = new EOSNotifyCallbackContext{callback};

    EOS_P2P_AddNotifyPeerConnectionEstablishedOptions opts{};
    opts.ApiVersion = EOS_P2P_ADDNOTIFYPEERCONNECTIONESTABLISHED_API_LATEST;
    opts.LocalUserId = local_user;
    opts.SocketId = socket_name.empty() ? nullptr : &socket_id;

    EOS_NotificationId id = EOS_P2P_AddNotifyPeerConnectionEstablished(
        p2p, &opts, ctx, &eos_p2p_connection_established_callback_native);

    if (id == EOS_INVALID_NOTIFICATIONID) {
        delete ctx;
        eos_set_last_error("EOS_P2P_AddNotifyPeerConnectionEstablished returned invalid ID.");
        return 0;
    }

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    g_connection_established_callbacks[(uint64_t)id] = ctx;
    return (uint64_t)id;
}

void eos_p2p_remove_notify_peer_connection_established(uint64_t notification_id)
{
    EOS_GUARD();

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) { eos_set_last_error("EOS P2P interface unavailable."); return; }

    EOS_P2P_RemoveNotifyPeerConnectionEstablished(p2p, (EOS_NotificationId)notification_id);

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    auto it = g_connection_established_callbacks.find(notification_id);
    if (it != g_connection_established_callbacks.end()) {
        delete it->second;
        g_connection_established_callbacks.erase(it);
    }
}

uint64_t eos_p2p_add_notify_peer_connection_interrupted(
    std::string_view local_user_id,
    std::string_view socket_name,
    const GMFunction& callback)
{
    EOS_GUARD_RET(0);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) { eos_set_last_error("EOS P2P interface unavailable."); return 0; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_P2P_AddNotifyPeerConnectionInterrupted: invalid local_user_id.");
        return 0;
    }

    EOS_P2P_SocketId socket_id{};
    eos_p2p_fill_socket_id(socket_id, socket_name);

    auto* ctx = new EOSNotifyCallbackContext{callback};

    EOS_P2P_AddNotifyPeerConnectionInterruptedOptions opts{};
    opts.ApiVersion = EOS_P2P_ADDNOTIFYPEERCONNECTIONINTERRUPTED_API_LATEST;
    opts.LocalUserId = local_user;
    opts.SocketId = socket_name.empty() ? nullptr : &socket_id;

    EOS_NotificationId id = EOS_P2P_AddNotifyPeerConnectionInterrupted(
        p2p, &opts, ctx, &eos_p2p_connection_interrupted_callback_native);

    if (id == EOS_INVALID_NOTIFICATIONID) {
        delete ctx;
        eos_set_last_error("EOS_P2P_AddNotifyPeerConnectionInterrupted returned invalid ID.");
        return 0;
    }

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    g_connection_interrupted_callbacks[(uint64_t)id] = ctx;
    return (uint64_t)id;
}

void eos_p2p_remove_notify_peer_connection_interrupted(uint64_t notification_id)
{
    EOS_GUARD();

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) { eos_set_last_error("EOS P2P interface unavailable."); return; }

    EOS_P2P_RemoveNotifyPeerConnectionInterrupted(p2p, (EOS_NotificationId)notification_id);

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    auto it = g_connection_interrupted_callbacks.find(notification_id);
    if (it != g_connection_interrupted_callbacks.end()) {
        delete it->second;
        g_connection_interrupted_callbacks.erase(it);
    }
}

uint64_t eos_p2p_add_notify_peer_connection_closed(
    std::string_view local_user_id,
    std::string_view socket_name,
    const GMFunction& callback)
{
    EOS_GUARD_RET(0);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) { eos_set_last_error("EOS P2P interface unavailable."); return 0; }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_P2P_AddNotifyPeerConnectionClosed: invalid local_user_id.");
        return 0;
    }

    EOS_P2P_SocketId socket_id{};
    eos_p2p_fill_socket_id(socket_id, socket_name);

    auto* ctx = new EOSNotifyCallbackContext{callback};

    EOS_P2P_AddNotifyPeerConnectionClosedOptions opts{};
    opts.ApiVersion = EOS_P2P_ADDNOTIFYPEERCONNECTIONCLOSED_API_LATEST;
    opts.LocalUserId = local_user;
    opts.SocketId = socket_name.empty() ? nullptr : &socket_id;

    EOS_NotificationId id = EOS_P2P_AddNotifyPeerConnectionClosed(
        p2p, &opts, ctx, &eos_p2p_connection_closed_callback_native);

    if (id == EOS_INVALID_NOTIFICATIONID) {
        delete ctx;
        eos_set_last_error("EOS_P2P_AddNotifyPeerConnectionClosed returned invalid ID.");
        return 0;
    }

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    g_connection_closed_callbacks[(uint64_t)id] = ctx;
    return (uint64_t)id;
}

void eos_p2p_remove_notify_peer_connection_closed(uint64_t notification_id)
{
    EOS_GUARD();

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) { eos_set_last_error("EOS P2P interface unavailable."); return; }

    EOS_P2P_RemoveNotifyPeerConnectionClosed(p2p, (EOS_NotificationId)notification_id);

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    auto it = g_connection_closed_callbacks.find(notification_id);
    if (it != g_connection_closed_callbacks.end()) {
        delete it->second;
        g_connection_closed_callbacks.erase(it);
    }
}

uint64_t eos_p2p_add_notify_incoming_packet_queue_full(const GMFunction& callback)
{
    EOS_GUARD_RET(0);

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) { eos_set_last_error("EOS P2P interface unavailable."); return 0; }

    auto* ctx = new EOSNotifyCallbackContext{callback};

    EOS_P2P_AddNotifyIncomingPacketQueueFullOptions opts{};
    opts.ApiVersion = EOS_P2P_ADDNOTIFYINCOMINGPACKETQUEUEFULL_API_LATEST;

    EOS_NotificationId id = EOS_P2P_AddNotifyIncomingPacketQueueFull(
        p2p, &opts, ctx, &eos_p2p_packet_queue_full_callback_native);

    if (id == EOS_INVALID_NOTIFICATIONID) {
        delete ctx;
        eos_set_last_error("EOS_P2P_AddNotifyIncomingPacketQueueFull returned invalid ID.");
        return 0;
    }

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    g_packet_queue_full_callbacks[(uint64_t)id] = ctx;
    return (uint64_t)id;
}

void eos_p2p_remove_notify_incoming_packet_queue_full(uint64_t notification_id)
{
    EOS_GUARD();

    EOS_HP2P p2p = eos_p2p_iface();
    if (!p2p) { eos_set_last_error("EOS P2P interface unavailable."); return; }

    EOS_P2P_RemoveNotifyIncomingPacketQueueFull(p2p, (EOS_NotificationId)notification_id);

    std::lock_guard<std::mutex> lock(g_notify_mutex);
    auto it = g_packet_queue_full_callbacks.find(notification_id);
    if (it != g_packet_queue_full_callbacks.end()) {
        delete it->second;
        g_packet_queue_full_callbacks.erase(it);
    }
}
