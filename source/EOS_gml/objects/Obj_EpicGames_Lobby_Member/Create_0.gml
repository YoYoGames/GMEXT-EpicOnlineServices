
Speaking = false
AudioStatus = EOS_RTC_AUDIO_STATUS.DISABLED

_struct = {user_id: user_id}

Mute = instance_create_depth(x+50,y+30,0,Obj_EpicGames_Lobby_Member_Mute,_struct)
Kick = instance_create_depth(x+150,y+30,0,Obj_EpicGames_Lobby_Member_Kick,_struct)
Promote = instance_create_depth(x+250,y+30,0,Obj_EpicGames_Lobby_Member_Promote,_struct)

