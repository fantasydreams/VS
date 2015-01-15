
#ifndef DHNETSDK_H
#define DHNETSDK_H

#include "dhassistant.h"

#ifdef WIN32

#ifdef DHNETSDK_EXPORTS
#define CLIENT_API  __declspec(dllexport) 
#else
#define CLIENT_API  __declspec(dllimport)
#endif

#define CALLBACK __stdcall
#define CALL_METHOD  __stdcall  //__cdecl

#else	//linux

#define CLIENT_API	extern "C"
#define CALL_METHOD
#define CALLBACK

//#define RELEASE_HEADER	//Release header 
#ifdef RELEASE_HEADER

#define WORD	unsigned short
#define DWORD	unsigned long
#define LPDWORD	DWORD*
#define BOOL	int
#define TRUE	1
#define FALSE	0
#define BYTE	unsigned char
#define LONG	long
#define UINT	unsigned int
#define HDC		void*
#define HWND	void*
#define LPVOID	void*
#define NULL	0
typedef struct  tagRECT
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT;

#else	//Internal translation
#include "../netsdk/osIndependent.h"
#endif

#endif


#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************
 ** Constant Definition
 ***********************************************************************/
#define DH_SERIALNO_LEN 			48			// Device SN string length
#define DH_MAX_DISKNUM 				32			// Max HDD number
#define DH_MAX_SDCARDNUM			32			// Max SD card number
#define DH_MAX_BURNING_DEV_NUM		32			// Max buner amount
#define DH_BURNING_DEV_NAMELEN		32			// Burner name max length 
#define DH_MAX_LINK 				6
#define DH_MAX_CHANNUM 				16			// Max channel amount
#define DH_MAX_ALARMIN 				128			// Max alarm input amount 
#define DH_MAX_ALARMOUT 			64			// Max alarm output amount 
#define DH_MAX_RIGHT_NUM			100			// Max user right amount
#define DH_MAX_GROUP_NUM			20			// Max user group amount
#define DH_MAX_USER_NUM				200			// Max user account amount
#define DH_RIGHT_NAME_LENGTH		32			// Right name length
#define DH_USER_NAME_LENGTH			8			// User name length 
#define DH_USER_PSW_LENGTH			8			// User password length 
#define DH_MEMO_LENGTH				32			// Note length 
#define DH_MAX_STRING_LEN			128
#define DH_DVR_SERIAL_RETURN		1			// Device send out SN callback
#define DH_DVR_DISCONNECT			-1			// Device disconnection callback during the verification period
#define MAX_STRING_LINE_LEN			6			// Max six rows
#define MAX_PER_STRING_LEN			20			// Line max length 
#define DH_MAX_MAIL_NAME_LEN		64			// The user name length the new mail structure supported
#define DH_MAX_MAIL_PSW_LEN			64			// Password length the new mail structhre supported

// Remote configuration structure corresponding constant 
#define DH_MAX_MAIL_ADDR_LEN		128			// Mail address max length
#define DH_MAX_MAIL_SUBJECT_LEN		64			// Mail subject max length 
#define DH_MAX_IPADDR_LEN			16			// IP address string length 
#define DH_MACADDR_LEN				40			// MACE address string length
#define DH_MAX_URL_LEN				128			// URL string length 
#define DH_MAX_DEV_ID_LEN			48			// Device serial number max length 
#define	DH_MAX_HOST_NAMELEN			64			// Host name length 
#define DH_MAX_HOST_PSWLEN			32			// Password length 
#define DH_MAX_NAME_LEN				16			// Universal name string length 
#define DH_MAX_ETHERNET_NUM			2			// Ethernet max amount 
#define	DH_DEV_SERIALNO_LEN			48			// Serial number string length 
#define DH_DEV_TYPE_LEN				32			// Device type string length 
#define DH_N_WEEKS					7			// The days in one week 
#define DH_N_TSECT					6			// Time period amount 
#define DH_N_REC_TSECT				6			// Record period amount 
#define DH_N_COL_TSECT				2			// Color period amount 
#define DH_CHAN_NAME_LEN			32			// Channel name lenght. DVR DSP capacity limit. Max 32 bytes.		
#define DH_N_ENCODE_AUX				3			// Extra stream amount 
#define DH_N_TALK					1			// Max audio talk channel amount 
#define DH_N_COVERS					1			// Privacy mask zone amount 
#define DH_N_CHANNEL				16			// Max channel amount 
#define DH_N_ALARM_TSECT			2			// Alarm prompt period amount 
#define DH_MAX_ALARMOUT_NUM			16			// Alarm output ports max amount 
#define DH_MAX_AUDIO_IN_NUM			16			// Audio input ports max amount 
#define DH_MAX_VIDEO_IN_NUM			16			// Video input ports max amount 
#define DH_MAX_ALARM_IN_NUM			16			// Alarm input ports max amount 
#define DH_MAX_DISK_NUM				16			// HDD max amount. Now the value is 16.
#define DH_MAX_DECODER_NUM			16			// Decoder(485) max amount 
#define DH_MAX_232FUNCS				10			// 232 COM function max amount 
#define DH_MAX_232_NUM				2			// 232 COM port max amount 
#define DH_MAX_DECPRO_LIST_SIZE		100			// Decoder protocol list max amount 
#define DH_FTP_MAXDIRLEN			240			// FTP file folder max length 
#define DH_MATRIX_MAXOUT			16			// Matrix output ports max amount
#define DH_TOUR_GROUP_NUM			6			// Matrix output ports max amount 
#define DH_MAX_DDNS_NUM				10			// ddns max amount the device supported 
#define DH_MAX_SERVER_TYPE_LEN		32			// ddns type and max string length 
#define DH_MAX_DOMAIN_NAME_LEN		256			// ddns domain name and max string length 
#define DH_MAX_DDNS_ALIAS_LEN		32			// ddns alias and max string length 
#define DH_MOTION_ROW				32			// Motion detection zone row amount 
#define DH_MOTION_COL				32			// Motion detection zone column amount 
#define	DH_FTP_USERNAME_LEN			64			// FTP setup:user name max lengh 
#define	DH_FTP_PASSWORD_LEN			64			// FTP setup:password max length 
#define	DH_TIME_SECTION				2			// FTP setup:time periods in each day.
#define DH_FTP_MAX_PATH				240			// FTP setup:file path max length 
#define DH_INTERVIDEO_UCOM_CHANID	32			// Platform embedded setup:U China Net Communication (CNC)channel ID
#define DH_INTERVIDEO_UCOM_DEVID	32			// Platform embedded setup:UCNC device ID
#define DH_INTERVIDEO_UCOM_REGPSW	16			// Platform embedded setup:UCNC registration password 
#define DH_INTERVIDEO_UCOM_USERNAME	32			// Platform embedded setup:UCNC user name 
#define DH_INTERVIDEO_UCOM_USERPSW	32			// Platform embedded setup: UCNC password 
#define DH_INTERVIDEO_NSS_IP		32			//Platform embedded setup:ZTE Netview IP
#define DH_INTERVIDEO_NSS_SERIAL	32			// Serial Platform embedded setup:ZTE Netview  serial
#define DH_INTERVIDEO_NSS_USER		32			// User Platform embedded setup:ZTE Netview user
#define DH_INTERVIDEO_NSS_PWD		50			// Password Platform embedded setup:ZTE Netview password
#define DH_MAX_VIDEO_COVER_NUM		16			// Privacy mask zones max amount 
#define DH_MAX_WATERMAKE_DATA		4096		// Watermark data max length 
#define DH_MAX_WATERMAKE_LETTER		128			// Watermark text max length
#define DH_MAX_WLANDEVICE_NUM		10			// Max searched wireless device amount 
#define DH_MAX_ALARM_NAME			64			// Address length 
#define DH_MAX_REGISTER_SERVER_NUM	10			// Auto registration server amount 
#define DH_SNIFFER_FRAMEID_NUM		6			// 6 FRAME ID options
#define DH_SNIFFER_CONTENT_NUM		4			// 4 sniffer in each FRAME
#define DH_MAX_PROTOCOL_NAME_LENGTH 20
#define DH_SNIFFER_GROUP_NUM		4			// 4 group sniffer setup 
#define MAX_PATH_STOR				240			// Remote folder length 
#define DH_ALARM_OCCUR_TIME_LEN		40			// New alarm upload time length 
#define DH_VIDEO_OSD_NAME_NUM		64			// Overlay name length. Now it supports 32-digit English and 16-digit Chinese.
#define DH_VIDEO_CUSTOM_OSD_NUM		8			// The self-defined amount supported excluding time and channel.
	
// Search type, corresponding to CLIENT_QueryDevState
#define DH_DEVSTATE_COMM_ALARM		0x0001		// Search general alarm status(including external alarm,video loss, motion detection)
#define DH_DEVSTATE_SHELTER_ALARM	0x0002		// Search camera masking alarm status
#define DH_DEVSTATE_RECORDING		0x0003		// Search record status 
#define DH_DEVSTATE_DISK			0x0004		// Search HDD information 
#define DH_DEVSTATE_RESOURCE		0x0005		// Search system resources status 
#define DH_DEVSTATE_BITRATE			0x0006		// Search channel bit stream 
#define DH_DEVSTATE_CONN			0x0007		// Search device connection status 
#define DH_DEVSTATE_PROTOCAL_VER	0x0008		// Search network protocol version number , pBuf = int*
#define DH_DEVSTATE_TALK_ECTYPE		0x0009		// Search the audio talk format the device supported. Please refer to structure DHDEV_TALKFORMAT_LIST
#define DH_DEVSTATE_SD_CARD			0x000A		// Search SD card information(FOR IPC series)
#define DH_DEVSTATE_BURNING_DEV		0x000B		// Search burner information
#define DH_DEVSTATE_BURNING_PROGRESS 0x000C		// Search burning information
#define DH_DEVSTATE_PLATFORM		0x000D		// Search the embedded platform the device supported
#define DH_DEVSTATE_CAMERA			0x000E		// Search camera property information ( for IPC series)£¬pBuf = DHDEV_CAMERA_INFO *£¬there can be several structure.
#define DH_DEVSTATE_SOFTWARE		0x000F		// Search device software version information
#define DH_DEVSTATE_LANGUAGE        0x0010		// Search the audio type the device supported 
#define DH_DEVSTATE_DSP				0x0011		// Search DSP capacity description 
#define	DH_DEVSTATE_OEM				0x0012		// Search OEM information 
#define	DH_DEVSTATE_NET				0x0013		// Search network running status information 
#define DH_DEVSTATE_TYPE			0x0014		// Search device type 
#define DH_DEVSTATE_SNAP			0x0015		// Search snapshot function property(For IPC series)

// Configuration type,corresponding to CLIENT_GetDevConfig and CLIENT_SetDevConfig
#define DH_DEV_DEVICECFG			0x0001		// Device property setup 
#define DH_DEV_NETCFG				0x0002		// Network setup 
#define DH_DEV_CHANNELCFG			0x0003		// Video channel setup
#define DH_DEV_PREVIEWCFG 			0x0004		// Preview parameter setup
#define DH_DEV_RECORDCFG			0x0005		// Record setup
#define DH_DEV_COMMCFG				0x0006		// COM property setup 
#define DH_DEV_ALARMCFG 			0x0007		// Alarm property setup
#define DH_DEV_TIMECFG 				0x0008		// DVR time setup 
#define DH_DEV_TALKCFG				0x0009		// Audio talk parameter setup 
#define DH_DEV_AUTOMTCFG			0x000A		// Auto matrix setup
#define	DH_DEV_VEDIO_MARTIX			0x000B		// Local matrix control strategy setup
#define DH_DEV_MULTI_DDNS			0x000C		//  Multiple ddns setup 
#define DH_DEV_SNAP_CFG				0x000D		// Snapshot corresponding setup 
#define DH_DEV_WEB_URL_CFG			0x000E		// HTTP path setup 
#define DH_DEV_FTP_PROTO_CFG		0x000F		// FTP upload setup 
#define DH_DEV_INTERVIDEO_CFG		0x0010		// Plaform embedded setup. Now the channel parameter represents the platform type. 
												// channel=4£ºBell alcatel£»channel=10£ºZTE Netview£»channel=11£ºU CNC
#define DH_DEV_VIDEO_COVER			0x0011		//Privacy mask setup
#define DH_DEV_TRANS_STRATEGY		0x0012		// Transmission strategy. Video quality\Fluency
#define DH_DEV_DOWNLOAD_STRATEGY	0x0013		//  Record download strategy setup:high-speed\general download
#define DH_DEV_WATERMAKE_CFG		0x0014		// Video watermark setup
#define DH_DEV_WLAN_CFG				0x0015		// Wireless network setup 
#define DH_DEV_WLAN_DEVICE_CFG		0x0016		// Search wireless device setup 
#define DH_DEV_REGISTER_CFG			0x0017		// Auto register parameter setup 
#define DH_DEV_CAMERA_CFG			0x0018		// Camera property setup 
#define DH_DEV_INFRARED_CFG 		0x0019		// IR alarm setup 
#define DH_DEV_SNIFFER_CFG			0x001A		//  Sniffer setup 
#define DH_DEV_MAIL_CFG				0x001B		// Mail setup 
#define DH_DEV_DNS_CFG				0x001C		// DNS setup 
#define DH_DEV_NTP_CFG				0x001D		// NTP setup
#define DH_DEV_AUDIO_DETECT_CFG		0x001E		// Audio detection setup 
#define DH_DEV_STORAGE_STATION_CFG  0x001F      // Storage position setup 
#define DH_DEV_PTZ_OPT_CFG			0x0020		// PTZ operation property(It is invalid now. Please use CLIENT_GetPtzOptAttr to get PTZ operation property.)
#define DH_DEV_DST_CFG				0x0021      // Daylight Saving Time (DST)setup
#define DH_DEV_ALARM_CENTER_CFG		0x0022		// Alarm centre setup
#define DH_DEV_VIDEO_OSD_CFG        0x0023		// VIdeo OSD setup
#define DH_DEV_USER_END_CFG			1000

// Alarm type, corresponding to CLIENT_StartListen
#define DH_COMM_ALARM				0x1100		// General alarm(Including external alarm, video loss and motion detection)
#define DH_SHELTER_ALARM			0x1101		// Camera masking alarm 
#define DH_DISK_FULL_ALARM			0x1102		// HDD full alarm 
#define DH_DISK_ERROR_ALARM			0x1103		// HDD malfunction alarm 
#define DH_SOUND_DETECT_ALARM		0x1104		// Audio detection alarm 
#define DH_ALARM_DECODER_ALARM		0x1105		// Alarm decoder alarm 

// Extensive alarm type,corresponding to CLIENT_StartListenEx
#define DH_ALARM_ALARM_EX			0x2101		// External alarm 
#define DH_MOTION_ALARM_EX			0x2102		// Motion detection alarm 
#define DH_VIDEOLOST_ALARM_EX		0x2103		// Video loss alarm 
#define DH_SHELTER_ALARM_EX			0x2104		// Camera masking alarm 
#define DH_SOUND_DETECT_ALARM_EX	0x2105		// Audio detection alarm 
#define DH_DISKFULL_ALARM_EX		0x2106		// HDD full alarm 
#define DH_DISKERROR_ALARM_EX		0x2107		// HDD malfunction alarm 
#define DH_ENCODER_ALARM_EX			0x210A		// Encoder alarm 
#define DH_URGENCY_ALARM_EX			0x210B		// Emergency alarm 
#define DH_WIRELESS_ALARM_EX		0x210C		// Wireless alarm 
#define DH_NEW_SOUND_DETECT_ALARM_EX 0x210D		// New auido detection alarm. Please refer to DH_NEW_SOUND_ALARM_STATE for alarm information structure£»
#define DH_ALARM_DECODER_ALARM_EX	0x210E		// Alarm decoder alarm 

// Event type
#define DH_CONFIG_RESULT_EVENT_EX	0x3000		// Modify the return code of the setup. Please refer to DEV_SET_RESULT for returned structure.
#define DH_REBOOT_EVENT_EX			0x3001		//  Device reboot event. Current modification becomes valid unitl sending out the reboot command. 
#define DH_AUTO_TALK_START_EX		0x3002		// Device automatically invites to begin audio talk 
#define DH_AUTO_TALK_STOP_EX		0x3003		// Device actively stop audio talk 
#define DH_CONFIG_CHANGE_EX			0x3004		// Device setup changes.

// Alarm type of alarm upload function,corresponding to CLIENT_StartService¡¢NEW_ALARM_UPLOAD structure.
#define DH_UPLOAD_ALARM					0x4000		// External alarm 		
#define DH_UPLOAD_MOTION_ALARM			0x4001		// Motion detection alarm 
#define DH_UPLOAD_VIDEOLOST_ALARM		0x4002		//Video loss alarm 
#define DH_UPLOAD_SHELTER_ALARM			0x4003		// Camera masking alarm 
#define DH_UPLOAD_SOUND_DETECT_ALARM	0x4004		//Audio detection alarm 
#define DH_UPLOAD_DISKFULL_ALARM		0x4005		// HDD full alarm 
#define DH_UPLOAD_DISKERROR_ALARM		0x4006		// HDD malfunction alarm 
#define DH_UPLOAD_ENCODER_ALARM			0x4007		//Encoder alarm 
#define DH_UPLOAD_DECODER_ALARM			0x400B		// Alarm decoder alarm 
#define DH_UPLOAD_EVENT					0x400C		// Scheduled upload 

// Resolution list. Use to AND & OR of resolution subnet mask 
#define	DH_CAPTURE_SIZE_D1			0x00000001
#define DH_CAPTURE_SIZE_HD1			0x00000002
#define DH_CAPTURE_SIZE_BCIF		0x00000004
#define DH_CAPTURE_SIZE_CIF			0x00000008
#define DH_CAPTURE_SIZE_QCIF		0x00000010	
#define DH_CAPTURE_SIZE_VGA			0x00000020	
#define DH_CAPTURE_SIZE_QVGA		0x00000040
#define DH_CAPTURE_SIZE_SVCD		0x00000080
#define DH_CAPTURE_SIZE_QQVGA		0x00000100
#define DH_CAPTURE_SIZE_SVGA		0x00000200
#define DH_CAPTURE_SIZE_XVGA		0x00000400
#define DH_CAPTURE_SIZE_WXGA		0x00000800
#define DH_CAPTURE_SIZE_SXGA		0x00001000
#define DH_CAPTURE_SIZE_WSXGA		0x00002000   
#define DH_CAPTURE_SIZE_UXGA		0x00004000
#define DH_CAPTURE_SIZE_WUXGA       0x00008000

// Encode mode list. Use to work AND & OR operation of encode mode mask.
#define DH_CAPTURE_COMP_DIVX_MPEG4	0x00000001
#define DH_CAPTURE_COMP_MS_MPEG4 	0x00000002
#define DH_CAPTURE_COMP_MPEG2		0x00000004
#define DH_CAPTURE_COMP_MPEG1		0x00000008
#define DH_CAPTURE_COMP_H263		0x00000010
#define DH_CAPTURE_COMP_MJPG		0x00000020
#define DH_CAPTURE_COMP_FCC_MPEG4	0x00000040
#define DH_CAPTURE_COMP_H264		0x00000080

// Alarm activation operation. Use to work AND & OR operation of alarm activation operation.
#define DH_ALARM_UPLOAD				0x00000001
#define DH_ALARM_RECORD				0x00000002
#define DH_ALARM_PTZ				0x00000004
#define DH_ALARM_MAIL				0x00000008
#define DH_ALARM_TOUR				0x00000010
#define DH_ALARM_TIP				0x00000020
#define DH_ALARM_OUT				0x00000040
#define DH_ALARM_FTP_UL				0x00000080
#define DH_ALARM_BEEP				0x00000100
#define DH_ALARM_VOICE				0x00000200
#define DH_ALARM_SNAP				0x00000400

// Restore default setup mask. Can use to AND & OR operation
#define DH_RESTORE_COMMON			0x00000001	// General setup
#define DH_RESTORE_CODING			0x00000002	// Encode setup
#define DH_RESTORE_VIDEO			0x00000004	// Record setup
#define DH_RESTORE_COMM				0x00000008	// COM setup
#define DH_RESTORE_NETWORK			0x00000010	//network setup
#define DH_RESTORE_ALARM			0x00000020	// Alarm setup
#define DH_RESTORE_VIDEODETECT		0x00000040	// Video detection
#define DH_RESTORE_PTZ				0x00000080	// PTZ control 
#define DH_RESTORE_OUTPUTMODE		0x00000100	// Output mode
#define DH_RESTORE_CHANNELNAME		0x00000200	//Channel name
#define DH_RESTORE_ALL				0x80000000	// Reset all

// PTZ property list
// Lower four bytes subnet mask
#define PTZ_DIRECTION				0x00000001	// Direction
#define PTZ_ZOOM					0x00000002	// Zoom
#define PTZ_FOCUS					0x00000004	// Focus
#define PTZ_IRIS					0x00000008	// Aperture
#define PTZ_ALARM					0x00000010	// Alarm function 
#define PTZ_LIGHT					0x00000020	// Light 
#define PTZ_SETPRESET				0x00000040	// Set preset 
#define PTZ_CLEARPRESET				0x00000080	// Delete preset
#define PTZ_GOTOPRESET				0x00000100	// Go to a preset
#define PTZ_AUTOPANON				0x00000200	// Enable pan
#define PTZ_AUTOPANOFF				0x00000400	// isable pan
#define PTZ_SETLIMIT				0x00000800	// Set limit
#define PTZ_AUTOSCANON				0x00001000	// Enable auto scan
#define PTZ_AUTOSCANOFF				0x00002000	// Disable auto scan 
#define PTZ_ADDTOUR					0x00004000	// Add tour point
#define PTZ_DELETETOUR				0x00008000	// Delete tour point
#define PTZ_STARTTOUR				0x00010000	// Begin tour
#define PTZ_STOPTOUR				0x00020000	// Stop tour
#define PTZ_CLEARTOUR				0x00040000	// Delete tour
#define PTZ_SETPATTERN				0x00080000	// Set pattern
#define PTZ_STARTPATTERN			0x00100000	// Enbale pattern
#define PTZ_STOPPATTERN				0x00200000	// Disable pattern
#define PTZ_CLEARPATTERN			0x00400000	// Delete pattern
#define PTZ_POSITION				0x00800000	// Position 
#define PTZ_AUX						0x01000000	// auxiliary button 
#define PTZ_MENU					0x02000000	// Speed dome menu 
#define PTZ_EXIT					0x04000000	// Exit speed dome menu 
#define PTZ_ENTER					0x08000000	// Confirm
#define PTZ_ESC						0x10000000	// Cancel 
#define PTZ_MENUUPDOWN				0x20000000	// Menu up/down
#define PTZ_MENULEFTRIGHT			0x40000000	// Menu left/right 
#define PTZ_OPT_NUM					0x80000000	// Operation amount
// Higher four bytes subnet mask
#define PTZ_DEV						0x00000001	// PTZ control 
#define PTZ_MATRIX					0x00000002	// Matrix control 

