// Functions

/**
 * @function eos_auth_login
 * @desc **Epic Online Services Function:** [EOS_Auth_Login](https://dev.epicgames.com/docs/api-ref/functions/eos-auth-login)
 *
 * Logs in / authenticates a local user against Epic Account Services (EAS) using the given credentials. The callback fires once with a ${struct.EpicAuthLoginCallbackInfo}.
 *
 * [[Note: The scope flags you pass must correspond exactly to the ones configured for your product on the [Developer Portal](https://dev.epicgames.com/docs/dev-portal). See [Permissions](https://dev.epicgames.com/docs/epic-account-services/getting-started#permissions).]]
 *
 * [[Note: If the credentials match an external account with no Epic Account linked yet, the callback's `result_code` is `EpicResult.InvalidUser` and `has_continuance_token` is `true` — pass `continuance_token_id` into ${function.eos_auth_link_account} to complete the link. See the External Login Flow Guide on the ${page.logging_in} page.]]
 *
 * @param {String} credentials_id ID for the credentials, meaning depends on `credentials_type` (often empty for exchange-code/portal logins).
 * @param {String} credentials_token Credentials or token for the login, meaning depends on `credentials_type`.
 * @param {Constant.EpicLoginCredentialType} credentials_type The login method to use.
 * @param {Constant.EpicExternalCredentialType} external_credential_type Identity provider to use when `credentials_type` is `EpicLoginCredentialType.ExternalAuth`. Ignored otherwise, but a value must still be passed — see ${module.connect} for the full list.
 * @param {Constant.EpicAuthScopeFlags} scope_flags Bitwise-OR (`|`) of the permissions to request from the user during login.
 * @param {Constant.EpicAuthLoginFlags} login_flags Bitwise-OR (`|`) of login behaviour flags.
 * @param {Function} [callback] Called once with the login result.
 *
 * @event callback
 * @desc Fires once with the outcome of the login attempt.
 * @member {Struct.EpicAuthLoginCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_auth_login(
 *     "", code,
 *     EpicLoginCredentialType.ExchangeCode,
 *     EpicExternalCredentialType.Epic,
 *     EpicAuthScopeFlags.BasicProfile | EpicAuthScopeFlags.FriendsList | EpicAuthScopeFlags.Presence,
 *     EpicAuthLoginFlags.NoFlags,
 *     function(_result)
 *     {
 *         if (_result.result_code == EpicResult.Success)
 *         {
 *             global.local_user_id = _result.selected_account_id;
 *         }
 *         else if (_result.result_code == EpicResult.InvalidUser && _result.has_continuance_token)
 *         {
 *             eos_auth_link_account(_result.continuance_token_id, "", EpicLinkAccountFlags.NoFlags, link_callback);
 *         }
 *     }
 * );
 * ```
 * @function_end
 */

/**
 * @function eos_auth_logout
 * @desc **Epic Online Services Function:** [EOS_Auth_Logout](https://dev.epicgames.com/docs/api-ref/functions/eos-auth-logout)
 *
 * Signs a locally logged-in user out of Epic Account Services.
 *
 * @param {String} local_user_id Epic Account ID of the local user to log out.
 * @param {Function} [callback] Called once logout completes.
 *
 * @event callback
 * @desc Fires once with the outcome of the logout attempt.
 * @member {Struct.EpicAuthLogoutCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_auth_logout(global.local_user_id, function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success) show_debug_message("Logged out");
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_auth_link_account
 * @desc **Epic Online Services Function:** [EOS_Auth_LinkAccount](https://dev.epicgames.com/docs/api-ref/functions/eos-auth-link-account)
 *
 * Continues a pending ${function.eos_auth_login} attempt by linking the external account behind `continuance_token_id` to an Epic Account. On success the user ends up logged in. This commits the external account to the Epic Account and cannot be undone through the SDK.
 *
 * @param {Real} continuance_token_id Continuance token handle obtained from a prior ${function.eos_auth_login} callback (`has_continuance_token` was `true`).
 * @param {String} local_user_id Epic Account ID of an already-logged-in local user to link this external account to. Pass an empty string to let the user pick/create an Epic Account instead.
 * @param {Constant.EpicLinkAccountFlags} link_account_flags Bitwise-OR (`|`) of link behaviour flags.
 * @param {Function} [callback] Called once linking completes.
 *
 * @event callback
 * @desc Fires once with the outcome of the link attempt.
 * @member {Struct.EpicAuthLinkAccountCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_auth_link_account(continuance_token_id, "", EpicLinkAccountFlags.NoFlags, function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success) global.local_user_id = _result.selected_account_id;
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_auth_delete_persistent_auth
 * @desc **Epic Online Services Function:** [EOS_Auth_DeletePersistentAuth](https://dev.epicgames.com/docs/api-ref/functions/eos-auth-delete-persistent-auth)
 *
 * Deletes any locally stored persistent-auth token, so a future launch will no longer be able to silently log the user back in with `EpicLoginCredentialType.PersistentAuth`. Also asks the backend to revoke the token.
 *
 * @param {Function} [callback] Called once the deletion completes.
 *
 * @event callback
 * @desc Fires once with the outcome of the deletion.
 * @member {Struct.EpicAuthDeletePersistentAuthCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_auth_delete_persistent_auth(function(_result)
 * {
 *     show_debug_message("Persistent auth deleted: " + string(_result.result_code == EpicResult.Success));
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_auth_get_logged_in_accounts_count
 * @desc **Epic Online Services Function:** [EOS_Auth_GetLoggedInAccountsCount](https://dev.epicgames.com/docs/api-ref/functions/eos-auth-get-logged-in-accounts-count)
 *
 * Returns how many local Epic Accounts are currently logged in.
 *
 * @returns {Real}
 *
 * @example
 * ```gml
 * var _count = eos_auth_get_logged_in_accounts_count();
 * ```
 * @function_end
 */

