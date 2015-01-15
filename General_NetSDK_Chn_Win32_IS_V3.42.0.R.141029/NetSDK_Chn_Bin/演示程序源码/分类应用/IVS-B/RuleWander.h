#if !defined(AFX_RULE12WANDER_H__29E4313F_D628_491A_97B3_97267DC58A02__INCLUDED_)
#define AFX_RULE12WANDER_H__29E4313F_D628_491A_97B3_97267DC58A02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RuleWander.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRuleWander dialog

class CRuleWander : public CDialog
{
public:
	void initSubDlg();

	//��������Ϣ��ʾ���Ӵ��ڽ�����
	void showRuleInfo(RuleStruct* pRuleStruct);
	
	//����Ӵ��ڽ����ϵ���Ϣ
	void clearRuleInfo();
	
	//�������ϵ���Ϣ��䵽�ṹ����
	void setRuleInfo(char* pRuleStruct, int nLen);
	
private:
	//���»�ͼ
	void updateDraw();
	
private:
	CFG_WANDER_INFO* m_pRule;

// Construction
public:
	CRuleWander(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRuleWander)
	enum { IDD = IDD_SUBDLG_RULE12_WANDER };
	CTreeCtrl	m_treeObjType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRuleWander)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRuleWander)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickRule12TreeObjtype(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeRule12EdtMindur();
	afx_msg void OnChangeRule12EdtReportinterval();
	afx_msg void OnRule12RadioCfilter();
	afx_msg void OnRule12RadioGfilter();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RULE12WANDER_H__29E4313F_D628_491A_97B3_97267DC58A02__INCLUDED_)
