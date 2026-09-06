// Functions


/**
 * @function eos_test
 * @desc Internal sanity-check function that confirms the extension's native library has loaded and is
 * callable. It always returns the constant `1993` and does not touch the EOS SDK in any way. Not part
 * of the Epic Online Services API itself.
 *
 * @returns {Real}
 *
 * @function_end
 */

/**
 * @function eos_api_last_error
 * @desc Returns the error message set by the most recent failed call into this extension, across every
 * module. Most functions clear this at the start of the call and, on failure, set it to the SDK's own
 * result-code text (see ${function.eos_api_result_to_string}) or a short internal validation message
 * (e.g. a required parameter was empty).
 *
 * [[Note: This is a single shared value, not per-function or per-thread. Read it immediately after a
 * call fails, before making any other extension call.]]
 *
 * @returns {String}
 *
 * @example
 * ```gml
 * if (eos_api_initialize("MyGame", "1.0") != EpicResult.Success)
 * {
 *     show_debug_message("Initialize failed: " + eos_api_last_error());
 * }
 * ```
 * @function_end
 */

/**
 * @function eos_api_is_initialized
 * @desc **Epic Online Services Function:** [EOS_Initialize](https://dev.epicgames.com/docs/api-ref/functions/eos-initialize)
 *
 * Returns whether ${function.eos_api_initialize} has already succeeded. The SDK can only be initialized
 * once per process, so check this before calling ${function.eos_api_initialize} again.
 *
 * @returns {Bool}
 *
 * @function_end
 */

/**
 * @function eos_api_initialize
 * @desc **Epic Online Services Function:** [EOS_Initialize](https://dev.epicgames.com/docs/api-ref/functions/eos-initialize)
 *
 * Initializes the Epic Online Services SDK. This must be the first call you make into this extension,
 * and must only be called once - call ${function.eos_api_is_initialized} first if you're not sure
 * whether it has already run. Once this succeeds, create the platform handle with
 * ${function.eos_platform_create}.
 *
 * @param {String} product_name Name of your product. Must be non-empty, at most 64 characters, and use
 * only `A-Z a-z 0-9 . _ space ! ? & - ( ) + :`.
 * @param {String} product_version Version string of your product, same character rules as `product_name`.
 *
 * @returns {Constant.EpicResult}
 *
 * [[Note: `EpicResult.Success` is also returned (as a no-op) if the SDK is already initialized.]]
 *
 * @example
 * ```gml
 * if (eos_api_initialize("MyGame", "1.0.0") == EpicResult.Success)
 * {
 *     eos_platform_create(working_directory);
 * }
 * ```
 * @function_end
 */

/**
 * @function eos_api_shutdown
 * @desc **Epic Online Services Function:** [EOS_Shutdown](https://dev.epicgames.com/docs/api-ref/functions/eos-shutdown)
 *
 * Shuts down the Epic Online Services SDK. Releases the platform handle first if one is still open, so
 * you don't need to call ${function.eos_platform_release} yourself beforehand. No further calls into
 * this extension are valid after this succeeds.
 *
 * [[Warning: Call this once, right before your game closes.]]
 *
 * @returns {Constant.EpicResult}
 *
 * @example
 * ```gml
 * /// Game End Event
 * eos_api_shutdown();
 * ```
 * @function_end
 */

/**
 * @function eos_api_get_version
 * @desc **Epic Online Services Function:** [EOS_GetVersion](https://dev.epicgames.com/docs/api-ref/functions/eos-get-version)
 *
 * Returns the version string of the vendored EOSSDK binary this extension was built against.
 *
 * @returns {String}
 *
 * @example
 * ```gml
 * show_debug_message($"EpicOnlineServices Version: {eos_api_get_version()}");
 * ```
 * @function_end
 */

/**
 * @function eos_api_result_to_string
 * @desc **Epic Online Services Function:** [EOS_EResult_ToString](https://dev.epicgames.com/docs/api-ref/functions/eos-eresult-to-string)
 *
 * Returns the human-readable text for a ${constant.EpicResult} value.
 *
 * @param {Constant.EpicResult} result The result code to convert.
 *
 * @returns {String}
 *
 * @function_end
 */

/**
 * @function eos_api_result_is_operation_complete
 * @desc **Epic Online Services Function:** [EOS_EResult_IsOperationComplete](https://dev.epicgames.com/docs/api-ref/functions/eos-eresult-is-operation-complete)
 *
 * Returns whether a ${constant.EpicResult} value represents a finished operation. Most codes are
 * terminal (`true`); `EpicResult.OperationWillRetry` is the one common case that is not (`false`) - the
 * SDK will call your callback again later with a further result.
 *
 * @param {Constant.EpicResult} result The result code to check.
 *
 * @returns {Bool}
 *
 * @function_end
 */

/**
 * @function eos_api_application_status_to_string
 * @desc **Epic Online Services Function:** [EOS_EApplicationStatus_ToString](https://dev.epicgames.com/docs/api-ref/functions/eos-eapplication-status-to-string)
 *
 * Returns the human-readable text for a ${constant.EpicApplicationStatus} value.
 *
 * @param {Constant.EpicApplicationStatus} status The status value to convert.
 *
 * @returns {String}
 *
 * @function_end
 */

/**
 * @function eos_api_network_status_to_string
 * @desc **Epic Online Services Function:** [EOS_ENetworkStatus_ToString](https://dev.epicgames.com/docs/api-ref/functions/eos-enetwork-status-to-string)
 *
 * Returns the human-readable text for a ${constant.EpicNetworkStatus} value.
 *
 * @param {Constant.EpicNetworkStatus} status The status value to convert.
 *
 * @returns {String}
 *
 * @function_end
 */

