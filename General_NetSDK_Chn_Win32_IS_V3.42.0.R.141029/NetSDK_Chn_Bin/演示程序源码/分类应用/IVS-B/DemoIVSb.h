// DemoIVSb.h : main header file for the DEMOIVSB application
//

#if !defined(AFX_DEMOIVSB_H__902FE451_4E3D_4E43_9666_B8FD7A29EF56__INCLUDED_)
#define AFX_DEMOIVSB_H__902FE451_4E3D_4E43_9666_B8FD7A29EF56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#include <list>

#include "PlayApi.h"

#include "Include/IvsDrawer.h"
#pragma comment(lib, "Lib/IvsDrawer.lib")
//////////////////////////////////////////////////////////////////////////

#define WM_CLEARINFO		(WM_USER + 99)

#define WM_ZONEDONE			(WM_USER + 100)	//����ȫ�ֱ궨����/�����ɺ�֪ͨ������
#define WM_REGIONDONE		(WM_USER + 101)	//����ģ��������/�ų�������ɺ�֪ͨ��������
#define WM_RULEDONE			(WM_USER + 102)	//�����ͼ��ɺ�֪ͨ��������

#define WM_USER_ALAMR_COME	(WM_USER + 200)	//�ص�������Ϣ

//total channel count supported by device
const int g_MaxChannelCount = 64;


//decode port num
const int g_nPlayPort = 450;

//draw port num for preview
const int g_nPreviewDrawPort = 300;

//draw port num for RuleCfg
const int g_nRuleCfgDrawPort = 400;

// For Loading PlaySDK dynamically
extern CPlayAPI s_PlayAPI;

//////////////////////////////////////////////////////////////////////////
// Custom info for Global Config
//ȫ�����ý���궨�������ؼ��ϵĽڵ�󶨵���Ϣ����
const int nNodeArea = 0;
const int nStaffHor = 1;
const int nStaffVer = 2;

//���ڵ�����
typedef struct tagGTNodeType
{
	int	nNodeType;		//�ڵ����ͣ�������򣬱��
	
	tagGTNodeType()
	{
		nNodeType = -1;
	}
	
	~tagGTNodeType()
	{
		nNodeType = -1;
	}
}GTNODETYPE;

//�궨����ڵ�
typedef struct tagGTNodeArea
{
	int						nNodeType;
	CFG_CALIBRATEAREA_INFO	CfgCalibrateAreaInfo;
	
	tagGTNodeArea()
	{
		nNodeType = -1;
		ZeroMemory(&CfgCalibrateAreaInfo,
			sizeof(CfgCalibrateAreaInfo));
	}
}GTNODEAREA;

//��߽ڵ�
typedef struct tagGTNodeStaff
{
	int			nNodeType;
	CFG_STAFF	CfgStaff;
	
	tagGTNodeStaff()
	{
		nNodeType = -1;
		ZeroMemory(&CfgStaff, sizeof(CfgStaff));
	}
}GTNODESTAFF;

//////////////////////////////////////////////////////////////////////////
// Custom info for Rule Config
//ÿ������Ĵ洢�ṹ��
typedef struct tagRuleStruct
{
	CFG_RULE_INFO RuleInfo;
	char* pRuleBuf;
	
	tagRuleStruct()
	{
		ZeroMemory(&RuleInfo, sizeof(RuleInfo));
		pRuleBuf = NULL;
	}

	~tagRuleStruct()
	{
		ZeroMemory(&RuleInfo, sizeof(RuleInfo));
		if (pRuleBuf)
		{
			delete pRuleBuf;
			pRuleBuf = NULL;
		}
	}
}RuleStruct;

//�����ص������ṹ��
typedef struct tagEventPara
{
	LLONG	lAnalyzerHandle;
	DWORD	dwAlarmType;
	void*	pAlarmInfo;
	BYTE*	pBuffer;
	DWORD	dwBufSize;
	int		nSequence;
}EventPara;

