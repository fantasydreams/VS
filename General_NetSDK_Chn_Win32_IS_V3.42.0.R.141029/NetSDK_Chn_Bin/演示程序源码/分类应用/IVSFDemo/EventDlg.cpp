// EventDlg.cpp : implementation file
//

#include "stdafx.h"
#include "IVSFDemo.h"
#include "EventDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEventDlg dialog


CEventDlg::CEventDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEventDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEventDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEventDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEventDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEventDlg, CDialog)
	//{{AFX_MSG_MAP(CEventDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEventDlg message handlers
