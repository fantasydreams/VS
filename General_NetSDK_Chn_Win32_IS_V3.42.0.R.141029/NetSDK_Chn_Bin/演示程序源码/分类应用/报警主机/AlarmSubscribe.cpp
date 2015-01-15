// AlarmSubscribe.cpp : implementation file
//

#include "stdafx.h"
#include "AlarmDevice.h"
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
	ON_BN_CLICKED(IDC_BUTTON_SUB, OnButtonSub)
	ON_BN_CLICKED(IDC_SUB_BTN_STOP, OnButtonStop)
	ON_BN_CLICKED(IDC_SUBSCRIBE_BTN_CONFIRM, OnBtnConfirm)
	ON_CBN_SELCHANGE(IDC_SUBSCRIBE_CMB_TYPE, OnSelchangeSubscribeCmbType)
	ON_WM_DESTROY()
	ON_MESSAGE(WM_ALARM_INFO, OnAlarmInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

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

	GetDlgItem(IDC_BUTTON_SUB)->EnableWindow(TRUE);
	GetDlgItem(IDC_SUB_BTN_STOP)->EnableWindow(FALSE);

	UpdateData(FALSE);

	return TRUE; 
}

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
			TRACE("MessCallBack triggered %08x in AlarmDevice...\n", pInfo->lCommand);
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
	case DH_ALARM_ALARM_EX:
		{
			InsertAlarmExEvent((BYTE*)pAlarmInfo->pBuf, pAlarmInfo->dwBufLen);
		}
		break;
	case DH_ALARM_ALARM_EX2:
		{
			InsertAlarmEx2Event((ALARM_ALARM_INFO_EX2*)pAlarmInfo->pBuf);
		}
		break;
	case DH_ALARM_POWERFAULT:
		{
			InsertPowerFaultEvent((ALARM_POWERFAULT_INFO*)pAlarmInfo->pBuf);
		}
		break;
	case DH_ALARM_CHASSISINTRUDED:
		{
			ALARM_CHASSISINTRUDED_INFO* pChassisIntrudedInfo = (ALARM_CHASSISINTRUDED_INFO*)pAlarmInfo->pBuf;
			if (pChassisIntrudedInfo != NULL && pAlarmInfo->dwBufLen >= sizeof(ALARM_CHASSISINTRUDED_INFO))
			{
				UpdateEventList();
				
				char szIndex[32] = {0};
				itoa(m_nAlarmIndex + 1, szIndex, 10);
				m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("ChassisIntruded", DLG_SUBSCRIBE));
				if (pChassisIntrudedInfo->nAction == 0)
				{
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("start", DLG_SUBSCRIBE));
				} 
				else if(pChassisIntrudedInfo->nAction == 1)
				{
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("stop", DLG_SUBSCRIBE));
				}
				else
				{
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("unknown", DLG_SUBSCRIBE));
				}
				char szAlarmTime[64] = {0};
				GetTimeStringByStruct(pChassisIntrudedInfo->stuTime, szAlarmTime);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex++, 4, szAlarmTime);
			}
		}
		break;
	case DH_ALARM_ALARMEXTENDED:
		{
			ALARM_ALARMEXTENDED_INFO* pAlarmExtendedInfo = (ALARM_ALARMEXTENDED_INFO*)pAlarmInfo->pBuf;
			if (pAlarmExtendedInfo != NULL && pAlarmInfo->dwBufLen >= sizeof(ALARM_ALARMEXTENDED_INFO))
			{
				UpdateEventList();
				
				char szIndex[32] = {0};
				itoa(m_nAlarmIndex + 1, szIndex, 10);
				m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("AlarmExtended", DLG_SUBSCRIBE));
				CString csChannelId;
				csChannelId.Format("exChannel %03d", pAlarmExtendedInfo->nChannelID + 1);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 2, csChannelId);

				if (pAlarmExtendedInfo->nAction == 0)
				{
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("start", DLG_SUBSCRIBE));
				} 
				else if(pAlarmExtendedInfo->nAction == 1)
				{
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("stop", DLG_SUBSCRIBE));
				}
				else
				{
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("unknown", DLG_SUBSCRIBE));
				}
				char szAlarmTime[64] = {0};
				GetTimeStringByStruct(pAlarmExtendedInfo->stuTime, szAlarmTime);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex++, 4, szAlarmTime);
			}
		}
		break;
	case DH_URGENCY_ALARM_EX:
		{
 			if (pAlarmInfo->dwBufLen < 4)
 			{
 				return -1;
 			}

			for (int i = 0; i < 32; i++)
			{
				BYTE* byInfo = (BYTE*)pAlarmInfo->pBuf;
				DWORD* pdwInfo = (DWORD*)pAlarmInfo->pBuf;
				if (!byInfo)
				{
					break;
				}

				DWORD dwInfo = *pdwInfo;

				UpdateEventList();

				char szIndex[32] = {0};
				itoa(m_nAlarmIndex + 1, szIndex, 10);
				m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);

				CString csChn;
				csChn.Format("%s %08d", ConvertString("channel", DLG_SUBSCRIBE), i+1);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 2, csChn);

				if (dwInfo & (1 << i) )
				{
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("Urgency ", DLG_SUBSCRIBE));
				}
				else
				{
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("No Urgency ", DLG_SUBSCRIBE));
				}
				m_nAlarmIndex++;
			}
		}
		break;
	case DH_ALARM_BATTERYLOWPOWER:
		{
			ALARM_BATTERYLOWPOWER_INFO* pChassisIntrudedInfo = (ALARM_BATTERYLOWPOWER_INFO*)pAlarmInfo->pBuf;
			if (pChassisIntrudedInfo != NULL && pAlarmInfo->dwBufLen >= sizeof(ALARM_BATTERYLOWPOWER_INFO))
			{
				UpdateEventList();
				
				char szIndex[32] = {0};
				itoa(m_nAlarmIndex + 1, szIndex, 10);
				m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("BatteryLowPower", DLG_SUBSCRIBE));
				if (pChassisIntrudedInfo->nAction == 0)
				{
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("start", DLG_SUBSCRIBE));
				} 
				else if(pChassisIntrudedInfo->nAction == 1)
				{
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("stop", DLG_SUBSCRIBE));
				}
				else
				{
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("unknown", DLG_SUBSCRIBE));
				}
				char szAlarmTime[64] = {0};
				GetTimeStringByStruct(pChassisIntrudedInfo->stTime, szAlarmTime);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 4, szAlarmTime);
				m_nAlarmIndex++;
			}
		}
		break;
	case DH_ALARM_TALKING_INVITE:
		{
			ALARM_TALKING_INVITE_INFO* pInfo = (ALARM_TALKING_INVITE_INFO*)pAlarmInfo->pBuf;
			if (pInfo != NULL && pAlarmInfo->dwBufLen >= sizeof(ALARM_TALKING_INVITE_INFO))
			{
				UpdateEventList();

				char szIndex[32] = {0};
				itoa(m_nAlarmIndex + 1, szIndex, 10);
				m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);

				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("TalkingInvite", DLG_SUBSCRIBE));

				// EventTime
				char szAlarmTime[64] = {0};
				GetTimeStringByStruct(pInfo->stuTime, szAlarmTime);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 4, szAlarmTime);
				m_nAlarmIndex++;
			}
		}
		break;
	case DH_ALARM_ARMMODE_CHANGE_EVENT:
		{
			ALARM_ARMMODE_CHANGE_INFO* pInfo = (ALARM_ARMMODE_CHANGE_INFO*)pAlarmInfo->pBuf;
			if (pInfo != NULL && pAlarmInfo->dwBufLen >= sizeof(ALARM_ARMMODE_CHANGE_INFO))
			{
				UpdateEventList();
				char szIndex[32] = {0};
				itoa(m_nAlarmIndex + 1, szIndex, 10);
				m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);
				// Name
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("ArmModeChange", DLG_SUBSCRIBE));
				// AlarmState
				switch(pInfo->bArm)
				{
				case NET_ALARM_MODE_DISARMING:
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("Disarming", DLG_SUBSCRIBE));
					break;
				case NET_ALARM_MODE_ARMING:
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("Arming", DLG_SUBSCRIBE));
					break;
				default:
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("Unknown", DLG_SUBSCRIBE));
					break;
				}
				// EventTime
				char szAlarmTime[64] = {0};
				GetTimeStringByStruct(pInfo->stuTime, szAlarmTime);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 4, szAlarmTime);
				// Scene mode
				switch(pInfo->emSceneMode)
				{
				case NET_SCENE_MODE_OUTDOOR:
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 5, ConvertString("Outdoor", DLG_SUBSCRIBE));
					break;
				case NET_SCENE_MODE_INDOOR:
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 5, ConvertString("AtHome", DLG_SUBSCRIBE));
					break;
				default:
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 5, ConvertString("Unknown", DLG_SUBSCRIBE));
					break;
				}
				++m_nAlarmIndex;
			}
		}
		break;
	case DH_ALARM_BYPASSMODE_CHANGE_EVENT:
		{
			ALARM_BYPASSMODE_CHANGE_INFO* pInfo = (ALARM_BYPASSMODE_CHANGE_INFO*)pAlarmInfo->pBuf;
			if (pInfo != NULL && pAlarmInfo->dwBufLen >= sizeof(ALARM_BYPASSMODE_CHANGE_INFO))
			{
				UpdateEventList();
				char szIndex[32] = {0};
				itoa(m_nAlarmIndex + 1, szIndex, 10);
				m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);
				// Name
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("BypassModeChange", DLG_SUBSCRIBE));
				// ChannelID
				CString csChn;
				csChn.Format("%s %03d", ConvertString("Channel", DLG_SUBSCRIBE), pInfo->nChannelID + 1);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 2, csChn);
				// AlarmState
				if (pInfo->emMode == NET_BYPASS_MODE_BYPASS)
				{
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("Change to Bypass", DLG_SUBSCRIBE));
				}
				else if (pInfo->emMode == NET_BYPASS_MODE_NORMAL)
				{
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("Change to Normal", DLG_SUBSCRIBE));
				}
				else
				{
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("Change to Unknown", DLG_SUBSCRIBE));
				}
				// EventTime
				char szAlarmTime[64] = {0};
				GetTimeStringByStruct(pInfo->stuTime, szAlarmTime);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 4, szAlarmTime);
				// Info
				CString csInfo;
				csInfo.Format("%s:%s, %s:%s",ConvertString("DefenceType", DLG_SUBSCRIBE), 
					pInfo->emDefenceType == NET_DEFENCEAREA_TYPE_ALARM ? ConvertString("Alarm", DLG_SUBSCRIBE) : ConvertString("Unknown", DLG_SUBSCRIBE),
					ConvertString("IsExtendChn", DLG_SUBSCRIBE), pInfo->nIsExtend == 1 ? "Yes" : "No");
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex++, 5, csInfo);
			}
		}
		break;
	case DH_ALARM_NET_ABORT:
		{		
			ALARM_NETABORT_INFO* pNetBortInfo = (ALARM_NETABORT_INFO*)pAlarmInfo->pBuf;
			if (pNetBortInfo != NULL && pAlarmInfo->dwBufLen >= sizeof(ALARM_NETABORT_INFO))
			{
				UpdateEventList();
				
				char szIndex[32] = {0};
				itoa(m_nAlarmIndex + 1, szIndex, 10);
				m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString(CFG_CMD_NETABORT, DLG_SUBSCRIBE));
				if (pNetBortInfo->nAction == 0)
				{
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("start", DLG_SUBSCRIBE));
				} 
				else if(pNetBortInfo->nAction == 1)
				{
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("stop", DLG_SUBSCRIBE));
				}
				else
				{
					m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("Unknown", DLG_SUBSCRIBE));
				}
				char szAlarmTime[64] = {0};
				GetTimeStringByStruct(pNetBortInfo->stuTime, szAlarmTime);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 4, szAlarmTime);

				CString csType = ConvertString("NetAbort", DLG_SUBSCRIBE);
				if (pNetBortInfo->emNetAbortType == EM_NETABORT_EVENT_TYPE_WIRE)
				{
					csType += ConvertString(" EVENT_WIRE", DLG_SUBSCRIBE);
				} 
				else if (pNetBortInfo->emNetAbortType == EM_NETABORT_EVENT_TYPE_WIRELESS)
				{
					csType += ConvertString(" EVENT_WIRELESS", DLG_SUBSCRIBE);
				}
				else if (pNetBortInfo->emNetAbortType == EM_NETABORT_EVENT_TYPE_3G)
				{
					csType += ConvertString(" EVENT_3G", DLG_SUBSCRIBE);
				}
				else
				{
					csType += ConvertString(" Unknow_Type", DLG_SUBSCRIBE);
				}
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex++, 5, csType);
			}
		}
		break;
	case DH_URGENCY_ALARM_EX2:
		{
			ALARM_URGENCY_ALARM_EX2* pInfo = (ALARM_URGENCY_ALARM_EX2*)pAlarmInfo->pBuf;
			if (pInfo != NULL && pInfo->dwSize >= sizeof(ALARM_URGENCY_ALARM_EX2))
			{
				UpdateEventList();
				
				char szIndex[32] = {0};
				itoa(m_nAlarmIndex + 1, szIndex, 10);
				m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);	
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("UrgencyEx", DLG_SUBSCRIBE));
				char szAlarmTime[64] = {0};
				GetTimeStringByStruct(pInfo->stuTime, szAlarmTime);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex++, 4, szAlarmTime);
			}
		}
		break;
	case DH_ALARM_INPUT_SOURCE_SIGNAL:
		{
			ALARM_INPUT_SOURCE_SIGNAL_INFO* pInfo = (ALARM_INPUT_SOURCE_SIGNAL_INFO*)pAlarmInfo->pBuf;
			if (pInfo != NULL && pInfo->dwSize >= sizeof(ALARM_INPUT_SOURCE_SIGNAL_INFO))
			{
				UpdateEventList();
				
				char szIndex[32] = {0};
				itoa(m_nAlarmIndex + 1, szIndex, 10);
				m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);
				
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("AlarmInputSourceSignal", DLG_SUBSCRIBE));

				CString csChannelId;
				// SDK�����û���ͨ���������0��ʼ
				csChannelId.Format("Channel %03d", pInfo->nChannelID + 1);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 2, csChannelId);
				
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

				char szAlarmTime[64] = {0};
				GetTimeStringByStruct(pInfo->stuTime, szAlarmTime);
				m_ctrAlarmRptList.SetItemText(m_nAlarmIndex++, 4, szAlarmTime);
			}
		}
		break;
	case DH_ALARM_ANALOGALARM_EVENT:
		{
			InsertAnalogAlarmEvent((ALARM_ANALOGALARM_EVENT_INFO*)pAlarmInfo->pBuf);
		}
		break;
    case DH_ALARM_ALARMCLEAR:
        {
            InsertAlarmClearEvent((ALARM_ALARMCLEAR_INFO*)pAlarmInfo->pBuf);
        }
        break;
    case DH_ALARM_CIDEVENT:
        {
            InsertCIDEvent((ALARM_CIDEVENT_INFO*)pAlarmInfo->pBuf);
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

void AlarmSubscribe::InsertAlarmExEvent(BYTE* byBuf, int nLen)
{
	if (NULL == byBuf && nLen <= 0)
	{
		return;
	}
	UpdateEventList();
	

	for (int i = 0; i < nLen; i++)
	{
		char szIndex[32] = {0};
		itoa(m_nAlarmIndex + 1, szIndex, 10);
		m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
		
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);
		
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("AlarmLocalEx", DLG_SUBSCRIBE));
		
		CString csChannelId;
		csChannelId.Format("%s %03d", ConvertString("Channel", DLG_SUBSCRIBE), i + 1);
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 2, csChannelId);

		if (byBuf[i])
		{
			m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("start", DLG_SUBSCRIBE));	
		}
		else
		{
			m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 3, ConvertString("stop", DLG_SUBSCRIBE));
		}
		
		m_nAlarmIndex++;
	}	
}

