#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_sessions.h>

#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>

using namespace gm::wire;
using namespace gm_structs;
using namespace gm_enums;

// ============================================================
// Internal helpers / state
// ============================================================

template <typename Fn>
static std::string eos_sessions_copy_string_with_fixed_retry(Fn&& call_fn, size_t initial_capacity = 256)
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

static std::string eos_sessions_product_user_id_to_string_internal(EOS_ProductUserId product_user_id)
{
    if (!product_user_id)
        return std::string();

    return eos_sessions_copy_string_with_fixed_retry(
        [&](char* out_buffer, int32_t* inout_len) -> EOS_EResult
        {
            return EOS_ProductUserId_ToString(product_user_id, out_buffer, inout_len);
        });
}


struct EOSAsyncCallbackContext
{
    GMFunction callback;
};

static std::unordered_map<uint64_t, EOS_HSessionModification> g_session_modifications;
static uint64_t g_next_session_modification_id = 1;

static EOS_HSessions eos_sessions_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetSessionsInterface(p) : nullptr;
}

static EOS_ProductUserId eos_product_user_id_from_string_internal(std::string_view product_user_id)
{
    std::string value(product_user_id);
    if (value.empty())
        return nullptr;
    return EOS_ProductUserId_FromString(value.c_str());
}

static EOS_HSessionModification eos_sessions_modification_get(uint64_t id)
{
    auto it = g_session_modifications.find(id);
    if (it == g_session_modifications.end())
        return nullptr;
    return it->second;
}

static uint64_t eos_sessions_modification_store(EOS_HSessionModification mod)
{
    const uint64_t id = g_next_session_modification_id++;
    g_session_modifications[id] = mod;
    return id;
}

static void eos_sessions_modification_erase(uint64_t id)
{
    auto it = g_session_modifications.find(id);
    if (it == g_session_modifications.end())
        return;

    if (it->second)
        EOS_SessionModification_Release(it->second);

    g_session_modifications.erase(it);
}

static gm_structs::EpicSessionsUpdateSessionCallbackInfo
eos_sessions_update_session_info_from_native(const EOS_Sessions_UpdateSessionCallbackInfo* p)
{
    gm_structs::EpicSessionsUpdateSessionCallbackInfo out{};
    if (!p) return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.session_name = p->SessionName ? std::string(p->SessionName) : std::string();
    return out;
}

static gm_structs::EpicSessionsDestroySessionCallbackInfo
eos_sessions_destroy_session_info_from_native(const EOS_Sessions_DestroySessionCallbackInfo* p)
{
    gm_structs::EpicSessionsDestroySessionCallbackInfo out{};
    if (!p) return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    return out;
}

static gm_structs::EpicSessionsStartSessionCallbackInfo
eos_sessions_start_session_info_from_native(const EOS_Sessions_StartSessionCallbackInfo* p)
{
    gm_structs::EpicSessionsStartSessionCallbackInfo out{};
    if (!p) return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    return out;
}

static gm_structs::EpicSessionsEndSessionCallbackInfo
eos_sessions_end_session_info_from_native(const EOS_Sessions_EndSessionCallbackInfo* p)
{
    gm_structs::EpicSessionsEndSessionCallbackInfo out{};
    if (!p) return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    return out;
}

static void EOS_CALL eos_sessions_update_session_callback_native(
    const EOS_Sessions_UpdateSessionCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_sessions_update_session_info_from_native(data)
    );
    delete ctx;
}

static void EOS_CALL eos_sessions_destroy_session_callback_native(
    const EOS_Sessions_DestroySessionCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_sessions_destroy_session_info_from_native(data)
    );
    delete ctx;
}

static void EOS_CALL eos_sessions_start_session_callback_native(
    const EOS_Sessions_StartSessionCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_sessions_start_session_info_from_native(data)
    );
    delete ctx;
}

static void EOS_CALL eos_sessions_end_session_callback_native(
    const EOS_Sessions_EndSessionCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_sessions_end_session_info_from_native(data)
    );
    delete ctx;
}

// ============================================================
// EOS Sessions (Part 1)
// ============================================================

std::uint64_t eos_sessions_create_session_modification(std::string_view session_name, std::string_view session_id, std::string_view bucket_id, std::int64_t max_players, std::string_view local_user_id, bool presence_enabled, bool sanctions_enabled, const std::vector<std::uint32_t>& allowed_platform_ids)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return 0;
    }

    std::string session_name_storage(session_name);
    std::string bucket_id_storage(bucket_id);
    std::string session_id_storage(session_id);
    

    if (session_name_storage.empty()) {
        eos_set_last_error("EOS_Sessions_CreateSessionModification: session_name is required.");
        return 0;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Sessions_CreateSessionModification: invalid local_user_id.");
        return 0;
    }

    EOS_Sessions_CreateSessionModificationOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_CREATESESSIONMODIFICATION_API_LATEST;
    opts.SessionName = session_name_storage.c_str();
    opts.BucketId = bucket_id_storage.empty() ? nullptr : bucket_id_storage.c_str();
    opts.MaxPlayers = (uint32_t)max_players;
    opts.LocalUserId = local_user;
    opts.bPresenceEnabled = presence_enabled ? EOS_TRUE : EOS_FALSE;
    
    opts.bSanctionsEnabled = sanctions_enabled? EOS_TRUE:EOS_FALSE;
	opts.SessionId = session_id_storage.c_str();
    const uint32_t* ptr = reinterpret_cast<const uint32_t*>(allowed_platform_ids.data());
	opts.AllowedPlatformIds = ptr;
	opts.AllowedPlatformIdsCount = (uint32_t)allowed_platform_ids.size();

    EOS_HSessionModification mod = nullptr;
    const EOS_EResult result = EOS_Sessions_CreateSessionModification(sessions, &opts, &mod);
    if (result != EOS_EResult::EOS_Success || mod == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Sessions_CreateSessionModification failed.");
        return 0;
    }

    return eos_sessions_modification_store(mod);
}

void eos_sessions_session_modification_release(uint64_t modification_id)
{
    eos_clear_last_error();
    eos_sessions_modification_erase(modification_id);
}

void eos_sessions_update_session(
    uint64_t modification_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return;
    }

    EOS_HSessionModification mod = eos_sessions_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS_Sessions_UpdateSession: invalid modification_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Sessions_UpdateSessionOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_UPDATESESSION_API_LATEST;
    opts.SessionModificationHandle = mod;

    EOS_Sessions_UpdateSession(
        sessions,
        &opts,
        ctx,
        &eos_sessions_update_session_callback_native
    );

    eos_sessions_modification_erase(modification_id);
}