/**
 * @function eos_auth_get_logged_in_account_by_index
 * @desc **Epic Online Services Function:** [EOS_Auth_GetLoggedInAccountByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-auth-get-logged-in-account-by-index)
 *
 * Returns the Epic Account ID of the logged-in local user at `index`. Use with ${function.eos_auth_get_logged_in_accounts_count} to enumerate every logged-in local user.
 *
 * @param {Real} index Index into the list of logged-in local users, `0` to `${function.eos_auth_get_logged_in_accounts_count}() - 1`.
 *
 * @returns {String}
 *
 * @example
 * ```gml
 * for (var i = 0; i < eos_auth_get_logged_in_accounts_count(); i++)
 * {
 *     show_debug_message(eos_auth_get_logged_in_account_by_index(i));
 * }
 * ```
 * @function_end
 */

/**
 * @function eos_auth_get_login_status
 * @desc **Epic Online Services Function:** [EOS_Auth_GetLoginStatus](https://dev.epicgames.com/docs/api-ref/functions/eos-auth-get-login-status)
 *
 * Returns the current EAS login status for the given local user.
 *
 * @param {String} local_user_id Epic Account ID of the local user being queried.
 *
 * @returns {Constant.EpicLoginStatus}
 *
 * @example
 * ```gml
 * if (eos_auth_get_login_status(global.local_user_id) == EpicLoginStatus.LoggedIn)
 * {
 *     // ...
 * }
 * ```
 * @function_end
 */

/**
 * @function eos_auth_copy_id_token
 * @desc **Epic Online Services Function:** [EOS_Auth_CopyIdToken](https://dev.epicgames.com/docs/api-ref/functions/eos-auth-copy-id-token)
 *
 * Fetches a locally-cached ID token for an Epic Account ID. ID tokens are the recommended way to securely prove a user's identity to your own backend or other online services — prefer this over ${function.eos_auth_copy_user_auth_token}.
 *
 * @param {String} local_user_id Epic Account ID of the local, logged-in user.
 * @param {String} target_account_id Epic Account ID the token should describe — usually `local_user_id`'s own `selected_account_id`, or another account ID merged with it.
 *
 * @returns {Struct.EpicAuthIdToken} Returns `undefined` if no ID token is cached for `target_account_id` — call ${function.eos_auth_query_id_token} first for any account other than the local user's own selected account ID.
 *
 * @example
 * ```gml
 * var _token = eos_auth_copy_id_token(global.local_user_id, global.local_user_id);
 * if (!is_undefined(_token)) global.jwt = _token.json_web_token;
 * ```
 * @function_end
 */

