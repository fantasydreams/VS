// NetSDKDemo.cpp : Defines the class behaviors for the application.
//

#include "StdAfx.h"
#include "NetSDKDemo.h"
#include "NetSDKDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//��̬�豸��Ϣ�б�ָ�룻
//CRITICAL_SECTION g_cs;
//CPtrList    *g_ptrdevicelist;
//CDeviceListProtector dlp(&g_ptrdevicelist);
//SplitInfoNode g_splitinfo[MAX_CHANNUM];
CString g_strWorkDir;
/////////////////////////////////////////////////////////////////////////////
// CNetSDKDemoApp

BEGIN_MESSAGE_MAP(CNetSDKDemoApp, CWinApp)
	//{{AFX_MSG_MAP(CNetSDKDemoApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNetSDKDemoApp construction

CNetSDKDemoApp::CNetSDKDemoApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CNetSDKDemoApp object

CNetSDKDemoApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CNetSDKDemoApp initialization

BOOL CNetSDKDemoApp::InitInstance()
{
//	InitializeCriticalSection(&g_cs);
	AfxEnableControlContainer();

//	memset((char *)g_splitinfo, 0, sizeof(g_splitinfo));
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
	
	CNetSDKDemoDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

//�Զ���ȫ�ֺ���
void g_systimetoprivatetime(SYSTEMTIME *systime , NET_TIME *privatetime)
{
	privatetime->dwYear = (DWORD)systime->wYear;
	privatetime->dwMonth = (DWORD)systime->wMonth;
	privatetime->dwDay = (DWORD)systime->wDay;
	privatetime->dwHour = (DWORD)systime->wHour;
	privatetime->dwMinute = (DWORD)systime->wMinute;
	privatetime->dwSecond = (DWORD)systime->wSecond;
}

//�Զ���ȫ�ֺ���
void g_privatetimetosystime(NET_TIME *privatetime , SYSTEMTIME *systime)
{
	systime->wYear = (WORD)privatetime->dwYear;
	systime->wMonth = (WORD)privatetime->dwMonth;
	systime->wDay = (WORD)privatetime->dwDay;
	systime->wHour = (WORD)privatetime->dwHour;
	systime->wMinute = (WORD)privatetime->dwMinute;
	systime->wSecond = (WORD)privatetime->dwSecond;
}

//�Զ���ȫ�ֺ���
CString g_TimeOutString(NET_TIME *privatetime )
{
	CString nStr;

	nStr.Format("%04d-%02d-%02d %02d:%02d:%02d", privatetime->dwYear,privatetime->dwMonth,privatetime->dwDay,
		privatetime->dwHour, privatetime->dwMinute, privatetime->dwSecond);

	return nStr;
}

//�Զ���ȫ�ֺ���
DWORD g_IntervalTime(NET_TIME *stime, NET_TIME *etime )
{
	if(*((DWORD *)&stime) > *((DWORD *)&etime))
	{
		return 0;
	}

	//ֻ����������һ�����ʱ���,����һ����һ���
	DWORD sSec = stime->dwHour * 3600 + stime->dwMinute *60 + stime->dwSecond;
	DWORD eSec = etime->dwHour * 3600 + etime->dwMinute *60 + etime->dwSecond;

	if(sSec > eSec)
	{
		sSec += 3600 * 24;
	}
	return (eSec - sSec);
}

//��ȡ����·��
//���ļ��Ի���󣬵�ǰ·���ᷢ���仯��������Ҫ��ʼ���Ի����ʱ�򱣴�·��
TCHAR* g_GetIniPath(void)
{
	static TCHAR* pszIniPath = NULL;//��ָ�����׳�ʼ��,
	if( NULL == pszIniPath)
	{
		TCHAR szDirBuf[512] = {0};
		pszIniPath = new TCHAR[512];//���ͷž��ڴ�й¶
		memset(pszIniPath, 0, 512);
		GetCurrentDirectory(512, szDirBuf);
		sprintf(pszIniPath, "%s\\langchn.ini", szDirBuf);
	}
	return pszIniPath;
}

//��Ӣ���ַ�����ת��Ϊ����ǰ�������͵��ַ�����
CString ConvertString(CString strText)
{
	char *val = new char[200];
	CString strIniPath,strRet;

	memset(val,0,200);
	GetPrivateProfileString("String", strText, "", val, 200, g_GetIniPath());
	strRet = val;
	if(strRet.GetLength()==0)
	{
		//���ini�ļ��в����ڶ�Ӧ���ַ���������ΪĬ��ֵ��Ӣ�ģ�
		strRet=strText;
	}
	delete val;
	return strRet;
}
//���öԻ����еľ�̬�ı�(Ӣ��-->��ǰ����)   
void g_SetWndStaticText(CWnd * pWnd)
{
	CString strCaption,strText;

	//���������ڵı���
	pWnd->GetWindowText(strCaption);
	if(strCaption.GetLength()>0)
	{
		strText=ConvertString(strCaption);
		pWnd->SetWindowText(strText);
	}

	//�����Ӵ��ڵı���
	CWnd * pChild=pWnd->GetWindow(GW_CHILD);
	CString strClassName;
	while(pChild)
	{
		//////////////////////////////////////////////////////////////////////////		
		//Added by Jackbin 2005-03-11
		strClassName = ((CRuntimeClass*)pChild->GetRuntimeClass())->m_lpszClassName;
		if(strClassName == "CEdit")
		{
			//��һ���Ӵ���
			pChild=pChild->GetWindow(GW_HWNDNEXT);
			continue;
		}

		//////////////////////////////////////////////////////////////////////////	

		//�����Ӵ��ڵĵ�ǰ�����ı�
		pChild->GetWindowText(strCaption);
		strText=ConvertString(strCaption);
		pChild->SetWindowText(strText);

		//��һ���Ӵ���
		pChild=pChild->GetWindow(GW_HWNDNEXT);
	}
}
/*
 *	��Ͽ�����ת��
 */
void ConvertComboBox(CComboBox &stuComboBox)
{
	int nCount = stuComboBox.GetCount();
	if(nCount <= 0)
	{
		return;
	}
	CString* strText = new CString[nCount];
	for(int i = 0; i < nCount;i++)
	{
		stuComboBox.GetLBText(i, strText[i]);
		strText[i] = ConvertString(strText[i]);
	}
	stuComboBox.ResetContent();
	for(i = 0; i< nCount; i++)
	{
		stuComboBox.AddString(strText[i]);
	}
	delete []strText;
}

int CNetSDKDemoApp::ExitInstance() 
{
//	DeleteCriticalSection(&g_cs);
	return CWinApp::ExitInstance();
}
