
var AllowedPlatformIds = [8,7,6]
var PresenceEnabled = true
var bSanctionsEnabled = true
var BucketId = "YYBucketId"
var LocalUserId = userID
var MaxPlayers = 10
var SessionId = "YYSessionId"
var SessionName = "YYSessionName"

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