// IVS_VDemo.h : main header file for the IVS_VDemo application
//

#if !defined(AFX_IVS_VDemo_H__66C09B60_FEA7_4109_9E9A_5E12453CF71D__INCLUDED_)
#define AFX_IVS_VDemo_H__66C09B60_FEA7_4109_9E9A_5E12453CF71D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIVS_VDemoApp:
// See IVS_VDemo.cpp for the implementation of this class
//

class CIVS_VDemoApp : public CWinApp
{
public:
	CIVS_VDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIVS_VDemoApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL InitApplication();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIVS_VDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IVS_VDemo_H__66C09B60_FEA7_4109_9E9A_5E12453CF71D__INCLUDED_)
