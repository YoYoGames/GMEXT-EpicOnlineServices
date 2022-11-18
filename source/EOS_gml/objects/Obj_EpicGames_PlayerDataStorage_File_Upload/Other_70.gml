
switch(async_load[?"type"])
{
	case "EpicGames_PlayerDataStorage_WriteFile_OnFileTransferProgressUpdated":
		
		if(async_load[?"identifier"] != request)
			exit
		
		porcent = async_load[?"BytesTransferred"]/async_load[?"TotalFileSizeBytes"] * 100
		
	break
	
	case "EpicGames_PlayerDataStorage_WriteFile_OnFileSent":

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
