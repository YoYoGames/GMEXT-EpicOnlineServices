/**
 * @function_partial eos_test
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_api_last_error
 * @returns {String} 
 * @function_end 
 */

/**
 * @function_partial eos_api_is_initialized
 * @returns {Bool} 
 * @function_end 
 */

/**
 * @function_partial eos_api_initialize
 * @param {String} product_name
 * @param {String} product_version
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_api_shutdown
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_api_get_version
 * @returns {String} 
 * @function_end 
 */

/**
 * @function_partial eos_api_result_to_string
 * @param {Enum.EpicResult} result
 * @returns {String} 
 * @function_end 
 */

/**
 * @function_partial eos_api_result_is_operation_complete
 * @param {Enum.EpicResult} result
 * @returns {Bool} 
 * @function_end 
 */

/**
 * @function_partial eos_api_application_status_to_string
 * @param {Enum.EpicApplicationStatus} status
 * @returns {String} 
 * @function_end 
 */

/**
 * @function_partial eos_api_network_status_to_string
 * @param {Enum.EpicNetworkStatus} status
 * @returns {String} 
 * @function_end 
 */

/**
 * @function_partial eos_api_epic_account_id_is_valid
 * @param {String} account_id
 * @returns {Bool} 
 * @function_end 
 */

/**
 * @function_partial eos_api_product_user_id_is_valid
 * @param {String} product_user_id
 * @returns {Bool} 
 * @function_end 
 */

/**
 * @function_partial eos_platform_is_created
 * @returns {Bool} 
 * @function_end 
 */

/**
 * @function_partial eos_platform_create
 * @param {Bool} is_server
 * @param {String} product_id
 * @param {String} sandbox_id
 * @param {String} deployment_id
 * @param {String} client_id
 * @param {String} client_secret
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_platform_release
 * @function_end 
 */

/**
 * @function_partial eos_platform_tick
 * @function_end 
 */

/**
 * @function_partial eos_platform_check_for_launcher_and_restart
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_platform_set_network_status
 * @param {Enum.EpicNetworkStatus} status
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_logging_set_callback
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_logging_clear_callback
 * @function_end 
 */

/**
 * @function_partial eos_logging_set_log_level
 * @param {Enum.EpicLogCategory} log_category
 * @param {Enum.EpicLogLevel} log_level
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_auth_login
 * @param {String} credentials_id
 * @param {String} credentials_token
 * @param {Enum.EpicLoginCredentialType} credentials_type
 * @param {Enum.EpicExternalCredentialType} external_credential_type
 * @param {Enum.EpicAuthScopeFlags} scope_flags
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_auth_logout
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_auth_link_account
 * @param {String} local_user_id
 * @param {Enum.EpicLinkAccountFlags} link_account_flags
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_auth_delete_persistent_auth
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_auth_get_logged_in_accounts_count
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_auth_get_logged_in_account_by_index
 * @param {Real} index
 * @returns {String} 
 * @function_end 
 */

/**
 * @function_partial eos_auth_get_login_status
 * @param {String} local_user_id
 * @returns {Enum.EpicLoginStatus} 
 * @function_end 
 */

/**
 * @function_partial eos_auth_copy_id_token
 * @param {String} local_user_id
 * @param {String} target_account_id
 * @returns {Struct.EpicAuthIdToken} 
 * @function_end 
 */

/**
 * @function_partial eos_auth_copy_user_auth_token
 * @param {String} local_user_id
 * @returns {Struct.EpicAuthUserAuthToken} 
 * @function_end 
 */

/**
 * @function_partial eos_auth_query_id_token
 * @param {String} local_user_id
 * @param {String} target_account_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_auth_verify_id_token
 * @param {String} json_web_token
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_auth_verify_user_auth
 * @param {String} access_token
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_auth_add_notify_login_status_changed
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_auth_remove_notify_login_status_changed
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_connect_login
 * @param {String} token
 * @param {Enum.EpicExternalCredentialType} external_credential_type
 * @param {String} display_name
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_connect_create_user
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_connect_link_account
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_connect_unlink_account
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_connect_create_device_id
 * @param {String} device_model
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_connect_delete_device_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_connect_transfer_device_id_account
 * @param {String} primary_local_user_id
 * @param {String} local_device_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_connect_logout
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_connect_get_logged_in_users_count
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_connect_get_logged_in_user_by_index
 * @param {Real} index
 * @returns {String} 
 * @function_end 
 */

/**
 * @function_partial eos_connect_get_login_status
 * @param {String} local_user_id
 * @returns {Enum.EpicLoginStatus} 
 * @function_end 
 */

/**
 * @function_partial eos_connect_copy_id_token
 * @param {String} local_user_id
 * @returns {Struct.EpicConnectIdToken} 
 * @function_end 
 */

/**
 * @function_partial eos_connect_copy_product_user_info
 * @param {String} target_user_id
 * @returns {Struct.EpicConnectExternalAccountInfo} 
 * @function_end 
 */

/**
 * @function_partial eos_connect_copy_product_user_external_account_by_index
 * @param {String} target_user_id
 * @param {Real} index
 * @returns {Struct.EpicConnectExternalAccountInfo} 
 * @function_end 
 */

/**
 * @function_partial eos_connect_copy_product_user_external_account_by_account_type
 * @param {String} target_user_id
 * @param {Enum.EpicExternalAccountType} account_id_type
 * @returns {Struct.EpicConnectExternalAccountInfo} 
 * @function_end 
 */

/**
 * @function_partial eos_connect_copy_product_user_external_account_by_account_id
 * @param {String} target_user_id
 * @param {String} account_id
 * @returns {Struct.EpicConnectExternalAccountInfo} 
 * @function_end 
 */

/**
 * @function_partial eos_connect_get_product_user_id_mapping
 * @param {String} local_user_id
 * @param {Enum.EpicExternalAccountType} account_id_type
 * @param {String} target_external_user_id
 * @returns {String} 
 * @function_end 
 */

/**
 * @function_partial eos_connect_get_external_account_mapping
 * @param {String} local_user_id
 * @param {Enum.EpicExternalAccountType} account_id_type
 * @param {String} target_external_user_id
 * @returns {String} 
 * @function_end 
 */

/**
 * @function_partial eos_connect_verify_id_token
 * @param {String} json_web_token
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_connect_query_external_account_mappings
 * @param {String} local_user_id
 * @param {Enum.EpicExternalAccountType} account_id_type
 * @param {Array[String]} target_external_user_ids
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_connect_query_product_user_id_mappings
 * @param {String} local_user_id
 * @param {Enum.EpicExternalAccountType} account_id_type
 * @param {Array[String]} target_product_user_ids
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_connect_add_notify_auth_expiration
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_connect_remove_notify_auth_expiration
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_connect_add_notify_login_status_changed
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_connect_remove_notify_login_status_changed
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_friends_query_friends
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_friends_get_friends_count
 * @param {String} local_user_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_friends_get_friend_at_index
 * @param {String} local_user_id
 * @param {Real} index
 * @returns {String} 
 * @function_end 
 */

/**
 * @function_partial eos_friends_get_status
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @returns {Enum.EpicFriendsStatus} 
 * @function_end 
 */

/**
 * @function_partial eos_friends_add_notify_friends_update
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_friends_remove_notify_friends_update
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_user_info_query_user_info
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_user_info_copy_user_info
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @returns {Struct.EpicUserInfo} 
 * @function_end 
 */

/**
 * @function_partial eos_user_info_get_local_platform_type
 * @returns {Enum.EpicExternalAccountType} 
 * @function_end 
 */

/**
 * @function_partial eos_user_info_copy_best_display_name
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @returns {String} 
 * @function_end 
 */

/**
 * @function_partial eos_user_info_copy_external_user_info_by_index
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {Real} index
 * @returns {Struct.EpicUserInfoExternalUserInfo} 
 * @function_end 
 */

/**
 * @function_partial eos_user_info_copy_external_user_info_by_account_type
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {Enum.EpicExternalAccountType} account_type
 * @returns {Struct.EpicUserInfoExternalUserInfo} 
 * @function_end 
 */

/**
 * @function_partial eos_user_info_copy_external_user_info_by_account_id
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {String} account_id
 * @returns {Struct.EpicUserInfoExternalUserInfo} 
 * @function_end 
 */

/**
 * @function_partial eos_stats_ingest_stat
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {String} stat_name
 * @param {Real} ingest_amount
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_stats_query_stats
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {Real} start_time
 * @param {Real} end_time
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_stats_get_stats_count
 * @param {String} target_user_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_stats_copy_stat_by_index
 * @param {String} target_user_id
 * @param {Real} index
 * @returns {Struct.EpicStatsStat} 
 * @function_end 
 */

/**
 * @function_partial eos_stats_copy_stat_by_name
 * @param {String} target_user_id
 * @param {String} name
 * @returns {Struct.EpicStatsStat} 
 * @function_end 
 */

/**
 * @function_partial eos_ui_show_friends
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_ui_show_native_profile
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_ui_acknowledge_event_id
 * @param {Real} ui_event_id
 * @function_end 
 */

/**
 * @function_partial eos_ui_set_display_preference
 * @param {Enum.EpicUINotificationLocation} notification_location
 * @function_end 
 */

/**
 * @function_partial eos_ui_report_input_state
 * @param {Bool} button_down
 * @param {Bool} button_up
 * @param {Bool} button_left
 * @param {Bool} button_right
 * @param {Bool} button_accept
 * @param {Bool} button_cancel
 * @function_end 
 */

/**
 * @function_partial eos_ui_add_notify_display_settings_updated
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_ui_remove_notify_display_settings_updated
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_ui_hide_friends
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_ui_get_friends_visible
 * @param {String} local_user_id
 * @returns {Bool} 
 * @function_end 
 */

/**
 * @function_partial eos_ui_get_friends_exclusive_input
 * @param {String} local_user_id
 * @returns {Bool} 
 * @function_end 
 */

/**
 * @function_partial eos_ui_pause_social_overlay
 * @param {Bool} is_paused
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_ui_is_social_overlay_paused
 * @returns {Bool} 
 * @function_end 
 */

/**
 * @function_partial eos_ui_get_notification_location_preference
 * @returns {Enum.EpicUINotificationLocation} 
 * @function_end 
 */

