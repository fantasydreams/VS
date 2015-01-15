// SystemConfig.cpp : implementation file
//

#include "StdAfx.h"
#include "netsdkdemo.h"
#include "SystemConfig.h"
#include "NetSDKDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSystemConfig dialog


CSystemConfig::CSystemConfig(CWnd* pParent /*=NULL*/)
	: CDialog(CSystemConfig::IDD, pParent)
{
	m_deviceID = -1;
	//{{AFX_DATA_INIT(CSystemConfig)
	//}}AFX_DATA_INIT
}


void CSystemConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSystemConfig)
	DDX_Control(pDX, IDC_SETDEVICECONFIG1, m_ocx_systemset);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSystemConfig, CDialog)
	//{{AFX_MSG_MAP(CSystemConfig)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSystemConfig message handlers

void CSystemConfig::setDeviceId(LONG deviceID)
{
	m_deviceID = deviceID;
}
void CSystemConfig::ShowDefModal(In_DeviceInfo& di )
{
	m_di = di;
	
	DoModal();
	return;
}

BOOL CSystemConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	g_SetWndStaticText(this);

	m_ocx_systemset.SetConfigPageHide(8);

#ifdef LANG_ENG
	m_ocx_systemset.CreateDeviceFram(0);
#else
	m_ocx_systemset.CreateDeviceFram(1);
#endif

	m_ocx_systemset.SetDeviceShowType((long *)(&m_di));
	
	return TRUE; 
}

BEGIN_EVENTSINK_MAP(CSystemConfig, CDialog)
    //{{AFX_EVENTSINK_MAP(CSystemConfig)
	ON_EVENT(CSystemConfig, IDC_SETDEVICECONFIG1, 13 /* OnBlockAskData */, OnOnBlockAskDataSetdeviceconfig1, VTS_I4 VTS_I4 VTS_PI4 VTS_PI4 VTS_PI4 VTS_PI4)
	ON_EVENT(CSystemConfig, IDC_SETDEVICECONFIG1, 8 /* OnSaveDeviceData */, OnOnSaveDeviceDataSetdeviceconfig1, VTS_I4 VTS_I4 VTS_PI4 VTS_I4 VTS_PI4)
	ON_EVENT(CSystemConfig, IDC_SETDEVICECONFIG1, 18 /* OnDeviceSetInfo */, OnOnDeviceSetInfoSetdeviceconfig1, VTS_PI4)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

//////////////////////for test///////////////////////



//��������
typedef struct {
	BYTE Com_Version[8]; /*!< �汾�� */
	BYTE Function; /*!< ���ڹ��� 0-��ͨ, 1-���Ƽ���, 2-͸������, 3-ATM��*/
	BYTE DataBits; /*!< ����λ ȡֵΪ5,6,7,8 */
	BYTE StopBits; /*!< ֹͣλ 0-1λ, 1-1.5λ, 2-2λ */
	BYTE Parity; /*!< У��λ 0-no, 1-odd, 2-even */
	DWORD BaudBase; /*!< ������ 0-9 �ֱ��ʾ: {300,600,1200,2400,4800,9600,19200,38400,57600,115200}*/
} CONFIG_COMM;

//��̨����
typedef struct
{
	DWORD baudrate; // ����ֵ�ο���������
	BYTE databits;
	BYTE parity;
	BYTE stopbits;
} PTZ_ATTR;

typedef struct {
	BYTE Ptz_Version[8]; /*!< �汾�� */
	PTZ_ATTR PTZAttr; /*!< �������� */
	WORD DestAddr; /*!< Ŀ�ĵ�ַ 0-255 */
	WORD Protocol; /*!< Э������ ����Э����±꣬��̬�仯 */
	WORD MonitorAddr; /*!< ��������ַ 0-64 */
	BYTE Reserved[10]; /*!< ���� */
} CONFIG_PTZ;

