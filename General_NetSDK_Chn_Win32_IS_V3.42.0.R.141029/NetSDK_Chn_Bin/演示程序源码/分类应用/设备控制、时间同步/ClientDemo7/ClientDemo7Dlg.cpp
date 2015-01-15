// ClientDemo7Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo7.h"
#include "ClientDemo7Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define DEMO_SDK_WAITTIME 3000
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientDemo7Dlg dialog

CClientDemo7Dlg::CClientDemo7Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CClientDemo7Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClientDemo7Dlg)
	m_dvrPort = 37777;
	m_strDvrPwd =  _T("admin");
	m_strDvrUserName =  _T("admin");
	m_CurTime = 0;
	m_dvrDate = 0;
	m_dvrTime = 0;
	m_CurDate = COleDateTime::GetCurrentTime();
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_LoginID = 0;
	m_nCurDiskType = 0;
	ZeroMemory(&m_stuDisk, sizeof(m_stuDisk));
}

void CClientDemo7Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClientDemo7Dlg)
	DDX_Control(pDX, IDC_COMBO_OUTCHANNEL, m_comboOutChannel);
	DDX_Control(pDX, IDC_COMBO_CHANNEL, m_comboChannel);
	DDX_Control(pDX, IDC_COMBO_DISK, m_comboDisk);
	DDX_Control(pDX, IDC_COMBO_OPERATE, m_comboOper);
	DDX_Control(pDX, IDC_IPADDRESS_DVRIP, m_dvrIP);
	DDX_Text(pDX, IDC_EDIT_PORT, m_dvrPort);
	DDV_MinMaxInt(pDX, m_dvrPort, 0, 100000);
	DDX_Text(pDX, IDC_EDIT_DVRPWD, m_strDvrPwd);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_strDvrUserName);
	DDX_DateTimeCtrl(pDX, IDC_TIME_SET, m_CurTime);
	DDX_DateTimeCtrl(pDX, IDC_DATE_GET, m_dvrDate);
	DDX_DateTimeCtrl(pDX, IDC_TIME_GET, m_dvrTime);
	DDX_DateTimeCtrl(pDX, IDC_DATE_SET, m_CurDate);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CClientDemo7Dlg, CDialog)
	//{{AFX_MSG_MAP(CClientDemo7Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_LOGIN, OnBtnLogin)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_LOGOUT, OnBtnLogout)
	ON_BN_CLICKED(IDC_BUTTON_SET, OnButtonSet)
	ON_BN_CLICKED(IDC_BUTTON_GET, OnButtonGet)
	ON_BN_CLICKED(IDC_BUTTON_RESTART, OnButtonRestart)
	ON_BN_CLICKED(IDC_BUTTON_DISKCTRL, OnButtonDiskctrl)
	ON_BN_CLICKED(IDC_BUTTON_ALARMSTART, OnButtonAlarmstart)
	ON_BN_CLICKED(IDC_BUTTON_ALARMSTOP, OnButtonAlarmstop)
	ON_BN_CLICKED(IDC_BUTTON_OUTALARMSTART, OnButtonOutalarmstart)
	ON_BN_CLICKED(IDC_BUTTON_OUTALARMSTOP, OnButtonOutalarmstop)
	ON_BN_CLICKED(IDC_BUTTON_NUM0, OnButtonNum0)
	ON_BN_CLICKED(IDC_BUTTON_NUM1, OnButtonNum1)
	ON_BN_CLICKED(IDC_BUTTON_NUM2, OnButtonNum2)
	ON_BN_CLICKED(IDC_BUTTON_NUM3, OnButtonNum3)
	ON_BN_CLICKED(IDC_BUTTON_NUM4, OnButtonNum4)
	ON_BN_CLICKED(IDC_BUTTON_NUM5, OnButtonNum5)
	ON_BN_CLICKED(IDC_BUTTON_NUM6, OnButtonNum6)
	ON_BN_CLICKED(IDC_BUTTON_NUM7, OnButtonNum7)
	ON_BN_CLICKED(IDC_BUTTON_NUM8, OnButtonNum8)
	ON_BN_CLICKED(IDC_BUTTON_NUM9, OnButtonNum9)
	ON_BN_CLICKED(IDC_BUTTON_NUM10, OnButtonNum10)
	ON_BN_CLICKED(IDC_BUTTON_NUM11, OnButtonNum11)
	ON_BN_CLICKED(IDC_BUTTON_NUM12, OnButtonNum12)
	ON_BN_CLICKED(IDC_BUTTON_NUM13, OnButtonNum13)
	ON_BN_CLICKED(IDC_BUTTON_NUM14, OnButtonNum14)
	ON_BN_CLICKED(IDC_BUTTON_NUM15, OnButtonNum15)
	ON_BN_CLICKED(IDC_BUTTON_NUM16, OnButtonNum16)
	ON_BN_CLICKED(IDC_BUTTON_REC, OnButtonRec)
	ON_BN_CLICKED(IDC_BUTTON_PREW, OnButtonPrew)
	ON_BN_CLICKED(IDC_BUTTON_SLOW, OnButtonSlow)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, OnButtonPlay)
	ON_BN_CLICKED(IDC_BUTTON_FAST, OnButtonFast)
	ON_BN_CLICKED(IDC_BUTTON_NEXT, OnButtonNext)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_JMPUP, OnButtonJmpup)
	ON_BN_CLICKED(IDC_BUTTON_JMPDOWN, OnButtonJmpdown)
	ON_BN_CLICKED(IDC_BUTTON_ESC, OnButtonEsc)
	ON_BN_CLICKED(IDC_BUTTON_FN1, OnButtonFn1)
	ON_BN_CLICKED(IDC_BUTTON_FN2, OnButtonFn2)
	ON_BN_CLICKED(IDC_BUTTON_UP, OnButtonUp)
	ON_BN_CLICKED(IDC_BUTTON_DOWN, OnButtonDown)
	ON_BN_CLICKED(IDC_BUTTON_LEFT, OnButtonLeft)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT, OnButtonRight)
	ON_BN_CLICKED(IDC_BUTTON_ENTER, OnButtonEnter)
	ON_BN_CLICKED(IDC_BUTTON_NINE, OnButtonNine)
	ON_BN_CLICKED(IDC_BUTTON_ONE, OnButtonOne)
	ON_BN_CLICKED(IDC_BUTTON_INFO, OnButtonInfo)
	ON_BN_CLICKED(IDC_BUTTON_ADDR, OnButtonAddr)
	ON_BN_CLICKED(IDC_BUTTON_SPLIT, OnButtonSplit)
	ON_BN_CLICKED(IDC_BUTTON_POWER, OnButtonPower)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientDemo7Dlg message handlers

