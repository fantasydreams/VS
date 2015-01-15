#if !defined(AFX_DLGDOORCONTROL_H__B622F09F_B761_41E1_B88C_FD2ADA0738C3__INCLUDED_)
#define AFX_DLGDOORCONTROL_H__B622F09F_B761_41E1_B88C_FD2ADA0738C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgDoorControl.h : header file
//

typedef enum tagDoorStatusType
{
	Door_Status_Type_Unknown = 0,
	Door_Status_Type_Open,
	Door_Status_Type_Close,
}emDoorStatusType;

typedef struct tagDemoDoorStatusInfo 
{
	emDoorStatusType	emType;
	const char*			szInfo;
}stuDemoDoorStatusInfo;

const stuDemoDoorStatusInfo stuDemoDoorStatus[] = {
	{Door_Status_Type_Unknown, "Unknown"},
	{Door_Status_Type_Open, "Open"},
	{Door_Status_Type_Close, "Close"},
};

/////////////////////////////////////////////////////////////////////////////
// CDlgDoorControl dialog

class CDlgDoorControl : public CDialog
{
// Construction
public:
	CDlgDoorControl(CWnd* pParent = NULL, LLONG lLoginID = 0);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgDoorControl)
	enum { IDD = IDD_DLG_DOOR_CTL };
	CComboBox	m_cmbDoorStatus;
	CComboBox	m_cmbChannel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDoorControl)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgDoorControl)
	virtual BOOL OnInitDialog();
	afx_msg void OnDoorctlBtnOpen();
	afx_msg void OnDoorctlBtnClose();
	afx_msg void OnDoorctlBtnQuery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void		InitDlg();

private:
	LLONG		m_lLoginID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDOORCONTROL_H__B622F09F_B761_41E1_B88C_FD2ADA0738C3__INCLUDED_)
