#include "EpicOnlineServices_native.h"
#include "GMEpicGames.h"

#include <eos_sdk.h>
#include <eos_ecom.h>

#include <cstdint>
#include <optional>
#include <cstring>
#include <mutex>
#include <string>
#include <string_view>
#include <unordered_map>
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

static EOS_HEcom eos_ecom_iface()
{
    EOS_HPlatform p = eos_platform_get();
    return p ? EOS_Platform_GetEcomInterface(p) : nullptr;
}

static EOS_EpicAccountId eos_epic_account_id_from_string_internal(std::string_view id)
{
    std::string v(id);
    if (v.empty()) return nullptr;
    return EOS_EpicAccountId_FromString(v.c_str());
}

static std::string eos_epic_account_id_to_string_internal(EOS_EpicAccountId id)
{
    if (!id) return std::string();
    char buf[64] = {};
    int32_t len = (int32_t)sizeof(buf);
    if (EOS_EpicAccountId_ToString(id, buf, &len) != EOS_EResult::EOS_Success)
        return std::string();
    return std::string(buf);
}

static std::string join_cstring_array(const char* const* arr, uint32_t count, char delim = '|')
{
    std::string out;
    for (uint32_t i = 0; i < count; ++i) {
        if (i > 0) out += delim;
        if (arr[i]) out += arr[i];
    }
    return out;
}

// ---- Entitlement struct conversion ----

static gm_structs::EpicEcomEntitlement eos_ecom_entitlement_from_native(
    const EOS_Ecom_Entitlement* e)
{
    gm_structs::EpicEcomEntitlement out{};
    if (!e) return out;
    out.entitlement_name = e->EntitlementName ? std::string(e->EntitlementName) : std::string();
    out.entitlement_id   = e->EntitlementId   ? std::string(e->EntitlementId)   : std::string();
    out.catalog_item_id  = e->CatalogItemId   ? std::string(e->CatalogItemId)   : std::string();
    out.server_index     = (int64_t)e->ServerIndex;
    out.redeemed         = (int64_t)(e->bRedeemed ? 1 : 0);
    out.end_timestamp    = e->EndTimestamp;
    return out;
}

// ---- CatalogOffer struct conversion ----

static gm_structs::EpicEcomCatalogOffer eos_ecom_offer_from_native(
    const EOS_Ecom_CatalogOffer* o)
{
    gm_structs::EpicEcomCatalogOffer out{};
    if (!o) return out;
    out.server_index             = (int64_t)o->ServerIndex;
    out.catalog_namespace        = o->CatalogNamespace ? std::string(o->CatalogNamespace) : std::string();
    out.id                       = o->Id               ? std::string(o->Id)               : std::string();
    out.title_text               = o->TitleText        ? std::string(o->TitleText)        : std::string();
    out.description_text         = o->DescriptionText  ? std::string(o->DescriptionText)  : std::string();
    out.long_description_text    = o->LongDescriptionText ? std::string(o->LongDescriptionText) : std::string();
    out.currency_code            = o->CurrencyCode     ? std::string(o->CurrencyCode)     : std::string();
    out.price_result             = (gm_enums::EpicResult)o->PriceResult;
    out.discount_percentage      = (int64_t)o->DiscountPercentage;
    out.expiration_timestamp     = o->ExpirationTimestamp;
    out.purchase_limit           = (int64_t)o->PurchaseLimit;
    out.available_for_purchase   = (int64_t)(o->bAvailableForPurchase ? 1 : 0);
    out.original_price64         = (int64_t)o->OriginalPrice64;
    out.current_price64          = (int64_t)o->CurrentPrice64;
    out.decimal_point            = (int64_t)o->DecimalPoint;
    out.release_date_timestamp   = o->ReleaseDateTimestamp;
    out.effective_date_timestamp = o->EffectiveDateTimestamp;
    return out;
}

// ---- CatalogItem struct conversion ----

static gm_structs::EpicEcomCatalogItem eos_ecom_item_from_native(
    const EOS_Ecom_CatalogItem* item)
{
    gm_structs::EpicEcomCatalogItem out{};
    if (!item) return out;
    out.catalog_namespace          = item->CatalogNamespace       ? std::string(item->CatalogNamespace)       : std::string();
    out.id                         = item->Id                     ? std::string(item->Id)                     : std::string();
    out.entitlement_name           = item->EntitlementName        ? std::string(item->EntitlementName)        : std::string();
    out.title_text                 = item->TitleText              ? std::string(item->TitleText)              : std::string();
    out.description_text           = item->DescriptionText        ? std::string(item->DescriptionText)        : std::string();
    out.long_description_text      = item->LongDescriptionText    ? std::string(item->LongDescriptionText)    : std::string();
    out.technical_details_text     = item->TechnicalDetailsText   ? std::string(item->TechnicalDetailsText)   : std::string();
    out.developer_text             = item->DeveloperText          ? std::string(item->DeveloperText)          : std::string();
    out.item_type                  = (gm_enums::EpicEcomItemType)item->ItemType;
    out.entitlement_end_timestamp  = item->EntitlementEndTimestamp;
    return out;
}

// ---- KeyImageInfo struct conversion ----

static gm_structs::EpicEcomKeyImageInfo eos_ecom_image_info_from_native(
    const EOS_Ecom_KeyImageInfo* img)
{
    gm_structs::EpicEcomKeyImageInfo out{};
    if (!img) return out;
    out.type   = img->Type ? std::string(img->Type) : std::string();
    out.url    = img->Url  ? std::string(img->Url)  : std::string();
    out.width  = (int64_t)img->Width;
    out.height = (int64_t)img->Height;
    return out;
}

// ---- CatalogRelease struct conversion ----

