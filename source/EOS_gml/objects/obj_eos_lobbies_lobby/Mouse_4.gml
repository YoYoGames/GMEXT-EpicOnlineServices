
var _opts = new EpicLobbyJoinLobbyByIdOptions();
_opts.lobby_id = lobby_id;
_opts.local_user_id = global.product_user_id;
_opts.presence_enabled = true;

eos_lobby_join_lobby_by_id(_opts);
