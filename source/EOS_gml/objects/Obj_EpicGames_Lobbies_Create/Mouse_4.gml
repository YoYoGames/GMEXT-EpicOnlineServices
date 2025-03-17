
	///** Anyone can find this lobby as long as it isn't full */
	//EOS_LPL_PUBLICADVERTISED = 0,
	///** Players who have access to presence can see this lobby */
	//EOS_LPL_JOINVIAPRESENCE = 1,
	///** Only players with invites registered can see this lobby */
	//EOS_LPL_INVITEONLY = 2
	
EpicGames_Lobby_CreateLobby(
		userID,//LocalUserId
		[/*100,0,4000*/],//AllowedPlatformIds
		"",//LobbyId
		"GameMode:Region:MapName",//BucketId
		10,//MaxLobbyMembers
		0,//PermissionLevel
		true,//bAllowInvites
		true,//bCrossplayOptOut
		false,//bDisableHostMigration
		true,//bEnableJoinById
		true,//bPresenceEnabled
		true,//bEnableRTCRoom
		0,//Flags
		false,//bUseManualAudioInput
		false,//bUseManualAudioOutput
		false//bLocalAudioDeviceInputStartsMuted
	)
