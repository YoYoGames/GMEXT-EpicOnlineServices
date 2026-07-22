// Functions

/**
 * @function eos_connect_login
 * @desc **Epic Online Services Function:** [EOS_Connect_Login](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-login)
 *
 * Logs a local user into the Connect interface using an external account credential (Steam, PSN, a
 * device ID, ...) rather than an Epic account. This is the entry point for cross-platform players who
 * don't sign in with an Epic account directly. On success the callback's `local_user_id` is the Product
 * User ID you pass to every other module in this extension.
 *
 * If the external account isn't yet linked to any Epic Product User ID, the callback fires with
 * `result_code` set to `EpicResult.InvalidUser` and `has_continuance_token` set to `true`. Pass
 * `continuance_token_id` to either ${function.eos_connect_create_user} (create a brand-new
 * headless/device account) or ${function.eos_connect_link_account} (link to an existing Epic account) to
 * complete the flow.
 *
 * [[Note: The continuance token is single-use — it's consumed the moment ${function.eos_connect_create_user}/${function.eos_connect_link_account} completes (whether that call succeeds or fails). Call ${function.eos_connect_login} again to get a fresh one.]]
 *
 * @param {String} token The external credential token (e.g. a Steam session ticket, or an arbitrary device identifier for `DeviceIdAccessToken`).
 * @param {Enum.EpicExternalCredentialType} external_credential_type The type of the external credential in `token`. See ${constant.EpicExternalCredentialType}.
 * @param {String} display_name The display name to associate with the user. Only used the first time a Product User ID is created for this external account; ignored on subsequent logins. Pass `""` if you don't need to set one.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Called once with the login result.
 * @member {Struct.EpicConnectLoginCallbackInfo} result
 * @event_end
 *
 * @example
 * ```gml
 * eos_connect_login(_steam_session_ticket, EpicExternalCredentialType.SteamSessionTicket, "", function(_result)
 * {
 *     if (_result.result_code == EpicResult.Success)
 *     {
 *         global.product_user_id = _result.local_user_id;
 *     }
 *     else if (_result.result_code == EpicResult.InvalidUser && _result.has_continuance_token)
 *     {
 *         eos_connect_create_user(_result.continuance_token_id, callback_create_user);
 *     }
 * });
 * ```
 * The above code logs a user in with a Steam session ticket, and creates a brand-new account for them if none exists yet.
 * @function_end
 */

