#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_userinfo.h>

#include <cstdint>
#include <optional>
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
    std::optional<GMFunction> callback;
};

static EOS_HUserInfo eos_user_info_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetUserInfoInterface(p) : nullptr;
}

template <typename Fn>
static std::string eos_user_info_copy_string_with_fixed_retry(Fn&& call_fn, size_t initial_capacity = 256)
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

static EOS_EpicAccountId eos_epic_account_id_from_string_internal(std::string_view account_id)
{
    std::string value(account_id);
    if (value.empty())
        return nullptr;
    return EOS_EpicAccountId_FromString(value.c_str());
}

static std::string eos_epic_account_id_to_string_internal(EOS_EpicAccountId account_id)
{
    if (!account_id)
        return std::string();

    return eos_user_info_copy_string_with_fixed_retry(
        [&](char* out_buffer, int32_t* inout_len) -> EOS_EResult
        {
            return EOS_EpicAccountId_ToString(account_id, out_buffer, inout_len);
        });
}

static gm_structs::EpicUserInfo eos_user_info_from_native(const EOS_UserInfo* p)
{
    gm_structs::EpicUserInfo out{};
    if (!p)
        return out;

    out.user_id = eos_epic_account_id_to_string_internal(p->UserId);
    out.country = p->Country ? std::string(p->Country) : std::string();
    out.display_name = p->DisplayName ? std::string(p->DisplayName) : std::string();
    out.preferred_language = p->PreferredLanguage ? std::string(p->PreferredLanguage) : std::string();
    out.nickname = p->Nickname ? std::string(p->Nickname) : std::string();

    return out;
}

static gm_structs::EpicUserInfoQueryUserInfoCallbackInfo eos_user_info_query_user_info_info_from_native(
    const EOS_UserInfo_QueryUserInfoCallbackInfo* p)
{
    gm_structs::EpicUserInfoQueryUserInfoCallbackInfo out{};
    if (!p)
        return out;

    out.result_code = (gm_enums::EpicResult)p->ResultCode;
    out.local_user_id = eos_epic_account_id_to_string_internal(p->LocalUserId);
    out.target_user_id = eos_epic_account_id_to_string_internal(p->TargetUserId);

    return out;
}

static void EOS_CALL eos_user_info_query_user_info_callback_native(
    const EOS_UserInfo_QueryUserInfoCallbackInfo* data)
{
    if (!data)
        return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx)
        return;
    if (ctx->callback) ctx->callback.value().call(
        eos_user_info_query_user_info_info_from_native(data)
    );
    delete ctx;
}

// ============================================================
// EOS UserInfo (Part 1)
// ============================================================

