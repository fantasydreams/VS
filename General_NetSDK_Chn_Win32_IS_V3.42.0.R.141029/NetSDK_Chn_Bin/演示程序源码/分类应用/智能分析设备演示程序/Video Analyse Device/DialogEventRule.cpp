// DialogEventRule.cpp : implementation file
//

#include "stdafx.h"
#include "Real Load Picture.h"
#include "DialogEventRule.h"
#include "Utility.h"
#include "IvsModule.h"
#include <wingdi.h>
#include <assert.h>
#include <string>
#include "DialogPCQuery.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifdef WIN32
#pragma warning (disable:4786)
#endif

const int EVENT_TYPE_COUNT = 26;
char* strAlarmList[EVENT_TYPE_COUNT] = {"ALL",
"TRAFFICCONTROL", "TRAFFICACCIDENT","TRAFFICJUNCTION", "TRAFFICGATE","TRAFFICSNAPSHOT", 
"TRAFFICRUREDLIGHT","TRAFFICOVERLINE", "TRAFFICRETROGRADE", "TRAFFICTURNLEFT", "TRAFFICTURNRIGHT",
"TRAFFICUTURN", "TRAFFICOVERSPEED", "TRAFFICUNDERSPEED","TRAFFIC_YELLOWPLATEINLANE","TRAFFIC_DRIVINGONSHOULDER",
"TRAFFIC_OVERYELLOWLINE","TRAFFIC_CROSSLANE","TRAFFIC_WRONGROUTE","TRAFFIC_PARKING","TRAFFICJAM",
"TRAFFIC_FLOWSTATE","TRAFFIC_STAY","TRAFFIC_VEHICLEINROUTE","TRAFFIC_MANUALSNAP","TrafficPedestrainPriority"
};

//�����¼���ö������
int nAlarmTypeList[EVENT_TYPE_COUNT]={EVENT_IVS_ALL, 
EVENT_IVS_TRAFFICCONTROL,
EVENT_IVS_TRAFFICACCIDENT,
EVENT_IVS_TRAFFICJUNCTION, 
EVENT_IVS_TRAFFICGATE,
EVENT_TRAFFICSNAPSHOT,

EVENT_IVS_TRAFFIC_RUNREDLIGHT, 
EVENT_IVS_TRAFFIC_OVERLINE,
EVENT_IVS_TRAFFIC_RETROGRADE,
EVENT_IVS_TRAFFIC_TURNLEFT,
EVENT_IVS_TRAFFIC_TURNRIGHT,

EVENT_IVS_TRAFFIC_UTURN,
EVENT_IVS_TRAFFIC_OVERSPEED,
EVENT_IVS_TRAFFIC_UNDERSPEED,
EVENT_IVS_TRAFFIC_YELLOWPLATEINLANE,
EVENT_IVS_TRAFFIC_DRIVINGONSHOULDER,

EVENT_IVS_TRAFFIC_OVERYELLOWLINE,
EVENT_IVS_TRAFFIC_CROSSLANE,
EVENT_IVS_TRAFFIC_WRONGROUTE,
EVENT_IVS_TRAFFIC_PARKING,
EVENT_IVS_TRAFFICJAM,

EVENT_IVS_TRAFFIC_FLOWSTATE,
EVENT_IVS_TRAFFIC_STAY,
EVENT_IVS_TRAFFIC_VEHICLEINROUTE,
EVENT_IVS_TRAFFIC_MANUALSNAP,
EVENT_IVS_TRAFFIC_PEDESTRAINPRIORITY
};

void CALLBACK RealDataCallBackEx(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer,DWORD dwBufSize, LONG lParam, LDWORD dwUser)
{
	if(dwUser == 0)
	{
		return;
	}
	
	CDialogEventRule *dlg = (CDialogEventRule *)dwUser;
	dlg->ReceiveRealData(lRealHandle,dwDataType, pBuffer, dwBufSize);
}

//Process after receiving real-time data 
void CDialogEventRule::ReceiveRealData(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize)
{
	//Stream port number according to the real-time handle.
	long lRealPort= 450;
	//Input the stream data getting from the card
	BOOL bInput=FALSE;
	if(0 != lRealPort)
	{
		switch(dwDataType) {
		case 0:
			//Original data 
			bInput = g_PlayAPI.PLAY_InputData(lRealPort,pBuffer,dwBufSize);
			break;
		case 1:
			//Standard video data 
			
			break;
		case 2:
			//yuv data 
			
			break;
		case 3:
			//pcm audio data 
			
			break;
		case 4:
			//Original audio data 
			
			break;
		default:
			break;
		}	
	}
}
/////////////////////////////////////////////////////////////////////////////
// CDialogEventRule dialog


CDialogEventRule::CDialogEventRule(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogEventRule::IDD, pParent)
{
	m_pcQueryDlg = NULL;
	m_lLoginID = 0;
	m_lPlayID = 0;
	memset(&m_netDevInfo, 0, sizeof(m_netDevInfo));
	m_alarmCount = 0;

 	m_szBmpBuffer = new char[1024 * 1024 * 5];//���5M
	m_dwBmpBufferSize = 0;

	m_hBitmap = 0;
	m_MemDC = NULL;
	m_ClientDC = NULL;
	m_nWidth = 0;
	m_nHeight = 0;
	ZeroMemory(&m_rect, sizeof(RECT));
	memset(&m_nCurrentPicGroupId, 0, sizeof(GUID));
	InitializeCriticalSection(&m_csAlarmItems);

	CIvsModule::Init();
}

CDialogEventRule::~CDialogEventRule()
{
	//list �е�����
	std::list<ALARM_ITEM>::iterator iter = m_allAlarmItems.begin();
	for (; iter != m_allAlarmItems.end(); iter++)
	{
		delete[] ((*iter).pAlarmInfo);
	}

	if (NULL != m_Font)
	{
		m_Font->DeleteObject();
		delete m_Font;
	}

 	delete[] m_szBmpBuffer;
	delete m_ClientDC;
	delete m_MemDC;
	DeleteCriticalSection(&m_csAlarmItems);

	CIvsModule::UnInit();
}

void CDialogEventRule::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogEventRule)
	DDX_Control(pDX, IDC_COMBO_ARRANGE, m_cbArrange);
	DDX_Control(pDX, IDC_COMBO_CANNALMS, m_cbMSChannel);
	DDX_Control(pDX, IDC_COMBO_DISPLAY_FILTER, m_cbDisplayFilter);
	DDX_Control(pDX, IDC_STATIC_PICTURE, m_stuShowBmp);
	DDX_Control(pDX, IDC_LISTCTRL_REAL_EVENT, m_lcRealEvent);
	DDX_Control(pDX, IDC_LIST_EVENT_TYPE, m_lstEventType);
	DDX_Control(pDX, IDC_LIST_EVENT_CHANNEL, m_lstEventChannel);
	DDX_Control(pDX, IDC_COMBO_PREVIEW_CHANNEL, m_cbPreviewChannel);
	DDX_Text(pDX, IDC_EDIT_SNAP_SEQ, m_strSnapSeq);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDialogEventRule, CDialog)
	//{{AFX_MSG_MAP(CDialogEventRule)
	ON_CBN_SELCHANGE(IDC_COMBO_PREVIEW_CHANNEL, OnSelchangeComboPreviewChannel)
	ON_BN_CLICKED(IDC_BUTTON_START_PREVIEW, OnButtonStartPreview)
	ON_BN_CLICKED(IDC_BUTTON_STOP_PREVIEW, OnButtonStopPreview)
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_CBN_SELCHANGE(IDC_COMBO_DISPLAY_FILTER, OnSelchangeComboDisplayFilter)
	ON_NOTIFY(NM_CLICK, IDC_LISTCTRL_REAL_EVENT, OnNMClickListctrlRealEvent)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_CHN_SEL_ALL, OnBnClickedButtonChnSelAll)
	ON_BN_CLICKED(IDC_BUTTON_CHN_ANTI_SEL, OnBnClickedButtonChnAntiSel)
	ON_BN_CLICKED(IDC_BUTTON_TYPE_SEL_ALL, OnBnClickedButtonTypeSelAll)
	ON_BN_CLICKED(IDC_BUTTON_TYPE_ANTI_SEL, OnBnClickedButtonTypeAntiSel)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	ON_NOTIFY(LVN_KEYDOWN, IDC_LISTCTRL_REAL_EVENT, OnKeydownListctrlRealEvent)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_MANUAL_SNAP, OnButtonManualSnap)
	ON_CBN_SELCHANGE(IDC_COMBO_ARRANGE, OnSelchangeComboArrange)
	ON_BN_CLICKED(IDC_FLAG_MOSAIC, OnFlagMosaic)
	ON_BN_CLICKED(IDC_FLAG_EVENT, OnFlagEvent)
	ON_MESSAGE(WM_USER_ALAMR_COME, OnAlarmCome)
	ON_BN_CLICKED(IDC_BUTTON_PAUSE, OnButtonPause)
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON_CLEAR_DATA, OnBnClickedButtonClearData)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogEventRule message handlers


