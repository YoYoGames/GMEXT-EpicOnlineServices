
LOBBIES REFERENCE PAGE: https://dev.epicgames.com/docs/api-ref/interfaces/lobby

------------------------------------------------------------------------------------

int64 eos_lobby_add_notify_join_lobby_accepted()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-join-lobby-accepted

ASYNC:

	string -> type"eos_lobby_add_notify_join_lobby_accepted");
	string -> "local_user_id"
	int64 -> "ui_event_id"

------------------------------------------------------------------------------------

int64 eos_lobby_add_notify_leave_lobby_requested()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-leave-lobby-requested

ASYNC

	string -> type"eos_lobby_add_notify_leave_lobby_requested");
	string -> "local_user_id"
	string -> "lobby_id"

------------------------------------------------------------------------------------

int64 eos_lobby_add_notify_lobby_invite_accepted()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-lobby-invite-accepted

ASYNC

	string -> type"eos_lobby_add_notify_lobby_invite_accepted");
	string -> "local_user_id"
	string -> "lobby_id"
	string -> "invite_id"
	string -> "target_user_id"

------------------------------------------------------------------------------------

int64 eos_lobby_add_notify_lobby_invite_received()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-lobby-invite-received

ASYNC

	string -> type"eos_lobby_add_notify_lobby_invite_received");
	string -> "local_user_id"
	string -> "invite_id"
	string -> "target_user_id"

------------------------------------------------------------------------------------

int64 eos_lobby_add_notify_lobby_invite_rejected()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-lobby-invite-rejected

ASYNC

	string -> type"eos_lobby_add_notify_lobby_invite_rejected");
	string -> "local_user_id"
	string -> "lobby_id"
	string -> "invite_id"
	string -> "target_user_id"

------------------------------------------------------------------------------------

int64 eos_lobby_add_notify_lobby_member_status_received()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-lobby-member-status-received

ASYNC

	string -> type"eos_lobby_add_notify_lobby_member_status_received");
	string -> "target_user_id"
	string -> "lobby_id"
	real -> "current_status"

------------------------------------------------------------------------------------

int64 eos_lobby_add_notify_lobby_member_update_received()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-lobby-member-update-received

ASYNC

	string -> type"eos_lobby_add_notify_lobby_member_update_received");
	string -> "target_user_id"
	string -> "lobby_id"

------------------------------------------------------------------------------------

int64 eos_lobby_add_notify_lobby_update_received()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-lobby-update-received

ASYNC

	string -> type"eos_lobby_add_notify_lobby_update_received");
	string -> "lobby_id"

------------------------------------------------------------------------------------
int64 eos_lobby_add_notify_rtc_room_connection_Stringnged()
https://dev.epicgames.com/docs/en-US/api-ref/structs/eos-lobby-add-notify-rtc-room-connection-Stringnged-options

ASYNC

	string -> type"eos_lobby_add_notify_rtc_room_connection_Stringnged");
	string -> "local_user_id"
	string -> "lobby_id"
	real -> "disconnect_reason"
	real -> "is_connected"


------------------------------------------------------------------------------------

int64 eos_lobby_add_notify_send_lobby_native_invite_requested()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-add-notify-send-lobby-native-invite-requested

ASYNC
	string -> type"eos_lobby_add_notify_send_lobby_native_invite_requested");
	string -> "local_user_id"
	string -> "lobby_id"
	string -> "local_user_id"
	string -> "lobby_id"
	int64 -> "ui_event_id"

------------------------------------------------------------------------------------

double eos_lobby_copy_lobby_details_handle(char* lobby_id,char* local_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-copy-lobby-details-handle

------------------------------------------------------------------------------------

double eos_lobby_copy_lobby_details_handle_by_invite_id(String InviteId)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-copy-lobby-details-handle-by-invite-id

------------------------------------------------------------------------------------

double eos_lobby_copy_lobby_details_handle_by_ui_event_id()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-copy-lobby-details-handle-by-ui-event-id

------------------------------------------------------------------------------------

double eos_lobby_create_lobby
		[local_user_id,buffer_string],
		[allowed_platform_ids, buffer_u32],//0,Array
		[lobby_id,buffer_string],
		[bucket_id,buffer_string],
		[max_lobby_members,buffer_f64],
		[permission_level, buffer_u8],
		[allow_invites,buffer_bool],
		[crossplay_opt_out,buffer_bool],
		[disable_host_migration,buffer_bool],
		[enable_join_by_id,buffer_bool],
		[presence_enabled,buffer_bool],
		[enable_rtc_room,buffer_bool],
		[flags,buffer_u32],
		[use_manual_audio_input,buffer_bool],
		[use_manual_audio_output,buffer_bool],
		[local_audio_device_input_starts_muted,buffer_bool],
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-create-lobby

ASYNC

	string -> type"eos_lobby_create_lobby");
	real -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "lobby_id"

