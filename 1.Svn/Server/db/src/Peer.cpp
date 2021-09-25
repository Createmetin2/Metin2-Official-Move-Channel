//Find
	m_wP2PPort = 0;

///Add
#if defined(__BL_MOVE_CHANNEL__)
	m_lAddr = 0;
#endif

//Find
void CPeer::SetMaps(long * pl)
{
	...
}

///Add
#if defined(__BL_MOVE_CHANNEL__)
bool CPeer::CheckMapIndex(const long lMapIndex) const
{
	return std::find(std::begin(m_alMaps), std::end(m_alMaps), lMapIndex) != std::end(m_alMaps);
}
#endif