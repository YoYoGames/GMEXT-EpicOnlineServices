@title Logging In

# Logging In

Epic Online Services offers several ways to log in and authenticate. When you use the Epic Online Services extension in your GameMaker game you should aim to use the [Preferred Login Types for Epic Account](https://dev.epicgames.com/docs/epic-account-services/auth/auth-interface#preferred-login-types-for-epic-account): 

|Platform |Login Type |Summary |
|---------|-----------|--------|
|Epic Games Launcher|`EOS_LCT_ExchangeCode`|Exchange code received from the launcher and used to automatically login the user.|
|Steam Client|`EOS_LCT_ExternalAuth`|Steam Session Ticket used to automatically login the Steam user to their associated Epic account.|
|Other store platforms and standalone distributions on PC and Mobile Devices|`EOS_LCT_AccountPortal` with `EOS_LCT_PersistentAuth`|Users are prompted to login using their Epic account credentials, after which a long-lived refresh token is stored locally to enable automatic login across consecutive application runs.|

[[Note: See (${constant.eos_login_credential_type}) for the corresponding Login Type constants of the extension.]]

## Using the Epic Games Launcher

When you log into Epic Online Services using the extension, a straightforward way is to [use the Epic Games Launcher](https://dev.epicgames.com/docs/epic-account-services/auth/auth-interface#epic-games-launcher). The launcher opens the game by running the executable, along with a few command-line parameters: 

```
-AUTH_LOGIN=unused -AUTH_PASSWORD=<password> -AUTH_TYPE=exchangecode -epicapp=<appid> -epicenv=Prod -EpicPortal  -epicusername=<username> -epicuserid=<userid> -epiclocale=en-US -epicsandboxid=<sandboxid> -epicdeploymentid=<deploymentid>
```

The `AUTH_PASSWORD` parameter value contains the token that you should pass into ${function.eos_auth_login}. This function should then be called with a credential type of `EOS_LCT_EXCHANGE_CODE`. The `id` parameter can be blank (an empty string `""`), as this login method does not require an ID. The `token` parameter needs to be set to the Exchange Code from the `AUTH_PASSWORD` command line parameter.

```gml
// Retrieve the AUTH_PASSWORD command-line parameter
// (available when launching from the Epic Games Launcher)
var _p_num = parameter_count();
var _p_auth_password = "";

if (_p_num > 0)
{
    for (var i = 0; i < _p_num; i++)
    {
        var _param = parameter_string(i + 1);
      
        if(string_pos("AUTH_PASSWORD", _param))
        {
            _p_auth_password = string_copy(_param, 16, string_length(_param));
        }
    }
}

// Login using the AUTH_PASSWORD as the token parameter
eos_auth_login(
    EOS_LCT_EXCHANGE_CODE,
    EOS_AS_BASIC_PROFILE | EOS_AS_FRIENDS_LIST | EOS_AS_PRESENCE,
    "",
    _p_auth_password,
    -1
);
```

[[Note: The permissions that you pass must correspond exactly to the ones you set in the [Developer Portal](https://dev.epicgames.com/docs/dev-portal). See [Permissions](https://dev.epicgames.com/docs/epic-account-services/getting-started#permissions).]]

## External Login Flow Guide

This is a detailed login flow for external accounts (the required credentials depend on the ${constant.eos_external_credential_type} used with the ${function.eos_auth_login} API).

1. Game calls ${function.eos_auth_login} with the `EOS_LCT_ExternalAuth` credential type.
2. ${function.eos_auth_login} callback returns a status `EOS_INVALID_USER` with a non-undefined EOS_ContinuanceToken in the EOS_Auth_LoginCallbackInfo data.
3. Game calls ${function.eos_auth_link_account} with the `EOS_ContinuanceToken` to initiate the login flow for linking the platform account with the user's Epic account.
4. EOS SDK automatically opens the local default web browser and takes the user to the Epic account portal web page.
  * The user is able to login to their existing Epic account or create a new account if needed.
  * In the meantime, EOS SDK will internally keep polling the backend for a completion status of the login flow.
5. The user is able to login to their existing Epic account or create a new account if needed.
6. In the meantime, EOS SDK will internally keep polling the backend for a completion status of the login flow.
7. Once user completes the login, cancels it or if the login flow times out, ${function.eos_auth_link_account} invokes the completion callback to the caller.
8. If the user was logged in successfully, `EOS_SUCCESS` is returned in the callback event. Otherwise, an error result code is returned accordingly.
