Attribute VB_Name = "Module1"

'��ʼ��API����
Public Declare Function CLIENT_Init Lib "dhnetsdk.dll" (ByVal fDisConnect As Long, _
ByVal wDVRPort As Long) As Long

'��¼API
Public Declare Function CLIENT_Login Lib "dhnetsdk.dll" _
(ByVal pchDVRIP As String, _
ByVal wDVRPort As Long, _
ByVal pchUserName As String, _
ByVal pchPassword As String, _
lpDeviceInfo As NET_DEVICEINFO, _
ByRef error As NET_RET_ERROR) As Long

'�ǳ��豸
Public Declare Function CLIENT_Logout Lib "dhnetsdk.dll" (ByVal lLoginID As Long) As Long

'ʵʱ����API
Public Declare Function CLIENT_RealPlay Lib "dhnetsdk.dll" _
(ByVal lLoginID As Long, ByVal nChannelID As Long, ByVal hwnd As Long) As Long

Public Declare Function CLIENT_RealPlayEx Lib "dhnetsdk.dll" _
(ByVal lLoginID As Long, ByVal nChannelID As Long, ByVal hwnd As Long, _
ByVal rType As Long) As Long

'ֹͣ����
Public Declare Function CLIENT_StopRealPlayEx Lib "dhnetsdk.dll" (ByVal lLoginID As Long) As Long

Public Declare Sub CLIENT_Cleanup Lib "dhnetsdk.dll" ()

'״̬����API
Public Declare Function CLIENT_StartListen Lib "dhnetsdk.dll" _
(ByVal lLoginID As Long) As Long

'��Ϣ�ص�API
Public Declare Function CLIENT_SetDVRMessCallBack Lib "dhnetsdk.dll" (ByVal fMessCallBack As Long, _
ByVal dwUser As Long) As Long


