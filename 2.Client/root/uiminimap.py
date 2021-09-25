#Find
	def ScaleDown(self):
		miniMap.ScaleDown()

#Add
	if app.BL_MOVE_CHANNEL:
		def RefreshServerInfo(self):
			self.serverInfo.SetText(net.GetServerInfo())