BOOL CClientDemo7Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	g_SetWndStaticText(this);
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	//Device default IP
	m_dvrIP.SetAddress(10,12,2,60);
	//Initialize net SDK
	InitNetSDK();
	//Set current time 
	CTime curTime = CTime::GetCurrentTime();
	m_CurDate.SetDateTime(curTime.GetYear(), curTime.GetMonth(), curTime.GetDay(), 
		curTime.GetHour(), curTime.GetMinute(), curTime.GetSecond());
	m_CurTime = curTime;
	m_dvrDate = curTime;
	m_dvrTime = curTime;
	UpdateData(FALSE);
	//Set HDD operation dropdown menu 
	int nIndex = m_comboOper.AddString(ConvertString("formatting"));
	m_comboOper.SetItemData(nIndex,0);
	nIndex = m_comboOper.AddString(ConvertString("read and write"));
	m_comboOper.SetItemData(nIndex,1);
	nIndex = m_comboOper.AddString(ConvertString("only read"));
	m_comboOper.SetItemData(nIndex,2);
	nIndex = m_comboOper.AddString(ConvertString("set redundancy"));
	m_comboOper.SetItemData(nIndex,3);
	nIndex = m_comboOper.AddString(ConvertString("disk recovery"));
	m_comboOper.SetItemData(nIndex,4);
	nIndex = m_comboOper.AddString(ConvertString("Set Snapshot"));
	m_comboOper.SetItemData(nIndex,5);
	m_comboOper.SetCurSel(0);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CClientDemo7Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CClientDemo7Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CClientDemo7Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//Initialize net SDK
