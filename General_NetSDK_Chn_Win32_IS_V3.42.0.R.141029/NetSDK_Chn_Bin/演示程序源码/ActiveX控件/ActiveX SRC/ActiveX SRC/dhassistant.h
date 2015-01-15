
#ifndef DHSYSABLE_H
#define DHSYSABLE_H


//////////////////////////////////////////////////////////////////////////
//	Search Type
typedef enum
{
	ABILITY_WATERMARK_CFG = 17,			// Watermark configuration capacity
	ABILITY_WIRELESS_CFG = 18,			// wireless  confuguration capacity
	ABILITY_DEVALL_INFO = 26,			// Device capacity list 
	ABILITY_CARD_QUERY = 0x0100,		// Card number search capacity 
	ABILITY_MULTIPLAY = 0x0101,			// Multiple-window preview capacity 
	ABILITY_INFRARED = 0x0121,			// Wireless alarm capacity 
	ABILITY_TRIGGER_MODE = 0x0131,		// Alarm activation mode function 
} DH_SYS_ABILITY;

//////////////////////////////////////////////////////////////////////////
//	The function list device supported 
enum 
{
	EN_FTP = 0,							// FTP bitwise£¬1£ºsend out record file;  2£ºSend out snapshot file
	EN_SMTP,							// SMTP bitwise£¬1£ºalarm send out text mail 2£ºAlarm send out image
	EN_NTP,								// NTP	 Bitwise£º1£ºAdjust system time 
	EN_AUTO_MAINTAIN,					// Auto maintenance  Bitwise£º1£ºreboot 2£ºclose  3:delete file
	EN_VIDEO_COVER,						// Privacy mask Bitwise  £º1£ºmultiple-window privacy mask 
	EN_AUTO_REGISTER,					// Auto registration	Bitwise£º1:SDK auto log in after registration 
	EN_DHCP,							// DHCP	Bitwise£º1£ºDHCP
	EN_UPNP,							// UPNP	Bitwise £º1£ºUPNP
	EN_COMM_SNIFFER,					// COM sniffer  Bitwise £º1:CommATM
	EN_NET_SNIFFER,						// Network sniffer Bitwise £º 1£ºNetSniffer
	EN_BURN,							// Burn function Bitwise 1£ºSearch burn status 
	EN_VIDEO_MATRIX,					// Video matrix Bitwise  1£ºSupport video matrix or not
	EN_AUDIO_DETECT,					// Video detection Bitwise £º1£ºSupport video detection or not 
	EN_STORAGE_STATION,					// Storage postion Bitwise£º1£ºFtp server (Ips) 2£ºSBM 3£ºNFS 16£ºDISK 17£ºFlash disk 
	EN_IPSSEARCH,						// IPS storage search  Bitwise  1£ºIPS storage search 	
	EN_SNAP,							// Snapshot Bitwise  1£ºResoluiton 2£ºFrame rate 3£ºSnapshoot  4£ºSnapshoot file image; 5£ºImage quality 
	EN_DEFAULTNIC,						// Search default network card search  Bitwise  1£ºSupport
	EN_SHOWQUALITY,						// Image quality configuration time in CBR mode 1:support 
	EN_CONFIG_IMEXPORT,					// Configuration import& emport function capacity.  Bitwise   1:support 
	EN_LOG,								// Support search log page by page or not. Bitwise 1£ºsupport 
	EN_SCHEDULE,						// Record setup capacity. Bitwise  1:Redandunce  2:Pre-record 3:Record period
};

typedef struct 
{
	DWORD IsFucEnable[512];				// Function list capacity set. Corresponding to the above mentioned enumeration. Use bit to represent sub-function.
} DH_DEV_ENABLE_INFO;

//////////////////////////////////////////////////////////////////////////
//Card number search function structure 
typedef struct 
{
	char		IsCardQueryEnable;
	char		iRev[3];
} DH_CARD_QUERY_EN;

//////////////////////////////////////////////////////////////////////////
//	Wireless capacity structure 
typedef struct 
{
	char		IsWirelessEnable;
	char		iRev[3];
} DH_WIRELESS_EN;

//////////////////////////////////////////////////////////////////////////
//	Image watermark capacity structure 
typedef struct 
{
	char		isSupportWM;			// 1:Support£»0 Do not support
	char		supportWhat;			// 0£ºCharacrer watermark£»1£ºImage watermark£»2£ºSupport character watermark and image watermark at the same time.
	char		reserved[2];
} DH_WATERMAKE_EN;

//////////////////////////////////////////////////////////////////////////
//	Multiple-window preview capacity structure 
typedef struct  
{
	int			nEnable;				// 1:Support£»  0 :Do not support 
	DWORD		dwMultiPlayMask;		// Multiple-window preview mask 
	char		reserved[4];			// Reserved 
} DH_MULTIPLAY_EN;

//////////////////////////////////////////////////////////////////////////
//	Wireless alarm capacity structure 
typedef struct  
{
	BOOL		bSupport;				// Support or not 
	int			nAlarmInCount;			// Input amount
	int			nAlarmOutCount;			// Output amount 
	int			nRemoteAddrCount;		// Remote control amount 
	BYTE		reserved[32];
}DH_WIRELESS_ALARM_INFO;


#endif // DHSYSABLE_H