/**
 * @function eos_connect_create_user
 * @desc **Epic Online Services Function:** [EOS_Connect_CreateUser](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-create-user)
 *
 * Creates a brand-new Product User ID for the external account represented by a continuance token from a
 * failed ${function.eos_connect_login} call.
 *
 * @param {Real} continuance_token_id The `continuance_token_id` from an ${function.eos_connect_login} callback whose `result_code` was `EpicResult.InvalidUser`.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Called once with the creation result.
 * @member {Struct.EpicConnectCreateUserCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_connect_link_account
 * @desc **Epic Online Services Function:** [EOS_Connect_LinkAccount](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-link-account)
 *
 * Links the external account represented by a continuance token from a failed ${function.eos_connect_login}
 * call to an existing, already-logged-in local user (obtained via a *different* external credential, or via
 * ${function.eos_auth_login}).
 *
 * @param {Real} continuance_token_id The `continuance_token_id` from an ${function.eos_connect_login} callback whose `result_code` was `EpicResult.InvalidUser`.
 * @param {String} local_user_id The Product User ID to link the external account to.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Called once with the link result.
 * @member {Struct.EpicConnectLinkAccountCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_connect_unlink_account
 * @desc **Epic Online Services Function:** [EOS_Connect_UnlinkAccount](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-unlink-account)
 *
 * Unlinks a previously-linked Epic account from the local device/headless Product User ID (the reverse of
 * a Device ID login that was later linked to a full Epic account).
 *
 * @param {String} local_user_id The Product User ID to unlink.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Called once with the unlink result.
 * @member {Struct.EpicConnectUnlinkAccountCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_connect_create_device_id
 * @desc **Epic Online Services Function:** [EOS_Connect_CreateDeviceId](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-create-device-id)
 *
 * Creates a new local Device ID for this device, letting a player start playing without linking any
 * external account. Combine with ${constant.EpicExternalCredentialType}'s `DeviceIdAccessToken` and
 * ${function.eos_connect_login} to log in with it afterwards.
 *
 * @param {String} device_model A short human-readable identifier for the local device (e.g. `"Windows"`, `"iPhone14,2"`). Not validated by the SDK; used for your own diagnostics.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Called once with the creation result.
 * @member {Struct.EpicConnectCreateDeviceIdCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_connect_delete_device_id
 * @desc **Epic Online Services Function:** [EOS_Connect_DeleteDeviceId](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-delete-device-id)
 *
 * Deletes the Device ID previously created on this device with ${function.eos_connect_create_device_id}.
 * Any Product User ID that was only reachable through this Device ID becomes permanently unreachable once
 * deleted (unless it was also linked to another external account).
 *
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Called once with the deletion result.
 * @member {Struct.EpicConnectDeleteDeviceIdCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_connect_transfer_device_id_account
 * @desc **Epic Online Services Function:** [EOS_Connect_TransferDeviceIdAccount](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-transfer-device-id-account)
 *
 * Transfers the Device-ID-based Product User ID of the local device to another, already-logged-in local
 * user on the same device. Useful for local multiplayer / shared-device scenarios where a Device ID
 * account was created before a second local player signed in properly.
 *
 * @param {String} primary_local_user_id The Product User ID to transfer the Device ID association to.
 * @param {String} local_device_user_id The Device-ID-based Product User ID currently associated with this device.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Called once with the transfer result.
 * @member {Struct.EpicConnectTransferDeviceIdAccountCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_connect_logout
 * @desc **Epic Online Services Function:** [EOS_Connect_Logout](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-logout)
 *
 * Logs out a local user previously logged in via ${function.eos_connect_login}.
 *
 * @param {String} local_user_id The Product User ID to log out.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Called once with the logout result.
 * @member {Struct.EpicConnectLogoutCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_connect_get_logged_in_users_count
 * @desc **Epic Online Services Function:** [EOS_Connect_GetLoggedInUsersCount](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-get-logged-in-users-count)
 *
 * Returns the number of locally logged-in users tracked by the Connect interface.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_connect_get_logged_in_user_by_index
 * @desc **Epic Online Services Function:** [EOS_Connect_GetLoggedInUserByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-get-logged-in-user-by-index)
 *
 * Returns the Product User ID of the locally logged-in user at the given index.
 *
 * @param {Real} index Index between 0 and ${function.eos_connect_get_logged_in_users_count} - 1.
 *
 * @returns {String} The Product User ID, or an empty string if `index` is out of range.
 *
 * @function_end
 */

/**
 * @function eos_connect_get_login_status
 * @desc **Epic Online Services Function:** [EOS_Connect_GetLoginStatus](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-get-login-status)
 *
 * Returns the Connect login status of the given Product User ID.
 *
 * @param {String} local_user_id The Product User ID to query.
 *
 * @returns {Enum.EpicLoginStatus} See ${constant.EpicLoginStatus}.
 *
 * @function_end
 */

/**
 * @function eos_connect_copy_id_token
 * @desc **Epic Online Services Function:** [EOS_Connect_CopyIdToken](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-copy-id-token)
 *
 * Fetches the locally-cached Connect ID token for a logged-in Product User ID. This token is what you
 * pass to your own game backend to have it verify the player's identity server-side (via a matching call
 * to ${function.eos_connect_verify_id_token}, or Epic's server-side SDK).
 *
 * @param {String} local_user_id The Product User ID to get the ID token of.
 *
 * @returns {Struct.EpicConnectIdToken} `undefined` if `local_user_id` isn't logged in or the token isn't available.
 *
 * @function_end
 */