void CClientDemo7Dlg::InitNetSDK()
{
	BOOL ret = CLIENT_Init(DisConnectFunc, (LDWORD)this);
	if (!ret)
	{
		MessageBox(ConvertString("Initialize SDK failed!"), ConvertString("Prompt"));
	}

	NET_PARAM stuNetParam = {0};
	stuNetParam.nConnectTryNum = 2;
	stuNetParam.nGetDevInfoTime = 3000;
	CLIENT_SetNetworkParam(&stuNetParam);
}

//Callback function when device dsiconnected 
void CALLBACK DisConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser)
{
	if(dwUser == 0)
	{
		return;
	}
	CClientDemo7Dlg *dlg = (CClientDemo7Dlg *)dwUser;
	dlg->DeviceDisConnect(lLoginID, pchDVRIP,nDVRPort);
}

//Process when device disconnected 
void CClientDemo7Dlg::DeviceDisConnect(LLONG lLoginID, char *sDVRIP, LONG nDVRPort)
{
	//Add device disconnection process code.
	MessageBox(ConvertString("Network disconnected!"), ConvertString("Prompt"));
}

//Register user to the device 
void CClientDemo7Dlg::OnBtnLogin() 
{
	// TODO: Add your control notification handler code here
	BOOL bValid = UpdateData(TRUE);
	if(bValid)
	{
		int err=0;	//Storage the possible returned error value.
		char *pchDVRIP;
		CString strDvrIP = GetDvrIP();
		pchDVRIP = (LPSTR)(LPCSTR)strDvrIP;
		WORD wDVRPort=(WORD)m_dvrPort;
		char *pchUserName=(LPSTR)(LPCSTR)m_strDvrUserName;
		char *pchPassword=(LPSTR)(LPCSTR)m_strDvrPwd;
		//Device information 
		NET_DEVICEINFO deviceInfo;
		//Call log in interface 
		m_LoginID = CLIENT_Login(pchDVRIP,wDVRPort,pchUserName,pchPassword,&deviceInfo,&err);
		if(0 == m_LoginID)
		{
			//Display log in failure reason 
			ShowLoginErrorReason(err);
		}
		else
		{
			GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(FALSE);
			GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_GET)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_SET)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_RESTART)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_DISKCTRL)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_ALARMSTART)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_ALARMSTOP)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON_OUTALARMSTART)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_OUTALARMSTOP)->EnableWindow(FALSE);
			//Read DVR message
			GetDiskInfo();
			//Set activation alarm channel dropdown menu
			InitComBox((int)deviceInfo.byAlarmInPortNum,(int)deviceInfo.byAlarmOutPortNum);
		}
	}
}

//To get DVR
CString CClientDemo7Dlg::GetDvrIP()
{
	CString strRet="";
	BYTE nField0,nField1,nField2,nField3;
	m_dvrIP.GetAddress(nField0,nField1,nField2,nField3);
	strRet.Format("%d.%d.%d.%d",nField0,nField1,nField2,nField3);
	return strRet;
}

//Display log in failure reason
void CClientDemo7Dlg::ShowLoginErrorReason(int nError)
{
	if(1 == nError)		MessageBox(ConvertString("Invalid password!"), ConvertString("Prompt"));
	else if(2 == nError)	MessageBox(ConvertString("Invalid account!"), ConvertString("Prompt"));
	else if(3 == nError)	MessageBox(ConvertString("Timeout!"), ConvertString("Prompt"));
	else if(4 == nError)	MessageBox(ConvertString("The user has logged in!"), ConvertString("Prompt"));
	else if(5 == nError)	MessageBox(ConvertString("The user has been locked!"), ConvertString("Prompt"));
	else if(6 == nError)	MessageBox(ConvertString("The user has listed into illegal!"), ConvertString("Prompt"));
	else if(7 == nError)	MessageBox(ConvertString("The system is busy!"), ConvertString("Prompt"));
	else if(9 == nError)	MessageBox(ConvertString("You Can't find the network server!"), ConvertString("Prompt"));
	else	MessageBox(ConvertString("Login failed!"), ConvertString("Prompt"));
}

void CClientDemo7Dlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	// Log off 
	if(0 != m_LoginID)
	{
		BOOL bLogout = CLIENT_Logout(m_LoginID);
	}
	//Clear SDK and then release occupied resources. 
	CLIENT_Cleanup();
}

