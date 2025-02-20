
//#define EOS_OPT_Unknown 0
//#define EOS_OPT_Epic 100
//#define EOS_OPT_Steam 4000


var AllowedPlatformIds = [100,0,4000]
var PresenceEnabled = true
var bSanctionsEnabled = true
var BucketId = "GameMode:Region:MapName"//"YYBucketId"
var LocalUserId = userID
var MaxPlayers = 3

///** Minimum number of characters allowed in the session id override */
//#define EOS_SESSIONMODIFICATION_MIN_SESSIONIDOVERRIDE_LENGTH 16
///** Maximum number of characters allowed in the session id override */
//#define EOS_SESSIONMODIFICATION_MAX_SESSIONIDOVERRIDE_LENGTH 64
var SessionId = "12345678901234567"//""
/*var*/SessionName = "YYSessionName12345"

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
		SessionName
	)

show_debug_message(result)

//var result = EpicGames_Sessions_UpdateSessionModification(SessionName)
//show_debug_message("EpicGames_Sessions_UpdateSessionModification: " + EpicGames_Result_ToString(result))

//EOS_ENUM(EOS_EOnlineSessionPermissionLevel,
//	/** Anyone can find this session as long as it isn't full */
//	EOS_OSPF_PublicAdvertised = 0,
//	/** Players who have access to presence can see this session */
//	EOS_OSPF_JoinViaPresence = 1,
//	/** Only players with invites registered can see this session */
//	EOS_OSPF_InviteOnly = 2
//);
var result = EpicGames_SessionModification_SetPermissionLevel(0)
show_debug_message("EpicGames_SessionModification_SetPermissionLevel: " + EpicGames_Result_ToString(result))

var result = EpicGames_SessionModification_SetJoinInProgressAllowed(true)
show_debug_message("EpicGames_SessionModification_SetJoinInProgressAllowed: " + EpicGames_Result_ToString(result))

var result = EpicGames_SessionModification_SetInvitesAllowed(true)
show_debug_message("EpicGames_SessionModification_SetInvitesAllowed" + EpicGames_Result_ToString(result))

//EOS_ENUM(EOS_ESessionAttributeAdvertisementType,
//	/** Don't advertise via the online service */
//	EOS_SAAT_DontAdvertise = 0,
//	/** Advertise via the online service only */
//	EOS_SAAT_Advertise = 1
//);

//#define EOS_SESSIONS_SEARCH_BUCKET_ID "bucket"
var result = EpicGames_SessionModification_AddAttribute(1,noone,{Key:"bucket",ValueType:3,Value: BucketId})
show_debug_message("EpicGames_SessionModification_AddAttribute:" + EpicGames_Result_ToString(result))

///** Search for empty servers only (value is true/false) */
//#define EOS_SESSIONS_SEARCH_EMPTY_SERVERS_ONLY "emptyonly"
var result = EpicGames_SessionModification_AddAttribute(1,noone,{Key:"emptyonly",ValueType:0,Value: false})
show_debug_message("EpicGames_SessionModification_AddAttribute:" + EpicGames_Result_ToString(result))

///** Search for non empty servers only (value is true/false) */
//#define EOS_SESSIONS_SEARCH_NONEMPTY_SERVERS_ONLY "nonemptyonly"
var result = EpicGames_SessionModification_AddAttribute(1,noone,{Key:"nonemptyonly",ValueType:0,Value: false})
show_debug_message("EpicGames_SessionModification_AddAttribute:" + EpicGames_Result_ToString(result))

///** Search for a match with min free space (value is int) */
//#define EOS_SESSIONS_SEARCH_MINSLOTSAVAILABLE "minslotsavailable"
var result = EpicGames_SessionModification_AddAttribute(1,noone,{Key:"minslotsavailable",ValueType:1,Value: 2})
show_debug_message("EpicGames_SessionModification_AddAttribute:" + EpicGames_Result_ToString(result))

EpicGames_Sessions_UpdateSession()

//EpicGames_SessionModification_Release()

show_debug_message(result)