/**
 * @function eos_api_epic_account_id_is_valid
 * @desc **Epic Online Services Function:** [EOS_EpicAccountId_IsValid](https://dev.epicgames.com/docs/api-ref/functions/eos-epic-account-id-is-valid)
 *
 * Returns whether a string is a well-formed Epic Account ID. This only checks the string's shape - it
 * does not confirm the account actually exists or is logged in.
 *
 * @param {String} account_id The Epic Account ID string to validate.
 *
 * @returns {Bool}
 *
 * @function_end
 */

/**
 * @function eos_api_product_user_id_is_valid
 * @desc **Epic Online Services Function:** [EOS_ProductUserId_IsValid](https://dev.epicgames.com/docs/api-ref/functions/eos-product-user-id-is-valid)
 *
 * Returns whether a string is a well-formed Product User ID. This only checks the string's shape - it
 * does not confirm the account actually exists or is logged in.
 *
 * @param {String} product_user_id The Product User ID string to validate.
 *
 * @returns {Bool}
 *
 * @function_end
 */

// Constants

/**
 * @const EpicResult
 * @desc **Epic Online Services Enum:** [EOS_EResult](https://dev.epicgames.com/docs/api-ref/enums/eos-e-result)
 *
 * The status/result code returned by (or passed into a callback by) nearly every function in this
 * extension. `EpicResult.Success` means the call succeeded; every other value is an error or an
 * in-progress/retry state. Use ${function.eos_api_result_to_string} to get human-readable text for any
 * value.
 *
 * [[Warning: This enum does not list the `AntiCheat_*`, `Mods_*` and `KWS_*` result families. Those
 * three EOS interfaces are not wrapped by this extension, so nothing here can return one of their
 * codes. Every other family the SDK defines is declared. If you ever receive a value with no matching
 * constant, pass it to ${function.eos_api_result_to_string}, which round-trips through the SDK and
 * names any code it knows.]]
 *
 * @member Success Successful result. No further error processing needed.
 * @member NoConnection Failed due to no connection.
 * @member InvalidCredentials Failed login due to invalid credentials.
 * @member InvalidUser Failed due to invalid or missing user.
 * @member InvalidAuth Failed due to invalid or missing authentication token for user (e.g. not logged in).
 * @member AccessDenied Failed due to invalid access.
 * @member MissingPermissions If the client does not possess the permission required.
 * @member Token_Not_Account If the token provided does not represent an account.
 * @member TooManyRequests Throttled due to too many requests.
 * @member AlreadyPending Async request was already pending.
 * @member InvalidParameters Invalid parameters specified for request.
 * @member InvalidRequest Invalid request.
 * @member UnrecognizedResponse Failed due to unable to parse or recognize a backend response.
 * @member IncompatibleVersion Incompatible client for backend version.
 * @member NotConfigured Not configured correctly for use.
 * @member AlreadyConfigured Already configured for use.
 * @member NotImplemented Feature not available on this implementation.
 * @member Canceled Operation was canceled (likely by user).
 * @member NotFound The requested information was not found.
 * @member OperationWillRetry An error occurred during an asynchronous operation, and it will be retried.
 * @member NoChange The request had no effect.
 * @member VersionMismatch The request attempted to use multiple or inconsistent API versions.
 * @member LimitExceeded A maximum limit was exceeded on the client, different from `TooManyRequests`.
 * @member Disabled Feature or client ID performing the operation has been disabled.
 * @member DuplicateNotAllowed Duplicate entry not allowed.
 * @member MissingParameters_DEPRECATED Deprecated - no longer returned by the SDK.
 * @member InvalidSandboxId Sandbox ID is invalid.
 * @member TimedOut Request timed out.
 * @member PartialResult A query returned some but not all of the requested results.
 * @member Missing_Role Client is missing the white-listed role.
 * @member Missing_Feature Client is missing the white-listed feature.
 * @member Invalid_Sandbox The sandbox given to the backend is invalid.
 * @member Invalid_Deployment The deployment given to the backend is invalid.
 * @member Invalid_Product The product ID specified to the backend is invalid.
 * @member Invalid_ProductUserID The product user ID specified to the backend is invalid.
 * @member ServiceFailure There was a failure with the backend service.
 * @member CacheDirectoryMissing Cache directory is not set in platform options.
 * @member CacheDirectoryInvalid Cache directory is not accessible.
 * @member InvalidState The request failed because resource was in an invalid state.
 * @member RequestInProgress Request is in progress.
 * @member ApplicationSuspended Application is suspended.
 * @member NetworkDisconnected Network is disconnected.
 * @member InsufficientOutputBuffer Given output buffer is insufficient to complete the operation.
 * @member ClientPolicyMissingAction The associated feature or action is not enabled in the client policy.
 * @member Auth_AccountLocked Account locked due to login failures.
 * @member Auth_AccountLockedForUpdate Account locked by update operation.
 * @member Auth_InvalidRefreshToken Refresh token used was invalid.
 * @member Auth_InvalidToken Invalid access token, typically when switching between backend environments.
 * @member Auth_AuthenticationFailure Invalid bearer token.
 * @member Auth_InvalidPlatformToken Invalid platform token.
 * @member Auth_WrongAccount Auth parameters are not associated with this account.
 * @member Auth_WrongClient Auth parameters are not associated with this client.
 * @member Auth_FullAccountRequired Full account is required.
 * @member Auth_HeadlessAccountRequired Headless account is required.
 * @member Auth_PasswordResetRequired Password reset is required.
 * @member Auth_PasswordCannotBeReused Password was previously used and cannot be reused.
 * @member Auth_Expired Authorization code/exchange code has expired.
 * @member Auth_ScopeConsentRequired Consent has not been given by the user.
 * @member Auth_ApplicationNotFound The application has no profile on the backend.
 * @member Auth_ScopeNotFound The requested consent wasn't found on the backend.
 * @member Auth_AccountFeatureRestricted This account has been denied access to login.
 * @member Auth_AccountPortalLoadError The account portal web page failed to load.
 * @member Auth_CorrectiveActionRequired The account requires a corrective action before it can log in.
 * @member Auth_PinGrantCode Pin grant code initiated.
 * @member Auth_PinGrantExpired Pin grant code attempt expired.
 * @member Auth_PinGrantPending Pin grant code attempt pending.
 * @member Auth_ExternalAuthNotLinked External auth source did not yield an account.
 * @member Auth_ExternalAuthRevoked External auth access revoked.
 * @member Auth_ExternalAuthInvalid External auth token cannot be interpreted.
 * @member Auth_ExternalAuthRestricted External auth cannot be linked to this account due to restrictions.
 * @member Auth_ExternalAuthCannotLogin External auth cannot be used for login.
 * @member Auth_ExternalAuthExpired External auth is expired.
 * @member Auth_ExternalAuthIsLastLoginType External auth cannot be removed since it's the last possible way to log in.
 * @member Auth_ExchangeCodeNotFound Exchange code not found.
 * @member Auth_OriginatingExchangeCodeSessionExpired Originating exchange code session has expired.
 * @member Auth_AccountNotActive The account has been disabled and cannot be used for authentication.
 * @member Auth_MFARequired MFA challenge required.
 * @member Auth_ParentalControls Parental locks are in place.
 * @member Auth_NoRealId Korea real ID association required but missing.
 * @member Auth_UserInterfaceRequired The auth flow requires the social overlay UI, which is unavailable.
 * @member Friends_InviteAwaitingAcceptance An outgoing friend invitation is waiting acceptance; sending another invite to the same user is erroneous.
 * @member Friends_NoInvitation There is no friend invitation to accept/reject.
 * @member Friends_AlreadyFriends Users are already friends, so sending another invite is erroneous.
 * @member Friends_NotFriends Users are not friends, so deleting the friend is erroneous.
 * @member Friends_TargetUserTooManyInvites Remote user has too many invites to receive new invites.
 * @member Friends_LocalUserTooManyInvites Local user has too many invites to send new invites.
 * @member Friends_TargetUserFriendLimitExceeded Remote user has too many friends to make a new friendship.
 * @member Friends_LocalUserFriendLimitExceeded Local user has too many friends to make a new friendship.
 * @member Presence_DataInvalid Request data was null or invalid.
 * @member Presence_DataLengthInvalid Request contained too many or too few unique data items, or the request would overflow the maximum amount of data allowed.
 * @member Presence_DataKeyInvalid Request contained data with an invalid key.
 * @member Presence_DataKeyLengthInvalid Request contained data with a key too long or too short.
 * @member Presence_DataValueInvalid Request contained data with an invalid value.
 * @member Presence_DataValueLengthInvalid Request contained data with a value too long.
 * @member Presence_RichTextInvalid Request contained an invalid rich text string.
 * @member Presence_RichTextLengthInvalid Request contained a rich text string that was too long.
 * @member Presence_StatusInvalid Request contained an invalid status state.
 * @member Presence_RichTextNotSupported Request created with a template - rich text is not supported.
 * @member Presence_TemplateNotSupported Request not created with a template - rich text expected.
 * @member Presence_TemplateIdInvalid Invalid Rich Presence Template ID.
 * @member Presence_TemplateTypeInvalid Template type value is not supported.
 * @member Presence_TemplateKeyInvalid Template key is null or not supplied.
 * @member Presence_TemplateValueInvalid Template value, if type is a string, is null or not supplie.
 * @member Presence_TemplateNotFound Template id was not found for the product or deployment.
 * @member Presence_TemplateInvalidVariableInput Failed to format template with given vairable data.
 * @member Presence_TemplateLocalizationServerError Localization server failed to format template.
 * @member Presence_TemplateUnknownError Unknown error formatting template.
 * @member Ecom_EntitlementStale The entitlement retrieved is stale, re-query for updated information.
 * @member Ecom_CatalogOfferStale The offer retrieved is stale, re-query for updated information.
 * @member Ecom_CatalogItemStale The item or associated structure retrieved is stale, re-query for updated information.
 * @member Ecom_CatalogOfferPriceInvalid One or more offers has an invalid price. This may be caused by the price setup.
 * @member Ecom_CheckoutLoadError The checkout page failed to load.
 * @member Ecom_PurchaseProcessing The player closed the purchase flow overlay after clicking the purchase button. The purchase may still go through - the game needs to query unredeemed entitlements for a short time.
 * @member Ecom_CatalogOfferInvalid The offer is not valid in the catalog for the current sandbox.
 * @member Sessions_SessionInProgress Session is already in progress.
 * @member Sessions_TooManyPlayers Too many players to register with this session.
 * @member Sessions_NoPermission Client has no permissions to access this session.
 * @member Sessions_SessionAlreadyExists Session already exists in the system.
 * @member Sessions_InvalidLock Session lock required for operation.
 * @member Sessions_InvalidSession Invalid session reference.
 * @member Sessions_SandboxNotAllowed Sandbox ID associated with auth didn't match.
 * @member Sessions_InviteFailed Invite failed to send.
 * @member Sessions_InviteNotFound Invite was not found with the service.
 * @member Sessions_UpsertNotAllowed This client may not modify the session.
 * @member Sessions_AggregationFailed Backend nodes unavailable to process request.
 * @member Sessions_HostAtCapacity Individual backend node is at capacity.
 * @member Sessions_SandboxAtCapacity Sandbox on node is at capacity.
 * @member Sessions_SessionNotAnonymous An anonymous operation was attempted on a non-anonymous session.
 * @member Sessions_OutOfSync Session is currently out of sync with the backend, data is saved locally but needs to sync with backend.
 * @member Sessions_TooManyInvites User has received too many invites.
 * @member Sessions_PresenceSessionExists Presence session already exists for the client.
 * @member Sessions_DeploymentAtCapacity Deployment on node is at capacity.
 * @member Sessions_NotAllowed Session operation not allowed.
 * @member Sessions_PlayerSanctioned Session operation not allowed for a sanctioned player.
 * @member PlayerDataStorage_FilenameInvalid Request filename was invalid.
 * @member PlayerDataStorage_FilenameLengthInvalid Request filename was too long.
 * @member PlayerDataStorage_FilenameInvalidChars Request filename contained invalid characters.
 * @member PlayerDataStorage_FileSizeTooLarge Request operation would grow file too large.
 * @member PlayerDataStorage_FileSizeInvalid Request file length is not valid.
 * @member PlayerDataStorage_FileHandleInvalid Request file handle is not valid.
 * @member PlayerDataStorage_DataInvalid Request data is invalid.
 * @member PlayerDataStorage_DataLengthInvalid Request data length was invalid.
 * @member PlayerDataStorage_StartIndexInvalid Request start index was invalid.
 * @member PlayerDataStorage_RequestInProgress Request is in progress.
 * @member PlayerDataStorage_UserThrottled User is marked as throttled, so some operations can't be performed because limits are exceeded.
 * @member PlayerDataStorage_EncryptionKeyNotSet Encryption key is not set during SDK init - see the **Encryption Key** extension option.
 * @member PlayerDataStorage_UserErrorFromDataCallback User data callback returned an error.
 * @member PlayerDataStorage_FileHeaderHasNewerVersion The file has a header from a newer SDK version than this client.
 * @member PlayerDataStorage_FileCorrupted The file is corrupted. In some cases retrying can fix the issue.
 * @member Connect_ExternalTokenValidationFailed EOS Auth service deemed the external token invalid.
 * @member Connect_UserAlreadyExists EOS Auth user already exists.
 * @member Connect_AuthExpired EOS Auth expired.
 * @member Connect_InvalidToken EOS Auth invalid token.
 * @member Connect_UnsupportedTokenType EOS Auth doesn't support this token type.
 * @member Connect_LinkAccountFailed EOS Auth account link failure.
 * @member Connect_ExternalServiceUnavailable EOS Auth external service for validation was unavailable.
 * @member Connect_ExternalServiceConfigurationFailure EOS Auth external service configuration failure with Dev Portal.
 * @member Connect_LinkAccountFailedMissingNintendoIdAccount_DEPRECATED Deprecated - no longer returned by the SDK.
 * @member UI_SocialOverlayLoadError The social overlay page failed to load.
 * @member UI_InconsistentVirtualMemoryFunctions Virtual memory functions are an inconsistent mix of functions and nullptrs.
 * @member Lobby_NotOwner Client has no permissions to modify this lobby.
 * @member Lobby_InvalidLock Lobby lock required for operation.
 * @member Lobby_LobbyAlreadyExists Lobby already exists in the system.
 * @member Lobby_SessionInProgress Lobby is already in progress.
 * @member Lobby_TooManyPlayers Too many players to register with this lobby.
 * @member Lobby_NoPermission Client has no permissions to access this lobby.
 * @member Lobby_InvalidSession Invalid lobby session reference.
 * @member Lobby_SandboxNotAllowed Sandbox ID associated with auth didn't match.
 * @member Lobby_InviteFailed Invite failed to send.
 * @member Lobby_InviteNotFound Invite was not found with the service.
 * @member Lobby_UpsertNotAllowed This client may not modify the lobby.
 * @member Lobby_AggregationFailed Backend nodes unavailable to process request.
 * @member Lobby_HostAtCapacity Individual backend node is at capacity.
 * @member Lobby_SandboxAtCapacity Sandbox on node is at capacity.
 * @member Lobby_TooManyInvites User has received too many invites.
 * @member Lobby_DeploymentAtCapacity Deployment on node is at capacity.
 * @member Lobby_NotAllowed Lobby operation not allowed.
 * @member Lobby_MemberUpdateOnly While restoring a lost connection, lobby ownership changed and only local member data was updated.
 * @member Lobby_PresenceLobbyExists Presence lobby already exists for the client.
 * @member Lobby_VoiceNotEnabled Operation requires a lobby with voice enabled.
 * @member Lobby_PlatformNotAllowed The client platform does not match the allowed platform list for the lobby.
 * @member TitleStorage_UserErrorFromDataCallback User callback that receives data from storage returned error.
 * @member TitleStorage_EncryptionKeyNotSet User forgot to set Encryption key during platform init. Title Storage can't work without it.
 * @member TitleStorage_FileCorrupted Downloaded file is corrupted.
 * @member TitleStorage_FileHeaderHasNewerVersion Downloaded file's format is newer than client SDK version.
 * @member RTC_TooManyParticipants EOS RTC room cannot accept more participants.
 * @member RTC_RoomAlreadyExists EOS RTC room already exists.
 * @member RTC_UserKicked The user kicked out from the room.
 * @member RTC_UserBanned The user is banned.
 * @member RTC_RoomWasLeft EOS RTC room was left successfully.
 * @member RTC_ReconnectionTimegateExpired Connection dropped due to long timeout.
 * @member RTC_ShutdownInvoked EOS RTC room was left due to platform release.
 * @member RTC_UserIsInBlocklist EOS RTC operation failed because the user is in the local user's block list.
 * @member RTC_AllocationFailed Failed to allocate resources.
 * @member RTC_VoiceModerationModeMismatch Failed to join room due to voice moderation mode mismatch.
 * @member RTC_EmptyRecord EOS RTC record buffer was empty.
 * @member RTC_RoomOptionsMismatch Failed to join room due to room options mismatch.
 * @member ProgressionSnapshot_SnapshotIdUnavailable The number of available Snapshot IDs have all been exhausted.
 * @member Android_JavaVMNotStored EOS Android VM not stored.
 * @member Android_ReservedMustReferenceLocalVM EOS Android if Reserved is set it must reference stored VM.
 * @member Android_ReservedMustBeNull EOS Android Reserved must not be provided.
 * @member Permission_RequiredPatchAvailable Patch required before the user can use the privilege.
 * @member Permission_RequiredSystemUpdate System update required before the user can use the privilege.
 * @member Permission_AgeRestrictionFailure Parental control failure usually.
 * @member Permission_AccountTypeFailure Premium Account Subscription required but not available.
 * @member Permission_ChatRestriction User restricted from chat.
 * @member Permission_UGCRestriction User restricted from User Generated Content.
 * @member Permission_OnlinePlayRestricted Online play is restricted.
 * @member DesktopCrossplay_ApplicationNotBootstrapped The application was not launched through the Bootstrapper. Desktop crossplay functionality is unavailable.
 * @member DesktopCrossplay_ServiceNotInstalled The redistributable service is not installed.
 * @member DesktopCrossplay_ServiceStartFailed The desktop crossplay service failed to start.
 * @member DesktopCrossplay_ServiceNotRunning The desktop crossplay service is no longer running for an unknown reason.
 * @member CustomInvites_InviteFailed When sending the custom invite failed.
 * @member UserInfo_BestDisplayNameIndeterminate The best display name could not be safely determined.
 * @member ConsoleInit_OnNetworkRequestedDeprecatedCallbackNotSet OnNetworkRequested_DEPRECATED callback not set when initializing platform.
 * @member ConsoleInit_CacheStorage_SizeKBNotMultipleOf16 CacheStorageSizeKB must be a multiple of 16.
 * @member ConsoleInit_CacheStorage_SizeKBBelowMinimumSize CacheStorageSizeKB is less than the minimum allowed.
 * @member ConsoleInit_CacheStorage_SizeKBExceedsMaximumSize CacheStorageSizeKB is greater than the maximum allowed (4000 MB).
 * @member ConsoleInit_CacheStorage_IndexOutOfRangeRange CacheStorageIndex is out of its allowed range.
 * @member UnexpectedError An unexpected error that we cannot identify has occurred.
 * @const_end
 */

