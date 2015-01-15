// DlgCfgAccessControlGeneral.cpp : implementation file
//

#include "stdafx.h"
#include "AccessControl.h"
#include "DlgCfgAccessControlGeneral.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCfgAccessControlGeneral dialog


CDlgCfgAccessControlGeneral::CDlgCfgAccessControlGeneral(CWnd* pParent /* = NULL */, LLONG lLoginID /* = 0 */)
	: CDialog(CDlgCfgAccessControlGeneral::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCfgAccessControlGeneral)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_lLoginID = lLoginID;
	memset(&m_stuInfo, 0, sizeof(m_stuInfo));
}


void CDlgCfgAccessControlGeneral::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCfgAccessControlGeneral)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCfgAccessControlGeneral, CDialog)
	//{{AFX_MSG_MAP(CDlgCfgAccessControlGeneral)
	ON_BN_CLICKED(IDC_ACCESSCONTROL_GENERAL_BTN_GET, OnAccesscontrolGeneralBtnGet)
	ON_BN_CLICKED(IDC_ACCESSCONTROL_GENERAL_BTN_SET, OnAccesscontrolGeneralBtnSet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCfgAccessControlGeneral private method

BOOL CDlgCfgAccessControlGeneral::SetConfigToDevice()
{	
	char szJsonBuf[1024 * 40] = {0};
	BOOL bRet = CLIENT_PacketData(CFG_CMD_ACCESS_GENERAL, &m_stuInfo, sizeof(m_stuInfo), szJsonBuf, sizeof(szJsonBuf));
	if (!bRet)
	{
		MessageBox(ConvertString(CString("packet AccessControlGeneral error..."), DLG_CFG_ACCESS_GENERAL), ConvertString("Prompt"));
		return FALSE;
	} 
	else
	{		
		int nerror = 0;
		int nrestart = 0;
		
		bRet = CLIENT_SetNewDevConfig((LLONG)m_lLoginID, CFG_CMD_ACCESS_GENERAL, -1, szJsonBuf, 1024*40, &nerror, &nrestart, 5000);
		if (!bRet)
		{
			CString csErr;
			csErr.Format("%s %08x...", ConvertString("SetupConfig AccessControlGeneral failed:", DLG_CFG_ACCESS_GENERAL), CLIENT_GetLastError());
			MessageBox(csErr, ConvertString("Prompt"));
			return FALSE;
		}
		else
		{
			MessageBox(ConvertString(CString("SetConfig AccessControlGeneral ok!"), DLG_CFG_ACCESS_GENERAL), ConvertString("Prompt"));
		}
	}
	return TRUE;
}

BOOL CDlgCfgAccessControlGeneral::GetConfigFromDevice()
{
	char szJsonBuf[1024 * 40] = {0};
	int nerror = 0;
	BOOL bRet = CLIENT_GetNewDevConfig((LLONG)m_lLoginID, CFG_CMD_ACCESS_GENERAL, -1, szJsonBuf, 1024*40, &nerror, 5000);
	
	if (bRet)
	{
		DWORD dwRetLen = 0;
		bRet = CLIENT_ParseData(CFG_CMD_ACCESS_GENERAL, szJsonBuf, (void*)&m_stuInfo, sizeof(m_stuInfo), &dwRetLen);
		if (!bRet)
		{
			MessageBox(ConvertString(CString("parse AccessControlGeneral error..."), DLG_CFG_ACCESS_GENERAL), ConvertString("Prompt"));
			return FALSE;
		}
	}
	else
	{			
		CString csErr;
		csErr.Format("%s %08x...\r\n\r\n%s", ConvertString("QueryConfig AccessControlGeneral error:", DLG_CFG_ACCESS_GENERAL),
			CLIENT_GetLastError(), szJsonBuf);
		MessageBox(csErr, ConvertString("Prompt"));
		return FALSE;
	}
	return TRUE;
}

void CDlgCfgAccessControlGeneral::DlgToStu()
{
	m_stuInfo.abProjectPassword = true;
	GetDlgItemText(IDC_ACCESSCONTROL_GENERAL_EDT_PROJECTPWD, m_stuInfo.szProjectPassword, sizeof(m_stuInfo.szProjectPassword) - 1);
}

void CDlgCfgAccessControlGeneral::StuToDlg()
{
	SetDlgItemText(IDC_ACCESSCONTROL_GENERAL_EDT_PROJECTPWD, m_stuInfo.szProjectPassword);
}

/////////////////////////////////////////////////////////////////////////////
// CDlgCfgAccessControlGeneral message handlers

void CDlgCfgAccessControlGeneral::OnAccesscontrolGeneralBtnGet() 
{
	// TODO: Add your control notification handler code here
	if (GetConfigFromDevice())
	{
		StuToDlg();
	}
}

void CDlgCfgAccessControlGeneral::OnAccesscontrolGeneralBtnSet() 
{
	// TODO: Add your control notification handler code here
	DlgToStu();
	SetConfigToDevice();
}

BOOL CDlgCfgAccessControlGeneral::OnInitDialog() 
{
	CDialog::OnInitDialog();
	g_SetWndStaticText(this, DLG_CFG_ACCESS_GENERAL);
	// TODO: Add extra initialization here
	OnAccesscontrolGeneralBtnGet();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