/**
 * @function_partial eos_ui_show_block_player
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_ui_show_report_player
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_metrics_begin_player_session
 * @param {String} product_user_id
 * @param {Enum.EpicMetricsAccountIdType} account_id_type
 * @param {Enum.EpicUserControllerType} controller_type
 * @param {String} server_ip
 * @param {String} game_session_id
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_metrics_end_player_session
 * @param {String} product_user_id
 * @param {Enum.EpicMetricsAccountIdType} account_id_type
 * @param {Enum.EpicUserControllerType} controller_type
 * @param {String} server_ip
 * @param {String} game_session_id
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_reports_send_player_behavior_report
 * @param {String} reporter_user_id
 * @param {String} reported_user_id
 * @param {Enum.EpicPlayerReportsCategory} category
 * @param {String} message
 * @param {String} context
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_sanctions_query_active_player_sanctions
 * @param {String} target_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_sanctions_get_player_sanction_count
 * @param {String} target_user_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_sanctions_copy_player_sanction_by_index
 * @param {String} target_user_id
 * @param {Real} index
 * @returns {Struct.EpicSanctionsPlayerSanction} 
 * @function_end 
 */

/**
 * @function_partial eos_sanctions_create_player_sanction_appeal
 * @param {String} local_user_id
 * @param {String} reference_id
 * @param {Enum.EpicSanctionAppealReason} reason
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_achievements_query_definitions
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_achievements_query_player_achievements
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_achievements_get_achievement_definition_count
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_achievements_get_player_achievement_count
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_achievements_copy_achievement_definition_by_index
 * @param {Real} index
 * @returns {Struct.EpicAchievementsDefinition} 
 * @function_end 
 */

/**
 * @function_partial eos_achievements_copy_achievement_definition_v2_by_index
 * @param {Real} index
 * @returns {Struct.EpicAchievementsDefinitionV2} 
 * @function_end 
 */

/**
 * @function_partial eos_achievements_copy_achievement_definition_by_id
 * @param {String} achievement_id
 * @returns {Struct.EpicAchievementsDefinition} 
 * @function_end 
 */

/**
 * @function_partial eos_achievements_copy_player_achievement_by_index
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {Real} index
 * @returns {Struct.EpicPlayerAchievement} 
 * @function_end 
 */

/**
 * @function_partial eos_achievements_copy_player_achievement_by_id
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {String} achievement_id
 * @returns {Struct.EpicPlayerAchievement} 
 * @function_end 
 */

/**
 * @function_partial eos_achievements_unlock_achievements
 * @param {String} user_id
 * @param {Array[String]} achievement_ids
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_achievements_add_notify_achievements_unlocked_v2
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_achievements_remove_notify_achievements_unlocked
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_leaderboards_query_definitions
 * @param {String} local_user_id
 * @param {Real} start_time
 * @param {Real} end_time
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_leaderboards_query_ranks
 * @param {String} local_user_id
 * @param {String} leaderboard_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_leaderboards_query_user_scores
 * @param {String} local_user_id
 * @param {String} stat_name
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_leaderboards_get_definition_count
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_leaderboards_get_record_count
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_leaderboards_get_user_score_count
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_leaderboards_copy_definition_by_index
 * @param {Real} index
 * @returns {Struct.EpicLeaderboardDefinition} 
 * @function_end 
 */

/**
 * @function_partial eos_leaderboards_copy_definition_by_id
 * @param {String} leaderboard_id
 * @returns {Struct.EpicLeaderboardDefinition} 
 * @function_end 
 */

/**
 * @function_partial eos_leaderboards_copy_record_by_index
 * @param {Real} index
 * @returns {Struct.EpicLeaderboardRecord} 
 * @function_end 
 */

/**
 * @function_partial eos_leaderboards_copy_record_by_user_id
 * @param {String} user_id
 * @returns {Struct.EpicLeaderboardRecord} 
 * @function_end 
 */

/**
 * @function_partial eos_leaderboards_copy_user_score_by_index
 * @param {Real} index
 * @returns {Struct.EpicLeaderboardUserScore} 
 * @function_end 
 */

/**
 * @function_partial eos_presence_query_presence
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_presence_has_presence
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @returns {Bool} 
 * @function_end 
 */

/**
 * @function_partial eos_presence_copy_presence
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @returns {Struct.EpicPresenceInfo} 
 * @function_end 
 */

/**
 * @function_partial eos_presence_create_presence_modification
 * @param {String} local_user_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_presence_modification_release
 * @param {Real} modification_id
 * @function_end 
 */

/**
 * @function_partial eos_presence_modification_set_status
 * @param {Real} modification_id
 * @param {Enum.EpicPresenceStatus} status
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_presence_modification_set_raw_rich_text
 * @param {Real} modification_id
 * @param {String} rich_text
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_presence_modification_set_data
 * @param {Real} modification_id
 * @param {String} key
 * @param {String} value
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_presence_modification_delete_data
 * @param {Real} modification_id
 * @param {String} key
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_presence_set_presence
 * @param {String} local_user_id
 * @param {Real} modification_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_presence_add_notify_on_presence_changed
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_presence_remove_notify_on_presence_changed
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_presence_add_notify_join_game_accepted
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_presence_remove_notify_join_game_accepted
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_sessions_create_session_modification
 * @param {String} session_name
 * @param {String} session_id
 * @param {String} bucket_id
 * @param {Real} max_players
 * @param {String} local_user_id
 * @param {Bool} presence_enabled
 * @param {Bool} sanctions_enabled
 * @param {Array[Real]} allowed_platform_ids
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_modification_release
 * @param {Real} modification_id
 * @function_end 
 */

/**
 * @function_partial eos_sessions_update_session
 * @param {Real} modification_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_sessions_destroy_session
 * @param {String} session_name
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_sessions_start_session
 * @param {String} session_name
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_sessions_end_session
 * @param {String} session_name
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_sessions_join_session
 * @param {String} session_name
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_sessions_register_players
 * @param {String} session_name
 * @param {Array[String]} target_user_ids
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_sessions_unregister_players
 * @param {String} session_name
 * @param {Array[String]} target_user_ids
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_sessions_create_session_search
 * @param {Real} max_search_results
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_search_release
 * @param {Real} search_id
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_search_set_session_id
 * @param {Real} search_id
 * @param {String} session_id
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_search_set_target_user_id
 * @param {Real} search_id
 * @param {String} target_user_id
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_search_find
 * @param {Real} search_id
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_search_copy_search_result_by_index
 * @param {Real} search_id
 * @param {Real} index
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_details_release
 * @param {Real} session_details_id
 * @function_end 
 */

/**
 * @function_partial eos_sessions_copy_active_session_handle
 * @param {String} session_name
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_active_session_release
 * @param {Real} active_session_id
 * @function_end 
 */

/**
 * @function_partial eos_sessions_active_session_copy_info
 * @param {Real} active_session_id
 * @returns {Struct.EpicActiveSessionInfo} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_copy_session_handle_by_invite_id
 * @param {String} invite_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_copy_session_handle_by_ui_event_id
 * @param {Real} ui_event_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_details_copy_info
 * @param {Real} session_details_id
 * @returns {Struct.EpicSessionDetailsInfo} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_add_notify_session_invite_received
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_remove_notify_session_invite_received
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_sessions_add_notify_session_invite_accepted
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_remove_notify_session_invite_accepted
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_sessions_add_notify_join_session_accepted
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_remove_notify_join_session_accepted
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_modification_set_bucket_id
 * @param {Real} modification_id
 * @param {String} bucket_id
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_modification_set_host_address
 * @param {Real} modification_id
 * @param {String} host_address
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_modification_set_permission_level
 * @param {Real} modification_id
 * @param {Enum.EpicOnlineSessionPermissionLevel} permission_level
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_modification_set_join_in_progress_allowed
 * @param {Real} modification_id
 * @param {Bool} allow_join_in_progress
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_modification_set_max_players
 * @param {Real} modification_id
 * @param {Real} max_players
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_modification_set_invites_allowed
 * @param {Real} modification_id
 * @param {Bool} invites_allowed
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_modification_add_attribute
 * @param {Real} modification_id
 * @param {String} key
 * @param {String} value
 * @param {Enum.EpicSessionAttributeAdvertisementType} advertisement_type
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_modification_remove_attribute
 * @param {Real} modification_id
 * @param {String} key
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_details_get_session_attribute_count
 * @param {Real} session_details_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_details_copy_session_attribute_by_index
 * @param {Real} session_details_id
 * @param {Real} index
 * @returns {Struct.EpicSessionDetailsAttribute} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_details_copy_session_attribute_by_key
 * @param {Real} session_details_id
 * @param {String} key
 * @returns {Struct.EpicSessionDetailsAttribute} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_active_session_get_registered_player_count
 * @param {Real} active_session_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_active_session_get_registered_player_by_index
 * @param {Real} active_session_id
 * @param {Real} index
 * @returns {String} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_send_invite
 * @param {String} session_name
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_sessions_reject_invite
 * @param {String} local_user_id
 * @param {String} invite_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_sessions_query_invites
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_sessions_get_invite_count
 * @param {String} local_user_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_get_invite_id_by_index
 * @param {String} local_user_id
 * @param {Real} index
 * @returns {String} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_search_set_parameter
 * @param {Real} search_id
 * @param {String} key
 * @param {String} value
 * @param {Enum.EpicComparisonOp} comparison_op
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_search_remove_parameter
 * @param {Real} search_id
 * @param {String} key
 * @param {Enum.EpicComparisonOp} comparison_op
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_session_search_get_search_result_count
 * @param {Real} search_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_add_notify_session_invite_rejected
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_remove_notify_session_invite_rejected
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_sessions_add_notify_leave_session_requested
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_remove_notify_leave_session_requested
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_sessions_add_notify_send_session_native_invite_requested
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_sessions_remove_notify_send_session_native_invite_requested
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_lobby_create_lobby
 * @param {String} local_user_id
 * @param {Real} max_lobby_members
 * @param {Enum.EpicLobbyPermissionLevel} permission_level
 * @param {Bool} presence_enabled
 * @param {Bool} allow_invites
 * @param {String} bucket_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_lobby_destroy_lobby
 * @param {String} lobby_id
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_lobby_join_lobby
 * @param {String} lobby_id
 * @param {String} local_user_id
 * @param {Bool} presence_enabled
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_lobby_leave_lobby
 * @param {String} lobby_id
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_lobby_update_lobby_modification
 * @param {String} lobby_id
 * @param {String} local_user_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_lobby_modification_release
 * @param {Real} modification_id
 * @function_end 
 */

