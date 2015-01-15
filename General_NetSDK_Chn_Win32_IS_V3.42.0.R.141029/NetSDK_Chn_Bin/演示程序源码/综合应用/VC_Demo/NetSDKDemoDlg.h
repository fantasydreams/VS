// NetSDKDemoDlg.h : header file
//

#if !defined(AFX_NETSDKDEMODLG_H__874C22A9_455C_4113_9954_FDC1528EE15D__INCLUDED_)
#define AFX_NETSDKDEMODLG_H__874C22A9_455C_4113_9954_FDC1528EE15D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "searchrecord.h"
#include "clientState.h"
#include "exbutton.h"
#include "systemconfig.h"
#include "PlayWnd.h"
#include "ScreenPannel.h"
#include "PTZPannel.h"
#include "ColorPannel.h"
#include "PlayCtrlPannel.h"
#include "NormalBtnPannel.h"
#include "AdvanceBtnPannel.h"
#include "SaveDataPannel.h"
#include "SelectPannel.h"
#include "RuntimeMsgPannel.h"
#include "AudioBroadcastDlg.h"
#include "downloadbytime.h"
/////////////////////////////////////////////////////////////////////////////
// CNetSDKDemoDlg dialog

#define TIMER_KBPS 1999
#define CUR_MAXCHAN 16
#define	CUR_SPLIT	SPLIT16

//����ָ�����
enum{
	SPLIT1 = 0,
	SPLIT4,
	SPLIT9,
	SPLIT16,	
	SPLIT_TOTAL
};

//���ſ�������
enum{
	STATUS_STOP,
	STATUS_PAUSE,
	STATUS_PLAY,
	STATUS_STEP,
};

//������Ƶ����
enum{
	VIDEO_BRIGHT = 0,
	VIDEO_CONTRAST,
	VIDEO_HUE,
	VIDEO_SATURATION,
	VIDEO_TOTAL
};

//��̨���Ʋ���
enum{
	PTZ_START,
	PTZ_STOP
};
//������Ϣ����
typedef struct _SplitMonitorParam
{
	DeviceNode *pDevice;  //�豸ָ��
	int iChannel;   //��Ӧ���豸�е�ͨ�����
//	BOOL  isTalkOpen;  //�Ƿ�������Խ�
}SplitMonitorParam;

//����ط���Ϣ����
typedef struct _SplitNetPlayParam
{
//	DWORD iFilePos;  //�ļ���Ϣ�б�position/
	FileInfoNode *pFileInfo;   //�ļ���Ϣָ��
	int   iStatus;  //����״̬ ����/��ͣ/���/����
	int   iPlayPos;  //��ǰ���ŵ�λ��
}SplitNetPlayParam;

//ͨ��ʱ��ط�¼�����
typedef struct _SplitPBByTimeParam
{
	DeviceNode *pDevice;
	NET_TIME starttime;
	NET_TIME endtime;
	int nChannel;
	int npos;
	int iStatus;
}SplitPBByTimeParam;

//�໭��Ԥ����Ϣ����
typedef struct _SplitMulitPlayParam
{
	DeviceNode *pDevice;  //�豸ָ��
}SplitMultiPlayParam;

//��ѭ������Ϣ����
typedef struct _CycleChannelInfo
{
	DWORD dwDeviceID;
	int iChannel;
}CycleChannelInfo;
typedef struct _SplitCycleParam
{
	DeviceNode *pDevice;	//�豸ָ��
	CPtrList *pChannelList;	//��ѭͨ���б�
	int iChannelCount;		//ͨ����
	int iCurPosition;		//��ǰ����ͨ�����������λ��
	UINT iInterval;			//�����л����ʱ�䣨�룩
}SplitCycleParam;	
/*Begin: Add by yehao(10857) For Task.NO.11071 2006-12-26*/
typedef struct _TalkHandleInfo
{
	DeviceNode *pDevice;
	LONG		lHandle;
} TalkHandleInfo, *LPTalkHandleInfo;
/*End: yehao(10857) Task.NO.11071 */

