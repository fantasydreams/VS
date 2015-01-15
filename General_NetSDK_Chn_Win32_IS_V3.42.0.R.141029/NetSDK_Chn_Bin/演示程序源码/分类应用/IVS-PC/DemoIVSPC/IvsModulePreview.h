#if !defined(AFX_IVSMODULEPREVIEW_H__F4159618_F744_49CE_90FB_276A626E8C58__INCLUDED_)
#define AFX_IVSMODULEPREVIEW_H__F4159618_F744_49CE_90FB_276A626E8C58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IvsModulePreview.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CIvsModulePreview window

class CIvsModulePreview : public CWnd
{
// Construction
public:
	CIvsModulePreview();
	virtual ~CIvsModulePreview();

	//��ȡ�Ѿ��е�ģ����Ϣ
	CFG_MODULE_INFO* GetModuleInfo();

	//����/���ģ����Ϣ
	void SetModuleInfo(CFG_MODULE_INFO* pModuleInfo, BOOL bClear);

	//��ȡ�������/�Ѿ�����������
	CFG_POLYGON* GetPolygonCfg(int& nCnt);

	//������ӵ�����
	void SetPolygonCfg(CFG_POLYGON* pPolygonCfg, int nCnt);

	//��ʼ��ͼ
	void BeginDraw(HTREEITEM hItem, BOOL bAddDectectZone);

	//�Ƿ����ڻ�ͼ
	BOOL IsDrawing();

	//��ͼ�ص�
	static void _stdcall DrawIvsModuleCfgProc(long nPort, HDC hDc, LONG dwUser);

	void Redraw(HTREEITEM hItem, BOOL bAddDectectZone);

	CRITICAL_SECTION	m_cs;

protected:
	//{{AFX_MSG(CIvsModulePreview)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	//��ģ�����ô��ڵ�ѡ�е�ģ����Ϣ���ݵ���
	CFG_MODULE_INFO	m_cfgModuleInfo;
	CFG_POLYGON*	m_pPolygonCfg;
	int				m_iPtCnt;
	float	m_fX;
	float	m_fY;

	BOOL			m_bAddDetecRegion;
	HTREEITEM		m_hItemToBeDraw;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IVSMODULEPREVIEW_H__F4159618_F744_49CE_90FB_276A626E8C58__INCLUDED_)
