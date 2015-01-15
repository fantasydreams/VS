unit dhnetsdk;

interface

uses
        SysUtils,WinTypes;

type
(************************************************************************
 ** 服务器断开回调原形
 ***********************************************************************)
        fDisConnect = procedure (lLoginID: LongInt; strDVRIP: Pchar; nDVRPort: LongInt;  dwUser: LongWord); stdcall;

(************************************************************************
 ** 回调原形
 ***********************************************************************)
        fMessCallBack = function (lCommand,lLoginID:LongInt; var pBuf;
			dwBufLen:LongWord; strDVRIP:Pchar; nDVRPort:LongInt; dwUser: LongWord ):LongBool;stdcall;

(************************************************************************
 ** 屏幕叠加回调原形
 ***********************************************************************)
        fDrawCallBack = procedure (lLoginID,lPlayHandle:LongInt; hDC: THandle; dwUser:LongInt);stdcall;

(************************************************************************
 ** 设备信息
 ***********************************************************************)
        NET_DEVICEINFO=Record
	        sSerialNumber: array [0..47] of Byte;	//序列号
        	byAlarmInPortNum: byte;				//DVR报警输入个数
	        byAlarmOutPortNum:BYTE;				//DVR报警输出个数
        	byDiskNum:BYTE;						//DVR 硬盘个数
	        byDVRType:BYTE ;						//DVR类型,
        	byChanNum:BYTE;						//DVR 通道个数
        end;

(************************************************************************
 ** SDK初始化
 ***********************************************************************)
function  CLIENT_Init( cbDisConnect: fDisConnect; dwUser:LongWord): LongBool; stdcall; 

(************************************************************************
 ** SDK退出清理
 ***********************************************************************)
procedure CLIENT_Cleanup() ; stdcall;

(************************************************************************
 ** 设置连接服务器超时时间和尝试次数
 ***********************************************************************)
procedure CLIENT_SetConnectTime(nWaitTime: Integer; nTryTimes: Integer);stdcall; 


(************************************************************************
 ** 获取SDK的版本信息
 ***********************************************************************)
function CLIENT_GetSDKVersion(): LongWord;stdcall; 


(************************************************************************
 ** 向设备注册
 ***********************************************************************)
function CLIENT_Login(strDVRIP: pAnsiChar; wDVRPort: WORD; strUserName: pAnsiChar; strPassword: pAnsiChar; var netDeviceInfo: NET_DEVICEINFO; error:Pinteger):LongInt;stdcall;


(************************************************************************
 ** 向设备注销
 ***********************************************************************)
function CLIENT_Logout(lLoginID: LongInt):LongBool;stdcall; 



(************************************************************************
 **
 ***********************************************************************)
procedure CLIENT_SetDVRMessCallBack(cbMessage:fMessCallBack; dwUser:LongWord);stdcall; 


(************************************************************************
 ** 设置屏幕叠加回调
 ***********************************************************************)
procedure CLIENT_RigisterDrawFun(cbDraw:fDrawCallBack; dwUser:LongWord);stdcall; 


(************************************************************************
 ** 开始实时预览
 ***********************************************************************)
function CLIENT_RealPlay(lLoginID:LongInt; nChannelID:Integer; hWnd:HWND):LongInt;stdcall; 


(************************************************************************
 ** 停止实时预览
 ***********************************************************************)
function CLIENT_StopRealPlay(lRealHandle:LongInt):LongBool;stdcall; 


implementation


function  CLIENT_Init; external 'dhnetsdk.dll';
procedure CLIENT_Cleanup; external 'dhnetsdk.dll';
procedure CLIENT_SetConnectTime; external 'dhnetsdk.dll';
function CLIENT_Login; external 'dhnetsdk.dll';
function CLIENT_Logout; external 'dhnetsdk.dll';
procedure CLIENT_SetDVRMessCallBack; external 'dhnetsdk.dll';
procedure CLIENT_RigisterDrawFun; external 'dhnetsdk.dll';
function CLIENT_RealPlay; external 'dhnetsdk.dll';
function CLIENT_StopRealPlay; external 'dhnetsdk.dll';
function CLIENT_GetSDKVersion;external 'dhnetsdk.dll';

end.

