
show_debug_message($"eos_lobby_send_invite {data}")

var result = eos_lobby_send_invite(obj_eos_lobbies.lobby_id,global.product_user_id,data.user_id)
show_debug_message(result)

