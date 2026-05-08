
Speaking = false

AudioStatus = EpicRTCAudioStatus.AdminDisabled

Mute = instance_create_depth(x+50,y+30,0,obj_eos_lobbies_member_mute,{data: data})
Kick = instance_create_depth(x+150,y+30,0,obj_eos_lobbies_member_kick,{data: data})
Promote = instance_create_depth(x+250,y+30,0,obj_eos_lobbies_member_promote,{data: data})

