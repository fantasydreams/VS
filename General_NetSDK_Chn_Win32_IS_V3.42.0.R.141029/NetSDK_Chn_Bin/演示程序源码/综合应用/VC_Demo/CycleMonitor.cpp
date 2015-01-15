// CycleMonitor.cpp : implementation file
//

#include "StdAfx.h"
#include "netsdkdemo.h"
#include "CycleMonitor.h"
#include "CycleChild.h"
#include "netsdkdemodlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCycleMonitor dialog

CCycleMonitor::CCycleMonitor(CWnd* pParent /*=NULL*/)
	: CDialog(CCycleMonitor::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCycleMonitor)
	//}}AFX_DATA_INIT
}


void CCycleMonitor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCycleMonitor)
	DDX_Control(pDX, IDC_ALLCHANNEL_LIST, m_channellist);
	DDX_Control(pDX, IDC_SCREEN_TAB, m_ScreenTabControl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCycleMonitor, CDialog)
	//{{AFX_MSG_MAP(CCycleMonitor)
	ON_NOTIFY(TCN_SELCHANGE, IDC_SCREEN_TAB, OnSelchangeScreenTab)
	ON_BN_CLICKED(IDC_ADD1, OnAdd1)
	ON_BN_CLICKED(IDC_ADDALL, OnAddall)
	ON_BN_CLICKED(IDC_DELETE1, OnDelete1)
	ON_BN_CLICKED(IDC_DELETEALL, OnDeleteall)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCycleMonitor message handlers

void CCycleMonitor::OnOK() 
{
	BOOL  bSuccess = TRUE;
	for (int i = 0; i < CUR_MAXCHAN; i++)
	{
		m_cyclechild[i].OnOK();
		if (m_cyclechild[i].bHaveBadValue)
		{
			bSuccess = FALSE;
		}
	}

	if (!bSuccess)
	{
		return;
	}
	else
	{
		//����Ӵ����ڴ�
		for (int i = 0; i < CUR_MAXCHAN; i++)
		{
			m_cyclechild[i].DoCycle();
		}
	}
	//����ڴ�й¶
	for (int j = 0; j < m_curRow; j++)
	{
		if (m_channellist.GetItemText(j, 1) != "") 
		{
			delete (CycleChannelInfo *)m_channellist.GetItemData(j);
		}
	}

	CDialog::OnOK();
}

//init cyclemonitor config left tree
int InitLeftTreeCallBack(const DeviceNode& node, DWORD dwUser)
{
	CCycleMonitor* pThis = (CCycleMonitor*)dwUser;
	if (!pThis)
	{
		return 1; //end callback
	}

	return pThis->InitLeftTreeCallBack_Imp(node);
}

int CCycleMonitor::InitLeftTreeCallBack_Imp(const DeviceNode& node)
{
	CString strDev, strCh;

	strDev.Format(" %s (%s):",node.Name, node.IP);
	m_channellist.InsertItem(m_curRow, strDev);
	m_channellist.SetItemText(m_curRow, 1, "");
	m_channellist.SetItemData(m_curRow,(DWORD)(&node));
	m_curRow++;	

	CNetSDKDemoDlg *pMain = (CNetSDKDemoDlg *)AfxGetMainWnd();
	if (!pMain)
	{
		return 1;
	}

	SplitInfoNode siNode;
	memset(&siNode, 0, sizeof(SplitInfoNode));
	//ͨ����ʾ
	int nTotalChnNum = __max(node.nChnNum, node.Info.byChanNum);
	for(int chlCounter = 0; chlCounter < nTotalChnNum; chlCounter++)
	{
		//ֻ��ʾδ��������ѭ�б���δ�����ӵ�ͨ����
		BOOL found = FALSE;
		//��ÿ����ѭ���洰�ڵĲ����в�ѯ
		for (int x = 0; x < CUR_MAXCHAN; x++)
		{
			pMain->GetSplitInfo_Main(x, &siNode);
			if (siNode.Type == SPLIT_TYPE_CYCLEMONITOR) 
			{
				POSITION pos;
				pos = ((SplitCycleParam *)siNode.Param)->pChannelList->GetHeadPosition();
				for (int y = 0; y < ((SplitCycleParam *)siNode.Param)->iChannelCount; y++ )
				{
					CycleChannelInfo *tempnode;
					tempnode = (CycleChannelInfo *)((SplitCycleParam *)siNode.Param)->pChannelList->GetNext(pos);
					if ((tempnode->dwDeviceID == (DWORD)(&node)) 
						&& (tempnode->iChannel == chlCounter))
					{
						found = TRUE;
						break;
					}
				}
				if (found) 
				{
					break;
				}
			}//if (siNode.Type == SPLIT_TYPE_CYCLEMONITOR) 
			if (siNode.Type == SPLIT_TYPE_MONITOR) 
			{
				if (((SplitMonitorParam *)siNode.Param)->pDevice->LoginID == node.LoginID
					 && ((SplitMonitorParam *)siNode.Param)->iChannel == chlCounter)
				{
					found = TRUE;
					break;
				}
			}
		}//for (int x = 0; x < CUR_MAXCHAN; x++)
		if (found) 
		{
			continue;
		}
		strCh.Format("chl %02d", chlCounter+1);
		m_channellist.InsertItem(m_curRow,strDev);
		m_channellist.SetItemText(m_curRow, 1, strCh);
		CycleChannelInfo *tempInfo = new(CycleChannelInfo);
		tempInfo->dwDeviceID = (DWORD)(&node);
		tempInfo->iChannel = chlCounter;
		m_channellist.SetItemData(m_curRow, (DWORD)tempInfo);
		m_curRow++;
	}//end of for(int chlCounter = 0; chlCounter < nDev->Info.byChanNum; chlCounter++)
	
	return 0;
}

