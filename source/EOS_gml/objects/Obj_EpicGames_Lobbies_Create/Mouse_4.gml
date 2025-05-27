	
eos_lobby_create_lobby(
		userID,//LocalUserId
		[/*EOS_OPT_UNKNOWN,EOS_OPT_EPIC,EOS_OPT_STEAM*/],//AllowedPlatformIds
		"",//lobby_id
		"GameMode:Region:MapName",//BucketId
		10,//MaxLobbyMembers
		EOS_LOBBY_PERMISSION_LEVEL.PUBLICADVERTISED,//PermissionLevel
		true,//bAllowInvites
		true,//bCrossplayOptOut
		false,//bDisableHostMigration
		true,//bEnableJoinById
		true,//bPresenceEnabled
		true,//bEnableRTCRoom
		0,//Flags  //EOS_RTC_JOINROOMFLAGS_ENABLE_ECHO or EOS_RTC_JOINROOMFLAGS_ENABLE_DATACHANNEL
		false,//bUseManualAudioInput
		false,//bUseManualAudioOutput
		false//bLocalAudioDeviceInputStartsMuted
	)
