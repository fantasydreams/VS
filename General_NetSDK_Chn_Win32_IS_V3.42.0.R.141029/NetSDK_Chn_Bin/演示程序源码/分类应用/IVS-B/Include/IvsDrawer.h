
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the IVSDRAWER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// IVSDRAWER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.

#ifdef IVSDRAWER_EXPORTS
#define IVSDRAWER_API __declspec(dllexport)
#else
#define IVSDRAWER_API __declspec(dllimport)
#endif
#ifndef IVS_DRAWER_H
#define IVS_DRAWER_H



#include <windows.h>
#include <time.h>
#include "dhnetsdk.h"
#include "dhconfigsdk.h"


/*������ʽ��*/
#define DRAW_PEN_SOLID            PS_SOLID
#define DRAW_PEN_DASH             PS_DASH       /* -------  */
#define DRAW_PEN_DOT              PS_DOT       /* .......  */
#define DRAW_PEN_DASHDOT          PS_DASHDOT       /* _._._._  */
#define DRAW_PEN_DASHDOTDOT       PS_DASHDOTDOT      /* _.._.._  */
#define DRAW_PEN_NULL             PS_NULL
#define DRAW_PEN_INSIDEFRAME      PS_INSIDEFRAME
#define DRAW_PEN_USERSTYLE        PS_USERSTYLE
#define DRAW_PEN_ALTERNATE        PS_ALTERNATE
#define DRAW_PEN_DEFAULT		  0xffffffff


#define IVS_DATA_DEFAULT		0xffffffff
#define IVS_MAX_EVENT_NUM 32
#define IVS_MAX_TTL				0xff

enum{
	DRAW_JSON = 0,
		DRAW_TRACK,
		DRAW_ALARM,
		DRAW_RULE,
		DRAW_END = 20
};

enum
{
	IVS_LINGER = 0,				//int 
	IVS_TRACKTAIL,				//�켣β��
	IVS_GET_OBJECT,
	IVS_DISABLE_VIDEO_TIME,		//��ֹ��ƵŨ����ʱ�� INT Ĭ�Ͽ���
	IVS_DISABLE_VIDEO_OBJECT,
	IVS_MODIFY_OBJECT_RGB,		//Dword
	IVS_TRACK_OBJECT,
	IVS_SET_PEN_HEIGHT
};

#define MAX_OBJECT_NUM	16

typedef struct IVS_CONFIG_EVENT
{
	char szEventName[MAX_NAME_LEN];			// �¼�����,���"�¼������б�"
	char szRuleName[MAX_NAME_LEN];			// ��������,��ͬ����������
	DH_MSG_OBJECT		stuObject;
	char		Context[28];
	int		alarmAction;					//netsdkһ��
	int		alarmType;
	
} IVS_CONFIG_EVENT_INFO;

typedef struct IVS_CONFIG_EVENTEX
{
	char szEventName[MAX_NAME_LEN];			// �¼�����,���"�¼������б�"
	char szRuleName[MAX_NAME_LEN];			// ��������,��ͬ����������
	char Context[28];					
	int		alarmAction;					//netsdkһ��				
	int		alarmType;
	int					nObjectNum;
	DH_MSG_OBJECT		stuObject[MAX_OBJECT_NUM];						// ��⵽������
	int					nContext;
	void*				pContext;
} IVS_CONFIG_EVENT_INFOEX;

typedef struct 
{
	int					nEventsNum;								// ��Ƶ����������
	IVS_CONFIG_EVENT_INFO stuEventInfo[IVS_MAX_EVENT_NUM]; //�¼���Ϣ
	
} IVS_CFG_ANALYSEVENTS_INFO;

typedef struct 
{
	int					nEventsNum;								// ��Ƶ����������
	IVS_CONFIG_EVENT_INFOEX stuEventInfo[IVS_MAX_EVENT_NUM]; //�¼���Ϣ
	
} IVS_CFG_ANALYSEVENTS_INFOEX;


typedef struct
{
	int objectid;
	struct tm startTime;
	struct tm endTime;
	char	cReverd[12];
}IVSOBJECT;