// Snapshot video encode type
#define CODETYPE_MPEG4				0
#define CODETYPE_H264				1
#define CODETYPE_JPG				2

// Bit stream control control list
#define DH_CAPTURE_BRC_CBR			0
#define DH_CAPTURE_BRC_VBR			1
//#define DH_CAPTURE_BRC_MBR		2

// Error type code. Corresponding to the return value of CLIENT_GetLastError
#define _EC(x)						(0x80000000|x)
#define NET_NOERROR 				0			// No error 
#define NET_ERROR					-1			// Unknow error
#define NET_SYSTEM_ERROR			_EC(1)		// Windows system error
#define NET_NETWORK_ERROR			_EC(2)		// Protocl error it may result from network timeout
#define NET_DEV_VER_NOMATCH			_EC(3)		// Device protocol does not match 
#define NET_INVALID_HANDLE			_EC(4)		// Handle is invalid
#define NET_OPEN_CHANNEL_ERROR		_EC(5)		// Failed to open channel 
#define NET_CLOSE_CHANNEL_ERROR		_EC(6)		// Failed to close channel 
#define NET_ILLEGAL_PARAM			_EC(7)		// User parameter is illegal 
#define NET_SDK_INIT_ERROR			_EC(8)		// SDK initialization error 
#define NET_SDK_UNINIT_ERROR		_EC(9)		// SDK clear error 
#define NET_RENDER_OPEN_ERROR		_EC(10)		// Error occurs when apply for render resources.
#define NET_DEC_OPEN_ERROR			_EC(11)		// Error occurs when opening the decoder library 
#define NET_DEC_CLOSE_ERROR			_EC(12)		// Error occurs when closing the decoder library 
#define NET_MULTIPLAY_NOCHANNEL		_EC(13)		// The detected channel number is 0 in multiple-channel preview. 
#define NET_TALK_INIT_ERROR			_EC(14)		// Failed to initialize record library 
#define NET_TALK_NOT_INIT			_EC(15)		// The record library has not been initialized
#define	NET_TALK_SENDDATA_ERROR		_EC(16)		// Error occurs when sending out audio data 
#define NET_REAL_ALREADY_SAVING		_EC(17)		// The real-time has been protected.
#define NET_NOT_SAVING				_EC(18)		// The real-time data has not been save.
#define NET_OPEN_FILE_ERROR			_EC(19)		// Error occurs when opening the file.
#define NET_PTZ_SET_TIMER_ERROR		_EC(20)		// Failed to enable PTZ to control timer.
#define NET_RETURN_DATA_ERROR		_EC(21)		// Error occurs when verify returned data.
#define NET_INSUFFICIENT_BUFFER		_EC(22)		// There is no sufficient buffer.
#define NET_NOT_SUPPORTED			_EC(23)		// The current SDK does not support this fucntion.
#define NET_NO_RECORD_FOUND			_EC(24)		// There is no searched result.
#define NET_NOT_AUTHORIZED			_EC(25)		// You have no operation right.
#define NET_NOT_NOW					_EC(26)		// Can not operate right now. 
#define NET_NO_TALK_CHANNEL			_EC(27)		// There is no audio talk channel.
#define NET_NO_AUDIO				_EC(28)		// There is no audio.
#define NET_NO_INIT					_EC(29)		// The network SDK has not been initialized.
#define NET_DOWNLOAD_END			_EC(30)		// The download completed.
#define NET_EMPTY_LIST				_EC(31)		// There is no searched result.
#define NET_ERROR_GETCFG_SYSATTR	_EC(32)		// Failed to get system property setup.
#define NET_ERROR_GETCFG_SERIAL		_EC(33)		// Failed to get SN.
#define NET_ERROR_GETCFG_GENERAL	_EC(34)		// Failed to get general property.
#define NET_ERROR_GETCFG_DSPCAP		_EC(35)		// Failed to get DSP capacity description.
#define NET_ERROR_GETCFG_NETCFG		_EC(36)		// Failed to get network channel setup.
#define NET_ERROR_GETCFG_CHANNAME	_EC(37)		// Failed to get channel name.
#define NET_ERROR_GETCFG_VIDEO		_EC(38)		// Failed to get video property.
#define NET_ERROR_GETCFG_RECORD		_EC(39)		// Failed to get record setup
#define NET_ERROR_GETCFG_PRONAME	_EC(40)		// Failed to get decoder protocol name 
#define NET_ERROR_GETCFG_FUNCNAME	_EC(41)		// Failed to get 232 COM function name.
#define NET_ERROR_GETCFG_485DECODER	_EC(42)		// Failed to get decoder property
#define NET_ERROR_GETCFG_232COM		_EC(43)		// Failed to get 232 COM setup
#define NET_ERROR_GETCFG_ALARMIN	_EC(44)		// Failed to get external alarm input setup
#define NET_ERROR_GETCFG_ALARMDET	_EC(45)		// Failed to get motion detection alarm
#define NET_ERROR_GETCFG_SYSTIME	_EC(46)		// Failed to get device time
#define NET_ERROR_GETCFG_PREVIEW	_EC(47)		// Failed to get preview parameter
#define NET_ERROR_GETCFG_AUTOMT		_EC(48)		// Failed to get audo maitenance setup
#define NET_ERROR_GETCFG_VIDEOMTRX	_EC(49)		// Failed to get video matrix setup
#define NET_ERROR_GETCFG_COVER		_EC(50)		// Failed to get privacy mask zone setup
#define NET_ERROR_GETCFG_WATERMAKE	_EC(51)		// Failed to get video watermark setup
#define NET_ERROR_SETCFG_GENERAL	_EC(55)		// Failed to modify general property
#define NET_ERROR_SETCFG_NETCFG		_EC(56)		// Failed to modify channel setup
#define NET_ERROR_SETCFG_CHANNAME	_EC(57)		// Faiedl to modify channel name
#define NET_ERROR_SETCFG_VIDEO		_EC(58)		// Failed to modify video channel 
#define NET_ERROR_SETCFG_RECORD		_EC(59)		// Failed to modify record setup 
#define NET_ERROR_SETCFG_485DECODER	_EC(60)		// Failed to mdofiy decoder property 
#define NET_ERROR_SETCFG_232COM		_EC(61)		// Failed to modify 232 COM setup 
#define NET_ERROR_SETCFG_ALARMIN	_EC(62)		// Failed to modify external input alarm setup
#define NET_ERROR_SETCFG_ALARMDET	_EC(63)		// Failed to modify motion detection alarm setup 
#define NET_ERROR_SETCFG_SYSTIME	_EC(64)		// Failed to mdofiy device time 
#define NET_ERROR_SETCFG_PREVIEW	_EC(65)		// Failed to modify preview parameter
#define NET_ERROR_SETCFG_AUTOMT		_EC(66)		// Failed to modify auto maintenance setup 
#define NET_ERROR_SETCFG_VIDEOMTRX	_EC(67)		// Failed to modify video matrix setup 
#define NET_ERROR_SETCFG_COVER		_EC(68)		// Failed to modify privacy mask zone
#define NET_ERROR_SETCFG_WATERMAKE	_EC(69)		// Failed to modify video watermark setup 
#define NET_ERROR_SETCFG_WLAN		_EC(70)		// Failed to modify wireless network information 
#define NET_ERROR_SETCFG_WLANDEV	_EC(71)		// Failed to select wireless network device
#define NET_ERROR_SETCFG_REGISTER	_EC(72)		// Failed to modify the actively registration parameter setup.
#define NET_ERROR_SETCFG_CAMERA		_EC(73)		// Failed to modify camera property
#define NET_ERROR_SETCFG_INFRARED	_EC(74)		// Failed to modify IR alarm setup
#define NET_ERROR_SETCFG_SOUNDALARM	_EC(75)		// Failed to modify audio alarm setup
#define NET_ERROR_SETCFG_STORAGE    _EC(76)		// Failed to modify storage postion setup
#define NET_AUDIOENCODE_NOTINIT		_EC(77)		// The audio encode port has not been successfully initialized. 
#define NET_DATA_TOOLONGH			_EC(78)		// The data are too long.
#define NET_UNSUPPORTED				_EC(79)		// The device does not support current operation. 
#define NET_DEVICE_BUSY				_EC(80)		// Device resources is not sufficient.
#define NET_SERVER_STARTED			_EC(81)		// The server has boot up 
#define NET_SERVER_STOPPED			_EC(82)		// The server has not fully boot up 
#define NET_LISTER_INCORRECT_SERIAL	_EC(83)		// Input serial number is not correct.
#define NET_QUERY_DISKINFO_FAILED	_EC(84)		// Failed to get HDD information.
#define NET_LOGIN_ERROR_PASSWORD	_EC(100)	// Password is not correct
#define NET_LOGIN_ERROR_USER		_EC(101)	// The account does not exist
#define NET_LOGIN_ERROR_TIMEOUT		_EC(102)	// Time out for log in returned value.
#define NET_LOGIN_ERROR_RELOGGIN	_EC(103)	// The account has logged in 
#define NET_LOGIN_ERROR_LOCKED		_EC(104)	// The accoutn has been locked
#define NET_LOGIN_ERROR_BLACKLIST	_EC(105)	// The account bas been in the black list
#define NET_LOGIN_ERROR_BUSY		_EC(106)	// Resources are not sufficient. System is busy now.
#define NET_LOGIN_ERROR_CONNECT		_EC(107)	// Time out. Please check network and try agaian.
#define NET_LOGIN_ERROR_NETWORK		_EC(108)	// Network conenction failed.
#define NET_LOGIN_ERROR_SUBCONNECT	_EC(109)	// Successfully logged in the device but can not create video channel. Please check network connection.
#define NET_RENDER_SOUND_ON_ERROR	_EC(120)	// Error occurs when Render library open audio.
#define NET_RENDER_SOUND_OFF_ERROR	_EC(121)	// Error occurs when Render libraty close audio 
#define NET_RENDER_SET_VOLUME_ERROR	_EC(122)	// Error occurs when Render library control vaolume
#define NET_RENDER_ADJUST_ERROR		_EC(123)	// Error occurs when Render library set video parameter
#define NET_RENDER_PAUSE_ERROR		_EC(124)	// Error occurs when Render library pause play
#define NET_RENDER_SNAP_ERROR		_EC(125)	// Render library snapshot error
#define NET_RENDER_STEP_ERROR		_EC(126)	// Render library stepper error
#define NET_RENDER_FRAMERATE_ERROR	_EC(127)	// Error occurs when Render library set frame rate.
#define NET_GROUP_EXIST				_EC(140)	// Group name has been existed.
#define	NET_GROUP_NOEXIST			_EC(141)	// The grouo name does not exsit. 
#define NET_GROUP_RIGHTOVER			_EC(142)	// The group right exceeds the right list!
#define NET_GROUP_HAVEUSER			_EC(143)	// The group can not be removed since there is user in it!
#define NET_GROUP_RIGHTUSE			_EC(144)	// The user has used one of the group right. It can not be removed. 
#define NET_GROUP_SAMENAME			_EC(145)	// New group name has been existed
#define	NET_USER_EXIST				_EC(146)	// The user name has been existed
#define NET_USER_NOEXIST			_EC(147)	// The accoutn does not exist.
#define NET_USER_RIGHTOVER			_EC(148)	// User right exceeds the group right. 
#define NET_USER_PWD				_EC(149)	// Reserved account. It does not allow to be modified.
#define NET_USER_FLASEPWD			_EC(150)	// Pasword is not correct
#define NET_USER_NOMATCHING			_EC(151)	// Password is invalid
#define NET_ERROR_GETCFG_ETHERNET	_EC(300)	// Failed to get network card setup.
#define NET_ERROR_GETCFG_WLAN		_EC(301)	// Failed to get wireless network information.
#define NET_ERROR_GETCFG_WLANDEV	_EC(302)	// Failed to get wireless network device.
#define NET_ERROR_GETCFG_REGISTER	_EC(303)	// Failed to get acitvely registration parameter.
#define NET_ERROR_GETCFG_CAMERA		_EC(304)	// Failed to get camera property 
#define NET_ERROR_GETCFG_INFRARED	_EC(305)	// Failed to get IR alarm setup
#define NET_ERROR_GETCFG_SOUNDALARM	_EC(306)	// Failed to get audio alarm setup
#define NET_ERROR_GETCFG_STORAGE    _EC(307)	// Failed to get storage position 
#define NET_ERROR_GETCFG_MAIL		_EC(308)	// Failed to get mail setup.
#define NET_CONFIG_DEVBUSY			_EC(309)	// Can not set right now. 
#define NET_CONFIG_DATAILLEGAL		_EC(310)	// The configuration setup data are illegal.
#define NET_ERROR_GETCFG_DST        _EC(311)    // Failed to get DST setup
#define NET_ERROR_SETCFG_DST        _EC(312)    // Failed to set DST 
#define NET_ERROR_GETCFG_VIDEO_OSD  _EC(313)    // Failed to get video osd setup.
#define NET_ERROR_SETCFG_VIDEO_OSD  _EC(314)    // Failed to set video osd 


/************************************************************************
 ** Enumeration Definition
 ***********************************************************************/
// Device type
enum NET_DEVICE_TYPE 
{
	NET_PRODUCT_NONE = 0,
	NET_DVR_NONREALTIME_MACE,					// Non real-time MACE
	NET_DVR_NONREALTIME,						// Non real-time
	NET_NVS_MPEG1,								// Network video server
	NET_DVR_MPEG1_2,							// MPEG1 2-ch DVR
	NET_DVR_MPEG1_8,							// MPEG1 8-ch DVR
	NET_DVR_MPEG4_8,							// MPEG4 8-ch DVR
	NET_DVR_MPEG4_16,							// MPEG4 16-ch DVR
	NET_DVR_MPEG4_SX2,							// LB series DVR
	NET_DVR_MEPG4_ST2,							// GB  series DVR
	NET_DVR_MEPG4_SH2,							// HB  series DVR
	NET_DVR_MPEG4_GBE,							// GBE  series DVR
	NET_DVR_MPEG4_NVSII,						// II network video server
	NET_DVR_STD_NEW,							// New stantdard configuration protocol
	NET_DVR_DDNS,								// DDNS server
	NET_DVR_ATM,								// ATM series 
	NET_NB_SERIAL,								// 2nd non real-time NB series DVR
	NET_LN_SERIAL,								// LN  sereis 
	NET_BAV_SERIAL,								// BAV series
	NET_SDIP_SERIAL,							// SDIP series
	NET_IPC_SERIAL,								// IPC series
	NET_NVS_B,									// NVS B series
	NET_NVS_C,									// NVS H series 
	NET_NVS_S,									// NVS S series
	NET_NVS_E,									// NVS E series
	NET_DVR_NEW_PROTOCOL						// Search device type from QueryDevState. it is in string format */
};

// Language type
typedef enum __LANGUAGE_TYPE
{
	DH_LANGUAGE_ENGLISH,						// English 
	DH_LANGUAGE_CHINESE_SIMPLIFIED,				// Simplfied Chinese
	DH_LANGUAGE_CHINESE_TRADITIONAL,			// Traditional Chinese
	DH_LANGUAGE_ITALIAN,						// Italian 
	DH_LANGUAGE_SPANISH,						// Spainish
	DH_LANGUAGE_JAPANESE,						// Japanese
	DH_LANGUAGE_RUSSIAN,						// Russian 
	DH_LANGUAGE_FRENCH,							// French
	DH_LANGUAGE_GERMAN, 						// German
	DH_LANGUAGE_PORTUGUESE,						// Portuguese
	DH_LANGUAGE_TURKEY,							// Turkey	
	DH_LANGUAGE_POLISH,							// Polish
	DH_LANGUAGE_ROMANIAN,						// Romanian 
	DH_LANGUAGE_HUNGARIAN,						// Hungarian
	DH_LANGUAGE_FINNISH,						// Finnish
	DH_LANGUAGE_ESTONIAN,						// Estonian	
	DH_LANGUAGE_KOREAN,							// Korean
	DH_LANGUAGE_FARSI,							// Farsi	
	DH_LANGUAGE_DANSK,							// Denmark
	DH_LANGUAGE_CZECHISH,						// Czechish
	DH_LANGUAGE_BULGARIA,						// Bulgaria
	DH_LANGUAGE_SLOVAKIAN,						// Slovakian
	DH_LANGUAGE_SLOVENIA,						// Slovenia
	DH_LANGUAGE_CROATIAN,						// Croatian
	DH_LANGUAGE_DUTCH,							// Dutch
	DH_LANGUAGE_GREEK,							// Greek
	DH_LANGUAGE_UKRAINIAN,						// Ukrainian
	DH_LANGUAGE_SWEDISH,						// Swedish
	DH_LANGUAGE_SERBIAN,						// Serbian
	DH_LANGUAGE_VIETNAMESE,						// Vietnamese
	DH_LANGUAGE_LITHUANIAN,						// Lithuanian
	DH_LANGUAGE_FILIPINO,						// Filipino
	DH_LANGUAGE_ARABIC,							// Arabic
	DH_LANGUAGE_CATALAN,						// Catalan
	DH_LANGUAGE_LATVIAN,						// Latvian
} DH_LANGUAGE_TYPE;

// Upgrade type
typedef enum __EM_UPGRADE_TYPE
{
	DH_UPGRADE_BIOS_TYPE = 1,					// BIOS  upgrade
	DH_UPGRADE_WEB_TYPE,						// WEB upgrade
	DH_UPGRADE_BOOT_YPE,						// BOOT upgrade
	DH_UPGRADE_CHARACTER_TYPE,					// Chinese character library
	DH_UPGRADE_LOGO_TYPE,						// LOGO
	DH_UPGRADE_EXE_TYPE,						// EXE such as player
} EM_UPGRADE_TYPE;

// Record related (schedule,motion detection,alarm)
typedef enum _REC_TYPE
{
	DH_REC_TYPE_TIM = 0,
	DH_REC_TYPE_MTD,
	DH_REC_TYPE_ALM,
	DH_REC_TYPE_NUM,
} REC_TYPE;

/////////////////////////////////Monitor related/////////////////////////////////

// Preview type.Corresponding to CLIENT_RealPlayEx
typedef enum _RealPlayType
{
	DH_RType_Realplay = 0,						// Realt-time preview
	DH_RType_Multiplay,							// Multiple-channel preview 
		
	DH_RType_Realplay_0,						// Real-time monitor-main stream. It is the same as DH_RType_Realplay
	DH_RType_Realplay_1,						// 1 Real-time montior---extra stream 1
	DH_RType_Realplay_2,						// 2Real-time monitor-- extra stream 2
	DH_RType_Realplay_3,						// 3 Real-time monitor -- extra stream 3
		
	DH_RType_Multiplay_1,						// Multiple-channel preview-- 1-window 
	DH_RType_Multiplay_4,						// Multiple-channel preview--4-window
	DH_RType_Multiplay_8,						// Multiple-channel preview--8-window
	DH_RType_Multiplay_9,						// Multiple-channel preview--9-window
	DH_RType_Multiplay_16,						// Multiple-channel preview--16-window
	DH_RType_Multiplay_6,						// Multiple-channel preview--6-window
	DH_RType_Multiplay_12,						// Multiple-channel preview--12-window
} DH_RealPlayType;

/////////////////////////////////About PTZ/////////////////////////////////

// General PTZ control command
typedef enum _PTZ_ControlType
{
	DH_PTZ_UP_CONTROL = 0,						// Up
	DH_PTZ_DOWN_CONTROL,						// Down
	DH_PTZ_LEFT_CONTROL,						// Left
	DH_PTZ_RIGHT_CONTROL,						// Right
	DH_PTZ_ZOOM_ADD_CONTROL,					// +Zoom in 
	DH_PTZ_ZOOM_DEC_CONTROL,					// -Zoom out 
	DH_PTZ_FOCUS_ADD_CONTROL,					// +Zoom in 
	DH_PTZ_FOCUS_DEC_CONTROL,					// -Zoom out 
	DH_PTZ_APERTURE_ADD_CONTROL,				// + Aperture 
	DH_PTZ_APERTURE_DEC_CONTROL,				// -Aperture
    DH_PTZ_POINT_MOVE_CONTROL,					// Go to preset 
    DH_PTZ_POINT_SET_CONTROL,					// Set 
    DH_PTZ_POINT_DEL_CONTROL,					// Delete
    DH_PTZ_POINT_LOOP_CONTROL,					// Tour 
    DH_PTZ_LAMP_CONTROL							// Light and wiper 
} DH_PTZ_ControlType;

