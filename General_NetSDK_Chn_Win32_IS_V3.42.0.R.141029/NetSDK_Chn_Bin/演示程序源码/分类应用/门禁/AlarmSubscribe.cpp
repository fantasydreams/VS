// AlarmSubscribe.cpp : implementation file
//

#include "stdafx.h"
#include "AccessControl.h"
#include "AlarmSubscribe.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AlarmSubscribe dialog


AlarmSubscribe::AlarmSubscribe(CWnd* pParent /* = NULL */, LLONG hLoginID /* = NULL */, UINT32 uiAlarmIn /* = 0 */)
	: CDialog(AlarmSubscribe::IDD, pParent)
{
	//{{AFX_DATA_INIT(AlarmSubscribe)
		// NOTE: the ClassWizard will add member initialization here
	m_hLogin = hLoginID;
	m_uiAlarmIn = uiAlarmIn;
	//}}AFX_DATA_INIT
}


void AlarmSubscribe::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AlarmSubscribe)
	DDX_Control(pDX, IDC_SUBSCRIBE_CMB_TYPE, m_cbAlarmType);
	DDX_Control(pDX, IDC_SUBSCRIBE_CMB_CHN, m_cbChannel);
	DDX_Control(pDX, IDC_LIST_ALARM_REPORT, m_ctrAlarmRptList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AlarmSubscribe, CDialog)
	//{{AFX_MSG_MAP(AlarmSubscribe)
	ON_BN_CLICKED(IDC_SUBSCRIBE_BTN_SUB, OnButtonSub)
	ON_BN_CLICKED(IDC_SUBSCRIBE_BTN_STOP, OnButtonStop)
	ON_BN_CLICKED(IDC_SUBSCRIBE_BTN_CONFIRM, OnBtnConfirm)
	ON_CBN_SELCHANGE(IDC_SUBSCRIBE_CMB_TYPE, OnSelchangeSubscribeCmbType)
	ON_WM_DESTROY()
	ON_MESSAGE(WM_ALARM_INFO, OnAlarmInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AlarmSubscribe private method

void AlarmSubscribe::InitListControl()
{
	m_ctrAlarmRptList.SetExtendedStyle(m_ctrAlarmRptList.GetExtendedStyle()| LVS_EX_HEADERDRAGDROP | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES );
	m_ctrAlarmRptList.InsertColumn(0, ConvertString("Index", DLG_SUBSCRIBE), LVCFMT_LEFT, 60, -1);
	m_ctrAlarmRptList.InsertColumn(1, ConvertString("alarm type", DLG_SUBSCRIBE), LVCFMT_LEFT, 90, -1);
	m_ctrAlarmRptList.InsertColumn(2, ConvertString("channel", DLG_SUBSCRIBE), LVCFMT_LEFT, 70, -1);
	m_ctrAlarmRptList.InsertColumn(3, ConvertString("alarm state", DLG_SUBSCRIBE), LVCFMT_LEFT, 90, -1);
	m_ctrAlarmRptList.InsertColumn(4, ConvertString("time", DLG_SUBSCRIBE), LVCFMT_LEFT, 120, -1);
	m_ctrAlarmRptList.InsertColumn(5, ConvertString("info", DLG_SUBSCRIBE), LVCFMT_LEFT, 150, -1);
}

void AlarmSubscribe::GetTimeStringByStruct(NET_TIME stuTime, char *pTime)
{
	if (pTime)
	{
		sprintf(pTime, "%d-%d-%d %d:%d:%d", stuTime.dwYear, stuTime.dwMonth, stuTime.dwDay,
			stuTime.dwHour, stuTime.dwMinute, stuTime.dwSecond);
	}
}

void AlarmSubscribe::UpdateEventList()
{
	//���������ų���10000��λΪ0
	if (m_nAlarmIndex >= MAX_MSG_SHOW)
	{
		m_nAlarmIndex = 0;
		m_ctrAlarmRptList.DeleteAllItems();
	}
}

// ÿ�������¼�����Ϣ����ΪͶ����Ϣ�����壬�û������ڴ�
typedef struct tagAlarmInfo
{
	long	lCommand;
	char*	pBuf;
	DWORD	dwBufLen;

	tagAlarmInfo()
	{
		lCommand = 0;
		pBuf = NULL;
		dwBufLen = 0;
	}

	~tagAlarmInfo()
	{
		if (pBuf)
		{
			delete []pBuf;
		}
	}
}AlarmInfo;

BOOL CALLBACK MessCallBack(LONG lCommand, LLONG lLoginID, char *pBuf,
						   DWORD dwBufLen, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser)
{
	if(!dwUser) 
	{
		return FALSE;
	}
	
	AlarmSubscribe* dlg = (AlarmSubscribe*)dwUser;
	BOOL bRet = FALSE;
	if (dlg != NULL && dlg->GetSafeHwnd())
	{
		AlarmInfo* pInfo = new AlarmInfo;
		if (!pInfo)
		{
			return FALSE;
		}
		pInfo->lCommand = lCommand;
		pInfo->pBuf = new char[dwBufLen];
		if (!pInfo->pBuf)
		{
			delete pInfo;
			return FALSE;
		}
		memcpy(pInfo->pBuf, pBuf, dwBufLen);
		pInfo->dwBufLen = dwBufLen;
		{
			TRACE("MessCallBack triggered %08x in Demo...\n", pInfo->lCommand);
		}
		dlg->PostMessage(WM_ALARM_INFO, (WPARAM)pInfo, (LPARAM)0);
	}

	return bRet;	
}

LRESULT AlarmSubscribe::OnAlarmInfo(WPARAM wParam, LPARAM lParam)
{
	AlarmInfo* pAlarmInfo = (AlarmInfo*)wParam;
	if (!pAlarmInfo || !pAlarmInfo->pBuf || pAlarmInfo->dwBufLen <= 0)
	{
		return -1;
	}
	
	SYSTEMTIME st;
	GetLocalTime(&st);
	TRACE("%04d-%02d-%02d %02d:%02d:%02d.%03d Alarm callback: cmd:%08x, buflen:%08x,\n", 
		st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond,
		pAlarmInfo->lCommand, pAlarmInfo->dwBufLen);

	CString csLog;

	switch (pAlarmInfo->lCommand)
	{
	case DH_ALARM_ACCESS_CTL_EVENT:
		{
			InsertAccessCtlEvent((ALARM_ACCESS_CTL_EVENT_INFO*)pAlarmInfo->pBuf);
		}
		break;
	case DH_ALARM_ACCESS_CTL_BREAK_IN:
		{
			InsertAccessCtlBreakIn((ALARM_ACCESS_CTL_BREAK_IN_INFO*)pAlarmInfo->pBuf);
		}
		break;
	case DH_ALARM_ACCESS_CTL_DURESS:
		{
			InsertAccessCtlDuress((ALARM_ACCESS_CTL_DURESS_INFO*)pAlarmInfo->pBuf);
		}
		break;
	case DH_ALARM_ACCESS_CTL_NOT_CLOSE:
		{
			InsertAccessCtlNotClose((ALARM_ACCESS_CTL_NOT_CLOSE_INFO*)pAlarmInfo->pBuf);
		}
		break;
	case DH_ALARM_ACCESS_CTL_REPEAT_ENTER:
		{
			InsertAccessCtlRepeatEnter((ALARM_ACCESS_CTL_REPEAT_ENTER_INFO*)pAlarmInfo->pBuf);
		}
		break;
	case DH_ALARM_ACCESS_CTL_STATUS:
		{
			InsertAccessCtlStatus((ALARM_ACCESS_CTL_STATUS_INFO*)pAlarmInfo->pBuf);
		}
		break;
	default:
		break;
	}

	if (pAlarmInfo)
	{
		if (pAlarmInfo->pBuf)
		{
			delete[] pAlarmInfo->pBuf;
			pAlarmInfo->pBuf = NULL;
		}
		delete pAlarmInfo;
		pAlarmInfo = NULL;
	}

	return 0;
}

void AlarmSubscribe::InsertAccessCtlEvent(ALARM_ACCESS_CTL_EVENT_INFO* pInfo)
{
	if (NULL == pInfo || 0 == pInfo->dwSize)
	{
		return;
	}
	UpdateEventList();
	
	char szIndex[32] = {0};
	itoa(m_nAlarmIndex + 1, szIndex, 10);
	m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
	
	m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);
	
	m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("AccessCtlEvent", DLG_SUBSCRIBE));
	
	DWORD dwSize = sizeof(pInfo->dwSize);
	
	// channelID
	dwSize += sizeof(pInfo->nDoor);
	if (dwSize <= pInfo->dwSize)
	{
		CString csChannelId;
		// SDK�����û���ͨ���������0��ʼ
		csChannelId.Format("%s %03d", ConvertString("Channel", DLG_SUBSCRIBE), pInfo->nDoor + 1);
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 2, csChannelId);
	}
	
	// time
	dwSize += sizeof(pInfo->stuTime);
	if (dwSize <= pInfo->dwSize)
	{
		char szAlarmTime[64] = {0};
		GetTimeStringByStruct(pInfo->stuTime, szAlarmTime);
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 4, szAlarmTime);
	}
	
	// name, evenType, status, cardType, openMethod, cardNo, pwd
	dwSize += sizeof(pInfo->szDoorName);
	if (dwSize <= pInfo->dwSize)
	{
		CString csInfo;
		csInfo.Format("");
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex++, 5, csInfo);
	}
}

