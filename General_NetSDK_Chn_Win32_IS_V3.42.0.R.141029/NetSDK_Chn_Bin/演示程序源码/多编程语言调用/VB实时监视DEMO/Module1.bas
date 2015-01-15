Attribute VB_Name = "Module1"

'初始化API声明
Public Declare Function CLIENT_Init Lib "dhnetsdk.dll" (ByVal fDisConnect As Long, _
ByVal wDVRPort As Long) As Long

'登录API
Public Declare Function CLIENT_Login Lib "dhnetsdk.dll" _
(ByVal pchDVRIP As String, _
ByVal wDVRPort As Long, _
ByVal pchUserName As String, _
ByVal pchPassword As String, _
lpDeviceInfo As NET_DEVICEINFO, _
ByRef error As NET_RET_ERROR) As Long

'登出设备
Public Declare Function CLIENT_Logout Lib "dhnetsdk.dll" (ByVal lLoginID As Long) As Long

'实时监视API
Public Declare Function CLIENT_RealPlay Lib "dhnetsdk.dll" _
(ByVal lLoginID As Long, ByVal nChannelID As Long, ByVal hwnd As Long) As Long

Public Declare Function CLIENT_RealPlayEx Lib "dhnetsdk.dll" _
(ByVal lLoginID As Long, ByVal nChannelID As Long, ByVal hwnd As Long, _
ByVal rType As Long) As Long

'停止监视
Public Declare Function CLIENT_StopRealPlayEx Lib "dhnetsdk.dll" (ByVal lLoginID As Long) As Long

Public Declare Sub CLIENT_Cleanup Lib "dhnetsdk.dll" ()

'状态侦听API
Public Declare Function CLIENT_StartListen Lib "dhnetsdk.dll" _
(ByVal lLoginID As Long) As Long

'消息回调API
Public Declare Function CLIENT_SetDVRMessCallBack Lib "dhnetsdk.dll" (ByVal fMessCallBack As Long, _
ByVal dwUser As Long) As Long


