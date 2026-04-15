#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_lobby.h>

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

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

static EOS_HLobby eos_lobby_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetLobbyInterface(p) : nullptr;
}

template <typename Fn>
static std::string eos_lobby_copy_string_with_fixed_retry(Fn&& call_fn, size_t initial_capacity = 256)
{
    std::vector<char> buffer(initial_capacity, '\0');
    int32_t length = (int32_t)buffer.size();

    EOS_EResult result = call_fn(buffer.data(), &length);
    if (result == EOS_EResult::EOS_LimitExceeded && length > 0)
    {
        buffer.assign((size_t)length, '\0');
        result = call_fn(buffer.data(), &length);
    }

    if (result != EOS_EResult::EOS_Success)
        return std::string();

    return std::string(buffer.data());
}

static EOS_ProductUserId eos_product_user_id_from_string_internal(std::string_view product_user_id)
{
    std::string value(product_user_id);
    if (value.empty())
        return nullptr;
    return EOS_ProductUserId_FromString(value.c_str());
}

static std::string eos_product_user_id_to_string_internal(EOS_ProductUserId product_user_id)
{
    if (!product_user_id)
        return std::string();

    return eos_lobby_copy_string_with_fixed_retry(
        [&](char* out_buffer, int32_t* inout_len) -> EOS_EResult
        {
            return EOS_ProductUserId_ToString(product_user_id, out_buffer, inout_len);
        });
}

static gm_structs::EpicLobbyCreateLobbyCallbackInfo eos_lobby_create_lobby_info_from_native(
    const EOS_Lobby_CreateLobbyCallbackInfo* p)
{
    gm_structs::EpicLobbyCreateLobbyCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.lobby_id = p->LobbyId ? std::string(p->LobbyId) : std::string();
    return out;
}

static gm_structs::EpicLobbyDestroyLobbyCallbackInfo eos_lobby_destroy_lobby_info_from_native(
    const EOS_Lobby_DestroyLobbyCallbackInfo* p)
{
    gm_structs::EpicLobbyDestroyLobbyCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.lobby_id = p->LobbyId ? std::string(p->LobbyId) : std::string();
    return out;
}

static gm_structs::EpicLobbyJoinLobbyCallbackInfo eos_lobby_join_lobby_info_from_native(
    const EOS_Lobby_JoinLobbyCallbackInfo* p)
{
    gm_structs::EpicLobbyJoinLobbyCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.lobby_id = p->LobbyId ? std::string(p->LobbyId) : std::string();
    return out;
}

static gm_structs::EpicLobbyLeaveLobbyCallbackInfo eos_lobby_leave_lobby_info_from_native(
    const EOS_Lobby_LeaveLobbyCallbackInfo* p)
{
    gm_structs::EpicLobbyLeaveLobbyCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.lobby_id = p->LobbyId ? std::string(p->LobbyId) : std::string();
    return out;
}

static void EOS_CALL eos_lobby_create_lobby_callback_native(
    const EOS_Lobby_CreateLobbyCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_lobby_create_lobby_info_from_native(data)
    );
    delete ctx;
}

static void EOS_CALL eos_lobby_destroy_lobby_callback_native(
    const EOS_Lobby_DestroyLobbyCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_lobby_destroy_lobby_info_from_native(data)
    );
    delete ctx;
}

static void EOS_CALL eos_lobby_join_lobby_callback_native(
    const EOS_Lobby_JoinLobbyCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_lobby_join_lobby_info_from_native(data)
    );
    delete ctx;
}

static void EOS_CALL eos_lobby_leave_lobby_callback_native(
    const EOS_Lobby_LeaveLobbyCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_lobby_leave_lobby_info_from_native(data)
    );
    delete ctx;
}

// ============================================================
// EOS Lobby (Part 1)
// ============================================================

void eos_lobby_create_lobby(
    std::string_view local_user_id,
    int64_t max_lobby_members,
    gm_enums::EpicLobbyPermissionLevel permission_level,
    bool presence_enabled,
    bool allow_invites,
    std::string_view bucket_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Lobby_CreateLobby: invalid local_user_id.");
        return;
    }

    std::string bucket_id_storage(bucket_id);

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Lobby_CreateLobbyOptions opts{};
    opts.ApiVersion = EOS_LOBBY_CREATELOBBY_API_LATEST;
    opts.LocalUserId = local_user;
    opts.MaxLobbyMembers = (uint32_t)max_lobby_members;
    opts.PermissionLevel = (EOS_ELobbyPermissionLevel)permission_level;
    opts.bPresenceEnabled = presence_enabled ? EOS_TRUE : EOS_FALSE;
    opts.bAllowInvites = allow_invites ? EOS_TRUE : EOS_FALSE;
    opts.BucketId = bucket_id_storage.empty() ? nullptr : bucket_id_storage.c_str();

    EOS_Lobby_CreateLobby(
        lobby,
        &opts,
        ctx,
        &eos_lobby_create_lobby_callback_native
    );
}