class CNetSDKDemoDlg : public CDialog
{
// Construction
	int m_connectwaittime;  //�������ӵȴ�ʱ��
	int m_curScreen;   //��ǰ��ʾ�������
	int m_curSoundSplit;  //��ǰ����������ڵĻ������

	//�ڲ����������Ҫ���ӹ��ܺ���
	void *GetCurDeviceInfo();  //��õ�ǰ�豸�б�ѡ����豸����Ϣָ��
	void *FindDeviceInfo(LONG lLoginID, char *sDVRIP,LONG nDVRPort); //�����豸id����豸��Ϣָ��
	int GetHandleSplit(LONG lPlayHandle);   //����id,��õ�ǰ�������
	BOOL CheckCurSplitAndClose();  //��鵱ǰ���沢�ر�ͼ����ʾ;
	BOOL IsCycling(DWORD deviceID, int channelNo);   //�Ƿ�����ѵͨ��
	int  GetCurSplitStart(int nScreen, int nSplit);   //��ȡ��ǰ����ָ�ģʽ��ָ���������ʼ�������
	int  PlayStop(int iScreen, BOOL bDis = FALSE);    //����ֹͣ

	//������²�������
	void UpdateVideoCtrl(int nMode);      //ˢ����Ƶ����������
	void UpdateDeviceList();     //ˢ���豸�б�
	void UpdateDeviceState(void *pDevice, char *pBuf, DWORD dwBufLen); //�����豸��״̬
	
public:
	CNetSDKDemoDlg(CWnd* pParent = NULL);	// standard constructor


	//���ڻص��Ľӿ�
	void DeviceDisConnect(LONG lLoginID, char *sDVRIP,LONG nDVRPort);
	void DeviceReConnect(LONG lLoginID, char *sDVRIP,LONG nDVRPort);
	void ReceiveRealData(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize);
	BOOL ReceiveMessage(LONG lLoginID, LONG lCommand, char *pchDVRIP, LONG nDVRPort, 
		char *pBuf, DWORD dwBufLen);
	void AddDisplayInfo(LONG lLoginID, LONG lPlayHandle, HDC hDC);  //�����ַ���ͼƬ
	void ReceivePlayPos(LONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize);
	int  ListenCallBack_Imp(LONG lServerHandle, char* ip, WORD port, int nCmd, void* pParam);

	//����ɾ����ѭ����Ĳ���
	void DeleteCycleParam(int nScreen);

	//�豸�Ͽ�ʱ�ص�������������������Ͽ����豸�б�ĸ��¼��豸��ɾ������
	friend void CALLBACK DisConnectFunc(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser);
	//�������ݻص�����,�����������ص����ݱ�����ļ�
	friend void CALLBACK RealDataCallBack(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, 
		DWORD dwBufSize, DWORD dwUser);
	//�ط����ݻص�������demo�ｫ���ݱ�����ļ�
	friend int CALLBACK PBDataCallBack(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, 
		DWORD dwBufSize, DWORD dwUser);
	friend void CALLBACK RealDataCallBackEx(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, 
		DWORD dwBufSize, LONG lParam, DWORD dwUser);
	//��Ϣ�ص�������,�Ƕ�����sdkӦ�õĻص�,��������ص������ı�����Ϣ
	friend BOOL CALLBACK MessCallBack(LONG lCommand, LONG lLoginID, char *pBuf, 
		DWORD dwBufLen, char *pchDVRIP, LONG nDVRPort);
	//�Զ��廭��ص�,����������ʾͨ������
	friend void CALLBACK ChannelAutoDraw(LONG lLoginID, LONG lPlayHandle, HDC hDC, DWORD dwUser);
		//���Ž���״̬�ص�����,���������������ʾ
	friend void CALLBACK PlayCallBack(LONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, DWORD dwUser);

	//�����������ص�
	friend  int CALLBACK ListenCallBack(LONG lServerHandle, char* ip, WORD port, int nCmd, void* pParam, DWORD dwUserData);
	//for stream parser
//	friend unsigned long __stdcall SpCallBack(PARSERHANDLE hHandle, PARSERMSG msg, 
//		unsigned long dwParam1, unsigned long dwParam2,
//		unsigned long dwUserData);

