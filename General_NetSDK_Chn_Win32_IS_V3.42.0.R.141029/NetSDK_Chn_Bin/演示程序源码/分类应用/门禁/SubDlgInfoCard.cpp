// SubDlgInfoCard.cpp : implementation file
//

#include "stdafx.h"
#include "accesscontrol.h"
#include "SubDlgInfoCard.h"
#include "SubDlgSensorInfoDescription.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubDlgInfoCard dialog


CSubDlgInfoCard::CSubDlgInfoCard(CWnd* pParent /* = NULL */, NET_RECORDSET_ACCESS_CTL_CARD* p /* = NULL */, int nAccessGroup /* = 1 */)
	: CDialog(CSubDlgInfoCard::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSubDlgInfoCard)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	memset(&m_stuInfo, 0, sizeof(m_stuInfo));
	if (p != NULL)
	{
		memcpy(&m_stuInfo, p, sizeof(NET_RECORDSET_ACCESS_CTL_CARD));
	}
	m_stuInfo.dwSize = sizeof(m_stuInfo);

	m_emOperateType = Em_Operate_Type_Show;
    m_nAccessGroup  = nAccessGroup;
}


void CSubDlgInfoCard::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubDlgInfoCard)
	DDX_Control(pDX, IDC_RECSET_CARD_CMB_CARDTYPE, m_cmbCardType);
	DDX_Control(pDX, IDC_RECSET_CARD_CMB_CARDSTATUS, m_cmbCardStatus);
	DDX_Control(pDX, IDC_RECSET_CARD_DTP_VDSTART, m_dtpVDStart);
	DDX_Control(pDX, IDC_RECSET_CARD_DTP_VDEND, m_dtpVDEnd);
	DDX_Control(pDX, IDC_RECSET_CARD_DTP_CT_TIME, m_dtpCreateTimeTime);
	DDX_Control(pDX, IDC_RECSET_CARD_DTP_CT_DATE, m_dtpCreateTimeDate);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubDlgInfoCard, CDialog)
	//{{AFX_MSG_MAP(CSubDlgInfoCard)
	ON_BN_CLICKED(IDC_RECSET_CARD_BTN_DOORS, OnRecsetCardBtnDoors)
	ON_BN_CLICKED(IDC_RECSET_CARD_BTN_TM, OnRecsetCardBtnTm)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CSubDlgInfoCard::InitDlg()
{
	int i = 0;

	// Card Status
	for (i = 0; i < sizeof(stuDemoCardStatus)/sizeof(stuDemoCardStatus[0]); i++)
	{
		m_cmbCardStatus.InsertString(-1, ConvertString(stuDemoCardStatus[i].szName, SUBDLG_INFO_CARD));
	}

	// Card Type
	for (i = 0; i < sizeof(stuDemoCardType)/sizeof(stuDemoCardType[0]); i++)
	{
		m_cmbCardType.InsertString(-1, ConvertString(stuDemoCardType[i].szName, SUBDLG_INFO_CARD));
	}

	if (Em_Operate_Type_Show == m_emOperateType)
	{
		GetDlgItem(IDC_RECSET_CARD_EDT_RECNO)->EnableWindow(FALSE);
		StuToDlg();
	}
	else if (Em_Operate_Type_Insert == m_emOperateType)
	{
		GetDlgItem(IDC_RECSET_CARD_EDT_RECNO)->EnableWindow(FALSE);
	}
	else if (Em_Operate_Type_Get == m_emOperateType)
	{
		GetDlgItem(IDC_RECSET_CARD_EDT_RECNO)->EnableWindow();
		m_dtpCreateTimeDate.EnableWindow(FALSE);
		m_dtpCreateTimeTime.EnableWindow(FALSE);
		GetDlgItem(IDC_RECSET_CARD_EDT_CARDNO)->EnableWindow(FALSE);
		GetDlgItem(IDC_RECSET_CARD_EDT_USERID)->EnableWindow(FALSE);
		m_cmbCardStatus.EnableWindow(FALSE);
		m_cmbCardType.EnableWindow(FALSE);
		GetDlgItem(IDC_RECSET_CARD_EDT_PWD)->EnableWindow(FALSE);
		GetDlgItem(IDC_RECSET_CARD_EDT_USETIME)->EnableWindow(FALSE);
		m_dtpVDStart.EnableWindow(FALSE);
		m_dtpVDEnd.EnableWindow(FALSE);
	}
	else if (Em_Operate_Type_Update == m_emOperateType)
	{
		StuToDlg();
 		GetDlgItem(IDC_RECSET_CARD_EDT_RECNO)->EnableWindow(FALSE);
	}
	else if (Em_Operate_Type_Remove == m_emOperateType)
	{
		StuToDlg();
		GetDlgItem(IDC_RECSET_CARD_EDT_RECNO)->EnableWindow();
		m_dtpCreateTimeDate.EnableWindow(FALSE);
		m_dtpCreateTimeTime.EnableWindow(FALSE);
		GetDlgItem(IDC_RECSET_CARD_EDT_CARDNO)->EnableWindow(FALSE);
		GetDlgItem(IDC_RECSET_CARD_EDT_USERID)->EnableWindow(FALSE);
		m_cmbCardStatus.EnableWindow(FALSE);
		m_cmbCardType.EnableWindow(FALSE);
		GetDlgItem(IDC_RECSET_CARD_EDT_PWD)->EnableWindow(FALSE);
		GetDlgItem(IDC_RECSET_CARD_EDT_USETIME)->EnableWindow(FALSE);
		m_dtpVDStart.EnableWindow(FALSE);
		m_dtpVDEnd.EnableWindow(FALSE);
	}
	else if (Em_Operate_Type_Clear == m_emOperateType)
	{
		// ...
	}
}

