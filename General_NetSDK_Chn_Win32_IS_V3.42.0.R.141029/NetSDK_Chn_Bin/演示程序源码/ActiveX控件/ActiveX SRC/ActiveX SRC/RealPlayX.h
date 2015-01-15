#if !defined(AFX_REALPLAYX_H__A27A0F2B_791F_46C2_98EE_686B48CD4AE9__INCLUDED_)
#define AFX_REALPLAYX_H__A27A0F2B_791F_46C2_98EE_686B48CD4AE9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// RealPlayX.h : main header file for REALPLAYX.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRealPlayXApp : See RealPlayX.cpp for implementation.

class CRealPlayXApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REALPLAYX_H__A27A0F2B_791F_46C2_98EE_686B48CD4AE9__INCLUDED)
