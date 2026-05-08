
var _opts = new EpicLobbyPromoteMemberOptions();
_opts.lobby_id = obj_eos_lobbies.lobby_id;
_opts.local_user_id = global.product_user_id;
_opts.target_user_id = data.product_user_id;

eos_lobby_promote_member(_opts);
