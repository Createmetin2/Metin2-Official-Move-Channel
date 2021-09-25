#Find
			channelName = localeInfo.CHANNEL_NORMAL % channelID

#Change
			channelName = localeInfo.CHANNEL_NORMAL % channelID

		if app.BL_MOVE_CHANNEL:
			net.ClearServerInfo()
			channelMax = len(serverInfo.REGION_DICT[regionID][serverID]["channel"])
			for i in xrange(1, channelMax+1):
				_channelName = serverInfo.REGION_DICT[regionID][serverID]["channel"][i]["name"]
				net.SetChannelName(i, _channelName.strip())
				
			net.SetChannelName(99, localeInfo.MOVE_CHANNEL_99)
			
			net.SetChannelName(channelID)
			net.SetServerName(serverName)