// PTZ control extensive command 
typedef enum _EXTPTZ_ControlType
{
	DH_EXTPTZ_LEFTTOP = 0x20,					// Upper left
	DH_EXTPTZ_RIGHTTOP,							// Upper right 
	DH_EXTPTZ_LEFTDOWN,							// Down left
	DH_EXTPTZ_RIGHTDOWN,						// Down right 
	DH_EXTPTZ_ADDTOLOOP,						// Add preset to tour		tour	 presse value
	DH_EXTPTZ_DELFROMLOOP,						// Delte preset in tour	tour	 preset value
    DH_EXTPTZ_CLOSELOOP,						// Delete tour	   tour		
	DH_EXTPTZ_STARTPANCRUISE,					// Begin pan rotation		
	DH_EXTPTZ_STOPPANCRUISE,					// Stop pan rotation		
	DH_EXTPTZ_SETLEFTBORDER,					// Set left limit		
	DH_EXTPTZ_SETRIGHTBORDER,					// Set right limit	
	DH_EXTPTZ_STARTLINESCAN,					// Begin scanning			
    DH_EXTPTZ_CLOSELINESCAN,					// Stop scanning		
    DH_EXTPTZ_SETMODESTART,						// Start mode	mode line		
    DH_EXTPTZ_SETMODESTOP,						// Stop mode	       mode line		
	DH_EXTPTZ_RUNMODE,							// Enable mode	Mode line		
	DH_EXTPTZ_STOPMODE,							// Disable mode	Mode line	
	DH_EXTPTZ_DELETEMODE,						// Delete mode	Mode line
	DH_EXTPTZ_REVERSECOMM,						// Flip
	DH_EXTPTZ_FASTGOTO,							// 3D position	X address(8192)	Y address(8192)	zoom(4)
	DH_EXTPTZ_AUXIOPEN,							// auxiliary open	Auxiliary point	
	DH_EXTPTZ_AUXICLOSE,						// Auxiliary close	Auxiliary point
	DH_EXTPTZ_OPENMENU = 0x36,					// Open dome menu 
	DH_EXTPTZ_CLOSEMENU,						// Close menu 
	DH_EXTPTZ_MENUOK,							// Confirm menu 
	DH_EXTPTZ_MENUCANCEL,						// Cancel menu 
	DH_EXTPTZ_MENUUP,							// menu up 
	DH_EXTPTZ_MENUDOWN,							// menu down
	DH_EXTPTZ_MENULEFT,							// menu left
	DH_EXTPTZ_MENURIGHT,						// Menu right 
	DH_EXTPTZ_ALARMHANDLE = 0x40,				// Alarm activate PTZ parm1£ºAlarm input channel £»parm2£ºAlarm activation type  1-preset 2-scan 3-tour£»parm 3£ºactivation value£¬such as preset value.
	DH_EXTPTZ_MATRIXSWITCH = 0x41,				// Matrix switch parm1£º monitor number(video output number )£»parm2£º video input number£»  parm3£ºmatrix number 
	DH_EXTPTZ_LIGHTCONTROL,						// Light controller
	DH_EXTPTZ_UP_TELE = 0x70,					// Up + TELE param1=speed (1-8)£¬ 
	DH_EXTPTZ_DOWN_TELE,						// Down + TELE
	DH_EXTPTZ_LEFT_TELE,						// Left + TELE
	DH_EXTPTZ_RIGHT_TELE,						// Right + TELE
	DH_EXTPTZ_LEFTUP_TELE,						// Upper left + TELE
	DH_EXTPTZ_LEFTDOWN_TELE,					// Down left + TELE
	DH_EXTPTZ_TIGHTUP_TELE,						// Upper right + TELE
	DH_EXTPTZ_RIGHTDOWN_TELE,					// Down right + TELE
	DH_EXTPTZ_UP_WIDE,							// Up + WIDE param1=speed (1-8)£¬ 
	DH_EXTPTZ_DOWN_WIDE,						// Down + WIDE
	DH_EXTPTZ_LEFT_WIDE,						// Left + WIDE
	DH_EXTPTZ_RIGHT_WIDE,						// Right + WIDE
	DH_EXTPTZ_LEFTUP_WIDE,						// Upper left + WIDE
	DH_EXTPTZ_LEFTDOWN_WIDE,					// Down legt+ WIDE
	DH_EXTPTZ_TIGHTUP_WIDE,						// Upper right + WIDE
	DH_EXTPTZ_RIGHTDOWN_WIDE,					// Down right + WIDE
	DH_EXTPTZ_TOTAL,							// max command value
} DH_EXTPTZ_ControlType;

/////////////////////////////////About Log /////////////////////////////////

// Log search type 
typedef enum _DH_LOG_QUERY_TYPE
{
	DHLOG_ALL = 0,								// All logs
	DHLOG_SYSTEM,								// System logs 
	DHLOG_CONFIG,								// Configuration logs 
	DHLOG_STORAGE,								// Storage logs
	DHLOG_ALARM,								// Alarm logs 
	DHLOG_RECORD,								// Record related
	DHLOG_ACCOUNT,								// Account related
	DHLOG_CLEAR,								// Clear log 
	DHLOG_PLAYBACK								// Playback related 
} DH_LOG_QUERY_TYPE;

// Log Type
typedef enum _DH_LOG_TYPE
{
	DH_LOG_REBOOT = 0x0000,						// Device reboot 
	DH_LOG_SHUT,								// Shut down device 
	DH_LOG_CONFSAVE = 0x0100,					// Save configuration 
	DH_LOG_CONFLOAD,							// Read configuration 
	DH_LOG_FSERROR = 0x0200,					// File system error
	DH_LOG_HDD_WERR,							// HDD write error 
	DH_LOG_HDD_RERR,							// HDD read error
	DH_LOG_HDD_TYPE,							// Set HDD type 
	DH_LOG_HDD_FORMAT,							// Format HDD
	DH_LOG_HDD_NOSPACE,							// Current working HDD space is not sufficient
	DH_LOG_HDD_TYPE_RW,							// Set HDD type as read-write 
	DH_LOG_HDD_TYPE_RO,							// Set HDD type as read-only
	DH_LOG_HDD_TYPE_RE,							// Set HDD type as redundant 
	DH_LOG_ALM_IN = 0x0300,						// External alarm begin 
	DH_LOG_NETALM_IN,							// Network alarm input 
	DH_LOG_ALM_END = 0x0302,					// External input alarm stop 
	DH_LOG_LOSS_IN,								// Video loss alarm begin 
	DH_LOG_LOSS_END,							// Video loss alarm stop
	DH_LOG_MOTION_IN,							// Motion detection alarm begin 
	DH_LOG_MOTION_END,							// Motion detection alarm stop 
	DH_LOG_ALM_BOSHI,							// Annuciator alarm input 
	DH_LOG_NET_ABORT = 0x0308,					// Network disconnected 
	DH_LOG_NET_ABORT_RESUME,					// Network connection restore 
	DH_LOG_CODER_BREAKDOWN,						// Encoder error
	DH_LOG_CODER_BREAKDOWN_RESUME,				// Encoder error restore 
	DH_LOG_BLIND_IN,							// Camera masking 
	DH_LOG_BLIND_END,							// Restroe camera masking 
	DH_LOG_ALM_TEMP_HIGH,						// High temperature 
	DH_LOG_ALM_VOLTAGE_LOW,						// Low voltage
	DH_LOG_ALM_BATTERY_LOW,						// Battery capacity is not sufficient 
	DH_LOG_ALM_ACC_BREAK,						// ACC power off 
	DH_LOG_INFRAREDALM_IN = 0x03a0,				// Wireless alarm begin 
	DH_LOG_INFRAREDALM_END,						// Wireless alarm end 
	DH_LOG_IPCONFLICT,							// IP conflict 
	DH_LOG_IPCONFLICT_RESUME,					// IP restore 
	DH_LOG_AUTOMATIC_RECORD = 0x0400,			// Auto record 
	DH_LOG_MANUAL_RECORD = 0x0401,				// Manual record 
	DH_LOG_CLOSED_RECORD,						// Stop record 
	DH_LOG_LOGIN = 0x0500,						// Log in 
	DH_LOG_LOGOUT,								// Log off 
	DH_LOG_ADD_USER,							// Add user
	DH_LOG_DELETE_USER,							// Delete user
	DH_LOG_MODIFY_USER,							// Modify user 
	DH_LOG_ADD_GROUP,							// Add user group 
	DH_LOG_DELETE_GROUP,						// Delete user group 
	DH_LOG_MODIFY_GROUP,						// Modify user group 
	DH_LOG_CLEAR = 0x0600,						// Clear log 
	DH_LOG_SEARCHLOG,							// Search log 
	DH_LOG_SEARCH = 0x0700,						// Search record 
	DH_LOG_DOWNLOAD,							// Record download
	DH_LOG_PLAYBACK,							// Record playback
	DH_LOG_BACKUP,								// Backup recorded file 
	DH_LOG_BACKUPERROR,							// Failed to backup recorded file

	DH_LOG_TYPE_NR = 7,
} DH_LOG_TYPE;

// Extensive log type. Correponding to CLIENT_QueryLogEx£¬ Condition (int nType = 1£» parameter reserved = &nType)
typedef enum _DH_NEWLOG_TYPE
{
	DH_NEWLOG_REBOOT = 0x0000,					// Reboot device 
	DH_NEWLOG_SHUT,								// Shut down device 
	DH_NEWLOG_CONFSAVE = 0x0100,				// Save configuration 
	DH_NEWLOG_CONFLOAD,							// Read configuration
	DH_NEWLOG_FSERROR = 0x0200,					// File system error
	DH_NEWLOG_HDD_WERR,							// HDD read error
	DH_NEWLOG_HDD_RERR,							// HDD write error
	DH_NEWLOG_HDD_TYPE,							// Set HDD type
	DH_NEWLOG_HDD_FORMAT,						// Format HDD
	DH_NEWLOG_HDD_NOSPACE,						// Current working HDD capacity is insufficient 
	DH_NEWLOG_HDD_TYPE_RW,						// Set HDD type as read-write
	DH_NEWLOG_HDD_TYPE_RO,						// Set HDD type as read-only 
	DH_NEWLOG_HDD_TYPE_RE,						// Set HDD type as redundant
	DH_NEWLOG_ALM_IN = 0x0300,					// External alarm input begin 
	DH_NEWLOG_NETALM_IN,						// Network alarm 
	DH_NEWLOG_ALM_END,							// External input alarm stop
	DH_NEWLOG_LOSS_IN,							// Video loss alarm begin
	DH_NEWLOG_LOSS_END,							// Video loss alarm stop 
	DH_NEWLOG_MOTION_IN,						// Motion detection alarm begin 
	DH_NEWLOG_MOTION_END,						// Motion detection alarm stop 
	DH_NEWLOG_ALM_BOSHI,						// Annunciator alarm input 
	DH_NEWLOG_NET_ABORT = 0x0308,				// Network disconnected 
	DH_NEWLOG_NET_ABORT_RESUME,					// Restore network 
	DH_NEWLOG_CODER_BREAKDOWN,					// Encoder error 
	DH_NEWLOG_CODER_BREAKDOWN_RESUME,			// Encoder error restore 
	DH_NEWLOG_BLIND_IN,							// Privacy mask 
	DH_NEWLOG_BLIND_END,						// Restore privacy mask zone
	DH_NEWLOG_ALM_TEMP_HIGH,					// Temperature is too high 
	DH_NEWLOG_ALM_VOLTAGE_LOW,					// Voltage is too low 
	DH_NEWLOG_ALM_BATTERY_LOW,					// Battery capacity is not sufficient
	DH_NEWLOG_ALM_ACC_BREAK,					// ACC power off 
	DH_NEWLOG_INFRAREDALM_IN = 0x03a0,			// Begin wireless alarm 
	DH_NEWLOG_INFRAREDALM_END,					// Stop wireless alarm 
	DH_NEWLOG_IPCONFLICT,						// IP conflict 
	DH_NEWLOG_IPCONFLICT_RESUME,				// Restore IP
	DH_NEWLOG_AUTOMATIC_RECORD = 0x0400,		// Auto record 
	DH_NEWLOG_MANUAL_RECORD,					// Enable manual record 
	DH_NEWLOG_CLOSED_RECORD,					// Stop recording
	DH_NEWLOG_LOGIN = 0x0500,					// Log in 
	DH_NEWLOG_LOGOUT,							// Log off 
	DH_NEWLOG_ADD_USER,							// Add user 
	DH_NEWLOG_DELETE_USER,						// Delete user 
	DH_NEWLOG_MODIFY_USER,						// Modify user
	DH_NEWLOG_ADD_GROUP,						// Add user group 
	DH_NEWLOG_DELETE_GROUP,						// Delete user group
	DH_NEWLOG_MODIFY_GROUP,						// Modify user group 
	DH_NEWLOG_CLEAR = 0x0600,					// Clear log
	DH_NEWLOG_SEARCHLOG,						// Search log
	DH_NEWLOG_SEARCH = 0x0700,					// Search file
	DH_NEWLOG_DOWNLOAD,							// Download file
	DH_NEWLOG_PLAYBACK,							// Playback file
	DH_NEWLOG_BACKUP,							// Backup recorded file
	DH_NEWLOG_BACKUPERROR,						// Failed to backup recorded file
	
	DH_NEWLOG_TYPE_NR = 8,		
} DH_NEWLOG_TYPE;

///////////////////////////////About audio talk ///////////////////////////////

// Audio encode type 
typedef enum __TALK_CODING_TYPE
{
	DH_TALK_DEFAULT = 0,						// No-head PCM
	DH_TALK_PCM = 1,							// With head PCM
	DH_TALK_G711a,								// G711a
	DH_TALK_AMR,								// AMR
	DH_TALK_G711u,								// G711u
	DH_TALK_G726,								// G726
} DH_TALK_CODING_TYPE;

// Audio talk way 
typedef enum __EM_USEDEV_MODE
{
	DH_TALK_CLIENT_MODE,						// Set client-end mode to begin audio talk 
	DH_TALK_SERVER_MODE,						// Set server mode to begin audio talk 
	DH_TALK_ENCODE_TYPE,						// Set encode format for audio talk 
	DH_ALARM_LISTEN_MODE,						// Set alarm subscribe way 
	DH_CONFIG_AUTHORITY_MODE,					// Set user right to realzie configuration management
} EM_USEDEV_MODE;

/////////////////////////////////Controal Related/////////////////////////////////

// Control type    Corresponding to CLIENT_ControlDevice
typedef enum _CtrlType
{
	DH_CTRL_REBOOT = 0,							// Reboot device	
	DH_CTRL_SHUTDOWN,							// Shut down device
	DH_CTRL_DISK,								// HDD management
	DH_KEYBOARD_POWER = 3,						// Nework keyboard
	DH_KEYBOARD_ENTER,
	DH_KEYBOARD_ESC,
	DH_KEYBOARD_UP,
	DH_KEYBOARD_DOWN,
	DH_KEYBOARD_LEFT,
	DH_KEYBOARD_RIGHT,
	DH_KEYBOARD_BTN0,
	DH_KEYBOARD_BTN1,
	DH_KEYBOARD_BTN2,
	DH_KEYBOARD_BTN3,
	DH_KEYBOARD_BTN4,
	DH_KEYBOARD_BTN5,
	DH_KEYBOARD_BTN6,
	DH_KEYBOARD_BTN7,
	DH_KEYBOARD_BTN8,
	DH_KEYBOARD_BTN9,
	DH_KEYBOARD_BTN10,
	DH_KEYBOARD_BTN11,
	DH_KEYBOARD_BTN12,
	DH_KEYBOARD_BTN13,
	DH_KEYBOARD_BTN14,
	DH_KEYBOARD_BTN15,
	DH_KEYBOARD_BTN16,
	DH_KEYBOARD_SPLIT,
	DH_KEYBOARD_ONE,
	DH_KEYBOARD_NINE,
	DH_KEYBOARD_ADDR,
	DH_KEYBOARD_INFO,
	DH_KEYBOARD_REC,
	DH_KEYBOARD_FN1,
	DH_KEYBOARD_FN2,
	DH_KEYBOARD_PLAY,
	DH_KEYBOARD_STOP,
	DH_KEYBOARD_SLOW,
	DH_KEYBOARD_FAST,
	DH_KEYBOARD_PREW,
	DH_KEYBOARD_NEXT,
	DH_KEYBOARD_JMPDOWN,
	DH_KEYBOARD_JMPUP,
	DH_TRIGGER_ALARM_IN = 100,					// Activate alarm input
	DH_TRIGGER_ALARM_OUT,						// Activate alarm output 
	DH_CTRL_MATRIX,								// Matrix control 
	DH_CTRL_SDCARD,								// SD card control(for IPC series). Please refer to HDD control
	DH_BURNING_START,							// Burner control:begin burning 
	DH_BURNING_STOP,							// Burner control:stop burning 
	DH_BURNING_ADDPWD,							// Burner control:overlay password(The string ended with '\0'. Max length is 8 bits. )
	DH_BURNING_ADDHEAD,							// Burner control:overlay head title(The string ended with '\0'. Max length is 1024 bytes. Use '\n' to Enter.)
	DH_BURNING_ADDSIGN,							// Burner control:overlay dot to the burned information(No parameter) 
	DH_BURNING_ADDCURSTOMINFO,					// Burner control:self-defined overlay (The string ended with '\0'. Max length is 1024 bytes. Use '\n' to Enter)
	DH_CTRL_RESTOREDEFAULT,						// restore device default setup 
	DH_CTRL_CAPTURE_START,						// Activate device snapshot
	DH_CTRL_CLEARLOG,							// Clear log
	DH_TRIGGER_ALARM_WIRELESS = 200,			// Activate wireless alarm (IPC series )
} CtrlType;

// IO control command. Corresponding to CLIENT_QueryIOControlState
typedef enum _IOTYPE
{
	DH_ALARMINPUT = 1,							// Control alarm input 
	DH_ALARMOUTPUT = 2,							// ontrol alarm output 
	DH_DECODER_ALARMOUT = 3,					// Control alarm decoder output 
	DH_WIRELESS_ALARMOUT = 5,					// Control wireless alarm output 
	DH_ALARM_TRIGGER_MODE = 7,					// Alarm activation type(auto/manual/close). Use TRIGGER_MODE_CONTROL structure 
} DH_IOTYPE;

/////////////////////////////////Configuration Related/////////////////////////////////

// Resolution enumeration. For DH_DSP_ENCODECAP to use 
typedef enum _CAPTURE_SIZE
{
	CAPTURE_SIZE_D1,							// 720*576(PAL)  720*480(NTSC)
	CAPTURE_SIZE_HD1,							// 352*576(PAL)  352*480(NTSC)
	CAPTURE_SIZE_BCIF,							// 720*288(PAL)  720*240(NTSC)
	CAPTURE_SIZE_CIF,							// 352*288(PAL)  352*240(NTSC)
	CAPTURE_SIZE_QCIF,							// 176*144(PAL)  176*120(NTSC)
	CAPTURE_SIZE_VGA,							// 640*480
	CAPTURE_SIZE_QVGA,							// 320*240
	CAPTURE_SIZE_SVCD,							// 480*480
	CAPTURE_SIZE_QQVGA,							// 160*128
	CAPTURE_SIZE_SVGA,							// 800*592
	CAPTURE_SIZE_XVGA,							// 1024*768
	CAPTURE_SIZE_WXGA,							// 1280*800
	CAPTURE_SIZE_SXGA,							// 1280*1024  
	CAPTURE_SIZE_WSXGA,							// 1600*1024  
	CAPTURE_SIZE_UXGA,							// 1600*1200
	CAPTURE_SIZE_WUXGA,							// 1920*1200
	CAPTURE_SIZE_NR  
} CAPTURE_SIZE;

// Configuration file type. For CLIENT_ExportConfigFile to use. 
typedef enum __DH_CONFIG_FILE_TYPE
{
	DH_CONFIGFILE_ALL = 0,						// All configuration file 
	DH_CONFIGFILE_LOCAL,						// Local configuration file 
	DH_CONFIGFILE_NETWORK,						// Network configuration file 
	DH_CONFIGFILE_USER,							// User congiguration file 
} DH_CONFIG_FILE_TYPE;

// NTP
typedef enum __DH_TIME_ZONE_TYPE
{
	DH_TIME_ZONE_0,								// {0, 0*3600,"GMT+00:00"}
	DH_TIME_ZONE_1,								// {1, 1*3600,"GMT+01:00"}
	DH_TIME_ZONE_2,								// {2, 2*3600,"GMT+02:00"}
	DH_TIME_ZONE_3,								// {3, 3*3600,"GMT+03:00"}
	DH_TIME_ZONE_4,								// {4, 3*3600+1800,"GMT+03:30"}
	DH_TIME_ZONE_5,								// {5, 4*3600,"GMT+04:00"}
	DH_TIME_ZONE_6,								// {6, 4*3600+1800,"GMT+04:30"}
	DH_TIME_ZONE_7,								// {7, 5*3600,"GMT+05:00"}
	DH_TIME_ZONE_8,								// {8, 5*3600+1800,"GMT+05:30"}
	DH_TIME_ZONE_9,								// {9, 5*3600+1800+900,"GMT+05:45"}
	DH_TIME_ZONE_10,							// {10, 6*3600,"GMT+06:00"}
	DH_TIME_ZONE_11,							// {11, 6*3600+1800,"GMT+06:30"}
	DH_TIME_ZONE_12,							// {12, 7*3600,"GMT+07:00"}
	DH_TIME_ZONE_13,							// {13, 8*3600,"GMT+08:00"}
	DH_TIME_ZONE_14,							// {14, 9*3600,"GMT+09:00"}
	DH_TIME_ZONE_15,							// {15, 9*3600+1800,"GMT+09:30"}
	DH_TIME_ZONE_16,							// {16, 10*3600,"GMT+10:00"}
	DH_TIME_ZONE_17,							// {17, 11*3600,"GMT+11:00"}
	DH_TIME_ZONE_18,							// {18, 12*3600,"GMT+12:00"}
	DH_TIME_ZONE_19,							// {19, 13*3600,"GMT+13:00"}
	DH_TIME_ZONE_20,							// {20, -1*3600,"GMT-01:00"}
	DH_TIME_ZONE_21,							// {21, -2*3600,"GMT-02:00"}
	DH_TIME_ZONE_22,							// {22, -3*3600,"GMT-03:00"}
	DH_TIME_ZONE_23,							// {23, -3*3600-1800,"GMT-03:30"}
	DH_TIME_ZONE_24,							// {24, -4*3600,"GMT-04:00"}
	DH_TIME_ZONE_25,							// {25, -5*3600,"GMT-05:00"}
	DH_TIME_ZONE_26,							// {26, -6*3600,"GMT-06:00"}
	DH_TIME_ZONE_27,							// {27, -7*3600,"GMT-07:00"}
	DH_TIME_ZONE_28,							// {28, -8*3600,"GMT-08:00"}
	DH_TIME_ZONE_29,							// {29, -9*3600,"GMT-09:00"}
	DH_TIME_ZONE_30,							// {30, -10*3600,"GMT-10:00"}
	DH_TIME_ZONE_31,							// {31, -11*3600,"GMT-11:00"}
	DH_TIME_ZONE_32,							// {32, -12*3600,"GMT-12:00"}
} DH_TIME_ZONE_TYPE;

typedef enum _SNAP_TYPE
{
	SNAP_TYP_TIMING = 0,
	SNAP_TYP_ALARM,
	SNAP_TYP_NUM,
} SNAP_TYPE;