BOOL CDialogEventRule::OnInitDialog() 
{
	CDialog::OnInitDialog();

	g_SetWndStaticText(this);
	//���յ�����
	m_Font = new CFont;
	if (NULL != m_Font)
	{
		m_Font->CreateFont(50, 0, 0, 0, 700, 
			FALSE, 
			FALSE,
			0, 
			DEFAULT_CHARSET, 
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS, 
			DEFAULT_QUALITY, 
			DEFAULT_PITCH | FF_MODERN, 
			"����" );
		GetDlgItem(IDC_STATIC_LP)->SetFont(m_Font);
	}
	GetDlgItem(IDC_STATIC_LP)->SetWindowText("��A781M2");
	
	//�¼���ʾLISTCTRL�ķ��
	m_lcRealEvent.SetExtendedStyle(m_lcRealEvent.GetExtendedStyle()|LVS_EX_FULLROWSELECT);  
	m_lcRealEvent.SetExtendedStyle(m_lcRealEvent.GetExtendedStyle()|LVS_EX_GRIDLINES); 

	//����ͨ���ķ��
	m_lstEventChannel.SetCheckStyle(BS_AUTOCHECKBOX);
	
	//ͼƬ��ʾ�ؼ�
	m_cPictureWnd.Create(NULL, NULL, WS_CHILD|WS_VISIBLE, CRect(0,0,0,0), this, 1981);
	CRect screenRect;
	GetDlgItem(IDC_STATIC_PICTURE)->GetWindowRect(&screenRect);
	ScreenToClient(&screenRect);
	m_cPictureWnd.MoveWindow(screenRect);
	m_cPictureWnd.ShowWindow(SW_SHOW);

	//���ÿؼ��ĳ�ʼֵ
	((CButton*)GetDlgItem(IDC_CHECK_REFRESH_PIC))->SetCheck(1);
	for (int i = 0; i < EVENT_TYPE_COUNT; i++)
	{
		//��������
		if (i > 0)
		{
			m_lstEventType.AddString(ConvertString(strAlarmList[i]));
			m_lstEventType.SetItemData(i - 1, nAlarmTypeList[i]);
		}
		//��������
		if (i > 0)
		{
			m_cbDisplayFilter.AddString(ConvertString(strAlarmList[i]));
			m_cbDisplayFilter.SetItemData(i - 1, nAlarmTypeList[i]);
		}
	}
	//���ù���������Ĭ��ѡ����
	const int DEFAULT_SELECT_ITEM = EVENT_IVS_TRAFFICGATE;//���Ҫ����Ĭ�ϵ�ѡ����޸����ֵ�Ϳ����ˡ�����ʹ��EVENT_IVS_ALL
	int nSelectItemIndex = 0;
	int nItemCount = sizeof(nAlarmTypeList) / sizeof(nAlarmTypeList[0]);
	for (int j = 0; j < nItemCount; j++)
	{
		if (nAlarmTypeList[j] == DEFAULT_SELECT_ITEM)
		{
			nSelectItemIndex = j;
			break;
		}
	}
	m_cbDisplayFilter.SetCurSel(nSelectItemIndex - 1);
	DWORD dwAlarmType = m_cbDisplayFilter.GetItemData(nSelectItemIndex - 1);
	this->ChangeDisplayTitle(dwAlarmType);

	// �������з�ʽ
	m_cbArrange.ResetContent();
	int nIndex = 0;
	nIndex = m_cbArrange.AddString(ConvertString("picture group"));
	m_cbArrange.SetItemData(nIndex, 0);
	nIndex = m_cbArrange.AddString(ConvertString("Event group"));
	m_cbArrange.SetItemData(nIndex, 1);
	m_cbArrange.SetCurSel(0);
	m_nArrangMode = 0;

	// ץͼ��־
	GetDlgItem(IDC_FLAG_ALL)->EnableWindow(TRUE);
	GetDlgItem(IDC_FLAG_TIMING)->EnableWindow(TRUE);
	GetDlgItem(IDC_FLAG_MANUAL)->EnableWindow(FALSE);
	GetDlgItem(IDC_FLAG_MARKED)->EnableWindow(FALSE);
	GetDlgItem(IDC_FLAG_EVENT)->EnableWindow(FALSE);
	GetDlgItem(IDC_FLAG_MOSAIC)->EnableWindow(TRUE);
	GetDlgItem(IDC_FLAG_CUTOUT)->EnableWindow(FALSE);
	CheckRadioButton(IDC_FLAG_MOSAIC,IDC_FLAG_MOSAIC,IDC_FLAG_MOSAIC);

	this->SetTimer(10001, 1000, NULL);

	return TRUE;
}


void CDialogEventRule::UpdateDeviceInfo(LONG lLoginID, NET_DEVICEINFO &netDevInfo, BOOL bLogin)
{
	if (bLogin)//��¼
	{
		m_lLoginID = lLoginID;
		m_netDevInfo = netDevInfo;

		//Ԥ��ͨ��������
		BYTE i= 0;
		for (i = 0; i < m_netDevInfo.byChanNum; i++)
		{
			char szContent[8] = {0};
			sprintf(szContent, "%d", i + 1);
			m_cbPreviewChannel.AddString(szContent);
			m_cbPreviewChannel.SetItemData(i, (DWORD)i);
		}
		m_cbPreviewChannel.SetCurSel(0);

		//�¼�����ͨ���б��
		for (i = 0; i < m_netDevInfo.byChanNum; i++)
 		{
			char szContent[8] = {0};
			std::string strChn = ConvertString("Chn");
			strChn.append("%d");
			sprintf(szContent, strChn.c_str(), i + 1);
			m_lstEventChannel.AddString(szContent);
			m_lstEventChannel.SetItemData(i, (DWORD)i);
 		}

		// ץ��ͨ��������
		for(i = 0; i < m_netDevInfo.byChanNum; i++)
		{
			char szContent[8] = {0};
			sprintf(szContent, "%d", i + 1);
			m_cbMSChannel.AddString(szContent);
			m_cbMSChannel.SetItemData(i, (DWORD)i);
		}
		m_cbMSChannel.SetCurSel(0);
		return;
	}
	else//�ǳ�
	{
		m_lLoginID = 0;
		ZeroMemory(&m_netDevInfo, sizeof(m_netDevInfo));

		while (m_cbPreviewChannel.GetCount() > 0)
		{
			m_cbPreviewChannel.DeleteString(0);
		}
		m_cbPreviewChannel.Clear();
		// ���ͨ�������б�
		while (m_cbMSChannel.GetCount() > 0)
		{
			m_cbMSChannel.DeleteString(0);
		}
		m_cbMSChannel.Clear();
		while (m_lstEventChannel.GetCount() > 0)
		{
			m_lstEventChannel.DeleteString(0);
		}
		this->ChangeUI(UI_STATE_SUBSCRIBE_STOP);	
	}
}

