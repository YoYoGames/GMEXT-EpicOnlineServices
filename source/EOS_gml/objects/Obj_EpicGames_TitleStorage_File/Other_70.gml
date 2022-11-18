
switch(async_load[?"type"])
{
	case "EpicGames_TitleStorage_ReadFile_OnFileTransferProgressUpdated":
		
		if(async_load[?"identifier"] != request)
			exit
		
		porcent = 100 * async_load[?"BytesTransferred"]/async_load[?"TotalFileSizeBytes"]
		
	break
	
	case "EpicGames_TitleStorage_ReadFile_OnFileReceived":

		if(async_load[?"identifier"] != request)
			exit
		
		if(async_load[?"status"] == EpicGames_Success)
			color_current = color_done
		else
			color_current = color_failed
		

		with(ins_cancel)
			instance_destroy()
	
	break
}