void AlarmSubscribe::InsertAlarmEx2Event(ALARM_ALARM_INFO_EX2* pInfo)
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
	
	m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("AlarmLocalEx2", DLG_SUBSCRIBE));
	
	CString csChannelId;
	// SDK�����û���ͨ���������0��ʼ
	csChannelId.Format("%s %03d", ConvertString("Channel", DLG_SUBSCRIBE), pInfo->nChannelID + 1);
	m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 2, csChannelId);
	
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
	char szAlarmTime[64] = {0};
	GetTimeStringByStruct(pInfo->stuTime, szAlarmTime);
	m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 4, szAlarmTime);
	
	CString csSense;
	SenseTypeToStr(pInfo->emSenseType, csSense);
	m_ctrAlarmRptList.SetItemText(m_nAlarmIndex++, 5, ConvertString(csSense, DLG_SUBSCRIBE));
}

void AlarmSubscribe::InsertPowerFaultEvent(ALARM_POWERFAULT_INFO* pInfo)
{
	if (pInfo != NULL && pInfo->dwSize >= sizeof(ALARM_POWERFAULT_INFO))
	{
		UpdateEventList();
		
		char szIndex[32] = {0};
		itoa(m_nAlarmIndex + 1, szIndex, 10);
		m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString(CFG_CMD_POWERFAULT, DLG_SUBSCRIBE));
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
		char szAlarmTime[64] = {0};
		GetTimeStringByStruct(pInfo->stuTime, szAlarmTime);
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 4, szAlarmTime);
		CString csTempInfo;
		if (pInfo->emPowerType == EM_POWER_TYPE_MAIN)
		{
			csTempInfo += ConvertString("Main", DLG_SUBSCRIBE);
		}
		else if (pInfo->emPowerType == EM_POWER_TYPE_BACKUP)
		{
			csTempInfo += ConvertString("Backup", DLG_SUBSCRIBE);
		}
		
		if (pInfo->emPowerFaultEvent == EM_POWERFAULT_EVENT_LOST)
		{
			csTempInfo += ConvertString(" Lost", DLG_SUBSCRIBE);
		}
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex++, 5, csTempInfo);	
	}
}

