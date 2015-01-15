unit dhnetsdk;

interface

uses
        SysUtils,WinTypes;

type
(************************************************************************
 ** �������Ͽ��ص�ԭ��
 ***********************************************************************)
        fDisConnect = procedure (lLoginID: LongInt; strDVRIP: Pchar; nDVRPort: LongInt;  dwUser: LongWord); stdcall;

(************************************************************************
 ** �ص�ԭ��
 ***********************************************************************)
        fMessCallBack = function (lCommand,lLoginID:LongInt; var pBuf;
			dwBufLen:LongWord; strDVRIP:Pchar; nDVRPort:LongInt; dwUser: LongWord ):LongBool;stdcall;

(************************************************************************
 ** ��Ļ���ӻص�ԭ��
 ***********************************************************************)
        fDrawCallBack = procedure (lLoginID,lPlayHandle:LongInt; hDC: THandle; dwUser:LongInt);stdcall;

(************************************************************************
 ** �豸��Ϣ
 ***********************************************************************)
        NET_DEVICEINFO=Record
	        sSerialNumber: array [0..47] of Byte;	//���к�
        	byAlarmInPortNum: byte;				//DVR�����������
	        byAlarmOutPortNum:BYTE;				//DVR�����������
        	byDiskNum:BYTE;						//DVR Ӳ�̸���
	        byDVRType:BYTE ;						//DVR����,
        	byChanNum:BYTE;						//DVR ͨ������
        end;

(************************************************************************
 ** SDK��ʼ��
 ***********************************************************************)
function  CLIENT_Init( cbDisConnect: fDisConnect; dwUser:LongWord): LongBool; stdcall; 

(************************************************************************
 ** SDK�˳�����
 ***********************************************************************)
procedure CLIENT_Cleanup() ; stdcall;

(************************************************************************
 ** �������ӷ�������ʱʱ��ͳ��Դ���
 ***********************************************************************)
procedure CLIENT_SetConnectTime(nWaitTime: Integer; nTryTimes: Integer);stdcall; 


(************************************************************************
 ** ��ȡSDK�İ汾��Ϣ
 ***********************************************************************)
function CLIENT_GetSDKVersion(): LongWord;stdcall; 


(************************************************************************
 ** ���豸ע��
 ***********************************************************************)
function CLIENT_Login(strDVRIP: pAnsiChar; wDVRPort: WORD; strUserName: pAnsiChar; strPassword: pAnsiChar; var netDeviceInfo: NET_DEVICEINFO; error:Pinteger):LongInt;stdcall;


(************************************************************************
 ** ���豸ע��
 ***********************************************************************)
function CLIENT_Logout(lLoginID: LongInt):LongBool;stdcall; 



(************************************************************************
 **
 ***********************************************************************)
procedure CLIENT_SetDVRMessCallBack(cbMessage:fMessCallBack; dwUser:LongWord);stdcall; 


(************************************************************************
 ** ������Ļ���ӻص�
 ***********************************************************************)
procedure CLIENT_RigisterDrawFun(cbDraw:fDrawCallBack; dwUser:LongWord);stdcall; 


(************************************************************************
 ** ��ʼʵʱԤ��
 ***********************************************************************)
function CLIENT_RealPlay(lLoginID:LongInt; nChannelID:Integer; hWnd:HWND):LongInt;stdcall; 


(************************************************************************
 ** ֹͣʵʱԤ��
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