/**
 * @function eos_connect_copy_product_user_info
 * @desc **Epic Online Services Function:** [EOS_Connect_CopyProductUserInfo](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-copy-product-user-info)
 *
 * Fetches the locally-cached primary external account info for a Product User ID.
 *
 * [[Note: This only returns data that has already been cached locally by a prior login or query. It does not make a network request.]]
 *
 * @param {String} target_user_id The Product User ID to get the external account info of.
 *
 * @returns {Struct.EpicConnectExternalAccountInfo} `undefined` if no cached info is available for `target_user_id`.
 *
 * @function_end
 */

/**
 * @function eos_connect_get_product_user_external_account_count
 * @desc **Epic Online Services Function:** [EOS_Connect_GetProductUserExternalAccountCount](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-get-product-user-external-account-count)
 *
 * Returns the number of locally-cached external accounts linked to a Product User ID.
 *
 * @param {String} target_user_id The Product User ID to query.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_connect_copy_product_user_external_account_by_index
 * @desc **Epic Online Services Function:** [EOS_Connect_CopyProductUserExternalAccountByIndex](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-copy-product-user-external-account-by-index)
 *
 * Fetches a locally-cached linked external account by index.
 *
 * @param {String} target_user_id The Product User ID to query.
 * @param {Real} index Index between 0 and ${function.eos_connect_get_product_user_external_account_count} - 1.
 *
 * @returns {Struct.EpicConnectExternalAccountInfo} `undefined` if `index` is out of range.
 *
 * @function_end
 */

/**
 * @function eos_connect_copy_product_user_external_account_by_account_type
 * @desc **Epic Online Services Function:** [EOS_Connect_CopyProductUserExternalAccountByAccountType](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-copy-product-user-external-account-by-account-type)
 *
 * Fetches a locally-cached linked external account of a specific type.
 *
 * @param {String} target_user_id The Product User ID to query.
 * @param {Enum.EpicExternalAccountType} account_id_type The external account type to look for. See ${constant.EpicExternalAccountType}.
 *
 * @returns {Struct.EpicConnectExternalAccountInfo} `undefined` if no linked account of that type is cached.
 *
 * @function_end
 */

/**
 * @function eos_connect_copy_product_user_external_account_by_account_id
 * @desc **Epic Online Services Function:** [EOS_Connect_CopyProductUserExternalAccountByAccountId](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-copy-product-user-external-account-by-account-id)
 *
 * Fetches a locally-cached linked external account by its raw account ID string.
 *
 * @param {String} target_user_id The Product User ID to query.
 * @param {String} account_id The raw external account ID to look for.
 *
 * @returns {Struct.EpicConnectExternalAccountInfo} `undefined` if no matching linked account is cached.
 *
 * @function_end
 */

/**
 * @function eos_connect_get_product_user_id_mapping
 * @desc **Epic Online Services Function:** [EOS_Connect_GetProductUserIdMapping](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-get-product-user-id-mapping)
 *
 * Reads the locally-cached external account ID that a target Product User ID maps to, for a given
 * external account type. The mapping must already be cached by an earlier
 * ${function.eos_connect_query_external_account_mappings} call.
 *
 * @param {String} local_user_id The Product User ID performing the lookup.
 * @param {Enum.EpicExternalAccountType} account_id_type The external account type to resolve to. See ${constant.EpicExternalAccountType}.
 * @param {String} target_product_user_id The Product User ID to resolve.
 *
 * @returns {String} The external account ID, or an empty string if there's no cached mapping.
 *
 * @function_end
 */

/**
 * @function eos_connect_get_external_account_mapping
 * @desc **Epic Online Services Function:** [EOS_Connect_GetExternalAccountMapping](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-get-external-account-mapping)
 *
 * Reads the locally-cached Product User ID that a target external account ID maps to. The mapping must
 * already be cached by an earlier ${function.eos_connect_query_product_user_id_mappings} call.
 *
 * @param {String} local_user_id The Product User ID performing the lookup.
 * @param {Enum.EpicExternalAccountType} account_id_type The external account type of `target_external_user_id`. See ${constant.EpicExternalAccountType}.
 * @param {String} target_external_user_id The external account ID to resolve.
 *
 * @returns {String} The Product User ID, or an empty string if there's no cached mapping or the external account isn't linked to any Product User ID.
 *
 * @function_end
 */

