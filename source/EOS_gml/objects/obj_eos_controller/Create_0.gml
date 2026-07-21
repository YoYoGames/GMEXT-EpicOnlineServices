

global.epic_account_id = ""
global.product_user_id = ""


function eos_login()
{
    eos_login_try_persistent_auth();
}

function eos_login_try_persistent_auth()
{
    show_debug_message("EOS: trying PersistentAuth...");

    eos_auth_login(
        "",
        "",
        EpicLoginCredentialType.PersistentAuth,
        EpicExternalCredentialType.Epic,
        EpicAuthScopeFlags.BasicProfile
        | EpicAuthScopeFlags.FriendsList
        | EpicAuthScopeFlags.Presence,
		EpicAuthLoginFlags.NoFlags,
        function(result)
        {
            if (result.result_code == EpicResult.Success)
            {
                global.epic_account_id = result.local_user_id;
                show_debug_message("EOS: PersistentAuth login success: " + global.epic_account_id);

                eos_connect_login_after_auth();
                return;
            }

            show_debug_message("EOS: PersistentAuth failed: " + string(result.result_code));
            show_debug_message("EOS: falling back to AccountPortal");

            eos_login_try_account_portal();
        }
    );
}

function eos_login_try_account_portal()
{
    show_debug_message("EOS: trying AccountPortal...");

    eos_auth_login(
        "",
        "",
        EpicLoginCredentialType.AccountPortal,
        EpicExternalCredentialType.Epic,
        EpicAuthScopeFlags.BasicProfile
        | EpicAuthScopeFlags.FriendsList
        | EpicAuthScopeFlags.Presence,
		EpicAuthLoginFlags.NoFlags,
        function(result)
        {
            if (result.result_code != EpicResult.Success)
            {
                show_debug_message("EOS: AccountPortal login failed: " + string(result.result_code));
                show_debug_message("EOS last error: " + eos_api_last_error());
                return;
            }

            global.epic_account_id = result.local_user_id;
            show_debug_message("EOS: AccountPortal login success: " + global.epic_account_id);

            eos_connect_login_after_auth();
        }
    );
}

function eos_connect_login_after_auth()
{
    var token = eos_auth_copy_user_auth_token(global.epic_account_id);

    if (is_undefined(token) || token.access_token == "")
    {
        show_debug_message("EOS: failed to copy auth token");
        show_debug_message("EOS last error: " + eos_api_last_error());
        return;
    }

    eos_connect_login(
        token.access_token,
        EpicExternalCredentialType.Epic,
        "",
        function(result)
        {
            if (result.result_code == EpicResult.Success)
            {
                global.product_user_id = result.local_user_id;
                show_debug_message("EOS: Connect login success: " + global.product_user_id);
                return;
            }

            if (result.has_continuance_token)
            {
                show_debug_message("EOS: Connect continuance token found, creating user...");

                eos_connect_create_user(result.continuance_token_id, function(r)
                {
                    if (r.result_code == EpicResult.Success)
                    {
                        global.product_user_id = r.local_user_id;
                        show_debug_message("EOS: Connect create user success: " + global.product_user_id);
                    }
                    else
                    {
                        show_debug_message("EOS: Connect create user failed: " + string(r.result_code));
                        show_debug_message("EOS last error: " + eos_api_last_error());
                    }
                });

                return;
            }

            show_debug_message("EOS: Connect login failed: " + string(result.result_code));
            show_debug_message("EOS last error: " + eos_api_last_error());
        }
    );
}










/// eos_init()

show_debug_message($"eos_test: {eos_test()}")

var r = eos_api_initialize("MyGame", "1.0");

if (r != EpicResult.Success)
{
    show_debug_message($"EOS init failed: {eos_api_last_error()}");
    return false;
}

show_debug_message("EOS initialized: " + eos_api_get_version());

//var options = {
//    product_id: "YOUR_PRODUCT_ID",
//    sandbox_id: "YOUR_SANDBOX_ID",
//    deployment_id: "YOUR_DEPLOYMENT_ID",
//    client_id: "YOUR_CLIENT_ID",
//    client_secret: "YOUR_CLIENT_SECRET"
//};

//var result = eos_platform_create(options);

// All credentials (ProductId, SandboxId, DeploymentId, ClientCredentialsId,
// ClientCredentialsSecret, EncryptionKey, IsServer) come from the extension options
// configured in the IDE. Only the runtime-determined cache directory is passed in.
show_debug_message($"eos_platform_create({working_directory})")
var result = eos_platform_create(working_directory)


if (result != EpicResult.Success)
{
    show_debug_message("Platform creation failed: " + eos_api_last_error());
	
    return false;
}

show_debug_message("EOS Platform created");
show_debug_message($"EOS storage directory: {eos_platform_get_storage_directory()}");

// Persistent notifications — must be registered after the platform exists: each
// add_notify_* call needs a live interface, which eos_platform_get() doesn't have
// until eos_platform_create succeeds above (registering them any earlier is a silent
// no-op — every add_notify_* call returns 0 with the interface-unavailable error).
notify_auth_login_status_changed = eos_auth_add_notify_login_status_changed(function(data){
	show_debug_message(data)})
notify_auth_expiration = eos_connect_add_notify_auth_expiration(function(data){show_debug_message(data)})
notify_connect_login_status_changed = eos_connect_add_notify_login_status_changed(function(data){show_debug_message(data)})
notify_friends_update = eos_friends_add_notify_friends_update(function(data){show_debug_message(data)})
notify_achievements_unlocked_v2 = eos_achievements_add_notify_achievements_unlocked_v2(function(data){show_debug_message(data)})
notify_display_settings_updated = eos_ui_add_notify_display_settings_updated(function(data){show_debug_message(data)})
notify_presence_join_game_accepted = eos_presence_add_notify_join_game_accepted(function(_info)
{
	// EpicPresenceJoinGameAcceptedCallbackInfo: .join_info, .local_user_id, .target_user_id, .ui_event_id
	// MUST acknowledge or the social overlay UI hangs.
	eos_ui_acknowledge_event_id(_info.ui_event_id, EpicResult.Success)
	show_debug_message($"presence join game accepted: {_info.join_info}")
})
notify_custominvites_send_native_invite_requested = eos_custominvites_add_notify_send_custom_native_invite_requested(function(_info)
{
	// EpicCustomInvitesSendCustomNativeInviteRequestedCallbackInfo:
	//   .ui_event_id, .local_user_id, .target_native_account_type, .target_user_native_account_id, .invite_id
	// MUST acknowledge or the social overlay UI hangs.
	eos_ui_acknowledge_event_id(_info.ui_event_id, EpicResult.Success)
})

eos_login();





function eos_logout_and_forget()
{
    eos_auth_delete_persistent_auth(function(info)
    {
        show_debug_message("EOS: persistent auth cleared: " + string(info.result_code));
    });
}


room_goto(rm_eos_menu)

