

#macro EOS_UI_EVENTID_INVALID 0

/** The most recent version of the EOS_UI_ShowFriends API. */
#macro EOS_UI_SHOWFRIENDS_API_LATEST 1

//??????
//#macro EOS_UI_KEY_CONSTANT(Prefix, Name, Value) Prefix ## Name = Value,
//#macro EOS_UI_KEY_MODIFIER(Prefix, Name, Value) Prefix ## Name = Value,
//#macro EOS_UI_KEY_MODIFIER_LAST(Prefix, Name, Value) Prefix ## Name = Value
//#macro EOS_UI_KEY_ENTRY_FIRST(Prefix, Name, Value) Prefix ## Name = Value,
//#macro EOS_UI_KEY_ENTRY(Prefix, Name) Prefix ## Name,
//#macro EOS_UI_KEY_CONSTANT_LAST(Prefix, Name) Prefix ## Name
//#undef EOS_UI_KEY_CONSTANT
//#undef EOS_UI_KEY_MODIFIER
//#undef EOS_UI_KEY_MODIFIER_LAST
//#undef EOS_UI_KEY_ENTRY_FIRST
//#undef EOS_UI_KEY_ENTRY
//#undef EOS_UI_KEY_CONSTANT_LAST

enum EOS_UI_NOTIFICATION_LOCATION
{
	TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_RIGHT
}
