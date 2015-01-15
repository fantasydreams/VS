// ComConstants.h: interface for the CComConstants class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMCONSTANTS_H__CFA5806B_B91C_4665_89A2_AD397C38F75A__INCLUDED_)
#define AFX_COMCONSTANTS_H__CFA5806B_B91C_4665_89A2_AD397C38F75A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/************************************************************************
 ** ��������
 ***********************************************************************/
#define CHANNEL_NUM_LIMIT 256 // �����Ƶͨ��������

#define MIN_CHANNEL_NUM_TAG 0	// ���ͨ����ѡ��
#define MAX_CHANNEL_NUM_TAG 256	// ��Сͨ����ѡ��

#define MIN_CIF_PFRAME_SIZE     7       // CIF��СP֡��С����λΪKbits
#define MAX_CIF_PFRAME_SIZE     40      // CIF���P֡��С����λΪKbits
#define IFRAME_PFRAME_QUOTIENT  3       // �����˶������I֡��С��P֡��С֮�� 
#define MAXFPS_LIMIT            8192    // ���������ֵ
#define MAX_NAS_LIMIT           2       // �������NAS��������
#define MAX_ETHERNET_LIMIT      9       // �������������,������Ϣ���һ��Ϊbond0,ʵ������������1
#define SDK_DEMO_WAITTIME       5000    // SDK�ӿڵȴ�ʱ�䣬��λms
/************************************************************************
 ** ö�ٶ���
 ***********************************************************************/
enum EnNetWorkMode
{
	En_Net_Bind,			///< ��
	En_Net_Balance,			///< ����ƽ��
	En_Net_Multiple,		///< ��ַ
	En_Net_Tolerance,		///< �ݴ�	
};


/************************************************************************
 ** �ṹ�嶨��
 ***********************************************************************/

#endif // !defined(AFX_COMCONSTANTS_H__CFA5806B_B91C_4665_89A2_AD397C38F75A__INCLUDED_)
