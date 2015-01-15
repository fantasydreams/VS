// SplitInfoDlg.cpp : implementation file
//

#include "StdAfx.h"
#include "NetSDKDemo.h"
#include "SplitInfoDlg.h"
#include "netsdkdemodlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSplitInfoDlg dialog
#define MAX_BPS_TYPE 7


CSplitInfoDlg::CSplitInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSplitInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSplitInfoDlg)
	//}}AFX_DATA_INIT
}


void CSplitInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSplitInfoDlg)
	DDX_Control(pDX, IDC_KBPS_SEL, m_kbpssel);
	DDX_Control(pDX, IDC_BPS_DEVSEL, m_devicesel);
	//}}AFX_DATA_MAP

//	OnRefreshInfo();
	// TODO: Add your specialized code here and/or call the base class
}


BEGIN_MESSAGE_MAP(CSplitInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CSplitInfoDlg)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_SET_DEVICEBPS, OnSetDevicebps)
	ON_CBN_SELCHANGE(IDC_BPS_DEVSEL, OnSelchangeBpsDevsel)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


int UpdateDeviceKbpsCallback(const DeviceNode& node, DWORD dwUser)
{
	CSplitInfoDlg* pThis = (CSplitInfoDlg*)dwUser;
	if (!pThis)
	{
		return 1;
	}

	return pThis->UpdateDeviceKbpsCallback_Imp(node);
}