/**
 * @function eos_auth_copy_user_auth_token
 * @desc **Epic Online Services Function:** [EOS_Auth_CopyUserAuthToken](https://dev.epicgames.com/docs/api-ref/functions/eos-auth-copy-user-auth-token)
 *
 * Fetches the locally-cached user auth token for a logged-in local user. Whoever holds this token can act on the user's behalf, so prefer ${function.eos_auth_copy_id_token} unless you specifically need this token (e.g. to hand it to a launcher/backend, or as the persistent-auth token to store yourself on Console).
 *
 * @param {String} local_user_id Epic Account ID of the local, logged-in user.
 *
 * @returns {Struct.EpicAuthUserAuthToken} Returns `undefined` if `local_user_id` is not currently logged in.
 *
 * @example
 * ```gml
 * var _token = eos_auth_copy_user_auth_token(global.local_user_id);
 * if (!is_undefined(_token)) global.access_token = _token.access_token;
 * ```
 * @function_end
 */

/**
 * @function eos_auth_query_id_token
 * @desc **Epic Online Services Function:** [EOS_Auth_QueryIdToken](https://dev.epicgames.com/docs/api-ref/functions/eos-auth-query-id-token)
 *
 * Queries the backend for an ID token describing `target_account_id`, one of the accounts merged with the local user's Epic Account. Once this completes, fetch the token with ${function.eos_auth_copy_id_token}. Not needed for the local user's own selected account ID — that token is always already cached.
 *
 * @param {String} local_user_id Epic Account ID of the local, logged-in user.
 * @param {String} target_account_id Epic Account ID to query an ID token for.
 * @param {Function} [callback] Called once the query completes.
 *
 * @event callback
 * @desc Fires once with the outcome of the query. Fetch the token itself afterwards with ${function.eos_auth_copy_id_token}.
 * @member {Struct.EpicAuthQueryIdTokenCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_auth_query_id_token(global.local_user_id, target_account_id, function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         var _token = eos_auth_copy_id_token(_result.local_user_id, _result.target_account_id);
 *     }
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_auth_verify_id_token
 * @desc **Epic Online Services Function:** [EOS_Auth_VerifyIdToken](https://dev.epicgames.com/docs/api-ref/functions/eos-auth-verify-id-token)
 *
 * Verifies an ID token (yours or another player's, e.g. received over your own backend/matchmaking) for authenticity and validity.
 *
 * @param {String} json_web_token The ID token to verify, as returned in ${struct.EpicAuthIdToken}'s `json_web_token`.
 * @param {Function} [callback] Called once verification completes.
 *
 * @event callback
 * @desc Fires once with the verification result.
 * @member {Struct.EpicAuthVerifyIdTokenCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_auth_verify_id_token(json_web_token, function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success) show_debug_message(_result.display_name + " verified");
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_auth_verify_user_auth
 * @desc **Epic Online Services Function:** [EOS_Auth_VerifyUserAuth](https://dev.epicgames.com/docs/api-ref/functions/eos-auth-verify-user-auth)
 *
 * Verifies a user auth access token (as returned by ${function.eos_auth_copy_user_auth_token}) for authenticity and validity.
 *
 * @param {String} access_token The access token to verify, as returned in ${struct.EpicAuthUserAuthToken}'s `access_token`.
 * @param {Function} [callback] Called once verification completes.
 *
 * @event callback
 * @desc Fires once with the verification result.
 * @member {Struct.EpicAuthVerifyUserAuthCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_auth_verify_user_auth(access_token, function(_result)
 * {
 *     show_debug_message("Valid: " + string(_result.result_code == EpicResult.Success));
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_auth_add_notify_login_status_changed
 * @desc **Epic Online Services Function:** [EOS_Auth_AddNotifyLoginStatusChanged](https://dev.epicgames.com/docs/api-ref/functions/eos-auth-add-notify-login-status-changed)
 *
 * Registers to be notified whenever any local user's EAS login status changes. Call ${function.eos_auth_remove_notify_login_status_changed} with the returned handle once you no longer need the notification.
 *
 * @param {Function} [callback] Called every time a login status change is reported.
 *
 * @returns {Real} A notification handle, or `0` if registration failed.
 *
 * @event callback
 * @desc Fires every time a local user's login status changes, until removed.
 * @member {Struct.EpicAuthLoginStatusChangedCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * global.auth_status_notify = eos_auth_add_notify_login_status_changed(function(_result)
 * {
 *     show_debug_message(_result.local_user_id + " status: " + string(_result.current_status));
 * });
 * ```
 * @function_end
 */

/**
 * @function eos_auth_remove_notify_login_status_changed
 * @desc **Epic Online Services Function:** [EOS_Auth_RemoveNotifyLoginStatusChanged](https://dev.epicgames.com/docs/api-ref/functions/eos-auth-remove-notify-login-status-changed)
 *
 * Unregisters a notification handle previously returned by ${function.eos_auth_add_notify_login_status_changed}.
 *
 * @param {Real} notification_id Handle returned by ${function.eos_auth_add_notify_login_status_changed}.
 *
 * @example
 * ```gml
 * eos_auth_remove_notify_login_status_changed(global.auth_status_notify);
 * ```
 * @function_end
 */