/************************************************************************/
/* ͨ���������ı��ʱ�򣬹ر���ǰ��Ԥ������ʼ�µ�Ԥ��                   */
/************************************************************************/
void CDialogEventRule::OnSelchangeComboPreviewChannel() 
{
	OnButtonStartPreview();
// 	int nSel = m_cbPreviewChannel.GetCurSel();
// 	int nChannel = (WORD)(m_cbPreviewChannel.GetItemData(nSel));
// 	if (m_lPlayID != 0)
// 	{
// 		CLIENT_StopRealPlay(m_lPlayID);
// 	}
// 	HWND hWnd = GetDlgItem(IDC_STATIC_PREVIEW)->GetSafeHwnd();
// 	m_lPlayID = CLIENT_RealPlay(m_lLoginID, nChannel, hWnd);
// 	if (m_lPlayID == 0)
// 	{
// 		MessageBox(ConvertString("Preview failed!"),ConvertString("Prompt"));
// 		return;
// 	}
}

/*************************************************************************/
/* ��ʼԤ����Ԥ��ǰ�ȹر���ǰ���ܴ򿪵�Ԥ��                             */
/************************************************************************/
void CDialogEventRule::OnButtonStartPreview() 
{
	CIvsModule::ClearData();

	HWND hWnd = GetDlgItem(IDC_STATIC_PREVIEW)->GetSafeHwnd();
	int nSel = m_cbPreviewChannel.GetCurSel();
	if ( (nSel < 0) || (m_lLoginID == 0) )
	{
		MessageBox(ConvertString("Please login and select a channel before preview!"),ConvertString("Prompt"));
		return;
	}
	//Open the preview
	int nChannelID = m_lstEventChannel.GetItemData(nSel);
	if (m_lPlayID != 0)
	{
		OnButtonStopPreview();
	}

	int nPort = 450;
	
	//Enable stream
	BOOL bOpenRet = g_PlayAPI.PLAY_OpenStream(nPort,0,0,1024*900);
	if(bOpenRet)
	{
		BOOL bRet = g_PlayAPI.PLAY_SetIVSCallBack(nPort,CIvsModule::GetIvsInfoProc,(DWORD)this);
		if (!bRet)
		{
			MessageBox(ConvertString("PLAY_SetIVSCallBack failed!"),ConvertString("Prompt"));
		}
		bRet = g_PlayAPI.PLAY_RigisterDrawFun(nPort,CIvsModule::DrawIvsInfoProc,(DWORD)this);
		if (!bRet)
		{
			MessageBox(ConvertString("PLAY_RigisterDrawFun failed!"),ConvertString("Prompt"));
		}
		//Begin play 
		BOOL bPlayRet = g_PlayAPI.PLAY_Play(nPort,hWnd);
		if(bPlayRet)
		{
			//Real-time play 
			m_lPlayID = CLIENT_RealPlay(m_lLoginID,nChannelID,0);
			if(0 != m_lPlayID)
			{
				//Callback monitor data and then save 
				CLIENT_SetRealDataCallBackEx(m_lPlayID, RealDataCallBackEx, (LDWORD)this, 0x1f);
				GetDlgItem(IDC_BUTTON_START_PREVIEW)->EnableWindow(FALSE);
				CIvsModule::OnOpenDeviceRealplay(m_lLoginID,nChannelID,nPort,hWnd,m_netDevInfo.byChanNum);
			}
			else
			{
				MessageBox(ConvertString("Fail to play!"), ConvertString("Prompt"));
			}
		}
	}
}

/************************************************************************/
/* �ر�Ԥ��                                                             */
/************************************************************************/
void CDialogEventRule::OnButtonStopPreview() 
{
	if (m_lPlayID != 0)
	{
		BOOL bRealPlay = CLIENT_StopRealPlay(m_lPlayID);

// 		if (bRealPlay)
// 		{
		//And then close PLAY_Play
		int nPort = 450;
		BOOL bPlay = g_PlayAPI.PLAY_Stop(nPort);
		if(bPlay)
		{
			//At last close PLAY_OpenStream
			BOOL bStream = g_PlayAPI.PLAY_CloseStream(nPort);
			m_lPlayID = 0;
		}
//		}
	}
	CWnd* window = GetDlgItem(IDC_STATIC_PREVIEW);
	CDC* cdc = window->GetDC();
	RECT rect;
	window->GetClientRect(&rect);
	CBrush brush(RGB(100,100,160));
	cdc->FillRect(&rect, &brush);
	GetDlgItem(IDC_BUTTON_START_PREVIEW)->EnableWindow(TRUE);
}

void CDialogEventRule::ChangeDisplayTitle(DWORD dwAlarmType)
{
	int nStructSize = 0;
	std::vector<ColDes> vTitle;
	BOOL bRet = GetStructInfo(dwAlarmType, NULL, GET_SI_TITLE, NULL, NULL, &vTitle, NULL);
	if (!bRet)
	{
		MessageBox(ConvertString("Alarm type not supported yet"), ConvertString("Prompt"));
		return;
	}

	//��ɾ�����е���
	int nItemCount = m_lcRealEvent.GetItemCount();
	for (int i = 0 ; i < nItemCount; i++)
	{
		char* szGUID = (char*)(m_lcRealEvent.GetItemData(i));
		delete[] szGUID;
	}
	m_lcRealEvent.DeleteAllItems();
	while(m_lcRealEvent.DeleteColumn(0)){}

	//����Ӷ�Ӧ����
	int nColCount = vTitle.size();
	LV_COLUMN lvc;
	lvc.mask=LVCF_FMT|LVCF_WIDTH|LVCF_TEXT|LVCF_SUBITEM;
	lvc.fmt=LVCFMT_LEFT;
	for(int j = 0; j < nColCount; j++) {//�������
		lvc.pszText = (char*)(vTitle[j].strColTitle.c_str());
		lvc.cx = vTitle[j].nColWidth;
		lvc.iSubItem = j;
		m_lcRealEvent.InsertColumn(j, &lvc);
	}

	std::list<GUID>::iterator iterGroupId = m_lsGroupId.begin();
	for (; iterGroupId != m_lsGroupId.end();)
	{
		m_lsGroupId.erase(iterGroupId++);
	}

	//���¼�����Ӧ�����͵�����
	std::list<ALARM_ITEM>::iterator iter = m_allAlarmItems.begin();
	for (; iter != m_allAlarmItems.end(); iter++)
	{
		this->DisplayInfo((*iter).strGUID.c_str(), (*iter).nAlarmType, (*iter).pAlarmInfo, (*iter).nPictureGroupId, (*iter).nEventGroupId);
	}
}

struct EventPara
{
	LONG lAnalyzerHandle;
	DWORD dwAlarmType;
	void* pAlarmInfo;
	BYTE *pBuffer;
	DWORD dwBufSize;
	int nSequence;
};