//Log off device user 
void CClientDemo7Dlg::OnBtnLogout() 
{
	// TODO: Add your control notification handler code here
	BOOL bRet = CLIENT_Logout(m_LoginID);
	//Clear log in handle after logged off 
	if(bRet)
	{
		m_LoginID=0;
		m_nCurDiskType = 0;
		GetDlgItem(IDC_BTN_LOGIN)->EnableWindow(TRUE);
		GetDlgItem(IDC_BTN_LOGOUT)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_GET)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_SET)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_RESTART)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_DISKCTRL)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_ALARMSTART)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_ALARMSTOP)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_OUTALARMSTART)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_OUTALARMSTOP)->EnableWindow(FALSE);
	}
	else
	{
		MessageBox(ConvertString("Logout failed!"), ConvertString("Prompt"));
	}
}

//DVR adjusting time 
void CClientDemo7Dlg::OnButtonSet()
{
	// TODO: Add your control notification handler code here
	BOOL bValid = UpdateData(TRUE);
	if(bValid && (0 != m_LoginID))
	{
		NET_TIME curDateTime = {0};
		BOOL bSuccess = ConvertToDateTime(m_CurDate, m_CurTime, curDateTime);
		if (!bSuccess)
		{
			MessageBox(ConvertString("Set failed!"), ConvertString("Prompt"));
			return;
		}

		//Set time 
		bSuccess = CLIENT_SetDevConfig(m_LoginID,DH_DEV_TIMECFG,-1,&curDateTime,sizeof(NET_TIME), DEMO_SDK_WAITTIME);
		if(bSuccess)
		{
			MessageBox(ConvertString("Set successfully!"), ConvertString("Prompt"));
		}
		else
		{
			MessageBox(ConvertString("Set failed!"), ConvertString("Prompt"));
		}
	}
}

//Get DVR time 
void CClientDemo7Dlg::OnButtonGet() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		NET_TIME curDateTime;
		DWORD dwRet = 0;
		//To get time 
		BOOL bSuccess = CLIENT_GetDevConfig(m_LoginID,DH_DEV_TIMECFG,
			-1,&curDateTime,sizeof(NET_TIME),&dwRet, DEMO_SDK_WAITTIME);
		if(bSuccess && (dwRet == sizeof(NET_TIME)))
		{
			int nYear = (int)curDateTime.dwYear;
			int nMonth = (int)curDateTime.dwMonth;
			int nDay = (int)curDateTime.dwDay;
			int nHour = (int)curDateTime.dwHour;
			int nMin = (int)curDateTime.dwMinute;
			int nSec = (int)curDateTime.dwSecond;
			CTime time(nYear,nMonth,nDay,nHour,nMin,nSec,0);
			m_dvrDate = time;
			m_dvrTime = time;
			UpdateData(FALSE);
		}
		else
		{
			MessageBox(ConvertString("Get failed!"), ConvertString("Prompt"));
		}
	}
}

//DVR reboot 
void CClientDemo7Dlg::OnButtonRestart() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_CTRL_REBOOT,NULL, DEMO_SDK_WAITTIME);
		if(bSuccess)
		{
			MessageBox(ConvertString("Reboot device successfully!"), ConvertString("Prompt"));
		}
		else
		{
			MessageBox(ConvertString("Reboot device failed!"), ConvertString("Prompt"));
		}
	}
}

/*
 *	Function��To realize DVR HDD management.
 *	Note��Some series DVR do not support current operation in case there is unauthorized operation resulting in data loss. 
 */
void CClientDemo7Dlg::OnButtonDiskctrl() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		DISKCTRL_PARAM diskParam;
		diskParam.dwSize = sizeof(DISKCTRL_PARAM);
		diskParam.nIndex = m_comboDisk.GetCurSel();

		if (diskParam.nIndex >= 0 && diskParam.nIndex < m_stuDisk.dwDiskNum)
		{
			int nIndex = m_comboOper.GetCurSel();
			diskParam.ctrlType = m_comboOper.GetItemData(nIndex);
			CopyMemory(&diskParam.stuDisk, &m_stuDisk.stDisks[diskParam.nIndex], sizeof(diskParam.stuDisk));

			BOOL bSuccess = 0;
			if (m_nCurDiskType == 0) 
			{
				bSuccess = CLIENT_ControlDevice(m_LoginID,DH_CTRL_DISK,&diskParam, 10000);
			}
			else
			{
				bSuccess = CLIENT_ControlDevice(m_LoginID,DH_CTRL_SDCARD,&diskParam, 10000);
			}
			
			if(bSuccess)
			{
				MessageBox(ConvertString("Control successfully!"), ConvertString("Prompt"));
			}
			else
			{
				MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
			}
		}		
	}
}