static gm_structs::EpicEcomCatalogRelease eos_ecom_release_from_native(
    const EOS_Ecom_CatalogRelease* rel)
{
    gm_structs::EpicEcomCatalogRelease out{};
    if (!rel) return out;
    out.compatible_app_ids  = join_cstring_array(rel->CompatibleAppIds,   rel->CompatibleAppIdCount);
    out.compatible_platforms = join_cstring_array(rel->CompatiblePlatforms, rel->CompatiblePlatformCount);
    out.release_note        = rel->ReleaseNote ? std::string(rel->ReleaseNote) : std::string();
    return out;
}

// ---- Ownership caches ----

struct EcomItemOwnershipEntry {
    std::string id;
    EOS_EOwnershipStatus status;
};

struct EcomSandboxOwnershipEntry {
    std::string sandbox_id;
    std::vector<std::string> owned_item_ids;
};

static std::mutex g_ecom_cache_mutex;
static std::unordered_map<std::string, std::vector<EcomItemOwnershipEntry>> g_item_ownership_cache;
static std::unordered_map<std::string, std::vector<EcomSandboxOwnershipEntry>> g_sandbox_ownership_cache;

// ---- Transaction handle registry ----

static std::mutex g_tx_mutex;
static uint64_t g_tx_next_id = 1;
static std::unordered_map<uint64_t, EOS_Ecom_HTransaction> g_tx_handles;

static uint64_t eos_ecom_store_tx(EOS_Ecom_HTransaction tx)
{
    std::lock_guard<std::mutex> lock(g_tx_mutex);
    uint64_t id = g_tx_next_id++;
    g_tx_handles[id] = tx;
    return id;
}

static EOS_Ecom_HTransaction eos_ecom_get_tx(uint64_t id)
{
    std::lock_guard<std::mutex> lock(g_tx_mutex);
    auto it = g_tx_handles.find(id);
    return (it != g_tx_handles.end()) ? it->second : nullptr;
}

static void eos_ecom_remove_tx(uint64_t id)
{
    std::lock_guard<std::mutex> lock(g_tx_mutex);
    g_tx_handles.erase(id);
}

// ============================================================
// Native callbacks
// ============================================================