/**
 * @function_partial eos_lobby_update_lobby
 * @param {String} lobby_id
 * @param {Real} modification_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_lobby_lobby_modification_set_permission_level
 * @param {Real} modification_id
 * @param {Enum.EpicLobbyPermissionLevel} permission_level
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_lobby_modification_set_max_members
 * @param {Real} modification_id
 * @param {Real} max_members
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_lobby_modification_set_bucket_id
 * @param {Real} modification_id
 * @param {String} bucket_id
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_lobby_modification_set_invites_allowed
 * @param {Real} modification_id
 * @param {Bool} invites_allowed
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_lobby_modification_add_attribute
 * @param {Real} modification_id
 * @param {String} key
 * @param {String} value
 * @param {Enum.EpicLobbyAttributeVisibility} visibility
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_lobby_modification_remove_attribute
 * @param {Real} modification_id
 * @param {String} key
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_lobby_modification_add_member_attribute
 * @param {Real} modification_id
 * @param {String} key
 * @param {String} value
 * @param {Enum.EpicLobbyAttributeVisibility} visibility
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_lobby_modification_remove_member_attribute
 * @param {Real} modification_id
 * @param {String} key
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_promote_member
 * @param {String} lobby_id
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_lobby_kick_member
 * @param {String} lobby_id
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_lobby_create_lobby_search
 * @param {Real} max_results
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_lobby_search_release
 * @param {Real} search_id
 * @function_end 
 */

/**
 * @function_partial eos_lobby_lobby_search_set_lobby_id
 * @param {Real} search_id
 * @param {String} lobby_id
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_lobby_search_set_target_user_id
 * @param {Real} search_id
 * @param {String} target_user_id
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_lobby_search_set_parameter
 * @param {Real} search_id
 * @param {String} key
 * @param {String} value
 * @param {Enum.EpicComparisonOp} comparison_op
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_lobby_search_remove_parameter
 * @param {Real} search_id
 * @param {String} key
 * @param {Enum.EpicComparisonOp} comparison_op
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_lobby_search_set_max_results
 * @param {Real} search_id
 * @param {Real} max_results
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_lobby_search_find
 * @param {Real} search_id
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_lobby_lobby_search_get_search_result_count
 * @param {Real} search_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_lobby_search_copy_search_result_by_index
 * @param {Real} search_id
 * @param {Real} index
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_details_release
 * @param {Real} lobby_details_id
 * @function_end 
 */

/**
 * @function_partial eos_lobby_copy_lobby_details_handle
 * @param {String} lobby_id
 * @param {String} local_user_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_details_copy_info
 * @param {Real} lobby_details_id
 * @returns {Struct.EpicLobbyDetailsInfo} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_details_get_member_count
 * @param {Real} lobby_details_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_details_get_member_by_index
 * @param {Real} lobby_details_id
 * @param {Real} index
 * @returns {String} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_details_get_lobby_owner
 * @param {Real} lobby_details_id
 * @returns {String} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_add_notify_lobby_update_received
 * @param {String} local_user_id
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_remove_notify_lobby_update_received
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_lobby_add_notify_lobby_member_update_received
 * @param {String} local_user_id
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_remove_notify_lobby_member_update_received
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_lobby_add_notify_lobby_member_status_received
 * @param {String} local_user_id
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_remove_notify_lobby_member_status_received
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_lobby_add_notify_join_lobby_accepted
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_remove_notify_join_lobby_accepted
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_lobby_add_notify_leave_lobby_requested
 * @param {String} local_user_id
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_remove_notify_leave_lobby_requested
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_lobby_add_notify_send_lobby_native_invite_requested
 * @param {String} local_user_id
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_remove_notify_send_lobby_native_invite_requested
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_lobby_details_get_attribute_count
 * @param {Real} lobby_details_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_details_copy_attribute_by_index
 * @param {Real} lobby_details_id
 * @param {Real} index
 * @returns {Struct.EpicLobbyDetailsAttribute} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_details_copy_attribute_by_key
 * @param {Real} lobby_details_id
 * @param {String} key
 * @returns {Struct.EpicLobbyDetailsAttribute} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_details_get_member_attribute_count
 * @param {Real} lobby_details_id
 * @param {String} target_user_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_details_copy_member_attribute_by_index
 * @param {Real} lobby_details_id
 * @param {String} target_user_id
 * @param {Real} index
 * @returns {Struct.EpicLobbyDetailsAttribute} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_details_copy_member_attribute_by_key
 * @param {Real} lobby_details_id
 * @param {String} target_user_id
 * @param {String} key
 * @returns {Struct.EpicLobbyDetailsAttribute} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_details_copy_member_info
 * @param {Real} lobby_details_id
 * @param {String} target_user_id
 * @returns {Struct.EpicLobbyDetailsMemberInfo} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_join_lobby_by_id
 * @param {String} lobby_id
 * @param {String} local_user_id
 * @param {Bool} presence_enabled
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_lobby_hard_mute_member
 * @param {String} lobby_id
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {Bool} hard_mute
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_lobby_send_invite
 * @param {String} lobby_id
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_lobby_reject_invite
 * @param {String} invite_id
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_lobby_query_invites
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_lobby_get_invite_count
 * @param {String} local_user_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_get_invite_id_by_index
 * @param {String} local_user_id
 * @param {Real} index
 * @returns {String} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_add_notify_lobby_invite_received
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_remove_notify_lobby_invite_received
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_lobby_add_notify_lobby_invite_accepted
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_remove_notify_lobby_invite_accepted
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_lobby_add_notify_lobby_invite_rejected
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_lobby_remove_notify_lobby_invite_rejected
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_p2p_send_packet
 * @param {String} local_user_id
 * @param {String} remote_user_id
 * @param {String} socket_name
 * @param {Real} channel
 * @param {Buffer} data
 * @param {Real} bytes
 * @param {Bool} allow_delayed_delivery
 * @param {Enum.EpicPacketReliability} reliability
 * @param {Bool} disable_auto_accept_connection
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_get_next_received_packet_size
 * @param {String} local_user_id
 * @param {Real} channel
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_receive_packet
 * @param {String} local_user_id
 * @param {Buffer} out_data
 * @param {Real} max_bytes
 * @param {Real} offset
 * @param {Real} channel
 * @returns {Struct.EpicP2PReceivedPacket} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_accept_connection
 * @param {String} local_user_id
 * @param {String} remote_user_id
 * @param {String} socket_name
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_close_connection
 * @param {String} local_user_id
 * @param {String} remote_user_id
 * @param {String} socket_name
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_close_connections
 * @param {String} local_user_id
 * @param {String} socket_name
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_query_nat_type
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_p2p_get_nat_type
 * @returns {Enum.EpicNATType} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_set_relay_control
 * @param {Enum.EpicRelayControl} relay_control
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_get_relay_control
 * @returns {Enum.EpicRelayControl} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_set_port_range
 * @param {Real} port
 * @param {Real} max_additional_ports_to_try
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_get_port_range
 * @returns {Struct.EpicP2PPortRange} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_set_packet_queue_size
 * @param {Real} incoming_max_bytes
 * @param {Real} outgoing_max_bytes
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_get_packet_queue_info
 * @returns {Struct.EpicP2PPacketQueueInfo} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_clear_packet_queue
 * @param {String} local_user_id
 * @param {String} remote_user_id
 * @param {String} socket_name
 * @returns {Enum.EpicResult} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_add_notify_peer_connection_request
 * @param {String} local_user_id
 * @param {String} socket_name
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_remove_notify_peer_connection_request
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_p2p_add_notify_peer_connection_established
 * @param {String} local_user_id
 * @param {String} socket_name
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_remove_notify_peer_connection_established
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_p2p_add_notify_peer_connection_interrupted
 * @param {String} local_user_id
 * @param {String} socket_name
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_remove_notify_peer_connection_interrupted
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_p2p_add_notify_peer_connection_closed
 * @param {String} local_user_id
 * @param {String} socket_name
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_remove_notify_peer_connection_closed
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_p2p_add_notify_incoming_packet_queue_full
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_p2p_remove_notify_incoming_packet_queue_full
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_playerdatastorage_query_file
 * @param {String} local_user_id
 * @param {String} filename
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_playerdatastorage_query_file_list
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_playerdatastorage_get_file_metadata_count
 * @param {String} local_user_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_playerdatastorage_copy_file_metadata_at_index
 * @param {String} local_user_id
 * @param {Real} index
 * @returns {Struct.EpicPlayerDataStorageFileMetadata} 
 * @function_end 
 */

/**
 * @function_partial eos_playerdatastorage_copy_file_metadata_by_filename
 * @param {String} local_user_id
 * @param {String} filename
 * @returns {Struct.EpicPlayerDataStorageFileMetadata} 
 * @function_end 
 */

/**
 * @function_partial eos_playerdatastorage_duplicate_file
 * @param {String} local_user_id
 * @param {String} source_filename
 * @param {String} destination_filename
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_playerdatastorage_delete_file
 * @param {String} local_user_id
 * @param {String} filename
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_playerdatastorage_read_file
 * @param {String} local_user_id
 * @param {String} filename
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_playerdatastorage_write_file
 * @param {String} local_user_id
 * @param {String} filename
 * @param {String} data_base64
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_playerdatastorage_delete_cache
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_titlestorage_query_file
 * @param {String} local_user_id
 * @param {String} filename
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_titlestorage_query_file_list
 * @param {String} local_user_id
 * @param {Array[String]} tags
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_titlestorage_get_file_metadata_count
 * @param {String} local_user_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_titlestorage_copy_file_metadata_at_index
 * @param {String} local_user_id
 * @param {Real} index
 * @returns {Struct.EpicTitleStorageFileMetadata} 
 * @function_end 
 */

/**
 * @function_partial eos_titlestorage_copy_file_metadata_by_filename
 * @param {String} local_user_id
 * @param {String} filename
 * @returns {Struct.EpicTitleStorageFileMetadata} 
 * @function_end 
 */