/**
 * @function eos_connect_verify_id_token
 * @desc **Epic Online Services Function:** [EOS_Connect_VerifyIdToken](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-verify-id-token)
 *
 * Verifies a Connect ID token (from ${function.eos_connect_copy_id_token}). Intended for a dedicated
 * game server verifying a connecting client's identity.
 *
 * [[Note: `account_id_type`/`account_id`/`platform`/`device_type` on the result are only meaningful when `is_account_info_present` is `true` — this is `false` for tokens belonging to a Device-ID-only (headless) account.]]
 *
 * @param {String} json_web_token The ID token JSON Web Token string to verify.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Called once with the verification result.
 * @member {Struct.EpicConnectVerifyIdTokenCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_connect_query_external_account_mappings
 * @desc **Epic Online Services Function:** [EOS_Connect_QueryExternalAccountMappings](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-query-external-account-mappings)
 *
 * Queries the backend to resolve a batch of external account IDs (of a single account type) to their
 * Product User IDs, caching the results locally for later lookup via
 * ${function.eos_connect_get_product_user_id_mapping}.
 *
 * @param {String} local_user_id The Product User ID performing the query.
 * @param {Enum.EpicExternalAccountType} account_id_type The external account type all IDs in `target_external_user_ids` belong to. See ${constant.EpicExternalAccountType}.
 * @param {Array[String]} target_external_user_ids The external account IDs to resolve.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Called once with the query result.
 * @member {Struct.EpicConnectQueryExternalAccountMappingsCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_connect_query_product_user_id_mappings
 * @desc **Epic Online Services Function:** [EOS_Connect_QueryProductUserIdMappings](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-query-product-user-id-mappings)
 *
 * Queries the backend to resolve a batch of Product User IDs to their external account IDs (across every
 * linked external account type), caching the results locally for later lookup via
 * ${function.eos_connect_get_external_account_mapping}.
 *
 * @param {String} local_user_id The Product User ID performing the query.
 * @param {Array[String]} target_product_user_ids The Product User IDs to resolve.
 * @param {Function} [callback] Called once with the result.
 *
 * @event callback
 * @desc Called once with the query result.
 * @member {Struct.EpicConnectQueryProductUserIdMappingsCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_connect_add_notify_auth_expiration
 * @desc **Epic Online Services Function:** [EOS_Connect_AddNotifyAuthExpiration](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-add-notify-auth-expiration)
 *
 * Registers to be notified when a local user's Connect authentication is about to expire, so you can
 * refresh their external credential and call ${function.eos_connect_login} again before they're logged
 * out. Call ${function.eos_connect_remove_notify_auth_expiration} with the returned ID when you no longer
 * need the notification.
 *
 * @param {Function} [callback] Called every time a local user's Connect authentication is about to expire.
 *
 * @returns {Real} A notification ID, or `0` if registration failed.
 *
 * @event callback
 * @desc Fires once per local user shortly before their Connect authentication expires.
 * @member {Struct.EpicConnectAuthExpirationCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_connect_remove_notify_auth_expiration
 * @desc **Epic Online Services Function:** [EOS_Connect_RemoveNotifyAuthExpiration](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-remove-notify-auth-expiration)
 *
 * Unregisters a notification handler previously registered with ${function.eos_connect_add_notify_auth_expiration}.
 *
 * @param {Real} notification_id The ID returned by ${function.eos_connect_add_notify_auth_expiration}.
 *
 * @function_end
 */

/**
 * @function eos_connect_add_notify_login_status_changed
 * @desc **Epic Online Services Function:** [EOS_Connect_AddNotifyLoginStatusChanged](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-add-notify-login-status-changed)
 *
 * Registers to be notified whenever a local user's Connect login status changes. Call
 * ${function.eos_connect_remove_notify_login_status_changed} with the returned ID when you no longer need
 * the notification.
 *
 * @param {Function} [callback] Called every time a local user's Connect login status changes.
 *
 * @returns {Real} A notification ID, or `0` if registration failed.
 *
 * @event callback
 * @desc Fires whenever a local user's login status changes.
 * @member {Struct.EpicConnectLoginStatusChangedCallbackInfo} result
 * @event_end
 *
 * @function_end
 */

