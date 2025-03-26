	
eos_lobby_create_lobby(
		userID,//LocalUserId
		[/*EOS_OPT_Unknown,EOS_OPT_Epic,EOS_OPT_Steam*/],//AllowedPlatformIds
		"",//LobbyId
		"GameMode:Region:MapName",//BucketId
		10,//MaxLobbyMembers
		EOS_LobbyPermissionLevel.PUBLICADVERTISED,//PermissionLevel
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