/**
 * @const EpicApplicationStatus
 * @desc **Epic Online Services Enum:** [EOS_EApplicationStatus](https://dev.epicgames.com/docs/api-ref/enums/eos-e-application-status)
 *
 * The application's current OS-level foreground/background state, used with
 * ${function.eos_api_application_status_to_string}.
 *
 * @member BackgroundConstrained The application is backgrounded and constrained (e.g. suspended soon).
 * @member BackgroundUnconstrained The application is backgrounded but not yet constrained.
 * @member BackgroundSuspended The application is fully suspended in the background.
 * @member Foreground The application is in the foreground.
 * @const_end
 */

/**
 * @const EpicNetworkStatus
 * @desc **Epic Online Services Enum:** [EOS_ENetworkStatus](https://dev.epicgames.com/docs/api-ref/enums/eos-e-network-status)
 *
 * The device's current network connectivity, used with ${function.eos_platform_set_network_status} and
 * ${function.eos_api_network_status_to_string}.
 *
 * @member Disabled Networking is completely disabled.
 * @member Offline The device has no network connection.
 * @member Online The device has a network connection.
 * @const_end
 */

/**
 * @const EpicDesktopCrossplayStatus
 * @desc **Epic Online Services Enum:** [EOS_EDesktopCrossplayStatus](https://dev.epicgames.com/docs/api-ref/enums/eos-e-desktop-crossplay-status)
 *
 * Reports whether the desktop crossplay bootstrapper/service required for account-portal login on some
 * desktop platforms is available.
 *
 * @member Ok Desktop crossplay is available and ready.
 * @member ApplicationNotBootstrapped The application was not launched through the Bootstrapper.
 * @member ServiceNotInstalled The redistributable crossplay service is not installed.
 * @member ServiceStartFailed The crossplay service failed to start.
 * @member ServiceNotRunning The crossplay service is no longer running for an unknown reason.
 * @member OverlayDisabled The overlay was explicitly disabled.
 * @member OverlayNotInstalled The overlay is not installed.
 * @member OverlayTrustCheckFailed The overlay's trust check failed.
 * @member OverlayLoadFailed The overlay failed to load.
 * @const_end
 */