//¼�󣨶�ʱ������
#define N_WEEKS 7
#define N_TSECT 6
typedef struct { // ��ʱʱ��
	BYTE StartHour; //��ʼʱ��
	BYTE StartMin;
	BYTE StartSec;
	BYTE EndHour; // ����ʱ��
	BYTE EndMin;
	BYTE EndSec;
	BYTE State; //�ڶ�λ�Ƕ�ʱ������λ�Ƕ�̬��⣬����λ�Ǳ���
	BYTE Reserve;
} TSECT;
typedef struct {
	BYTE RecVersion[8]; /*!< �汾�� */
	TSECT Sector[N_WEEKS][N_TSECT]; /*!< ��ʱʱ�Σ�һ���������죬ÿ��N_TSECTʱ��� */
	BYTE PreRecord; /*!< Ԥ¼����, 0-�ر�, 1-�� */
	BYTE Redundancy; /*!< ���࿪�أ�0-��Ч, 1-��Ч */
	BYTE Reserved[2]; /*!< ���� */
} CONFIG_RECORD;

//ͼ������
// ʹ���еı�����Ϣ�ṹ���壨���ô˽ṹ��
typedef struct {
	BYTE CapVersion[8]; /*!< �汾�� */
	BYTE CifMode; /*!< �ֱ���CIF1, CIF2, CIF4 */
	BYTE VideoType; /*!< ����ģʽ��MPEG1 or MPEG4 */
	BYTE EncodeMode; /*!< �������� */
	BYTE ImgQlty; /*!< �����Ļ��� */
	BYTE Frames; /*!< ֡�� */
	BYTE Brightness; /*!< ���� */
	BYTE Contrast; /*!< �Աȶ� */
	BYTE Saturation; /*!< ���Ͷ� */
	BYTE Hue; /*!< ɫ�� */
	BYTE AudioEn; /*!< ��Ƶʹ�� */
	BYTE Gain; /*!< ���� */
	BYTE CoverEnable; /*!< �����ڸǿ��� */
	RECT Cover; /*!< �����ڸǷ�Χ */
} OLD_CONFIG_CAPTURE;
//! ����õı�����Ϣ�ṹ����ʱû��ʹ�ã�
/*
enum capture_size_t {
	CAPTURE_SIZE_D1,
		CAPTURE_SIZE_HD1,
		CAPTURE_SIZE_DCIF,
		CAPTURE_SIZE_CIF,
		CAPTURE_SIZE_QCIF,
		CAPTURE_SIZE_VGA,
		CAPTURE_SIZE_QVGA,
		CAPTURE_SIZE_SVCD,
		CAPTURE_SIZE_NR,
};
enum capture_comp_t {
	CAPTURE_COMP_DIVX_MPEG4,
		CAPTURE_COMP_MS_MPEG4,
		CAPTURE_COMP_MPEG2,
		CAPTURE_COMP_MPEG1,
		CAPTURE_COMP_H263,
		CAPTURE_COMP_MJPG,
		CAPTURE_COMP_FCC_MPEG4,
		CAPTURE_COMP_H264,
		CAPTURE_COMP_NR,
};
enum capture_brc_t {
	CAPTURE_BRC_CBR,
		CAPTURE_BRC_VBR,
		CAPTURE_BRC_MBR,
		CAPTURE_BRC_NR,
};
*/
typedef struct 
{
	BYTE CapVersion[8]; /*!< �汾�� */
	BYTE CifMode; /*!< �ֱ��� ����ö��capture_size_t*/
	BYTE VideoType; /*!< ����ģʽ ����ö��capture_comp_t */
	BYTE EncodeMode; /*!< �������� ����ö��capture_brc_t */
	BYTE ImgQlty; /*!< �����Ļ��� 1-6 */
	BYTE Frames; /*!< ֡�� ����N��1-6, P��1-5 */
	BYTE Brightness; /*!< ���� 0-100 */
	BYTE Contrast; /*!< �Աȶ� 0-100 */
	BYTE Saturation; /*!< ���Ͷ� 0-100 */
	BYTE Hue; /*!< ɫ�� 0-100 */
	BYTE AudioEn; /*!< ��Ƶʹ�� 0-�ر�, 1-�� */
	BYTE Gain; /*!< ���� 0-100 */
	BYTE CoverEnable; /*!< �����ڸǿ��� 0-�ر�, 1-��*/
	RECT Cover; /*!< �����ڸǷ�Χ */
	BYTE TimeTilteEn; /*!< ʱ�����ʹ�� 0-�ر�, 1-�� */
	BYTE ChTitleEn; /*!< ͨ������ʹ�� 0-�ر�, 1-�� */
	BYTE Reserver[2]; /*!< ���� */
} CONFIG_CAPTURE;

