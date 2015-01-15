#if !defined(AFX_RULE11VIDEOABNORMAL_H__DDCA5C53_4120_420D_8C3B_C21D45A22DD1__INCLUDED_)
#define AFX_RULE11VIDEOABNORMAL_H__DDCA5C53_4120_420D_8C3B_C21D45A22DD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RuleVideoAbnormal.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRule11VideoAbnormal dialog

class CRuleVideoAbnormal : public CDialog
{
public:
	void initSubDlg();

	//��������Ϣ��ʾ���Ӵ��ڽ�����
	void showRuleInfo(RuleStruct* pRuleStruct);
	
	//����Ӵ��ڽ����ϵ���Ϣ
	void clearRuleInfo();
	
	//�������ϵ���Ϣ��䵽�ṹ����
	void setRuleInfo(char* pRuleStruct, int nLen);
	
	// ������� Ŀǰֻ֧��SceneChange
	char m_szArrDetectType[6][MAX_NAME_LEN];

private:
	//���»�ͼ
	void updateDraw();
	
private:
	CFG_VIDEOABNORMALDETECTION_INFO* m_pRule;

// Construction
public:
	CRuleVideoAbnormal(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRuleVideoAbnormal)
	enum { IDD = IDD_SUBDLG_RULE11_VIDEOABNORMAL };
	CSliderCtrl	m_slidSensi;
	CTreeCtrl	m_treeDetectType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRuleVideoAbnormal)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRuleVideoAbnormal)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickRule11TreeDetecttype(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeRule11EdtMindur();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RULE11VIDEOABNORMAL_H__DDCA5C53_4120_420D_8C3B_C21D45A22DD1__INCLUDED_)