/**
 * @const EpicComparisonOp
 * @desc **Epic Online Services Enum:** [EOS_EComparisonOp](https://dev.epicgames.com/docs/api-ref/enums/eos-e-comparison-op)
 *
 * Shared comparison operator used when adding a search parameter to a ${module.sessions} or
 * ${module.lobbies} search - how the search value should be compared against the value stored on the
 * session/lobby.
 *
 * @member Equal Value must equal the one stored on the lobby/session.
 * @member NotEqual Value must not equal the one stored on the lobby/session.
 * @member GreaterThan Value must be strictly greater than the one stored on the lobby/session.
 * @member GreaterThanOrEqual Value must be greater than or equal to the one stored on the lobby/session.
 * @member LessThan Value must be strictly less than the one stored on the lobby/session.
 * @member LessThanOrEqual Value must be less than or equal to the one stored on the lobby/session.
 * @member Distance Prefer values nearest the one specified, i.e. `abs(SearchValue - SessionValue)` closest to 0.
 * @member AnyOf Value stored on the lobby/session may be any from a specified list.
 * @member NotAnyOf Value stored on the lobby/session may NOT be any from a specified list.
 * @member OneOf This one value is part of a collection.
 * @member NotOneOf This one value is NOT part of a collection.
 * @member Contains This value is a case-sensitive substring of an attribute stored on the lobby/session.
 * @const_end
 */

