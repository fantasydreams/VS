#if !defined(AFX_RULE7PRESERVATION_H__593E1F3F_D52C_4267_AC61_65F7F01B9FEC__INCLUDED_)
#define AFX_RULE7PRESERVATION_H__593E1F3F_D52C_4267_AC61_65F7F01B9FEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RulePreservation.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRulePreservation dialog

class CRulePreservation : public CDialog
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
	CFG_PRESERVATION_INFO* m_pRule;

// Construction
public:
	CRulePreservation(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRulePreservation)
	enum { IDD = IDD_SUBDLG_RULE07_PRESERV };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRulePreservation)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRulePreservation)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeRule7EdtMindur();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RULE7PRESERVATION_H__593E1F3F_D52C_4267_AC61_65F7F01B9FEC__INCLUDED_)
