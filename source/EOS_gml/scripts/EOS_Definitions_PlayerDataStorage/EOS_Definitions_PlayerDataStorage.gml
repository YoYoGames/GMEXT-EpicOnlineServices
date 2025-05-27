
/** Maximum File Name Length in bytes */
#macro EOS_PLAYERDATASTORAGE_FILENAME_MAX_LENGTH_BYTES 64

/** Timestamp value representing an undefined time for Player Data Storage. */
#macro EOS_PLAYERDATASTORAGE_TIME_UNDEFINED -1

/**
 * Return results for EOS_PlayerDataStorage_OnReadFileDataCallback callbacks to return
 */
enum EOS_PLAYER_DATA_STORAGE_READ_RESULT
{
	/** Signifies the data was read successfully, and we should continue to the next chunk if possible */
	CONTINUE_READING = 1,
	/** Signifies there was a failure reading the data, and the request should end */
	FAIL_REQUEST = 2,
	/** Signifies the request should be canceled, but not due to an error */
	CANCEL_REQUEST = 3
}


/**
 * Return results for EOS_PlayerDataStorage_OnWriteFileDataCallback callbacks to return
 */
enum EOS_PlayerDataStorage_WriteResult
{
	/** Signifies the data was written successfully, and we should write the data the file */
	CONTINUE_WRITING = 1,
	/** Signifies all data has now been written successfully, and we should upload the data to the cloud */
	COMPLETE_REQUEST = 2,
	/** Signifies there was a failure writing the data, and the request should end */
	FAIL_REQUEST = 3,
	/** Signifies the request should be canceled, but not due to an error */
	CANCEL_REQUEST = 4
}
