
var _score = random(99999)
show_message_async("Your score: " + string(_score))
eos_stats_ingest_stat(global.product_user_id,global.product_user_id,"Leaderboard_Stat",_score,
	function(data){
			show_debug_message(data)
		})
