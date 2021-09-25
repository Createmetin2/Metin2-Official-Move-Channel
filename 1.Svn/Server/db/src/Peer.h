//Find
	BYTE	GetChannel()			{ return m_bChannel; }

///Add
#if defined(__BL_MOVE_CHANNEL__)
	void	SetAddr(const long l) { m_lAddr = l; };
	long	GetAddr() const { return m_lAddr; };
	bool	CheckMapIndex(const long lMapIndex) const;
#endif

//Find
	DWORD	m_dwUserCount;

///Add
#if defined(__BL_MOVE_CHANNEL__)
	long	m_lAddr;
#endif