//To get HDD alarm 
void CClientDemo7Dlg::GetDiskInfo()
{
	if( 0 != m_LoginID)
	{
		DH_HARDDISK_STATE diskInfo = {0};
		DH_SDCARD_STATE sdInfo = {0};
		int nRetLen = 0;
		DWORD dwDiskNum = 0;
		int i = 0;
		BOOL bSuccess = CLIENT_QueryDevState(m_LoginID,DH_DEVSTATE_DISK,(char *)&diskInfo,
			sizeof(DH_HARDDISK_STATE),&nRetLen, DEMO_SDK_WAITTIME);
		if(bSuccess && (nRetLen == sizeof(DH_HARDDISK_STATE)))
		{
			m_nCurDiskType = 0;
			CopyMemory(&m_stuDisk, &diskInfo, sizeof(m_stuDisk));
		}
		else
		{
			bSuccess =  CLIENT_QueryDevState(m_LoginID, DH_DEVSTATE_SD_CARD, (char*)&sdInfo, sizeof(DH_SDCARD_STATE), &nRetLen, 1000);
			if(bSuccess && (nRetLen == sizeof(DH_HARDDISK_STATE)))
			{
				m_nCurDiskType = 1;
				CopyMemory(&m_stuDisk, &sdInfo, sizeof(m_stuDisk));
			}
			else
			{
				m_nCurDiskType = 0;
			}
		}

		if (bSuccess) 
		{
			if (m_nCurDiskType == 0) //disk
			{
				dwDiskNum = diskInfo.dwDiskNum;
			}
			else
			{
				dwDiskNum = sdInfo.dwDiskNum;
			}

			//Clear dropdown menu 
			m_comboDisk.ResetContent();

			for(i=0;i<(int)dwDiskNum;i++)
			{
				CString str;
				str.Format(ConvertString("disk%d"), i+1);
				m_comboDisk.AddString(str);
			}
			if(0 < m_comboDisk.GetCount())
			{
				m_comboDisk.SetCurSel(0);
			}
		}
		else
		{
			MessageBox(ConvertString("Get device info failed!"), ConvertString("Prompt"));
		}
	}
}

//Begin input activation alarm 
void CClientDemo7Dlg::OnButtonAlarmstart() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		ALARMCTRL_PARAM alarmParam;
		alarmParam.dwSize = sizeof(ALARMCTRL_PARAM);
		alarmParam.nAction = 1;
		int nIndex = m_comboChannel.GetCurSel();
		alarmParam.nAlarmNo = m_comboChannel.GetItemData(nIndex);
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_TRIGGER_ALARM_IN,&alarmParam, DEMO_SDK_WAITTIME);
		if(bSuccess)
		{
			GetDlgItem(IDC_BUTTON_ALARMSTART)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON_ALARMSTOP)->EnableWindow(TRUE);
			MessageBox(ConvertString("Trigger Network Alarm Input successfully!"), ConvertString("Prompt"));
		}
		else
		{
			MessageBox(ConvertString("Trigger Network Alarm Input failed!"), ConvertString("Prompt"));
		}
	}
}

//End input activation alarm 
void CClientDemo7Dlg::OnButtonAlarmstop() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		ALARMCTRL_PARAM alarmParam;
		alarmParam.dwSize = sizeof(ALARMCTRL_PARAM);
		alarmParam.nAction = 0;
		int nIndex = m_comboChannel.GetCurSel();
		alarmParam.nAlarmNo = m_comboChannel.GetItemData(nIndex);
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_TRIGGER_ALARM_IN,&alarmParam, DEMO_SDK_WAITTIME);
		if(bSuccess)
		{
			GetDlgItem(IDC_BUTTON_ALARMSTART)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_ALARMSTOP)->EnableWindow(FALSE);
			MessageBox(ConvertString("Close the Network Alarm Input successfully!"), ConvertString("Prompt"));
		}
		else
		{
			MessageBox(ConvertString("Close the Network Alarm Input failed!"), ConvertString("Prompt"));
		}
	}
}