void AlarmSubscribe::InsertAccessCtlBreakIn(ALARM_ACCESS_CTL_BREAK_IN_INFO* pInfo)
{
	if (NULL == pInfo || 0 == pInfo->dwSize)
	{
		return;
	}
	UpdateEventList();
	
	char szIndex[32] = {0};
	itoa(m_nAlarmIndex + 1, szIndex, 10);
	m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
	
	m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);
	
	m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("AccessCtlBreakIn", DLG_SUBSCRIBE));
	
	DWORD dwSize = sizeof(pInfo->dwSize);
	
	// channelID
	dwSize += sizeof(pInfo->nDoor);
	if (dwSize <= pInfo->dwSize)
	{
		CString csChannelId;
		// SDK�����û���ͨ���������0��ʼ
		csChannelId.Format("%s %03d", ConvertString("Channel", DLG_SUBSCRIBE), pInfo->nDoor + 1);
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 2, csChannelId);
	}
	
	// time
	dwSize += sizeof(pInfo->stuTime);
	if (dwSize <= pInfo->dwSize)
	{
		char szAlarmTime[64] = {0};
		GetTimeStringByStruct(pInfo->stuTime, szAlarmTime);
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 4, szAlarmTime);
	}
	
	// name
	dwSize += sizeof(pInfo->szDoorName);
	if (dwSize <= pInfo->dwSize)
	{
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex++, 5, pInfo->szDoorName);
	}
}