/////////////////////////////////Cancelled Type/////////////////////////////////

// Configuration type. The interface that uses the enumberaiton has veen cancelled. Please do not use. 
typedef enum _CFG_INDEX
{
    CFG_GENERAL = 0,							// General 
	CFG_COMM,									// COM
	CFG_NET,									// Network
	CFG_RECORD,									// Record
	CFG_CAPTURE,								// Video setup
	CFG_PTZ,									// PTZ
	CFG_DETECT,									// Motion detection
	CFG_ALARM,									// Alarm 
	CFG_DISPLAY,								// Display 
	CFG_RESERVED,								// Reserved to keet typ consecutive
	CFG_TITLE = 10,								// channel title 
	CFG_MAIL = 11,								// Mail function 
	CFG_EXCAPTURE = 12,							// preview video setup
	CFG_PPPOE = 13,								// pppoe setup
	CFG_DDNS = 14,								// DDNS  setup
	CFG_SNIFFER	= 15,							// Network monitor capture setup
	CFG_DSPINFO	= 16,							// Encode capacity information
	CFG_COLOR = 126,							// Color setup informaiton 
	CFG_ALL,									// Reserved 
} CFG_INDEX;


/************************************************************************
 ** Structure Definition 
 ***********************************************************************/
// Time
typedef struct 
{
	DWORD				dwYear;					// Year
	DWORD				dwMonth;				// Month
	DWORD				dwDay;					// Date
	DWORD				dwHour;					// Hour
	DWORD				dwMinute;				// Minute
	DWORD				dwSecond;				// Second
} NET_TIME,*LPNET_TIME;

// The time definition in the log informaiton
typedef struct _DHDEVTIME
{
	DWORD				second		:6;			// Second	1-60		
	DWORD				minute		:6;			// Minute	1-60		
	DWORD				hour		:5;			// Hour	1-24		
	DWORD				day			:5;			// Date	1-31		
	DWORD				month		:4;			// Month	1-12		
	DWORD				year		:6;			// Year	2000-2063	
} DHDEVTIME, *LPDHDEVTIME;

///////////////////////////////Monitor Related Definition ///////////////////////////////

// Frame parameter structure of Callback video data frame 
typedef struct _tagVideoFrameParam
{
	BYTE				encode;					// Encode type 
	BYTE				frametype;				// I = 0, P = 1, B = 2...
	BYTE				format;					// PAL - 0, NTSC - 1
	BYTE				size;					// CIF - 0, HD1 - 1, 2CIF - 2, D1 - 3, VGA - 4, QCIF - 5, QVGA - 6 ,
												// SVCD - 7,QQVGA - 8, SVGA - 9, XVGA - 10,WXGA - 11,SXGA - 12,WSXGA - 13,UXGA - 14,WUXGA - 15,
	DWORD				fourcc;					// If it is H264 encode it is always 0£¬Fill in FOURCC('X','V','I','D') in MPEG 4;
	DWORD				reserved;				// Reserved
	NET_TIME			struTime;				// Time informaiton 
} tagVideoFrameParam;

// Frame parameter structure of audio data callback 
typedef struct _tagCBPCMDataParam
{
	BYTE				channels;				// Track amount 
	BYTE				samples;				// sample 0 - 8000, 1 - 11025, 2 - 16000, 3 - 22050, 4 - 32000, 5 - 44100, 6 - 48000
	BYTE				depth;					// Sampling depth. Value:8/16 show directly
	BYTE				param1;					// 0 - indication no symbol£¬1-indication with symbol
	DWORD				reserved;				// Reserved
} tagCBPCMDataParam;

// Data structure of channel video title overlay 
typedef struct _DH_CHANNEL_OSDSTRING
{
	BOOL				bEnable;				// Enable 
	DWORD				dwPosition[MAX_STRING_LINE_LEN];	//Character position in each line. The value ranges from 1 to 9.Correesponding to the small keyboard.
												//		7upper left 	8upper		9upper right 
												//		4left		5middle 	6right 
												//		1down left	2down	        3down right 
	char				szStrings[MAX_STRING_LINE_LEN][MAX_PER_STRING_LEN];	// Max 6 lines. Each line max 20 bytes.
} DH_CHANNEL_OSDSTRING;

///////////////////////////////Playback Related Definition///////////////////////////////

// Record file information
typedef struct
{
    unsigned int		ch;						// Channel number
    char				filename[128];			// File name 
    unsigned int		size;					// File length 
    NET_TIME			starttime;				// Start time 
    NET_TIME			endtime;				// End time 
    unsigned int		driveno;				// HDD number 
    unsigned int		startcluster;			// Initial cluster number 
	int					nRecordFileType;		// Recorded file type  0£ºgeneral record£»1£ºalarm record £»2£ºmotion detection£»3£ºcard number record £»4£ºimage 
} NET_RECORDFILE_INFO, *LPNET_RECORDFILE_INFO;

///////////////////////////////Alarm Related Definition ///////////////////////////////

// General alarm informaiton 
typedef struct
{
	int					channelcount;
	int					alarminputcount;
	unsigned char		alarm[16];				// External alarm 
	unsigned char		motiondection[16];		// Motion detection 
	unsigned char		videolost[16];			// Video loss 
} NET_CLIENT_STATE;

// Alarm IO control 
typedef struct 
{
	unsigned short		index;					// Port serial number 
	unsigned short		state;					// Port status 
} ALARM_CONTROL;

//Activation type 
typedef struct
{
	unsigned short		index;					// Port serial number 
	unsigned short		mode;					// Activation way(0:close.1:manual.2:auto); The SDK reserves the original setup if you do not set channel here. 
	BYTE				bReserved[28];			
} TRIGGER_MODE_CONTROL;

// Alarm decoder control 
typedef struct 
{
	int					decoderNo;				// Alarm decoder. It begins from 0. 
	unsigned short		alarmChn;				// Alarm output port. It begin from o.£¬ 
	unsigned short		alarmState;				// Alarm output status£»1£ºopen£¬0£ºclose.
} DECODER_ALARM_CONTROL;

// Alarm information of alarm upload function
typedef struct  
{
	DWORD				dwAlarmType;			// Alarm type£¬when dwAlarmType = DH_UPLOAD_EVENT£¬dwAlarmMask and bAlarmDecoderIndex are invalid.
	DWORD				dwAlarmMask;			// Alarm information subnet mask. Bit represents each alarm status
	char				szGlobalIP[DH_MAX_IPADDR_LEN];	// Client-end IP address 
	char				szDomainName[DH_MAX_DOMAIN_NAME_LEN];	// Client-end domain name
	int					nPort;					// The port client-end connected when upload alarm 
	char				szAlarmOccurTime[DH_ALARM_OCCUR_TIME_LEN];	// Alarm occured time 
	BYTE				bAlarmDecoderIndex;		// It means which alarm decoder. It is valid when dwAlarmType = DH_UPLOAD_DECODER_ALARM.
	BYTE				bReservedSpace[15];
}NEW_ALARM_UPLOAD;

/////////////////////////////Audio Talk Related Definition/////////////////////////////

// Audio format informaiton 
typedef struct
{
	BYTE				byFormatTag;			// Encode type such as 0£ºPCM
	WORD				nChannels;				// Track number 
	WORD				wBitsPerSample;			// Sampling depth 	
	DWORD				nSamplesPerSec;			// Sampling rate
} DH_AUDIO_FORMAT, *LPDH_AUDIO_FORMAT;

/////////////////////////////User Management Correponding Definition /////////////////////////////

// Support the device with max 8 bits user name. Corresponding to the CLIENT_QueryUserInfo and CLIENT_OperateUserInfo.
// Right information 
typedef struct _OPR_RIGHT
{
	DWORD				dwID;
	char				name[DH_RIGHT_NAME_LENGTH];
	char				memo[DH_MEMO_LENGTH];
} OPR_RIGHT;

// User information 
typedef struct _USER_INFO
{
	DWORD				dwID;
	DWORD				dwGroupID;
	char				name[DH_USER_NAME_LENGTH];
	char				passWord[DH_USER_PSW_LENGTH];
	DWORD				dwRightNum;
	DWORD				rights[DH_MAX_RIGHT_NUM];
	char				memo[DH_MEMO_LENGTH];
	DWORD				dwReusable;				// Reuse or not£»1£º enable reuse£¬0£ºdisable reuser 
} USER_INFO;

// User group information 
typedef struct _USER_GROUP_INFO
{
	DWORD				dwID;
	char				name[DH_USER_NAME_LENGTH];
	DWORD				dwRightNum;
	DWORD				rights[DH_MAX_RIGHT_NUM];
	char				memo[DH_MEMO_LENGTH];
} USER_GROUP_INFO;

// User informaiton list 
typedef struct _USER_MANAGE_INFO
{
	DWORD				dwRightNum;				// Right information 
	OPR_RIGHT			rightList[DH_MAX_RIGHT_NUM];
	DWORD				dwGroupNum;				// User group information 
	USER_GROUP_INFO		groupList[DH_MAX_GROUP_NUM];
	DWORD				dwUserNum;				// User information 
	USER_INFO			userList[DH_MAX_USER_NUM];
	DWORD				dwSpecial;				// User account reuse £»1£ºsupport account to be reused. 0£ºDoes not support account to be reused.
} USER_MANAGE_INFO;

// Support the device of max 8-bit or 16-bit name. Corresponding interface to CLIENT_QueryUserInfoEx and CLIENT_OperateUserInfoEx
#define DH_USER_NAME_LENGTH_EX		16			// User name length 
#define DH_USER_PSW_LENGTH_EX		16			// Password 

// Right information
typedef struct _OPR_RIGHT_EX
{
	DWORD				dwID;
	char				name[DH_RIGHT_NAME_LENGTH];
	char				memo[DH_MEMO_LENGTH];
} OPR_RIGHT_EX;

// User informaiton 
typedef struct _USER_INFO_EX
{
	DWORD				dwID;
	DWORD				dwGroupID;
	char				name[DH_USER_NAME_LENGTH_EX];
	char				passWord[DH_USER_PSW_LENGTH_EX];
	DWORD				dwRightNum;
	DWORD				rights[DH_MAX_RIGHT_NUM];
	char				memo[DH_MEMO_LENGTH];
	DWORD				dwFouctionMask;			// Subnet mask£¬0x00000001 - support reuse  
	BYTE				byReserve[32];
} USER_INFO_EX;

// User group information 
typedef struct _USER_GROUP_INFO_EX
{
	DWORD				dwID;
	char				name[DH_USER_NAME_LENGTH_EX];
	DWORD				dwRightNum;
	DWORD				rights[DH_MAX_RIGHT_NUM];
	char				memo[DH_MEMO_LENGTH];
} USER_GROUP_INFO_EX;

// User information sheet 
typedef struct _USER_MANAGE_INFO_EX
{
	DWORD				dwRightNum;				// Right information 
	OPR_RIGHT_EX		rightList[DH_MAX_RIGHT_NUM];
	DWORD				dwGroupNum;				// User group informaiton 
	USER_GROUP_INFO_EX  groupList[DH_MAX_GROUP_NUM];
	DWORD				dwUserNum;				// User informaiton 
	USER_INFO_EX		userList[DH_MAX_USER_NUM];
	DWORD				dwFouctionMask;			// Subnet mask£»0x00000001 - support reuse  £¬0x00000002 - Password has been modified , it needs to be verified.
	BYTE				byNameMaxLength;		// The supported user name max length 
	BYTE				byPSWMaxLength;			// The supported password max length
	BYTE				byReserve[254];
} USER_MANAGE_INFO_EX;

///////////////////////////////Search Related Definition ///////////////////////////////

// The language types device supported 
typedef struct _DH_LANGUAGE_DEVINFO
{
	DWORD				dwLanguageNum;			// The language amount supported
	BYTE				byLanguageType[252];	// Enumeration value please refer to DH_LANGUAGE_TYPE
} DH_DEV_LANGUAGE_INFO, *LPDH_DEV_LANGUAGE_INFO;

// HDD informaiton 
typedef struct
{
	DWORD				dwVolume;				// HDD capacity 
	DWORD				dwFreeSpace;			// HDD free space 
	BYTE				dwStatus;				// HDD status,0-hiberation,1-active,2-malfucntion and etc.£»Devide DWORD into four BYTE
	BYTE				bDiskNum;				// HDD number
	BYTE				bSubareaNum;			// Subarea number
	BYTE				bSignal;				// Symbol. 0:local. 1:remote
} NET_DEV_DISKSTATE,*LPNET_DEV_DISKSTATE;

// Device HDD informaiton 
typedef struct _DH_HARDDISK_STATE
{
	DWORD				dwDiskNum;				// Amount 
	NET_DEV_DISKSTATE	stDisks[DH_MAX_DISKNUM];// HDD or subarea informaiton 
} DH_HARDDISK_STATE, *LPDH_HARDDISK_STATE;

typedef DH_HARDDISK_STATE	DH_SDCARD_STATE;	// SD card. Please refer to HDD information for data structure. 

// Audio encode information 
typedef struct  
{
	DH_TALK_CODING_TYPE	encodeType;				// Encode type 
	int					nAudioBit;				// Bit:8/16
	DWORD				dwSampleRate;			// Sampling rate such as 8000 or 16000
	char				reserved[64];
} DHDEV_TALKDECODE_INFO;

// The audio talk type the device supported
typedef struct 
{
	int					nSupportNum;			// Amount
	DHDEV_TALKDECODE_INFO type[64];				// Encode type 
	char				reserved[64];
} DHDEV_TALKFORMAT_LIST;

// PTZ property information
#define  NAME_MAX_LEN 16
typedef struct 
{
	DWORD				dwHighMask;				// Operation mask high bit 
	DWORD				dwLowMask;				// Operation mask low bit 
	char				szName[NAME_MAX_LEN];	// Operation protocol name 
	WORD				wCamAddrMin;			// Channel address min value
	WORD				wCamAddrMax;			// Channel address max value
	WORD				wMonAddrMin;			// Monitor address min value
	WORD				wMonAddrMax;			// Monitor address max value
	BYTE				bPresetMin;				// Preset min value
	BYTE				bPresetMax;				// Preset max value
	BYTE				bTourMin;				// Auto tour min value
	BYTE				bTourMax;				// Auto tour max value
	BYTE				bPatternMin;			// Pattern min value
	BYTE				bPatternMax;			// Pattern max value
	BYTE				bTileSpeedMin;			// Tilt speed min value
	BYTE				bTileSpeedMax;			// Tilt speed max value
	BYTE				bPanSpeedMin;			// Pan speed min value
	BYTE				bPanSpeedMax;			// Pan speed max value
	BYTE				bAuxMin;				// Aux function min value
	BYTE				bAuxMax;				// Aux function max value
	int					nInternal;				// Command interval
	char				cType;					// Protocl type
	char				Reserved[7];
} PTZ_OPT_ATTR;

// Burner informaiton 
typedef struct _NET_DEV_BURNING
{
	DWORD				dwDriverType;			// Burner driver type £»0£ºDHFS£¬1£ºDISK£¬2£ºCDRW
	DWORD				dwBusType;				// Bus type£»0£ºUSB£¬1£º1394£¬2£ºIDE
	DWORD				dwTotalSpace;			// Total space(KB)
	DWORD				dwRemainSpace;			// Free space(KB)
	BYTE				dwDriverName[DH_BURNING_DEV_NAMELEN];	// Burnern driver name
} NET_DEV_BURNING, *LPNET_DEV_BURNING;

// Device burner informaiton 
typedef struct _DH_BURNING_DEVINFO
{
	DWORD				dwDevNum;				// Burner device amount
	NET_DEV_BURNING		stDevs[DH_MAX_BURNING_DEV_NUM];	// Each burner device information 
} DH_BURNING_DEVINFO, *LPDH_BURNING_DEVINFO;

// Burner progress 
typedef struct _DH_BURNING_PROGRESS
{
	BYTE				bBurning;				// Burner status£»0£ºready to burn£¬1£ºburner typs is not correct. It does not match. 
												// 2£ºthere is no burner available  £¬3£ºThere is burning in process. £¬4£ºBurner is not free(It is backup or buring or playback.) 
	BYTE				bRomType;				// CD type£»0£ºDahua file system £¬1£ºPortable HDD or flash disk £¬2£º CD
	BYTE				bOperateType;			// Operation type£»0£ºfree £¬1£ºbackup  £¬2£ºburning £¬3£ºplayback from the cd 
	BYTE				bType;					// Backup pr burning status£»0£ºstop or end£¬1£ºstart£¬2£ºerror£¬3£ºfull£¬4£ºinitializing
	NET_TIME			stTimeStart;			// Begint time 
	DWORD				dwTimeElapse;			// Buring time(second)
	DWORD				dwTotalSpace;			// Total space
	DWORD				dwRemainSpace;			// Free space
	DWORD				dwBurned;				// Burned capacity 
	WORD				dwStatus;				// Reserved
	WORD				wChannelMask;			// The burning channel mask 
} DH_BURNING_PROGRESS, *LPDH_BURNING_PROGRESS;

// Log information. Corresponding to CLIENT_QueryLog
typedef struct _DH_LOG_ITEM
{
    DHDEVTIME			time;					// Date 
    unsigned short		type;					// Type
    unsigned char		reserved;				// Reserved
    unsigned char		data;					// Data 
    unsigned char		context[8];				// Content
} DH_LOG_ITEM, *LPDH_LOG_ITEM;

// Log information. Corresponding to CLIENT_QueryLogEx£¬ paramter reserved(int nType=1;reserved=&nType;)
typedef struct _DH_NEWLOG_ITEM
{
	DHDEVTIME			time;					// Date
	WORD				type;					// Type
	WORD				data;					// data
	char				szOperator[8]; 			// User name 
	BYTE				context[16];		    // Content	
} DH_NEWLOG_ITEM, *LPDH_NEWLOG_ITEM;

// Log information. Corresponding to CLIENT_QueryDeviceLog
typedef struct _DH_DEVICE_LOG_ITEM
{
	int					nLogType;				// Log type 
	DHDEVTIME			stuOperateTime;			// Date
	char				szOperator[16]; 		// Operator
	BYTE				bReserved[3];
	BYTE				bUnionType;				// union structure type,0:szLogContext£»1:stuOldLog¡£
	union
	{
		char			szLogContext[64];		// Log content
		struct 
		{
			DH_LOG_ITEM		stuLog;				// Old log structure 
			BYTE			bReserved[48];		// Reserved
		}stuOldLog;
	};
	char				reserved[16];
} DH_DEVICE_LOG_ITEM, *LPDH_DEVICE_LOG_ITEM;

// Record log informaiton. Corresponding to the context of log structure 
typedef struct _LOG_ITEM_RECORD
{
	DHDEVTIME			time;					// Time 
	BYTE				channel;				// Channel
	BYTE				type;					// Record type
	BYTE				reserved[2];
} LOG_ITEM_RECORD, *LPLOG_ITEM_RECORD;

typedef struct _QUERY_DEVICE_LOG_PARAM
{
	 DH_LOG_QUERY_TYPE	emLogType;				// Searched log type
	 NET_TIME			stuStartTime;			// The searched log start time
	 NET_TIME			stuEndTime;				// The searched log end time. 
	 int				nStartNum;				// The search begins from which log in one period. It shall begin with 0 if it is the first time search.
	 int				nEndNum;				// The ended log serial number in one search
	 BYTE				bReserved[48];
} QUERY_DEVICE_LOG_PARAM;
///////////////////////////////Control Related Definition///////////////////////////////

// HDD operation
typedef struct _DISKCTRL_PARAM
{
	DWORD				dwSize;					// Structure size. For version control.
	int					nIndex;					// Subscript of array stDisks of informaiton structure DH_HARDDISK_STATE. It begins from 0. 
	int					ctrlType;				// Operation type
												// 0 -  clear data, 1 - set as read-write HDD , 2 -  set as read-only HDD
												// 3 - set as redundant , 4 - restore error , 5 -set as snapshot disk  
} DISKCTRL_PARAM;

// Alarm status
typedef struct _ALARMCTRL_PARAM
{
	DWORD				dwSize;
	int					nAlarmNo;				// Alarm channel. It begins from 0.£¬ 
	int					nAction;				// 0£º activate alarm £¬1£ºstop alarm  
} ALARMCTRL_PARAM;

// Matrix control 
typedef struct _MATRIXCTRL_PARAM
{
	DWORD				dwSize;
	int					nChannelNo;				// Video input number. It begins from  0.
	int					nMatrixNo;				// Matrix output number. It begins from 0
} MATRIXCTRL_PARAM;

// Burner control 
typedef struct _BURNING_PARM
{
	int					channelMask;			// channel subnet mask. Bit means the channel to be burned.
	int					devMask;				// Burner subnet mask.  Use bit to represent according to the searched burner list 
} BURNNG_PARM;

///////////////////////////////Configuration Related Definition ///////////////////////////////

//-------------------------------Device Property ---------------------------------
// Device information 
typedef struct
{
	BYTE				sSerialNumber[DH_SERIALNO_LEN];	// SN
	BYTE				byAlarmInPortNum;		// DVR alarm input amount
	BYTE				byAlarmOutPortNum;		// DVR alarm output amount
	BYTE				byDiskNum;				// DVR HDD amount 
	BYTE				byDVRType;				// DVR type.Please refer to DHDEV_DEVICE_TYPE
	BYTE				byChanNum;				// DVR channel ammount 
} NET_DEVICEINFO, *LPNET_DEVICEINFO;

//Device software version informaiton. The higher 16-bit means the main version number and low 16-bit means second version number. 
typedef struct 
{
	DWORD				dwSoftwareVersion;
	DWORD				dwSoftwareBuildDate;
	DWORD				dwDspSoftwareVersion;
	DWORD				dwDspSoftwareBuildDate;
	DWORD				dwPanelVersion;
	DWORD				dwPanelSoftwareBuildDate;
	DWORD				dwHardwareVersion;
	DWORD				dwHardwareDate;
	DWORD				dwWebVersion;
	DWORD				dwWebBuildDate;
} DH_VERSION_INFO, *LPDH_VERSION_INFO;