static void EOS_CALL eos_ecom_query_ownership_callback_native(
    const EOS_Ecom_QueryOwnershipCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    std::string user_id = eos_epic_account_id_to_string_internal(data->LocalUserId);

    // Cache ownership results (only valid during callback)
    if (data->ResultCode == EOS_EResult::EOS_Success && data->ItemOwnership && data->ItemOwnershipCount > 0) {
        std::vector<EcomItemOwnershipEntry> entries;
        entries.reserve(data->ItemOwnershipCount);
        for (uint32_t i = 0; i < data->ItemOwnershipCount; ++i) {
            EcomItemOwnershipEntry e;
            e.id     = data->ItemOwnership[i].Id ? std::string(data->ItemOwnership[i].Id) : std::string();
            e.status = data->ItemOwnership[i].OwnershipStatus;
            entries.push_back(std::move(e));
        }
        std::lock_guard<std::mutex> lock(g_ecom_cache_mutex);
        g_item_ownership_cache[user_id] = std::move(entries);
    }

    gm_structs::EpicEcomQueryOwnershipCallbackInfo out{};
    out.result_code         = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id       = user_id;
    out.item_ownership_count = (int64_t)data->ItemOwnershipCount;
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

static void EOS_CALL eos_ecom_query_ownership_by_sandbox_ids_callback_native(
    const EOS_Ecom_QueryOwnershipBySandboxIdsCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    std::string user_id = eos_epic_account_id_to_string_internal(data->LocalUserId);

    if (data->ResultCode == EOS_EResult::EOS_Success && data->SandboxIdItemOwnerships && data->SandboxIdItemOwnershipsCount > 0) {
        std::vector<EcomSandboxOwnershipEntry> entries;
        entries.reserve(data->SandboxIdItemOwnershipsCount);
        for (uint32_t i = 0; i < data->SandboxIdItemOwnershipsCount; ++i) {
            const auto& src = data->SandboxIdItemOwnerships[i];
            EcomSandboxOwnershipEntry e;
            e.sandbox_id = src.SandboxId ? std::string(src.SandboxId) : std::string();
            for (uint32_t j = 0; j < src.OwnedCatalogItemIdsCount; ++j) {
                if (src.OwnedCatalogItemIds[j])
                    e.owned_item_ids.push_back(std::string(src.OwnedCatalogItemIds[j]));
            }
            entries.push_back(std::move(e));
        }
        std::lock_guard<std::mutex> lock(g_ecom_cache_mutex);
        g_sandbox_ownership_cache[user_id] = std::move(entries);
    }

    gm_structs::EpicEcomQueryOwnershipBySandboxIdsCallbackInfo out{};
    out.result_code              = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id            = user_id;
    out.sandbox_ownership_count  = (int64_t)data->SandboxIdItemOwnershipsCount;
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

static void EOS_CALL eos_ecom_query_ownership_token_callback_native(
    const EOS_Ecom_QueryOwnershipTokenCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicEcomQueryOwnershipTokenCallbackInfo out{};
    out.result_code   = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_epic_account_id_to_string_internal(data->LocalUserId);
    out.ownership_token = data->OwnershipToken ? std::string(data->OwnershipToken) : std::string();
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

static void EOS_CALL eos_ecom_query_entitlements_callback_native(
    const EOS_Ecom_QueryEntitlementsCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicEcomQueryEntitlementsCallbackInfo out{};
    out.result_code   = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_epic_account_id_to_string_internal(data->LocalUserId);
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

static void EOS_CALL eos_ecom_query_entitlement_token_callback_native(
    const EOS_Ecom_QueryEntitlementTokenCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicEcomQueryEntitlementTokenCallbackInfo out{};
    out.result_code       = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id     = eos_epic_account_id_to_string_internal(data->LocalUserId);
    out.entitlement_token = data->EntitlementToken ? std::string(data->EntitlementToken) : std::string();
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

static void EOS_CALL eos_ecom_query_offers_callback_native(
    const EOS_Ecom_QueryOffersCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicEcomQueryOffersCallbackInfo out{};
    out.result_code   = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id = eos_epic_account_id_to_string_internal(data->LocalUserId);
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

static void EOS_CALL eos_ecom_checkout_callback_native(
    const EOS_Ecom_CheckoutCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicEcomCheckoutCallbackInfo out{};
    out.result_code    = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id  = eos_epic_account_id_to_string_internal(data->LocalUserId);
    out.transaction_id = data->TransactionId ? std::string(data->TransactionId) : std::string();
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

static void EOS_CALL eos_ecom_redeem_entitlements_callback_native(
    const EOS_Ecom_RedeemEntitlementsCallbackInfo* data)
{
    if (!data) return;
    auto* ctx = static_cast<EOSAsyncCallbackContext*>(data->ClientData);
    if (!ctx) return;

    gm_structs::EpicEcomRedeemEntitlementsCallbackInfo out{};
    out.result_code    = (gm_enums::EpicResult)data->ResultCode;
    out.local_user_id  = eos_epic_account_id_to_string_internal(data->LocalUserId);
    out.redeemed_count = (int64_t)data->RedeemedEntitlementIdsCount;
    if (ctx->callback) ctx->callback.value().call(out);
    delete ctx;
}

// ============================================================
// EOS Ecom — Async queries
// ============================================================

void eos_ecom_query_ownership(
    std::string_view local_user_id,
    const std::vector<std::string_view>& catalog_item_ids,
    std::string_view catalog_namespace,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) { eos_set_last_error("eos_ecom_query_ownership: invalid local_user_id."); return; }

    std::vector<const char*> id_ptrs;
    id_ptrs.reserve(catalog_item_ids.size());
    for (const auto& id : catalog_item_ids)
        id_ptrs.push_back(id.data());

    std::string ns(catalog_namespace);

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_Ecom_QueryOwnershipOptions opts{};
    opts.ApiVersion         = EOS_ECOM_QUERYOWNERSHIP_API_LATEST;
    opts.LocalUserId        = local_user;
    opts.CatalogItemIds     = id_ptrs.empty() ? nullptr : id_ptrs.data();
    opts.CatalogItemIdCount = (uint32_t)id_ptrs.size();
    opts.CatalogNamespace   = ns.empty() ? nullptr : ns.c_str();

    EOS_Ecom_QueryOwnership(ecom, &opts, ctx, &eos_ecom_query_ownership_callback_native);
}

void eos_ecom_query_ownership_by_sandbox_ids(
    std::string_view local_user_id,
    const std::vector<std::string_view>& sandbox_ids,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) { eos_set_last_error("eos_ecom_query_ownership_by_sandbox_ids: invalid local_user_id."); return; }

    std::vector<const char*> id_ptrs;
    id_ptrs.reserve(sandbox_ids.size());
    for (const auto& id : sandbox_ids)
        id_ptrs.push_back(id.data());

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_Ecom_QueryOwnershipBySandboxIdsOptions opts{};
    opts.ApiVersion     = EOS_ECOM_QUERYOWNERSHIPBYSANDBOXIDSOPTIONS_API_LATEST;
    opts.LocalUserId    = local_user;
    opts.SandboxIds     = (EOS_Ecom_SandboxId*)id_ptrs.data();
    opts.SandboxIdsCount = (uint32_t)id_ptrs.size();

    EOS_Ecom_QueryOwnershipBySandboxIds(ecom, &opts, ctx, &eos_ecom_query_ownership_by_sandbox_ids_callback_native);
}

void eos_ecom_query_ownership_token(
    std::string_view local_user_id,
    const std::vector<std::string_view>& catalog_item_ids,
    std::string_view catalog_namespace,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) { eos_set_last_error("eos_ecom_query_ownership_token: invalid local_user_id."); return; }

    std::vector<const char*> id_ptrs;
    id_ptrs.reserve(catalog_item_ids.size());
    for (const auto& id : catalog_item_ids)
        id_ptrs.push_back(id.data());

    std::string ns(catalog_namespace);

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_Ecom_QueryOwnershipTokenOptions opts{};
    opts.ApiVersion         = EOS_ECOM_QUERYOWNERSHIPTOKEN_API_LATEST;
    opts.LocalUserId        = local_user;
    opts.CatalogItemIds     = (EOS_Ecom_CatalogItemId*)id_ptrs.data();
    opts.CatalogItemIdCount = (uint32_t)id_ptrs.size();
    opts.CatalogNamespace   = ns.empty() ? nullptr : ns.c_str();

    EOS_Ecom_QueryOwnershipToken(ecom, &opts, ctx, &eos_ecom_query_ownership_token_callback_native);
}

void eos_ecom_query_entitlements(
    std::string_view local_user_id,
    const std::vector<std::string_view>& entitlement_names,
    int64_t include_redeemed,
    std::string_view catalog_namespace,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) { eos_set_last_error("eos_ecom_query_entitlements: invalid local_user_id."); return; }

    std::vector<const char*> name_ptrs;
    name_ptrs.reserve(entitlement_names.size());
    for (const auto& n : entitlement_names)
        name_ptrs.push_back(n.data());

    std::string ns(catalog_namespace);

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_Ecom_QueryEntitlementsOptions opts{};
    opts.ApiVersion                 = EOS_ECOM_QUERYENTITLEMENTS_API_LATEST;
    opts.LocalUserId                = local_user;
    opts.EntitlementNames           = (EOS_Ecom_EntitlementName*)(name_ptrs.empty() ? nullptr : name_ptrs.data());
    opts.EntitlementNameCount       = (uint32_t)name_ptrs.size();
    opts.bIncludeRedeemed           = (EOS_Bool)(include_redeemed != 0 ? EOS_TRUE : EOS_FALSE);
    opts.OverrideCatalogNamespace   = ns.empty() ? nullptr : ns.c_str();

    EOS_Ecom_QueryEntitlements(ecom, &opts, ctx, &eos_ecom_query_entitlements_callback_native);
}

void eos_ecom_query_entitlement_token(
    std::string_view local_user_id,
    const std::vector<std::string_view>& entitlement_names,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) { eos_set_last_error("eos_ecom_query_entitlement_token: invalid local_user_id."); return; }

    std::vector<const char*> name_ptrs;
    name_ptrs.reserve(entitlement_names.size());
    for (const auto& n : entitlement_names)
        name_ptrs.push_back(n.data());

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_Ecom_QueryEntitlementTokenOptions opts{};
    opts.ApiVersion           = EOS_ECOM_QUERYENTITLEMENTTOKEN_API_LATEST;
    opts.LocalUserId          = local_user;
    opts.EntitlementNames     = (EOS_Ecom_EntitlementName*)(name_ptrs.empty() ? nullptr : name_ptrs.data());
    opts.EntitlementNameCount = (uint32_t)name_ptrs.size();

    EOS_Ecom_QueryEntitlementToken(ecom, &opts, ctx, &eos_ecom_query_entitlement_token_callback_native);
}

void eos_ecom_query_offers(
    std::string_view local_user_id,
    std::string_view catalog_namespace,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) { eos_set_last_error("eos_ecom_query_offers: invalid local_user_id."); return; }

    std::string ns(catalog_namespace);

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_Ecom_QueryOffersOptions opts{};
    opts.ApiVersion             = EOS_ECOM_QUERYOFFERS_API_LATEST;
    opts.LocalUserId            = local_user;
    opts.OverrideCatalogNamespace = ns.empty() ? nullptr : ns.c_str();

    EOS_Ecom_QueryOffers(ecom, &opts, ctx, &eos_ecom_query_offers_callback_native);
}

void eos_ecom_checkout(
    std::string_view local_user_id,
    const std::vector<std::string_view>& offer_ids,
    std::string_view catalog_namespace,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) { eos_set_last_error("eos_ecom_checkout: invalid local_user_id."); return; }

    std::vector<EOS_Ecom_CheckoutEntry> entries;
    entries.reserve(offer_ids.size());
    for (const auto& id : offer_ids) {
        EOS_Ecom_CheckoutEntry entry{};
        entry.ApiVersion = EOS_ECOM_CHECKOUTENTRY_API_LATEST;
        entry.OfferId    = id.data();
        entries.push_back(entry);
    }

    std::string ns(catalog_namespace);

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_Ecom_CheckoutOptions opts{};
    opts.ApiVersion               = EOS_ECOM_CHECKOUT_API_LATEST;
    opts.LocalUserId              = local_user;
    opts.OverrideCatalogNamespace = ns.empty() ? nullptr : ns.c_str();
    opts.EntryCount               = (uint32_t)entries.size();
    opts.Entries                  = entries.empty() ? nullptr : entries.data();
    opts.PreferredOrientation     = EOS_ECheckoutOrientation::EOS_ECO_Default;

    EOS_Ecom_Checkout(ecom, &opts, ctx, &eos_ecom_checkout_callback_native);
}

