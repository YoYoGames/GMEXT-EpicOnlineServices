package ${YYAndroidPackageName};
import static com.gamemaker.ExtensionCore.ExtBridge.EpicOnlineServicesBridge.*;
import java.lang.String;
import java.nio.ByteBuffer;

public class EpicOnlineServicesInternal extends RunnerSocial {
    public double __EXT_NATIVE__EpicOnlineServices_invocation_handler(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__EpicOnlineServices_invocation_handler(__ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_test()
    {
        return __EXT_JNI__eos_test();
    }
    public String __EXT_NATIVE__eos_api_last_error()
    {
        return __EXT_JNI__eos_api_last_error();
    }
    public double __EXT_NATIVE__eos_api_is_initialized()
    {
        return __EXT_JNI__eos_api_is_initialized();
    }
    public double __EXT_NATIVE__eos_api_initialize(String product_name, String product_version, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_api_initialize(product_name, product_version, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_api_shutdown(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_api_shutdown(__ret_buffer, __ret_buffer_length);
    }
    public String __EXT_NATIVE__eos_api_get_version()
    {
        return __EXT_JNI__eos_api_get_version();
    }
    public String __EXT_NATIVE__eos_api_result_to_string(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_api_result_to_string(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_api_result_is_operation_complete(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_api_result_is_operation_complete(__arg_buffer, __arg_buffer_length);
    }
    public String __EXT_NATIVE__eos_api_application_status_to_string(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_api_application_status_to_string(__arg_buffer, __arg_buffer_length);
    }
    public String __EXT_NATIVE__eos_api_network_status_to_string(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_api_network_status_to_string(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_api_epic_account_id_is_valid(String account_id)
    {
        return __EXT_JNI__eos_api_epic_account_id_is_valid(account_id);
    }
    public double __EXT_NATIVE__eos_api_product_user_id_is_valid(String product_user_id)
    {
        return __EXT_JNI__eos_api_product_user_id_is_valid(product_user_id);
    }
    public double __EXT_NATIVE__eos_platform_is_created()
    {
        return __EXT_JNI__eos_platform_is_created();
    }
    public double __EXT_NATIVE__eos_platform_create(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_platform_create(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_platform_release()
    {
        return __EXT_JNI__eos_platform_release();
    }
    public double __EXT_NATIVE__eos_platform_tick()
    {
        return __EXT_JNI__eos_platform_tick();
    }
    public double __EXT_NATIVE__eos_platform_check_for_launcher_and_restart(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_platform_check_for_launcher_and_restart(__ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_platform_set_network_status(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_platform_set_network_status(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_logging_set_callback(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_logging_set_callback(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_logging_clear_callback()
    {
        return __EXT_JNI__eos_logging_clear_callback();
    }
    public double __EXT_NATIVE__eos_logging_set_log_level(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_logging_set_log_level(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_auth_login(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_auth_login(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_auth_logout(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_auth_logout(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_auth_link_account(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_auth_link_account(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_auth_delete_persistent_auth(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_auth_delete_persistent_auth(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_auth_get_logged_in_accounts_count(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_auth_get_logged_in_accounts_count(__ret_buffer, __ret_buffer_length);
    }
    public String __EXT_NATIVE__eos_auth_get_logged_in_account_by_index(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_auth_get_logged_in_account_by_index(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_auth_get_login_status(String local_user_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_auth_get_login_status(local_user_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_auth_copy_id_token(String local_user_id, String target_account_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_auth_copy_id_token(local_user_id, target_account_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_auth_copy_user_auth_token(String local_user_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_auth_copy_user_auth_token(local_user_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_auth_query_id_token(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_auth_query_id_token(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_auth_verify_id_token(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_auth_verify_id_token(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_auth_verify_user_auth(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_auth_verify_user_auth(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_auth_add_notify_login_status_changed(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_auth_add_notify_login_status_changed(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_auth_remove_notify_login_status_changed(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_auth_remove_notify_login_status_changed(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_login(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_connect_login(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_create_user(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_connect_create_user(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_link_account(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_connect_link_account(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_unlink_account(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_connect_unlink_account(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_create_device_id(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_connect_create_device_id(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_delete_device_id(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_connect_delete_device_id(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_transfer_device_id_account(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_connect_transfer_device_id_account(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_logout(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_connect_logout(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_get_logged_in_users_count(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_connect_get_logged_in_users_count(__ret_buffer, __ret_buffer_length);
    }
    public String __EXT_NATIVE__eos_connect_get_logged_in_user_by_index(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_connect_get_logged_in_user_by_index(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_get_login_status(String local_user_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_connect_get_login_status(local_user_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_copy_id_token(String local_user_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_connect_copy_id_token(local_user_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_copy_product_user_info(String target_user_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_connect_copy_product_user_info(target_user_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_copy_product_user_external_account_by_index(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_connect_copy_product_user_external_account_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_copy_product_user_external_account_by_account_type(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_connect_copy_product_user_external_account_by_account_type(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_copy_product_user_external_account_by_account_id(String target_user_id, String account_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_connect_copy_product_user_external_account_by_account_id(target_user_id, account_id, __ret_buffer, __ret_buffer_length);
    }
    public String __EXT_NATIVE__eos_connect_get_product_user_id_mapping(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_connect_get_product_user_id_mapping(__arg_buffer, __arg_buffer_length);
    }
    public String __EXT_NATIVE__eos_connect_get_external_account_mapping(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_connect_get_external_account_mapping(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_verify_id_token(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_connect_verify_id_token(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_query_external_account_mappings(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_connect_query_external_account_mappings(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_query_product_user_id_mappings(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_connect_query_product_user_id_mappings(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_add_notify_auth_expiration(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_connect_add_notify_auth_expiration(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_remove_notify_auth_expiration(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_connect_remove_notify_auth_expiration(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_add_notify_login_status_changed(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_connect_add_notify_login_status_changed(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_connect_remove_notify_login_status_changed(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_connect_remove_notify_login_status_changed(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_friends_query_friends(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_friends_query_friends(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_friends_get_friends_count(String local_user_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_friends_get_friends_count(local_user_id, __ret_buffer, __ret_buffer_length);
    }
    public String __EXT_NATIVE__eos_friends_get_friend_at_index(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_friends_get_friend_at_index(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_friends_get_status(String local_user_id, String target_user_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_friends_get_status(local_user_id, target_user_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_friends_add_notify_friends_update(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_friends_add_notify_friends_update(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_friends_remove_notify_friends_update(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_friends_remove_notify_friends_update(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_user_info_query_user_info(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_user_info_query_user_info(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_user_info_copy_user_info(String local_user_id, String target_user_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_user_info_copy_user_info(local_user_id, target_user_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_user_info_get_local_platform_type(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_user_info_get_local_platform_type(__ret_buffer, __ret_buffer_length);
    }
    public String __EXT_NATIVE__eos_user_info_copy_best_display_name(String local_user_id, String target_user_id)
    {
        return __EXT_JNI__eos_user_info_copy_best_display_name(local_user_id, target_user_id);
    }
    public double __EXT_NATIVE__eos_user_info_copy_external_user_info_by_index(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_user_info_copy_external_user_info_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_user_info_copy_external_user_info_by_account_type(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_user_info_copy_external_user_info_by_account_type(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_user_info_copy_external_user_info_by_account_id(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_user_info_copy_external_user_info_by_account_id(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_stats_ingest_stat(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_stats_ingest_stat(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_stats_query_stats(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_stats_query_stats(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_stats_get_stats_count(String target_user_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_stats_get_stats_count(target_user_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_stats_copy_stat_by_index(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_stats_copy_stat_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_stats_copy_stat_by_name(String target_user_id, String name, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_stats_copy_stat_by_name(target_user_id, name, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_ui_show_friends(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_ui_show_friends(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_ui_show_native_profile(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_ui_show_native_profile(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_ui_acknowledge_event_id(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_ui_acknowledge_event_id(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_ui_set_display_preference(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_ui_set_display_preference(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_ui_report_input_state(double button_down, double button_up, double button_left, double button_right, double button_accept, double button_cancel)
    {
        return __EXT_JNI__eos_ui_report_input_state(button_down, button_up, button_left, button_right, button_accept, button_cancel);
    }
    public double __EXT_NATIVE__eos_ui_add_notify_display_settings_updated(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_ui_add_notify_display_settings_updated(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_ui_remove_notify_display_settings_updated(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_ui_remove_notify_display_settings_updated(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_metrics_begin_player_session(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_metrics_begin_player_session(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_metrics_end_player_session(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_metrics_end_player_session(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_reports_send_player_behavior_report(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_reports_send_player_behavior_report(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_sanctions_query_active_player_sanctions(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_sanctions_query_active_player_sanctions(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_sanctions_get_player_sanction_count(String target_user_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_sanctions_get_player_sanction_count(target_user_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_sanctions_copy_player_sanction_by_index(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_sanctions_copy_player_sanction_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_sanctions_create_player_sanction_appeal(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_sanctions_create_player_sanction_appeal(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_achievements_query_definitions(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_achievements_query_definitions(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_achievements_query_player_achievements(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_achievements_query_player_achievements(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_achievements_get_achievement_definition_count(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_achievements_get_achievement_definition_count(__ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_achievements_get_player_achievement_count(String local_user_id, String target_user_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_achievements_get_player_achievement_count(local_user_id, target_user_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_achievements_copy_achievement_definition_by_index(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_achievements_copy_achievement_definition_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_achievements_copy_achievement_definition_v2_by_index(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_achievements_copy_achievement_definition_v2_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_achievements_copy_achievement_definition_by_id(String achievement_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_achievements_copy_achievement_definition_by_id(achievement_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_achievements_copy_player_achievement_by_index(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_achievements_copy_player_achievement_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_achievements_copy_player_achievement_by_id(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_achievements_copy_player_achievement_by_id(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_achievements_unlock_achievements(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_achievements_unlock_achievements(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_achievements_add_notify_achievements_unlocked_v2(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_achievements_add_notify_achievements_unlocked_v2(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_achievements_remove_notify_achievements_unlocked(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_achievements_remove_notify_achievements_unlocked(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_leaderboards_query_definitions(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_leaderboards_query_definitions(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_leaderboards_query_ranks(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_leaderboards_query_ranks(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_leaderboards_query_user_scores(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_leaderboards_query_user_scores(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_leaderboards_get_definition_count(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_leaderboards_get_definition_count(__ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_leaderboards_get_record_count(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_leaderboards_get_record_count(__ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_leaderboards_get_user_score_count(ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_leaderboards_get_user_score_count(__ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_leaderboards_copy_definition_by_index(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_leaderboards_copy_definition_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_leaderboards_copy_definition_by_id(String leaderboard_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_leaderboards_copy_definition_by_id(leaderboard_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_leaderboards_copy_record_by_index(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_leaderboards_copy_record_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_leaderboards_copy_record_by_user_id(String user_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_leaderboards_copy_record_by_user_id(user_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_leaderboards_copy_user_score_by_index(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_leaderboards_copy_user_score_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_presence_query_presence(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_presence_query_presence(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_presence_has_presence(String local_user_id, String target_user_id)
    {
        return __EXT_JNI__eos_presence_has_presence(local_user_id, target_user_id);
    }
    public double __EXT_NATIVE__eos_presence_copy_presence(String local_user_id, String target_user_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_presence_copy_presence(local_user_id, target_user_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_presence_create_presence_modification(String local_user_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_presence_create_presence_modification(local_user_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_presence_modification_release(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_presence_modification_release(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_presence_modification_set_status(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_presence_modification_set_status(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_presence_modification_set_raw_rich_text(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_presence_modification_set_raw_rich_text(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_presence_modification_set_data(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_presence_modification_set_data(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_presence_modification_delete_data(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_presence_modification_delete_data(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_presence_set_presence(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_presence_set_presence(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_presence_add_notify_on_presence_changed(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_presence_add_notify_on_presence_changed(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_presence_remove_notify_on_presence_changed(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_presence_remove_notify_on_presence_changed(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_presence_add_notify_join_game_accepted(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_presence_add_notify_join_game_accepted(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_presence_remove_notify_join_game_accepted(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_presence_remove_notify_join_game_accepted(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_create_session_modification(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_sessions_create_session_modification(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_session_modification_release(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_sessions_session_modification_release(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_update_session(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_sessions_update_session(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_destroy_session(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_sessions_destroy_session(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_start_session(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_sessions_start_session(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_end_session(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_sessions_end_session(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_join_session(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_sessions_join_session(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_register_players(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_sessions_register_players(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_unregister_players(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_sessions_unregister_players(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_create_session_search(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_sessions_create_session_search(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_session_search_release(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_sessions_session_search_release(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_session_search_set_session_id(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_sessions_session_search_set_session_id(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_session_search_set_target_user_id(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_sessions_session_search_set_target_user_id(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_session_search_find(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_sessions_session_search_find(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_session_search_copy_search_result_by_index(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_sessions_session_search_copy_search_result_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_session_details_release(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_sessions_session_details_release(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_copy_active_session_handle(String session_name, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_sessions_copy_active_session_handle(session_name, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_active_session_release(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_sessions_active_session_release(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_active_session_copy_info(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_sessions_active_session_copy_info(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_copy_session_handle_by_invite_id(String invite_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_sessions_copy_session_handle_by_invite_id(invite_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_copy_session_handle_by_ui_event_id(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_sessions_copy_session_handle_by_ui_event_id(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_session_details_copy_info(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_sessions_session_details_copy_info(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_add_notify_session_invite_received(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_sessions_add_notify_session_invite_received(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_remove_notify_session_invite_received(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_sessions_remove_notify_session_invite_received(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_add_notify_session_invite_accepted(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_sessions_add_notify_session_invite_accepted(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_remove_notify_session_invite_accepted(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_sessions_remove_notify_session_invite_accepted(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_add_notify_join_session_accepted(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_sessions_add_notify_join_session_accepted(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_sessions_remove_notify_join_session_accepted(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_sessions_remove_notify_join_session_accepted(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_create_lobby(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_create_lobby(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_destroy_lobby(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_destroy_lobby(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_join_lobby(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_join_lobby(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_leave_lobby(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_leave_lobby(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_update_lobby_modification(String lobby_id, String local_user_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_update_lobby_modification(lobby_id, local_user_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_lobby_modification_release(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_lobby_modification_release(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_update_lobby(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_update_lobby(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_lobby_modification_set_permission_level(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_lobby_modification_set_permission_level(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_lobby_modification_set_max_members(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_lobby_modification_set_max_members(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_lobby_modification_set_bucket_id(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_lobby_modification_set_bucket_id(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_lobby_modification_set_invites_allowed(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_lobby_modification_set_invites_allowed(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_lobby_modification_add_attribute(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_lobby_modification_add_attribute(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_lobby_modification_remove_attribute(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_lobby_modification_remove_attribute(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_lobby_modification_add_member_attribute(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_lobby_modification_add_member_attribute(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_lobby_modification_remove_member_attribute(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_lobby_modification_remove_member_attribute(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_promote_member(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_promote_member(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_kick_member(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_kick_member(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_create_lobby_search(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_create_lobby_search(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_lobby_search_release(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_lobby_search_release(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_lobby_search_set_lobby_id(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_lobby_search_set_lobby_id(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_lobby_search_set_target_user_id(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_lobby_search_set_target_user_id(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_lobby_search_set_parameter(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_lobby_search_set_parameter(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_lobby_search_remove_parameter(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_lobby_search_remove_parameter(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_lobby_search_set_max_results(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_lobby_search_set_max_results(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_lobby_search_find(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_lobby_search_find(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_lobby_search_get_search_result_count(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_lobby_search_get_search_result_count(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_lobby_search_copy_search_result_by_index(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_lobby_search_copy_search_result_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_details_release(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_details_release(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_copy_lobby_details_handle(String lobby_id, String local_user_id, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_copy_lobby_details_handle(lobby_id, local_user_id, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_details_copy_info(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_details_copy_info(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_details_get_member_count(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_details_get_member_count(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public String __EXT_NATIVE__eos_lobby_details_get_member_by_index(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_details_get_member_by_index(__arg_buffer, __arg_buffer_length);
    }
    public String __EXT_NATIVE__eos_lobby_details_get_lobby_owner(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_details_get_lobby_owner(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_add_notify_lobby_update_received(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_add_notify_lobby_update_received(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_remove_notify_lobby_update_received(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_remove_notify_lobby_update_received(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_add_notify_lobby_member_update_received(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_add_notify_lobby_member_update_received(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_remove_notify_lobby_member_update_received(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_remove_notify_lobby_member_update_received(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_add_notify_lobby_member_status_received(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_add_notify_lobby_member_status_received(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_remove_notify_lobby_member_status_received(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_remove_notify_lobby_member_status_received(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_add_notify_join_lobby_accepted(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_add_notify_join_lobby_accepted(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_remove_notify_join_lobby_accepted(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_remove_notify_join_lobby_accepted(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_add_notify_leave_lobby_requested(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_add_notify_leave_lobby_requested(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_remove_notify_leave_lobby_requested(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_remove_notify_leave_lobby_requested(__arg_buffer, __arg_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_add_notify_send_lobby_native_invite_requested(ByteBuffer __arg_buffer, double __arg_buffer_length, ByteBuffer __ret_buffer, double __ret_buffer_length)
    {
        return __EXT_JNI__eos_lobby_add_notify_send_lobby_native_invite_requested(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
    }
    public double __EXT_NATIVE__eos_lobby_remove_notify_send_lobby_native_invite_requested(ByteBuffer __arg_buffer, double __arg_buffer_length)
    {
        return __EXT_JNI__eos_lobby_remove_notify_send_lobby_native_invite_requested(__arg_buffer, __arg_buffer_length);
    }
}