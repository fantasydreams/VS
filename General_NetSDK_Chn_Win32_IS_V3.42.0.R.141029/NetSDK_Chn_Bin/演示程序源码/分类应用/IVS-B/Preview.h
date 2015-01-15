#if !defined(AFX_PREVIEW_H__8E9C1545_CAAC_4618_9A5D_7889CFA50EA4__INCLUDED_)
#define AFX_PREVIEW_H__8E9C1545_CAAC_4618_9A5D_7889CFA50EA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Preview.h : header file
//

// #include "PictureWnd.h"
#define WM_CLOSEPREVIEW		(WM_USER + 300)

/////////////////////////////////////////////////////////////////////////////
// CPreview dialog

class CPreview : public CDialog
{
public:
	//��ȡ�豸��¼������豸��Ϣ���ʼ��������
	void initPreviewDlg(int nChnCount);

	//�ǳ��豸�������ڽ�����Ϣ
	void uninitPreviewDlg();

	void showPreview(LONG lLoginHanlde, int nChannel);
	void closePreview(LONG lRealPlayHandle);

	void showAlarmInfo(int nChannel);
	void insertAlarmInfo(AlarmInfoNode* pAlarmInfoNode);
	void clearAllAlarmInfo();
	
	//ʵʱ�����ϻ��ƹ�����Ϣ
	static void _stdcall drawIvsInfoPreviewProc(long nPort,HDC hdc,LONG nUser);
	
	//ʵʱ�����ϻ���ʵʱ�����ܷ�����Ϣ
	static void _stdcall getIvsInfoProc(char* buf, long type, long len, long reallen, long reserved, long nUser);


// Construction
public:
	CPreview(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPreview)
	enum { IDD = IDD_PREVIEW };
	CListCtrl	m_lsAlarm;
	CComboBox	m_cmbChannel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPreview)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPreview)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnSelchangePreviewCmbChannel();
	afx_msg void OnRclickPreviewListAlarm(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClearInfo();
	afx_msg void OnClosePreview();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PREVIEW_H__8E9C1545_CAAC_4618_9A5D_7889CFA50EA4__INCLUDED_)