void eos_sessions_destroy_session(std::string_view session_name, const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return;
    }

    std::string session_name_storage(session_name);
    if (session_name_storage.empty()) {
        eos_set_last_error("EOS_Sessions_DestroySession: session_name is required.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Sessions_DestroySessionOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_DESTROYSESSION_API_LATEST;
    opts.SessionName = session_name_storage.c_str();

    EOS_Sessions_DestroySession(
        sessions,
        &opts,
        ctx,
        &eos_sessions_destroy_session_callback_native
    );
}

void eos_sessions_start_session(std::string_view session_name, const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return;
    }

    std::string session_name_storage(session_name);
    if (session_name_storage.empty()) {
        eos_set_last_error("EOS_Sessions_StartSession: session_name is required.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Sessions_StartSessionOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_STARTSESSION_API_LATEST;
    opts.SessionName = session_name_storage.c_str();

    EOS_Sessions_StartSession(
        sessions,
        &opts,
        ctx,
        &eos_sessions_start_session_callback_native
    );
}

void eos_sessions_end_session(std::string_view session_name, const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return;
    }

    std::string session_name_storage(session_name);
    if (session_name_storage.empty()) {
        eos_set_last_error("EOS_Sessions_EndSession: session_name is required.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Sessions_EndSessionOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_ENDSESSION_API_LATEST;
    opts.SessionName = session_name_storage.c_str();

    EOS_Sessions_EndSession(
        sessions,
        &opts,
        ctx,
        &eos_sessions_end_session_callback_native
    );
}

// ============================================================
// EOS Sessions (Part 2)
// ============================================================


static gm_structs::EpicSessionsJoinSessionCallbackInfo
eos_sessions_join_session_info_from_native(const EOS_Sessions_JoinSessionCallbackInfo* p)
{
    gm_structs::EpicSessionsJoinSessionCallbackInfo out{};
    if (!p) return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    return out;
}

static gm_structs::EpicSessionsRegisterPlayersCallbackInfo 
eos_sessions_register_players_info_from_native(const EOS_Sessions_RegisterPlayersCallbackInfo* p)
{
    gm_structs::EpicSessionsRegisterPlayersCallbackInfo out{};
    if (!p) return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    
    out.registered_players = std::vector<std::string>{};
    for(int i = 0 ; i < p->RegisteredPlayersCount ; i++){
        out.registered_players.push_back(eos_sessions_product_user_id_to_string_internal(p->RegisteredPlayers[i]));
    }

    out.sanctioned_players = std::vector<std::string>{};
    for(int i = 0 ; i < p->SanctionedPlayersCount ; i++){
        out.sanctioned_players.push_back(eos_sessions_product_user_id_to_string_internal(p->SanctionedPlayers[i]));
    }

    return out;
}

static gm_structs::EpicSessionsUnregisterPlayersCallbackInfo
eos_sessions_unregister_players_info_from_native(const EOS_Sessions_UnregisterPlayersCallbackInfo* p)
{
    gm_structs::EpicSessionsUnregisterPlayersCallbackInfo out{};
    if (!p) return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    
	EOS_ProductUserId* UnregisteredPlayers;
	uint32_t UnregisteredPlayersCount;

    out.unregistered_players = std::vector<std::string>{};
    for(int i = 0 ; i < p->UnregisteredPlayersCount ; i++){
        out.unregistered_players.push_back(eos_sessions_product_user_id_to_string_internal(p->UnregisteredPlayers[i]));
    }

    return out;
}

static void EOS_CALL eos_sessions_join_session_callback_native(
    const EOS_Sessions_JoinSessionCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_sessions_join_session_info_from_native(data)
    );
    delete ctx;
}

static void EOS_CALL eos_sessions_register_players_callback_native(
    const EOS_Sessions_RegisterPlayersCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_sessions_register_players_info_from_native(data)
    );
    delete ctx;
}

static void EOS_CALL eos_sessions_unregister_players_callback_native(
    const EOS_Sessions_UnregisterPlayersCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_sessions_unregister_players_info_from_native(data)
    );
    delete ctx;
}

void eos_sessions_join_session(
    std::string_view session_name,
    std::string_view local_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return;
    }

    std::string session_name_storage(session_name);
    if (session_name_storage.empty()) {
        eos_set_last_error("EOS_Sessions_JoinSession: session_name is required.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Sessions_JoinSession: invalid local_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Sessions_JoinSessionOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_JOINSESSION_API_LATEST;
    opts.SessionName = session_name_storage.c_str();
    opts.LocalUserId = local_user;
    opts.bPresenceEnabled = EOS_TRUE;

    EOS_Sessions_JoinSession(
        sessions,
        &opts,
        ctx,
        &eos_sessions_join_session_callback_native
    );
}

void eos_sessions_register_players(std::string_view session_name, 
    const std::vector<std::string_view>& target_user_ids, 
    const gm::wire::GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return;
    }

    std::string session_name_storage(session_name);
    if (session_name_storage.empty()) {
        eos_set_last_error("EOS_Sessions_RegisterPlayers: session_name is required.");
        return;
    }

    if (target_user_ids.empty()) {
        eos_set_last_error("EOS_Sessions_RegisterPlayers: target_user_ids is required.");
        return;
    }

    std::vector<EOS_ProductUserId> users;
    users.reserve(target_user_ids.size());

    for (const std::string_view& id_str : target_user_ids)
    {
        EOS_ProductUserId id = eos_product_user_id_from_string_internal(id_str);
        if (!id) {
            eos_set_last_error("EOS_Sessions_RegisterPlayers: invalid target_user_id.");
            return;
        }
        users.push_back(id);
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Sessions_RegisterPlayersOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_REGISTERPLAYERS_API_LATEST;
    opts.SessionName = session_name_storage.c_str();
    opts.PlayersToRegister = users.data();
    opts.PlayersToRegisterCount = (uint32_t)users.size();

    EOS_Sessions_RegisterPlayers(
        sessions,
        &opts,
        ctx,
        &eos_sessions_register_players_callback_native
    );
}

void eos_sessions_unregister_players(
    std::string_view session_name,
    const std::vector<std::string_view>& target_user_ids,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return;
    }

    std::string session_name_storage(session_name);
    if (session_name_storage.empty()) {
        eos_set_last_error("EOS_Sessions_UnregisterPlayers: session_name is required.");
        return;
    }

    if (target_user_ids.empty()) {
        eos_set_last_error("EOS_Sessions_UnregisterPlayers: target_user_ids is required.");
        return;
    }

    std::vector<EOS_ProductUserId> users;
    users.reserve(target_user_ids.size());

    for (const std::string_view& id_str : target_user_ids)
    {
        EOS_ProductUserId id = eos_product_user_id_from_string_internal(id_str);
        if (!id) {
            eos_set_last_error("EOS_Sessions_UnregisterPlayers: invalid target_user_id.");
            return;
        }
        users.push_back(id);
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Sessions_UnregisterPlayersOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_UNREGISTERPLAYERS_API_LATEST;
    opts.SessionName = session_name_storage.c_str();
    opts.PlayersToUnregister = users.data();
    opts.PlayersToUnregisterCount = (uint32_t)users.size();

    EOS_Sessions_UnregisterPlayers(
        sessions,
        &opts,
        ctx,
        &eos_sessions_unregister_players_callback_native
    );
}

// ============================================================
// EOS Sessions (Part 3)
// ============================================================

#include <unordered_map>

static std::unordered_map<uint64_t, EOS_HSessionSearch> g_session_searches;
static uint64_t g_next_session_search_id = 1;

static std::unordered_map<uint64_t, EOS_HSessionDetails> g_session_details_handles;
static uint64_t g_next_session_details_id = 1;

static EOS_HSessionSearch eos_sessions_search_get(uint64_t id)
{
    auto it = g_session_searches.find(id);
    if (it == g_session_searches.end())
        return nullptr;
    return it->second;
}

static uint64_t eos_sessions_search_store(EOS_HSessionSearch handle)
{
    const uint64_t id = g_next_session_search_id++;
    g_session_searches[id] = handle;
    return id;
}

static void eos_sessions_search_erase(uint64_t id)
{
    auto it = g_session_searches.find(id);
    if (it == g_session_searches.end())
        return;

    if (it->second)
        EOS_SessionSearch_Release(it->second);

    g_session_searches.erase(it);
}

static EOS_HSessionDetails eos_sessions_details_get(uint64_t id)
{
    auto it = g_session_details_handles.find(id);
    if (it == g_session_details_handles.end())
        return nullptr;
    return it->second;
}

static uint64_t eos_sessions_details_store(EOS_HSessionDetails handle)
{
    const uint64_t id = g_next_session_details_id++;
    g_session_details_handles[id] = handle;
    return id;
}

static void eos_sessions_details_erase(uint64_t id)
{
    auto it = g_session_details_handles.find(id);
    if (it == g_session_details_handles.end())
        return;

    if (it->second)
        EOS_SessionDetails_Release(it->second);

    g_session_details_handles.erase(it);
}

static gm_structs::EpicSessionsFindCallbackInfo
eos_sessions_find_info_from_native(const EOS_SessionSearch_FindCallbackInfo* p)
{
    gm_structs::EpicSessionsFindCallbackInfo out{};
    if (!p) return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    return out;
}

static void EOS_CALL eos_sessions_find_callback_native(
    const EOS_SessionSearch_FindCallbackInfo* data)
{
    if (!data)
        return;

    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;

    ctx->callback.call(
        eos_sessions_find_info_from_native(data)
    );
    delete ctx;
}

uint64_t eos_sessions_create_session_search(int64_t max_search_results)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return 0;
    }

    EOS_Sessions_CreateSessionSearchOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_CREATESESSIONSEARCH_API_LATEST;
    opts.MaxSearchResults = (uint32_t)max_search_results;

    EOS_HSessionSearch search = nullptr;
    const EOS_EResult result = EOS_Sessions_CreateSessionSearch(sessions, &opts, &search);
    if (result != EOS_EResult::EOS_Success || search == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Sessions_CreateSessionSearch failed.");
        return 0;
    }

    return eos_sessions_search_store(search);
}

