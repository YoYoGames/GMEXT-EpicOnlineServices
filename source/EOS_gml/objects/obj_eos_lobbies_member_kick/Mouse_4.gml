
var _opts = new EpicLobbyKickMemberOptions();
_opts.lobby_id = obj_eos_lobbies.lobby_id;
_opts.local_user_id = global.product_user_id;
_opts.target_user_id = user_id;

eos_lobby_kick_member(_opts);
