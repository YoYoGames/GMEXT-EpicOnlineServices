

func double __eos_active_session_copy_info(char* SessionName,char* buff_ret)

func char* eos_active_session_get_registered_player_by_index(char* SessionName)

func double eos_active_session_get_registered_player_count(char* SessionName)

EOS_HSessionDetails mHSessionDetails = 0;
func double __eos_session_details_copy_info(char* buff_ret)

func double __eos_session_details_copy_session_attribute_by_index(double AttrIndex,char* buff_ret)

func double __eos_session_details_copy_session_attribute_by_key(char* AttrKey,char* buff_ret)

func double eos_session_details_get_session_attribute_count()

func double eos_session_details_release()


EOS_HSessionModification mHSessionModification = 0;

func double __eos_session_modification_add_attribute(double AdvertisementType, double SessionAttribute,char* buff_args)

func double eos_session_modification_release()

func double eos_session_modification_remove_attribute(char* Key)

func double __eos_session_modification_set_allowed_platform_ids(char* buff_args)

func double eos_session_modification_set_bucket_id(char* BucketId)

func double eos_session_modification_set_host_address(char* HostAddress)

func double eos_session_modification_set_invites_allowed(double bInvitesAllowed)

func double eos_session_modification_set_join_in_progress_allowed(double bAllowJoinInProgress)

func double eos_session_modification_set_max_players(double MaxPlayers)

func double eos_session_modification_set_permission_level(double PermissionLevel)

	DsMapAddString(map, "type", "eos_sessions_add_notify_join_session_accepted");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddInt64(map, "ui_event_id", (int64)data->UiEventId);

func double __eos_sessions_add_notify_join_session_accepted(char* buff_ret)

	DsMapAddString(map, "type", "eos_sessions_add_notify_leave_session_requested");
	// DsMapAddDouble(map, "status", (double)data->ResultCode);
	// DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	// DsMapAddDouble(map, "identifier", (double)((callback*)(data->ClientData))->identifier);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "session_name", data->SessionName);

func double __eos_sessions_add_notify_leave_session_requested(char* buff_ret)

	DsMapAddString(map, "type", "eos_sessions_add_notify_send_session_native_invite_requested");
	// DsMapAddDouble(map, "status", (double)data->ResultCode);
	// DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	// DsMapAddDouble(map, "identifier", (double)((callback*)(data->ClientData))->identifier);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "target_native_account_type", data->TargetNativeAccountType);
	DsMapAddString(map, "target_user_native_account_id", data->TargetUserNativeAccountId);
	DsMapAddString(map, "session_id", data->SessionId);
	DsMapAddInt64(map, "ui_event_id", (int64)data->UiEventId);

func double __eos_sessions_add_notify_send_session_native_invite_requested(char* buff_ret)

	DsMapAddString(map, "type", "eos_sessions_add_notify_session_invite_accepted");
	// DsMapAddDouble(map, "status", (double)data->ResultCode);
	// DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	// DsMapAddDouble(map, "identifier", (double)((callback*)(data->ClientData))->identifier);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "invite_id", data->InviteId);
	DsMapAddString(map, "session_id", data->SessionId);
	DsMapAddString(map, "target_user_id", productID_toString(data->TargetUserId));

func double __eos_sessions_add_notify_session_invite_accepted(char* buff_ret)

	DsMapAddString(map, "type", "eos_sessions_add_notify_session_invite_received");
	// DsMapAddDouble(map, "status", (double)data->ResultCode);
	// DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	// DsMapAddDouble(map, "identifier", (double)((callback*)(data->ClientData))->identifier);
	DsMapAddString(map, "invite_id", data->InviteId);
	DsMapAddString(map, "target_user_id", productID_toString(data->TargetUserId));
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));

func double __eos_sessions_add_notify_session_invite_received(char* buff_ret)

	DsMapAddString(map, "type", "eos_sessions_add_notify_session_invite_rejected");
	// DsMapAddDouble(map, "status", (double)data->ResultCode);
	// DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	// DsMapAddDouble(map, "identifier", (double)((callback*)(data->ClientData))->identifier);
	DsMapAddString(map, "invite_id", data->InviteId);
	DsMapAddString(map, "target_user_id", productID_toString(data->TargetUserId));
	DsMapAddString(map, "session_id", data->SessionId);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));