/**
 * @const EpicAttributeType
 * @desc **Epic Online Services Enum:** [EOS_EAttributeType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-attribute-type)
 *
 * The value type of a ${module.sessions}/${module.lobbies} attribute.
 *
 * @member Boolean A boolean value.
 * @member Int64 A 64-bit integer value.
 * @member Double A floating-point value.
 * @member String A string value.
 * @const_end
 */

/**
 * @const EpicAntiCheatClientMode
 * @desc **Epic Online Services Enum:** [EOS_EAntiCheatClientMode](https://dev.epicgames.com/docs/api-ref/enums/eos-e-anti-cheat-client-mode)
 *
 * [[Note: Reserved for the EOS Anti-Cheat interface, which this extension does not currently wrap. No
 * function in this extension consumes this type yet.]]
 *
 * @member Invalid Invalid/uninitialized mode.
 * @member ClientServer Client-server anti-cheat mode.
 * @member PeerToPeer Peer-to-peer anti-cheat mode.
 * @const_end
 */

/**
 * @const EpicAntiCheatClientViolationType
 * @desc **Epic Online Services Enum:** [EOS_EAntiCheatCommonClientViolationType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-anti-cheat-common-client-violation-type)
 *
 * [[Note: Reserved for the EOS Anti-Cheat interface, which this extension does not currently wrap. No
 * function in this extension consumes this type yet.]]
 *
 * @member Invalid Invalid/unset violation type.
 * @member IntegrityCatalogNotFound The integrity catalog could not be found.
 * @member IntegrityCatalogError The integrity catalog failed to load/parse.
 * @member IntegrityCatalogCertificateRevoked The integrity catalog's certificate was revoked.
 * @member IntegrityCatalogMissingMainExecutable The integrity catalog is missing the main executable entry.
 * @member GameFileMismatch A protected game file did not match its expected checksum.
 * @member RequiredGameFileNotFound A required game file was not found.
 * @member UnknownGameFileForbidden An unknown, forbidden game file was detected.
 * @member SystemFileUntrusted An untrusted system file was detected.
 * @member ForbiddenModuleLoaded A forbidden module was loaded into the process.
 * @member CorruptedMemory Memory corruption was detected.
 * @member ForbiddenToolDetected A forbidden tool was detected running alongside the client.
 * @member InternalAntiCheatViolation An internal anti-cheat violation occurred.
 * @member CorruptedNetworkMessageFlow Corrupted anti-cheat network message flow was detected.
 * @member VirtualMachineNotAllowed The client is running inside a disallowed virtual machine.
 * @member ForbiddenSystemConfiguration The system configuration is forbidden.
 * @const_end
 */

