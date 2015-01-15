// RealPlayXPpg.cpp : Implementation of the CRealPlayXPropPage property page class.

#include "stdafx.h"
#include "RealPlayX.h"
#include "RealPlayXPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CRealPlayXPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CRealPlayXPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CRealPlayXPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CRealPlayXPropPage, "REALPLAYX.RealPlayXPropPage.1",
	0x2cd67db, 0x14ce, 0x4b1a, 0xb5, 0x71, 0x2b, 0x7c, 0xbe, 0x69, 0xd, 0x6)


/////////////////////////////////////////////////////////////////////////////
// CRealPlayXPropPage::CRealPlayXPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CRealPlayXPropPage

BOOL CRealPlayXPropPage::CRealPlayXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_REALPLAYX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CRealPlayXPropPage::CRealPlayXPropPage - Constructor

CRealPlayXPropPage::CRealPlayXPropPage() :
	COlePropertyPage(IDD, IDS_REALPLAYX_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CRealPlayXPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CRealPlayXPropPage::DoDataExchange - Moves data between page and properties

void CRealPlayXPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CRealPlayXPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CRealPlayXPropPage message handlers
