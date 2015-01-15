#if !defined(AFX_DLGCHN_H__D348D8AD_9809_4FF8_9843_E576C622E6DF__INCLUDED_)
#define AFX_DLGCHN_H__D348D8AD_9809_4FF8_9843_E576C622E6DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgChn.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgChn dialog

class CDlgChn : public CDialog
{
// Construction
public:
	CDlgChn(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgChn)
	enum { IDD = IDD_DIALOG_CHN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgChn)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
public:
	BOOL SetChnState(BYTE* bState, int nLen = 16);
	BOOL GetChnState(BYTE* bState, int nLen);

	BOOL SetChnState(DWORD dwState, int nLen = 16);
	BOOL GetChnState(DWORD* dwState, int nLen);

	BOOL Attach(UINT uID, CDialog* pAttachDlg);
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgChn)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCHN_H__D348D8AD_9809_4FF8_9843_E576C622E6DF__INCLUDED_)