// Constants

/**
 * @const EpicLoginCredentialType
 * @desc **Epic Online Services Enum:** [EOS_ELoginCredentialType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-login-credential-type)
 *
 * The login method to use with ${function.eos_auth_login}. Availability depends on platform and the permissions granted to your client.
 *
 * @member Password Direct username/password login. Restricted to internal Epic testing.
 * @member ExchangeCode A short-lived, one-time exchange code (e.g. handed to your game by the Epic Games Launcher). Must be consumed promptly, before it expires.
 * @member PersistentAuth Desktop/Mobile only — logs in using a long-lived access token previously stored on the device by a prior login. Returns `EpicResult.InvalidAuth` if no valid stored token exists.
 * @member DeviceCode Deprecated, no longer used.
 * @member Developer Login using named credentials hosted by the EOS SDK Developer Authentication Tool (local development only).
 * @member RefreshToken A refresh token obtained from a previous ${Function.eos_auth_login} in another local process — used by launcher-to-game-client handoff flows.
 * @member AccountPortal Desktop/Mobile only — opens the Epic Account Portal for the user to log in interactively.
 * @member ExternalAuth Login using an external platform's credentials (Steam, PlayStation Network, Xbox Live, Nintendo, etc. — see `external_credential_type`). The primary login method on Console.
 * @const_end
 */

/**
 * @const EpicAuthTokenType
 * @desc **Epic Online Services Enum:** [EOS_EAuthTokenType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-auth-token-type)
 *
 * Whether an ${struct.EpicAuthUserAuthToken} was issued to a client or a user.
 *
 * @member Client Token issued to the client itself.
 * @member User Token issued to a logged-in user.
 * @const_end
 */

/**
 * @const EpicAuthScopeFlags
 * @desc **Epic Online Services Enum:** [EOS_EAuthScopeFlags](https://dev.epicgames.com/docs/api-ref/enums/eos-e-auth-scope-flags)
 *
 * Permissions to request from the user during ${function.eos_auth_login}. Combine with bitwise-OR (`|`). Must match the scopes configured for your product on the [Developer Portal](https://dev.epicgames.com/docs/dev-portal).
 *
 * @member NoFlags No permissions requested.
 * @member BasicProfile See the user's account ID, display name, language, and country.
 * @member FriendsList See the list of the user's friends who also use this application.
 * @member Presence Set the user's online presence and see the presence of their friends.
 * @member FriendsManagement Manage the user's Epic friends list. Restricted to Epic first-party products; requesting it elsewhere fails authentication.
 * @member Email See the user's email address. Restricted to Epic first-party products; requesting it elsewhere fails authentication.
 * @member Country See the user's country.
 * @const_end
 */

/**
 * @const EpicAuthLoginFlags
 * @desc **Epic Online Services Enum:** [EOS_ELoginFlags](https://dev.epicgames.com/docs/api-ref/enums/eos-e-login-flags)
 *
 * Login behaviour flags for ${function.eos_auth_login}. Combine with bitwise-OR (`|`).
 *
 * @member NoFlags Default login behaviour.
 * @member NoUserInterface Suppress any UI the login flow would otherwise show, failing instead if UI would be required.
 * @const_end
 */

/**
 * @const EpicLinkAccountFlags
 * @desc **Epic Online Services Enum:** [EOS_ELinkAccountFlags](https://dev.epicgames.com/docs/api-ref/enums/eos-e-link-account-flags)
 *
 * Link behaviour flags for ${function.eos_auth_link_account}. Combine with bitwise-OR (`|`).
 *
 * @member NoFlags Default link behaviour.
 * @member NintendoNsaId The continuance token identifies a Nintendo Service Account ID being linked.
 * @const_end
 */

/**
 * @const EpicLoginStatus
 * @desc **Epic Online Services Enum:** [EOS_ELoginStatus](https://dev.epicgames.com/docs/api-ref/enums/eos-e-login-status)
 *
 * The EAS login status of a local user, returned by ${function.eos_auth_get_login_status} and reported by ${function.eos_auth_add_notify_login_status_changed}.
 *
 * @member NotLoggedIn Not logged in, no local profile selected.
 * @member UsingLocalProfile Using a local profile, but not logged in to EAS.
 * @member LoggedIn Fully authenticated with EAS.
 * @const_end
 */