void eos_user_info_query_user_info(
    std::string_view local_user_id,
    std::string_view target_user_id,
    const std::optional<gm::wire::GMFunction>& callback)
{
    eos_clear_last_error();

    EOS_HUserInfo user_info = eos_user_info_iface();
    if (!user_info) {
        eos_set_last_error("EOS UserInfo interface unavailable.");
        return;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    EOS_EpicAccountId target_user = eos_epic_account_id_from_string_internal(target_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_UserInfo_QueryUserInfo: invalid local_user_id.");
        return;
    }

    if (!target_user) {
        eos_set_last_error("EOS_UserInfo_QueryUserInfo: invalid target_user_id.");
        return;
    }

    auto* ctx = new EOSAsyncCallbackContext{};
    ctx->callback = callback;

    EOS_UserInfo_QueryUserInfoOptions opts{};
    opts.ApiVersion = EOS_USERINFO_QUERYUSERINFO_API_LATEST;
    opts.LocalUserId = local_user;
    opts.TargetUserId = target_user;
    EOS_UserInfo_QueryUserInfo(
        user_info,
        &opts,
        ctx,
        &eos_user_info_query_user_info_callback_native);
}

gm_structs::EpicUserInfo eos_user_info_copy_user_info(
    std::string_view local_user_id,
    std::string_view target_user_id)
{
    eos_clear_last_error();

    gm_structs::EpicUserInfo out{};

    EOS_HUserInfo user_info = eos_user_info_iface();
    if (!user_info) {
        eos_set_last_error("EOS UserInfo interface unavailable.");
        return out;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    EOS_EpicAccountId target_user = eos_epic_account_id_from_string_internal(target_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_UserInfo_CopyUserInfo: invalid local_user_id.");
        return out;
    }

    if (!target_user) {
        eos_set_last_error("EOS_UserInfo_CopyUserInfo: invalid target_user_id.");
        return out;
    }

    EOS_UserInfo_CopyUserInfoOptions opts{};
    opts.ApiVersion = EOS_USERINFO_COPYUSERINFO_API_LATEST;
    opts.LocalUserId = local_user;
    opts.TargetUserId = target_user;

    EOS_UserInfo* info = nullptr;
    const EOS_EResult result = EOS_UserInfo_CopyUserInfo(user_info, &opts, &info);
    if (result != EOS_EResult::EOS_Success || info == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_UserInfo_CopyUserInfo failed.");
        return out;
    }

    out = eos_user_info_from_native(info);
    EOS_UserInfo_Release(info);
    return out;
}

gm_enums::EpicExternalAccountType eos_user_info_get_local_platform_type()
{
    eos_clear_last_error();

    EOS_HUserInfo user_info = eos_user_info_iface();
    if (!user_info) {
        eos_set_last_error("EOS UserInfo interface unavailable.");
        return (gm_enums::EpicExternalAccountType)0;
    }

    EOS_UserInfo_GetLocalPlatformTypeOptions opts{};
    opts.ApiVersion = EOS_USERINFO_GETLOCALPLATFORMTYPE_API_LATEST;

    return (gm_enums::EpicExternalAccountType)EOS_UserInfo_GetLocalPlatformType(user_info, &opts);
}

std::string eos_user_info_copy_best_display_name(
    std::string_view local_user_id,
    std::string_view target_user_id)
{
    return "";
    //TODO
    // eos_clear_last_error();

    // EOS_HUserInfo user_info = eos_user_info_iface();
    // if (!user_info) {
    //     eos_set_last_error("EOS UserInfo interface unavailable.");
    //     return std::string();
    // }

    // EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    // EOS_EpicAccountId target_user = eos_epic_account_id_from_string_internal(target_user_id);

    // if (!local_user) {
    //     eos_set_last_error("EOS_UserInfo_CopyBestDisplayName: invalid local_user_id.");
    //     return std::string();
    // }

    // if (!target_user) {
    //     eos_set_last_error("EOS_UserInfo_CopyBestDisplayName: invalid target_user_id.");
    //     return std::string();
    // }

    // EOS_UserInfo_CopyBestDisplayNameOptions opts{};
    // opts.ApiVersion = EOS_USERINFO_COPYBESTDISPLAYNAME_API_LATEST;
    // opts.LocalUserId = local_user;
    // opts.TargetUserId = target_user;

    // return eos_user_info_copy_string_with_fixed_retry(
    //     [&](char* out_buffer, int32_t* inout_len) -> EOS_EResult
    //     {
    //         return EOS_UserInfo_CopyBestDisplayName(user_info, &opts, out_buffer, inout_len);
    //     });
}


// ============================================================
// EOS UserInfo (Part 2)
// ============================================================

static gm_structs::EpicUserInfoExternalUserInfo eos_user_info_external_user_info_from_native(
    const EOS_UserInfo_ExternalUserInfo* p)
{
    gm_structs::EpicUserInfoExternalUserInfo out{};
    if (!p)
        return out;

    out.account_id = p->AccountId ? std::string(p->AccountId) : std::string();
    out.account_type = (gm_enums::EpicExternalAccountType)p->AccountType;
    out.display_name = p->DisplayName ? std::string(p->DisplayName) : std::string();

    return out;
}

gm_structs::EpicUserInfoExternalUserInfo eos_user_info_copy_external_user_info_by_index(
    std::string_view local_user_id,
    std::string_view target_user_id,
    int64_t index)
{
    eos_clear_last_error();

    gm_structs::EpicUserInfoExternalUserInfo out{};

    EOS_HUserInfo user_info = eos_user_info_iface();
    if (!user_info) {
        eos_set_last_error("EOS UserInfo interface unavailable.");
        return out;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    EOS_EpicAccountId target_user = eos_epic_account_id_from_string_internal(target_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_UserInfo_CopyExternalUserInfoByIndex: invalid local_user_id.");
        return out;
    }

    if (!target_user) {
        eos_set_last_error("EOS_UserInfo_CopyExternalUserInfoByIndex: invalid target_user_id.");
        return out;
    }

    EOS_UserInfo_CopyExternalUserInfoByIndexOptions opts{};
    opts.ApiVersion = EOS_USERINFO_COPYEXTERNALUSERINFOBYINDEX_API_LATEST;
    opts.LocalUserId = local_user;
    opts.TargetUserId = target_user;
    opts.Index = (uint32_t)index;

    EOS_UserInfo_ExternalUserInfo* info = nullptr;
    const EOS_EResult result = EOS_UserInfo_CopyExternalUserInfoByIndex(user_info, &opts, &info);
    if (result != EOS_EResult::EOS_Success || info == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_UserInfo_CopyExternalUserInfoByIndex failed.");
        return out;
    }

    out = eos_user_info_external_user_info_from_native(info);
    EOS_UserInfo_ExternalUserInfo_Release(info);
    return out;
}

gm_structs::EpicUserInfoExternalUserInfo eos_user_info_copy_external_user_info_by_account_type(
    std::string_view local_user_id,
    std::string_view target_user_id,
    gm_enums::EpicExternalAccountType account_type)
{
    eos_clear_last_error();

    gm_structs::EpicUserInfoExternalUserInfo out{};

    EOS_HUserInfo user_info = eos_user_info_iface();
    if (!user_info) {
        eos_set_last_error("EOS UserInfo interface unavailable.");
        return out;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    EOS_EpicAccountId target_user = eos_epic_account_id_from_string_internal(target_user_id);

    if (!local_user) {
        eos_set_last_error("EOS_UserInfo_CopyExternalUserInfoByAccountType: invalid local_user_id.");
        return out;
    }

    if (!target_user) {
        eos_set_last_error("EOS_UserInfo_CopyExternalUserInfoByAccountType: invalid target_user_id.");
        return out;
    }

    EOS_UserInfo_CopyExternalUserInfoByAccountTypeOptions opts{};
    opts.ApiVersion = EOS_USERINFO_COPYEXTERNALUSERINFOBYACCOUNTTYPE_API_LATEST;
    opts.LocalUserId = local_user;
    opts.TargetUserId = target_user;
    opts.AccountType = (EOS_EExternalAccountType)account_type;

    EOS_UserInfo_ExternalUserInfo* info = nullptr;
    const EOS_EResult result = EOS_UserInfo_CopyExternalUserInfoByAccountType(user_info, &opts, &info);
    if (result != EOS_EResult::EOS_Success || info == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_UserInfo_CopyExternalUserInfoByAccountType failed.");
        return out;
    }

    out = eos_user_info_external_user_info_from_native(info);
    EOS_UserInfo_ExternalUserInfo_Release(info);
    return out;
}

gm_structs::EpicUserInfoExternalUserInfo eos_user_info_copy_external_user_info_by_account_id(
    std::string_view local_user_id,
    std::string_view target_user_id,
    std::string_view account_id)
{
    eos_clear_last_error();

    gm_structs::EpicUserInfoExternalUserInfo out{};

    EOS_HUserInfo user_info = eos_user_info_iface();
    if (!user_info) {
        eos_set_last_error("EOS UserInfo interface unavailable.");
        return out;
    }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    EOS_EpicAccountId target_user = eos_epic_account_id_from_string_internal(target_user_id);
    std::string account_id_storage(account_id);

    if (!local_user) {
        eos_set_last_error("EOS_UserInfo_CopyExternalUserInfoByAccountId: invalid local_user_id.");
        return out;
    }

    if (!target_user) {
        eos_set_last_error("EOS_UserInfo_CopyExternalUserInfoByAccountId: invalid target_user_id.");
        return out;
    }

    if (account_id_storage.empty()) {
        eos_set_last_error("EOS_UserInfo_CopyExternalUserInfoByAccountId: account_id is required.");
        return out;
    }

    EOS_UserInfo_CopyExternalUserInfoByAccountIdOptions opts{};
    opts.ApiVersion = EOS_USERINFO_COPYEXTERNALUSERINFOBYACCOUNTID_API_LATEST;
    opts.LocalUserId = local_user;
    opts.TargetUserId = target_user;
    opts.AccountId = account_id_storage.c_str();

    EOS_UserInfo_ExternalUserInfo* info = nullptr;
    const EOS_EResult result = EOS_UserInfo_CopyExternalUserInfoByAccountId(user_info, &opts, &info);
    if (result != EOS_EResult::EOS_Success || info == nullptr) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_UserInfo_CopyExternalUserInfoByAccountId failed.");
        return out;
    }

    out = eos_user_info_external_user_info_from_native(info);
    EOS_UserInfo_ExternalUserInfo_Release(info);
    return out;
}