/************************************************************************/
/* SDK�ص�����                                                          */
/************************************************************************/
int  CDialogEventRule::RealLoadPicCallback (LLONG lAnalyzerHandle, DWORD dwAlarmType, void* pAlarmInfo, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser, int nSequence, void *userdata)
{
	DEV_EVENT_TRAFFICGATE_INFO* pInfo = (DEV_EVENT_TRAFFICGATE_INFO*)pAlarmInfo;
	CDialogEventRule* This = (CDialogEventRule*)dwUser;
	int nAlarmInfoSize = 0;
	int iRet = GetStructInfo(dwAlarmType, NULL, GET_SI_SIZE, &nAlarmInfoSize, NULL, NULL, NULL);
	if (iRet == -1)
	{
		This->MessageBox(ConvertString("Alarm type not supported yet"), ConvertString("Prompt"));
		return -1;
	}

	//����ڻص��߳��д���UI�ϵ�Ԫ�أ��ᵼ��UI����Ϣ�Ĳ�����
	//���ʱ�������ȥ����UI,ȥ����Client_stop�ȣ����ܻᵼ������
	EventPara* eventData = new EventPara;
	eventData->lAnalyzerHandle = lAnalyzerHandle;
	eventData->dwAlarmType = dwAlarmType;
	eventData->dwBufSize = dwBufSize;
	eventData->nSequence = nSequence;
	
	eventData->pBuffer = new BYTE[dwBufSize];
	memcpy(eventData->pBuffer, pBuffer, dwBufSize);

	eventData->pAlarmInfo = new char[nAlarmInfoSize];
	memcpy(eventData->pAlarmInfo, pAlarmInfo, nAlarmInfoSize);

	HWND hwnd = This->GetSafeHwnd();
	::PostMessage(hwnd, WM_USER_ALAMR_COME, (DWORD)(eventData), 0);
	return 0;
}

/************************************************************************/
/*WM_USER_ALAMR_COME����Ϣ����                                          */
/************************************************************************/
LRESULT CDialogEventRule::OnAlarmCome(WPARAM wParam, LPARAM lParam)
{
	EventPara* ep = (EventPara*)wParam;
	this->OnReceiveEvent(ep->lAnalyzerHandle, ep->dwAlarmType, ep->pAlarmInfo, ep->pBuffer, ep->dwBufSize, ep->nSequence);
	delete[] ep->pBuffer;
	delete[] ep->pAlarmInfo;
	delete ep;
	return 0;
}

void CDialogEventRule::OnReceiveEvent(LONG lAnalyzerHandle, DWORD dwAlarmType, void* pAlarmInfo, BYTE *pBuffer, DWORD dwBufSize, int nSequence)
{
	//���еĽṹ���ǰ���4����Ա����һ���ģ�����ͳһ�Ļ�ȡʱ��
	DEV_EVENT_TRAFFICGATE_INFO* pInfo = (DEV_EVENT_TRAFFICGATE_INFO*)pAlarmInfo;
	char szTime[32] = {0};
	sprintf(szTime, 
		"%04d%02d%02d%02d%02d%02d%3d",
		pInfo->UTC.dwYear,
		pInfo->UTC.dwMonth,
		pInfo->UTC.dwDay,
		pInfo->UTC.dwHour,
		pInfo->UTC.dwMinute,
		pInfo->UTC.dwSecond,
		pInfo->UTC.dwMillisecond);

	//����ͼƬ�ĺ������ļ��ľ���·��
	GUID guid = {0};
	HRESULT hr =  CoCreateGuid(&guid);
	std::string strGUID(szTime);
	strGUID.append(GuidToString(guid));

	// ����ͼƬ��ID
	if (nSequence == 0) //ͼƬ�鿪ʼ
	{
		CoCreateGuid(&m_nCurrentPicGroupId);
	}
	
	// �����¼���ID
	DH_EVENT_FILE_INFO stuFileInfo = {0};
	int iRet = GetStructInfo(dwAlarmType, pAlarmInfo, GET_SI_FILEINFO, NULL, &stuFileInfo, NULL, NULL);
	if (iRet == -1)
	{
		//���¼���
		m_alarmCount++;
		SetDlgItemInt(IDC_STATIC_ALARM_COUNT, m_alarmCount);
		return;
	}

	GUID nEvnGroupID = {0};
	if (stuFileInfo.bCount >= 1)
	{
		GROUPIDMAP::iterator iter = m_mapCurrentEvnGroupId.find(stuFileInfo.nGroupId);
		if ( iter != m_mapCurrentEvnGroupId.end() )
		{
			memcpy(&nEvnGroupID, &(iter->second), sizeof(GUID));
			if (stuFileInfo.bIndex == stuFileInfo.bCount) // �¼������
			{
				m_mapCurrentEvnGroupId.erase(iter);
			}
		}
		else
		{
			CoCreateGuid(&nEvnGroupID);
			m_mapCurrentEvnGroupId[stuFileInfo.nGroupId] = nEvnGroupID;
		}
	}
	


	//��ȡ�����ļ��е�λ��
	std::string strCfgFolder = GetDataFolder();
	std::string strCfgFile = strCfgFolder + std::string(".ini");
	std::string strJpgFile = strCfgFolder + strGUID + std::string(".jpg");

	//���Դ����ļ���
	::CreateDirectory(strCfgFolder.c_str(), NULL);

	//�����ȱ������ݣ������һЩ��ʾ��������õ�ͼƬ����Ϣ
	this->StoreEvent(strGUID.c_str(), strCfgFile.c_str(), strJpgFile.c_str(), dwAlarmType, pAlarmInfo, pBuffer, dwBufSize, m_nCurrentPicGroupId, nEvnGroupID);

	if (nSequence == 2) // ͼƬ�����
	{
		memset(&m_nCurrentPicGroupId, 0, sizeof(GUID));
	}

	//��ʾ����
	this->DisplayEvent(strGUID.c_str(), strJpgFile.c_str(), dwAlarmType, pAlarmInfo, pBuffer, dwBufSize);
	
	ALARM_ITEM* itemPtr = this->m_pcQueryDlg->GetAlarmItemByGUID(strGUID.c_str());
	if (itemPtr == NULL)
	{
		assert(0);
	}
	//��ʾ���Ƶ�����
	TryDisplayLP(itemPtr->nAlarmType, itemPtr->pAlarmInfo, GetDlgItem(IDC_STATIC_LP));

	//���¼���
	m_alarmCount++;
	SetDlgItemInt(IDC_STATIC_ALARM_COUNT, m_alarmCount);
}


// BOOL CDialogEventRule::DisplayPic(const char* szBMPFilePath)
// {
// 	BOOL bShowFull = ((CButton*)GetDlgItem(IDC_CHECK_SHOW_FULL_PIC))->GetCheck();
// 	if(!bShowFull)
// 	{
// 		m_cPictureWnd.ShowWindow(SW_HIDE);
// 
// 		//HBITMAP hBitmap; //Define .BMP object handle.
// 		BITMAP BM; 
// 		if (m_MemDC == NULL)
// 		{
// 			m_MemDC = new CDC;
// 			if (m_ClientDC == NULL)
// 			{
// 				m_ClientDC = new CClientDC(&m_stuShowBmp);
// 			}
// 			m_stuShowBmp.GetClientRect(&m_rect);
// 			m_MemDC->CreateCompatibleDC(m_ClientDC); 
// 		}
// 		if (m_hBitmap != NULL)
// 		{
// 			::DeleteObject(m_hBitmap);
// 		}
// 		m_hBitmap = LoadImageFile(szBMPFilePath, m_nWidth, m_nHeight);
// 
// 		if(m_hBitmap != NULL)
// 		{
// 			m_MemDC->SelectObject(m_hBitmap);
// 			::GetObject(m_hBitmap,sizeof(BM),&BM);
// 
// 			m_ClientDC->SetStretchBltMode(STRETCH_HALFTONE);
// 			m_ClientDC->StretchBlt(0,0,(m_rect.right - m_rect.left),(m_rect.bottom - m_rect.top), m_MemDC,0,0,m_nWidth,m_nHeight,SRCCOPY);
// 		}
// 	}
// 	else
// 	{
// 		m_cPictureWnd.ShowWindow(SW_SHOW);
// 
// 		HANDLE hFile=CreateFile(szBMPFilePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
// 		if (hFile == NULL)
// 		{
// 			return FALSE;
// 		}
// 
// 		DWORD dwFileSize = GetFileSize(hFile, NULL);
// 		if (m_szBmpBuffer == NULL)
// 		{
// 			CloseHandle(hFile);
// 			return FALSE;
// 		}
// 
// 		DWORD dwReadedSize;
// 		ReadFile(hFile, m_szBmpBuffer, dwFileSize, &dwReadedSize, NULL);
// 
// 		m_dwBmpBufferSize = dwReadedSize;
// 		m_cPictureWnd.ShowPicture(m_szBmpBuffer, m_dwBmpBufferSize);
// 
// 		CloseHandle(hFile);
// 	}
// 	return TRUE;
// }