union ObjectContex
{
	IVSOBJECT object;
	POINT	  xPt;
};


#define CALLMETHOD __stdcall

#ifdef __cplusplus
extern "C" {
#endif

IVSDRAWER_API int CALLMETHOD DRAW_Startup();

IVSDRAWER_API void CALLMETHOD DRAW_Cleanup();

//------------------------------------------------------------------------
// ����: DRAW_Open
// ����: ����ͼ
// ����: nPort,��ͼ�˿�.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
IVSDRAWER_API BOOL CALLMETHOD DRAW_Open(int nPort);

//------------------------------------------------------------------------
// ����: DRAW_Close
// ����: �ر���ͼ
// ����: nPort,��ͼ�˿�.
// ����: void
//------------------------------------------------------------------------
IVSDRAWER_API void CALLMETHOD DRAW_Close(int nPort);

//------------------------------------------------------------------------
// ����: DRAW_Reset
// ����: ������ͼ
// ����: nPort,��ͼ�˿�.
// ����: BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
//------------------------------------------------------------------------
IVSDRAWER_API BOOL CALLMETHOD DRAW_Reset(int nPort,int type);

//------------------------------------------------------------------------
// ����: DRAW_InputJsonData
// ����: ����Json��ʽ������֡����.
// ����: nPort,��ͼ�˿�.
//		 pJsonData,json�ַ���
//		 nDataLen,json�ַ����ĳ���
// ����: int,С��0ʧ��,����DRAW_GetLastError��ѯʧ�ܴ�����;������ʾ�ɹ�.
//------------------------------------------------------------------------
IVSDRAWER_API int  CALLMETHOD DRAW_InputJsonData(int nPort, unsigned char* pJsonData, int nDataLen,int nFrame);



//------------------------------------------------------------------------
// ����: DRAW_InputRuleData
// ����: �����������.
// ����: nPort,��ͼ�˿�.
//		 nType,����:
//		 pRuleData,�������ݽṹ��
//		 nDataLen,���ݳ���
// ����: int,С��0ʧ��,����DRAW_GetLastError��ѯʧ�ܴ�����;������ʾ�ɹ�.
//------------------------------------------------------------------------
IVSDRAWER_API int  CALLMETHOD DRAW_InputRuleData(int nPort, int nType, unsigned char* pRuleData, int nDataLen);

//------------------------------------------------------------------------
// ����: DRAW_InputTrackData
// ����: ����켣����.
// ����: nPort,��ͼ�˿�.
//		 nType,����,�켣��Ϣ�����ֽṹ������.
//		 pTrackData,�켣���ݽṹ��
//		 nDataLen,���ݳ���
//       nFrameNum ��Ƶ֡��
// ����: int,С��0ʧ��,����DRAW_GetLastError��ѯʧ�ܴ�����;������ʾ�ɹ�.
//------------------------------------------------------------------------
IVSDRAWER_API int  CALLMETHOD DRAW_InputTrackData(int nPort, int nType, unsigned char* pTrackData, int nDataLen,int nFrameNum);


//------------------------------------------------------------------------
// ����: DRAW_InputAlarmData
// ����: ���뱨������.
// ����: nPort,��ͼ�˿�.
//		 nType,����,�켣��Ϣ�����ֽṹ������.
//		 pAlarmData,�������ݽṹ��
//		 nDataLen,���ݳ���
// ����: int,С��0ʧ��,����DRAW_GetLastError��ѯʧ�ܴ�����;������ʾ�ɹ�.
//------------------------------------------------------------------------
IVSDRAWER_API int  CALLMETHOD DRAW_InputAlarmData(int nPort, int nType, unsigned char* pAlarmData, int nDataLen);

//------------------------------------------------------------------------
// ����: DRAW_InputAlarmData
// ����: ���뱨������.
// ����: nPort,��ͼ�˿�.
//		 nType,����,�켣��Ϣ�����ֽṹ������.
//		 pAlarmData,�������ݽṹ��
//		 nDataLen,���ݳ���
// ����: int,С��0ʧ��,����DRAW_GetLastError��ѯʧ�ܴ�����;������ʾ�ɹ�.
//------------------------------------------------------------------------
IVSDRAWER_API int  CALLMETHOD DRAW_InputAlarmDataEx(int nPort, int nType, unsigned char* pAlarmData, int nDataLen);

//------------------------------------------------------------------------
// ����: DRAW_Draw
// ����: ��ͼ.
// ����: nPort,��ͼ�˿�.
//		 hDC,��ͼ�����ľ��
// ����: int,С��0ʧ��,����DRAW_GetLastError��ѯʧ�ܴ�����;������ʾ�ɹ�.
//------------------------------------------------------------------------
IVSDRAWER_API int  CALLMETHOD DRAW_Draw(int nPort, HDC hDC,HWND hwnd,int nFrameNum);

//------------------------------------------------------------------------
// ����: DRAW_SetLifeCount
// ����: ���ù켣��������.
// ����: nPort,��ͼ�˿�.
//		 nLifeCount,��������
// ����: int,С��0ʧ��,����DRAW_GetLastError��ѯʧ�ܴ�����;������ʾ�ɹ�.
//------------------------------------------------------------------------
IVSDRAWER_API int  CALLMETHOD DRAW_SetLifeCount(int nPort, int type,int nLifeCount);

//------------------------------------------------------------------------
// ����: DRAW_SetEnable
// ����: ����ʹ��.
// ����: nPort,��ͼ�˿�.
//		 nType,����
//		 bEnable,ʹ��
// ����: int,С��0ʧ��,����DRAW_GetLastError��ѯʧ�ܴ�����;������ʾ�ɹ�.
//------------------------------------------------------------------------
IVSDRAWER_API int  CALLMETHOD DRAW_SetEnable(int nPort, int nType, BOOL bEnable);

//------------------------------------------------------------------------
// ����: DRAW_SetPen
// ����: ������ͼ����.
// ����: nPort,��ͼ�˿�.
//		 nType,����
//		 nPenStyle,������ʽ,��"������ʽ��"
//		 nWidth,���ʿ��
//		 crColor,������ɫ		 
// ����: int,��=0ʧ��,����DRAW_SetPen��ѯʧ�ܴ�����;������ʾ�ɹ�.
//------------------------------------------------------------------------
IVSDRAWER_API int  CALLMETHOD DRAW_SetPen(int nPort, int nType, int nPenStyle, int nWidth, COLORREF crColor);

//------------------------------------------------------------------------
// ����: DRAW_GetLastError(Ŀǰ��֧��)
// ����: ��ȡ���Ĵ�����
// ����: nPort,��ͼ�˿�.	 
// ����: int,���ش�����.
//------------------------------------------------------------------------
IVSDRAWER_API int  CALLMETHOD DRAW_GetLastError(int nPort);

//------------------------------------------------------------------------
// ����: DRAW_Ioctl
// ����: 
// ����: nPort,��ͼ�˿�.	
//		cmdType �����
//		context ���Ӧ�ṹ���ַ
//		len		�ṹ��ĳ���
// ����: int,���ش�����.
//------------------------------------------------------------------------
IVSDRAWER_API int  CALLMETHOD DRAW_Ioctl(int nPort,int cmdType,void* context,int len);


//------------------------------------------------------------------------
// ����: DRAW_InputJpegData
// ����: ��ȡ���Ĵ�����
// ����: nPort,��ͼ�˿�.	
// ����: int,���ش�����.
//------------------------------------------------------------------------
IVSDRAWER_API int  CALLMETHOD DRAW_InputJpegData(int nPort, int nType, unsigned char* pJpegData, int nDataLen,int nFrameNum);



//------------------------------------------------------------------------
// ����: DRAW_Idle
// ����: 
// ����: nPort,��ͼ�˿�.	
// ����: void
IVSDRAWER_API void CALLMETHOD DRAW_Idle(int nPort);

#ifdef __cplusplus
}
#endif

#endif