/**
 * @function_partial eos_titlestorage_read_file
 * @param {String} local_user_id
 * @param {String} filename
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_titlestorage_delete_cache
 * @param {String} local_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_ecom_query_ownership
 * @param {String} local_user_id
 * @param {Array[String]} catalog_item_ids
 * @param {String} catalog_namespace
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_ecom_query_ownership_by_sandbox_ids
 * @param {String} local_user_id
 * @param {Array[String]} sandbox_ids
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_ecom_query_ownership_token
 * @param {String} local_user_id
 * @param {Array[String]} catalog_item_ids
 * @param {String} catalog_namespace
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_ecom_query_entitlements
 * @param {String} local_user_id
 * @param {Array[String]} entitlement_names
 * @param {Real} include_redeemed
 * @param {String} catalog_namespace
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_ecom_query_entitlement_token
 * @param {String} local_user_id
 * @param {Array[String]} entitlement_names
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_ecom_query_offers
 * @param {String} local_user_id
 * @param {String} catalog_namespace
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_ecom_checkout
 * @param {String} local_user_id
 * @param {Array[String]} offer_ids
 * @param {String} catalog_namespace
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_ecom_redeem_entitlements
 * @param {String} local_user_id
 * @param {Array[String]} entitlement_ids
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_ecom_get_item_ownership_count
 * @param {String} local_user_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_copy_item_ownership_at_index
 * @param {String} local_user_id
 * @param {Real} index
 * @returns {Struct.EpicEcomItemOwnership} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_get_sandbox_ownership_count
 * @param {String} local_user_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_copy_sandbox_ownership_at_index
 * @param {String} local_user_id
 * @param {Real} index
 * @returns {Struct.EpicEcomSandboxIdItemOwnership} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_get_entitlements_count
 * @param {String} local_user_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_get_entitlements_by_name_count
 * @param {String} local_user_id
 * @param {String} entitlement_name
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_copy_entitlement_by_index
 * @param {String} local_user_id
 * @param {Real} index
 * @returns {Struct.EpicEcomEntitlement} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_copy_entitlement_by_name_and_index
 * @param {String} local_user_id
 * @param {String} entitlement_name
 * @param {Real} index
 * @returns {Struct.EpicEcomEntitlement} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_copy_entitlement_by_id
 * @param {String} local_user_id
 * @param {String} entitlement_id
 * @returns {Struct.EpicEcomEntitlement} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_get_last_redeemed_entitlements_count
 * @param {String} local_user_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_copy_last_redeemed_entitlement_by_index
 * @param {String} local_user_id
 * @param {Real} index
 * @returns {String} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_get_offer_count
 * @param {String} local_user_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_copy_offer_by_index
 * @param {String} local_user_id
 * @param {Real} index
 * @returns {Struct.EpicEcomCatalogOffer} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_copy_offer_by_id
 * @param {String} local_user_id
 * @param {String} offer_id
 * @returns {Struct.EpicEcomCatalogOffer} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_get_offer_item_count
 * @param {String} local_user_id
 * @param {String} offer_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_copy_offer_item_by_index
 * @param {String} local_user_id
 * @param {String} offer_id
 * @param {Real} item_index
 * @returns {Struct.EpicEcomCatalogItem} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_copy_item_by_id
 * @param {String} local_user_id
 * @param {String} item_id
 * @returns {Struct.EpicEcomCatalogItem} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_get_offer_image_info_count
 * @param {String} local_user_id
 * @param {String} offer_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_copy_offer_image_info_by_index
 * @param {String} local_user_id
 * @param {String} offer_id
 * @param {Real} image_info_index
 * @returns {Struct.EpicEcomKeyImageInfo} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_get_item_image_info_count
 * @param {String} local_user_id
 * @param {String} item_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_copy_item_image_info_by_index
 * @param {String} local_user_id
 * @param {String} item_id
 * @param {Real} image_info_index
 * @returns {Struct.EpicEcomKeyImageInfo} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_get_item_release_count
 * @param {String} local_user_id
 * @param {String} item_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_copy_item_release_by_index
 * @param {String} local_user_id
 * @param {String} item_id
 * @param {Real} release_index
 * @returns {Struct.EpicEcomCatalogRelease} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_get_transaction_count
 * @param {String} local_user_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_copy_transaction_by_index
 * @param {String} local_user_id
 * @param {Real} transaction_index
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_copy_transaction_by_id
 * @param {String} local_user_id
 * @param {String} transaction_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_transaction_get_transaction_id
 * @param {Real} tx_handle_id
 * @returns {String} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_transaction_get_entitlements_count
 * @param {Real} tx_handle_id
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_transaction_copy_entitlement_by_index
 * @param {Real} tx_handle_id
 * @param {Real} index
 * @returns {Struct.EpicEcomEntitlement} 
 * @function_end 
 */

/**
 * @function_partial eos_ecom_transaction_release
 * @param {Real} tx_handle_id
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_set_custom_invite
 * @param {String} local_user_id
 * @param {String} payload
 * @returns {Bool} 
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_send_custom_invite
 * @param {String} local_user_id
 * @param {Array[String]} target_user_ids
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_finalize_invite
 * @param {String} target_user_id
 * @param {String} local_user_id
 * @param {String} custom_invite_id
 * @param {Enum.EpicResult} processing_result
 * @returns {Bool} 
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_send_request_to_join
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_accept_request_to_join
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_reject_request_to_join
 * @param {String} local_user_id
 * @param {String} target_user_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_add_notify_custom_invite_received
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_remove_notify_custom_invite_received
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_add_notify_custom_invite_accepted
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_remove_notify_custom_invite_accepted
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_add_notify_custom_invite_rejected
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_remove_notify_custom_invite_rejected
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_add_notify_request_to_join_response_received
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_remove_notify_request_to_join_response_received
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_add_notify_request_to_join_received
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_remove_notify_request_to_join_received
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_add_notify_send_custom_native_invite_requested
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_remove_notify_send_custom_native_invite_requested
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_add_notify_request_to_join_accepted
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_remove_notify_request_to_join_accepted
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_add_notify_request_to_join_rejected
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_custominvites_remove_notify_request_to_join_rejected
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_rtc_join_room
 * @param {String} local_user_id
 * @param {String} room_name
 * @param {String} client_base_url
 * @param {String} participant_token
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_rtc_leave_room
 * @param {String} local_user_id
 * @param {String} room_name
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_rtc_block_participant
 * @param {String} local_user_id
 * @param {String} room_name
 * @param {String} participant_id
 * @param {Bool} blocked
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_rtc_set_setting
 * @param {String} setting_name
 * @param {String} setting_value
 * @returns {Bool} 
 * @function_end 
 */

/**
 * @function_partial eos_rtc_set_room_setting
 * @param {String} local_user_id
 * @param {String} room_name
 * @param {String} setting_name
 * @param {String} setting_value
 * @returns {Bool} 
 * @function_end 
 */

/**
 * @function_partial eos_rtc_add_notify_disconnected
 * @param {String} local_user_id
 * @param {String} room_name
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_rtc_remove_notify_disconnected
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_rtc_add_notify_participant_status_changed
 * @param {String} local_user_id
 * @param {String} room_name
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_rtc_remove_notify_participant_status_changed
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_rtc_add_notify_room_statistics_updated
 * @param {String} local_user_id
 * @param {String} room_name
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_rtc_remove_notify_room_statistics_updated
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_update_sending
 * @param {String} local_user_id
 * @param {String} room_name
 * @param {Enum.EpicRTCAudioStatus} audio_status
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_update_receiving
 * @param {String} local_user_id
 * @param {String} room_name
 * @param {String} participant_id
 * @param {Bool} audio_enabled
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_update_sending_volume
 * @param {String} local_user_id
 * @param {String} room_name
 * @param {Real} volume
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_update_receiving_volume
 * @param {String} local_user_id
 * @param {String} room_name
 * @param {Real} volume
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_update_participant_volume
 * @param {String} local_user_id
 * @param {String} room_name
 * @param {String} participant_id
 * @param {Real} volume
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_get_input_devices_count
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_copy_input_device_info_by_index
 * @param {Real} index
 * @returns {Struct.EpicRTCAudioInputDeviceInfo} 
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_get_output_devices_count
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_copy_output_device_info_by_index
 * @param {Real} index
 * @returns {Struct.EpicRTCAudioOutputDeviceInfo} 
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_query_input_devices
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_query_output_devices
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_set_input_device_settings
 * @param {String} local_user_id
 * @param {String} real_device_id
 * @param {Bool} platform_aec
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_set_output_device_settings
 * @param {String} local_user_id
 * @param {String} real_device_id
 * @param {Function} callback
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_add_notify_participant_updated
 * @param {String} local_user_id
 * @param {String} room_name
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_remove_notify_participant_updated
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_add_notify_audio_devices_changed
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_remove_notify_audio_devices_changed
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_add_notify_audio_input_state
 * @param {String} local_user_id
 * @param {String} room_name
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_remove_notify_audio_input_state
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_add_notify_audio_output_state
 * @param {String} local_user_id
 * @param {String} room_name
 * @param {Function} callback
 * @returns {Real} 
 * @function_end 
 */

/**
 * @function_partial eos_rtc_audio_remove_notify_audio_output_state
 * @param {Real} notification_id
 * @function_end 
 */

/**
 * @struct_partial EpicLoggingMessage
 * @member {Enum.EpicLogCategory} category
 * @member {Enum.EpicLogLevel} level
 * @member {String} message
 * @struct_end 
 */

/**
 * @struct_partial EpicAuthLoginCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} selected_account_id
 * @member {Bool} has_continuance_token
 * @struct_end 
 */

/**
 * @struct_partial EpicAuthLogoutCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicAuthLinkAccountCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} selected_account_id
 * @struct_end 
 */

/**
 * @struct_partial EpicAuthDeletePersistentAuthCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @struct_partial EpicAuthIdToken
 * @member {String} account_id
 * @member {String} json_web_token
 * @struct_end 
 */

/**
 * @struct_partial EpicAuthUserAuthToken
 * @member {String} app
 * @member {String} client_id
 * @member {String} account_id
 * @member {String} access_token
 * @member {Real} expires_in
 * @member {String} expires_at
 * @member {Enum.EpicAuthTokenType} auth_type
 * @member {String} refresh_token
 * @member {Real} refresh_expires_in
 * @member {String} refresh_expires_at
 * @struct_end 
 */

/**
 * @struct_partial EpicAuthQueryIdTokenCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} target_account_id
 * @struct_end 
 */

/**
 * @struct_partial EpicAuthVerifyIdTokenCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} application_id
 * @member {String} client_id
 * @member {String} product_id
 * @member {String} sandbox_id
 * @member {String} deployment_id
 * @member {String} display_name
 * @member {Bool} is_external_account_info_present
 * @struct_end 
 */

/**
 * @struct_partial EpicAuthVerifyUserAuthCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @struct_partial EpicAuthLoginStatusChangedCallbackInfo
 * @member {String} local_user_id
 * @member {Enum.EpicLoginStatus} previous_status
 * @member {Enum.EpicLoginStatus} current_status
 * @struct_end 
 */

/**
 * @struct_partial EpicConnectLoginCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {Bool} has_continuance_token
 * @struct_end 
 */

/**
 * @struct_partial EpicConnectCreateUserCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicConnectLinkAccountCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicConnectUnlinkAccountCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicConnectCreateDeviceIdCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} device_model
 * @struct_end 
 */

/**
 * @struct_partial EpicConnectDeleteDeviceIdCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @struct_partial EpicConnectTransferDeviceIdAccountCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicConnectLogoutCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicConnectIdToken
 * @member {String} product_user_id
 * @member {String} json_web_token
 * @struct_end 
 */

/**
 * @struct_partial EpicConnectExternalAccountInfo
 * @member {String} product_user_id
 * @member {String} display_name
 * @member {String} account_id
 * @member {Enum.EpicExternalAccountType} account_id_type
 * @member {Real} last_login_time
 * @struct_end 
 */

