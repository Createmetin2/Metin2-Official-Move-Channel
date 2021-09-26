//Find
bool CHARACTER::WarpSet(long x, long y, long lPrivateMapIndex)

///Change
#if defined(__BL_MOVE_CHANNEL__)
bool CHARACTER::WarpSet(long x, long y, long lPrivateMapIndex, long lCustomAddr, WORD wCustomPort)
#else
bool CHARACTER::WarpSet(long x, long y, long lPrivateMapIndex)
#endif

//Find
	p.lAddr = lAddr;
	p.wPort = wPort;

///Change
#if defined(__BL_MOVE_CHANNEL__)
	p.lAddr	= lCustomAddr ? lCustomAddr : lAddr;
	p.wPort	= wCustomPort ? wCustomPort : wPort;
#else
	p.lAddr = lAddr;
	p.wPort = wPort;
#endif

///Add to end
#if defined(__BL_MOVE_CHANNEL__)
EVENTINFO(move_channel_info)
{
	LPCHARACTER		ch;
	int				left_second;
	long			lAddr;
	WORD			wPort;

	move_channel_info(const LPCHARACTER m_ch, const int m_sec, const long m_Addr, const WORD m_Port) :
		ch(m_ch),
		left_second(m_sec),
		lAddr(m_Addr),
		wPort(m_Port)
	{}
};

EVENTFUNC(move_channel_event)
{
	move_channel_info* info = dynamic_cast<move_channel_info*>(event->info);

	if (info == nullptr)
	{
		sys_err("<move_channel_event> <Factor> Null pointer");
		return 0;
	}

	const LPCHARACTER ch = info->ch;
	if (ch == nullptr)
		return 0;

	if (info->left_second <= 0)
	{
		ch->m_pkTimedEvent = nullptr;
		ch->WarpSet(ch->GetX(), ch->GetY(), 0, info->lAddr, info->wPort);
		return 0;
	}
	else
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("%d초 남았습니다."), info->left_second);
		--info->left_second;
	}

	return PASSES_PER_SEC(1);
}

void CHARACTER::MoveChannel(const TRespondMoveChannel* p)
{
	if (p == nullptr)
		return;
	
	const LPDESC d = GetDesc();
	if (d == nullptr)
		return;

	if (p->wPort == 0 
		|| p->lAddr == 0)
	{
		ChatPacket(CHAT_TYPE_INFO, "Currently, you cannot switch to that channel.");
		return;
	}

	if (m_pkTimedEvent)
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("취소 되었습니다."));
		event_cancel(&m_pkTimedEvent);
		return;
	}

	ChatPacket(CHAT_TYPE_INFO, "Please wait a moment. Changing channel...");
	if (IsHack(false, true, 10))
		return;

	m_pkTimedEvent = event_create(move_channel_event, 
		new move_channel_info(this, IsPosition(POS_FIGHTING) ? 10 : 3, p->lAddr, p->wPort), 1);
}
#endif