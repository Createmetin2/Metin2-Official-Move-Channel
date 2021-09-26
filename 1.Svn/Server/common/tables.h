///Add
#include "service.h"

//Find
	HEADER_GD_REQUEST_CHANNELSTATUS	= 140,

///Add
#if defined(__BL_MOVE_CHANNEL__)
	HEADER_GD_MOVE_CHANNEL = 152,
#endif

//Find
	HEADER_DG_RESPOND_CHANNELSTATUS		= 181,

///Add
#if defined(__BL_MOVE_CHANNEL__)
	HEADER_DG_RESPOND_MOVE_CHANNEL = 188,
#endif

//Find
typedef struct SSafeboxLoadPacket
{
	...
} TSafeboxLoadPacket;

///Add
#if defined(__BL_MOVE_CHANNEL__)
typedef struct SMoveChannel
{
	BYTE	bChannel;
	long	lMapIndex;
} TMoveChannel;

typedef struct SRespondMoveChannel
{
	WORD	wPort;
	long	lAddr;
} TRespondMoveChannel;
#endif