void eos_ecom_redeem_entitlements(
    std::string_view local_user_id,
    const std::vector<std::string_view>& entitlement_ids,
    const std::optional<gm::wire::GMFunction>& callback)
{
    EOS_GUARD();

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    if (!local_user) { eos_set_last_error("eos_ecom_redeem_entitlements: invalid local_user_id."); return; }

    std::vector<const char*> id_ptrs;
    id_ptrs.reserve(entitlement_ids.size());
    for (const auto& id : entitlement_ids)
        id_ptrs.push_back(id.data());

    auto* ctx = new EOSAsyncCallbackContext{callback};

    EOS_Ecom_RedeemEntitlementsOptions opts{};
    opts.ApiVersion          = EOS_ECOM_REDEEMENTITLEMENTS_API_LATEST;
    opts.LocalUserId         = local_user;
    opts.EntitlementIdCount  = (uint32_t)id_ptrs.size();
    opts.EntitlementIds      = (EOS_Ecom_EntitlementId*)(id_ptrs.empty() ? nullptr : id_ptrs.data());

    EOS_Ecom_RedeemEntitlements(ecom, &opts, ctx, &eos_ecom_redeem_entitlements_callback_native);
}

// ============================================================
// EOS Ecom — Ownership cache accessors
// ============================================================

int64_t eos_ecom_get_item_ownership_count(std::string_view local_user_id)
{
    std::string uid(local_user_id);
    std::lock_guard<std::mutex> lock(g_ecom_cache_mutex);
    auto it = g_item_ownership_cache.find(uid);
    return (it != g_item_ownership_cache.end()) ? (int64_t)it->second.size() : 0;
}

gm_structs::EpicEcomItemOwnership eos_ecom_copy_item_ownership_at_index(
    std::string_view local_user_id,
    int64_t index)
{
    gm_structs::EpicEcomItemOwnership out{};
    std::string uid(local_user_id);
    std::lock_guard<std::mutex> lock(g_ecom_cache_mutex);
    auto it = g_item_ownership_cache.find(uid);
    if (it == g_item_ownership_cache.end() || index < 0 || (size_t)index >= it->second.size()) {
        eos_set_last_error("eos_ecom_copy_item_ownership_at_index: index out of range.");
        return out;
    }
    const auto& e = it->second[(size_t)index];
    out.id               = e.id;
    out.ownership_status = (gm_enums::EpicOwnershipStatus)e.status;
    return out;
}