BOOL CCycleMonitor::OnInitDialog() 
{
	CDialog::OnInitDialog();
	g_SetWndStaticText(this);

	//ȷ������ҳ�Ӵ��ڵ�λ��
	CRect rect;
	m_ScreenTabControl.GetClientRect(rect);
	rect.top += 30;
	rect.bottom -= 4;
	rect.left += 4;
	rect.right -= 4;

	for (int i = 0; i < CUR_MAXCHAN; i++)
	{
		//��ʼ������ҳ���Ӵ���
		CString childtitle;
		childtitle.Format(" %d",i + 1);
		childtitle = ConvertString(NAME_SCRN) + childtitle;
		
		m_ScreenTabControl.InsertItem(i,childtitle);
		m_cyclechild[i].SetScreenNo(i);
		m_cyclechild[i].Create(IDD_CYCLE_CHILD, GetDlgItem(IDC_SCREEN_TAB));
		m_cyclechild[i].MoveWindow(rect);
	 	m_cyclechild[i].ShowWindow(SW_HIDE);
	}
	
	m_cyclechild[0].ShowWindow(SW_NORMAL);
	m_ScreenTabControl.SetCurSel(0);
	m_curChild = 0;
	m_curRow = 0;
	
	//��ʼ���豸��ͨ���б�
	m_channellist.SetExtendedStyle(m_channellist.GetExtendedStyle()|LVS_EX_FULLROWSELECT);
	m_channellist.InsertColumn(0, ConvertString(NAME_DEVICE), LVCFMT_LEFT, 120, 0);
	m_channellist.InsertColumn(1, ConvertString(NAME_CHANNEL), LVCFMT_LEFT, 70, 1);
	
	CDevMgr::GetDevMgr().For_EachDev(InitLeftTreeCallBack, (DWORD)this);
	return TRUE; 
}


void CCycleMonitor::OnSelchangeScreenTab(NMHDR* pNMHDR, LRESULT* pResult) 
{
	int nCurSel = m_ScreenTabControl.GetCurSel();
	if (nCurSel != m_curChild)
	{
		m_cyclechild[nCurSel].ShowWindow(SW_SHOW);
		m_cyclechild[m_curChild].ShowWindow(SW_HIDE);
		m_curChild = nCurSel;
	}
	
	*pResult = 0;
}


void CCycleMonitor::OnAdd1() 
{
	int rightindex;
	int leftindex = m_channellist.GetSelectionMark();
	if (leftindex == -1) 
	{
		return;
	}

	//����ȡ������item data��һ����Device�ڵ㣬�ж�ʱ����ȡ���Ա������������
	DWORD itemData = m_channellist.GetItemData(leftindex);

	BOOL bRet = CDevMgr::GetDevMgr().IsOnline((DeviceNode *)itemData);
	if (!bRet)
	{
		rightindex = m_cyclechild[m_curChild].GetCurRow();
		AddItem(leftindex, rightindex);
	}
	else
	{
		//�������豸�ı����ӵ��ұ���ѭ�б�
		int addindex = 0;
		int dotimes = m_curRow;
		for (int i = 0; i < dotimes; i++)
		{
			if (CDevMgr::GetDevMgr().IsOnline((DeviceNode *)m_channellist.GetItemData(addindex))) 
			{
				addindex ++;
				continue;
			}

			CycleChannelInfo *tempnode = (CycleChannelInfo *)m_channellist.GetItemData(addindex);
			if (tempnode->dwDeviceID != itemData)
			{
				addindex ++;
				continue;
			}

			if (tempnode->dwDeviceID == itemData)
			{
				rightindex = m_cyclechild[m_curChild].GetCurRow();
				AddItem(addindex, rightindex);					
			}
		}
		return;
	}



	/*
	POSITION nPos;	
	nPos = g_ptrdevicelist->GetHeadPosition();
	for(int devCounter = 0; devCounter < g_ptrdevicelist->GetCount(); devCounter ++ )
	{
		//�Ƿ�ѡ�������豸
		nDev = (DeviceNode *)g_ptrdevicelist->GetNext(nPos);
		if (m_channellist.GetItemData(leftindex) == (DWORD)nDev)
		{
			//�������豸�ı����ӵ��ұ���ѭ�б�
			int addindex = 0;
			int dotimes = m_curRow;
			for (int i = 0; i < dotimes; i++)
			{
				if (m_channellist.GetItemText(addindex, 1) == "") 
				{
					addindex ++;
					continue;
				}
				
				CycleChannelInfo *tempnode = (CycleChannelInfo *)m_channellist.GetItemData(addindex);
				if (tempnode->dwDeviceID != (DWORD)nDev)
				{
					addindex ++;
					continue;
				}

				if (tempnode->dwDeviceID == (DWORD)nDev)
				{
					rightindex = m_cyclechild[m_curChild].GetCurRow();
					AddItem(addindex, rightindex);					
				}
			}
		return;
		}
		
	}
	*/

}

