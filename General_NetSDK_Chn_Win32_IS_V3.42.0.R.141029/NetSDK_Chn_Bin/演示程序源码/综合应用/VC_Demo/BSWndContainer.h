/*********************************************************************************
 *	���� :	CBSWndContainer
 *
 *	���� :	��ͬһ������ͬʱ���Ŷ�·��Ƶʱ,��ɶര�ڽ����һЩ���ƿ��ơ�
 *			
 *			[��/�ര���л�],[ȫ��],[�߿�],[���ڰ���������],[�Զ�������߱���]
 *		
 *	���� :	OLinS
 *
 *	ʱ�� :	2003.1.15
 *												
 *********************************************************************************
 */


#if !defined(AFX_BSWNDCONTAINER_H__73CB8E46_8ED9_4C36_BA91_29D5F5BB05DE__INCLUDED_)
#define AFX_BSWNDCONTAINER_H__73CB8E46_8ED9_4C36_BA91_29D5F5BB05DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BSWndContainer.h : header file
//
//��Ƶ����֮��ļ��
#define WINDOW_SPACE  1

/////////////////////////////////////////////////////////////////////////////
// CBSWndContainer window
#include <afxtempl.h>

class CBSWndContainer : public CWnd
{
// Construction
public:
	CBSWndContainer();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBSWndContainer)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBSWndContainer();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBSWndContainer)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////////////////////////////
// public interface member
public:

	///////////////////////////////////////////////////
	// ��������(Container)
	BOOL Create( LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);

	///////////////////////////////////////////////////
	// ��Ӵ���
	BOOL AddPage(CWnd *pWnd, BOOL bRepaint = TRUE);

	///////////////////////////////////////////////////
	// ɾ������(ֻ�Ǵ�������ɾ��,ʵ�ʶ���ı����ⲿɾ��) 
	CWnd *DelPage(CWnd *pWnd);

	///////////////////////////////////////////////////
	// ɾ�������
	CWnd *DelPage();

	///////////////////////////////////////////////////
	// ���ü����
	void SetActivePage(CWnd *pWnd, BOOL bRepaint = TRUE);

	///////////////////////////////////////////////////
	// �õ������
	CWnd *GetActivePage();

	///////////////////////////////////////////////////
	// �õ���һ������
	CWnd *GetNextPage(CWnd *pWnd);

	///////////////////////////////////////////////////
	// �õ�ǰһ������
	CWnd *GetPrevPage(CWnd *pWnd);

	///////////////////////////////////////////////////
	//	�õ�ָ����ŵĴ���
	CWnd *GetPage(int nIndex);

	///////////////////////////////////////////////////
	//	�õ���������
	int GetCount() const;

	///////////////////////////////////////////////////
	//	�õ���󴰿�
	CWnd *GetTailPage();

	///////////////////////////////////////////////////
	// ���´���
	virtual void UpdateWnd();

	///////////////////////////////////////////////////
	//	ȫ����ʾ
	void SetFullScreen(BOOL bFlag);
	BOOL GetFullScreen();

	///////////////////////////////////////////////////
	//	������ʾ
	void SetMultiScreen(BOOL bFlag);
	BOOL GetMultiScreen();

	//////////////////////////////////////////////////
	//	�Զ����ڳߴ�
	void SetAutoAdjustPos(BOOL bFlag);
	BOOL GetAutoAdjustPos();

	//////////////////////////////////////////////////
	//	����ڱ߿�
	void SetDrawActivePage(BOOL bFlag,COLORREF clrTopLeft=RGB(255, 0, 0), COLORREF clrBottomRight=RGB(255, 0, 0));
	BOOL GetDrawActivePage();

	//////////////////////////////////////////////////
	//	��ʾ�ٷֱ�
	//	40 <= nPortion <=100
	void SetShowPortion(int nPortion=100);
	int  GetShowPortion();

//////////////////////////////////////////////////////////////////////////////////////////////////////
// protected member for derived class
protected:
	
	///////////////////////////////////////////////////
	// ֮��������
	CList<CWnd *,CWnd *> m_PageList;

	///////////////////////////////////////////////////
	// �����ָ��
	CWnd *m_pActivePage;

	///////////////////////////////////////////////////
	// ȫ�����
	BOOL m_bFullScreen;

	///////////////////////////////////////////////////
	// �������
	BOOL m_bMultiScreen;	

	///////////////////////////////////////////////////
	// �Զ��������
	BOOL m_bAutoAdjustPos;

	///////////////////////////////////////////////////
	// �߿���
	BOOL m_bDrawActive;

	///////////////////////////////////////////////////
	// ��ʾ����ٷֱ�(40-100)
	int	m_nShowPortion; 

	WINDOWPLACEMENT m_OldWndPlacement; //��������ԭ����λ�� 
	CRect m_FullScreenRect; //��ʾȫ����ʾʱ�Ĵ���λ��
////////////////////////////////////////////////////////////////////////////////////////////////////////
// private member for inter user
private:

	///////////////////////////////////////////////////
	//	��������,ɾ�����е���Ч�ڵ�,���ؽڵ����
	int UpdateList();

	///////////////////////////////////////////////////
	//	�����Ӵ��ڵ���� �� ��ʾ��Χ ,�õ����ڵ�λ��
	virtual void CalcPageRect(LPRECT lpRect,int nIndex,int nPageCount);

	///////////////////////////////////////////////////
	//	����Ԥ����ı����õ���ʾ����(11/8)
	void AdjustRect(LPRECT lpRect);

	///////////////////////////////////////////////////
	//	�������õ���ʾ����
	void GetShowRect(LPRECT lpRect);

	///////////////////////////////////////////////////
	//	������ڱ߿�
	void DrawActivePage(BOOL bFlag);

	///////////////////////////////////////////////////
	//	���ڱ߿���ɫ
	COLORREF m_clrTopLeft;
	COLORREF m_clrBottomRight;

	///////////////////////////////////////////////////
	//	ȫ��ʱ����ԭ������Ϣ,�����ָ�����
	WINDOWPLACEMENT _temppl;		//window's placement
	CWnd *			_tempparent;	//window's parent
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BSWNDCONTAINER_H__73CB8E46_8ED9_4C36_BA91_29D5F5BB05DE__INCLUDED_)