/**
 * @const EpicAntiCheatCommonClientType
 * @desc **Epic Online Services Enum:** [EOS_EAntiCheatCommonClientType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-anti-cheat-common-client-type)
 *
 * [[Note: Reserved for the EOS Anti-Cheat interface, which this extension does not currently wrap. No
 * function in this extension consumes this type yet.]]
 *
 * @member ProtectedClient A client protected by anti-cheat.
 * @member UnprotectedClient A client not protected by anti-cheat.
 * @member AIBot An AI-controlled bot client.
 * @const_end
 */

/**
 * @const EpicAntiCheatCommonClientPlatform
 * @desc **Epic Online Services Enum:** [EOS_EAntiCheatCommonClientPlatform](https://dev.epicgames.com/docs/api-ref/enums/eos-e-anti-cheat-common-client-platform)
 *
 * [[Note: Reserved for the EOS Anti-Cheat interface, which this extension does not currently wrap. No
 * function in this extension consumes this type yet.]]
 *
 * @member Unknown Unknown platform.
 * @member Windows Windows.
 * @member Mac macOS.
 * @member Linux Linux.
 * @member Xbox Xbox.
 * @member PlayStation PlayStation.
 * @member Nintendo Nintendo.
 * @member IOS iOS.
 * @member Android Android.
 * @const_end
 */

/**
 * @const EpicAntiCheatCommonClientAction
 * @desc **Epic Online Services Enum:** [EOS_EAntiCheatCommonClientAction](https://dev.epicgames.com/docs/api-ref/enums/eos-e-anti-cheat-common-client-action)
 *
 * [[Note: Reserved for the EOS Anti-Cheat interface, which this extension does not currently wrap. No
 * function in this extension consumes this type yet.]]
 *
 * @member Invalid Invalid/unset action.
 * @member RemovePlayer Remove the player from the session.
 * @const_end
 */

/**
 * @const EpicAntiCheatCommonClientActionReason
 * @desc **Epic Online Services Enum:** [EOS_EAntiCheatCommonClientActionReason](https://dev.epicgames.com/docs/api-ref/enums/eos-e-anti-cheat-common-client-action-reason)
 *
 * [[Note: Reserved for the EOS Anti-Cheat interface, which this extension does not currently wrap. No
 * function in this extension consumes this type yet.]]
 *
 * @member Invalid Invalid/unset reason.
 * @member InternalError An internal anti-cheat error occurred.
 * @member InvalidMessage An invalid anti-cheat message was received.
 * @member AuthenticationFailed Anti-cheat authentication failed.
 * @member NullClient The client handle was null.
 * @member HeartbeatTimeout The anti-cheat heartbeat timed out.
 * @member ClientViolation A client-side violation was detected.
 * @member BackendViolation A backend-side violation was detected.
 * @member TemporaryCooldown The client is under a temporary cooldown.
 * @member TemporaryBanned The client is temporarily banned.
 * @member PermanentBanned The client is permanently banned.
 * @const_end
 */

