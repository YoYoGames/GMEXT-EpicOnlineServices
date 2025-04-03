

SEASSONS REFERENCE PAGE: https://dev.epicgames.com/docs/api-ref/interfaces/sessions

------------------------------------------------------------------------------------
Struct {
	session_name: String
	state: EOS_EOnlineSessionState,
	session_name: String
	details:{
		host_address:string,
		num_open_public_connections: int,
		owner_server_client_id: string,
		owner_user_id: string,
		session_id: string,
	},
	settings:
	{
		allowed_platform_ids: array,
		allow_join_in_progress: bool,
		invites_allowed: bool.
		sanctions_enabled: bool,
		bucket_id: string,
		num_public_connections: int,
		permission_level: int,
	}
} eos_active_session_copy_info()

	
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-active-session-copy-info

------------------------------------------------------------------------------------

String eos_active_session_get_registered_player_by_index(String session_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-active-session-get-registered-player-by-index

------------------------------------------------------------------------------------

double eos_active_session_get_registered_player_count(String session_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-active-session-get-registered-player-count

------------------------------------------------------------------------------------

Struct 	{host_address: String,
		num_open_public_connections: int,
		owner_user_id: String,
		owner_server_client_id: String,
		session_id: String,
		settings: {
			allowed_platform_ids: _array,
			allow_join_in_progress: bool,
			invites_allowed: bool,
			sanctions_enabled: bool,
			bucket_id: string,
			num_public_connections: int,
			permission_level: int,
		}} eos_session_details_copy_info()
		
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-details-copy-info

------------------------------------------------------------------------------------

struct {advertisement_type: int, key: string, value:any} eos_session_details_copy_session_attribute_by_index(double attr_index)

https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-details-copy-session-attribute-by-index

------------------------------------------------------------------------------------

struct {advertisement_type: int, key: string, value:any} eos_session_details_copy_session_attribute_by_key(String attr_key)

https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-details-copy-session-attribute-by-key

------------------------------------------------------------------------------------

double eos_session_details_get_session_attribute_count()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-details-get-session-attribute-count

------------------------------------------------------------------------------------

double eos_session_details_release()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-details-release

------------------------------------------------------------------------------------

double eos_session_modification_add_attribute(AdvertisementType,Sessionattribute,attribute)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-add-attribute

------------------------------------------------------------------------------------

double eos_session_modification_release()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-release

------------------------------------------------------------------------------------

double eos_session_modification_remove_attribute(String key)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-release

------------------------------------------------------------------------------------

double eos_session_modification_set_allowed_platform_ids(Array array_ids)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-allowed-platform-ids

------------------------------------------------------------------------------------

double eos_session_modification_set_bucket_id(String bucket_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-bucket-id

------------------------------------------------------------------------------------

double eos_session_modification_set_host_address(String host_address)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-host-address

------------------------------------------------------------------------------------

double eos_session_modification_set_invites_allowed(bool invites_allowed)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-invites-allowed

------------------------------------------------------------------------------------

double eos_session_modification_set_join_in_progress_allowed(bool allow_join_in_progress)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-join-in-progress-allowed

------------------------------------------------------------------------------------

double eos_session_modification_set_max_players(double max_players)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-max-players

------------------------------------------------------------------------------------

double eos_session_modification_set_permission_level(double permission_level)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-modification-set-permission-level

------------------------------------------------------------------------------------

int64 eos_sessions_add_notify_join_session_accepted()

ASYNC

	string -> type"eos_sessions_add_notify_join_session_accepted"
	string -> "local_user_id"
	int64 -> "ui_event_id"
	

------------------------------------------------------------------------------------

int64 eos_sessions_add_notify_leave_session_requested()

ASYNC

	string -> type"eos_sessions_add_notify_leave_session_requested"
	// EOS_Result -> "status"
	// string -> "status_message"
	// real -> "identifier"
	string -> "local_user_id"
	string -> "session_name"

------------------------------------------------------------------------------------

int64 eos_sessions_add_notify_send_session_native_invite_requested()

ASYNC
	string -> type"eos_sessions_add_notify_send_session_native_invite_requested"
	// EOS_Result -> "status"
	// string -> "status_message"
	// real -> "identifier"
	string -> "local_user_id"
	string -> "target_native_account_type"
	string -> "target_user_native_account_id"
	string -> "session_id"
	int64 -> "ui_event_id"

------------------------------------------------------------------------------------

int64 eos_sessions_add_notify_session_invite_accepted()

ASYNC
	string -> type"eos_sessions_add_notify_session_invite_accepted"
	// EOS_Result -> "status"
	// string -> "status_message"
	// real -> "identifier"
	string -> "local_user_id"
	string -> "invite_id"
	string -> "session_id"
	string -> "target_user_id"

------------------------------------------------------------------------------------

int64 eos_sessions_add_notify_session_invite_received()

ASYNC
	string -> type"eos_sessions_add_notify_session_invite_received"
	// EOS_Result -> "status"
	// string -> "status_message"
	// real -> "identifier"
	string -> "invite_id"
	string -> "target_user_id"
	string -> "local_user_id"

------------------------------------------------------------------------------------

int64 eos_sessions_add_notify_session_invite_rejected()
ASYNC
	string -> type"eos_sessions_add_notify_session_invite_rejected"
	// EOS_Result -> "status"
	// string -> "status_message"
	// real -> "identifier"
	string -> "invite_id"
	string -> "target_user_id"
	string -> "session_id"
	string -> "local_user_id"
------------------------------------------------------------------------------------

double eos_sessions_copy_session_handle_by_invite_id(String invite_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-copy-session-handle-by-invite-id

------------------------------------------------------------------------------------

double eos_sessions_copy_session_handle_by_ui_event_id(int64 ui_event_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-copy-session-handle-by-ui-event-id

------------------------------------------------------------------------------------

double eos_sessions_copy_session_handle_for_presence(String local)
https://dev.epicgames.com/docs/en-US/api-ref/structs/eos-sessions-copy-session-handle-for-presence-options

------------------------------------------------------------------------------------

double eos_sessions_create_session_modification(		
		Array allowed_platform_ids,
		bool presence_enabled,
		bool sanctions_enabled,
		String bucket_id,
		String local_user_id,
		double max_players,
		String session_id,
		String session_name)
		
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-create-session-modification

------------------------------------------------------------------------------------

EOS_HSessionSearch mOutSessionSearchHandle = 0;
double eos_sessions_create_session_search(double max_search_results)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-create-session-search

------------------------------------------------------------------------------------

double eos_sessions_destroy_session(String session_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-destroy-session
ASYNC

	string -> type"eos_sessions_destroy_session"
	EOS_Result -> "status"
	string -> "status_message"
	real -> "identifier"

------------------------------------------------------------------------------------

double eos_sessions_dump_session_state(String session_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-dump-session-state

------------------------------------------------------------------------------------


double eos_sessions_end_session(String session_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-end-session

ASYNC
	string -> type"eos_sessions_end_session"
	EOS_Result -> "status"
	string -> "status_message"
	real -> "identifier"

------------------------------------------------------------------------------------

double eos_sessions_get_invite_count(String local)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-get-invite-count

------------------------------------------------------------------------------------

String eos_sessions_get_invite_id_by_index(String local_user_id, int index)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-get-invite-id-by-index

------------------------------------------------------------------------------------

double eos_sessions_is_user_in_session(String session_name, string target_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-is-user-in-session

------------------------------------------------------------------------------------

double eos_sessions_join_session(double presence_enabled,char* local_user_id,char* session_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-join-session

ASYNC
	string -> type"eos_sessions_join_session"
	EOS_Result -> "status"
	string -> "status_message"
	real -> "identifier"


------------------------------------------------------------------------------------

double eos_sessions_query_invites(String target_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-query-invites

ASYNC
	string -> type"eos_sessions_query_invites"
	EOS_Result -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "local_user_id"


------------------------------------------------------------------------------------

double eos_sessions_register_players(String session_name, Array array_product_ids)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-register-players

ASYNC
	string -> type"eos_sessions_register_players"
	EOS_Result -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "registered_players"
	string -> "sanctioned_players"


------------------------------------------------------------------------------------


double eos_sessions_reject_invite(char* local_user_id,char* invite_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-reject-invite

ASYNC
	string -> type"eos_sessions_reject_invite"
	EOS_Result -> "status"
	string -> "status_message"
	real -> "identifier"


------------------------------------------------------------------------------------

double eos_sessions_remove_notify_join_session_accepted(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-remove-notify-join-session-accepted

------------------------------------------------------------------------------------

double eos_sessions_remove_notify_leave_session_requested(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-remove-notify-leave-session-requested

------------------------------------------------------------------------------------

double eos_sessions_remove_notify_send_session_native_invite_requested(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-remove-notify-send-session-native-invite-requested

------------------------------------------------------------------------------------

double eos_sessions_remove_notify_session_invite_accepted(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-remove-notify-session-invite-accepted

------------------------------------------------------------------------------------

double eos_sessions_remove_notify_session_invite_received(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-remove-notify-session-invite-received

------------------------------------------------------------------------------------

double eos_sessions_remove_notify_session_invite_rejected(notification_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-remove-notify-session-invite-received

------------------------------------------------------------------------------------

double eos_sessions_send_invite(char* local_user_id,char* session_name,char* target_user_id)

ASYNC
	string -> type"eos_sessions_send_invite"
	EOS_Result -> "status"
	string -> "status_message"
	real -> "identifier"


------------------------------------------------------------------------------------

double eos_sessions_start_session(String session_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-send-invite

ASYNC
	string -> type"eos_sessions_start_session"
	EOS_Result -> "status"
	string -> "status_message"
	real -> "identifier"


------------------------------------------------------------------------------------

double eos_sessions_unregister_players(String session_name, Array array_product_ids)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-unregister-players

ASYNC
	string -> type"eos_sessions_unregister_players"
	EOS_Result -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "unregistered_players"


------------------------------------------------------------------------------------

double eos_sessions_update_session()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-unregister-players
ASYNC
	string -> type"eos_sessions_update_session"
	EOS_Result -> "status"
	string -> "status_message"
	real -> "identifier"
	string -> "session_id"
	string -> "session_name"


------------------------------------------------------------------------------------

double eos_sessions_update_session_modification(String session_name)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-sessions-update-session-modification

------------------------------------------------------------------------------------

double eos_session_search_copy_search_result_by_index(double session_index)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-copy-search-result-by-index

------------------------------------------------------------------------------------

double eos_session_search_find(String local_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-find

ASYNC
	string -> type"eos_session_search_find"
	EOS_Result -> "status"
	string -> "status_message"
	real -> "identifier"


------------------------------------------------------------------------------------

double eos_session_search_get_search_result_count()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-get-search-result-count

------------------------------------------------------------------------------------

double eos_session_search_release()
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-release

------------------------------------------------------------------------------------

double eos_session_search_remove_parameter(String key, EOS_ComparisonOp comparison_op)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-remove-parameter

------------------------------------------------------------------------------------

double eos_session_search_set_max_results(double max_search_results)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-set-max-results

------------------------------------------------------------------------------------

double eos_session_search_set_parameter(EOS_ComparisonOp comparison_op, Struct attribute)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-set-parameter

------------------------------------------------------------------------------------

double eos_session_search_set_session_id(String session_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-set-session-id

------------------------------------------------------------------------------------

double eos_session_search_set_target_user_id(String target_user_id)
https://dev.epicgames.com/docs/en-US/api-ref/functions/eos-session-search-set-target-user-id

------------------------------------------------------------------------------------




Notes:

------------------------------------------------------------------------------------

mOutSessionSearchHandle

Obtain:
	eos_sessions_create_session_search
	
Uses:
	eos_session_search_copy_search_result_by_index
	eos_session_search_find
	eos_session_search_get_search_result_count
	eos_session_search_remove_parameter
	eos_session_search_set_max_results
	__eos_session_search_set_parameter
	eos_session_search_set_session_id
	eos_session_search_set_target_user_id
	
	
Release:
	eos_session_search_release()

------------------------------------------------------------------------------------

mHSessionDetails

Obtain:
	eos_sessions_copy_session_handle_by_invite_id
	__eos_sessions_copy_session_handle_by_ui_event_id
	eos_sessions_copy_session_handle_for_presence
	eos_session_search_copy_search_result_by_index
	
Uses:
	__eos_session_details_copy_info
	__eos_session_details_copy_session_attribute_by_index
	__eos_session_details_copy_session_attribute_by_key
	eos_session_details_get_session_attribute_count
	eos_sessions_join_session
	
Release:
	eos_session_details_release()

------------------------------------------------------------------------------------

mHSessionModification

Obtain:
	__eos_sessions_create_session_modification
	eos_sessions_update_session_modification
	
Uses:
	__eos_session_modification_add_attribute
	eos_session_modification_remove_attribute
	__eos_session_modification_set_allowed_platform_ids
	eos_session_modification_set_bucket_id
	eos_session_modification_set_host_address
	eos_session_modification_set_invites_allowed
	eos_session_modification_set_join_in_progress_allowed
	eos_session_modification_set_max_players
	eos_session_modification_set_permission_level
	eos_sessions_update_session
	
Release:
	eos_session_modification_release()

