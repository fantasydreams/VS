#pragma once
#include "afxwin.h"


// CTargetFilter �Ի���
class CTargetFilterPreview;


class CTargetFilter : public CDialog
{
	DECLARE_DYNAMIC(CTargetFilter)

public:
	CTargetFilter(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTargetFilter();

	void ShowView();
	void Init(CFG_ANALYSEMODULES_INFO*pAnalyseModulesInfo, int nChannel);
	void FillData();

// �Ի�������
	enum { IDD = IDD_TARGET_FILTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	
	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedBtnFilterOk();
	afx_msg void OnBnClickedBtnFilterCancel();
	
	afx_msg void OnCbnSelendcancelComboFilterType();
	afx_msg void OnCbnSelendcancelComboFilterPattern();
	afx_msg void OnBnClickedCheckRectangle();
private:
	CTargetFilterPreview *m_pTargetFilterPreview;
	int m_nChannel;
	int m_nMoudleIndex;
	CFG_ANALYSEMODULES_INFO* m_pAnalyseModulesInfo;

	CComboBox m_comboFilterPattern;
	CComboBox m_comboFilterType;
	CButton m_checkLenWidth;
};
