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
	CIvsGlobalPreview();
	virtual ~CIvsGlobalPreview();

	//���û�ͼ����
	void setGlobalInfo(CFG_ANALYSEGLOBAL_INFO* pGlobalInfo, BOOL bClear);

	//������л�ͼ����
	CFG_ANALYSEGLOBAL_INFO* getGlobalInfo();

	//��ͼ�ص�����
	static void _stdcall DrawIvsGlobalCfgProc(long nPort, HDC hDc, LONG dwUser);

	void EnableDrawLine(bool bDraw){m_bDrawLine = bDraw;}
	
	CRITICAL_SECTION	m_cs;
	// Generated message map functions
protected:
	//{{AFX_MSG(CIvsGlobalPreview)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	//��������
	int		m_iPtCnt;
	CFG_POLYGON*	m_pPolygonCfg;
	BOOL	m_bCloseRegion;
	//
	CFG_ANALYSEGLOBAL_INFO	*m_pGlobalInfo;

	bool m_bLButtonDown; // ��ʾ����Ƿ���
	bool m_bDrawLine;//��ʾ�Ƿ���Ի���
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IVSGLOBALPREVIEW_H__2F7A4317_C981_4514_BDC5_118EB89E97D4__INCLUDED_)
