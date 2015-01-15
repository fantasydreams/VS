#if !defined(AFX_RULE10TAKENAWAY_H__9E847AA8_508D_40EF_A62F_55968896FF7C__INCLUDED_)
#define AFX_RULE10TAKENAWAY_H__9E847AA8_508D_40EF_A62F_55968896FF7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RuleTakenAway.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRuleTakenAway dialog

class CRuleTakenAway : public CDialog
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
	CFG_TAKENAWAYDETECTION_INFO* m_pRule;

// Construction
public:
	CRuleTakenAway(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRuleTakenAway)
	enum { IDD = IDD_SUBDLG_RULE10_TAKENAWAY };
	CComboBox	m_cmbTriggerPos;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRuleTakenAway)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRuleTakenAway)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeRule10CmbTriggerpos();
	afx_msg void OnChangeRule10EdtMindur();
	afx_msg void OnRule10RadioCfilter();
	afx_msg void OnRule10RadioGfilter();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RULE10TAKENAWAY_H__9E847AA8_508D_40EF_A62F_55968896FF7C__INCLUDED_)