BOOL CDialogEventRule::DisplayInfo(const char* szGUID, DWORD dwAlarmType, void* pAlarmInfo, GUID nPicGroupId, GUID nEvnGroupId)
{
	//�鿴��ʾ������������������Ϲ�����������ô����Ҫ��ʾ
	int nCurSel = m_cbDisplayFilter.GetCurSel();
	if (nCurSel < 0)
	{
		return FALSE;
	}
	int nDisplayAlarmType = m_cbDisplayFilter.GetItemData(nCurSel);
	if (nDisplayAlarmType != dwAlarmType)
	{
		return FALSE;
	}

	// �������з�ʽ�ҵ����¼���Ϣ�Ĳ���λ��
	int nInsertIndex = 0;
	GetInsertIndex(nInsertIndex, nPicGroupId, nEvnGroupId);

	//��ʾ����
	using namespace std;
	vector<string> vContents;
	vector<ColDes> vTitles;
	BOOL bRet = GetStructInfo(dwAlarmType,
							pAlarmInfo,
							GET_SI_CONTENT | GET_SI_TITLE,
							NULL,
							NULL,
							&vTitles,
							&vContents);
	int nTitleCount = vTitles.size();
	int nContentCount = vContents.size();
	if (nTitleCount == 0)
	{
		//���Ҫ��ʾ���ݣ�����Ҫ�б��⣬����GetStructInfo����Ӷ�Ӧ�ı���
		assert(0);
		return FALSE;
	}
	if ( (nContentCount % nTitleCount) != 0 )
	{
		//��ʾ�����ݵ��ֶθ��������Ǳ������������������ԣ�
		//����GetStructInfo�м��GET_SI_CONTENT��GET_SI_TITLE���ص��ֶ�����
		assert(0);
		return FALSE;
	}

	LV_ITEM lvi;
	lvi.mask=LVIF_TEXT|LVIF_IMAGE|LVIF_PARAM;
	lvi.iSubItem = 0;
	lvi.pszText = "";
	lvi.iImage = 0;
	lvi.iItem = nInsertIndex;
	
	/************************************************************************/
	/* һ��ͼƬ��Ӧ���¼������кü���                                       */
	/************************************************************************/
	//Display data
	int nDisplayCount = nContentCount / nTitleCount;//��¼������=���ݵ�����/���������
	for (int nCurDisplayIndex = 0; nCurDisplayIndex < nDisplayCount; nCurDisplayIndex++)
	{
		m_lcRealEvent.InsertItem(&lvi);
		char* szGUIDTmp = new char[64];
		memset(szGUIDTmp, 0, 64);
		strcpy(szGUIDTmp, szGUID);
		m_lcRealEvent.SetItemData(nInsertIndex, (DWORD)(szGUIDTmp));
		for (int i = 0; i < nTitleCount; i++)
		{
			m_lcRealEvent.SetItemText(nInsertIndex, i, vContents[(nCurDisplayIndex * nTitleCount) + i].c_str());//��ʾ�����еĶ�Ӧ�ַ���
		}
	}
	
	return TRUE;
}

// �������з�ʽ����ID�ҵ����¼���Ϣ�Ĳ���λ��
void CDialogEventRule::GetInsertIndex(int &nInsertIndex, GUID nPicGroupId, GUID nEvnGroupId)
{
	BOOL bExist = FALSE;
	GUID nGroupId =  {0};
	if (m_nArrangMode == 0) // ͼƬ�鷽ʽ
	{
		memcpy(&nGroupId, &nPicGroupId, sizeof(GUID));
	}
	else if (m_nArrangMode == 1)// �¼��鷽ʽ
	{
		memcpy(&nGroupId, &nEvnGroupId, sizeof(GUID));
	}
	
	// ����Ƿ�ǰid�Ѿ����ֹ�
	std::list<GUID>::iterator iter = m_lsGroupId.begin();
	for (; iter != m_lsGroupId.end(); iter++)
	{
		if (iter->Data1 == nGroupId.Data1 && iter->Data2 == nGroupId.Data2
			&& iter->Data3 == nGroupId.Data3)
		{
			bExist = TRUE;
			break;
		}
	}
	
	std::string strGuid =GuidToString(nGroupId);
	if (!bExist)// ����ǰ���δ���ֹ���������µ���˵����
	{
		// ����ǰid��Ϊ0����˵����ǰ��Ϣ�������κ���
		if (nGroupId.Data1 == 0 && nGroupId.Data2 == 0 && nGroupId.Data3 == 0)
		{
			nInsertIndex = 0;
		}
		else
		{
			m_lsGroupId.push_back(nGroupId);
			
			// ������˵����
			LV_ITEM lviGroupItem;
			lviGroupItem.mask=LVIF_TEXT|LVIF_IMAGE|LVIF_PARAM;
			lviGroupItem.iSubItem = 0;
			lviGroupItem.pszText = "";
			lviGroupItem.iImage = 0;
			lviGroupItem.iItem = 0;
			m_lcRealEvent.InsertItem(&lviGroupItem);
			m_lcRealEvent.SetItemData(0, 0);
			m_lcRealEvent.InsertItem(&lviGroupItem);
			char* szGuid = new char[64];
			strcpy(szGuid, strGuid.c_str());
			m_lcRealEvent.SetItemData(0, (DWORD)szGuid);
			m_lcRealEvent.SetItemText(0, 1, ConvertString("below this column is belong to one Group"));
			
			nInsertIndex = 1;
		}
	}
	else// ���ѳ������ҵ���ǰ��˵���е�λ��
	{
		char* pGuid = NULL;
		int nCount = m_lcRealEvent.GetItemCount();
		for(int i = 0; i < nCount; i++)
		{
			pGuid = (char*)m_lcRealEvent.GetItemData(i);
			if (pGuid != NULL && strcmp(pGuid, strGuid.c_str()) == 0)
			{
				nInsertIndex = i + 1;
				break;
			}
		}
	}

	return;
}

BOOL CDialogEventRule::DisplayEvent(const char* szGUID , const char* szBMPFilePath, DWORD dwAlarmType, void* pAlarmInfo, BYTE *pBuffer, DWORD dwBufSize)
{
	ALARM_ITEM* item = m_pcQueryDlg->GetAlarmItemByGUID(szGUID);

	//����������ʾ
	this->DisplayInfo(szGUID, (*item).nAlarmType, (*item).pAlarmInfo, (*item).nPictureGroupId, (*item).nEventGroupId);

	//ͼƬ��ʾ
	if (((CButton*)(GetDlgItem(IDC_CHECK_REFRESH_PIC)))->GetCheck() == 0)
	{
		return TRUE;
	}
// 	//��ʾ����
// 	ALARM_ITEM* item = m_pcQueryDlg->GetAlarmItemByGUID(szGUID);
// 	TryDisplayLPPic(szBMPFilePath, item, GetDlgItem(IDC_STATIC_EVENT_LP_IMAGE));	
	if (NULL == pBuffer || 0 == dwBufSize)
	{
		OutputDebugString("No image to display\n");
		return TRUE;
	}
	
	TryDisplayImageAndLPPart(szBMPFilePath, 
							item, 
							GetDlgItem(IDC_STATIC_PICTURE), 
							GetDlgItem(IDC_STATIC_EVENT_LP_IMAGE));

	return TRUE;
}