/**
 * @struct_partial EpicConnectVerifyIdTokenCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @struct_partial EpicConnectQueryExternalAccountMappingsCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicConnectQueryProductUserIdMappingsCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicConnectAuthExpirationCallbackInfo
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicConnectLoginStatusChangedCallbackInfo
 * @member {String} local_user_id
 * @member {Enum.EpicLoginStatus} previous_status
 * @member {Enum.EpicLoginStatus} current_status
 * @struct_end 
 */

/**
 * @struct_partial EpicFriendsQueryFriendsCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicFriendsFriendsUpdateCallbackInfo
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @member {Enum.EpicFriendsStatus} previous_status
 * @member {Enum.EpicFriendsStatus} current_status
 * @struct_end 
 */

/**
 * @struct_partial EpicUserInfo
 * @member {String} user_id
 * @member {String} country
 * @member {String} display_name
 * @member {String} preferred_language
 * @member {String} nickname
 * @struct_end 
 */

/**
 * @struct_partial EpicUserInfoQueryUserInfoCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicUserInfoExternalUserInfo
 * @member {String} account_id
 * @member {Enum.EpicExternalAccountType} account_type
 * @member {String} display_name
 * @struct_end 
 */

/**
 * @struct_partial EpicStatsStat
 * @member {String} name
 * @member {Real} start_time
 * @member {Real} end_time
 * @member {Real} value
 * @struct_end 
 */

/**
 * @struct_partial EpicStatsIngestStatCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicStatsQueryStatsCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicUIShowFriendsCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicUIShowNativeProfileCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicUIDisplaySettingsUpdatedCallbackInfo
 * @member {Bool} is_visible
 * @member {Bool} is_exclusive_input
 * @struct_end 
 */

/**
 * @struct_partial EpicUIHideFriendsCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicUIShowBlockPlayerCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicUIShowReportPlayerCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicReportsSendPlayerBehaviorReportCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @struct_partial EpicSanctionsPlayerSanction
 * @member {Real} time_placed
 * @member {String} action
 * @member {Real} time_expires
 * @member {String} reference_id
 * @struct_end 
 */

/**
 * @struct_partial EpicSanctionsQueryActivePlayerSanctionsCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} target_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicSanctionsCreatePlayerSanctionAppealCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} reference_id
 * @struct_end 
 */

/**
 * @struct_partial EpicAchievementsQueryDefinitionsCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @struct_partial EpicAchievementsQueryPlayerAchievementsCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} user_id
 * @member {String} target_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicAchievementsDefinition
 * @member {String} achievement_id
 * @member {String} display_name
 * @member {String} description
 * @member {String} locked_display_name
 * @member {String} locked_description
 * @member {String} hidden_description
 * @member {String} completion_description
 * @member {String} unlocked_icon_id
 * @member {String} locked_icon_id
 * @member {Bool} is_hidden
 * @member {Real} stat_thresholds_count
 * @struct_end 
 */

/**
 * @struct_partial EpicPlayerAchievement
 * @member {String} achievement_id
 * @member {Real} progress
 * @member {Real} unlock_time
 * @member {Real} stat_info_count
 * @struct_end 
 */

/**
 * @struct_partial EpicAchievementsUnlockAchievementsCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} user_id
 * @member {Real} achievements_count
 * @struct_end 
 */

/**
 * @struct_partial EpicAchievementsDefinitionV2
 * @member {String} achievement_id
 * @member {String} unlocked_display_name
 * @member {String} unlocked_description
 * @member {String} locked_display_name
 * @member {String} locked_description
 * @member {String} flavor_text
 * @member {String} completion_description
 * @member {String} unlocked_icon_url
 * @member {String} locked_icon_url
 * @member {Bool} is_hidden
 * @member {Real} stat_thresholds_count
 * @struct_end 
 */

/**
 * @struct_partial EpicAchievementsUnlockedV2CallbackInfo
 * @member {String} user_id
 * @member {String} achievement_id
 * @member {Real} unlock_time
 * @struct_end 
 */

/**
 * @struct_partial EpicLeaderboardsQueryDefinitionsCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @struct_partial EpicLeaderboardsQueryRanksCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @struct_partial EpicLeaderboardsQueryUserScoresCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @struct_partial EpicLeaderboardDefinition
 * @member {String} leaderboard_id
 * @member {String} stat_name
 * @member {Real} start_time
 * @member {Real} end_time
 * @member {String} aggregation
 * @struct_end 
 */

/**
 * @struct_partial EpicLeaderboardRecord
 * @member {String} user_id
 * @member {Real} rank
 * @member {Real} score
 * @member {String} user_display_name
 * @struct_end 
 */

/**
 * @struct_partial EpicLeaderboardUserScore
 * @member {String} user_id
 * @member {Real} score
 * @struct_end 
 */

/**
 * @struct_partial EpicPresenceInfo
 * @member {String} user_id
 * @member {Enum.EpicPresenceStatus} status
 * @member {String} product_id
 * @member {String} product_version
 * @member {String} platform
 * @member {String} rich_text
 * @member {Real} records_count
 * @struct_end 
 */

/**
 * @struct_partial EpicPresenceQueryPresenceCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicPresenceSetPresenceCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicPresenceChangedCallbackInfo
 * @member {String} local_user_id
 * @member {String} presence_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicPresenceJoinGameAcceptedCallbackInfo
 * @member {String} join_info
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @member {Real} ui_event_id
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionsUpdateSessionCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} session_name
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionsDestroySessionCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionsStartSessionCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionsEndSessionCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionsJoinSessionCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionsRegisterPlayersCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {Array[String]} registered_players
 * @member {Array[String]} sanctioned_players
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionsUnregisterPlayersCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {Array[String]} unregistered_players
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionsFindCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionDetailsInfo
 * @member {String} session_id
 * @member {String} host_address
 * @member {String} owner_user_id
 * @member {Real} num_open_public_connections
 * @member {Real} settings_count
 * @struct_end 
 */

/**
 * @struct_partial EpicActiveSessionInfo
 * @member {String} session_name
 * @member {String} local_user_id
 * @member {String} session_id
 * @member {String} bucket_id
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionsSessionInviteReceivedCallbackInfo
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @member {String} invite_id
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionsSessionInviteAcceptedCallbackInfo
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @member {String} invite_id
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionsJoinSessionAcceptedCallbackInfo
 * @member {Real} ui_event_id
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionDetailsAttribute
 * @member {String} key
 * @member {String} value
 * @member {Enum.EpicAttributeType} value_type
 * @member {Enum.EpicSessionAttributeAdvertisementType} advertisement_type
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionsSendInviteCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionsRejectInviteCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionsQueryInvitesCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionsSessionInviteRejectedCallbackInfo
 * @member {String} invite_id
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @member {String} session_id
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionsLeaveSessionRequestedCallbackInfo
 * @member {String} local_user_id
 * @member {String} session_name
 * @struct_end 
 */

/**
 * @struct_partial EpicSessionsSendSessionNativeInviteRequestedCallbackInfo
 * @member {Real} ui_event_id
 * @member {String} local_user_id
 * @member {String} session_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyCreateLobbyCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} lobby_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyDestroyLobbyCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} lobby_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyJoinLobbyCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} lobby_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyLeaveLobbyCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} lobby_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyUpdateLobbyCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} lobby_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyPromoteMemberCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} lobby_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyKickMemberCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} lobby_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbySearchFindCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyDetailsInfo
 * @member {String} lobby_id
 * @member {String} bucket_id
 * @member {String} lobby_owner_user_id
 * @member {Real} available_slots
 * @member {Real} max_members
 * @member {Enum.EpicLobbyPermissionLevel} permission_level
 * @member {Bool} allow_invites
 * @member {Bool} presence_enabled
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyLobbyUpdateReceivedCallbackInfo
 * @member {String} lobby_id
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyLobbyMemberUpdateReceivedCallbackInfo
 * @member {String} lobby_id
 * @member {String} target_user_id
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyLobbyMemberStatusReceivedCallbackInfo
 * @member {String} lobby_id
 * @member {String} target_user_id
 * @member {String} local_user_id
 * @member {Enum.EpicLobbyMemberStatus} current_status
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyJoinLobbyAcceptedCallbackInfo
 * @member {Real} ui_event_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyLeaveLobbyRequestedCallbackInfo
 * @member {String} lobby_id
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbySendLobbyNativeInviteRequestedCallbackInfo
 * @member {String} lobby_id
 * @member {String} local_user_id
 * @member {String} target_native_account_type
 * @member {String} target_user_native_account_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyDetailsAttribute
 * @member {String} key
 * @member {String} value
 * @member {Enum.EpicAttributeType} value_type
 * @member {Enum.EpicLobbyAttributeVisibility} visibility
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyDetailsMemberInfo
 * @member {String} user_id
 * @member {Real} platform
 * @member {Bool} allows_crossplay
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyJoinLobbyByIdCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} lobby_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyHardMuteMemberCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} lobby_id
 * @member {String} target_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbySendInviteCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} lobby_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyRejectInviteCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} invite_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyQueryInvitesCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyLobbyInviteReceivedCallbackInfo
 * @member {String} invite_id
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyLobbyInviteAcceptedCallbackInfo
 * @member {String} invite_id
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @member {String} lobby_id
 * @struct_end 
 */

/**
 * @struct_partial EpicLobbyLobbyInviteRejectedCallbackInfo
 * @member {String} invite_id
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @member {String} lobby_id
 * @struct_end 
 */

/**
 * @struct_partial EpicP2PReceivedPacket
 * @member {String} peer_id
 * @member {String} socket_name
 * @member {Real} channel
 * @member {Bool} ok
 * @member {Real} bytes_written
 * @struct_end 
 */

/**
 * @struct_partial EpicP2PQueryNATTypeCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {Enum.EpicNATType} nat_type
 * @struct_end 
 */

/**
 * @struct_partial EpicP2PConnectionRequestCallbackInfo
 * @member {String} local_user_id
 * @member {String} remote_user_id
 * @member {String} socket_name
 * @struct_end 
 */

/**
 * @struct_partial EpicP2PConnectionEstablishedCallbackInfo
 * @member {String} local_user_id
 * @member {String} remote_user_id
 * @member {String} socket_name
 * @member {Enum.EpicConnectionEstablishedType} connection_type
 * @member {Enum.EpicNetworkConnectionType} network_type
 * @struct_end 
 */

/**
 * @struct_partial EpicP2PConnectionInterruptedCallbackInfo
 * @member {String} local_user_id
 * @member {String} remote_user_id
 * @member {String} socket_name
 * @struct_end 
 */

/**
 * @struct_partial EpicP2PConnectionClosedCallbackInfo
 * @member {String} local_user_id
 * @member {String} remote_user_id
 * @member {String} socket_name
 * @member {Enum.EpicConnectionClosedReason} reason
 * @struct_end 
 */