void CSubDlgInfoCard::StuToDlg()
{
	// RecNo
	SetDlgItemInt(IDC_RECSET_CARD_EDT_RECNO, m_stuInfo.nRecNo);

	// create time
	SYSTEMTIME st = {0};
	st.wYear	= (WORD)m_stuInfo.stuCreateTime.dwYear;
	st.wMonth	= (WORD)m_stuInfo.stuCreateTime.dwMonth;
	st.wDay		= (WORD)m_stuInfo.stuCreateTime.dwDay;
	m_dtpCreateTimeDate.SetTime(&st);
	st.wHour	= (WORD)m_stuInfo.stuCreateTime.dwHour;
	st.wMinute	= (WORD)m_stuInfo.stuCreateTime.dwMinute;
	st.wSecond	= (WORD)m_stuInfo.stuCreateTime.dwSecond;
	m_dtpCreateTimeTime.SetTime(&st);
	
	// card no
	SetDlgItemText(IDC_RECSET_CARD_EDT_CARDNO, m_stuInfo.szCardNo);

	// user id
	SetDlgItemText(IDC_RECSET_CARD_EDT_USERID, m_stuInfo.szUserID);

	// card status
	m_cmbCardStatus.SetCurSel(CardStatusToInt(m_stuInfo.emStatus));

	// card type
	m_cmbCardType.SetCurSel(CardTypeToInt(m_stuInfo.emType));

	// password
	SetDlgItemText(IDC_RECSET_CARD_EDT_PWD, m_stuInfo.szPsw);

	// use time
	SetDlgItemInt(IDC_RECSET_CARD_EDT_USETIME, m_stuInfo.nUserTime, TRUE);

	// valid time start
	st.wYear	= (WORD)m_stuInfo.stuValidStartTime.dwYear;
	st.wMonth	= (WORD)m_stuInfo.stuValidStartTime.dwMonth;
	st.wDay		= (WORD)m_stuInfo.stuValidStartTime.dwDay;
	m_dtpVDStart.SetTime(&st);

	// valid time end
	st.wYear	= (WORD)m_stuInfo.stuValidEndTime.dwYear;
	st.wMonth	= (WORD)m_stuInfo.stuValidEndTime.dwMonth;
	st.wDay		= (WORD)m_stuInfo.stuValidEndTime.dwDay;
	m_dtpVDEnd.SetTime(&st);
}

