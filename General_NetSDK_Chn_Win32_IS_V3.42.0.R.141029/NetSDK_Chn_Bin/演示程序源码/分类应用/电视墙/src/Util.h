#ifndef _DEMO_MATRIX_UTIL_H_
#define _DEMO_MATRIX_UTIL_H_

#pragma warning(disable: 4786)
#include <map>
#include <vector>
#include <list>
#include "LanguageManager.h"

#include "../lib/dhnetsdk.h"
#pragma comment(lib, "../lib/dhnetsdk.lib")

#include "../lib/dhconfigsdk.h"
#pragma comment(lib, "../lib/dhconfigsdk.lib")

#ifndef _countof
#define _countof(array)		sizeof(array) / sizeof(array[0])
#endif

#define APP_NAME			"DemoMonitorWall"
#define MAX_RECT_VALUE		8192.0

#define ID_MENU_GROUP_ID	13500

#define WAIT_TIME			5000

//**********************************************************************
// �ṹ����
//**********************************************************************

enum
{
	TREE_ITEM_DEVICE,			// �豸���
	TREE_ITEM_CHANNEL,			// ͨ�����
};

class CEncoder;
// �ڵ���Ϣ
struct TreeItemData
{
	UINT					uItemType;					// �������
	CEncoder*				pDevice;					// �豸��Ϣ
	int						nChannel;					// ͨ����Ϣ, ͨ�������Ч

	TreeItemData(UINT uType = TREE_ITEM_DEVICE, CEncoder* pDev = NULL, int nChn = -1)
		: uItemType(uType)
		, pDevice(pDev)
		, nChannel(nChn)
	{
	}

	virtual bool operator==(const TreeItemData& other)
	{
		return other.uItemType == uItemType
			&& other.pDevice == pDevice
			&& other.nChannel == nChannel;
	}
};

struct TreeItemDataDscon : public TreeItemData
{
	int					nInputType;		// 0-analogMatrix, 1-remoteDevice
	char				szDevID[128];	// analogMatrixID or remoteDeviceID

	TreeItemDataDscon(int _nInputType, const char* szName, CEncoder* pDev = NULL, int nChn = -1)
		: TreeItemData(TREE_ITEM_CHANNEL, pDev, nChn)
		, nInputType(_nInputType)
	{
		ZeroMemory(szDevID, sizeof(szDevID));
		strncpy(szDevID, szName, min(strlen(szName), sizeof(szDevID) - 1));
	}
};

//**********************************************************************
// MesssageBox
//**********************************************************************
int MsgBoxFmt( HWND hWnd, UINT uType, LPCTSTR lpszCaption, LPCTSTR lpszTextFmt, ... );
int _MsgBoxErr(HWND hWnd, UINT uType, LPCTSTR lpszCaption, LPCTSTR lpszMsg);

#define MsgBox0(str)					MsgBoxFmt(m_hWnd, MB_ICONINFORMATION, LMIC("Prompt"), LMIC(str))
#define MsgBox1(str, p1)				MsgBoxFmt(m_hWnd, MB_ICONINFORMATION, LMIC("Prompt"), LMIC(str), p1)
#define MsgBox2(str, p1, p2)			MsgBoxFmt(m_hWnd, MB_ICONINFORMATION, LMIC("Prompt"), LMIC(str), p1, p2)
#define MsgBox3(str, p1, p2, p3)		MsgBoxFmt(m_hWnd, MB_ICONINFORMATION, LMIC("Prompt"), LMIC(str), p1, p2, p3)
#define MsgBox4(str, p1, p2, p3, p4)	MsgBoxFmt(m_hWnd, MB_ICONINFORMATION, LMIC("Prompt"), LMIC(str), p1, p2, p3, p4)
#define MsgBox							MsgBox0
#define MsgBoxErr(str)					_MsgBoxErr(m_hWnd, MB_ICONINFORMATION, LMIC("Prompt"), str)


#endif
