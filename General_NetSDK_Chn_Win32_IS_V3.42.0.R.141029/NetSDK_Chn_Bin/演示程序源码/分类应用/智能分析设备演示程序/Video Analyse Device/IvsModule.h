#pragma once

#include <vector>
#include <list>
#include <map>

#define M_PI 3.1415926
#define LOCUS_WIDTH				1024
#define LOCUS_HEIGHT			1024
#define IVS_VIDEO_WIDTH			8192
#define IVS_VIDEO_HEIGHT		8192

#define Min_Distance			512		//�������������ͷ����С2�����루8192����ϵ�£�
#define  MAX_TRACKPOINT_NUM 10
#define IVS_INFO_SHOW_FRAMES	100		// �ڶ���֡����ʾ���ܷ�����Ϣ(�˶��켣,������Ϣ)
#define MAX_IVS_LOCUS_SEG_CNT	50		// �˶�Ŀ������˶��켣����Ŀ
#define MAX_IVS_OBJECT_CNT		50		// �˶�Ŀ�������Ŀ
#define CHANNEL_MAX_COUNT		32

enum
{
	Color_ObjectNormal = RGB(0,255,0),	// ����Ŀ�����ɫ
		Color_ObjectAlarm  = RGB(255,0,0),	// ����ʱĿ�����ɫ
		Color_LocusNormal  = RGB(0,255,0),	// �����켣��ɫ
		Color_LocusAlarm   = RGB(255,0,0),	// ����ʱ�켣��ɫ
		Color_RuleNormal   = RGB(0,0,255),	// ����������ɫ
		Color_RuleAlarm    = RGB(255,0,0)	// ����ʱ������ɫ
};

enum IvsOjbOpt
{
	IvsOjbOpt_AddOjb = 1,
		IvsOjbOpt_AddLocus,
		IvsOjbOpt_DelOjb,
		IvsOjbOpt_HideLocus
};

typedef struct _tagCHANNEL_INFO
{
	bool			m_bAtmIvs;
	bool			m_bSupportIvs;
	bool			m_bEnableIvs;
	int				m_nMaxRuleStructSize;
	int				m_nMaxRuleNum;
}CHANNEL_INFO;

typedef struct _deviceinfo_tag
{
public:	
	LONG			m_ID;									//�豸ID
	LONG			m_LoginHandle;							//��½���
	int				m_ChannelCount;							//ͨ����
	CHANNEL_INFO	m_Channel[CHANNEL_MAX_COUNT];			//ͨ����Ϣ
}DEV_INFO;

//RECT=(X-XSize, Y-YSize, X+XSize, Y+YSize)
typedef struct _PRIVATE_IVS_POINT
{
	short			x;
	short			y;
	short			xSize;
	short			ySize;
}PRIVATE_IVS_POINT;

//�˶�Ŀ��켣
typedef struct _PRIVATE_IVS_OBJ
{
	int				decode_id;
	int				obj_id;
	int				enable;
	PRIVATE_IVS_POINT	track_point[MAX_TRACKPOINT_NUM];
	int				trackpt_num;
	int				operator_type; //������Ϊ���ࣺ��������(1), ��������켣��(2)��ɾ������(3)����������켣(4),����ֵ��Ч
	int				frame_part_id; //0��ʾһ֡�Ŀ�ʼ�����ε���
	char			reserved[128]; //����
	
}PRIVATE_IVS_OBJ;

struct IvsRuleInfo
{
	char szRuleName[MAX_NAME_LEN];				// ��������,��ͬ����������
	bool bRuleEnable;							// ����ʹ��
	
	CFG_RULE_INFO stuRuleInfo;
	