//Begin output activation alarm 
void CClientDemo7Dlg::OnButtonOutalarmstart() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		ALARMCTRL_PARAM alarmParam;
		alarmParam.dwSize = sizeof(ALARMCTRL_PARAM);
		alarmParam.nAction = 1;
		int nIndex = m_comboOutChannel.GetCurSel();
		alarmParam.nAlarmNo = m_comboOutChannel.GetItemData(nIndex);
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_TRIGGER_ALARM_OUT,&alarmParam, DEMO_SDK_WAITTIME);
		if(bSuccess)
		{
			GetDlgItem(IDC_BUTTON_OUTALARMSTART)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON_OUTALARMSTOP)->EnableWindow(TRUE);
			MessageBox(ConvertString("Trigger Network Alarm Output successfully!"), ConvertString("Prompt"));
		}
		else
		{
			MessageBox(ConvertString("Trigger Network Alarm Output failed!"), ConvertString("Prompt"));
		}
	}
}

//End output activation alarm 
void CClientDemo7Dlg::OnButtonOutalarmstop() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		ALARMCTRL_PARAM alarmParam;
		alarmParam.dwSize = sizeof(ALARMCTRL_PARAM);
		alarmParam.nAction = 0;
		int nIndex = m_comboOutChannel.GetCurSel();
		alarmParam.nAlarmNo = m_comboOutChannel.GetItemData(nIndex);
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_TRIGGER_ALARM_OUT,&alarmParam,DEMO_SDK_WAITTIME);
		if(bSuccess)
		{
			GetDlgItem(IDC_BUTTON_OUTALARMSTART)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON_OUTALARMSTOP)->EnableWindow(FALSE);
			MessageBox(ConvertString("Close the Network Alarm Output successfully!"), ConvertString("Prompt"));
		}
		else
		{
			MessageBox(ConvertString("Close the Network Alarm Output failed!"), ConvertString("Prompt"));
		}
	}
}

//Set dropdown menu 
void CClientDemo7Dlg::InitComBox(int nInChannel, int nOutChannel)
{
	//Set input to activate alarm channel dropdown menu 
	int i = 0;
	m_comboChannel.ResetContent();
	for(i=0;i<nInChannel;i++)
	{
		CString str;
		str.Format(ConvertString("Channel%d"), i);
		m_comboChannel.AddString(str);
		m_comboChannel.SetItemData(i,i);
	}
	if(0 < m_comboChannel.GetCount())
	{
		m_comboChannel.SetCurSel(0);
	}
	//Set output to activate alarm channel dropdown menu 
	m_comboOutChannel.ResetContent();
	for(i=0;i<nOutChannel;i++)
	{
		CString str;
		str.Format(ConvertString("Channel%d"), i);
		m_comboOutChannel.AddString(str);
		m_comboOutChannel.SetItemData(i,i);
	}
	if(0 < m_comboOutChannel.GetCount())
	{
		m_comboOutChannel.SetCurSel(0);
	}
}

//Number0 button
void CClientDemo7Dlg::OnButtonNum0() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_BTN0,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Number 1 button
void CClientDemo7Dlg::OnButtonNum1() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_BTN1,NULL,DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Number 2 button
void CClientDemo7Dlg::OnButtonNum2() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_BTN2,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Number 3 button
void CClientDemo7Dlg::OnButtonNum3() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_BTN3,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Number 4 button
void CClientDemo7Dlg::OnButtonNum4() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_BTN4,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Number 5 button
void CClientDemo7Dlg::OnButtonNum5() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_BTN5,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Number 6 button
void CClientDemo7Dlg::OnButtonNum6() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_BTN6,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Number 7 button
void CClientDemo7Dlg::OnButtonNum7() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_BTN7,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Number 8 button
void CClientDemo7Dlg::OnButtonNum8() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_BTN8,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Number 9 button
void CClientDemo7Dlg::OnButtonNum9() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_BTN9,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Number 10 button
void CClientDemo7Dlg::OnButtonNum10() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_BTN10,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Number 11 button
void CClientDemo7Dlg::OnButtonNum11() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_BTN11,NULL,DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Number 12 button
void CClientDemo7Dlg::OnButtonNum12() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_BTN12,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Number 13 button
void CClientDemo7Dlg::OnButtonNum13() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_BTN13,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"),ConvertString("Prompt"));
		}
	}
}

