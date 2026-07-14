
if(global.product_user_id == "")
{
    // LOGIN FLOW
    show_debug_message("Starting login...");
    
    eos_auth_login("", "", EpicLoginCredentialType.AccountPortal,
        EpicExternalCredentialType.Epic,
        EpicAuthScopeFlags.BasicProfile | EpicAuthScopeFlags.FriendsList | EpicAuthScopeFlags.Presence,
        EpicAuthLoginFlags.NoFlags,
        function(_auth_info) {
            if (_auth_info.result_code == EpicResult.Success)
            {
                global.epic_account_id = _auth_info.local_user_id;
                show_debug_message("Auth login success: " + global.epic_account_id);
                
                // Step 2: Get access token and connect
                var auth_token = eos_auth_copy_user_auth_token(global.epic_account_id);
                
                if (auth_token != "")
                {
                    eos_connect_login(auth_token, 
                        EpicExternalCredentialType.Epic, 
                        "player",
                        function(_connect_info) {
                            if (_connect_info.result_code == EpicResult.Success)
                            {
                                global.product_user_id = _connect_info.local_user_id;
                                show_debug_message("Connect login success: " + global.product_user_id);
                                show_debug_message("User is now logged in!");
                            }
                            else
                                show_debug_message("Connect login failed: " + string(_connect_info.result_code));
                        });
                }
                else
                    show_debug_message("Failed to get auth token");
            }
            else
                show_debug_message("Auth login failed: " + string(_auth_info.result_code));
        });
}
else
{
    // LOGOUT FLOW
    show_debug_message("Starting logout...");
    
    logout_count = 0;
    
    // Delete persistent auth first
    eos_auth_delete_persistent_auth(function(_info) {
        logout_count++;
        show_debug_message("Delete persistent auth result: " + string(_info.result_code));
        if (logout_count == 3) {
            global.epic_account_id = "";
            global.product_user_id = "";
            show_debug_message("Fully logged out!");
        }
    });
    
    // Logout from auth
    eos_auth_logout(global.epic_account_id, function(_info) {
        logout_count++;
        show_debug_message("Auth logout result: " + string(_info.result_code));
        if (logout_count == 3) {
            global.epic_account_id = "";
            global.product_user_id = "";
            show_debug_message("Fully logged out!");
        }
    });
    
    // Logout from connect
    eos_connect_logout(global.product_user_id, function(_info) {
        logout_count++;
        show_debug_message("Connect logout result: " + string(_info.result_code));
        if (logout_count == 3) {
            global.epic_account_id = "";
            global.product_user_id = "";
            show_debug_message("Fully logged out!");
        }
    });
}