/**
 * @struct_partial EpicP2PPacketQueueInfo
 * @member {Real} incoming_packet_queue_max_size_bytes
 * @member {Real} incoming_packet_queue_current_size_bytes
 * @member {Real} incoming_packet_queue_current_packet_count
 * @member {Real} outgoing_packet_queue_max_size_bytes
 * @member {Real} outgoing_packet_queue_current_size_bytes
 * @member {Real} outgoing_packet_queue_current_packet_count
 * @struct_end 
 */

/**
 * @struct_partial EpicP2PPortRange
 * @member {Real} port
 * @member {Real} num_additional_ports_to_try
 * @struct_end 
 */

/**
 * @struct_partial EpicP2PIncomingPacketQueueFullCallbackInfo
 * @member {Real} packet_queue_max_size_bytes
 * @member {Real} packet_queue_current_size_bytes
 * @member {String} overflow_packet_local_user_id
 * @member {Real} overflow_packet_channel
 * @member {Real} overflow_packet_size_bytes
 * @struct_end 
 */

/**
 * @struct_partial EpicPlayerDataStorageFileMetadata
 * @member {Real} file_size_bytes
 * @member {String} md5_hash
 * @member {String} filename
 * @member {Real} last_modified_time
 * @member {Real} unencrypted_data_size_bytes
 * @struct_end 
 */

/**
 * @struct_partial EpicPlayerDataStorageQueryFileCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicPlayerDataStorageQueryFileListCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {Real} file_count
 * @struct_end 
 */

/**
 * @struct_partial EpicPlayerDataStorageDuplicateFileCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicPlayerDataStorageDeleteFileCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicPlayerDataStorageReadFileCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} filename
 * @member {String} data
 * @struct_end 
 */

/**
 * @struct_partial EpicPlayerDataStorageWriteFileCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} filename
 * @struct_end 
 */

/**
 * @struct_partial EpicPlayerDataStorageDeleteCacheCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicTitleStorageFileMetadata
 * @member {Real} file_size_bytes
 * @member {String} md5_hash
 * @member {String} filename
 * @member {Real} unencrypted_data_size_bytes
 * @struct_end 
 */

/**
 * @struct_partial EpicTitleStorageQueryFileCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicTitleStorageQueryFileListCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {Real} file_count
 * @struct_end 
 */

/**
 * @struct_partial EpicTitleStorageReadFileCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} filename
 * @member {String} data
 * @struct_end 
 */

/**
 * @struct_partial EpicTitleStorageDeleteCacheCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicEcomEntitlement
 * @member {String} entitlement_name
 * @member {String} entitlement_id
 * @member {String} catalog_item_id
 * @member {Real} server_index
 * @member {Real} redeemed
 * @member {Real} end_timestamp
 * @struct_end 
 */

/**
 * @struct_partial EpicEcomItemOwnership
 * @member {String} id
 * @member {Enum.EpicOwnershipStatus} ownership_status
 * @struct_end 
 */

/**
 * @struct_partial EpicEcomSandboxIdItemOwnership
 * @member {String} sandbox_id
 * @member {String} owned_catalog_item_ids
 * @struct_end 
 */

/**
 * @struct_partial EpicEcomCatalogOffer
 * @member {Real} server_index
 * @member {String} catalog_namespace
 * @member {String} id
 * @member {String} title_text
 * @member {String} description_text
 * @member {String} long_description_text
 * @member {String} currency_code
 * @member {Enum.EpicResult} price_result
 * @member {Real} discount_percentage
 * @member {Real} expiration_timestamp
 * @member {Real} purchase_limit
 * @member {Real} available_for_purchase
 * @member {Real} original_price64
 * @member {Real} current_price64
 * @member {Real} decimal_point
 * @member {Real} release_date_timestamp
 * @member {Real} effective_date_timestamp
 * @struct_end 
 */

/**
 * @struct_partial EpicEcomCatalogItem
 * @member {String} catalog_namespace
 * @member {String} id
 * @member {String} entitlement_name
 * @member {String} title_text
 * @member {String} description_text
 * @member {String} long_description_text
 * @member {String} technical_details_text
 * @member {String} developer_text
 * @member {Enum.EpicEcomItemType} item_type
 * @member {Real} entitlement_end_timestamp
 * @struct_end 
 */

/**
 * @struct_partial EpicEcomKeyImageInfo
 * @member {String} type
 * @member {String} url
 * @member {Real} width
 * @member {Real} height
 * @struct_end 
 */

/**
 * @struct_partial EpicEcomCatalogRelease
 * @member {String} compatible_app_ids
 * @member {String} compatible_platforms
 * @member {String} release_note
 * @struct_end 
 */

/**
 * @struct_partial EpicEcomQueryOwnershipCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {Real} item_ownership_count
 * @struct_end 
 */

/**
 * @struct_partial EpicEcomQueryOwnershipBySandboxIdsCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {Real} sandbox_ownership_count
 * @struct_end 
 */

/**
 * @struct_partial EpicEcomQueryOwnershipTokenCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} ownership_token
 * @struct_end 
 */

/**
 * @struct_partial EpicEcomQueryEntitlementsCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicEcomQueryEntitlementTokenCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} entitlement_token
 * @struct_end 
 */

/**
 * @struct_partial EpicEcomQueryOffersCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicEcomCheckoutCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} transaction_id
 * @struct_end 
 */

/**
 * @struct_partial EpicEcomRedeemEntitlementsCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {Real} redeemed_count
 * @struct_end 
 */

/**
 * @struct_partial EpicCustomInvitesSendCustomInviteCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicCustomInvitesCustomInviteReceivedCallbackInfo
 * @member {String} target_user_id
 * @member {String} local_user_id
 * @member {String} custom_invite_id
 * @member {String} payload
 * @struct_end 
 */

/**
 * @struct_partial EpicCustomInvitesCustomInviteAcceptedCallbackInfo
 * @member {String} target_user_id
 * @member {String} local_user_id
 * @member {String} custom_invite_id
 * @member {String} payload
 * @struct_end 
 */

/**
 * @struct_partial EpicCustomInvitesCustomInviteRejectedCallbackInfo
 * @member {String} target_user_id
 * @member {String} local_user_id
 * @member {String} custom_invite_id
 * @member {String} payload
 * @struct_end 
 */

/**
 * @struct_partial EpicCustomInvitesSendRequestToJoinCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicCustomInvitesRequestToJoinResponseReceivedCallbackInfo
 * @member {String} from_user_id
 * @member {String} to_user_id
 * @member {Enum.EpicRequestToJoinResponse} response
 * @struct_end 
 */

/**
 * @struct_partial EpicCustomInvitesRequestToJoinReceivedCallbackInfo
 * @member {String} from_user_id
 * @member {String} to_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicCustomInvitesAcceptRequestToJoinCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicCustomInvitesRejectRequestToJoinCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} target_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicCustomInvitesSendCustomNativeInviteRequestedCallbackInfo
 * @member {Real} ui_event_id
 * @member {String} local_user_id
 * @member {String} target_native_account_type
 * @member {String} target_user_native_account_id
 * @member {String} invite_id
 * @struct_end 
 */

/**
 * @struct_partial EpicCustomInvitesRequestToJoinAcceptedCallbackInfo
 * @member {String} target_user_id
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicCustomInvitesRequestToJoinRejectedCallbackInfo
 * @member {String} target_user_id
 * @member {String} local_user_id
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCJoinRoomCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCLeaveRoomCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCBlockParticipantCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {String} participant_id
 * @member {Bool} blocked
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCDisconnectedCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCParticipantStatusChangedCallbackInfo
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {String} participant_id
 * @member {Enum.EpicRTCParticipantStatus} participant_status
 * @member {Bool} participant_in_blocklist
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCRoomStatisticsUpdatedInfo
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {String} statistic
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCAudioParticipantUpdatedCallbackInfo
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {String} participant_id
 * @member {Bool} speaking
 * @member {Enum.EpicRTCAudioStatus} audio_status
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCAudioDevicesChangedCallbackInfo
 * @member {Bool} triggered
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCAudioInputStateCallbackInfo
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {Enum.EpicRTCAudioInputStatus} status
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCAudioOutputStateCallbackInfo
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {Enum.EpicRTCAudioOutputStatus} status
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCAudioUpdateSendingCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {Enum.EpicRTCAudioStatus} audio_status
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCAudioUpdateReceivingCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {String} participant_id
 * @member {Bool} audio_enabled
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCAudioUpdateSendingVolumeCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {Real} volume
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCAudioUpdateReceivingVolumeCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {Real} volume
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCAudioUpdateParticipantVolumeCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} local_user_id
 * @member {String} room_name
 * @member {String} participant_id
 * @member {Real} volume
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCAudioInputDeviceInfo
 * @member {Bool} default_device
 * @member {String} device_id
 * @member {String} device_name
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCAudioOutputDeviceInfo
 * @member {Bool} default_device
 * @member {String} device_id
 * @member {String} device_name
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCAudioSetInputDeviceSettingsCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} real_device_id
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCAudioSetOutputDeviceSettingsCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @member {String} real_device_id
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCAudioQueryInputDevicesCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @struct_partial EpicRTCAudioQueryOutputDevicesCallbackInfo
 * @member {Enum.EpicResult} result_code
 * @struct_end 
 */