void eos_lobby_destroy_lobby(
    std::string_view lobby_id,
    std::string_view local_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return;
    }

    std::string lobby_id_storage(lobby_id);
    if (lobby_id_storage.empty()) {
        eos_set_last_error("EOS_Lobby_DestroyLobby: lobby_id is required.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Lobby_DestroyLobby: invalid local_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Lobby_DestroyLobbyOptions opts{};
    opts.ApiVersion = EOS_LOBBY_DESTROYLOBBY_API_LATEST;
    opts.LobbyId = lobby_id_storage.c_str();
    opts.LocalUserId = local_user;

    EOS_Lobby_DestroyLobby(
        lobby,
        &opts,
        ctx,
        &eos_lobby_destroy_lobby_callback_native
    );
}

void eos_lobby_join_lobby(
    std::string_view lobby_id,
    std::string_view local_user_id,
    bool presence_enabled,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return;
    }

    std::string lobby_id_storage(lobby_id);
    if (lobby_id_storage.empty()) {
        eos_set_last_error("EOS_Lobby_JoinLobby: lobby_id is required.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Lobby_JoinLobby: invalid local_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Lobby_JoinLobbyOptions opts{};
    opts.ApiVersion = EOS_LOBBY_JOINLOBBY_API_LATEST;
    //TODO
    // opts.LobbyId = lobby_id_storage.c_str();
    opts.LocalUserId = local_user;
    opts.bPresenceEnabled = presence_enabled ? EOS_TRUE : EOS_FALSE;
    opts.bCrossplayOptOut = EOS_FALSE;

    EOS_Lobby_JoinLobby(
        lobby,
        &opts,
        ctx,
        &eos_lobby_join_lobby_callback_native
    );
}

void eos_lobby_leave_lobby(
    std::string_view lobby_id,
    std::string_view local_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return;
    }

    std::string lobby_id_storage(lobby_id);
    if (lobby_id_storage.empty()) {
        eos_set_last_error("EOS_Lobby_LeaveLobby: lobby_id is required.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Lobby_LeaveLobby: invalid local_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Lobby_LeaveLobbyOptions opts{};
    opts.ApiVersion = EOS_LOBBY_LEAVELOBBY_API_LATEST;
    opts.LobbyId = lobby_id_storage.c_str();
    opts.LocalUserId = local_user;

    EOS_Lobby_LeaveLobby(
        lobby,
        &opts,
        ctx,
        &eos_lobby_leave_lobby_callback_native
    );
}

// ============================================================
// EOS Lobby (Part 2)
// ============================================================

#include <unordered_map>

static std::unordered_map<uint64_t, EOS_HLobbyModification> g_lobby_modifications;
static uint64_t g_next_lobby_modification_id = 1;

static EOS_HLobbyModification eos_lobby_modification_get(uint64_t id)
{
    auto it = g_lobby_modifications.find(id);
    if (it == g_lobby_modifications.end())
        return nullptr;
    return it->second;
}

static uint64_t eos_lobby_modification_store(EOS_HLobbyModification mod)
{
    const uint64_t id = g_next_lobby_modification_id++;
    g_lobby_modifications[id] = mod;
    return id;
}

static void eos_lobby_modification_erase(uint64_t id)
{
    auto it = g_lobby_modifications.find(id);
    if (it == g_lobby_modifications.end())
        return;

    if (it->second)
        EOS_LobbyModification_Release(it->second);

    g_lobby_modifications.erase(it);
}

static gm_structs::EpicLobbyUpdateLobbyCallbackInfo eos_lobby_update_lobby_info_from_native(
    const EOS_Lobby_UpdateLobbyCallbackInfo* p)
{
    gm_structs::EpicLobbyUpdateLobbyCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.lobby_id = p->LobbyId ? std::string(p->LobbyId) : std::string();
    return out;
}

static gm_structs::EpicLobbyPromoteMemberCallbackInfo eos_lobby_promote_member_info_from_native(
    const EOS_Lobby_PromoteMemberCallbackInfo* p)
{
    gm_structs::EpicLobbyPromoteMemberCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.lobby_id = p->LobbyId ? std::string(p->LobbyId) : std::string();
    return out;
}

static gm_structs::EpicLobbyKickMemberCallbackInfo eos_lobby_kick_member_info_from_native(
    const EOS_Lobby_KickMemberCallbackInfo* p)
{
    gm_structs::EpicLobbyKickMemberCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.lobby_id = p->LobbyId ? std::string(p->LobbyId) : std::string();
    return out;
}

static void EOS_CALL eos_lobby_update_lobby_callback_native(
    const EOS_Lobby_UpdateLobbyCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_lobby_update_lobby_info_from_native(data)
    );
    delete ctx;
}

static void EOS_CALL eos_lobby_promote_member_callback_native(
    const EOS_Lobby_PromoteMemberCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_lobby_promote_member_info_from_native(data)
    );
    delete ctx;
}

static void EOS_CALL eos_lobby_kick_member_callback_native(
    const EOS_Lobby_KickMemberCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_lobby_kick_member_info_from_native(data)
    );
    delete ctx;
}

uint64_t eos_lobby_update_lobby_modification(
    std::string_view lobby_id,
    std::string_view local_user_id)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return 0;
    }

    std::string lobby_id_storage(lobby_id);
    if (lobby_id_storage.empty()) {
        eos_set_last_error("EOS_Lobby_UpdateLobbyModification: lobby_id is required.");
        return 0;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Lobby_UpdateLobbyModification: invalid local_user_id.");
        return 0;
    }

    EOS_Lobby_UpdateLobbyModificationOptions opts{};
    opts.ApiVersion = EOS_LOBBY_UPDATELOBBYMODIFICATION_API_LATEST;
    opts.LobbyId = lobby_id_storage.c_str();
    opts.LocalUserId = local_user;

    EOS_HLobbyModification mod = nullptr;
    const EOS_EResult result = EOS_Lobby_UpdateLobbyModification(lobby, &opts, &mod);
    if (result != EOS_EResult::EOS_Success || mod == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Lobby_UpdateLobbyModification failed.");
        return 0;
    }

    return eos_lobby_modification_store(mod);
}

void eos_lobby_lobby_modification_release(uint64_t modification_id)
{
    eos_clear_last_error();
    eos_lobby_modification_erase(modification_id);
}

void eos_lobby_update_lobby(
    std::string_view lobby_id,
    uint64_t modification_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return;
    }

    std::string lobby_id_storage(lobby_id);
    if (lobby_id_storage.empty()) {
        eos_set_last_error("EOS_Lobby_UpdateLobby: lobby_id is required.");
        return;
    }

    EOS_HLobbyModification mod = eos_lobby_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS_Lobby_UpdateLobby: invalid modification_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Lobby_UpdateLobbyOptions opts{};
    opts.ApiVersion = EOS_LOBBY_UPDATELOBBY_API_LATEST;
    opts.LobbyModificationHandle = mod;

    EOS_Lobby_UpdateLobby(
        lobby,
        &opts,
        ctx,
        &eos_lobby_update_lobby_callback_native
    );

    eos_lobby_modification_erase(modification_id);
}