// Device software version informaiton. Corresponding to CLIENT_QueryDevState
typedef struct  
{
	char				szDevSerialNo[DH_DEV_SERIALNO_LEN];	// Serial number 
	char				byDevType;				// Device type, please refer to DHDEV_DEVICE_TYPE
	char				szDevType[DH_DEV_TYPE_LEN];	// Device detailed type. String format. It may be null.
	int					nProtocalVer;			//  Protocl version number 
	char				szSoftWareVersion[DH_MAX_URL_LEN];
	DWORD				dwSoftwareBuildDate;
	char				szDspSoftwareVersion[DH_MAX_URL_LEN];
	DWORD				dwDspSoftwareBuildDate;
	char				szPanelVersion[DH_MAX_URL_LEN];
	DWORD				dwPanelSoftwareBuildDate;
	char				szHardwareVersion[DH_MAX_URL_LEN];
	DWORD				dwHardwareDate;
	char				szWebVersion[DH_MAX_URL_LEN];
	DWORD				dwWebBuildDate;
	char				reserved[256];
} DHDEV_VERSION_INFO;

// DSP capacity description. Correspondign to CLIENT_GetDevConfig
typedef struct 
{
	DWORD				dwVideoStandardMask;	// video format mask. Bit stands for the video format device supported.
	DWORD				dwImageSizeMask;		// Resolution mask bit. Bit stands for the resolution setup devices supported.
	DWORD				dwEncodeModeMask;		// Encode mode mask bit. Bit stands for the encode mode devices supported.
	DWORD				dwStreamCap;			// The multiple-media function the devices supported
												// The first bit:main stream
												// The second bit:extra stream 1
												// The third bit:extra stream 2
												// The fifth bit: snapshot in .jpg format
	DWORD				dwImageSizeMask_Assi[8];// When the main stream is the corresponding resolution, the supported extra stream resolution mask.
	DWORD				dwMaxEncodePower;		// The highest encode capacity DSP supported
	WORD				wMaxSupportChannel;		// The max video channel amount each DSP supported.
	WORD				wChannelMaxSetSync;		// Max encode bit setup in each DSP channel  are synchronized or not £»0£ºdoes not synchronized£¬1£ºsynchronized
} DH_DSP_ENCODECAP, *LPDH_DSP_ENCODECAP;

// DSP capacity description. Extensive type. Corresponding to CLIENT_QueryDevState
typedef struct 
{
	DWORD				dwVideoStandardMask;	// video format mask. Bit stands for the video format device supported.
	DWORD				dwImageSizeMask;		// Resolution mask bit. Bit stands for the resolution setup devices supported.
	DWORD				dwEncodeModeMask;		// Encode mode mask bit. Bit stands for the encode mode devices supported.
	DWORD				dwStreamCap;			// The multiple-media function the devices supported
												// The first bit:main stream
												// The second bit:extra stream 1
												// The third bit:extra stream 2
												// The fifth bit: snapshot in .jpg format
	DWORD				dwImageSizeMask_Assi[32];// When the main stream is the corresponding resolution, the supported extra stream resolution mask.
	DWORD				dwMaxEncodePower;		// The highest encode capacity DSP supported
	WORD				wMaxSupportChannel;		// The max video channel amount each DSP supported.
	WORD				wChannelMaxSetSync;		// Max encode bit setup in each DSP channel  are synchronized or not £»0£ºdo not synchronized£¬1£ºsynchronized
	BYTE				bMaxFrameOfImageSize[32];// The max sampling frame rate in different resolution. Bit corresponding to the dwVideoStandardMask.
	BYTE				bEncodeCap;				// Symbol. The configuraiton shall meet the following requirements, otherwise the configuration is invalid.
												// 0£º main stream encode capacity+extra stream encode capacity<= device encode capacity 
												// 1£º main stream encode capacity +extra stream encode capacity<= device encode capacity 
												// Extra stream encode capacity <=main stream encode capacity 
												// Extra stream resolution<=main stream resolution 
												// Main stream resolution and extra stream resoultion <=front-end video collection frame rate

	char				reserved[95];
} DHDEV_DSP_ENCODECAP, *LPDHDEV_DSP_ENCODECAP;

// System information
typedef struct 
{
	DWORD				dwSize;
	/* The followin are read only for device. */
	DH_VERSION_INFO		stVersion;
	DH_DSP_ENCODECAP	stDspEncodeCap;			// DSP  capacity description 
	BYTE				szDevSerialNo[DH_DEV_SERIALNO_LEN];	// SN
	BYTE				byDevType;				// device type. Please refer to enumeration DHDEV_DEVICE_TYPE
	BYTE				szDevType[DH_DEV_TYPE_LEN];	// Device detailed type. String format. It may be empty.
	BYTE				byVideoCaptureNum;		// Video port amount
	BYTE				byAudioCaptureNum;		// Audio port amount 
	BYTE				byTalkInChanNum;		// NSP
	BYTE				byTalkOutChanNum;		// NSP
	BYTE				byDecodeChanNum;		// NSP
	BYTE				byAlarmInNum;			// Alarm input port amount
	BYTE				byAlarmOutNum;			// Alarm output amount port
	BYTE				byNetIONum;				// network port amount 
	BYTE				byUsbIONum;				// USB USB port amount
	BYTE				byIdeIONum;				// IDE amount 
	BYTE				byComIONum;				// COM amount 
	BYTE				byLPTIONum;				// LPT amount
	BYTE				byVgaIONum;				// NSP
	BYTE				byIdeControlNum;		// NSP
	BYTE				byIdeControlType;		// NSP
	BYTE				byCapability;			// NSP£¬ expansible description 
	BYTE				byMatrixOutNum;			// video matrix output amount 
	/* The following are read-write part for device */
	BYTE				byOverWrite;			// Operate when HDD is full£¨overwrite/stop£©
	BYTE				byRecordLen;			// Video file Package length
	BYTE				byDSTEnable;			// Enable  DTS or not  1--enable. 0--disbale
	WORD				wDevNo;					// Device serial number. Remote control can use this SN to control.
	BYTE				byVideoStandard;		// Video format
	BYTE				byDateFormat;			// Date format
	BYTE				byDateSprtr;			// Date separator(0£º"."£¬1£º"-"£¬2£º"/")
	BYTE				byTimeFmt;				// Time separator  (0-24H£¬1£­12H)
	BYTE				byLanguage;				// Please refer to DH_LANGUAGE_TYPE for enumeration value
} DHDEV_SYSTEM_ATTR_CFG, *LPDHDEV_SYSTEM_ATTR_CFG;

// The returned information after modify device 
typedef struct
{
	DWORD				dwType;					// Type (type of GetDevConfig and SetDevConfig)
	WORD				wResultCode;			// Returned bit£»0£ºsucceeded £¬1£ºfailed £¬2£ºillegal data £¬3£º can not set right now£¬4£ºhave no right 
	WORD   				wRebootSign;			// Reboot symbol£»0£ºdo not need to reboot £¬1£ºneed to reboot to get activated 
	DWORD				dwReserved[2];			// Reserved 
} DEV_SET_RESULT;

//DST(Daylight Save Time) setup
typedef struct  
{
	int					nYear;					// Year[200 - 2037]
	int					nMonth;					// Month[1 - 12]
	int					nHour;					// Hour[0 - 23]
	int					nMinute;				// Minute [0 - 59]
	int					nWeekOrDay;				// [-1 - 4]0:It means it adopts the date calculation method. 
												// 1:  in week: the first week ,2:the second week  ,3:the third week  ,4: The fourth week ,-1: the last week  
	union
	{
		int				iWeekDay;				// week[0 - 6](nWeekOrDay£ºcalculated in weeok )0: Sunday, 1:Monday , 2:Tuesday ,3: Wednesday,4:Thirsday ,5: Friday,6:Saturday 
		int				iDay;					// date[1 - 31] (nWeekOrDay£º in date)
	};
	
	DWORD				dwReserved[8];			// Reserved 
}DH_DST_POINT;

typedef struct  
{
	DWORD				dwSize;
	int					nDSTType;				// DST position way. 0: position in date  , 1:position in week  
	DH_DST_POINT        stDSTStart;             // Enable DTS
	DH_DST_POINT        stDSTEnd;				// End DTS
	DWORD				dwReserved[16];			// Reserved
}DHDEV_DST_CFG;


// Auto maintenance setup
typedef struct
{
	DWORD				dwSize;
	BYTE				byAutoRebootDay;		// Auto reboot£»0£ºnever, 1£ºeach day £¬2£ºeach Sunday £¬3£ºEach Monday £¬......
	BYTE				byAutoRebootTime;		// 0£º0:00£¬1£º1:00£¬......23£º23:00
	BYTE				byAutoDeleteFilesTime;	// Auto delete file£»0£ºnever£¬1£º24H£¬2£º48H£¬3£º72H£¬4£º96H£¬5£ºONE WEEK£¬6£ºONE MONTH
	BYTE				reserved[13];			// Reserved bit
} DHDEV_AUTOMT_CFG;

//-----------------------------Video Channel Property -------------------------------

// Time period structure 															    
typedef struct 
{
	BOOL				bEnable;				// Current record period . Bit means the three Enble functions. From the low bit to the high bit:Motion detection record, alarm record and general record.  
	int					iBeginHour;
	int					iBeginMin;
	int					iBeginSec;
	int					iEndHour;
	int					iEndMin;
	int					iEndSec;
} DH_TSECT, *LPDH_TSECT;

// Zone£»Each margin is total lenght :8192
typedef struct {
   long					left;
   long					top;
   long					right;
   long					bottom;
} DH_RECT, *LPDH_RECT;

// OSD property structure 
typedef struct  tagENCODE_WIDGET
{
	DWORD				rgbaFrontground;		// Object front view. Use bit to represent:red, green, blue and transparency.
	DWORD				rgbaBackground;			// Object back ground. Use bit to represent:red, green, blue and transparency.
	DH_RECT				rcRect;					// Postition
	BYTE				bShow;					// Enable display
	BYTE				byReserved[3];
} DH_ENCODE_WIDGET, *LPDH_ENCODE_WIDGET;

// Channel audio property 
typedef struct 
{
	// Video property 
	BYTE				byVideoEnable;			// Enable video£»1£ºopen£¬0£ºclose 
	BYTE				byBitRateControl;		// Bit stream control£»Please refer to constant Bit Stream Control definition 
	BYTE				byFramesPerSec;			// Frame rate
	BYTE				byEncodeMode;			// Encode mode:please refer to constant Encode Mode definition
	BYTE				byImageSize;			// Resolution:please refer to constant Resolution definition.
	BYTE				byImageQlty;			// Level 1-6
	WORD				wLimitStream;			// Limit stream parameter
	// Audio property 
	BYTE				byAudioEnable;			// Enable audio£»1£ºopen£¬0£ºclose
	BYTE				wFormatTag;				// Audio encode mode 
	WORD				nChannels;				// Track amount 
	WORD				wBitsPerSample;			// Sampling depth 	
	DWORD				nSamplesPerSec;			// Sampling rate 
	BYTE				bIFrameInterval;		// 0-149. I frame interval amount. Describe the P frame amount between two I frames.
	char				reserved;
} DH_VIDEOENC_OPT, *LPDH_VIDEOENC_OPT;

// Image color property  
typedef struct 
{
	DH_TSECT			stSect;
	BYTE				byBrightness;			// Brightness£»0-100
	BYTE				byContrast;				// Contrast£»0-100
	BYTE				bySaturation;			// Saturation£»0-100
	BYTE				byHue;					// Hue£»0-100
	BYTE				byGainEn;				// Enable gain
	BYTE				byGain;					// Gain£»0-100
	BYTE				byReserved[2];
} DH_COLOR_CFG, *LPDH_COLOR_CFG;

// Image channel property structure 
typedef struct 
{
	DWORD				dwSize;
	char				szChannelName[DH_CHAN_NAME_LEN];
	DH_VIDEOENC_OPT		stMainVideoEncOpt[DH_REC_TYPE_NUM];
	DH_VIDEOENC_OPT		stAssiVideoEncOpt[DH_N_ENCODE_AUX];		
	DH_COLOR_CFG		stColorCfg[DH_N_COL_TSECT];
	DH_ENCODE_WIDGET	stTimeOSD;
	DH_ENCODE_WIDGET	stChannelOSD;
	DH_ENCODE_WIDGET	stBlindCover[DH_N_COVERS];	// Single privacy mask zone
	BYTE				byBlindEnable;			// Privacy mask zone enbale button£»0x00£ºdisable privacy mask £¬0x01£ºprivacy mask local preview £¬0x10£ºprivacy mask record and network preview½ö £¬0x11£º Privacy mask all
	BYTE				byBlindMask;			// Privacy mask zone subnet mask. The first bit£ºdevice local preview £»The second bit £ºrecord (and network preview ) */
	BYTE				byReserved[2];
} DHDEV_CHANNEL_CFG, *LPDHDEV_CHANNEL_CFG;

// Preview image property 
typedef struct 
{
	DWORD				dwSize;
	DH_VIDEOENC_OPT		stPreView;
	DH_COLOR_CFG		stColorCfg[DH_N_COL_TSECT];
}DHDEV_PREVIEW_CFG;

//-------------------------------COM property ---------------------------------

// COM basic property 
typedef struct
{
	BYTE				byDataBit;				// Data bit£»0£º5£¬1£º6£¬2£º7£¬3£º8
	BYTE				byStopBit;				// Stop bit£»0£º1 bit£¬1£º1.5 bit£¬2£º2 bits
	BYTE				byParity;				// Parity£»0£º None£¬1£º Odd£»2£º even
	BYTE				byBaudRate;				// Baud rate£»0£º300£¬1£º600£¬2£º1200£¬3£º2400£¬4£º4800£¬
												// 5£º9600£¬6£º19200£¬7£º38400£¬8£º57600£¬9£º115200
} DH_COMM_PROP;

// 485 decoder setup 
typedef struct
{ 
	DH_COMM_PROP		struComm;
	BYTE				wProtocol;				// Protocol type. Corresponding to the subcript of Protocol Name List
	BYTE				byReserved;				// Reserved
	BYTE				wDecoderAddress;		// Decoder address£»0 - 255
	BYTE 				byMartixID;				// Matrix number 
} DH_485_CFG;

// 232 COM setup 
typedef struct
{
	DH_COMM_PROP		struComm;
	BYTE				byFunction;				// COM function£¬Corresponding to the subscript of Function Name list. 
	BYTE				byReserved[3];
} DH_RS232_CFG;

// COM configuration structure 
typedef struct
{
	DWORD				dwSize;

	DWORD				dwDecProListNum;				// Decoder protocol amount
	char				DecProName[DH_MAX_DECPRO_LIST_SIZE][DH_MAX_NAME_LEN]; // Protocol name list
	DH_485_CFG			stDecoder[DH_MAX_DECODER_NUM];	// Each decoder current property

	DWORD				dw232FuncNameNum;		// 232 function amount 
	char				s232FuncName[DH_MAX_232FUNCS][DH_MAX_NAME_LEN];	// Function name list 
	DH_RS232_CFG		st232[DH_MAX_232_NUM];	// Current 232 COM property 
} DHDEV_COMM_CFG;

//-------------------------------Record configuration---------------------------------

// Scheduled record 
typedef struct 
{
	DWORD				dwSize;
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];
	BYTE				byPreRecordLen;			// Pre-record button. Unit is second. 0 means disble pre-record 
	BYTE				byRedundancyEn;			// Record redundant enable button 
	BYTE				byReserved[2];
} DHDEV_RECORD_CFG, *LPDH_RECORD_CFG;

// NTP setup 
typedef struct  
{
	BOOL				bEnable;				// Enable or not
	int					nHostPort;				// NTP  server default port is 123
	char				szHostIp[32];			// Host IP
	char				szDomainName[128];		// Domain name 
	int					nType;					// Read only £¬0£ºIP£¬1£ºdomain name £¬2£ºIP and doamin name 
	int					nUpdateInterval;		// Update time(minute)
	int					nTimeZone;				// Please refer to DH_TIME_ZONE_TYPE
	char				reserved[128];
} DHDEV_NTP_CFG;

// FTP upload setup 
typedef struct
{
	struct
	{
		DH_TSECT		struSect;				// Enable function is disabled during the period. Can ignore
		BOOL			bMdEn;					// Upload motion detection record
		BOOL			bAlarmEn;				// Upload external alarm record 
		BOOL			bTimerEn;				// Upload scheduled record 
		DWORD			dwRev[4];
	} struPeriod[DH_TIME_SECTION];
} DH_FTP_UPLOAD_CFG;

typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;							// Enable or not
	char				szHostIp[DH_MAX_IPADDR_LEN];		// Host IP
	WORD				wHostPort;							// Host port 
	char				szDirName[DH_FTP_MAX_PATH];			// FTP path
	char				szUserName[DH_FTP_USERNAME_LEN];	// User name
	char				szPassword[DH_FTP_PASSWORD_LEN];	// Password 
	int					iFileLen;							// File length
	int					iInterval;							// Time interval between two near files.
	DH_FTP_UPLOAD_CFG	struUploadCfg[DH_MAX_CHANNUM][DH_N_WEEKS];
	char 				protocol;							// 0-FTP 1-SMB
	char				NASVer;								// Network storage server version 0=Old FTP(There is time period in the user interface)£¬1=NAS storage(There is no time period in the user interface. )
	DWORD				dwFunctionMask;						// Function capacity mask. Use bit to represent. Lower 16-bit:FTP£¬SMB£¬NFS£¬and higher 16-bit:(Local storage)DISK£¬U
	BYTE 				reserved[124];
} DHDEV_FTP_PROTO_CFG;

//-------------------------------Network Configuration---------------------------------

// Ethernet Configuration
typedef struct 
{
	char				sDevIPAddr[DH_MAX_IPADDR_LEN];	// DVR IP  address
	char				sDevIPMask[DH_MAX_IPADDR_LEN];	// DVR IP subnet mask    
	char				sGatewayIP[DH_MAX_IPADDR_LEN];	// Gateway address

	/* 10M/100M  Self-adaptive. index 
	 * 1-10MBase - T
	 * 2-10MBase-T Duplex Transmissions  
	 * 3-100MBase - TX
	 * 4-100M Duplex Transmissions  
	 * 5-10M/100M  Self-adaptive. 
	 */
	// Divide DWORD into four to future development
	BYTE				dwNetInterface;			// NSP
	BYTE				bTranMedia;				// 0£ºcable£¬1£ºwireless
	BYTE				bValid;					// Use bit to represent£¬ The first bit£º1£ºvalid 0£ºinvalid£»The second bit£º0£ºDisable DHCP 1£ºEnable DHCP£»The third bit£º0£ºDo not support DHCP 1£ºSupport DHCP
	BYTE				bDefaultEth;			// To be the default network card or not.  1£º default 0£ºnon-default 
	char				byMACAddr[DH_MACADDR_LEN];	// MAC address , read-only.£¬ 
} DH_ETHERNET; 

// Remote host setup 
typedef struct 
{
	BYTE				byEnable;				// Enable connection 
	BYTE				byReserved;
	WORD				wHostPort;				// Remote host Port 
	char				sHostIPAddr[DH_MAX_IPADDR_LEN];		// Remote host IP address  				
	char				sHostUser[DH_MAX_HOST_NAMELEN];		// Remote host User name   
	char				sHostPassword[DH_MAX_HOST_PSWLEN];	// Remote host Password   
} DH_REMOTE_HOST;

// Mail setup 
typedef struct 
{
	char				sMailIPAddr[DH_MAX_IPADDR_LEN];	// Email server IP
	WORD				wMailPort;				// Email server port 
	WORD				wReserved;				// Reserved
	char				sSenderAddr[DH_MAX_MAIL_ADDR_LEN];	// Send out address 
	char				sUserName[DH_MAX_NAME_LEN];			// User name 
	char				sUserPsw[DH_MAX_NAME_LEN];			// User password 
	char				sDestAddr[DH_MAX_MAIL_ADDR_LEN];	// Destination address 
	char				sCcAddr[DH_MAX_MAIL_ADDR_LEN];		// CC address 
	char				sBccAddr[DH_MAX_MAIL_ADDR_LEN];		// BCC address 
	char				sSubject[DH_MAX_MAIL_SUBJECT_LEN];	// Subject 
} DH_MAIL_CFG;

// Network configuration structure 
typedef struct
{ 
	DWORD				dwSize; 

	char				sDevName[DH_MAX_NAME_LEN];	// Device host name

	WORD				wTcpMaxConnectNum;		// TCP max conntion amount
	WORD				wTcpPort;				// TCP listening port 
	WORD				wUdpPort;				// UDP listening port 
	WORD				wHttpPort;				// HTTP port number 
	WORD				wHttpsPort;				// HTTPS port number 
	WORD				wSslPort;				// SSL port number 
	DH_ETHERNET			stEtherNet[DH_MAX_ETHERNET_NUM];	// Ethernet port 

	DH_REMOTE_HOST		struAlarmHost;			// Alarm server 
	DH_REMOTE_HOST		struLogHost;			// Log server 
	DH_REMOTE_HOST		struSmtpHost;			// SMTP server 
	DH_REMOTE_HOST		struMultiCast;			// Multiple-cast group 
	DH_REMOTE_HOST		struNfs;				// NFS server
	DH_REMOTE_HOST		struPppoe;				// PPPoE server 
	char				sPppoeIP[DH_MAX_IPADDR_LEN]; // returned IP after PPPoE resgistration 
	DH_REMOTE_HOST		struDdns;				// DDNS server
	char				sDdnsHostName[DH_MAX_HOST_NAMELEN];	// DDNS host name
	DH_REMOTE_HOST		struDns;				// DNS server 
	DH_MAIL_CFG			struMail;				// Email setup 
} DHDEV_NET_CFG;

// ddns configuraiton structure 
typedef struct
{
	DWORD				dwId;					// ddns server id
	bool				bEnable;				// Enbale. There is only one valid ddns server at one time.
	char				szServerType[DH_MAX_SERVER_TYPE_LEN];	// Server type. www.3322.org.
	char				szServerIp[DH_MAX_DOMAIN_NAME_LEN];		// Server IP or domain name 
	DWORD				dwServerPort;			// Server port 
	char				szDomainName[DH_MAX_DOMAIN_NAME_LEN];	// DVR domain name such as jeckean.3322.org
	char				szUserName[DH_MAX_HOST_NAMELEN];		// User name
	char				szUserPsw[DH_MAX_HOST_PSWLEN];			// Password
	char				szAlias[DH_MAX_DDNS_ALIAS_LEN];			// Server alias such as "dahua inter ddns"
	DWORD				dwAlivePeriod;							// DDNS alive period
	char				reserved[256];
} DH_DDNS_SERVER_CFG;