	//����״̬ҳ��
	CClientState  m_ClientStateDlg;
	
//	CSystemConfig m_SysConfig;
	// Dialog Data
	//{{AFX_DATA(CNetSDKDemoDlg)
	enum { IDD = IDD_NETSDKDEMO_DIALOG };
	CExButton	m_ptz_righttop;
	CExButton	m_ptz_rightdown;
	CExButton	m_ptz_lefttop;
	CExButton	m_ptz_leftdown;
	CExButton	m_zoom_wide;
	CExButton	m_zoom_tele;
	CExButton	m_focus_near;
	CExButton	m_focus_far;
	CExButton	m_iris_open;
	CExButton	m_iris_close;
	CExButton	m_ptz_up;
	CExButton	m_ptz_right;
	CExButton	m_ptz_left;
	CExButton	m_ptz_down;
	CComboBox	m_channelsel;
	CTreeCtrl	m_devicelist;
	int		m_play_frame;
	UINT	m_testvalue;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetSDKDemoDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL
	// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNetSDKDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDblclkTreeDevicelist(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	void OpenSingleChannel(DeviceNode *pInfo,int nCh, int screenNo, DH_RealPlayType subtype);	//��һ������ͨ��
	void OpenAllChannel(DeviceNode *pInfo, DH_RealPlayType subtype);					//��ѡ���豸�����м���ͨ��
	void PlayRecordFile(FileInfoNode* playfile, int scrNo);	//��һ��¼���ļ��Ĳ���
	BOOL ProcessCloseScreen(int scrNo, BOOL bDis = FALSE);  //ִ�йرջ���
	BOOL ProcessCloseAllChannel(DeviceNode *pInfo);			//ִ�йر�ѡ���豸������ͨ��
	void SwitchFullScreen();		//�л�ȫ�� 
//	void ReturnOrignalSplit(void);	//�ָ���������ָ�
	void UpdateScreen(int nSplit);	//ˢ����Ļ,��Ҫ��ˢ����Ƶ����

	void AddDevice();				//�ԡ�����豸����������Ӧ���� 
	void DeleteDevice();			//�ԡ�ɾ���豸����������Ӧ����
	void OpenChannel();				//�ԡ���ͨ������������Ӧ����
	void OpenMultiplay();			//�ԡ��໭��Ԥ������������Ӧ����
	void CloseScreen();				//�ԡ��رջ��桱��������Ӧ����
	void CloseAllChannel();			//�ԡ��ر��豸ͨ������������Ӧ����
	void SearchRecord();			//�ԡ�¼���ѯ����������Ӧ����
	void CycleMonitor();			//�ԡ���ѭ����������Ӧ����
	void Playbackbytime();			//�ԡ���ʱ��طš���������Ӧ����
	void Downloadbytime();			//�ԡ���ʱ�����ء���������Ӧ����
	void Sysconfig();				//�ԡ�ϵͳ���á���������Ӧ����
	void Sysconfig2();				//�ԡ�ϵͳ����<X>����������Ӧ����

	BOOL OpenSound(BOOL bOpen);		//��\�ر���Ƶ
	BOOL OpenTalk(BOOL bOpen);		//��\�رնԽ�
	void UpdateDevice();			//�ԡ��豸��������������Ӧ����
	void Recordstate();				//�ԡ�¼��״̬����������Ӧ����
	void RebootDevice();			//�ԡ������豸����������Ӧ����
	void AlarmIOctrl();				//�ԡ�����IO���ơ���������Ӧ����
	void ShutdownDevice();			//�ԡ��ر��豸����������Ӧ����
	void DeviceState();				//�ԡ��豸״̬����������Ӧ����
	void CaptureScreen();			//�ԡ�ץͼ����������Ӧ����
	void SetIframe();				//�ԡ�ǿ��I֡����������Ӧ����
	void ShowFluxInfo();			//�ԡ���ʾ��������������Ӧ����
	void Transcom();				//�ԡ�͸��ͨ������������Ӧ����
	void DDNS_QueryIP();				//�ԡ�DDNS��ѯIP����������Ӧ����
	void Getversion();				//�ԡ�SDK�汾����������Ӧ����
	void OpenAudioBroadcastDlg();	//�������㲥�Ĳ�������
	void ptzctrl();					//�ԡ���̨�˵�����������Ӧ����
	void Extptzctrl();				//�ԡ���̨��չ�˵�����������Ӧ����

	void SaveRealdata(int nCheck);			//����ʵʱ��������
	void SavecbdataRaw(int nCheck);				//����ص����ݣ�ԭʼ����
	void SavecbdataStd(int nCheck);			//����ص����ݣ���׼����
	void Savecbdatapcm(int nCheck);			//����ص����ݣ�pcm��Ƶ����
	void Savecbdatayuv(int nCheck);			//����ص����ݣ�yuv��Ƶ����
				
	void PtzControl(int type, BOOL stop, int param);   //��̨���Ʋ���
	void ProcessDeleteDevice(DeviceNode *pDevice,  BOOL bDelList, BOOL bDis = false); //ɾ���豸,nDelList�Ƿ�ɾ���豸�б�, bDis��ʾ�Ƿ����
	
	void NextCycleMonitor(UINT nID);	//����ѭ�б�����һ��ͨ��

	void CtrlColor_Bright(int pos);			//���ƻ�������
	void CtrlColor_Contrast(int pos);		//���ƻ���Աȶ�
	void CtrlColor_Saturation(int pos);		//���ƻ��汥�Ͷ�
	void CtrlColor_Hue(int pos);			//���ƻ���ɫ��

	BOOL SeekPlayPositon(int nPos);		//���Ž��������϶���Ӧ����
	BOOL PlayCtrl_Play();				//"����"\"��ͣ"������Ӧ����
	BOOL PlayCtrl_Stop();				//"ֹͣ"������Ӧ����
	BOOL PlayCtrl_Fast();				//"���"������Ӧ����
	BOOL PlayCtrl_Slow();				//"����"������Ӧ����
	BOOL PlayCtrl_Step();				//"��֡"������Ӧ����
	BOOL PlayCtrl_Frame(int frame);		//"��֡"������Ӧ����

	void GetDeviceWorkstate();			//"�豸����״̬"������Ӧ����
	void DeviceControldisk();			//"Ӳ�̿���"������Ӧ����
	void DeviceUserinfo();				//"�û���Ϣ"������Ӧ����
	
	void SeleteNormalPannel();			//��ʾ�����桱����ҳ��
	void SeleteAdvancePannel();			//��ʾ���߼�������ҳ��
	void SeleteSaveDataPannel();		//��ʾ�����ݱ��桱����ҳ��
	void SeletePTZPannel();				//��ʾ����̨���ơ�����ҳ��
	void SeleteColorPannel();			//��ʾ����ɫ����������ҳ��
	void SeletePlayCtrlPannel();		//��ʾ�����ſ��ơ�����ҳ��
	void SeleteDevListPannel();			//��ʾ���豸�б�����ҳ��
	
	void UpdatePannelPosition();			//���¸��Ӵ���λ��

	void LastError();						//��ʾ����ִ�г���ԭ��

	void SwitchMultiWnd(int nSplit);

	int	 GetCurWinID(void);

	void SetCurWindId(int nCuWinID)
	{
		m_curScreen = nCuWinID;
	}

	int UpdateDeviceListCallback_Imp(const DeviceNode& node);
	int WriteAlarmLogFunc_Imp(const AlarmNode& node);

	void TestProc(); //for test