int64_t eos_ecom_get_sandbox_ownership_count(std::string_view local_user_id)
{
    std::string uid(local_user_id);
    std::lock_guard<std::mutex> lock(g_ecom_cache_mutex);
    auto it = g_sandbox_ownership_cache.find(uid);
    return (it != g_sandbox_ownership_cache.end()) ? (int64_t)it->second.size() : 0;
}

gm_structs::EpicEcomSandboxIdItemOwnership eos_ecom_copy_sandbox_ownership_at_index(
    std::string_view local_user_id,
    int64_t index)
{
    gm_structs::EpicEcomSandboxIdItemOwnership out{};
    std::string uid(local_user_id);
    std::lock_guard<std::mutex> lock(g_ecom_cache_mutex);
    auto it = g_sandbox_ownership_cache.find(uid);
    if (it == g_sandbox_ownership_cache.end() || index < 0 || (size_t)index >= it->second.size()) {
        eos_set_last_error("eos_ecom_copy_sandbox_ownership_at_index: index out of range.");
        return out;
    }
    const auto& e = it->second[(size_t)index];
    out.sandbox_id = e.sandbox_id;
    // join owned item IDs with pipe delimiter
    for (size_t i = 0; i < e.owned_item_ids.size(); ++i) {
        if (i > 0) out.owned_catalog_item_ids += '|';
        out.owned_catalog_item_ids += e.owned_item_ids[i];
    }
    return out;
}

// ============================================================
// EOS Ecom — Entitlement accessors
// ============================================================

int64_t eos_ecom_get_entitlements_count(std::string_view local_user_id)
{
    EOS_GUARD_RET(0);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return 0; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);

    EOS_Ecom_GetEntitlementsCountOptions opts{};
    opts.ApiVersion  = EOS_ECOM_GETENTITLEMENTSCOUNT_API_LATEST;
    opts.LocalUserId = local_user;

    return (int64_t)EOS_Ecom_GetEntitlementsCount(ecom, &opts);
}

int64_t eos_ecom_get_entitlements_by_name_count(
    std::string_view local_user_id,
    std::string_view entitlement_name)
{
    EOS_GUARD_RET(0);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return 0; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    std::string name(entitlement_name);

    EOS_Ecom_GetEntitlementsByNameCountOptions opts{};
    opts.ApiVersion      = EOS_ECOM_GETENTITLEMENTSBYNAMECOUNT_API_LATEST;
    opts.LocalUserId     = local_user;
    opts.EntitlementName = name.c_str();

    return (int64_t)EOS_Ecom_GetEntitlementsByNameCount(ecom, &opts);
}

gm_structs::EpicEcomEntitlement eos_ecom_copy_entitlement_by_index(
    std::string_view local_user_id,
    int64_t index)
{
    gm_structs::EpicEcomEntitlement out{};
    EOS_GUARD_RET(out);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return out; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);

    EOS_Ecom_CopyEntitlementByIndexOptions opts{};
    opts.ApiVersion       = EOS_ECOM_COPYENTITLEMENTBYINDEX_API_LATEST;
    opts.LocalUserId      = local_user;
    opts.EntitlementIndex = (uint32_t)index;

    EOS_Ecom_Entitlement* ent = nullptr;
    EOS_EResult result = EOS_Ecom_CopyEntitlementByIndex(ecom, &opts, &ent);
    if (result != EOS_EResult::EOS_Success || !ent) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Ecom_CopyEntitlementByIndex failed.");
        return out;
    }
    out = eos_ecom_entitlement_from_native(ent);
    EOS_Ecom_Entitlement_Release(ent);
    return out;
}

gm_structs::EpicEcomEntitlement eos_ecom_copy_entitlement_by_name_and_index(
    std::string_view local_user_id,
    std::string_view entitlement_name,
    int64_t index)
{
    gm_structs::EpicEcomEntitlement out{};
    EOS_GUARD_RET(out);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return out; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    std::string name(entitlement_name);

    EOS_Ecom_CopyEntitlementByNameAndIndexOptions opts{};
    opts.ApiVersion      = EOS_ECOM_COPYENTITLEMENTBYNAMEANDINDEX_API_LATEST;
    opts.LocalUserId     = local_user;
    opts.EntitlementName = name.c_str();
    opts.Index           = (uint32_t)index;

    EOS_Ecom_Entitlement* ent = nullptr;
    EOS_EResult result = EOS_Ecom_CopyEntitlementByNameAndIndex(ecom, &opts, &ent);
    if (result != EOS_EResult::EOS_Success || !ent) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Ecom_CopyEntitlementByNameAndIndex failed.");
        return out;
    }
    out = eos_ecom_entitlement_from_native(ent);
    EOS_Ecom_Entitlement_Release(ent);
    return out;
}

gm_structs::EpicEcomEntitlement eos_ecom_copy_entitlement_by_id(
    std::string_view local_user_id,
    std::string_view entitlement_id)
{
    gm_structs::EpicEcomEntitlement out{};
    EOS_GUARD_RET(out);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return out; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    std::string eid(entitlement_id);

    EOS_Ecom_CopyEntitlementByIdOptions opts{};
    opts.ApiVersion    = EOS_ECOM_COPYENTITLEMENTBYID_API_LATEST;
    opts.LocalUserId   = local_user;
    opts.EntitlementId = eid.c_str();

    EOS_Ecom_Entitlement* ent = nullptr;
    EOS_EResult result = EOS_Ecom_CopyEntitlementById(ecom, &opts, &ent);
    if (result != EOS_EResult::EOS_Success || !ent) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Ecom_CopyEntitlementById failed.");
        return out;
    }
    out = eos_ecom_entitlement_from_native(ent);
    EOS_Ecom_Entitlement_Release(ent);
    return out;
}

