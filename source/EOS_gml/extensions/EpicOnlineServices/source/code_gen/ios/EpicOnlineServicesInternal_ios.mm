// ##### extgen :: Auto-generated file do not edit!! #####

#import "EpicOnlineServicesInternal_ios.h"
#import "native/EpicOnlineServicesInternal_exports.h"
#import <objc/runtime.h>


extern "C" const char* extOptGetString(char* _ext, char* _opt);

// Adapter: matches const signature expected by your C++ API
static const char* ExtOptGetString(const char* ext, const char* opt)
{
    return extOptGetString(const_cast<char*>(ext), const_cast<char*>(opt));
}

static BOOL GMIsSubclassOf(Class cls, Class base)
{
    for (Class c = cls; c != Nil; c = class_getSuperclass(c)) {
        if (c == base) return YES;
    }
    return NO;
}

static void GMInjectSelectorsIntoSubclass(Class subclass, Class base)
{
    // Build set of methods already defined on subclass
    unsigned subCount = 0;
    Method *subList = class_copyMethodList(subclass, &subCount);

    CFMutableSetRef owned = CFSetCreateMutable(kCFAllocatorDefault, 0, NULL);
    for (unsigned i = 0; i < subCount; ++i) {
        CFSetAddValue(owned, method_getName(subList[i]));
    }

    // Walk base class methods
    unsigned baseCount = 0;
    Method *baseList = class_copyMethodList(base, &baseCount);

    for (unsigned i = 0; i < baseCount; ++i) {
        SEL sel = method_getName(baseList[i]);
        const char *name = sel_getName(sel);

        // Only inject your extension selectors
        if (!name || strncmp(name, "__EXT_NATIVE__", 13) != 0) continue;

        // Add only if subclass doesn't already have it
        if (!CFSetContainsValue(owned, sel)) {
            IMP imp = method_getImplementation(baseList[i]);
            const char *types = method_getTypeEncoding(baseList[i]);
            if (class_addMethod(subclass, sel, imp, types)) {
                CFSetAddValue(owned, sel);
            }
        }
    }

    if (subList) free(subList);
    if (baseList) free(baseList);
    if (owned) CFRelease(owned);
}

@implementation EpicOnlineServicesInternal

+ (void)load
{
    // Find all loaded classes
    int num = objc_getClassList(NULL, 0);
    if (num <= 0) return;

    Class *classes = (Class *)malloc(sizeof(Class) * (unsigned)num);
    num = objc_getClassList(classes, num);

    Class base = [EpicOnlineServicesInternal class];

    for (int i = 0; i < num; ++i) {
        Class cls = classes[i];
        if (cls == base) continue;

        // We only care about direct or indirect subclasses
        if (GMIsSubclassOf(cls, base)) {
            GMInjectSelectorsIntoSubclass(cls, base);
        }
    }

    free(classes);

    gm::details::GMRTRunnerInterface ri{};
    ri.ExtOptGetString = &ExtOptGetString;
    GMExtensionInitialise(&ri, sizeof(ri));
}

