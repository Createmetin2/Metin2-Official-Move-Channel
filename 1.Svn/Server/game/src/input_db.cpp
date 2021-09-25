///Add
#if defined(__BL_MOVE_CHANNEL__)
void CInputDB::MoveChannelRespond(LPDESC d, const char* c_pData)
{
	if (d == nullptr)
		return;

	const LPCHARACTER ch = d->GetCharacter();
	if (ch == nullptr)
		return;

	ch->MoveChannel(reinterpret_cast<const TRespondMoveChannel*>(c_pData));
}
#endif

//Find
	case HEADER_DG_SAFEBOX_CHANGE_SIZE:
		SafeboxChangeSize(DESC_MANAGER::instance().FindByHandle(m_dwHandle), c_pData);
		break;

///Add
#if defined(__BL_MOVE_CHANNEL__)
	case HEADER_DG_RESPOND_MOVE_CHANNEL:
		MoveChannelRespond(DESC_MANAGER::instance().FindByHandle(m_dwHandle), c_pData);
		break;
#endif