int64_t eos_ecom_get_last_redeemed_entitlements_count(std::string_view local_user_id)
{
    EOS_GUARD_RET(0);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return 0; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);

    EOS_Ecom_GetLastRedeemedEntitlementsCountOptions opts{};
    opts.ApiVersion  = EOS_ECOM_GETLASTREDEEMEDENTITLEMENTSCOUNT_API_LATEST;
    opts.LocalUserId = local_user;

    return (int64_t)EOS_Ecom_GetLastRedeemedEntitlementsCount(ecom, &opts);
}

std::string eos_ecom_copy_last_redeemed_entitlement_by_index(
    std::string_view local_user_id,
    int64_t index)
{
    EOS_GUARD_RET(std::string{});

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return {}; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);

    EOS_Ecom_CopyLastRedeemedEntitlementByIndexOptions opts{};
    opts.ApiVersion               = EOS_ECOM_COPYLASTREDEEMEDENTITLEMENTBYINDEX_API_LATEST;
    opts.LocalUserId              = local_user;
    opts.RedeemedEntitlementIndex = (uint32_t)index;

    char out_buf[EOS_ECOM_ENTITLEMENTID_MAX_LENGTH + 1] = {};
    int32_t out_len = (int32_t)sizeof(out_buf);
    EOS_EResult result = EOS_Ecom_CopyLastRedeemedEntitlementByIndex(ecom, &opts, out_buf, &out_len);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Ecom_CopyLastRedeemedEntitlementByIndex failed.");
        return {};
    }
    return std::string(out_buf);
}

// ============================================================
// EOS Ecom — Offer accessors
// ============================================================

int64_t eos_ecom_get_offer_count(std::string_view local_user_id)
{
    EOS_GUARD_RET(0);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return 0; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);

    EOS_Ecom_GetOfferCountOptions opts{};
    opts.ApiVersion  = EOS_ECOM_GETOFFERCOUNT_API_LATEST;
    opts.LocalUserId = local_user;

    return (int64_t)EOS_Ecom_GetOfferCount(ecom, &opts);
}

gm_structs::EpicEcomCatalogOffer eos_ecom_copy_offer_by_index(
    std::string_view local_user_id,
    int64_t index)
{
    gm_structs::EpicEcomCatalogOffer out{};
    EOS_GUARD_RET(out);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return out; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);

    EOS_Ecom_CopyOfferByIndexOptions opts{};
    opts.ApiVersion  = EOS_ECOM_COPYOFFERBYINDEX_API_LATEST;
    opts.LocalUserId = local_user;
    opts.OfferIndex  = (uint32_t)index;

    EOS_Ecom_CatalogOffer* offer = nullptr;
    EOS_EResult result = EOS_Ecom_CopyOfferByIndex(ecom, &opts, &offer);
    if (result != EOS_EResult::EOS_Success || !offer) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Ecom_CopyOfferByIndex failed.");
        return out;
    }
    out = eos_ecom_offer_from_native(offer);
    EOS_Ecom_CatalogOffer_Release(offer);
    return out;
}

gm_structs::EpicEcomCatalogOffer eos_ecom_copy_offer_by_id(
    std::string_view local_user_id,
    std::string_view offer_id)
{
    gm_structs::EpicEcomCatalogOffer out{};
    EOS_GUARD_RET(out);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return out; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    std::string oid(offer_id);

    EOS_Ecom_CopyOfferByIdOptions opts{};
    opts.ApiVersion  = EOS_ECOM_COPYOFFERBYID_API_LATEST;
    opts.LocalUserId = local_user;
    opts.OfferId     = oid.c_str();

    EOS_Ecom_CatalogOffer* offer = nullptr;
    EOS_EResult result = EOS_Ecom_CopyOfferById(ecom, &opts, &offer);
    if (result != EOS_EResult::EOS_Success || !offer) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Ecom_CopyOfferById failed.");
        return out;
    }
    out = eos_ecom_offer_from_native(offer);
    EOS_Ecom_CatalogOffer_Release(offer);
    return out;
}

int64_t eos_ecom_get_offer_item_count(
    std::string_view local_user_id,
    std::string_view offer_id)
{
    EOS_GUARD_RET(0);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return 0; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    std::string oid(offer_id);

    EOS_Ecom_GetOfferItemCountOptions opts{};
    opts.ApiVersion  = EOS_ECOM_GETOFFERITEMCOUNT_API_LATEST;
    opts.LocalUserId = local_user;
    opts.OfferId     = oid.c_str();

    return (int64_t)EOS_Ecom_GetOfferItemCount(ecom, &opts);
}

gm_structs::EpicEcomCatalogItem eos_ecom_copy_offer_item_by_index(
    std::string_view local_user_id,
    std::string_view offer_id,
    int64_t item_index)
{
    gm_structs::EpicEcomCatalogItem out{};
    EOS_GUARD_RET(out);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return out; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    std::string oid(offer_id);

    EOS_Ecom_CopyOfferItemByIndexOptions opts{};
    opts.ApiVersion  = EOS_ECOM_COPYOFFERITEMBYINDEX_API_LATEST;
    opts.LocalUserId = local_user;
    opts.OfferId     = oid.c_str();
    opts.ItemIndex   = (uint32_t)item_index;

    EOS_Ecom_CatalogItem* item = nullptr;
    EOS_EResult result = EOS_Ecom_CopyOfferItemByIndex(ecom, &opts, &item);
    if (result != EOS_EResult::EOS_Success || !item) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Ecom_CopyOfferItemByIndex failed.");
        return out;
    }
    out = eos_ecom_item_from_native(item);
    EOS_Ecom_CatalogItem_Release(item);
    return out;
}

