#if !defined(AFX_IVSGLOBALPREVIEW_H__2F7A4317_C981_4514_BDC5_118EB89E97D4__INCLUDED_)
#define AFX_IVSGLOBALPREVIEW_H__2F7A4317_C981_4514_BDC5_118EB89E97D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IvsGlobalPreview.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIvsGlobalPreview window

class CIvsGlobalPreview : public CWnd
{
public:
	//��ȡ�Ѿ��е�����
	CFG_POLYGON* getRegion(int& nCnt);

	//�������
	BOOL closeRegion();

	//������е�����
	void clearRegion();

	//���û�ͼ����
	void setGlobalInfo(CFG_ANALYSEGLOBAL_INFO* pGlobalInfo, BOOL bClear);

	//������л�ͼ����
	CFG_ANALYSEGLOBAL_INFO getGlobalInfo();

	//��ͼ����
	void beginDraw(HTREEITEM hItem, EM_STAFF_TYPE emStaffType);

	//ǿ��ֹͣ��ͼ
	void endDraw();
	
	//�Ƿ����ڻ�ͼ
	BOOL isDrawing();

	//��ͼ�ص�����
	static void _stdcall drawIvsGlobalCfgProc(long nPort, HDC hDc, LONG dwUser);
	
public:
	CRITICAL_SECTION	m_cs;

private:
	//��������
	int		m_iPtCnt;
	CFG_POLYGON*	m_pPolygonCfg;
	BOOL	m_bCloseRegion;

	//���Ʊ��
	int		m_iMaxStaffCnt;
	int		m_iStaffCnt;
	CFG_STAFF*		m_pStaffCfg;

	//
	CFG_ANALYSEGLOBAL_INFO	m_stuGlobalInfo;
	float	m_fX;
	float	m_fY;
	
	BOOL	m_bAddRegion;
	BOOL	m_bAddStaff;
	EM_STAFF_TYPE	m_emStaffType;
	HTREEITEM	m_hItemToBeDraw;

// Construction
public:
	CIvsGlobalPreview();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIvsGlobalPreview)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CIvsGlobalPreview();

	// Generated message map functions
protected:
	//{{AFX_MSG(CIvsGlobalPreview)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IVSGLOBALPREVIEW_H__2F7A4317_C981_4514_BDC5_118EB89E97D4__INCLUDED_)
