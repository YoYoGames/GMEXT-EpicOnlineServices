
switch(async_load[? "type"])
{
	case "eos_friends_query_friends":
		
		if(async_load[? "status"] == EOS_Result.Success)
		{
			friends = {}
			var count = eos_friends_get_friends_count(AccountID)
			for(var a = 0 ; a < count ; a ++)
			{
				var Friend_AccountID = eos_friends_get_friend_at_index(AccountID,a)
				request = eos_user_info_query_user_info(AccountID,Friend_AccountID)
				struct_set(friends,Friend_AccountID,{})
			}
		}
		
	break
	
	case "eos_user_info_query_user_info":
		
		var struct = eos_user_info_copy_user_info(AccountID,async_load[? "target"])
		
		struct_set(friends,async_load[? "target"],struct)
		
		var _arrayName = struct_get_names(friends)
		for(var a = 0 ; a < array_length(_arrayName) ; a++)
			if(struct_names_count(struct_get(friends,_arrayName[a])) == 0)
				exit
			
		show_debug_message("REQUEST: eos_connect_query_external_account_mappings")
		
		//Ok, let's request!
		var friends_account_ids = struct_get_names(friends)
		eos_connect_query_external_account_mappings(userID,0,friends_account_ids)
		
	break
	
	case "eos_connect_query_external_account_mappings":
			
		var friends_account_ids = struct_get_names(friends)
		
		for(var a = 0 ; a < array_length(friends_account_ids) ; a++)
		{
			var user_id = eos_connect_get_external_account_mapping(userID,friends_account_ids[a],0)
			struct_set(struct_get(friends,friends_account_ids[a]),"user_id",user_id)
		}
		
		struct_foreach(friends,function(_name, _value)
			{
				show_debug_message($"Friend: {_value}")
				var ins = instance_create_depth(x,y+100+friend_counter_index*80,0,friend_object,_value)
				friend_counter_index++
				exit
			})
			
	break
}