void CCycleMonitor::OnAddall() 
{
	int leftindex = 0;
	int rightindex;

	int dotimes = m_curRow;
	DWORD itemData;
	
	for (int i = 0; i < dotimes; i++)
	{
		itemData = m_channellist.GetItemData(leftindex);
		if (CDevMgr::GetDevMgr().IsOnline((DeviceNode *)itemData))
		{
			leftindex++;
			continue;
		}
		
		rightindex = m_cyclechild[m_curChild].GetCurRow();
		AddItem(leftindex, rightindex);
	}
}

void CCycleMonitor::OnDelete1() 
{
	DeleteItem(m_cyclechild[m_curChild].GetSelectionMark());
}

void CCycleMonitor::OnDeleteall() 
{
	int dotimes = m_cyclechild[m_curChild].GetCurRow();
	for (int i = 0; i < dotimes; i++)
	{
		DeleteItem(0);
	}
}

void CCycleMonitor::DeleteItem(int rightindex)
{
	if (rightindex != -1) 
	{	
		//������ȷ�Ĳ���λ��
		DWORD dwDev = ((CycleChannelInfo *)m_cyclechild[m_curChild].GetItemData(rightindex))->dwDeviceID;
		int iChl = ((CycleChannelInfo *)m_cyclechild[m_curChild].GetItemData(rightindex))->iChannel;
		int leftindex = m_curRow;//��ʼ��Ϊ���һ��λ��
		for (int i = 0; i < m_curRow; i++)
		{
			if (m_channellist.GetItemData(i) == dwDev) 
			{
				leftindex = i + 1;
			}
			else if (!CDevMgr::GetDevMgr().IsOnline(m_channellist.GetItemData(i)) &&
				((CycleChannelInfo *)m_channellist.GetItemData(i))->dwDeviceID == dwDev) 
			{
				if (((CycleChannelInfo *)m_channellist.GetItemData(i))->iChannel < iChl) 
				{
					leftindex = i + 1;
				}
			}
		}
		
		m_channellist.InsertItem(leftindex, m_cyclechild[m_curChild].GetItemText(rightindex, 0));
		m_channellist.SetItemText(leftindex, 1, m_cyclechild[m_curChild].GetItemText(rightindex, 1));
		m_channellist.SetItemData(leftindex, m_cyclechild[m_curChild].GetItemData(rightindex));
		m_cyclechild[m_curChild].DeleteItem(rightindex);
		m_curRow++;
		leftindex = m_curRow;
	}
}

void CCycleMonitor::AddItem(int lindex, int rindex)
{
	m_cyclechild[m_curChild].InsertItem(rindex, m_channellist.GetItemText(lindex, 0));
	m_cyclechild[m_curChild].SetItemText(rindex, 1, m_channellist.GetItemText(lindex, 1));
	m_cyclechild[m_curChild].SetItemData(rindex, m_channellist.GetItemData(lindex));
	m_channellist.DeleteItem(lindex);
	m_curRow--;
	m_channellist.SetFocus();
}

void CCycleMonitor::OnCancel() 
{
	for (int i = 0; i < CUR_MAXCHAN; i++)
	{
		m_cyclechild[i].OnCancel();
	}
	//����ڴ�й¶
	for (int j = 0; j < m_curRow; j++)
	{
		if (m_channellist.GetItemText(j, 1) != "") 
		{
			delete (CycleChannelInfo *)m_channellist.GetItemData(j);
		}
	}
	CDialog::OnCancel();
}

void CCycleMonitor::OnClose() 
{
	OnCancel();
}