	union RuleEvent
	{
		CFG_CROSSLINE_INFO			stuCrossLineCfg;		// �����߹�������,��������Ϊ"CrossLineDetection"ʱ��Ч
		CFG_CROSSREGION_INFO		stuCrossRegionCfg;		// ��������������,��������Ϊ"CrossRegionDetection"ʱ��Ч
		CFG_PASTE_INFO				stuPasteCfg;			// ATM������������,��������Ϊ"PasteDetection"ʱ��Ч
		CFG_LEFT_INFO				stuLetfCfg;				// ��Ʒ������������,��������Ϊ"LeftDetection"ʱ��Ч
		CFG_PRESERVATION_INFO		stuPreseRvationCfg;		// ��Ʒ��ȫ��������,��������Ϊ"Preservation"ʱ��Ч
		CFG_STAY_INFO				stuStayCfg;				// ͣ����������,��������Ϊ"StayDetection"ʱ��Ч
		CFG_WANDER_INFO				stuWanderCfg;			// �ǻ���������,��������Ϊ"WanderDetection"ʱ��Ч
		CFG_MOVE_INFO				stuMoveCfg;				// �˶���������,��������Ϊ"MoveDetection"ʱ��Ч
		CFG_TAIL_INFO				stuTailCfg;				// β���������,��������Ϊ"TailDetection"ʱ��Ч
		CFG_RIOTER_INFO				stuRioterCfg;			// �ۼ���������,��������Ϊ"RioterDetection"ʱ��Ч
		CFG_FIGHT_INFO				stuFightCfg;			// ��ܹ�������,��������Ϊ"FightDetection"ʱ��Ч
		CFG_FIRE_INFO				stuFireCfg;				// �����������,��������Ϊ"FireDetection"ʱ��Ч
		CFG_SMOKE_INFO				stuSmokeCfg;			// �����������,��������Ϊ"SmokeDetection"ʱ��Ч
		CFG_FLOWSTAT_INFO			stuFlowStatCfg;			// ����ͳ�ƹ�������, ��������Ϊ"FlowStat"ʱ��Ч
		CFG_NUMBERSTAT_INFO			stuNumberStatCfg;		// ����ͳ�ƹ�������,��������Ϊ"NumberStat"ʱ��Ч
		CFG_TRAFFICCONTROL_INFO		stuTraControlCfg;		// ��ͨ���ƹ�������,��������Ϊ"TrafficControl"ʱ��Ч
		CFG_TRAACCIDENT_INFO		stuAccidentCfg;			// ��ͨ�¹ʹ�������,��������Ϊ"TrafficAccident"ʱ��Ч
		CFG_TRAJUNCTION_INFO		stuJunctionCfg;			// ·�ڹ�������,��������Ϊ"TrafficJunction"ʱ��Ч
		CFG_TRAFFICGATE_INFO		stuTrafficGateCfg;		// ���ڹ�������,��������Ϊ"TrafficGate"ʱ��Ч
		CFG_FACEDETECT_INFO			stuFaceDetectCfg;		// ��������������,��������Ϊ"FaceDetect"ʱ��Ч
	} ruleEvent;
};

// ������Ϣ
struct IvsDecodeInfo
{
	LONG				dev_id;			// �豸ID
	int					chnl_idx;		// ͨ�����
	int					decoder_id;		// ����˿�
	HWND				hwnd;			// ��Ƶ��ʾ����

	bool				bShowRule;		// �Ƿ���ʾ���ܷ�������
	bool				bShowObj;		// �Ƿ���ʾ�˶�Ŀ�����
	bool				bShowLocus;		// �Ƿ���ʾ�˶��켣
};

// ���ܷ���������Ϣ
struct IvsRule
{
	int					rule_id;				// �������
	int					trigger_cnt;			// ����������
 	IvsRuleInfo			ruleInfo;				//������Ϣ
	IvsRule()
	{
		memset(&ruleInfo, 0 , sizeof(ruleInfo));
		rule_id = 0;
		trigger_cnt = 0;
	}
};

typedef std::map<int,IvsRule*>		IvsRuleMap;		// ����ID ==> ����
typedef DH_RECT				IvsRect;
typedef std::list<CFG_POLYLINE>		IvsLocusSeg;	// һ���˶��켣
typedef std::list<IvsLocusSeg>		IvsLocus;		// Ŀ���˶��켣

