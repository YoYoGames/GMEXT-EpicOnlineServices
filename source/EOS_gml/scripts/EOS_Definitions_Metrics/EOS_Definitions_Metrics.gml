
/** User game controller types. */
enum EOS_USER_CONTROLLER_TYPE
{
	/** The game controller type is unknown. */
	UNKNOWN = 0,
	/** Mouse and keyboard controller. */
	MOUSE_KEYBOARD = 1,
	/** Gamepad controller. */
	GAMEPAD_CONTROL = 2,
	/** Touch controller. */
	TOUCH_CONTROL = 3
}

/** Account ID type for EOS_Metrics_BeginPlayerSession and EOS_Metrics_EndPlayerSession. */
enum EOS_METRIC_ACCOUNT_ID_TYPE
{
	/** An Epic Account ID. */
	EPIC = 0,
	/** An external service Account ID. */
	EXTERNAL = 1
}