void CSubDlgInfoCard::DlgToStu()
{
	// RecNo
	m_stuInfo.nRecNo = GetDlgItemInt(IDC_RECSET_CARD_EDT_RECNO, NULL, TRUE);
	
	// create time
	SYSTEMTIME st = {0};
	m_dtpCreateTimeDate.GetTime(&st);
	m_stuInfo.stuCreateTime.dwYear	= st.wYear;
	m_stuInfo.stuCreateTime.dwMonth = st.wMonth;
	m_stuInfo.stuCreateTime.dwDay	= st.wDay;
	m_dtpCreateTimeTime.GetTime(&st);
	m_stuInfo.stuCreateTime.dwHour	= st.wHour;
	m_stuInfo.stuCreateTime.dwMinute = st.wMinute;
	m_stuInfo.stuCreateTime.dwSecond = st.wSecond;
	
	// card no
	GetDlgItemText(IDC_RECSET_CARD_EDT_CARDNO, m_stuInfo.szCardNo, sizeof(m_stuInfo.szCardNo) - 1);
	
	// user id
	GetDlgItemText(IDC_RECSET_CARD_EDT_USERID, m_stuInfo.szUserID, sizeof(m_stuInfo.szUserID) - 1);
	
	// card status
	m_stuInfo.emStatus = IntToCardStatus(m_cmbCardStatus.GetCurSel());
	
	// card type
	m_stuInfo.emType = IntToCardType(m_cmbCardType.GetCurSel());
	
	// password
	GetDlgItemText(IDC_RECSET_CARD_EDT_PWD, m_stuInfo.szPsw, sizeof(m_stuInfo.szPsw) - 1);
	
	// use time
	m_stuInfo.nUserTime = GetDlgItemInt(IDC_RECSET_CARD_EDT_USETIME, NULL, TRUE);
	
	// valid time start
	m_dtpVDStart.GetTime(&st);
	m_stuInfo.stuValidStartTime.dwYear = st.wYear;
	m_stuInfo.stuValidStartTime.dwMonth = st.wMonth;
	m_stuInfo.stuValidStartTime.dwDay = st.wDay;
	
	// valid time end
	m_dtpVDEnd.GetTime(&st);
	m_stuInfo.stuValidEndTime.dwYear = st.wYear;
	m_stuInfo.stuValidEndTime.dwMonth = st.wMonth;
	m_stuInfo.stuValidEndTime.dwDay = st.wDay;
}

BOOL CSubDlgInfoCard::Get()
{
	m_stuInfo.nRecNo = GetDlgItemInt(IDC_RECSET_CARD_EDT_RECNO, NULL, TRUE);
	return TRUE;
}

BOOL CSubDlgInfoCard::Update()
{
	return TRUE;
}

BOOL CSubDlgInfoCard::Remove()
{
	return TRUE;
}

void CSubDlgInfoCard::Clear()
{

}

int CSubDlgInfoCard::CardStatusToInt(NET_ACCESSCTLCARD_STATE emStatus)
{
	int n = -1;
	if (NET_ACCESSCTLCARD_STATE_UNKNOWN == emStatus)
	{
		n = 0;
	}
	else if (NET_ACCESSCTLCARD_STATE_NORMAL == emStatus)
	{
		n = 1;
	}
	else if (NET_ACCESSCTLCARD_STATE_LOSE == emStatus)
	{
		n = 2;
	}
	else if (NET_ACCESSCTLCARD_STATE_LOGOFF == emStatus)
	{
		n = 3;
	}
	else if (NET_ACCESSCTLCARD_STATE_FREEZE == emStatus)
	{
		n = 4;
	}
	return n;
}

NET_ACCESSCTLCARD_STATE CSubDlgInfoCard::IntToCardStatus(int n)
{
	NET_ACCESSCTLCARD_STATE emStatua = NET_ACCESSCTLCARD_STATE_UNKNOWN;
	if (0 == n)
	{
	}
	else if (1 == n)
	{
		emStatua = NET_ACCESSCTLCARD_STATE_NORMAL;
	}
	else if (2 == n)
	{
		emStatua = NET_ACCESSCTLCARD_STATE_LOSE;
	}
	else if (3 == n)
	{
		emStatua = NET_ACCESSCTLCARD_STATE_LOGOFF;
	}
	else if (4 == n)
	{
		emStatua = NET_ACCESSCTLCARD_STATE_FREEZE;
	}
	return emStatua;
}

int CSubDlgInfoCard::CardTypeToInt(NET_ACCESSCTLCARD_TYPE emType)
{
	int n = -1;
	if (NET_ACCESSCTLCARD_TYPE_UNKNOWN == emType)
	{
		n = 0;
	}
	else if (NET_ACCESSCTLCARD_TYPE_GENERAL == emType)
	{
		n = 1;
	}
	else if (NET_ACCESSCTLCARD_TYPE_VIP == emType)
	{
		n = 2;
	}
	else if (NET_ACCESSCTLCARD_TYPE_GUEST == emType)
	{
		n = 3;
	}
	else if (NET_ACCESSCTLCARD_TYPE_PATROL == emType)
	{
		n = 4;
	}
	else if (NET_ACCESSCTLCARD_TYPE_BLACKLIST == emType)
	{
		n = 5;
	}
	else if (NET_ACCESSCTLCARD_TYPE_CORCE == emType)
	{
		n = 6;
	}
	else if (NET_ACCESSCTLCARD_TYPE_MOTHERCARD == emType)
	{
		n = 7;
	}
	return n;
}