/**
 * @const EpicAntiCheatCommonClientAuthStatus
 * @desc **Epic Online Services Enum:** [EOS_EAntiCheatCommonClientAuthStatus](https://dev.epicgames.com/docs/api-ref/enums/eos-e-anti-cheat-common-client-auth-status)
 *
 * [[Note: Reserved for the EOS Anti-Cheat interface, which this extension does not currently wrap. No
 * function in this extension consumes this type yet.]]
 *
 * @member Invalid Invalid/unset status.
 * @member LocalAuthComplete Local anti-cheat authentication completed.
 * @member RemoteAuthComplete Remote anti-cheat authentication completed.
 * @const_end
 */

/**
 * @const EpicAntiCheatCommonClientFlags
 * @desc **Epic Online Services Enum:** [EOS_EAntiCheatCommonClientFlags](https://dev.epicgames.com/docs/api-ref/enums/eos-e-anti-cheat-common-client-flags)
 *
 * [[Note: Reserved for the EOS Anti-Cheat interface, which this extension does not currently wrap. No
 * function in this extension consumes this type yet.]]
 *
 * @member None No flags set.
 * @const_end
 */

/**
 * @const EpicAntiCheatCommonClientInput
 * @desc **Epic Online Services Enum:** [EOS_EAntiCheatCommonClientInput](https://dev.epicgames.com/docs/api-ref/enums/eos-e-anti-cheat-common-client-input)
 *
 * [[Note: Reserved for the EOS Anti-Cheat interface, which this extension does not currently wrap. No
 * function in this extension consumes this type yet.]]
 *
 * @member Unknown Unknown input method.
 * @member MouseKeyboard Mouse and keyboard.
 * @member Gamepad Gamepad.
 * @member TouchInput Touch input.
 * @const_end
 */

/**
 * @const EpicAntiCheatCommonEventType
 * @desc **Epic Online Services Enum:** [EOS_EAntiCheatCommonEventType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-anti-cheat-common-event-type)
 *
 * [[Note: Reserved for the EOS Anti-Cheat interface, which this extension does not currently wrap. No
 * function in this extension consumes this type yet.]]
 *
 * @member Invalid Invalid/unset event type.
 * @member GameEvent A game-level event.
 * @member PlayerEvent A player-level event.
 * @const_end
 */

/**
 * @const EpicAntiCheatCommonEventParamType
 * @desc **Epic Online Services Enum:** [EOS_EAntiCheatCommonEventParamType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-anti-cheat-common-event-param-type)
 *
 * [[Note: Reserved for the EOS Anti-Cheat interface, which this extension does not currently wrap. No
 * function in this extension consumes this type yet.]]
 *
 * @member Invalid Invalid/unset param type.
 * @member ClientHandle A client handle value.
 * @member String A string value.
 * @member UInt32 An unsigned 32-bit integer value.
 * @member Int32 A signed 32-bit integer value.
 * @member UInt64 An unsigned 64-bit integer value.
 * @member Int64 A signed 64-bit integer value.
 * @member Vector3f A 3D float vector value.
 * @member Quat A quaternion value.
 * @member Float A float value.
 * @const_end
 */

/**
 * @const EpicAntiCheatCommonGameRoundCompetitionType
 * @desc **Epic Online Services Enum:** [EOS_EAntiCheatCommonGameRoundCompetitionType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-anti-cheat-common-game-round-competition-type)
 *
 * [[Note: Reserved for the EOS Anti-Cheat interface, which this extension does not currently wrap. No
 * function in this extension consumes this type yet.]]
 *
 * @member None No competition type set.
 * @member Casual Casual game round.
 * @member Ranked Ranked game round.
 * @member Competitive Competitive game round.
 * @const_end
 */

/**
 * @const EpicAntiCheatCommonPlayerMovementState
 * @desc **Epic Online Services Enum:** [EOS_EAntiCheatCommonPlayerMovementState](https://dev.epicgames.com/docs/api-ref/enums/eos-e-anti-cheat-common-player-movement-state)
 *
 * [[Note: Reserved for the EOS Anti-Cheat interface, which this extension does not currently wrap. No
 * function in this extension consumes this type yet.]]
 *
 * @member None No movement state.
 * @member Crouching Crouching.
 * @member Prone Prone.
 * @member Mounted Mounted (e.g. on a vehicle/mount).
 * @member Swimming Swimming.
 * @member Falling Falling.
 * @member Flying Flying.
 * @member OnLadder On a ladder.
 * @const_end
 */

/**
 * @const EpicAntiCheatCommonPlayerTakeDamageSource
 * @desc **Epic Online Services Enum:** [EOS_EAntiCheatCommonPlayerTakeDamageSource](https://dev.epicgames.com/docs/api-ref/enums/eos-e-anti-cheat-common-player-take-damage-source)
 *
 * [[Note: Reserved for the EOS Anti-Cheat interface, which this extension does not currently wrap. No
 * function in this extension consumes this type yet.]]
 *
 * @member None No damage source.
 * @member Player Another player.
 * @member NonPlayerCharacter A non-player character.
 * @member World The world/environment.
 * @const_end
 */

/**
 * @const EpicAntiCheatCommonPlayerTakeDamageType
 * @desc **Epic Online Services Enum:** [EOS_EAntiCheatCommonPlayerTakeDamageType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-anti-cheat-common-player-take-damage-type)
 *
 * [[Note: Reserved for the EOS Anti-Cheat interface, which this extension does not currently wrap. No
 * function in this extension consumes this type yet.]]
 *
 * @member None No damage type.
 * @member PointDamage Single point-of-impact damage.
 * @member RadialDamage Radial/area damage.
 * @member DamageOverTime Damage applied over time.
 * @const_end
 */

