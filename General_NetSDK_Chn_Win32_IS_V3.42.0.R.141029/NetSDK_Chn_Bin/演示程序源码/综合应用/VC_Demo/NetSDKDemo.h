// NetSDKDemo.h : main header file for the NETSDKDEMO application
//

#if !defined(AFX_NETSDKDEMO_H__F984CDA1_DB9B_44E5_ADD8_44A8BB6D6E9D__INCLUDED_)
#define AFX_NETSDKDEMO_H__F984CDA1_DB9B_44E5_ADD8_44A8BB6D6E9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'StdAfx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNetSDKDemoApp:
// See NetSDKDemo.cpp for the implementation of this class
//


//�ϱ����ӿ�
typedef struct 
{
	NET_CLIENT_STATE cState;
	DWORD dError;
	DWORD dFull;
	BYTE  shelter[16];
	BYTE  soundalarm[16];
	BYTE  almDecoder[16];
}DEV_STATE;
/*
//�±����ӿ�
typedef struct 
{
	BYTE	alarmout[16];
	BYTE	motion[16];
	BYTE	videolost[16];
	BYTE	shelter[16];
	BYTE	soundalarm[16];
	BYTE	diskfull;
	BYTE	diskerror[32];
}DEV_STATE;
*/
//�豸��Ϣ�б�ṹ
typedef struct _DeviceNode {
	char UserNanme[20]; //��¼�û���
	char Name[24];   //�豸����
	char IP[20];     //�豸IP��ַ�ַ�
	LONG LoginID;    //�豸��¼iD
	NET_DEVICEINFO Info;  //�豸��Ϣ
	int nChnNum;        //�豸ͨ������ͨ��������255ʱ��¼�ӿڲ���������
	DEV_STATE State; //�豸״̬
	DWORD TotalKbps;     //�豸��ǰ������
	DWORD Max_Kbps;     //���������������
	BOOL	bIsOnline;
}DeviceNode;

//��ǰ������ʾ���ݵ�����
typedef enum _SplitType{
	SPLIT_TYPE_NULL = 0,   //�հ�
	SPLIT_TYPE_MONITOR,    //�������
	SPLIT_TYPE_NETPLAY,    //����ط�
	SPLIT_TYPE_MULTIPLAY,  //����Ԥ��
	SPLIT_TYPE_FILEPLAY,    //�����ļ�����
	SPLIT_TYPE_CYCLEMONITOR,   //��ѭ����
	SPLIT_TYPE_PBBYTIME		//ͨ��ʱ��ط�
}SplitType;

//��Ƶ�����ṹ
typedef union _VideoParam{
		BYTE  bParam[4];
		DWORD dwParam; //��Ƶ����
}VideoParam;

//����ָ�ͨ����ʾ��Ϣ(���Զ����type/param��param�Զ���)
typedef struct _SplitInfoNode
{
	SplitType Type;     //��ʾ���� �հ�/����/����ط�/���ػطŵ�
	DWORD iHandle;  //���ڼ�¼ͨ��id(����ͨ��ID/�����ļ�iD��)
//	DWORD nTimeCount;   //ʱ�����,��������ͳ�� 
//	DWORD nKBPS;       //����ͳ��//sdk���ӽӿں���Ӧ�ò�ͳ��
	int isSaveData;  //�����Ƿ񱣴�(ֱ��sdk����)
	FILE *SavecbFileRaw; //����ص�ԭʼ����
	FILE *SavecbFileStd; //����ص�mp4����
	FILE *SavecbFileYUV; //����ص�yuv����
	FILE *SavecbFilePcm;  //����ص�pcm����
	VideoParam nVideoParam;  //��Ƶ����
	void *Param;  //��Ϣ����,���ڲ�ͬ����ʾ�в�ͬ�Ĳ���
}SplitInfoNode;


class CNetSDKDemoApp : public CWinApp
{
public:
	CNetSDKDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetSDKDemoApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNetSDKDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/*
class CDeviceListProtector //ȫ�ֱ���������
{
public:
	CDeviceListProtector(CPtrList **list):m_ptrdevicelist(list)
	{
		*m_ptrdevicelist = new CPtrList(sizeof(DeviceNode));
		*list = *m_ptrdevicelist;
	}
	~CDeviceListProtector()
	{
		int count = (*m_ptrdevicelist)->GetCount();
		for (int i = 0; i < count; i++)
		{
			delete (DeviceNode *)((*m_ptrdevicelist)->GetTail());
			(*m_ptrdevicelist)->RemoveTail();
		}
		(*m_ptrdevicelist)->RemoveAll();
		delete (*m_ptrdevicelist);
	}
private:
	CPtrList **m_ptrdevicelist;
};

class CCSLock
{
public:
	CCSLock(CRITICAL_SECTION& cs):m_cs(cs)
	{
		EnterCriticalSection(&m_cs);
	}
	
	~CCSLock()
	{
		LeaveCriticalSection(&m_cs);
	}
private:
	CRITICAL_SECTION& m_cs;
};
*/

//extern CRITICAL_SECTION g_cs;

//ȫ�ֱ��������ڱ����������Ŀ¼��·����
extern CString g_strWorkDir;

//ȫ�ֱ��������ڱ����豸�б�
//extern CPtrList  *g_ptrdevicelist ;

//ȫ�ֺ�������ϵͳʱ���ʽת��Ϊ˽�ж��������ʱ���ʽ
void g_systimetoprivatetime(SYSTEMTIME *systime , NET_TIME *privatetime);

//ȫ�ֺ�������˽�ж��������ʱ���ʽת��Ϊϵͳʱ���ʽ
void g_privatetimetosystime(NET_TIME *privatetime , SYSTEMTIME *systime);

//ȫ�ֺ�������˽�ж��������ʱ��ת��Ϊ�ַ�����ʾ
CString g_TimeOutString(NET_TIME *privatetime );

//ȫ�ֺ���, ������ʱ���֮��
DWORD g_IntervalTime(NET_TIME *stime, NET_TIME *etime );

void g_SetWndStaticText(CWnd * pWnd);

TCHAR* g_GetIniPath(void);

CString ConvertString(CString strText);

void ConvertComboBox(CComboBox &stuComboBox);
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETSDKDEMO_H__F984CDA1_DB9B_44E5_ADD8_44A8BB6D6E9D__INCLUDED_)