NET_ACCESSCTLCARD_TYPE CSubDlgInfoCard::IntToCardType(int n)
{
	NET_ACCESSCTLCARD_TYPE emType = NET_ACCESSCTLCARD_TYPE_UNKNOWN;
	if (0 == n)
	{
	}
	else if (1 == n)
	{
		emType = NET_ACCESSCTLCARD_TYPE_GENERAL;
	}
	else if (2 == n)
	{
		emType = NET_ACCESSCTLCARD_TYPE_VIP;
	}
	else if (3 == n)
	{
		emType = NET_ACCESSCTLCARD_TYPE_GUEST;
	}
	else if (4 == n)
	{
		emType = NET_ACCESSCTLCARD_TYPE_PATROL;
	}
	else if (5 == n)
	{
		emType = NET_ACCESSCTLCARD_TYPE_BLACKLIST;
	}
	else if (6 == n)
	{
		emType = NET_ACCESSCTLCARD_TYPE_CORCE;
	}
	else if (7 == n)
	{
		emType = NET_ACCESSCTLCARD_TYPE_MOTHERCARD;
	}
	return emType;
}

/////////////////////////////////////////////////////////////////////////////
// CSubDlgInfoCard message handlers

BOOL CSubDlgInfoCard::OnInitDialog() 
{
	CDialog::OnInitDialog();
	g_SetWndStaticText(this, SUBDLG_INFO_CARD);
	// TODO: Add extra initialization here
	InitDlg();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSubDlgInfoCard::OnOK() 
{
	// TODO: Add extra validation here
	switch (m_emOperateType)
	{
	case Em_Operate_Type_Show:
		{
			StuToDlg();
		}
		break;
	case Em_Operate_Type_Insert:
		{
			DlgToStu();
		}
		break;
	case Em_Operate_Type_Get:
		{
			DlgToStu();
		}
	case Em_Operate_Type_Update:
		{
			DlgToStu();
		}
		break;
	case Em_Operate_Type_Remove:
		{
			DlgToStu();
		}
		break;
	case Em_Operate_Type_Clear:
		break;
	default:
		break;
	}
	CDialog::OnOK();
}

void CSubDlgInfoCard::OnRecsetCardBtnDoors() 
{
	// TODO: Add your control notification handler code here	
	std::vector<int> vecChn;
	int i = 0;
	for (; i < m_stuInfo.nDoorNum; i++)
	{
		vecChn.push_back(m_stuInfo.sznDoors[i]);
	}
	
	CSubDlgSensorInfoDescription dlg(this, m_nAccessGroup);
	dlg.SetID(vecChn);
	if (IDOK == dlg.DoModal())
	{
		if (Em_Operate_Type_Insert == m_emOperateType
			|| Em_Operate_Type_Update == m_emOperateType)
		{
			vecChn.clear();
			vecChn = dlg.GetID();
			std::vector<int>::iterator it = vecChn.begin();
			for (i = 0; i < __min(vecChn.size(), DH_MAX_DOOR_NUM) && it != vecChn.end(); i++, it++)
			{
				m_stuInfo.sznDoors[i] = *it;
			}
			m_stuInfo.nDoorNum = __min(vecChn.size(), DH_MAX_DOOR_NUM);
		}
	}
}

void CSubDlgInfoCard::OnRecsetCardBtnTm() 
{
	// TODO: Add your control notification handler code here	
	std::vector<int> vecChn;
	int i = 0;
	for (; i < m_stuInfo.nTimeSectionNum; i++)
	{
		vecChn.push_back(m_stuInfo.sznTimeSectionNo[i]);
	}
	
	CSubDlgSensorInfoDescription dlg(this, 128);
	dlg.SetID(vecChn);
	if (IDOK == dlg.DoModal())
	{
		if (Em_Operate_Type_Insert == m_emOperateType
			|| Em_Operate_Type_Update == m_emOperateType)
		{
			vecChn.clear();
			vecChn = dlg.GetID();
			std::vector<int>::iterator it = vecChn.begin();
			for (i = 0; i < __min(vecChn.size(), DH_MAX_TIMESECTION_NUM) && it != vecChn.end(); i++, it++)
			{
				m_stuInfo.sznTimeSectionNo[i] = *it;
			}
			m_stuInfo.nTimeSectionNum = __min(vecChn.size(), DH_MAX_TIMESECTION_NUM);
		}
	}	
}
