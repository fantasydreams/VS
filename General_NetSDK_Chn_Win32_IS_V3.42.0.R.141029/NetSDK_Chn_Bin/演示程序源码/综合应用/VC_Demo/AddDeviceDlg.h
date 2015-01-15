#if !defined(AFX_ADDDEVICEDLG_H__27F0123F_5073_4459_978F_8710DAB04FF0__INCLUDED_)
#define AFX_ADDDEVICEDLG_H__27F0123F_5073_4459_978F_8710DAB04FF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddDeviceDlg.h : header file
//
#include"depend/dhnetsdk.h"
/////////////////////////////////////////////////////////////////////////////
// AddDeviceDlg dialog

typedef struct _UserInfo
{
	char devicename[24];
	char ip[64];
	DWORD port;
	char username[20];
	char userpsw[20];
}UserInfo;

class AddDeviceDlg : public CDialog
{
// Construction
public:
	AddDeviceDlg(CWnd* pParent = NULL);   // standard constructor

	void GetConnectError(int error);    //��ȡ������Ϣ
// Dialog Data
	//{{AFX_DATA(AddDeviceDlg)
	enum { IDD = IDD_ADDDEVICE };
	CComboBox	m_ctlNetState;
	CComboBox	m_ipsel;
	CString	m_devicename;
	CString	m_deviceusername;
	CString	m_deviceuserpsw;
	DWORD	m_deviceport;
	CString	m_IPstr;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AddDeviceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AddDeviceDlg)
	afx_msg void OnConnectDevice();
	afx_msg void OnCancelAdddevice();
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnSelchangeIpselection();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	NET_PARAM	stuParam[5];
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDDEVICEDLG_H__27F0123F_5073_4459_978F_8710DAB04FF0__INCLUDED_)
