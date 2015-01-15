#if !defined(AFX_RULE5LEFT_H__183D97AB_E32F_4898_9C8B_F59ED3C91ECC__INCLUDED_)
#define AFX_RULE5LEFT_H__183D97AB_E32F_4898_9C8B_F59ED3C91ECC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RuleLeft.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRuleLeft dialog

class CRuleLeft : public CDialog
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
	CFG_LEFT_INFO* m_pRule;

// Construction
public:
	CRuleLeft(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRuleLeft)
	enum { IDD = IDD_SUBDLG_RULE05_LEFT };
	CComboBox	m_cmbTriggerPos;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRuleLeft)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRuleLeft)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeRule5CmbTriggerpos();
	afx_msg void OnChangeRule5EdtMindur();
	afx_msg void OnRule5RadioCfilter();
	afx_msg void OnRule5RadioGfilter();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RULE5LEFT_H__183D97AB_E32F_4898_9C8B_F59ED3C91ECC__INCLUDED_)
