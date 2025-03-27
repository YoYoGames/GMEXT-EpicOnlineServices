

// EOS Ecom Interface API Reference
// Top - Level Reference for the EOS Ecom Interface's API
// https://dev.epicgames.com/docs/api-ref/interfaces/ecom

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include <eos_ecom.h>
#include <eos_ecom_types.h>

// EOS_Ecom_QueryOwnership
// EOS_Ecom_QueryOwnershipBySandboxIds
// EOS_Ecom_QueryOwnershipToken
// EOS_Ecom_QueryEntitlements
// EOS_Ecom_QueryEntitlementToken
// EOS_Ecom_QueryOffers
// EOS_Ecom_Checkout
// EOS_Ecom_RedeemEntitlements
// EOS_Ecom_GetLastRedeemedEntitlementsCount
// EOS_Ecom_CopyLastRedeemedEntitlementByIndex
// EOS_Ecom_GetEntitlementsCount
// EOS_Ecom_GetEntitlementsByNameCount
// EOS_Ecom_CopyEntitlementByIndex
// EOS_Ecom_CopyEntitlementByNameAndIndex
// EOS_Ecom_CopyEntitlementById
// EOS_Ecom_GetOfferCount
// EOS_Ecom_CopyOfferByIndex
// EOS_Ecom_CopyOfferById
// EOS_Ecom_GetOfferItemCount
// EOS_Ecom_CopyOfferItemByIndex
// EOS_Ecom_CopyItemById
// EOS_Ecom_GetOfferImageInfoCount
// EOS_Ecom_CopyOfferImageInfoByIndex
// EOS_Ecom_GetItemImageInfoCount
// EOS_Ecom_CopyItemImageInfoByIndex
// EOS_Ecom_GetItemReleaseCount
// EOS_Ecom_CopyItemReleaseByIndex
// EOS_Ecom_GetTransactionCount
// EOS_Ecom_CopyTransactionByIndex
// EOS_Ecom_CopyTransactionById
// EOS_Ecom_Transaction_GetTransactionId
// EOS_Ecom_Transaction_GetEntitlementsCount
// EOS_Ecom_Transaction_CopyEntitlementByIndex

EOS_HEcom HEcom;
void eos_ecom_init()
{
	HEcom = EOS_Platform_GetEcomInterface(PlatformHandle);
}