gm_enums::EpicResult eos_lobby_lobby_modification_set_permission_level(
    uint64_t modification_id,
    gm_enums::EpicLobbyPermissionLevel permission_level)
{
    eos_clear_last_error();

    EOS_HLobbyModification mod = eos_lobby_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS Lobby modification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_LobbyModification_SetPermissionLevelOptions opts{};
    opts.ApiVersion = EOS_LOBBYMODIFICATION_SETPERMISSIONLEVEL_API_LATEST;
    opts.PermissionLevel = (EOS_ELobbyPermissionLevel)permission_level;

    const EOS_EResult result = EOS_LobbyModification_SetPermissionLevel(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_LobbyModification_SetPermissionLevel failed.");
    }

    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_lobby_lobby_modification_set_max_members(
    uint64_t modification_id,
    int64_t max_members)
{
    eos_clear_last_error();

    EOS_HLobbyModification mod = eos_lobby_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS Lobby modification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_LobbyModification_SetMaxMembersOptions opts{};
    opts.ApiVersion = EOS_LOBBYMODIFICATION_SETMAXMEMBERS_API_LATEST;
    opts.MaxMembers = (uint32_t)max_members;

    const EOS_EResult result = EOS_LobbyModification_SetMaxMembers(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_LobbyModification_SetMaxMembers failed.");
    }

    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_lobby_lobby_modification_set_bucket_id(
    uint64_t modification_id,
    std::string_view bucket_id)
{
    eos_clear_last_error();

    EOS_HLobbyModification mod = eos_lobby_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS Lobby modification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::string bucket_id_storage(bucket_id);
    if (bucket_id_storage.empty()) {
        eos_set_last_error("EOS_LobbyModification_SetBucketId: bucket_id is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_LobbyModification_SetBucketIdOptions opts{};
    opts.ApiVersion = EOS_LOBBYMODIFICATION_SETBUCKETID_API_LATEST;
    opts.BucketId = bucket_id_storage.c_str();

    const EOS_EResult result = EOS_LobbyModification_SetBucketId(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_LobbyModification_SetBucketId failed.");
    }

    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_lobby_lobby_modification_set_invites_allowed(
    uint64_t modification_id,
    bool invites_allowed)
{
    eos_clear_last_error();

    EOS_HLobbyModification mod = eos_lobby_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS Lobby modification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_LobbyModification_SetInvitesAllowedOptions opts{};
    opts.ApiVersion = EOS_LOBBYMODIFICATION_SETINVITESALLOWED_API_LATEST;
    opts.bInvitesAllowed = invites_allowed ? EOS_TRUE : EOS_FALSE;

    const EOS_EResult result = EOS_LobbyModification_SetInvitesAllowed(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_LobbyModification_SetInvitesAllowed failed.");
    }

    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_lobby_lobby_modification_add_attribute(
    uint64_t modification_id,
    std::string_view key,
    std::string_view value,
    gm_enums::EpicLobbyAttributeVisibility visibility)
{
    eos_clear_last_error();

    EOS_HLobbyModification mod = eos_lobby_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS Lobby modification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::string key_storage(key);
    std::string value_storage(value);

    if (key_storage.empty()) {
        eos_set_last_error("EOS_LobbyModification_AddAttribute: key is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_Lobby_AttributeData attr{};
    attr.ApiVersion = EOS_LOBBY_ATTRIBUTEDATA_API_LATEST;
    attr.Key = key_storage.c_str();
    attr.Value.AsUtf8 = value_storage.c_str();
    //TODO
    // attr.ValueType = EOS_AT_STRING;

    EOS_LobbyModification_AddAttributeOptions opts{};
    opts.ApiVersion = EOS_LOBBYMODIFICATION_ADDATTRIBUTE_API_LATEST;
    opts.Attribute = &attr;
    opts.Visibility = (EOS_ELobbyAttributeVisibility)visibility;

    const EOS_EResult result = EOS_LobbyModification_AddAttribute(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_LobbyModification_AddAttribute failed.");
    }

    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_lobby_lobby_modification_remove_attribute(
    uint64_t modification_id,
    std::string_view key)
{
    eos_clear_last_error();

    EOS_HLobbyModification mod = eos_lobby_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS Lobby modification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::string key_storage(key);
    if (key_storage.empty()) {
        eos_set_last_error("EOS_LobbyModification_RemoveAttribute: key is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_Lobby_AttributeData attr{};
    attr.ApiVersion = EOS_LOBBY_ATTRIBUTEDATA_API_LATEST;
    attr.Key = key_storage.c_str();

    EOS_LobbyModification_RemoveAttributeOptions opts{};
    opts.ApiVersion = EOS_LOBBYMODIFICATION_REMOVEATTRIBUTE_API_LATEST;
    opts.Key = key_storage.c_str();

    const EOS_EResult result = EOS_LobbyModification_RemoveAttribute(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_LobbyModification_RemoveAttribute failed.");
    }

    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_lobby_lobby_modification_add_member_attribute(
    uint64_t modification_id,
    std::string_view key,
    std::string_view value,
    gm_enums::EpicLobbyAttributeVisibility visibility)
{
    eos_clear_last_error();

    EOS_HLobbyModification mod = eos_lobby_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS Lobby modification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::string key_storage(key);
    std::string value_storage(value);

    if (key_storage.empty()) {
        eos_set_last_error("EOS_LobbyModification_AddMemberAttribute: key is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_Lobby_AttributeData attr{};
    attr.ApiVersion = EOS_LOBBY_ATTRIBUTEDATA_API_LATEST;
    attr.Key = key_storage.c_str();
    attr.Value.AsUtf8 = value_storage.c_str();
    //TODO
    // attr.ValueType = EOS_AT_STRING;

    EOS_LobbyModification_AddMemberAttributeOptions opts{};
    opts.ApiVersion = EOS_LOBBYMODIFICATION_ADDMEMBERATTRIBUTE_API_LATEST;
    opts.Attribute = &attr;
    opts.Visibility = (EOS_ELobbyAttributeVisibility)visibility;

    const EOS_EResult result = EOS_LobbyModification_AddMemberAttribute(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_LobbyModification_AddMemberAttribute failed.");
    }

    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_lobby_lobby_modification_remove_member_attribute(
    uint64_t modification_id,
    std::string_view key)
{
    eos_clear_last_error();

    EOS_HLobbyModification mod = eos_lobby_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS Lobby modification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::string key_storage(key);
    if (key_storage.empty()) {
        eos_set_last_error("EOS_LobbyModification_RemoveMemberAttribute: key is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_LobbyModification_RemoveMemberAttributeOptions opts{};
    opts.ApiVersion = EOS_LOBBYMODIFICATION_REMOVEMEMBERATTRIBUTE_API_LATEST;
    opts.Key = key_storage.c_str();

    const EOS_EResult result = EOS_LobbyModification_RemoveMemberAttribute(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_LobbyModification_RemoveMemberAttribute failed.");
    }

    return (gm_enums::EpicResult)result;
}

void eos_lobby_promote_member(
    std::string_view lobby_id,
    std::string_view local_user_id,
    std::string_view target_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return;
    }

    std::string lobby_id_storage(lobby_id);
    if (lobby_id_storage.empty()) {
        eos_set_last_error("EOS_Lobby_PromoteMember: lobby_id is required.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_Lobby_PromoteMember: invalid local_user_id.");
        return;
    }

    if (!target_user) {
        eos_set_last_error("EOS_Lobby_PromoteMember: invalid target_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Lobby_PromoteMemberOptions opts{};
    opts.ApiVersion = EOS_LOBBY_PROMOTEMEMBER_API_LATEST;
    opts.LobbyId = lobby_id_storage.c_str();
    opts.LocalUserId = local_user;
    opts.TargetUserId = target_user;

    EOS_Lobby_PromoteMember(
        lobby,
        &opts,
        ctx,
        &eos_lobby_promote_member_callback_native
    );
}

void eos_lobby_kick_member(
    std::string_view lobby_id,
    std::string_view local_user_id,
    std::string_view target_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return;
    }

    std::string lobby_id_storage(lobby_id);
    if (lobby_id_storage.empty()) {
        eos_set_last_error("EOS_Lobby_KickMember: lobby_id is required.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_Lobby_KickMember: invalid local_user_id.");
        return;
    }

    if (!target_user) {
        eos_set_last_error("EOS_Lobby_KickMember: invalid target_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Lobby_KickMemberOptions opts{};
    opts.ApiVersion = EOS_LOBBY_KICKMEMBER_API_LATEST;
    opts.LobbyId = lobby_id_storage.c_str();
    opts.LocalUserId = local_user;
    opts.TargetUserId = target_user;

    EOS_Lobby_KickMember(
        lobby,
        &opts,
        ctx,
        &eos_lobby_kick_member_callback_native
    );
}

// ============================================================
// EOS Lobby (Part 3)
// ============================================================

#include <unordered_map>

static std::unordered_map<uint64_t, EOS_HLobbySearch> g_lobby_searches;
static uint64_t g_next_lobby_search_id = 1;

static std::unordered_map<uint64_t, EOS_HLobbyDetails> g_lobby_details;
static uint64_t g_next_lobby_details_id = 1;

static EOS_HLobbySearch eos_lobby_search_get(uint64_t id)
{
    auto it = g_lobby_searches.find(id);
    if (it == g_lobby_searches.end())
        return nullptr;
    return it->second;
}

static uint64_t eos_lobby_search_store(EOS_HLobbySearch handle)
{
    const uint64_t id = g_next_lobby_search_id++;
    g_lobby_searches[id] = handle;
    return id;
}

static void eos_lobby_search_erase(uint64_t id)
{
    auto it = g_lobby_searches.find(id);
    if (it == g_lobby_searches.end())
        return;

    if (it->second)
        EOS_LobbySearch_Release(it->second);

    g_lobby_searches.erase(it);
}

static EOS_HLobbyDetails eos_lobby_details_get(uint64_t id)
{
    auto it = g_lobby_details.find(id);
    if (it == g_lobby_details.end())
        return nullptr;
    return it->second;
}

static uint64_t eos_lobby_details_store(EOS_HLobbyDetails handle)
{
    const uint64_t id = g_next_lobby_details_id++;
    g_lobby_details[id] = handle;
    return id;
}

static void eos_lobby_details_erase(uint64_t id)
{
    auto it = g_lobby_details.find(id);
    if (it == g_lobby_details.end())
        return;

    if (it->second)
        EOS_LobbyDetails_Release(it->second);

    g_lobby_details.erase(it);
}

static gm_structs::EpicLobbySearchFindCallbackInfo eos_lobby_search_find_info_from_native(
    const EOS_LobbySearch_FindCallbackInfo* p)
{
    gm_structs::EpicLobbySearchFindCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    return out;
}

static void EOS_CALL eos_lobby_search_find_callback_native(
    const EOS_LobbySearch_FindCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_lobby_search_find_info_from_native(data)
    );
    delete ctx;
}

uint64_t eos_lobby_create_lobby_search(int64_t max_results)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return 0;
    }

    EOS_Lobby_CreateLobbySearchOptions opts{};
    opts.ApiVersion = EOS_LOBBY_CREATELOBBYSEARCH_API_LATEST;
    opts.MaxResults = (uint32_t)max_results;

    EOS_HLobbySearch search = nullptr;
    const EOS_EResult result = EOS_Lobby_CreateLobbySearch(lobby, &opts, &search);
    if (result != EOS_EResult::EOS_Success || search == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Lobby_CreateLobbySearch failed.");
        return 0;
    }

    return eos_lobby_search_store(search);
}

void eos_lobby_lobby_search_release(uint64_t search_id)
{
    eos_clear_last_error();
    eos_lobby_search_erase(search_id);
}

gm_enums::EpicResult eos_lobby_lobby_search_set_lobby_id(
    uint64_t search_id,
    std::string_view lobby_id)
{
    eos_clear_last_error();

    EOS_HLobbySearch search = eos_lobby_search_get(search_id);
    if (!search) {
        eos_set_last_error("EOS LobbySearch handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::string lobby_id_storage(lobby_id);
    if (lobby_id_storage.empty()) {
        eos_set_last_error("EOS_LobbySearch_SetLobbyId: lobby_id is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_LobbySearch_SetLobbyIdOptions opts{};
    opts.ApiVersion = EOS_LOBBYSEARCH_SETLOBBYID_API_LATEST;
    opts.LobbyId = lobby_id_storage.c_str();

    const EOS_EResult result = EOS_LobbySearch_SetLobbyId(search, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_LobbySearch_SetLobbyId failed.");
    }

    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_lobby_lobby_search_set_target_user_id(
    uint64_t search_id,
    std::string_view target_user_id)
{
    eos_clear_last_error();

    EOS_HLobbySearch search = eos_lobby_search_get(search_id);
    if (!search) {
        eos_set_last_error("EOS LobbySearch handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);
    if (!target_user) {
        eos_set_last_error("EOS_LobbySearch_SetTargetUserId: invalid target_user_id.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_LobbySearch_SetTargetUserIdOptions opts{};
    opts.ApiVersion = EOS_LOBBYSEARCH_SETTARGETUSERID_API_LATEST;
    opts.TargetUserId = target_user;

    const EOS_EResult result = EOS_LobbySearch_SetTargetUserId(search, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_LobbySearch_SetTargetUserId failed.");
    }

    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_lobby_lobby_search_set_parameter(
    uint64_t search_id,
    std::string_view key,
    std::string_view value,
    gm_enums::EpicComparisonOp comparison_op)
{
    eos_clear_last_error();

    EOS_HLobbySearch search = eos_lobby_search_get(search_id);
    if (!search) {
        eos_set_last_error("EOS LobbySearch handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::string key_storage(key);
    std::string value_storage(value);

    if (key_storage.empty()) {
        eos_set_last_error("EOS_LobbySearch_SetParameter: key is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_Lobby_AttributeData attr{};
    attr.ApiVersion = EOS_LOBBY_ATTRIBUTEDATA_API_LATEST;
    attr.Key = key_storage.c_str();
    attr.Value.AsUtf8 = value_storage.c_str();
    //TODO
    // attr.ValueType = EOS_AT_STRING;

    EOS_LobbySearch_SetParameterOptions opts{};
    opts.ApiVersion = EOS_LOBBYSEARCH_SETPARAMETER_API_LATEST;
    opts.Parameter = &attr;
    opts.ComparisonOp = (EOS_EComparisonOp)comparison_op;

    const EOS_EResult result = EOS_LobbySearch_SetParameter(search, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_LobbySearch_SetParameter failed.");
    }

    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_lobby_lobby_search_remove_parameter(
    uint64_t search_id,
    std::string_view key,
    gm_enums::EpicComparisonOp comparison_op)
{
    eos_clear_last_error();

    EOS_HLobbySearch search = eos_lobby_search_get(search_id);
    if (!search) {
        eos_set_last_error("EOS LobbySearch handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::string key_storage(key);
    if (key_storage.empty()) {
        eos_set_last_error("EOS_LobbySearch_RemoveParameter: key is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_LobbySearch_RemoveParameterOptions opts{};
    opts.ApiVersion = EOS_LOBBYSEARCH_REMOVEPARAMETER_API_LATEST;
    opts.Key = key_storage.c_str();
    opts.ComparisonOp = (EOS_EComparisonOp)comparison_op;

    const EOS_EResult result = EOS_LobbySearch_RemoveParameter(search, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_LobbySearch_RemoveParameter failed.");
    }

    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_lobby_lobby_search_set_max_results(
    uint64_t search_id,
    int64_t max_results)
{
    eos_clear_last_error();

    EOS_HLobbySearch search = eos_lobby_search_get(search_id);
    if (!search) {
        eos_set_last_error("EOS LobbySearch handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_LobbySearch_SetMaxResultsOptions opts{};
    opts.ApiVersion = EOS_LOBBYSEARCH_SETMAXRESULTS_API_LATEST;
    opts.MaxResults = (uint32_t)max_results;

    const EOS_EResult result = EOS_LobbySearch_SetMaxResults(search, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_LobbySearch_SetMaxResults failed.");
    }

    return (gm_enums::EpicResult)result;
}

void eos_lobby_lobby_search_find(
    uint64_t search_id,
    std::string_view local_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HLobbySearch search = eos_lobby_search_get(search_id);
    if (!search) {
        eos_set_last_error("EOS LobbySearch handle invalid.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_LobbySearch_Find: invalid local_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_LobbySearch_FindOptions opts{};
    opts.ApiVersion = EOS_LOBBYSEARCH_FIND_API_LATEST;
    opts.LocalUserId = local_user;

    EOS_LobbySearch_Find(
        search,
        &opts,
        ctx,
        &eos_lobby_search_find_callback_native
    );
}

int64_t eos_lobby_lobby_search_get_search_result_count(uint64_t search_id)
{
    eos_clear_last_error();

    EOS_HLobbySearch search = eos_lobby_search_get(search_id);
    if (!search) {
        eos_set_last_error("EOS LobbySearch handle invalid.");
        return 0;
    }

    EOS_LobbySearch_GetSearchResultCountOptions opts{};
    opts.ApiVersion = EOS_LOBBYSEARCH_GETSEARCHRESULTCOUNT_API_LATEST;

    return (int64_t)EOS_LobbySearch_GetSearchResultCount(search, &opts);
}

uint64_t eos_lobby_lobby_search_copy_search_result_by_index(
    uint64_t search_id,
    int64_t index)
{
    eos_clear_last_error();

    EOS_HLobbySearch search = eos_lobby_search_get(search_id);
    if (!search) {
        eos_set_last_error("EOS LobbySearch handle invalid.");
        return 0;
    }

    EOS_LobbySearch_CopySearchResultByIndexOptions opts{};
    opts.ApiVersion = EOS_LOBBYSEARCH_COPYSEARCHRESULTBYINDEX_API_LATEST;
    opts.LobbyIndex = (uint32_t)index;

    EOS_HLobbyDetails details = nullptr;
    const EOS_EResult result = EOS_LobbySearch_CopySearchResultByIndex(search, &opts, &details);
    if (result != EOS_EResult::EOS_Success || details == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_LobbySearch_CopySearchResultByIndex failed.");
        return 0;
    }

    return eos_lobby_details_store(details);
}

void eos_lobby_details_release(uint64_t lobby_details_id)
{
    eos_clear_last_error();
    eos_lobby_details_erase(lobby_details_id);
}

// ============================================================
// EOS Lobby (Part 4)
// ============================================================

static GMFunction g_cb_lobby_update_received = nullptr;
static GMFunction g_cb_lobby_member_update_received = nullptr;
static GMFunction g_cb_lobby_member_status_received = nullptr;
static GMFunction g_cb_lobby_join_accepted = nullptr;
static GMFunction g_cb_lobby_leave_requested = nullptr;
static GMFunction g_cb_lobby_native_invite_requested = nullptr;

static gm_structs::EpicLobbyDetailsInfo eos_lobby_details_info_from_native(
    const EOS_LobbyDetails_Info* p)
{
    gm_structs::EpicLobbyDetailsInfo out{};
    if (!p)
        return out;

    out.lobby_id = p->LobbyId ? std::string(p->LobbyId) : std::string();
    out.bucket_id = p->BucketId ? std::string(p->BucketId) : std::string();
    out.lobby_owner_user_id = eos_product_user_id_to_string_internal(p->LobbyOwnerUserId);
    out.available_slots = (int64_t)p->AvailableSlots;
    out.max_members = (int64_t)p->MaxMembers;
    out.permission_level = (gm_enums::EpicLobbyPermissionLevel)p->PermissionLevel;
    out.allow_invites = (p->bAllowInvites != 0);
    out.presence_enabled = (p->bPresenceEnabled != 0);

    return out;
}

static gm_structs::EpicLobbyLobbyUpdateReceivedCallbackInfo eos_lobby_update_received_info_from_native(
    const EOS_Lobby_LobbyUpdateReceivedCallbackInfo* p)
{
    gm_structs::EpicLobbyLobbyUpdateReceivedCallbackInfo out{};
    if (!p)
        return out;

    out.lobby_id = p->LobbyId ? std::string(p->LobbyId) : std::string();
    out.local_user_id = "";
    return out;
}

static gm_structs::EpicLobbyLobbyMemberUpdateReceivedCallbackInfo eos_lobby_member_update_received_info_from_native(
    const EOS_Lobby_LobbyMemberUpdateReceivedCallbackInfo* p)
{
    gm_structs::EpicLobbyLobbyMemberUpdateReceivedCallbackInfo out{};
    if (!p)
        return out;

    out.lobby_id = p->LobbyId ? std::string(p->LobbyId) : std::string();
    out.target_user_id = eos_product_user_id_to_string_internal(p->TargetUserId);
    out.local_user_id = "";
    return out;
}

static gm_structs::EpicLobbyLobbyMemberStatusReceivedCallbackInfo eos_lobby_member_status_received_info_from_native(
    const EOS_Lobby_LobbyMemberStatusReceivedCallbackInfo* p)
{
    gm_structs::EpicLobbyLobbyMemberStatusReceivedCallbackInfo out{};
    if (!p)
        return out;

    out.lobby_id = p->LobbyId ? std::string(p->LobbyId) : std::string();
    out.target_user_id = eos_product_user_id_to_string_internal(p->TargetUserId);
    out.local_user_id = "";
    out.current_status = (gm_enums::EpicLobbyMemberStatus)p->CurrentStatus;
    return out;
}

static gm_structs::EpicLobbyJoinLobbyAcceptedCallbackInfo eos_lobby_join_accepted_info_from_native(
    const EOS_Lobby_JoinLobbyAcceptedCallbackInfo* p)
{
    gm_structs::EpicLobbyJoinLobbyAcceptedCallbackInfo out{};
    if (!p)
        return out;

    out.ui_event_id = (uint64_t)p->UiEventId;
    return out;
}

static gm_structs::EpicLobbyLeaveLobbyRequestedCallbackInfo eos_lobby_leave_requested_info_from_native(
    const EOS_Lobby_LeaveLobbyRequestedCallbackInfo* p)
{
    gm_structs::EpicLobbyLeaveLobbyRequestedCallbackInfo out{};
    if (!p)
        return out;

    out.lobby_id = p->LobbyId ? std::string(p->LobbyId) : std::string();
    out.local_user_id = "";
    return out;
}

static gm_structs::EpicLobbySendLobbyNativeInviteRequestedCallbackInfo eos_lobby_native_invite_requested_info_from_native(
    const EOS_Lobby_SendLobbyNativeInviteRequestedCallbackInfo* p)
{
    gm_structs::EpicLobbySendLobbyNativeInviteRequestedCallbackInfo out{};
    if (!p)
        return out;

    out.lobby_id = p->LobbyId ? std::string(p->LobbyId) : std::string();
    out.local_user_id = "";
    out.target_native_account_type = p->TargetNativeAccountType ? std::string(p->TargetNativeAccountType) : std::string();
    out.target_user_native_account_id = p->TargetUserNativeAccountId ? std::string(p->TargetUserNativeAccountId) : std::string();
    return out;
}

static void EOS_CALL eos_lobby_update_received_callback_native(
    const EOS_Lobby_LobbyUpdateReceivedCallbackInfo* data)
{
    if (!data || !g_cb_lobby_update_received)
        return;

    g_cb_lobby_update_received.call(
        eos_lobby_update_received_info_from_native(data)
    );
}

static void EOS_CALL eos_lobby_member_update_received_callback_native(
    const EOS_Lobby_LobbyMemberUpdateReceivedCallbackInfo* data)
{
    if (!data || !g_cb_lobby_member_update_received)
        return;

    g_cb_lobby_member_update_received.call(
        eos_lobby_member_update_received_info_from_native(data)
    );
}

static void EOS_CALL eos_lobby_member_status_received_callback_native(
    const EOS_Lobby_LobbyMemberStatusReceivedCallbackInfo* data)
{
    if (!data || !g_cb_lobby_member_status_received)
        return;

    g_cb_lobby_member_status_received.call(
        eos_lobby_member_status_received_info_from_native(data)
    );
}

static void EOS_CALL eos_lobby_join_accepted_callback_native(
    const EOS_Lobby_JoinLobbyAcceptedCallbackInfo* data)
{
    if (!data || !g_cb_lobby_join_accepted)
        return;

    g_cb_lobby_join_accepted.call(
        eos_lobby_join_accepted_info_from_native(data)
    );
}

static void EOS_CALL eos_lobby_leave_requested_callback_native(
    const EOS_Lobby_LeaveLobbyRequestedCallbackInfo* data)
{
    if (!data || !g_cb_lobby_leave_requested)
        return;

    g_cb_lobby_leave_requested.call(
        eos_lobby_leave_requested_info_from_native(data)
    );
}

static void EOS_CALL eos_lobby_native_invite_requested_callback_native(
    const EOS_Lobby_SendLobbyNativeInviteRequestedCallbackInfo* data)
{
    if (!data || !g_cb_lobby_native_invite_requested)
        return;

    g_cb_lobby_native_invite_requested.call(
        eos_lobby_native_invite_requested_info_from_native(data)
    );
}

uint64_t eos_lobby_copy_lobby_details_handle(
    std::string_view lobby_id,
    std::string_view local_user_id)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return 0;
    }

    std::string lobby_id_storage(lobby_id);
    if (lobby_id_storage.empty()) {
        eos_set_last_error("EOS_Lobby_CopyLobbyDetailsHandle: lobby_id is required.");
        return 0;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Lobby_CopyLobbyDetailsHandle: invalid local_user_id.");
        return 0;
    }

    EOS_Lobby_CopyLobbyDetailsHandleOptions opts{};
    opts.ApiVersion = EOS_LOBBY_COPYLOBBYDETAILSHANDLE_API_LATEST;
    opts.LobbyId = lobby_id_storage.c_str();
    opts.LocalUserId = local_user;

    EOS_HLobbyDetails details = nullptr;
    const EOS_EResult result = EOS_Lobby_CopyLobbyDetailsHandle(lobby, &opts, &details);
    if (result != EOS_EResult::EOS_Success || details == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Lobby_CopyLobbyDetailsHandle failed.");
        return 0;
    }

    return eos_lobby_details_store(details);
}

gm_structs::EpicLobbyDetailsInfo eos_lobby_details_copy_info(uint64_t lobby_details_id)
{
    eos_clear_last_error();

    gm_structs::EpicLobbyDetailsInfo out{};

    EOS_HLobbyDetails details = eos_lobby_details_get(lobby_details_id);
    if (!details) {
        eos_set_last_error("EOS LobbyDetails handle invalid.");
        return out;
    }

    EOS_LobbyDetails_CopyInfoOptions opts{};
    opts.ApiVersion = EOS_LOBBYDETAILS_COPYINFO_API_LATEST;

    EOS_LobbyDetails_Info* info = nullptr;
    const EOS_EResult result = EOS_LobbyDetails_CopyInfo(details, &opts, &info);
    if (result != EOS_EResult::EOS_Success || info == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_LobbyDetails_CopyInfo failed.");
        return out;
    }

    out = eos_lobby_details_info_from_native(info);
    EOS_LobbyDetails_Info_Release(info);
    return out;
}

int64_t eos_lobby_details_get_member_count(uint64_t lobby_details_id)
{
    eos_clear_last_error();

    EOS_HLobbyDetails details = eos_lobby_details_get(lobby_details_id);
    if (!details) {
        eos_set_last_error("EOS LobbyDetails handle invalid.");
        return 0;
    }

    EOS_LobbyDetails_GetMemberCountOptions opts{};
    opts.ApiVersion = EOS_LOBBYDETAILS_GETMEMBERCOUNT_API_LATEST;

    return (int64_t)EOS_LobbyDetails_GetMemberCount(details, &opts);
}

std::string eos_lobby_details_get_member_by_index(uint64_t lobby_details_id, int64_t index)
{
    eos_clear_last_error();

    EOS_HLobbyDetails details = eos_lobby_details_get(lobby_details_id);
    if (!details) {
        eos_set_last_error("EOS LobbyDetails handle invalid.");
        return std::string();
    }

    EOS_LobbyDetails_GetMemberByIndexOptions opts{};
    opts.ApiVersion = EOS_LOBBYDETAILS_GETMEMBERBYINDEX_API_LATEST;
    opts.MemberIndex = (uint32_t)index;

    EOS_ProductUserId id = EOS_LobbyDetails_GetMemberByIndex(details, &opts);
    return eos_product_user_id_to_string_internal(id);
}

std::string eos_lobby_details_get_lobby_owner(uint64_t lobby_details_id)
{
    eos_clear_last_error();

    EOS_HLobbyDetails details = eos_lobby_details_get(lobby_details_id);
    if (!details) {
        eos_set_last_error("EOS LobbyDetails handle invalid.");
        return std::string();
    }

    EOS_LobbyDetails_GetLobbyOwnerOptions opts{};
    opts.ApiVersion = EOS_LOBBYDETAILS_GETLOBBYOWNER_API_LATEST;

    EOS_ProductUserId id = EOS_LobbyDetails_GetLobbyOwner(details, &opts);
    return eos_product_user_id_to_string_internal(id);
}

uint64_t eos_lobby_add_notify_lobby_update_received(
    std::string_view local_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return 0;
    }

    g_cb_lobby_update_received = callback;

    EOS_Lobby_AddNotifyLobbyUpdateReceivedOptions opts{};
    opts.ApiVersion = EOS_LOBBY_ADDNOTIFYLOBBYUPDATERECEIVED_API_LATEST;

    return (uint64_t)EOS_Lobby_AddNotifyLobbyUpdateReceived(
        lobby,
        &opts,
        nullptr,
        &eos_lobby_update_received_callback_native
    );
}

void eos_lobby_remove_notify_lobby_update_received(uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return;
    }

    EOS_Lobby_RemoveNotifyLobbyUpdateReceived(
        lobby,
        (EOS_NotificationId)notification_id
    );
}

uint64_t eos_lobby_add_notify_lobby_member_update_received(
    std::string_view local_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return 0;
    }

    g_cb_lobby_member_update_received = callback;

    EOS_Lobby_AddNotifyLobbyMemberUpdateReceivedOptions opts{};
    opts.ApiVersion = EOS_LOBBY_ADDNOTIFYLOBBYMEMBERUPDATERECEIVED_API_LATEST;

    return (uint64_t)EOS_Lobby_AddNotifyLobbyMemberUpdateReceived(
        lobby,
        &opts,
        nullptr,
        &eos_lobby_member_update_received_callback_native
    );
}

void eos_lobby_remove_notify_lobby_member_update_received(uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return;
    }

    EOS_Lobby_RemoveNotifyLobbyMemberUpdateReceived(
        lobby,
        (EOS_NotificationId)notification_id
    );
}

uint64_t eos_lobby_add_notify_lobby_member_status_received(
    std::string_view local_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return 0;
    }

    g_cb_lobby_member_status_received = callback;

    EOS_Lobby_AddNotifyLobbyMemberStatusReceivedOptions opts{};
    opts.ApiVersion = EOS_LOBBY_ADDNOTIFYLOBBYMEMBERSTATUSRECEIVED_API_LATEST;

    return (uint64_t)EOS_Lobby_AddNotifyLobbyMemberStatusReceived(
        lobby,
        &opts,
        nullptr,
        &eos_lobby_member_status_received_callback_native
    );
}

void eos_lobby_remove_notify_lobby_member_status_received(uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return;
    }

    EOS_Lobby_RemoveNotifyLobbyMemberStatusReceived(
        lobby,
        (EOS_NotificationId)notification_id
    );
}

uint64_t eos_lobby_add_notify_join_lobby_accepted(const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return 0;
    }

    g_cb_lobby_join_accepted = callback;

    EOS_Lobby_AddNotifyJoinLobbyAcceptedOptions opts{};
    opts.ApiVersion = EOS_LOBBY_ADDNOTIFYJOINLOBBYACCEPTED_API_LATEST;

    return (uint64_t)EOS_Lobby_AddNotifyJoinLobbyAccepted(
        lobby,
        &opts,
        nullptr,
        &eos_lobby_join_accepted_callback_native
    );
}

void eos_lobby_remove_notify_join_lobby_accepted(uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return;
    }

    EOS_Lobby_RemoveNotifyJoinLobbyAccepted(
        lobby,
        (EOS_NotificationId)notification_id
    );
}

uint64_t eos_lobby_add_notify_leave_lobby_requested(
    std::string_view local_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return 0;
    }

    g_cb_lobby_leave_requested = callback;

    EOS_Lobby_AddNotifyLeaveLobbyRequestedOptions opts{};
    opts.ApiVersion = EOS_LOBBY_ADDNOTIFYLEAVELOBBYREQUESTED_API_LATEST;

    return (uint64_t)EOS_Lobby_AddNotifyLeaveLobbyRequested(
        lobby,
        &opts,
        nullptr,
        &eos_lobby_leave_requested_callback_native
    );
}

void eos_lobby_remove_notify_leave_lobby_requested(uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return;
    }

    EOS_Lobby_RemoveNotifyLeaveLobbyRequested(
        lobby,
        (EOS_NotificationId)notification_id
    );
}

uint64_t eos_lobby_add_notify_send_lobby_native_invite_requested(
    std::string_view local_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return 0;
    }

    g_cb_lobby_native_invite_requested = callback;

    EOS_Lobby_AddNotifySendLobbyNativeInviteRequestedOptions opts{};
    opts.ApiVersion = EOS_LOBBY_ADDNOTIFYSENDLOBBYNATIVEINVITEREQUESTED_API_LATEST;

    return (uint64_t)EOS_Lobby_AddNotifySendLobbyNativeInviteRequested(
        lobby,
        &opts,
        nullptr,
        &eos_lobby_native_invite_requested_callback_native
    );
}

void eos_lobby_remove_notify_send_lobby_native_invite_requested(uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HLobby lobby = eos_lobby_iface();
    if (!lobby) {
        eos_set_last_error("EOS Lobby interface unavailable.");
        return;
    }

    EOS_Lobby_RemoveNotifySendLobbyNativeInviteRequested(
        lobby,
        (EOS_NotificationId)notification_id
    );
}