void AlarmSubscribe::InsertAccessCtlDuress(ALARM_ACCESS_CTL_DURESS_INFO* pInfo)
{
	if (NULL == pInfo || 0 == pInfo->dwSize)
	{
		return;
	}
	UpdateEventList();
	
	char szIndex[32] = {0};
	itoa(m_nAlarmIndex + 1, szIndex, 10);
	m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
	
	m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);
	
	m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("AccessCtlDuress", DLG_SUBSCRIBE));
	
	DWORD dwSize = sizeof(pInfo->dwSize);
	
	// channelID
	dwSize += sizeof(pInfo->nDoor);
	if (dwSize <= pInfo->dwSize)
	{
		CString csChannelId;
		// SDK�����û���ͨ���������0��ʼ
		csChannelId.Format("%s %03d", ConvertString("Channel", DLG_SUBSCRIBE), pInfo->nDoor + 1);
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 2, csChannelId);
	}

	// time
	dwSize += sizeof(pInfo->stuTime);
	if (dwSize <= pInfo->dwSize)
	{
		char szAlarmTime[64] = {0};
		GetTimeStringByStruct(pInfo->stuTime, szAlarmTime);
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 4, szAlarmTime);
	}
	
	// name &&  card no
	dwSize += sizeof(pInfo->szDoorName);
	if (dwSize <= pInfo->dwSize)
	{
		CString csInfo;
		csInfo.Format("%s:%s, %s:%s", ConvertString("Name", DLG_SUBSCRIBE), pInfo->szDoorName,
			ConvertString("CardNo", DLG_SUBSCRIBE), pInfo->szCardNo);
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex++, 5, csInfo);
	}
}