void EOS_CALL QueryOwnershipCallback(const EOS_Ecom_QueryOwnershipCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_ecom_query_ownership");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddString(map, "account_id", AccountID_toString(data->LocalUserId));

	RValue _array = {0};
	YYCreateArray(&_array);

	for (uint32_t i = 0; i < data->ItemOwnershipCount; i++)
	{
		RValue _struct = {0};
		YYStructCreate(&_struct);

		YYStructAddString(&_struct, "id", data->ItemOwnership[i].Id);
		YYStructAddDouble(&_struct, "ownership_status", (double)data->ItemOwnership[i].OwnershipStatus); // (data->ItemOwnership[i].OwnershipStatus == EOS_EOwnershipStatus::EOS_OS_Owned) ? 1.0 : 0.0);
		// data->ItemOwnership[i].ApiVersion

		SET_RValue(&_array, &_struct, NULL, i);
	}

	DsMapAddRValue(map, "items", &_array);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_ecom_query_ownership(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	constchar* user = YYGetString(arg, 0);
	auto vec = _SW_GetArrayOfStrings(arg, 1, "eos_ecom_query_ownership");
	// arg2 optional

	EOS_Ecom_QueryOwnershipOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_QUERYOWNERSHIP_API_LATEST;

	Options.CatalogItemIdCount = static_cast<uint32_t>(vec.size());
	Options.CatalogItemIds = vec.data();

	if (argc > 2)
	{
		constchar* catalogNamespace = YYGetString(arg, 2);
		Options.CatalogNamespace = catalogNamespace;
	}

	Options.LocalUserId = EOS_EpicAccountId_FromString(user);

	callback *mcallback = getCallbackData();
	EOS_Ecom_QueryOwnership(HEcom, &Options, mcallback, QueryOwnershipCallback);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL QueryOwnershipBySandboxIdsCallback(const EOS_Ecom_QueryOwnershipBySandboxIdsCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_ecom_query_ownership_by_sandbox_ids");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddString(map, "account_id", AccountID_toString(data->LocalUserId));

	RValue _array = {0};
	YYCreateArray(&_array);

	for (uint32_t i = 0; i < data->SandboxIdItemOwnershipsCount; i++)
	{
		RValue _struct = {0};
		YYStructCreate(&_struct);

		YYStructAddString(&_struct, "id", data->SandboxIdItemOwnerships[i].SandboxId);

		RValue __array = {0};
		YYCreateArray(&__array);

		for (uint32_t j = 0; j < data->SandboxIdItemOwnerships[i].OwnedCatalogItemIdsCount; j++)
		{
			RValue _value = {0};
			YYCreateString(&_value, data->SandboxIdItemOwnerships[i].OwnedCatalogItemIds[j]);

			SET_RValue(&__array, &_value, NULL, i);
		}

		YYStructAddRValue(&_struct, "items", &__array);

		SET_RValue(&_array, &_struct, NULL, i);
	}

	DsMapAddRValue(map, "items", &_array);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_ecom_query_ownership_by_sandbox_ids(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	constchar* user = YYGetString(arg, 0);
	auto vec = _SW_GetArrayOfStrings(arg, 1, "eos_ecom_query_ownership_by_sandbox_ids");

	EOS_Ecom_QueryOwnershipBySandboxIdsOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_QUERYOWNERSHIPBYSANDBOXIDSOPTIONS_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);

	Options.SandboxIdsCount = static_cast<uint32_t>(vec.size());
	Options.SandboxIds = vec.data();

	callback *mcallback = getCallbackData();
	EOS_Ecom_QueryOwnershipBySandboxIds(HEcom, &Options, mcallback, QueryOwnershipBySandboxIdsCallback);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL QueryOwnershipTokenCallback(const EOS_Ecom_QueryOwnershipTokenCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_ecom_query_ownership_token");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddString(map, "account_id", AccountID_toString(data->LocalUserId));
	DsMapAddString(map, "ownership_token", data->OwnershipToken);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_ecom_query_ownership_token(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	constchar* user = YYGetString(arg, 0);
	auto vec = _SW_GetArrayOfStrings(arg, 1, "eos_ecom_query_ownership_token");
	// arg2 oprtional

	EOS_Ecom_QueryOwnershipTokenOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_QUERYOWNERSHIPTOKEN_API_LATEST;

	Options.CatalogItemIdCount = static_cast<uint32_t>(vec.size());
	Options.CatalogItemIds = vec.data();

	if (argc > 2)
	{
		constchar* catalogNamespace = YYGetString(arg, 2);
		Options.CatalogNamespace = catalogNamespace;
	}

	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	callback *mcallback = getCallbackData();

	EOS_Ecom_QueryOwnershipToken(HEcom, &Options, mcallback, QueryOwnershipTokenCallback);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL OnQueryEntitlementsCallback(const EOS_Ecom_QueryEntitlementsCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_ecom_query_entitlements");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddString(map, "account_id", AccountID_toString(data->LocalUserId));

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_ecom_query_entitlements(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(3);

	constchar* user = YYGetString(arg, 0);
	auto vec = _SW_GetArrayOfStrings(arg, 1, "eos_ecom_query_entitlements");
	bool bIncludeRedeemed = YYGetBool(arg, 2);

	EOS_Ecom_QueryEntitlementsOptions Options = {0};

	Options.ApiVersion = EOS_ECOM_QUERYENTITLEMENTS_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.EntitlementNameCount = static_cast<uint32_t>(vec.size());
	Options.EntitlementNames = vec.data();
	Options.bIncludeRedeemed = bIncludeRedeemed;

	callback *mcallback = getCallbackData();

	EOS_Ecom_QueryEntitlements(HEcom, &Options, mcallback, OnQueryEntitlementsCallback);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL QueryEntitlementTokenCallback(const EOS_Ecom_QueryEntitlementTokenCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_ecom_query_entitlement_token");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddString(map, "account_id", AccountID_toString(data->LocalUserId));
	DsMapAddString(map, "entitlement_token", data->EntitlementToken);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_ecom_query_entitlement_token(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	constchar* user = YYGetString(arg, 0);
	auto vec = _SW_GetArrayOfStrings(arg, 1, "eos_ecom_query_entitlement_token");

	EOS_Ecom_QueryEntitlementTokenOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_QUERYENTITLEMENTTOKEN_API_LATEST;
	Options.EntitlementNameCount = static_cast<uint32_t>(vec.size());
	Options.EntitlementNames = vec.data();
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);

	callback *mcallback = getCallbackData();
	EOS_Ecom_QueryEntitlementToken(HEcom, &Options, mcallback, QueryEntitlementTokenCallback);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL QueryOffersCallback(const EOS_Ecom_QueryOffersCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_ecom_query_offers");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddString(map, "account_id", AccountID_toString(data->LocalUserId));

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_ecom_query_offers(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	constchar* user = YYGetString(arg, 0);

	EOS_Ecom_QueryOffersOptions Options = {};
	Options.ApiVersion = EOS_ECOM_QUERYOFFERS_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);

	if (argc > 1)
	{
		constchar* OverrideCatalogNamespace = YYGetString(arg, 1);
		Options.OverrideCatalogNamespace = OverrideCatalogNamespace;
	}

	callback *mcallback = getCallbackData();
	EOS_Ecom_QueryOffers(HEcom, &Options, mcallback, QueryOffersCallback);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

std::vector<EOS_Ecom_CheckoutEntry> entries = {};

void EOS_CALL CheckoutCallback(const EOS_Ecom_CheckoutCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_ecom_checkout");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddString(map, "account_id", AccountID_toString(data->LocalUserId));
	DsMapAddString(map, "transaction_id", data->TransactionId);

	RValue _array = {0};
	YYCreateArray(&_array);

	for (int i = 0; i < entries.size(); i++)
	{
		RValue _value = {0};
		YYCreateString(&_value, entries[i].OfferId);

		SET_RValue(&_array, &_value, NULL, i);
	}

	DsMapAddRValue(map, "offer_ids", &_array); // TODO this should be documented

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_ecom_checkout(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	constchar* user = YYGetString(arg, 0);

	EOS_Ecom_CheckoutOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_CHECKOUT_API_LATEST;

	auto vec = _SW_GetArrayOfStrings(arg, 1, "eos_ecom_checkout");

	entries.clear();

	for (int i = 0; i < vec.size(); i++)
	{
		EOS_Ecom_CheckoutEntry _entry = {0};
		_entry.ApiVersion = EOS_ECOM_CHECKOUTENTRY_API_LATEST;
		_entry.OfferId = vec[i];
		entries.push_back(_entry);
	}

	Options.EntryCount = static_cast<uint32_t>(vec.size());
	Options.Entries = entries.data();

	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	if (argc > 2)
	{
		constchar* OverrideCatalogNamespace = YYGetString(arg, 2);
		Options.OverrideCatalogNamespace = OverrideCatalogNamespace;
	}

	callback *mcallback = getCallbackData();
	EOS_Ecom_Checkout(HEcom, &Options, mcallback, CheckoutCallback);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL RedeemEntitlementsCallback(const EOS_Ecom_RedeemEntitlementsCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "eos_ecom_redeem_entitlements");
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddString(map, "account_id", AccountID_toString(data->LocalUserId));
	DsMapAddDouble(map, "redeemed_entitlement_ids_count", (double)data->RedeemedEntitlementIdsCount);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void eos_ecom_redeem_entitlements(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	constchar* user = YYGetString(arg, 0);
	auto vec = _SW_GetArrayOfStrings(arg, 1, "eos_ecom_redeem_entitlements");

	EOS_Ecom_RedeemEntitlementsOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_REDEEMENTITLEMENTS_API_LATEST;
	Options.EntitlementIdCount = static_cast<uint32_t>(vec.size());
	Options.EntitlementIds = vec.data();
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);

	callback *mcallback = getCallbackData();
	EOS_Ecom_RedeemEntitlements(HEcom, &Options, mcallback, RedeemEntitlementsCallback);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void eos_ecom_get_last_redeemed_entitlements_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	constchar* user = YYGetString(arg, 0);

	EOS_Ecom_GetLastRedeemedEntitlementsCountOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_GETLASTREDEEMEDENTITLEMENTSCOUNT_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);

	int count = EOS_Ecom_GetLastRedeemedEntitlementsCount(HEcom, &Options);

	Result.kind = VALUE_REAL;
	Result.val = (double)count;
}

YYEXPORT void eos_ecom_copy_last_redeemed_entitlement_by_index(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	constchar* user = YYGetString(arg, 0);
	uint32_t RedeemedEntitlementIndex = YYGetUint32(arg, 1);

	EOS_Ecom_CopyLastRedeemedEntitlementByIndexOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_COPYLASTREDEEMEDENTITLEMENTBYINDEX_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.RedeemedEntitlementIndex = RedeemedEntitlementIndex;

	char OutRedeemedEntitlementId[EOS_ECOM_ENTITLEMENTID_MAX_LENGTH + 1];
	int32_t InOutRedeemedEntitlementIdLength = EOS_ECOM_ENTITLEMENTID_MAX_LENGTH;
	EOS_Ecom_CopyLastRedeemedEntitlementByIndex(HEcom, &Options, OutRedeemedEntitlementId, &InOutRedeemedEntitlementIdLength);

	YYCreateString(&Result, OutRedeemedEntitlementId);
}

YYEXPORT void eos_ecom_get_entitlements_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	constchar* user = YYGetString(arg, 0);

	EOS_Ecom_GetEntitlementsCountOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_GETENTITLEMENTSCOUNT_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);

	int count = EOS_Ecom_GetEntitlementsCount(HEcom, &Options);

	Result.kind = VALUE_REAL;
	Result.val = (double)count;
}

YYEXPORT void eos_ecom_get_entitlements_by_name_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	constchar* user = YYGetString(arg, 0);
	constchar* entitlementName = YYGetString(arg, 1);

	EOS_Ecom_GetEntitlementsByNameCountOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_GETENTITLEMENTSBYNAMECOUNT_API_LATEST;
	Options.EntitlementName = entitlementName;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);

	int count = EOS_Ecom_GetEntitlementsByNameCount(HEcom, &Options);

	Result.kind = VALUE_REAL;
	Result.val = (double)count;
}

RValue EOS_Ecom_EntitlementToMap(EOS_Ecom_Entitlement *data, EOS_EResult result)
{
	RValue Struct = {0};
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result != EOS_EResult::EOS_Success)
		return Struct;

	YYStructAddBool(&Struct, "redeemed", data->bRedeemed);
	YYStructAddString(&Struct, "catalog_item_id", data->CatalogItemId);
	YYStructAddInt64(&Struct, "end_timestamp", data->EndTimestamp);
	YYStructAddString(&Struct, "entitlement_id", data->EntitlementId);
	YYStructAddString(&Struct, "entitlement_name", data->EntitlementName);
	YYStructAddDouble(&Struct, "server_index", data->ServerIndex);

	EOS_Ecom_Entitlement_Release(data);

	return Struct;
}

YYEXPORT void eos_ecom_copy_entitlement_by_index(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(2);

	constchar* user = YYGetString(arg, 0);
	uint32_t index = YYGetUint32(arg, 1);

	EOS_Ecom_CopyEntitlementByIndexOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_COPYENTITLEMENTBYINDEX_API_LATEST;
	Options.EntitlementIndex = index;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);

	EOS_Ecom_Entitlement *OutEntitlement;
	EOS_EResult result = EOS_Ecom_CopyEntitlementByIndex(HEcom, &Options, &OutEntitlement);

	RValue Struct = EOS_Ecom_EntitlementToMap(OutEntitlement, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_ecom_copy_entitlement_by_name_and_index(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(3);

	constchar* user = YYGetString(arg, 0);
	constchar* EntitlementName = YYGetString(arg, 1);
	uint32_t Index = YYGetUint32(arg, 2);

	EOS_Ecom_CopyEntitlementByNameAndIndexOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_COPYENTITLEMENTBYNAMEANDINDEX_API_LATEST;
	Options.EntitlementName = EntitlementName;
	Options.Index = Index;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);

	EOS_Ecom_Entitlement *OutEntitlement;
	EOS_EResult result = EOS_Ecom_CopyEntitlementByNameAndIndex(HEcom, &Options, &OutEntitlement);

	RValue Struct = EOS_Ecom_EntitlementToMap(OutEntitlement, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_ecom_copy_entitlement_by_id(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(2);

	constchar* user = YYGetString(arg, 0);
	constchar* EntitlementName = YYGetString(arg, 1);

	EOS_Ecom_CopyEntitlementByIdOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_COPYENTITLEMENTBYID_API_LATEST;
	Options.EntitlementId = EntitlementName;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);

	EOS_Ecom_Entitlement *OutEntitlement;
	EOS_EResult result = EOS_Ecom_CopyEntitlementById(HEcom, &Options, &OutEntitlement);

	RValue Struct = EOS_Ecom_EntitlementToMap(OutEntitlement, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_ecom_get_offer_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	constchar* user = YYGetString(arg, 0);

	EOS_Ecom_GetOfferCountOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_GETOFFERCOUNT_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	int count = EOS_Ecom_GetOfferCount(HEcom, &Options);

	Result.kind = VALUE_REAL;
	Result.val = (double)count;
}

RValue EOS_Ecom_CatalogOfferToMap(EOS_Ecom_CatalogOffer *data, EOS_EResult result)
{
	RValue Struct = {0};
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result != EOS_EResult::EOS_Success)
		return Struct;

	YYStructAddBool(&Struct, "available_for_purchase", data->bAvailableForPurchase);
	YYStructAddString(&Struct, "catalog_namespace", data->CatalogNamespace);
	YYStructAddString(&Struct, "currency_code", data->CurrencyCode);
	YYStructAddInt64(&Struct, "current_price64", data->CurrentPrice64);
	YYStructAddDouble(&Struct, "decimal_point", data->DecimalPoint);
	YYStructAddString(&Struct, "description_text", data->DescriptionText);
	YYStructAddDouble(&Struct, "discount_percentage", data->DiscountPercentage);
	YYStructAddInt64(&Struct, "effective_date_timestamp", data->EffectiveDateTimestamp);
	YYStructAddString(&Struct, "offer_id", data->Id);
	YYStructAddString(&Struct, "long_description_text", data->LongDescriptionText);
	YYStructAddInt64(&Struct, "original_price64", data->OriginalPrice64);
	YYStructAddDouble(&Struct, "price_result", (double)data->PriceResult);
	YYStructAddDouble(&Struct, "purchase_limit", data->PurchaseLimit);
	YYStructAddInt64(&Struct, "release_date_timestamp", data->ReleaseDateTimestamp);
	YYStructAddDouble(&Struct, "server_index", data->ServerIndex);
	YYStructAddString(&Struct, "title_text", data->TitleText);

	EOS_Ecom_CatalogOffer_Release(data);

	return Struct;
}

YYEXPORT void eos_ecom_copy_offer_by_index(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(2);

	constchar* user = YYGetString(arg, 0);
	uint32_t index = YYGetUint32(arg, 1);

	EOS_Ecom_CopyOfferByIndexOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_COPYOFFERBYINDEX_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.OfferIndex = index;

	EOS_Ecom_CatalogOffer *OutOffer;
	EOS_EResult result = EOS_Ecom_CopyOfferByIndex(HEcom, &Options, &OutOffer);

	RValue Struct = EOS_Ecom_CatalogOfferToMap(OutOffer, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_ecom_copy_offer_by_id(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(2);

	constchar* user = YYGetString(arg, 0);
	constchar* OfferId = YYGetString(arg, 1);

	EOS_Ecom_CopyOfferByIdOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_COPYOFFERBYID_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.OfferId = OfferId;

	EOS_Ecom_CatalogOffer *OutOffer;
	EOS_EResult result = EOS_Ecom_CopyOfferById(HEcom, &Options, &OutOffer);

	RValue Struct = EOS_Ecom_CatalogOfferToMap(OutOffer, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_ecom_get_offer_item_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	constchar* user = YYGetString(arg, 0);
	constchar* OfferId = YYGetString(arg, 1);

	EOS_Ecom_GetOfferItemCountOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_GETOFFERITEMCOUNT_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.OfferId = OfferId;

	int count = EOS_Ecom_GetOfferItemCount(HEcom, &Options);

	Result.kind = VALUE_REAL;
	Result.val = (double)count;
}

RValue EOS_Ecom_CatalogItemToMap(EOS_Ecom_CatalogItem *data, EOS_EResult result)
{
	RValue Struct = {0};
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result != EOS_EResult::EOS_Success)
		return Struct;

	/*YYStructAddBool(&Struct, "available_for_purchase", data->ApiVersion);*/
	YYStructAddString(&Struct, "catalog_namespace", data->CatalogNamespace);
	YYStructAddString(&Struct, "description_text", data->DescriptionText);
	YYStructAddString(&Struct, "developer_text", data->DeveloperText);
	YYStructAddInt64(&Struct, "entitlement_end_timestamp", data->EntitlementEndTimestamp);
	YYStructAddString(&Struct, "entitlement_name", data->EntitlementName);
	YYStructAddString(&Struct, "id", data->Id);
	YYStructAddDouble(&Struct, "item_type", (double)data->ItemType);
	YYStructAddString(&Struct, "long_description_text", data->LongDescriptionText);
	YYStructAddString(&Struct, "technical_details_text", data->TechnicalDetailsText);
	YYStructAddString(&Struct, "title_text", data->TitleText);

	EOS_Ecom_CatalogItem_Release(data);

	return Struct;
}

YYEXPORT void eos_ecom_copy_offer_item_by_index(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(3);

	constchar* user = YYGetString(arg, 0);
	constchar* OfferId = YYGetString(arg, 1);
	uint32_t index = YYGetUint32(arg, 2);

	EOS_Ecom_CopyOfferItemByIndexOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_COPYOFFERITEMBYINDEX_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.OfferId = OfferId;
	Options.ItemIndex = index;

	EOS_Ecom_CatalogItem *OutItem;
	EOS_EResult result = EOS_Ecom_CopyOfferItemByIndex(HEcom, &Options, &OutItem);

	RValue Struct = EOS_Ecom_CatalogItemToMap(OutItem, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_ecom_copy_item_by_id(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(2);

	constchar* user = YYGetString(arg, 0);
	constchar* ItemId = YYGetString(arg, 1);

	EOS_Ecom_CopyItemByIdOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_COPYITEMBYID_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.ItemId = ItemId;

	EOS_Ecom_CatalogItem *OutItem;
	EOS_EResult result = EOS_Ecom_CopyItemById(HEcom, &Options, &OutItem);

	RValue Struct = EOS_Ecom_CatalogItemToMap(OutItem, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_ecom_get_offer_image_info_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(3);

	constchar* user = YYGetString(arg, 0);
	constchar* OfferId = YYGetString(arg, 1);

	EOS_Ecom_GetOfferImageInfoCountOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_GETOFFERIMAGEINFOCOUNT_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.OfferId = OfferId;

	int count = EOS_Ecom_GetOfferImageInfoCount(HEcom, &Options);

	Result.kind = VALUE_REAL;
	Result.val = (double)count;
}

RValue EOS_Ecom_KeyImageInfoToMap(EOS_Ecom_KeyImageInfo *data, EOS_EResult result)
{
	RValue Struct = {0};
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result != EOS_EResult::EOS_Success)
		return Struct;

	YYStructAddDouble(&Struct, "height", data->Height);
	YYStructAddDouble(&Struct, "width", data->Width);
	YYStructAddString(&Struct, "type", data->Type);
	YYStructAddString(&Struct, "url", data->Url);

	EOS_Ecom_KeyImageInfo_Release(data);

	return Struct;
}

YYEXPORT void eos_ecom_copy_offer_image_info_by_index(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(3);

	constchar* user = YYGetString(arg, 0);
	constchar* OfferId = YYGetString(arg, 1);
	uint32_t ImageInfoIndex = YYGetUint32(arg, 2);

	EOS_Ecom_CopyOfferImageInfoByIndexOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_COPYOFFERIMAGEINFOBYINDEX_API_LATEST;
	Options.ImageInfoIndex = ImageInfoIndex;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.OfferId = OfferId;
	EOS_Ecom_KeyImageInfo *OutImageInfo;

	EOS_EResult result = EOS_Ecom_CopyOfferImageInfoByIndex(HEcom, &Options, &OutImageInfo);

	RValue Struct = EOS_Ecom_KeyImageInfoToMap(OutImageInfo, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_ecom_get_item_image_info_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	constchar* user = YYGetString(arg, 0);
	constchar* ItemId = YYGetString(arg, 1);

	EOS_Ecom_GetItemImageInfoCountOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_GETITEMIMAGEINFOCOUNT_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.ItemId = ItemId;

	int count = EOS_Ecom_GetItemImageInfoCount(HEcom, &Options);

	Result.kind = VALUE_REAL;
	Result.val = (double)count;
}

YYEXPORT void eos_ecom_copy_item_image_info_by_index(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(3);

	constchar* user = YYGetString(arg, 0);
	constchar* ItemId = YYGetString(arg, 1);
	uint32_t ImageInfoIndex = YYGetUint32(arg, 2);

	EOS_Ecom_CopyItemImageInfoByIndexOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_COPYITEMIMAGEINFOBYINDEX_API_LATEST;
	Options.ImageInfoIndex = ImageInfoIndex;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.ItemId = ItemId;

	EOS_Ecom_KeyImageInfo *OutImageInfo;
	EOS_EResult result = EOS_Ecom_CopyItemImageInfoByIndex(HEcom, &Options, &OutImageInfo);

	RValue Struct = EOS_Ecom_KeyImageInfoToMap(OutImageInfo, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_ecom_get_item_release_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	constchar* user = YYGetString(arg, 0);
	constchar* ItemId = YYGetString(arg, 1);

	EOS_Ecom_GetItemReleaseCountOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_GETITEMRELEASECOUNT_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.ItemId = ItemId;

	int count = EOS_Ecom_GetItemReleaseCount(HEcom, &Options);

	Result.kind = VALUE_REAL;
	Result.val = (double)count;
}

RValue EOS_Ecom_CatalogReleaseToMap(EOS_Ecom_CatalogRelease *data, EOS_EResult result)
{
	RValue Struct = {0};
	YYStructCreate(&Struct);

	YYStructAddDouble(&Struct, "status", (double)result);
	YYStructAddString(&Struct, "status_message", EOS_EResult_ToString(result));

	if (result != EOS_EResult::EOS_Success)
		return Struct;

	RValue _array = {0};
	YYCreateArray(&_array);

	for (uint32_t i = 0; i < data->CompatibleAppIdCount; i++)
	{
		RValue _value = {0};
		YYCreateString(&_value, data->CompatibleAppIds[i]);

		SET_RValue(&_array, &_value, NULL, i);
	}

	YYStructAddRValue(&Struct, "compatible_app_ids", &_array);

	RValue __array = {0};
	YYCreateArray(&__array);

	for (uint32_t i = 0; i < data->CompatiblePlatformCount; i++)
	{
		RValue _value = {0};
		YYCreateString(&_value, data->CompatiblePlatforms[i]);

		SET_RValue(&__array, &_value, NULL, i);
	}

	YYStructAddRValue(&Struct, "compatible_platforms", &__array);

	YYStructAddString(&Struct, "release_note", data->ReleaseNote);

	EOS_Ecom_CatalogRelease_Release(data);

	return Struct;
}

YYEXPORT void eos_ecom_copy_item_release_by_index(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(3);

	constchar* user = YYGetString(arg, 0);
	constchar* ItemId = YYGetString(arg, 1);
	uint32_t ReleaseIndex = YYGetUint32(arg, 2);

	EOS_Ecom_CopyItemReleaseByIndexOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_COPYITEMRELEASEBYINDEX_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.ItemId = ItemId;
	Options.ReleaseIndex = ReleaseIndex;

	EOS_Ecom_CatalogRelease *OutRelease;
	EOS_EResult result = EOS_Ecom_CopyItemReleaseByIndex(HEcom, &Options, &OutRelease);

	RValue Struct = EOS_Ecom_CatalogReleaseToMap(OutRelease, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_ecom_get_transaction_count(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	constchar* user = YYGetString(arg, 0);

	EOS_Ecom_GetTransactionCountOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_GETTRANSACTIONCOUNT_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);

	int count = EOS_Ecom_GetTransactionCount(HEcom, &Options);

	Result.kind = VALUE_REAL;
	Result.val = (double)count;
}

// YYEXPORT void eos_ecom_copy_transaction_by_index(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	EOS_Ecom_CopyTransactionByIndexOptions Options = { 0 };
//	Options.ApiVersion = EOS_ECOM_COPYTRANSACTIONBYINDEX_API_LATEST;
//	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
//	Options.TransactionIndex;
//
//	EOS_Ecom_HTransaction OutTransaction;
//	EOS_Ecom_CopyTransactionByIndex(HEcom, &Options, &OutTransaction);
// }
//
// YYEXPORT void eos_ecom_copy_transaction_by_id(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	EOS_Ecom_CopyTransactionByIdOptions Options = { 0 };
//	Options.ApiVersion = EOS_ECOM_COPYTRANSACTIONBYID_API_LATEST;
//	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
//	Options.TransactionId;
//
//	EOS_Ecom_HTransaction OutTransaction;
//	EOS_Ecom_CopyTransactionById(HEcom, &Options, &OutTransaction);
// }

YYEXPORT void eos_ecom_transaction_get_transaction_id_by_index_transaction(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_string;

	eos_ensure_argc(2);

	constchar* user = YYGetString(arg, 0);
	uint32_t TransactionIndex = YYGetUint32(arg, 1);

	EOS_Ecom_CopyTransactionByIndexOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_COPYTRANSACTIONBYINDEX_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.TransactionIndex = TransactionIndex;

	EOS_Ecom_HTransaction OutTransaction;
	EOS_Ecom_CopyTransactionByIndex(HEcom, &Options, &OutTransaction);

	char OutBuffer[1024];
	int32_t InOutBufferLength = 1024;
	EOS_Ecom_Transaction_GetTransactionId(OutTransaction, OutBuffer, &InOutBufferLength);

	YYCreateString(&Result, OutBuffer);

	EOS_Ecom_Transaction_Release(OutTransaction);
}

// No Sense....
// YYEXPORT void eos_ecom_transaction_get_transaction_id_by_id_transaction(RValue& Result, CInstance* selfinst, CInstance* otherinst, int argc, RValue* arg)
//{
//	constchar* user = YYGetString(arg, 0);
//	constchar* TransactionId = YYGetString(arg, 1);
//
//	EOS_Ecom_CopyTransactionByIdOptions Options = { 0 };
//	Options.ApiVersion = EOS_ECOM_COPYTRANSACTIONBYID_API_LATEST;
//	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
//	Options.TransactionId = TransactionId;
//
//	EOS_Ecom_HTransaction OutTransaction;
//	EOS_Ecom_CopyTransactionById(HEcom, &Options, &OutTransaction);
//
//	char OutBuffer[1024];
//	int32_t InOutBufferLength = 1024;
//	EOS_Ecom_Transaction_GetTransactionId(OutTransaction, OutBuffer, &InOutBufferLength);
//
//	YYCreateString(&Result, OutBuffer);
//
//	EOS_Ecom_Transaction_Release(OutTransaction);
// }

YYEXPORT void eos_ecom_transaction_get_entitlements_count_by_index_transaction(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	constchar* user = YYGetString(arg, 0);
	uint32_t TransactionIndex = YYGetUint32(arg, 1);

	EOS_Ecom_CopyTransactionByIndexOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_COPYTRANSACTIONBYINDEX_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.TransactionIndex = TransactionIndex;

	EOS_Ecom_HTransaction OutTransaction;
	EOS_Ecom_CopyTransactionByIndex(HEcom, &Options, &OutTransaction);

	EOS_Ecom_Transaction_GetEntitlementsCountOptions _Options = {0};
	_Options.ApiVersion = EOS_ECOM_GETTRANSACTIONCOUNT_API_LATEST;

	int count = EOS_Ecom_Transaction_GetEntitlementsCount(OutTransaction, &_Options);

	Result.kind = VALUE_REAL;
	Result.val = (double)count;
}

YYEXPORT void eos_ecom_transaction_get_entitlements_count_by_id_transaction(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(3);

	constchar* user = YYGetString(arg, 0);
	constchar* TransactionId = YYGetString(arg, 1);

	EOS_Ecom_CopyTransactionByIdOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_COPYTRANSACTIONBYID_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.TransactionId = TransactionId;

	EOS_Ecom_HTransaction OutTransaction;
	EOS_Ecom_CopyTransactionById(HEcom, &Options, &OutTransaction);

	EOS_Ecom_Transaction_GetEntitlementsCountOptions _Options = {0};
	_Options.ApiVersion = EOS_ECOM_GETTRANSACTIONCOUNT_API_LATEST;
	int count = EOS_Ecom_Transaction_GetEntitlementsCount(OutTransaction, &_Options);

	Result.kind = VALUE_REAL;
	Result.val = (double)count;
}

YYEXPORT void eos_ecom_transaction_copy_entitlement_by_index_by_index_transaction(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(3);

	constchar* user = YYGetString(arg, 0);
	uint32_t TransactionIndex = YYGetUint32(arg, 1);
	uint32_t EntitlementIndex = YYGetUint32(arg, 2);

	EOS_Ecom_CopyTransactionByIndexOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_COPYTRANSACTIONBYINDEX_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.TransactionIndex = TransactionIndex;

	EOS_Ecom_HTransaction OutTransaction;
	EOS_Ecom_CopyTransactionByIndex(HEcom, &Options, &OutTransaction);

	EOS_Ecom_Transaction_CopyEntitlementByIndexOptions _Options = {0};
	_Options.ApiVersion = EOS_ECOM_TRANSACTION_COPYENTITLEMENTBYINDEX_API_LATEST;
	_Options.EntitlementIndex = EntitlementIndex;

	EOS_Ecom_Entitlement *OutEntitlement;
	EOS_EResult result = EOS_Ecom_Transaction_CopyEntitlementByIndex(OutTransaction, &_Options, &OutEntitlement);

	RValue Struct = EOS_Ecom_EntitlementToMap(OutEntitlement, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}

YYEXPORT void eos_ecom_transaction_copy_entitlement_by_index_by_id_transaction(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_struct;

	eos_ensure_argc(3);

	constchar* user = YYGetString(arg, 0);
	constchar* TransactionId = YYGetString(arg, 1);
	uint32_t EntitlementIndex = YYGetUint32(arg, 2);

	EOS_Ecom_CopyTransactionByIdOptions Options = {0};
	Options.ApiVersion = EOS_ECOM_COPYTRANSACTIONBYID_API_LATEST;
	Options.LocalUserId = EOS_EpicAccountId_FromString(user);
	Options.TransactionId = TransactionId;

	EOS_Ecom_HTransaction OutTransaction;
	EOS_Ecom_CopyTransactionById(HEcom, &Options, &OutTransaction);

	EOS_Ecom_Transaction_CopyEntitlementByIndexOptions _Options = {0};
	_Options.ApiVersion = EOS_ECOM_TRANSACTION_COPYENTITLEMENTBYINDEX_API_LATEST;
	_Options.EntitlementIndex = EntitlementIndex;

	EOS_Ecom_Entitlement *OutEntitlement;
	EOS_EResult result = EOS_Ecom_Transaction_CopyEntitlementByIndex(OutTransaction, &_Options, &OutEntitlement);

	RValue Struct = EOS_Ecom_EntitlementToMap(OutEntitlement, result);

	COPY_RValue(&Result, &Struct);
	FREE_RValue(&Struct);
}
