

global.epic_account_id = ""
global.product_user_id = ""


notify_login_status_changed = eos_auth_add_notify_login_status_changed(function(data){show_debug_message(data)})
notify_auth_expiration = eos_connect_add_notify_auth_expiration(function(data){show_debug_message(data)})
notify_login_status_changed = eos_connect_add_notify_login_status_changed(function(data){show_debug_message(data)})
notify_friends_update = eos_friends_add_notify_friends_update(function(data){show_debug_message(data)})
notify_achievements_unlocked_v2 = eos_achievements_add_notify_achievements_unlocked_v2(function(data){show_debug_message(data)})
notify_display_settings_updated = eos_ui_add_notify_display_settings_updated(function(data){show_debug_message(data)})


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

                eos_connect_create_user(function(r)
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
    show_debug_message("EOS init failed: " + eos_api_last_error());
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

var result = eos_platform_create(
		false,
	    "144042169a6940a58e014acaa264cb8a",
	    "3fefc033b7dc48d68553e095b4f9b58d",
	    "750a6c35c15a4879baf3c4a2e02ca60d",
	    "xyza7891r9cqTcARXLV4XC1g4fxJ3yXX",
	    "+o3AXL60HNu94ERLlyExQKgQtNe6aqMwSXJ50ZYMCLg"
	)


if (result != EpicResult.Success)
{
    show_debug_message("Platform creation failed: " + eos_api_last_error());
	
    return false;
}

show_debug_message("EOS Platform created");

eos_login();





function eos_logout_and_forget()
{
    eos_auth_delete_persistent_auth(function(info)
    {
        show_debug_message("EOS: persistent auth cleared: " + string(info.result_code));
    });
}


room_goto(rm_eos_menu)