// Structs

/**
 * @struct EpicAuthPinGrantInfo
 * @desc Out-of-band ("pin grant") login details, present on ${struct.EpicAuthLoginCallbackInfo}/${struct.EpicAuthLinkAccountCallbackInfo} while a Console-style device-code login is in progress. Fields are empty when no pin-grant flow is active.
 *
 * @member {String} user_code Code the user should enter at `verification_uri`.
 * @member {String} verification_uri URL the user should browse to and enter `user_code`.
 * @member {String} verification_uri_complete URL that both identifies the device and submits the code, letting compatible platforms skip manual entry.
 * @member {Real} expires_in Seconds until `user_code` expires.
 * @struct_end
 */

/**
 * @struct EpicAuthLoginCallbackInfo
 * @desc Result of ${function.eos_auth_login}.
 *
 * @member {Constant.EpicResult} result_code Result of the login attempt. `EpicResult.InvalidUser` with `has_continuance_token` set means the external credentials aren't linked to an Epic Account yet — see `continuance_token_id`.
 * @member {String} local_user_id Epic Account ID that logged in. Empty on failure.
 * @member {String} selected_account_id Account ID selected for this application — use this to key game-scoped data. Only meaningful when `result_code` is `EpicResult.Success`.
 * @member {Bool} has_continuance_token `true` if `continuance_token_id` can be used to complete an account link via ${function.eos_auth_link_account}.
 * @member {Real} continuance_token_id Continuance token handle, valid only when `has_continuance_token` is `true`.
 * @member {Struct.EpicAuthPinGrantInfo} pin_grant_info Out-of-band login details; fields are empty unless a pin-grant flow is in progress.
 * @struct_end
 */

/**
 * @struct EpicAuthLogoutCallbackInfo
 * @desc Result of ${function.eos_auth_logout}.
 *
 * @member {Constant.EpicResult} result_code Result of the logout attempt.
 * @member {String} local_user_id Epic Account ID that was logged out.
 * @struct_end
 */

/**
 * @struct EpicAuthLinkAccountCallbackInfo
 * @desc Result of ${function.eos_auth_link_account}.
 *
 * @member {Constant.EpicResult} result_code Result of the link attempt.
 * @member {String} local_user_id Epic Account ID now logged in.
 * @member {String} selected_account_id Account ID selected for this application.
 * @member {Struct.EpicAuthPinGrantInfo} pin_grant_info Out-of-band login details; fields are empty unless a further pin-grant step is required.
 * @struct_end
 */

/**
 * @struct EpicAuthDeletePersistentAuthCallbackInfo
 * @desc Result of ${function.eos_auth_delete_persistent_auth}.
 *
 * @member {Constant.EpicResult} result_code Result of the deletion.
 * @struct_end
 */

/**
 * @struct EpicAuthIdToken
 * @desc An ID token for an Epic Account, returned by ${function.eos_auth_copy_id_token}.
 *
 * @member {String} account_id Epic Account ID the token describes.
 * @member {String} json_web_token The ID token as a JSON Web Token (JWT) string.
 * @struct_end
 */

/**
 * @struct EpicAuthUserAuthToken
 * @desc A user auth token for an Epic Account, returned by ${function.eos_auth_copy_user_auth_token}.
 *
 * @member {String} app Name of the app the requesting client ID belongs to.
 * @member {String} client_id Client ID that requested this token.
 * @member {String} account_id Epic Account ID the token belongs to.
 * @member {String} access_token The access token string. Whoever holds this can act on the user's behalf — treat it like a secret.
 * @member {Real} expires_in Seconds until `access_token` expires, relative to the call that returned this struct.
 * @member {String} expires_at Absolute UTC expiry time for `access_token`, in ISO 8601 format.
 * @member {Constant.EpicAuthTokenType} auth_type Whether this token was issued to the client or the user.
 * @member {String} refresh_token Refresh token; empty if none was issued.
 * @member {Real} refresh_expires_in Seconds until `refresh_token` expires.
 * @member {String} refresh_expires_at Absolute UTC expiry time for `refresh_token`, in ISO 8601 format.
 * @struct_end
 */

/**
 * @struct EpicAuthQueryIdTokenCallbackInfo
 * @desc Result of ${function.eos_auth_query_id_token}.
 *
 * @member {Constant.EpicResult} result_code Result of the query.
 * @member {String} local_user_id Epic Account ID of the local user that made the request.
 * @member {String} target_account_id Epic Account ID the token was queried for.
 * @struct_end
 */

