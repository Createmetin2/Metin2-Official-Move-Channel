///Add
#if defined(__BL_MOVE_CHANNEL__)
void CInputMain::MoveChannel(LPCHARACTER ch, const char* c_pData)
{
	const TPacketCGMoveChannel* p = reinterpret_cast<const TPacketCGMoveChannel*>(c_pData);
	if (p == nullptr)
		return;
	
	if (ch->m_pkTimedEvent)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("취소 되었습니다."));
		event_cancel(&ch->m_pkTimedEvent);
		return;
	}
	
	const BYTE bChannel = p->channel;

	if (bChannel == g_bChannel
		|| g_bAuthServer
		|| g_bChannel == 99
		|| ch->GetMapIndex() >= 1000
		|| ch->GetDungeon()
		|| ch->CanWarp() == false
		)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "You cannot change channel.");
		return;
	}

	TMoveChannel t{ bChannel, ch->GetMapIndex() };
	db_clientdesc->DBPacket(HEADER_GD_MOVE_CHANNEL, ch->GetDesc()->GetHandle(), &t, sizeof(t));
}
#endif

//Find
		case HEADER_CG_MALL_CHECKOUT:
			SafeboxCheckout(ch, c_pData, true);
			break;

///Add
#if defined(__BL_MOVE_CHANNEL__)
		case HEADER_CG_MOVE_CHANNEL:
			MoveChannel(ch, c_pData);
			break;
#endif