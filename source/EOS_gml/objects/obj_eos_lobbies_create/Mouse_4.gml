
var _createLobbyOptions = new EpicLobbyCreateLobbyOptions()
_createLobbyOptions.bucket_id = "GameMode:Region:MapName";
_createLobbyOptions.allow_invites = true;
_createLobbyOptions.disable_host_migration = true;
_createLobbyOptions.local_user_id = global.product_user_id;
_createLobbyOptions.max_lobby_members = 10
_createLobbyOptions.permission_level = EpicLobbyPermissionLevel.PublicAdvertised;
_createLobbyOptions.presence_enabled = true;
_createLobbyOptions.rejoin_after_kick_requires_invite = false
_createLobbyOptions.enable_join_by_id = true
_createLobbyOptions.enable_rtc_room = true

eos_lobby_create_lobby(_createLobbyOptions)
//		global.product_user_id,//LocalUserId
//		[/*EOS_OPT_UNKNOWN,EOS_OPT_EPIC,EOS_OPT_STEAM*/],//AllowedPlatformIds
//		"",//lobby_id
//		"GameMode:Region:MapName",//BucketId
//		10,//MaxLobbyMembers
//		EOS_LOBBY_PERMISSION_LEVEL.PUBLIC_ADVERTISED,//PermissionLevel
//		true,//bAllowInvites
//		true,//bCrossplayOptOut
//		false,//bDisableHostMigration
//		true,//bEnableJoinById
//		true,//bPresenceEnabled
//		true,//bEnableRTCRoom
//		0,//Flags  //EOS_RTC_JOINROOMFLAGS_ENABLE_ECHO or EOS_RTC_JOINROOMFLAGS_ENABLE_DATACHANNEL
//		false,//bUseManualAudioInput
//		false,//bUseManualAudioOutput
//		false//bLocalAudioDeviceInputStartsMuted
	//)
