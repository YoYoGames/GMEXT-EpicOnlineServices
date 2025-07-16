
alarm[0] = RefreshPeriod_AccountID

var struct = eos_auth_copy_user_auth_token(AccountID)

eos_auth_login(
		EOS_LOGIN_CREDENTIAL_TYPE.REFRESH_TOKEN, 
        EOS_AUTH_SCOPE_FLAGS.BASIC_PROFILE | EOS_AUTH_SCOPE_FLAGS.FRIENDS_LIST | EOS_AUTH_SCOPE_FLAGS.PRESENCE,
	"",
	struct.refresh_token,
	noone
	)
