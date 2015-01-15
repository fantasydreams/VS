#if !defined(AFX_FLASHLABEL_H__67607320_8161_4863_8FE0_224C14FD28A1__INCLUDED_)
#define AFX_FLASHLABEL_H__67607320_8161_4863_8FE0_224C14FD28A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FlashLabel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFlashLabel window

class CFlashLabel : public CStatic
{
// Construction
public:
	CFlashLabel();

// Attributes
public:
    enum { COLOR_NUM = 2 };
    enum { TIME_ID_FLASH = 1 };

// Operations
public:    
    /// ��ʼ��˸
    /// \param  nTime ��˸����ʱ��, ʱ�䵽���Զ�ֹͣ. -1��ʾһֱ��˸, �����Զ�ֹͣ
    /// \return 
    void StartFlash(UINT nTime = -1);

    /// ֹͣ��˸
    /// \return 
    void StopFlash();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlashLabel)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFlashLabel();

protected:
    //void Redraw();

protected:
    COLORREF    m_arColor[COLOR_NUM];
    UINT        m_nColorIndex;
    UINT        m_nTimer;
	DWORD       m_dwDrawTick;
    UINT        m_nFlashTime;

	// Generated message map functions
protected:
	//{{AFX_MSG(CFlashLabel)
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLASHLABEL_H__67607320_8161_4863_8FE0_224C14FD28A1__INCLUDED_)