void eos_sessions_session_search_release(uint64_t search_id)
{
    eos_clear_last_error();
    eos_sessions_search_erase(search_id);
}

gm_enums::EpicResult eos_sessions_session_search_set_session_id(
    uint64_t search_id,
    std::string_view session_id)
{
    eos_clear_last_error();

    EOS_HSessionSearch search = eos_sessions_search_get(search_id);
    if (!search) {
        eos_set_last_error("EOS SessionSearch handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::string session_id_storage(session_id);
    if (session_id_storage.empty()) {
        eos_set_last_error("EOS_SessionSearch_SetSessionId: session_id is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_SessionSearch_SetSessionIdOptions opts{};
    opts.ApiVersion = EOS_SESSIONSEARCH_SETSESSIONID_API_LATEST;
    opts.SessionId = session_id_storage.c_str();

    const EOS_EResult result = EOS_SessionSearch_SetSessionId(search, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_SessionSearch_SetSessionId failed.");
    }

    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_sessions_session_search_set_target_user_id(
    uint64_t search_id,
    std::string_view target_user_id)
{
    eos_clear_last_error();

    EOS_HSessionSearch search = eos_sessions_search_get(search_id);
    if (!search) {
        eos_set_last_error("EOS SessionSearch handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);
    if (!target_user) {
        eos_set_last_error("EOS_SessionSearch_SetTargetUserId: invalid target_user_id.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_SessionSearch_SetTargetUserIdOptions opts{};
    opts.ApiVersion = EOS_SESSIONSEARCH_SETTARGETUSERID_API_LATEST;
    opts.TargetUserId = target_user;

    const EOS_EResult result = EOS_SessionSearch_SetTargetUserId(search, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_SessionSearch_SetTargetUserId failed.");
    }

    return (gm_enums::EpicResult)result;
}

void eos_sessions_session_search_find(
    uint64_t search_id,
    std::string_view local_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HSessionSearch search = eos_sessions_search_get(search_id);
    if (!search) {
        eos_set_last_error("EOS SessionSearch handle invalid.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_SessionSearch_Find: invalid local_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_SessionSearch_FindOptions opts{};
    opts.ApiVersion = EOS_SESSIONSEARCH_FIND_API_LATEST;
    opts.LocalUserId = local_user;

    EOS_SessionSearch_Find(
        search,
        &opts,
        ctx,
        &eos_sessions_find_callback_native
    );
}

uint64_t eos_sessions_session_search_copy_search_result_by_index(
    uint64_t search_id,
    int64_t index)
{
    eos_clear_last_error();

    EOS_HSessionSearch search = eos_sessions_search_get(search_id);
    if (!search) {
        eos_set_last_error("EOS SessionSearch handle invalid.");
        return 0;
    }

    EOS_SessionSearch_CopySearchResultByIndexOptions opts{};
    opts.ApiVersion = EOS_SESSIONSEARCH_COPYSEARCHRESULTBYINDEX_API_LATEST;
    opts.SessionIndex = (uint32_t)index;

    EOS_HSessionDetails details = nullptr;
    const EOS_EResult result = EOS_SessionSearch_CopySearchResultByIndex(
        search, &opts, &details);

    if (result != EOS_EResult::EOS_Success || details == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_SessionSearch_CopySearchResultByIndex failed.");
        return 0;
    }

    return eos_sessions_details_store(details);
}

void eos_sessions_session_details_release(uint64_t session_details_id)
{
    eos_clear_last_error();
    eos_sessions_details_erase(session_details_id);
}

// ============================================================
// EOS Sessions (Part 4)
// ============================================================

static GMFunction g_cb_sessions_invite_received = nullptr;
static GMFunction g_cb_sessions_invite_accepted = nullptr;
static GMFunction g_cb_sessions_join_accepted = nullptr;

static std::unordered_map<uint64_t, EOS_HActiveSession> g_active_sessions;
static uint64_t g_next_active_session_id = 1;

static EOS_HActiveSession eos_sessions_active_get(uint64_t id)
{
    auto it = g_active_sessions.find(id);
    if (it == g_active_sessions.end())
        return nullptr;
    return it->second;
}

static uint64_t eos_sessions_active_store(EOS_HActiveSession handle)
{
    const uint64_t id = g_next_active_session_id++;
    g_active_sessions[id] = handle;
    return id;
}

static void eos_sessions_active_erase(uint64_t id)
{
    auto it = g_active_sessions.find(id);
    if (it == g_active_sessions.end())
        return;

    if (it->second)
        EOS_ActiveSession_Release(it->second);

    g_active_sessions.erase(it);
}


static gm_structs::EpicSessionDetailsInfo eos_sessions_session_details_info_from_native(
    const EOS_SessionDetails_Info* p)
{
    gm_structs::EpicSessionDetailsInfo out{};
    if (!p)
        return out;

    out.session_id = p->SessionId ? std::string(p->SessionId) : std::string();
    out.host_address = p->HostAddress ? std::string(p->HostAddress) : std::string();
    out.owner_user_id = eos_sessions_product_user_id_to_string_internal(p->OwnerUserId);
    out.num_open_public_connections = (int64_t)p->NumOpenPublicConnections;
    
    //TODO
    // out.settings_count = (int64_t)p->SettingsCount;
    // const EOS_SessionDetails_Settings* Settings;

    const char* OwnerServerClientId = p->OwnerServerClientId;

    return out;
}

static gm_structs::EpicActiveSessionInfo eos_sessions_active_session_info_from_native(
    const EOS_ActiveSession_Info* p)
{
    gm_structs::EpicActiveSessionInfo out{};
    if (!p)
        return out;

    out.session_name = p->SessionName ? std::string(p->SessionName) : std::string();
    out.local_user_id = eos_sessions_product_user_id_to_string_internal(p->LocalUserId);
    out.session_id = "";
    out.bucket_id = "";

    if (p->SessionDetails)
    {
        out.session_id = p->SessionDetails->SessionId ? std::string(p->SessionDetails->SessionId) : std::string();
    }

    return out;
}

static gm_structs::EpicSessionsSessionInviteReceivedCallbackInfo eos_sessions_invite_received_info_from_native(
    const EOS_Sessions_SessionInviteReceivedCallbackInfo* p)
{
    gm_structs::EpicSessionsSessionInviteReceivedCallbackInfo out{};
    if (!p)
        return out;

    out.local_user_id = eos_sessions_product_user_id_to_string_internal(p->LocalUserId);
    out.target_user_id = eos_sessions_product_user_id_to_string_internal(p->TargetUserId);
    out.invite_id = p->InviteId ? std::string(p->InviteId) : std::string();
    return out;
}

static gm_structs::EpicSessionsSessionInviteAcceptedCallbackInfo eos_sessions_invite_accepted_info_from_native(
    const EOS_Sessions_SessionInviteAcceptedCallbackInfo* p)
{
    gm_structs::EpicSessionsSessionInviteAcceptedCallbackInfo out{};
    if (!p)
        return out;

    out.local_user_id = eos_sessions_product_user_id_to_string_internal(p->LocalUserId);
    out.target_user_id = eos_sessions_product_user_id_to_string_internal(p->TargetUserId);
    out.invite_id = p->InviteId ? std::string(p->InviteId) : std::string();
    return out;
}

static gm_structs::EpicSessionsJoinSessionAcceptedCallbackInfo eos_sessions_join_accepted_info_from_native(
    const EOS_Sessions_JoinSessionAcceptedCallbackInfo* p)
{
    gm_structs::EpicSessionsJoinSessionAcceptedCallbackInfo out{};
    if (!p)
        return out;

    out.ui_event_id = (uint64_t)p->UiEventId;
    return out;
}

static void EOS_CALL eos_sessions_invite_received_callback_native(
    const EOS_Sessions_SessionInviteReceivedCallbackInfo* data)
{
    if (!data || !g_cb_sessions_invite_received)
        return;

    g_cb_sessions_invite_received.call(
        eos_sessions_invite_received_info_from_native(data)
    );
}

static void EOS_CALL eos_sessions_invite_accepted_callback_native(
    const EOS_Sessions_SessionInviteAcceptedCallbackInfo* data)
{
    if (!data || !g_cb_sessions_invite_accepted)
        return;

    g_cb_sessions_invite_accepted.call(
        eos_sessions_invite_accepted_info_from_native(data)
    );
}

static void EOS_CALL eos_sessions_join_accepted_callback_native(
    const EOS_Sessions_JoinSessionAcceptedCallbackInfo* data)
{
    if (!data || !g_cb_sessions_join_accepted)
        return;

    g_cb_sessions_join_accepted.call(
        eos_sessions_join_accepted_info_from_native(data)
    );
}

uint64_t eos_sessions_copy_active_session_handle(std::string_view session_name)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return 0;
    }

    std::string session_name_storage(session_name);
    if (session_name_storage.empty()) {
        eos_set_last_error("EOS_Sessions_CopyActiveSessionHandle: session_name is required.");
        return 0;
    }

    EOS_Sessions_CopyActiveSessionHandleOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_COPYACTIVESESSIONHANDLE_API_LATEST;
    opts.SessionName = session_name_storage.c_str();

    EOS_HActiveSession active = nullptr;
    const EOS_EResult result = EOS_Sessions_CopyActiveSessionHandle(sessions, &opts, &active);
    if (result != EOS_EResult::EOS_Success || active == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Sessions_CopyActiveSessionHandle failed.");
        return 0;
    }

    return eos_sessions_active_store(active);
}

void eos_sessions_active_session_release(uint64_t active_session_id)
{
    eos_clear_last_error();
    eos_sessions_active_erase(active_session_id);
}

gm_structs::EpicActiveSessionInfo eos_sessions_active_session_copy_info(uint64_t active_session_id)
{
    eos_clear_last_error();

    gm_structs::EpicActiveSessionInfo out{};

    EOS_HActiveSession active = eos_sessions_active_get(active_session_id);
    if (!active) {
        eos_set_last_error("EOS ActiveSession handle invalid.");
        return out;
    }

    EOS_ActiveSession_CopyInfoOptions opts{};
    opts.ApiVersion = EOS_ACTIVESESSION_COPYINFO_API_LATEST;

    EOS_ActiveSession_Info* info = nullptr;
    const EOS_EResult result = EOS_ActiveSession_CopyInfo(active, &opts, &info);
    if (result != EOS_EResult::EOS_Success || info == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_ActiveSession_CopyInfo failed.");
        return out;
    }

    out = eos_sessions_active_session_info_from_native(info);
    EOS_ActiveSession_Info_Release(info);
    return out;
}

uint64_t eos_sessions_copy_session_handle_by_invite_id(std::string_view invite_id)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return 0;
    }

    std::string invite_id_storage(invite_id);
    if (invite_id_storage.empty()) {
        eos_set_last_error("EOS_Sessions_CopySessionHandleByInviteId: invite_id is required.");
        return 0;
    }

    EOS_Sessions_CopySessionHandleByInviteIdOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_COPYSESSIONHANDLEBYINVITEID_API_LATEST;
    opts.InviteId = invite_id_storage.c_str();

    EOS_HSessionDetails details = nullptr;
    const EOS_EResult result = EOS_Sessions_CopySessionHandleByInviteId(sessions, &opts, &details);
    if (result != EOS_EResult::EOS_Success || details == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Sessions_CopySessionHandleByInviteId failed.");
        return 0;
    }

    return eos_sessions_details_store(details);
}

uint64_t eos_sessions_copy_session_handle_by_ui_event_id(uint64_t ui_event_id)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return 0;
    }

    EOS_Sessions_CopySessionHandleByUiEventIdOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_COPYSESSIONHANDLEBYUIEVENTID_API_LATEST;
    opts.UiEventId = (EOS_UI_EventId)ui_event_id;

    EOS_HSessionDetails details = nullptr;
    const EOS_EResult result = EOS_Sessions_CopySessionHandleByUiEventId(sessions, &opts, &details);
    if (result != EOS_EResult::EOS_Success || details == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Sessions_CopySessionHandleByUiEventId failed.");
        return 0;
    }

    return eos_sessions_details_store(details);
}

gm_structs::EpicSessionDetailsInfo eos_sessions_session_details_copy_info(uint64_t session_details_id)
{
    eos_clear_last_error();

    gm_structs::EpicSessionDetailsInfo out{};

    EOS_HSessionDetails details = eos_sessions_details_get(session_details_id);
    if (!details) {
        eos_set_last_error("EOS SessionDetails handle invalid.");
        return out;
    }

    EOS_SessionDetails_CopyInfoOptions opts{};
    opts.ApiVersion = EOS_SESSIONDETAILS_COPYINFO_API_LATEST;

    EOS_SessionDetails_Info* info = nullptr;
    const EOS_EResult result = EOS_SessionDetails_CopyInfo(details, &opts, &info);
    if (result != EOS_EResult::EOS_Success || info == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_SessionDetails_CopyInfo failed.");
        return out;
    }

    out = eos_sessions_session_details_info_from_native(info);
    EOS_SessionDetails_Info_Release(info);
    return out;
}

uint64_t eos_sessions_add_notify_session_invite_received(const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return 0;
    }

    g_cb_sessions_invite_received = callback;

    EOS_Sessions_AddNotifySessionInviteReceivedOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_ADDNOTIFYSESSIONINVITERECEIVED_API_LATEST;

    return (uint64_t)EOS_Sessions_AddNotifySessionInviteReceived(
        sessions,
        &opts,
        nullptr,
        &eos_sessions_invite_received_callback_native
    );
}

void eos_sessions_remove_notify_session_invite_received(uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return;
    }

    EOS_Sessions_RemoveNotifySessionInviteReceived(
        sessions,
        (EOS_NotificationId)notification_id
    );
}

uint64_t eos_sessions_add_notify_session_invite_accepted(const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return 0;
    }

    g_cb_sessions_invite_accepted = callback;

    EOS_Sessions_AddNotifySessionInviteAcceptedOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_ADDNOTIFYSESSIONINVITEACCEPTED_API_LATEST;

    return (uint64_t)EOS_Sessions_AddNotifySessionInviteAccepted(
        sessions,
        &opts,
        nullptr,
        &eos_sessions_invite_accepted_callback_native
    );
}

void eos_sessions_remove_notify_session_invite_accepted(uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return;
    }

    EOS_Sessions_RemoveNotifySessionInviteAccepted(
        sessions,
        (EOS_NotificationId)notification_id
    );
}

uint64_t eos_sessions_add_notify_join_session_accepted(const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return 0;
    }

    g_cb_sessions_join_accepted = callback;

    EOS_Sessions_AddNotifyJoinSessionAcceptedOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_ADDNOTIFYJOINSESSIONACCEPTED_API_LATEST;

    return (uint64_t)EOS_Sessions_AddNotifyJoinSessionAccepted(
        sessions,
        &opts,
        nullptr,
        &eos_sessions_join_accepted_callback_native
    );
}