func double __eos_sessions_add_notify_session_invite_rejected(char* buff_ret)

func double eos_sessions_copy_session_handle_by_invite_id(char* InviteId)

func double __eos_sessions_copy_session_handle_by_ui_event_id(char* buff_args)

func double eos_sessions_copy_session_handle_for_presence(char* local)

func double __eos_sessions_create_session_modification(char* buff_args)

EOS_HSessionSearch mOutSessionSearchHandle = 0;
func double eos_sessions_create_session_search(double MaxSearchResults)

void EOS_CALL Sessions_OnDestroySessionCallback(const EOS_Sessions_DestroySessionCallbackInfo *data)
	DsMapAddString(map, "type", "eos_sessions_destroy_session");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

func double eos_sessions_destroy_session(char* SessionName)

func double eos_sessions_dump_session_state(char* SessionName)

	DsMapAddString(map, "type", "eos_sessions_end_session");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

func double eos_sessions_end_session(char* SessionName)

func double eos_sessions_get_invite_count(char* local)

func char* eos_sessions_get_invite_id_by_index(char* local, double index)

func double eos_sessions_is_user_in_session(char* SessionName,char* TargetUserId)

	DsMapAddString(map, "type", "eos_sessions_join_session");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

func double eos_sessions_join_session(double PresenceEnabled,char* LocalUserId,char* SessionName)

	DsMapAddString(map, "type", "eos_sessions_query_invites");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));

func double eos_sessions_query_invites(char* TargetUserId)

	DsMapAddString(map, "type", "eos_sessions_register_players");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "registered_players", productIds2ArrayStr(data->RegisteredPlayers, data->RegisteredPlayersCount).c_str());
	DsMapAddString(map, "sanctioned_players", productIds2ArrayStr(data->SanctionedPlayers, data->SanctionedPlayersCount).c_str());

func double __eos_sessions_register_players(char* SessionName,char* buff_args)

	DsMapAddString(map, "type", "eos_sessions_reject_invite");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

func double eos_sessions_reject_invite(char* LocalUserId,char* InviteId)

func double __eos_sessions_remove_notify_join_session_accepted(char* buff_args)

func double __eos_sessions_remove_notify_leave_session_requested(char* buff_args)

func double __eos_sessions_remove_notify_send_session_native_invite_requested(char* buff_args)

func double __eos_sessions_remove_notify_session_invite_accepted(char* buff_args)

func double __eos_sessions_remove_notify_session_invite_received(char* buff_args)

func double __eos_sessions_remove_notify_session_invite_rejected(char* buff_args)

	DsMapAddString(map, "type", "eos_sessions_send_invite");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

func double eos_sessions_send_invite(char* LocalUserId,char* SessionName,char* TargetUserId)

	DsMapAddString(map, "type", "eos_sessions_start_session");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

func double eos_sessions_start_session(char* SessionName)

	DsMapAddString(map, "type", "eos_sessions_unregister_players");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "unregistered_players", productIds2ArrayStr(data->UnregisteredPlayers, data->UnregisteredPlayersCount).c_str());
func double __eos_sessions_unregister_players(char* SessionName,char* buff_args)

	DsMapAddString(map, "type", "eos_sessions_update_session");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "session_id", data->SessionId);
	DsMapAddString(map, "session_name", data->SessionName);

func double eos_sessions_update_session()

func double eos_sessions_update_session_modification(char* SessionName)

func double eos_session_search_copy_search_result_by_index(double SessionIndex)

	DsMapAddString(map, "type", "eos_session_search_find");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

func double eos_session_search_find(char* LocalUserId)

func double eos_session_search_get_search_result_count()

func double eos_session_search_release()

func double eos_session_search_remove_parameter(char* Key, double ComparisonOp)

func double eos_session_search_set_max_results(double MaxSearchResults)

func double __eos_session_search_set_parameter(double comparisonOp,char* buff_args)

func double eos_session_search_set_session_id(char* SessionId)

func double eos_session_search_set_target_user_id(char* TargetUserId)
