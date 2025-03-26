
switch(async_load[? "type"])
{
	case "eos_title_storage_read_file_on_file_transfer_progress_updated":
		
		if(async_load[? "identifier"] != request)
			exit
		
		porcent = 100 * async_load[? "bytes_transferred"]/async_load[? "total_file_size_bytes"]
		
	break
	
	case "eos_title_storage_read_file_on_file_received":

		if(async_load[? "identifier"] != request)
			exit
		
		if(async_load[? "status"] == EOS_SUCCESS)
			color_current = color_done
		else
			color_current = color_failed
		

		with(ins_cancel)
			instance_destroy()
	
	break
}