void AlarmSubscribe::InsertAnalogAlarmEvent(ALARM_ANALOGALARM_EVENT_INFO* pInfo)
{
	if (pInfo && pInfo->dwSize > 0)
	{
		UpdateEventList();
		char szIndex[32] = {0};
		itoa(m_nAlarmIndex + 1, szIndex, 10);
		m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);
		
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("AnalogAlarmEvent", DLG_SUBSCRIBE));

		int nSize = sizeof(pInfo->dwSize);

		// channelID
		nSize += sizeof(pInfo->nChannelID);
		if (nSize <= pInfo->dwSize)
		{
			CString csChannelId;
			// SDK�����û���ͨ���������0��ʼ
			csChannelId.Format("%s %03d", ConvertString("Channel", DLG_SUBSCRIBE), pInfo->nChannelID + 1);
			m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 2, csChannelId);
		}

		// nAction
		nSize += sizeof(pInfo->nAction);
		if (nSize <= pInfo->dwSize)
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
		nSize += sizeof(pInfo->stuTime);
		if (nSize <= pInfo->dwSize)
		{
			char szAlarmTime[64] = {0};
			GetTimeStringByStruct(pInfo->stuTime, szAlarmTime);
			m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 4, szAlarmTime);
		}

		CString csInfo;
		{
			// sensor type
			nSize += sizeof(pInfo->emSensorType);
			if (nSize <= pInfo->dwSize)
			{
				CString csSensor;
				SenseTypeToStr(pInfo->emSensorType, csSensor);
				csInfo += ConvertString(csSensor, DLG_CFG_ALARM);
				csInfo += ",";
			}

			// name
			nSize += sizeof(pInfo->szName);
			if (nSize <= pInfo->dwSize)
			{
				CString csName(pInfo->szName);
				csInfo += csName;
				csInfo += ",";
			}

			// is valid
			nSize += sizeof(pInfo->nIsValid);
			if (nSize <= pInfo->dwSize)
			{
				CString csValid = pInfo->nIsValid ? "Valid" : "Invalid";
				csInfo += ConvertString(csValid, DLG_SUBSCRIBE);
				csInfo += ",";
			}

            // status
            nSize += sizeof(pInfo->nStatus);
            if (nSize <= pInfo->dwSize)
            {
                CString csStatus = AnalogAlarmDataStatusToStr(pInfo->nStatus);
                csInfo += ConvertString(csStatus, DLG_SUBSCRIBE);
                csInfo += ",";
            }

            // value
            nSize += sizeof(pInfo->fValue);
            if (nSize <= pInfo->dwSize)
            {
                CString csValue;
                csValue.Format("%e", pInfo->fValue);
                csInfo += csValue;
                csInfo += ",";
            }

            // collect time
            nSize += sizeof(pInfo->stuCollectTime);
            if (nSize <= pInfo->dwSize)
            {
                const NET_TIME& stuTm = pInfo->stuCollectTime;

                CString csCollectTime;
                csCollectTime.Format("%04d-%02d-%02d %02d:%02d:%02d",
                    stuTm.dwYear, stuTm.dwMonth, stuTm.dwDay,
                    stuTm.dwHour, stuTm.dwMinute, stuTm.dwSecond);
                csInfo += csCollectTime;
            }
		}
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex++, 5, csInfo);
	}
}

