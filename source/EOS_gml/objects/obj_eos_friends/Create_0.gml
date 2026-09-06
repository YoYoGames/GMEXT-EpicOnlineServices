
event_inherited();

if(!variable_instance_exists(id,"friend_object"))
	friend_object = obj_eos_friend

friend_counter_index = 0

eos_friends_query_friends(global.epic_account_id,function(data){
	if(data.result_code != EpicResult.Success)
		return 0
	
		friends = {}
		var count = eos_friends_get_friends_count(global.epic_account_id)
		for(var a = 0 ; a < count ; a ++)
		{
			var Friend_AccountID = eos_friends_get_friend_at_index(global.epic_account_id,a)
			request = eos_user_info_query_user_info(global.epic_account_id,Friend_AccountID,function(data){
				
				if(data.result_code != EpicResult.Success)
					return 0
					
				var struct = eos_user_info_copy_user_info(global.epic_account_id,data.target_user_id)
					
				struct_set(friends,data.target_user_id,struct)
				
				var nope = false
				var _arrayName = struct_get_names(friends)
				for(var b = 0 ; b < array_length(_arrayName) ; b++)
					if(struct_names_count(struct_get(friends,_arrayName[b])) == 0)
					{
						nope = true
						break
					}
				if(nope)
					{return}
					
				//Ok, let's request!
				var friends_account_ids = struct_get_names(friends)
				eos_connect_query_external_account_mappings(global.product_user_id,0,friends_account_ids,function(data){
						
					if(data.result_code != EpicResult.Success)
						return 0
						
					var friends_account_ids = struct_get_names(friends)
		
					for(var c = 0 ; c < array_length(friends_account_ids) ; c++)
					{
						var user_id = eos_connect_get_external_account_mapping(global.product_user_id,0,friends_account_ids[c])
						struct_set(struct_get(friends,friends_account_ids[c]),"user_id",user_id)
					}
		
					struct_foreach(friends,function(_name, _value)
						{
							if(!struct_exists(_value,"display_name"))
								{return}
							var ins = instance_create_depth(x,y+100+friend_counter_index*80,0,friend_object,{data: _value})
							friend_counter_index++
							
						})
					})
				})
				
			struct_set(friends,Friend_AccountID,{})
		}
	})



