
// EOS_Friends_AcceptInvite
// EOS_Friends_AddNotifyFriendsUpdate
// EOS_Friends_GetFriendAtIndex
// EOS_Friends_GetFriendsCount
// EOS_Friends_GetStatus
// EOS_Friends_QueryFriends
// EOS_Friends_RejectInvite
// EOS_Friends_RemoveNotifyFriendsUpdate
// EOS_Friends_SendInvite

#include "pch.h"
#include "YYEpicOnlineServices.h"
#include <eos_friends.h>

//EOS_HFriends HFriends;
void EpicGames_Friends_Init()
{
	HFriends = EOS_Platform_GetFriendsInterface(PlatformHandle);
}

void EOS_CALL AcceptFriendInviteCompleteCallbackFn_old(const EOS_Friends_AcceptInviteCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Friends_AcceptInvite");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void EpicGames_Friends_AcceptInvite(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *target = YYGetString(arg, 1);

	EOS_Friends_AcceptInviteOptions AcceptInviteOptions;
	AcceptInviteOptions.ApiVersion = EOS_FRIENDS_ACCEPTINVITE_API_LATEST;
	AcceptInviteOptions.LocalUserId = EOS_EpicAccountId_FromString(user);
	AcceptInviteOptions.TargetUserId = EOS_EpicAccountId_FromString(target);

	callback *mcallback = getCallbackData();

	EOS_Friends_AcceptInvite(HFriends, &AcceptInviteOptions, mcallback, AcceptFriendInviteCompleteCallbackFn_old);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL FriendUpdateCallback_old(const EOS_Friends_OnFriendsUpdateInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Friends_AddNotifyFriendsUpdate");
	DsMapAddDouble(map, "CurrentStatus", (double)data->CurrentStatus);
	DsMapAddDouble(map, "PreviousStatus", (double)data->PreviousStatus);
	DsMapAddString(map, "TargetUserId", AccountID_toString(data->TargetUserId));
	DsMapAddString(map, "LocalUserId", AccountID_toString(data->LocalUserId));

	CreateAsyncEventWithDSMap(map, 70);
}

YYEXPORT void EpicGames_Friends_AddNotifyFriendsUpdate(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_int64;

	EOS_Friends_AddNotifyFriendsUpdateOptions Options;
	Options.ApiVersion = EOS_FRIENDS_ADDNOTIFYFRIENDSUPDATE_API_LATEST;

	EOS_NotificationId NotificationId = EOS_Friends_AddNotifyFriendsUpdate(HFriends, &Options, nullptr, FriendUpdateCallback_old);

	Result.kind = VALUE_INT64;
	Result.v64 = static_cast<int64_t>(NotificationId);
}

YYEXPORT void EpicGames_Friends_GetFriendAtIndex(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_string;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	int index = (int)YYGetReal(arg, 1);

	EOS_Friends_GetFriendAtIndexOptions IndexOptions;
	IndexOptions.ApiVersion = EOS_FRIENDS_GETFRIENDATINDEX_API_LATEST;
	IndexOptions.LocalUserId = EOS_EpicAccountId_FromString(user);
	IndexOptions.Index = index;

	EOS_EpicAccountId FriendUserId = EOS_Friends_GetFriendAtIndex(HFriends, &IndexOptions);

	YYCreateString(&Result, AccountID_toString(FriendUserId));
}

YYEXPORT void EpicGames_Friends_GetFriendsCount(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_int32;

	eos_ensure_argc(1);

	const char *user = YYGetString(arg, 0);

	EOS_Friends_GetFriendsCountOptions FriendsCountOptions;
	FriendsCountOptions.ApiVersion = EOS_FRIENDS_GETFRIENDSCOUNT_API_LATEST;
	FriendsCountOptions.LocalUserId = EOS_EpicAccountId_FromString(user);
	int32_t FriendCount = EOS_Friends_GetFriendsCount(HFriends, &FriendsCountOptions);

	Result.kind = VALUE_INT32;
	Result.v32 = FriendCount;
}

YYEXPORT void EpicGames_Friends_GetStatus(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *target = YYGetString(arg, 1);

	EOS_Friends_GetStatusOptions StatusOptions;
	StatusOptions.ApiVersion = EOS_FRIENDS_GETSTATUS_API_LATEST;
	StatusOptions.LocalUserId = EOS_EpicAccountId_FromString(user);
	StatusOptions.TargetUserId = EOS_EpicAccountId_FromString(target);
	EOS_EFriendsStatus FriendStatus = EOS_Friends_GetStatus(HFriends, &StatusOptions);

	Result.kind = VALUE_REAL;
	Result.val = (double)FriendStatus;
}

void EOS_CALL QueryFriendsCompleteCallbackFn_old(const EOS_Friends_QueryFriendsCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Friends_QueryFriends");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void EpicGames_Friends_QueryFriends(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	const char *user = YYGetString(arg, 0);

	EOS_Friends_QueryFriendsOptions QueryFriendsOptions;
	QueryFriendsOptions.ApiVersion = EOS_FRIENDS_QUERYFRIENDS_API_LATEST;
	QueryFriendsOptions.LocalUserId = EOS_EpicAccountId_FromString(user);

	callback *mcallback = getCallbackData();

	EOS_Friends_QueryFriends(HFriends, &QueryFriendsOptions, mcallback, QueryFriendsCompleteCallbackFn_old);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

void EOS_CALL RejectFriendInviteCompleteCallbackFn_old(const EOS_Friends_RejectInviteCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Friends_RejectInvite");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void EpicGames_Friends_RejectInvite(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *target = YYGetString(arg, 1);

	EOS_Friends_RejectInviteOptions RejectInviteOptions;
	RejectInviteOptions.ApiVersion = EOS_FRIENDS_REJECTINVITE_API_LATEST;
	RejectInviteOptions.LocalUserId = EOS_EpicAccountId_FromString(user);
	RejectInviteOptions.TargetUserId = EOS_EpicAccountId_FromString(target);

	callback *mcallback = getCallbackData();

	EOS_Friends_RejectInvite(HFriends, &RejectInviteOptions, mcallback, &RejectFriendInviteCompleteCallbackFn_old);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}

YYEXPORT void EpicGames_Friends_RemoveNotifyFriendsUpdate(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(1);

	int64 notifyIndex = YYGetInt64(arg, 0);
	EOS_Friends_RemoveNotifyFriendsUpdate(HFriends, notifyIndex);
}

void EOS_CALL SendFriendInviteCompleteCallbackFn_old(const EOS_Friends_SendInviteCallbackInfo *data)
{
	int map = CreateDsMap(0, 0);
	DsMapAddString(map, "type", "EpicGames_Friends_SendInvite");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	CreateAsyncEventWithDSMap(map, 70);

	delete reinterpret_cast<callback *>(data->ClientData);
}

YYEXPORT void EpicGames_Friends_SendInvite(RValue &Result, CInstance *selfinst, CInstance *otherinst, int argc, RValue *arg)
{
	eos_not_init_return_rvalue_real;

	eos_ensure_argc(2);

	const char *user = YYGetString(arg, 0);
	const char *target = YYGetString(arg, 1);

	EOS_Friends_SendInviteOptions SendInviteOptions;
	SendInviteOptions.ApiVersion = EOS_FRIENDS_SENDINVITE_API_LATEST;
	SendInviteOptions.LocalUserId = EOS_EpicAccountId_FromString(user);
	SendInviteOptions.TargetUserId = EOS_EpicAccountId_FromString(target);

	callback *mcallback = getCallbackData();

	EOS_Friends_SendInvite(HFriends, &SendInviteOptions, mcallback, &SendFriendInviteCompleteCallbackFn_old);

	Result.kind = VALUE_REAL;
	Result.val = (double)mcallback->identifier;
}