/**
 * @function eos_connect_remove_notify_login_status_changed
 * @desc **Epic Online Services Function:** [EOS_Connect_RemoveNotifyLoginStatusChanged](https://dev.epicgames.com/docs/api-ref/functions/eos-connect-remove-notify-login-status-changed)
 *
 * Unregisters a notification handler previously registered with ${function.eos_connect_add_notify_login_status_changed}.
 *
 * @param {Real} notification_id The ID returned by ${function.eos_connect_add_notify_login_status_changed}.
 *
 * @function_end
 */

// Structs

/**
 * @struct EpicConnectLoginCallbackInfo
 * @desc Result of ${function.eos_connect_login}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id Empty unless `result_code` is `EpicResult.Success`.
 * @member {Bool} has_continuance_token `true` if `result_code` is `EpicResult.InvalidUser` and this login can be continued via ${function.eos_connect_create_user}/${function.eos_connect_link_account}.
 * @member {Real} continuance_token_id Only meaningful when `has_continuance_token` is `true`.
 *
 * @struct_end
 */

/**
 * @struct EpicConnectCreateUserCallbackInfo
 * @desc Result of ${function.eos_connect_create_user}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id The newly created Product User ID. Empty on failure.
 *
 * @struct_end
 */

/**
 * @struct EpicConnectLinkAccountCallbackInfo
 * @desc Result of ${function.eos_connect_link_account}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 *
 * @struct_end
 */

/**
 * @struct EpicConnectUnlinkAccountCallbackInfo
 * @desc Result of ${function.eos_connect_unlink_account}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 *
 * @struct_end
 */

/**
 * @struct EpicConnectCreateDeviceIdCallbackInfo
 * @desc Result of ${function.eos_connect_create_device_id}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} device_model Echoes the `device_model` you passed in.
 *
 * @struct_end
 */

/**
 * @struct EpicConnectDeleteDeviceIdCallbackInfo
 * @desc Result of ${function.eos_connect_delete_device_id}.
 *
 * @member {Constant.EpicResult} result_code
 *
 * @struct_end
 */

/**
 * @struct EpicConnectTransferDeviceIdAccountCallbackInfo
 * @desc Result of ${function.eos_connect_transfer_device_id_account}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 *
 * @struct_end
 */

/**
 * @struct EpicConnectLogoutCallbackInfo
 * @desc Result of ${function.eos_connect_logout}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 *
 * @struct_end
 */

/**
 * @struct EpicConnectIdToken
 * @desc A Connect ID token, as returned by ${function.eos_connect_copy_id_token}.
 *
 * @member {String} product_user_id
 * @member {String} json_web_token The signed JSON Web Token string. Pass this to your backend, or to ${function.eos_connect_verify_id_token}.
 *
 * @struct_end
 */

/**
 * @struct EpicConnectExternalAccountInfo
 * @desc Info about one external account linked to a Product User ID.
 *
 * @member {String} product_user_id
 * @member {String} display_name The display name on the external platform. May be empty if the platform didn't provide one.
 * @member {String} account_id The raw external account ID.
 * @member {Constant.EpicExternalAccountType} account_id_type
 * @member {Real} last_login_time Unix timestamp of the last time this external account was used to log in, or `-1` if unknown.
 *
 * @struct_end
 */

/**
 * @struct EpicConnectVerifyIdTokenCallbackInfo
 * @desc Result of ${function.eos_connect_verify_id_token}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} product_user_id
 * @member {Bool} is_account_info_present When `false`, this token belongs to a Device-ID-only account and `account_id_type`/`account_id`/`platform`/`device_type` below are empty — do not treat them as real values in that case.
 * @member {Constant.EpicExternalAccountType} account_id_type Only valid when `is_account_info_present` is `true`.
 * @member {String} account_id Only valid when `is_account_info_present` is `true`.
 * @member {String} platform Only valid when `is_account_info_present` is `true`.
 * @member {String} device_type Only valid when `is_account_info_present` is `true`.
 * @member {String} client_id The client ID that requested this token.
 * @member {String} product_id
 * @member {String} sandbox_id
 * @member {String} deployment_id
 *
 * @struct_end
 */

