//Find
	Set(HEADER_CG_ANSWER_MAKE_GUILD, sizeof(TPacketCGAnswerMakeGuild), "AnswerMakeGuild", true);

///Add
#if defined(__BL_MOVE_CHANNEL__)
	Set(HEADER_CG_MOVE_CHANNEL, sizeof(TPacketCGMoveChannel), "MoveChannel", true);
#endif