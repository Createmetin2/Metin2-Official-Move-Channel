#Add
if app.BL_MOVE_CHANNEL:
	import chat

#Find
		self.gameOptionDlg = None

#Add
		if app.BL_MOVE_CHANNEL:
			self.moveChannelDlg = None

#Find(x2)
		self.GetChild("cancel_button").SAFE_SetEvent(self.Close)

#Add(x2)
		if app.BL_MOVE_CHANNEL:
			self.GetChild("movechannel_button").SAFE_SetEvent(self.__ClickMoveChannelButton)

#Find
	def OnPressEscapeKey(self):
		self.Close()
		return True

#Add
	if app.BL_MOVE_CHANNEL:
		def __ClickMoveChannelButton(self):
			## 99 서버 예외 처리 
			if net.GetChannelNumber() == 99:
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.MOVE_CHANNEL_NOT_MOVE)
				return
			## 인스턴스 던전 예외처리
			elif net.GetMapIndex() >= 10000:
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeInfo.MOVE_CHANNEL_NOT_MOVE)
				return
			
			if self.moveChannelDlg:
				self.moveChannelDlg.Show()
			else:
				moveChannelDlg = MoveChannelDialog()
				moveChannelDlg.Show()
				self.moveChannelDlg = moveChannelDlg
			
			self.Close()

#Find
if __name__ == "__main__":

#Add Above
if app.BL_MOVE_CHANNEL:
	class MoveChannelDialog(ui.ScriptWindow):
		def __init__(self):
			ui.ScriptWindow.__init__(self)
			self.__LoadDialog()
			
			self.IsShow = False
			
		def __del__(self):
			ui.ScriptWindow.__del__(self)
			
		def __LoadDialog(self) :	
			try:
				pyScrLoader = ui.PythonScriptLoader()
				pyScrLoader.LoadScriptFile(self, "UIScript/MoveChannelDialog.py")
			except:
				import exception
				exception.Abort("MoveChannelDialog.__LoadDialog")
			

			self.ParentBoard = self.GetChild("MoveChannelBoard")
			self.ChildBoard = self.GetChild("BlackBoard")
			self.GetChild("MoveChannelTitle").SetCloseEvent(ui.__mem_func__(self.Close))
			
			self.ChannelList = []
			cnt = net.GetChannelCount()
			cnt = cnt - 1 # 99서버 제외
			
			self.DlgWidht = 190
			self.BlackBoardHeight = 23*cnt + 5*(cnt-1) + 13
			self.DlgHeight = self.BlackBoardHeight + 75
			
			self.AcceptBtn = ui.MakeButton(self.ParentBoard, 13, self.DlgHeight - 33, "", "d:/ymir work/ui/public/", "middle_button_01.sub", "middle_button_02.sub", "middle_button_03.sub")
			self.AcceptBtn.SetText( localeInfo.MOVE_CHANNEL_SELECT )
			self.AcceptBtn.SetEvent(ui.__mem_func__(self.AcceptButton))
			self.CloseBtn = ui.MakeButton(self.ParentBoard, self.DlgWidht - 73, self.DlgHeight - 33, "", "d:/ymir work/ui/public/", "middle_button_01.sub", "middle_button_02.sub", "middle_button_03.sub")
			self.CloseBtn.SetText( localeInfo.MOVE_CHANNEL_CANCEL )
			self.CloseBtn.SetEvent(ui.__mem_func__(self.Close))

			for i in xrange(cnt):
				btn = ui.MakeButton(self.ChildBoard, 8, 6 + i*28, "", "d:/ymir work/ui/game/myshop_deco/", "select_btn_01.sub", "select_btn_02.sub", "select_btn_03.sub")
				btn.SetText(net.GetChannelName(i+1))
				btn.SetEvent(ui.__mem_func__(self.__SelectChannel), i+1)
				self.ChannelList.append(btn)
			
			self.ParentBoard.SetSize(self.DlgWidht, self.DlgHeight)
			self.ChildBoard.SetSize(self.DlgWidht - 26, self.BlackBoardHeight)
			self.SetSize(self.DlgWidht, self.DlgHeight)
			
			self.UpdateRect()
			
		def __SelectChannel(self, idx):
			self.ChangeChannelNumber = idx
			
			for btn in self.ChannelList:
				btn.SetUp()
				btn.Enable()
				
			self.ChannelList[idx-1].Down()
			self.ChannelList[idx-1].Disable()
			
		def AcceptButton(self):
			if self.ChangeChannelNumber == self.StartChannelNumber:
				return
			
			net.MoveChannelGame(self.ChangeChannelNumber)
			self.StartChannelNumber = self.ChangeChannelNumber
			self.Close()
						
		def Show(self) :
			ui.ScriptWindow.Show(self)
			
			self.StartChannelNumber = net.GetChannelNumber()
			self.__SelectChannel(self.StartChannelNumber)
			
			self.IsShow = True
		
		def Close(self):
			self.Hide()
			
			self.IsShow = False
			
		def OnPressEscapeKey(self):
			self.Close()
			return True
			
		def IsShowWindow(self):
			return self.IsShow