BOOL CDialogEventRule::StoreEvent(const char* szGUID, const char* szCFGFilePath, const char* szBMPFilePath, DWORD dwAlarmType, void* pAlarmInfo, BYTE *pBuffer, DWORD dwBufSize, GUID nPicGroupID, GUID nEvnGroupID)
{
	/************************************************************************/
	/*  ���浽�ڴ���                                                        */
	/************************************************************************/
	
	//���Ҫ��ʾ�ļ�¼�������࣬ɾ����ǰ������
	//size_t vSize = m_allAlarmItems.size();
	//if (vSize >= MAX_REAL_EVENT_STORE_COUNT)
	//{
	//	std::list<ALARM_ITEM>::iterator iter = m_allAlarmItems.begin();
	//	delete[] (*iter).pAlarmInfo;
	//	m_allAlarmItems.pop_front();
	//}

	//���챨���ṹ
	int nStructSize = 0;
	BOOL bRet = GetStructInfo(dwAlarmType, NULL, GET_SI_SIZE, &nStructSize, NULL, NULL, NULL);
	char* pStructInfo = new char[nStructSize];
	char* pStructInfo2 = new char[nStructSize];
	memcpy(pStructInfo, pAlarmInfo, nStructSize);
	memcpy(pStructInfo2, pAlarmInfo, nStructSize);
	ALARM_ITEM ai;
	ai.nAlarmType = dwAlarmType;
	ai.pAlarmInfo = pStructInfo;
	ai.strGUID    = std::string(szGUID);
	ai.nLen       = nStructSize;
	ai.nCheckFlag = 0;//Not checked
	memcpy(&ai.nEventGroupId, &nEvnGroupID, sizeof(GUID));
	memcpy(&ai.nPictureGroupId, &nPicGroupID, sizeof(GUID));

	//���浽������ʾ��������
	EnterCriticalSection(&m_csAlarmItems);
	m_allAlarmItems.push_back(ai);
	LeaveCriticalSection(&m_csAlarmItems);

	//���浽������ѯ���б���
	ai.pAlarmInfo = pStructInfo2;
	m_pcQueryDlg->AddAlarm(ai);

	// ����ͼƬ��Ӳ����
	if (NULL == pBuffer || dwBufSize == 0)
	{
		OutputDebugString("No Pic data\n");
		return TRUE;
	}
	FILE* fp = fopen(szBMPFilePath, "wb");
	if (fp == NULL)
	{
		MessageBox(ConvertString("Save picture failed!"), ConvertString("Prompt"));
		return FALSE;
	}
	fwrite(pBuffer, dwBufSize, 1, fp);
	fclose(fp);
	return TRUE;
}

void CDialogEventRule::OnButtonStart() 
{
	//����Ƿ��¼
	if (m_lLoginID == 0)
	{
		MessageBox(ConvertString("Please login first!"),ConvertString("Prompt"));
		return;
	}
	int i = 0;
	//����Ƿ����κ�һ��ͨ��ѡ��
	bool bAnyChecked = false;
	int nChnCount = m_lstEventChannel.GetCount();
	for (i = 0; i < nChnCount; i++)
	{
		if (m_lstEventChannel.GetCheck(i) != 0)
		{
			bAnyChecked = true;
			break;
		}
	}
	if (!bAnyChecked)
	{
		MessageBox(ConvertString("Please select one channel at last!"),ConvertString("Prompt"));
		return;
	}

	//����Ƿ����κζ���ѡ��
	bAnyChecked = false;
	int nTypeCount = m_lstEventType.GetCount();
	for (i = 0; i < nTypeCount; i++)
	{
		if (m_lstEventType.GetCheck(i) != 0)
		{
			bAnyChecked = true;
			break;
		}
	}
	if (!bAnyChecked)
	{
		MessageBox(ConvertString("Please select one type at last!"),ConvertString("Prompt"));
		return;
	}

	NET_RESERVED_COMMON stReservedCommon = {0};
	stReservedCommon.dwStructSize = sizeof(NET_RESERVED_COMMON);
	for (int j=IDC_FLAG_ALL;j<=IDC_FLAG_CUTOUT;j++)
	{
		if(IsDlgButtonChecked(j))
		{
			stReservedCommon.dwSnapFlagMask += 1 << (j-IDC_FLAG_ALL);
		}
	}

// 	if (0 == stReservedCommon.dwSnapFlagMask)
// 	{
// 		MessageBox(ConvertString("Please select one Snap Flag at last!"),ConvertString("Prompt"));
// 		return;
// 	}
	ReservedPara stReserved;
	stReserved.dwType = RESERVED_TYPE_FOR_COMMON;
	stReserved.pData = &stReservedCommon;

	int nCheck = ((CButton*)(GetDlgItem(IDC_CHECK_WITH_DATA)))->GetCheck();
	BOOL bNeedData = nCheck > 0 ? TRUE : FALSE;

	//////////////////////////////////////////////////////////////////////////׼������
    bool bSuccess = false;
	for (int nChn = 0; nChn < m_netDevInfo.byChanNum; nChn++)
	{
		if ( m_lstEventChannel.GetCheck(nChn) == 0 )
		{
			continue;
		}
		int nAlarmTypeCount = m_lstEventType.GetCount();

		//�鿴�Ƿ�ѡ�������е�����ѡ�������е����ô��EVENT_IVS_ALL
		bool isALLChecked = true;
		int i = 0;
		for (i = 0; i < nAlarmTypeCount; i++)
		{
			int   nCheck = m_lstEventType.GetCheck(i);
			if (nCheck == 0)
			{
				isALLChecked = false;
				break;
			}
		}
		if (isALLChecked)//ֻ�Ǵ�һ������,��EVENT_IVS_ALL
		{
			LONG lRet = CLIENT_RealLoadPictureEx(m_lLoginID, nChn, EVENT_IVS_ALL, bNeedData, CDialogEventRule::RealLoadPicCallback, (LDWORD)this, (void*)&stReserved);
			if (lRet == 0)
			{
				MessageBox(ConvertString("Subscribe picture failed!"), ConvertString("Prompt"));
				continue;
			}
            bSuccess = true;
			m_allRealLoadPicHandle.push_back(lRet);
		}
		else//������ѡ�еĶ���
		{


//#define  SINGLE_CALL
#define  MULTI_CALL
#ifdef   MULTI_CALL
//��ζ��Ķ����¼�
			for (i = 0; i < nAlarmTypeCount; i++)
			{
				if (m_lstEventType.GetCheck(i) == 0 )
				{
					continue;
				}
				DWORD dwAlarmType = m_lstEventType.GetItemData(i);
				LONG lRet = CLIENT_RealLoadPictureEx(m_lLoginID, nChn, dwAlarmType, bNeedData,CDialogEventRule::RealLoadPicCallback, (LDWORD)this, (void*)&stReserved);
				if (lRet == 0)
				{
					MessageBox(ConvertString("Subscribe picture failed!"), ConvertString("Prompt"));
					continue;
				}
                bSuccess = true;
				m_allRealLoadPicHandle.push_back(lRet);
			}
//////////////////////////////////////////////////////////////////////////
#else
//���ζ��Ķ���¼���ʵ��
			ReservedDataIntelBox resDataIntelBox = {0};
			stReservedCommon.pIntelBox = &resDataIntelBox;

			DWORD* dwPtrEventTypeData = new DWORD[nAlarmTypeCount];
			resDataIntelBox.dwEventCount = 0;
			resDataIntelBox.dwPtrEventType = dwPtrEventTypeData;
		
			for (i = 0; i < nAlarmTypeCount; i++)
			{
				if (m_lstEventType.GetCheck(i) == 0 )
			 	{
			 		continue;
			 	}
				DWORD dwAlarmType = m_lstEventType.GetItemData(i);
				resDataIntelBox.dwPtrEventType[resDataIntelBox.dwEventCount] = dwAlarmType;
				resDataIntelBox.dwEventCount++;
 			}

			LONG lRet = CLIENT_RealLoadPictureEx(m_lLoginID, nChn, 0, bNeedData, CDialogEventRule::RealLoadPicCallback, (DWORD)this, (void*)&stReserved);
			if (lRet == 0)
			{
				MessageBox(ConvertString("Subscribe picture failed!"), ConvertString("Prompt"));
			}
			else
			{
                bSuccess = true;
				m_allRealLoadPicHandle.push_back(lRet);
			}
			delete[] dwPtrEventTypeData;
//////////////////////////////////////////////////////////////////////////
#endif






			
		}
	}
	//Change UI
    if (bSuccess)
    {
        this->ChangeUI(UI_STATE_SUBSCRIBE_NOW);
    }
}