void eos_sessions_remove_notify_join_session_accepted(uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return;
    }

    EOS_Sessions_RemoveNotifyJoinSessionAccepted(
        sessions,
        (EOS_NotificationId)notification_id
    );
}

// ============================================================
// EOS Sessions (Part 5) — SessionModification setters
// ============================================================

gm_enums::EpicResult eos_sessions_session_modification_set_bucket_id(
    uint64_t modification_id,
    std::string_view bucket_id)
{
    eos_clear_last_error();

    EOS_HSessionModification mod = eos_sessions_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS SessionModification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::string bucket_id_storage(bucket_id);
    if (bucket_id_storage.empty()) {
        eos_set_last_error("EOS_SessionModification_SetBucketId: bucket_id is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_SessionModification_SetBucketIdOptions opts{};
    opts.ApiVersion = EOS_SESSIONMODIFICATION_SETBUCKETID_API_LATEST;
    opts.BucketId = bucket_id_storage.c_str();

    const EOS_EResult result = EOS_SessionModification_SetBucketId(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_SessionModification_SetBucketId failed.");
    }
    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_sessions_session_modification_set_host_address(
    uint64_t modification_id,
    std::string_view host_address)
{
    eos_clear_last_error();

    EOS_HSessionModification mod = eos_sessions_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS SessionModification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::string host_address_storage(host_address);

    EOS_SessionModification_SetHostAddressOptions opts{};
    opts.ApiVersion = EOS_SESSIONMODIFICATION_SETHOSTADDRESS_API_LATEST;
    opts.HostAddress = host_address_storage.empty() ? nullptr : host_address_storage.c_str();

    const EOS_EResult result = EOS_SessionModification_SetHostAddress(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_SessionModification_SetHostAddress failed.");
    }
    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_sessions_session_modification_set_permission_level(
    uint64_t modification_id,
    gm_enums::EpicOnlineSessionPermissionLevel permission_level)
{
    eos_clear_last_error();

    EOS_HSessionModification mod = eos_sessions_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS SessionModification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_SessionModification_SetPermissionLevelOptions opts{};
    opts.ApiVersion = EOS_SESSIONMODIFICATION_SETPERMISSIONLEVEL_API_LATEST;
    opts.PermissionLevel = (EOS_EOnlineSessionPermissionLevel)permission_level;

    const EOS_EResult result = EOS_SessionModification_SetPermissionLevel(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_SessionModification_SetPermissionLevel failed.");
    }
    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_sessions_session_modification_set_join_in_progress_allowed(
    uint64_t modification_id,
    bool allow_join_in_progress)
{
    eos_clear_last_error();

    EOS_HSessionModification mod = eos_sessions_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS SessionModification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_SessionModification_SetJoinInProgressAllowedOptions opts{};
    opts.ApiVersion = EOS_SESSIONMODIFICATION_SETJOININPROGRESSALLOWED_API_LATEST;
    opts.bAllowJoinInProgress = allow_join_in_progress ? EOS_TRUE : EOS_FALSE;

    const EOS_EResult result = EOS_SessionModification_SetJoinInProgressAllowed(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_SessionModification_SetJoinInProgressAllowed failed.");
    }
    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_sessions_session_modification_set_max_players(
    uint64_t modification_id,
    int64_t max_players)
{
    eos_clear_last_error();

    EOS_HSessionModification mod = eos_sessions_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS SessionModification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_SessionModification_SetMaxPlayersOptions opts{};
    opts.ApiVersion = EOS_SESSIONMODIFICATION_SETMAXPLAYERS_API_LATEST;
    opts.MaxPlayers = (uint32_t)max_players;

    const EOS_EResult result = EOS_SessionModification_SetMaxPlayers(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_SessionModification_SetMaxPlayers failed.");
    }
    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_sessions_session_modification_set_invites_allowed(
    uint64_t modification_id,
    bool invites_allowed)
{
    eos_clear_last_error();

    EOS_HSessionModification mod = eos_sessions_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS SessionModification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_SessionModification_SetInvitesAllowedOptions opts{};
    opts.ApiVersion = EOS_SESSIONMODIFICATION_SETINVITESALLOWED_API_LATEST;
    opts.bInvitesAllowed = invites_allowed ? EOS_TRUE : EOS_FALSE;

    const EOS_EResult result = EOS_SessionModification_SetInvitesAllowed(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_SessionModification_SetInvitesAllowed failed.");
    }
    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_sessions_session_modification_add_attribute(
    uint64_t modification_id,
    std::string_view key,
    std::string_view value,
    gm_enums::EpicSessionAttributeAdvertisementType advertisement_type)
{
    eos_clear_last_error();

    EOS_HSessionModification mod = eos_sessions_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS SessionModification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::string key_storage(key);
    std::string value_storage(value);

    if (key_storage.empty()) {
        eos_set_last_error("EOS_SessionModification_AddAttribute: key is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_Sessions_AttributeData attr{};
    attr.ApiVersion = EOS_SESSIONS_ATTRIBUTEDATA_API_LATEST;
    attr.Key = key_storage.c_str();
    attr.Value.AsUtf8 = value_storage.c_str();
    attr.ValueType = EOS_ESessionAttributeType::EOS_AT_STRING;

    EOS_SessionModification_AddAttributeOptions opts{};
    opts.ApiVersion = EOS_SESSIONMODIFICATION_ADDATTRIBUTE_API_LATEST;
    opts.SessionAttribute = &attr;
    opts.AdvertisementType = (EOS_ESessionAttributeAdvertisementType)advertisement_type;

    const EOS_EResult result = EOS_SessionModification_AddAttribute(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_SessionModification_AddAttribute failed.");
    }
    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_sessions_session_modification_remove_attribute(
    uint64_t modification_id,
    std::string_view key)
{
    eos_clear_last_error();

    EOS_HSessionModification mod = eos_sessions_modification_get(modification_id);
    if (!mod) {
        eos_set_last_error("EOS SessionModification handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::string key_storage(key);
    if (key_storage.empty()) {
        eos_set_last_error("EOS_SessionModification_RemoveAttribute: key is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_SessionModification_RemoveAttributeOptions opts{};
    opts.ApiVersion = EOS_SESSIONMODIFICATION_REMOVEATTRIBUTE_API_LATEST;
    opts.Key = key_storage.c_str();

    const EOS_EResult result = EOS_SessionModification_RemoveAttribute(mod, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_SessionModification_RemoveAttribute failed.");
    }
    return (gm_enums::EpicResult)result;
}

// ============================================================
// EOS Sessions (Part 6) — SessionDetails attribute accessors
// ============================================================

static gm_structs::EpicSessionDetailsAttribute eos_sessions_attribute_from_native(
    const EOS_SessionDetails_Attribute* a)
{
    gm_structs::EpicSessionDetailsAttribute out{};
    if (!a || !a->Data) return out;

    out.key = a->Data->Key ? std::string(a->Data->Key) : std::string();
    out.advertisement_type = (gm_enums::EpicSessionAttributeAdvertisementType)a->AdvertisementType;
    out.value_type = (gm_enums::EpicAttributeType)a->Data->ValueType;
    switch (a->Data->ValueType) {
        case EOS_EAttributeType::EOS_AT_BOOLEAN:
            out.value = a->Data->Value.AsBool ? "true" : "false";
            break;
        case EOS_EAttributeType::EOS_AT_INT64:
            out.value = std::to_string(a->Data->Value.AsInt64);
            break;
        case EOS_EAttributeType::EOS_AT_DOUBLE:
            out.value = std::to_string(a->Data->Value.AsDouble);
            break;
        case EOS_EAttributeType::EOS_AT_STRING:
        default:
            out.value = a->Data->Value.AsUtf8 ? std::string(a->Data->Value.AsUtf8) : std::string();
            break;
    }
    return out;
}

int64_t eos_sessions_session_details_get_session_attribute_count(uint64_t session_details_id)
{
    eos_clear_last_error();

    EOS_HSessionDetails details = eos_sessions_details_get(session_details_id);
    if (!details) {
        eos_set_last_error("EOS SessionDetails handle invalid.");
        return 0;
    }

    EOS_SessionDetails_GetSessionAttributeCountOptions opts{};
    opts.ApiVersion = EOS_SESSIONDETAILS_GETSESSIONATTRIBUTECOUNT_API_LATEST;
    return (int64_t)EOS_SessionDetails_GetSessionAttributeCount(details, &opts);
}

gm_structs::EpicSessionDetailsAttribute eos_sessions_session_details_copy_session_attribute_by_index(
    uint64_t session_details_id,
    int64_t index)
{
    eos_clear_last_error();
    gm_structs::EpicSessionDetailsAttribute out{};

    EOS_HSessionDetails details = eos_sessions_details_get(session_details_id);
    if (!details) {
        eos_set_last_error("EOS SessionDetails handle invalid.");
        return out;
    }

    EOS_SessionDetails_CopySessionAttributeByIndexOptions opts{};
    opts.ApiVersion = EOS_SESSIONDETAILS_COPYSESSIONATTRIBUTEBYINDEX_API_LATEST;
    opts.AttrIndex = (uint32_t)index;

    EOS_SessionDetails_Attribute* attr = nullptr;
    const EOS_EResult result = EOS_SessionDetails_CopySessionAttributeByIndex(details, &opts, &attr);
    if (result != EOS_EResult::EOS_Success || !attr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_SessionDetails_CopySessionAttributeByIndex failed.");
        return out;
    }

    out = eos_sessions_attribute_from_native(attr);
    EOS_SessionDetails_Attribute_Release(attr);
    return out;
}

gm_structs::EpicSessionDetailsAttribute eos_sessions_session_details_copy_session_attribute_by_key(
    uint64_t session_details_id,
    std::string_view key)
{
    eos_clear_last_error();
    gm_structs::EpicSessionDetailsAttribute out{};

    EOS_HSessionDetails details = eos_sessions_details_get(session_details_id);
    if (!details) {
        eos_set_last_error("EOS SessionDetails handle invalid.");
        return out;
    }

    std::string key_storage(key);
    if (key_storage.empty()) {
        eos_set_last_error("EOS_SessionDetails_CopySessionAttributeByKey: key is required.");
        return out;
    }

    EOS_SessionDetails_CopySessionAttributeByKeyOptions opts{};
    opts.ApiVersion = EOS_SESSIONDETAILS_COPYSESSIONATTRIBUTEBYKEY_API_LATEST;
    opts.AttrKey = key_storage.c_str();

    EOS_SessionDetails_Attribute* attr = nullptr;
    const EOS_EResult result = EOS_SessionDetails_CopySessionAttributeByKey(details, &opts, &attr);
    if (result != EOS_EResult::EOS_Success || !attr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_SessionDetails_CopySessionAttributeByKey failed.");
        return out;
    }

    out = eos_sessions_attribute_from_native(attr);
    EOS_SessionDetails_Attribute_Release(attr);
    return out;
}

// ============================================================
// EOS Sessions (Part 7) — ActiveSession player accessors
// ============================================================

int64_t eos_sessions_active_session_get_registered_player_count(uint64_t active_session_id)
{
    eos_clear_last_error();

    EOS_HActiveSession active = eos_sessions_active_get(active_session_id);
    if (!active) {
        eos_set_last_error("EOS ActiveSession handle invalid.");
        return 0;
    }

    EOS_ActiveSession_GetRegisteredPlayerCountOptions opts{};
    opts.ApiVersion = EOS_ACTIVESESSION_GETREGISTEREDPLAYERCOUNT_API_LATEST;
    return (int64_t)EOS_ActiveSession_GetRegisteredPlayerCount(active, &opts);
}

std::string eos_sessions_active_session_get_registered_player_by_index(
    uint64_t active_session_id,
    int64_t index)
{
    eos_clear_last_error();

    EOS_HActiveSession active = eos_sessions_active_get(active_session_id);
    if (!active) {
        eos_set_last_error("EOS ActiveSession handle invalid.");
        return std::string();
    }

    EOS_ActiveSession_GetRegisteredPlayerByIndexOptions opts{};
    opts.ApiVersion = EOS_ACTIVESESSION_GETREGISTEREDPLAYERBYINDEX_API_LATEST;
    opts.PlayerIndex = (uint32_t)index;

    EOS_ProductUserId player = EOS_ActiveSession_GetRegisteredPlayerByIndex(active, &opts);
    return eos_sessions_product_user_id_to_string_internal(player);
}

// ============================================================
// EOS Sessions (Part 8) — Invite flow
// ============================================================

static void EOS_CALL eos_sessions_send_invite_callback_native(
    const EOS_Sessions_SendInviteCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicSessionsSendInviteCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    ctx->callback.call(out);
    delete ctx;
}

static void EOS_CALL eos_sessions_reject_invite_callback_native(
    const EOS_Sessions_RejectInviteCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicSessionsRejectInviteCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    ctx->callback.call(out);
    delete ctx;
}

static void EOS_CALL eos_sessions_query_invites_callback_native(
    const EOS_Sessions_QueryInvitesCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicSessionsQueryInvitesCallbackInfo out{};
    out.result_code = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_sessions_product_user_id_to_string_internal(data->LocalUserId);
    ctx->callback.call(out);
    delete ctx;
}

void eos_sessions_send_invite(
    std::string_view session_name,
    std::string_view local_user_id,
    std::string_view target_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return;
    }

    std::string session_name_storage(session_name);
    if (session_name_storage.empty()) {
        eos_set_last_error("EOS_Sessions_SendInvite: session_name is required.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Sessions_SendInvite: invalid local_user_id.");
        return;
    }

    EOS_ProductUserId target_user = eos_product_user_id_from_string_internal(target_user_id);
    if (!target_user) {
        eos_set_last_error("EOS_Sessions_SendInvite: invalid target_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Sessions_SendInviteOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_SENDINVITE_API_LATEST;
    opts.SessionName = session_name_storage.c_str();
    opts.LocalUserId = local_user;
    opts.TargetUserId = target_user;

    EOS_Sessions_SendInvite(sessions, &opts, ctx, &eos_sessions_send_invite_callback_native);
}

void eos_sessions_reject_invite(
    std::string_view local_user_id,
    std::string_view invite_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Sessions_RejectInvite: invalid local_user_id.");
        return;
    }

    std::string invite_id_storage(invite_id);
    if (invite_id_storage.empty()) {
        eos_set_last_error("EOS_Sessions_RejectInvite: invite_id is required.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Sessions_RejectInviteOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_REJECTINVITE_API_LATEST;
    opts.LocalUserId = local_user;
    opts.InviteId = invite_id_storage.c_str();

    EOS_Sessions_RejectInvite(sessions, &opts, ctx, &eos_sessions_reject_invite_callback_native);
}

void eos_sessions_query_invites(
    std::string_view local_user_id,
    const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Sessions_QueryInvites: invalid local_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_Sessions_QueryInvitesOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_QUERYINVITES_API_LATEST;
    opts.LocalUserId = local_user;

    EOS_Sessions_QueryInvites(sessions, &opts, ctx, &eos_sessions_query_invites_callback_native);
}

int64_t eos_sessions_get_invite_count(std::string_view local_user_id)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return 0;
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Sessions_GetInviteCount: invalid local_user_id.");
        return 0;
    }

    EOS_Sessions_GetInviteCountOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_GETINVITECOUNT_API_LATEST;
    opts.LocalUserId = local_user;

    return (int64_t)EOS_Sessions_GetInviteCount(sessions, &opts);
}

std::string eos_sessions_get_invite_id_by_index(
    std::string_view local_user_id,
    int64_t index)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return std::string();
    }

    EOS_ProductUserId local_user = eos_product_user_id_from_string_internal(local_user_id);
    if (!local_user) {
        eos_set_last_error("EOS_Sessions_GetInviteIdByIndex: invalid local_user_id.");
        return std::string();
    }

    EOS_Sessions_GetInviteIdByIndexOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_GETINVITEIDBYINDEX_API_LATEST;
    opts.LocalUserId = local_user;
    opts.Index = (uint32_t)index;

    char buf[EOS_SESSIONS_INVITEID_MAX_LENGTH + 1] = {};
    int32_t len = (int32_t)sizeof(buf);
    const EOS_EResult result = EOS_Sessions_GetInviteIdByIndex(sessions, &opts, buf, &len);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Sessions_GetInviteIdByIndex failed.");
        return std::string();
    }
    return std::string(buf);
}

// ============================================================
// EOS Sessions (Part 9) — SessionSearch parameter functions
// ============================================================

gm_enums::EpicResult eos_sessions_session_search_set_parameter(
    uint64_t search_id,
    std::string_view key,
    std::string_view value,
    gm_enums::EpicComparisonOp comparison_op)
{
    eos_clear_last_error();

    EOS_HSessionSearch search = eos_sessions_search_get(search_id);
    if (!search) {
        eos_set_last_error("EOS SessionSearch handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::string key_storage(key);
    std::string value_storage(value);

    if (key_storage.empty()) {
        eos_set_last_error("EOS_SessionSearch_SetParameter: key is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_Sessions_AttributeData attr{};
    attr.ApiVersion = EOS_SESSIONS_ATTRIBUTEDATA_API_LATEST;
    attr.Key = key_storage.c_str();
    attr.Value.AsUtf8 = value_storage.c_str();
    attr.ValueType = EOS_ESessionAttributeType::EOS_AT_STRING;

    EOS_SessionSearch_SetParameterOptions opts{};
    opts.ApiVersion = EOS_SESSIONSEARCH_SETPARAMETER_API_LATEST;
    opts.Parameter = &attr;
    opts.ComparisonOp = (EOS_EOnlineComparisonOp)comparison_op;

    const EOS_EResult result = EOS_SessionSearch_SetParameter(search, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_SessionSearch_SetParameter failed.");
    }
    return (gm_enums::EpicResult)result;
}

gm_enums::EpicResult eos_sessions_session_search_remove_parameter(
    uint64_t search_id,
    std::string_view key,
    gm_enums::EpicComparisonOp comparison_op)
{
    eos_clear_last_error();

    EOS_HSessionSearch search = eos_sessions_search_get(search_id);
    if (!search) {
        eos_set_last_error("EOS SessionSearch handle invalid.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    std::string key_storage(key);
    if (key_storage.empty()) {
        eos_set_last_error("EOS_SessionSearch_RemoveParameter: key is required.");
        return (gm_enums::EpicResult)EOS_EResult::EOS_InvalidParameters;
    }

    EOS_SessionSearch_RemoveParameterOptions opts{};
    opts.ApiVersion = EOS_SESSIONSEARCH_REMOVEPARAMETER_API_LATEST;
    opts.Key = key_storage.c_str();
    opts.ComparisonOp = (EOS_EOnlineComparisonOp)comparison_op;

    const EOS_EResult result = EOS_SessionSearch_RemoveParameter(search, &opts);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_SessionSearch_RemoveParameter failed.");
    }
    return (gm_enums::EpicResult)result;
}

int64_t eos_sessions_session_search_get_search_result_count(uint64_t search_id)
{
    eos_clear_last_error();

    EOS_HSessionSearch search = eos_sessions_search_get(search_id);
    if (!search) {
        eos_set_last_error("EOS SessionSearch handle invalid.");
        return 0;
    }

    EOS_SessionSearch_GetSearchResultCountOptions opts{};
    opts.ApiVersion = EOS_SESSIONSEARCH_GETSEARCHRESULTCOUNT_API_LATEST;
    return (int64_t)EOS_SessionSearch_GetSearchResultCount(search, &opts);
}

// ============================================================
// EOS Sessions (Part 10) — Additional notifications
// ============================================================

static GMFunction g_cb_sessions_invite_rejected = nullptr;
static GMFunction g_cb_sessions_leave_requested = nullptr;
static GMFunction g_cb_sessions_native_invite_requested = nullptr;

static void EOS_CALL eos_sessions_invite_rejected_callback_native(
    const EOS_Sessions_SessionInviteRejectedCallbackInfo* data)
{
    if (!data || !g_cb_sessions_invite_rejected) return;

    gm_structs::EpicSessionsSessionInviteRejectedCallbackInfo out{};
    out.invite_id = data->InviteId ? std::string(data->InviteId) : std::string();
    out.local_user_id = eos_sessions_product_user_id_to_string_internal(data->LocalUserId);
    out.target_user_id = eos_sessions_product_user_id_to_string_internal(data->TargetUserId);
    out.session_id = data->SessionId ? std::string(data->SessionId) : std::string();
    g_cb_sessions_invite_rejected.call(out);
}

static void EOS_CALL eos_sessions_leave_requested_callback_native(
    const EOS_Sessions_LeaveSessionRequestedCallbackInfo* data)
{
    if (!data || !g_cb_sessions_leave_requested) return;

    gm_structs::EpicSessionsLeaveSessionRequestedCallbackInfo out{};
    out.local_user_id = eos_sessions_product_user_id_to_string_internal(data->LocalUserId);
    out.session_name = data->SessionName ? std::string(data->SessionName) : std::string();
    g_cb_sessions_leave_requested.call(out);
}

static void EOS_CALL eos_sessions_native_invite_requested_callback_native(
    const EOS_Sessions_SendSessionNativeInviteRequestedCallbackInfo* data)
{
    if (!data || !g_cb_sessions_native_invite_requested) return;

    gm_structs::EpicSessionsSendSessionNativeInviteRequestedCallbackInfo out{};
    out.ui_event_id = (uint64_t)data->UiEventId;
    out.local_user_id = eos_sessions_product_user_id_to_string_internal(data->LocalUserId);
    out.session_id = data->SessionId ? std::string(data->SessionId) : std::string();
    g_cb_sessions_native_invite_requested.call(out);
}

uint64_t eos_sessions_add_notify_session_invite_rejected(const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return 0;
    }

    g_cb_sessions_invite_rejected = callback;

    EOS_Sessions_AddNotifySessionInviteRejectedOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_ADDNOTIFYSESSIONINVITEREJECTED_API_LATEST;

    return (uint64_t)EOS_Sessions_AddNotifySessionInviteRejected(
        sessions, &opts, nullptr, &eos_sessions_invite_rejected_callback_native);
}

void eos_sessions_remove_notify_session_invite_rejected(uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return;
    }

    EOS_Sessions_RemoveNotifySessionInviteRejected(sessions, (EOS_NotificationId)notification_id);
}

uint64_t eos_sessions_add_notify_leave_session_requested(const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return 0;
    }

    g_cb_sessions_leave_requested = callback;

    EOS_Sessions_AddNotifyLeaveSessionRequestedOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_ADDNOTIFYLEAVESESSIONREQUESTED_API_LATEST;

    return (uint64_t)EOS_Sessions_AddNotifyLeaveSessionRequested(
        sessions, &opts, nullptr, &eos_sessions_leave_requested_callback_native);
}

void eos_sessions_remove_notify_leave_session_requested(uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return;
    }

    EOS_Sessions_RemoveNotifyLeaveSessionRequested(sessions, (EOS_NotificationId)notification_id);
}

uint64_t eos_sessions_add_notify_send_session_native_invite_requested(const GMFunction& callback)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return 0;
    }

    g_cb_sessions_native_invite_requested = callback;

    EOS_Sessions_AddNotifySendSessionNativeInviteRequestedOptions opts{};
    opts.ApiVersion = EOS_SESSIONS_ADDNOTIFYSENDSESSIONNATIVEINVITEREQUESTED_API_LATEST;

    return (uint64_t)EOS_Sessions_AddNotifySendSessionNativeInviteRequested(
        sessions, &opts, nullptr, &eos_sessions_native_invite_requested_callback_native);
}

void eos_sessions_remove_notify_send_session_native_invite_requested(uint64_t notification_id)
{
    eos_clear_last_error();

    EOS_HSessions sessions = eos_sessions_iface();
    if (!sessions) {
        eos_set_last_error("EOS Sessions interface unavailable.");
        return;
    }

    EOS_Sessions_RemoveNotifySendSessionNativeInviteRequested(
        sessions, (EOS_NotificationId)notification_id);
}
