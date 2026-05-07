
show_debug_message($"eos_lobby_send_invite {data}");

var _opts = new EpicLobbySendInviteOptions();
_opts.lobby_id = obj_eos_lobbies.lobby_id;
_opts.local_user_id = global.product_user_id;
_opts.target_user_id = data.user_id;

eos_lobby_send_invite(_opts);
