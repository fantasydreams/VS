// RecordCtrlDlg.cpp : implementation file
//

#include "StdAfx.h"
#include "netsdkdemo.h"
#include "RecordCtrlDlg.h"
#include "NetSDKDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRecordCtrlDlg dialog


CRecordCtrlDlg::CRecordCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRecordCtrlDlg::IDD, pParent)
{
	m_DeviceId = 0;
	memset(m_State, 0, MAX_RECORD_CHANNEL);
	//{{AFX_DATA_INIT(CRecordCtrlDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRecordCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRecordCtrlDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRecordCtrlDlg, CDialog)
	//{{AFX_MSG_MAP(CRecordCtrlDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecordCtrlDlg message handlers
void CRecordCtrlDlg::SetDeviceId(LONG nDeviceId)
{
	m_DeviceId = nDeviceId;
}
void CRecordCtrlDlg::OnOK() 
{
	if(m_DeviceId)
	{
		for(int i = 0; i < m_ChannelNum; i++)
		{
			if(((CButton *)GetDlgItem(IDC_AUTORECORD1 + i))->GetCheck())
			{
				m_State[i] = 2;
			}
			else if(((CButton *)GetDlgItem(IDC_MANIRECORD1 + i))->GetCheck())
			{
				m_State[i] = 1;
				continue;
			}
			else
			{
				m_State[i] = 0;			
			}
		}
		BOOL nRet = CLIENT_SetupRecordState(m_DeviceId, m_State,m_ChannelNum);
		if(!nRet)
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
			MessageBox(ConvertString(MSG_RECORDCTRL_SETUPFAILED));
			return;
		}	
	}

	CDialog::OnOK();
}

BOOL CRecordCtrlDlg::OnInitDialog() 
{

	CDialog::OnInitDialog();
	g_SetWndStaticText(this);

	if(m_DeviceId)
	{
		BOOL nRet = CLIENT_QueryRecordState(m_DeviceId, m_State, MAX_RECORD_CHANNEL, &m_ChannelNum);
		if(!nRet  || !m_ChannelNum)
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
			MessageBox(ConvertString(MSG_RECORDCTRL_QUERYSTATEFAILED));
			((CButton *)GetDlgItem(IDOK))->EnableWindow(FALSE);
			return TRUE;
		}
		else
		{
			for(int i = 0; i < m_ChannelNum; i++)
			{
				switch(m_State[i]) {
				case 2:
					((CButton *)GetDlgItem(IDC_AUTORECORD1 + i))->SetCheck(1);
					break;
				case 1:
					((CButton *)GetDlgItem(IDC_MANIRECORD1 + i))->SetCheck(1);
					break;
				default:
					((CButton *)GetDlgItem(IDC_NORECORD1 + i))->SetCheck(1);
					break;
				}
			}
			for(int j = m_ChannelNum; j < MAX_RECORD_CHANNEL; j ++)
			{
				((CButton *)GetDlgItem(IDC_NORECORD1 + j))->EnableWindow(0);
				((CButton *)GetDlgItem(IDC_AUTORECORD1 + j))->EnableWindow(0);
				((CButton *)GetDlgItem(IDC_MANIRECORD1 + j))->EnableWindow(0);

			}

		}

	}
	return TRUE; 
}
