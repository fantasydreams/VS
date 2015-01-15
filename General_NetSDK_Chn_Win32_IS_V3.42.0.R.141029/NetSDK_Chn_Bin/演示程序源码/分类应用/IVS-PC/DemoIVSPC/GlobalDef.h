#ifndef __IVS_GLOBAL_DEF_H__
#define __IVS_GLOBAL_DEF_H__

#include <list>
using namespace std;



/// ���ƹ���״̬
/// \enum  __eRULESTATE
typedef enum __eRULESTATE
{
	eStateNull = 0,    ///<��״̬
	eRegionStart,      ///<��ʼ������
	eRegionNext,       ///<���������һ����
	eRegionEnd,        ///<���������
	eDirctionStart,    ///<��ʼ������
	eDirctionEnd,      ///<���������
	eStateNum
}eRuleState;

#define  WM_RULE_DRAW            (WM_USER+300)   /// ��������Ϣ
#define  WM_UPDATE_NOTIFY        (WM_USER+400)   /// ���ݸ���֪ͨ

typedef enum _ARROW_DIRECTION_TYPE
{
	ARROW_UP = 0,
	ARROW_DOWN,
	ARROW_LEFT,
	ARROW_RIGHT
}ARROW_DIRECTION_TYPE, *PARROW_DIRECTION_TYPE;

typedef enum __ModuleDrawState
{
	DetectZone = 1, // �������
	ExcludeZone		// �ų�����

}ModuleDrawState;



typedef enum __LoginState
{
	LoginSucc = 1,	// ��½�ɹ�
	LoginFailed ,	// ��½ʧ��
	LogOut,			// �ǳ�
	LoginOpenView,	// �򿪼���ͨ��	

}LoginState;




//////////////////////////////////////////////////////////////////////////

#define WM_ZONEDONE			(WM_USER + 100)	//����ȫ�ֱ궨����/�����ɺ�֪ͨ������
#define WM_REGIONDONE		(WM_USER + 101)	//����ģ��������/�ų�������ɺ�֪ͨ��������
#define WM_USER_ALAMR_COME	(WM_USER + 200)	//�ص�������Ϣ


#define PEN_WIDTH 1 // ���ʵĿ��

/////////////////////////////////////////////////////////////////////////////





//һ̨�豸�������ͨ����
const int g_MaxChannelCount = 32;

//decode port num
const int g_nPlayPort = 450;

//draw port num for preview
const int g_nPreviewDrawPort = 300;

//draw port num for RuleCfg
const int g_nRuleCfgDrawPort = 400;

//////////////////////////////////////////////////////////////////////////

//ȫ�����ý���궨�������ؼ��ϵĽڵ�󶨵���Ϣ����



const int nNodeArea = 0;
const int nStaffHor = 1;
const int nStaffVer = 2;

//���ڵ�����
typedef struct tagGTNodeType
{
	int	nNodeType;		//�ڵ����ͣ�������򣬱��
}GTNODETYPE;

//�궨����ڵ�
typedef struct tagGTNodeArea
{
	int						nNodeType;
	CFG_CALIBRATEAREA_INFO	CfgCalibrateAreaInfo;
}GTNODEAREA;

//��߽ڵ�
typedef struct tagGTNodeStaff
{
	int			nNodeType;
	CFG_STAFF	CfgStaff;
}GTNODESTAFF;

//////////////////////////////////////////////////////////////////////////

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

//һ��ͨ���Ĺ����б�
typedef std::list<RuleStruct*> lsRuleList;

//�����¼����ؼ�CRuleTreeCtrl�Ͻڵ�󶨵���Ϣ
typedef struct tagRuleNodeInfo
{
	int nChnNum;		//ͨ����
	BOOL bEnPic;		//�Ƿ���ͼƬ	
	DWORD sRuleType;	//��������

	tagRuleNodeInfo()
	{
		nChnNum = -1;
		bEnPic = FALSE;
		sRuleType = 0;
	}
}RuleNodeInfo;
//Ҫ/�ڼ��Ĺ��������б�
typedef std::list<RuleNodeInfo*> vecRULE;


//�����ص������ṹ��
typedef struct tagEventPara
{
	LONG lAnalyzerHandle;
	DWORD dwAlarmType;
	void* pAlarmInfo;
	BYTE *pBuffer;
	DWORD dwBufSize;
	int nSequence;
}EventPara;

//������Ϣ�ṹ��
typedef struct tagAlarmInfoNode
{
	int nChnNum;
	DWORD dwRuleType;
	NET_TIME_EX Time;
	TCHAR szFile[MAX_PATH];

	tagAlarmInfoNode()
	{
		nChnNum = -1;
		dwRuleType = -1;
		ZeroMemory(&Time, sizeof(Time));
		ZeroMemory(szFile, _countof(szFile));
	}
}AlarmInfoNode;
//������Ϣ�������տͻ����յ����Ⱥ�˳���������
typedef	std::list<AlarmInfoNode*> lsAlarmInfo;




typedef struct tagMTNode
{
	int			nNodeType;
	int			nPointCount;
	CFG_POLYGON	CfgPolygon[MAX_POLYGON_NUM];

	tagMTNode()
	{
		nNodeType = 0;
		nPointCount = 0;
		for (int i = 0; i < MAX_POLYGON_NUM; i++)
		{
			CfgPolygon[i].nX = 0;
			CfgPolygon[i].nY = 0;
		}
	}
}MTNODE;

typedef struct
{
	int ivsType;
	TCHAR szType[32];
}IVSType;

const IVSType TypeTable[] = 
{
	{EVENT_IVS_CROSSFENCEDETECTION, _T("CrossFence")},
	{EVENT_IVS_CROSSLINEDETECTION, _T("CrossLine")},
	{EVENT_IVS_CROSSREGIONDETECTION, _T("CrossRegion")},
	{EVENT_IVS_MOVEDETECTION, _T("MoveDetection")},
	{EVENT_IVS_LEFTDETECTION, _T("LeftDetection")},
	{EVENT_IVS_PARKINGDETECTION, _T("Parking")},
	{EVENT_IVS_PRESERVATION, _T("Preservation")},
	{EVENT_IVS_RETROGRADEDETECTION, _T("Retrogradation")},
	{EVENT_IVS_STAYDETECTION, _T("Stay")},
	{EVENT_IVS_TAKENAWAYDETECTION, _T("TakenAway")},
	{EVENT_IVS_VIDEOABNORMALDETECTION, _T("VideoAbnormal")},
	{EVENT_IVS_WANDERDETECTION, _T("Wander")},
	{0, _T("\0")}
};


//////////////////////////////////////////////////////////////////////////

void CALLBACK RealDataCallBackEx(LLONG lRealHandle,
								 DWORD dwDataType, 
								 BYTE *pBuffer,
								 DWORD dwBufSize, 
								 LONG lParam, 
								 LDWORD dwUser);
//
void  g_SetWndStaticText(CWnd * pWnd);

//
CString ConvertString(CString strText);

//
int g_getStructSize(int nRuleType);

//
CString g_ConvertRuleTypeToString(DWORD dwType);

//
int g_ConvertRuleTypeToStructSize(DWORD dwType);

//
int g_GetStructInfo(DWORD dwAlarmType);

//
void g_DrawArrow(CDC *pDC, POINT pointStart, ARROW_DIRECTION_TYPE eArrowDirection);

//////////////////////////////////////////////////////////////////////////
//

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







#endif