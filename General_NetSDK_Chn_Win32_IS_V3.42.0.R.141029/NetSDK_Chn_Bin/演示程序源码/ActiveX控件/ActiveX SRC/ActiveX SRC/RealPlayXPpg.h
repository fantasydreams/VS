#if !defined(AFX_REALPLAYXPPG_H__E8FDACB9_DA10_4F6C_8691_AA5F0409ABD6__INCLUDED_)
#define AFX_REALPLAYXPPG_H__E8FDACB9_DA10_4F6C_8691_AA5F0409ABD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// RealPlayXPpg.h : Declaration of the CRealPlayXPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CRealPlayXPropPage : See RealPlayXPpg.cpp.cpp for implementation.

class CRealPlayXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CRealPlayXPropPage)
	DECLARE_OLECREATE_EX(CRealPlayXPropPage)

// Constructor
public:
	CRealPlayXPropPage();

// Dialog Data
	//{{AFX_DATA(CRealPlayXPropPage)
	enum { IDD = IDD_PROPPAGE_REALPLAYX };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CRealPlayXPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REALPLAYXPPG_H__E8FDACB9_DA10_4F6C_8691_AA5F0409ABD6__INCLUDED)
