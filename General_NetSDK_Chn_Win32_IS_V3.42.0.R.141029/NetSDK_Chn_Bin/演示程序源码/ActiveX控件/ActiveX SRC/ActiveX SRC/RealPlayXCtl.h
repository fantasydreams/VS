#if !defined(AFX_REALPLAYXCTL_H__008BB552_E4D9_42A4_8E51_778D5D339625__INCLUDED_)
#define AFX_REALPLAYXCTL_H__008BB552_E4D9_42A4_8E51_778D5D339625__INCLUDED_

#include "dhnetsdk.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// RealPlayXCtl.h : Declaration of the CRealPlayXCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CRealPlayXCtrl : See RealPlayXCtl.cpp for implementation.

class CRealPlayXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CRealPlayXCtrl)

// Constructor
public:
	CRealPlayXCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRealPlayXCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CRealPlayXCtrl();

	DECLARE_OLECREATE_EX(CRealPlayXCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CRealPlayXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CRealPlayXCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CRealPlayXCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CRealPlayXCtrl)
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CRealPlayXCtrl)
	afx_msg BOOL SetDeviceInfo(LPCTSTR strDvrIP, long nPort, short nChannel, LPCTSTR strUserId, LPCTSTR strUserPwd);
	afx_msg BOOL StartPlay();
	afx_msg BOOL StopPlay();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CRealPlayXCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	short m_nChannel;
	friend void CALLBACK DisConnectFunc(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser);
	void DeviceDisConnect(LONG lLoginID, char *sDVRIP, LONG nDVRPort);
	enum {
	//{{AFX_DISP_ID(CRealPlayXCtrl)
	dispidSetDeviceInfo = 1L,
	dispidStartPlay = 2L,
	dispidStopPlay = 3L,
	//}}AFX_DISP_ID
	};
private:
	long m_hRealPlay;
	CString m_strDvrIP;
	void ShowLoginErrorReason(int nError);
	long m_LoginID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REALPLAYXCTL_H__008BB552_E4D9_42A4_8E51_778D5D339625__INCLUDED)
