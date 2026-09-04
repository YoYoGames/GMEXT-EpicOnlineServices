@title Logging In

# Logging In

Epic Online Services offers several ways to log in and authenticate. When you use the Epic Online Services extension in your GameMaker game you should aim to use the [Preferred Login Types for Epic Account](https://dev.epicgames.com/docs/epic-account-services/auth/auth-interface#preferred-login-types-for-epic-account):

|Platform |Login Type |Summary |
|---------|-----------|--------|
|Epic Games Launcher|`EpicLoginCredentialType.ExchangeCode`|Exchange code received from the launcher and used to automatically login the user.|
|Steam Client|`EpicLoginCredentialType.ExternalAuth`|Steam Session Ticket used to automatically login the Steam user to their associated Epic account.|
|Other store platforms and standalone distributions on PC and Mobile Devices|`EpicLoginCredentialType.AccountPortal` with `EpicLoginCredentialType.PersistentAuth`|Users are prompted to login using their Epic account credentials, after which a long-lived refresh token is stored locally to enable automatic login across consecutive application runs.|

[[Note: See ${constant.EpicLoginCredentialType} for the Login Type constants of the extension.]]

## Using the Epic Games Launcher

When you log into Epic Online Services using the extension, a straightforward way is to [use the Epic Games Launcher](https://dev.epicgames.com/docs/epic-account-services/auth/auth-interface#epic-games-launcher). The launcher opens the game by running the executable, along with a few command-line parameters:

```
-AUTH_LOGIN=unused -AUTH_PASSWORD=<password> -AUTH_TYPE=exchangecode -epicapp=<appid> -epicenv=Prod -EpicPortal  -epicusername=<username> -epicuserid=<userid> -epiclocale=en-US -epicsandboxid=<sandboxid> -epicdeploymentid=<deploymentid>
```

The `AUTH_PASSWORD` parameter value contains the token that you should pass into ${function.eos_auth_login} as `credentials_token`. This function should then be called with a `credentials_type` of `EpicLoginCredentialType.ExchangeCode`. The `credentials_id` parameter can be left blank (an empty string `""`), as this login method does not require an ID. `external_credential_type` is ignored for this login type, but a value must still be passed - `EpicExternalCredentialType.Epic` is a safe default.

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

// Login using the AUTH_PASSWORD as the credentials_token parameter
eos_auth_login(
    "",
    _p_auth_password,
    EpicLoginCredentialType.ExchangeCode,
    EpicExternalCredentialType.Epic,
    EpicAuthScopeFlags.BasicProfile | EpicAuthScopeFlags.FriendsList | EpicAuthScopeFlags.Presence,
    EpicAuthLoginFlags.NoFlags,
    function(_result)
    {
        if (_result.result_code == EpicResult.Success)
        {
            global.local_user_id = _result.selected_account_id;
        }
    }
);
```

[[Note: The permissions that you pass must correspond exactly to the ones you set in the [Developer Portal](https://dev.epicgames.com/docs/dev-portal). See [Permissions](https://dev.epicgames.com/docs/epic-account-services/getting-started#permissions).]]

## External Login Flow Guide

This is a detailed login flow for external accounts (the required credentials depend on the ${constant.EpicExternalCredentialType} used with the ${function.eos_auth_login} API).

1. Game calls ${function.eos_auth_login} with the `EpicLoginCredentialType.ExternalAuth` credential type.
2. ${function.eos_auth_login}'s callback reports `result_code` as `EpicResult.InvalidUser` with `has_continuance_token` set to `true` and a valid `continuance_token_id`.
3. Game calls ${function.eos_auth_link_account} with `continuance_token_id` to initiate the flow for linking the external account with the user's Epic account.
4. EOS SDK automatically opens the local default web browser and takes the user to the Epic account portal web page.
   * The user is able to login to their existing Epic account or create a new account if needed.
   * In the meantime, EOS SDK will internally keep polling the backend for a completion status of the login flow.
5. Once the user completes the login, cancels it, or the flow times out, ${function.eos_auth_link_account}'s callback fires.
6. If the user was logged in successfully, `EpicResult.Success` is reported and `selected_account_id` holds the resulting Epic Account ID. Otherwise, an error result code is reported instead.

```gml
eos_auth_login(
    steam_session_ticket, "",
    EpicLoginCredentialType.ExternalAuth,
    EpicExternalCredentialType.SteamSessionTicket,
    EpicAuthScopeFlags.BasicProfile | EpicAuthScopeFlags.FriendsList | EpicAuthScopeFlags.Presence,
    EpicAuthLoginFlags.NoFlags,
    function(_result)
    {
        if (_result.result_code == EpicResult.Success)
        {
            global.local_user_id = _result.selected_account_id;
        }
        else if (_result.result_code == EpicResult.InvalidUser && _result.has_continuance_token)
        {
            eos_auth_link_account(_result.continuance_token_id, "", EpicLinkAccountFlags.NoFlags, function(_link_result)
            {
                if (_link_result.result_code == EpicResult.Success)
                {
                    global.local_user_id = _link_result.selected_account_id;
                }
            });
        }
    }
);
```
