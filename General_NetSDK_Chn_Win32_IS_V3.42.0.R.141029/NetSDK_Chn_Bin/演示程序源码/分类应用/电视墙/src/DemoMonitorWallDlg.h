// DemoMonitorWallDlg.h : header file
//

#if !defined(AFX_DEMOMONITORWALLDLG_H__60CAB033_5393_4279_ABAC_B7BC928646B7__INCLUDED_)
#define AFX_DEMOMONITORWALLDLG_H__60CAB033_5393_4279_ABAC_B7BC928646B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "VideoScreen.h"
#include "Device.h"
#include "ToolBarEx.h"

/////////////////////////////////////////////////////////////////////////////
// CDemoMonitorWallDlg dialog

class CDemoMonitorWallDlg : public CDialog
{
// Construction
public:
	CDemoMonitorWallDlg(CWnd* pParent = NULL);	// standard constructor
	enum { SBF_BYID, SBF_BYVALUE };

// Dialog Data
	//{{AFX_DATA(CDemoMonitorWallDlg)
	enum { IDD = IDD_DEMOMONITORWALL_DIALOG };
	CTreeCtrl	m_treeDevice;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoMonitorWallDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	const CDecoder* GetDecoderInfo() const { return m_pDecoder; }

protected:

	void InitUI();

	void ClearDecoder();
	// ����豸map
	void ClearEncoder();
	// �����豸����
	void AddDevice2Tree(CEncoder* pDev);
	// ��treeCtrl��hItem����²�����������(==data)�Ľ��, û�оͷ���NULL
	HTREEITEM FindTreeNode(const CTreeCtrl& treeCtrl, HTREEITEM hItem, const TreeItemData& data);
	// ����豸��
	void ClearEncoderTree();
	// ���treeCtrl�е�ĳ����㼰���ӽ��
	void ClearTreeNode(CTreeCtrl& treeCtrl, HTREEITEM hItem);
	// ���Ĭ�ϱ����豸
	void AddDefaultEncoder();

	// ˢ�´��ڵ���ʾԴ��Ϣ
	void UpdateSplitSource();
	// �������ָťʹ��, nBtnIDΪ-1��ʾ���а�ť
	void EnableSplitButton(UINT nBtnIDorValue, BOOL bEnable = TRUE, UINT uFlag = SBF_BYID);
	void EnableFreeStyleButton(BOOL bEnable = TRUE);

	// �õ���ʾԴ��Ӧ����ʾ��Ϣ
	CString GetSplitSourceCaption(const DH_SPLIT_SOURCE* pstuSrc);
	CString GetSplitSourceCaption(const DH_WINDOW_COLLECTION* pstuSrc);

	DH_RECT RectUniversalize(const CRect& rcWnd);
	CRect RectUniversalize(const DH_RECT& rcWnd);

	// ���߻ص�
	static void CALLBACK DisConnect(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);
	void OnDeviceDisconnect(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort);
	static void CALLBACK HaveReConnect(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);
	void OnReconnect(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort);

    BOOL ToolBarLogin(WPARAM wParam, LPARAM lParam);
    BOOL ToolBarLogout(WPARAM wParam, LPARAM lParam);
    BOOL ToolBarSplice(WPARAM wParam, LPARAM lParam);
    BOOL ToolBarSplitN(WPARAM wParam, LPARAM lParam);
    BOOL ToolBarOpenWindow(WPARAM wParam, LPARAM lParam); 
    BOOL ToolBarCloseWindow(WPARAM wParam, LPARAM lParam);
    BOOL ToolBarSplitFree(WPARAM wParam, LPARAM lParam);
    BOOL ToolBarSetLevel(WPARAM wParam, LPARAM lParam);
    BOOL ToolBarPower(WPARAM wParam, LPARAM lParam);
    BOOL ToolBarCollection(WPARAM wParam, LPARAM lParam);
    BOOL ToolBarSetPush(WPARAM wParam, LPARAM lParam);

protected:
	HICON		m_hIcon;
	CToolBarEx	m_wndToolBar;
	CToolBarEx	m_wndSplit;
	CVideoScreen m_wndScreen;
	CComboBox	m_cbTVOut;

	// ������Ϣ
	CDecoder*	m_pDecoder;
	// �豸��Ϣ
	typedef std::map<LLONG, CEncoder*> CEncoderMap;
	CEncoderMap	m_mapEncoder;

	// Generated message map functions
	//{{AFX_MSG(CDemoMonitorWallDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnAddDevice();
	afx_msg void OnBtnRemoveDevice();
	afx_msg void OnDblclkTreeDevice(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeComboTVOut();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOMONITORWALLDLG_H__60CAB033_5393_4279_ABAC_B7BC928646B7__INCLUDED_)
