///////////////////
/** Participant RTC's status change */
enum EOS_RTCParticipantStatus
{
	/** Participant joined the room */
	Joined = 0,
	/** Participant left the room */
	Left = 1
};

/**
 * Enables echo mode.
 * This can be used during development to have the server send your voice back to you so you don't need 2 clients to test
 * if voice is being sent and received.
 *
 * @see EOS_RTC_JoinRoomOptions::Flags
 */
#macro EOS_RTC_JOINROOMFLAGS_ENABLE_ECHO 0x01


/**
 * Enables the (optional) data channel feature for RTC rooms. This feature allows members of a room to send packets to all
 * members of a room they are in, and automatically receive data packets sent by other players in that room.
 * Data packets sent this way will be automatically relayed by EOS RTC servers to all other members of the room that are listening.
 * It is not currently possible to send packets to only a subset of members of a room chosen by the sender, all members
 * listening will receive the data.
 *
 * @see EOS_RTC_JoinRoomOptions::Flags
 */
#macro EOS_RTC_JOINROOMFLAGS_ENABLE_DATACHANNEL 0x04


#macro EOS_RTC_OPTION_KEY_MAXCHARCOUNT 256
#macro EOS_RTC_OPTION_VALUE_MAXCHARCOUNT 256



#macro EOS_RTC_PARTICIPANTMETADATA_KEY_MAXCHARCOUNT 256
#macro EOS_RTC_PARTICIPANTMETADATA_VALUE_MAXCHARCOUNT 256


//////////////////////////


enum EOS_RTCAudioStatus
{
	/** Audio unsupported by the source (no devices) */
	Unsupported = 0,
	/** Audio enabled */
	Enabled = 1,
	/** Audio disabled */
	Disabled = 2,
	/** Audio disabled by the administrator */
	AdminDisabled = 3,
	/** Audio channel is disabled temporarily for both sending and receiving */
	NotListeningDisabled = 4
};


/**
 * An enumeration of the different audio input device statuses.
 */
enum EOS_RTCAudioInputStatus
{
	/** The device is not in use right now (e.g., you are alone in the room). In such cases, the hardware resources are not allocated. */
	Idle = 0,
	/** The device is being used and capturing audio. */
	Recording = 1,
	/**
	 * The SDK is in a recording state, but actually capturing silence because the device is exclusively being used by the platform at the moment.
	 * This only applies to certain platforms.
	 */
	RecordingSilent = 2,
	/**
	 * The SDK is in a recording state, but actually capturing silence because the device is disconnected (e.g., the microphone is not plugged in).
	 * This only applies to certain platforms.
	 */
	RecordingDisconnected = 3,
	/** Something failed while trying to use the device. */
	Failed = 4
};


/**
 * An enumeration of the different audio output device statuses.
 */
enum EOS_RTCAudioOutputStatus
{
	/** The device is not in used right now (e.g: you are alone in the room). In such cases, the hardware resources are not allocated. */
	Idle = 0,
	/** Device is in use */
	Playing = 1,
	/** Something failed while trying to use the device */
	Failed = 2
};


/////////////////////////


/** The maximum length of data chunk in bytes that can be sent and received */
#macro EOS_RTCDATA_MAX_PACKET_SIZE 1170

enum EOS_RTCDataStatus
{
	/** Data unsupported */
	Unsupported = 0,
	/** Data enabled */
	Enabled = 1,
	/** Data disabled */
	Disabled = 2
};


