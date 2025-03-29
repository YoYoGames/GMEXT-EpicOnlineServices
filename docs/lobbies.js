	DsMapAddString(map, "type", "eos_lobby_add_notify_join_lobby_accepted");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddInt64(map, "ui_event_id", (int64)data->UiEventId);

func double __eos_lobby_add_notify_join_lobby_accepted(char* buff_ret)

	DsMapAddString(map, "type", "eos_lobby_add_notify_leave_lobby_requested");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "lobby_id", data->LobbyId);

func double __eos_lobby_add_notify_leave_lobby_requested(char* buff_ret)

	DsMapAddString(map, "type", "eos_lobby_add_notify_lobby_invite_accepted");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "lobby_id", data->LobbyId);
	DsMapAddString(map, "invite_id", data->InviteId);
	DsMapAddString(map, "target_user_id", productID_toString(data->TargetUserId));

func double __eos_lobby_add_notify_lobby_invite_accepted(char* buff_ret)

	DsMapAddString(map, "type", "eos_lobby_add_notify_lobby_invite_received");
	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "invite_id", data->InviteId);
	DsMapAddString(map, "target_user_id", productID_toString(data->TargetUserId));

func double __eos_lobby_add_notify_lobby_invite_received(char* buff_ret)

	DsMapAddString(map, "type", "eos_lobby_add_notify_lobby_invite_rejected");

	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "lobby_id", data->LobbyId);
	DsMapAddString(map, "invite_id", data->InviteId);
	DsMapAddString(map, "target_user_id", productID_toString(data->TargetUserId));

func double __eos_lobby_add_notify_lobby_invite_rejected(char* buff_ret)

	DsMapAddString(map, "type", "eos_lobby_add_notify_lobby_member_status_received");

	DsMapAddString(map, "target_user_id", productID_toString(data->TargetUserId));
	DsMapAddString(map, "lobby_id", data->LobbyId);
	DsMapAddDouble(map, "current_status", (double)data->CurrentStatus);

func double __eos_lobby_add_notify_lobby_member_status_received(char* buff_ret)

	DsMapAddString(map, "type", "eos_lobby_add_notify_lobby_member_update_received");

	DsMapAddString(map, "target_user_id", productID_toString(data->TargetUserId));
	DsMapAddString(map, "lobby_id", data->LobbyId);

func double __eos_lobby_add_notify_lobby_member_update_received(char* buff_ret)

	DsMapAddString(map, "type", "eos_lobby_add_notify_lobby_update_received");
	DsMapAddString(map, "lobby_id", data->LobbyId);

func double __eos_lobby_add_notify_lobby_update_received(char* buff_ret)

	DsMapAddString(map, "type", "eos_lobby_add_notify_rtc_room_connection_changed");

	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "lobby_id", data->LobbyId);
	DsMapAddDouble(map, "disconnect_reason", (double)data->DisconnectReason);
	DsMapAddDouble(map, "is_connected", data->bIsConnected ? 1.0 : 0.0);

func double __eos_lobby_add_notify_rtc_room_connection_changed(char* buff_ret)

	DsMapAddString(map, "type", "eos_lobby_add_notify_send_lobby_native_invite_requested");

	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));
	DsMapAddString(map, "lobby_id", data->LobbyId);

	DsMapAddString(map, "local_user_id", data->TargetNativeAccountType);
	DsMapAddString(map, "lobby_id", data->TargetUserNativeAccountId);
	DsMapAddInt64(map, "ui_event_id", (int64)data->UiEventId);
func double __eos_lobby_add_notify_send_lobby_native_invite_requested(char* buff_ret)

func double eos_lobby_copy_lobby_details_handle(char* LobbyId,char* LocalUserId)

func double eos_lobby_copy_lobby_details_handle_by_invite_id(char* InviteId)

func double __eos_lobby_copy_lobby_details_handle_by_ui_event_id(char* buff_args)

	DsMapAddString(map, "type", "eos_lobby_create_lobby");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "lobby_id", data->LobbyId);

func double __eos_lobby_create_lobby(char* buff_args)

func double eos_lobby_create_lobby_search(double MaxResults)

	DsMapAddString(map, "type", "eos_lobby_destroy_lobby");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "lobby_id", data->LobbyId);

func double eos_lobby_destroy_lobby(char* LobbyId,char* LocalUserID)

func char* eos_lobby_get_connect_string(char* LobbyId,char* LocalUserId)

func double eos_lobby_get_invite_count(char* LocalUserID)

func char* eos_lobby_get_invite_id_by_index(char* LocalUserID, double index)

func char* eos_lobby_get_rtc_room_name(char* LocalUserID,char* LobbyId)

	DsMapAddString(map, "type", "eos_lobby_hard_mute_member");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "lobby_id", data->LobbyId);
	DsMapAddString(map, "target_user_id", productID_toString(data->TargetUserId));

func double eos_lobby_hard_mute_member(double HardMute,char* LobbyId,char* LocalUserId,char* TargetUserId)

func double eos_lobby_is_rtc_room_connected(char* LobbyId,char* LocalUserId)

	DsMapAddString(map, "type", "eos_lobby_join_lobby");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "lobby_id", data->LobbyId);

