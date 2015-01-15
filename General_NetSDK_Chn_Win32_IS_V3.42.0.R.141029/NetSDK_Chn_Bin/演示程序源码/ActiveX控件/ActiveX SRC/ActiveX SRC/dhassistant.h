
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
	EN_FTP = 0,							// FTP bitwise��1��send out record file;  2��Send out snapshot file
	EN_SMTP,							// SMTP bitwise��1��alarm send out text mail 2��Alarm send out image
	EN_NTP,								// NTP	 Bitwise��1��Adjust system time 
	EN_AUTO_MAINTAIN,					// Auto maintenance  Bitwise��1��reboot 2��close  3:delete file
	EN_VIDEO_COVER,						// Privacy mask Bitwise  ��1��multiple-window privacy mask 
	EN_AUTO_REGISTER,					// Auto registration	Bitwise��1:SDK auto log in after registration 
	EN_DHCP,							// DHCP	Bitwise��1��DHCP
	EN_UPNP,							// UPNP	Bitwise ��1��UPNP
	EN_COMM_SNIFFER,					// COM sniffer  Bitwise ��1:CommATM
	EN_NET_SNIFFER,						// Network sniffer Bitwise �� 1��NetSniffer
	EN_BURN,							// Burn function Bitwise 1��Search burn status 
	EN_VIDEO_MATRIX,					// Video matrix Bitwise  1��Support video matrix or not
	EN_AUDIO_DETECT,					// Video detection Bitwise ��1��Support video detection or not 
	EN_STORAGE_STATION,					// Storage postion Bitwise��1��Ftp server (Ips) 2��SBM 3��NFS 16��DISK 17��Flash disk 
	EN_IPSSEARCH,						// IPS storage search  Bitwise  1��IPS storage search 	
	EN_SNAP,							// Snapshot Bitwise  1��Resoluiton 2��Frame rate 3��Snapshoot  4��Snapshoot file image; 5��Image quality 
	EN_DEFAULTNIC,						// Search default network card search  Bitwise  1��Support
	EN_SHOWQUALITY,						// Image quality configuration time in CBR mode 1:support 
	EN_CONFIG_IMEXPORT,					// Configuration import& emport function capacity.  Bitwise   1:support 
	EN_LOG,								// Support search log page by page or not. Bitwise 1��support 
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
	char		isSupportWM;			// 1:Support��0 Do not support
	char		supportWhat;			// 0��Characrer watermark��1��Image watermark��2��Support character watermark and image watermark at the same time.
	char		reserved[2];
} DH_WATERMAKE_EN;

//////////////////////////////////////////////////////////////////////////
//	Multiple-window preview capacity structure 
typedef struct  
{
	int			nEnable;				// 1:Support��  0 :Do not support 
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

