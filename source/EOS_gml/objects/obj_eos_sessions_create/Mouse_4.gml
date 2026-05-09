
//#macro EOS_OPT_UNKNOWN 0
//#macro EOS_OPT_EPIC 100
//#macro EOS_OPT_STEAM 4000


var AllowedPlatformIds = [/*100,0,4000*/]
var PresenceEnabled = true
var bSanctionsEnabled = true
var BucketId = "GameMode:Region:MapName"//"YYBucketId"
var LocalUserId = global.product_user_id
var MaxPlayers = 3

///** Minimum number of characters allowed in the session id override */
//#macro EOS_SESSIONMODIFICATION_MIN_SESSIONIDOVERRIDE_LENGTH 16
///** Maximum number of characters allowed in the session id override */
//#macro EOS_SESSIONMODIFICATION_MAX_SESSIONIDOVERRIDE_LENGTH 64
SessionId = ""//eos_create_code(17)

//var _handle = eos_sessions_copy_active_session_handle("SessionName")
//if(_handle != 0)
//{
//	var count = eos_sessions_active_session_get_registered_player_count(_handle)
//	show_debug_message("----------------" + string(count))
//	for(var a = 0 ; a < count ; a++)
//	{
//		var playerid = eos_sessions_active_session_get_registered_player_by_index(_handle, a)
//		show_debug_message(playerid)
//	}
//	eos_sessions_active_session_release(_handle)
//}


show_debug_message("GML: " + global.product_user_id)
var modification_id = eos_sessions_create_session_modification(
		obj_eos_sessions.SessionName,
		SessionId,
		BucketId,
		MaxPlayers,
		LocalUserId,
		PresenceEnabled,
		bSanctionsEnabled,
		AllowedPlatformIds
	)

show_debug_message("CreateSessionModification id=" + string(modification_id))

if(modification_id != 0)
{
	var result = eos_sessions_session_modification_set_permission_level(modification_id, EpicOnlineSessionPermissionLevel.PublicAdvertised)
	show_debug_message("set_permission_level: " + eos_api_result_to_string(result))

	result = eos_sessions_session_modification_set_join_in_progress_allowed(modification_id, true)
	show_debug_message("set_join_in_progress_allowed: " + eos_api_result_to_string(result))

	result = eos_sessions_session_modification_set_invites_allowed(modification_id, true)
	show_debug_message("set_invites_allowed: " + eos_api_result_to_string(result))

	//TODO: new add_attribute only accepts string values; bool/double attributes need a different API
	result = eos_sessions_session_modification_add_attribute(modification_id, "bucket", BucketId, EpicSessionAttributeAdvertisementType.Advertise)
	show_debug_message("add_attribute(bucket): " + eos_api_result_to_string(result))

	result = eos_sessions_session_modification_add_attribute(modification_id, "session_name", "MySessionName :)", EpicSessionAttributeAdvertisementType.Advertise)
	show_debug_message("add_attribute(session_name): " + eos_api_result_to_string(result))

	eos_sessions_update_session(modification_id, function(_info)
	{
		// EpicSessionsUpdateSessionCallbackInfo: .result_code, .session_name, .session_id
		show_debug_message("update_session: " + eos_api_result_to_string(_info.result_code))
		if(_info.result_code != EpicResult.Success) {return}

		// Owner side comes online: spawn the P2P relay and announce ourselves
		// to the active-session player roster.
		instance_create_depth(0, 0, 0, obj_eos_sessions_p2p, {owner: true})

		eos_sessions_register_players(obj_eos_sessions.SessionName, [global.product_user_id], function(_reg)
		{
			// EpicSessionsRegisterPlayersCallbackInfo: .result_code, .registered_players, .sanctioned_players
			show_debug_message($"register_players: {eos_api_result_to_string(_reg.result_code)} registered={_reg.registered_players}")
		})
	})

	eos_sessions_session_modification_release(modification_id)
}
