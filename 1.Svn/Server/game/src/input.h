//Find
		void 		PartyInvite(LPCHARACTER ch, const char * c_pData);

///Add
#if defined(__BL_MOVE_CHANNEL__)
		void		MoveChannel(LPCHARACTER ch, const char* c_pData);
#endif

//Find
	void		SafeboxLoad(LPDESC d, const char * c_pData);

///Add
#if defined(__BL_MOVE_CHANNEL__)
	void		MoveChannelRespond(LPDESC d, const char* c_pData);
#endif