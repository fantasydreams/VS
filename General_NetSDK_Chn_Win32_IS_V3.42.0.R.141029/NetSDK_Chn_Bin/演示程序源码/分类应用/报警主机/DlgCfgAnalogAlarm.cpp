// DlgCfgAnalogAlarm.cpp : implementation file
//

#include "stdafx.h"
#include "AlarmDevice.h"
#include "DlgCfgAnalogAlarm.h"
#include "SubDlgCfgEventHandler.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCfgAnalogAlarm dialog


CDlgCfgAnalogAlarm::CDlgCfgAnalogAlarm(CWnd* pParent /* = NULL */, LLONG hLoginID /* = NULL */, int nChannelNum /* = 16 */)
	: CDialog(CDlgCfgAnalogAlarm::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCfgAnalogAlarm)
	//}}AFX_DATA_INIT
	
	m_hLoginID = hLoginID;
	m_nChannelNum = nChannelNum;
	memset(&m_stuInfo, 0, sizeof(m_stuInfo));
    memset(&m_stuSensorList, 0, sizeof(m_stuSensorList));
    m_stuSensorList.dwSize = sizeof(m_stuSensorList);
}


void CDlgCfgAnalogAlarm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCfgAnalogAlarm)
	DDX_Control(pDX, IDC_CFG_ANALOGALARM_CMB_SENSORTYPE, m_cmbSensorType);
	DDX_Control(pDX, IDC_CFG_ANALOGALARM_CMB_MODE, m_cmbMode);
	DDX_Control(pDX, IDC_CFG_ANALOGALARM_EDT_NAME, m_edtName);
	DDX_Control(pDX, IDC_CFG_ANALOGALARM_CMB_SENSORMETHOD, m_cmbSensorMethod);
	DDX_Control(pDX, IDC_CFG_ANALOGALARM_CMB_CHN, m_cmbChn);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCfgAnalogAlarm, CDialog)
	//{{AFX_MSG_MAP(CDlgCfgAnalogAlarm)
	ON_BN_CLICKED(IDC_CFG_ANALOGALARM_BTN_EVENTHANDLER, OnCfgAnalogalarmBtnEventhandler)
	ON_BN_CLICKED(IDC_CFG_ANALOGALARM_BTN_GET, OnCfgAnalogalarmBtnGet)
	ON_BN_CLICKED(IDC_CFG_ANALOGALARM_BTN_SET, OnCfgAnalogalarmBtnSet)
	ON_CBN_SELCHANGE(IDC_CFG_ANALOGALARM_CMB_CHN, OnSelchangeCfgAnalogalarmCmbChn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCfgAnalogAlarm message handlers

BOOL CDlgCfgAnalogAlarm::OnInitDialog() 
{
	CDialog::OnInitDialog();
	g_SetWndStaticText(this, DLG_CFG_ANALOGALARM);
	// TODO: Add extra initialization here
	if (!m_hLoginID)
	{
		MessageBox(ConvertString("We haven't login yet!", DLG_CFG_ANALOGALARM), ConvertString("Prompt"));
		return FALSE;
	}

	int nRetLen = 0;

	BOOL bRet = CLIENT_QueryDevState(m_hLoginID,DH_DEVSTATE_GET_SENSORLIST,(char*)&m_stuSensorList, sizeof(m_stuSensorList),&nRetLen,SDK_API_WAIT);
	if (bRet == FALSE)
	{
		CString csErr;
		csErr.Format("%s %08x...",ConvertString("Query state GetSensorList failed:", DLG_CFG_ANALOGALARM), CLIENT_GetLastError());
		MessageBox(csErr, ConvertString("Prompt"));
		//return FALSE;
	} 

	GetConfigFromDevice();
	InitDlg();
	StuToDlg();
		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgCfgAnalogAlarm::OnCfgAnalogalarmBtnEventhandler() 
{
	// TODO: Add your control notification handler code here
	CSubDlgCfgEventHandler* dlgEventHandler = new CSubDlgCfgEventHandler;
	if (dlgEventHandler != NULL)
	{
		dlgEventHandler->SetEventHandler(m_stuInfo.stuEventHandler);
		dlgEventHandler->SetTimeSection(&m_stuInfo.stuTimeSection[0][0]);
		
		if (IDOK == dlgEventHandler->DoModal())
		{
			const CFG_ALARM_MSG_HANDLE stuEventHandler = dlgEventHandler->GetEventHandler();
			memcpy(&m_stuInfo.stuEventHandler, &stuEventHandler, sizeof(CFG_ALARM_MSG_HANDLE));
			
			for (int i = 0; i < WEEK_DAY_NUM; i++)
			{
				for (int j = 0; j < MAX_REC_TSECT; j++)
				{
					const CFG_TIME_SECTION* pstuTimeSection = dlgEventHandler->GetTimeSection(i, j);
					if (pstuTimeSection)
					{
						memcpy(&m_stuInfo.stuTimeSection[i][j], pstuTimeSection, sizeof(CFG_TIME_SECTION));
					}
				}
			}
		}
	}
}

void CDlgCfgAnalogAlarm::OnCfgAnalogalarmBtnGet() 
{
	// TODO: Add your control notification handler code here
	if (GetConfigFromDevice())
	{
		StuToDlg();
	}
}

void CDlgCfgAnalogAlarm::OnCfgAnalogalarmBtnSet() 
{
	// TODO: Add your control notification handler code here
	DlgToStu();
	SetConfigToDevice();	
}

void CDlgCfgAnalogAlarm::OnSelchangeCfgAnalogalarmCmbChn() 
{
	// TODO: Add your control notification handler code here
	int nSel = m_cmbChn.GetCurSel();
	if (-1 == nSel)
	{
		return;
	}
	if (GetConfigFromDevice())
	{
		StuToDlg();
	}
}

//////////////////////////////////////////////////////////////////////////
// Private method

void CDlgCfgAnalogAlarm::InitDlg(BOOL bShow /* = TRUE */)
{
	if (!bShow)
	{
		memset(&m_stuInfo, 0, sizeof(m_stuInfo));
	}

	int i = 0;
	int nChannelNum = m_nChannelNum == 0 ? 16 : m_nChannelNum;

	// channel
	m_cmbChn.ResetContent();
	for (i = 0; i < nChannelNum; i++)
	{
		CString csItem;
		csItem.Format("%s %02d", ConvertString("Channel"), i + 1);
		m_cmbChn.InsertString(-1, csItem);
	}
	m_cmbChn.SetCurSel(0);

	// limit1

	// limit2

	// limit3

	// limit4

	// mode
	m_cmbMode.ResetContent();
	for (i = 0; i < sizeof(stuDemoMode) / sizeof(stuDemoMode[0]); i++)
	{
		m_cmbMode.InsertString(-1, stuDemoMode[i].szMode);
	}

	m_cmbMode.SetCurSel(-1);

	// name
	SetDlgItemText(IDC_CFG_ANALOGALARM_EDT_NAME, NULL);

	// sensor method
	m_cmbSensorMethod.ResetContent();
	for (i = 0; i < sizeof(stuDemoAnalogSenseMethod) / sizeof(stuDemoAnalogSenseMethod[0]); i++)
	{
		m_cmbSensorMethod.InsertString(-1, ConvertString(stuDemoAnalogSenseMethod[i].pszName, DLG_CFG_ALARM));
	}
	m_cmbSensorMethod.SetCurSel(-1);

	// sensor type
	m_cmbSensorType.ResetContent();
	for (i = 0; i < m_stuSensorList.nSupportSensorNum; i++)
	{
		m_cmbSensorType.InsertString(-1, m_stuSensorList.szSensorList[i]);
		char sztemp[64] = {0};
		strncpy(sztemp, m_stuSensorList.szSensorList[i], sizeof(sztemp) - 1);
	}
	
	// set unknown type 
	m_cmbSensorType.InsertString(-1, "UnknownType");
	m_cmbSensorType.SetCurSel(-1);

	// upper limit

	// lower limit

	// sensitivity

	// compensation
}

BOOL CDlgCfgAnalogAlarm::SetConfigToDevice()
{	
	int nSel = m_cmbChn.GetCurSel();
	if (-1 == nSel)
	{
		return FALSE;
	}
	char szJsonBuf[1024 * 40] = {0};
	BOOL bRet = CLIENT_PacketData(CFG_CMD_ANALOGALARM, &m_stuInfo, sizeof(m_stuInfo), szJsonBuf, sizeof(szJsonBuf));
	if (!bRet)
	{
		MessageBox(CString("packet AnalogAlarm error..."), ConvertString("Prompt"));
		return FALSE;
	} 
	else
	{
		int nerror = 0;
		int nrestart = 0;
		
		bRet = CLIENT_SetNewDevConfig((LLONG)m_hLoginID, CFG_CMD_ANALOGALARM, nSel, szJsonBuf, strlen(szJsonBuf), &nerror, &nrestart, SDK_API_WAIT);
		if (!bRet)
		{
			CString csErr;
			csErr.Format("%s: %08x...", 
				ConvertString("SetupConfig AnalogAlarm failed", DLG_CFG_ANALOGALARM), CLIENT_GetLastError());
			MessageBox(csErr, ConvertString("Prompt"));
			return FALSE;
		}
		else
		{
			MessageBox(ConvertString("SetConfig Alarm ok!", DLG_CFG_ANALOGALARM), ConvertString("Prompt"));
		}
	}
	return TRUE;
}

BOOL CDlgCfgAnalogAlarm::GetConfigFromDevice()
{
	char szJsonBuf[1024 * 40] = {0};
	int nerror = 0;
	int nSelChn = m_cmbChn.GetCurSel() == -1 ? 0 : m_cmbChn.GetCurSel();
	BOOL bRet = CLIENT_GetNewDevConfig((LLONG)m_hLoginID, CFG_CMD_ANALOGALARM, nSelChn, szJsonBuf, 
		sizeof(szJsonBuf), &nerror, SDK_API_WAIT);
	
	if (bRet)
	{
		DWORD dwRetLen = 0;
		bRet = CLIENT_ParseData(CFG_CMD_ANALOGALARM, szJsonBuf, (void*)&m_stuInfo, sizeof(m_stuInfo), &dwRetLen);
		if (!bRet)
		{
			MessageBox(ConvertString("parse AnalogAlarm error...", DLG_CFG_ANALOGALARM), ConvertString("Prompt"));
			return FALSE;
		}
	}
	else
	{			
		CString csErr;
		csErr.Format("%s: %08x...\r\n\r\n%s", 
			ConvertString("QueryConfig AnalogAlarm error", DLG_CFG_ANALOGALARM),
			CLIENT_GetLastError(), szJsonBuf);
		MessageBox(csErr, ConvertString("Prompt"));
		return FALSE;
	}
	return TRUE;
}

void CDlgCfgAnalogAlarm::DlgToStu()
{
	CString csTmp;

	// limit1
	GetDlgItemText(IDC_CFG_ANALOGALARM_EDT_LIMIT1, csTmp);
	m_stuInfo.fLimit1 = (float)atof(csTmp);
	// limit2
	GetDlgItemText(IDC_CFG_ANALOGALARM_EDT_LIMIT2, csTmp);
	m_stuInfo.fLimit2 = (float)atof(csTmp);
	// limit3
	GetDlgItemText(IDC_CFG_ANALOGALARM_EDT_LIMIT3, csTmp);
	m_stuInfo.fLimit3 = (float)atof(csTmp);
	// limit4
	GetDlgItemText(IDC_CFG_ANALOGALARM_EDT_LIMIT4, csTmp);
	m_stuInfo.fLimit4 = (float)atof(csTmp);
	// mode
	if (m_cmbMode.GetCurSel() != -1)
	{
		m_stuInfo.byMode = ModeToByte(m_cmbMode.GetCurSel());
	}
	// name
	GetDlgItemText(IDC_CFG_ANALOGALARM_EDT_NAME, m_stuInfo.szChnName, sizeof(m_stuInfo.szChnName));

	// sense method
	m_stuInfo.emSense = (EM_SENSE_METHOD)m_cmbSensorMethod.GetCurSel();

	// sensor type
	int nIndex = m_cmbSensorType.GetCurSel();
	if (nIndex >= m_stuSensorList.nSupportSensorNum || -1 == nIndex)
	{
		strcpy(m_stuInfo.szSensorType, "");
	}
	else
	{
		strncpy(m_stuInfo.szSensorType, m_stuSensorList.szSensorList[nIndex], CFG_COMMON_STRING_64 - 1);
	}

	// upper limit
	GetDlgItemText(IDC_CFG_ANALOGALARM_EDT_UPLIMIT, csTmp);
	m_stuInfo.fUpperLimit = (float)atof(csTmp);
	// lower limit
	GetDlgItemText(IDC_CFG_ANALOGALARM_EDT_LOWLIMIT, csTmp);
	m_stuInfo.fLowerLimit = (float)atof(csTmp);
	// sensitivity
	m_stuInfo.nSensitivity = GetDlgItemInt(IDC_CFG_ANALOGALARM_EDT_SENSITIVITY, NULL, FALSE);
	// compensation
	GetDlgItemText(IDC_CFG_ANALOGALARM_EDT_COMPENSATION, csTmp);
	m_stuInfo.fCompensation = (float)atof(csTmp);
}

void CDlgCfgAnalogAlarm::StuToDlg()
{
	CString csTmp;

	// limit1
	csTmp.Format("%e", m_stuInfo.fLimit1);
	SetDlgItemText(IDC_CFG_ANALOGALARM_EDT_LIMIT1, csTmp);
	// limit2
	csTmp.Format("%e", m_stuInfo.fLimit2);
	SetDlgItemText(IDC_CFG_ANALOGALARM_EDT_LIMIT2, csTmp);
	// limit3
	csTmp.Format("%e", m_stuInfo.fLimit3);
	SetDlgItemText(IDC_CFG_ANALOGALARM_EDT_LIMIT3, csTmp);
	// limit4
	csTmp.Format("%e", m_stuInfo.fLimit4);
	SetDlgItemText(IDC_CFG_ANALOGALARM_EDT_LIMIT4, csTmp);
	// mode
	m_cmbMode.SetCurSel(ModeToInt(m_stuInfo.byMode));
	// name
	SetDlgItemText(IDC_CFG_ANALOGALARM_EDT_NAME, m_stuInfo.szChnName);

	// sense method
	m_cmbSensorMethod.SetCurSel((int)m_stuInfo.emSense);

	// sense type
	int nIndex = 0;
	for (nIndex = 0; nIndex < m_stuSensorList.nSupportSensorNum; ++nIndex)
	{
		if (strncmp(m_stuSensorList.szSensorList[nIndex], m_stuInfo.szSensorType, CFG_COMMON_STRING_64)==0)
		{
			break;
		}
	}
	m_cmbSensorType.SetCurSel(nIndex);

	// upper limit
	csTmp.Format("%e", m_stuInfo.fUpperLimit);
	SetDlgItemText(IDC_CFG_ANALOGALARM_EDT_UPLIMIT, csTmp);
	// lower limit
	csTmp.Format("%e", m_stuInfo.fLowerLimit);
	SetDlgItemText(IDC_CFG_ANALOGALARM_EDT_LOWLIMIT, csTmp);
	// sensitivity
	SetDlgItemInt(IDC_CFG_ANALOGALARM_EDT_SENSITIVITY, m_stuInfo.nSensitivity, FALSE);
	// compensation
	csTmp.Format("%e", m_stuInfo.fCompensation);
	SetDlgItemText(IDC_CFG_ANALOGALARM_EDT_COMPENSATION, csTmp);
}

BYTE CDlgCfgAnalogAlarm::ModeToByte(int nCurSel)
{
	// ����ģʽ, �����ʾ, ��������ֵ1111��1110��1100��1000��0000
	BYTE byMode = 0;

	if (0 == nCurSel)
	{
		byMode = 15;
	}
	else if (1 == nCurSel)
	{
		byMode = 14;
	}
	else if (2 == nCurSel)
	{
		byMode = 12;
	}
	else if (3 == nCurSel)
	{
		byMode = 8;
	}
	else if (4 == nCurSel)
	{
		byMode = 0;
	}
	
	return byMode;
}

int CDlgCfgAnalogAlarm::ModeToInt(BYTE byMode)
{
	int nCurSel = -1;
	if (15 == byMode)
	{
		nCurSel = 0;
	}
	else if (14 == byMode)
	{
		nCurSel = 1;
	}
	else if (12 == byMode)
	{
		nCurSel = 2;
	}
	else if (8 == byMode)
	{
		nCurSel = 3;
	}
	else if (0 == byMode)
	{
		nCurSel = 4;
	}
	return nCurSel;
}

