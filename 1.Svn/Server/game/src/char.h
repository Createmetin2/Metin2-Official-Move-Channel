//Find
		bool			WarpSet(long x, long y, long lRealMapIndex = 0);

///Change
#if defined(__BL_MOVE_CHANNEL__)
		void			MoveChannel(const TRespondMoveChannel* p);
		bool			WarpSet(long x, long y, long lRealMapIndex = 0, long lCustomAddr = 0, WORD wCustomPort = 0);
#else
		bool			WarpSet(long x, long y, long lRealMapIndex = 0);
#endif