
var _opts = new EpicLobbyHardMuteMemberOptions();
_opts.lobby_id = obj_eos_lobbies.lobby_id;
_opts.local_user_id = global.product_user_id;
_opts.target_user_id = user_id;
_opts.hard_mute = _bool;

eos_lobby_hard_mute_member(_opts);

_bool = !_bool;
