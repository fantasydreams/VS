// RealPlayXCtl.cpp : Implementation of the CRealPlayXCtrl ActiveX Control class.

#include "stdafx.h"
#include "RealPlayX.h"
#include "RealPlayXCtl.h"
#include "RealPlayXPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CRealPlayXCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CRealPlayXCtrl, COleControl)
	//{{AFX_MSG_MAP(CRealPlayXCtrl)
	ON_WM_DESTROY()
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CRealPlayXCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CRealPlayXCtrl)
	DISP_FUNCTION(CRealPlayXCtrl, "SetDeviceInfo", SetDeviceInfo, VT_BOOL, VTS_BSTR VTS_I4 VTS_I2 VTS_BSTR VTS_BSTR)
	DISP_FUNCTION(CRealPlayXCtrl, "StartPlay", StartPlay, VT_BOOL, VTS_NONE)
	DISP_FUNCTION(CRealPlayXCtrl, "StopPlay", StopPlay, VT_BOOL, VTS_NONE)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CRealPlayXCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CRealPlayXCtrl, COleControl)
	//{{AFX_EVENT_MAP(CRealPlayXCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CRealPlayXCtrl, 1)
	PROPPAGEID(CRealPlayXPropPage::guid)
END_PROPPAGEIDS(CRealPlayXCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CRealPlayXCtrl, "REALPLAYX.RealPlayXCtrl.1",
	0x30209fbc, 0x57eb, 0x4f87, 0xbf, 0x3e, 0x74, 0xe, 0x3d, 0x80, 0x19, 0xd2)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CRealPlayXCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DRealPlayX =
		{ 0x59dce921, 0x4ce3, 0x4791, { 0xb9, 0xe5, 0xde, 0x1c, 0xfc, 0xe8, 0xa7, 0x1c } };
const IID BASED_CODE IID_DRealPlayXEvents =
		{ 0x97ea9bd2, 0x418f, 0x49a4, { 0x9a, 0xdd, 0x7f, 0xed, 0x27, 0xbf, 0xd0, 0xed } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwRealPlayXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CRealPlayXCtrl, IDS_REALPLAYX, _dwRealPlayXOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CRealPlayXCtrl::CRealPlayXCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CRealPlayXCtrl

BOOL CRealPlayXCtrl::CRealPlayXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_REALPLAYX,
			IDB_REALPLAYX,
			afxRegApartmentThreading,
			_dwRealPlayXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CRealPlayXCtrl::CRealPlayXCtrl - Constructor

CRealPlayXCtrl::CRealPlayXCtrl()
{
	InitializeIIDs(&IID_DRealPlayX, &IID_DRealPlayXEvents);

	// TODO: Initialize your control's instance data here.
	m_LoginID = 0;
	m_strDvrIP = "";
	m_nChannel = -1;
	m_hRealPlay = 0;
}


/////////////////////////////////////////////////////////////////////////////
// CRealPlayXCtrl::~CRealPlayXCtrl - Destructor

CRealPlayXCtrl::~CRealPlayXCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CRealPlayXCtrl::OnDraw - Drawing function

void CRealPlayXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	//pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	//pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CRealPlayXCtrl::DoPropExchange - Persistence support

void CRealPlayXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CRealPlayXCtrl::OnResetState - Reset control to default state

void CRealPlayXCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CRealPlayXCtrl::AboutBox - Display an "About" box to the user

void CRealPlayXCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_REALPLAYX);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CRealPlayXCtrl message handlers