typedef struct
{
	DWORD				dwSize;
	DWORD				dwDdnsServerNum;	
	DH_DDNS_SERVER_CFG	struDdnsServer[DH_MAX_DDNS_NUM];	
} DHDEV_MULTI_DDNS_CFG;

// Mail configration structure 
typedef struct 
{
	char				sMailIPAddr[DH_MAX_DOMAIN_NAME_LEN];	// Mail server address(IP and domain name )
	char				sSubMailIPAddr[DH_MAX_DOMAIN_NAME_LEN];
	WORD				wMailPort;								// Mail server port 
	WORD				wSubMailPort;
	WORD				wReserved;								// Reserved 
	char				sSenderAddr[DH_MAX_MAIL_ADDR_LEN];		// From
	char				sUserName[DH_MAX_MAIL_NAME_LEN];		// User name
	char				sUserPsw[DH_MAX_MAIL_NAME_LEN];			// assword
	char				sDestAddr[DH_MAX_MAIL_ADDR_LEN];		// To
	char				sCcAddr[DH_MAX_MAIL_ADDR_LEN];			// CC
	char				sBccAddr[DH_MAX_MAIL_ADDR_LEN];			// BCC
	char				sSubject[DH_MAX_MAIL_SUBJECT_LEN];		// Subject
	BYTE				bEnable;								// Enable 0:false,	1:true
	char				reserved[159];
} DHDEV_MAIL_CFG;

// DNS server setup 
typedef struct  
{
	char				szPrimaryIp[DH_MAX_IPADDR_LEN];
	char				szSecondaryIp[DH_MAX_IPADDR_LEN];
	char				reserved[256];
} DHDEV_DNS_CFG;

// Record download strategy setup 
typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;				// TRUE£º high-speed download£¬FALSE£ºgeneral download  
}DHDEV_DOWNLOAD_STRATEGY_CFG;

// Network transmission strategy setup 
typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;
	int					iStrategy;				// 0£º video quality£¬1£ºfluency £¬2£º auto
}DHDEV_TRANSFER_STRATEGY_CFG;

// The corresponding parameter when setting log in
typedef struct  
{
	int					nWaittime;				// Waiting time (unit is ms)
	int					nConnectTime;			// Connection timeout value (Unit is ms)
	int					nConnectTryNum;			// Connection trial times(Unit is ms)
	int					nSubConnectSpaceTime;	// Sub-connection waiting time(Unit is ms)
	BYTE				bReserved[32];			// Reserved string 
} NET_PARAM;

// Corresponding to CLIENT_SearchDevices
typedef struct 
{
	char				szIP[DH_MAX_IPADDR_LEN];		// IP
	int					nPort;							// Port
	char				szSubmask[DH_MAX_IPADDR_LEN];	// Subnet mask
	char				szGateway[DH_MAX_IPADDR_LEN];	// Gateway
	char				szMac[DH_MACADDR_LEN];			// MAC address
	char				szDeviceType[DH_DEV_TYPE_LEN];	// Device type
	BYTE				bReserved[32];					// Reserved string 
} DEVICE_NET_INFO;

//-------------------------------Alarm Property ---------------------------------

// PTZ Activation
typedef struct 
{
	int					iType;
	int					iValue;
} DH_PTZ_LINK, *LPDH_PTZ_LINK;

//Alarm activation structure 
typedef struct 
{
	/* Message process way. There can be several process ways.
	 * 0x00000001 -  Alarm upload
	 * 0x00000002 -  Activation alarm 
	 * 0x00000004 -  PTZ activation
	 * 0x00000008 -  Send out mail
	 * 0x00000010 -  Local tour
	 * 0x00000020 -  Local prompt
	 * 0x00000040 -  Alarm output
	 * 0x00000080 - Ftp upload
	 * 0x00000100 -  Buzzer 
	 * 0x00000200 -  Video prompt
	 * 0x00000400 -  Snapshot
	*/

	/* The process way current alarm supported. Use bit mask to represent */
	DWORD				dwActionMask;

	/* Use bit mask to represent. The parameters of detailed operation are in its correspondg configuration */
	DWORD				dwActionFlag;
	
	/* The output channel the alarm activated. The output alarm activated. 1 means activate current output. */ 
	BYTE				byRelAlarmOut[DH_MAX_ALARMOUT_NUM];
	DWORD				dwDuration;				/*  Alarm duration time*/

	/* Activation record */
	BYTE				byRecordChannel[DH_MAX_VIDEO_IN_NUM]; /*  The record channel alarm activated. 1 means activate current channel. */
	DWORD				dwRecLatch;				/*  Record duration time */

	/* Snapshot channel  */
	BYTE				bySnap[DH_MAX_VIDEO_IN_NUM];
	/* Tour channel */
	BYTE				byTour[DH_MAX_VIDEO_IN_NUM];

	/* PTZ activation  */
	DH_PTZ_LINK			struPtzLink[DH_MAX_VIDEO_IN_NUM];
	DWORD				dwEventLatch;			/* The latch time after activation begins. Unit is second. The value ranges from 0 to 15. Default value is 0. */
	/* The wireless output channel alarm activated.The output alarm activated. 1 means activate current output.*/ 
	BYTE				byRelWIAlarmOut[DH_MAX_ALARMOUT_NUM];
	BYTE				bMessageToNet;
	BYTE				byReserved[111];       
} DH_MSG_HANDLE;

// External alarm 
typedef struct
{
	BYTE				byAlarmType;			// Annunciator type£¬0£º normal close£¬1£ºnormal open 
	BYTE				byAlarmEn;				// Enable alarm 
	BYTE				byReserved[2];						
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT]; // NSP
	DH_MSG_HANDLE		struHandle;				// Process way 
} DH_ALARMIN_CFG, *LPDHDEV_ALARMIN_CFG; 

//Motion detection alarm 
typedef struct 
{
	BYTE				byMotionEn;				// Enable motion detection alarm 
	BYTE				byReserved;
	WORD				wSenseLevel;			// Sensitivity 
	WORD				wMotionRow;				// Row amount in motion detection zones
	WORD				wMotionCol;				// Column amount in motion detection zones 
	BYTE				byDetected[DH_MOTION_ROW][DH_MOTION_COL]; // Detection zones .Max 32*32 zones.
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];	// NSP
	DH_MSG_HANDLE		struHandle;				// Process way 
} DH_MOTION_DETECT_CFG;

// Video loss alarm 
typedef struct
{
	BYTE				byAlarmEn;				// Enable video loss alarm 
	BYTE				byReserved[3];
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];	// NSP
	DH_MSG_HANDLE		struHandle;				// Process way
} DH_VIDEO_LOST_CFG;

// Camera masking alarm 
typedef struct
{
	BYTE				byBlindEnable;			// Enable
	BYTE				byBlindLevel;			// Sensitivity 1-6
	BYTE				byReserved[2];
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];	// NSP
	DH_MSG_HANDLE		struHandle;				// Process way 
} DH_BLIND_CFG;

// HDD information(External alarm )
typedef struct 
{
	BYTE				byNoDiskEn;				// Alarm when there is no HDD
	BYTE				byReserved_1[3];
	DH_TSECT			stNDSect[DH_N_WEEKS][DH_N_REC_TSECT]; // NSP
	DH_MSG_HANDLE		struNDHandle;			// Process way 

	BYTE				byLowCapEn;				// Alarm when HDD capacity is low 
	BYTE				byLowerLimit;			// Capacity threshold 0-99
	BYTE				byReserved_2[2];
	DH_TSECT			stLCSect[DH_N_WEEKS][DH_N_REC_TSECT]; // NSP
	DH_MSG_HANDLE		struLCHandle;			// Process way 

	BYTE				byDiskErrEn;			// HDD malfucntion alarm 
	BYTE				bDiskNum;
	BYTE				byReserved_3[2];
	DH_TSECT			stEDSect[DH_N_WEEKS][DH_N_REC_TSECT]; // NSP
	DH_MSG_HANDLE		struEDHandle;			// Process way 
} DH_DISK_ALARM_CFG;

typedef struct
{
	BYTE				byEnable;
	BYTE				byReserved[3];
	DH_MSG_HANDLE		struHandle;
} DH_NETBROKEN_ALARM_CFG;

// Alarm deployment 
typedef struct
{
	DWORD dwSize;
	DH_ALARMIN_CFG 		struLocalAlmIn[DH_MAX_ALARM_IN_NUM];
	DH_ALARMIN_CFG		struNetAlmIn[DH_MAX_ALARM_IN_NUM];
	DH_MOTION_DETECT_CFG struMotion[DH_MAX_VIDEO_IN_NUM];
	DH_VIDEO_LOST_CFG	struVideoLost[DH_MAX_VIDEO_IN_NUM];
	DH_BLIND_CFG		struBlind[DH_MAX_VIDEO_IN_NUM];
	DH_DISK_ALARM_CFG	struDiskAlarm;
	DH_NETBROKEN_ALARM_CFG	struNetBrokenAlarm;
} DHDEV_ALARM_SCHEDULE;

// The setup of alarm upload
typedef struct  
{
	BYTE				byEnable;				// Enable upload
	BYTE				bReserverd;				// Reserved
	WORD				wHostPort;				// Alarm centre listening port 
	char				sHostIPAddr[DH_MAX_IPADDR_LEN];		// Alarm centre IP

	int					nByTimeEn;				// Enable scheduled upload.Use it to upload IP or domain name to the centre.
	int					nUploadDay;				/*  Set upload date 
													"Never = 0", "Everyday = 1", "Sunday = 2", 
													"Monday = 3", Tuesday = 4", "Wednesday = 5",
													"Thursday = 6", "Friday = 7", "Saturday = 8"*/	
	int					nUploadHour;			// Set upload time ,[0~23]o'clock
	
	DWORD				dwReserved[300]; 		// Reserved for future development 
}ALARMCENTER_UP_CFG;

//------------------------------Multiple privacy mask zones--------------------------------

// Privacy mask information
typedef struct __VIDEO_COVER_ATTR
{
	DH_RECT				rcBlock;				// Privacy mask zone coordinates
	int					nColor;					// Privacy mask color
	BYTE				bBlockType;				// Mask type£»0£ºBlack block£¬1£º mosaic
	BYTE				bEncode;				// Encode lelel mask£»1£ºvalid£¬0£ºinvalid
	BYTE				bPriview;				// Preview mask£» 1£ºvalid£¬0£ºinvalid
	char				reserved[29];			// Reserved 
} VIDEO_COVER_ATTR;

// Multiple privacy mask zones 
typedef struct __DHDEV_VIDEOCOVER_CFG 
{
	DWORD				dwSize;
	char				szChannelName[DH_CHAN_NAME_LEN]; // Read-only
	BYTE				bTotalBlocks;			// The mask zones supported
	BYTE				bCoverCount;			// The mask zones have been set 
	VIDEO_COVER_ATTR	CoverBlock[DH_MAX_VIDEO_COVER_NUM]; // The mask zones 
	char				reserved[30];			// Reserved 
}DHDEV_VIDEOCOVER_CFG;

////////////////////////////////IPC series ////////////////////////////////

// Set wireless network information 
typedef struct 
{
	int					nEnable;				// Enable wireless
	char				szSSID[36];				// SSID
	int					nLinkMode;				// onnecion mode£»0£ºauto£¬1£ºadhoc£¬2£ºInfrastructure
	int					nEncryption;			// encrypt£»0£ºoff£¬2£ºWEP64bit£¬3£ºWEP128bit
	int					nKeyType;				// 0£ºHex£¬1£ºASCII
    int					nKeyID;					// Serial number
	char				szKeys[4][32];			// Four group passwords 
	int					nKeyFlag;
	char				reserved[12];
} DHDEV_WLAN_INFO;

// Select to use one wireless device 
typedef struct  
{
	char				szSSID[36];
	int					nLinkMode;				// Connection mode£»0£ºadhoc£¬1£ºInfrastructure
	int 				nEncryption;			// Encrypt£»0£ºoff£¬2£ºWEP64bit£¬3£ºWEP128bit
	char				reserved[48];
} DHDEV_WLAN_DEVICE;

// The searched wireless device list 
typedef struct  
{
	DWORD				dwSize;
	BYTE				bWlanDevCount;			// The wireless devices searched 
	DHDEV_WLAN_DEVICE	lstWlanDev[DH_MAX_WLANDEVICE_NUM];
	char				reserved[255];
} DHDEV_WLAN_DEVICE_LIST;

// Auto registration parameter setup 
typedef struct  
{
	char				szServerIp[32];			// Registration server IP
	int					nServerPort;			// Port number 
	char				reserved[64];
} DHDEV_SERVER_INFO;

typedef struct  
{
	DWORD				dwSize;
	BYTE				bServerNum;				// The max IP amount supported
	DHDEV_SERVER_INFO	lstServer[DH_MAX_REGISTER_SERVER_NUM];
	BYTE				bEnable;				// Enable
	char				szDeviceID[32];			// Device ID
	char				reserved[94];
} DHDEV_REGISTER_SERVER;

// Camera property 
typedef struct __DHDEV_CAMERA_INFO
{
	BYTE				bBrightnessEn;			// Brightness adjustable£»1£ºadjustable£¬0£ºcan not be adjusted
	BYTE				bContrastEn;			// Contrast adjustable
	BYTE				bColorEn;				// Hue adjustable
	BYTE				bGainEn;				// Gain adjustable
	BYTE				bSaturationEn;			// Saturation adjustable
	BYTE				bBacklightEn;			// Backlight compensation adjustable
	BYTE				bExposureEn;			// Exposure option adjustable
	BYTE				bColorConvEn;			// Day/nignt switch 
	BYTE				bAttrEn;				// Property option£»1£ºEnable£¬0£ºDisable
	BYTE				bMirrorEn;				// Mirror£»1£ºsupport£¬0£ºdo not support 
    BYTE				bFlipEn;				// Flip£»1£ºsupport £¬0£ºdo not support  
	BYTE				bRev[125];				// Reserved 
} DHDEV_CAMERA_INFO;

// Camera property setup 
typedef struct __DHDEV_CAMERA_CFG 
{
	DWORD				dwSize;
	BYTE				bExposure;				// Exposure mode£»1-9£ºManual exposure level  £¬0£º Auto exposure 
	BYTE				bBacklight;				// Backlight compensation£º3:High£¬2£ºMedium£¬1£ºLow£¬0£ºclose
	BYTE				bAutoColor2BW;			// Day/night mode£»2£ºOpen£¬1£ºAuto£¬0£ºClose
	BYTE				bMirror;				// Mirror£»1£ºOpen£¬0£ºClose
	BYTE				bFlip;					// Flip£»1£ºOpen£¬0£ºClose  support£»0 £ºdo not support 
	BYTE				bLensFunction;			// Auto aperture function: 1:Enable aperture  £»0: Disable aperture  
	char				bRev[121];				// Reserved 
} DHDEV_CAMERA_CFG;

#define ALARM_MAX_NAME 64
// (wireless)IR alarm setup
typedef struct
{
	BOOL				bEnable;				// Enable alarm input
	char				szAlarmName[DH_MAX_ALARM_NAME];	// Alarm input name
	int					nAlarmInPattern;		// Annunciator input wave
	int					nAlarmOutPattern;		// Annunciator output wave
	char				szAlarmInAddress[DH_MAX_ALARM_NAME];// Alarm input address
	int					nSensorType;			// External device sensor type normal open or normal close 
	int					nDefendEfectTime;		// Deploy and cancel latch time. The alarm input becomes activated after the specified time.
	int					nDefendAreaType;		// Defend area 
	int					nAlarmSmoothTime;		// Alarm smooth time:system ingores the second alarm if one alarm inputs in two times. 
	char				reserved[128];
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];
	DH_MSG_HANDLE		struHandle;				// Process way 
} DH_INFRARED_INFO;

// Wireless remote control setup 
typedef struct 
{
	BYTE				address[ALARM_MAX_NAME];// Remote control address
	BYTE				name[ALARM_MAX_NAME];	// Remote control name
	BYTE				reserved[32];			// Reserved string 
} DH_WI_CONFIG_ROBOT;

// Wireless alarm output setup 
typedef struct 
{
	BYTE				address[ALARM_MAX_NAME];// Alarm output address
	BYTE				name[ALARM_MAX_NAME];	// Aalarm output name
	BYTE				reserved[32];			// Reserved string 
} DH_WI_CONFIG_ALARM_OUT;

typedef struct  
{
	DWORD				dwSize;
	BYTE				bAlarmInNum;			// Wireless alarm input amount 
	BYTE				bAlarmOutNum;			// Wireless alarm output amount 
	DH_WI_CONFIG_ALARM_OUT AlarmOutAddr[16];	// Alarm output address
	BYTE				bRobotNum;				// Remote control amount
	DH_WI_CONFIG_ROBOT RobotAddr[16];			// Remote control address 
	DH_INFRARED_INFO	InfraredAlarm[16];
	char				reserved[256];
} DH_INFRARED_CFG;

// New audio detection alarm information 
typedef struct
{
	int					channel;				// Alarm channel number
	int					alarmType;				// Alarm type£»0£ºVolumn value is too low £¬1£ºVolumn value is too high. 
	unsigned int		volume;					// Volume
	char				reserved[256];
} NET_NEW_SOUND_ALARM_STATE;

typedef struct  
{
	int					channelcount;			// Alarm channel amount 
	NET_NEW_SOUND_ALARM_STATE SoundAlarmInfo[DH_MAX_ALARM_IN_NUM];
} DH_NEW_SOUND_ALARM_STATE;

// Snapshot function property structure 
typedef struct 
{
	int					nChannelNum;			// Channel amount 
	DWORD				dwVideoStandardMask;	// Resolution(Bit). Please refer to enumeration CAPTURE_SIZE						
	int					nFramesCount;			// Valid length of Frequence[128] array
	char				Frames[128];			// Frame rate(value) 
												// -25£º1f/25s£»-24£º1f/24s£»-23£º1f/23s£»-22£º1f/23s
												// ¡­¡­
												// 0£º invalid£»1£º1f/s£»2£º2f/s£»3£º13f/s
												// 4£º4f/s£»5£º5f/s£»17£º17f/s£»18£º18f/s
												// 19£º19f/s£»20£º20f/s
												// ¡­¡­
												// 25: 25f/s
	int					nSnapModeCount;			// valid lenght of SnapMode[16] array
	char				SnapMode[16];			// (value)0£ºactivate scheduled snapshot£¬1£ºManually activate snapshot
	int					nPicFormatCount;		// Valid length of Format[16] array 
	char 				PictureFormat[16];		// (Value)0£ºBMP format£¬1£ºJPG format
	int					nPicQualityCount;		// valid length of Quality[32] array
	char 				PictureQuality[32];		// value
												// 100£ºImage quality 100%£»80:Image quality 80%£»60:Image quality60%
												// 50:Image quality50%£»30:Image quality30%£»10:Image quality10%
	char 				nReserved[128];			// Reserved
} DH_QUERY_SNAP_INFO;

typedef struct 
{
	int					nChannelCount;			// Channel amount 
	DH_QUERY_SNAP_INFO  stuSnap[DH_MAX_CHANNUM];
}DH_SNAP_ATTR_EN;

////////////////////////////////Mobile DVR supported////////////////////////////////

// GPS information(Mobile device)
typedef struct _GPS_Info
{
    NET_TIME			revTime;				// Postion time 
	char				DvrSerial[50];			// Device serial number
    double				longitude;				// Longitude
    double				latidude;				// Latitude 
    double				height;					// Height(meter)
    double				angle;					// Angle(The north pole is the original point and clockwise is +)
    double				speed;					// Speed(Kilomter/hour)
    WORD				starCount;				// Starcount
    BOOL				antennaState;			// Antenna status(true=good£¬false =bad)
    BOOL				orientationState;		// Orientation status (true=position£¬false = no position )
} GPS_Info,*LPGPS_Info;

// Snapshot parameter structure 
typedef struct _snap_param
{
	unsigned int		Channel;				// Snapshot channel
	unsigned int		Quality;				// Image quality:level 1 to level 6
	unsigned int		ImageSize;				// Vide size£»0£ºQCIF£¬1£ºCIF£¬2£ºD1
	unsigned int		mode;					// Snapshot mode£»0£ºrequest one frame£¬1£ºsend out requestion regularly£¬2£º Request consecutively
	unsigned int		InterSnap;				// Time unit is second.If mode=1, it means send out requestion regularly. The time is valid.
	unsigned int		CmdSerial;				// Request serial number
	unsigned int		Reserved[4];
} SNAP_PARAMS, *LPSNAP_PARAMS;

// Snapshot function setup 
typedef struct 
{
	DWORD				dwSize;
	BOOL				bTimingEnable;			// Sechedule snapshot button(The alarm snapshot button is in alarm activation configuration) 
	DH_VIDEOENC_OPT		struSnapEnc[SNAP_TYP_NUM]; // Snapshot encode setup. The resolution, video quality, frame rate setup and fram rate are all negative. It means the snapshot times in each second. 
} DHDEV_SNAP_CFG;

//////////////////////////////////ATM support//////////////////////////////////

typedef struct
{
	int					Offset;					// Symbol position bit Offser
	int					Length;					// Symbol position length
	char				Key[16];				// Symbol position value 
} DH_SNIFFER_FRAMEID;

typedef struct 
{
	int					Offset;					// Symbol position bit offset 
	int					Offset2;				// It is invalid now 
	int					Length;					// The symbol postion length
	int					Length2;				// It is invald now
	char				KeyTitle[24];			// Title value 
} DH_SNIFFER_CONTENT;

// Network sniffer setup 
typedef struct 
{
	DH_SNIFFER_FRAMEID	snifferFrameId;			// Each FRAME ID option
	DH_SNIFFER_CONTENT	snifferContent[DH_SNIFFER_CONTENT_NUM];	// The corresponding four sniffers in each FRAME
} DH_SNIFFER_FRAME;

// Configuration structure of each sniffer 
typedef struct
{
	char				SnifferSrcIP[DH_MAX_IPADDR_LEN];	// Sniffer source address 	
	int					SnifferSrcPort;			// Sniffer source port 
	char				SnifferDestIP[DH_MAX_IPADDR_LEN];	// Sniffer destination address 
	int					SnifferDestPort;		// Sniffer detination port 
	char				reserved[28];			// Reserved string 
	DH_SNIFFER_FRAME	snifferFrame[DH_SNIFFER_FRAMEID_NUM];	// 6 FRAME options 
	int					displayPosition;		// Display postion 
	int					recdChannelMask;		// Channel mask
} DH_ATM_SNIFFER_CFG;