/************************************************************************/
/* �ر����еĶ��ģ����������                                           */
/************************************************************************/
void CDialogEventRule::OnButtonStop() 
{
	std::vector<LONG>::iterator iter = m_allRealLoadPicHandle.begin();
	while (iter != m_allRealLoadPicHandle.end())
	{
		CLIENT_StopLoadPic(*iter);
		iter++;
	}
	m_allRealLoadPicHandle.clear();
	this->ChangeUI(UI_STATE_SUBSCRIBE_STOP);
}

void CDialogEventRule::OnSelchangeComboDisplayFilter() 
{
	DisplayFilter();
}

void CDialogEventRule::DisplayFilter()
{
	int nCurSel = m_cbDisplayFilter.GetCurSel();
	if (nCurSel < 0)
	{
		return;
	}
	DWORD dwAlarmType = m_cbDisplayFilter.GetItemData(nCurSel);
	this->ChangeDisplayTitle(dwAlarmType);
}

void CDialogEventRule::OnNMClickListctrlRealEvent(NMHDR *pNMHDR, LRESULT *pResult)
{
	HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;
	if (phdn->iItem == -1)
	{
		return;
	}
	int newIndex = phdn->iItem;
	DisplaySelectedPicInfo(newIndex, &m_lcRealEvent);
	
	*pResult = 0;
}


void CDialogEventRule::OnDestroy()
{
	CDialog::OnDestroy();

	//���ListCtrl �е�����
	int nItemCount = m_lcRealEvent.GetItemCount();
	for (int i = 0 ; i < nItemCount; i++)
	{
		char* szGUID = (char*)(m_lcRealEvent.GetItemData(i));
		delete[] szGUID;
	}

	OnButtonStopPreview();
}

void CDialogEventRule::OnBnClickedButtonChnSelAll()
{
	int itemCount = m_lstEventChannel.GetCount();
	for (int i = 0; i < itemCount; i++)
	{
		m_lstEventChannel.SetCheck(i, TRUE);
	}
}

void CDialogEventRule::OnBnClickedButtonChnAntiSel()
{
	int itemCount = m_lstEventChannel.GetCount();
	for (int i = 0; i < itemCount; i++)
	{
		m_lstEventChannel.SetCheck(i, !(m_lstEventChannel.GetCheck(i)));
	}
}

void CDialogEventRule::OnBnClickedButtonTypeSelAll()
{
	int itemCount = m_lstEventType.GetCount();
	for (int i = 0; i < itemCount; i++)
	{
		m_lstEventType.SetCheck(i, TRUE);
	}
}

void CDialogEventRule::OnBnClickedButtonTypeAntiSel()
{
	int itemCount = m_lstEventType.GetCount();
	for (int i = 0; i < itemCount; i++)
	{
		m_lstEventType.SetCheck(i, !(m_lstEventType.GetCheck(i)));
	}
}

void CDialogEventRule::ChangeUI( int nState )
{
	switch (nState)
	{
	case UI_STATE_SUBSCRIBE_NOW:
		{
			m_lstEventChannel.EnableWindow(FALSE);
			m_lstEventType.EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON_CHN_SEL_ALL)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON_CHN_ANTI_SEL)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON_TYPE_SEL_ALL)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON_TYPE_ANTI_SEL)->EnableWindow(FALSE);
            GetDlgItem(IDC_BUTTON_START)->EnableWindow(FALSE);
            GetDlgItem(IDC_BUTTON_PAUSE)->EnableWindow(TRUE);
            GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(TRUE);
		}
		break;

	case UI_STATE_SUBSCRIBE_STOP:
		{
            CString strPause;
            GetDlgItem(IDC_BUTTON_PAUSE)->GetWindowText(strPause);
            if (strPause == ConvertString("Resume"))
            {
                std::vector<LONG>::iterator iter = m_allRealLoadPicHandle.begin();
                while (iter != m_allRealLoadPicHandle.end())
                {
                    BOOL bret = CLIENT_PauseLoadPic(*iter, FALSE);
                    iter++;
                }
                GetDlgItem(IDC_BUTTON_PAUSE)->SetWindowText(ConvertString("Pause"));
            }

			m_lstEventChannel.EnableWindow(TRUE);
			m_lstEventType.EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_CHN_SEL_ALL)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_CHN_ANTI_SEL)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_TYPE_SEL_ALL)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_TYPE_ANTI_SEL)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_START)->EnableWindow(TRUE);
            GetDlgItem(IDC_BUTTON_PAUSE)->EnableWindow(FALSE);
            GetDlgItem(IDC_BUTTON_STOP)->EnableWindow(FALSE);
		}
		break;

	default:
		break;
	}
}
void CDialogEventRule::OnTimer(UINT_PTR nIDEvent)
{
	//��ʱ��ˢ��ͼƬ������ͼƬ��ʾʱ���ڽ����ˢ�µ���ͼƬ������
	if (nIDEvent == 10001)
	{
		BOOL bShowFull = ((CButton*)GetDlgItem(IDC_CHECK_SHOW_FULL_PIC))->GetCheck();
		if(!bShowFull)
		{
			if (m_ClientDC == NULL)
			{
				return;
			}
			m_cPictureWnd.ShowWindow(SW_HIDE);
			m_ClientDC->SetStretchBltMode(STRETCH_HALFTONE);
			m_ClientDC->StretchBlt(0,0,(m_rect.right - m_rect.left),(m_rect.bottom - m_rect.top), m_MemDC,0,0,m_nWidth,m_nHeight,SRCCOPY);
		}
	}
	CDialog::OnTimer(nIDEvent);
}

void CDialogEventRule::OnButtonClear() 
{
	m_alarmCount = 0;
	SetDlgItemInt(IDC_STATIC_ALARM_COUNT, m_alarmCount, FALSE);
}

void CDialogEventRule::OnBnClickedButtonClearData()
{
	int nCount = m_lcRealEvent.GetItemCount();
	for ( int i = 0; i < nCount; i++ )
	{
		delete[] (char*)(m_lcRealEvent.GetItemData(i));
	}
	m_lcRealEvent.DeleteAllItems();
}

BOOL CDialogEventRule::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg-> message   ==   WM_KEYDOWN) 
    { 
		   switch(pMsg-> wParam) 
		   {
		   case   VK_RETURN://���λس� 
			   return   TRUE; 
		   case   VK_ESCAPE://����Esc 
			   return   TRUE; 
		   } 
	   } 
	return CDialog::PreTranslateMessage(pMsg);
}

void CDialogEventRule::OnKeydownListctrlRealEvent(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_KEYDOWN* pLVKeyDow = (LV_KEYDOWN*)pNMHDR;
	int nCurIndex = (int)m_lcRealEvent.GetFirstSelectedItemPosition() - 1;
	
	//��ʾ��һ������һ����¼
	if (pLVKeyDow->wVKey == 38 || pLVKeyDow->wVKey == 40)
	{
		int newIndex = 0;
		if (pLVKeyDow->wVKey == 38)//up
		{
			newIndex = (nCurIndex == 0)? nCurIndex : nCurIndex -1;
		}
		else//down
		{
			newIndex = (nCurIndex == m_lcRealEvent.GetItemCount()-1) ? nCurIndex : nCurIndex + 1;
		}
		DisplaySelectedPicInfo(newIndex, &m_lcRealEvent);
	}
	*pResult = 0;
}