gm_structs::EpicEcomCatalogItem eos_ecom_copy_item_by_id(
    std::string_view local_user_id,
    std::string_view item_id)
{
    gm_structs::EpicEcomCatalogItem out{};
    EOS_GUARD_RET(out);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return out; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    std::string iid(item_id);

    EOS_Ecom_CopyItemByIdOptions opts{};
    opts.ApiVersion  = EOS_ECOM_COPYITEMBYID_API_LATEST;
    opts.LocalUserId = local_user;
    opts.ItemId      = iid.c_str();

    EOS_Ecom_CatalogItem* item = nullptr;
    EOS_EResult result = EOS_Ecom_CopyItemById(ecom, &opts, &item);
    if (result != EOS_EResult::EOS_Success || !item) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Ecom_CopyItemById failed.");
        return out;
    }
    out = eos_ecom_item_from_native(item);
    EOS_Ecom_CatalogItem_Release(item);
    return out;
}

// ============================================================
// EOS Ecom — Image info accessors
// ============================================================

int64_t eos_ecom_get_offer_image_info_count(
    std::string_view local_user_id,
    std::string_view offer_id)
{
    EOS_GUARD_RET(0);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return 0; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    std::string oid(offer_id);

    EOS_Ecom_GetOfferImageInfoCountOptions opts{};
    opts.ApiVersion  = EOS_ECOM_GETOFFERIMAGEINFOCOUNT_API_LATEST;
    opts.LocalUserId = local_user;
    opts.OfferId     = oid.c_str();

    return (int64_t)EOS_Ecom_GetOfferImageInfoCount(ecom, &opts);
}

gm_structs::EpicEcomKeyImageInfo eos_ecom_copy_offer_image_info_by_index(
    std::string_view local_user_id,
    std::string_view offer_id,
    int64_t image_info_index)
{
    gm_structs::EpicEcomKeyImageInfo out{};
    EOS_GUARD_RET(out);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return out; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    std::string oid(offer_id);

    EOS_Ecom_CopyOfferImageInfoByIndexOptions opts{};
    opts.ApiVersion      = EOS_ECOM_COPYOFFERIMAGEINFOBYINDEX_API_LATEST;
    opts.LocalUserId     = local_user;
    opts.OfferId         = oid.c_str();
    opts.ImageInfoIndex  = (uint32_t)image_info_index;

    EOS_Ecom_KeyImageInfo* img = nullptr;
    EOS_EResult result = EOS_Ecom_CopyOfferImageInfoByIndex(ecom, &opts, &img);
    if (result != EOS_EResult::EOS_Success || !img) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Ecom_CopyOfferImageInfoByIndex failed.");
        return out;
    }
    out = eos_ecom_image_info_from_native(img);
    EOS_Ecom_KeyImageInfo_Release(img);
    return out;
}

int64_t eos_ecom_get_item_image_info_count(
    std::string_view local_user_id,
    std::string_view item_id)
{
    EOS_GUARD_RET(0);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return 0; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    std::string iid(item_id);

    EOS_Ecom_GetItemImageInfoCountOptions opts{};
    opts.ApiVersion  = EOS_ECOM_GETITEMIMAGEINFOCOUNT_API_LATEST;
    opts.LocalUserId = local_user;
    opts.ItemId      = iid.c_str();

    return (int64_t)EOS_Ecom_GetItemImageInfoCount(ecom, &opts);
}

gm_structs::EpicEcomKeyImageInfo eos_ecom_copy_item_image_info_by_index(
    std::string_view local_user_id,
    std::string_view item_id,
    int64_t image_info_index)
{
    gm_structs::EpicEcomKeyImageInfo out{};
    EOS_GUARD_RET(out);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return out; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    std::string iid(item_id);

    EOS_Ecom_CopyItemImageInfoByIndexOptions opts{};
    opts.ApiVersion     = EOS_ECOM_COPYITEMIMAGEINFOBYINDEX_API_LATEST;
    opts.LocalUserId    = local_user;
    opts.ItemId         = iid.c_str();
    opts.ImageInfoIndex = (uint32_t)image_info_index;

    EOS_Ecom_KeyImageInfo* img = nullptr;
    EOS_EResult result = EOS_Ecom_CopyItemImageInfoByIndex(ecom, &opts, &img);
    if (result != EOS_EResult::EOS_Success || !img) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Ecom_CopyItemImageInfoByIndex failed.");
        return out;
    }
    out = eos_ecom_image_info_from_native(img);
    EOS_Ecom_KeyImageInfo_Release(img);
    return out;
}

// ============================================================
// EOS Ecom — Release accessors
// ============================================================

int64_t eos_ecom_get_item_release_count(
    std::string_view local_user_id,
    std::string_view item_id)
{
    EOS_GUARD_RET(0);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return 0; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    std::string iid(item_id);

    EOS_Ecom_GetItemReleaseCountOptions opts{};
    opts.ApiVersion  = EOS_ECOM_GETITEMRELEASECOUNT_API_LATEST;
    opts.LocalUserId = local_user;
    opts.ItemId      = iid.c_str();

    return (int64_t)EOS_Ecom_GetItemReleaseCount(ecom, &opts);
}

gm_structs::EpicEcomCatalogRelease eos_ecom_copy_item_release_by_index(
    std::string_view local_user_id,
    std::string_view item_id,
    int64_t release_index)
{
    gm_structs::EpicEcomCatalogRelease out{};
    EOS_GUARD_RET(out);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return out; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    std::string iid(item_id);

    EOS_Ecom_CopyItemReleaseByIndexOptions opts{};
    opts.ApiVersion   = EOS_ECOM_COPYITEMRELEASEBYINDEX_API_LATEST;
    opts.LocalUserId  = local_user;
    opts.ItemId       = iid.c_str();
    opts.ReleaseIndex = (uint32_t)release_index;

    EOS_Ecom_CatalogRelease* rel = nullptr;
    EOS_EResult result = EOS_Ecom_CopyItemReleaseByIndex(ecom, &opts, &rel);
    if (result != EOS_EResult::EOS_Success || !rel) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Ecom_CopyItemReleaseByIndex failed.");
        return out;
    }
    out = eos_ecom_release_from_native(rel);
    EOS_Ecom_CatalogRelease_Release(rel);
    return out;
}