//������Ϣ�ṹ��
typedef struct tagAlarmInfoNode
{
	int nChnNum;
	char szAlarmName[128];
	DWORD dwRuleType;
	NET_TIME_EX Time;
	TCHAR szFile[MAX_PATH];

	tagAlarmInfoNode()
	{
		nChnNum = -1;
		ZeroMemory(szAlarmName, sizeof(szAlarmName));
		dwRuleType = -1;
		ZeroMemory(&Time, sizeof(Time));
		ZeroMemory(szFile, sizeof(szFile));
	}
}AlarmInfoNode;

//������Ϣ�������տͻ����յ����Ⱥ�˳���������
typedef	std::list<AlarmInfoNode*> lsAlarmInfo;

//////////////////////////////////////////////////////////////////////////

template<class T> 
void setRuleEnableTime(T* pRule)
{
	if (!pRule)
	{
		return;
	}

	// ÿ��7�죬ÿ��6��ʱ��Σ�ֻ�������õ�ʱ�䷶Χ�ڣ�����ʹ�ܣ��������Ч��
	for (int i = 0; i < WEEK_DAY_NUM; i++)
	{
		pRule->stuTimeSection[i][0].dwRecordMask = 1;
		pRule->stuTimeSection[i][0].nBeginHour = 0;
		pRule->stuTimeSection[i][0].nBeginMin = 0;
		pRule->stuTimeSection[i][0].nBeginSec = 0;
		pRule->stuTimeSection[i][0].nEndHour = 23;
		pRule->stuTimeSection[i][0].nEndMin = 59;
		pRule->stuTimeSection[i][0].nEndSec = 59;
	}
}

//////////////////////////////////////////////////////////////////////////
//function: RealDataCallBackEx
//describe: callback to get buffer
//param: 
//return: 
//////////////////////////////////////////////////////////////////////////
void CALLBACK RealDataCallBackEx(LLONG lRealHandle,
								 DWORD dwDataType, 
								 BYTE *pBuffer,
								 DWORD dwBufSize, 
								 LONG lParam, 
								 LDWORD dwUser);

//////////////////////////////////////////////////////////////////////////
//function: ConvertString
//describe: convert GUI text
//param: 
//return: 
//////////////////////////////////////////////////////////////////////////
CString ConvertString(CString strText);

//////////////////////////////////////////////////////////////////////////
//function: g_SetWndStaticText
//describe: convert static wnd text
//param: 
//return: 
//////////////////////////////////////////////////////////////////////////
void  g_SetWndStaticText(CWnd * pWnd);

//////////////////////////////////////////////////////////////////////////
//function: g_getStructSize
//describe: get configuration struct size of ruletype
//param: 
//return: 
//////////////////////////////////////////////////////////////////////////
int g_getStructSize(int IN nRuleType);

//////////////////////////////////////////////////////////////////////////
//function: g_convertRuleTypeToString
//describe: convert ruletype to its name
//param: 
//return: 
//////////////////////////////////////////////////////////////////////////
CString g_convertRuleTypeToString(DWORD IN dwType);

//////////////////////////////////////////////////////////////////////////
//function: g_ConvertRuleTypeToStructSize
//describe: get struct size of ruletype, used for configuration struct
//param: 
//return: 
//////////////////////////////////////////////////////////////////////////
// int g_ConvertRuleTypeToStructSize(DWORD dwType);

//////////////////////////////////////////////////////////////////////////
//function: g_getStructInfo
//describe: get alarm struct size of ruletype
//param: 
//return: 
//////////////////////////////////////////////////////////////////////////
int g_getStructInfo(DWORD dwAlarmType);


//////////////////////////////////////////////////////////////////////////
// smart guard
class CGuard
{
public:
	CGuard(CRITICAL_SECTION* pCS)
		:m_lock(pCS)
	{
		EnterCriticalSection(m_lock);
	}
	virtual ~CGuard()
	{
		LeaveCriticalSection(m_lock);
	}

private:
	CRITICAL_SECTION* m_lock;
};

/////////////////////////////////////////////////////////////////////////////
// CDemoIVSbApp:
// See DemoIVSb.cpp for the implementation of this class
//

class CDemoIVSbApp : public CWinApp
{
public:
	CDemoIVSbApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoIVSbApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDemoIVSbApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOIVSB_H__902FE451_4E3D_4E43_9666_B8FD7A29EF56__INCLUDED_)
