#if !defined(AFX_CONFIGGLOBAL_H__B65DAC46_5353_45D7_9CC9_76046D91201C__INCLUDED_)
#define AFX_CONFIGGLOBAL_H__B65DAC46_5353_45D7_9CC9_76046D91201C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConfigGlobal.h : header file
//

class CIvsGlobalPreview;
/////////////////////////////////////////////////////////////////////////////
// CConfigGlobal dialog

class CConfigGlobal : public CDialog
{
private:
	CIvsGlobalPreview* m_pIvsGlobalPreview;

private:
	CFG_ANALYSEGLOBAL_INFO updateTreeRegion();

public:
	//��ȡ�豸ȫ�����ú��ʼ������
	void initGlobalDlg(int nChannel);

	//�ǳ��豸���˳�����ʱ�������
	void uninitGlobalDlg();
	
	void showPreview(LONG lLoginHanlde, int nChannel);
	
	void closePreview(LONG lRealPlayHandle);
	
public:
	COLORREF m_colorPen;
	
public:
	friend class CDemoIVSbDlg;
	friend class CConfig;

// Construction
public:
	CConfigGlobal(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CConfigGlobal)
	enum { IDD = IDD_CONFIG_GLOBAL };
	CTreeCtrl	m_treeRegion;
	CEdit	m_edtChnName;
	CComboBox	m_cmbScene;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConfigGlobal)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CConfigGlobal)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCfggloCmbScene();
	afx_msg void OnClickCfggloTreeRegion(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCfggloBtnAddaera();
	afx_msg void OnCfggloBtnAddruler();
	afx_msg void OnDestroy();
	afx_msg LRESULT OnZoneDone(WPARAM, LPARAM);
	afx_msg void OnCfggloBtnDelarea();
	afx_msg void OnCfggloBtnDelruler();
	afx_msg void OnCfggloBtnGet();
	afx_msg void OnCfggloBtnSet();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONFIGGLOBAL_H__B65DAC46_5353_45D7_9CC9_76046D91201C__INCLUDED_)
