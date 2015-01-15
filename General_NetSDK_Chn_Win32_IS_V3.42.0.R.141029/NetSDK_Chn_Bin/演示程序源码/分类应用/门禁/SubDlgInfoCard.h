#if !defined(AFX_SUBDLGINFOCARD_H__2410B577_5B03_4F4D_8F44_54E07099336D__INCLUDED_)
#define AFX_SUBDLGINFOCARD_H__2410B577_5B03_4F4D_8F44_54E07099336D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubDlgInfoCard.h : header file
//

// card status
typedef struct tagDemoCardStatus 
{
	NET_ACCESSCTLCARD_STATE	emStatus;
	const char*				szName;
}DemoCardStatus;

const DemoCardStatus stuDemoCardStatus[] =
{
	{NET_ACCESSCTLCARD_STATE_UNKNOWN, "Unknown"},
	{NET_ACCESSCTLCARD_STATE_NORMAL, "Normal"},
	{NET_ACCESSCTLCARD_STATE_LOSE, "Lose"},
	{NET_ACCESSCTLCARD_STATE_LOGOFF, "LogOff"},
	{NET_ACCESSCTLCARD_STATE_FREEZE, "Freeze"},
};

// card type
typedef struct tagDemoCardType 
{
	NET_ACCESSCTLCARD_TYPE	emType;
	const char*				szName;
}DemoCardType;

const DemoCardType stuDemoCardType[] = 
{
	{NET_ACCESSCTLCARD_TYPE_UNKNOWN, "Unknown"},
	{NET_ACCESSCTLCARD_TYPE_GENERAL, "General"},
	{NET_ACCESSCTLCARD_TYPE_VIP, "VIP"},
	{NET_ACCESSCTLCARD_TYPE_GUEST, "Guest"},
	{NET_ACCESSCTLCARD_TYPE_PATROL, "Patrol"},
	{NET_ACCESSCTLCARD_TYPE_BLACKLIST, "BlackList"},
	{NET_ACCESSCTLCARD_TYPE_CORCE, "Duress"},
	{NET_ACCESSCTLCARD_TYPE_MOTHERCARD, "MotherCard"},
};

/////////////////////////////////////////////////////////////////////////////
// CSubDlgInfoCard dialog

class CSubDlgInfoCard : public CDialog
{
// Construction
public:
	CSubDlgInfoCard(CWnd* pParent = NULL, NET_RECORDSET_ACCESS_CTL_CARD* p = NULL, int nAccessGroup = 1);   // standard constructor

	void		SetOperateType(Em_RecordSet_Operate_Type emType) {m_emOperateType = emType;}

	void		SetInfo(const NET_RECORDSET_ACCESS_CTL_CARD* p) {	
		memcpy(&m_stuInfo, p, sizeof(NET_RECORDSET_ACCESS_CTL_CARD));}

	const NET_RECORDSET_ACCESS_CTL_CARD& GetInfo() const { return m_stuInfo;}

// Dialog Data
	//{{AFX_DATA(CSubDlgInfoCard)
	enum { IDD = IDD_SUBDLG_INFO_CARD };
	CComboBox	m_cmbCardType;
	CComboBox	m_cmbCardStatus;
	CDateTimeCtrl	m_dtpVDStart;
	CDateTimeCtrl	m_dtpVDEnd;
	CDateTimeCtrl	m_dtpCreateTimeTime;
	CDateTimeCtrl	m_dtpCreateTimeDate;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubDlgInfoCard)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSubDlgInfoCard)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnRecsetCardBtnDoors();
	afx_msg void OnRecsetCardBtnTm();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	void InitDlg();
	void StuToDlg();
	void DlgToStu();

	BOOL Get();
	BOOL Update();
	BOOL Remove();
	void Clear();

	int  CardStatusToInt(NET_ACCESSCTLCARD_STATE emStatus);
	NET_ACCESSCTLCARD_STATE IntToCardStatus(int n);

	int  CardTypeToInt(NET_ACCESSCTLCARD_TYPE emType);
	NET_ACCESSCTLCARD_TYPE IntToCardType(int n);

private:
	NET_RECORDSET_ACCESS_CTL_CARD	m_stuInfo;
	Em_RecordSet_Operate_Type		m_emOperateType;
    int                             m_nAccessGroup;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBDLGINFOCARD_H__2410B577_5B03_4F4D_8F44_54E07099336D__INCLUDED_)
