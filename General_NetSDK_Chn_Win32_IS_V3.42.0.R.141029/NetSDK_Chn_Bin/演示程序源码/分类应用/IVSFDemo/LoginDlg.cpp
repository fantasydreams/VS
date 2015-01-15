// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "IVSFDemo.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog


CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	EnableAutomation();

	//{{AFX_DATA_INIT(CLoginDlg)
// 	m_strIP = _T("10.45.1.117");
	m_strIP = _T("10.45.0.139");
	m_strPassWord = _T("admin");
	m_nPort = 37777;
	m_strUserName = _T("admin");
	//}}AFX_DATA_INIT

	memset(&m_stDevInfo, 0, sizeof(m_stDevInfo));
	m_lLogHandle = 0;
}


void CLoginDlg::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Text(pDX, IDC_EDIT_IP, m_strIP);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_strPassWord);
	DDX_Text(pDX, IDC_EDIT_PORT, m_nPort);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_strUserName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, OnButtonLogin)
	ON_BN_CLICKED(IDC_BUTTON_LOGOUT, OnButtonLogout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CLoginDlg, CDialog)
	//{{AFX_DISPATCH_MAP(CLoginDlg)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_ILoginDlg to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {C68F53CF-3336-4D78-9124-D9B737924B1E}
static const IID IID_ILoginDlg =
{ 0xc68f53cf, 0x3336, 0x4d78, { 0x91, 0x24, 0xd9, 0xb7, 0x37, 0x92, 0x4b, 0x1e } };

BEGIN_INTERFACE_MAP(CLoginDlg, CDialog)
	INTERFACE_PART(CLoginDlg, IID_ILoginDlg, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

BOOL CLoginDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	g_SetWndStaticText(this);

	return TRUE; 
}

void CLoginDlg::OnButtonLogin() 
{
	UpdateData(TRUE);

	int nErr = 0;	//Storage the possible error return value.
	WORD wDVRPort = (WORD)m_nPort;
	char *pDevIP = (LPSTR)(LPCSTR)m_strIP;
	char *pchUserName = (LPSTR)(LPCSTR)m_strUserName;
	char *pchPassword = (LPSTR)(LPCSTR)m_strPassWord;
	
	//Call log in interface 
	long lRet = CLIENT_Login(pDevIP,wDVRPort,pchUserName,pchPassword,&m_stDevInfo,&nErr);
	if(0 != lRet)
	{
		m_lLogHandle = lRet;
	}
	else
	{
		GetConnectError(nErr);
	}

	CDialog::OnOK();
}

//����ʧ�ܵ�����
void CLoginDlg::GetConnectError(int error)
{
	//���ݷ���ֵ��ͬ�жϴ�������
	switch(error) {
	case 1://���벻��ȷ
		MessageBox(ConvertString(MSG_ERROR_PASSWORD), ConvertString("Prompt"));
		break;
	case 2://�û���������
		MessageBox(ConvertString(MSG_ERROR_USER), ConvertString("Prompt"));
		break;
	case 3://��¼��ʱ
		MessageBox(ConvertString(MSG_ERROR_TIMEOUT), ConvertString("Prompt"));
		break;
	case 4://�ظ���¼
		MessageBox(ConvertString(MSG_ERROR_RELOGGIN), ConvertString("Prompt"));
		break;
	case 5://�ʺű�����
		MessageBox(ConvertString(MSG_ERROR_LOCKED), ConvertString("Prompt"));
		break;
	case 6://�ʺű����������
		MessageBox(ConvertString(MSG_ERROR_BLACKLIST), ConvertString("Prompt"));
		break;
	case 7://ϵͳæ����Դ����
		MessageBox(ConvertString(MSG_ERROR_BUSY), ConvertString("Prompt"));
		break;
	case 8://������ʧ��
		MessageBox(ConvertString(MSG_ERROR_CONNECT), ConvertString("Prompt"));
		break;
	case 9://�Ҳ�������
		MessageBox(ConvertString(MSG_ERROR_CONNECT), ConvertString("Prompt"));
		break;
	case 10://�������������
		MessageBox(ConvertString(MSG_ERROR_OVER_MAX_CONNECT), ConvertString("Prompt"));
		break;
	case 0:
	default:
		MessageBox(ConvertString(MSG_ERROR_NETWORK), ConvertString("Prompt"));
		break;
	}
}

void CLoginDlg::OnButtonLogout() 
{
	// TODO: Add your control notification handler code here

	CDialog::OnCancel();
}