// ============================================================
// EOS Ecom — Transaction accessors
// ============================================================

int64_t eos_ecom_get_transaction_count(std::string_view local_user_id)
{
    EOS_GUARD_RET(0);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return 0; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);

    EOS_Ecom_GetTransactionCountOptions opts{};
    opts.ApiVersion  = EOS_ECOM_GETTRANSACTIONCOUNT_API_LATEST;
    opts.LocalUserId = local_user;

    return (int64_t)EOS_Ecom_GetTransactionCount(ecom, &opts);
}

uint64_t eos_ecom_copy_transaction_by_index(
    std::string_view local_user_id,
    int64_t transaction_index)
{
    EOS_GUARD_RET(0);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return 0; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);

    EOS_Ecom_CopyTransactionByIndexOptions opts{};
    opts.ApiVersion       = EOS_ECOM_COPYTRANSACTIONBYINDEX_API_LATEST;
    opts.LocalUserId      = local_user;
    opts.TransactionIndex = (uint32_t)transaction_index;

    EOS_Ecom_HTransaction tx = nullptr;
    EOS_EResult result = EOS_Ecom_CopyTransactionByIndex(ecom, &opts, &tx);
    if (result != EOS_EResult::EOS_Success || !tx) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Ecom_CopyTransactionByIndex failed.");
        return 0;
    }
    return eos_ecom_store_tx(tx);
}

uint64_t eos_ecom_copy_transaction_by_id(
    std::string_view local_user_id,
    std::string_view transaction_id)
{
    EOS_GUARD_RET(0);

    EOS_HEcom ecom = eos_ecom_iface();
    if (!ecom) { eos_set_last_error("EOS Ecom interface unavailable."); return 0; }

    EOS_EpicAccountId local_user = eos_epic_account_id_from_string_internal(local_user_id);
    std::string tid(transaction_id);

    EOS_Ecom_CopyTransactionByIdOptions opts{};
    opts.ApiVersion    = EOS_ECOM_COPYTRANSACTIONBYID_API_LATEST;
    opts.LocalUserId   = local_user;
    opts.TransactionId = tid.c_str();

    EOS_Ecom_HTransaction tx = nullptr;
    EOS_EResult result = EOS_Ecom_CopyTransactionById(ecom, &opts, &tx);
    if (result != EOS_EResult::EOS_Success || !tx) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Ecom_CopyTransactionById failed.");
        return 0;
    }
    return eos_ecom_store_tx(tx);
}

std::string eos_ecom_transaction_get_transaction_id(uint64_t tx_handle_id)
{
    EOS_GUARD_RET(std::string{});

    EOS_Ecom_HTransaction tx = eos_ecom_get_tx(tx_handle_id);
    if (!tx) { eos_set_last_error("eos_ecom_transaction_get_transaction_id: invalid handle."); return {}; }

    char buf[EOS_ECOM_TRANSACTIONID_MAXIMUM_LENGTH + 1] = {};
    int32_t len = (int32_t)sizeof(buf);
    EOS_EResult result = EOS_Ecom_Transaction_GetTransactionId(tx, buf, &len);
    if (result != EOS_EResult::EOS_Success) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Ecom_Transaction_GetTransactionId failed.");
        return {};
    }
    return std::string(buf);
}

int64_t eos_ecom_transaction_get_entitlements_count(uint64_t tx_handle_id)
{
    EOS_GUARD_RET(0);

    EOS_Ecom_HTransaction tx = eos_ecom_get_tx(tx_handle_id);
    if (!tx) { eos_set_last_error("eos_ecom_transaction_get_entitlements_count: invalid handle."); return 0; }

    EOS_Ecom_Transaction_GetEntitlementsCountOptions opts{};
    opts.ApiVersion = EOS_ECOM_TRANSACTION_GETENTITLEMENTSCOUNT_API_LATEST;

    return (int64_t)EOS_Ecom_Transaction_GetEntitlementsCount(tx, &opts);
}

gm_structs::EpicEcomEntitlement eos_ecom_transaction_copy_entitlement_by_index(
    uint64_t tx_handle_id,
    int64_t index)
{
    gm_structs::EpicEcomEntitlement out{};
    EOS_GUARD_RET(out);

    EOS_Ecom_HTransaction tx = eos_ecom_get_tx(tx_handle_id);
    if (!tx) { eos_set_last_error("eos_ecom_transaction_copy_entitlement_by_index: invalid handle."); return out; }

    EOS_Ecom_Transaction_CopyEntitlementByIndexOptions opts{};
    opts.ApiVersion       = EOS_ECOM_TRANSACTION_COPYENTITLEMENTBYINDEX_API_LATEST;
    opts.EntitlementIndex = (uint32_t)index;

    EOS_Ecom_Entitlement* ent = nullptr;
    EOS_EResult result = EOS_Ecom_Transaction_CopyEntitlementByIndex(tx, &opts, &ent);
    if (result != EOS_EResult::EOS_Success || !ent) {
        const char* err = EOS_EResult_ToString(result);
        eos_set_last_error(err ? err : "EOS_Ecom_Transaction_CopyEntitlementByIndex failed.");
        return out;
    }
    out = eos_ecom_entitlement_from_native(ent);
    EOS_Ecom_Entitlement_Release(ent);
    return out;
}

void eos_ecom_transaction_release(uint64_t tx_handle_id)
{
    EOS_GUARD();

    EOS_Ecom_HTransaction tx = eos_ecom_get_tx(tx_handle_id);
    if (!tx) return;

    EOS_Ecom_Transaction_Release(tx);
    eos_ecom_remove_tx(tx_handle_id);
}
