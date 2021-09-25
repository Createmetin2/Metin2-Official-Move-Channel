//Find
		bool RecvMallItemDelPacket();

///Add
#if defined(__BL_MOVE_CHANNEL__)
		bool SendMoveChannelPacket(const BYTE bChannelIndex);
#endif