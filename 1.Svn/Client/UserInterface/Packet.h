//Find
	HEADER_CG_STATE_CHECKER					= 206,

///Add
#if defined(__BL_MOVE_CHANNEL__)
	HEADER_CG_MOVE_CHANNEL = 229,
#endif

//Find
typedef struct command_position
{   
	...
} TPacketCGPosition;

///Add
#if defined(__BL_MOVE_CHANNEL__)
typedef struct command_move_channel
{
	BYTE		header;
	BYTE		channel;
} TPacketCGMoveChannel;
#endif