void CDialogEventRule::DisplaySelectedPicInfo(int nItemIndex, CListCtrl* listCtrl)
{
	//����±�ĺϷ���
	if ( (nItemIndex < 0) 
		||(nItemIndex >= listCtrl->GetItemCount())
		)
	{
		return;
	}
	
	//��ȡ�����ļ��е�λ��
	std::string strDataFolder = GetDataFolder();
	
	//��ȡ��¼ID
	char* szGUID = (char*)(listCtrl->GetItemData(nItemIndex));
	if (szGUID != NULL)
	{
		strDataFolder.append(szGUID);
	}
	else
	{
		return;
	}
	
	//��ȡ��¼�ļ�
	std::string strJpgFilePath = strDataFolder.append(".jpg");
	
	//��ʾ���գ������ϵ����֣�
	ALARM_ITEM* itemPtr = m_pcQueryDlg->GetAlarmItemByGUID(szGUID);
	if (itemPtr == NULL)
	{
		return;
	}
	TryDisplayLP(itemPtr->nAlarmType, itemPtr->pAlarmInfo, GetDlgItem(IDC_STATIC_LP));
	
	//��ʾͼƬ
	//this->DisplayPic(strJpgFilePath.c_str());
	
	//��ʾͼƬ�еĳ���
	//TryDisplayLPPic(strJpgFilePath.c_str(), itemPtr, GetDlgItem(IDC_STATIC_EVENT_LP_IMAGE));

	ALARM_ITEM* item = m_pcQueryDlg->GetAlarmItemByGUID(szGUID);
	TryDisplayImageAndLPPart(strJpgFilePath.c_str(), 
							itemPtr, 
							GetDlgItem(IDC_STATIC_PICTURE), 
							GetDlgItem(IDC_STATIC_EVENT_LP_IMAGE));
}

/************************************************************************/
/* �ı�����������ʾ��ı���ɫ��������ɫ                                 */
/************************************************************************/
HBRUSH CDialogEventRule::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if (pWnd-> GetDlgCtrlID() == IDC_STATIC_LP)
	{
		pDC-> SetBkColor(RGB(0,0,255)); 
		pDC-> SetTextColor(RGB(255,255,255)); 
	}
	return hbr;
}

void CDialogEventRule::OnButtonManualSnap() 
{
	UpdateData(TRUE);
	int nChannel = m_cbMSChannel.GetCurSel();
	if ( (nChannel < 0) || (m_lLoginID == 0) )
	{
		MessageBox(ConvertString("Please login and select a channel before mannal snap!"),ConvertString("Prompt"));
		return;
	}

	MANUAL_SNAP_PARAMETER stuSanpParam = {0};
	stuSanpParam.nChannel = 0;
	// �ַ��������жϣ�����124�����ջ���
	int nCpLen = m_strSnapSeq.GetLength() > 64 ? 64 : m_strSnapSeq.GetLength();
	memcpy(stuSanpParam.bySequence, m_strSnapSeq, nCpLen);
	BOOL bRet = CLIENT_ControlDevice(m_lLoginID, DH_MANUAL_SNAP, &stuSanpParam);
	if (!bRet)
	{
		MessageBox(ConvertString("mannal snap failed!"),ConvertString("Prompt"));
		return;
	}
}

void CDialogEventRule::ChangeDisplayArrange(int nArrangMode)
{
	//��ɾ�����е���
	int nItemCount = m_lcRealEvent.GetItemCount();
	for (int i = 0 ; i < nItemCount; i++)
	{
		char* szGUID = (char*)(m_lcRealEvent.GetItemData(i));
		delete[] szGUID;
	}
	m_lcRealEvent.DeleteAllItems();

	std::list<GUID>::iterator iterGroupId = m_lsGroupId.begin();
	for (; iterGroupId != m_lsGroupId.end();)
	{
		m_lsGroupId.erase(iterGroupId++);
	}


	//���¼�����Ӧ�����͵�����
	std::list<ALARM_ITEM>::iterator iter = m_allAlarmItems.begin();
	for (; iter != m_allAlarmItems.end(); iter++)
	{
		this->DisplayInfo((*iter).strGUID.c_str(), (*iter).nAlarmType, (*iter).pAlarmInfo, (*iter).nPictureGroupId, (*iter).nEventGroupId);
	}
}

// �������з�ʽ���޸ģ�������ʾ�б�
void CDialogEventRule::OnSelchangeComboArrange() 
{
	int nIndex = m_cbArrange.GetCurSel();
	m_nArrangMode = m_cbArrange.GetItemData(nIndex);
	
	ChangeDisplayArrange(m_nArrangMode);
}


void CDialogEventRule::OnDisConnect(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser)
{
	OnButtonStop();
	OnButtonStart();
}

void CDialogEventRule::OnFlagMosaic() 
{
	// TODO: Add your control notification handler code here
	CButton* pMosaic = static_cast<CButton *>(GetDlgItem(IDC_FLAG_MOSAIC));
	if (NULL != pMosaic)
	{
		int n = pMosaic->GetCheck();
		GetDlgItem(IDC_FLAG_EVENT)->EnableWindow(BST_CHECKED != n);
	}
}

void CDialogEventRule::OnFlagEvent() 
{
	// TODO: Add your control notification handler code here
	CButton* pEvent = static_cast<CButton *>(GetDlgItem(IDC_FLAG_EVENT));
	if (NULL != pEvent)
	{
		int n = pEvent->GetCheck();
		GetDlgItem(IDC_FLAG_MOSAIC)->EnableWindow(BST_CHECKED != n);
	}
}

void CDialogEventRule::OnButtonPause() 
{
	// TODO: Add your control notification handler code here
	CString strPause;
	GetDlgItem(IDC_BUTTON_PAUSE)->GetWindowText(strPause);
	if (strPause == ConvertString("Pause"))
	{
		std::vector<LONG>::iterator iter = m_allRealLoadPicHandle.begin();
		while (iter != m_allRealLoadPicHandle.end())
		{
			BOOL bret = CLIENT_PauseLoadPic(*iter, TRUE);
			iter++;
		}
		GetDlgItem(IDC_BUTTON_PAUSE)->SetWindowText(ConvertString("Resume"));
	}
	else if (strPause == ConvertString("Resume"))
	{
		std::vector<LONG>::iterator iter = m_allRealLoadPicHandle.begin();
		while (iter != m_allRealLoadPicHandle.end())
		{
			BOOL bret = CLIENT_PauseLoadPic(*iter, FALSE);
			iter++;
		}
		GetDlgItem(IDC_BUTTON_PAUSE)->SetWindowText(ConvertString("Pause"));
	}
}

// �ڲ�ѯҳ��ɾ��������Ϣ��ͬʱ����Ҫ������ҳ���ϵ������ϢҲɾ����
void CDialogEventRule::DeletAlarmInfo(char* pGUID)
{
	if(pGUID == NULL)
	{
		return;
	}

	EnterCriticalSection(&m_csAlarmItems);
	std::list<ALARM_ITEM>::iterator iter = m_allAlarmItems.begin();
	while(iter != m_allAlarmItems.end())
	{
		if (_stricmp((*iter).strGUID.c_str(), pGUID) == 0) 
		{
			delete[] ((*iter).pAlarmInfo);
			m_allAlarmItems.erase(iter);
			break;
		}

		iter++;
	}
	LeaveCriticalSection(&m_csAlarmItems);

	return;
}