------------------------------------------------------------------------------------

double eos_lobby_create_lobby_search(double max_results)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-create-lobby-search

------------------------------------------------------------------------------------

double eos_lobby_destroy_lobby(char* lobby_id,char* local_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-destroy-lobby

ASYNC

	string -> type"eos_lobby_destroy_lobby");
	real -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "lobby_id"

------------------------------------------------------------------------------------

String eos_lobby_get_connect_string(char* lobby_id,char* local_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-get-connect-string

------------------------------------------------------------------------------------

double eos_lobby_get_invite_count(char* local_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-get-invite-count

------------------------------------------------------------------------------------

String eos_lobby_get_invite_id_by_index(char* local_user_id, double index)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-get-invite-id-by-index

------------------------------------------------------------------------------------

String eos_lobby_get_rtc_room_name(char* local_user_id,char* lobby_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-get-rtc-room-name

------------------------------------------------------------------------------------

double eos_lobby_hard_mute_member(double hard_mute,char* lobby_id,char* local_user_id,char* target_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-hard-mute-member

ASYNC

	string -> type"eos_lobby_hard_mute_member");
	real -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "lobby_id"
	string -> "target_user_id"


------------------------------------------------------------------------------------

double eos_lobby_is_rtc_room_connected(char* lobby_id,char* local_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-is-rtc-room-connected

------------------------------------------------------------------------------------

double eos_lobby_join_lobby(string local_user_id,bool crossplay_opt_out, bool presence_enabled, bool enable_rtc_room, bool local_audio_device_input_starts_muted, bool use_manual_audio_input, bool use_manual_audio_output, flags)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-join-lobby

ASYNC

	string -> type"eos_lobby_join_lobby");
	real -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "lobby_id"

------------------------------------------------------------------------------------

double eos_lobby_join_lobby_by_id(String local_user_id,bool crossplay_opt_out,bool presence_enabled, string lobby_id,, bool enable_rtc_room, bool local_audio_device_input_starts_muted, bool use_manual_audio_input, bool use_manual_audio_output, flags)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-join-lobby-by-id

ASYNC

	string -> type"eos_lobby_join_lobby_by_id");
	real -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "lobby_id"

------------------------------------------------------------------------------------

double eos_lobby_kick_member(char* lobby_id,char* local_user_id,char* target_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-kick-member

ASYNC

	string -> type"eos_lobby_kick_member");
	real -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "lobby_id"

------------------------------------------------------------------------------------

double eos_lobby_leave_lobby(char* lobby_id,char* local_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-leave-lobby
ASYNC
	string -> type"eos_lobby_leave_lobby");
	real -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "lobby_id"

------------------------------------------------------------------------------------

String eos_lobby_parse_connect_string()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-parse-connect-string

------------------------------------------------------------------------------------

double eos_lobby_promote_member(char* lobby_id,char* local_user_id,char* target_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-promote-member

ASYNC

	string -> type"eos_lobby_promote_member");
	real -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "lobby_id"


------------------------------------------------------------------------------------

double eos_lobby_query_invites(char* local_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-query-invites

ASYNC

	string -> type"eos_lobby_query_invites");
	real -> "status"
	string -> "status_message"
	real -> "identifier"

	string -> "local_user_id"

------------------------------------------------------------------------------------

double eos_lobby_reject_invite(char* invite_id,char* local_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-reject-invite

ASYNC 

	string -> type"eos_lobby_reject_invite");
	real -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "status_message"


------------------------------------------------------------------------------------

double eos_lobby_remove_notify_join_lobby_accepted(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-join-lobby-accepted

------------------------------------------------------------------------------------

double eos_lobby_remove_notify_leave_lobby_requested(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-leave-lobby-requested

------------------------------------------------------------------------------------

double eos_lobby_remove_notify_lobby_invite_accepted(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-lobby-invite-accepted

------------------------------------------------------------------------------------

double eos_lobby_remove_notify_lobby_invite_received(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-lobby-invite-received

------------------------------------------------------------------------------------

double eos_lobby_remove_notify_lobby_invite_rejected(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-lobby-invite-rejected

------------------------------------------------------------------------------------

double eos_lobby_remove_notify_lobby_member_status_received(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-lobby-member-status-received

------------------------------------------------------------------------------------

double eos_lobby_remove_notify_lobby_member_update_received(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-lobby-member-update-received

------------------------------------------------------------------------------------

double eos_lobby_remove_notify_lobby_update_received(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-lobby-update-received

------------------------------------------------------------------------------------

double eos_lobby_remove_notify_rtc_room_connection_Stringnged(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-rtc-room-connection-Stringnged

------------------------------------------------------------------------------------

double eos_lobby_remove_notify_send_lobby_native_invite_requested(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-remove-notify-send-lobby-native-invite-requested

------------------------------------------------------------------------------------

double eos_lobby_send_invite(char* lobby_id,char* local_user_id,char* target_user_id)

ASYNC

	string -> type"eos_lobby_send_invite");
	real -> "status"
	string -> "status_message"
	real -> "identifier"

	string -> "lobby_id"

------------------------------------------------------------------------------------

double eos_lobby_update_lobby()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-send-invite

ASYNC

	string -> type"eos_lobby_update_lobby");
	real -> "status"
	string -> "status_message"
	real -> "identifier"

	string -> "lobby_id"
	
------------------------------------------------------------------------------------

double eos_lobby_update_lobby_modification(char* lobby_id,char* local_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-update-lobby-modification

------------------------------------------------------------------------------------

Struct(Attribute) eos_lobby_details_copy_attribute_by_index(double index,char* buff_ret)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-copy-attribute-by-index

------------------------------------------------------------------------------------

Struct(Attribute) eos_lobby_details_copy_attribute_by_key(String attr_key)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-copy-attribute-by-key

------------------------------------------------------------------------------------

Struct{
		available_slots: int,
		allow_host_migration: bool,
		allow_invites: bool,
		allow_join_by_id: bool,
		bool presence_enabled,
		bool rejoin_after_kick_requires_invite,
		bool rtc_room_enabled,
		bucket_id: String,
		lobby_id: String,
		lobby_owner_user_id:String,
		max_members: int,
		permission_level: EOS_ELobbyPermissionLevel
	}eos_lobby_details_copy_info()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-copy-info

------------------------------------------------------------------------------------

double eos_lobby_details_copy_member_attribute_by_index(index,target_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-copy-member-attribute-by-index

------------------------------------------------------------------------------------

double eos_lobby_details_copy_member_attribute_by_key(char* attr_key,char* target_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-copy-member-attribute-by-key

------------------------------------------------------------------------------------

Struct {allows_crossplay: bool, platform: EOS_OnlinePlatformType, user_id: String} eos_lobby_details_copy_member_info(char* target_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-copy-member-info


------------------------------------------------------------------------------------

double eos_lobby_details_get_attribute_count()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-get-attribute-count

------------------------------------------------------------------------------------

String eos_lobby_details_get_lobby_owner()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-get-lobby-owner

------------------------------------------------------------------------------------

double eos_lobby_details_get_member_attribute_count(String target_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-get-member-attribute-count

------------------------------------------------------------------------------------

String eos_lobby_details_get_member_by_index(double index)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-get-member-by-index

------------------------------------------------------------------------------------

double eos_lobby_details_get_member_count()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-get-member-count

------------------------------------------------------------------------------------

double eos_lobby_details_release()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-details-info-release

------------------------------------------------------------------------------------

double eos_lobby_modification_add_attribute(double Visibility
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-add-attribute

------------------------------------------------------------------------------------

double eos_lobby_modification_add_member_attribute(visibility,_args_buffer_address)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-add-member-attribute

------------------------------------------------------------------------------------

double eos_lobby_modification_release()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-release

------------------------------------------------------------------------------------

double eos_lobby_modification_remove_attribute(String key)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-remove-member-attribute

------------------------------------------------------------------------------------

double eos_lobby_modification_remove_member_attribute(String key)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-remove-member-attribute

------------------------------------------------------------------------------------

double eos_lobby_modification_set_allowed_platform_ids(allowed_platform_ids)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-set-allowed-platform-ids

------------------------------------------------------------------------------------

double eos_lobby_modification_set_bucket_id(String bucket_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-set-bucket-id

------------------------------------------------------------------------------------

double eos_lobby_modification_set_invites_allowed(double invites_allowed)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-set-invites-allowed

------------------------------------------------------------------------------------

double eos_lobby_modification_set_max_members(double max_members)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-set-max-members

------------------------------------------------------------------------------------

double eos_lobby_modification_set_permission_level(double PermissionLevel)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-modification-set-permission-level

------------------------------------------------------------------------------------

double eos_lobby_search_copy_search_result_by_index(double index)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-copy-search-result-by-index

------------------------------------------------------------------------------------

double eos_lobby_search_find(String local_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-find

ASYNC

	string -> type"eos_lobby_search_find");
	real -> "status"
	string -> "status_message"
	real -> "identifier"

------------------------------------------------------------------------------------

double eos_lobby_search_get_search_result_count()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-get-search-result-count

------------------------------------------------------------------------------------

double eos_lobby_search_release()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-get-search-result-count

------------------------------------------------------------------------------------

double eos_lobby_search_remove_parameter(char* key, EOS_ComparisonOp comparison_op)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-remove-parameter

------------------------------------------------------------------------------------

double eos_lobby_search_set_lobby_id(String lobby_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-set-lobby-id

------------------------------------------------------------------------------------

double eos_lobby_search_set_max_results(double max_results)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-set-max-results

------------------------------------------------------------------------------------

double eos_lobby_search_set_parameter(EOS_ComparisonOp comparison_op,attribute)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-set-parameter

------------------------------------------------------------------------------------

double eos_lobby_search_set_target_user_id(String target_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-lobby-search-set-target-user-id

------------------------------------------------------------------------------------

NOTES:

------------------------------------------------------------------------------------
mHLobbyDetails

Obtain:
	eos_lobby_copy_lobby_details_handle
	eos_lobby_copy_lobby_details_handle_by_invite_id
	eos_lobby_search_copy_search_result_by_index
	__eos_lobby_copy_lobby_details_handle_by_ui_event_id
Uses:
	eos_lobby_join_lobby
	eos_lobby_details_copy_attribute_by_index
	eos_lobby_details_copy_attribute_by_key
	eos_lobby_details_copy_info
	eos_lobby_details_copy_member_attribute_by_index
	eos_lobby_details_copy_member_attribute_by_key
	eos_lobby_details_copy_member_info
	eos_lobby_details_get_attribute_count
	eos_lobby_details_get_lobby_owner
	eos_lobby_details_get_member_attribute_count
	eos_lobby_details_get_member_by_index
	eos_lobby_details_get_member_count
Release:
	eos_lobby_details_release()


------------------------------------------------------------------------------------


mHLobbyModification

Obtain:
	eos_lobby_update_lobby_modification
	
Uses:
	eos_lobby_update_lobby
	__eos_lobby_modification_add_attribute
	__eos_lobby_modification_add_member_attribute
	eos_lobby_modification_remove_attribute
	eos_lobby_modification_remove_member_attribute
	__eos_lobby_modification_set_allowed_platform_ids
	eos_lobby_modification_set_bucket_id
	eos_lobby_modification_set_invites_allowed
	eos_lobby_modification_set_max_members
	eos_lobby_modification_set_permission_level
	
Release:
	eos_lobby_modification_release()


------------------------------------------------------------------------------------

mHLobbySearch


Obtain:
	eos_lobby_create_lobby_search
	
Uses:
	eos_lobby_search_copy_search_result_by_index
	eos_lobby_search_find
	eos_lobby_search_get_search_result_count
	eos_lobby_search_remove_parameter
	eos_lobby_search_set_lobby_id
	eos_lobby_search_set_max_results
	__eos_lobby_search_set_parameter
	eos_lobby_search_set_target_user_id
	
Release:
	func double eos_lobby_search_release()