/**
 * @enum_partial EpicResult
 * @member Success
 * @member NoConnection
 * @member InvalidCredentials
 * @member InvalidUser
 * @member InvalidAuth
 * @member AccessDenied
 * @member MissingPermissions
 * @member Token_Not_Account
 * @member TooManyRequests
 * @member AlreadyPending
 * @member InvalidParameters
 * @member InvalidRequest
 * @member UnrecognizedResponse
 * @member IncompatibleVersion
 * @member NotConfigured
 * @member AlreadyConfigured
 * @member NotImplemented
 * @member Canceled
 * @member NotFound
 * @member OperationWillRetry
 * @member NoChange
 * @member VersionMismatch
 * @member LimitExceeded
 * @member Disabled
 * @member DuplicateNotAllowed
 * @member MissingParameters_DEPRECATED
 * @member InvalidSandboxId
 * @member TimedOut
 * @member PartialResult
 * @member Missing_Role
 * @member Missing_Feature
 * @member Invalid_Sandbox
 * @member Invalid_Deployment
 * @member Invalid_Product
 * @member Invalid_ProductUserID
 * @member ServiceFailure
 * @member CacheDirectoryMissing
 * @member CacheDirectoryInvalid
 * @member InvalidState
 * @member RequestInProgress
 * @member ApplicationSuspended
 * @member NetworkDisconnected
 * @member Auth_AccountLocked
 * @member Auth_AccountLockedForUpdate
 * @member Auth_InvalidRefreshToken
 * @member Auth_InvalidToken
 * @member Auth_AuthenticationFailure
 * @member Auth_InvalidPlatformToken
 * @member Auth_WrongAccount
 * @member Auth_WrongClient
 * @member Auth_FullAccountRequired
 * @member Auth_HeadlessAccountRequired
 * @member Auth_PasswordResetRequired
 * @member Auth_PasswordCannotBeReused
 * @member Auth_Expired
 * @member Auth_ScopeConsentRequired
 * @member Auth_ApplicationNotFound
 * @member Auth_ScopeNotFound
 * @member Auth_AccountFeatureRestricted
 * @member Auth_AccountPortalLoadError
 * @member Auth_CorrectiveActionRequired
 * @member Auth_PinGrantCode
 * @member Auth_PinGrantExpired
 * @member Auth_PinGrantPending
 * @member Auth_ExternalAuthNotLinked
 * @member Auth_ExternalAuthRevoked
 * @member Auth_ExternalAuthInvalid
 * @member Auth_ExternalAuthRestricted
 * @member Auth_ExternalAuthCannotLogin
 * @member Auth_ExternalAuthExpired
 * @member Auth_ExternalAuthIsLastLoginType
 * @member Auth_ExchangeCodeNotFound
 * @member Auth_OriginatingExchangeCodeSessionExpired
 * @member Auth_AccountNotActive
 * @member Auth_MFARequired
 * @member Auth_ParentalControls
 * @member Auth_NoRealId
 * @member Auth_UserInterfaceRequired
 * @member Friends_InviteAwaitingAcceptance
 * @member Friends_NoInvitation
 * @member Friends_AlreadyFriends
 * @member Friends_NotFriends
 * @member Friends_TargetUserTooManyInvites
 * @member Friends_LocalUserTooManyInvites
 * @member Friends_TargetUserFriendLimitExceeded
 * @member Friends_LocalUserFriendLimitExceeded
 * @member Presence_DataInvalid
 * @member Presence_DataLengthInvalid
 * @member Presence_DataKeyInvalid
 * @member Presence_DataKeyLengthInvalid
 * @member Presence_DataValueInvalid
 * @member Presence_DataValueLengthInvalid
 * @member Presence_RichTextInvalid
 * @member Presence_RichTextLengthInvalid
 * @member Presence_StatusInvalid
 * @member Ecom_EntitlementStale
 * @member Ecom_CatalogOfferStale
 * @member Ecom_CatalogItemStale
 * @member Ecom_CatalogOfferPriceInvalid
 * @member Ecom_CheckoutLoadError
 * @member Ecom_PurchaseProcessing
 * @member Sessions_SessionInProgress
 * @member Sessions_TooManyPlayers
 * @member Sessions_NoPermission
 * @member Sessions_SessionAlreadyExists
 * @member Sessions_InvalidLock
 * @member Sessions_InvalidSession
 * @member Sessions_SandboxNotAllowed
 * @member Sessions_InviteFailed
 * @member Sessions_InviteNotFound
 * @member Sessions_UpsertNotAllowed
 * @member Sessions_AggregationFailed
 * @member Sessions_HostAtCapacity
 * @member Sessions_SandboxAtCapacity
 * @member Sessions_SessionNotAnonymous
 * @member Sessions_OutOfSync
 * @member Sessions_TooManyInvites
 * @member Sessions_PresenceSessionExists
 * @member Sessions_DeploymentAtCapacity
 * @member Sessions_NotAllowed
 * @member Sessions_PlayerSanctioned
 * @member PlayerDataStorage_FilenameInvalid
 * @member PlayerDataStorage_FilenameLengthInvalid
 * @member PlayerDataStorage_FilenameInvalidChars
 * @member PlayerDataStorage_FileSizeTooLarge
 * @member PlayerDataStorage_FileSizeInvalid
 * @member PlayerDataStorage_FileHandleInvalid
 * @member PlayerDataStorage_DataInvalid
 * @member PlayerDataStorage_DataLengthInvalid
 * @member PlayerDataStorage_StartIndexInvalid
 * @member PlayerDataStorage_RequestInProgress
 * @member PlayerDataStorage_UserThrottled
 * @member PlayerDataStorage_EncryptionKeyNotSet
 * @member PlayerDataStorage_UserErrorFromDataCallback
 * @member PlayerDataStorage_FileHeaderHasNewerVersion
 * @member PlayerDataStorage_FileCorrupted
 * @member Connect_ExternalTokenValidationFailed
 * @member Connect_UserAlreadyExists
 * @member Connect_AuthExpired
 * @member Connect_InvalidToken
 * @member Connect_UnsupportedTokenType
 * @member Connect_LinkAccountFailed
 * @member Connect_ExternalServiceUnavailable
 * @member Connect_ExternalServiceConfigurationFailure
 * @member Connect_LinkAccountFailedMissingNintendoIdAccount_DEPRECATED
 * @member UI_SocialOverlayLoadError
 * @member UI_InconsistentVirtualMemoryFunctions
 * @member Lobby_NotOwner
 * @member Lobby_InvalidLock
 * @member Lobby_LobbyAlreadyExists
 * @member Lobby_SessionInProgress
 * @member Lobby_TooManyPlayers
 * @member Lobby_NoPermission
 * @member Lobby_InvalidSession
 * @member Lobby_SandboxNotAllowed
 * @member Lobby_InviteFailed
 * @member Lobby_InviteNotFound
 * @member Lobby_UpsertNotAllowed
 * @member Lobby_AggregationFailed
 * @member Lobby_HostAtCapacity
 * @member Lobby_SandboxAtCapacity
 * @member Lobby_TooManyInvites
 * @member Lobby_DeploymentAtCapacity
 * @member Lobby_NotAllowed
 * @member Lobby_MemberUpdateOnly
 * @member Lobby_PresenceLobbyExists
 * @member Lobby_VoiceNotEnabled
 * @member Lobby_PlatformNotAllowed
 * @member UnexpectedError
 * @enum_end 
 */

/**
 * @enum_partial EpicAntiCheatClientMode
 * @member Invalid
 * @member ClientServer
 * @member PeerToPeer
 * @enum_end 
 */

/**
 * @enum_partial EpicAntiCheatClientViolationType
 * @member Invalid
 * @member IntegrityCatalogNotFound
 * @member IntegrityCatalogError
 * @member IntegrityCatalogCertificateRevoked
 * @member IntegrityCatalogMissingMainExecutable
 * @member GameFileMismatch
 * @member RequiredGameFileNotFound
 * @member UnknownGameFileForbidden
 * @member SystemFileUntrusted
 * @member ForbiddenModuleLoaded
 * @member CorruptedMemory
 * @member ForbiddenToolDetected
 * @member InternalAntiCheatViolation
 * @member CorruptedNetworkMessageFlow
 * @member VirtualMachineNotAllowed
 * @member ForbiddenSystemConfiguration
 * @enum_end 
 */

/**
 * @enum_partial EpicAntiCheatCommonClientType
 * @member ProtectedClient
 * @member UnprotectedClient
 * @member AIBot
 * @enum_end 
 */

/**
 * @enum_partial EpicAntiCheatCommonClientPlatform
 * @member Unknown
 * @member Windows
 * @member Mac
 * @member Linux
 * @member Xbox
 * @member PlayStation
 * @member Nintendo
 * @member IOS
 * @member Android
 * @enum_end 
 */

/**
 * @enum_partial EpicAntiCheatCommonClientAction
 * @member Invalid
 * @member RemovePlayer
 * @enum_end 
 */

/**
 * @enum_partial EpicAntiCheatCommonClientActionReason
 * @member Invalid
 * @member InternalError
 * @member InvalidMessage
 * @member AuthenticationFailed
 * @member NullClient
 * @member HeartbeatTimeout
 * @member ClientViolation
 * @member BackendViolation
 * @member TemporaryCooldown
 * @member TemporaryBanned
 * @member PermanentBanned
 * @enum_end 
 */

/**
 * @enum_partial EpicAntiCheatCommonClientAuthStatus
 * @member Invalid
 * @member LocalAuthComplete
 * @member RemoteAuthComplete
 * @enum_end 
 */

/**
 * @enum_partial EpicAntiCheatCommonClientFlags
 * @member None
 * @enum_end 
 */

/**
 * @enum_partial EpicAntiCheatCommonClientInput
 * @member Unknown
 * @member MouseKeyboard
 * @member Gamepad
 * @member TouchInput
 * @enum_end 
 */

/**
 * @enum_partial EpicAntiCheatCommonEventType
 * @member Invalid
 * @member GameEvent
 * @member PlayerEvent
 * @enum_end 
 */

/**
 * @enum_partial EpicAntiCheatCommonEventParamType
 * @member Invalid
 * @member ClientHandle
 * @member String
 * @member UInt32
 * @member Int32
 * @member UInt64
 * @member Int64
 * @member Vector3f
 * @member Quat
 * @member Float
 * @enum_end 
 */

/**
 * @enum_partial EpicAntiCheatCommonGameRoundCompetitionType
 * @member None
 * @member Casual
 * @member Ranked
 * @member Competitive
 * @enum_end 
 */

/**
 * @enum_partial EpicAntiCheatCommonPlayerMovementState
 * @member None
 * @member Crouching
 * @member Prone
 * @member Mounted
 * @member Swimming
 * @member Falling
 * @member Flying
 * @member OnLadder
 * @enum_end 
 */

/**
 * @enum_partial EpicAntiCheatCommonPlayerTakeDamageSource
 * @member None
 * @member Player
 * @member NonPlayerCharacter
 * @member World
 * @enum_end 
 */

/**
 * @enum_partial EpicAntiCheatCommonPlayerTakeDamageType
 * @member None
 * @member PointDamage
 * @member RadialDamage
 * @member DamageOverTime
 * @enum_end 
 */

/**
 * @enum_partial EpicAntiCheatCommonPlayerTakeDamageResult
 * @member None
 * @member DownedDeprecated
 * @member EliminatedDeprecated
 * @member NormalToDowned
 * @member NormalToEliminated
 * @member DownedToEliminated
 * @enum_end 
 */

/**
 * @enum_partial EpicLoginCredentialType
 * @member Password
 * @member ExchangeCode
 * @member PersistentAuth
 * @member DeviceCode
 * @member Developer
 * @member RefreshToken
 * @member AccountPortal
 * @member ExternalAuth
 * @enum_end 
 */

/**
 * @enum_partial EpicAuthTokenType
 * @member Client
 * @member User
 * @enum_end 
 */

/**
 * @enum_partial EpicAuthScopeFlags
 * @member NoFlags
 * @member BasicProfile
 * @member FriendsList
 * @member Presence
 * @member FriendsManagement
 * @member Email
 * @member Country
 * @enum_end 
 */

/**
 * @enum_partial EpicLinkAccountFlags
 * @member NoFlags
 * @member NintendoNsaId
 * @enum_end 
 */

