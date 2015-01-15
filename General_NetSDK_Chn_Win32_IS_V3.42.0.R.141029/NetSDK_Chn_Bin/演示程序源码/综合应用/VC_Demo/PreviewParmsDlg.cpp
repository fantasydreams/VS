// PreviewParmsDlg.cpp : implementation file
//

#include "StdAfx.h"
#include "netsdkdemo.h"
#include "PreviewParmsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPreviewParmsDlg dialog


CPreviewParmsDlg::CPreviewParmsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPreviewParmsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPreviewParmsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPreviewParmsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPreviewParmsDlg)
	DDX_Control(pDX, IDC_COMBO_PREVIEWTYPE, m_previewtypesel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPreviewParmsDlg, CDialog)
	//{{AFX_MSG_MAP(CPreviewParmsDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPreviewParmsDlg message handlers

BOOL CPreviewParmsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	g_SetWndStaticText(this);
	
	if (m_previewtypesel.GetCount() > 0)
	{
		m_previewtypesel.SetCurSel(0);
	}
	SetDlgItemInt(IDC_EDIT_STCHANNEL, 1);

	m_iPreviewType = -1;
	m_channelId = 0;
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPreviewParmsDlg::OnOK() 
{
	m_iPreviewType = m_previewtypesel.GetCurSel();
	m_channelId = GetDlgItemInt(IDC_EDIT_STCHANNEL);
	if (m_channelId < 0 || m_channelId > 16)
	{
		m_channelId = 0;
	}

	CDialog::OnOK();
}

void CPreviewParmsDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}