typedef struct
{
    unsigned char Version[8]; // 8�ֽڵİ汾��Ϣ
    char HostName[16]; // ������
    unsigned long HostIP; // IP ��ַ
    unsigned long Submask; // ��������
    unsigned long GateWayIP; // ���� IP
    unsigned long DNSIP; // DNS IP
	
    // �ⲿ�ӿ�
    unsigned long AlarmServerIP; // ��������IP
    unsigned short  AlarmServerPort; // �������Ķ˿�
    unsigned long SMTPServerIP; // SMTP server IP
    unsigned short  SMTPServerPort; // SMTP server port
    unsigned long LogServerIP; // Log server IP
    unsigned short  LogServerPort; // Log server port
	
    // ��������˿�
    unsigned short  HttpPort; // HTTP����˿ں�
    unsigned short  HttpsPort; // HTTPS����˿ں�
    unsigned short  TCPPort; // TCP �����˿�
    unsigned short  TCPMaxConn; // TCP ���������
    unsigned short  SSLPort; // SSL �����˿�
    unsigned short  UDPPort; // UDP �����˿�
    unsigned long McastIP; // �鲥IP
    unsigned short  McastPort; // �鲥�˿�
    
    // ����
    unsigned char  MonMode; // ����Э�� 0-TCP, 1-UDP, 2-MCAST
    unsigned char  PlayMode; // �ط�Э�� 0-TCP, 1-UDP, 2-MCAST
    unsigned char  AlmSvrStat; // ��������״̬ 0-�ر�, 1-��
}CONFIG_NET;

//alarm
typedef struct
{
	DWORD dwVersion;
	BYTE dbReserve[4];
}VER_CONFIG;
#define NAME_LEN 32

#define ALARM_SECTS 2
typedef struct 
{
	VER_CONFIG sVerConfig; /*! �����ļ��汾��Ϣ */
	DWORD AlarmMask; /*! ����������� */
	DWORD RecordMask; /*! ¼��ͨ������ */
	DWORD TimeDelay; /*! ¼����ʱ��10��300 sec */
	BYTE SensorType; /*! ���������ͣ����� or ���� */
	BYTE TimePreRec; /*! Ԥ¼ʱ�� ���� Ԥ¼���� */
	BYTE AlarmTipEn; /*! ������ʾ */
	TSECT sAlarmSects[ALARM_SECTS]; /*! �����������ʾ��ʱ��� */
	DWORD dwSectMask[ALARM_SECTS]; /*! �����������ʾ��ʱ��ε����� */
	DWORD dwInputTypeMask; /*! ���������������� */
	BYTE dbTourEn; /*! �Ƿ���������ѵ */
	BYTE Mailer; /*! �����ʼ����루1-8λ��ʾ���8ͨ����ͼ�� */
	BYTE SendAlarmMsg; /*! ���ͱ�����Ϣ���������������ȣ� */
	BYTE adbReserved; /*! �����ֶ� */
} CONFIG_ALARM, *pCONFIG_ALARM;

//////////////////////end test///////////////////////

