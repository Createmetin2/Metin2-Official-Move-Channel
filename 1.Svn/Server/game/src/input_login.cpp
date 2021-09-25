///Add to end of void CInputLogin::Entergame(LPDESC d, const char * data)
#if defined(__BL_MOVE_CHANNEL__)
	ch->ChatPacket(CHAT_TYPE_COMMAND, "server_info %d %ld", g_bChannel, ch->GetMapIndex());
#endif