int CSplitInfoDlg::UpdateDeviceKbpsCallback_Imp(const DeviceNode& node)
{
	DeviceNode& _node = *const_cast<DeviceNode*>(&node);
	_node.TotalKbps = CLIENT_GetStatiscFlux(_node.LoginID, 0);
	if (_node.TotalKbps < 0)
	{
		_node.TotalKbps = 0;
		((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
	}

	return 0;
}

/////////////////////////////////////////////////////////////////////////////
// CSplitInfoDlg message handlers

//ˢ���豸������
void CSplitInfoDlg::UpdateDeviceKbps()
{
	CDevMgr::GetDevMgr().For_EachDev(UpdateDeviceKbpsCallback, (DWORD)this);

	/*
	DeviceNode * pInfo;
	
	POSITION nPos = g_ptrdevicelist->GetHeadPosition();
	for(int i = 0; i < g_ptrdevicelist->GetCount(); i ++ )
	{
		pInfo = (DeviceNode *)g_ptrdevicelist->GetNext(nPos);
		if(pInfo)
		{
			pInfo->TotalKbps = CLIENT_GetStatiscFlux(pInfo->LoginID, 0);
			if (pInfo->TotalKbps < 0)
			{
				pInfo->TotalKbps = 0;
				((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
			}
		}
	}
	*/
}

//ˢ����ʾ��ǰ���������Ϣ
//ֱ�ӵ���sdk����ͳ�ƽӿ� 2006-8-11
void CSplitInfoDlg::OnRefreshInfo() 
{
//	CCSLock lck(g_cs);
	CString str, substr;
	DeviceNode *pDev;
	int nChl;
	DWORD dwTotalKbps, dwChnKbps;
	
	UpdateDeviceKbps();
	int realrate = 0;

	SplitInfoNode siNode;
	memset(&siNode, 0, sizeof(siNode));
	
	CNetSDKDemoDlg *pMain = (CNetSDKDemoDlg *)AfxGetMainWnd();
	for(int i = 0; i < DH_MAX_CHANNUM; i++)
	{
		BOOL ret = pMain->GetSplitInfo_Main(i, &siNode);
		if (!ret)
		{
			MessageBox(ConvertString("error while getting split info"));
		}
		if(siNode.Type == SPLIT_TYPE_NULL)
		{
			str.Format("%s",ConvertString(MSG_SPLITINFO_BLANK));
			GetDlgItem(IDC_SPLIT_INFO1 + i)->SetWindowText(str);
			continue;
		}
		else if(siNode.Type == ConvertString(SPLIT_TYPE_MONITOR))
		{
			SplitMonitorParam *mParam = (SplitMonitorParam *)siNode.Param;
			pDev = mParam->pDevice;
			nChl = mParam->iChannel + 1;
			str.Format("%s          %02d          %s",pDev->Name, nChl,
				ConvertString(MSG_SPLITINFO_MONITOR));
		}
		else if(siNode.Type == ConvertString(SPLIT_TYPE_NETPLAY))
		{
			SplitNetPlayParam *nParam = (SplitNetPlayParam *)siNode.Param; 
			pDev = nParam->pFileInfo->pDevice;
			nChl = nParam->pFileInfo->fileinfo.ch + 1;
			str.Format("%s          %02d          %s",pDev->Name, nChl,
				ConvertString(MSG_SPLITINFO_PLAYBACK));
		}
		else if(siNode.Type == ConvertString(SPLIT_TYPE_PBBYTIME))
		{
			SplitPBByTimeParam *pbParam = (SplitPBByTimeParam *)siNode.Param; 
			pDev = pbParam->pDevice;
			nChl = pbParam->nChannel + 1;
			str.Format("%s          %02d          %s",pDev->Name, nChl,
				ConvertString(MSG_SPLITINFO_PLAYBACK));
		}
		else if(siNode.Type == ConvertString(SPLIT_TYPE_MULTIPLAY))
		{
			pDev = (DeviceNode *)siNode.Param;
			str.Format("%s                      %s",pDev->Name, ConvertString(MSG_SPLITINFO_PREVIEW));
		}
		else if(siNode.Type == SPLIT_TYPE_CYCLEMONITOR)
		{
		//	EnterCriticalSection(&g_csCycle);
			SplitCycleParam *cmParam = (SplitCycleParam *)siNode.Param;
			pDev = cmParam->pDevice;
			POSITION nPos;
			nPos = ((SplitCycleParam *)siNode.Param)->pChannelList->GetHeadPosition();
			CycleChannelInfo *tempnode;
			for (int j = 0; j <= cmParam->iCurPosition; j++)
			{
				tempnode = (CycleChannelInfo *)((SplitCycleParam *)siNode.Param)->pChannelList->GetNext(nPos);
			}
			nChl = tempnode->iChannel + 1;
			str.Format("%s          %02d          %s",pDev->Name, nChl,
				ConvertString(MSG_SPLITINFO_CYCLEMONITOR));
		//	LeaveCriticalSection(&g_csCycle);
		}
		if(siNode.Type != SPLIT_TYPE_NULL)
		{
			dwTotalKbps  = CLIENT_GetStatiscFlux(pDev->LoginID, 0);
			dwChnKbps = CLIENT_GetStatiscFlux(pDev->LoginID, siNode.iHandle);
			if (dwChnKbps < 0) 
			{
				dwChnKbps = 0;
				((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
			}
			realrate += dwChnKbps*8 / 1024;
			substr.Format("   %d     %d ",dwChnKbps * 8 /1024, pDev->TotalKbps * 8 /1024);
			str += substr;
		}
		GetDlgItem(IDC_SPLIT_INFO1 + i)->SetWindowText(str);
	}	
	char temp[10];
	ZeroMemory(temp, 10);
	GetDlgItem(IDC_REAlRATE)->SetWindowText(ltoa(realrate, temp, 10));
}

int InitComboxSICallback(const DeviceNode& node, DWORD dwUser)
{
	CSplitInfoDlg* pThis = (CSplitInfoDlg*)dwUser;
	if(!pThis)
	{
		return 1;
	}

	return pThis->InitComboxCallback_Imp(node);
}

int CSplitInfoDlg::InitComboxCallback_Imp(const DeviceNode& node)
{
	//�豸��ʾ
	CString strDev;	

	strDev.Format(" %s ",node.Name);
	int nIndex = m_devicesel.GetCount();
	m_devicesel.InsertString(nIndex,strDev);
	m_devicesel.SetItemData(nIndex, (DWORD)(&node)); //���ñ��浱ǰ�豸ָ��ֵ

	return 0;
}

BOOL CSplitInfoDlg::OnInitDialog() 
{
	g_SetWndStaticText(this);

	int i;
	//DeviceNode *nDev;
	CString strDev, strBps;

	CDialog::OnInitDialog();
	int TabKbps[MAX_BPS_TYPE] = {65535, 64 ,128, 256, 512, 768, 1024};

	OnRefreshInfo();
	
	CDevMgr::GetDevMgr().For_EachDev(InitComboxSICallback, (DWORD)this);

	/*
	//��ʼ����ѡ����豸
	POSITION nPos = g_ptrdevicelist->GetHeadPosition();
	m_devicesel.Clear();
	for(i = 0; i < g_ptrdevicelist->GetCount(); i ++ )
	{
		//�豸��ʾ��ʽ
		nDev = (DeviceNode *)g_ptrdevicelist->GetNext(nPos);
		
		//�豸��ʾ
		strDev.Format(" %s ",nDev->Name);
		m_devicesel.InsertString(i,strDev);
		m_devicesel.SetItemData(i, (DWORD)nDev); //���ñ��浱ǰ�豸ָ��ֵ
	}
	*/

	for(i = 0; i < MAX_BPS_TYPE; i ++)
	{
		strBps.Format(" %d kbps", TabKbps[i]);
		if(TabKbps[i] == 65535)
		{
			strBps.Format(ConvertString(MSG_SPLITINFO_NOLIMIT));
		}
		m_kbpssel.InsertString(i, strBps);
		m_kbpssel.SetItemData(i, TabKbps[i]);
	}
	SetTimer((UINT)this, 1000,NULL);
	
	return TRUE; 
}

void CSplitInfoDlg::OnTimer(UINT nIDEvent) 
{
	OnRefreshInfo();
	CDialog::OnTimer(nIDEvent);
}

void CSplitInfoDlg::OnSetDevicebps() 
{
	if(m_devicesel.GetCount() <= 0 || m_devicesel.GetCurSel() < 0)
	{
		MessageBox(ConvertString(MSG_SPLITINFO_NODEVICE), ConvertString(MSG_SPLITINFO_CHOOSEDEVICE));
		return;
	}
	
	DeviceNode *nDev = (DeviceNode *)m_devicesel.GetItemData(m_devicesel.GetCurSel());
	int nKbps = m_kbpssel.GetItemData(m_kbpssel.GetCurSel());
	nDev->Max_Kbps = m_kbpssel.GetCurSel();
	BOOL nRet = CLIENT_SetMaxFlux(nDev->LoginID,nKbps);
	if(!nRet)
	{
		((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
		MessageBox(ConvertString(MSG_SPLITINFO_LIMIT_FAILED));
	}
}

//�豸ѡ����������Ӧ
void CSplitInfoDlg::OnSelchangeBpsDevsel() 
{
	if(m_devicesel.GetCount() <= 0 || m_devicesel.GetCurSel() < 0)
	{
		return;
	}
	
	DeviceNode *nDev = (DeviceNode *)m_devicesel.GetItemData(m_devicesel.GetCurSel());
	
	m_kbpssel.SetCurSel(nDev->Max_Kbps);
}

void CSplitInfoDlg::OnClose() 
{
	KillTimer((int)this);
	CDialog::OnClose();
}