void CSystemConfig::OnOnBlockAskDataSetdeviceconfig1(long DeviceID, long lConfigType, long FAR* lpConfigbuf, long FAR* lpMaxLen, long FAR* lpConfigBufLen, long FAR* lpResult) 
{
	BOOL nRet;
	NET_TIME nTime;
	if(DeviceID == 0)
	{
		return;
	}
	switch(lConfigType)
	{
	case 1:
		nRet = CLIENT_QueryDeviceTime(DeviceID, &nTime, 2000);
		if(nRet)
		{
			*(LONG *)lpConfigBufLen =  sizeof(nTime);//g_TimeOutString(&nTime).GetBuffer(0)
			memcpy((char *)lpConfigbuf,(char *)&nTime,sizeof(nTime));
		}
		else if (!nRet)
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
		}
		break;
	case 2:   //ϵͳ��Ϣ5��ʾ�ַ���Ϣ
		nRet = CLIENT_QuerySystemInfo(DeviceID, 5, (char *)lpConfigbuf, *(LONG *)lpMaxLen, (int *)lpConfigBufLen, 2000);
		if (!nRet)
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
		}
		break;
	case 3:
		nRet = CLIENT_QueryConfig(DeviceID, 10, (char *)lpConfigbuf,*(LONG *)lpMaxLen, (int *)lpConfigBufLen, 2000);
		if (!nRet)
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
		}
		break;
	case 4:
		nRet = CLIENT_QueryComProtocol(DeviceID, 0, (char *)lpConfigbuf,*(LONG *)lpMaxLen, (int *)lpConfigBufLen, 2000);
		if (!nRet)
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
		}
		break;
	case 5:
		nRet = CLIENT_QueryComProtocol(DeviceID, 1, (char *)lpConfigbuf,*(LONG *)lpMaxLen, (int *)lpConfigBufLen, 2000);
		if (!nRet)
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
		}
		break;	
	case 6:
	//	ZeroMemory(lpConfigbuf, *lpMaxLen);
	//	nRet = 1;
		nRet = CLIENT_QueryConfig(DeviceID, 210, (char *)lpConfigbuf, *(LONG *)lpMaxLen, (int *)lpConfigBufLen, 2000);
		break;
	case 31:
	case 33:
	case 34: //DDNS
		nRet = CLIENT_QueryConfig(DeviceID, lConfigType - 20, (char *)lpConfigbuf, *(LONG *)lpMaxLen, (int *)lpConfigBufLen, 10000);
		if (!nRet)
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
		}
		{
			//for test
			char temp[1000] = {0};
			memcpy(temp, lpConfigbuf, *lpConfigBufLen);
			//end test
		}
		break;
	case 50:
		nRet = CLIENT_QueryLog(DeviceID, (char *)lpConfigbuf,*(LONG *)lpMaxLen, (int *)lpConfigBufLen);
		if (!nRet)
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
		}
		break;
	case 51:
		ZeroMemory(lpConfigbuf,*lpMaxLen);
		nRet = 1;
	//	nRet = CLIENT_QueryConfig(DeviceID, 200, (char *)lpConfigbuf, *(LONG *)lpMaxLen, (int *)lpConfigBufLen, 10000);
		break;

/////////////////////////////////for test////////////////////////
		
	case 20: //general
		nRet = CLIENT_QueryConfig(DeviceID, lConfigType - 20, (char *)lpConfigbuf, *(LONG *)lpMaxLen, (int *)lpConfigBufLen, 5000);
		if (!nRet)
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
		}
		break;
	case 21: //comm
		nRet = CLIENT_QueryConfig(DeviceID, lConfigType - 20, (char *)lpConfigbuf, *(LONG *)lpMaxLen, (int *)lpConfigBufLen, 5000);
		if (!nRet)
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
		}
		if (*lpConfigBufLen == sizeof(CONFIG_COMM))
		{
			CONFIG_COMM *temp = (CONFIG_COMM *)lpConfigbuf;
			int i = 0;
		}
		//test
	//	nRet = 1;
		break;
	case 22:
		nRet = CLIENT_QueryConfig(DeviceID, lConfigType - 20, (char *)lpConfigbuf, *(LONG *)lpMaxLen, (int *)lpConfigBufLen, 5000);
		if (!nRet)
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
		}
		if (*lpConfigBufLen == sizeof(CONFIG_NET))
		{
			CONFIG_NET *ptmpNetCfg = (CONFIG_NET *)lpConfigbuf;
			int i = 0;
		}
		break;
	case 23: //record
		nRet = CLIENT_QueryConfig(DeviceID, lConfigType - 20, (char *)lpConfigbuf, *(LONG *)lpMaxLen, (int *)lpConfigBufLen, 5000);
		if (!nRet)
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
		}
		if (*lpConfigBufLen == 16 * sizeof(CONFIG_RECORD))
		{
			int length = *lpConfigBufLen;
			while (length/sizeof(CONFIG_RECORD) > 0)
			{
				CONFIG_RECORD *temp = (CONFIG_RECORD *)lpConfigbuf;
				length -= sizeof(CONFIG_RECORD);
			}
		}
		break;
	case 24: //picture
		nRet = CLIENT_QueryConfig(DeviceID, lConfigType - 20, (char *)lpConfigbuf, *(LONG *)lpMaxLen, (int *)lpConfigBufLen, 5000);
		if (!nRet)
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
		}
		if (*lpConfigBufLen == 16 * sizeof(OLD_CONFIG_CAPTURE))
		{
			int length = *lpConfigBufLen;
			while (length/sizeof(OLD_CONFIG_CAPTURE) > 0)
			{
				OLD_CONFIG_CAPTURE *temp = (OLD_CONFIG_CAPTURE *)lpConfigbuf;
				length -= sizeof(OLD_CONFIG_CAPTURE);
			}
		}
		break;
	case 25: //ptz
		nRet = CLIENT_QueryConfig(DeviceID, lConfigType - 20, (char *)lpConfigbuf, *(LONG *)lpMaxLen, (int *)lpConfigBufLen, 5000);
		if (!nRet)
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
		}
		if (*lpConfigBufLen == 16 * sizeof(CONFIG_PTZ))
		{
			int length = *lpConfigBufLen;
			while (length/sizeof(CONFIG_PTZ) > 0)
			{
				CONFIG_PTZ *temp = (CONFIG_PTZ *)lpConfigbuf;
				length -= sizeof(CONFIG_PTZ);
			}
		}
		break;
	case 27: //alarm
		nRet = CLIENT_QueryConfig(DeviceID, lConfigType - 20, (char *)lpConfigbuf, *(LONG *)lpMaxLen, (int *)lpConfigBufLen, 5000);
		if (!nRet)
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
		}
		if (*lpConfigBufLen == 16 * sizeof(CONFIG_ALARM))
		{
			int length = *lpConfigBufLen;
			while (length/sizeof(CONFIG_ALARM) > 0)
			{
				CONFIG_ALARM *temp = (CONFIG_ALARM *)lpConfigbuf;
				length -= sizeof(CONFIG_ALARM);
			}
		}
		break;		