- (double)__EXT_NATIVE__eos_test
{
    return __EXT_NATIVE__eos_test();
}
- (char*)__EXT_NATIVE__eos_api_last_error
{
    return __EXT_NATIVE__eos_api_last_error();
}
- (double)__EXT_NATIVE__eos_api_is_initialized
{
    return __EXT_NATIVE__eos_api_is_initialized();
}
- (double)__EXT_NATIVE__eos_api_initialize:(char*)product_name arg1:(char*)product_version arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_api_initialize(product_name, product_version, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_api_shutdown:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_api_shutdown(__ret_buffer, __ret_buffer_length);
}
- (char*)__EXT_NATIVE__eos_api_get_version
{
    return __EXT_NATIVE__eos_api_get_version();
}
- (char*)__EXT_NATIVE__eos_api_result_to_string:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_api_result_to_string(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_api_result_is_operation_complete:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_api_result_is_operation_complete(__arg_buffer, __arg_buffer_length);
}
- (char*)__EXT_NATIVE__eos_api_application_status_to_string:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_api_application_status_to_string(__arg_buffer, __arg_buffer_length);
}
- (char*)__EXT_NATIVE__eos_api_network_status_to_string:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_api_network_status_to_string(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_api_epic_account_id_is_valid:(char*)account_id
{
    return __EXT_NATIVE__eos_api_epic_account_id_is_valid(account_id);
}
- (double)__EXT_NATIVE__eos_api_product_user_id_is_valid:(char*)product_user_id
{
    return __EXT_NATIVE__eos_api_product_user_id_is_valid(product_user_id);
}
- (double)__EXT_NATIVE__eos_platform_is_created
{
    return __EXT_NATIVE__eos_platform_is_created();
}
- (double)__EXT_NATIVE__eos_platform_create:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_platform_create(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_platform_release
{
    return __EXT_NATIVE__eos_platform_release();
}
- (double)__EXT_NATIVE__eos_platform_tick
{
    return __EXT_NATIVE__eos_platform_tick();
}
- (double)__EXT_NATIVE__eos_platform_check_for_launcher_and_restart:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_platform_check_for_launcher_and_restart(__ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_platform_set_network_status:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_platform_set_network_status(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_logging_set_callback:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_logging_set_callback(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_logging_clear_callback
{
    return __EXT_NATIVE__eos_logging_clear_callback();
}
- (double)__EXT_NATIVE__eos_logging_set_log_level:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_logging_set_log_level(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_auth_login:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_auth_login(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_auth_logout:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_auth_logout(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_auth_link_account:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_auth_link_account(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_auth_delete_persistent_auth:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_auth_delete_persistent_auth(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_auth_get_logged_in_accounts_count:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_auth_get_logged_in_accounts_count(__ret_buffer, __ret_buffer_length);
}
- (char*)__EXT_NATIVE__eos_auth_get_logged_in_account_by_index:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_auth_get_logged_in_account_by_index(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_auth_get_login_status:(char*)local_user_id arg1:(char*)__ret_buffer arg2:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_auth_get_login_status(local_user_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_auth_copy_id_token:(char*)local_user_id arg1:(char*)target_account_id arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_auth_copy_id_token(local_user_id, target_account_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_auth_copy_user_auth_token:(char*)local_user_id arg1:(char*)__ret_buffer arg2:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_auth_copy_user_auth_token(local_user_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_auth_query_id_token:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_auth_query_id_token(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_auth_verify_id_token:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_auth_verify_id_token(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_auth_verify_user_auth:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_auth_verify_user_auth(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_auth_add_notify_login_status_changed:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_auth_add_notify_login_status_changed(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_auth_remove_notify_login_status_changed:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_auth_remove_notify_login_status_changed(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_login:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_connect_login(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_create_user:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_connect_create_user(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_link_account:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_connect_link_account(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_unlink_account:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_connect_unlink_account(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_create_device_id:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_connect_create_device_id(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_delete_device_id:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_connect_delete_device_id(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_transfer_device_id_account:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_connect_transfer_device_id_account(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_logout:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_connect_logout(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_get_logged_in_users_count:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_connect_get_logged_in_users_count(__ret_buffer, __ret_buffer_length);
}
- (char*)__EXT_NATIVE__eos_connect_get_logged_in_user_by_index:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_connect_get_logged_in_user_by_index(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_get_login_status:(char*)local_user_id arg1:(char*)__ret_buffer arg2:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_connect_get_login_status(local_user_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_copy_id_token:(char*)local_user_id arg1:(char*)__ret_buffer arg2:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_connect_copy_id_token(local_user_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_copy_product_user_info:(char*)target_user_id arg1:(char*)__ret_buffer arg2:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_connect_copy_product_user_info(target_user_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_copy_product_user_external_account_by_index:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_connect_copy_product_user_external_account_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_copy_product_user_external_account_by_account_type:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_connect_copy_product_user_external_account_by_account_type(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_copy_product_user_external_account_by_account_id:(char*)target_user_id arg1:(char*)account_id arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_connect_copy_product_user_external_account_by_account_id(target_user_id, account_id, __ret_buffer, __ret_buffer_length);
}
- (char*)__EXT_NATIVE__eos_connect_get_product_user_id_mapping:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_connect_get_product_user_id_mapping(__arg_buffer, __arg_buffer_length);
}
- (char*)__EXT_NATIVE__eos_connect_get_external_account_mapping:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_connect_get_external_account_mapping(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_verify_id_token:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_connect_verify_id_token(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_query_external_account_mappings:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_connect_query_external_account_mappings(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_query_product_user_id_mappings:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_connect_query_product_user_id_mappings(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_add_notify_auth_expiration:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_connect_add_notify_auth_expiration(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_remove_notify_auth_expiration:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_connect_remove_notify_auth_expiration(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_add_notify_login_status_changed:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_connect_add_notify_login_status_changed(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_connect_remove_notify_login_status_changed:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_connect_remove_notify_login_status_changed(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_friends_query_friends:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_friends_query_friends(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_friends_get_friends_count:(char*)local_user_id arg1:(char*)__ret_buffer arg2:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_friends_get_friends_count(local_user_id, __ret_buffer, __ret_buffer_length);
}
- (char*)__EXT_NATIVE__eos_friends_get_friend_at_index:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_friends_get_friend_at_index(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_friends_get_status:(char*)local_user_id arg1:(char*)target_user_id arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_friends_get_status(local_user_id, target_user_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_friends_add_notify_friends_update:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_friends_add_notify_friends_update(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_friends_remove_notify_friends_update:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_friends_remove_notify_friends_update(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_user_info_query_user_info:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_user_info_query_user_info(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_user_info_copy_user_info:(char*)local_user_id arg1:(char*)target_user_id arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_user_info_copy_user_info(local_user_id, target_user_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_user_info_get_local_platform_type:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_user_info_get_local_platform_type(__ret_buffer, __ret_buffer_length);
}
- (char*)__EXT_NATIVE__eos_user_info_copy_best_display_name:(char*)local_user_id arg1:(char*)target_user_id
{
    return __EXT_NATIVE__eos_user_info_copy_best_display_name(local_user_id, target_user_id);
}
- (double)__EXT_NATIVE__eos_user_info_copy_external_user_info_by_index:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_user_info_copy_external_user_info_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_user_info_copy_external_user_info_by_account_type:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_user_info_copy_external_user_info_by_account_type(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_user_info_copy_external_user_info_by_account_id:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_user_info_copy_external_user_info_by_account_id(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_stats_ingest_stat:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_stats_ingest_stat(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_stats_query_stats:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_stats_query_stats(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_stats_get_stats_count:(char*)target_user_id arg1:(char*)__ret_buffer arg2:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_stats_get_stats_count(target_user_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_stats_copy_stat_by_index:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_stats_copy_stat_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_stats_copy_stat_by_name:(char*)target_user_id arg1:(char*)name arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_stats_copy_stat_by_name(target_user_id, name, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_ui_show_friends:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_ui_show_friends(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_ui_show_native_profile:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_ui_show_native_profile(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_ui_acknowledge_event_id:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_ui_acknowledge_event_id(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_ui_set_display_preference:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_ui_set_display_preference(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_ui_report_input_state:(double)button_down arg1:(double)button_up arg2:(double)button_left arg3:(double)button_right arg4:(double)button_accept arg5:(double)button_cancel
{
    return __EXT_NATIVE__eos_ui_report_input_state(button_down, button_up, button_left, button_right, button_accept, button_cancel);
}
- (double)__EXT_NATIVE__eos_ui_add_notify_display_settings_updated:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_ui_add_notify_display_settings_updated(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_ui_remove_notify_display_settings_updated:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_ui_remove_notify_display_settings_updated(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_metrics_begin_player_session:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_metrics_begin_player_session(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_metrics_end_player_session:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_metrics_end_player_session(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_reports_send_player_behavior_report:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_reports_send_player_behavior_report(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_sanctions_query_active_player_sanctions:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_sanctions_query_active_player_sanctions(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_sanctions_get_player_sanction_count:(char*)target_user_id arg1:(char*)__ret_buffer arg2:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_sanctions_get_player_sanction_count(target_user_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_sanctions_copy_player_sanction_by_index:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_sanctions_copy_player_sanction_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_sanctions_create_player_sanction_appeal:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_sanctions_create_player_sanction_appeal(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_achievements_query_definitions:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_achievements_query_definitions(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_achievements_query_player_achievements:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_achievements_query_player_achievements(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_achievements_get_achievement_definition_count:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_achievements_get_achievement_definition_count(__ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_achievements_get_player_achievement_count:(char*)local_user_id arg1:(char*)target_user_id arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_achievements_get_player_achievement_count(local_user_id, target_user_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_achievements_copy_achievement_definition_by_index:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_achievements_copy_achievement_definition_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_achievements_copy_achievement_definition_v2_by_index:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_achievements_copy_achievement_definition_v2_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_achievements_copy_achievement_definition_by_id:(char*)achievement_id arg1:(char*)__ret_buffer arg2:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_achievements_copy_achievement_definition_by_id(achievement_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_achievements_copy_player_achievement_by_index:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_achievements_copy_player_achievement_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_achievements_copy_player_achievement_by_id:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_achievements_copy_player_achievement_by_id(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_achievements_unlock_achievements:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_achievements_unlock_achievements(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_achievements_add_notify_achievements_unlocked_v2:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_achievements_add_notify_achievements_unlocked_v2(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_achievements_remove_notify_achievements_unlocked:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_achievements_remove_notify_achievements_unlocked(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_leaderboards_query_definitions:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_leaderboards_query_definitions(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_leaderboards_query_ranks:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_leaderboards_query_ranks(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_leaderboards_query_user_scores:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_leaderboards_query_user_scores(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_leaderboards_get_definition_count:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_leaderboards_get_definition_count(__ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_leaderboards_get_record_count:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_leaderboards_get_record_count(__ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_leaderboards_get_user_score_count:(char*)__ret_buffer arg1:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_leaderboards_get_user_score_count(__ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_leaderboards_copy_definition_by_index:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_leaderboards_copy_definition_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_leaderboards_copy_definition_by_id:(char*)leaderboard_id arg1:(char*)__ret_buffer arg2:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_leaderboards_copy_definition_by_id(leaderboard_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_leaderboards_copy_record_by_index:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_leaderboards_copy_record_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_leaderboards_copy_record_by_user_id:(char*)user_id arg1:(char*)__ret_buffer arg2:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_leaderboards_copy_record_by_user_id(user_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_leaderboards_copy_user_score_by_index:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_leaderboards_copy_user_score_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_presence_query_presence:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_presence_query_presence(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_presence_has_presence:(char*)local_user_id arg1:(char*)target_user_id
{
    return __EXT_NATIVE__eos_presence_has_presence(local_user_id, target_user_id);
}
- (double)__EXT_NATIVE__eos_presence_copy_presence:(char*)local_user_id arg1:(char*)target_user_id arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_presence_copy_presence(local_user_id, target_user_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_presence_create_presence_modification:(char*)local_user_id arg1:(char*)__ret_buffer arg2:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_presence_create_presence_modification(local_user_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_presence_modification_release:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_presence_modification_release(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_presence_modification_set_status:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_presence_modification_set_status(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_presence_modification_set_raw_rich_text:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_presence_modification_set_raw_rich_text(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_presence_modification_set_data:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_presence_modification_set_data(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_presence_modification_delete_data:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_presence_modification_delete_data(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_presence_set_presence:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_presence_set_presence(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_presence_add_notify_on_presence_changed:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_presence_add_notify_on_presence_changed(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_presence_remove_notify_on_presence_changed:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_presence_remove_notify_on_presence_changed(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_presence_add_notify_join_game_accepted:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_presence_add_notify_join_game_accepted(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_presence_remove_notify_join_game_accepted:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_presence_remove_notify_join_game_accepted(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_create_session_modification:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_sessions_create_session_modification(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_session_modification_release:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_sessions_session_modification_release(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_update_session:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_sessions_update_session(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_destroy_session:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_sessions_destroy_session(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_start_session:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_sessions_start_session(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_end_session:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_sessions_end_session(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_join_session:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_sessions_join_session(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_register_players:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_sessions_register_players(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_unregister_players:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_sessions_unregister_players(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_create_session_search:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_sessions_create_session_search(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_session_search_release:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_sessions_session_search_release(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_session_search_set_session_id:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_sessions_session_search_set_session_id(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_session_search_set_target_user_id:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_sessions_session_search_set_target_user_id(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_session_search_find:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_sessions_session_search_find(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_session_search_copy_search_result_by_index:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_sessions_session_search_copy_search_result_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_session_details_release:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_sessions_session_details_release(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_copy_active_session_handle:(char*)session_name arg1:(char*)__ret_buffer arg2:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_sessions_copy_active_session_handle(session_name, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_active_session_release:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_sessions_active_session_release(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_active_session_copy_info:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_sessions_active_session_copy_info(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_copy_session_handle_by_invite_id:(char*)invite_id arg1:(char*)__ret_buffer arg2:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_sessions_copy_session_handle_by_invite_id(invite_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_copy_session_handle_by_ui_event_id:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_sessions_copy_session_handle_by_ui_event_id(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_session_details_copy_info:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_sessions_session_details_copy_info(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_add_notify_session_invite_received:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_sessions_add_notify_session_invite_received(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_remove_notify_session_invite_received:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_sessions_remove_notify_session_invite_received(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_add_notify_session_invite_accepted:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_sessions_add_notify_session_invite_accepted(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_remove_notify_session_invite_accepted:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_sessions_remove_notify_session_invite_accepted(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_add_notify_join_session_accepted:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_sessions_add_notify_join_session_accepted(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_sessions_remove_notify_join_session_accepted:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_sessions_remove_notify_join_session_accepted(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_create_lobby:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_create_lobby(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_destroy_lobby:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_destroy_lobby(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_join_lobby:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_join_lobby(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_leave_lobby:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_leave_lobby(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_update_lobby_modification:(char*)lobby_id arg1:(char*)local_user_id arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_update_lobby_modification(lobby_id, local_user_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_lobby_modification_release:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_lobby_modification_release(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_update_lobby:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_update_lobby(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_lobby_modification_set_permission_level:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_lobby_modification_set_permission_level(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_lobby_modification_set_max_members:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_lobby_modification_set_max_members(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_lobby_modification_set_bucket_id:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_lobby_modification_set_bucket_id(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_lobby_modification_set_invites_allowed:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_lobby_modification_set_invites_allowed(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_lobby_modification_add_attribute:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_lobby_modification_add_attribute(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_lobby_modification_remove_attribute:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_lobby_modification_remove_attribute(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_lobby_modification_add_member_attribute:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_lobby_modification_add_member_attribute(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_lobby_modification_remove_member_attribute:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_lobby_modification_remove_member_attribute(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_promote_member:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_promote_member(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_kick_member:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_kick_member(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_create_lobby_search:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_create_lobby_search(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_lobby_search_release:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_lobby_search_release(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_lobby_search_set_lobby_id:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_lobby_search_set_lobby_id(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_lobby_search_set_target_user_id:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_lobby_search_set_target_user_id(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_lobby_search_set_parameter:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_lobby_search_set_parameter(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_lobby_search_remove_parameter:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_lobby_search_remove_parameter(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_lobby_search_set_max_results:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_lobby_search_set_max_results(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_lobby_search_find:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_lobby_search_find(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_lobby_search_get_search_result_count:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_lobby_search_get_search_result_count(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_lobby_search_copy_search_result_by_index:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_lobby_search_copy_search_result_by_index(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_details_release:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_details_release(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_copy_lobby_details_handle:(char*)lobby_id arg1:(char*)local_user_id arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_copy_lobby_details_handle(lobby_id, local_user_id, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_details_copy_info:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_details_copy_info(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_details_get_member_count:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_details_get_member_count(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (char*)__EXT_NATIVE__eos_lobby_details_get_member_by_index:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_details_get_member_by_index(__arg_buffer, __arg_buffer_length);
}
- (char*)__EXT_NATIVE__eos_lobby_details_get_lobby_owner:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_details_get_lobby_owner(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_add_notify_lobby_update_received:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_add_notify_lobby_update_received(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_remove_notify_lobby_update_received:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_remove_notify_lobby_update_received(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_add_notify_lobby_member_update_received:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_add_notify_lobby_member_update_received(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_remove_notify_lobby_member_update_received:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_remove_notify_lobby_member_update_received(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_add_notify_lobby_member_status_received:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_add_notify_lobby_member_status_received(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_remove_notify_lobby_member_status_received:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_remove_notify_lobby_member_status_received(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_add_notify_join_lobby_accepted:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_add_notify_join_lobby_accepted(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_remove_notify_join_lobby_accepted:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_remove_notify_join_lobby_accepted(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_add_notify_leave_lobby_requested:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_add_notify_leave_lobby_requested(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_remove_notify_leave_lobby_requested:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_remove_notify_leave_lobby_requested(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_add_notify_send_lobby_native_invite_requested:(char*)__arg_buffer arg1:(double)__arg_buffer_length arg2:(char*)__ret_buffer arg3:(double)__ret_buffer_length
{
    return __EXT_NATIVE__eos_lobby_add_notify_send_lobby_native_invite_requested(__arg_buffer, __arg_buffer_length, __ret_buffer, __ret_buffer_length);
}
- (double)__EXT_NATIVE__eos_lobby_remove_notify_send_lobby_native_invite_requested:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__eos_lobby_remove_notify_send_lobby_native_invite_requested(__arg_buffer, __arg_buffer_length);
}
- (double)__EXT_NATIVE__EpicOnlineServices_invocation_handler:(char*)__arg_buffer arg1:(double)__arg_buffer_length
{
    return __EXT_NATIVE__EpicOnlineServices_invocation_handler(__arg_buffer, __arg_buffer_length);
}
@end