	//for stream parser
//	void HandleParserMsg(PARSERHANDLE hHandle, PARSERMSG msg, 
//		unsigned long dwParam1, unsigned long dwParam2);

public:
	int GetCurScreen(){return m_curScreen;}
	void UpdateCurScreenInfo();  //ˢ�µ�ǰ����������Ϣ��ʾ
	void SetSplit(int split);
	int  GetSplit();
	//��ȡ���洰����Ϣ
	BOOL GetSplitInfo_Main(int nIndex, SplitInfoNode* info);
	BOOL SetSplitInfo_Main(int nIndex, SplitInfoNode* info);
	/*Begin: Add by yehao(10857) 2006-12-20*/
	static void CALLBACK AudioDataCallBack(LONG lTalkHandle, char *pDataBuf, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser);
	LONG GetTalkHandle();
	/*End: yehao(10857) */
private:
	/*Begin: Add by yehao(10857) For Task.NO.11071 2006-12-26*/
	BOOL RecordStart();
	BOOL RecordStop();
	/*End: yehao(10857) Task.NO.11071 */
private:
	BOOL		m_bPTZCtrl;		//��ʶPTZ����״̬
	
//	BOOL		m_bFullSCRN;		//��ʶ��ǰ�Ƿ�ȫ��״̬
	CRect		m_clientRect;		//�����������λ��
	CRect		m_screenRect;		//������Ļ�����λ��
	CRect		m_pannelRect;		//���湦����������λ��
	CRect		m_selectRect;		//���桰ѡ��ҳ�桱����λ��
	CRect		m_btnAreaRect;		//���湦�ܰ��������λ��
	CRect		m_runtimeMsgRect;			//���桰����ʱ��Ϣ������λ��

	CScreenPannel		m_screenPannel;		//������Ļ�װ壭�Ӵ���
//	CPlayWnd			m_playWnd[MAX_CHANNUM];		//�������Ż��棭�Ӵ���
//	CWnd				*m_originParent;	//��ʱ������Ӵ��ڵĸ�����
	CPTZPannel			m_ptzPannel;		//��̨������壭�Ӵ���
	CColorPannel		m_colorPannel;		//��ɫ������壭�Ӵ���
	CPlayCtrlPannel		m_playctrlPannel;	//�طſ�����壭�Ӵ���
	CNormalBtnPannel	m_normalBtnPannel;	//���湦�ܰ�����壭�Ӵ���
	CAdvanceBtnPannel	m_advanceBtnPannel;	//�߼����ܰ�����壭�Ӵ���
	CSaveDataPannel		m_saveDataPannel;	//���ݱ��水����壭�Ӵ���
	CSelectPannel		m_selectPannel;		//��ʾ��ѡ��ҳ�桱��������壭�Ӵ���
	CRuntimeMsgPannel	m_runtimeMsgPannel;	//��ʾ����ʱ��Ϣ����壭�Ӵ���
	/*Begin: Add by yehao(10857) 2006-12-22*/
	list<DeviceNode *>	m_broadcastDevList;
	CAudioBroadcastDlg	m_audioBroadcastDlg;
	BOOL				m_bRecord;
	TalkHandleInfo		m_talkhandle;
	unsigned int		m_uRecordCount;
	/*End: yehao(10857) 2006-12-22*/
	CBrush				m_myBrush;

	
#ifdef DH_STREAMPARSER
	//for stream parser
	PARSERHANDLE m_hSp;
	FILE         *m_spFile;
	BOOL		 m_bGetIFrame;
	int			 m_framecount;
#endif

	//download test
	CDownloadByTime m_dbByTime;

	//specified alarm test
	FILE	*m_almLogFile_Comm;
	FILE	*m_almLogFile_Shelter;
	FILE	*m_almLogFile_dFull;
	FILE	*m_almLogFile_dError;
	FILE	*m_almLogFile_SoundDec;
	
	DEV_STATE	m_lastAlarm;

	//listen device test
	LONG	m_lListenDevice;
	LONG	m_lListenChannel;
	typedef struct 
	{
		int state;
		char ip[16];
		WORD port;
		char serial[48];
	}LISTEN_DATA;
	LISTEN_DATA m_mylsdata;
};

 
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETSDKDEMODLG_H__874C22A9_455C_4113_9954_FDC1528EE15D__INCLUDED_)
