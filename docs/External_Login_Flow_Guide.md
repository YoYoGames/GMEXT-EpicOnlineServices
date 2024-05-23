@title External_Login_Flow_Guide

# Login Flow Guide

This is a detailed login flow for external accounts (the required credentials depend on the ${constant.External_Credential_Type} used with the ${function.EpicGames_Auth_Login} API).

1. Game calls ${function.EpicGames_Auth_Login} with the `EOS_LCT_ExternalAuth` credential type.
2. ${function.EpicGames_Auth_Login} callback returns a status `EpicGames_InvalidUser` with a non-undefined EOS_ContinuanceToken in the EOS_Auth_LoginCallbackInfo data.
3. Game calls ${function.EpicGames_Auth_LinkAccount} with the `EOS_ContinuanceToken` to initiate the login flow for linking the platform account with the user's Epic account.
4. EOS SDK automatically opens the local default web browser and takes the user to the Epic account portal web page.
  * The user is able to login to their existing Epic account or create a new account if needed.
  * In the meantime, EOS SDK will internally keep polling the backend for a completion status of the login flow.
5. The user is able to login to their existing Epic account or create a new account if needed.
6. In the meantime, EOS SDK will internally keep polling the backend for a completion status of the login flow.
7. Once user completes the login, cancels it or if the login flow times out, ${function.EpicGames_Auth_LinkAccount} invokes the completion callback to the caller.
8. If the user was logged in successfully, `EpicGames_Success` is returned in the callback event. Otherwise, an error result code is returned accordingly.