void AlarmSubscribe::InsertAlarmClearEvent(ALARM_ALARMCLEAR_INFO* pInfo)
{
    if (pInfo && pInfo->dwSize > 0)
    {
        UpdateEventList();
        char szIndex[32] = {0};
        itoa(m_nAlarmIndex + 1, szIndex, 10);
        m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
        m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);
        
        m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("AlarmClear", DLG_SUBSCRIBE));
        
        int nSize = sizeof(pInfo->dwSize);
        
        // channelID
        nSize += sizeof(pInfo->nChannelID);
        if (nSize <= pInfo->dwSize)
        {
            CString csChannelId;
            // SDK�����û���ͨ���������0��ʼ
            csChannelId.Format("%s %03d", ConvertString("Channel", DLG_SUBSCRIBE), pInfo->nChannelID + 1);
            m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 2, csChannelId);
        }
        
        // time
        nSize += sizeof(pInfo->stuTime);
        if (nSize <= pInfo->dwSize)
        {
            char szAlarmTime[64] = {0};
            GetTimeStringByStruct(pInfo->stuTime, szAlarmTime);
            m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 4, szAlarmTime);
        }
		m_ctrAlarmRptList.SetItemText(m_nAlarmIndex++, 5, NULL);
    }
}

void AlarmSubscribe::InsertCIDEvent(ALARM_CIDEVENT_INFO* pInfo)
{
    if (pInfo && pInfo->dwSize > 0)
    {
        UpdateEventList();
        char szIndex[32] = {0};
        itoa(m_nAlarmIndex + 1, szIndex, 10);
        m_ctrAlarmRptList.InsertItem(m_nAlarmIndex, NULL);
        m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 0, szIndex);
        
        m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 1, ConvertString("CIDEvent", DLG_SUBSCRIBE));
        
        int nSize = sizeof(pInfo->dwSize);
        
        // time
        nSize += sizeof(pInfo->stuTime);
        if (nSize <= pInfo->dwSize)
        {
            char szAlarmTime[64] = {0};
            GetTimeStringByStruct(pInfo->stuTime, szAlarmTime);
            m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 4, szAlarmTime);
        }
        
        // CID
        nSize += sizeof(pInfo->szCID);
        if (nSize <= pInfo->dwSize)
        {
            CString csChannelId;
            // SDK�����û���ͨ���������0��ʼ
            csChannelId.Format("%s %s", ConvertString("CID code", DLG_SUBSCRIBE), pInfo->szCID);
            m_ctrAlarmRptList.SetItemText(m_nAlarmIndex, 5, csChannelId);
        }
    }
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

	GetDlgItem(IDC_BUTTON_SUB)->EnableWindow(FALSE);
	GetDlgItem(IDC_SUB_BTN_STOP)->EnableWindow(TRUE);

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

	GetDlgItem(IDC_BUTTON_SUB)->EnableWindow(TRUE);
	GetDlgItem(IDC_SUB_BTN_STOP)->EnableWindow(FALSE);

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

	BOOL bRet = CLIENT_ControlDevice(m_hLogin, DH_CTRL_CLEAR_ALARM, (void *)&stuInParam, SDK_API_WAIT);
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
