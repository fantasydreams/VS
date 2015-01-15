// DlgSetArmMode.cpp : implementation file
//

#include "stdafx.h"
#include "AlarmDevice.h"
#include "DlgSetArmMode.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSetArmMode dialog


CDlgSetArmMode::CDlgSetArmMode(CWnd* pParent /*=NULL*/, LLONG lLoginId /*=0*/)
	: CDialog(CDlgSetArmMode::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSetArmMode)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_lLoginId = lLoginId;
}


void CDlgSetArmMode::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSetArmMode)
	DDX_Control(pDX, IDC_SETARMMODE_COMBO_SCENE, m_cmbScene);
	DDX_Control(pDX, IDC_SETARMMODE_COMBO_MODE, m_cmbMode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSetArmMode, CDialog)
	//{{AFX_MSG_MAP(CDlgSetArmMode)
	ON_BN_CLICKED(IDC_SETARMMODE_BTN_SET, OnSetarmmodeBtnSet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSetArmMode message handlers

BOOL CDlgSetArmMode::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	g_SetWndStaticText(this, DLG_SETAMRMODE);
	
	if (m_lLoginId == 0)
	{
		MessageBox(ConvertString(CString("we haven't login a device yet!"), DLG_SETAMRMODE), ConvertString("Prompt"));
		return TRUE;
	}
	
	m_cmbMode.ResetContent();
	m_cmbMode.InsertString(-1, ConvertString("Unknown", DLG_SETAMRMODE));
	m_cmbMode.InsertString(-1, ConvertString("Disarming", DLG_SETAMRMODE));
	m_cmbMode.InsertString(-1, ConvertString("Arming", DLG_SETAMRMODE));
	m_cmbMode.SetCurSel(0);

	m_cmbScene.ResetContent();
	m_cmbScene.InsertString(-1, ConvertString("Unknown", DLG_SETAMRMODE));
	m_cmbScene.InsertString(-1, ConvertString("Outdoor", DLG_SETAMRMODE));
	m_cmbScene.InsertString(-1, ConvertString("Indoor", DLG_SETAMRMODE));
	m_cmbScene.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
void CDlgSetArmMode::OnSetarmmodeBtnSet() 
{
	// TODO: Add your control notification handler code here
	if (m_lLoginId == 0)
	{
		MessageBox(ConvertString(CString("we haven't login a device yet!"), DLG_SETAMRMODE), ConvertString("Prompt"));
		return;
	}

	CString csPsw;
	GetDlgItemText(IDC_SETARMMODE_EDT_PASSWORD, csPsw);
	
	CTRL_ARM_DISARM_PARAM stuParam = {0};
	
	stuParam.bState = m_cmbMode.GetCurSel() - 1;
	stuParam.emSceneMode = (NET_SCENE_MODE)m_cmbScene.GetCurSel();	
	stuParam.szDevPwd = csPsw.GetBuffer(0);
	BOOL bRet = CLIENT_ControlDevice(m_lLoginId, DH_CTRL_ARMED, &stuParam, SDK_API_WAIT);
	if (!bRet)
	{
		CString csOut;
		csOut.Format("%s %08x...", ConvertString("Set Arm Mode failed:", DLG_SETAMRMODE), CLIENT_GetLastError());
		MessageBox(csOut, ConvertString("Prompt"));
		return;
	}
	MessageBox(ConvertString("Set Arm Mode successfully.", DLG_SETAMRMODE), ConvertString("Prompt"));
}


