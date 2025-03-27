
alarm[0] = RefreshPeriod_AccountID

var struct = eos_auth_copy_user_auth_token(AccountID)

eos_auth_login(
		EOS_LoginCredentialType.RefreshToken, 
        EOS_AuthScopeFlags.BasicProfile | EOS_AuthScopeFlags.FriendsList | EOS_AuthScopeFlags.Presence,
	"",
	struct.refresh_token,
	noone
	)