void AlarmSubscribe::InsertAccessCtlNotClose(ALARM_ACCESS_CTL_NOT_CLOSE_INFO* pInfo)
{
	if (NULL == pInfo || 0 == pInfo->dwSize)
	{
		return;
	}
	UpdateEventList();
	
	char szIndex[32] = {0};
	itoa(m_nAlarmIndex + 1, szIndex, 10);
	m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
	
	m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);
	
	m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("DoorNotClose", DLG_SUBSCRIBE));
	
	DWORD dwSize = sizeof(pInfo->dwSize);
	
	// channelID
	dwSize += sizeof(pInfo->nDoor);
	if (dwSize <= pInfo->dwSize)
	{
		CString csChannelId;
		// SDK�����û���ͨ���������0��ʼ
		csChannelId.Format("%s %03d", ConvertString("Channel", DLG_SUBSCRIBE), pInfo->nDoor + 1);
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 2, csChannelId);
	}
	
	// action
	dwSize += sizeof(pInfo->nAction);
	if (dwSize <= pInfo->dwSize)
	{
		if (pInfo->nAction == 0)
		{
			m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("start", DLG_SUBSCRIBE));
		} 
		else if(pInfo->nAction == 1)
		{
			m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("stop", DLG_SUBSCRIBE));
		}
		else
		{
			m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("unknown", DLG_SUBSCRIBE));
		}
	}
	
	// time
	dwSize += sizeof(pInfo->stuTime);
	if (dwSize <= pInfo->dwSize)
	{
		char szAlarmTime[64] = {0};
		GetTimeStringByStruct(pInfo->stuTime, szAlarmTime);
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 4, szAlarmTime);
	}
	
	// name
	dwSize += sizeof(pInfo->szDoorName);
	if (dwSize <= pInfo->dwSize)
	{
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex++, 5, pInfo->szDoorName);
	}	
}

void AlarmSubscribe::InsertAccessCtlRepeatEnter(ALARM_ACCESS_CTL_REPEAT_ENTER_INFO* pInfo)
{
	if (NULL == pInfo || 0 == pInfo->dwSize)
	{
		return;
	}
	UpdateEventList();
	
	char szIndex[32] = {0};
	itoa(m_nAlarmIndex + 1, szIndex, 10);
	m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
	
	m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);
	
	m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("RepeatEnter", DLG_SUBSCRIBE));
	
	DWORD dwSize = sizeof(pInfo->dwSize);
	
	// channelID
	dwSize += sizeof(pInfo->nDoor);
	if (dwSize <= pInfo->dwSize)
	{
		CString csChannelId;
		// SDK�����û���ͨ���������0��ʼ
		csChannelId.Format("%s %03d", ConvertString("Channel", DLG_SUBSCRIBE), pInfo->nDoor + 1);
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 2, csChannelId);
	}

	// time
	dwSize += sizeof(pInfo->stuTime);
	if (dwSize <= pInfo->dwSize)
	{
		char szAlarmTime[64] = {0};
		GetTimeStringByStruct(pInfo->stuTime, szAlarmTime);
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 4, szAlarmTime);
	}
	
	// name
	dwSize += sizeof(pInfo->szDoorName);
	if (dwSize <= pInfo->dwSize)
	{
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex++, 5, pInfo->szDoorName);
	}
}

