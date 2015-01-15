#if !defined _ITS_COMMON_H
#define  _ITS_COMMON_H


#define _CS 

#define WM_INSERTCOMBOX (WM_USER)
#define WM_UPDATESTATE	(WM_USER+1)

#define MAX_DETECT_LINE			8
#define MAX_ROAD_LINE			8
#define MAX_AREA				1
//**************************************
#define MAX_STOPLINE			8
#define MAX_PRELINE				8
#define MAX_POSTLINE			8
#define MAX_STOPLIGHTREGION		8
//***************************************

#define LIMIT_ANGLE  45	//�봹ֱ�������Ƕ�
#define CTRL_SPACING 30 //�ؼ�֮��ļ��

//���Ƴ���
enum SelectScene
{
	ssNone = -1,
	ssRoadLine ,     // ������
	ssDetectLine,       // �����
	ssDetectArea,       // �������
// ***********************	
	ssStopLine,         // ֹͣ��
	ssPreLine,          // ǰ����
	ssPostLine,         // ������
	ssStopLightRegion,  // �����
// *************************
};


#define 	eRoadLine   0       // ������
#define 	eDetectLine 1       // �����
#define 	eDetectArea 2       // �������
// *****************	 
#define 	eStopLine   3       // ֹͣ��
#define		ePreLine    4       // ǰ����
#define  	ePostLine   5       // ������
#define 	eStopLightRegion 6  // �����
// ******************
#define     eText        7      // ����
#define     eTrackRegion 8      // ��������

struct   CVSPoint   
{   
	double   m_dX;   
	double   m_dY;   
};

typedef struct
{
	int		nDirect;	//����
	char*	pName;		//����
}MODIFY_DATA;

const double PI = 3.1415926;


#endif