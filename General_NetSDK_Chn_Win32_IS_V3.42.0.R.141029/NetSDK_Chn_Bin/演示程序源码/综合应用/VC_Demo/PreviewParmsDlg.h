#if !defined(AFX_PREVIEWPARMSDLG_H__5B0E1DAD_D44D_4748_A668_E3E4E9271246__INCLUDED_)
#define AFX_PREVIEWPARMSDLG_H__5B0E1DAD_D44D_4748_A668_E3E4E9271246__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PreviewParmsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPreviewParmsDlg dialog

class CPreviewParmsDlg : public CDialog
{
// Construction
public:
	CPreviewParmsDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPreviewParmsDlg)
	enum { IDD = IDD_PREVIEW_PARM };
	CComboBox	m_previewtypesel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPreviewParmsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPreviewParmsDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	int m_iPreviewType;
	int m_channelId;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREVIEWPARMSDLG_H__5B0E1DAD_D44D_4748_A668_E3E4E9271246__INCLUDED_)