void AlarmSubscribe::InsertAccessCtlStatus(ALARM_ACCESS_CTL_STATUS_INFO* pInfo)
{
	if (NULL == pInfo || 0 == pInfo->dwSize)
	{
		return;
	}
	UpdateEventList();
	
	char szIndex[32] = {0};
	itoa(m_nAlarmIndex + 1, szIndex, 10);
	m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
	
	m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);
	
	m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("DoorStatus", DLG_SUBSCRIBE));
	
	DWORD dwSize = sizeof(pInfo->dwSize);

	// channelID
	dwSize += sizeof(pInfo->nDoor);
	if (dwSize <= pInfo->dwSize)
	{
		CString csChannelId;
		// SDK�����û���ͨ���������0��ʼ
		csChannelId.Format("%s %03d", ConvertString("Channel", DLG_SUBSCRIBE), pInfo->nDoor + 1);
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 2, csChannelId);
	}

	// time
	dwSize += sizeof(pInfo->stuTime);
	if (dwSize <= pInfo->dwSize)
	{
		char szAlarmTime[64] = {0};
		GetTimeStringByStruct(pInfo->stuTime, szAlarmTime);
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 4, szAlarmTime);
	}

	// status
	dwSize += sizeof(pInfo->emStatus);
	if (dwSize <= pInfo->dwSize)
	{
		CString csStatus;
		if (NET_ACCESS_CTL_STATUS_TYPE_UNKNOWN == pInfo->emStatus)
		{
			csStatus = ConvertString("Unknown", DLG_SUBSCRIBE);
		}
		else if (NET_ACCESS_CTL_STATUS_TYPE_OPEN == pInfo->emStatus)
		{
			csStatus = ConvertString("Open", DLG_SUBSCRIBE);
		}
		else if (NET_ACCESS_CTL_STATUS_TYPE_CLOSE == pInfo->emStatus)
		{
			csStatus = ConvertString("Close", DLG_SUBSCRIBE);
		}
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex++, 5, ConvertString(csStatus, DLG_SUBSCRIBE));
	}
}

/////////////////////////////////////////////////////////////////////////////
// AlarmSubscribe message handlers

BOOL AlarmSubscribe::OnInitDialog()
{
	CDialog::OnInitDialog();
	g_SetWndStaticText(this, DLG_SUBSCRIBE);
// 	if (!m_hLogin)
// 	{
// 		MessageBox("Please login device first.", ConvertString("Prompt"));
// 		return TRUE;
// 	}

	m_nAlarmIndex = 0;
	InitListControl();

	int i = 0;
	for (i = 0; i < sizeof(stuDemoConfirmEvent) / sizeof(stuDemoConfirmEvent[0]); i++)
	{
		m_cbAlarmType.InsertString(-1, ConvertString(stuDemoConfirmEvent[i].pszName, DLG_SUBSCRIBE));
	}
	m_cbAlarmType.SetCurSel(-1);

	int nChannelNum = m_uiAlarmIn == 0 ? 16 : m_uiAlarmIn;
	for (i = 0; i < nChannelNum; i++)
	{
		CString csTmp;
		csTmp.Format("%s %02d", ConvertString("Channel", DLG_SUBSCRIBE), i + 1);
		m_cbChannel.InsertString(-1, csTmp);
	}
	m_cbChannel.SetCurSel(-1);

	GetDlgItem(IDC_SUBSCRIBE_BTN_SUB)->EnableWindow(TRUE);
	GetDlgItem(IDC_SUBSCRIBE_BTN_STOP)->EnableWindow(FALSE);

	UpdateData(FALSE);

	return TRUE; 
}