//////////////////////////////test end///////////////////////////////
	default:
		if(lConfigType >= 20 && lConfigType <= 27)
		{
			nRet = CLIENT_QueryConfig(DeviceID, lConfigType - 20, (char *)lpConfigbuf, *(LONG *)lpMaxLen, (int *)lpConfigBufLen, 5000);
			if (!nRet)
			{
				((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
			}
		}
	}
	if(nRet)
	{
		*lpResult = 1;		
	}
	else
	{
		((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
		*lpResult = 0;		
	}
}

void CSystemConfig::OnOnSaveDeviceDataSetdeviceconfig1(long DeviceID, long lConfigType, long FAR* lpConfigbuf, long lConfigbuflen, long FAR* lpResult) 
{
	BOOL nRet = false;
	if(DeviceID < 0)
	{
		return;
	}
	switch(lConfigType)
	{
	case 1:
		nRet = CLIENT_SetupDeviceTime(DeviceID, (NET_TIME *)lpConfigbuf);
		break;
	case 3:
		nRet = 1;
		nRet = CLIENT_SetupConfig(DeviceID, 10, (char *)lpConfigbuf, lConfigbuflen, 5000);
		 if (!nRet)
		{
			 ((CNetSDKDemoDlg *)GetParent())->LastError();
		}
		break;
	case 31:
	case 33:
	case 34:
		nRet = CLIENT_SetupConfig(DeviceID, lConfigType - 20, (char *)lpConfigbuf, lConfigbuflen, 5000);
		if (!nRet)
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();
		}
		break;
	case 51:
	//	nRet = 1;
		nRet = CLIENT_SetupConfig(DeviceID, 200, (char *)lpConfigbuf, lConfigbuflen, 10000);
		break;
	default:
		if((lConfigType >= 20 && lConfigType <= 27))
		{
			nRet = CLIENT_SetupConfig(DeviceID, lConfigType - 20, (char *)lpConfigbuf, lConfigbuflen, 5000);
			if (!nRet)
			{
				((CNetSDKDemoDlg *)GetParent())->LastError();
			}
		}
	}
	if(nRet)
	{
		*lpResult = 1;		
	}
	else
	{
		((CNetSDKDemoDlg *)GetParent())->LastError();
		*lpResult = 0;
		TRACE("CONFIG ERROR %d",lConfigType );
	}
}

void CSystemConfig::OnOnDeviceSetInfoSetdeviceconfig1(long FAR* lpInfoType) 
{
	if(!*lpInfoType)
	{
		CDialog ::OnCancel();
	}
}
