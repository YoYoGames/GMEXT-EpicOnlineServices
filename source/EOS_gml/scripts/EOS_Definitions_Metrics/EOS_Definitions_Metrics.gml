
/** User game controller types. */
enum EOS_UserControllerType
{
	/** The game controller type is unknown. */
	Unknown = 0,
	/** Mouse and keyboard controller. */
	MouseKeyboard = 1,
	/** Gamepad controller. */
	GamepadControl = 2,
	/** Touch controller. */
	TouchControl = 3
}

/** Account ID type for EOS_Metrics_BeginPlayerSession and EOS_Metrics_EndPlayerSession. */
enum EOS_MetricsAccountIdType
{
	/** An Epic Account ID. */
	Epic = 0,
	/** An external service Account ID. */
	External = 1
}


