#if !defined(AFX_IVSGLOBALPREVIEW_H__2F7A4317_C981_4514_BDC5_118EB89E97D4__INCLUDED_)
#define AFX_IVSGLOBALPREVIEW_H__2F7A4317_C981_4514_BDC5_118EB89E97D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IvsGlobalPreview.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIvsGlobalPreview window
#define WM_ZONEDONE			(WM_USER + 100)	//����ȫ�ֱ궨����/�����ɺ�֪ͨ������

class CIvsSceneDraw : public CWnd
{
public:
	//��ȡ�Ѿ��е�����
	CFG_POLYGON* getRegion(int& nCnt);

	//�������
	BOOL closeRegion();

	//������е�����
	void clearRegion();

	//���û�ͼ����
	void setMainDirection(CFG_POLYGON* pMainDirectioInfo, BOOL bClear);

	//��ͼ����
	void beginDraw(bool bStart);

	CFG_POLYGON*  GetMainDirectionInfo() { return m_szMainDirection; }
	
	bool          IsShow() {return m_bShow;}

	static void  Paint_Arrow(POINT startPoint,POINT endPoint,HDC hDc_Paint_Arrow);

	//��ͼ�ص�����
	static void _stdcall drawIvsSceneCfgProc(long nPort, HDC hDc, LONG dwUser);
	
public:
	CRITICAL_SECTION	m_cs;

private:
	bool        m_bStartDraw;
	bool        m_bShow;
	CFG_POLYGON	m_szMainDirection[2];
	float	    m_fX;
	float	    m_fY;

// Construction
public:
	CIvsSceneDraw();

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
	virtual ~CIvsSceneDraw();

	// Generated message map functions
protected:
	//{{AFX_MSG(CIvsGlobalPreview)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IVSGLOBALPREVIEW_H__2F7A4317_C981_4514_BDC5_118EB89E97D4__INCLUDED_)
