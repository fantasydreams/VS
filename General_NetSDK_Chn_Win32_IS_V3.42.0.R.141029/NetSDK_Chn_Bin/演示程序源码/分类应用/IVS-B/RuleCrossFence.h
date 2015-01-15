#if !defined(AFX_RULE1CROSSFENCE_H__C31147DB_38A8_456C_A363_D65AEAE3F742__INCLUDED_)
#define AFX_RULE1CROSSFENCE_H__C31147DB_38A8_456C_A363_D65AEAE3F742__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RuleCrossFence.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRuleCrossFence dialog

class CRuleCrossFence : public CDialog
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
	CFG_CROSSFENCEDETECTION_INFO* m_pRule;

// Construction
public:
	CRuleCrossFence(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRuleCrossFence)
	enum { IDD = IDD_SUBDLG_RULE01_CROSSFENCE };
	CTreeCtrl	m_treeObjType;
	CComboBox	m_cmbDirection;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRuleCrossFence)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRuleCrossFence)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeRule1CmbDirection();
	afx_msg void OnClickRule1TreeObjtype(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRule1RadioCfilter();
	afx_msg void OnRule1RadioGfilter();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RULE1CROSSFENCE_H__C31147DB_38A8_456C_A363_D65AEAE3F742__INCLUDED_)
