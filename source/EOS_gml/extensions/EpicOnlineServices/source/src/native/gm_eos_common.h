#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

// Use the EOS umbrella header, not eos_common.h directly.
#include <eos_sdk.h>

// The EOS *_ToString entry points report the size they need through
// EOS_LimitExceeded instead of writing a truncated value, so a fixed buffer has
// to be retried at the reported length.
template <typename Fn>
inline std::string eos_copy_string_with_fixed_retry(Fn&& call_fn, size_t initial_capacity = 256)
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

EOS_ProductUserId eos_product_user_id_from_string_internal(std::string_view product_user_id);
std::string eos_product_user_id_to_string_internal(EOS_ProductUserId product_user_id);

EOS_EpicAccountId eos_epic_account_id_from_string_internal(std::string_view account_id);
std::string eos_epic_account_id_to_string_internal(EOS_EpicAccountId account_id);

std::string eos_result_string(EOS_EResult result);