void AlarmSubscribe::OnButtonSub() 
{
	// TODO: Add your control notification handler code here
	if (!m_hLogin)
	{
		MessageBox(ConvertString("Please login device first.", DLG_SUBSCRIBE), ConvertString("Prompt"));
		return;
	}

	// ���ûص��ӿ�
	CLIENT_SetDVRMessCallBack(MessCallBack, (LDWORD)this);

	BOOL bRet = CLIENT_StartListenEx(m_hLogin);
	if (!bRet)
	{
		MessageBox(ConvertString("Subscribe failed.", DLG_SUBSCRIBE), ConvertString("Prompt"));
		return;
	}
	
	m_nAlarmIndex = 0;
	m_ctrAlarmRptList.DeleteAllItems();

	//MessageBox("Subscribe ok.", ConvertString("Prompt"));

	GetDlgItem(IDC_SUBSCRIBE_BTN_SUB)->EnableWindow(FALSE);
	GetDlgItem(IDC_SUBSCRIBE_BTN_STOP)->EnableWindow(TRUE);

	return;
}

void AlarmSubscribe::OnButtonStop() 
{
	// TODO: Add your control notification handler code here
	//if (!m_hLogin || !m_hSubscribe)
	if(m_hLogin == 0)
	{
		MessageBox(ConvertString("Please login device first.", DLG_SUBSCRIBE), ConvertString("Prompt"));
		return;
	}

	CLIENT_StopListen(m_hLogin);

	MessageBox(ConvertString("Stop Subscribe ok.", DLG_SUBSCRIBE), ConvertString("Prompt"));

	GetDlgItem(IDC_SUBSCRIBE_BTN_SUB)->EnableWindow(TRUE);
	GetDlgItem(IDC_SUBSCRIBE_BTN_STOP)->EnableWindow(FALSE);

	return;
}

void AlarmSubscribe::OnBtnConfirm() 
{
	// TODO: Add your control notification handler code here
	NET_CTRL_CLEAR_ALARM stuInParam = {sizeof(NET_CTRL_CLEAR_ALARM)};
	stuInParam.nChannelID = m_cbChannel.GetCurSel();
	stuInParam.emAlarmType = (NET_ALARM_TYPE)m_cbAlarmType.GetCurSel();
	CString csPsw;
	GetDlgItemText(IDC_SUBSCRIBE_EDIT_PASSWORD, csPsw);
	stuInParam.szDevPwd = csPsw.GetBuffer(0);
// 	if (!csPsw.GetLength())
// 	{
// 		MessageBox(ConvertString("password length error...", DLG_SUBSCRIBE), ConvertString("Prompt"));
// 		return;
// 	}

	BOOL bRet = CLIENT_ControlDevice(m_hLogin, DH_CTRL_CLEAR_ALARM, (void *)&stuInParam, 3000);
	if (bRet)
	{
		MessageBox(ConvertString("ConfirmEvent ok", DLG_SUBSCRIBE), ConvertString("Prompt"));
	}
	else
	{
		CString csErr;
		csErr.Format("%s %08x", ConvertString("ConfrimEvent error:", DLG_SUBSCRIBE), CLIENT_GetLastError());
		MessageBox(csErr, ConvertString("Prompt"));
	}
}

void AlarmSubscribe::OnSelchangeSubscribeCmbType() 
{
	// TODO: Add your control notification handler code here
	int i = 0;
	NET_ALARM_TYPE emAlarmTypeSel = (NET_ALARM_TYPE)m_cbAlarmType.GetCurSel();
	m_cbChannel.ResetContent();
	if (NET_ALARM_ALARMEXTENDED == emAlarmTypeSel)
	{
		// ��չ����ģ���ͨ����Ϊ0 ~ 255
		for (i = 0; i < 256; i++)
		{
			CString csTmp;
			csTmp.Format("%s %03d", ConvertString("ExChannel", DLG_SUBSCRIBE), i + 1);
			m_cbChannel.InsertString(-1, csTmp);
		}
	}
	else 
	{
		int nChannelNum = m_uiAlarmIn == 0 ? 16 : m_uiAlarmIn;
		for (i = 0; i < nChannelNum; i++)
		{
			CString csTmp;
			csTmp.Format("%s %02d", ConvertString("Channel", DLG_SUBSCRIBE), i + 1);
			m_cbChannel.InsertString(-1, csTmp);
		}
	}
	m_cbChannel.SetCurSel(-1);

}

void AlarmSubscribe::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	CLIENT_StopListen(m_hLogin);
}