struct IvsObject
{
	int					object_id;			// �˶�Ŀ��ID
	int					opt_type;			// ������Ϊ���ࣺ��������(1), ��������켣��(2)��ɾ������(3)����������켣(4),����ֵ��Ч
	int					alarm_cnt;			// �˶�Ŀ�걨������
	int					display_cnt;		// �˶�Ŀ����ʾ����
	IvsRect				obj_rect;			// �˶�Ŀ�����
 	IvsLocus			obj_locus;			// �˶��켣
};

typedef std::map<int,IvsObject>		IvsObjectMap;	// �˶�Ŀ��ID ==> �˶�Ŀ��

// ����ͨ����Ϣ
struct IvsChnlInfo
{
	LONG				dev_id;				// �豸ID
	int					chnl_idx;			// ͨ�����
	BOOL				bEnableIvs;			// ͨ���Ƿ��������ܷ�������
	BOOL				bAtm;				// ��ATM�豸��?
	BYTE				bPreset;			// ������

	/*
		ʹ���ĸ�����˿ڵĹ켣��Ϣ:
		һ���豸ͨ�����ܱ���δ�,�ж��ʵʱ�����ڽ���,���еĹ켣��ϢӦ�ö���һ����,
		����ֻʹ������һ��ʵʱ�����еĹ켣��Ϣ�Ϳ�����.���ֶ�ָʾʹ���ĸ�����˿��ϱ��Ĺ켣��Ϣ.
	*/
	int					live_dec_id;
	IvsRuleMap			rule_map;			// �����
	IvsObjectMap		mapId2Obj;			// �˶�Ŀ���б�
};

struct ReloadIvsRuleReq
{
	LONG				devHandle;
	int					nChnlIdx;
	bool				bReloadCfg;
	bool				bAddNew;
	int					nDecPort;
	HWND				hVideoWnd;
	int					nChnlCnt;
};

class CIvsModule : public CWnd
{
public:
	// ���豸ͨ��ʱ��ȡ�����ܷ�������
	static int OnOpenDeviceRealplay(LONG lDevHandle,int nChnlIdx,int nDecoderPort,HWND hwnd,int nChnlCnt);
	static void ReloadIvsRuleProc(ReloadIvsRuleReq* pReq);
	static int GetDeviceIvsConfig(DEV_INFO& devInfo);
	static int GetRulesMaxStructSize(DWORD *pRulesTypes, int nRuleNum);

	// ���¶�ȡ���ܷ���ͨ������
	static int ReloadChannelIvsRule(LONG lDevHandle,DEV_INFO &devInfo,int nChnlIdx,
		bool bAddNew = true,int  nDecPort = -1);

	// ���ƹ�����˶�Ŀ��(�켣�����)
	static int DrawIvsRuleProc(IvsChnlInfo* pChnlInfo,HDC hdc);
	static void DrawIvsRule(IvsRule* pIvsRule,HDC hdc);
	static int DrawIvsObjectProc(IvsChnlInfo* pChnlInfo,IvsDecodeInfo* pDecInfo,HDC hdc);
	
	// ���Ƽ�ͷ
	static void DrawDirectionArrow(HDC hdc,POINT ptStart,POINT ptEnd,int nDirection,HRGN hrgn = NULL);

	static void DrawIvsObjectLocus(IvsObject* pIvsObj, HDC hdc);
	static void DrawIvsObjectBoundBox(IvsObject* pIvsObj, HDC hdc);


	static void __stdcall GetIvsInfoProc(char* buf, long type, long len, long reallen, void* reserved, void* nUser);
	static void __stdcall DrawIvsInfoProc(long nPort,HDC hdc,LONG nUser);

	static BOOL Init();
	static BOOL UnInit();

	static void ClearData();
protected:
private:
	CIvsModule(){}
	virtual ~CIvsModule();
	static void* AllocateMemory(UINT nSize);
	static void FreeMemory(void* pMem);

private:
	static HANDLE								m_hIvsHeap;
	static std::map<int,IvsDecodeInfo>			m_decode_info_map;		// ����˿ں� ==> ������Ϣ
	static std::list<IvsChnlInfo>				m_chnl_info_list;		// ͨ����Ϣ��
	static CRITICAL_SECTION						m_cs;
};