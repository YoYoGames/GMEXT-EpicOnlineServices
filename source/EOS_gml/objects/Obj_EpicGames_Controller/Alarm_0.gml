
alarm[0] = RefreshPeriod_AccountID

var struct = eos_auth_copy_user_auth_token(AccountID)

eos_auth_login(
		EOS_LOGIN_CREDENTIAL_TYPE.RefreshToken, 
        EOS_AUTH_SCOPE_FLAGS.BasicProfile | EOS_AUTH_SCOPE_FLAGS.FriendsList | EOS_AUTH_SCOPE_FLAGS.Presence,
	"",
	struct.refresh_token,
	noone
	)
