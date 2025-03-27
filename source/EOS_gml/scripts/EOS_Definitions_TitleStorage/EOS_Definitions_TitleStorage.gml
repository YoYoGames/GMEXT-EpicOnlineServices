
/** Maximum File Name Length in bytes */
#macro EOS_TITLESTORAGE_FILENAME_MAX_LENGTH_BYTES 64


/**
 * Return results for EOS_TitleStorage_OnReadFileDataCallback callbacks
 */
enum EOS_TitleStorage_ReadResult
{
	/** Signifies the data was read successfully, and we should continue to the next chunk if possible */
	ContinueReading = 1,
	/** Signifies there was a failure reading the data, and the request should end */
	FailRequest = 2,
	/** Signifies the request should be canceled, but not due to an error */
	CancelRequest = 3
}

