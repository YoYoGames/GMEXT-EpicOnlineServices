
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

//var count = EpicGames_ActiveSession_GetRegisteredPlayerCount("SessionName")
//show_debug_message("----------------" + string(count))
//for(var a = 0 ; a < count ; a++)
//{
//	var playerid = EpicGames_ActiveSession_GetRegisteredPlayerByIndex("SessionName")
//	show_debug_message(playerid)
//}


show_debug_message("GML: " + userID)
var result = EpicGames_Sessions_CreateSessionModification(
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

//var result = EpicGames_Sessions_UpdateSessionModification(SessionName)
//show_debug_message("EpicGames_Sessions_UpdateSessionModification: " + EpicGames_Result_ToString(result))


var result = EpicGames_SessionModification_SetPermissionLevel(EOS_OnlineSessionPermissionLevel.PublicAdvertised)
show_debug_message("EpicGames_SessionModification_SetPermissionLevel: " + EpicGames_Result_ToString(result))

var result = EpicGames_SessionModification_SetJoinInProgressAllowed(true)
show_debug_message("EpicGames_SessionModification_SetJoinInProgressAllowed: " + EpicGames_Result_ToString(result))

var result = EpicGames_SessionModification_SetInvitesAllowed(true)
show_debug_message("EpicGames_SessionModification_SetInvitesAllowed" + EpicGames_Result_ToString(result))

var result = EpicGames_SessionModification_AddAttribute(EOS_SessionAttributeAdvertisementType.Advertise,noone,{Key: EOS_SESSIONS_SEARCH_BUCKET_ID,ValueType: EOS_AttributeType.STRING,Value: BucketId})
show_debug_message("EpicGames_SessionModification_AddAttribute:" + EpicGames_Result_ToString(result))

var result = EpicGames_SessionModification_AddAttribute(EOS_SessionAttributeAdvertisementType.Advertise,noone,{Key: EOS_SESSIONS_SEARCH_EMPTY_SERVERS_ONLY,ValueType: EOS_AttributeType.BOOLEAN,Value: false})
show_debug_message("EpicGames_SessionModification_AddAttribute:" + EpicGames_Result_ToString(result))

var result = EpicGames_SessionModification_AddAttribute(EOS_SessionAttributeAdvertisementType.Advertise,noone,{Key: EOS_SESSIONS_SEARCH_NONEMPTY_SERVERS_ONLY,ValueType: EOS_AttributeType.BOOLEAN,Value: false})
show_debug_message("EpicGames_SessionModification_AddAttribute:" + EpicGames_Result_ToString(result))

var result = EpicGames_SessionModification_AddAttribute(EOS_SessionAttributeAdvertisementType.Advertise,noone,{Key: EOS_SESSIONS_SEARCH_MINSLOTSAVAILABLE,ValueType: EOS_AttributeType.DOUBLE,Value: 2})
show_debug_message("EpicGames_SessionModification_AddAttribute:" + EpicGames_Result_ToString(result))

EpicGames_Sessions_UpdateSession()

//EpicGames_SessionModification_Release()

show_debug_message(result)