/**
 * @enum_partial Epicname
 * @enum_end 
 */

/**
 * @enum_partial EpicLoginStatus
 * @member NotLoggedIn
 * @member UsingLocalProfile
 * @member LoggedIn
 * @enum_end 
 */

/**
 * @enum_partial EpicAttributeType
 * @member Boolean
 * @member Int64
 * @member Double
 * @member String
 * @enum_end 
 */

/**
 * @enum_partial EpicComparisonOp
 * @member Equal
 * @member NotEqual
 * @member GreaterThan
 * @member GreaterThanOrEqual
 * @member LessThan
 * @member LessThanOrEqual
 * @member Distance
 * @member AnyOf
 * @member NotAnyOf
 * @member OneOf
 * @member NotOneOf
 * @member Contains
 * @enum_end 
 */

/**
 * @enum_partial EpicExternalAccountType
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
 * @enum_end 
 */

/**
 * @enum_partial EpicExternalCredentialType
 * @member Epic
 * @member SteamAppTicket
 * @member PsnIdToken
 * @member XblXstsToken
 * @member DiscordAccessToken
 * @member GogSessionTicket
 * @member NintendoIdToken
 * @member NintendoNsaIdToken
 * @member UplayAccessToken
 * @member OpenIdAccessToken
 * @member DeviceIdAccessToken
 * @member AppleIdToken
 * @member GoogleIdToken
 * @member OculusUseridNonce
 * @member ItchIoJwt
 * @member ItchIoKey
 * @member EpicIdToken
 * @member AmazonAccessToken
 * @member SteamSessionTicket
 * @member ViveportUserToken
 * @enum_end 
 */

/**
 * @enum_partial EpicRequestToJoinResponse
 * @member Accepted
 * @member Rejected
 * @enum_end 
 */

/**
 * @enum_partial EpicOwnershipStatus
 * @member NotOwned
 * @member Owned
 * @enum_end 
 */

/**
 * @enum_partial EpicEcomItemType
 * @member Durable
 * @member Consumable
 * @member Other
 * @enum_end 
 */

/**
 * @enum_partial EpicCheckoutOrientation
 * @member Default
 * @member Portrait
 * @member Landscape
 * @enum_end 
 */

/**
 * @enum_partial EpicFriendsStatus
 * @member NotFriends
 * @member InviteSent
 * @member InviteReceived
 * @member Friends
 * @enum_end 
 */

/**
 * @enum_partial EpicIntegratedPlatformManagementFlags
 * @member Disabled
 * @member LibraryManagedByApplication
 * @member LibraryManagedBySDK
 * @member DisablePresenceMirroring
 * @member DisableSDKManagedSessions
 * @member PreferEOSIdentity
 * @member PreferIntegratedIdentity
 * @member ApplicationManagedIdentityLogin
 * @enum_end 
 */

/**
 * @enum_partial EpicIntegratedPlatformPreLogoutAction
 * @member ProcessLogoutImmediately
 * @member DeferLogout
 * @enum_end 
 */

/**
 * @enum_partial EpicKWSPermissionStatus
 * @member Granted
 * @member Rejected
 * @member Pending
 * @enum_end 
 */

/**
 * @enum_partial EpicLeaderboardAggregation
 * @member Min
 * @member Max
 * @member Sum
 * @member Latest
 * @enum_end 
 */

/**
 * @enum_partial EpicLobbyPermissionLevel
 * @member PublicAdvertised
 * @member JoinViaPresence
 * @member InviteOnly
 * @enum_end 
 */

/**
 * @enum_partial EpicLobbyAttributeVisibility
 * @member Public
 * @member Private
 * @enum_end 
 */

/**
 * @enum_partial EpicLobbyMemberStatus
 * @member Joined
 * @member Left
 * @member Disconnected
 * @member Kicked
 * @member Promoted
 * @member Closed
 * @enum_end 
 */

/**
 * @enum_partial EpicLobbyRTCRoomJoinActionType
 * @member AutomaticJoin
 * @member ManualJoin
 * @enum_end 
 */

/**
 * @enum_partial EpicLogLevel
 * @member Off
 * @member Fatal
 * @member Error
 * @member Warning
 * @member Info
 * @member Verbose
 * @member VeryVerbose
 * @enum_end 
 */

/**
 * @enum_partial EpicLogCategory
 * @member Core
 * @member Auth
 * @member Friends
 * @member Presence
 * @member UserInfo
 * @member HttpSerialization
 * @member Ecom
 * @member P2P
 * @member Sessions
 * @member RateLimiter
 * @member PlayerDataStorage
 * @member Analytics
 * @member Messaging
 * @member Connect
 * @member Overlay
 * @member Achievements
 * @member Stats
 * @member UI
 * @member Lobby
 * @member Leaderboards
 * @member Keychain
 * @member IntegratedPlatform
 * @member TitleStorage
 * @member Mods
 * @member AntiCheat
 * @member Reports
 * @member Sanctions
 * @member ProgressionSnapshots
 * @member KWS
 * @member RTC
 * @member RTCAdmin
 * @member CustomInvites
 * @member AllCategories
 * @enum_end 
 */

/**
 * @enum_partial EpicUserControllerType
 * @member Unknown
 * @member MouseKeyboard
 * @member GamepadControl
 * @member TouchControl
 * @enum_end 
 */

/**
 * @enum_partial EpicMetricsAccountIdType
 * @member Epic
 * @member External
 * @enum_end 
 */

/**
 * @enum_partial EpicModEnumerationType
 * @member Installed
 * @member AllAvailable
 * @enum_end 
 */

/**
 * @enum_partial EpicNATType
 * @member Unknown
 * @member Open
 * @member Moderate
 * @member Strict
 * @enum_end 
 */

/**
 * @enum_partial EpicPacketReliability
 * @member UnreliableUnordered
 * @member ReliableUnordered
 * @member ReliableOrdered
 * @enum_end 
 */

/**
 * @enum_partial EpicConnectionEstablishedType
 * @member NewConnection
 * @member Reconnection
 * @enum_end 
 */

/**
 * @enum_partial EpicNetworkConnectionType
 * @member NoConnection
 * @member DirectConnection
 * @member RelayedConnection
 * @enum_end 
 */

/**
 * @enum_partial EpicConnectionClosedReason
 * @member Unknown
 * @member ClosedByLocalUser
 * @member ClosedByPeer
 * @member TimedOut
 * @member TooManyConnections
 * @member InvalidMessage
 * @member InvalidData
 * @member ConnectionFailed
 * @member ConnectionClosed
 * @member NegotiationFailed
 * @member UnexpectedError
 * @member ConnectionIgnored
 * @enum_end 
 */

/**
 * @enum_partial EpicRelayControl
 * @member NoRelays
 * @member AllowRelays
 * @member ForceRelays
 * @enum_end 
 */

/**
 * @enum_partial EpicPlayerDataStorageReadResult
 * @member ContinueReading
 * @member FailRequest
 * @member CancelRequest
 * @enum_end 
 */

/**
 * @enum_partial EpicPlayerDataStorageWriteResult
 * @member ContinueWriting
 * @member CompleteRequest
 * @member FailRequest
 * @member CancelRequest
 * @enum_end 
 */

/**
 * @enum_partial EpicPresenceStatus
 * @member Offline
 * @member Online
 * @member Away
 * @member ExtendedAway
 * @member DoNotDisturb
 * @enum_end 
 */

/**
 * @enum_partial EpicPlayerReportsCategory
 * @member Invalid
 * @member Cheating
 * @member Exploiting
 * @member OffensiveProfile
 * @member VerbalAbuse
 * @member Scamming
 * @member Spamming
 * @member Other
 * @enum_end 
 */

/**
 * @enum_partial EpicRTCAudioStatus
 * @member Unsupported
 * @member Enabled
 * @member Disabled
 * @member AdminDisabled
 * @member NotListeningDisabled
 * @enum_end 
 */

/**
 * @enum_partial EpicRTCAudioInputStatus
 * @member Idle
 * @member Recording
 * @member RecordingSilent
 * @member RecordingDisconnected
 * @member Failed
 * @enum_end 
 */

/**
 * @enum_partial EpicRTCAudioOutputStatus
 * @member Idle
 * @member Playing
 * @member Failed
 * @enum_end 
 */

/**
 * @enum_partial EpicRTCDataStatus
 * @member Unsupported
 * @member Enabled
 * @member Disabled
 * @enum_end 
 */

/**
 * @enum_partial EpicRTCParticipantStatus
 * @member Joined
 * @member Left
 * @enum_end 
 */

/**
 * @enum_partial EpicSanctionAppealReason
 * @member Invalid
 * @member IncorrectSanction
 * @member CompromisedAccount
 * @member UnfairPunishment
 * @member AppealForForgiveness
 * @enum_end 
 */

/**
 * @enum_partial EpicOnlineSessionState
 * @member NoSession
 * @member Creating
 * @member Pending
 * @member Starting
 * @member InProgress
 * @member Ending
 * @member Ended
 * @member Destroying
 * @enum_end 
 */

/**
 * @enum_partial EpicSessionAttributeAdvertisementType
 * @member DontAdvertise
 * @member Advertise
 * @enum_end 
 */

/**
 * @enum_partial EpicOnlineSessionPermissionLevel
 * @member PublicAdvertised
 * @member JoinViaPresence
 * @member InviteOnly
 * @enum_end 
 */

/**
 * @enum_partial EpicTitleStorageReadResult
 * @member ContinueReading
 * @member FailRequest
 * @member CancelRequest
 * @enum_end 
 */

/**
 * @enum_partial EpicRTCBackgroundMode
 * @member LeaveRooms
 * @member KeepRoomsAlive
 * @enum_end 
 */

/**
 * @enum_partial EpicApplicationStatus
 * @member BackgroundConstrained
 * @member BackgroundUnconstrained
 * @member BackgroundSuspended
 * @member Foreground
 * @enum_end 
 */

/**
 * @enum_partial EpicNetworkStatus
 * @member Disabled
 * @member Offline
 * @member Online
 * @enum_end 
 */

/**
 * @enum_partial EpicDesktopCrossplayStatus
 * @member Ok
 * @member ApplicationNotBootstrapped
 * @member ServiceNotInstalled
 * @member ServiceStartFailed
 * @member ServiceNotRunning
 * @member OverlayDisabled
 * @member OverlayNotInstalled
 * @member OverlayTrustCheckFailed
 * @member OverlayLoadFailed
 * @enum_end 
 */

/**
 * @enum_partial EpicUINotificationLocation
 * @member TopLeft
 * @member TopRight
 * @member BottomLeft
 * @member BottomRight
 * @enum_end 
 */

/**
 * @const_partial macros
 * @const_end 
 */