/**
 * @struct EpicConnectQueryExternalAccountMappingsCallbackInfo
 * @desc Result of ${function.eos_connect_query_external_account_mappings}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 *
 * @struct_end
 */

/**
 * @struct EpicConnectQueryProductUserIdMappingsCallbackInfo
 * @desc Result of ${function.eos_connect_query_product_user_id_mappings}.
 *
 * @member {Constant.EpicResult} result_code
 * @member {String} local_user_id
 *
 * @struct_end
 */

/**
 * @struct EpicConnectAuthExpirationCallbackInfo
 * @desc Payload of the ${function.eos_connect_add_notify_auth_expiration} notification.
 *
 * @member {String} local_user_id The Product User ID whose authentication is about to expire.
 *
 * @struct_end
 */

/**
 * @struct EpicConnectLoginStatusChangedCallbackInfo
 * @desc Payload of the ${function.eos_connect_add_notify_login_status_changed} notification.
 *
 * @member {String} local_user_id
 * @member {Constant.EpicLoginStatus} previous_status
 * @member {Constant.EpicLoginStatus} current_status
 *
 * @struct_end
 */

// Constants

/**
 * @const EpicExternalAccountType
 * @desc **Epic Online Services Enum:** [EOS_EExternalAccountType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-external-account-type)
 *
 * The external platform an external account ID belongs to.
 *
 * @member Epic
 * @member Steam
 * @member Psn
 * @member Xbl
 * @member Discord
 * @member Gog
 * @member Nintendo
 * @member Uplay
 * @member OpenId
 * @member Apple
 * @member Google
 * @member Oculus
 * @member ItchIo
 * @member Amazon
 * @member Viveport
 *
 * @const_end
 */

/**
 * @const EpicExternalCredentialType
 * @desc **Epic Online Services Enum:** [EOS_EExternalCredentialType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-external-credential-type)
 *
 * The type of external credential passed to ${function.eos_connect_login} (and to
 * ${function.eos_auth_login} for external-account Epic Account Service logins).
 *
 * @member Epic Epic Account Services token. Using an ID token (${Function.eos_auth_copy_id_token}) is
 * preferred; an auth token (${function.eos_auth_copy_user_auth_token}) is supported for backwards
 * compatibility.
 * @member SteamAppTicket Steam Encrypted App Ticket, generated with Steamworks SDK's
 * `RequestEncryptedAppTicket`.
 * @member PsnIdToken PlayStation Network ID Token, retrieved from the PlayStation SDK.
 * @member XblXstsToken Xbox Live XSTS Token, retrieved from the GDK/XDK.
 * @member DiscordAccessToken Discord Access Token, retrieved with Discord SDK's `GetOAuth2Token`.
 * @member GogSessionTicket GOG Galaxy Encrypted App Ticket, generated with GOG Galaxy SDK's
 * `RequestEncryptedAppTicket`.
 * @member NintendoIdToken Nintendo Account ID Token, acquired through web-flow authentication with the
 * user's email/sign-in ID and password (the common cross-device Nintendo account).
 * @member NintendoNsaIdToken Nintendo Service Account ID (NSA ID) Token, identifying the local Nintendo
 * Switch device without explicit user credentials. Not exposed to the user; link a Nintendo Account or
 * other external account to preserve progression across devices/platforms.
 * @member UplayAccessToken Uplay Access Token.
 * @member OpenIdAccessToken Generic OpenID Provider Access Token.
 * @member DeviceIdAccessToken Local Device ID token from ${Function.eos_connect_create_device_id},
 * identifying the current OS user profile on this device rather than any real external account — lets a
 * player start playing without logging into anything, with the option to link a real account later onto
 * the same Product User ID.
 * @member AppleIdToken Apple ID Token.
 * @member GoogleIdToken Google ID Token.
 * @member OculusUseridNonce Oculus User ID + Nonce (from `ovr_User_GetUserProof`), passed as a
 * `"{UserID}{Nonce}"` formatted string. Requires the User ID feature enabled for your app in the Oculus
 * Developer Dashboard.
 * @member ItchIoJwt itch.io JWT Access Token, obtained via the itch.io app manifest's
 * `ITCHIO_API_KEY` environment variable. Valid for 7 days; the game needs restarting after expiry to
 * refresh the EOS Connect session.
 * @member ItchIoKey itch.io Key Access Token, retrieved through itch.io's OAuth 2.0 flow.
 * @member EpicIdToken Epic Games ID Token, acquired with ${Function.eos_auth_copy_id_token}.
 * @member AmazonAccessToken Amazon Access Token.
 * @member SteamSessionTicket Steam Auth Session Ticket, generated with Steamworks SDK's
 * `ISteamUser::GetAuthTicketForWebApi`.
 * @member ViveportUserToken VIVEPORT User Session Token.
 *
 * @const_end
 */

