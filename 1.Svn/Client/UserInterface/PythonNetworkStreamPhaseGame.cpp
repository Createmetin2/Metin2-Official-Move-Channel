///Add
#if defined(__BL_MOVE_CHANNEL__)
bool CPythonNetworkStream::SendMoveChannelPacket(const BYTE bChannelIndex)
{
	TPacketCGMoveChannel p;
	p.header = HEADER_CG_MOVE_CHANNEL;
	p.channel = bChannelIndex;

	if (!Send(sizeof(p), &p))
	{
		Tracef("CPythonNetworkStream::SendMoveChannelPacket Error\n");
		return false;
	}

	return SendSequence();
}
#endif