typedef struct  
{
	DWORD				dwSize;
	DH_ATM_SNIFFER_CFG	SnifferConfig[4];
	char				reserved[256];			// Reserved string 
} DHDEV_SNIFFER_CFG;



/////////////////////////////////Special version/////////////////////////////////

// Activate device to snapshot overlay card number information 
typedef struct __NET_SNAP_COMMANDINFO 
{
	char				szCardInfo[16];			// Card information
	char				reserved[64];			// Reserved 
} NET_SNAP_COMMANDINFO, LPNET_SNAP_COMMANDINFO;

typedef struct
{
	int					nChannelNum;			// Channel number 
	char				szUseType[32];			// Channel type 
	DWORD				dwStreamSize;			// Stream size(Unit£ºkb/s)
	char				reserved[32];			// Reserved 
} DHDEV_USE_CHANNEL_STATE;

typedef struct 
{
	char				szUserName[32];			// User name 
	char				szUserGroup[32];		// User group 
	NET_TIME			time;					// Log in time
	int					nOpenedChannelNum;		// Enabled channel amount 
	DHDEV_USE_CHANNEL_STATE	channelInfo[DH_MAX_CHANNUM];
	char				reserved[64];
} DHDEV_USER_NET_INFO;

// Network running status information 
typedef	struct 
{
	int					nUserCount;				// User amount
	DHDEV_USER_NET_INFO	stuUserInfo[32];
	char				reserved[256];
}DHDEV_TOTAL_NET_STATE;

// Image watermark setup 
typedef struct __DHDEV_WATERMAKE_CFG 
{
	DWORD				dwSize;
	int					nEnable;				// Enable 
	int					nStream;				// Bit stream(1¡«n)0- All bit streams
	int					nKey;					// Data type(1- text£¬2- image )
	char				szLetterData[DH_MAX_WATERMAKE_LETTER];	// text
	char				szData[DH_MAX_WATERMAKE_DATA]; // Image data
	BYTE				bReserved[512];			// Reserved
} DHDEV_WATERMAKE_CFG;

// Storage position set structure.  Each channel set separately.Each channel can set several storage types including local,portableand remote storage.
typedef struct 
{
	DWORD				dwSize;
	DWORD				dwLocalMask;			// Local storage mask. Use bit to represent.
												// The first bit£ºsystem pre-record. The second bit£ºscheduled record. The third bit:motion detection record.
												// The fourth bit£ºalarm record. The fifth bit:card record. The sixth bit:manual record.
	DWORD				dwMobileMask;			// Moving storage mask. Storage mask such as local storage mask.
	int					RemoteType;				// Remote storage type 0: Ftp  1: Smb 
	DWORD				dwRemoteMask;			// Remote storage mask.  Storage mask such as local storage mask.
	DWORD				dwRemoteSecondSelLocal;	// Local storage mask when remote is abnormal
	DWORD				dwRemoteSecondSelMobile;// Moving storage mask when remote is abnormal.
	char				SubRemotePath[MAX_PATH_STOR]; // Remote path. Its length is 240
	DWORD				dwFunctionMask;			// Function shield bit. Use bit to represent bit0 = 1:Shield sanpshot event activate storage position function.
	
	char				reserved[124];
} DH_STORAGE_STATION_CFG;

#define MAX_ALARM_DECODER_NUM 16
typedef struct  
{
	DWORD				dwAlarmDecoder;			// Now it supports max 8 alarm input ports. Reserved 8 bits for future development.
	BYTE				bDecoderIndex;			// It means it is from which alarm decoder.
	BYTE				bReserved[3];
} ALARM_DECODER;

// Alarm decoder alarm 
typedef struct
{
	int					nAlarmDecoderNum;
	ALARM_DECODER		stuAlarmDecoder[MAX_ALARM_DECODER_NUM];
	BYTE				bReserved[32];
} ALARM_DECODER_ALARM;

// New audio detection alarm setup 
typedef struct
{
	BOOL				bEnable;				// Enable alarm input 
	int					Volume_min;				// Min volume
	int					Volume_max;				// Max volume
	char				reserved[128];	
	DH_TSECT			stSect[DH_N_WEEKS][DH_N_REC_TSECT];	
	DH_MSG_HANDLE		struHandle;				// Process way 
} DH_AUDIO_DETECT_INFO;

typedef struct  
{
	DWORD				dwSize;
	int					AlarmNum;
	DH_AUDIO_DETECT_INFO AudioDetectAlarm[DH_MAX_AUDIO_IN_NUM];
	char				reserved[256];
} DH_AUDIO_DETECT_CFG;

typedef struct
{
	BOOL				bTourEnable;			// Enable tour
	int					nTourPeriod;			// Tour interval. Unit is second. The value ranges from 5 to 300 
	DWORD				dwChannelMask;			// Tour channel. Use mas bit to represent.
	char				reserved[64];
}DH_VIDEOGROUP_CFG;

// Local matrix control strategy setup 
typedef struct
{
	DWORD				dwSize;
	int					nMatrixNum;				// Matrix amount(Read only )
	DH_VIDEOGROUP_CFG	struVideoGroup[DH_MATRIX_MAXOUT];
	char				reserved[32];
} DHDEV_VIDEO_MATRIX_CFG;   

// WEB path setup 
typedef struct 
{
	DWORD				dwSize;
	BOOL				bSnapEnable;			// Snapshot or not
	int					iSnapInterval;			// Snapshot interval
	char				szHostIp[DH_MAX_IPADDR_LEN]; // HTTP host IP
	WORD				wHostPort;
	int					iMsgInterval;			// Message sending out interval
	char				szUrlState[DH_MAX_URL_LEN];	// Status message upload URL
	char				szUrlImage[DH_MAX_URL_LEN];	// Image upload Url
	char				szDevId[DH_MAX_DEV_ID_LEN];	// Device web serial number
	BYTE				byReserved[2];
} DHDEV_URL_CFG;

// OEM search 
typedef struct  
{
	char				szVendor[DH_MAX_STRING_LEN];
	char				szType[DH_MAX_STRING_LEN];
	char				reserved[128];
} DHDEV_OEM_INFO;


//Video OSD
typedef struct 
{ 
	DWORD	rgbaFrontground;		// Object front view. Use bit to represent:red,green, blue and transparency.
	DWORD	rgbaBackground;			// Object background. Use bit to represent:red,green, blue and transparency
	RECT	rcRelativePos;			// Position. The proportion of border distance and whole length *8191
	BOOL	bPreviewBlend;			// Enable preview overlay	
	BOOL	bEncodeBlend;			// Enable encode overlay
	BYTE    bReserved[4];           // Reserved 
} DH_DVR_VIDEO_WIDGET;

typedef struct 
{
	DH_DVR_VIDEO_WIDGET	StOSD_POS; 								// OSD position and background color.
	char 				SzOSD_Name[DH_VIDEO_OSD_NAME_NUM]; 		// OSD name 
}DH_DVR_VIDEOITEM;
 
// OSD information in each channel
typedef struct 
{
	DWORD 				dwSize;
	DH_DVR_VIDEOITEM 	StOSDTitleOpt [DH_VIDEO_CUSTOM_OSD_NUM];// Each channel OSD informaiton
	BYTE    			bReserved[16];							// Reserved
}DH_DVR_VIDEOOSD_CFG;


/////////////////////////////////Embedded platform/////////////////////////////////

// Platform embedded setup £­ U China Network Communication(CNC)
typedef struct
{
    BOOL				bChnEn;
    char				szChnId[DH_INTERVIDEO_UCOM_CHANID];
} DH_INTERVIDEO_UCOM_CHN_CFG;

typedef struct
{
	DWORD				dwSize;
	BOOL				bFuncEnable;			// Enable connection
	BOOL				bAliveEnable;			// Enable alive
	DWORD				dwAlivePeriod;			// Alive period. Unit is second. The value ranges from 0 to 3600.
	char				szServerIp[DH_MAX_IPADDR_LEN]; // CMS IP
	WORD				wServerPort;			// CMS Port
    char				szRegPwd[DH_INTERVIDEO_UCOM_REGPSW]; // Registration password 
	char				szDeviceId[DH_INTERVIDEO_UCOM_DEVID];// Device id
	char				szUserName[DH_INTERVIDEO_UCOM_USERNAME];
	char				szPassWord[DH_INTERVIDEO_UCOM_USERPSW];
    DH_INTERVIDEO_UCOM_CHN_CFG  struChnInfo[DH_MAX_CHANNUM]; // Channel id,en
} DHDEV_INTERVIDEO_UCOM_CFG;

//  Platform embedded setup £­ Alcatel
typedef struct
{
	DWORD				dwSize;
    unsigned short		usCompanyID[2];			// Company ID£¬Value. the different three party service company. Now use the first array considering the four bytes in line.
    char				szDeviceNO[32];			// Strings including '\0' are 32 bytes.
    char				szVSName[32];			// Front-end device name. Strings including '\0' are 16 bytes.
    char				szVapPath[32];			// VAP path
    unsigned short		usTcpPort;				// TCP port£¬value£ºvalue ranges from 1 to 65535 
    unsigned short		usUdpPort;				// UDP port£¬Value£ºValue ranges from 1 to 65535
    bool				bCsEnable[4];			// Enable central server symbol. Value:true=enable,false=disable.Now only use the first array considering the four bytes in line.
    char				szCsIP[16];				// Central server IP address.Strings including '\0' are 16 bytes.
    unsigned short		usCsPort[2];			// Central server port. Value ranges from 1 to 65535.Now only use the first array considering the four bytes in line.
    bool				bHsEnable[4];			// Enable pulse server symbol. Value:treu-enbale,false=disable.Now only use the first array considering the four bytes in line.
    char				szHsIP[16];				// Pulse server IP address. Strings including '\0' are 16 bytes.
    unsigned short		usHsPort[2];			// Pulse server port. Value ranges from 1 to 65535.Now only use the first array considering the four bytes in line
    int					iHsIntervalTime;		// Pulse server interval. Value(unit is second)
    bool				bRsEnable[4];			// Enable registration server symbol. Value:£¬true=enable£¬false=disable.Now only use the first array considering the four bytes in line. 
    char				szRsIP[16];				// Registration server IP address. Strings including '\0' are 16 bytes.
    unsigned short		usRsPort[2];			// Registration server port. Value. The value ranges from 1 to 65535.Now use the first array considering the four bytes in line
    int					iRsAgedTime;			// Registration server valid duration. Value(unit is hour)
    char				szAuthorizeServerIp[16];// IP Authorization server IP
    unsigned short		usAuthorizePort[2];		// Authorization server port. Now only use the first array considering the four bytes in line
    char				szAuthorizeUsername[32];// Authorization server account
    char				szAuthorizePassword[36];// Authorization server password
    
    char				szIpACS[16];			// ACS( auto registration server) IP
    unsigned short		usPortACS[2];			// ACS Port£¬Now only use the first array considering the four bytes in line. 
    char				szUsernameACS[32];		// ACS user name
    char				szPasswordACS[36];		// ACS password
    bool				bVideoMonitorEnabled[4];// DVS regularly uploads front-end video monitor message or not.Value£ºtrue=enable£¬false=disable
    int					iVideoMonitorInterval;	// Upload interval(minute)
    
    char				szCoordinateGPS[64];	// GPS coordinates
    char				szPosition[32];			// Device position
    char				szConnPass[36];			// Device connection bit 
} DHDEV_INTERVIDEO_BELL_CFG;

//  Platform embedded setup £­ ZTE Netview
typedef struct  
{
	DWORD				dwSize;
	unsigned short		nSevPort;				// Server port. Value. The value ranges from 1 to 65535
    char				szSevIp[DH_INTERVIDEO_NSS_IP]; // Server IP address£¬string£¬including '\0' end symbol, there are total 32byte.
    char				szDevSerial[DH_INTERVIDEO_NSS_SERIAL]; // Front-end device serial number, string including '\0' end symbol, there are total 32byte.
    char				szUserName[DH_INTERVIDEO_NSS_USER];
    char				szPwd[DH_INTERVIDEO_NSS_PWD];
} DHDEV_INTERVIDEO_NSS_CFG;


/////////////////////////////////Abandoned Type/////////////////////////////////

// Search device working staus channel information. Corresponding interfaces have been abandoned. Do not user.
typedef struct
{
	BYTE				byRecordStatic;			// Channel is recording or not. £»0£º does not record£¬1£º manual record£¬2£ºauto record  
	BYTE				bySignalStatic;			// Connected signal status £»0£ºnormal£¬1£ºsignal loss  
	BYTE				byHardwareStatic;		// Channel hardware status£»0£ºnormal £¬1£ºabnormal such as DSP is down £¬ 
	char				reserve;
	DWORD				dwBitRate;				// Actual bit rate
	DWORD				dwLinkNum;				// The client-end connected amount 
	DWORD				dwClientIP[DH_MAX_LINK];// Client-end IP address 
} NET_DEV_CHANNELSTATE, *LPNET_DEV_CHANNELSTATE;

// Search device working status. The corresponding interfaces have been abandoned. Please do not use
typedef struct
{
	DWORD				dwDeviceStatic;			// Device status£»0x00£ºnormal £¬0x01£ºCPU occupation is too high £¬0x02£ºhardware error 
	NET_DEV_DISKSTATE	stHardDiskStatic[DH_MAX_DISKNUM]; 
	NET_DEV_CHANNELSTATE stChanStatic[DH_MAX_CHANNUM];	// Channel status
	BYTE				byAlarmInStatic[DH_MAX_ALARMIN];// Alarm port status£»0£ºno alarm£¬1£º alarm
	BYTE				byAlarmOutStatic[DH_MAX_ALARMOUT]; // Alarm output port status£»0£ºno alarm£¬1£ºalarm  
	DWORD				dwLocalDisplay;			// Local display status  £»0£ºnormal£¬1£ºabnormal 
} NET_DEV_WORKSTATE, *LPNET_DEV_WORKSTATE;

// Protocol informaiton
typedef struct 
{
	char				protocolname[12];		// Protocl name
	unsigned int		baudbase;				// Baud rate
	unsigned char		databits;				// Data bit
	unsigned char		stopbits;				// Stop bit
	unsigned char		parity;					// Pairty bit 
	unsigned char		reserve;
} PROTOCOL_INFO, *LPPROTOCOL_INFO;

// Audio talk parameter setup
typedef struct 
{
	// Audio input parameter
	BYTE				byInFormatTag;			// Encode type such as PCM
	BYTE				byInChannels;			// Track amount
	WORD				wInBitsPerSample;		// Sampling depth 				
	DWORD				dwInSamplesPerSec;		// Sampling rate 

	// Audio output parameter
	BYTE				byOutFormatTag;			// Encode type such as PCM
	BYTE				byOutChannels;			// Track amount
	WORD				wOutBitsPerSample;		// Sampling depth 		
	DWORD				dwOutSamplesPerSec;		// Sampling rate
} DHDEV_TALK_CFG, *LPDHDEV_TALK_CFG;


/************************************************************************
 ** Callback Function Definition 
 ***********************************************************************/

// Network disconnection callback fucntion original shape 
typedef void (CALLBACK *fDisConnect)(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser);

// network re-connection callback fucntion original shape
typedef void (CALLBACK *fHaveReConnect)(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser);

// Real-time monitor data callback fucntion original shape
typedef void (CALLBACK *fRealDataCallBack)(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, DWORD dwUser);

// Real-time monitor data callback fucntion original shape---extensive
typedef void (CALLBACK *fRealDataCallBackEx)(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LONG param, DWORD dwUser);

// OSD callback fucntion original shape 
typedef void (CALLBACK *fDrawCallBack)(LONG lLoginID, LONG lPlayHandle, HDC hDC, DWORD dwUser);

// Playback data callback fucntion original shape 
typedef int (CALLBACK *fDataCallBack)(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, DWORD dwUser);

// Playback process callback fucntion original shape 
typedef void (CALLBACK *fDownLoadPosCallBack)(LONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, DWORD dwUser);

// Playback process by time callback fucntion original shape
typedef void (CALLBACK *fTimeDownLoadPosCallBack) (LONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, int index, NET_RECORDFILE_INFO recordfileinfo, DWORD dwUser);

// Alarm message callback fucntion original shape
typedef BOOL (CALLBACK *fMessCallBack)(LONG lCommand, LONG lLoginID, char *pBuf, DWORD dwBufLen, char *pchDVRIP, LONG nDVRPort, DWORD dwUser);

// Listening server callback fucntion original shape
typedef int (CALLBACK *fServiceCallBack)(LONG lHandle, char *pIp, WORD wPort, LONG lCommand, void *pParam, DWORD dwParamLen, DWORD dwUserData);

// Audio data of audio talk callback fucntion original shape 
typedef void (CALLBACK *pfAudioDataCallBack)(LONG lTalkHandle, char *pDataBuf, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser);

// Upgrade device callback fucntion original shape
typedef void (CALLBACK *fUpgradeCallBack) (LONG lLoginID, LONG lUpgradechannel, int nTotalSize, int nSendSize, DWORD dwUser);

// Transparent COM callback function original shape
typedef void (CALLBACK *fTransComCallBack) (LONG lLoginID, LONG lTransComChannel, char *pBuffer, DWORD dwBufSize, DWORD dwUser);

// Search device log data callback fucntion original shape 
typedef void (CALLBACK *fLogDataCallBack)(LONG lLoginID, char *pBuffer, DWORD dwBufSize, DWORD nTotalSize, BOOL bEnd, DWORD dwUser);

// Snapshot callback fucntion original shape 
typedef void (CALLBACK *fSnapRev)(LONG lLoginID, BYTE *pBuf, UINT RevLen, UINT EncodeType, DWORD CmdSerial, DWORD dwUser);

// GPS message subscription callback 
typedef void( CALLBACK *fGPSRev)(LONG lLoginID, GPS_Info GpsInfo, DWORD dwUserData);


/************************************************************************
 ** Interface Definition 
 ***********************************************************************/

// SDK Initialization 
CLIENT_API BOOL CALL_METHOD CLIENT_Init(fDisConnect cbDisConnect, DWORD dwUser);

// SDK exit and clear
CLIENT_API void CALL_METHOD CLIENT_Cleanup();

//------------------------------------------------------------------------

// Set re-connection callback fucntion after disconnection. Internal SDK  auto connect again after disconnection 
CLIENT_API void CALL_METHOD CLIENT_SetAutoReconnect(fHaveReConnect cbAutoConnect, DWORD dwUser);

// Return the function execution failure code
CLIENT_API DWORD CALL_METHOD CLIENT_GetLastError(void);

// Set device connection timeout value and trial times 
CLIENT_API void CALL_METHOD CLIENT_SetConnectTime(int nWaitTime, int nTryTimes);

// Set log in network environment 
CLIENT_API void CALL_METHOD CLIENT_SetNetworkParam(NET_PARAM *pNetParam);

// Get SDK version informaiton 
CLIENT_API DWORD CALL_METHOD CLIENT_GetSDKVersion();

//------------------------------------------------------------------------

// Register to the device 
CLIENT_API LONG CALL_METHOD CLIENT_Login(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, LPNET_DEVICEINFO lpDeviceInfo, int *error = 0);

// Extenvise port£»nSpecCap = 0, it is log in in TCP mode. nSpecCap = 2, it is log in actively registration.nSpecCap = 3, it is log in in multiple-group broadcast. nSpecCap = 4, it is log in in UDP mode. 
CLIENT_API LONG CALL_METHOD CLIENT_LoginEx(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, int nSpecCap, void* pCapParam, LPNET_DEVICEINFO lpDeviceInfo, int *error = 0);

// Log out the device 
CLIENT_API BOOL CALL_METHOD CLIENT_Logout(LONG lLoginID);

//------------------------------------------------------------------------

// Begin real-time monitor 
CLIENT_API LONG CALL_METHOD CLIENT_RealPlay(LONG lLoginID, int nChannelID, HWND hWnd);

// Begin real-time monitor--extensive
CLIENT_API LONG CALL_METHOD CLIENT_RealPlayEx(LONG lLoginID, int nChannelID, HWND hWnd, DH_RealPlayType rType = DH_RType_Realplay);

// Multiple-window preview 
CLIENT_API LONG CALL_METHOD CLIENT_MultiPlay(LONG lLoginID, HWND hWnd);

// Stop multiple-window preview 
CLIENT_API BOOL CALL_METHOD CLIENT_StopMultiPlay(LONG lMultiHandle);

// Snapshot£»hPlayHandle is monitor or playback handle
CLIENT_API BOOL CALL_METHOD CLIENT_CapturePicture(LONG hPlayHandle, const char *pchPicFileName);

// Set real-time monitor data callback 
CLIENT_API BOOL CALL_METHOD CLIENT_SetRealDataCallBack(LONG lRealHandle, fRealDataCallBack cbRealData, DWORD dwUser);

// Set real-time monitor data callback--extensive 
CLIENT_API BOOL CALL_METHOD CLIENT_SetRealDataCallBackEx(LONG lRealHandle, fRealDataCallBackEx cbRealData, DWORD dwUser, DWORD dwFlag);

// Set video fluency
CLIENT_API BOOL	CALL_METHOD CLIENT_AdjustFluency(LONG lRealHandle, int nLevel);

// Save data as file
CLIENT_API BOOL CALL_METHOD CLIENT_SaveRealData(LONG lRealHandle, const char *pchFileName);

// Stop saving data as file 
CLIENT_API BOOL CALL_METHOD CLIENT_StopSaveRealData(LONG lRealHandle);

// Set video property
CLIENT_API BOOL CALL_METHOD CLIENT_ClientSetVideoEffect(LONG lPlayHandle, unsigned char nBrightness, unsigned char nContrast, unsigned char nHue, unsigned char nSaturation);

// Get video property 
CLIENT_API BOOL CALL_METHOD CLIENT_ClientGetVideoEffect(LONG lPlayHandle, unsigned char *nBrightness, unsigned char *nContrast, unsigned char *nHue, unsigned char *nSaturation);

