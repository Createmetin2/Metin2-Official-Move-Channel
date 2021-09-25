///Add
#if defined(__BL_MOVE_CHANNEL__)
static std::map<int, std::string> g_ChannelNameMap;
static std::string gs_ServerName{};
static int gi_ChannelIndex{};
static long gl_MapIndex{};
#endif

///Change netGetServerInfo
PyObject* netGetServerInfo(PyObject* poSelf, PyObject* poArgs)
{
#if defined(__BL_MOVE_CHANNEL__)
	auto it = g_ChannelNameMap.find(gi_ChannelIndex);
	if (it != g_ChannelNameMap.end())
		gs_stServerInfo = gs_ServerName + ", " + it->second;
#endif
	return Py_BuildValue("s", gs_stServerInfo.c_str());
}

///Add
#if defined(__BL_MOVE_CHANNEL__)
PyObject* netSetChannelName(PyObject* poSelf, PyObject* poArgs)
{
	switch (PyTuple_Size(poArgs))
	{
	case 1:
	{
		int iChannelIndex;
		if (!PyTuple_GetInteger(poArgs, 0, &iChannelIndex))
			return Py_BuildException();

		gi_ChannelIndex = iChannelIndex;
	}
	break;
	case 2:
	{
		int iChannelIndex;
		if (!PyTuple_GetInteger(poArgs, 0, &iChannelIndex))
			return Py_BuildException();

		char* szChannelName;
		if (!PyTuple_GetString(poArgs, 1, &szChannelName))
			return Py_BuildException();

		g_ChannelNameMap[iChannelIndex] = szChannelName;
	}
	break;
	default:
		return Py_BuildException();
	}

	return Py_BuildNone();
}

PyObject* netGetChannelName(PyObject* poSelf, PyObject* poArgs)
{
	int iChannelIndex;
	if (!PyTuple_GetInteger(poArgs, 0, &iChannelIndex))
		return Py_BuildException();

	auto it = g_ChannelNameMap.find(iChannelIndex);
	if (it != g_ChannelNameMap.end())
		return Py_BuildValue("s", it->second.c_str());

	return Py_BuildValue("s", "");
}

PyObject* netGetChannelNumber(PyObject* poSelf, PyObject* poArgs)
{
	return Py_BuildValue("i", gi_ChannelIndex);
}

PyObject* netGetChannelCount(PyObject* poSelf, PyObject* poArgs)
{
	return Py_BuildValue("i", g_ChannelNameMap.size());
}

PyObject* netSetMapIndex(PyObject* poSelf, PyObject* poArgs)
{
	long lMapIndex;
	if (!PyTuple_GetLong(poArgs, 0, &lMapIndex))
		return Py_BuildException();

	gl_MapIndex = lMapIndex;

	return Py_BuildNone();
}

PyObject* netGetMapIndex(PyObject* poSelf, PyObject* poArgs)
{
	return Py_BuildValue("i", gl_MapIndex);
}

PyObject* netSetServerName(PyObject* poSelf, PyObject* poArgs)
{
	char* szServerName;
	if (!PyTuple_GetString(poArgs, 0, &szServerName))
		return Py_BuildException();

	gs_ServerName = szServerName;
	return Py_BuildNone();
}

PyObject* netClearServerInfo(PyObject* poSelf, PyObject* poArgs)
{
	g_ChannelNameMap.clear();

	return Py_BuildNone();
}

PyObject* netMoveChannelGame(PyObject* poSelf, PyObject* poArgs)
{
	BYTE bChannelIndex;
	if (!PyTuple_GetByte(poArgs, 0, &bChannelIndex))
		return Py_BuildException();

	CPythonNetworkStream& rkNetStream = CPythonNetworkStream::Instance();
	rkNetStream.SendMoveChannelPacket(bChannelIndex);
	return Py_BuildNone();
}
#endif

//Find
		{ "GetServerInfo",						netGetServerInfo,						METH_VARARGS },

///Add
#if defined(__BL_MOVE_CHANNEL__)		
		{ "SetChannelName",						netSetChannelName,						METH_VARARGS },
		{ "GetChannelName",						netGetChannelName,						METH_VARARGS },

		{ "GetChannelNumber",					netGetChannelNumber,					METH_VARARGS },
		{ "GetChannelCount",					netGetChannelCount,						METH_VARARGS },

		{ "SetMapIndex",						netSetMapIndex,							METH_VARARGS },
		{ "GetMapIndex",						netGetMapIndex,							METH_VARARGS },
		
		{ "SetServerName",						netSetServerName,						METH_VARARGS },		
		{ "ClearServerInfo",					netClearServerInfo,						METH_VARARGS },

		{ "MoveChannelGame",					netMoveChannelGame,						METH_VARARGS },
#endif