/**
 * @module connect
 * @title Connect
 * @desc **Epic Online Services Interface:** [Connect Interface](https://dev.epicgames.com/docs/game-services/eos-connect-interface)
 *
 * The [Connect Interface](https://dev.epicgames.com/docs/game-services/eos-connect-interface) links
 * external accounts (Steam, PSN, Xbox Live, a local device ID, ...) to an Epic Online Services Product
 * User ID, independently of the Epic Account Service. Most cross-platform games authenticate through
 * this module rather than ${module.auth} directly.
 *
 * [[Note: See ${page.logging_in} for a full walkthrough of the login flow, including how to handle the continuance-token case.]]
 *
 * @section_func
 * @desc Provided functions:
 *
 * @ref eos_connect_login
 * @ref eos_connect_create_user
 * @ref eos_connect_link_account
 * @ref eos_connect_unlink_account
 * @ref eos_connect_create_device_id
 * @ref eos_connect_delete_device_id
 * @ref eos_connect_transfer_device_id_account
 * @ref eos_connect_logout
 * @ref eos_connect_get_logged_in_users_count
 * @ref eos_connect_get_logged_in_user_by_index
 * @ref eos_connect_get_login_status
 * @ref eos_connect_copy_id_token
 * @ref eos_connect_copy_product_user_info
 * @ref eos_connect_get_product_user_external_account_count
 * @ref eos_connect_copy_product_user_external_account_by_index
 * @ref eos_connect_copy_product_user_external_account_by_account_type
 * @ref eos_connect_copy_product_user_external_account_by_account_id
 * @ref eos_connect_get_product_user_id_mapping
 * @ref eos_connect_get_external_account_mapping
 * @ref eos_connect_verify_id_token
 * @ref eos_connect_query_external_account_mappings
 * @ref eos_connect_query_product_user_id_mappings
 * @ref eos_connect_add_notify_auth_expiration
 * @ref eos_connect_remove_notify_auth_expiration
 * @ref eos_connect_add_notify_login_status_changed
 * @ref eos_connect_remove_notify_login_status_changed
 *
 * @section_end
 *
 * @section_struct
 * @desc Structs used by this module:
 *
 * @ref EpicConnectLoginCallbackInfo
 * @ref EpicConnectCreateUserCallbackInfo
 * @ref EpicConnectLinkAccountCallbackInfo
 * @ref EpicConnectUnlinkAccountCallbackInfo
 * @ref EpicConnectCreateDeviceIdCallbackInfo
 * @ref EpicConnectDeleteDeviceIdCallbackInfo
 * @ref EpicConnectTransferDeviceIdAccountCallbackInfo
 * @ref EpicConnectLogoutCallbackInfo
 * @ref EpicConnectIdToken
 * @ref EpicConnectExternalAccountInfo
 * @ref EpicConnectVerifyIdTokenCallbackInfo
 * @ref EpicConnectQueryExternalAccountMappingsCallbackInfo
 * @ref EpicConnectQueryProductUserIdMappingsCallbackInfo
 * @ref EpicConnectAuthExpirationCallbackInfo
 * @ref EpicConnectLoginStatusChangedCallbackInfo
 *
 * @section_end
 *
 * @section_const
 * @desc Constants used by this module:
 *
 * @ref EpicExternalAccountType
 * @ref EpicExternalCredentialType
 *
 * @section_end
 *
 * @module_end
 */
