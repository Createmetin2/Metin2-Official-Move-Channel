//Find
void CClientManager::QUERY_SAFEBOX_LOAD(CPeer * pkPeer, DWORD dwHandle, TSafeboxLoadPacket * packet, bool bMall)
{
	...
}

///Add
#if defined(__BL_MOVE_CHANNEL__)
void CClientManager::QUERY_MOVE_CHANNEL(CPeer* pkPeer, DWORD dwHandle, TMoveChannel* data)
{
	auto it = std::find_if(m_peerList.begin(), m_peerList.end(), [data](CPeer* p) {
		return p->GetChannel() == data->bChannel;
	});

	TRespondMoveChannel t{};

	if (it != m_peerList.end())
	{
		CPeer* p = *it;
		if (p && p != pkPeer && p->CheckMapIndex(data->lMapIndex))
			t = { p->GetListenPort(), p->GetAddr() };
	}

	pkPeer->EncodeHeader(HEADER_DG_RESPOND_MOVE_CHANNEL, dwHandle, sizeof(TRespondMoveChannel));
	pkPeer->Encode(&t, sizeof(t));
}
#endif

//Find
	peer->SetPublicIP(p->szPublicIP);

///Add
#if defined(__BL_MOVE_CHANNEL__)
	peer->SetAddr(inet_addr(p->szPublicIP));
#endif

//Find
			case HEADER_GD_SAFEBOX_CHANGE_SIZE:
				QUERY_SAFEBOX_CHANGE_SIZE(peer, dwHandle, (TSafeboxChangeSizePacket *) data);
				break;

///Add
#if defined(__BL_MOVE_CHANNEL__)
			case HEADER_GD_MOVE_CHANNEL:
				QUERY_MOVE_CHANNEL(peer, dwHandle, (TMoveChannel*)data);
				break;
#endif