//Number 14 button
void CClientDemo7Dlg::OnButtonNum14() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_BTN14,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Number 15 button
void CClientDemo7Dlg::OnButtonNum15() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_BTN15,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Number 16 button 
void CClientDemo7Dlg::OnButtonNum16() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_BTN16,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Rec button 
void CClientDemo7Dlg::OnButtonRec() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_REC,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Prew button 
void CClientDemo7Dlg::OnButtonPrew() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_PREW,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Slow button 
void CClientDemo7Dlg::OnButtonSlow() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_SLOW,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Play button 
void CClientDemo7Dlg::OnButtonPlay() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		CString str;
		GetDlgItemText(IDC_BUTTON_PLAY,str);
		if(str == "Play")
		{
			SetDlgItemText(IDC_BUTTON_PLAY,"Pause");
		}
		else
		{
			SetDlgItemText(IDC_BUTTON_PLAY,"Play");
		}
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_PLAY,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Fast button 
void CClientDemo7Dlg::OnButtonFast() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_FAST,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Nextbutton 
void CClientDemo7Dlg::OnButtonNext() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_NEXT,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Stop button 
void CClientDemo7Dlg::OnButtonStop() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_STOP,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//JmpUp button 
void CClientDemo7Dlg::OnButtonJmpup() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_JMPUP,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//JmpDown button 
void CClientDemo7Dlg::OnButtonJmpdown() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_JMPDOWN,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Esc button 
void CClientDemo7Dlg::OnButtonEsc() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_ESC,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Fn1 button 
void CClientDemo7Dlg::OnButtonFn1() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_FN1,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Fn2 button 
void CClientDemo7Dlg::OnButtonFn2() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_FN2,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Up button 
void CClientDemo7Dlg::OnButtonUp() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_UP,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Down button 
void CClientDemo7Dlg::OnButtonDown() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_DOWN,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Left button 
void CClientDemo7Dlg::OnButtonLeft() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_LEFT,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Right button 
void CClientDemo7Dlg::OnButtonRight() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_RIGHT,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Enter button 
void CClientDemo7Dlg::OnButtonEnter() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_ENTER,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Nine button 
void CClientDemo7Dlg::OnButtonNine() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_NINE,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//One button 
void CClientDemo7Dlg::OnButtonOne() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_ONE,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Info button 
void CClientDemo7Dlg::OnButtonInfo() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_INFO,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Addr button 
void CClientDemo7Dlg::OnButtonAddr() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_ADDR,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Split button 
void CClientDemo7Dlg::OnButtonSplit() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_SPLIT,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

//Power button 
void CClientDemo7Dlg::OnButtonPower() 
{
	// TODO: Add your control notification handler code here
	if(0 != m_LoginID)
	{
		BOOL bSuccess = CLIENT_ControlDevice(m_LoginID,DH_KEYBOARD_POWER,NULL, DEMO_SDK_WAITTIME);
		if(!bSuccess)
		{
			MessageBox(ConvertString("Control failed!"), ConvertString("Prompt"));
		}
	}
}

BOOL CClientDemo7Dlg::ConvertToDateTime(const COleDateTime &date, const CTime &time, NET_TIME &curDateTime)
{
	int year = date.GetYear();
	if (year < 2000)
	{
		return FALSE;
	}
	else if (year >= 2100)
	{
		return FALSE;
	}
	else
	{
		curDateTime.dwYear = date.GetYear();
		curDateTime.dwMonth = date.GetMonth();
		curDateTime.dwDay = date.GetDay();
		curDateTime.dwHour = time.GetHour();
		curDateTime.dwMinute = time.GetMinute();
		curDateTime.dwSecond =time.GetSecond();
	}
	
	return TRUE;
}































