// Set screen overlay callback 
CLIENT_API void CALL_METHOD CLIENT_RigisterDrawFun(fDrawCallBack cbDraw, DWORD dwUser);

// Open audio 
CLIENT_API BOOL CALL_METHOD CLIENT_OpenSound(LONG hPlayHandle);

// Set volume£»lPlayHandle is monitor handle or playabck handle 
CLIENT_API BOOL CALL_METHOD CLIENT_SetVolume(LONG lPlayHandle, int nVolume);

// Stop audio 
CLIENT_API BOOL CALL_METHOD CLIENT_CloseSound();

// Stop real-time preview 
CLIENT_API BOOL CALL_METHOD CLIENT_StopRealPlay(LONG lRealHandle);

// stop real-time preview-extensive
CLIENT_API BOOL CALL_METHOD CLIENT_StopRealPlayEx(LONG lRealHandle);

//------------------------------------------------------------------------

// general PTZ control
CLIENT_API BOOL CALL_METHOD CLIENT_PTZControl(LONG lLoginID, int nChannelID, DWORD dwPTZCommand, DWORD dwStep, BOOL dwStop);

// Dahua PTZ control 
CLIENT_API BOOL CALL_METHOD CLIENT_DHPTZControl(LONG lLoginID, int nChannelID, DWORD dwPTZCommand, unsigned char param1, unsigned char param2, unsigned char param3, BOOL dwStop);

//  Dahua PTZ control extensive port. support 3D intelligent position
CLIENT_API BOOL CALL_METHOD CLIENT_DHPTZControlEx(LONG lLoginID, int nChannelID, DWORD dwPTZCommand, LONG lParam1, LONG lParam2, LONG lParam3, BOOL dwStop);

//------------------------------------------------------------------------

// Search whether there is recorded file in specified period
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRecordTime(LONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmStart, LPNET_TIME tmEnd, char* pchCardid, BOOL *bResult, int waittime=1000);

// Search all recorded file sin the specified periods
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRecordFile(LONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmStart, LPNET_TIME tmEnd, char* pchCardid, LPNET_RECORDFILE_INFO nriFileinfo, int maxlen, int *filecount, int waittime=1000, BOOL bTime = FALSE);

// Begin searching recorded file
CLIENT_API LONG	CALL_METHOD CLIENT_FindFile(LONG lLoginID, int nChannelId, int nRecordFileType, char* cardid, LPNET_TIME time_start, LPNET_TIME time_end, BOOL bTime, int waittime);

// Search recorded file 
CLIENT_API int	CALL_METHOD CLIENT_FindNextFile(LONG lFindHandle,LPNET_RECORDFILE_INFO lpFindData);

// Stop searching recorded file 
CLIENT_API BOOL CALL_METHOD CLIENT_FindClose(LONG lFindHandle);

// Playback in file 
CLIENT_API LONG CALL_METHOD CLIENT_PlayBackByRecordFile(LONG lLoginID, LPNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, fDownLoadPosCallBack cbDownLoadPos, DWORD dwUserData);

// Playback in file--extensive
CLIENT_API LONG CALL_METHOD CLIENT_PlayBackByRecordFileEx(LONG lLoginID, LPNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, fDownLoadPosCallBack cbDownLoadPos, DWORD dwPosUser, fDataCallBack fDownLoadDataCallBack, DWORD dwDataUser);

// Playabck in time
CLIENT_API LONG CALL_METHOD CLIENT_PlayBackByTime(LONG lLoginID, int nChannelID, LPNET_TIME lpStartTime, LPNET_TIME lpStopTime, HWND hWnd, fDownLoadPosCallBack cbDownLoadPos, DWORD dwPosUser);

// Playback in time--extensive
CLIENT_API LONG CALL_METHOD CLIENT_PlayBackByTimeEx(LONG lLoginID, int nChannelID, LPNET_TIME lpStartTime, LPNET_TIME lpStopTime, HWND hWnd, fDownLoadPosCallBack cbDownLoadPos, DWORD dwPosUser, fDataCallBack fDownLoadDataCallBack, DWORD dwDataUser);

// Locate recorded file playback start time 
CLIENT_API BOOL CALL_METHOD CLIENT_SeekPlayBack(LONG lPlayHandle, unsigned int offsettime, unsigned int offsetbyte);

// Pause or restore file playback 
CLIENT_API BOOL CALL_METHOD CLIENT_PausePlayBack(LONG lPlayHandle, BOOL bPause);

// Fast playback file 
CLIENT_API BOOL CALL_METHOD CLIENT_FastPlayBack(LONG lPlayHandle);

// Slow playback file 
CLIENT_API BOOL CALL_METHOD CLIENT_SlowPlayBack(LONG lPlayHandle);

// Step playback file 
CLIENT_API BOOL CALL_METHOD CLIENT_StepPlayBack(LONG lPlayHandle, BOOL bStop);

// Set playabck frame rate 
CLIENT_API BOOL CALL_METHOD CLIENT_SetFramePlayBack(LONG lPlayHandle, int framerate);

// Get playback frame rate
CLIENT_API BOOL CALL_METHOD CLIENT_GetFramePlayBack(LONG lPlayHandle, int *fileframerate, int *playframerate);

// Restore ordinary playback
CLIENT_API BOOL CALL_METHOD CLIENT_NormalPlayBack(LONG lPlayHandle);

// Get playabck OSD time 
CLIENT_API BOOL CALL_METHOD CLIENT_GetPlayBackOsdTime(LONG lPlayHandle, LPNET_TIME lpOsdTime, LPNET_TIME lpStartTime, LPNET_TIME lpEndTime);

// Stop file playback 
CLIENT_API BOOL CALL_METHOD CLIENT_StopPlayBack(LONG lPlayHandle);

// Download recorded file 
CLIENT_API LONG CALL_METHOD CLIENT_DownloadByRecordFile(LONG lLoginID,LPNET_RECORDFILE_INFO lpRecordFile, char *sSavedFileName, fDownLoadPosCallBack cbDownLoadPos, DWORD dwUserData);

// Download file by time 
CLIENT_API LONG CALL_METHOD CLIENT_DownloadByTime(LONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmStart, LPNET_TIME tmEnd, char *sSavedFileName, fTimeDownLoadPosCallBack cbTimeDownLoadPos, DWORD dwUserData);

// Search record download process 
CLIENT_API BOOL CALL_METHOD CLIENT_GetDownloadPos(LONG lFileHandle, int *nTotalSize, int *nDownLoadSize);

// Stop record download 
CLIENT_API BOOL CALL_METHOD CLIENT_StopDownload(LONG lFileHandle);

//------------------------------------------------------------------------

// Set alarm callback fucntion 
CLIENT_API void CALL_METHOD CLIENT_SetDVRMessCallBack(fMessCallBack cbMessage,DWORD dwUser);

// subscribe alarm 
CLIENT_API BOOL CALL_METHOD CLIENT_StartListen(LONG lLoginID);

// subscribe alarm---extensive
CLIENT_API BOOL CALL_METHOD CLIENT_StartListenEx(LONG lLoginID);

// Stop subscribe alarm 
CLIENT_API BOOL CALL_METHOD CLIENT_StopListen(LONG lLoginID);

//------------------------------------------------------------------------

// actively registration function. enable service. nTimeout is invalid. 
CLIENT_API LONG CALL_METHOD CLIENT_ListenServer(char* ip, WORD port, int nTimeout, fServiceCallBack cbListen, DWORD dwUserData);

// stop service
CLIENT_API BOOL CALL_METHOD CLIENT_StopListenServer(LONG lServerHandle);

// Respond the registration requestion from the device 
CLIENT_API BOOL CALL_METHOD CLIENT_ResponseDevReg(char *devSerial, char* ip, WORD port, BOOL bAccept);

//------------------------------------------------------------------------

// Alarm upload function. Enable service. dwTimeOut paramter is invalid 
CLIENT_API LONG CALL_METHOD CLIENT_StartService(WORD wPort, char *pIp = NULL, fServiceCallBack pfscb = NULL, DWORD dwTimeOut = 0xffffffff, DWORD dwUserData = 0);

// Stop service 
CLIENT_API BOOL CALL_METHOD CLIENT_StopService(LONG lHandle);

//------------------------------------------------------------------------

// Set audio talk mode(clien-end mode or server mode)
CLIENT_API BOOL CALL_METHOD CLIENT_SetDeviceMode(LONG lLoginID, EM_USEDEV_MODE emType, void* pValue);

// Enable audio talk 
CLIENT_API LONG CALL_METHOD CLIENT_StartTalkEx(LONG lLoginID, pfAudioDataCallBack pfcb, DWORD dwUser);

// Begin PC record 
CLIENT_API BOOL CALL_METHOD CLIENT_RecordStart();

// Stop PC record 
CLIENT_API BOOL CALL_METHOD CLIENT_RecordStop();

// Send out audio data to the device 
CLIENT_API LONG CALL_METHOD CLIENT_TalkSendData(LONG lTalkHandle, char *pSendBuf, DWORD dwBufSize);

// Decode audio data 
CLIENT_API void CALL_METHOD CLIENT_AudioDec(char *pAudioDataBuf, DWORD dwBufSize);

// Set audio talk volume
CLIENT_API BOOL CALL_METHOD CLIENT_SetAudioClientVolume(LONG lTalkHandle, WORD wVolume);

// Stop audio talk 
CLIENT_API BOOL CALL_METHOD CLIENT_StopTalkEx(LONG lTalkHandle);

// add device into broadcast group 
CLIENT_API BOOL CALL_METHOD CLIENT_AudioBroadcastAddDev(LONG lLoginID);

// Remove device from the broadcast group 
CLIENT_API BOOL CALL_METHOD CLIENT_AudioBroadcastDelDev(LONG lLoginID);

// audio encode-initialization(specifeid standard format---? Dahua format)
CLIENT_API int  CALL_METHOD CLIENT_InitAudioEncode(DH_AUDIO_FORMAT aft);

// Audio encode--data encode
CLIENT_API int	CALL_METHOD	CLIENT_AudioEncode(LONG lTalkHandle, BYTE *lpInBuf, DWORD *lpInLen, BYTE *lpOutBuf, DWORD *lpOutLen);

// audio encode--complete and then exit
CLIENT_API int	CALL_METHOD	CLIENT_ReleaseAudioEncode();

//------------------------------------------------------------------------

// Search device log
CLIENT_API BOOL CALL_METHOD CLIENT_QueryLog(LONG lLoginID, char *pLogBuffer, int maxlen, int *nLogBufferlen, int waittime=3000);

// Search device log page by page.
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDeviceLog(LONG lLoginID, QUERY_DEVICE_LOG_PARAM *pQueryParam, char *pLogBuffer, int nLogBufferLen, int *pRecLogNum, int waittime=3000);

// Search channel record staus 
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRecordState(LONG lLoginID, char *pRSBuffer, int maxlen, int *nRSBufferlen, int waittime=1000);

// Search device status
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDevState(LONG lLoginID, int nType, char *pBuf, int nBufLen, int *pRetLen, int waittime=1000);

// Search system capacity informaiton 
CLIENT_API BOOL CALL_METHOD CLIENT_QuerySystemInfo(LONG lLoginID, int nSystemType, char *pSysInfoBuffer, int maxlen, int *nSysInfolen, int waittime=1000);

// Get channel bit stream 
CLIENT_API LONG CALL_METHOD CLIENT_GetStatiscFlux(LONG lLoginID, LONG lPlayHandle);

// Get PTZ information 
CLIENT_API BOOL  CALL_METHOD CLIENT_GetPtzOptAttr(LONG lLoginID,DWORD dwProtocolIndex,LPVOID lpOutBuffer,DWORD dwBufLen,DWORD *lpBytesReturned,int waittime=500);

//------------------------------------------------------------------------

// Reboot device 
CLIENT_API BOOL CALL_METHOD CLIENT_RebootDev(LONG lLoginID);

// Shut down devic e
CLIENT_API BOOL CALL_METHOD CLIENT_ShutDownDev(LONG lLoginID);

// Device control 
CLIENT_API BOOL CALL_METHOD CLIENT_ControlDevice(LONG lLoginID, CtrlType type, void *param, int waittime = 1000);

// Set channel record status 
CLIENT_API BOOL CALL_METHOD CLIENT_SetupRecordState(LONG lLoginID, char *pRSBuffer, int nRSBufferlen);

// Search IO status
CLIENT_API BOOL CALL_METHOD CLIENT_QueryIOControlState(LONG lLoginID, DH_IOTYPE emType, 
                                           void *pState, int maxlen, int *nIOCount, int waittime=1000);

// IO control 
CLIENT_API BOOL CALL_METHOD CLIENT_IOControl(LONG lLoginID, DH_IOTYPE emType, void *pState, int maxlen);

// Compulsive I frame
CLIENT_API BOOL CALL_METHOD CLIENT_MakeKeyFrame(LONG lLoginID, int nChannelID, int nSubChannel=0);

//------------------------------------------------------------------------

// Search user information 
CLIENT_API BOOL CALL_METHOD CLIENT_QueryUserInfo(LONG lLoginID, USER_MANAGE_INFO *info, int waittime=1000);

// Search user informaiton--extensvie
CLIENT_API BOOL CALL_METHOD CLIENT_QueryUserInfoEx(LONG lLoginID, USER_MANAGE_INFO_EX *info, int waittime=1000);

// Device operation user 
CLIENT_API BOOL CALL_METHOD CLIENT_OperateUserInfo(LONG lLoginID, int nOperateType, void *opParam, void *subParam, int waittime=1000);

// Device operation user--extensive
CLIENT_API BOOL CALL_METHOD CLIENT_OperateUserInfoEx(LONG lLoginID, int nOperateType, void *opParam, void *subParam, int waittime=1000);

//------------------------------------------------------------------------

// Create transparent COM channel 
CLIENT_API LONG CALL_METHOD CLIENT_CreateTransComChannel(LONG lLoginID, int TransComType, unsigned int baudrate, unsigned int databits, unsigned int stopbits, unsigned int parity, fTransComCallBack cbTransCom, DWORD dwUser);

// Transparent COM send out data 
CLIENT_API BOOL CALL_METHOD CLIENT_SendTransComData(LONG lTransComChannel, char *pBuffer, DWORD dwBufSize);

// Release transparent COM channel 
CLIENT_API BOOL CALL_METHOD CLIENT_DestroyTransComChannel(LONG lTransComChannel);

//------------------------------------------------------------------------

// Begin upgrading device program 
CLIENT_API LONG CALL_METHOD CLIENT_StartUpgrade(LONG lLoginID, char *pchFileName, fUpgradeCallBack cbUpgrade, DWORD dwUser);

// Begin upgrading device program--extensive
CLIENT_API LONG CALL_METHOD CLIENT_StartUpgradeEx(LONG lLoginID, EM_UPGRADE_TYPE emType, char *pchFileName, fUpgradeCallBack cbUpgrade, DWORD dwUser);

// Send out data
CLIENT_API BOOL CALL_METHOD CLIENT_SendUpgrade(LONG lUpgradeID);

// Stop upgrading device program 
CLIENT_API BOOL CALL_METHOD CLIENT_StopUpgrade(LONG lUpgradeID);

//------------------------------------------------------------------------

// Search configuration informaiton 
CLIENT_API BOOL  CALL_METHOD CLIENT_GetDevConfig(LONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned,int waittime=500);

// Set configuration information 
CLIENT_API BOOL  CALL_METHOD CLIENT_SetDevConfig(LONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize, int waittime=500);

//------------------------------------------------------------------------

// Search device channel name 
CLIENT_API BOOL CALL_METHOD CLIENT_QueryChannelName(LONG lLoginID, char *pChannelName, int maxlen, int *nChannelCount, int waittime=1000);

// Set device channel name
CLIENT_API BOOL  CALL_METHOD CLIENT_SetupChannelName(LONG lLoginID,char *pbuf, int nbuflen);

// Set device channel character overlay 
CLIENT_API BOOL  CALL_METHOD CLIENT_SetupChannelOsdString(LONG lLoginID, int nChannelNo, DH_CHANNEL_OSDSTRING* struOsdString, int nbuflen);

// Search device current time
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDeviceTime(LONG lLoginID, LPNET_TIME pDeviceTime, int waittime=1000);

// Set device current time
CLIENT_API BOOL CALL_METHOD CLIENT_SetupDeviceTime(LONG lLoginID, LPNET_TIME pDeviceTime);

// Set device max bit stream
CLIENT_API BOOL CALL_METHOD CLIENT_SetMaxFlux(LONG lLoginID, WORD wFlux);

//------------------------------------------------------------------------

// Import configuraiton file 
CLIENT_API LONG CALL_METHOD CLIENT_ImportConfigFile(LONG lLoginID, char *szFileName, fDownLoadPosCallBack cbUploadPos, DWORD dwUserData, DWORD param=0);

// Stop importing configuration file
CLIENT_API BOOL CALL_METHOD CLIENT_StopImportCfgFile(LONG lImportHandle);

// Exporting configuration file
CLIENT_API LONG CALL_METHOD CLIENT_ExportConfigFile(LONG lLoginID, DH_CONFIG_FILE_TYPE emConfigFileType, char *szSavedFilePath, fDownLoadPosCallBack cbDownLoadPos, DWORD dwUserData);

// top exporting configuration file
CLIENT_API BOOL CALL_METHOD CLIENT_StopExportCfgFile(LONG lExportHandle);

//------------------------------------------------------------------------

// Search device IP in DDBS by device name or device serial number
CLIENT_API BOOL CALL_METHOD CLIENT_GetDVRIPByResolveSvr(char *pchDVRIP, WORD wDVRPort, BYTE *sDVRName, WORD wDVRNameLen, BYTE *sDVRSerialNumber, WORD wDVRSerialLen, char* sGetIP);

// Search IPC,NVS and etc in LAN 
CLIENT_API BOOL CALL_METHOD CLIENT_SearchDevices(char* szBuf, int nBufLen, int* pRetLen, DWORD dwSearchTime);

//------------------------------------------------------------------------

// Platform embedded interface
CLIENT_API BOOL CALL_METHOD CLIENT_GetPlatFormInfo(LONG lLoginID, DWORD dwCommand, int nSubCommand, int nParam, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned,int waittime=500);
CLIENT_API BOOL CALL_METHOD CLIENT_SetPlatFormInfo(LONG lLoginID, DWORD dwCommand, int nSubCommand, int nParam, LPVOID lpInBuffer, DWORD dwInBufferSize, int waittime=500);


///////////////////////////////Mobile DVR interface///////////////////////////////

// Set snapshit callback function 
CLIENT_API void CALL_METHOD CLIENT_SetSnapRevCallBack(fSnapRev OnSnapRevMessage, DWORD dwUser);

// Snapshot request
CLIENT_API BOOL CALL_METHOD CLIENT_SnapPicture(LONG lLoginID, SNAP_PARAMS par);

// Set GPS subscription callback fucntion 
CLIENT_API void CALL_METHOD CLIENT_SetSubcribeGPSCallBack(fGPSRev OnGPSMessage, DWORD dwUser);

// GPS message subscription 
CLIENT_API BOOL CALL_METHOD CLIENT_SubcribeGPS (LONG lLoginID, BOOL bStart, LONG KeepTime, LONG InterTime);


///////////////////////////////Special Version Interface///////////////////////////////
// Search device log--extensive
CLIENT_API BOOL CALL_METHOD CLIENT_QueryLogEx(LONG lLoginID, DH_LOG_QUERY_TYPE logType, char *pLogBuffer, int maxlen, int *nLogBufferlen, void* reserved, int waittime=3000);


/////////////////////////////////Cancelled Interface/////////////////////////////////

// Search system server setup. This interface is invalid now please use  CLIENT_GetDevConfig
CLIENT_API BOOL CALL_METHOD CLIENT_QueryConfig(LONG lLoginID, int nConfigType, char *pConfigbuf, int maxlen, int *nConfigbuflen, int waittime=1000);

// Set system server setup. This interface is invalid now please use  CLIENT_SetDevConfig
CLIENT_API BOOL CALL_METHOD CLIENT_SetupConfig(LONG lLoginID, int nConfigType, char *pConfigbuf, int nConfigbuflen, int waittime=1000);

// This interface is invalid now. 
CLIENT_API BOOL CALL_METHOD CLIENT_Reset(LONG lLoginID, BOOL bReset);

// Search COM protocol. This interface is invalid now please use  CLIENT_GetDevConfig
CLIENT_API BOOL CALL_METHOD CLIENT_QueryComProtocol(LONG lLoginID, int nProtocolType, char *pProtocolBuffer, int maxlen, int *nProtocollen, int waittime=1000);

// Begin aduio talk. This interface is invalid now. Please use  CLIENT_StartTalkEx
CLIENT_API BOOL CALL_METHOD CLIENT_StartTalk(LONG lRealHandle, BOOL bCustomSend=false);

// Stop audio talk. This interface is invalid now , please use  CLIENT_StopTalkEx
CLIENT_API BOOL CALL_METHOD CLIENT_StopTalk(LONG lRealHandle);

// Send out self-defined audio talk data. This interface is invalid now, please use  CLIENT_TalkSendData
CLIENT_API BOOL CALL_METHOD CLIENT_SendTalkData_Custom(LONG lRealHandle, char *pBuffer, DWORD dwBufSize);

// Set real-time preview buffer size
CLIENT_API BOOL CALL_METHOD CLIENT_SetPlayerBufNumber(LONG lRealHandle, DWORD dwBufNum);

// Download file by time
CLIENT_API BOOL CALL_METHOD CLIENT_GetFileByTime(LONG lLoginID, int nChannelID, LPNET_TIME lpStartTime, LPNET_TIME lpStopTime, char *sSavedFileName);

// Network playback control 
CLIENT_API BOOL CALL_METHOD CLIENT_PlayBackControl(LONG lPlayHandle, DWORD dwControlCode, DWORD dwInValue, DWORD *lpOutValue);

// Search device working status .This interface is invalid now, please use  CLIENT_QueryDevState
CLIENT_API BOOL CALL_METHOD CLIENT_GetDEVWorkState(LONG lLoginID, LPNET_DEV_WORKSTATE lpWorkState, int waittime=1000);

// Asyncronism search device log 
CLIENT_API BOOL CALL_METHOD CLIENT_QueryLogCallback(LONG lLoginID, fLogDataCallBack cbLogData, DWORD dwUser);



#ifdef __cplusplus
}
#endif

#endif // DHNETSDK_H










