/**
 * @struct EpicAuthVerifyIdTokenCallbackInfo
 * @desc Result of ${function.eos_auth_verify_id_token}.
 *
 * @member {Constant.EpicResult} result_code Result of the verification.
 * @member {String} application_id ID of the application the token was issued for.
 * @member {String} client_id Client ID the token was issued to.
 * @member {String} product_id Product ID the token was issued for.
 * @member {String} sandbox_id Sandbox ID the token was issued in.
 * @member {String} deployment_id Deployment ID the token was issued in.
 * @member {String} display_name Display name of the token's owner.
 * @member {Bool} is_external_account_info_present `true` if `external_account_id_type`/`external_account_id`/`external_account_display_name`/`platform` below are populated.
 * @member {Constant.EpicExternalAccountType} external_account_id_type Only valid when `is_external_account_info_present` is `true`.
 * @member {String} external_account_id Only valid when `is_external_account_info_present` is `true`.
 * @member {String} external_account_display_name Only valid when `is_external_account_info_present` is `true`.
 * @member {String} platform Only valid when `is_external_account_info_present` is `true`.
 * @struct_end
 */

/**
 * @struct EpicAuthVerifyUserAuthCallbackInfo
 * @desc Result of ${function.eos_auth_verify_user_auth}.
 *
 * @member {Constant.EpicResult} result_code Result of the verification.
 * @struct_end
 */

/**
 * @struct EpicAuthLoginStatusChangedCallbackInfo
 * @desc Reported by ${function.eos_auth_add_notify_login_status_changed} every time a local user's login status changes.
 *
 * @member {String} local_user_id Epic Account ID whose status changed.
 * @member {Constant.EpicLoginStatus} previous_status Status before the change.
 * @member {Constant.EpicLoginStatus} current_status Status after the change.
 * @struct_end
 */

/**
 * @module auth
 * @title Auth
 * @desc **Epic Online Services Interface:** [Auth Interface](https://dev.epicgames.com/docs/epic-account-services/auth-interface)
 *
 * The Auth Interface lets players log into their Epic Account (EAS) from your game, unlocking Friends, Presence, UserInfo, and Ecom. Most games also call ${function.eos_connect_login} (see ${module.connect}) right after a successful Auth login to obtain a Product User ID usable with the rest of this extension's gameplay-facing services (Lobby, Sessions, Stats, ...).
 *
 * @section Guides
 * @desc The following guides are available:
 * @ref page.logging_in
 * @section_end
 *
 * @section_func
 * @desc These functions are provided for handling Epic Account authentication:
 * @ref eos_auth_login
 * @ref eos_auth_logout
 * @ref eos_auth_link_account
 * @ref eos_auth_delete_persistent_auth
 * @ref eos_auth_get_logged_in_accounts_count
 * @ref eos_auth_get_logged_in_account_by_index
 * @ref eos_auth_get_login_status
 * @ref eos_auth_copy_id_token
 * @ref eos_auth_copy_user_auth_token
 * @ref eos_auth_query_id_token
 * @ref eos_auth_verify_id_token
 * @ref eos_auth_verify_user_auth
 * @ref eos_auth_add_notify_login_status_changed
 * @ref eos_auth_remove_notify_login_status_changed
 * @section_end
 *
 * @section_const
 * @desc These are the constants used by this module:
 * @ref EpicLoginCredentialType
 * @ref EpicAuthTokenType
 * @ref EpicAuthScopeFlags
 * @ref EpicAuthLoginFlags
 * @ref EpicLinkAccountFlags
 * @ref EpicLoginStatus
 * @section_end
 *
 * @section_struct
 * @desc These are the structs used by this module:
 * @ref EpicAuthPinGrantInfo
 * @ref EpicAuthLoginCallbackInfo
 * @ref EpicAuthLogoutCallbackInfo
 * @ref EpicAuthLinkAccountCallbackInfo
 * @ref EpicAuthDeletePersistentAuthCallbackInfo
 * @ref EpicAuthIdToken
 * @ref EpicAuthUserAuthToken
 * @ref EpicAuthQueryIdTokenCallbackInfo
 * @ref EpicAuthVerifyIdTokenCallbackInfo
 * @ref EpicAuthVerifyUserAuthCallbackInfo
 * @ref EpicAuthLoginStatusChangedCallbackInfo
 * @section_end
 *
 * @module_end
 */