/**
 * @const EpicAntiCheatCommonPlayerTakeDamageResult
 * @desc **Epic Online Services Enum:** [EOS_EAntiCheatCommonPlayerTakeDamageResult](https://dev.epicgames.com/docs/api-ref/enums/eos-e-anti-cheat-common-player-take-damage-result)
 *
 * [[Note: Reserved for the EOS Anti-Cheat interface, which this extension does not currently wrap. No
 * function in this extension consumes this type yet.]]
 *
 * @member None No result.
 * @member DownedDeprecated Deprecated - player was downed.
 * @member EliminatedDeprecated Deprecated - player was eliminated.
 * @member NormalToDowned Player transitioned from normal to downed.
 * @member NormalToEliminated Player transitioned from normal to eliminated.
 * @member DownedToEliminated Player transitioned from downed to eliminated.
 * @const_end
 */

/**
 * @const EpicIntegratedPlatformManagementFlags
 * @desc **Epic Online Services Enum:** [EOS_EIntegratedPlatformManagementFlags](https://dev.epicgames.com/docs/api-ref/enums/eos-e-integrated-platform-management-flags)
 *
 * [[Note: Reserved for the EOS Integrated Platform interface, which this extension does not currently
 * wrap. No function in this extension consumes this type yet.]]
 *
 * @member Disabled Integrated platform management is disabled.
 * @member LibraryManagedByApplication The application manages the integrated platform library itself.
 * @member LibraryManagedBySDK The EOS SDK manages the integrated platform library.
 * @member DisablePresenceMirroring Don't mirror presence to the integrated platform.
 * @member DisableSDKManagedSessions Don't let the SDK manage integrated platform sessions.
 * @member PreferEOSIdentity Prefer the EOS identity over the integrated platform's.
 * @member PreferIntegratedIdentity Prefer the integrated platform's identity over EOS's.
 * @member ApplicationManagedIdentityLogin The application manages the integrated platform identity login.
 * @const_end
 */

/**
 * @const EpicIntegratedPlatformPreLogoutAction
 * @desc **Epic Online Services Enum:** [EOS_EIntegratedPlatformPreLogoutAction](https://dev.epicgames.com/docs/api-ref/enums/eos-e-integrated-platform-pre-logout-action)
 *
 * [[Note: Reserved for the EOS Integrated Platform interface, which this extension does not currently
 * wrap. No function in this extension consumes this type yet.]]
 *
 * @member ProcessLogoutImmediately Process the logout immediately.
 * @member DeferLogout Defer the logout.
 * @const_end
 */

/**
 * @const EpicKWSPermissionStatus
 * @desc **Epic Online Services Enum:** [EOS_EKWSPermissionStatus](https://dev.epicgames.com/docs/api-ref/enums/eos-e-kws-permission-status)
 *
 * [[Note: Reserved for the EOS Kids Web Services (KWS) interface, which this extension does not
 * currently wrap. No function in this extension consumes this type yet.]]
 *
 * @member Granted Permission granted.
 * @member Rejected Permission rejected.
 * @member Pending Permission decision pending.
 * @const_end
 */

/**
 * @const EpicModEnumerationType
 * @desc **Epic Online Services Enum:** [EOS_EModEnumerationType](https://dev.epicgames.com/docs/api-ref/enums/eos-e-mod-enumeration-type)
 *
 * [[Note: Reserved for the EOS Mods interface, which this extension does not currently wrap. No function
 * in this extension consumes this type yet.]]
 *
 * @member Installed Only enumerate installed mods.
 * @member AllAvailable Enumerate every mod available, installed or not.
 * @const_end
 */

/**
 * @module general
 * @title General
 * @desc This module covers the extension's top-level, no-interface functions - initialization,
 * shutdown, version/ID helpers - plus the shared constants used across every other module
 * (${constant.EpicResult}, comparison/attribute types for session/lobby search, and a handful of enums
 * reserved for EOS interfaces this extension doesn't wrap yet).
 *
 * @section_func
 * @desc Provided functions:
 *
 * @ref eos_test
 * @ref eos_api_last_error
 * @ref eos_api_is_initialized
 * @ref eos_api_initialize
 * @ref eos_api_shutdown
 * @ref eos_api_get_version
 * @ref eos_api_result_to_string
 * @ref eos_api_result_is_operation_complete
 * @ref eos_api_application_status_to_string
 * @ref eos_api_network_status_to_string
 * @ref eos_api_epic_account_id_is_valid
 * @ref eos_api_product_user_id_is_valid
 *
 * @section_end
 *
 * @section_const
 * @desc These are the constants used by this API:
 *
 * @ref EpicResult
 * @ref EpicApplicationStatus
 * @ref EpicNetworkStatus
 * @ref EpicDesktopCrossplayStatus
 * @ref EpicComparisonOp
 * @ref EpicAttributeType
 * @ref EpicAntiCheatClientMode
 * @ref EpicAntiCheatClientViolationType
 * @ref EpicAntiCheatCommonClientType
 * @ref EpicAntiCheatCommonClientPlatform
 * @ref EpicAntiCheatCommonClientAction
 * @ref EpicAntiCheatCommonClientActionReason
 * @ref EpicAntiCheatCommonClientAuthStatus
 * @ref EpicAntiCheatCommonClientFlags
 * @ref EpicAntiCheatCommonClientInput
 * @ref EpicAntiCheatCommonEventType
 * @ref EpicAntiCheatCommonEventParamType
 * @ref EpicAntiCheatCommonGameRoundCompetitionType
 * @ref EpicAntiCheatCommonPlayerMovementState
 * @ref EpicAntiCheatCommonPlayerTakeDamageSource
 * @ref EpicAntiCheatCommonPlayerTakeDamageType
 * @ref EpicAntiCheatCommonPlayerTakeDamageResult
 * @ref EpicIntegratedPlatformManagementFlags
 * @ref EpicIntegratedPlatformPreLogoutAction
 * @ref EpicKWSPermissionStatus
 * @ref EpicModEnumerationType
 *
 * @section_end
 *
 * @module_end
 */
