// DevMgr.h: interface for the CDevMgr class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _DEVMGR_H_
#define _DEVMGR_H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "NetSDKDemo.h"
#pragma warning(disable:4786)
#include <list>

using namespace std;

typedef struct 
{
	LONG alarmType;
	DEV_STATE state;
	CTime	timeStamp;
}AlarmNode;

class CDevMgr  
{
public:

	/*
	//�豸��Ϣ�б�ṹ
	typedef struct _DeviceNode {
		char UserNanme[20]; //��¼�û���
		char Name[20];   //�豸����
		char IP[20];     //�豸IP��ַ�ַ�
		LONG LoginID;    //�豸��¼iD
		NET_DEVICEINFO Info;  //�豸��Ϣ
		NET_CLIENT_STATE State; //�豸״̬
		DWORD TotalKbps;     //�豸��ǰ������
		DWORD Max_Kbps;     //���������������
	}DeviceNode;
	*/

	class SearchDevByHandle;
	friend class SearchDevByHandle;

public:
	CDevMgr();
	~CDevMgr();

	static CDevMgr& GetDevMgr(void);

	//protected copy object
private:
	CDevMgr(const CDevMgr&);
	CDevMgr& operator=(const CDevMgr&);

public:

	//����ڵ�
	int  PushBack(DeviceNode* node);
	
	//ɾ���ڵ�
	int  DelNode(LONG lLoginID);

	//�޸Ľڵ�
	int	 ModifyNode(LONG lLoginID, BOOL bIsOnline);

	//�ص���������ֵ˵����1 ����ö�٣� 0 ����ö��
	void For_EachDev(int (* cbForEach)(const DeviceNode& node, DWORD dwUser), DWORD dwUser);

	//�ص���������ֵ˵����1 ����ö�٣� 0 ����ö��
	void For_EachAlmNode(int (* cbForEachAlm)(const AlarmNode& node, DWORD dwUser), DWORD dwUser);
	
	//���ص����ݲ��������ñ��棬�´�Ҫ���»�ȡ
	int  GetDev(LONG lLoginID, DeviceNode& node);

	//д��ص������ı�������
	int SetAlarmInfo(LONG lLoginID, LONG lCommand, char *pchDVRIP, LONG nDVRPort, 
						  char *pBuf, DWORD dwBufLen);
	int CDevMgr::GetAlarmInfo(LONG lLoginID, DEV_STATE *des);

	BOOL IsOnline(LONG lLoginID);

	BOOL IsOnline(DeviceNode* node);

private:

	list<DeviceNode*> m_lstDevice;
	list<AlarmNode*> m_lstAlarm;
	CRITICAL_SECTION  m_csDev;
	CRITICAL_SECTION  m_csAlarm;
	CRITICAL_SECTION  m_csAlmList;
};

class CDevMgr::SearchDevByHandle
{
	LONG m_lLoginID;
public:
	SearchDevByHandle(const LONG& lLoginID):m_lLoginID(lLoginID){}

	bool operator()(const DeviceNode*& node)
	{
		if (!node)
		{
			return false;
		}

		return (m_lLoginID==node->LoginID)?true:false;
	}
};

#endif // _DEVMGR_H_
