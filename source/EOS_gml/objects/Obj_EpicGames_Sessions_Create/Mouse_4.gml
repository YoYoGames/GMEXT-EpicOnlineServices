
//#macro EOS_OPT_Unknown 0
//#macro EOS_OPT_Epic 100
//#macro EOS_OPT_Steam 4000


var AllowedPlatformIds = [/*100,0,4000*/]
var PresenceEnabled = true
var bSanctionsEnabled = true
var BucketId = "GameMode:Region:MapName"//"YYBucketId"
var LocalUserId = userID
var MaxPlayers = 3

///** Minimum number of characters allowed in the session id override */
//#macro EOS_SESSIONMODIFICATION_MIN_SESSIONIDOVERRIDE_LENGTH 16
///** Maximum number of characters allowed in the session id override */
//#macro EOS_SESSIONMODIFICATION_MAX_SESSIONIDOVERRIDE_LENGTH 64
SessionId = eos_create_code(17)

//var count = eos_active_session_get_registered_player_count("SessionName")
//show_debug_message("----------------" + string(count))
//for(var a = 0 ; a < count ; a++)
//{
//	var playerid = eos_active_session_get_registered_player_by_index("SessionName")
//	show_debug_message(playerid)
//}


show_debug_message("GML: " + userID)
var result = eos_sessions_create_session_modification(
		AllowedPlatformIds,
		PresenceEnabled,
		bSanctionsEnabled,
		BucketId,
		LocalUserId,
		MaxPlayers,
		SessionId,
		Obj_EpicGames_Session.SessionName
	)

show_debug_message(result)

//var result = eos_sessions_update_session_modification(SessionName)
//show_debug_message("eos_sessions_update_session_modification: " + eos_result_to_string(result))


var result = eos_session_modification_set_permission_level(EOS_OnlineSessionPermissionLevel.PublicAdvertised)
show_debug_message("eos_session_modification_set_permission_level: " + eos_result_to_string(result))

var result = eos_session_modification_set_join_in_progress_allowed(true)
show_debug_message("eos_session_modification_set_join_in_progress_allowed: " + eos_result_to_string(result))

var result = eos_session_modification_set_invites_allowed(true)
show_debug_message("eos_session_modification_set_invites_allowed" + eos_result_to_string(result))

var result = eos_session_modification_add_attribute(EOS_SessionAttributeAdvertisementType.Advertise,noone,{key: EOS_SESSIONS_SEARCH_BUCKET_ID,value_type: EOS_AttributeType.STRING,value: BucketId})
show_debug_message("eos_session_modification_add_attribute:" + eos_result_to_string(result))

var result = eos_session_modification_add_attribute(EOS_SessionAttributeAdvertisementType.Advertise,noone,{key: EOS_SESSIONS_SEARCH_EMPTY_SERVERS_ONLY,value_type: EOS_AttributeType.BOOLEAN,value: false})
show_debug_message("eos_session_modification_add_attribute:" + eos_result_to_string(result))

var result = eos_session_modification_add_attribute(EOS_SessionAttributeAdvertisementType.Advertise,noone,{key: EOS_SESSIONS_SEARCH_NONEMPTY_SERVERS_ONLY,value_type: EOS_AttributeType.BOOLEAN,value: false})
show_debug_message("eos_session_modification_add_attribute:" + eos_result_to_string(result))

var result = eos_session_modification_add_attribute(EOS_SessionAttributeAdvertisementType.Advertise,noone,{key: EOS_SESSIONS_SEARCH_MINSLOTSAVAILABLE,value_type: EOS_AttributeType.DOUBLE,value: 2})
show_debug_message("eos_session_modification_add_attribute:" + eos_result_to_string(result))

eos_sessions_update_session()

//eos_session_modification_release()

show_debug_message(result)

