
/** Maximum File Name Length in bytes */
#macro EOS_TITLESTORAGE_FILENAME_MAX_LENGTH_BYTES 64


/**
 * Return results for EOS_TitleStorage_OnReadFileDataCallback callbacks
 */
enum EOS_TITLE_STORAGE_READ_RESULT
{
	/** Signifies the data was read successfully, and we should continue to the next chunk if possible */
	CONTINUE_READING = 1,
	/** Signifies there was a failure reading the data, and the request should end */
	FAIL_REQUEST = 2,
	/** Signifies the request should be canceled, but not due to an error */
	CANCEL_REQUEST = 3
}