//	Connect device
BOOL CRealPlayXCtrl::SetDeviceInfo(LPCTSTR strDvrIP, long nPort, short nChannel, LPCTSTR strUserId, LPCTSTR strUserPwd) 
{
	// TODO: Add your dispatch handler code here
	BOOL bSuccess = FALSE;

	//	Different device, re-login
	if(strDvrIP != m_strDvrIP)
	{
		if(0 != m_LoginID)
		{
			CLIENT_Logout(m_LoginID);
			m_LoginID = 0;
			m_strDvrIP = "";

			Invalidate();
		}

		int err = 0;
		NET_DEVICEINFO deviceInfo;

		long lRet = CLIENT_Login((LPSTR)strDvrIP,(WORD)nPort,(LPSTR)strUserId,(LPSTR)strUserPwd,&deviceInfo,&err);
		if(0 != lRet)
		{
			m_LoginID = lRet;
			m_nChannel = nChannel;
			m_strDvrIP = strDvrIP;
			bSuccess = TRUE;
		}
		else
		{
			m_LoginID = 0;
			m_nChannel = -1;
			bSuccess = FALSE;
			ShowLoginErrorReason(err);
		}
	}
	else
	{
		//	The same device, no login, then re-login
		if(0 == m_LoginID)
		{
			int err = 0;
			NET_DEVICEINFO deviceInfo;

			long lRet = CLIENT_Login((LPSTR)strDvrIP,(WORD)nPort,(LPSTR)strUserId,(LPSTR)strUserPwd,&deviceInfo,&err);
			if(0 != lRet)
			{
				m_LoginID = lRet;
				m_nChannel = nChannel;
				bSuccess = TRUE;
			}
			else
			{
				m_LoginID = 0;
				m_nChannel = -1;
				bSuccess = FALSE;
				ShowLoginErrorReason(err);
			}
		}
		else
		{
			m_nChannel = nChannel;
			bSuccess = TRUE;
		}
	}

	return bSuccess;
}

//	Start Play
BOOL CRealPlayXCtrl::StartPlay() 
{
	// TODO: Add your dispatch handler code here
	BOOL bSuccess = FALSE;

	if(0 != m_LoginID)
	{
		if(0 != m_hRealPlay)
		{
			BOOL bRet = CLIENT_StopRealPlay(m_hRealPlay);

			Invalidate();
		}

		long lRet = CLIENT_RealPlay(m_LoginID,m_nChannel,m_hWnd);
		if(0 != lRet)
		{
			m_hRealPlay = lRet;
			bSuccess = TRUE;
		}
		else
		{
			m_hRealPlay = 0;
			bSuccess = FALSE;
		}
	}

	return bSuccess;
}

//	Stop Play
BOOL CRealPlayXCtrl::StopPlay() 
{
	// TODO: Add your dispatch handler code here
	BOOL bSuccess = TRUE;

	if(0 != m_hRealPlay)
	{
		BOOL bRet = CLIENT_StopRealPlay(m_hRealPlay);
		m_hRealPlay = 0;

		Invalidate();
	}

	return bSuccess;
}

void CRealPlayXCtrl::OnDestroy() 
{
	COleControl::OnDestroy();
	
	// TODO: Add your message handler code here
	if(0 != m_LoginID)
	{
		CLIENT_Logout(m_LoginID);
	}

	CLIENT_Cleanup();
}

int CRealPlayXCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	BOOL ret = CLIENT_Init(DisConnectFunc, (DWORD)this);
	if (!ret)
	{
		//Initialization failure

	}
	return 0;
}

void CALLBACK DisConnectFunc(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser)
{
	if(dwUser == 0)
	{
		return;
	}
	CRealPlayXCtrl *pCtl = (CRealPlayXCtrl *)dwUser;
	pCtl->DeviceDisConnect(lLoginID, pchDVRIP,nDVRPort);
}

void CRealPlayXCtrl::DeviceDisConnect(LONG lLoginID, char *sDVRIP, LONG nDVRPort)
{
	//Connection interrupted

}

void CRealPlayXCtrl::ShowLoginErrorReason(int nError)
{
	if(1 == nError)		MessageBox("Invalid password!","Prompt");
	else if(2 == nError)	MessageBox("Invalid account!","Prompt");
	else if(3 == nError)	MessageBox("Timeout!","Prompt");
	else if(4 == nError)	MessageBox("The user has logged in!","Prompt");
	else if(5 == nError)	MessageBox("The user has been locked!","Prompt");
	else if(6 == nError)	MessageBox("The user has listed into illegal!","Prompt");
	else if(7 == nError)	MessageBox("The system is busy!","Prompt");
	else if(9 == nError)	MessageBox("You Can't find the network server!","Prompt");
	else	MessageBox("Logout failed!","Prompt");
}

BOOL CRealPlayXCtrl::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BACKGROUND);
	BITMAP bmp;
	bitmap.GetBitmap(&bmp);

	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);

	dcCompatible.SelectObject(&bitmap);

	CRect rect;
	GetClientRect(&rect);
	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&dcCompatible,0,0,
		bmp.bmWidth,bmp.bmHeight,SRCCOPY);
	
	return TRUE;
}
