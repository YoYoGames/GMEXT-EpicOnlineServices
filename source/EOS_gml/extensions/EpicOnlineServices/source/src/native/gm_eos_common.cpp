#include "gm_eos_common.h"

EOS_ProductUserId eos_product_user_id_from_string_internal(std::string_view product_user_id)
{
    std::string value(product_user_id);
    if (value.empty())
        return nullptr;
    return EOS_ProductUserId_FromString(value.c_str());
}

std::string eos_product_user_id_to_string_internal(EOS_ProductUserId product_user_id)
{
    if (!product_user_id)
        return std::string();

    return eos_copy_string_with_fixed_retry(
        [&](char* out_buffer, int32_t* inout_len) -> EOS_EResult
        {
            return EOS_ProductUserId_ToString(product_user_id, out_buffer, inout_len);
        });
}

EOS_EpicAccountId eos_epic_account_id_from_string_internal(std::string_view account_id)
{
    std::string value(account_id);
    if (value.empty())
        return nullptr;
    return EOS_EpicAccountId_FromString(value.c_str());
}

std::string eos_epic_account_id_to_string_internal(EOS_EpicAccountId account_id)
{
    if (!account_id)
        return std::string();

    return eos_copy_string_with_fixed_retry(
        [&](char* out_buffer, int32_t* inout_len) -> EOS_EResult
        {
            return EOS_EpicAccountId_ToString(account_id, out_buffer, inout_len);
        });
}

std::string eos_result_string(EOS_EResult result)
{
    const char* s = EOS_EResult_ToString(result);
    return s ? std::string(s) : std::string();
}