func double __eos_lobby_join_lobby(char* buff_args)

	DsMapAddString(map, "type", "eos_lobby_join_lobby_by_id");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	DsMapAddString(map, "lobby_id", data->LobbyId);

func double __eos_lobby_join_lobby_by_id(char* buff_args)

	DsMapAddString(map, "type", "eos_lobby_kick_member");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "lobby_id", data->LobbyId);

func double eos_lobby_kick_member(char* LobbyId,char* LocalUserId,char* TargetUserId)

	DsMapAddString(map, "type", "eos_lobby_leave_lobby");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "lobby_id", data->LobbyId);

func double eos_lobby_leave_lobby(char* LobbyId,char* LocalUserId)

func char* eos_lobby_parse_connect_string()

	DsMapAddString(map, "type", "eos_lobby_promote_member");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);
	DsMapAddString(map, "lobby_id", data->LobbyId);

func double eos_lobby_promote_member(char* LobbyId,char* LocalUserId,char* TargetUserId)

	DsMapAddString(map, "type", "eos_lobby_query_invites");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	DsMapAddString(map, "local_user_id", productID_toString(data->LocalUserId));

func double eos_lobby_query_invites(char* LocalUserId)

	DsMapAddString(map, "type", "eos_lobby_reject_invite");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	DsMapAddString(map, "status_message", data->InviteId);

func double eos_lobby_reject_invite(char* InviteId,char* LocalUserId)

func double __eos_lobby_remove_notify_join_lobby_accepted(char* buff_args)

func double __eos_lobby_remove_notify_leave_lobby_requested(char* buff_args)

func double __eos_lobby_remove_notify_lobby_invite_accepted(char* buff_args)

func double __eos_lobby_remove_notify_lobby_invite_received(char* buff_args)

func double __eos_lobby_remove_notify_lobby_invite_rejected(char* buff_args)

func double __eos_lobby_remove_notify_lobby_member_status_received(char* buff_args)

func double __eos_lobby_remove_notify_lobby_member_update_received(char* buff_args)

func double __eos_lobby_remove_notify_lobby_update_received(char* buff_args)

func double __eos_lobby_remove_notify_rtc_room_connection_changed(char* buff_args)

func double __eos_lobby_remove_notify_send_lobby_native_invite_requested(char* buff_args)

	DsMapAddString(map, "type", "eos_lobby_send_invite");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	DsMapAddString(map, "lobby_id", data->LobbyId);

func double eos_lobby_send_invite(char* LobbyId,char* LocalUserId,char* TargetUserId)

	DsMapAddString(map, "type", "eos_lobby_update_lobby");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

	DsMapAddString(map, "lobby_id", data->LobbyId);

func double eos_lobby_update_lobby()

func double eos_lobby_update_lobby_modification(char* LobbyId,char* LocalUserId)

func double __eos_lobby_details_copy_attribute_by_index(double index,char* buff_ret)

func double __eos_lobby_details_copy_attribute_by_key(char* AttrKey,char* buff_ret)

func double __eos_lobby_details_copy_info(char* buff_ret)

func double __eos_lobby_details_copy_member_attribute_by_index(double index,char* TargetUserId,char* buff_ret)

func double eos_lobby_details_copy_member_attribute_by_key(char* AttrKey,char* TargetUserId)

func double __eos_lobby_details_copy_member_info(char* TargetUserId,char* buff_ret)

func double eos_lobby_details_get_attribute_count()

func char* eos_lobby_details_get_lobby_owner()

func double eos_lobby_details_get_member_attribute_count(char* TargetUserId)

func char* eos_lobby_details_get_member_by_index(double index)

func double eos_lobby_details_get_member_count()

func double eos_lobby_details_release()

func double __eos_lobby_modification_add_attribute(double Visibility,char* buff_args)

func double __eos_lobby_modification_add_member_attribute(double Visibility,char* buff_args)

func double eos_lobby_modification_release()

func double eos_lobby_modification_remove_attribute(char* Key)

func double eos_lobby_modification_remove_member_attribute(char* Key)

func double __eos_lobby_modification_set_allowed_platform_ids(char* buff_args)

func double eos_lobby_modification_set_bucket_id(char* BucketId)

func double eos_lobby_modification_set_invites_allowed(double InvitesAllowed)

func double eos_lobby_modification_set_max_members(double MaxMembers)

func double eos_lobby_modification_set_permission_level(double PermissionLevel)

func double eos_lobby_search_copy_search_result_by_index(double Index)

	DsMapAddString(map, "type", "eos_lobby_search_find");
	DsMapAddDouble(map, "status", (double)data->ResultCode);
	DsMapAddString(map, "status_message", EOS_EResult_ToString(data->ResultCode));
	DsMapAddDouble(map, "identifier", (double)((callback *)(data->ClientData))->identifier);

func double eos_lobby_search_find(char* LocalUserId)

func double eos_lobby_search_get_search_result_count()

func double eos_lobby_search_release()

func double eos_lobby_search_remove_parameter(char* Key, double ComparisonOp)

func double eos_lobby_search_set_lobby_id(char* LobbyId)

func double eos_lobby_search_set_max_results(double MaxResults)

func double __eos_lobby_search_set_parameter(double ComparisonOp,char* buff_args)

func double eos_lobby_search_set_target_user_id(char* TargetUserId)
