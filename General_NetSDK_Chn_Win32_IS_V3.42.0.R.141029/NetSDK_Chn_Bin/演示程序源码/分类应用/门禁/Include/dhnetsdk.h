
#ifndef DHNETSDK_H
#define DHNETSDK_H


#if (defined(WIN32) || defined(WIN64))
#include <windows.h>
#ifdef NETSDK_EXPORTS

#ifndef CLIENT_API
#define CLIENT_API  __declspec(dllexport)
#endif

#else

#ifndef CLIENT_API
#define CLIENT_API  __declspec(dllimport)
#endif

#endif

#define CALLBACK __stdcall
#define CALL_METHOD  __stdcall  //__cdecl

#define INT64    __int64

#ifndef LLONG
#ifdef WIN64
#define LLONG INT64
#else 
#define LLONG LONG
#endif
#endif

#ifndef LDWORD
#ifdef WIN64
#define LDWORD INT64
#else 
#define LDWORD DWORD
#endif
#endif

#else    //non-windows

#define CLIENT_API    extern "C"
#define CALL_METHOD 
#define CALLBACK

#ifndef INTERNAL_COMPILE
#define RELEASE_HEADER //发布头文件
#endif
 
#ifdef RELEASE_HEADER

#define WORD        unsigned short
#define DWORD       unsigned int
#define LONG        int
#define LPDWORD     DWORD*
#ifdef __OBJC__
#include "objc/objc.h"
#else
#define BOOL        int
#endif
#ifndef TRUE
#define TRUE        1
#endif
#ifndef FALSE
#define FALSE       0
#endif
#define BYTE        unsigned char
#define UINT        unsigned int
#define HDC         void*
#define HWND        void*
#define LPVOID      void*
#ifndef NULL
#define NULL        0
#endif
#define LLONG       long
#define INT64       long long
#define LDWORD      long 

#ifndef MAX_PATH
#define MAX_PATH    260
#endif

#ifndef DEF_RECT
typedef struct  tagRECT
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT;
#define DEF_RECT
#endif

#else    //内部编译

#include "../Platform/osIndependent.h"
#endif // RELEASE_HEADER

#endif // linux

#include "dhassistant.h"

#ifndef LDWORD
#if (defined(WIN32) || defined(WIN64))
#ifdef WIN64
#define LDWORD __int64
#else //WIN32 
#define LDWORD DWORD
#endif
#else    //linux
#define LDWORD long 
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************
 ** 常量定义
 ***********************************************************************/
#define DH_SERIALNO_LEN                   48               // 设备序列号字符长度
#define DH_MAX_DISKNUM                    256              // 最大硬盘个数
#define DH_MAX_SDCARDNUM                  32               // 最大SD卡个数
#define DH_MAX_BURNING_DEV_NUM            32               // 最大刻录设备个数
#define DH_BURNING_DEV_NAMELEN            32               // 刻录设备名字最大长度
#define DH_MAX_LINK                       6                
#define DH_MAX_CHANNUM                    16               // 最大通道个数
#define DH_MAX_DECODER_CHANNUM            64               // 解码器最大通道数
#define DH_MAX_ALARMIN                    128              // 最大报警输入个数
#define DH_MAX_ALARMOUT                   64               // 最大报警输出个数
#define DH_MAX_RIGHT_NUM                  100              // 用户权限个数上限
#define DH_MAX_GROUP_NUM                  20               // 用户组个数上限
#define DH_MAX_USER_NUM                   200              // 用户个数上限
#define DH_RIGHT_NAME_LENGTH              32               // 权限名长度
#define DH_USER_NAME_LENGTH               8                // 用户名长度
#define DH_USER_PSW_LENGTH                8                // 用户密码长度
#define DH_MEMO_LENGTH                    32               // 备注长度
#define DH_MAX_STRING_LEN                 128              
#define MAX_STRING_LINE_LEN               6                // 最多六行
#define MAX_PER_STRING_LEN                20               // 每行最大长度
#define DH_MAX_MAIL_NAME_LEN              64               // 新的邮件结构体支持的用户名长度
#define DH_MAX_MAIL_PSW_LEN               64               // 新的邮件结构体支持的密码长度
#define DH_SPEEDLIMIT_TYPE_LEN            32               // 限速类型字符串长度
#define DH_VEHICLE_TYPE_LEN               32               // 车载自定义信息类型字符串长度
#define DH_VEHICLE_INFO_LEN               32               // 车载自定义信息字符串长度
#define DH_VEHICLE_DRIVERNO_LEN           32               // 车载自定义信息司机工号字符串长度
#define DH_MAX_CROSSING_NUM               128              // 最大点位
#define DH_MAX_CROSSING_ID                32               // 路口序列号最大长度
#define DH_MAX_CARD_INFO_LEN              256              // 卡号信息最大长度
#define DH_MAX_CHANNUM_EX                 32               // 最大通道数扩展  
#define DH_MAX_SAERCH_IP_NUM              256              // 最大搜索IP个数
#define DH_MAX_HARDDISK_TYPE_LEN          32               // 硬盘型号最大长度
#define DH_MAX_HARDDISK_SERIAL_LEN        32               // 硬盘序列号最大长度
#define DH_MAX_SIM_LEN                    16               // SIM卡的值的最大长度
#define DH_MAX_SIM_NUM                    10               // 车载SIM卡最大个数
#define DH_MAX_VERSION_LEN                32               // 软件版本号最大长度
#define DH_MAX_MDN_LEN                    36               // MDN的值的最大长度
#define DH_MAX_NETINTERFACE_NUM           64               // 支持的网卡个数
#define DH_EVENT_NAME_LEN                 128              // 事件名称长度
#define DH_STORAGE_NAME_LEN               128              // 存储设备名称长度
#define DH_MAX_CARPORTLIGHT_NUM           4                // 最大车位灯个数
#define DH_STATION_NAME_LEN               32               // 车站站点名称长度   
#define PTZ_PRESET_NAME_LEN               64               // 云台预置点名称长度
    
#define DH_MAX_VERSION_STR                64               // 版本字符串最大长度

#define DH_COMMON_STRING_16               16               // 通用字符串长度16
#define DH_COMMON_STRING_32               32               // 通用字符串长度32
#define DH_COMMON_STRING_64               64               // 通用字符串长度64
#define DH_COMMON_STRING_128              128              // 通用字符串长度128
#define DH_COMMON_STRING_256              256              // 通用字符串长度256
#define DH_COMMON_STRING_512              512              // 通用字符串长度512
#define DH_COMMON_STRING_1024             1024             // 通用字符串长度1024

#define DH_MAX_ACCESS_NAME_LEN            64               // 门禁名称长度
#define DH_MAX_EXALARMCHANNEL_NAME_LEN    128              // 扩展模块报警通道名称长度

// 远程配置结构体相关常量                 
#define DH_MAX_MAIL_ADDR_LEN              128              // 邮件发(收)地址最大长度
#define DH_MAX_MAIL_SUBJECT_LEN           64               // 邮件主题最大长度
#define DH_MAX_IPADDR_LEN                 16               // IP地址字符串长度
#define DH_MAX_IPADDR_LEN_EX              40               // 扩展IP地址字符串长度, 支持IPV6#define DH_MACADDR_LEN                    40               // MAC地址字符串长度
#define DH_MACADDR_LEN                    40               // MAC地址字符串长度
#define DH_MAX_URL_LEN                    128              // URL字符串长度
#define DH_MAX_DEV_ID_LEN                 48               // 机器编号最大长度
#define DH_MAX_HOST_NAMELEN               64               // 主机名长度，
#define DH_MAX_HOST_PSWLEN                32               // 密码长度
#define DH_MAX_NAME_LEN                   16               // 通用名字字符串长度
#define DH_MAX_ETHERNET_NUM               2                // 以太网口最大个数
#define DH_MAX_ETHERNET_NUM_EX            10               // 扩展以太网口最大个数
#define DH_DEV_SERIALNO_LEN               48               // 序列号字符串长度
#define DH_DEV_TYPE_LEN                   32               // 设备类型字符串长度
#define DH_N_WEEKS                        7                // 一周的天数    
#define DH_N_TSECT                        6                // 通用时间段个数
#define DH_N_REC_TSECT                    6                // 录像时间段个数
#define DH_N_COL_TSECT                    2                // 颜色时间段个数    
#define DH_CHAN_NAME_LEN                  32               // 通道名长度，DVR DSP能力限制，最多32字节        
#define DH_N_ENCODE_AUX                   3                // 扩展码流个数    
#define DH_N_TALK                         1                // 最多对讲通道个数
#define DH_N_COVERS                       1                // 遮挡区域个数    
#define DH_N_CHANNEL                      16               // 最大通道个数    
#define DH_N_ALARM_TSECT                  2                // 报警提示时间段个数
#define DH_MAX_ALARMOUT_NUM               16               // 报警输出口个数上限
#define DH_MAX_AUDIO_IN_NUM               16               // 音频输入口个数上限
#define DH_MAX_VIDEO_IN_NUM               16               // 视频输入口个数上限
#define DH_MAX_ALARM_IN_NUM               16               // 报警输入口个数上限
#define DH_MAX_DISK_NUM                   16               // 硬盘个数上限，暂定为16
#define DH_MAX_DECODER_NUM                16               // 解码器(485)个数上限    
#define DH_MAX_232FUNCS                   10               // 232串口功能个数上限
#define DH_MAX_232_NUM                    2                // 232串口个数上限
#define DH_MAX_232_NUM_EX                 16               // 扩展串口配置个数上限          
#define DH_MAX_DECPRO_LIST_SIZE           100              // 解码器协议列表个数上限
#define DH_FTP_MAXDIRLEN                  240              // FTP文件目录最大长度
#define DH_MATRIX_MAXOUT                  16               // 矩阵输出口最大个数
#define DH_TOUR_GROUP_NUM                 6                // 矩阵输出组最大个数
#define DH_MAX_DDNS_NUM                   10               // 设备支持的ddns服务器最大个数
#define DH_MAX_SERVER_TYPE_LEN            32               // ddns服务器类型，最大字符串长度
#define DH_MAX_DOMAIN_NAME_LEN            256              // ddns域名，最大字符串长度
#define DH_MAX_DDNS_ALIAS_LEN             32               // ddns服务器别名，最大字符串长度
#define DH_MAX_DEFAULT_DOMAIN_LEN         60               // ddns默认域名，最大字符串长度     
#define DH_MOTION_ROW                     32               // 动态检测区域的行数
#define DH_MOTION_COL                     32               // 动态检测区域的列数
#define DH_STATIC_ROW                     32               // 静态检测区域的行数
#define DH_STATIC_COL                     32               // 静态检测区域的列数
#define DH_FTP_USERNAME_LEN               64               // FTP配置，用户名最大长度
#define DH_FTP_PASSWORD_LEN               64               // FTP配置，密码最大长度
#define DH_TIME_SECTION                   2                // FTP配置，每天时间段个数
#define DH_FTP_MAX_PATH                   240              // FTP配置，文件路径名最大长度
#define DH_FTP_MAX_SUB_PATH               128              // FTP配置，文件路径名最大长度
#define DH_INTERVIDEO_UCOM_CHANID         32               // 平台接入配置，U网通通道ID
#define DH_INTERVIDEO_UCOM_DEVID          32               // 平台接入配置，U网通设备ID
#define DH_INTERVIDEO_UCOM_REGPSW         16               // 平台接入配置，U网通注册密码
#define DH_INTERVIDEO_UCOM_USERNAME       32               // 平台接入配置，U网通用户名
#define DH_INTERVIDEO_UCOM_USERPSW        32               // 平台接入配置，U网通密码
#define DH_INTERVIDEO_NSS_IP              32               // 平台接入配置，中兴力维IP
#define DH_INTERVIDEO_NSS_SERIAL          32               // 平台接入配置，中兴力维serial
#define DH_INTERVIDEO_NSS_USER            32               // 平台接入配置，中兴力维user
#define DH_INTERVIDEO_NSS_PWD             50               // 平台接入配置，中兴力维password
#define DH_MAX_VIDEO_COVER_NUM            16               // 遮挡区域最大个数
#define DH_MAX_WATERMAKE_DATA             4096             // 水印图片数据最大长度
#define DH_MAX_WATERMAKE_LETTER           128              // 水印文字最大长度
#define DH_MAX_WLANDEVICE_NUM             10               // 最多搜索出的无线设备个数
#define DH_MAX_WLANDEVICE_NUM_EX          32               // 最多搜索出的无线设备个数
#define DH_MAX_ALARM_NAME                 64               // 地址长度
#define DH_MAX_REGISTER_SERVER_NUM        10               // 主动注册服务器个数
#define DH_SNIFFER_FRAMEID_NUM            6                // 6个FRAME ID 选项
#define DH_SNIFFER_CONTENT_NUM            4                // 每个FRAME对应的4个抓包内容
#define DH_SNIFFER_CONTENT_NUM_EX         8                // 每个FRAME对应的8个抓包内容
#define DH_SNIFFER_PROTOCOL_SIZE          20               // 协议名字长度
#define DH_MAX_PROTOCOL_NAME_LENGTH       20               
#define DH_SNIFFER_GROUP_NUM              4                // 4组抓包设置
#define MAX_PATH_STOR                     240              // 远程目录的长度
#define DH_ALARM_OCCUR_TIME_LEN           40               // 新的报警上传时间的长度
#define DH_VIDEO_OSD_NAME_NUM             64               // 叠加的名称长度，目前支持32个英文，16个中文
#define DH_VIDEO_CUSTOM_OSD_NUM           8                // 支持的自定义叠加的数目，不包含时间和通道
#define DH_CONTROL_AUTO_REGISTER_NUM      100              // 支持定向主动注册服务器的个数
#define DH_MMS_RECEIVER_NUM               100              // 支持短信接收者的个数
#define DH_MMS_SMSACTIVATION_NUM          100              // 支持短信发送者的个数
#define DH_MMS_DIALINACTIVATION_NUM       100              // 支持拨号发送者的个数
#define DH_MAX_ALARMOUT_NUM_EX            32               // 报警输出口个数上限扩展
#define DH_MAX_VIDEO_IN_NUM_EX            32               // 视频输入口个数上限扩展
#define DH_MAX_ALARM_IN_NUM_EX            32               // 报警输入口个数上限
#define DH_MAX_IPADDR_OR_DOMAIN_LEN       64               // IP地址字符串长度
#define DH_MAX_CALLID				      32
#define DH_MAX_OBJECT_LIST                16               // 智能分析设备检测到的物体ID个数上限    
#define DH_MAX_RULE_LIST                  16               // 智能分析设备规则个数上限
#define DH_MAX_POLYGON_NUM                16               // 多边形最大顶点个数
#define DH_MAX_DETECT_LINE_NUM            20               // 规则检测线最大顶点数
#define DH_MAX_DETECT_REGION_NUM          20               // 规则检测区域最大顶点数
#define DH_MAX_TRACK_LINE_NUM             20               // 物体运动轨迹最大顶点数
#define DH_MAX_CANDIDATE_NUM              50               // 人脸识别最大匹配数
#define DH_MAX_PERSON_IMAGE_NUM           48               // 每个人员对应的最大人脸图片数
#define DH_MAX_FENCE_LINE_NUM             2                // 围栏最大曲线数
#define MAX_SMART_VALUE_NUM               30               // 最多的smart信息个数
#define DH_MACHINE_NAME_NUM               64               // 机器名称长度
#define DH_INTERVIDEO_AMP_DEVICESERIAL    48               // 平台接入配置，天地阳光 设备序列号字符串长度
#define DH_INTERVIDEO_AMP_DEVICENAME      16               // 平台接入配置，天地阳光 设备名称字符串长度
#define DH_INTERVIDEO_AMP_USER            32               // 平台接入配置，天地阳光 注册用户名字符串长度
#define DH_INTERVIDEO_AMP_PWD             32               // 平台接入配置，天地阳光 注册密码字符串长度
#define MAX_SUBMODULE_NUM                 32               // 最多子模块信息个数
#define DH_MAX_CARWAY_NUM                 8                // 交通抓拍，最大车道数
#define DH_MAX_SNAP_SIGNAL_NUM            3                // 一个车道的最大抓拍张数
#define DH_MAX_CARD_NUM                   128              // 卡号的最大个数
#define DH_MAX_CARDINFO_LEN               32               // 每条卡号最长字符数
#define DH_MAX_CONTROLER_NUM              64               // 最大支持控制器数目
#define DH_MAX_LIGHT_NUM                  32               // 最多控制灯组数
#define DH_MAX_SNMP_COMMON_LEN            64               // snmp 读写数据长度
#define DH_MAX_DDNS_STATE_LEN             128              // DDNS 状态信息长度
#define DH_MAX_PHONE_NO_LEN               16               // 电话号码长度
#define DH_MAX_MSGTYPE_LEN                32               // 导航类型或短信息类型长度
#define DH_MAX_MSG_LEN                    256              // 导航和短信息长度
#define DH_MAX_DRIVINGDIRECTION           256              // 行驶方向字符串长度
#define DH_MAX_GRAB_INTERVAL_NUM          4                // 多张图片抓拍个数
#define DH_MAX_FLASH_NUM                  5                // 最多支持闪光灯个数
#define DH_MAX_LANE_NUM                   8                // 视频分析设备每个通道对应车道数上限
#define DH_MAX_ISCSI_PATH_NUM             64               // ISCSI远程目录最大数量
#define DH_MAX_WIRELESS_CHN_NUM           256              // 无线路由最大信道数
#define DH_PROTOCOL3_BASE                 100              // 三代协议版本基数
#define DH_PROTOCOL3_SUPPORT              11               // 只支持3代协议
#define DH_MAX_CHANMASK                   64               // 通道掩码最大值
#define DH_MAX_STAFF_NUM                  20               // 浓缩视频配置信息中标尺数上限
#define DH_MAX_CALIBRATEBOX_NUM           10               // 浓缩视频配置信息中标定区域数上限
#define DH_MAX_EXCLUDEREGION_NUM          10               // 浓缩视频配置信息中排除区域数上限
#define DH_MAX_POLYLINE_NUM               20               // 浓缩视频配置信息中标尺线数
#define DH_MAX_COLOR_NUM                  16               // 最大颜色数目
#define MAX_OBJFILTER_NUM                 16               // 最大过滤种类个数
#define DH_MAX_SYNOPSIS_STATE_NAME        64               // 视频浓缩状态字符串长度
#define DH_MAX_SYNOPSIS_QUERY_FILE_COUNT  10               // 视频浓缩相关原始文件按照路径查找时文件个数上限
#define DH_MAX_SSID_LEN                   36               // SSID长度
#define DH_MAX_APPIN_LEN                  16               // PIN码长度
#define DH_NETINTERFACE_NAME_LEN          260              // 网口名称长度
#define DH_NETINTERFACE_TYPE_LEN          260              // 网络类型长度
#define DH_MAX_CONNECT_STATUS_LEN         260              // 连接状态字符串长度
#define DH_MAX_MODE_LEN                   64               // 3G支持的网络模式长度
#define DH_MAX_MODE_NUM                   64               // 3G支持的网络模式个数
#define DH_MAX_CAPTURE_SIZE_NUM           64               // 视频分辨率个数
#define DH_NODE_NAME_LEN                  64               // 组织结构节点名称长度
#define MAX_CALIBPOINTS_NUM               256              // 支持最大标定点数
#define DH_MAX_ATTR_NUM                   32               // 显示单元属性最大数量
#define DH_MAX_CLOUDCONNECT_STATE_LEN     128              // 云注册连接状态信息长度
#define DH_MAX_IPADDR_EX_LEN              128              // 扩展IP地址最大长度
#define DH_MAX_PLATE_NUMBER_LEN           32               // 车牌字符串长度   
#define DH_MAX_AUTHORITY_LIST_NUM         16               // 权限列表最大个数   
#define DH_MAX_CITY_NAME_LEN              64               // 城市名称最大长度
#define DH_MAX_PROVINCE_NAME_LEN          64               // 省份名称最大长度
#define DH_MAX_PERSON_ID_LEN              32               // 人员id最大长度
#define MAX_FACE_AREA_NUM                 8                // 最大人脸区域个数 
#define MAX_FACE_DB_NUM                   8                // 最大人脸数据库个数
#define MAX_EVENT_NAME                    128              // 最长事件名
#define DH_MAX_ETH_NAME                   64               // 最大网卡名
#define DH_MAX_PERSON_NAME_LEN            64               // 人员名字最大长度
#define DH_N_SCHEDULE_TSECT               8                // 时间表元素个数    
#define DH_MAX_URL_NUM                    8                // URL最大个数
#define DH_MAX_LOWER_MITRIX_NUM           16               // 最大下位矩阵数
#define DH_MAX_BURN_CHANNEL_NUM           32               // 最大刻录通道数
#define DH_MAX_NET_STRORAGE_BLOCK_NUM     64               // 最大远程存储区块数量
#define DH_MAX_CASE_PERSON_NUM            32               // 案件人员最大数量
#define DH_MAX_MULTIPLAYBACK_CHANNEL_NUM  64               // 最大多通道预览回放通道数
#define DH_MAX_MULTIPLAYBACK_SPLIT_NUM    32               // 最大多通道预览回放分割模式数
#define DH_MAX_AUDIO_ENCODE_TYPE          64               // 最大语音编码类型个数
#define MAX_LOG_PATH_LEN                  260              // 日志路径名最大长度
#define MAX_CARD_RECORD_FIELD_NUM         16               // 卡号录像最大域数量
#define DH_BATTERY_NUM_MAX                16               // 最大电池数量    
#define DH_POWER_NUM_MAX                  16               // 最大电源数量        
#define DH_MAX_AUDIO_PATH                 260              // 最大音频文件路长度
#define DH_MAX_DOORNAME_LEN               128              // 最大门禁名称长度    
#define DH_MAX_CARDPWD_LEN                64               // 最大门禁名称长度    

// 查询类型，对应CLIENT_QueryDevState接口
#define DH_DEVSTATE_COMM_ALARM            0x0001           // 查询普通报警状态(包括外部报警，视频丢失，动态检测)
#define DH_DEVSTATE_SHELTER_ALARM         0x0002           // 查询遮挡报警状态
#define DH_DEVSTATE_RECORDING             0x0003           // 查询录象状态
#define DH_DEVSTATE_DISK                  0x0004           // 查询硬盘信息
#define DH_DEVSTATE_RESOURCE              0x0005           // 查询系统资源状态
#define DH_DEVSTATE_BITRATE               0x0006           // 查询通道码流
#define DH_DEVSTATE_CONN                  0x0007           // 查询设备连接状态
#define DH_DEVSTATE_PROTOCAL_VER          0x0008           // 查询网络协议版本号，pBuf = int*
#define DH_DEVSTATE_TALK_ECTYPE           0x0009           // 查询设备支持的语音对讲格式列表，见结构体DHDEV_TALKFORMAT_LIST
#define DH_DEVSTATE_SD_CARD               0x000A           // 查询SD卡信息(IPC类产品)
#define DH_DEVSTATE_BURNING_DEV           0x000B           // 查询刻录机信息
#define DH_DEVSTATE_BURNING_PROGRESS      0x000C           // 查询刻录进度
#define DH_DEVSTATE_PLATFORM              0x000D           // 查询设备支持的接入平台
#define DH_DEVSTATE_CAMERA                0x000E           // 查询摄像头属性信息(IPC类产品)，pBuf = DHDEV_CAMERA_INFO *，可以有多个结构体
#define DH_DEVSTATE_SOFTWARE              0x000F           // 查询设备软件版本信息
#define DH_DEVSTATE_LANGUAGE              0x0010           // 查询设备支持的语音种类
#define DH_DEVSTATE_DSP                   0x0011           // 查询DSP能力描述(对应结构体DHDEV_DSP_ENCODECAP)
#define DH_DEVSTATE_OEM                   0x0012           // 查询OEM信息
#define DH_DEVSTATE_NET                   0x0013           // 查询网络运行状态信息
#define DH_DEVSTATE_TYPE                  0x0014           // 查询设备类型
#define DH_DEVSTATE_SNAP                  0x0015           // 查询功能属性(IPC类产品)
#define DH_DEVSTATE_RECORD_TIME           0x0016           // 查询最早录像时间和最近录像时间
#define DH_DEVSTATE_NET_RSSI              0x0017           // 查询无线网络信号强度，见结构体DHDEV_WIRELESS_RSS_INFO
#define DH_DEVSTATE_BURNING_ATTACH        0x0018           // 查询附件刻录选项
#define DH_DEVSTATE_BACKUP_DEV            0x0019           // 查询备份设备列表
#define DH_DEVSTATE_BACKUP_DEV_INFO       0x001a           // 查询备份设备详细信息
#define DH_DEVSTATE_BACKUP_FEEDBACK       0x001b           // 备份进度反馈
#define DH_DEVSTATE_ATM_QUERY_TRADE       0x001c           // 查询ATM交易类型
#define DH_DEVSTATE_SIP                   0x001d           // 查询sip状态
#define DH_DEVSTATE_VICHILE_STATE         0x001e           // 查询车载wifi状态
#define DH_DEVSTATE_TEST_EMAIL            0x001f           // 查询邮件配置是否成功
#define DH_DEVSTATE_SMART_HARD_DISK       0x0020           // 查询硬盘smart信息
#define DH_DEVSTATE_TEST_SNAPPICTURE      0x0021           // 查询抓图设置是否成功
#define DH_DEVSTATE_STATIC_ALARM          0x0022           // 查询静态报警状态
#define DH_DEVSTATE_SUBMODULE_INFO        0x0023           // 查询设备子模块信息
#define DH_DEVSTATE_DISKDAMAGE            0x0024           // 查询硬盘坏道能力 
#define DH_DEVSTATE_IPC                   0x0025           // 查询设备支持的IPC能力, 见结构体DH_DEV_IPC_INFO
#define DH_DEVSTATE_ALARM_ARM_DISARM      0x0026           // 查询报警布撤防状态
#define DH_DEVSTATE_ACC_POWEROFF_ALARM    0x0027           // 查询ACC断电报警状态(返回一个DWORD, 1表示断电，0表示通电)
#define DH_DEVSTATE_TEST_FTP_SERVER       0x0028           // 测试FTP服务器连接
#define DH_DEVSTATE_3GFLOW_EXCEED         0x0029           // 查询3G流量超出阈值状态,(见结构体DHDEV_3GFLOW_EXCEED_STATE_INFO)
#define DH_DEVSTATE_3GFLOW_INFO           0x002a           // 查询3G网络流量信息,见结构体DH_DEV_3GFLOW_INFO
#define DH_DEVSTATE_VIHICLE_INFO_UPLOAD   0x002b           // 车载自定义信息上传(见结构体ALARM_VEHICLE_INFO_UPLOAD)
#define DH_DEVSTATE_SPEED_LIMIT           0x002c           // 查询限速报警状态(见结构体ALARM_SPEED_LIMIT)
#define DH_DEVSTATE_DSP_EX                0x002d           // 查询DSP扩展能力描述(对应结构体DHDEV_DSP_ENCODECAP_EX)
#define DH_DEVSTATE_3GMODULE_INFO         0x002e           // 查询3G模块信息(对应结构体DH_DEV_3GMODULE_INFO)
#define DH_DEVSTATE_MULTI_DDNS            0x002f           // 查询多DDNS状态信息(对应结构体DH_DEV_MULTI_DDNS_INFO)
#define DH_DEVSTATE_CONFIG_URL            0x0030           // 查询设备配置URL信息(对应结构体DH_DEV_URL_INFO)
#define DH_DEVSTATE_HARDKEY               0x0031           // 查询HardKey状态（对应结构体DHDEV_HARDKEY_STATE)
#define DH_DEVSTATE_ISCSI_PATH            0x0032           // 查询ISCSI路径列表(对应结构体DHDEV_ISCSI_PATHLIST)
#define DH_DEVSTATE_DLPREVIEW_SLIPT_CAP   0x0033           // 查询设备本地预览支持的分割模式(对应结构体DEVICE_LOCALPREVIEW_SLIPT_CAP)
#define DH_DEVSTATE_WIFI_ROUTE_CAP        0x0034           // 查询无线路由能力信息(对应结构体DHDEV_WIFI_ROUTE_CAP)
#define DH_DEVSTATE_ONLINE                0x0035           // 查询设备的在线状态(返回一个DWORD, 1表示在线, 0表示断线)
#define DH_DEVSTATE_PTZ_LOCATION          0x0036           // 查询云台状态信息(对应结构体DH_PTZ_LOCATION_INFO)
#define DH_DEVSTATE_MONITOR_INFO          0x0037           // 画面监控辅助信息(对应结构体DHDEV_MONITOR_INFO)
#define DH_DEVSTATE_SUBDEVICE             0x0300           // 查询子设备(电源, 风扇等)状态(对应结构体CFG_DEVICESTATUS_INFO)
#define DH_DEVSTATE_RAID_INFO             0x0038           // 查询RAID状态(对应结构体ALARM_RAID_INFO)  
#define DH_DEVSTATE_TEST_DDNSDOMAIN       0x0039           // 测试DDNS域名是否可用
#define DH_DEVSTATE_VIRTUALCAMERA         0x003a           // 查询虚拟摄像头状态(对应DHDEV_VIRTUALCAMERA_STATE_INFO)
#define DH_DEVSTATE_TRAFFICWORKSTATE      0x003b           // 获取设备工作视频/线圈模式状态等(对应DHDEV_TRAFFICWORKSTATE_INFO)
#define DH_DEVSTATE_ALARM_CAMERA_MOVE     0x003c           // 获取摄像机移位报警事件状态(对应ALARM_CAMERA_MOVE_INFO)
#define DH_DEVSTATE_ALARM                 0x003e           // 获取外部报警状态(对应 NET_CLIENT_ALARM_STATE) 
#define DH_DEVSTATE_VIDEOLOST             0x003f           // 获取视频丢失报警状态(对应 NET_CLIENT_VIDEOLOST_STATE) 
#define DH_DEVSTATE_MOTIONDETECT          0x0040           // 获取动态监测报警状态(对应 NET_CLIENT_MOTIONDETECT_STATE)
#define DH_DEVSTATE_DETAILEDMOTION        0x0041           // 获取详细的动态监测报警状态(对应 NET_CLIENT_DETAILEDMOTION_STATE)
#define DH_DEVSTATE_VEHICLE_INFO          0x0042           // 获取车载自身各种硬件信息(对应 DHDEV_VEHICLE_INFO)
#define DH_DEVSTATE_VIDEOBLIND            0x0043           // 获取视频遮挡报警状态(对应 NET_CLIENT_VIDEOBLIND_STATE)
#define DH_DEVSTATE_3GSTATE_INFO          0x0044           // 查询3G模块相关信息(对应结构体DHDEV_VEHICLE_3GMODULE)
#define DH_DEVSTATE_NETINTERFACE          0x0045           // 查询网络接口信息(对应 DHDEV_NETINTERFACE_INFO)
#define DH_DEVSTATE_PICINPIC_CHN          0x0046           // 查询画中画通道号(对应DWORD数组)
#define DH_DEVSTATE_COMPOSITE_CHN         0x0047           // 查询融合屏通道信息(对应DH_COMPOSITE_CHANNEL数组)
#define DH_DEVSTATE_WHOLE_RECORDING       0x0048           // 查询设备整体录像状态(对应BOOL), 只要有一个通道在录像，即为设备整体状态为录像
#define DH_DEVSTATE_WHOLE_ENCODING        0x0049           // 查询设备整体编码状态(对应BOOL), 只要有一个通道在编码，即为设备整体状态为编码
#define DH_DEVSTATE_DISK_RECORDE_TIME     0x004a           // 查询设备硬盘录像时间信息(pBuf = DEV_DISK_RECORD_TIME*，可以有多个结构体)
#define DH_DEVSTATE_BURNER_DOOR           0x004b           // 是否已弹出刻录机光驱门(对应结构体 NET_DEVSTATE_BURNERDOOR)
#define DH_DEVSTATE_GET_DATA_CHECK        0x004c           // 查询光盘数据校验进度(对应 NET_DEVSTATE_DATA_CHECK)
#define DH_DEVSTATE_ALARM_IN_CHANNEL      0x004f           // 查询报警输入通道信息(对应NET_ALARM_IN_CHANNEL数组)
#define DH_DEVSTATE_ALARM_CHN_COUNT       0x0050           // 查询报警通道数(对应NET_ALARM_CHANNEL_COUNT)
#define DH_DEVSTATE_PTZ_VIEW_RANGE        0x0051           // 查询云台可视域状态(对应DH_OUT_PTZ_VIEW_RANGE_STATUS)
#define DH_DEVSTATE_DEV_CHN_COUNT         0x0052           // 查询设备通道信息(对应NET_DEV_CHN_COUNT_INFO)
#define DH_DEVSTATE_RTSP_URL              0x0053           // 查询设备支持的RTSP URL列表，见结构体DEV_RTSPURL_LIST
#define DH_DEVSTATE_LIMIT_LOGIN_TIME      0x0054           // 查询设备登录的在线超时时间,返回一个BTYE,（单位：分钟） ,0表示不限制,非零正整数表示限制的分钟数
#define DH_DEVSTATE_GET_COMM_COUNT        0x0055           // 获取串口数 见结构体NET_GET_COMM_COUNT
#define DH_DEVSTATE_RECORDING_DETAIL      0x0056           // 查询录象状态详细信息(pBuf = NET_RECORD_STATE_DETAIL*)
#define DH_DEVSTATE_PTZ_PRESET_LIST       0x0057           // 获取当前云台的预置点列表(对应结构NET_PTZ_PRESET_LIST)
#define DH_DEVSTATE_EXTERNAL_DEVICE       0x0058           // 外接设备信息(pBuf = NET_EXTERNAL_DEVICE*)
#define DH_DEVSTATE_GET_UPGRADE_STATE     0x0059           // 获取设备升级状态(对应结构DHDEV_UPGRADE_STATE_INFO)
#define DH_DEVSTATE_MULTIPLAYBACK_SPLIT_CAP 0x005a         // 获取多通道预览分割能力( 对应结构体 NET_MULTIPLAYBACK_SPLIT_CAP )
#define DH_DEVSTATE_BURN_SESSION_NUM      0x005b           // 获取刻录会话总数(pBuf = int*)
#define DH_DEVSTATE_PROTECTIVE_CAPSULE    0X005c           // 查询防护舱状态(对应结构体ALARM_PROTECTIVE_CAPSULE_INFO)


#define DH_DEVSTATE_POWER_STATE           0x0152           // 查询电源状态(对应结构体DH_POWER_STATUS)
#define DH_DEVSTATE_ALL_ALARM_CHANNELS_STATE  0x153        // 查询报警通道状态(对应结构体 NET_CLIENT_ALARM_CHANNELS_STATE)
#define DH_DEVSTATE_ALARMKEYBOARD_COUNT   0x0154           // 查询串口上连接的报警键盘数(对应结构体NET_ALARMKEYBOARD_COUNT)
#define DH_DEVSTATE_EXALARMCHANNELS       0x0155           // 查询扩展报警模块通道映射关系(对应结构体 NET_EXALARMCHANNELS)
#define DH_DEVSTATE_GET_BYPASS            0x0156           // 查询通道旁路状态(对应结构体 NET_DEVSTATE_GET_BYPASS)
#define DH_DEVSTATE_ACTIVATEDDEFENCEAREA  0x0157           // 获取激活的防区信息(对应结构体 NET_ACTIVATEDDEFENCEAREA)
#define DH_DEVSTATE_DEV_RECORDSET         0x0158           // 查询设备记录集信息(对应NET_CTRL_RECORDSET_PARAM)
#define DH_DEVSTATE_DOOR_STATE            0x0159           // 查询门禁状态(对应NET_DOOR_STATUS_INFO)
#define DH_DEVSTATE_ANALOGALARM_CHANNELS  0x1560           // 模拟量报警输入通道映射关系(对应NET_ANALOGALARM_CHANNELS)
#define DH_DEVSTATE_GET_SENSORLIST        0x1561           // 获取设备支持的传感器列表(对应 NET_SENSOR_LIST)
#define DH_DEVSTATE_ALARM_CHANNELS	0x1562		// 查询开关量报警模块通道映射关系(对应结构体 NET_ALARM_CHANNELS)
												// 如果设备不支持查询扩展报警模块通道,可以用该功能查询扩展通道的逻辑通道号，并当做本地报警通道使用
#define DH_DEVSTATE_GET_ALARM_SUBSYSTEM_ACTIVATESTATUS	0x1563	// 获取当前子系统启用状态( 对应 NET_GET_ALARM_SUBSYSTEM_ACTIVATE_STATUES)


// 开关量报警通道信息
typedef struct tagNET_ALARM_CHANNEL_INFO 
{
	DWORD			dwSize;
	int				nSlot;					// 根地址, 0表示本地通道, 1表示连接在第一个串口上的扩展通道, 2、3...以此类推
	int				nChannel;				// 非本地报警通道在扩展模块上的通道号, 从0开始
	char			szName[DH_COMMON_STRING_128];	// 通道名称
}NET_ALARM_CHANNEL_INFO;

// 本地(或远程)开关量报警通道和逻辑通道号映射关系
typedef struct tagNET_ALARM_CHANNELS 
{
	DWORD			dwSize;
	int				nMaxAlarmChannels;		// 最大通道数
	int				nRetAlarmChannels;		// 返回的通道数
	NET_ALARM_CHANNEL_INFO*	pstuChannelInfo;// 通道信息，用户分配内存
}NET_ALARM_CHANNELS;

// 查询类型，对应CLIENT_QueryRemotDevState接口
#define DH_DEVSTATE_ALARM_REMOTE          0x1000           // 获取远程设备外部报警(对应 ALARM_REMOTE_ALARM_INFO)
#define DH_DEVSTATE_ALARM_FRONTDISCONNECT 0x1001           // 获取前端IPC断网报警(对应结构体ALARM_FRONTDISCONNET_INFO)

// 配置类型，对应CLIENT_GetDevConfig和CLIENT_SetDevConfig接口
#define DH_DEV_DEVICECFG                  0x0001           // 设备属性配置
#define DH_DEV_NETCFG                     0x0002           // 网络配置
#define DH_DEV_CHANNELCFG                 0x0003           // 图象通道配置
#define DH_DEV_PREVIEWCFG                 0x0004           // 预览参数配置
#define DH_DEV_RECORDCFG                  0x0005           // 录像配置
#define DH_DEV_COMMCFG                    0x0006           // 串口属性配置
#define DH_DEV_ALARMCFG                   0x0007           // 报警属性配置
#define DH_DEV_TIMECFG                    0x0008           // DVR时间配置
#define DH_DEV_TALKCFG                    0x0009           // 对讲参数配置
#define DH_DEV_AUTOMTCFG                  0x000A           // 自动维护配置        
#define DH_DEV_VEDIO_MARTIX               0x000B           // 本机矩阵控制策略配置    
#define DH_DEV_MULTI_DDNS                 0x000C           // 多ddns服务器配置
#define DH_DEV_SNAP_CFG                   0x000D           // 抓图相关配置
#define DH_DEV_WEB_URL_CFG                0x000E           // HTTP路径配置
#define DH_DEV_FTP_PROTO_CFG              0x000F           // FTP上传配置
#define DH_DEV_INTERVIDEO_CFG             0x0010           // 平台接入配置，此时channel参数代表平台类型，
                                                           // channel=4： 代表贝尔阿尔卡特；channel=10：代表中兴力维；channel=11：代表U网通；channel=51：代表天地阳光
#define DH_DEV_VIDEO_COVER                0x0011           // 区域遮挡配置
#define DH_DEV_TRANS_STRATEGY             0x0012           // 传输策略配置，画质优先\流畅性优先
#define DH_DEV_DOWNLOAD_STRATEGY          0x0013           // 录象下载策略配置，高速下载\普通下载
#define DH_DEV_WATERMAKE_CFG              0x0014           // 图象水印配置
#define DH_DEV_WLAN_CFG                   0x0015           // 无线网络配置
#define DH_DEV_WLAN_DEVICE_CFG            0x0016           // 搜索无线设备配置
#define DH_DEV_REGISTER_CFG               0x0017           // 主动注册参数配置
#define DH_DEV_CAMERA_CFG                 0x0018           // 摄像头属性配置
#define DH_DEV_INFRARED_CFG               0x0019           // 红外报警配置
#define DH_DEV_SNIFFER_CFG                0x001A           // Sniffer抓包配置
#define DH_DEV_MAIL_CFG                   0x001B           // 邮件配置
#define DH_DEV_DNS_CFG                    0x001C           // DNS服务器配置
#define DH_DEV_NTP_CFG                    0x001D           // NTP配置
#define DH_DEV_AUDIO_DETECT_CFG           0x001E           // 音频检测配置
#define DH_DEV_STORAGE_STATION_CFG        0x001F           // 存储位置配置
#define DH_DEV_PTZ_OPT_CFG                0x0020           // 云台操作属性(已经废除，请使用CLIENT_GetPtzOptAttr获取云台操作属性)
#define DH_DEV_DST_CFG                    0x0021           // 夏令时配置
#define DH_DEV_ALARM_CENTER_CFG           0x0022           // 报警中心配置
#define DH_DEV_VIDEO_OSD_CFG              0x0023           // 视频OSD叠加配置
#define DH_DEV_CDMAGPRS_CFG               0x0024           // CDMA\GPRS网络配置

#define DH_DEV_IPFILTER_CFG               0x0025           // IP过滤配置
#define DH_DEV_TALK_ENCODE_CFG            0x0026           // 语音对讲编码配置
#define DH_DEV_RECORD_PACKET_CFG          0X0027           // 录像打包长度配置
#define DH_DEV_MMS_CFG                    0X0028           // 短信MMS配置 
#define DH_DEV_SMSACTIVATION_CFG          0X0029           // 短信激活无线连接配置
#define DH_DEV_DIALINACTIVATION_CFG       0X002A           // 拨号激活无线连接配置
#define DH_DEV_SNIFFER_CFG_EX             0x0030           // 网络抓包配置
#define DH_DEV_DOWNLOAD_RATE_CFG          0x0031           // 下载速度限制
#define DH_DEV_PANORAMA_SWITCH_CFG        0x0032           // 全景切换报警配置
#define DH_DEV_LOST_FOCUS_CFG             0x0033           // 失去焦点报警配置
#define DH_DEV_ALARM_DECODE_CFG           0x0034           // 报警解码器配置
#define DH_DEV_VIDEOOUT_CFG               0x0035           // 视频输出参数配置
#define DH_DEV_POINT_CFG                  0x0036           // 预制点使能配置
#define DH_DEV_IP_COLLISION_CFG           0x0037           // Ip冲突检测报警配置
#define DH_DEV_OSD_ENABLE_CFG             0x0038           // OSD叠加使能配置
#define DH_DEV_LOCALALARM_CFG             0x0039           // 本地报警配置(结构体DH_ALARMIN_CFG_EX)
#define DH_DEV_NETALARM_CFG               0x003A           // 网络报警配置(结构体DH_ALARMIN_CFG_EX)
#define DH_DEV_MOTIONALARM_CFG            0x003B           // 动检报警配置(结构体DH_MOTION_DETECT_CFG_EX)
#define DH_DEV_VIDEOLOSTALARM_CFG         0x003C           // 视频丢失报警配置(结构体DH_VIDEO_LOST_CFG_EX)
#define DH_DEV_BLINDALARM_CFG             0x003D           // 视频遮挡报警配置(结构体DH_BLIND_CFG_EX)
#define DH_DEV_DISKALARM_CFG              0x003E           // 硬盘报警配置(结构体DH_DISK_ALARM_CFG_EX)
#define DH_DEV_NETBROKENALARM_CFG         0x003F           // 网络中断报警配置(结构体DH_NETBROKEN_ALARM_CFG_EX)
#define DH_DEV_ENCODER_CFG                0x0040           // 数字通道的前端编码器信息（混合DVR使用，结构体DEV_ENCODER_CFG）
#define DH_DEV_TV_ADJUST_CFG              0x0041           // TV调节配置（channel代表TV号(0开始)，类型结构体）
#define DH_DEV_ABOUT_VEHICLE_CFG          0x0042           // 车载相关配置，北京公交使用
#define DH_DEV_ATM_OVERLAY_ABILITY        0x0043           // 获取atm叠加支持能力信息
#define DH_DEV_ATM_OVERLAY_CFG            0x0044           // atm叠加配置，新atm特有
#define DH_DEV_DECODER_TOUR_CFG           0x0045           // 解码器解码轮巡配置
#define DH_DEV_SIP_CFG                    0x0046           // SIP配置
#define DH_DEV_VICHILE_WIFI_AP_CFG        0x0047           // wifi ap配置
#define DH_DEV_STATICALARM_CFG            0x0048           // 静态报警配置 
#define DH_DEV_DECODE_POLICY_CFG          0x0049           // 设备的解码策略配置(结构体DHDEV_DECODEPOLICY_CFG，channel为解码通道0开始) 
#define DH_DEV_MACHINE_CFG                0x004A           // 机器相关的配置(结构体DHDEV_MACHINE_CFG)
#define DH_DEV_MAC_COLLISION_CFG          0x004B           // MAC冲突检测配置(结构体ALARM_MAC_COLLISION_CFG)
#define DH_DEV_RTSP_CFG                   0x004C           // RTSP配置(对应结构体DHDEV_RTSP_CFG)
#define DH_DEV_232_COM_CARD_CFG           0x004E           // 232串口卡号信号事件配置(对应结构体COM_CARD_SIGNAL_LINK_CFG)
#define DH_DEV_485_COM_CARD_CFG           0x004F           // 485串口卡号信号事件配置(对应结构体COM_CARD_SIGNAL_LINK_CFG)
#define DH_DEV_FTP_PROTO_CFG_EX           0x0050           // FTP上传扩展配置(对应结构体DHDEV_FTP_PROTO_CFG_EX)
#define DH_DEV_SYSLOG_REMOTE_SERVER       0x0051           // SYSLOG 远程服务器配置(对应结构体DHDEV_SYSLOG_REMOTE_SERVER)
#define DH_DEV_COMMCFG_EX                 0x0052           // 扩展串口属性配置(对应结构体DHDEV_COMM_CFG_EX)            
#define DH_DEV_NETCARD_CFG                0x0053           // 卡口信息配置(对应结构体DHDEV_NETCARD_CFG)
#define DH_DEV_BACKUP_VIDEO_FORMAT        0x0054           // 视频备份格式配置(对应结构体DHDEV_BACKUP_VIDEO_FORMAT)
#define DH_DEV_STREAM_ENCRYPT_CFG         0x0055           // 码流加密配置(对应结构体DHEDV_STREAM_ENCRYPT)
#define DH_DEV_IPFILTER_CFG_EX            0x0056           // IP过滤配置扩展(对应结构体DHDEV_IPIFILTER_CFG_EX)
#define DH_DEV_CUSTOM_CFG                 0x0057           // 用户自定义配置(对应结构体DHDEV_CUSTOM_CFG)
#define DH_DEV_WLAN_DEVICE_CFG_EX         0x0058           // 搜索无线设备扩展配置(对应结构体DHDEV_WLAN_DEVICE_LIST_EX)
#define DH_DEV_ACC_POWEROFF_CFG           0x0059           // ACC断线事件配置(对应结构体DHDEV_ACC_POWEROFF_CFG)
#define DH_DEV_EXPLOSION_PROOF_CFG        0x005a           // 防爆盒报警事件配置(对应结构体DHDEV_EXPLOSION_PROOF_CFG)
#define DH_DEV_NETCFG_EX                  0x005b           // 网络扩展配置(对应结构体DHDEV_NET_CFG_EX)
#define DH_DEV_LIGHTCONTROL_CFG           0x005c           // 灯光控制配置(对应结构体DHDEV_LIGHTCONTROL_CFG)
#define DH_DEV_3GFLOW_CFG                 0x005d           // 3G流量信息配置(对应结构体DHDEV_3GFLOW_INFO_CFG)
#define DH_DEV_IPV6_CFG                   0x005e           // IPv6配置(对应结构体DHDEV_IPV6_CFG)
#define DH_DEV_SNMP_CFG                   0X005f           // Snmp配置(对应结构体DHDEV_NET_SNMP_CFG), 设置完成后需要重启设备
#define DH_DEV_SNAP_CONTROL_CFG           0x0060           // 抓图开关配置(对应结构体DHDEV_SNAP_CONTROL_CFG)
#define DH_DEV_GPS_MODE_CFG               0X0061           // GPS定位模式配置(对应结构体DHDEV_GPS_MODE_CFG)
#define DH_DEV_SNAP_UPLOAD_CFG            0X0062           // 图片上传配置信息(对应结构体 DHDEV_SNAP_UPLOAD_CFG)
#define DH_DEV_SPEED_LIMIT_CFG            0x0063           // 限速配置信息(对应结构体DHDEV_SPEED_LIMIT_CFG)
#define DH_DEV_ISCSI_CFG                  0x0064           // iSCSI配置(对应结构体DHDEV_ISCSI_CFG), 设置完成后需要重启设备
#define DH_DEV_WIRELESS_ROUTING_CFG       0x0065           // 无线路由配置(对应结构体DHDEV_WIRELESS_ROUTING_CFG)
#define DH_DEV_ENCLOSURE_CFG              0x0066           // 电子围栏配置(对应结构体DHDEV_ENCLOSURE_CFG)
#define DH_DEV_ENCLOSURE_VERSION_CFG      0x0067           // 电子围栏版本号配置(对应结构体DHDEV_ENCLOSURE_VERSION_CFG)
#define DH_DEV_RIAD_EVENT_CFG             0x0068           // Raid事件配置(对应结构体DHDEV_RAID_EVENT_CFG)
#define DH_DEV_FIRE_ALARM_CFG             0x0069           // 火警报警配置(对应结构体DHDEV_FIRE_ALARM_CFG)
#define DH_DEV_LOCALALARM_NAME_CFG        0x006a           // 本地名称报警配置(对应Name1&&name2&&name3...格式字符串)
#define DH_DEV_URGENCY_RECORD_CFG         0x0070           // 紧急存储配置(对应结构体DHDEV_URGENCY_RECORD_CFG)
#define DH_DEV_ELEVATOR_ATTRI_CFG         0x0071           // 电梯运行参数配置(对应结构体DHDEV_ELEVATOR_ATTRI_CFG)
#define DH_DEV_ATM_OVERLAY_CFG_EX         0x0072           // atm叠加配置，新atm特有,支持大于32通道的设备(对应结构体DHDEV_ATM_OVERLAY_CONFIG_EX)
#define DH_DEV_MACFILTER_CFG              0x0073           // MAC过滤配置(对应结构体DHDEV_MACFILTER_CFG)
#define DH_DEV_MACIPFILTER_CFG            0x0074           // MAC,IP过滤(要求ip,mac是一一对应的)配置(对应结构体DHDEV_MACIPFILTER_CFG)
#define DH_DEV_STREAM_ENCRYPT_TIME_CFG    0x0075           // 码流加密(加密计划)配置(对应结构体DHEDV_STREAM_ENCRYPT)
#define DH_DEV_LIMIT_BIT_RATE_CFG         0x0076           // 限码流配置(对应结构体 DHDEV_LIMIT_BIT_RATE) 
#define DH_DEV_SNAP_CFG_EX                0x0077           // 抓图相关配置扩展(对应结构体 DHDEV_SNAP_CFG_EX)
#define DH_DEV_DECODER_URL_CFG            0x0078           // 解码器url配置(对应结构体DHDEV_DECODER_URL_CFG)
#define DH_DEV_TOUR_ENABLE_CFG            0x0079           // 轮巡使能配置(对应结构体DHDEV_TOUR_ENABLE_CFG)
#define DH_DEV_VICHILE_WIFI_AP_CFG_EX     0x007a           // wifi ap配置扩展(对应结构体DHDEV_VEHICLE_WIFI_AP_CFG_EX)
#define DH_DEV_ENCODER_CFG_EX             0x007b           // 数字通道的前端编码器信息扩展，(对应结构体DEV_ENCODER_CFG_EX)
#define DH_DEV_USER_END_CFG               1000             

// 报警类型，对应CLIENT_StartListen接口
#define DH_COMM_ALARM                     0x1100           // 常规报警(包括外部报警，视频丢失，动态检测)
#define DH_SHELTER_ALARM                  0x1101           // 视频遮挡报警
#define DH_DISK_FULL_ALARM                0x1102           // 硬盘满报警
#define DH_DISK_ERROR_ALARM               0x1103           // 硬盘故障报警
#define DH_SOUND_DETECT_ALARM             0x1104           // 音频检测报警
#define DH_ALARM_DECODER_ALARM            0x1105           // 报警解码器报警

// 扩展报警类型，对应CLIENT_StartListenEx接口
#define DH_ALARM_ALARM_EX                 0x2101           // 外部报警
#define DH_MOTION_ALARM_EX                0x2102           // 动态检测报警
#define DH_VIDEOLOST_ALARM_EX             0x2103           // 视频丢失报警
#define DH_SHELTER_ALARM_EX               0x2104           // 视频遮挡报警
#define DH_SOUND_DETECT_ALARM_EX          0x2105           // 音频检测报警
#define DH_DISKFULL_ALARM_EX              0x2106           // 硬盘满报警
#define DH_DISKERROR_ALARM_EX             0x2107           // 坏硬盘报警
#define DH_ENCODER_ALARM_EX               0x210A           // 编码器报警
#define DH_URGENCY_ALARM_EX               0x210B           // 紧急报警
#define DH_WIRELESS_ALARM_EX              0x210C           // 无线报警
#define DH_NEW_SOUND_DETECT_ALARM_EX      0x210D           // 新音频检测报警，报警信息的结构体见DH_NEW_SOUND_ALARM_STATE；
#define DH_ALARM_DECODER_ALARM_EX         0x210E           // 报警解码器报警
#define DH_DECODER_DECODE_ABILITY         0x210F           // 解码器：解码能力报警
#define DH_FDDI_DECODER_ABILITY           0x2110           // 光纤编码器状态报警
#define DH_PANORAMA_SWITCH_ALARM_EX       0x2111           // 切换场景报警
#define DH_LOSTFOCUS_ALARM_EX             0x2112           // 失去焦点报警
#define DH_OEMSTATE_EX                    0x2113           // oem报停状态
#define DH_DSP_ALARM_EX                   0x2114           // DSP报警
#define DH_ATMPOS_BROKEN_EX               0x2115           // atm和pos机断开报警， 0：连接断开 1：连接正常
#define DH_RECORD_CHANGED_EX              0x2116           // 录像状态变化报警
#define DH_CONFIG_CHANGED_EX              0x2117           // 配置发生变化报警
#define DH_DEVICE_REBOOT_EX               0x2118           // 设备重启报警
#define DH_WINGDING_ALARM_EX              0x2119           // 线圈/车检器故障报警
#define DH_TRAF_CONGESTION_ALARM_EX       0x211A           // 交通阻塞报警(车辆出现异常停止或者排队)
#define DH_TRAF_EXCEPTION_ALARM_EX        0x211B           // 交通异常报警(交通流量趋于0或异常空闲)
#define DH_EQUIPMENT_FILL_ALARM_EX        0x211C           // 补光设备故障报警
#define DH_ALARM_ARM_DISARM_STATE         0x211D           // 报警布撤防状态
#define DH_ALARM_ACC_POWEROFF             0x211E           // ACC断电报警
#define DH_ALARM_3GFLOW_EXCEED            0x211F           // 3G流量超出阈值报警(报警信息的结构体见结构体DHDEV_3GFLOW_EXCEED_STATE_INFO)
#define DH_ALARM_SPEED_LIMIT              0x2120           // 限速报警
#define DH_ALARM_VEHICLE_INFO_UPLOAD      0x2121           // 车载自定义信息上传 
#define DH_STATIC_ALARM_EX                0x2122           // 静态检测报警
#define DH_PTZ_LOCATION_EX                0x2123           // 云台定位信息
#define DH_ALARM_CARD_RECORD_UPLOAD       0x2124           // 卡号录像信息上传(对应结构体 ALARM_CARD_RECORD_INFO_UPLOAD)
#define DH_ALARM_ATM_INFO_UPLOAD          0x2125           // ATM交易信息上传(对应结构体 ALARM_ATM_INFO_UPLOAD)
#define DH_ALARM_ENCLOSURE                0x2126           // 电子围栏报警(对应结构体ALARM_ENCLOSURE_INFO)
#define DH_ALARM_SIP_STATE                0x2127           // SIP状态报警(对应结构体ALARM_SIP_STATE)
#define DH_ALARM_RAID_STATE               0x2128           // RAID异常报警(对应结构体ALARM_RAID_INFO)
#define DH_ALARM_CROSSING_SPEED_LIMIT     0x2129           // 路口限速报警(对应结构体ALARM_SPEED_LIMIT)
#define DH_ALARM_OVER_LOADING             0x212A           // 超载报警(对应结构体ALARM_OVER_LOADING)
#define DH_ALARM_HARD_BRAKING             0x212B           // 急刹车报警(对应机构体ALARM_HARD_BRAKING)
#define DH_ALARM_SMOKE_SENSOR             0x212C           // 烟感报警(对应结构体ALARM_SMOKE_SENSOR)
#define DH_ALARM_TRAFFIC_LIGHT_FAULT      0x212D           // 交通灯故障报警(对应结构体ALARM_TRAFFIC_LIGHT_FAULT) 
#define DH_ALARM_TRAFFIC_FLUX_STAT        0x212E           // 交通流量统计报警(对应结构体ALARM_TRAFFIC_FLUX_LANE_INFO)
#define DH_ALARM_CAMERA_MOVE              0x212F           // 摄像机移位报警事件(对应结构体ALARM_CAMERA_MOVE_INFO)
#define DH_ALARM_DETAILEDMOTION           0x2130           // 详细动检报警上报信息(对应结构体ALARM_DETAILEDMOTION_CHNL_INFO)
#define DH_ALARM_STORAGE_FAILURE          0x2131           // 存储异常报警(对应结构体ALARM_STORAGE_FAILURE数组)
#define DH_ALARM_FRONTDISCONNECT          0x2132           // 前端IPC断网报警(对应结构体ALARM_FRONTDISCONNET_INFO)
#define DH_ALARM_ALARM_EX_REMOTE          0x2133           // 远程外部报警(对应结构体 ALARM_REMOTE_ALARM_INFO)
#define DH_ALARM_BATTERYLOWPOWER          0x2134           // 电池电量低报警(对应结构体ALARM_BATTERYLOWPOWER_INFO)
#define DH_ALARM_TEMPERATURE              0x2135           // 温度过高报警(对应结构体ALARM_TEMPERATURE_INFO)
#define DH_ALARM_TIREDDRIVE               0x2136           // 疲劳驾驶报警(对应结构体ALARM_TIREDDRIVE_INFO)
#define DH_ALARM_LOST_RECORD              0x2137           // 丢录像事件报警(对应结构体ALARM_LOST_RECORD)
#define DH_ALARM_HIGH_CPU                 0x2138           // CPU占用率过高事件报警(对应结构体ALARM_HIGH_CPU)
#define DH_ALARM_LOST_NETPACKET           0x2139           // 网络发送数据丢包事件报警(对应结构体ALARM_LOST_NETPACKET)
#define DH_ALARM_HIGH_MEMORY              0x213A           // 内存占用率过高事件报警(对应结构体ALARM_HIGH_MEMORY)
#define DH_LONG_TIME_NO_OPERATION         0x213B           // WEB用户长时间无操作事件（无扩展信息）
#define DH_BLACKLIST_SNAP                 0x213C           // 黑名单车辆抓拍事件(对应结构体DH_BLACKLIST_SNAP_INFO)         
#define DH_ALARM_DISK                     0x213E           // 硬盘报警(对应ALARM_DISK_INFO数组)
#define DH_ALARM_FILE_SYSTEM              0x213F           // 文件系统报警(对应ALARM_FILE_SYSTEM_INFO数组)
#define DH_ALARM_IVS                      0x2140           // 智能报警事件(对应结构体ALARM_IVS_INFO)
#define DH_ALARM_GOODS_WEIGHT_UPLOAD      0x2141           // 货重信息上报(对应ALARM_GOODS_WEIGHT_UPLOAD_INFO)
#define DH_ALARM_GOODS_WEIGHT             0x2142           // 货重信息报警(对应ALARM_GOODS_WEIGHT_INFO)
#define DH_GPS_STATUS                     0x2143           // GPS定位信息(对应 NET_GPS_STATUS_INFO)
#define DH_ALARM_DISKBURNED_FULL          0x2144           // 硬盘刻录满报警(对应 ALARM_DISKBURNED_FULL_INFO)
#define DH_ALARM_STORAGE_LOW_SPACE        0x2145           // 存储容量不足事件(对应ALARM_STORAGE_LOW_SPACE_INFO)
#define DH_ALARM_DISK_FLUX                0x2160           // 硬盘数据异常事件(对应ALARM_DISK_FLUX)
#define DH_ALARM_NET_FLUX                 0x2161           // 网络数据异常事件(对应ALARM_NET_FLUX)
#define DH_ALARM_FAN_SPEED                0x2162           // 风扇转速异常事件(对应ALARM_FAN_SPEED)
#define DH_ALARM_STORAGE_FAILURE_EX       0x2163           // 存储错误报警(对应结构体ALARM_STORAGE_FAILURE_EX)
#define DH_ALARM_RECORD_FAILED            0x2164           // 录像异常报警(对应结构体ALARM_RECORD_FAILED_INFO)
#define DH_ALARM_STORAGE_BREAK_DOWN       0x2165           // 存储崩溃事件(对应结构体ALARM_STORAGE_BREAK_DOWN_INFO)
#define DH_ALARM_VIDEO_ININVALID          0x2166           // 视频输入通道失效事件（例：配置的视频输入通道码流，超出设备处理能力）ALARM_VIDEO_ININVALID_INFO
#define DH_ALARM_VEHICLE_TURNOVER         0x2167           // 车辆侧翻报警事件(对应结构体ALARM_VEHICEL_TURNOVER_EVENT_INFO)
#define DH_ALARM_VEHICLE_COLLISION        0x2168           // 车辆撞车报警事件(对应结构体ALARM_VEHICEL_COLLISION_EVENT_INFO)
#define DH_ALARM_VEHICLE_CONFIRM          0x2169           // 车辆上传信息事件(对应结构体ALARM_VEHICEL_CONFIRM_INFO)
#define DH_ALARM_VEHICLE_LARGE_ANGLE      0x2170           // 车载摄像头大角度扭转事件(对应结构体ALARM_VEHICEL_LARGE_ANGLE)
#define DH_ALARM_TALKING_INVITE           0x2171           // 设备请求对方发起对讲事件(对应结构体ALARM_TALKING_INVITE_INFO)
#define DH_ALARM_ALARM_EX2                0x2175           // 本地报警事件(对应结构体ALARM_ALARM_INFO_EX2，对DH_ALARM_ALARM_EX升级)
#define DH_ALARM_VIDEO_TIMING             0x2176           // 视频定时检测事件(对应结构体ALARM_VIDEO_TIMING)
#define DH_ALARM_COMM_PORT                0x2177           // 串口事件(对应结构体ALARM_COMM_PORT_EVENT_INFO)
#define DH_ALARM_AUDIO_ANOMALY            0x2178           // 音频异常事件(对应结构体ALARM_AUDIO_ANOMALY)
#define DH_ALARM_AUDIO_MUTATION           0x2179           // 声强突变事件(对应结构体ALARM_AUDIO_MUTATION)
#define DH_EVENT_TYREINFO                 0X2180           // 轮胎信息上报事件(对应结构体EVENT_TYRE_INFO)
#define DH_ALARM_POWER_ABNORMAL           0X2181           // 冗余电源异常报警(对应结构体ALARM_POWER_ABNORMAL_INFO)
#define DH_EVENT_REGISTER_OFF             0x2182           // 车载设备主动下线事件(对应结构体 EVENT_REGISTER_OFF_INFO)
#define DH_ALARM_NO_DISK                  0X2183           // 无硬盘报警(对应结构体ALARM_NO_DISK_INFO)
#define DH_ALARM_FALLING                  0X2184           // 跌落事件报警(对应结构体ALARM_FALLING_INFO)
#define DH_ALARM_PROTECTIVE_CAPSULE       0X2185           // 防护舱事件(对应结构体ALARM_PROTECTIVE_CAPSULE_INFO)
#define DH_ALARM_NO_RESPONSE              0x2186           // 呼叫未应答警报(对应结构体ALARM_NO_RESPONSE_INFO)

#define DH_ALARM_STORAGE_NOT_EXIST        0x3167           // 存储组不存在事件(对应结构体ALARM_STORAGE_NOT_EXIST_INFO)
#define DH_ALARM_NET_ABORT                0x3169           // 网络故障事件(对应结构体ALARM_NETABORT_INFO)
#define DH_ALARM_IP_CONFLICT              0x3170           // IP冲突事件(对应结构体ALARM_IP_CONFLICT_INFO)
#define DH_ALARM_MAC_CONFLICT             0x3171           // MAC冲突事件(对应结构体ALARM_MAC_CONFLICT_INFO)
#define DH_ALARM_POWERFAULT               0x3172           // 电源故障事件(对应结构体ALARM_POWERFAULT_INFO)
#define DH_ALARM_CHASSISINTRUDED          0x3173           // 机箱入侵(防拆)报警事件(对应结构体ALARM_CHASSISINTRUDED_INFO)
#define DH_ALARM_ALARMEXTENDED            0x3174           // 本地扩展报警事件(对应结构体 ALARM_ALARMEXTENDED_INFO)
#define DH_ALARM_ARMMODE_CHANGE_EVENT     0x3175           // 布撤防状态变化事件(对应结构体ALARM_ARMMODE_CHANGE_INFO)
#define DH_ALARM_BYPASSMODE_CHANGE_EVENT  0x3176           // 旁路状态变化事件(对应结构体ALARM_BYPASSMODE_CHANGE_INFO)
#define DH_ALARM_ACCESS_CTL_NOT_CLOSE     0x3177           // 门禁未关事件(对应结构体ALARM_ACCESS_CTL_NOT_CLOSE_INFO)
#define DH_ALARM_ACCESS_CTL_BREAK_IN      0x3178           // 闯入事件(对应结构体ALARM_ACCESS_CTL_BREAK_IN_INFO)
#define DH_ALARM_ACCESS_CTL_REPEAT_ENTER  0x3179           // 反复进入事件(对应结构体ALARM_ACCESS_CTL_REPEAT_ENTER_INFO)
#define DH_ALARM_ACCESS_CTL_DURESS        0x3180           // 胁迫卡刷卡事件(对应结构体ALARM_ACCESS_CTL_DURESS_INFO)
#define DH_ALARM_ACCESS_CTL_EVENT         0x3181           // 门禁事件(对应结构体ALARM_ACCESS_CTL_EVENT_INFO)
#define DH_URGENCY_ALARM_EX2              0x3182           // 紧急报警EX2(对DH_URGENCY_ALARM_EX的升级,对应结构体ALARM_URGENCY_ALARM_EX2, 人为触发的紧急事件, 一般处理是联动外部通讯功能请求帮助
#define DH_ALARM_INPUT_SOURCE_SIGNAL      0x3183           // 报警输入源信号事件(只要有输入就会产生该事件, 不论防区当前的模式，无法屏蔽, 对应ALARM_INPUT_SOURCE_SIGNAL_INFO)
#define DH_ALARM_ANALOGALARM_EVENT        0x3184           // 模拟量报警输入通道事件(对应结构体ALARM_ANALOGALARM_EVENT_INFO)
#define DH_ALARM_ACCESS_CTL_STATUS        0x3185           // 门禁状态事件(对应结构体ALARM_ACCESS_CTL_STATUS_INFO)
#define DH_ALARM_ACCESS_SNAP              0x3186           // 门禁抓图事件(对应结构体ALARM_ACCESS_SNAP_INFO)
#define DH_ALARM_ALARMCLEAR               0x3187           // 消警事件(对应结构体ALARM_ALARMCLEAR_INFO)
#define DH_ALARM_CIDEVENT                 0x3188           // CID事件(对应结构体ALARM_CIDEVENT_INFO)
#define DH_ALARM_TALKING_HANGUP           0x3189           // 设备主动挂断对讲事件(对应结构体ALARM_TALKING_HANGUP_INFO)


// 事件类型
#define DH_CONFIG_RESULT_EVENT_EX         0x3000           // 修改配置的返回码；返回结构见DEV_SET_RESULT
#define DH_REBOOT_EVENT_EX                0x3001           // 设备重启事件；如果未发送重启命令，当前修改的配置不会立即生效
#define DH_AUTO_TALK_START_EX             0x3002           // 设备主动邀请开始语音对讲
#define DH_AUTO_TALK_STOP_EX              0x3003           // 设备主动停止语音对讲
#define DH_CONFIG_CHANGE_EX               0x3004           // 设备配置发生改变
#define DH_IPSEARCH_EVENT_EX              0x3005           // IP搜索事件, 返回字符串格式如下:DevName::Manufacturer::MAC::IP::Port::DevType::POEPort::SubMask::GateWay&&DevName::Manufacturer::MAC::IP::Port::DevType::POEPort::SubMask::GateWay &&…
#define DH_AUTO_RECONNECT_FAILD           0x3006           // 自动重连失败事件
#define DH_REALPLAY_FAILD_EVENT           0x3007           // 监视失败事件,返回结构体DEV_PLAY_RESULT
#define DH_PLAYBACK_FAILD_EVENT           0x3008           // 回放失败事件,返回结构体DEV_PLAY_RESULT   
#define DH_IVS_TRAFFIC_REALFLOWINFO       0x3009           // 交通实时流量信息事件ALARM_IVS_TRAFFIC_REALFLOW_INFO
#define DH_DEVICE_ABORT_EVENT		      0x300a	       // 客户端被踢出, 对应结构体 DEV_CLIENT_ABORT_INFO

// 报警上传功能的报警类型，对应CLIENT_StartService接口、NEW_ALARM_UPLOAD结构体.
#define DH_UPLOAD_ALARM                   0x4000           // 外部报警            
#define DH_UPLOAD_MOTION_ALARM            0x4001           // 动态检测报警
#define DH_UPLOAD_VIDEOLOST_ALARM         0x4002           // 视频丢失报警
#define DH_UPLOAD_SHELTER_ALARM           0x4003           // 视频遮挡报警
#define DH_UPLOAD_SOUND_DETECT_ALARM      0x4004           // 音频检测报警
#define DH_UPLOAD_DISKFULL_ALARM          0x4005           // 硬盘满报警
#define DH_UPLOAD_DISKERROR_ALARM         0x4006           // 坏硬盘报警
#define DH_UPLOAD_ENCODER_ALARM           0x4007           // 编码器报警
#define DH_UPLOAD_DECODER_ALARM           0x400B           // 报警解码器报警
#define DH_UPLOAD_EVENT                   0x400C           // 定时上传的
#define DH_UPLOAD_IVS                     0x400D           // 智能报警, 对应结构体ALARM_UPLOAD_IVS_INFO
#define DH_UPLOAD_SMOKESENSOR_ALARM       0x400E           // 烟感报警, 对应结构体ALARM_UPLOAD_SMOKESENSOR_INFO
#define DH_UPLOAD_ALARM_EX                0x400F           // 外部报警扩展，对应结构体 ALARM_UPLOAD_ALARMEX_INFO 

// 异步接口回调类型
#define RESPONSE_DECODER_CTRL_TV          0x00000001       // 对应CLIENT_CtrlDecTVScreen接口
#define RESPONSE_DECODER_SWITCH_TV        0x00000002       // 对应CLIENT_SwitchDecTVEncoder接口
#define RESPONSE_DECODER_PLAYBACK         0x00000003       // 对应CLIENT_DecTVPlayback接口

#define RESPONSE_EXCHANGE_DATA            0X00000004       // 对应CLIENT_ExchangeData接口
#define RESPONSE_ASYN_QUERY_RECORDFILE    0X00000005       // 对应CLIENT_StartQueryRecordFile接口

// CLIENT_FileTransmit接口传输文件类型
#define DH_DEV_UPGRADEFILETRANS_START     0x0000           // 开始升级文件上传(对应结构体 DHDEV_UPGRADE_FILE_INFO)
#define DH_DEV_UPGRADEFILETRANS_SEND      0x0001           // 发送升级文件  
#define DH_DEV_UPGRADEFILETRANS_STOP      0x0002           // 停止发送升级文件
#define DH_DEV_BLACKWHITETRANS_START      0x0003           // 开始发送黑白名单(对应结构体DHDEV_BLACKWHITE_LIST_INFO)
#define DH_DEV_BLACKWHITETRANS_SEND       0x0004           // 发送黑白名单
#define DH_DEV_BLACKWHITETRANS_STOP       0x0005           // 停止发送黑白名单 
#define DH_DEV_BLACKWHITE_LOAD            0x0006           // 下载黑白名单(对应结构体DHDEV_LOAD_BLACKWHITE_LIST_INFO)
#define DH_DEV_BLACKWHITE_LOAD_STOP       0x0007           // 停止下载黑白名单
#define DH_DEV_FILETRANS_STOP             0x002B           // 停止文件上传
#define DH_DEV_FILETRANS_BURN             0x002C           // 刻录文件上传


// 分辨率列表，用于与分辨率掩码进行与、或操作
#define DH_CAPTURE_SIZE_D1                0x00000001
#define DH_CAPTURE_SIZE_HD1               0x00000002
#define DH_CAPTURE_SIZE_BCIF              0x00000004
#define DH_CAPTURE_SIZE_CIF               0x00000008
#define DH_CAPTURE_SIZE_QCIF              0x00000010    
#define DH_CAPTURE_SIZE_VGA               0x00000020    
#define DH_CAPTURE_SIZE_QVGA              0x00000040
#define DH_CAPTURE_SIZE_SVCD              0x00000080
#define DH_CAPTURE_SIZE_QQVGA             0x00000100
#define DH_CAPTURE_SIZE_SVGA              0x00000200
#define DH_CAPTURE_SIZE_XVGA              0x00000400
#define DH_CAPTURE_SIZE_WXGA              0x00000800
#define DH_CAPTURE_SIZE_SXGA              0x00001000
#define DH_CAPTURE_SIZE_WSXGA             0x00002000   
#define DH_CAPTURE_SIZE_UXGA              0x00004000
#define DH_CAPTURE_SIZE_WUXGA             0x00008000
#define DH_CAPTURE_SIZE_LFT               0x00010000
#define DH_CAPTURE_SIZE_720               0x00020000
#define DH_CAPTURE_SIZE_1080              0x00040000
#define DH_CAPTURE_SIZE_1_3M              0x00080000
#define DH_CAPTURE_SIZE_2M                0x00100000
#define DH_CAPTURE_SIZE_5M                0x00200000
#define DH_CAPTURE_SIZE_3M                0x00400000                
#define DH_CAPTURE_SIZE_5_0M              0x00800000
#define DH_CPTRUTE_SIZE_1_2M              0x01000000    
#define DH_CPTRUTE_SIZE_1408_1024         0x02000000    
#define DH_CPTRUTE_SIZE_8M                0x04000000    
#define DH_CPTRUTE_SIZE_2560_1920         0x08000000
#define DH_CAPTURE_SIZE_960H              0x10000000
#define DH_CAPTURE_SIZE_960_720           0x20000000

// 编码模式列表，用于与编码模式掩码进行与、或操作
#define DH_CAPTURE_COMP_DIVX_MPEG4        0x00000001
#define DH_CAPTURE_COMP_MS_MPEG4          0x00000002
#define DH_CAPTURE_COMP_MPEG2             0x00000004
#define DH_CAPTURE_COMP_MPEG1             0x00000008
#define DH_CAPTURE_COMP_H263              0x00000010
#define DH_CAPTURE_COMP_MJPG              0x00000020
#define DH_CAPTURE_COMP_FCC_MPEG4         0x00000040
#define DH_CAPTURE_COMP_H264              0x00000080

// 报警联动动作，用于与报警联动动作掩码进行与、或操作
#define DH_ALARM_UPLOAD                   0x00000001
#define DH_ALARM_RECORD                   0x00000002
#define DH_ALARM_PTZ                      0x00000004
#define DH_ALARM_MAIL                     0x00000008
#define DH_ALARM_TOUR                     0x00000010
#define DH_ALARM_TIP                      0x00000020
#define DH_ALARM_OUT                      0x00000040
#define DH_ALARM_FTP_UL                   0x00000080
#define DH_ALARM_BEEP                     0x00000100
#define DH_ALARM_VOICE                    0x00000200
#define DH_ALARM_SNAP                     0x00000400

// "恢复默认配置"掩码，可进行与、或操作
#define DH_RESTORE_COMMON                 0x00000001       // 普通设置
#define DH_RESTORE_CODING                 0x00000002       // 编码设置
#define DH_RESTORE_VIDEO                  0x00000004       // 录像设置
#define DH_RESTORE_COMM                   0x00000008       // 串口设置
#define DH_RESTORE_NETWORK                0x00000010       // 网络设置
#define DH_RESTORE_ALARM                  0x00000020       // 报警设置
#define DH_RESTORE_VIDEODETECT            0x00000040       // 视频检测
#define DH_RESTORE_PTZ                    0x00000080       // 云台控制
#define DH_RESTORE_OUTPUTMODE             0x00000100       // 输出模式
#define DH_RESTORE_CHANNELNAME            0x00000200       // 通道名称
#define DH_RESTORE_VIDEOINOPTIONS         0x00000400       // 摄像头属性
#define DH_RESTORE_CPS                    0x00000800       // 智能交通
#define DH_RESTORE_INTELLIGENT            0x00001000       // 视频分析
#define DH_RESTORE_REMOTEDEVICE           0x00002000       // 远程设备配置
#define DH_RESTORE_DECODERVIDEOOUT        0x00004000       // 解码轮巡
#define DH_RESTORE_LINKMODE               0x00008000       // 连接模式
#define DH_RESTORE_COMPOSITE              0x00010000       // 融合屏    
#define DH_RESTORE_ALL                    0x80000000       // 全部重置

// 云台属性列表--低四个字节掩码
#define PTZ_DIRECTION                     0x00000001       // 方向
#define PTZ_ZOOM                          0x00000002       // 变倍
#define PTZ_FOCUS                         0x00000004       // 聚焦
#define PTZ_IRIS                          0x00000008       // 光圈
#define PTZ_ALARM                         0x00000010       // 报警功能
#define PTZ_LIGHT                         0x00000020       // 灯光
#define PTZ_SETPRESET                     0x00000040       // 设置预置点
#define PTZ_CLEARPRESET                   0x00000080       // 清除预置点
#define PTZ_GOTOPRESET                    0x00000100       // 转至预置点
#define PTZ_AUTOPANON                     0x00000200       // 水平开始
#define PTZ_AUTOPANOFF                    0x00000400       // 水平结束
#define PTZ_SETLIMIT                      0x00000800       // 设置边界
#define PTZ_AUTOSCANON                    0x00001000       // 自动扫描开始
#define PTZ_AUTOSCANOFF                   0x00002000       // 自动扫描开停止
#define PTZ_ADDTOUR                       0x00004000       // 增加巡航点
#define PTZ_DELETETOUR                    0x00008000       // 删除巡航点
#define PTZ_STARTTOUR                     0x00010000       // 开始巡航
#define PTZ_STOPTOUR                      0x00020000       // 结束巡航
#define PTZ_CLEARTOUR                     0x00040000       // 删除巡航
#define PTZ_SETPATTERN                    0x00080000       // 设置模式
#define PTZ_STARTPATTERN                  0x00100000       // 开始模式
#define PTZ_STOPPATTERN                   0x00200000       // 停止模式
#define PTZ_CLEARPATTERN                  0x00400000       // 清除模式
#define PTZ_POSITION                      0x00800000       // 快速定位
#define PTZ_AUX                           0x01000000       // 辅助开关
#define PTZ_MENU                          0x02000000       // 球机菜单
#define PTZ_EXIT                          0x04000000       // 退出球机菜单
#define PTZ_ENTER                         0x08000000       // 确认
#define PTZ_ESC                           0x10000000       // 取消
#define PTZ_MENUUPDOWN                    0x20000000       // 菜单上下操作
#define PTZ_MENULEFTRIGHT                 0x40000000       // 菜单左右操作
#define PTZ_OPT_NUM                       0x80000000       // 操作的个数

// 高四个字节掩码
#define PTZ_DEV                           0x00000001       // 云台控制
#define PTZ_MATRIX                        0x00000002       // 矩阵控制

// 抓图视频编码类型
#define CODETYPE_MPEG4                    0
#define CODETYPE_H264                     1
#define CODETYPE_JPG                      2

// 码流控制列表
#define DH_CAPTURE_BRC_CBR                0
#define DH_CAPTURE_BRC_VBR                1
//#define DH_CAPTURE_BRC_MBR              2

// 帧类型掩码定义
#define FRAME_TYPE_MOTION                       0x00000001       // 动检帧

// 智能分析事件类型
#define EVENT_IVS_ALL                           0x00000001        // 订阅所有事件
#define EVENT_IVS_CROSSLINEDETECTION            0x00000002        // 警戒线事件
#define EVENT_IVS_CROSSREGIONDETECTION          0x00000003        // 警戒区事件
#define EVENT_IVS_PASTEDETECTION                0x00000004        // 贴条事件
#define EVENT_IVS_LEFTDETECTION                 0x00000005        // 物品遗留事件
#define EVENT_IVS_STAYDETECTION                 0x00000006        // 停留事件
#define EVENT_IVS_WANDERDETECTION               0x00000007        // 徘徊事件
#define EVENT_IVS_PRESERVATION                  0x00000008        // 物品保全事件
#define EVENT_IVS_MOVEDETECTION                 0x00000009        // 移动事件
#define EVENT_IVS_TAILDETECTION                 0x0000000A        // 尾随事件
#define EVENT_IVS_RIOTERDETECTION               0x0000000B        // 聚众事件
#define EVENT_IVS_FIREDETECTION                 0x0000000C        // 火警事件
#define EVENT_IVS_SMOKEDETECTION                0x0000000D        // 烟雾报警事件
#define EVENT_IVS_FIGHTDETECTION                0x0000000E        // 斗殴事件
#define EVENT_IVS_FLOWSTAT                      0x0000000F        // 流量统计事件
#define EVENT_IVS_NUMBERSTAT                    0x00000010        // 数量统计事件
#define EVENT_IVS_CAMERACOVERDDETECTION         0x00000011        // 摄像头覆盖事件
#define EVENT_IVS_CAMERAMOVEDDETECTION          0x00000012        // 摄像头移动事件
#define EVENT_IVS_VIDEOABNORMALDETECTION        0x00000013        // 视频异常事件
#define EVENT_IVS_VIDEOBADDETECTION             0x00000014        // 视频损坏事件
#define EVENT_IVS_TRAFFICCONTROL                0x00000015        // 交通管制事件
#define EVENT_IVS_TRAFFICACCIDENT               0x00000016        // 交通事故事件
#define EVENT_IVS_TRAFFICJUNCTION               0x00000017        // 交通路口事件----老规则
#define EVENT_IVS_TRAFFICGATE                   0x00000018        // 交通卡口事件----老规则
#define EVENT_TRAFFICSNAPSHOT                   0x00000019        // 交通抓拍事件
#define EVENT_IVS_FACEDETECT                    0x0000001A        // 人脸检测事件 
#define EVENT_IVS_TRAFFICJAM                    0x0000001B        // 交通拥堵事件
#define EVENT_IVS_TRAFFIC_RUNREDLIGHT           0x00000100        // 交通违章-闯红灯事件
#define EVENT_IVS_TRAFFIC_OVERLINE              0x00000101        // 交通违章-压车道线事件
#define EVENT_IVS_TRAFFIC_RETROGRADE            0x00000102        // 交通违章-逆行事件
#define EVENT_IVS_TRAFFIC_TURNLEFT              0x00000103        // 交通违章-违章左转
#define EVENT_IVS_TRAFFIC_TURNRIGHT             0x00000104        // 交通违章-违章右转
#define EVENT_IVS_TRAFFIC_UTURN                 0x00000105        // 交通违章-违章掉头
#define EVENT_IVS_TRAFFIC_OVERSPEED             0x00000106        // 交通违章-超速
#define EVENT_IVS_TRAFFIC_UNDERSPEED            0x00000107        // 交通违章-低速
#define EVENT_IVS_TRAFFIC_PARKING               0x00000108        // 交通违章-违章停车
#define EVENT_IVS_TRAFFIC_WRONGROUTE            0x00000109        // 交通违章-不按车道行驶
#define EVENT_IVS_TRAFFIC_CROSSLANE             0x0000010A        // 交通违章-违章变道
#define EVENT_IVS_TRAFFIC_OVERYELLOWLINE        0x0000010B        // 交通违章-压黄线 
#define EVENT_IVS_TRAFFIC_DRIVINGONSHOULDER     0x0000010C        // 交通违章-路肩行驶事件   
#define EVENT_IVS_TRAFFIC_YELLOWPLATEINLANE     0x0000010E        // 交通违章-黄牌车占道事件
#define EVENT_IVS_TRAFFIC_PEDESTRAINPRIORITY    0x0000010F        // 交通违章-斑马线行人优先事件
#define EVENT_IVS_CROSSFENCEDETECTION           0x0000011F        // 翻越围栏事件
#define EVENT_IVS_ELECTROSPARKDETECTION         0X00000110        // 电火花事件
#define EVENT_IVS_TRAFFIC_NOPASSING             0x00000111        // 交通违章-禁止通行事件
#define EVENT_IVS_ABNORMALRUNDETECTION          0x00000112        // 异常奔跑事件
#define EVENT_IVS_RETROGRADEDETECTION           0x00000113        // 人员逆行事件
#define EVENT_IVS_INREGIONDETECTION             0x00000114        // 区域内检测事件
#define EVENT_IVS_TAKENAWAYDETECTION            0x00000115        // 物品搬移事件
#define EVENT_IVS_PARKINGDETECTION              0x00000116        // 非法停车事件
#define EVENT_IVS_FACERECOGNITION               0x00000117        // 人脸识别事件
#define EVENT_IVS_TRAFFIC_MANUALSNAP            0x00000118        // 交通手动抓拍事件
#define EVENT_IVS_TRAFFIC_FLOWSTATE             0x00000119        // 交通流量统计事件
#define EVENT_IVS_TRAFFIC_STAY                  0x0000011A        // 交通滞留事件
#define EVENT_IVS_TRAFFIC_VEHICLEINROUTE        0x0000011B        // 有车占道事件
#define EVENT_ALARM_MOTIONDETECT                0x0000011C        // 视频移动侦测事件
#define EVENT_ALARM_LOCALALARM                  0x0000011D        // 外部报警事件
#define EVENT_IVS_PRISONERRISEDETECTION         0X0000011E        // 看守所囚犯起身事件
#define EVENT_IVS_TRAFFIC_TOLLGATE              0X00000120        // 交通违章-卡口事件----新规则
#define EVENT_IVS_DENSITYDETECTION              0x00000121        // 人员密集度检测
#define EVENT_IVS_VIDEODIAGNOSIS                0X00000122        // 视频诊断结果事件
#define EVENT_IVS_QUEUEDETECTION                0x00000123        // 排队检测报警事件
#define EVENT_IVS_TRAFFIC_VEHICLEINBUSROUTE     0x00000124        // 占用公交车道事件
#define EVENT_IVS_TRAFFIC_BACKING               0x00000125        // 违章倒车事件
#define EVENT_IVS_AUDIO_ABNORMALDETECTION       0x00000126        // 声音异常检测
#define EVENT_IVS_TRAFFIC_RUNYELLOWLIGHT        0x00000127        // 交通违章-闯黄灯事件
#define EVENT_IVS_CLIMBDETECTION                0x00000128        // 攀高检测事件
#define EVENT_IVS_LEAVEDETECTION                0x00000129        // 离岗检测事件
#define EVENT_IVS_TRAFFIC_PARKINGONYELLOWBOX    0x0000012A        // 黄网格线抓拍事件
#define EVENT_IVS_TRAFFIC_PARKINGSPACEPARKING   0x0000012B        // 车位有车事件
#define EVENT_IVS_TRAFFIC_PARKINGSPACENOPARKING 0x0000012C        // 车位无车事件    
#define EVENT_IVS_TRAFFIC_PEDESTRAIN            0x0000012D        // 交通行人事件
#define EVENT_IVS_TRAFFIC_THROW                 0x0000012E        // 交通抛洒物品事件
#define EVENT_IVS_TRAFFIC_IDLE                  0x0000012F        // 交通空闲事件
#define EVENT_ALARM_VEHICLEACC                  0x00000130        // 车载ACC断电报警事件
#define EVENT_ALARM_VEHICLE_TURNOVER            0x00000131        // 车辆侧翻报警事件
#define EVENT_ALARM_VEHICLE_COLLISION           0x00000132        // 车辆撞车报警事件
#define EVENT_ALARM_VEHICLE_LARGE_ANGLE         0x00000133        // 车载摄像头大角度扭转事件
#define EVENT_IVS_TRAFFIC_PARKINGSPACEOVERLINE  0x00000134        // 车位压线事件
#define EVENT_IVS_MULTISCENESWITCH              0x00000135        // 多场景切换事件
#define EVENT_IVS_TRAFFIC_RESTRICTED_PLATE      0X00000136        // 受限车牌事件
#define EVENT_ALARM_ANALOGALARM                 0x00000150        // 模拟量报警通道的报警事件(对应DEV_EVENT_ALARM_ANALOGALRM_INFO)


#define EVENT_IVS_TRAFFIC_ALL                   0x000001FF        // 所有以traffic开头的事件，目前指的是
                                                                  // EVENT_IVS_TRAFFICCONTROL -> EVENT_TRAFFICSNAPSHOT
                                                                  // EVENT_IVS_TRAFFIC_RUNREDLIGHT -> EVENT_IVS_TRAFFIC_UNDERSPEED
#define EVENT_IVS_VIDEOANALYSE                  0x00000200        // 所有智能分析事件 

//流量统计事件使用宏
#define FLOWSTAT_ADDR_NAME                      16                //上下行地点名长

//针对接口CLIENT_OperateTrafficList各类字符串长度定义
#define DH_TARFFIC_NAME_LEN                     16                
#define DH_CREATE_TIME_LEN                      32
#define DH_AUTHORITY_NUM                        16


// 错误类型代号，对应CLIENT_GetLastError接口的返回值
#define _EC(x)                                  (0x80000000|x)
#define NET_NOERROR                             0                 // 没有错误
#define NET_ERROR                               -1                // 未知错误
#define NET_SYSTEM_ERROR                        _EC(1)            // Windows系统出错
#define NET_NETWORK_ERROR                       _EC(2)            // 网络错误，可能是因为网络超时
#define NET_DEV_VER_NOMATCH                     _EC(3)            // 设备协议不匹配
#define NET_INVALID_HANDLE                      _EC(4)            // 句柄无效
#define NET_OPEN_CHANNEL_ERROR                  _EC(5)            // 打开通道失败
#define NET_CLOSE_CHANNEL_ERROR                 _EC(6)            // 关闭通道失败
#define NET_ILLEGAL_PARAM                       _EC(7)            // 用户参数不合法
#define NET_SDK_INIT_ERROR                      _EC(8)            // SDK初始化出错
#define NET_SDK_UNINIT_ERROR                    _EC(9)            // SDK清理出错
#define NET_RENDER_OPEN_ERROR                   _EC(10)           // 申请render资源出错
#define NET_DEC_OPEN_ERROR                      _EC(11)           // 打开解码库出错
#define NET_DEC_CLOSE_ERROR                     _EC(12)           // 关闭解码库出错
#define NET_MULTIPLAY_NOCHANNEL                 _EC(13)           // 多画面预览中检测到通道数为0
#define NET_TALK_INIT_ERROR                     _EC(14)           // 录音库初始化失败
#define NET_TALK_NOT_INIT                       _EC(15)           // 录音库未经初始化
#define NET_TALK_SENDDATA_ERROR                 _EC(16)           // 发送音频数据出错
#define NET_REAL_ALREADY_SAVING                 _EC(17)           // 实时数据已经处于保存状态
#define NET_NOT_SAVING                          _EC(18)           // 未保存实时数据
#define NET_OPEN_FILE_ERROR                     _EC(19)           // 打开文件出错
#define NET_PTZ_SET_TIMER_ERROR                 _EC(20)           // 启动云台控制定时器失败
#define NET_RETURN_DATA_ERROR                   _EC(21)           // 对返回数据的校验出错
#define NET_INSUFFICIENT_BUFFER                 _EC(22)           // 没有足够的缓存
#define NET_NOT_SUPPORTED                       _EC(23)           // 当前SDK未支持该功能
#define NET_NO_RECORD_FOUND                     _EC(24)           // 查询不到录象
#define NET_NOT_AUTHORIZED                      _EC(25)           // 无操作权限
#define NET_NOT_NOW                             _EC(26)           // 暂时无法执行
#define NET_NO_TALK_CHANNEL                     _EC(27)           // 未发现对讲通道
#define NET_NO_AUDIO                            _EC(28)           // 未发现音频
#define NET_NO_INIT                             _EC(29)           // 网络SDK未经初始化
#define NET_DOWNLOAD_END                        _EC(30)           // 下载已结束
#define NET_EMPTY_LIST                          _EC(31)           // 查询结果为空
#define NET_ERROR_GETCFG_SYSATTR                _EC(32)           // 获取系统属性配置失败
#define NET_ERROR_GETCFG_SERIAL                 _EC(33)           // 获取序列号失败
#define NET_ERROR_GETCFG_GENERAL                _EC(34)           // 获取常规属性失败
#define NET_ERROR_GETCFG_DSPCAP                 _EC(35)           // 获取DSP能力描述失败
#define NET_ERROR_GETCFG_NETCFG                 _EC(36)           // 获取网络配置失败
#define NET_ERROR_GETCFG_CHANNAME               _EC(37)           // 获取通道名称失败
#define NET_ERROR_GETCFG_VIDEO                  _EC(38)           // 获取视频属性失败
#define NET_ERROR_GETCFG_RECORD                 _EC(39)           // 获取录象配置失败
#define NET_ERROR_GETCFG_PRONAME                _EC(40)           // 获取解码器协议名称失败
#define NET_ERROR_GETCFG_FUNCNAME               _EC(41)           // 获取232串口功能名称失败
#define NET_ERROR_GETCFG_485DECODER             _EC(42)           // 获取解码器属性失败
#define NET_ERROR_GETCFG_232COM                 _EC(43)           // 获取232串口配置失败
#define NET_ERROR_GETCFG_ALARMIN                _EC(44)           // 获取外部报警输入配置失败
#define NET_ERROR_GETCFG_ALARMDET               _EC(45)           // 获取动态检测报警失败
#define NET_ERROR_GETCFG_SYSTIME                _EC(46)           // 获取设备时间失败
#define NET_ERROR_GETCFG_PREVIEW                _EC(47)           // 获取预览参数失败
#define NET_ERROR_GETCFG_AUTOMT                 _EC(48)           // 获取自动维护配置失败
#define NET_ERROR_GETCFG_VIDEOMTRX              _EC(49)           // 获取视频矩阵配置失败
#define NET_ERROR_GETCFG_COVER                  _EC(50)           // 获取区域遮挡配置失败
#define NET_ERROR_GETCFG_WATERMAKE              _EC(51)           // 获取图象水印配置失败
#define NET_ERROR_GETCFG_MULTICAST	            _EC(52)			  // 获取配置失败位置：组播端口按通道配置
#define NET_ERROR_SETCFG_GENERAL                _EC(55)           // 修改常规属性失败
#define NET_ERROR_SETCFG_NETCFG                 _EC(56)           // 修改网络配置失败
#define NET_ERROR_SETCFG_CHANNAME               _EC(57)           // 修改通道名称失败
#define NET_ERROR_SETCFG_VIDEO                  _EC(58)           // 修改视频属性失败
#define NET_ERROR_SETCFG_RECORD                 _EC(59)           // 修改录象配置失败
#define NET_ERROR_SETCFG_485DECODER             _EC(60)           // 修改解码器属性失败
#define NET_ERROR_SETCFG_232COM                 _EC(61)           // 修改232串口配置失败
#define NET_ERROR_SETCFG_ALARMIN                _EC(62)           // 修改外部输入报警配置失败
#define NET_ERROR_SETCFG_ALARMDET               _EC(63)           // 修改动态检测报警配置失败
#define NET_ERROR_SETCFG_SYSTIME                _EC(64)           // 修改设备时间失败
#define NET_ERROR_SETCFG_PREVIEW                _EC(65)           // 修改预览参数失败
#define NET_ERROR_SETCFG_AUTOMT                 _EC(66)           // 修改自动维护配置失败
#define NET_ERROR_SETCFG_VIDEOMTRX              _EC(67)           // 修改视频矩阵配置失败
#define NET_ERROR_SETCFG_COVER                  _EC(68)           // 修改区域遮挡配置失败
#define NET_ERROR_SETCFG_WATERMAKE              _EC(69)           // 修改图象水印配置失败
#define NET_ERROR_SETCFG_WLAN                   _EC(70)           // 修改无线网络信息失败
#define NET_ERROR_SETCFG_WLANDEV                _EC(71)           // 选择无线网络设备失败
#define NET_ERROR_SETCFG_REGISTER               _EC(72)           // 修改主动注册参数配置失败
#define NET_ERROR_SETCFG_CAMERA                 _EC(73)           // 修改摄像头属性配置失败
#define NET_ERROR_SETCFG_INFRARED               _EC(74)           // 修改红外报警配置失败
#define NET_ERROR_SETCFG_SOUNDALARM             _EC(75)           // 修改音频报警配置失败
#define NET_ERROR_SETCFG_STORAGE                _EC(76)           // 修改存储位置配置失败
#define NET_AUDIOENCODE_NOTINIT                 _EC(77)           // 音频编码接口没有成功初始化
#define NET_DATA_TOOLONGH                       _EC(78)           // 数据过长
#define NET_UNSUPPORTED                         _EC(79)           // 设备不支持该操作
#define NET_DEVICE_BUSY                         _EC(80)           // 设备资源不足
#define NET_SERVER_STARTED                      _EC(81)           // 服务器已经启动
#define NET_SERVER_STOPPED                      _EC(82)           // 服务器尚未成功启动
#define NET_LISTER_INCORRECT_SERIAL             _EC(83)           // 输入序列号有误
#define NET_QUERY_DISKINFO_FAILED               _EC(84)           // 获取硬盘信息失败
#define NET_ERROR_GETCFG_SESSION                _EC(85)           // 获取连接Session信息
#define NET_USER_FLASEPWD_TRYTIME               _EC(86)           // 输入密码错误超过限制次数
#define NET_LOGIN_ERROR_PASSWORD                _EC(100)          // 密码不正确
#define NET_LOGIN_ERROR_USER                    _EC(101)          // 帐户不存在
#define NET_LOGIN_ERROR_TIMEOUT                 _EC(102)          // 等待登录返回超时
#define NET_LOGIN_ERROR_RELOGGIN                _EC(103)          // 帐号已登录
#define NET_LOGIN_ERROR_LOCKED                  _EC(104)          // 帐号已被锁定
#define NET_LOGIN_ERROR_BLACKLIST               _EC(105)          // 帐号已被列为黑名单
#define NET_LOGIN_ERROR_BUSY                    _EC(106)          // 资源不足，系统忙
#define NET_LOGIN_ERROR_CONNECT                 _EC(107)          // 登录设备超时，请检查网络并重试
#define NET_LOGIN_ERROR_NETWORK                 _EC(108)          // 网络连接失败
#define NET_LOGIN_ERROR_SUBCONNECT              _EC(109)          // 登录设备成功，但无法创建视频通道，请检查网络状况
#define NET_LOGIN_ERROR_MAXCONNECT              _EC(110)          // 超过最大连接数
#define NET_LOGIN_ERROR_PROTOCOL3_ONLY          _EC(111)          // 只支持3代协议
#define NET_LOGIN_ERROR_UKEY_LOST               _EC(112)          // 未插入U盾或U盾信息错误
#define NET_LOGIN_ERROR_NO_AUTHORIZED           _EC(113)          // 客户端IP地址没有登录权限  
#define NET_RENDER_SOUND_ON_ERROR               _EC(120)          // Render库打开音频出错
#define NET_RENDER_SOUND_OFF_ERROR              _EC(121)          // Render库关闭音频出错
#define NET_RENDER_SET_VOLUME_ERROR             _EC(122)          // Render库控制音量出错
#define NET_RENDER_ADJUST_ERROR                 _EC(123)          // Render库设置画面参数出错
#define NET_RENDER_PAUSE_ERROR                  _EC(124)          // Render库暂停播放出错
#define NET_RENDER_SNAP_ERROR                   _EC(125)          // Render库抓图出错
#define NET_RENDER_STEP_ERROR                   _EC(126)          // Render库步进出错
#define NET_RENDER_FRAMERATE_ERROR              _EC(127)          // Render库设置帧率出错
#define NET_RENDER_DISPLAYREGION_ERROR          _EC(128)          // Render库设置显示区域出错
#define NET_GROUP_EXIST                         _EC(140)          // 组名已存在
#define NET_GROUP_NOEXIST                       _EC(141)          // 组名不存在
#define NET_GROUP_RIGHTOVER                     _EC(142)          // 组的权限超出权限列表范围
#define NET_GROUP_HAVEUSER                      _EC(143)          // 组下有用户，不能删除
#define NET_GROUP_RIGHTUSE                      _EC(144)          // 组的某个权限被用户使用，不能出除
#define NET_GROUP_SAMENAME                      _EC(145)          // 新组名同已有组名重复
#define NET_USER_EXIST                          _EC(146)          // 用户已存在
#define NET_USER_NOEXIST                        _EC(147)          // 用户不存在
#define NET_USER_RIGHTOVER                      _EC(148)          // 用户权限超出组权限
#define NET_USER_PWD                            _EC(149)          // 保留帐号，不容许修改密码
#define NET_USER_FLASEPWD                       _EC(150)          // 密码不正确
#define NET_USER_NOMATCHING                     _EC(151)          // 密码不匹配
#define NET_USER_INUSE                          _EC(152)          // 账号正在使用中
#define NET_ERROR_GETCFG_ETHERNET               _EC(300)          // 获取网卡配置失败
#define NET_ERROR_GETCFG_WLAN                   _EC(301)          // 获取无线网络信息失败
#define NET_ERROR_GETCFG_WLANDEV                _EC(302)          // 获取无线网络设备失败
#define NET_ERROR_GETCFG_REGISTER               _EC(303)          // 获取主动注册参数失败
#define NET_ERROR_GETCFG_CAMERA                 _EC(304)          // 获取摄像头属性失败
#define NET_ERROR_GETCFG_INFRARED               _EC(305)          // 获取红外报警配置失败
#define NET_ERROR_GETCFG_SOUNDALARM             _EC(306)          // 获取音频报警配置失败
#define NET_ERROR_GETCFG_STORAGE                _EC(307)          // 获取存储位置配置失败
#define NET_ERROR_GETCFG_MAIL                   _EC(308)          // 获取邮件配置失败
#define NET_CONFIG_DEVBUSY                      _EC(309)          // 暂时无法设置
#define NET_CONFIG_DATAILLEGAL                  _EC(310)          // 配置数据不合法
#define NET_ERROR_GETCFG_DST                    _EC(311)          // 获取夏令时配置失败
#define NET_ERROR_SETCFG_DST                    _EC(312)          // 设置夏令时配置失败
#define NET_ERROR_GETCFG_VIDEO_OSD              _EC(313)          // 获取视频OSD叠加配置失败
#define NET_ERROR_SETCFG_VIDEO_OSD              _EC(314)          // 设置视频OSD叠加配置失败
#define NET_ERROR_GETCFG_GPRSCDMA               _EC(315)          // 获取CDMA\GPRS网络配置失败
#define NET_ERROR_SETCFG_GPRSCDMA               _EC(316)          // 设置CDMA\GPRS网络配置失败
#define NET_ERROR_GETCFG_IPFILTER               _EC(317)          // 获取IP过滤配置失败
#define NET_ERROR_SETCFG_IPFILTER               _EC(318)          // 设置IP过滤配置失败
#define NET_ERROR_GETCFG_TALKENCODE             _EC(319)          // 获取语音对讲编码配置失败
#define NET_ERROR_SETCFG_TALKENCODE             _EC(320)          // 设置语音对讲编码配置失败
#define NET_ERROR_GETCFG_RECORDLEN              _EC(321)          // 获取录像打包长度配置失败
#define NET_ERROR_SETCFG_RECORDLEN              _EC(322)          // 设置录像打包长度配置失败
#define NET_DONT_SUPPORT_SUBAREA                _EC(323)          // 不支持网络硬盘分区
#define NET_ERROR_GET_AUTOREGSERVER             _EC(324)          // 获取设备上主动注册服务器信息失败
#define NET_ERROR_CONTROL_AUTOREGISTER          _EC(325)          // 主动注册重定向注册错误
#define NET_ERROR_DISCONNECT_AUTOREGISTER       _EC(326)          // 断开主动注册服务器错误
#define NET_ERROR_GETCFG_MMS                    _EC(327)          // 获取mms配置失败
#define NET_ERROR_SETCFG_MMS                    _EC(328)          // 设置mms配置失败
#define NET_ERROR_GETCFG_SMSACTIVATION          _EC(329)          // 获取短信激活无线连接配置失败
#define NET_ERROR_SETCFG_SMSACTIVATION          _EC(330)          // 设置短信激活无线连接配置失败
#define NET_ERROR_GETCFG_DIALINACTIVATION       _EC(331)          // 获取拨号激活无线连接配置失败
#define NET_ERROR_SETCFG_DIALINACTIVATION       _EC(332)          // 设置拨号激活无线连接配置失败
#define NET_ERROR_GETCFG_VIDEOOUT               _EC(333)          // 查询视频输出参数配置失败
#define NET_ERROR_SETCFG_VIDEOOUT               _EC(334)          // 设置视频输出参数配置失败
#define NET_ERROR_GETCFG_OSDENABLE              _EC(335)          // 获取osd叠加使能配置失败
#define NET_ERROR_SETCFG_OSDENABLE              _EC(336)          // 设置osd叠加使能配置失败
#define NET_ERROR_SETCFG_ENCODERINFO            _EC(337)          // 设置数字通道前端编码接入配置失败
#define NET_ERROR_GETCFG_TVADJUST               _EC(338)          // 获取TV调节配置失败
#define NET_ERROR_SETCFG_TVADJUST               _EC(339)          // 设置TV调节配置失败
#define NET_ERROR_CONNECT_FAILED                _EC(340)          // 请求建立连接失败
#define NET_ERROR_SETCFG_BURNFILE               _EC(341)          // 请求刻录文件上传失败
#define NET_ERROR_SNIFFER_GETCFG                _EC(342)          // 获取抓包配置信息失败
#define NET_ERROR_SNIFFER_SETCFG                _EC(343)          // 设置抓包配置信息失败
#define NET_ERROR_DOWNLOADRATE_GETCFG           _EC(344)          // 查询下载限制信息失败
#define NET_ERROR_DOWNLOADRATE_SETCFG           _EC(345)          // 设置下载限制信息失败
#define NET_ERROR_SEARCH_TRANSCOM               _EC(346)          // 查询串口参数失败
#define NET_ERROR_GETCFG_POINT                  _EC(347)          // 获取预制点信息错误
#define NET_ERROR_SETCFG_POINT                  _EC(348)          // 设置预制点信息错误
#define NET_SDK_LOGOUT_ERROR                    _EC(349)          // SDK没有正常登出设备
#define NET_ERROR_GET_VEHICLE_CFG               _EC(350)          // 获取车载配置失败
#define NET_ERROR_SET_VEHICLE_CFG               _EC(351)          // 设置车载配置失败
#define NET_ERROR_GET_ATM_OVERLAY_CFG           _EC(352)          // 获取atm叠加配置失败
#define NET_ERROR_SET_ATM_OVERLAY_CFG           _EC(353)          // 设置atm叠加配置失败
#define NET_ERROR_GET_ATM_OVERLAY_ABILITY       _EC(354)          // 获取atm叠加能力失败
#define NET_ERROR_GET_DECODER_TOUR_CFG          _EC(355)          // 获取解码器解码轮巡配置失败
#define NET_ERROR_SET_DECODER_TOUR_CFG          _EC(356)          // 设置解码器解码轮巡配置失败
#define NET_ERROR_CTRL_DECODER_TOUR             _EC(357)          // 控制解码器解码轮巡失败
#define NET_GROUP_OVERSUPPORTNUM                _EC(358)          // 超出设备支持最大用户组数目
#define NET_USER_OVERSUPPORTNUM                 _EC(359)          // 超出设备支持最大用户数目
#define NET_ERROR_GET_SIP_CFG                   _EC(368)          // 获取SIP配置失败
#define NET_ERROR_SET_SIP_CFG                   _EC(369)          // 设置SIP配置失败
#define NET_ERROR_GET_SIP_ABILITY               _EC(370)          // 获取SIP能力失败
#define NET_ERROR_GET_WIFI_AP_CFG               _EC(371)          // 获取WIFI ap配置失败
#define NET_ERROR_SET_WIFI_AP_CFG               _EC(372)          // 设置WIFI ap配置失败
#define NET_ERROR_GET_DECODE_POLICY             _EC(373)          // 获取解码策略配置失败
#define NET_ERROR_SET_DECODE_POLICY             _EC(374)          // 设置解码策略配置失败
#define NET_ERROR_TALK_REJECT                   _EC(375)          // 拒绝对讲
#define NET_ERROR_TALK_OPENED                   _EC(376)          // 对讲被其他客户端打开
#define NET_ERROR_TALK_RESOURCE_CONFLICIT       _EC(377)          // 资源冲突
#define NET_ERROR_TALK_UNSUPPORTED_ENCODE       _EC(378)          // 不支持的语音编码格式
#define NET_ERROR_TALK_RIGHTLESS                _EC(379)          // 无权限
#define NET_ERROR_TALK_FAILED                   _EC(380)          // 请求对讲失败
#define NET_ERROR_GET_MACHINE_CFG               _EC(381)          // 获取机器相关配置失败
#define NET_ERROR_SET_MACHINE_CFG               _EC(382)          // 设置机器相关配置失败
#define NET_ERROR_GET_DATA_FAILED               _EC(383)          // 设备无法获取当前请求数据
#define NET_ERROR_MAC_VALIDATE_FAILED           _EC(384)          // MAC地址验证失败 
#define NET_ERROR_GET_INSTANCE                  _EC(385)          // 获取服务器实例失败
#define NET_ERROR_JSON_REQUEST                  _EC(386)          // 生成的jason字符串错误
#define NET_ERROR_JSON_RESPONSE                 _EC(387)          // 响应的jason字符串错误
#define NET_ERROR_VERSION_HIGHER                _EC(388)          // 协议版本低于当前使用的版本
#define NET_SPARE_NO_CAPACITY                   _EC(389)          // 热备操作失败, 容量不足
#define NET_ERROR_SOURCE_IN_USE                 _EC(390)          // 显示源被其他输出占用
#define NET_ERROR_REAVE                         _EC(391)          // 高级用户抢占低级用户资源
#define NET_ERROR_NETFORBID                     _EC(392)          // 禁止入网 
#define NET_ERROR_GETCFG_MACFILTER              _EC(393)          // 获取MAC过滤配置失败
#define NET_ERROR_SETCFG_MACFILTER              _EC(394)          // 设置MAC过滤配置失败
#define NET_ERROR_GETCFG_IPMACFILTER            _EC(395)          // 获取IP/MAC过滤配置失败
#define NET_ERROR_SETCFG_IPMACFILTER            _EC(396)          // 设置IP/MAC过滤配置失败
#define NET_ERROR_OPERATION_OVERTIME            _EC(397)          // 当前操作超时 
#define NET_ERROR_SENIOR_VALIDATE_FAILED        _EC(398)          // 高级校验失败 
#define NET_ERROR_DEVICE_ID_NOT_EXIST           _EC(399)          // 设备ID不存在
#define NET_ERROR_UNSUPPORTED                   _EC(400)          // 不支持当前操作
#define NET_ERROR_PROXY_DLLLOAD                 _EC(401)          // 代理库加载失败
#define NET_ERROR_PROXY_ILLEGAL_PARAM           _EC(402)          // 代理用户参数不合法
#define NET_ERROR_PROXY_INVALID_HANDLE          _EC(403)          // 代理句柄无效
#define NET_ERROR_PROXY_LOGIN_DEVICE_ERROR      _EC(404)          // 代理登入前端设备失败
#define NET_ERROR_PROXY_START_SERVER_ERROR      _EC(405)          // 启动代理服务失败
#define NET_ERROR_SPEAK_FAILED                  _EC(406)          // 请求喊话失败
#define NET_ERROR_NOT_SUPPORT_F6                _EC(407)          // 设备不支持此F6接口调用
#define NET_ERROR_CD_UNREADY                    _EC(408)          // 光盘未就绪
#define NET_ERROR_DIR_NOT_EXIST                 _EC(409)          // 目录不存在
#define NET_ERROR_UNSUPPORTED_SPLIT_MODE        _EC(410)          // 设备不支持的分割模式
#define NET_ERROR_OPEN_WND_PARAM                _EC(411)          // 开窗参数不合法
#define NET_ERROR_LIMITED_WND_COUNT             _EC(412)          // 开窗数量超过限制
#define NET_ERROR_UNMATCHED_REQUEST             _EC(413)          // 请求命令与当前模式不匹配
#define NET_RENDER_ENABLELARGEPICADJUSTMENT_ERROR _EC(414)        // Render库启用高清图像内部调整策略出错
#define NET_ERROR_UPGRADE_FAILED                _EC(415)          // 设备升级失败
#define NET_ERROR_NO_TARGET_DEVICE              _EC(416)          // 找不到目标设备
#define NET_ERROR_NO_VERIFY_DEVICE              _EC(417)          // 找不到验证设备
#define NET_ERROR_CASCADE_RIGHTLESS             _EC(418)          // 无级联权限
#define NET_ERROR_LOW_PRIORITY                  _EC(419)          // 低优先级
#define NET_ERROR_REMOTE_REQUEST_TIMEOUT        _EC(420)          // 远程设备请求超时
#define NET_ERROR_LIMITED_INPUT_SOURCE          _EC(421)          // 输入源超出最大路数限制
#define NET_ERROR_SET_LOG_PRINT_INFO            _EC(422)          // 设置日志打印失败

#define NET_ERROR_VISITE_FILE                   _EC(510)          // 访问文件失败
#define NET_ERROR_DEVICE_STATUS_BUSY            _EC(511)          // 设备忙

/************************************************************************
 ** 枚举定义
 ***********************************************************************/
//获取网卡信息类型 CLIENT_QueryNetStat  接口使用
enum EM_NET_QUERY_TYPE {
    NET_APP_DATA_STAT ,     // 获取协议栈统计数据,(输入结构体NET_IN_NETAPP_NET_DATA_STAT,输出结构体NET_OUT_NETAPP_NET_DATA_STAT)
    NET_APP_LINK_STAT ,     // 获取物理链路状态,(输入结构体NET_IN_NETAPP_LINK_STATUS,输出结构体NET_OUT_NETAPP_LINK_STATUS)
};

// 抓图类型 CLIENT_CapturePictureEx 接口使用
enum NET_CAPTURE_FORMATS
{
    NET_CAPTURE_BMP,
    NET_CAPTURE_JPEG,       // 100%质量的JPEG
    NET_CAPTURE_JPEG_70,    // 70%质量的JPEG
    NET_CAPTURE_JPEG_50,
    NET_CAPTURE_JPEG_30,
};

// 设备类型
enum NET_DEVICE_TYPE 
{
    NET_PRODUCT_NONE = 0,
    NET_DVR_NONREALTIME_MACE,     // 非实时MACE
    NET_DVR_NONREALTIME,          // 非实时
    NET_NVS_MPEG1,                // 网络视频服务器
    NET_DVR_MPEG1_2,              // MPEG1二路录像机
    NET_DVR_MPEG1_8,              // MPEG1八路录像机
    NET_DVR_MPEG4_8,              // MPEG4八路录像机
    NET_DVR_MPEG4_16,             // MPEG4十六路录像机
    NET_DVR_MPEG4_SX2,            // LB系列录像机
    NET_DVR_MEPG4_ST2,            // GB系列录像机
    NET_DVR_MEPG4_SH2,            // HB系列录像机
    NET_DVR_MPEG4_GBE,            // GBE系列录像机
    NET_DVR_MPEG4_NVSII,          // II代网络视频服务器
    NET_DVR_STD_NEW,              // 新标准配置协议
    NET_DVR_DDNS,                 // DDNS服务器
    NET_DVR_ATM,                  // ATM机
    NET_NB_SERIAL,                // 二代非实时NB系列机器
    NET_LN_SERIAL,                // LN系列产品
    NET_BAV_SERIAL,               // BAV系列产品
    NET_SDIP_SERIAL,              // SDIP系列产品
    NET_IPC_SERIAL,               // IPC系列产品
    NET_NVS_B,                    // NVS B系列
    NET_NVS_C,                    // NVS H系列
    NET_NVS_S,                    // NVS S系列
    NET_NVS_E,                    // NVS E系列
    NET_DVR_NEW_PROTOCOL,         // 从QueryDevState中查询设备类型,以字符串格式
    NET_NVD_SERIAL,               // 解码器
    NET_DVR_N5,                   // N5
    NET_DVR_MIX_DVR,              // 混合DVR
    NET_SVR_SERIAL,               // SVR系列
    NET_SVR_BS,                   // SVR-BS
    NET_NVR_SERIAL,               // NVR系列
    NET_DVR_N51,                  // N51
    NET_ITSE_SERIAL,              // ITSE 智能分析盒
    NET_ITC_SERIAL,               // 智能交通像机设备
    NET_HWS_SERIAL,               // 雷达测速仪HWS
    NET_PVR_SERIAL,               // 便携式音视频录像机
    NET_IVS_SERIAL,               // IVS（智能视频服务器系列）
    NET_IVS_B,                    // 通用智能视频侦测服务器
    NET_IVS_F,                    // 人脸识别服务器
    NET_IVS_V,                    // 视频质量诊断服务器
    NET_MATRIX_SERIAL,            // 矩阵
    NET_DVR_N52,                  // N52
    NET_DVR_N56,                  // N56
    NET_ESS_SERIAL,               // ESS
    NET_IVS_PC,                   // 人数统计服务器
    NET_PC_NVR,                   // pc-nvr
    NET_DSCON,                    // 大屏控制器
    NET_EVS,                      // 网络视频存储服务器
    NET_EIVS,                     // 嵌入式智能分析视频系统
    NET_DVR_N6,                   // DVR-N6
    NET_UDS,                      // 万能解码器
    NET_AF6016,                   // 银行报警主机
    NET_AS5008,                   // 视频网络报警主机
    NET_AH2008,                   // 网络报警主机
    NET_A_SERIAL,                 // 报警主机系列
    NET_BSC_SERIAL,               // 门禁系列产品
    NET_NVS_SERIAL,               // NVS系列产品
};

// 语言种类
typedef enum __LANGUAGE_TYPE
{
    DH_LANGUAGE_ENGLISH,                // 英文    
    DH_LANGUAGE_CHINESE_SIMPLIFIED,     // 简体中文    
    DH_LANGUAGE_CHINESE_TRADITIONAL,    // 繁体中文    
    DH_LANGUAGE_ITALIAN,                // 意大利文    
    DH_LANGUAGE_SPANISH,                // 西班牙文
    DH_LANGUAGE_JAPANESE,               // 日文版    
    DH_LANGUAGE_RUSSIAN,                // 俄文版        
    DH_LANGUAGE_FRENCH,                 // 法文版        
    DH_LANGUAGE_GERMAN,                 // 德文版        
    DH_LANGUAGE_PORTUGUESE,             // 葡萄牙语    
    DH_LANGUAGE_TURKEY,                 // 土尔其语    
    DH_LANGUAGE_POLISH,                 // 波兰语    
    DH_LANGUAGE_ROMANIAN,               // 罗马尼亚    
    DH_LANGUAGE_HUNGARIAN,              // 匈牙利语    
    DH_LANGUAGE_FINNISH,                // 芬兰语    
    DH_LANGUAGE_ESTONIAN,               // 爱沙尼亚语    
    DH_LANGUAGE_KOREAN,                 // 韩语    
    DH_LANGUAGE_FARSI,                  // 波斯语     
    DH_LANGUAGE_DANSK,                  // 丹麦语
    DH_LANGUAGE_CZECHISH,               // 捷克文
    DH_LANGUAGE_BULGARIA,               // 保加利亚文
    DH_LANGUAGE_SLOVAKIAN,              // 斯洛伐克语
    DH_LANGUAGE_SLOVENIA,               // 斯洛文尼亚文
    DH_LANGUAGE_CROATIAN,               // 克罗地亚语
    DH_LANGUAGE_DUTCH,                  // 荷兰语
    DH_LANGUAGE_GREEK,                  // 希腊语
    DH_LANGUAGE_UKRAINIAN,              // 乌克兰语
    DH_LANGUAGE_SWEDISH,                // 瑞典语
    DH_LANGUAGE_SERBIAN,                // 塞尔维亚语
    DH_LANGUAGE_VIETNAMESE,             // 越南语
    DH_LANGUAGE_LITHUANIAN,             // 立陶宛语
    DH_LANGUAGE_FILIPINO,               // 菲律宾语
    DH_LANGUAGE_ARABIC,                 // 阿拉伯语
    DH_LANGUAGE_CATALAN,                // 加泰罗尼亚语
    DH_LANGUAGE_LATVIAN,                // 拉脱维亚语
    DH_LANGUAGE_THAI,                   // 泰语
    DH_LANGUAGE_HEBREW,                 // 希伯来语
    DH_LANGUAGE_Bosnian,                // 波斯尼亚文
} DH_LANGUAGE_TYPE;

// 升级类型
typedef enum __EM_UPGRADE_TYPE
{
    DH_UPGRADE_BIOS_TYPE = 1,           // BIOS升级
    DH_UPGRADE_WEB_TYPE,                // WEB升级
    DH_UPGRADE_BOOT_YPE,                // BOOT升级
    DH_UPGRADE_CHARACTER_TYPE,          // 汉字库
    DH_UPGRADE_LOGO_TYPE,               // LOGO
    DH_UPGRADE_EXE_TYPE,                // EXE，例如播放器等
    DH_UPGRADE_DEVCONSTINFO_TYPE,       // 设备固有信息设置(如：硬件ID，MAC，序列号)
    DH_UPGRADE_PERIPHERAL_TYPE,         // 外设接入从片(如车载287芯片)
    DH_UPGRADE_GEOINFO_TYPE,            // 地理信息定位芯片
    DH_UPGRADE_MENU,                    // 菜单（设备操作界面的图片）
    DH_UPGRADE_ROUTE,                   // 线路文件（如公交线路）
    DH_UPGRADE_ROUTE_STATE_AUTO,        // 报站音频（与线路配套的报站音频）
    DH_UPGRADE_SCREEN,                  // 调度屏（如公交操作屏）
} EM_UPGRADE_TYPE;

// 录象类型(定时、动态检测、报警)
typedef enum __REC_TYPE
{
    DH_REC_TYPE_TIM = 0,
    DH_REC_TYPE_MTD,
    DH_REC_TYPE_ALM,
    DH_REC_TYPE_NUM,
} REC_TYPE;

// 网络类型 
typedef enum __GPRSCDMA_NETWORK_TYPE
{
    DH_TYPE_AUTOSEL = 0,                        // 自动选择
    DH_TYPE_TD_SCDMA,                           // TD-SCDMA网络 
    DH_TYPE_WCDMA,                              // WCDMA网络
    DH_TYPE_CDMA_1x,                            // CDMA 1.x网络
    DH_TYPE_EDGE,                               // GPRS网络
    DH_TYPE_EVDO,                               // EVDO网络
    DH_TYPE_WIFI,                               // 无线
} EM_GPRSCDMA_NETWORK_TYPE;

// 接口类型，对应CLIENT_SetSubconnCallBack接口
typedef enum __EM_INTERFACE_TYPE
{
    DH_INTERFACE_OTHER = 0x00000000,            // 未知接口
    DH_INTERFACE_REALPLAY,                      // 实时监视接口
    DH_INTERFACE_PREVIEW,                       // 多画面预览接口
    DH_INTERFACE_PLAYBACK,                      // 回放接口
    DH_INTERFACE_DOWNLOAD,                      // 下载接口
    DH_INTERFACE_REALLOADPIC,                   // 下载智能图片接口
} EM_INTERFACE_TYPE;

// 视频监视断开事件类型
typedef enum _EM_REALPLAY_DISCONNECT_EVENT_TYPE
{
    DISCONNECT_EVENT_REAVE,                     // 表示高级用户抢占低级用户资源
    DISCONNECT_EVENT_NETFORBID,                 // 禁止入网
    DISCONNECT_EVENT_SUBCONNECT,                // 动态子链接断开
}EM_REALPLAY_DISCONNECT_EVENT_TYPE;

// 事件文件的文件标签类型
typedef enum __EM_EVENT_FILETAG
{
    DH_ATMBEFOREPASTE = 1,                      // ATM贴条前
    DH_ATMAFTERPASTE,                           // ATM贴条后
}EM_EVENT_FILETAG;

// IPC类型
typedef enum __EM_IPC_TYPE
{
    DH_IPC_PRIVATE,                                 // 私有
    DH_IPC_AEBELL,                                  // 美电贝尔
    DH_IPC_PANASONIC,                               // 松下
    DH_IPC_SONY,                                    // 索尼
    DH_IPC_DYNACOLOR,                               // Dynacolor
    DH_IPC_TCWS = 5,                                // 天城威视
    DH_IPC_SAMSUNG,                                 // 三星
    DH_IPC_YOKO,                                    // YOKO
    DH_IPC_AXIS,                                    // 安讯视
    DH_IPC_SANYO,                                   // 三洋       
    DH_IPC_BOSH = 10,                               // Bosch
    DH_IPC_PECLO,                                   // Peclo
    DH_IPC_PROVIDEO,                                // Provideo
    DH_IPC_ACTI,                                    // ACTi
    DH_IPC_VIVOTEK,                                 // Vivotek
    DH_IPC_ARECONT = 15,                            // Arecont
    DH_IPC_PRIVATEEH,                               // PrivateEH    
    DH_IPC_IMATEK,                                  // IMatek
    DH_IPC_SHANY,                                   // Shany
    DH_IPC_VIDEOTREC,                               // 动力盈科
    DH_IPC_URA = 20,                                // Ura
    DH_IPC_BITICINO,                                // Bticino 
    DH_IPC_ONVIF,                                   // Onvif协议类型
    DH_IPC_SHEPHERD,                                // 视霸
    DH_IPC_YAAN,                                    // 亚安
    DH_IPC_AIRPOINT = 25,                           // Airpop
    DH_IPC_TYCO,                                    // TYCO
    DH_IPC_XUNMEI,                                  // 讯美
    DH_IPC_HIKVISION,                               // 海康
    DH_IPC_LG,                                      // LG
    DH_IPC_AOQIMAN = 30,                            // 奥奇曼
    DH_IPC_BAOKANG,                                 // 宝康    
    DH_IPC_WATCHNET,                                // Watchnet
    DH_IPC_XVISION,                                 // Xvision
    DH_IPC_FUSITSU,                                 // 富士通
    DH_IPC_CANON = 35,                              // Canon
    DH_IPC_GE,                                      // GE
    DH_IPC_Basler,                                  // 巴斯勒
    DH_IPC_Patro,                                   // 帕特罗
    DH_IPC_CPKNC,                                   // CPPLUS K系列
    DH_IPC_CPRNC = 40,                              // CPPLUS R系列
    DH_IPC_CPUNC,                                   // CPPLUS U系列
    DH_IPC_CPPLUS,                                  // CPPLUS IPC
    DH_IPC_XunmeiS,                                 // 讯美s,实际协议为Onvif
    DH_IPC_GDDW,                                    // 广东电网
    DH_IPC_PSIA = 45,                               // PSIA
    DH_IPC_GB2818,                                  // GB2818    
    DH_IPC_GDYX,                                    // GDYX
    DH_IPC_OTHER,                                   // 由用户自定义
    DH_IPC_CPUNR,                                   // CPPLUS NVR
    DH_IPC_CPUAR = 50,                              // CPPLUS DVR
    DH_IPC_AIRLIVE,                                 // Airlive    
    DH_IPC_NPE,                                     // NPE    
    DH_IPC_AXVIEW,                                  // AXVIEW
    DH_IPC_HYUNDAI = 56,                            // HYUNDAI DVR
    DH_IPC_APHD,                                    // 爱普华顿
    DH_IPC_WELLTRANS ,                              // 微创
    DH_IPC_CDJF,                                    // 成都佳发
    DH_IPC_JVC = 60,                                // JVC
    DH_IPC_INFINOVA,                                // 英飞拓
    DH_IPC_ADT,                                     // ADT
    DH_IPC_SIVIDI,                                  // 海南创先
    DH_IPC_CPUNP,                                   // CPPLUS 球机
    DH_IPC_HX = 65,                                 // 海信
    DH_IPC_TJGS,                                    // 天津高速
}EM_IPC_TYPE;

// H264 编码级别
typedef enum __EM_H264_PROFILE_RANK
{
    DH_PROFILE_BASELINE = 1,                       // 提供I/P帧，仅支持progressive(逐行扫描)和CAVLC
    DH_PROFILE_MAIN,                               // 提供I/P/B帧，支持progressiv和interlaced，提供CAVLC或CABAC
    DH_PROFILE_EXTENDED,                           // 提供I/P/B/SP/SI帧，仅支持progressive(逐行扫描)和CAVLC
    DH_PROFILE_HIGH,                               // 即FRExt，Main_Profile基础上新增：8x8 intra prediction(8x8 帧内预测), custom 
                                                   // quant(自定义量化), lossless video coding(无损视频编码), 更多的yuv格式
}EM_H264_PROFILE_RANK;

typedef enum __EM_DISK_TYPE
{
    DH_DISK_READ_WRITE,                         // 读写驱动器
    DH_DISK_READ_ONLY,                          // 只读驱动器
    DH_DISK_BACKUP,                             // 备份驱动器或媒体驱动器
    DH_DISK_REDUNDANT,                          // 冗余驱动器
    DH_DISK_SNAPSHOT,                           // 快照驱动器
}EM_DISK_TYPE;

// 码流加密算法工作模式
typedef enum  __EM_ENCRYPT_ALOG_WORKMODE
{
    ENCRYPT_ALOG_WORKMODE_ECB,     // ECB模式
    ENCRYPT_ALOG_WORKMODE_CBC,     // CBC模式
    ENCRYPT_ALOG_WORKMODE_CFB,     // CFB模式
    ENCRYPT_ALOG_WORKMODE_OFB,     // OFB模式
}EM_ENCRYPT_ALOG_WORKMODE;

typedef enum __EM_MOBILE_PPP_STATE
{
    MOBILE_PPP_UP = 0,             // 链接已经建立
    MOBILE_PPP_DOWN,               // ppp连接断开        
    MOBILE_PPP_CONNECTING,         // 正在创建链接        
    MOBILE_PPP_CLOSEING,           // 正在关闭PPP链接
} EM_MOBILE_PPP_STATE;

typedef enum __EM_3GMOBILE_STATE
{
    MOBILE_MODULE_OFF,             // 表示3g网卡模块关闭           
    MOBILE_MODULE_STARTING,        // 表示3g网卡模块正在启动    
    MOBILE_MODULE_WORKING,         // 表示3g网卡模块正在工作中
}EM_3GMOBILE_STATE;

/////////////////////////////////监视相关/////////////////////////////////

// 预览类型，对应CLIENT_RealPlayEx接口
typedef enum _RealPlayType
{
    DH_RType_Realplay = 0,                      // 实时预览
    DH_RType_Multiplay,                         // 多画面预览
    DH_RType_Realplay_0,                        // 实时监视-主码流，等同于DH_RType_Realplay
    DH_RType_Realplay_1,                        // 实时监视-从码流1
    DH_RType_Realplay_2,                        // 实时监视-从码流2
    DH_RType_Realplay_3,                        // 实时监视-从码流3    
    DH_RType_Multiplay_1,                       // 多画面预览－1画面
    DH_RType_Multiplay_4,                       // 多画面预览－4画面
    DH_RType_Multiplay_8,                       // 多画面预览－8画面
    DH_RType_Multiplay_9,                       // 多画面预览－9画面
    DH_RType_Multiplay_16,                      // 多画面预览－16画面
    DH_RType_Multiplay_6,                       // 多画面预览－6画面
    DH_RType_Multiplay_12,                      // 多画面预览－12画面
    DH_RType_Multiplay_25,                      // 多画面预览－25画面
    DH_RType_Multiplay_36,                      // 多画面预览－36画面
} DH_RealPlayType;

/////////////////////////////////云台相关/////////////////////////////////

// 通用云台控制命令
typedef enum _PTZ_ControlType
{

    DH_PTZ_UP_CONTROL = 0,                      // 上
    DH_PTZ_DOWN_CONTROL,                        // 下
    DH_PTZ_LEFT_CONTROL,                        // 左
    DH_PTZ_RIGHT_CONTROL,                       // 右
    DH_PTZ_ZOOM_ADD_CONTROL,                    // 变倍+
    DH_PTZ_ZOOM_DEC_CONTROL,                    // 变倍-
    DH_PTZ_FOCUS_ADD_CONTROL,                   // 调焦+
    DH_PTZ_FOCUS_DEC_CONTROL,                   // 调焦-
    DH_PTZ_APERTURE_ADD_CONTROL,                // 光圈+
    DH_PTZ_APERTURE_DEC_CONTROL,                // 光圈-
    DH_PTZ_POINT_MOVE_CONTROL,                  // 转至预置点
    DH_PTZ_POINT_SET_CONTROL,                   // 设置
    DH_PTZ_POINT_DEL_CONTROL,                   // 删除
    DH_PTZ_POINT_LOOP_CONTROL,                  // 点间巡航
    DH_PTZ_LAMP_CONTROL                         // 灯光雨刷
} DH_PTZ_ControlType;

// 云台控制扩展命令
typedef enum _EXTPTZ_ControlType
{
    DH_EXTPTZ_LEFTTOP = 0x20,                   // 左上
    DH_EXTPTZ_RIGHTTOP,                         // 右上
    DH_EXTPTZ_LEFTDOWN,                         // 左下
    DH_EXTPTZ_RIGHTDOWN,                        // 右下
    DH_EXTPTZ_ADDTOLOOP,                        // 加入预置点到巡航 巡航线路 预置点值
    DH_EXTPTZ_DELFROMLOOP,                      // 删除巡航中预置点 巡航线路 预置点值
    DH_EXTPTZ_CLOSELOOP,                        // 清除巡航 巡航线路
    DH_EXTPTZ_STARTPANCRUISE,                   // 开始水平旋转
    DH_EXTPTZ_STOPPANCRUISE,                    // 停止水平旋转
    DH_EXTPTZ_SETLEFTBORDER,                    // 设置左边界
    DH_EXTPTZ_SETRIGHTBORDER,                   // 设置右边界
    DH_EXTPTZ_STARTLINESCAN,                    // 开始线扫
    DH_EXTPTZ_CLOSELINESCAN,                    // 停止线扫
    DH_EXTPTZ_SETMODESTART,                     // 设置模式开始    模式线路
    DH_EXTPTZ_SETMODESTOP,                      // 设置模式结束    模式线路
    DH_EXTPTZ_RUNMODE,                          // 运行模式    模式线路
    DH_EXTPTZ_STOPMODE,                         // 停止模式    模式线路
    DH_EXTPTZ_DELETEMODE,                       // 清除模式    模式线路
    DH_EXTPTZ_REVERSECOMM,                      // 翻转命令
    DH_EXTPTZ_FASTGOTO,                         // 快速定位 水平坐标(8192) 垂直坐标(8192) 变倍(4)
    DH_EXTPTZ_AUXIOPEN,                         // 辅助开关开 辅助点
    DH_EXTPTZ_AUXICLOSE,                        // 辅助开关关 辅助点
    DH_EXTPTZ_OPENMENU = 0x36,                  // 打开球机菜单
    DH_EXTPTZ_CLOSEMENU,                        // 关闭菜单
    DH_EXTPTZ_MENUOK,                           // 菜单确定
    DH_EXTPTZ_MENUCANCEL,                       // 菜单取消
    DH_EXTPTZ_MENUUP,                           // 菜单上
    DH_EXTPTZ_MENUDOWN,                         // 菜单下
    DH_EXTPTZ_MENULEFT,                         // 菜单左
    DH_EXTPTZ_MENURIGHT,                        // 菜单右
    DH_EXTPTZ_ALARMHANDLE = 0x40,               // 报警联动云台 parm1：报警输入通道；parm2：报警联动类型1-预置点2-线扫3-巡航；parm3：联动值，如预置点号
    DH_EXTPTZ_MATRIXSWITCH = 0x41,              // 矩阵切换 parm1：监视器号(视频输出号)；parm2：视频输入号；parm3：矩阵号
    DH_EXTPTZ_LIGHTCONTROL,                     // 灯光控制器
    DH_EXTPTZ_EXACTGOTO,                        // 三维精确定位 parm1：水平角度(0~3600)；parm2：垂直坐标(0~900)；parm3：变倍(1~128)
    DH_EXTPTZ_RESETZERO,                        // 三维定位重设零位
    DH_EXTPTZ_MOVE_ABSOLUTELY,                  // 绝对移动控制命令，param4对应结构PTZ_CONTROL_ABSOLUTELY
    DH_EXTPTZ_MOVE_CONTINUOUSLY,                // 持续移动控制命令，param4对应结构PTZ_CONTROL_CONTINUOUSLY
    DH_EXTPTZ_GOTOPRESET,                       // 云台控制命令，以一定速度转到预置位点，parm4对应结构PTZ_CONTROL_GOTOPRESET
    DH_EXTPTZ_SET_VIEW_RANGE = 0x49,            // 设置可视域(param4对应结构 PTZ_VIEW_RANGE_INFO)
    DH_EXTPTZ_FOCUS_ABSOLUTELY = 0x4A,          // 绝对聚焦(param4对应结构PTZ_FOCUS_ABSOLUTELY)
    DH_EXTPTZ_HORSECTORSCAN = 0x4B,             // 水平扇扫(param4对应PTZ_CONTROL_SECTORSCAN,param1、param2、param3无效)
    DH_EXTPTZ_VERSECTORSCAN = 0x4C,             // 垂直扇扫(param4对应PTZ_CONTROL_SECTORSCAN,param1、param2、param3无效)
    DH_EXTPTZ_SET_ABS_ZOOMFOCUS = 0x4D,         // 设定绝对焦距、聚焦值,param1为焦距,范围:[0,255],param2为聚焦,范围:[0,255],param3、param4无效
    
    DH_EXTPTZ_UP_TELE = 0x70,                   // 上 + TELE param1=速度(1-8)，下同
    DH_EXTPTZ_DOWN_TELE,                        // 下 + TELE
    DH_EXTPTZ_LEFT_TELE,                        // 左 + TELE
    DH_EXTPTZ_RIGHT_TELE,                       // 右 + TELE
    DH_EXTPTZ_LEFTUP_TELE,                      // 左上 + TELE
    DH_EXTPTZ_LEFTDOWN_TELE,                    // 左下 + TELE
    DH_EXTPTZ_TIGHTUP_TELE,                     // 右上 + TELE
    DH_EXTPTZ_RIGHTDOWN_TELE,                   // 右下 + TELE
    DH_EXTPTZ_UP_WIDE,                          // 上 + WIDE param1=速度(1-8)，下同
    DH_EXTPTZ_DOWN_WIDE,                        // 下 + WIDE
    DH_EXTPTZ_LEFT_WIDE,                        // 左 + WIDE
    DH_EXTPTZ_RIGHT_WIDE,                       // 右 + WIDE
    DH_EXTPTZ_LEFTUP_WIDE,                      // 左上 + WIDE
    DH_EXTPTZ_LEFTDOWN_WIDE,                    // 左下 + WIDE
    DH_EXTPTZ_TIGHTUP_WIDE,                     // 右上 + WIDE
    DH_EXTPTZ_RIGHTDOWN_WIDE,                   // 右下 + WIDE
    DH_EXTPTZ_TOTAL,                            // 最大命令值
} DH_EXTPTZ_ControlType;

/////////////////////////////////日志相关/////////////////////////////////

// 日志查询类型
typedef enum _DH_LOG_QUERY_TYPE
{
    DHLOG_ALL = 0,                              // 所有日志
    DHLOG_SYSTEM,                               // 系统日志
    DHLOG_CONFIG,                               // 配置日志
    DHLOG_STORAGE,                              // 存储相关
    DHLOG_ALARM,                                // 报警日志
    DHLOG_RECORD,                               // 录象相关
    DHLOG_ACCOUNT,                              // 帐号相关
    DHLOG_CLEAR,                                // 清除日志
    DHLOG_PLAYBACK,                             // 回放相关
    DHLOG_MANAGER                               // 前端管理运行相关
} DH_LOG_QUERY_TYPE;

// 日志类型
typedef enum _DH_LOG_TYPE
{
    DH_LOG_REBOOT = 0x0000,                     // 设备重启
    DH_LOG_SHUT,                                // 设备关机
    DH_LOG_REPORTSTOP,
    DH_LOG_REPORTSTART,
    DH_LOG_UPGRADE = 0x0004,                    // 设备升级
    DH_LOG_SYSTIME_UPDATE = 0x0005,             // 系统时间更新
    DH_LOG_GPS_TIME_UPDATE = 0x0006,            // GPS时间更新
    DH_LOG_AUDIO_TALKBACK,                      // 语音对讲， true代表开启，false代表关闭    
    DH_LOG_COMM_ADAPTER,                        // 透明传输， true代表开启，false代表关闭    
    DH_LOG_NET_TIMING,                          // 网络校时
    DH_LOG_CONFSAVE = 0x0100,                   // 保存配置
    DH_LOG_CONFLOAD,                            // 读取配置
    DH_LOG_FSERROR = 0x0200,                    // 文件系统错误
    DH_LOG_HDD_WERR,                            // 硬盘写错误
    DH_LOG_HDD_RERR,                            // 硬盘读错误
    DH_LOG_HDD_TYPE,                            // 设置硬盘类型
    DH_LOG_HDD_FORMAT,                          // 格式化硬盘
    DH_LOG_HDD_NOSPACE,                         // 当前工作盘空间不足
    DH_LOG_HDD_TYPE_RW,                         // 设置硬盘类型为读写盘
    DH_LOG_HDD_TYPE_RO,                         // 设置硬盘类型为只读盘    
    DH_LOG_HDD_TYPE_RE,                         // 设置硬盘类型为冗余盘
    DH_LOG_HDD_TYPE_SS,                         // 设置硬盘类型为快照盘
    DH_LOG_HDD_NONE,                            // 无硬盘记录
    DH_LOG_HDD_NOWORKHDD,                       // 无工作盘(没有读写盘)
    DH_LOG_HDD_TYPE_BK,                         // 设置硬盘类型为备份盘
    DH_LOG_HDD_TYPE_REVERSE,                    // 设置硬盘类型为保留分区
    DH_LOG_HDD_START_INFO = 0x200 +14,          // 记录开机时的硬盘信息
    DH_LOG_HDD_WORKING_DISK,                    // 记录换盘后的工作盘号
    DH_LOG_HDD_OTHER_ERROR,                     // 记录硬盘其它错误
    DH_LOG_HDD_SLIGHT_ERR,                      // 硬盘存在轻微问题
    DH_LOG_HDD_SERIOUS_ERR,                     // 硬盘存在严重问题
    DH_LOG_HDD_NOSPACE_END,                     // 当前工作盘空间不足报警结束
    DH_LOG_HDD_TYPE_RAID_CONTROL,               // Raid操作
    DH_LOG_HDD_TEMPERATURE_HIGH,                // 温度过高
    DH_LOG_HDD_TEMPERATURE_LOW,                 // 温度过低
    DH_LOG_HDD_ESATA_REMOVE,                    // 移除eSATA
    DH_LOG_ALM_IN = 0x0300,                     // 外部输入报警开始
    DH_LOG_NETALM_IN,                           // 网络报警输入
    DH_LOG_ALM_END = 0x0302,                    // 外部输入报警停止
    DH_LOG_LOSS_IN,                             // 视频丢失报警开始
    DH_LOG_LOSS_END,                            // 视频丢失报警结束
    DH_LOG_MOTION_IN,                           // 动态检测报警开始
    DH_LOG_MOTION_END,                          // 动态检测报警结束
    DH_LOG_ALM_BOSHI,                           // 报警器报警输入
    DH_LOG_NET_ABORT = 0x0308,                  // 网络断开
    DH_LOG_NET_ABORT_RESUME,                    // 网络恢复
    DH_LOG_CODER_BREAKDOWN,                     // 编码器故障
    DH_LOG_CODER_BREAKDOWN_RESUME,              // 编码器故障恢复
    DH_LOG_BLIND_IN,                            // 视频遮挡
    DH_LOG_BLIND_END,                           // 视频遮挡恢复
    DH_LOG_ALM_TEMP_HIGH,                       // 温度过高
    DH_LOG_ALM_VOLTAGE_LOW,                     // 电压过低
    DH_LOG_ALM_BATTERY_LOW,                     // 电池容量不足
    DH_LOG_ALM_ACC_BREAK,                       // ACC断电
    DH_LOG_ALM_ACC_RES,
    DH_LOG_GPS_SIGNAL_LOST,                     // GPS无信号
    DH_LOG_GPS_SIGNAL_RESUME,                   // GPS信号恢复
    DH_LOG_3G_SIGNAL_LOST,                      // 3G无信号
    DH_LOG_3G_SIGNAL_RESUME,                    // 3G信号恢复
    DH_LOG_ALM_IPC_IN,                          // IPC外部报警
    DH_LOG_ALM_IPC_END,                         // IPC外部报警恢复
    DH_LOG_ALM_DIS_IN,                          // 断网报警
    DH_LOG_ALM_DIS_END,                         // 断网报警恢复
    DH_LOG_INFRAREDALM_IN = 0x03a0,             // 无线报警开始
    DH_LOG_INFRAREDALM_END,                     // 无线报警结束
    DH_LOG_IPCONFLICT,                          // IP冲突
    DH_LOG_IPCONFLICT_RESUME,                   // IP恢复
    DH_LOG_SDPLUG_IN,                           // SD卡插入(DH_LOG_ITEM中的reserved值为3表示U盘插入)
    DH_LOG_SDPLUG_OUT,                          // SD卡拔出(DH_LOG_ITEM中的reserved值为3表示U盘拔出)
    DH_LOG_NET_PORT_BIND_FAILED,                // 网络端口绑定失败
    DH_LOG_HDD_BEEP_RESET,                      // 硬盘错误报警蜂鸣结束
    DH_LOG_MAC_CONFLICT,                        // MAC冲突
    DH_LOG_MAC_CONFLICT_RESUME,                 // MAC冲突恢复
    DH_LOG_ALARM_OUT,                           // 报警输出状态
    DH_LOG_ALM_RAID_STAT_EVENT,                 // RAID状态变化事件 
    DH_LOG_ABLAZE_ON,                           // 火警报警，烟感或温度
    DH_LOG_ABLAZE_OFF,                          // 火警报警 恢复
    DH_LOG_INTELLI_ALARM_PLUSE,                 // 智能脉冲型报警
    DH_LOG_INTELLI_ALARM_IN,                    // 智能报警开始
    DH_LOG_INTELLI_ALARM_END,                   // 智能报警结束
    DH_LOG_3G_SIGNAL_SCAN,                      // 3G信号检测
    DH_LOG_GPS_SIGNAL_SCAN,                     // GPS信号检测
    DH_LOG_AUTOMATIC_RECORD = 0x0400,           // 自动录像
    DH_LOG_MANUAL_RECORD = 0x0401,              // 手动录象
    DH_LOG_CLOSED_RECORD,                       // 停止录象
    DH_LOG_LOGIN = 0x0500,                      // 登录
    DH_LOG_LOGOUT,                              // 注销
    DH_LOG_ADD_USER,                            // 添加用户
    DH_LOG_DELETE_USER,                         // 删除用户
    DH_LOG_MODIFY_USER,                         // 修改用户
    DH_LOG_ADD_GROUP,                           // 添加用户组
    DH_LOG_DELETE_GROUP,                        // 删除用户组
    DH_LOG_MODIFY_GROUP,                        // 修改用户组
    DH_LOG_NET_LOGIN = 0x0508,                  // 网络用户登录
    DH_LOG_MODIFY_PASSWORD,                     // 修改密码
    DH_LOG_CLEAR = 0x0600,                      // 清除日志
    DH_LOG_SEARCHLOG,                           // 查询日志
    DH_LOG_SEARCH = 0x0700,                     // 录像查询
    DH_LOG_DOWNLOAD,                            // 录像下载
    DH_LOG_PLAYBACK,                            // 录像回放
    DH_LOG_BACKUP,                              // 备份录像文件
    DH_LOG_BACKUPERROR,                         // 备份录像文件失败
    DH_LOG_BACK_UPRT,                           // 实时备份，即光盘刻录
    DH_LOG_BACKUPCLONE,                         // 光盘复制。
    DH_LOG_DISK_CHANGED,                        // 手动换盘
    DH_LOG_IMAGEPLAYBACK,                       // 图片回放
    DH_LOG_LOCKFILE,                            // 锁定录像
    DH_LOG_UNLOCKFILE,                          // 解锁录像
    DH_LOG_ATMPOS,                              // ATM卡号叠加添加日志

    DH_LOG_TIME_UPDATE  = 0x0800,               // 时间同步
    DH_LOG_REMOTE_STATE = 0x0850,               // 远程日志 
    DH_LOG_USER_DEFINE = 0x0900,
    DH_LOG_TYPE_NR = 10,
} DH_LOG_TYPE;

// 扩展日志类型，对应CLIENT_QueryLogEx接口，条件(int nType = 1；参数reserved = &nType)
typedef enum _DH_NEWLOG_TYPE
{
    DH_NEWLOG_REBOOT = 0x0000,                     // 设备重启
    DH_NEWLOG_SHUT,                                // 设备关机
    DH_NEWLOG_REPORTSTOP,
    DH_NEWLOG_REPORTSTART,
    DH_NEWLOG_UPGRADE = 0x0004,                    // 设备升级
    DH_NEWLOG_SYSTIME_UPDATE = 0x0005,             // 系统时间更新
    DH_NEWLOG_GPS_TIME_UPDATE = 0x0006,            // GPS时间更新

    DH_NEWLOG_AUDIO_TALKBACK,                      // 语音对讲， true代表开启，false代表关闭    
    DH_NEWLOG_COMM_ADAPTER,                        // 透明传输， true代表开启，false代表关闭    
    DH_NEWLOG_NET_TIMING,                          // 网络校时

    DH_NEWLOG_CONFSAVE = 0x0100,                   // 保存配置
    DH_NEWLOG_CONFLOAD,                            // 读取配置
    DH_NEWLOG_FSERROR = 0x0200,                    // 文件系统错误
    DH_NEWLOG_HDD_WERR,                            // 硬盘写错误
    DH_NEWLOG_HDD_RERR,                            // 硬盘读错误
    DH_NEWLOG_HDD_TYPE,                            // 设置硬盘类型
    DH_NEWLOG_HDD_FORMAT,                          // 格式化硬盘
    DH_NEWLOG_HDD_NOSPACE,                         // 当前工作盘空间不足
    DH_NEWLOG_HDD_TYPE_RW,                         // 设置硬盘类型为读写盘
    DH_NEWLOG_HDD_TYPE_RO,                         // 设置硬盘类型为只读盘    
    DH_NEWLOG_HDD_TYPE_RE,                         // 设置硬盘类型为冗余盘
    DH_NEWLOG_HDD_TYPE_SS,                         // 设置硬盘类型为快照盘
    DH_NEWLOG_HDD_NONE,                            // 无硬盘记录日志
    DH_NEWLOG_HDD_NOWORKHDD,                       // 无工作盘(没有读写盘)
    DH_NEWLOG_HDD_TYPE_BK,                         // 设置硬盘类型为备份盘
    DH_NEWLOG_HDD_TYPE_REVERSE,                    // 设置硬盘类型为保留分区
    DH_NEWLOG_HDD_START_INFO = 0x200 +14,          // 记录开机时的硬盘信息
    DH_NEWLOG_HDD_WORKING_DISK,                    // 记录换盘后的工作盘号
    DH_NEWLOG_HDD_OTHER_ERROR,                     // 记录硬盘其它错误
    DH_NEWLOG_HDD_SLIGHT_ERR,                      // 硬盘存在轻微问题
    DH_NEWLOG_HDD_SERIOUS_ERR,                     // 硬盘存在严重问题
    DH_NEWLOG_HDD_NOSPACE_END,                     // 当前工作盘空间不足报警结束

    DH_NEWLOG_HDD_TYPE_RAID_CONTROL,               // Raid操作
    DH_NEWLOG_HDD_TEMPERATURE_HIGH,                // 温度过高
    DH_NEWLOG_HDD_TEMPERATURE_LOW,                 // 温度过低
    DH_NEWLOG_HDD_ESATA_REMOVE,                    // 移除eSATA

    DH_NEWLOG_ALM_IN = 0x0300,                     // 外部输入报警开始
    DH_NEWLOG_NETALM_IN,                           // 网络报警
    DH_NEWLOG_ALM_END = 0x0302,                    // 外部输入报警停止
    DH_NEWLOG_LOSS_IN,                             // 视频丢失报警开始
    DH_NEWLOG_LOSS_END,                            // 视频丢失报警结束
    DH_NEWLOG_MOTION_IN,                           // 动态检测报警开始
    DH_NEWLOG_MOTION_END,                          // 动态检测报警结束
    DH_NEWLOG_ALM_BOSHI,                           // 报警器报警输入
    DH_NEWLOG_NET_ABORT = 0x0308,                  // 网络断开
    DH_NEWLOG_NET_ABORT_RESUME,                    // 网络恢复
    DH_NEWLOG_CODER_BREAKDOWN,                     // 编码器故障
    DH_NEWLOG_CODER_BREAKDOWN_RESUME,              // 编码器故障恢复
    DH_NEWLOG_BLIND_IN,                            // 视频遮挡
    DH_NEWLOG_BLIND_END,                           // 视频遮挡恢复
    DH_NEWLOG_ALM_TEMP_HIGH,                       // 温度过高
    DH_NEWLOG_ALM_VOLTAGE_LOW,                     // 电压过低
    DH_NEWLOG_ALM_BATTERY_LOW,                     // 电池容量不足
    DH_NEWLOG_ALM_ACC_BREAK,                       // ACC断电
    DH_NEWLOG_ALM_ACC_RES,
    DH_NEWLOG_GPS_SIGNAL_LOST,                     // GPS无信号
    DH_NEWLOG_GPS_SIGNAL_RESUME,                   // GPS信号恢复
    DH_NEWLOG_3G_SIGNAL_LOST,                      // 3G无信号
    DH_NEWLOG_3G_SIGNAL_RESUME,                    // 3G信号恢复

    DH_NEWLOG_ALM_IPC_IN,                          // IPC外部报警
    DH_NEWLOG_ALM_IPC_END,                         // IPC外部报警恢复
    DH_NEWLOG_ALM_DIS_IN,                          // 断网报警
    DH_NEWLOG_ALM_DIS_END,                         // 断网报警恢复

    DH_NEWLOG_INFRAREDALM_IN = 0x03a0,             // 无线报警开始
    DH_NEWLOG_INFRAREDALM_END,                     // 无线报警结束
    DH_NEWLOG_IPCONFLICT,                          // IP冲突
    DH_NEWLOG_IPCONFLICT_RESUME,                   // IP恢复
    DH_NEWLOG_SDPLUG_IN,                           // SD卡插入
    DH_NEWLOG_SDPLUG_OUT,                          // SD卡拔出
    DH_NEWLOG_NET_PORT_BIND_FAILED,                // 网络端口绑定失败
    DH_NEWLOG_HDD_BEEP_RESET,                      // 硬盘错误报警蜂鸣结束
    DH_NEWLOG_MAC_CONFLICT,                        // MAC冲突
    DH_NEWLOG_MAC_CONFLICT_RESUME,                 // MAC冲突恢复
    DH_NEWLOG_ALARM_OUT,                           // 报警输出状态
    DH_NEWLOG_ALM_RAID_STAT_EVENT,                 // RAID状态变化事件 
    DH_NEWLOG_ABLAZE_ON,                           // 火警报警，烟感或温度
    DH_NEWLOG_ABLAZE_OFF,                          // 火警报警 恢复
    DH_NEWLOG_INTELLI_ALARM_PLUSE,                 // 智能脉冲型报警
    DH_NEWLOG_INTELLI_ALARM_IN,                    // 智能报警开始
    DH_NEWLOG_INTELLI_ALARM_END,                   // 智能报警结束
    DH_NEWLOG_3G_SIGNAL_SCAN,                      // 3G信号检测
    DH_NEWLOG_GPS_SIGNAL_SCAN,                     // GPS信号检测
    DH_NEWLOG_AUTOMATIC_RECORD = 0x0400,           // 自动录象
    DH_NEWLOG_MANUAL_RECORD,                       // 手动录象开
    DH_NEWLOG_CLOSED_RECORD,                       // 停止录象
    DH_NEWLOG_LOGIN = 0x0500,                      // 登录
    DH_NEWLOG_LOGOUT,                              // 注销
    DH_NEWLOG_ADD_USER,                            // 添加用户
    DH_NEWLOG_DELETE_USER,                         // 删除用户
    DH_NEWLOG_MODIFY_USER,                         // 修改用户
    DH_NEWLOG_ADD_GROUP,                           // 添加用户组
    DH_NEWLOG_DELETE_GROUP,                        // 删除用户组
    DH_NEWLOG_MODIFY_GROUP,                        // 修改用户组
    DH_NEWLOG_NET_LOGIN = 0x0508,                  // 网络用户登录
    DH_NEWLOG_CLEAR = 0x0600,                      // 清除日志
    DH_NEWLOG_SEARCHLOG,                           // 查询日志
    DH_NEWLOG_SEARCH = 0x0700,                     // 录像查询
    DH_NEWLOG_DOWNLOAD,                            // 录像下载
    DH_NEWLOG_PLAYBACK,                            // 录像回放
    DH_NEWLOG_BACKUP,                              // 备份录像文件
    DH_NEWLOG_BACKUPERROR,                         // 备份录像文件失败

    DH_NEWLOG_BACK_UPRT,                           // 实时备份，即光盘刻录
    DH_NEWLOG_BACKUPCLONE,                         // 光盘复制。
    DH_NEWLOG_DISK_CHANGED,                        // 手动换盘
    DH_NEWLOG_IMAGEPLAYBACK,                       // 图片回放
    DH_NEWLOG_LOCKFILE,                            // 锁定录像
    DH_NEWLOG_UNLOCKFILE,                          // 解锁录像
    DH_NEWLOG_ATMPOS,                              // ATM卡号叠加添加日志

    DH_NEWLOG_TIME_UPDATE  = 0x0800,               // 时间更新
    DH_NEWLOG_REMOTE_STATE = 0x0850,               // 远程日志 

    DH_NEWLOG_USER_DEFINE = 0x0900,
    DH_NEWLOG_TYPE_NR = 10,        
} DH_NEWLOG_TYPE;

///////////////////////////////语音对讲相关///////////////////////////////

// 语音编码类型
typedef enum __TALK_CODING_TYPE 
{
    DH_TALK_DEFAULT = 0,                        // 无头PCM
    DH_TALK_PCM = 1,                            // 带头PCM
    DH_TALK_G711a,                              // G711a
    DH_TALK_AMR,                                // AMR
    DH_TALK_G711u,                              // G711u
    DH_TALK_G726,                               // G726
    DH_TALK_G723_53,                            // G723_53
    DH_TALK_G723_63,                            // G723_63
    DH_TALK_AAC,                                // AAC
    DH_TALK_OGG,                                // OGG
    DH_TALK_ADPCM = 21,                         // ADPCM
    DH_TALK_MP3   = 22,                            // MP3
} DH_TALK_CODING_TYPE;

// 录像文件类型
typedef enum __NET_RECORD_TYPE
{
    NET_RECORD_TYPE_ALL,                        // 所有录像
    NET_RECORD_TYPE_NORMAL,                     // 普通录像
    NET_RECORD_TYPE_ALARM,                      // 外部报警录像
    NET_RECORD_TYPE_MOTION,                     // 动检报警录像
}NET_RECORD_TYPE;

// 对讲方式
typedef enum __EM_USEDEV_MODE
{
    DH_TALK_CLIENT_MODE,                        // 设置客户端方式进行语音对讲
    DH_TALK_SERVER_MODE,                        // 设置服务器方式进行语音对讲
    DH_TALK_ENCODE_TYPE,                        // 设置语音对讲编码格式(对应DHDEV_TALKDECODE_INFO)
    DH_ALARM_LISTEN_MODE,                       // 设置报警订阅方式
    DH_CONFIG_AUTHORITY_MODE,                   // 设置通过权限进行配置管理
    DH_TALK_TALK_CHANNEL,                       // 设置对讲通道(0~MaxChannel-1)
    DH_RECORD_STREAM_TYPE,                      // 设置待查询及按时间回放的录像码流类型(0-主辅码流,1-主码流,2-辅码流)  
    DH_TALK_SPEAK_PARAM,                        // 设置语音对讲喊话参数，对应结构体 NET_SPEAK_PARAM
    DH_RECORD_TYPE,                             // 设置按时间录像回放及下载的录像文件类型(详见NET_RECORD_TYPE)
    DH_TALK_MODE3,                              // 设置三代设备的语音对讲参数, 对应结构体NET_TALK_EX
} EM_USEDEV_MODE;


typedef enum __EM_TALK_DATA_TYPE
{ 
    NET_TALK_DATA_LOCAL_AUDIO = 0,              // 本地录音库采集的音频数据
    NET_TALK_DATA_RECV_AUDIO,                   // 收到的设备发过来的音频数据
    NET_TALK_DATA_RESPOND,                      // 对讲呼叫响应数据
    NET_TALK_DATA_RECV_VIDEO,                   // 收到的设备发过来的视频数据
}EM_TALK_DATA_TYPE;

typedef struct tagNET_TALK_VIDEO_FORMAT
{
	DWORD				dwSize;
	DWORD				dwCompression;			// 视频压缩格式
	int					nFrequency;				// 视频采样频率
}NET_TALK_VIDEO_FORMAT;
// 三代设备的语音对讲参数，对应CLIENT_SetDeviceMode()的DH_TALK_MODE3命令
typedef struct tagNET_TALK_EX
{
    DWORD               dwSize;
    int                 nChannel;               // 通道号
    int                 nAudioPort;             // 音频传输侦听端口
    int                 nWaitTime;              // 等待时间, 单位ms,为0则使用默认值
    HWND				hVideoWnd;				// 可视对讲视频显示窗口
	NET_TALK_VIDEO_FORMAT stuVideoFmt;			// 视频编码格式
	char				szMulticastAddr[DH_MAX_IPADDR_LEN_EX]; // 组播地址
	WORD				wMulticastLocalPort;	// 组播本地端口
	WORD				wMulticastRemotePort;	// 组播远程端口
}NET_TALK_EX;

// AMR编码类型
typedef enum __EM_ARM_ENCODE_MODE
{
    DH_TALK_AMR_AMR475 = 1,                     // AMR475编码
    DH_TALK_AMR_AMR515,                         // AMR515编码
    DH_TALK_AMR_AMR59,                          // AMR59编码
    DH_TALK_AMR_AMR67,                          // AMR67编码
    DH_TALK_AMR_AMR74,                          // AMR74编码
    DH_TALK_AMR_AMR795,                         // AMR795编码
    DH_TALK_AMR_AMR102,                         // AMR102编码
    DH_TALK_AMR_AMR122,                         // AMR122编码
} EM_ARM_ENCODE_MODE;

typedef struct __NET_SPEAK_PARAM
{
    DWORD           dwSize;                     // 结构体大小
    int             nMode;                      // 0：对讲（默认模式），1：喊话；从喊话切换到对讲要重新设置
    int             nSpeakerChannel;            // 扬声器通道号，喊话时有效
} NET_SPEAK_PARAM;

/////////////////////////////////控制相关/////////////////////////////////

// 控制类型，对应CLIENT_ControlDevice接口
typedef enum _CtrlType
{
    DH_CTRL_REBOOT = 0,                            // 重启设备    
    DH_CTRL_SHUTDOWN,                              // 关闭设备
    DH_CTRL_DISK,                                  // 硬盘管理
    DH_KEYBOARD_POWER = 3,                         // 网络键盘
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
    DH_KEYBOARD_10PLUS,
    DH_KEYBOARD_SHIFT,
    DH_KEYBOARD_BACK,
    DH_TRIGGER_ALARM_IN = 100,                     // 触发报警输入
    DH_TRIGGER_ALARM_OUT,                          // 触发报警输出
    DH_CTRL_MATRIX,                                // 矩阵控制
    DH_CTRL_SDCARD,                                // SD卡控制(IPC产品)参数同硬盘控制
    DH_BURNING_START,                              // 刻录机控制，开始刻录
    DH_BURNING_STOP,                               // 刻录机控制，结束刻录
    DH_BURNING_ADDPWD,                             // 刻录机控制，叠加密码(以'\0'为结尾的字符串，最大长度8位)
    DH_BURNING_ADDHEAD,                            // 刻录机控制，叠加片头(以'\0'为结尾的字符串，最大长度1024字节，支持分行，行分隔符'\n')
    DH_BURNING_ADDSIGN,                            // 刻录机控制，叠加打点到刻录信息(参数无)
    DH_BURNING_ADDCURSTOMINFO,                     // 刻录机控制，自定义叠加(以'\0'为结尾的字符串，最大长度1024字节，支持分行，行分隔符'\n')
    DH_CTRL_RESTOREDEFAULT,                        // 恢复设备的默认设置
    DH_CTRL_CAPTURE_START,                         // 触发设备抓图
    DH_CTRL_CLEARLOG,                              // 清除日志
    DH_TRIGGER_ALARM_WIRELESS = 200,               // 触发无线报警(IPC产品)
    DH_MARK_IMPORTANT_RECORD,                      // 标识重要录像文件
    DH_CTRL_DISK_SUBAREA,                          // 网络硬盘分区    
    DH_BURNING_ATTACH,                             // 刻录机控制，附件刻录.
    DH_BURNING_PAUSE,                              // 刻录暂停
    DH_BURNING_CONTINUE,                           // 刻录继续
    DH_BURNING_POSTPONE,                           // 刻录顺延
    DH_CTRL_OEMCTRL,                               // 报停控制
    DH_BACKUP_START,                               // 设备备份开始
    DH_BACKUP_STOP,                                // 设备备份停止
    DH_VIHICLE_WIFI_ADD,                           // 车载手动增加WIFI配置
    DH_VIHICLE_WIFI_DEC,                           // 车载手动删除WIFI配置
    DH_BUZZER_START,                               // 蜂鸣器控制开始
    DH_BUZZER_STOP,                                // 蜂鸣器控制结束
    DH_REJECT_USER,                                // 剔除用户
    DH_SHIELD_USER,                                // 屏蔽用户
    DH_RAINBRUSH,                                  // 智能交通, 雨刷控制 
    DH_MANUAL_SNAP,                                // 智能交通, 手动抓拍 (对应结构体MANUAL_SNAP_PARAMETER)
    DH_MANUAL_NTP_TIMEADJUST,                      // 手动NTP校时
    DH_NAVIGATION_SMS,                             // 导航信息和短消息
    DH_CTRL_ROUTE_CROSSING,                        // 路线点位信息
    DH_BACKUP_FORMAT,                              // 格式化备份设备
    DH_DEVICE_LOCALPREVIEW_SLIPT,                  // 控制设备端本地预览分割(对应结构体DEVICE_LOCALPREVIEW_SLIPT_PARAMETER)    
    DH_CTRL_INIT_RAID,                             // RAID初始化
    DH_CTRL_RAID,                                  // RAID操作
    DH_CTRL_SAPREDISK,                             // 热备盘操作
    DH_WIFI_CONNECT,                               // 手动发起WIFI连接(对应结构体WIFI_CONNECT)
    DH_WIFI_DISCONNECT,                            // 手动断开WIFI连接(对应结构体WIFI_CONNECT)
    DH_CTRL_ARMED,                                 // 布撤防操作
    DH_CTRL_IP_MODIFY,                             // 修改前端IP(对应结构体DHCTRL_IPMODIFY_PARAM)                     
    DH_CTRL_WIFI_BY_WPS,                           // wps连接wifi(对应结构体DHCTRL_CONNECT_WIFI_BYWPS)
    DH_CTRL_FORMAT_PATITION,                       // 格式化分区(对应结构体DH_FORMAT_PATITION)
    DH_CTRL_EJECT_STORAGE,                         // 手动卸载设备(对应结构体DH_EJECT_STORAGE_DEVICE)
    DH_CTRL_LOAD_STORAGE,                          // 手动装载设备(对应结构体DH_LOAD_STORAGE_DEVICE)
    DH_CTRL_CLOSE_BURNER,                          // 关闭刻录机光驱门(对应结构体 NET_CTRL_BURNERDOOR) 一般需要等6秒
    DH_CTRL_EJECT_BURNER,                          // 弹出刻录机光驱门(对应结构体 NET_CTRL_BURNERDOOR) 一般需要等4秒
    DH_CTRL_CLEAR_ALARM,                           // 消警(对应结构体 NET_CTRL_CLEAR_ALARM)
    DH_CTRL_MONITORWALL_TVINFO,                    // 电视墙信息显示(对应结构体 NET_CTRL_MONITORWALL_TVINFO)
    DH_CTRL_START_VIDEO_ANALYSE,                   // 开始视频智能分析(对应结构体 NET_CTRL_START_VIDEO_ANALYSE)
    DH_CTRL_STOP_VIDEO_ANALYSE,                    // 停止视频智能分析(对应结构体 NET_CTRL_STOP_VIDEO_ANALYSE)
    DH_CTRL_UPGRADE_DEVICE,                        // 控制启动设备升级,由设备独立完成升级过程,不需要传输升级文件
    DH_CTRL_MULTIPLAYBACK_CHANNALES,               // 切换多通道预览回放的通道(对应结构体 NET_CTRL_MULTIPLAYBACK_CHANNALES)
    DH_CTRL_SEQPOWER_OPEN,                         // 电源时序器打开开关量输出口(对应 NET_CTRL_SEQPOWER_PARAM)
    DH_CTRL_SEQPOWER_CLOSE,                        // 电源时序器关闭开关量输出口(对应 NET_CTRL_SEQPOWER_PARAM)
    DH_CTRL_SEQPOWER_OPEN_ALL,                     // 电源时序器打开开关量输出口组(对应 NET_CTRL_SEQPOWER_PARAM)
    DH_CTRL_SEQPOWER_CLOSE_ALL,                    // 电源时序器关闭开关量输出口组(对应 NET_CTRL_SEQPOWER_PARAM)
    DH_CTRL_PROJECTOR_RISE,                        // 投影仪上升(对应 NET_CTRL_PROJECTOR_PARAM)
    DH_CTRL_PROJECTOR_FALL,                        // 投影仪下降(对应 NET_CTRL_PROJECTOR_PARAM)
    DH_CTRL_PROJECTOR_STOP,                        // 投影仪停止(对应 NET_CTRL_PROJECTOR_PARAM)
    DH_CTRL_INFRARED_KEY,                          // 红外按键(对应 NET_CTRL_INFRARED_KEY_PARAM)
    DH_CTRL_START_PLAYAUDIO,                       // 设备开始播放音频文件(对应结构体 NET_CTRL_START_PLAYAUDIO)
    DH_CTRL_STOP_PLAYAUDIO,                        // 设备停止播放音频文件
    DH_CTRL_START_ALARMBELL,                       // 开启警号(对应结构体 NET_CTRL_ALARMBELL)
    DH_CTRL_STOP_ALARMBELL,                        // 关闭警号(对应结构体 NET_CTRL_ALARMBELL)
    DH_CTRL_ACCESS_OPEN,                           // 门禁控制-开门(对应结构体 NET_CTRL_ACCESS_OPEN)
    DH_CTRL_SET_BYPASS,                            // 设置旁路功能(对应结构体 NET_CTRL_SET_BYPASS)
    DH_CTRL_RECORDSET_INSERT,                      // 添加记录，获得记录集编号(对应NET_CTRL_RECORDSET_INSERT_PARAM)
    DH_CTRL_RECORDSET_UPDATE,                      // 更新某记录集编号的记录(对应NET_CTRL_RECORDSET_PARAM)
    DH_CTRL_RECORDSET_REMOVE,                      // 根据记录集编号删除某记录(对应NET_CTRL_RECORDSET_PARAM)
    DH_CTRL_RECORDSET_CLEAR,                       // 清除所有记录集信息(对应NET_CTRL_RECORDSET_PARAM)
    DH_CTRL_ACCESS_CLOSE,                          // 门禁控制-关门(对应结构体 NET_CTRL_ACCESS_CLOSE)
	DH_CTRL_ALARM_SUBSYSTEM_ACTIVE_SET,			   // 报警子系统激活设置(对应结构体NET_CTRL_ALARM_SUBSYSTEM_SETACTIVE)
    DH_CTRL_FORBID_OPEN_STROBE,                    // 禁止设备端开闸(对应结构体 NET_CTRL_FORBID_OPEN_STROBE)
    DH_CTRL_OPEN_STROBE,                           // 开启道闸(对应结构体 NET_CTRL_OPEN_STROBE)
    DH_CTRL_TALKING_REFUSE,                        // 对讲拒绝接听(对应结构体 NET_CTRL_TALKING_REFUSE)
	DH_CTRL_NET_KEYBOARD = 400,                    // 网络键盘控制(对应结构体 DHCTRL_NET_KEYBOARD)
} CtrlType;

// IO控制命令，对应CLIENT_QueryIOControlState接口
typedef enum _IOTYPE
{
    DH_ALARMINPUT = 1,                             // 控制报警输入
    DH_ALARMOUTPUT = 2,                            // 控制报警输出
    DH_DECODER_ALARMOUT = 3,                       // 控制报警解码器输出
    DH_WIRELESS_ALARMOUT = 5,                      // 控制无线报警输出
    DH_ALARM_TRIGGER_MODE = 7,                     // 报警触发方式（手动,自动,关闭），使用TRIGGER_MODE_CONTROL结构体
} DH_IOTYPE;

/////////////////////////////////配置相关/////////////////////////////////

// 分辨率枚举，供DH_DSP_ENCODECAP使用
typedef enum _CAPTURE_SIZE
{
    CAPTURE_SIZE_D1,                               // 704*576(PAL)  704*480(NTSC)
    CAPTURE_SIZE_HD1,                              // 352*576(PAL)  352*480(NTSC)
    CAPTURE_SIZE_BCIF,                             // 704*288(PAL)  704*240(NTSC)
    CAPTURE_SIZE_CIF,                              // 352*288(PAL)  352*240(NTSC)
    CAPTURE_SIZE_QCIF,                             // 176*144(PAL)  176*120(NTSC)
    CAPTURE_SIZE_VGA,                              // 640*480
    CAPTURE_SIZE_QVGA,                             // 320*240
    CAPTURE_SIZE_SVCD,                             // 480*480
    CAPTURE_SIZE_QQVGA,                            // 160*128
    CAPTURE_SIZE_SVGA,                             // 800*592
    CAPTURE_SIZE_XVGA,                             // 1024*768
    CAPTURE_SIZE_WXGA,                             // 1280*800
    CAPTURE_SIZE_SXGA,                             // 1280*1024  
    CAPTURE_SIZE_WSXGA,                            // 1600*1024  
    CAPTURE_SIZE_UXGA,                             // 1600*1200
    CAPTURE_SIZE_WUXGA,                            // 1920*1200
    CAPTURE_SIZE_LTF,                              // 240*192
    CAPTURE_SIZE_720,                              // 1280*720
    CAPTURE_SIZE_1080,                             // 1920*1080
    CAPTURE_SIZE_1_3M,                             // 1280*960
    CAPTURE_SIZE_2M,                               // 1872*1408
    CAPTURE_SIZE_5M,                               // 3744*1408
    CAPTURE_SIZE_3M,                               // 2048*1536
    CAPTURE_SIZE_5_0M,                             // 2432*2050
    CPTRUTE_SIZE_1_2M,                             // 1216*1024
    CPTRUTE_SIZE_1408_1024,                        // 1408*1024
    CPTRUTE_SIZE_8M,                               // 3296*2472
    CPTRUTE_SIZE_2560_1920,                        // 2560*1920(5M)
    CAPTURE_SIZE_960H,                             // 960*576(PAL) 960*480(NTSC)
    CAPTURE_SIZE_960_720,                          // 960*720
    CAPTURE_SIZE_NHD,                              // 640*360
    CAPTURE_SIZE_QNHD,                             // 320*180
    CAPTURE_SIZE_QQNHD,                            // 160*90
    CAPTURE_SIZE_960_540,                          // 960*540
    CAPTURE_SIZE_640_352,                          // 640*352
    CAPTURE_SIZE_640_400,                          // 640*400
    CAPTURE_SIZE_320_192,                          // 320*192    
    CAPTURE_SIZE_320_176,                          // 320*176
    CAPTURE_SIZE_NR=255  
} CAPTURE_SIZE;

// 配置文件类型，供CLIENT_ExportConfigFile接口使用
typedef enum __DH_CONFIG_FILE_TYPE
{
    DH_CONFIGFILE_ALL = 0,                         // 全部配置文件
    DH_CONFIGFILE_LOCAL,                           // 本地配置文件
    DH_CONFIGFILE_NETWORK,                         // 网络配置文件
    DH_CONFIGFILE_USER,                            // 用户配置文件
} DH_CONFIG_FILE_TYPE;

// NTP
typedef enum __DH_TIME_ZONE_TYPE
{
    DH_TIME_ZONE_0,                                // {0, 0*3600,"GMT+00:00"}
    DH_TIME_ZONE_1,                                // {1, 1*3600,"GMT+01:00"}
    DH_TIME_ZONE_2,                                // {2, 2*3600,"GMT+02:00"}
    DH_TIME_ZONE_3,                                // {3, 3*3600,"GMT+03:00"}
    DH_TIME_ZONE_4,                                // {4, 3*3600+1800,"GMT+03:30"}
    DH_TIME_ZONE_5,                                // {5, 4*3600,"GMT+04:00"}
    DH_TIME_ZONE_6,                                // {6, 4*3600+1800,"GMT+04:30"}
    DH_TIME_ZONE_7,                                // {7, 5*3600,"GMT+05:00"}
    DH_TIME_ZONE_8,                                // {8, 5*3600+1800,"GMT+05:30"}
    DH_TIME_ZONE_9,                                // {9, 5*3600+1800+900,"GMT+05:45"}
    DH_TIME_ZONE_10,                               // {10, 6*3600,"GMT+06:00"}
    DH_TIME_ZONE_11,                               // {11, 6*3600+1800,"GMT+06:30"}
    DH_TIME_ZONE_12,                               // {12, 7*3600,"GMT+07:00"}
    DH_TIME_ZONE_13,                               // {13, 8*3600,"GMT+08:00"}
    DH_TIME_ZONE_14,                               // {14, 9*3600,"GMT+09:00"}
    DH_TIME_ZONE_15,                               // {15, 9*3600+1800,"GMT+09:30"}
    DH_TIME_ZONE_16,                               // {16, 10*3600,"GMT+10:00"}
    DH_TIME_ZONE_17,                               // {17, 11*3600,"GMT+11:00"}
    DH_TIME_ZONE_18,                               // {18, 12*3600,"GMT+12:00"}
    DH_TIME_ZONE_19,                               // {19, 13*3600,"GMT+13:00"}
    DH_TIME_ZONE_20,                               // {20, -1*3600,"GMT-01:00"}
    DH_TIME_ZONE_21,                               // {21, -2*3600,"GMT-02:00"}
    DH_TIME_ZONE_22,                               // {22, -3*3600,"GMT-03:00"}
    DH_TIME_ZONE_23,                               // {23, -3*3600-1800,"GMT-03:30"}
    DH_TIME_ZONE_24,                               // {24, -4*3600,"GMT-04:00"}
    DH_TIME_ZONE_25,                               // {25, -5*3600,"GMT-05:00"}
    DH_TIME_ZONE_26,                               // {26, -6*3600,"GMT-06:00"}
    DH_TIME_ZONE_27,                               // {27, -7*3600,"GMT-07:00"}
    DH_TIME_ZONE_28,                               // {28, -8*3600,"GMT-08:00"}
    DH_TIME_ZONE_29,                               // {29, -9*3600,"GMT-09:00"}
    DH_TIME_ZONE_30,                               // {30, -10*3600,"GMT-10:00"}
    DH_TIME_ZONE_31,                               // {31, -11*3600,"GMT-11:00"}
    DH_TIME_ZONE_32,                               // {32, -12*3600,"GMT-12:00"}
} DH_TIME_ZONE_TYPE;

typedef enum _SNAP_TYPE
{
    SNAP_TYP_TIMING = 0,
    SNAP_TYP_ALARM,
    SNAP_TYP_NUM,
} SNAP_TYPE;

typedef enum _CONNECT_STATE
{
    CONNECT_STATE_UNCONNECT  = 0,
    CONNECT_STATE_CONNECTING,
    CONNECT_STATE_CONNECTED,
    CONNECT_STATE_ERROR = 255,
} CONNECT_STATE;

// 抓拍模式
typedef enum tagDH_TRAFFIC_SNAP_MODE
{    
    DH_TRAFFIC_SNAP_MODE_COIL = 1,                       // 线圈抓拍
    DH_TRAFFIC_SNAP_MODE_COIL_PICANALYSIS,               // 线圈抓拍, 图片分析
    DH_TRAFFIC_SNAP_MODE_STREAM,                         // 视频抓拍
    DH_TRAFFIC_SNAP_MODE_STREAM_IDENTIFY,                // 视频抓拍, 并且识别
} DH_TRAFFIC_SNAP_MODE;

// 车位灯类型
typedef enum 
{
    NET_CARPORTLIGHT_TYPE_RED,                           // 红灯
    NET_CARPORTLIGHT_TYPE_GREEN,                         // 绿灯
}NET_CARPORTLIGHT_TYPE;

// 车位灯亮灯方式
typedef enum
{
    NET_CARPORTLIGHT_MODE_OFF,                           // 灭 
    NET_CARPORTLIGHT_MODE_ON,                            // 亮
    NET_CARPORTLIGHT_MODE_GLINT,                         // 闪烁
}NET_CARPORTLIGHT_MODE;

/////////////////////////////////智能交通相关/////////////////////////////////
//黑白名单操作类型
typedef enum _EM_OPERATE_TYPE
{
    NET_TRAFFIC_LIST_INSERT,                             // 增加记录操作
    NET_TRAFFIC_LIST_UPDATE,                             // 更新记录操作
    NET_TRAFFIC_LIST_REMOVE,                             // 删除记录操作
    NET_TRAFFIC_LIST_MAX,
}EM_RECORD_OPERATE_TYPE ;

//车牌类型
typedef enum _EM_NET_PLATE_TYPE
{
    NET_PLATE_TYPE_UNKNOWN,
    NET_PLATE_TYPE_NORMAL,                              // "Normal" 蓝牌黑牌
    NET_PLATE_TYPE_YELLOW,                              // "Yellow" 黄牌
    NET_PLATE_TYPE_DOUBLEYELLOW,                        // "DoubleYellow" 双层黄尾牌
    NET_PLATE_TYPE_POLICE,                              // "Police" 警牌
    NET_PLATE_TYPE_ARMED,                               // "Armed" 武警牌
    NET_PLATE_TYPE_MILITARY,                            // "Military" 部队号牌
    NET_PLATE_TYPE_DOUBLEMILITARY,                      // "DoubleMilitary" 部队双层
    NET_PLATE_TYPE_SAR,                                 // "SAR" 港澳特区号牌    
    NET_PLATE_TYPE_TRAINNING,                           // "Trainning" 教练车号牌
    NET_PLATE_TYPE_PERSONAL,                            // "Personal" 个性号牌
    NET_PLATE_TYPE_AGRI,                                // "Agri" 农用牌
    NET_PLATE_TYPE_EMBASSY,                             // "Embassy" 使馆号牌
    NET_PLATE_TYPE_MOTO,                                // "Moto" 摩托车号牌
    NET_PLATE_TYPE_TRACTOR,                             // "Tractor" 拖拉机号牌
    NET_PLATE_TYPE_OFFICIALCAR,                         // "OfficialCar " 公务车
    NET_PLATE_TYPE_PERSONALCAR,                         // "PersonalCar" 私家车
    NET_PLATE_TYPE_WARCAR,                              // "WarCar"  军用
    NET_PLATE_TYPE_OTHER,                               // "Other" 其他号牌
}EM_NET_PLATE_TYPE;


//车牌颜色
typedef enum _EM_NET_PLATE_COLOR_TYPE
{
    NET_PLATE_COLOR_OTHER,                              // 其他颜色
    NET_PLATE_COLOR_BLUE,                               // 蓝色 "Blue"
    NET_PLATE_COLOR_YELLOW,                             // 黄色 "Yellow"    
    NET_PLATE_COLOR_WHITE,                              // 白色 "White"
    NET_PLATE_COLOR_BLACK,                              // 黑色 "Black"
    NET_PLATE_COLOR_YELLOW_BOTTOM_BLACK_TEXT,           // 黄底黑字 "YellowbottomBlackText"
    NET_PLATE_COLOR_BLUE_BOTTOM_WHITE_TEXT,             // 蓝底白字 "BluebottomWhiteText" 
    NET_PLATE_COLOR_BLACK_BOTTOM_WHITE_TEXT,            // 黑底白字 "BlackBottomWhiteText"
}EM_NET_PLATE_COLOR_TYPE;

//车辆类型
typedef enum _EM_NET_VEHICLE_TYPE
{
    NET_VEHICLE_TYPE_UNKNOW,                            // 未知类型
    NET_VEHICLE_TYPE_MOTOR,                             // "Motor" 机动车           
    NET_VEHICLE_TYPE_NON_MOTOR,                         // "Non-Motor"非机动车        
    NET_VEHICLE_TYPE_BUS,                               // "Bus"公交车        
    NET_VEHICLE_TYPE_BICYCLE,                           // "Bicycle" 自行车        
    NET_VEHICLE_TYPE_MOTORCYCLE,                        // "Motorcycle"摩托车        
    NET_VEHICLE_TYPE_UNLICENSEDMOTOR,                   // "UnlicensedMotor": 无牌机动车
    NET_VEHICLE_TYPE_LARGECAR,                          // "LargeCar"  大型汽车
    NET_VEHICLE_TYPE_MICROCAR,                          // "MicroCar" 小型汽车
    NET_VEHICLE_TYPE_EMBASSYCAR,                        // "EmbassyCar" 使馆汽车
    NET_VEHICLE_TYPE_MARGINALCAR,                       // "MarginalCar" 领馆汽车
    NET_VEHICLE_TYPE_AREAOUTCAR,                        // "AreaoutCar" 境外汽车
    NET_VEHICLE_TYPE_FOREIGNCAR,                        // "ForeignCar" 外籍汽车
    NET_VEHICLE_TYPE_DUALTRIWHEELMOTORCYCLE,            // "DualTriWheelMotorcycle"两、三轮摩托车
    NET_VEHICLE_TYPE_LIGHTMOTORCYCLE,                   // "LightMotorcycle" 轻便摩托车
    NET_VEHICLE_TYPE_EMBASSYMOTORCYCLE,                 // "EmbassyMotorcycle "使馆摩托车
    NET_VEHICLE_TYPE_MARGINALMOTORCYCLE,                // "MarginalMotorcycle "领馆摩托车
    NET_VEHICLE_TYPE_AREAOUTMOTORCYCLE,                 // "AreaoutMotorcycle "境外摩托车
    NET_VEHICLE_TYPE_FOREIGNMOTORCYCLE,                 // "ForeignMotorcycle "外籍摩托车
    NET_VEHICLE_TYPE_FARMTRANSMITCAR,                   // "FarmTransmitCar" 农用运输车
    NET_VEHICLE_TYPE_TRACTOR,                           // "Tractor" 拖拉机
    NET_VEHICLE_TYPE_TRAILER,                           // "Trailer"  挂车
    NET_VEHICLE_TYPE_COACHCAR,                          // "CoachCar"教练汽车
    NET_VEHICLE_TYPE_COACHMOTORCYCLE,                   // "CoachMotorcycle "教练摩托车
    NET_VEHICLE_TYPE_TRIALCAR,                          // "TrialCar" 试验汽车
    NET_VEHICLE_TYPE_TRIALMOTORCYCLE,                   // "TrialMotorcycle "试验摩托车
    NET_VEHICLE_TYPE_TEMPORARYENTRYCAR,                 // "TemporaryEntryCar"临时入境汽车
    NET_VEHICLE_TYPE_TEMPORARYENTRYMOTORCYCLE,          // "TemporaryEntryMotorcycle"临时入境摩托车
    NET_VEHICLE_TYPE_TEMPORARYSTEERCAR,                 // "TemporarySteerCar"临时行驶车
    NET_VEHICLE_TYPE_PASSENGERCAR,                      // "PassengerCar" 客车
    NET_VEHICLE_TYPE_LARGETRUCK,                        // "LargeTruck" 大货车
    NET_VEHICLE_TYPE_MIDTRUCK,                          // "MidTruck" 中货车
    NET_VEHICLE_TYPE_SALOONCAR,                         // "SaloonCar" 轿车
    NET_VEHICLE_TYPE_MICROBUS,                          // "Microbus"面包车
    NET_VEHICLE_TYPE_MICROTRUCK,                        // "MicroTruck"小货车
    NET_VEHICLE_TYPE_TRICYCLE,                          // "Tricycle"三轮车
    NET_VEHICLE_TYPE_PASSERBY,                          // "Passerby" 行人
}EM_NET_VEHICLE_TYPE;


//车身颜色
typedef enum _EM_NET_VEHICLE_COLOR_TYPE
{
    NET_VEHICLE_COLOR_OTHER,                            //其他颜色    
    NET_VEHICLE_COLOR_WHITE,                            //白色 "White"
    NET_VEHICLE_COLOR_BLACK,                            //黑色 "Black"
    NET_VEHICLE_COLOR_RED,                              //红色 "Red"
    NET_VEHICLE_COLOR_YELLOW,                           //黄色 "Yellow"
    NET_VEHICLE_COLOR_GRAY,                             //灰色 "Gray"
    NET_VEHICLE_COLOR_BLUE,                             //蓝色 "Blue"
    NET_VEHICLE_COLOR_GREEN,                            //绿色 "Green"
    NET_VEHICLE_COLOR_PINK,                             //粉红色 "Pink"
    NET_VEHICLE_COLOR_PURPLE,                           //紫色 "Purple"
    NET_VEHICLE_COLOR_BROWN,                            //棕色 "Brown"
}EM_NET_VEHICLE_COLOR_TYPE;

//布控类型
typedef enum _EM_NET_TRAFFIC_CAR_CONTROL_TYPE
{
    NET_CAR_CONTROL_OTHER,
    NET_CAR_CONTROL_OVERDUE_NO_CHECK,                   // 过期未检 "OverdueNoCheck"
    NET_CAR_CONTROL_BRIGANDAGE_CAR,                     // 盗抢车辆 "BrigandageCar"
    NET_CAR_CONTROL_BREAKING,                           // 肇事逃逸 "CausetroubleEscape"
    NET_CAR_CONTROL_CAUSETROUBLE_ESCAPE,                // 违章 "Breaking"
}EM_NET_TRAFFIC_CAR_CONTROL_TYPE;

typedef enum _EM_NET_AUTHORITY_TYPE
{
    NET_AUTHORITY_UNKNOW,
    NET_AUTHORITY_OPEN_GATE,                            //开闸权限
}EM_NET_AUTHORITY_TYPE;

typedef enum _EM_NET_RECORD_TYPE
{
    NET_RECORD_UNKNOWN,
    NET_RECORD_TRAFFICREDLIST,                          // 交通白名单账户记录
    NET_RECORD_TRAFFICBLACKLIST,                        // 交通黑名单账号记录
    NET_RECORD_BURN_CASE,                               // 刻录案件记录
    NET_RECORD_ACCESSCTLCARD,                           // 门禁卡,对应NET_RECORDSET_ACCESS_CTL_CARD
    NET_RECORD_ACCESSCTLPWD,                            // 门禁密码,对应NET_RECORDSET_ACCESS_CTL_PWD
    NET_RECORD_ACCESSCTLCARDREC,                        // 门禁出入记录,对应NET_RECORDSET_ACCESS_CTL_CARDREC
    NET_RECORD_ACCESSCTLHOLIDAY,                        // 假日记录集, 对应NET_RECORDSET_HOLIDAY
}EM_NET_RECORD_TYPE;

// 时间类型
typedef enum
{
    NET_TIME_TYPE_ABSLUTE,                                  // 绝对时间
    NET_TIME_TYPE_RELATIVE,                                 // 相对时间，相对于视频文件头帧为时间基点,头帧对应于UTC(0000-00-00 00:00:00)
}EM_TIME_TYPE;

// 颜色类型
typedef enum
{
    NET_COLOR_TYPE_RED,                                     // 红色
    NET_COLOR_TYPE_YELLOW,                                  // 黄色
    NET_COLOR_TYPE_GREEN,                                   // 绿色
    NET_COLOR_TYPE_CYAN,                                    // 青色
    NET_COLOR_TYPE_BLUE,                                    // 蓝色
    NET_COLOR_TYPE_PURPLE,                                  // 紫色
    NET_COLOR_TYPE_BLACK,                                   // 黑色
    NET_COLOR_TYPE_WHITE,                                   // 白色
    NET_COLOR_TYPE_MAX,
}EM_COLOR_TYPE;

/////////////////////////////////人脸识别相关/////////////////////////////////
// 人员类型
typedef enum 
{
    PERSON_TYPE_UNKNOWN,
    PERSON_TYPE_NORMAL,                                     // 普通人员
    PERSON_TYPE_SUSPICION,                                  // 嫌疑人员
}EM_PERSON_TYPE;

// 证件类型
typedef enum
{
    CERTIFICATE_TYPE_UNKNOWN,
    CERTIFICATE_TYPE_IC,                                    // 身份证
    CERTIFICATE_TYPE_PASSPORT,                              // 护照 
}EM_CERTIFICATE_TYPE;

// 人脸识别数据库操作
typedef enum
{
    NET_FACERECONGNITIONDB_UNKOWN, 
    NET_FACERECONGNITIONDB_ADD,                         // 添加人员信息和人脸样本，如果人员已经存在，图片数据和原来的数据合并
    NET_FACERECONGNITIONDB_DELETE,                      // 删除人员信息和人脸样本
}EM_OPERATE_FACERECONGNITIONDB_TYPE;

// 人脸对比模式
typedef enum 
{
    NET_FACE_COMPARE_MODE_UNKOWN,
    NET_FACE_COMPARE_MODE_NORMAL,                       // 正常
    NET_FACE_COMPARE_MODE_AREA,                         // 指定人脸区域组合区域
    NET_FACE_COMPARE_MODE_AUTO,                         // 智能模式，算法根据人脸各个区域情况自动选取组合 
}EM_FACE_COMPARE_MODE;

// 人脸区域
typedef enum
{
    NET_FACE_AREA_TYPE_UNKOWN,
    NET_FACE_AREA_TYPE_EYEBROW,                         // 眉毛
    NET_FACE_AREA_TYPE_EYE,                             // 眼睛
    NET_FACE_AREA_TYPE_NOSE,                            // 鼻子
    NET_FACE_AREA_TYPE_MOUTH,                           // 嘴巴
    NET_FACE_AREA_TYPE_CHEEK,                           // 脸颊
}EM_FACE_AREA_TYPE;

// 人脸数据类型
typedef enum
{
    NET_FACE_DB_TYPE_UNKOWN,
    NET_FACE_DB_TYPE_HISTORY,                           // 历史数据库，存放的是检测出的人脸信息，一般没有包含人脸对应人员信息
    NET_FACE_DB_TYPE_BLACKLIST,                         // 黑名单数据库
    NET_FACE_DB_TYPE_WHITELIST,                         // 白名单数据库
}EM_FACE_DB_TYPE;

// 人脸识别事件类型
typedef enum 
{
    NET_FACERECOGNITION_ALARM_TYPE_UNKOWN,
    NET_FACERECOGNITION_ALARM_TYPE_ALL,                // 黑白名单
    NET_FACERECOGNITION_ALARM_TYPE_BLACKLIST,          // 黑名单
    NET_FACERECOGNITION_ALARM_TYPE_WHITELIST,          // 白名单
}EM_FACERECOGNITION_ALARM_TYPE;

// 人脸识别人脸类型
typedef enum
{
    EM_FACERECOGNITION_FACE_TYPE_UNKOWN,
    EM_FACERECOGNITION_FACE_TYPE_ALL,                  // 所有人脸   
    EM_FACERECOGNITION_FACE_TYPE_REC_SUCCESS,          // 识别成功
    EM_FACERECOGNITION_FACE_TYPE_REC_FAIL,             // 识别失败
}EM_FACERECOGNITION_FACE_TYPE;

// 帧类型枚举值  
typedef enum __EM_FRAME_TYPE
{
    EM_FRAME_UNKOWN,                                   // 未知类型 
    EM_FRAME_TYPE_MOTION,                              // 动检帧，对应帧信息结构体 NET_MOTION_FRAM_INFO
}EM_FRAME_TYPE;

/////////////////////////////////淘汰类型/////////////////////////////////

// 配置类型，目前使用该枚举的接口已淘汰，请不要使用
typedef enum _CFG_INDEX
{
    CFG_GENERAL = 0,                                    // 普通
    CFG_COMM,                                           // 串口
    CFG_NET,                                            // 网络
    CFG_RECORD,                                         // 录像
    CFG_CAPTURE,                                        // 图像设置
    CFG_PTZ,                                            // 云台
    CFG_DETECT,                                         // 动态检测
    CFG_ALARM,                                          // 报警
    CFG_DISPLAY,                                        // 显示
    CFG_RESERVED,                                       // 保留，使类型连贯
    CFG_TITLE = 10,                                     // 通道标题
    CFG_MAIL = 11,                                      // 邮件功能
    CFG_EXCAPTURE = 12,                                 // 预览图像设置
    CFG_PPPOE = 13,                                     // pppoe设置
    CFG_DDNS = 14,                                      // DDNS设置
    CFG_SNIFFER    = 15,                                // 网络监视捕获设置
    CFG_DSPINFO    = 16,                                // 编码能力信息
    CFG_COLOR = 126,                                    // 颜色配置信息
    CFG_ALL,                                            // 保留
} CFG_INDEX;

/************************************************************************
 ** 结构体定义
 ***********************************************************************/
//显示区域相对于原显示窗口的坐标
typedef struct
{
    double                dleft;                  //显示区域相对于原显示窗口的左坐标 
    double                dright;                 //显示区域相对于原显示窗口的右坐标
    double                dtop;                   //显示区域相对于原显示窗口的上坐标
    double                dbottom;                //显示区域相对于原显示窗口的下坐标
} DH_DISPLAYRREGION;
// 时间
typedef struct 
{
    DWORD                dwYear;                  // 年
    DWORD                dwMonth;                 // 月
    DWORD                dwDay;                   // 日
    DWORD                dwHour;                  // 时
    DWORD                dwMinute;                // 分
    DWORD                dwSecond;                // 秒
} NET_TIME,*LPNET_TIME;

typedef struct 
{
    DWORD                dwYear;                  // 年
    DWORD                dwMonth;                 // 月
    DWORD                dwDay;                   // 日
    DWORD                dwHour;                  // 时
    DWORD                dwMinute;                // 分
    DWORD                dwSecond;                // 秒
    DWORD                dwMillisecond;           // 毫秒
    DWORD                dwReserved[2];           // 保留字段
} NET_TIME_EX,*LPNET_TIME_EX;

// 日志信息里的时间定义
typedef struct _DHDEVTIME
{
    DWORD                second:6;                // 秒    1-60        
    DWORD                minute:6;                // 分    1-60        
    DWORD                hour:5;                  // 时    1-24        
    DWORD                day:5;                   // 日    1-31        
    DWORD                month:4;                 // 月    1-12        
    DWORD                year:6;                  // 年    2000-2063    
} DHDEVTIME, *LPDHDEVTIME;

// 回调数据(异步接口)
typedef struct __NET_CALLBACK_DATA 
{
    int                  nResultCode;            // 返回码；0：成功
    char                 *pBuf;                  // 接收数据, 缓冲是由用户开辟的，从接口形参传入
    int                  nRetLen;                // 接收长度
    LLONG                lOperateHandle;         // 操作句柄
    void*                userdata;               // 操作对应用户参数
    char                 reserved[16];
} NET_CALLBACK_DATA, *LPNET_CALLBACK_DATA;

///////////////////////////////监视相关定义///////////////////////////////

// 回调视频数据帧的帧参数结构体
typedef struct _tagVideoFrameParam
{
    BYTE                 encode;                 // 编码类型
    BYTE                 frametype;              // I = 0, P = 1, B = 2...
    BYTE                 format;                 // PAL - 0, NTSC - 1
    BYTE                 size;                   // CIF - 0, HD1 - 1, 2CIF - 2, D1 - 3, VGA - 4, QCIF - 5, QVGA - 6 ,
                                                 // SVCD - 7,QQVGA - 8, SVGA - 9, XVGA - 10,WXGA - 11,SXGA - 12,WSXGA - 13,UXGA - 14,WUXGA - 15, LFT - 16, 720 - 17, 1080 - 18
    DWORD                fourcc;                 // 如果是H264编码则总为0，MPEG4这里总是填写FOURCC('X','V','I','D');
    DWORD                reserved;               // 保留
    NET_TIME             struTime;               // 时间信息
} tagVideoFrameParam;

// 回调音频数据帧的帧参数结构体
typedef struct _tagCBPCMDataParam
{
    BYTE                channels;                // 声道数
    BYTE                samples;                 // 采样 0 - 8000, 1 - 11025, 2 - 16000, 3 - 22050, 4 - 32000, 5 - 44100, 6 - 48000
    BYTE                depth;                   // 采样深度 取值8或者16等。直接表示
    BYTE                param1;                  // 0 - 指示无符号，1-指示有符号
    DWORD               reserved;                // 保留
} tagCBPCMDataParam;

// 通道画面字幕叠加的数据结构
typedef struct _DH_CHANNEL_OSDSTRING
{
    BOOL                bEnable;                            // 使能
    DWORD               dwPosition[MAX_STRING_LINE_LEN];    //各行字符的位置　用1-9整数表示，与小键盘位置对应
                                                            // 7左上    8上        9右上
                                                            // 4左      5中        6右
                                                            // 1左下    2下        3右下
    char                szStrings[MAX_STRING_LINE_LEN][MAX_PER_STRING_LEN];    // 最多六行字符，每行最多20个字节
} DH_CHANNEL_OSDSTRING;

//回调YUV数据的参数结构体
typedef struct _tagCBYUVDataParam
{
    long                nWidth;                 // 图象的宽
    long                nHeight;                // 图象的高
    DWORD               reserved[8];            // 保留
} tagCBYUVDataParam;

///////////////////////////////回放相关定义///////////////////////////////

// 录像文件信息
typedef struct
{

    unsigned int        ch;                         // 通道号
    char                filename[124];              // 文件名
    unsigned int        framenum;                   // 文件总帧数
    unsigned int        size;                       // 文件长度
    NET_TIME            starttime;                  // 开始时间
    NET_TIME            endtime;                    // 结束时间
    unsigned int        driveno;                    // 磁盘号(区分网络录像和本地录像的类型，0－127表示本地录像,其中64表示光盘1，128表示网络录像)
    unsigned int        startcluster;               // 起始簇号
    BYTE                nRecordFileType;            // 录象文件类型  0：普通录象；1：报警录象；2：移动检测；3：卡号录象；4：图片, 5: 智能录像
    BYTE                bImportantRecID;            // 0:普通录像 1:重要录像
    BYTE                bHint;                      // 文件定位索引
    BYTE                bRecType;                   // 0-主码流录像 1-辅码1流录像 2-辅码流2 3-辅码流3录像
} NET_RECORDFILE_INFO, *LPNET_RECORDFILE_INFO;

// 浓缩录像文件信息
typedef struct tagNET_SynopsisFileInfo
{
    DWORD               dwSize;                     // 该结构体大小
    char                szFileName[MAX_PATH];       // 文件名，例如C:\a.dav
    NET_TIME            stuStartTime;               // 开始时间
    NET_TIME            stuEndTime;                 // 结束时间
    unsigned int        nTaskID;                    // 在服务器里的标示，与文件名2选1使用
    BYTE                bFileType;                  // 1-视频浓缩录像文件，2-视频浓缩源文件
    BYTE                byMode;                     // 下载模式: 0-按文件下载, 1-按时间下载, 2-按文件偏移下载
    BYTE                bReserved[2];
    unsigned int        nFileLength;                // 文件大小，单位:KB
    unsigned int        nStartFileOffset;           // 起始文件偏移, 单位: KB
    unsigned int        nEndFileOffset;             // 结束文件偏移, 单位: KB
}NET_SYNOPSISFILE_INFO, *LPNET_SYNOPSISFILE_INFO;

// 回放数据回调函数原形
typedef int (CALLBACK *fDataCallBack)(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser);

typedef struct __NET_MULTI_PLAYBACK_PARAM 
{
    DWORD                      dwSize; 
    int                        nChannels[DH_MAX_MULTIPLAYBACK_CHANNEL_NUM]; // 预览通道号
    int                        nChannelNum;                             // 预览通道数 
    int                        nType;                                   // 回放文件类型，0：普通录象；1：报警录象；2：移动检测；3：卡号录象；4：图片
    NET_TIME                   stStartTime;                             // 回放开始时间
    NET_TIME                   stEndTime;                               // 回放结束时间
    int                        nFPS;                                    // 帧率,1~25
    int                        nBitRate;                                // 码流值,192~1024
    char                       szResolution[DH_MAX_CAPTURE_SIZE_NUM];   // 分辨率，"D1"、"HD1"、"2CIF"、"CIF"、"QCIF"   
    int                        nWaitTime;                               // 超时等待时间 
    HWND                       hWnd;                                    // 视频播放窗口句柄
    fDataCallBack              fDownLoadDataCallBack;                   // 视频数据回调
    LDWORD                     dwDataUser;                              // 
}NET_MULTI_PLAYBACK_PARAM;

// 某月的各天是否存在录像的状态信息
typedef struct
{
    BYTE        flag[32];           //某月内的各天是否存在录像的状态掩码，0表示没有，1表示有。
    BYTE        Reserved[64];       //保留
}NET_RECORD_STATUS, *LPNET_RECORD_STATUS;

// 异步查询结果回调函数原形,nError = 0表示查询成功，nError = 1表示内存申请失败，nError = 2表示超时，nError = 3表示设备返回数据校验不通过，nError = 4 发送查询请求失败
typedef void (CALLBACK *fQueryRecordFileCallBack)(LLONG lQueryHandle, LPNET_RECORDFILE_INFO pFileinfos, int nFileNum, int nError, void *pReserved, LDWORD dwUser);

// CLIENT_StartQueryRecordFile接口输入参数
typedef struct tagNET_IN_START_QUERY_RECORDFILE
{ 
    DWORD               dwSize;                            // 结构体大小
    int                 nChannelId;                        // 待查询通道号
    int                 nRecordFileType;                   // 待查询录像类型 
    int                 nStreamType;                       // 查询码流类型,0-主辅码流,1-主码流,2-辅码流
    NET_TIME            stStartTime;                       // 查询起始时间
    NET_TIME            stEndTime;                         // 查询结束时间
    char*               pchCardid;                         // 卡号信息
    int                 nWaitTime;                         // 超时等待时间，单位ms 
    fQueryRecordFileCallBack cbFunc;                       // 查询结果回调函数 
    LDWORD              dwUser;                            // 用户信息
}NET_IN_START_QUERY_RECORDFILE;

typedef struct tagNET_OUT_START_QUERY_RECORDFILE
{
    DWORD                dwSize;                           // 结构体大小
    LLONG                lQueryHandle;                     // 返回句柄    
}NET_OUT_START_QUERY_RECORDFILE;

typedef struct
{
    unsigned short      left;                        // 0~8192
    unsigned short      right;                       // 0~8192
    unsigned short      top;                         // 0~8192
    unsigned short      bottom;                      // 0~8192
} MotionDetectRect;

// 智能回放信息
typedef struct 
{
    MotionDetectRect    motion_rect;               // 动检帧检索区域
    NET_TIME            stime;                     // 回放的开始时间
    NET_TIME            etime;                     // 回放的结束时间
    BYTE                bStart;                    // 开始停止命令: 1,开始,2:停止
    BYTE                reserved[116];
} IntelligentSearchPlay, *LPIntelligentSearchPlay;

// 最早录像时间
typedef struct  
{
    int                 nChnCount;                  // 通道数目
    NET_TIME            stuFurthestTime[16];        // 最早录像时间,有效值为前面0 到 (nChnCount-1)个.如果某通道没有录象的话，最早录象时间全为0
    DWORD               dwFurthestTimeAllSize;      // 当通道个数大于16时，使用。表示下面pStuFurthestTimeAll这块内存大小。
    NET_TIME*           pStuFurthestTimeAll;        // 当通道个数大于16时，使用。此部分内存需要用户申请,申请大小为(通道个数*sizeof(NET_TIME))。
    BYTE                bReserved[376];             // 保留字段
} NET_FURTHEST_RECORD_TIME;

// CLIENT_FindFramInfo 接口输入参数
typedef struct __NET_IN_FIND_FRAMEINFO_PRAM
{
    DWORD                 dwSize;                   // 结构体大小 
    BOOL                  abFileName;               // 文件名是否作为有效的查询条件，若文件名有效，则不用填充文件信息（stRecordInfo）
    char                  szFileName[MAX_PATH];     // 文件名
    NET_RECORDFILE_INFO   stuRecordInfo;            // 文件信息
    DWORD                 dwFramTypeMask;           // 帧类型掩码，详见“帧类型掩码定义”
}NET_IN_FIND_FRAMEINFO_PRAM;

// CLIENT_FindFramInfo 接口输出参数
typedef struct __NET_OUT_FIND_FRAMEINFO_PRAM
{
    DWORD                 dwSize;               // 结构体大小 
    LLONG                 lFindHandle;          // 文件查找句柄
}NET_OUT_FIND_FRAMEINFO_PRAM;

// 动检帧信息
typedef struct __NET_MOTION_FRAME_INFO
{
    DWORD                 dwSize;               // 结构体大小
    NET_TIME              stuTime;              // 当前帧，时间戳 
    int                   nMotionRow;           // 动态检测区域的行数
    int                   nMotionCol;           // 动态检测区域的列数
    BYTE                  byRegion[DH_MOTION_ROW][DH_MOTION_COL];// 检测区域，最多32*32块区域
}NET_MOTION_FRAME_INFO;

// 文件帧信息
typedef struct __NET_FILE_FRAME_INFO
{
    DWORD                 dwSize;               // 结构体大小
    int                   nChannelId;           // 通道号
    NET_TIME              stuStartTime;         // 开始时间
    NET_TIME              stuEndTime;           // 结束时间
    WORD                  wRecType;             // 0-主码流录像 1-辅码1流录像 2-辅码流2 3-辅码流3录像
    WORD                  wFameType;            // 帧类型，详见EM_FRAM_TYPE
    void*                 pFramInfo;            // 对应类型帧信息，空间由用户申请
}NET_FILE_FRAME_INFO;

// CLIENT_FindNextFramInfo 接口输入参数
typedef struct __NET_IN_FINDNEXT_FRAMEINFO_PRAM
{
    DWORD                 dwSize;               // 结构体大小  
    int                   nFramCount;           // 待查询帧条数，0，表示查询符合查询条件的所有帧信息
}NET_IN_FINDNEXT_FRAMEINFO_PRAM;

// CLIENT_FindNextFramInfo 接口输出参数
typedef struct __NET_OUT_FINDNEXT_FRAMEINFO_PRAM
{
    DWORD                 dwSize;               // 结构体大小 
    NET_FILE_FRAME_INFO*  pFramInfos;           // 帧信息，由用户申请空间，空间大小为 sizeof(NET_FILE_FRAM_INFO) * nMaxFramCount
    int                   nMaxFramCount;        // 用户申请的帧信息个数
    int                   nRetFramCount;        // 实际返回的帧信息个数
}NET_OUT_FINDNEXT_FRAMEINFO_PRAM;

///////////////////////////////报警相关定义///////////////////////////////

// 普通报警信息
typedef struct
{
    int                  channelcount;
    int                  alarminputcount;
    unsigned char        alarm[16];                // 外部报警
    unsigned char        motiondection[16];        // 动态检测
    unsigned char        videolost[16];            // 视频丢失
} NET_CLIENT_STATE;

// 普通报警信息
typedef struct
{
    int                  channelcount;
    int                  alarminputcount;
    unsigned char        alarm[32];                // 外部报警
    unsigned char        motiondection[32];        // 动态检测
    unsigned char        videolost[32];            // 视频丢失
    BYTE                 bReserved[32];
} NET_CLIENT_STATE_EX;

// 外部报警状态信息对应结构体
typedef struct
{
    DWORD                dwSize;
    int                  alarminputcount;
    DWORD                dwAlarmState[DH_MAX_CHANMASK]; //每一个DWORD按位表示32通道的报警状态, 0-表示无报警, 1-表示有报警
}NET_CLIENT_ALARM_STATE;

// 视频丢失报警状态信息对应结构体
typedef struct
{
    DWORD                dwSize;
    int                  channelcount;
    DWORD                dwAlarmState[DH_MAX_CHANMASK]; //每一个DWORD按位表示32通道的报警状态, 0-表示无报警, 1-表示有报警
}NET_CLIENT_VIDEOLOST_STATE;

// 动态检测报警状态信息对应结构体
typedef struct
{
    DWORD                dwSize;
    int                  channelcount;
    DWORD                dwAlarmState[DH_MAX_CHANMASK]; //每一个DWORD按位表示32通道的报警状态, 0-表示无报警, 1-表示有报警
}NET_CLIENT_MOTIONDETECT_STATE;

// 视频遮挡报警状态信息对应结构体
typedef struct
{
    DWORD                dwSize;
    int                  channelcount;
    DWORD                dwAlarmState[DH_MAX_CHANMASK]; //每一个DWORD按位表示32通道的报警状态, 0-表示无报警, 1-表示有报警
}NET_CLIENT_VIDEOBLIND_STATE;

// 查询 动态检测报警状态详细信息对应结构体
typedef struct
{
    DWORD               dwSize;
    int                 nChannelID;                 // 通道号
    BOOL                bAlarm;                     // 是否报警 TRUE/FALSE
    int                 nLevel;                     // 报警级别，单位千分之，以动检发生小格数除以总小格数计算
}NET_CLIENT_DETAILEDMOTION_STATE;

// 报警IO控制
typedef struct 
{
    unsigned short        index;                    // 端口序号
    unsigned short        state;                    // 端口状态
} ALARM_CONTROL;

// 触发方式
typedef struct
{
    unsigned short        index;                    // 端口序号
    unsigned short        mode;                     // 触发方式(0关闭1手动2自动);不设置的通道，sdk默认将保持原来的设置。
    BYTE                  bReserved[28];            
} TRIGGER_MODE_CONTROL;

// 报警解码器控制
typedef struct 
{
    int                     decoderNo;               // 报警解码器号，从0开始
    unsigned short          alarmChn;                // 报警输出口，从0开始
    unsigned short          alarmState;              // 报警输出状态；1：打开，0：关闭
} DECODER_ALARM_CONTROL;

// 呼叫无应答报警事件
typedef struct __ALARM_NO_RESPONSE_INFO
{
	DWORD		dwSize;
	char        szCallID[DH_MAX_CALLID];                             //Call ID
}ALARM_NO_RESPONSE_INFO;

// 报警上传功能的报警信息
typedef struct  
{
    DWORD               dwAlarmType;                            // 报警类型，dwAlarmType = DH_UPLOAD_EVENT时，dwAlarmMask和bAlarmDecoderIndex是无效的
    DWORD               dwAlarmMask;                            // 报警信息掩码，按位表示各报警通道状态
    char                szGlobalIP[DH_MAX_IPADDR_LEN];          // 客户端IP地址
    char                szDomainName[DH_MAX_DOMAIN_NAME_LEN];   // 客户端域名
    int                 nPort;                                  // 报警上传时客户端连接的端口
    char                szAlarmOccurTime[DH_ALARM_OCCUR_TIME_LEN];    // 报警发生的时间
    BYTE                bAlarmDecoderIndex;                     // 表示第几个报警解码器，dwAlarmType = DH_UPLOAD_DECODER_ALARM 才有效.
    BYTE                bReservedSpace[15];
} NEW_ALARM_UPLOAD;

// 报警中心烟感报警事件
typedef struct __ALARM_UPLOAD_SMOKESENSOR_INFO
{
    DWORD           dwSize;
    char            szGlobalIP[DH_MAX_IPADDR_LEN];               // 客户端IP地址
    char            szDomainName[DH_MAX_DOMAIN_NAME_LEN];        // 客户端域名
    int             nPort;                                       // 报警上传时客户端连接的端口
    char            szAlarmOccurTime[DH_ALARM_OCCUR_TIME_LEN];   // 报警发生的时间
    int             nChannel;                                    // 报警通道 从0开始
    BYTE            byHighTemperature;                           // 1:高温报警开始，0：高温报警结束
    BYTE            bySmoke;                                     // 1:烟感报警开始，0：烟感报警结束
}ALARM_UPLOAD_SMOKESENSOR_INFO;

// 报警中心智能报警事件
typedef struct __ALARM_UPLOAD_IVS_INFO
{
    DWORD           dwSize;
    NET_TIME        stuTime;                                    // 事件发生时间    
    char            szDomainName[DH_MAX_DOMAIN_NAME_LEN];       // 客户端域名
    int             nChannelID;                                 // 通道号，从0开始
    char            szType[MAX_PATH];                           // 报警类型, 检测规则
    int             nState;                                     // 报警状态，0-报警复位，1-报警置位, 2-脉冲式报警
    char            szRuleName[DH_COMMON_STRING_128];           // 规则名称  
    char            szIPAddress[DH_MAX_IPADDR_LEN_EX];          // 设备IP地址  
    int             nPort;                                      // 设备端口号
    char            szMacAddress[DH_MACADDR_LEN];               // 设备端mac地址
    char            szPicFilePath[MAX_PATH];                    // 图片存放文件夹路径
    int             nPicFileNum;                                // 当前报警对应的图片文件个数
    int             nUploadPicFileNum;                          // 已上传FTP的图片文件个数
    DWORD           dwChannelMask;                              // 抓图视频通道的掩码，15表示此次报警抓图的有1,2,3,4通道 
} ALARM_UPLOAD_IVS_INFO;

// 报警中心外部报警扩展信息
typedef struct _ALARM_UPLOAD_ALARMEX_INFO
{
    DWORD           dwSize;
    NET_TIME        stuTime;                                    // 事件发生时间    
    char            szDomainName[DH_MAX_DOMAIN_NAME_LEN];       // 客户端域名
    DWORD           dwAlarmMask;                                // 报警信息掩码，按位表示各报警通道状态, 7表示1,2,3报警输入通道
    char            szDevMac[DH_MACADDR_LEN];                   // 设备端mac地址
    char            szPicFilePath[MAX_PATH];                    // 图片存放文件夹路径
    int             nPicFileNum;                                // 当前报警对应的图片文件个数
    int             nUploadPicFileNum;                          // 已上传FTP的图片文件个数
    char            szAreaName[DH_COMMON_STRING_128];           // 防区名称
    DWORD           dwChannelMask;                              // 抓图视频通道的掩码，15表示此次报警抓图的有1,2,3,4通道 
}ALARM_UPLOAD_ALARMEX_INFO;

// 录像状态变化报警信息
typedef struct
{
    int                 nChannel;               // 录像通道号
    char                reserved[12];
} ALARM_RECORDING_CHANGED;

#define NET_MAX_WINDINGID_NUM    8

// 线圈/车检器报警
typedef struct __ALARM_WINGDING_INFO
{
    int                 nDriveWayID;            // 车道号
    int                 nWindingID;             // 线圈ID，此字段废除，以nWindingIDs为准
    NET_TIME            stuTime;                // 报警发生时间
    int                 nState;                 // 设备状态，0表示故障恢复，1表示发生故障
    DWORD               dwChannel;              // 报警的通道号
    char                reserve[28];
    int                 nWindingIDNum;          // 线圈ID个数
    int                 nWindingIDs[NET_MAX_WINDINGID_NUM];// 具体线圈ID 
} ALARM_WINGDING_INFO;

// 交通拥塞报警
typedef struct __ALARM_TRAF_CONGESTION_INFO
{
    int                 nDriveWayID;            // 车道号
    int                 nCongestionLevel;       // 交通拥塞等级:1,2,3,4,5,6;1级最严重
    NET_TIME            stuTime;                // 报警发生时间
    int                 nState;                 // 设备状态，0表示故障恢复，1表示发生故障
    DWORD               dwChannel;              // 报警的通道号
    char                reserve[28];
} ALARM_TRAF_CONGESTION_INFO;

// 交通异常报警
typedef struct __ALARM_TRAF_EXCEPTION_INFO
{
    int                 nDriveWayID;            // 车道号
    NET_TIME            stuTime;                // 报警发生时间
    int                 nState;                 // 设备状态，0表示故障恢复，1表示发生故障
    DWORD               dwChannel;              // 报警的通道号
    char                reserve[28];
} ALARM_TRAF_EXCEPTION_INFO;

// 补光设备故障报警
typedef struct __ALARM_EQUIPMENT_FILL_INFO
{
    int                 nDriveWayID;            // 车道号
    NET_TIME            stuTime;                // 报警发生时间
    int                 nState;                 // 设备状态，0表示故障恢复，1表示发生故障
    DWORD               dwChannel;              // 报警的通道号
    char                reserve[28];
} ALARM_EQUIPMENT_FILL_INFO;

// 报警布撤防状态信息
typedef struct __ALARM_ARM_DISARM_STATE_INFO
{
    BYTE                bState;                 // 布撤防状态，0表示撤防，1表示布防，2表示强制布防
    char                reserve[31];
} ALARM_ARM_DISARM_STATE_INFO;

// 3G流量超出阈值状态信息 
typedef struct __DHDEV_3GFLOW_EXCEED_STATE_INFO
{
    BYTE                bState;                 // 3G流量超出阈值状态，0表示未超出阀值，1表示超出阀值
    char                reserve[31];
} DHDEV_3GFLOW_EXCEED_STATE_INFO;

// 限速报警或路口限速报警 (DH_DEVSTATE_SPEED_LIMIT)
typedef struct __ALARM_SPEED_LIMIT
{
    char                szType[DH_SPEEDLIMIT_TYPE_LEN];     // 限速报警类别：LowerSpeed, UpperSpeed
    int                 iSpeedLimit;                        // 限速 单位KM/H 
    int                 iSpeed;                             // 速度 单位KM/H
    char                szCrossingID[DH_MAX_CROSSING_ID];   // 路口序列号
    DWORD               dwLongitude;                        // 经度(单位是百万分之度，范围0-360度)如东经120.178274度表示为300178274
    DWORD               dwLatidude;                         // 纬度(单位是百万分之度，范围0-180度)如北纬30.183382度表示为120183382
    DHDEVTIME           stTime;                             // 报警发生时间
    BYTE                bOffline;                           // 0-实时 1-补传 
    char                reserve[19];
}ALARM_SPEED_LIMIT;

// 限速报警

// 超载报警
typedef struct __ALARM_OVER_LOADING
{
    NET_TIME            stuCurTime;                         // 当前时间
    DWORD               dwLatidude;                         // 纬度(单位是百万分之度，范围0-180度)如北纬30.183382度表示为120183382
    DWORD               dwLongitude;                        // 经度(单位是百万分之度，范围0-360度)如东经120.178274度表示为300178274
    char                szDriverNo[DH_VEHICLE_DRIVERNO_LEN];// 驾驶员ID
    DWORD               dwCurSpeed;                         // 当前速度
    BYTE                byReserved[128]; 
}ALARM_OVER_LOADING;

// 急刹车报警
typedef struct __ALARM_HARD_BRAKING
{
    NET_TIME        stuCurTime;                             // 当前时间
    DWORD           dwLatidude;                             // 纬度(单位是百万分之度，范围0-180度)如北纬30.183382度表示为120183382
    DWORD           dwLongitude;                            // 经度(单位是百万分之度，范围0-360度)如东经120.178274度表示为300178274
    char            szDriverNo[DH_VEHICLE_DRIVERNO_LEN];    // 驾驶员ID
    DWORD           dwCurSpeed;                             // 当前速度
    BYTE            byReserved[128]; 
}ALARM_HARD_BRAKING;

// 烟感报警
typedef struct __ALARM_SMOKE_SENSOR
{
    NET_TIME        stuCurTime;             // 当前时间
    int             nChannel;               // 报警通道
    BYTE            byHighTemperature;      // 1:高温报警开始，0：高温报警结束
    BYTE            bySmoke;                // 1:烟感报警开始，0：烟感报警结束
    BYTE            byReservrd[126];
}ALARM_SMOKE_SENSOR;

// 交通灯故障报警
typedef struct _LIGHT_INFO
{
    BYTE               byDirection;            // 交通灯方向: 1-左行，2-右行，3-直行, 4-掉头
    BYTE               byState;                // 交通灯状态: 1-故障，2-正常
    BYTE               byReserved[62];         // 保留字节 
}LIGHT_INFO;

typedef struct __ALARM_TRAFFIC_LIGHT_FAULT 
{
    NET_TIME           stTime;                 // 报警发生时间
    int                nInfoNumber;            // 故障信息数
    LIGHT_INFO         stLightInfo[8];         // 交通灯故障信息
    BYTE               byReserved[128];        // 保留字段
}ALARM_TRAFFIC_LIGHT_FAULT;

// 流量统计报警通道信息
typedef struct __ALARM_TRAFFIC_FLUX_LANE_INFO
{
    NET_TIME            stuCurTime;            // 当前时间
    int                 nLane;                 // 车道号
    int                 nState;                // 状态值：1-表示拥堵, 2-表示拥堵恢复, 3-表示正常, 4-表示中断, 5-表示中断恢复
    int                 nFlow;                 // 流量值，单位：辆/分
    BYTE                byReserved[124];       // 保留
}ALARM_TRAFFIC_FLUX_LANE_INFO;

// SIP状态改变报警()
typedef struct __ALARM_SIP_STATE
{
    int     nChannelID;
    BYTE    byStatus;                         //0:注册成功,1:未注册,2:无效,3:注册中,4:通话中
    BYTE    bReserved[63];                    //保留
}ALARM_SIP_STATE;

// 车载自定义信息上传(DH_DEVSTATE_VIHICLE_INFO_UPLOAD)
typedef struct __ALARM_VEHICLE_INFO_UPLOAD
{
    char                szType[DH_VEHICLE_TYPE_LEN];                 // 信息类别: DriverCheck：司机签入签出
    char                szCheckInfo[DH_VEHICLE_INFO_LEN];            // 签入：CheckIn、签出：CheckOut  
    char                szDirverNO[DH_VEHICLE_DRIVERNO_LEN];         // 司机工号字符串
    DHDEVTIME           stTime;                                      // 报警发生时间
    BYTE                bOffline;                                    // 0-实时 1-补传 
    char                reserved[59];                     
}ALARM_VEHICLE_INFO_UPLOAD;
// 车载自定义信息上传

// 卡号录像信息上传
typedef struct __ALARM_CARD_RECORD_INFO_UPLOAD
{
    int                 nChannel;                           // 通道号
    BOOL                bEnable;                            // 是否正在卡号录像
    char                szCardInfo[DH_MAX_CARD_INFO_LEN];   // 卡号信息
    NET_TIME            stuTime;                            // 该卡号生效起始时间
    BOOL                bPreviewOverlayEn;                  // 预览叠加使能
    BYTE                byOverlayPos;                       // 叠加位置,1-左上，2-左下，3-右上，4-右下
    char                reserved[59];
}ALARM_CARD_RECORD_INFO_UPLOAD;



typedef enum __ATMTradeTypes{
    TRADE_TYPE_INC = 0,        //插卡INSERTCARD
    TRADE_TYPE_WDC,            //退卡WITHDRAWCARD
    TRADE_TYPE_CKT,            //校时CHECKTIME
    TRADE_TYPE_INQ,            //查询
    TRADE_TYPE_CWD,            //取款
    TRADE_TYPE_PIN,            //改密
    TRADE_TYPE_TFR,            //转帐
    TRADE_TYPE_DEP,            //存款
    TRADE_TYPE_NCINQ,          //无卡查询
    TRADE_TYPE_NCDEP,          //无卡存款
    TRADE_TYPE_OTHERS,         //其它
    TRADE_TYPE_ALL,            //总
}DH_eATMTradeTypes;

typedef struct __ALARM_ATM_INFO_UPLOAD_CHNL
{
    int                 nChannel;                   // 查询的第几通道ATM叠加信息,范围0-N-1（N表示通道数）
    char                szATMID[32];                // ATM终端号
    char                szCardNo[32];               // 卡号    例：6222421541208230456 
    char                szTradetime[32];            // 交易时间    例：20111118112200表示2011-11-18 11:22:00
    DH_eATMTradeTypes   emTradeType;                // 交易类型    范围: ATMTradeTypes
    int                 nAmount;                    // 交易金额    0-4294967296
    BYTE                byRerved[32];               // 保留
}ALARM_ATM_INFO_UPLOAD_CHNL;

// ATM交易信息上传(DH_ALARM_ATM_INFO_UPLOAD)事件对应结构体
typedef struct __ALARM_ATM_INFO_UPLOAD
{
    int                           nCnt;
    ALARM_ATM_INFO_UPLOAD_CHNL    m_stAtmInfo[DH_MAX_CHANNUM];
}ALARM_ATM_INFO_UPLOAD;

// 摄像机移位报警事件
typedef struct __ALARM_CAMERA_MOVE_INFO
{
    int                         nChannelNum;                        // 报警发生通道数
    unsigned char               alarmChannels[DH_MAX_CHANNUM_EX];   // 发生报警通道号信息
    BYTE                        byReserved[128];
}ALARM_CAMERA_MOVE_INFO;

// 详细动检报警信息
typedef struct __ALARM_DETAILEDMOTION_CHNL_INFO
{
    DWORD              dwSize;
    int                nChannelID;    // 通道号
    BOOL               bAlarm;        // 是否报警 TRUE/FALSE
    int                nLevel;        // 报警级别，单位千分之，以动检发生小格数除以总小格数计算
}ALARM_DETAILEDMOTION_CHNL_INFO;

/// 存储异常报警
typedef struct __ALARM_STORAGE_FAILURE
{
    DWORD     dwSize;                                     // 结构体大小
    UINT      ActionType;                                 // 0：停止， 1：开始
    char      szProtocol[DH_MAX_STRING_LEN];              // 协议类型，目前只支持FTP
    char      szServerAddr[DH_MAX_IPADDR_OR_DOMAIN_LEN];  // 服务器IP地址
    DWORD     dwPort;                                     // 端口号
    NET_TIME  stuTime;                                    // 事件发生时间
    int       nChannel;                                   // 通道号, 从1开始, 0表示不区分通道
}ALARM_STORAGE_FAILURE;

// 前端断网报警信息
typedef struct __ALARM_FRONTDISCONNET_INFO
{
    DWORD              dwSize;                           // 结构体大小
    int                nChannelID;                       // 通道号
    int                nAction;                          // 0:开始 1:停止
    NET_TIME           stuTime;                          // 事件发生时间
    char               szIpAddress[MAX_PATH];            // 前端IPC的IP地址
}ALARM_FRONTDISCONNET_INFO;

// 电池电压过低报警
typedef struct __ALARM_BATTERYLOWPOWER_INFO
{
    DWORD             dwSize;                            // 结构体大小
    int               nAction;                           // 0:开始 1:停止
    int               nBatteryLeft;                      // 剩余电量百分比，单位%
    NET_TIME          stTime;                            // 事件发生时间

}ALARM_BATTERYLOWPOWER_INFO;

// 温度过高报警
typedef struct __ALARM_TEMPERATURE_INFO
{
    DWORD              dwSize;                           // 结构体大小
    char               szSensorName[DH_MACHINE_NAME_NUM];// 温度传感器名称
    int                nChannelID;                       // 通道号
    int                nAction;                          // 0:开始 1:停止
    float              fTemperature;                     // 当前温度值, 单位摄氏度
    NET_TIME           stTime;                           // 事件发生时间
}ALARM_TEMPERATURE_INFO;

// 疲劳驾驶报警
typedef struct __ALARM_TIREDDRIVE_INFO
{
    DWORD             dwSize;                            // 结构体大小
    int               nAction;                           // 0:开始 1:停止
    int               nDriveTime;                        // 持续驾驶时间，单位分钟
    NET_TIME          stTime;                            // 事件发生时间
}ALARM_TIREDDRIVE_INFO;

// 丢录像事件报警
typedef struct __ALARM_LOST_RECORD
{
    DWORD     dwSize;                                     //结构体大小
    UINT      ActionType;                                 // 0：停止， 1：开始
    UINT      nChannelID;                                 // 通道号，从1开始
    UINT      nStreamType;                                // 码流类型，0：主码流；1：辅码流1；2：辅码流2；3：辅码流3；4：抓图码流
    NET_TIME  stuTime;                                    // 事件发生时间    
}ALARM_LOST_RECORD;

// CPU占用率过高事件报警，暂定上限95%。
typedef struct __ALARM_HIGH_CPU
{
    DWORD     dwSize;                                     //结构体大小
    UINT      ActionType;                                 // 0：停止， 1：开始
    UINT      nUsed;                                      // CPU占用率的1000倍
    NET_TIME  stuTime;                                    // 事件发生时间    
}ALARM_HIGH_CPU;

// 网络发送数据丢包事件报警
typedef struct __ALARM_LOST_NETPACKET
{
    DWORD     dwSize;                                     //结构体大小
    UINT      ActionType;                                 // 0：停止， 1：开始
    UINT      nChannelID;                                 // 通道号，从1开始
    UINT      nStreamType;                                // 码流类型，0：主码流；1：辅码流1；2：辅码流2；3：辅码流3；4：抓图码流
    char      szRemoteIP[DH_MAX_IPADDR_LEN];              // 发送端IP地址
    DWORD     dwRemotePort;                               // 发送端的端口地址
    NET_TIME  stuTime;                                    // 事件发生时间    
}ALARM_LOST_NETPACKET;

// 内存占用率过高事件报警，暂定上限95%。
typedef struct __ALARM_HIGH_MEMORY
{
    DWORD     dwSize;                                     //结构体大小
    UINT      ActionType;                                 // 0：停止， 1：开始
    UINT      nUsed;                                      // 内存占用率的1000倍
    NET_TIME  stuTime;                                    // 事件发生时间    
}ALARM_HIGH_MEMORY;

// 黑名单车辆抓拍事件
typedef struct __DH_BLACKLIST_SNAP_INFO
{
    DWORD     dwSize;
    char      szPlateNumber[32];                          // 车牌号
    NET_TIME  stuTime;                                    // 事件发生时间
}DH_BLACKLIST_SNAP_INFO;

// 硬盘流量异常事件
typedef struct __ALARM_DISK_FLUX
{
    DWORD                dwSize;    
    DWORD                dwAction;                         // 0-开始, 1-停止
    DWORD                dwDataFlux;                       // 当前数据流量, KB            
    NET_TIME             stuTime;                          // 事件发生时间
} ALARM_DISK_FLUX;

// 网络流量异常事件
typedef struct __ALARM_NET_FLUX
{
    DWORD                dwSize;    
    DWORD                dwAction;                           // 0-开始, 1-停止
    DWORD                dwDataFlux;                         // 当前数据流量, KB
    NET_TIME             stuTime;                            // 事件发生时间
} ALARM_NET_FLUX;

// 风扇转速异常事件
typedef struct __ALARM_FAN_SPEED
{
    DWORD                dwSize;    
    DWORD                dwAction;                            // 0-开始, 1-停止
    DWORD                dwIndex;                             // 风扇序号
    char                 szName[DH_MACHINE_NAME_NUM];         // 传感器名称
    NET_TIME             stuTime;                             // 事件发生时间
    DWORD                dwCurrent;                           // 当前转速
} ALARM_FAN_SPEED;

// 硬盘报警
typedef struct __ALARM_DISK_INFO 
{
    DWORD                dwSize;
    DWORD                nChannel;                            // 硬盘通道号
    DWORD                nHDDNumber;                          // 磁盘列阵号, 0: 主柜，1: 扩展柜1,  2: 扩展柜2 
    DWORD                nHDDState;                           // 硬盘状态, 0: Unknown, 1: Running, 2: Offline, 3: Warning, 4: Failed
} ALARM_DISK_INFO;

// 文件系统告警
typedef struct __ALARM_FILE_SYSTEM_INFO 
{
    DWORD                dwSize;
    char                 szMountDir[MAX_PATH];                // 文件系统挂载名
    DWORD                nState;                              // 文件系统状态, 0: Unkown, 1: Normal, 2: Error
} ALARM_FILE_SYSTEM_INFO;

// 远程外部报警信息
typedef struct __ALARM_REMOTE_ALARM_INFO
{
    DWORD      dwSize;
    int        nChannelID;                               // 通道号，从1开始
    int        nState;                                   // 报警状态，0-报警复位，1-报警置位
}ALARM_REMOTE_ALARM_INFO;

// 智能报警事件
typedef struct __ALARM_IVS_INFO
{
    DWORD      dwSize;
    NET_TIME   stuTime;                                  // 事件发生时间    
    int        nChannelID;                               // 通道号，从0开始
    char       szType[MAX_PATH];                         // 报警类型
    int        nState;                                   // 报警状态，0-报警复位，1-报警置位, 2-脉冲式报警
}ALARM_IVS_INFO;

// 车载货重报警
typedef struct __ALARM_GOODS_WEIGHT_INFO
{
    DWORD        dwSize;
    int          nAction;                               // 0-开始, 1-停止
    int          nAlarmType;                            // 0-大于最大货重, 1-小于最小货重, 2-货重变化超过报警阈值
    DWORD        dwGoodsWeight;                         // 当前货重(kg)
    DWORD        dwSelfWeight;                          // 自重(kg)
    DWORD        dwTotalWeight;                         // 总重(kg)
    DWORD        dwStandardWeight;                      // 核定货重(kg)
    DWORD        dwWeightScale;                         // 货重比例
    DWORD        dwMaxGoodsWeight;                      // 最大货重(kg)
    DWORD        dwMinGoodsWeight;                      // 最小货重(kg)
    DWORD        dwAlarmWeight;                         // 报警阈值(kg)
    int          nWeightChange;                         // 采集时间间隔内货重变化(kg)
    int          nCheckTime;                            // 静止采集时间(s)
} ALARM_GOODS_WEIGHT_INFO;

// 车载货重信息上传
typedef struct __ALARM_GOODS_WEIGHT_UPLOAD_INFO 
{
    DWORD        dwSize;
    DWORD        dwGoodsWeight;                         // 当前货重(kg)
    DWORD        dwSelfWeight;                          // 自重(kg)
    DWORD        dwTotalWeight;                         // 总重(kg)
    DWORD        dwStandardWeight;                      // 核定货重(kg)
    DWORD        dwWeightScale;                         // 货重比例    
} ALARM_GOODS_WEIGHT_UPLOAD_INFO;

// GPS状态信息
typedef struct _NET_GPS_STATUS_INFO
{
    NET_TIME            revTime;                        // 定位时间
    char                DvrSerial[50];                  // 设备序列号
    double              longitude;                      // 经度(单位是百万分之度，范围0-360度)
    double              latidude;                       // 纬度(单位是百万分之度，范围0-180度)
    double              height;                         // 高度(米)
    double              angle;                          // 方向角(正北方向为原点，顺时针为正)
    double              speed;                          // 速度(单位是海里，speed/1000*1.852公里/小时)
    WORD                starCount;                      // 定位星数
    BOOL                antennaState;                   // 天线状态(true 好，false 坏)
    BOOL                orientationState;               // 定位状态(true 定位，false 不定位)
    BOOL                workStae;                       // 工作状态(0=未定位，1=非差分定位，2=差分定位，3=无效PPS，6=正在估算 

    int                 nAlarmCount;                    // 发生的报警位置个数
    int                 nAlarmState[128];               // 发生的报警位置，值可能多个
    BYTE                bOffline;                       // 0-实时 1-补传 
    BYTE                byRserved[127];                 // 保留字节
} NET_GPS_STATUS_INFO,*LPNET_GPS_STATUS_INFO;

// 硬盘刻录满报警事件
typedef struct __ALARM_DISKBURNED_FULL_INFO
{
    DWORD       dwSize;
    int         nIndex;                             //光盘号
}ALARM_DISKBURNED_FULL_INFO;

// 存储容量不足事件
typedef struct tagALARM_STORAGE_LOW_SPACE_INFO 
{
    DWORD               dwSize;
    int                 nAction;                            // 0:开始 1:停止
    char                szName[DH_EVENT_NAME_LEN];          // 事件名称
    char                szDevice[DH_STORAGE_NAME_LEN];      // 存储设备名称
    char                szGroup[DH_STORAGE_NAME_LEN];       // 存储组名称
    INT64               nTotalSpace;                        // 总容量, byte
    INT64               nFreeSpace;                         // 剩余容量, byte
    int                 nPercent;                           // 已经使用的百分比
} ALARM_STORAGE_LOW_SPACE_INFO;

// 存储错误类型
typedef enum __EM_STORAGE_ERROR
{
    STORAGE_ERROR_NONE,                             // 无
    STORAGE_ERROR_PATITION,                         // 分区错误          
    STORAGE_ERROR_INIT_FS,                          // 初始化文件系统错误    
    STORAGE_ERROR_READ_DATA,                        // 读数据失败
    STORAGE_ERROR_WRITE_DATA,                       // 写数据失败
    STORAGE_ERROR_RAID_FAILED,                      // RAID错误
    STORAGE_ERROR_RAID_DEGRADED,                    // RAID降级
    STORAGE_ERROR_ISCSI_FAILED,                     // iSCSI错误
} EM_STORAGE_ERROR;

// 存储错误报警
typedef struct __ALARM_STORAGE_FAILURE_EX
{
    DWORD               dwSize;
    int                 nAction;                            // 0:开始 1:停止
    char                szName[DH_EVENT_NAME_LEN];          // 事件名称
    char                szDevice[DH_STORAGE_NAME_LEN];      // 存储设备名称
    char                szGroup[DH_STORAGE_NAME_LEN];       // 存储组名称
    char                szPath[MAX_PATH];                   // 路径
    EM_STORAGE_ERROR    emError;                            // 错误类型
} ALARM_STORAGE_FAILURE_EX;

// 录像异常报警
typedef struct __ALARM_RECORD_FAILED_INFO 
{
    DWORD                dwSize;
    int                  nAction;                           // 0:开始 1:停止
    int                  nIndex;                            // 通道号
} ALARM_RECORD_FAILED_INFO;

// 存储崩溃事件
typedef struct __ALARM_STORAGE_BREAK_DOWN_INFO 
{
    DWORD                dwSize;
    int                  nAction;                           // 0:开始 1:停止
} ALARM_STORAGE_BREAK_DOWN_INFO;

typedef enum tagEM_NET_UPS_STATUS
{
    EM_NET_UPS_SYS_SIGN=0,              //系统温度值符号位. 1:表示温度负; 0:表示温度正
    EM_NET_UPS_SYS_SHUTDOWN,            //系统关机.         1:表示关机激活状态
    EM_NET_UPS_SYS_TEST,                //系统测试中.       1:表示测试中
    EM_NET_UPS_SYS_TYPE,                //UPS 类型.         1:表示后备机 ; 0:表示在线机
    EM_NET_UPS_SYS_FAULT,               //UPS 故障.         1:表示UPS内部故障 ; 0:正常
    EM_NET_UPS_ELE_SUPPLY,              //旁路/逆变状态.    1:AC供电 ; 0:电池供电
    EM_NET_UPS_VOL_LOW,                 //电池电压低.       1:表示电池电压低 ; 0:表示电池正常
    EM_NET_UPS_BYPASS_STATUS,           //市电故障.         1:表示市电故障 ; 0:表示市电正常
    EM_NET_UPS_MAX = 64,                //
}EM_NET_UPS_STATUS;

typedef struct tagNET_UPS_INFO
{
    DWORD dwSize;
    float fInputVoltage;                        //输入电压    具体参考 智能交通专用电源通信协议(V1.2)，蓝盾专用定义
    float fInputAbnormalVoltage;                //输入异常电压    
    float fOutputVoltage;                       //输出电压
    float fOutputCurrent;                       //输出电流百分比,单位(%)
    float fInputFrequency;                      //输入频率
    float fVoltage;                             //电压
    float fTemp;                                //温度
    BYTE  bStatusInfo[EM_NET_UPS_MAX];          //UPS状态集,参见NET_UPS_STATUS枚举
    char  szVersionInfo[DH_MAX_VERSION_STR];    //版本
}NET_UPS_INFO;

typedef struct tagALARM_COMM_PORT_EVENT_INFO
{
    DWORD           dwSize;
    UINT            nEventAction;       // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    NET_UPS_INFO    stUPSInfo;          // UPS串口信息
}ALARM_COMM_PORT_EVENT_INFO;

// 视频输入通道失效事件（例：配置的视频输入通道码流，超出设备处理能力）DH_ALARM_VIDEO_ININVALID
typedef struct __ALARM_VIDEO_ININVALID_INFO 
{
    DWORD               dwSize;                         // 结构体大小
    int                 nChannelID;                     // 通道号，从0开始
} ALARM_VIDEO_ININVALID_INFO;


// 存储组不存在事件信息
typedef struct tagALARM_STORAGE_NOT_EXIST_INFO 
{
    DWORD           dwSize;
    char            szName[DH_EVENT_NAME_LEN];          // 事件名称
    char            szDevice[DH_STORAGE_NAME_LEN];      // 存储设备名称
    char            szGroup[DH_STORAGE_NAME_LEN];       // 存储组名称
    NET_TIME        stuTime;                            // 事件触发时间
}ALARM_STORAGE_NOT_EXIST_INFO;

//网络故障事件类型
typedef enum __EM_NETABORT_EVENT_TYPE
{
    EM_NETABORT_EVENT_TYPE_WIRE = 0,                    // 有线网络故障事件
    EM_NETABORT_EVENT_TYPE_WIRELESS,                    // 无线网络故障事件
    EM_NETABORT_EVENT_TYPE_3G,                          // 3G网络故障事件
}EM_NETABORT_EVENT_TYPE;

// 网络故障事件
typedef struct tagALARM_NETABORT_INFO
{
    DWORD                   dwSize;
    int                     nAction;                    // 0:开始 1:停止
    EM_NETABORT_EVENT_TYPE  emNetAbortType;             // 事件类型
    NET_TIME                stuTime;                    // 事件触发时间
}ALARM_NETABORT_INFO;

// IP冲突事件
typedef struct tagALARM_IP_CONFLICT_INFO
{
    DWORD            dwSize;
    int              nAction;                        // 0:开始 1:停止
    NET_TIME         stuTime;                        // 事件触发时间
}ALARM_IP_CONFLICT_INFO;


// MAC冲突事件
typedef struct tagALARM_MAC_CONFLICT_INFO
{
    DWORD           dwSize;
    int             nAction;                        // 0:开始 1:停止
    NET_TIME        stuTime;                        // 事件触发时间
}ALARM_MAC_CONFLICT_INFO;


// 电源类型
typedef enum __EM_POWER_TYPE
{
    EM_POWER_TYPE_MAIN = 0,                          // 主电源
    EM_POWER_TYPE_BACKUP,                            // 备用电源
}EM_POWER_TYPE;

// 电源故障事件类型
typedef enum __EM_POWERFAULT_EVENT_TYPE
{
    EM_POWERFAULT_EVENT_LOST = 0                    // 电源掉电
}EM_POWERFAULT_EVENT_TYPE;

// 电源故障事件
typedef struct tagALARM_POWERFAULT_INFO
{
    DWORD                    dwSize;            
    EM_POWER_TYPE            emPowerType;            // 电源类型
    EM_POWERFAULT_EVENT_TYPE emPowerFaultEvent;      // 电源故障事件
    NET_TIME                 stuTime;                // 报警事件发生的时间
    int                      nAction;                // 0:开始 1:停止
}ALARM_POWERFAULT_INFO;

// 防拆报警事件
typedef struct tagALARM_CHASSISINTRUDED_INFO
{
    DWORD               dwSize;
    int                 nAction;                // 0:开始 1:停止
    NET_TIME            stuTime;                // 报警事件发生的时间
    int                 nChannelID;             // 通道号
}ALARM_CHASSISINTRUDED_INFO;

// 扩展模块报警事件
typedef struct tagALARM_ALARMEXTENDED_INFO
{
    DWORD               dwSize;
    int                 nChannelID;             // 通道号
    int                 nAction;                // 0:开始 1:停止
    NET_TIME            stuTime;                // 报警事件发生的时间
}ALARM_ALARMEXTENDED_INFO;


// 对讲发起方
typedef enum __EM_TALKING_CALLER
{
    EM_TALKING_CALLER_UNKNOWN = 0,                 // 未知发起方
    EM_TALKING_CALLER_PLATFORM,                    // 对讲发起方为平台
}EM_TALKING_CALLER;

// 报警事件类型DH_ALARM_TALKING_INVITE(设备请求对方发起对讲事件)对应的数据描述信息
typedef struct tagALARM_TALKING_INVITE_INFO
{
    DWORD                dwSize;
    EM_TALKING_CALLER    emCaller;                // 设备希望的对讲发起方
    NET_TIME             stuTime;                 // 事件触发时间
}ALARM_TALKING_INVITE_INFO;

// 报警事件类型DH_ALARM_TALKING_HANGUP对应的数据描述信息
typedef struct tagALARM_TALKING_HANGUP_INFO 
{
    DWORD               dwSize;
    NET_TIME            stuTime;                // 事件触发时间
}ALARM_TALKING_HANGUP_INFO;

// 传感器感应方式枚举类型
typedef enum tagNET_SENSE_METHOD
{
    NET_SENSE_UNKNOWN = -1,      //未知类型
    NET_SENSE_DOOR=0,            //门磁
    NET_SENSE_PASSIVEINFRA,      //被动红外
    NET_SENSE_GAS,               //气感
    NET_SENSE_SMOKING,           //烟感
    NET_SENSE_WATER,             //水感
    NET_SENSE_ACTIVEFRA,         //主动红外
    NET_SENSE_GLASS,             //玻璃破碎
    NET_SENSE_EMERGENCYSWITCH,   //紧急开关
    NET_SENSE_SHOCK,             //震动
    NET_SENSE_DOUBLEMETHOD,      //双鉴(红外+微波)
    NET_SENSE_THREEMETHOD,       //三技术
    NET_SENSE_TEMP,              //温度
    NET_SENSE_HUMIDITY,          //湿度
	NET_SENSE_WIND,              //风速
    NET_SENSE_CALLBUTTON,        //呼叫按钮
    NET_SENSE_GASPRESSURE,       //气体压力
    NET_SENSE_GASCONCENTRATION,  //燃气浓度
    NET_SENSE_GASFLOW,           //气体流量
    NET_SENSE_OTHER,             //其他
    NET_SENSE_NUM,               //枚举类型总数
}NET_SENSE_METHOD;

// 本地报警事件(对DH_ALARM_ALARM_EX升级)
typedef struct tagALARM_ALARM_INFO_EX2
{
    DWORD               dwSize;
    int                 nChannelID;             // 通道号
    int                 nAction;                // 0:开始 1:停止
    NET_TIME            stuTime;                // 报警事件发生的时间
    NET_SENSE_METHOD    emSenseType;            // 传感器类型
}ALARM_ALARM_INFO_EX2;

// 布撤防模式
typedef enum tagNET_ALARM_MODE
{    
    NET_ALARM_MODE_UNKNOWN = -1,        // 未知
    NET_ALARM_MODE_DISARMING,           // 撤防
    NET_ALARM_MODE_ARMING,              // 布防
    NET_ALARM_MODE_FORCEON,             // 强制布防
}NET_ALARM_MODE;

// 布撤防场景模式
typedef enum tagNET_SCENE_MODE
{
    NET_SCENE_MODE_UNKNOWN,             // 未知场景
    NET_SCENE_MODE_OUTDOOR,             // 外出模式
    NET_SCENE_MODE_INDOOR,              // 室内模式
}NET_SCENE_MODE;

// 布撤防状态变化事件的信息
typedef struct tagALARM_ARMMODE_CHANGE_INFO
{
    DWORD               dwSize;
    NET_TIME            stuTime;        // 报警事件发生的时间
    NET_ALARM_MODE      bArm;           // 变化后的状态
    NET_SCENE_MODE      emSceneMode;    // 情景模式
}ALARM_ARMMODE_CHANGE_INFO;

// 防区类型
typedef enum
{
    NET_DEFENCEAREA_TYPE_UNKNOWN,       // 未知类型防区
    NET_DEFENCEAREA_TYPE_ALARM,         // 开关量防区
}NET_DEFENCEAREA_TYPE;

// 旁路状态类型
typedef enum
{
    NET_BYPASS_MODE_UNKNOW,             //未知状态
    NET_BYPASS_MODE_BYPASS,             //旁路
    NET_BYPASS_MODE_NORMAL,             //正常
    NET_BYPASS_MODE_ISOLATED,           //隔离
}NET_BYPASS_MODE;

// 旁路状态变化事件的信息
typedef struct tagALARM_BYPASSMODE_CHANGE_INFO
{
    DWORD                   dwSize;
    int                     nChannelID;                 // 通道号
    NET_TIME                stuTime;                    // 报警事件发生的时间
    NET_DEFENCEAREA_TYPE    emDefenceType;              // 防区类型
    int                     nIsExtend;                  // 是否为扩展(通道)防区, 1:扩展通道, 0: 非扩展通道
    NET_BYPASS_MODE         emMode;                     // 变化后的模式 
}ALARM_BYPASSMODE_CHANGE_INFO;


// 紧急事件(对应DH_URGENCY_ALARM_EX2, 对原有的DH_URGENCY_ALARM_EX类型的升级, 指人为触发的紧急事件, 一般处理是联动外部通讯功能请求帮助)
typedef struct tagALARM_URGENCY_ALARM_EX2 
{
    DWORD           dwSize;
    NET_TIME        stuTime;                     //事件产生的时间
    DWORD           nID;                         // 用于标识不同的紧急事件
}ALARM_URGENCY_ALARM_EX2;

// 报警输入源事件详情(只要有输入就会产生改事件，不论防区当前的模式，无法屏蔽)
typedef struct tagALARM_INPUT_SOURCE_SIGNAL_INFO
{
    DWORD           dwSize;
    int             nChannelID;                         // 通道号
    int             nAction;                            // 0:开始 1:停止
    NET_TIME        stuTime;                            // 报警事件发生的时间
}ALARM_INPUT_SOURCE_SIGNAL_INFO;

// 模拟量报警输入通道事件信息(对应DH_ALARM_ANALOGALARM_EVENT)
typedef struct tagALARM_ANALOGALARM_EVENT_INFO 
{
    DWORD           dwSize;
    int             nChannelID;                         // 通道号
    int             nAction;                            // 0:开始 1:停止
    NET_TIME        stuTime;                            // 报警事件发生的时间
    NET_SENSE_METHOD  emSensorType;                     // 传感器类型
    char            szName[DH_COMMON_STRING_128];       // 通道名称
    int             nIsValid;                           // 数据是否有效,-1:未知,0:无效,1:有效
    int             nStatus;                            // 数据状态, -1:未知,0:正常,1:数据无效(超过量程),
                                                        // 2:超过阈值1,3:超过阈值2,4:超过阈值3,5:超过阈值4,
                                                        // 6:低于阈值1,7:低于阈值2,8:低于阈值3,9:低于阈值4
    float           fValue;                             // 探测器数值
    NET_TIME        stuCollectTime;                     // 数据采集时间(UTC)
}ALARM_ANALOGALARM_EVENT_INFO;


// 门禁状态类型
typedef enum tagNET_ACCESS_CTL_STATUS_TYPE
{
	NET_ACCESS_CTL_STATUS_TYPE_UNKNOWN = 0,
	NET_ACCESS_CTL_STATUS_TYPE_OPEN,		// 开门
	NET_ACCESS_CTL_STATUS_TYPE_CLOSE,		// 关门
}NET_ACCESS_CTL_STATUS_TYPE;

// 门禁状态事件
typedef struct tagALARM_ACCESS_CTL_STATUS_INFO 
{
	DWORD		dwSize;
	int			nDoor;						// 门通道号
	NET_TIME	stuTime;					// 事件发生的时间
	NET_ACCESS_CTL_STATUS_TYPE	emStatus;	// 门禁状态
}ALARM_ACCESS_CTL_STATUS_INFO;

// 门禁抓图类型
typedef enum tagNET_ACCESS_SNAP_TYPE
{
    NET_ACCESS_SNAP_TYPE_UNKNOWN = 0,
    NET_ACCESS_SNAP_TYPE_CARD,                          // 刷卡
    NET_ACCESS_SNAP_TYPE_PASSWORD,                      // 密码
}NET_ACCESS_SNAP_TYPE;

// 门禁抓图事件
typedef struct tagALARM_ACCESS_SNAP_INFO
{
    DWORD           dwSize;
    NET_ACCESS_SNAP_TYPE emType;                        // 类型
    char            szCardNO[DH_COMMON_STRING_32];      // 卡号, 刷卡开门时有效
    char            szPassword[DH_COMMON_STRING_64];    // 密码, 密码开门时才有效    
    char            szFtpUrl[MAX_PATH];                 // ftp上传地址, 图片路径
    int             nImageNum;                          // 抓图张数
    NET_TIME        stuTime;                            // 事件发生的时间
}ALARM_ACCESS_SNAP_INFO;

// 消警事件
typedef struct tagALARM_ALARMCLEAR_INFO 
{
    DWORD           dwSize;
    int             nChannelID;                         // 通道号
    NET_TIME        stuTime;                            // 报警事件发生的时间
}ALARM_ALARMCLEAR_INFO;

// CID事件
typedef struct tagALARM_CIDEVENT_INFO
{
    DWORD           dwSize;
    NET_TIME        stuTime;                            // 报警事件发生的时间
    char			szCID[DH_COMMON_STRING_32];         // CID码，标准协议码 字符串长度为16，字符数值为0~F
                                                        // 4位用户码 + 2位识别码 + 1位事件限定码 + 3位事件码 + 2位系统号 + 3位防区码 + 1位校验码
}ALARM_CIDEVENT_INFO;

//////////////////////////////////////////////////////////////////////////

// 记录集新增操作(insert)输入参数
typedef struct tagNET_CTRL_RECORDSET_IN
{
    DWORD           dwSize;
    EM_NET_RECORD_TYPE emType;                          // 记录集信息类型
    void*           pBuf;                               // 记录集信息缓存，详见EM_NET_RECORD_TYPE注释
    int             nBufLen;                            // 记录集信息缓存大小
}NET_CTRL_RECORDSET_INSERT_IN;

// 记录集新增操作(insert)输出参数
typedef struct tagNET_CTRL_RECORDSET_OUT 
{
    DWORD           dwSize;
    int             nRecNo;                             // 记录编号(新增insert时设备返回)
}NET_CTRL_RECORDSET_INSERT_OUT;

// 记录集新增操作(insert)参数
typedef struct tagNET_CTRL_RECORDSET_INSERT_PARAM 
{
    DWORD                           dwSize;
    NET_CTRL_RECORDSET_INSERT_IN    stuCtrlRecordSetInfo;       // 记录集信息(用户填写)
    NET_CTRL_RECORDSET_INSERT_OUT   stuCtrlRecordSetResult;     // 记录集信息(设备返回)
}NET_CTRL_RECORDSET_INSERT_PARAM;

// 记录集操作参数
typedef struct tagNET_CTRL_RECORDSET_PARAM 
{
    DWORD               dwSize;
    EM_NET_RECORD_TYPE  emType;                         // 记录集信息类型
    void*               pBuf;                           // 新增\更新\查询时,为记录集信息缓存，详见EM_NET_RECORD_TYPE注释
                                                        // 删除时,为记录编号(int型)
    int                    nBufLen;                     // 记录集信息缓存大小
}NET_CTRL_RECORDSET_PARAM;

// 卡状态
typedef enum tagNET_ACCESSCTLCARD_STATE
{
    NET_ACCESSCTLCARD_STATE_UNKNOWN = -1,
    NET_ACCESSCTLCARD_STATE_NORMAL = 0,                 // 正常
    NET_ACCESSCTLCARD_STATE_LOSE   = 0x01,              // 挂失
    NET_ACCESSCTLCARD_STATE_LOGOFF = 0x02,              // 注销
    NET_ACCESSCTLCARD_STATE_FREEZE = 0x04,              // 冻结
}NET_ACCESSCTLCARD_STATE;

// 卡类型
typedef enum tagNET_ACCESSCTLCARD_TYPE
{
    NET_ACCESSCTLCARD_TYPE_UNKNOWN = -1,
    NET_ACCESSCTLCARD_TYPE_GENERAL,                     // 一般卡
    NET_ACCESSCTLCARD_TYPE_VIP,                         // VIP卡
    NET_ACCESSCTLCARD_TYPE_GUEST,                       // 来宾卡
    NET_ACCESSCTLCARD_TYPE_PATROL,                      // 巡逻卡
    NET_ACCESSCTLCARD_TYPE_BLACKLIST,                   // 黑名单卡
    NET_ACCESSCTLCARD_TYPE_CORCE,                       // 胁迫卡
    NET_ACCESSCTLCARD_TYPE_MOTHERCARD = 0xff,           // 母卡
}NET_ACCESSCTLCARD_TYPE;

#define DH_MAX_DOOR_NUM               32                // 最大有权限门禁数目
#define DH_MAX_TIMESECTION_NUM        32                // 最大有效时间段数目
#define DH_MAX_CARDNO_LEN             32                // 门禁卡号最大长度
#define DH_MAX_USERID_LEN             32                // 门禁卡用户ID最大长度

// 门禁卡记录集信息
typedef struct tagNET_RECORDSET_ACCESS_CTL_CARD
{
    DWORD           dwSize;
    int             nRecNo;                                 // 记录集编号，只读
    NET_TIME        stuCreateTime;                          // 创建时间
    char            szCardNo[DH_MAX_CARDNO_LEN];            // 卡号
    char            szUserID[DH_MAX_USERID_LEN];            // 用户ID, 设备暂不支持
    NET_ACCESSCTLCARD_STATE       emStatus;                 // 卡状态
    NET_ACCESSCTLCARD_TYPE        emType;                   // 卡类型
    char            szPsw[DH_MAX_CARDPWD_LEN];              // 卡密码
    int             nDoorNum;                               // 有效的门数目;
    int             sznDoors[DH_MAX_DOOR_NUM];              // 有权限的门序号，即CFG_CMD_ACCESS_EVENT配置的数组下标
    int             nTimeSectionNum;                        // 有效的的开门时间段数目
    int             sznTimeSectionNo[DH_MAX_TIMESECTION_NUM];  // 开门时间段索引，即CFG_ACCESS_TIMESCHEDULE_INFO的数组下标
    int             nUserTime;                              // 使用次数，仅当来宾卡时有效
    NET_TIME        stuValidStartTime;                      // 开始有效期, 设备暂不支持时分秒
    NET_TIME        stuValidEndTime;                        // 结束有效期, 设备暂不支持时分秒
    BOOL            bIsValid;                               // 是否有效,true有效;false无效
}NET_RECORDSET_ACCESS_CTL_CARD;

// 门禁密码记录集信息
typedef struct tagNET_RECORDSET_ACCESS_CTL_PWD 
{
    DWORD           dwSize;
    int             nRecNo;                                 // 记录集编号，只读
    NET_TIME        stuCreateTime;                          // 创建时间
    char            szUserID[DH_MAX_USERID_LEN];            // 用户ID, 设备暂不支持
    char            szDoorOpenPwd[DH_MAX_CARDPWD_LEN];      // 开门密码
    char            szAlarmPwd[DH_MAX_CARDPWD_LEN];         // 报警密码
    int             nDoorNum;                               // 有效的的门数目
    int             sznDoors[DH_MAX_DOOR_NUM];              // 有权限的门序号，即CFG_CMD_ACCESS_EVENT配置CFG_ACCESS_EVENT_INFO的数组下标
}NET_RECORDSET_ACCESS_CTL_PWD;


// 开门方式(门禁配置,门的一种工作模式)
typedef enum tagNET_DOOR_OPEN_METHOD
{
    NET_DOOR_OPEN_METHOD_UNKNOWN = 0,
    NET_DOOR_OPEN_METHOD_PWD_ONLY,                          // 只允许密码开锁
    NET_DOOR_OPEN_METHOD_CARD,                              // 只允许刷卡开锁
    NET_DOOR_OPEN_METHOD_PWD_OR_CARD,                       // 密码或刷卡开锁
    NET_DOOR_OPEN_METHOD_CARD_FIRST,                        // 先刷卡后密码开锁
    NET_DOOR_OPEN_METHOD_PWD_FIRST,                         // 先密码后刷卡开锁
    NET_DOOR_OPEN_METHOD_SECTION,                           // 分时段开门
}NET_DOOR_OPEN_METHOD;

// 开门方式(门禁事件,门禁出入记录,实际的开门方式)
typedef enum tagNET_ACCESS_DOOROPEN_METHOD
{
    NET_ACCESS_DOOROPEN_METHOD_UNKNOWN = 0,
    NET_ACCESS_DOOROPEN_METHOD_PWD_ONLY,                    // 密码开锁
    NET_ACCESS_DOOROPEN_METHOD_CARD,                        // 刷卡开锁
    NET_ACCESS_DOOROPEN_METHOD_CARD_FIRST,                  // 先刷卡后密码开锁
    NET_ACCESS_DOOROPEN_METHOD_PWD_FIRST,                   // 先密码后刷卡开锁
    NET_ACCESS_DOOROPEN_METHOD_REMOTE,                      // 远程开锁，如通过室内机或者平台对门口机开锁
    NET_ACCESS_DOOROPEN_METHOD_BUTTON,                      // 开锁按钮进行开锁
}NET_ACCESS_DOOROPEN_METHOD;

// 门禁刷卡记录记录集信息
typedef struct tagNET_RECORDSET_ACCESS_CTL_CARDREC
{
    DWORD           dwSize;
    int             nRecNo;                                 // 记录集编号，只读
    char            szCardNo[DH_MAX_CARDNO_LEN];            // 卡号
    char            szPwd[DH_MAX_CARDPWD_LEN];              // 密码
    NET_TIME        stuTime;                                // 刷卡时间
    BOOL            bStatus;                                // 刷卡结果，TRUE表示成功，FALSE表示失败
    NET_ACCESS_DOOROPEN_METHOD    emMethod;                 // 开门方式
    int             nDoor;                                  // 门号，即CFG_CMD_ACCESS_EVENT配置CFG_ACCESS_EVENT_INFO的数组下标
}NET_RECORDSET_ACCESS_CTL_CARDREC;

// 假日记录集信息
typedef struct tagNET_RECORDSET_HOLIDAY
{
    DWORD           dwSize;
    int             nRecNo;                                 // 记录集编号，只读
    int             nDoorNum;                               // 有效的的门数目    
    int             sznDoors[DH_MAX_DOOR_NUM];              // 有权限的门序号，即CFG_CMD_ACCESS_EVENT配置CFG_ACCESS_EVENT_INFO的数组下标
    NET_TIME        stuStartTime;                           // 开始时间
    NET_TIME        stuEndTime;                             // 结束时间
    BOOL            bEnable;                                // 假期使能
	char            szHolidayNo[DH_COMMON_STRING_32];       // 假期编号
}NET_RECORDSET_HOLIDAY;

// 门禁未关事件详细信息
typedef struct tagALARM_ACCESS_CTL_NOT_CLOSE_INFO 
{
    DWORD           dwSize;
    int             nDoor;                                  // 门通道号
    char            szDoorName[DH_MAX_DOORNAME_LEN];        // 门禁名称
    NET_TIME        stuTime;                                // 报警事件发生的时间
    int             nAction;                                // 0:开始 1:停止
}ALARM_ACCESS_CTL_NOT_CLOSE_INFO;

// 闯入事件详细信息
typedef struct tagALARM_ACCESS_CTL_BREAK_IN_INFO 
{
    DWORD           dwSize;
    int             nDoor;                                  // 门通道号
    char            szDoorName[DH_MAX_DOORNAME_LEN];        // 门禁名称
    NET_TIME        stuTime;                                // 报警事件发生的时间
}ALARM_ACCESS_CTL_BREAK_IN_INFO;


// 反复进入事件详细信息
typedef struct tagALARM_ACCESS_CTL_REPEAT_ENTER_INFO 
{
    DWORD           dwSize;
    int             nDoor;                                  // 门通道号
    char            szDoorName[DH_MAX_DOORNAME_LEN];        // 门禁名称
    NET_TIME        stuTime;                                // 报警事件发生的时间
}ALARM_ACCESS_CTL_REPEAT_ENTER_INFO;


// 胁迫卡刷卡事件详细信息
typedef struct tagALARM_ACCESS_CTL_DURESS_INFO 
{
    DWORD           dwSize;
    int             nDoor;                                  // 门通道号
    char            szDoorName[DH_MAX_DOORNAME_LEN];        // 门禁名称
    char            szCardNo[DH_MAX_CARDNO_LEN];            // 胁迫卡号
    NET_TIME        stuTime;                                // 报警事件发生的时间
}ALARM_ACCESS_CTL_DURESS_INFO;


// 门禁事件类型
typedef enum tagNET_ACCESS_CTL_EVENT_TYPE
{
    NET_ACCESS_CTL_EVENT_UNKNOWN = 0,
    NET_ACCESS_CTL_EVENT_ENTRY,                             // 进门
    NET_ACCESS_CTL_EVENT_EXIT,                              // 出门
}NET_ACCESS_CTL_EVENT_TYPE;


// 门禁事件
typedef struct tagALARM_ACCESS_CTL_EVENT_INFO 
{
    DWORD                       dwSize;
    int                         nDoor;                              // 门通道号
    char                        szDoorName[DH_MAX_DOORNAME_LEN];    // 门禁名称
    NET_TIME                    stuTime;                            // 报警事件发生的时间
    NET_ACCESS_CTL_EVENT_TYPE   emEventType;                        // 门禁事件类型
    BOOL                        bStatus;                            // 刷卡结果，TRUE表示成功，FALSE表示失败
    NET_ACCESSCTLCARD_TYPE      emCardType;                         // 卡类型
    NET_ACCESS_DOOROPEN_METHOD  emOpenMethod;                       // 开门方式
    char                        szCardNo[DH_MAX_CARDNO_LEN];        // 卡号
    char                        szPwd[DH_MAX_CARDPWD_LEN];          // 密码
}ALARM_ACCESS_CTL_EVENT_INFO;

///////////////////////// 智能交通报警事件[CLIENT_StartListenEx] /////////////////////////////////////

//事件类型 DH_IVS_TRAFFIC_REALFLOWINFO(交通实时流量信息事件)对应的数据块描述信息
typedef struct tagALARM_IVS_TRAFFIC_REALFLOW_INFO
{
    int                 nChannelID;                     // 通道号
    char                szName[128];                    // 事件名称
    char                bReserved1[4];                  // 字节对齐
    double              PTS;                            // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                            // 事件发生的时间
    int                 nEventID;                       // 事件ID
    unsigned int        nSequence;                      // 序号
    BYTE                bEventAction;                   // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[3];
    int                 nLane;                          // 对应车道号
    int                 nCount;                         // 车辆总数
    int                 nSpeed;                         // 车速，km/h
    int                 nOverPercent;                   // 平均超速百分比
    int                 nMetersUints;                   // 速度单位，0：公里，1：英里
    BYTE                bReserved[1024];                // 保留字节,留待扩展.
}ALARM_IVS_TRAFFIC_REALFLOW_INFO;

// 报警事件类型 DH_ALARM_VEHICLE_TURNOVER(车辆侧翻事件)对应的数据描述信息
typedef struct tagALARM_VEHICEL_TURNOVER_EVENT_INFO
{
    NET_GPS_STATUS_INFO stGPSStatusInfo;                // GPS信息
    BYTE                bEventAction;                   // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                bReserved[1023];                // 保留字节,留待扩展.
}ALARM_VEHICEL_TURNOVER_EVENT_INFO;

// 报警事件类型DH_ALARM_VEHICLE_COLLISION(车辆撞车事件)对应的数据描述信息
typedef struct tagALARM_VEHICEL_COLLISION_EVENT_INFO
{
    NET_GPS_STATUS_INFO stGPSStatusInfo;                // GPS信息
    BYTE                bEventAction;                   // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                bReserved[1023];                // 保留字节,留待扩展.
}ALARM_VEHICEL_COLLISION_EVENT_INFO;

// 报警事件类型DH_ALARM_VEHICLE_CONFIRM(车辆上传信息事件)对应的数据描述信息
typedef struct tagALARM_VEHICEL_CONFIRM_INFO
{
    DWORD               dwStructSize;                   // 结构体大小
    NET_GPS_STATUS_INFO stGPSStatusInfo;                // GPS信息
    BYTE                bEventAction;                   // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byRserved[3];                   // 对齐
    char                szInfo[128];                    // 上传报警具体信息
}ALARM_VEHICEL_CONFIRM_INFO;

//事件类型DH_EVENT_REGISTER_OFF(车载设备主动下线事件)对应的数据描述信息
typedef struct tagEVENT_REGISTER_OFF_INFO
{
    DWORD               dwStructSize;                   // 结构体大小
    NET_GPS_STATUS_INFO stGPSStatusInfo;                // GPS信息
    BYTE                bEventAction;                   // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byRserved[3];                   // 对齐
}EVENT_REGISTER_OFF_INFO;

// 报警事件类型DH_ALARM_VIDEO_TIMING(视频定时检测事件)对应的数据描述信息
typedef struct tagALARM_VIDEO_TIMING
{
    DWORD               dwStructSize;                   // 结构体大小
    DWORD               dwAction;                       // 事件动作, 0:Pause, 1:Start, 2:Stop
    DWORD               dwChannelID;                    // 视频通道号
}ALARM_VIDEO_TIMING;

// 报警事件类型DH_ALARM_VEHICLE_LARGE_ANGLE(车载摄像头大角度扭转事件)对应的数据描述信息
typedef struct tagALARM_VEHICEL_LARGE_ANGLE
{
    DWORD               dwStructSize;                   // 结构体大小
    NET_GPS_STATUS_INFO stGPSStatusInfo;                // GPS信息
    BYTE                bEventAction;                   // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byRserved[3];                   // 对齐
}ALARM_VEHICEL_LARGE_ANGLE;

// 报警事件类型DH_ALARM_AUDIO_ANOMALY(音频异常事件)对应的数据描述信息
typedef struct tagALARM_AUDIO_ANOMALY
{
    DWORD               dwStructSize;                   // 结构体大小
    DWORD               dwAction;                       // 事件动作, 0:Start, 1:Stop
    DWORD               dwChannelID;                    // 音频通道号
}ALARM_AUDIO_ANOMALY;

// 报警事件类型DH_ALARM_AUDIO_MUTATION(声强突变事件)对应的数据描述信息
typedef struct tagALARM_AUDIO_MUTATION
{
    DWORD               dwStructSize;                   // 结构体大小
    DWORD               dwAction;                       // 事件动作, 0:Start, 1:Stop
    DWORD               dwChannelID;                    // 音频通道号
}ALARM_AUDIO_MUTATION;

#define MAX_SENSORID_NUMBER 20                          // 传感器最大个数
#define MAX_TYRE_NUM        128                         // 最大轮胎个数
// 轮胎告警标志位对应枚举
typedef enum tagAlarmTyreFlag
{
    ALARM_TYRE_FLAG_NONE,                               // 无有效数据
    ALARM_TYRE_FLAG_NORMAL,                             // 正常
    ALARM_TYRE_FLAG_HIGHPRESSURE,                       // 高压
    ALARM_TYRE_FLAG_LOWERPRESSURE,                      // 低压
    ALARM_TYRE_FLAG_HIGHTEMP,                           // 高温
    ALARM_TYRE_FLAG_HIGHTEMP_HIGHPRESSURE,              // 高温、高压
    ALARM_TYRE_FLAG_HIGHTEMP_LOWERPRESSURE,             // 高温、低压

    ALARM_TYRE_FLAG_INVALID,                            // 非法的标志位数据
}EM_ALARM_TYER_FALG;

// 轮胎信息结构
typedef struct tagTYRE_INFO_UNIT
{
    DWORD               dwStructSize;                    // 结构体大小
    DWORD               dwSensorIDNum;                   // 传感器个数
    DWORD               dwSensorID[MAX_SENSORID_NUMBER]; // 传感器ID信息
    DWORD               dwTyreNum;                       // 胎位编号
    DWORD               dwTyrePlace;                     // 轮胎位于第几轴

    EM_ALARM_TYER_FALG  emAlarmFlag;                     // 轮胎告警标志位

    int                 nTemp;                           // 温度,单位℃
    int                 nTempLimit;                      // 温度,单位℃

    float               fPressure;                       // 压力,单位Kpa
    float               fUpperLimit;                     // 告警压力阈值上限,单位Kpa
    float               fLowerLimit;                     // 告警压力阈值下限,单位Kpa
    float               fVoltage;                        // 当前的传感器电压,单位 V
}TYRE_INFO_UNIT;

// 报警事件类型DH_EVENT_TYREINFO(轮胎信息上报事件)对应的数据描述信息
typedef struct tagEVENT_TYRE_INFO
{
    DWORD               dwStructSize;                   // 结构体大小
    DWORD               dwAction;                       // 事件动作, 0:Pause, 1:Stop
    DWORD               dwTyreNum;                      // 轮胎个数
    TYRE_INFO_UNIT      *pstuTyre;                      // 轮胎信息
}EVENT_TYRE_INFO;

/////////////////////////////语音对讲相关定义/////////////////////////////

// 音频格式信息
typedef struct
{
    BYTE                byFormatTag;                    // 编码类型，如0：PCM
    WORD                nChannels;                      // 声道数
    WORD                wBitsPerSample;                 // 采样深度            
    DWORD               nSamplesPerSec;                 // 采样率
} DH_AUDIO_FORMAT, *LPDH_AUDIO_FORMAT;

/////////////////////////////用户管理相关定义/////////////////////////////

// 支持用户名最大长度为8位的设备，对应CLIENT_QueryUserInfo和CLIENT_OperateUserInfo接口
// 权限信息
typedef struct _OPR_RIGHT
{
    DWORD               dwID;
    char                name[DH_RIGHT_NAME_LENGTH];
    char                memo[DH_MEMO_LENGTH];
} OPR_RIGHT;

// 用户信息
typedef struct _USER_INFO
{
    DWORD               dwID;
    DWORD               dwGroupID;
    char                name[DH_USER_NAME_LENGTH];
    char                passWord[DH_USER_PSW_LENGTH];
    DWORD               dwRightNum;
    DWORD               rights[DH_MAX_RIGHT_NUM];
    char                memo[DH_MEMO_LENGTH];
    DWORD               dwReusable;                     // 是否复用；1：复用，0：不复用
} USER_INFO;

// 用户组信息
typedef struct _USER_GROUP_INFO
{
    DWORD               dwID;
    char                name[DH_USER_NAME_LENGTH];
    DWORD               dwRightNum;
    DWORD               rights[DH_MAX_RIGHT_NUM];
    char                memo[DH_MEMO_LENGTH];
} USER_GROUP_INFO;

// 用户信息表
typedef struct _USER_MANAGE_INFO
{
    DWORD                dwRightNum;                    // 权限信息
    OPR_RIGHT            rightList[DH_MAX_RIGHT_NUM];
    DWORD                dwGroupNum;                    // 用户组信息
    USER_GROUP_INFO      groupList[DH_MAX_GROUP_NUM];
    DWORD                dwUserNum;                     // 用户信息
    USER_INFO            userList[DH_MAX_USER_NUM];
    DWORD                dwSpecial;                     // 用户复用能力；1：支持用户复用，0：不支持用户复用
} USER_MANAGE_INFO;

// 支持用户名最大长度为8位或16位的设备，对应扩展接口CLIENT_QueryUserInfoEx和CLIENT_OperateUserInfoEx
#define DH_USER_NAME_LENGTH_EX       16                 // 用户名长度
#define DH_USER_PSW_LENGTH_EX        16                 // 密码

// 权限信息
typedef struct _OPR_RIGHT_EX
{
    DWORD                dwID;
    char                 name[DH_RIGHT_NAME_LENGTH];
    char                 memo[DH_MEMO_LENGTH];
} OPR_RIGHT_EX;

// 用户信息
typedef struct _USER_INFO_EX
{
    DWORD                dwID;
    DWORD                dwGroupID;
    char                 name[DH_USER_NAME_LENGTH_EX];
    char                 passWord[DH_USER_PSW_LENGTH_EX];
    DWORD                dwRightNum;
    DWORD                rights[DH_MAX_RIGHT_NUM];
    char                 memo[DH_MEMO_LENGTH];
    DWORD                dwFouctionMask;                // 掩码，0x00000001 - 支持用户复用
    BYTE                 byReserve[32];
} USER_INFO_EX;

// 用户组信息
typedef struct _USER_GROUP_INFO_EX
{
    DWORD                dwID;
    char                 name[DH_USER_NAME_LENGTH_EX];
    DWORD                dwRightNum;
    DWORD                rights[DH_MAX_RIGHT_NUM];
    char                 memo[DH_MEMO_LENGTH];
} USER_GROUP_INFO_EX;

// 用户信息表
typedef struct _USER_MANAGE_INFO_EX
{
    DWORD                dwRightNum;                    // 权限信息
    OPR_RIGHT_EX         rightList[DH_MAX_RIGHT_NUM];
    DWORD                dwGroupNum;                    // 用户组信息
    USER_GROUP_INFO_EX   groupList[DH_MAX_GROUP_NUM];
    DWORD                dwUserNum;                     // 用户信息
    USER_INFO_EX         userList[DH_MAX_USER_NUM];
    DWORD                dwFouctionMask;                // 掩码；0x00000001 - 支持用户复用，0x00000002 - 密码修改需要校验
    BYTE                 byNameMaxLength;               // 支持的用户名最大长度
    BYTE                 byPSWMaxLength;                // 支持的密码最大长度
    BYTE                 byReserve[254];
} USER_MANAGE_INFO_EX;

// 最大支持64通道的设备，对应扩展接口CLIENT_QueryUserInfoNew和CLIENT_OperateUserInfoNew
#define DH_NEW_MAX_RIGHT_NUM        1024
#define DH_NEW_USER_NAME_LENGTH     128                 // 用户名长度
#define DH_NEW_USER_PSW_LENGTH      128                 // 密码


// 权限信息
typedef struct _OPR_RIGHT_NEW
{
    DWORD               dwSize;
    DWORD               dwID;
    char                name[DH_RIGHT_NAME_LENGTH];
    char                memo[DH_MEMO_LENGTH];
} OPR_RIGHT_NEW;

// 用户信息
typedef struct _USER_INFO_NEW
{
    DWORD               dwSize;
    DWORD               dwID;
    DWORD               dwGroupID;
    char                name[DH_NEW_USER_NAME_LENGTH];
    char                passWord[DH_NEW_USER_PSW_LENGTH];
    DWORD               dwRightNum;
    DWORD               rights[DH_NEW_MAX_RIGHT_NUM];
    char                memo[DH_MEMO_LENGTH];
    DWORD               dwFouctionMask;                 // 掩码，0x00000001 - 支持用户复用
    NET_TIME            stuTime;                        // 最后修改时间
    BYTE                byIsAnonymous;                  // 是否可以匿名登录, 0:不可匿名登录, 1: 可以匿名登录
    BYTE                byReserve[7];
} USER_INFO_NEW;

// 用户组信息
typedef struct _USER_GROUP_INFO_NEW
{
    DWORD               dwSize;
    DWORD               dwID;
    char                name[DH_USER_NAME_LENGTH_EX];
    DWORD               dwRightNum;
    DWORD               rights[DH_NEW_MAX_RIGHT_NUM];
    char                memo[DH_MEMO_LENGTH];
} USER_GROUP_INFO_NEW;

// 用户组信息扩展，用户组名加长
typedef struct _USER_GROUP_INFO_EX2
{
    DWORD               dwSize;
    DWORD               dwID;
    char                name[DH_NEW_USER_NAME_LENGTH];
    DWORD               dwRightNum;
    DWORD               rights[DH_NEW_MAX_RIGHT_NUM];
    char                memo[DH_MEMO_LENGTH];
} USER_GROUP_INFO_EX2;

// 用户信息表
typedef struct _USER_MANAGE_INFO_NEW
{
    DWORD               dwSize;
    DWORD               dwRightNum;                         // 权限信息
    OPR_RIGHT_NEW       rightList[DH_NEW_MAX_RIGHT_NUM];
    DWORD               dwGroupNum;                         // 用户组数
    USER_GROUP_INFO_NEW groupList[DH_MAX_GROUP_NUM];        // 用户组信息，此参数废弃,请使用groupListEx
    DWORD               dwUserNum;                          // 用户信息
    USER_INFO_NEW       userList[DH_MAX_USER_NUM];
    DWORD               dwFouctionMask;                     // 掩码；0x00000001 - 支持用户复用，0x00000002 - 密码修改需要校验
    BYTE                byNameMaxLength;                    // 支持的用户名最大长度
    BYTE                byPSWMaxLength;                     // 支持的密码最大长度
    BYTE                byReserve[254];
    USER_GROUP_INFO_EX2 groupListEx[DH_MAX_GROUP_NUM];      // 用户组信息扩展
} USER_MANAGE_INFO_NEW;

///////////////////////////////查询相关定义///////////////////////////////

// 设备支持语言种类
typedef struct _DH_LANGUAGE_DEVINFO
{
    DWORD               dwLanguageNum;                      // 支持语言个数
    BYTE                byLanguageType[252];                // 枚举值，详见DH_LANGUAGE_TYPE
} DH_DEV_LANGUAGE_INFO, *LPDH_DEV_LANGUAGE_INFO;

// 查询设备支持的IPC能力信息
typedef struct
{
    int                 nTypeCount;                         // 支持的IPC个数
    BYTE                bSupportTypes[128];                 // 枚举值，详见EM_IPC_TYPE
}DH_DEV_IPC_INFO;

//3G网络流量信息
typedef struct
{
    int                 nStrategy;                          // 包月策略,0-按流量包月,1-按时间包月
    int                 nUplimit;                           // 流量上限, 与策略对应, 按流量, 单位MB; 按时间，单位小时
    int                 nUsed;                              // 已使用流量，单位与nUplimit相同
    BYTE                bReserved[64];                      // 保留字段
}DH_DEV_3GFLOW_INFO;

// 3G模块信息
typedef struct
{
    BYTE                byEthNum;                           // 3G模块数
    BYTE                byReserved[255];                    // 保留字节
}DH_DEV_3GMODULE_INFO;

typedef struct
{
    DWORD               dwId;                               // ddns 服务器id号
    char                szState[DH_MAX_DDNS_STATE_LEN];     // ddns 状态
    BYTE                bReserved[512];                     // 保留字段
}DH_DEV_DNS_INFO;
typedef struct
{
    DWORD               dwDdnsServerNum;    
    DH_DEV_DNS_INFO     stDdns[DH_MAX_DDNS_NUM];
}DH_DEV_MULTI_DDNS_INFO;

// 设备URL信息
typedef struct
{
    char               szURLInfo[512];                      //设备URL信息, 由字符串组成
    BYTE               bReserved[512];
}DH_DEV_URL_INFO;
// 硬盘信息
typedef struct
{
    DWORD               dwVolume;                           // 硬盘的容量, 单位MB(B表示字节)
    DWORD               dwFreeSpace;                        // 硬盘的剩余空间, 单位MB(B表示字节)
    BYTE                dwStatus;                           // 高四位的值表示硬盘类型，具体见枚举类型EM_DISK_TYPE；低四位的值表示硬盘的状态，0-休眠,1-活动,2-故障等；将DWORD拆成四个BYTE
    BYTE                bDiskNum;                           // 硬盘号
    BYTE                bSubareaNum;                        // 分区号
    BYTE                bSignal;                            // 标识，0为本地 1为远程
} NET_DEV_DISKSTATE,*LPNET_DEV_DISKSTATE;

// 设备硬盘信息
typedef struct _DH_HARDDISK_STATE
{
    DWORD                dwDiskNum;                         // 个数
    NET_DEV_DISKSTATE    stDisks[DH_MAX_DISKNUM];           // 硬盘或分区信息
} DH_HARDDISK_STATE, *LPDH_HARDDISK_STATE;

typedef DH_HARDDISK_STATE    DH_SDCARD_STATE;             // SD卡，数据结构同硬盘信息

// 语音编码信息
typedef struct  
{
    DH_TALK_CODING_TYPE encodeType;                         // 编码类型
    int                 nAudioBit;                          // 位数，如8或16
    DWORD               dwSampleRate;                       // 采样率，如8000或16000
    int                 nPacketPeriod;                      // 打包周期, 单位ms
    char                reserved[60];
} DHDEV_TALKDECODE_INFO;

// 设备支持的语音对讲类型
typedef struct 
{
    int                     nSupportNum;                    // 个数
    DHDEV_TALKDECODE_INFO   type[64];                       // 编码类型
    char                    reserved[64];
} DHDEV_TALKFORMAT_LIST;

// 云台属性信息
#define  NAME_MAX_LEN 16
typedef struct 
{
    DWORD               dwHighMask;                 // 操作的掩码高位
    DWORD               dwLowMask;                  // 操作的掩码低位
    char                szName[NAME_MAX_LEN];       // 操作的协议名
    WORD                wCamAddrMin;                // 通道地址的最小值
    WORD                wCamAddrMax;                // 通道地址的最大值
    WORD                wMonAddrMin;                // 监视地址的最小值
    WORD                wMonAddrMax;                // 监视地址的最大值
    BYTE                bPresetMin;                 // 预置点的最小值
    BYTE                bPresetMax;                 // 预置点的最大值
    BYTE                bTourMin;                   // 自动巡航线路的最小值
    BYTE                bTourMax;                   // 自动巡航线路的最大值
    BYTE                bPatternMin;                // 轨迹线路的最小值
    BYTE                bPatternMax;                // 轨迹线路的最大值
    BYTE                bTileSpeedMin;              // 垂直速度的最小值
    BYTE                bTileSpeedMax;              // 垂直速度的最大值
    BYTE                bPanSpeedMin;               // 水平速度的最小值
    BYTE                bPanSpeedMax;               // 水平速度的最大值
    BYTE                bAuxMin;                    // 辅助功能的最小值
    BYTE                bAuxMax;                    // 辅助功能的最大值
    int                 nInternal;                  // 发送命令的时间间隔
    char                cType;                      // 协议的类型
    BYTE                bReserved_1;                // 保留
    BYTE                bFuncMask;                  // 协议功能掩码,按位表示,置１表示支持,第一位表示内置云台功能，其它７位暂时保留
    BYTE                bReserved_2;
    char                Reserved[4];
} PTZ_OPT_ATTR;

// 刻录机信息
typedef struct _NET_DEV_BURNING
{
    DWORD               dwDriverType;               // 刻录驱动器类型；0：DHFS，1：DISK，2：CDRW
    DWORD               dwBusType;                  // 总线类型；0：USB，1：1394，2：IDE, 3: SATA, 4: ESATA
    DWORD               dwTotalSpace;               // 总容量(KB)
    DWORD               dwRemainSpace;              // 剩余容量(KB)
    BYTE                dwDriverName[DH_BURNING_DEV_NAMELEN];    // 刻录驱动器名称
} NET_DEV_BURNING, *LPNET_DEV_BURNING;

// 设备刻录机信息
typedef struct _DH_BURNING_DEVINFO
{
    DWORD               dwDevNum;                           // 刻录设备个数
    NET_DEV_BURNING     stDevs[DH_MAX_BURNING_DEV_NUM];     // 各刻录设备信息
} DH_BURNING_DEVINFO, *LPDH_BURNING_DEVINFO;

// 刻录进度
typedef struct _DH_BURNING_PROGRESS
{

    BYTE                bBurning;                   // 刻录机状态；0：可以刻录，1：刻录机类型不对，是一个非光盘设备，
                                                    // 2：未找到刻录机，3：有其它光盘在刻录，4：刻录机处于非空闲状态，即在备份、刻录或回放中
    BYTE                bRomType;                   // 盘片类型；0：私有文件系统，1：移动硬盘或U盘，2：光盘
    BYTE                bOperateType;               // 操作类型；0：空闲，1：正在备份中，2：正在刻录中，3：正在进行光盘回放
    BYTE                bType;                      // 备份或刻录过程状态；0-停止 1-开始 2-出错 3-满 4-结束 5-正在初始化 6-暂停 7-等待附件
    NET_TIME            stTimeStart;                // 开始时间　
    DWORD               dwTimeElapse;               // 已刻录时间(秒)
    DWORD               dwTotalSpace;               // 光盘总容量
    DWORD               dwRemainSpace;              // 光盘剩余容量
    DWORD               dwBurned;                   // 已刻录容量
    WORD                dwStatus;                   // 保留
    WORD                wChannelMask;               // 正在刻录的通道掩码
} DH_BURNING_PROGRESS, *LPDH_BURNING_PROGRESS;

// 日志信息，对应接口CLIENT_QueryLog接口
typedef struct _DH_LOG_ITEM
{
    DHDEVTIME           time;                       // 日期
    unsigned short      type;                       // 类型
    unsigned char       reserved;                   // 保留
    unsigned char       data;                       // 数据
    unsigned char       context[8];                 // 内容
} DH_LOG_ITEM, *LPDH_LOG_ITEM;

// 日志信息，对应扩展接口CLIENT_QueryLogEx，参数reserved(int nType=1;reserved=&nType;)
typedef struct _DH_NEWLOG_ITEM
{
    DHDEVTIME           time;                       // 日期
    WORD                type;                       // 类型
    WORD                data;                       // 数据
    char                szOperator[8];              // 用户名
    BYTE                context[16];                // 内容    
} DH_NEWLOG_ITEM, *LPDH_NEWLOG_ITEM;

// 日志信息，对应接口CLIENT_QueryDeviceLog接口
typedef struct _DH_DEVICE_LOG_ITEM
{
    int                 nLogType;                   // 日志类型
    DHDEVTIME           stuOperateTime;             // 日期
    char                szOperator[16];             // 操作者
    BYTE                bReserved[3];
    BYTE                bUnionType;                 //  union结构类型,0:szLogContext；1:stuOldLog。
    union
    {
        char            szLogContext[64];           // 日志备注信息
        struct 
        {
            DH_LOG_ITEM     stuLog;                 // 旧的日志结构体
            BYTE            bReserved[48];          // 保留
        }stuOldLog;
    };
    char                reserved[16];
} DH_DEVICE_LOG_ITEM, *LPDH_DEVICE_LOG_ITEM;

// 新日志信息结构，对应接口CLIENT_QueryDeviceLog接口
typedef struct _DH_DEVICE_LOG_ITEM_EX
{
    int                 nLogType;                   // 日志类型
    DHDEVTIME           stuOperateTime;             // 日期
    char                szOperator[16];             // 操作者
    BYTE                bReserved[3];
    BYTE                bUnionType;                 //  union结构类型,0:szLogContext；1:stuOldLog。
    union
    {
        char            szLogContext[64];           // 日志备注信息
        struct 
        {
            DH_LOG_ITEM     stuLog;                 // 旧的日志结构体
            BYTE            bReserved[48];          // 保留
        }stuOldLog;
    };
    char                szOperation[32];            // 具体的操作内容
    char                szDetailContext[4*1024];    // 详细日志信息描述
} DH_DEVICE_LOG_ITEM_EX, *LPDH_DEVICE_LOG_ITEM_EX;

// 录象日志信息，对应日志结构体里的context
typedef struct _LOG_ITEM_RECORD
{
    DHDEVTIME           time;                       // 时间
    BYTE                channel;                    // 通道
    BYTE                type;                       // 录像类型
    BYTE                reserved[2];
} LOG_ITEM_RECORD, *LPLOG_ITEM_RECORD;

typedef struct _QUERY_DEVICE_LOG_PARAM
{
    DH_LOG_QUERY_TYPE   emLogType;                  // 查询日志类型
    NET_TIME            stuStartTime;               // 查询日志的开始时间
    NET_TIME            stuEndTime;                 // 查询日志的结束时间
    int                 nStartNum;                  // 在时间段中从第几条日志开始查询，开始第一次查询可设为0
    int                 nEndNum;                    // 一次查询中到第几条日志结束,日志返回条数的最大值为1024
    BYTE                nLogStuType;                // 日志数据结构体类型,0:表示DH_DEVICE_LOG_ITEM；1:表示DH_DEVICE_LOG_ITEM_EX
    BYTE                reserved[3];                // 保留 对齐
    unsigned int        nChannelID;                 // 通道号,0:兼容之前表示所有通道号，所以通道号从1开始; 1:第一个通道
    BYTE                bReserved[40];
} QUERY_DEVICE_LOG_PARAM;

// 设备硬盘里的录象信息
typedef struct __DEV_DISK_RECORD_INFO 
{
    NET_TIME            stuBeginTime;               // 最早录象时间
    NET_TIME            stuEndTime;                 // 最近录象时间
    char                reserved[128];
} DEV_DISK_RECORD_INFO;

// 设备硬盘录像时间信息
typedef struct __DEV_DISK_RECORD_TIME
{
    NET_TIME            stuStartTime1;              // 录像时间段1开始时间
    NET_TIME            stuEndTime1;                // 录像时间段1结束时间
    BOOL                bTwoPart;                   // 是否有第二段
    NET_TIME            stuStartTime2;              // 录像时间段2开始时间
    NET_TIME            stuEndTime2;                // 录像时间段2结束时间
    BYTE                bDiskNum;                   // 硬盘号
    BYTE                bSubareaNum;                // 分区号
    BYTE                byReserved[62];             // 保留字节  

}DEV_DISK_RECORD_TIME;

///////////////////////////////控制相关定义///////////////////////////////

// 硬盘操作
typedef struct _DISKCTRL_PARAM
{
    DWORD               dwSize;                     // 结构体大小，版本控制用
    int                 nIndex;                     // 为硬盘信息结构体DH_HARDDISK_STATE里的数组stDisks下标，从0开始
    int                 ctrlType;                   // 操作类型，
                                                    // 0 - 清除数据, 1 - 设为读写盘, 2 - 设为只读盘
                                                    // 3 - 设为冗余盘, 4 - 恢复错误, 5 - 设为快照盘，7 - 弹出SD卡（对SD卡操作有效）
    NET_DEV_DISKSTATE   stuDisk;                    // 磁盘信息, 由于磁盘顺序可能改变导致下标不准, 用来代替下标
} DISKCTRL_PARAM;

typedef struct  
{
    BYTE                bSubareaNum;                // 预分区的个数
    BYTE                bIndex;                     // 为硬盘信息结构体DH_HARDDISK_STATE里的数组stDisks下标，从0开始
    BYTE                bSubareaSize[32];           // 分区大小（百分比）
    BYTE                bReserved[30];              // 保留
} DISKCTRL_SUBAREA;

// 报警状态
typedef struct _ALARMCTRL_PARAM
{
    DWORD               dwSize;
    int                 nAlarmNo;                   // 报警通道号，从0开始
    int                 nAction;                    // 1：触发报警，0：停止报警
} ALARMCTRL_PARAM;

// 矩阵控制
typedef struct _MATRIXCTRL_PARAM
{
    DWORD               dwSize;
    int                 nChannelNo;                 // 视频输入号，从0开始
    int                 nMatrixNo;                  // 矩阵输出号，从0开始
} MATRIXCTRL_PARAM;

// 刻录控制
typedef struct _BURNING_PARM
{
    int                 channelMask;                // 通道掩码，按位表示要刻录的通道
    BYTE                devMask;                    // 刻录机掩码，根据查询到的刻录机列表，按位表示
    BYTE                bySpicalChannel;            // 画中画通道(通道数+32)
    BYTE                byReserved[2];              // 保留字段
} BURNNG_PARM;

// 附件刻录
typedef struct _BURNING_PARM_ATTACH
{
    BOOL                bAttachBurn;                // 是否为附件刻录，0:不是; 1:是
    BYTE                bReserved[12];              // 保留字段
} BURNING_PARM_ATTACH;

// 手动抓拍参数
typedef struct  _MANUAL_SNAP_PARAMETER{
    int                 nChannel;                   // 抓图通道,从0开始
    BYTE                bySequence[64];             // 抓图序列号字符串
    BYTE                byReserved[60];             // 保留字段
}MANUAL_SNAP_PARAMETER;

// 控制设备端本地预览分割参数
typedef struct _DEVICE_LOCALPREVIEW_SLIPT_PARAMETER
{
    int                 nSliptMode;                 // 分割模式，见设备端本地预览支持的分割模式
    int                 nSubSliptNum;               // 当前要预览的子分割,从1开始
    BYTE                byReserved[64];             // 保留字段
}DEVICE_LOCALPREVIEW_SLIPT_PARAMETER;

// 设备端本地预览支持的分割模式
typedef struct _DEVICE_LOCALPREVIEW_SLIPT_CAP
{
    int                 nModeNumber;
    int                 nSliptMode[36];             // 支持的分割模式，
    BYTE                byReserved[64];             // 保留字段
}DEVICE_LOCALPREVIEW_SLIPT_CAP;

// 路口信息
typedef struct  _CROSSING_INFO{
    char                szCrossingID[DH_MAX_CROSSING_ID];   // 路口序列号
    DWORD               dwLatitude;                         // 纬度(单位是百万分之度，范围0-180度)如北纬30（.）183382度表示为120183382)
    DWORD               dwLongitude;                        // 经度(单位是百万分之度，范围0-360度) 如东经120（.）178274度表示为300178274）
    WORD                wSpeedLimit;                        // 路口限速值,单位Km/h 0表示不限速,其他表示限速值上限
    BYTE                byReserved[22];
}CROSSING_INFO;

// 路线点位信息
typedef struct  _ROUTE_CROSSING_INFO{
    BYTE                byCrossingNum;                      // 路口有效数量范围1~DH_MAX_CROSSING_NUM
    BYTE                byReserved1;
    WORD                wCrossingRange;                     // 定位精度范围单位m
    CROSSING_INFO       stCrossingInfo[DH_MAX_CROSSING_NUM];// 路口信息最大支持128个路口
    BYTE                byReserved2[2044];
}ROUTE_CROSSING_INFO;

// raid操作
typedef struct _CTRL_RAID_INFO
{
    char                szAction[16];                       // Add增加，Delete删除
    char                szName[16];                         // Raid名称
    int                 nType;                              // 类型 1:Jbod     2:Raid0      3:Raid1     4:Raid5
    int                 nStatus;                            // 状态 0:unknown ，1:active，2:degraded，3:inactive，4:recovering
    int                 nCntMem;                            // nMember数组的有效数据个数
    int                 nMember[32];                        // 1,2,3,... 组成磁盘通道,是个数组
    int                 nCapacity;                          // 容量,单位G
    int                 nRemainSpace;                       // 剩余容量，单位M
    int                 nTank;                              // 扩展柜 0:主机，1:扩展柜1，2:扩展柜2，……
    char                reserved[128];
}CTRL_RAID_INFO;

// 热备操作
typedef struct _CTRL_SPARE_DISK_INFO
{
    char                szAction[16];                       // Enable，使能，Disable，不使能
    char                szScope[16];                        // Global，全局热备，Local，非全局热备
    char                szName[16];                         // 热备名字，若Scope为Global，则为热备池的名称，否则表示Raid组的名称
    unsigned int        nIndex;                             // 磁盘序号
    const char*         pszDevName;                         // 存储设备名称
    char                reserved[124];
}CTRL_SPARE_DISK_INFO;

typedef struct _CTRL_SPARE_DISK_INFO_A
{
    int                     nCnt;                           // 热备盘的个数
    CTRL_SPARE_DISK_INFO    stSpaceDiskInfo[32];
}CTRL_SPARE_DISK_INFO_A;

// 报警布撤防控制
typedef struct __CTRL_ARM_DISARM_PARAM
{
    BYTE                bState;                             // 布撤防状态，0表示撤防，1表示布防，2表示强制布防
    char                reserve[3];
    const char*         szDevPwd;                           // 用户密码
    NET_SCENE_MODE      emSceneMode;                        // 情景模式
    const char*         szDevID;                            // 转发目标设备ID,为NULL表示不转发
    char                reserve1[16];
} CTRL_ARM_DISARM_PARAM;


typedef struct tagDHCTRL_CONNECT_WIFI_BYWPS_IN
{
    DWORD               dwSize;
    int                 nType;                              // WPS连接类型,0:虚拟按钮方式; 1:(设备端)pin码方式; 2:(wifi热点端)pin码方式
    char                szSSID[DH_MAX_SSID_LEN];            // SSID，nType为1或2时有效，最大支持32位
    char                szApPin[DH_MAX_APPIN_LEN];          // APPIN码, nType为2时有效，PIN码为8位数字，这个pin码是从wifi热点端拿到的
    char                szWLanPin[DH_MAX_APPIN_LEN];        // 设备pin码,nType为1时有效:为空时由设备产生;不为空时即表示由用户设定，最大支持8位数字，这个pin码要在WIFI热点端增加
}DHCTRL_CONNECT_WIFI_BYWPS_IN;

typedef struct tagDHCTRL_CONNECT_WIFI_BYWPS_OUT
{
    DWORD               dwSize;
    char                szRetWLanPin[DH_MAX_APPIN_LEN];// 返回设备PIN码，当WPS连接类型为(设备端)pin码方式时该输出参数有效
}DHCTRL_CONNECT_WIFI_BYWPS_OUT;

// CLIENT_ControlDevice接口的DH_CTRL_WIFI_BY_WPS命令参数(WPS快速配置WIFI)
typedef struct tagDHCTRL_CONNECT_WIFI_BYWPS
{
    DWORD                dwSize;
    DHCTRL_CONNECT_WIFI_BYWPS_IN     stuWpsInfo;            // 连接参数(由用户填写)
    DHCTRL_CONNECT_WIFI_BYWPS_OUT    stuWpsResult;          // 返回数据(由设备返回)
} DHCTRL_CONNECT_WIFI_BYWPS;

// CLIENT_ControlDevice接口的 DH_CTRL_CLOSE_BURNER 等 命令参数
typedef struct tagNET_CTRL_BURNERDOOR
{
    DWORD               dwSize;
    const char*         szBurnerName;                       // 光盘名称，如“/dev/sda”
    BOOL                bResult;                            // 操作结果
    BOOL                bSafeEject;                         // 是否安全弹出光驱, TRUE-弹出前做数据保存, FALSE-直接弹出
}NET_CTRL_BURNERDOOR;

// CLIENT_ControlDevice接口的 DH_CTRL_START_PLAYAUDIO 命令参数
typedef struct tagNET_CTRL_START_PLAYAUDIO
{
    DWORD               dwSize;
    char                szAudioPath[DH_MAX_AUDIO_PATH];
}NET_CTRL_START_PLAYAUDIO;

// CLIENT_ControlDevice接口的 DH_CTRL_START_ALARMBELL、DH_CTRL_STOP_ALARMBELL命令参数
typedef struct tagNET_CTRL_ALARMBELL
{
    DWORD               dwSize;
    int                 nChannelID;             // 通道号(0开始)            
}NET_CTRL_ALARMBELL;

// CLIENT_ControlDevice接口的 DH_CTRL_ACCESS_OPEN 命令参数
typedef struct tagNET_CTRL_ACCESS_OPEN
{
    DWORD               dwSize;
    int                 nChannelID;             // 通道号(0开始)
}NET_CTRL_ACCESS_OPEN;

// CLIENT_ControlDevice接口的 DH_CTRL_ACCESS_CLOSE 命令参数
typedef struct tagNET_CTRL_ACCESS_CLOSE
{
    DWORD               dwSize;
    int                 nChannelID;             // 通道号(0开始)
}NET_CTRL_ACCESS_CLOSE;

typedef enum
{
    NET_ALARM_LOCAL,                            //开关量防区的报警事件
    NET_ALARM_ALARMEXTENDED,                    //扩展模块报警事件
    NET_ALARM_TEMP,                             //温度报警事件
    NET_ALARM_URGENCY,                          //紧急报警事件
}NET_ALARM_TYPE;

// CLIENT_ControlDevice接口的 DH_CTRL_CLEAR_ALARM 命令参数
typedef struct tagNET_CTRL_CLEAR_ALARM
{
    DWORD               dwSize;
    int                 nChannelID;             //防区通道号
    NET_ALARM_TYPE      emAlarmType;            //事件类型
    const char*         szDevPwd;               //登陆设备的密码,如不使用加密消警,直接赋值为NULL
}NET_CTRL_CLEAR_ALARM;

// 电视墙显示信息控制参数
typedef struct tagNET_CTRL_MONITORWALL_TVINFO 
{
    DWORD               dwSize;
    int                 nMonitorWallID;         // 电视墙ID
    BOOL                bDecodeChannel;         // 显示解码通道信息
} NET_CTRL_MONITORWALL_TVINFO;

// CLIENT_ControlDevice接口的 DH_CTRL_START_VIDEO_ANALYSE 命令参数
typedef struct tagNET_CTRL_START_VIDEO_ANALYSE
{
    DWORD               dwSize; 
    int                 nChannelId;             // 通道号  
}NET_CTRL_START_VIDEO_ANALYSE;

// CLIENT_ControlDevice接口的 DH_CTRL_STOP_VIDEO_ANALYSE 命令参数
typedef struct tagNET_CTRL_STOP_VIDEO_ANALYSE
{
    DWORD               dwSize; 
    int                 nChannelId;             // 通道号  
}NET_CTRL_STOP_VIDEO_ANALYSE;

// CLIENT_ControlDevice接口的 DH_CTRL_MULTIPLAYBACK_CHANNALES 命令参数 
typedef struct tagNET_CTRL_MULTIPLAYBACK_CHANNALES
{
    DWORD               dwSize;
    LLONG               lPlayBackHandle;        // 回放句柄，CLIENT_MultiPlayBack接口返回值
    int                 nChannels[DH_MAX_MULTIPLAYBACK_CHANNEL_NUM];// 预览通道号
    int                 nChannelNum;            // 预览通道数 
}NET_CTRL_MULTIPLAYBACK_CHANNALES;

// CLIENT_ControlDevice接口的 DH_CTRL_SET_BYPASS 命令参数
typedef struct tagNET_CTRL_SET_BYPASS
{
    DWORD               dwSize;
    const char*         szDevPwd;               // 登入设备的密码
    NET_BYPASS_MODE     emMode;                 // 通道状态
    int                 nLocalCount;            // 本地报警输入通道个数
    int*                pnLocal;                // 本地报警输入通道号    
    int                 nExtendedCount;         // 扩展模块报警输入通道个数
    int*                pnExtended;             // 扩展模块报警输入通道号
}NET_CTRL_SET_BYPASS;

// CLIENT_QueryDevState接口的 DH_DEVSTATE_GET_BYPASS 命令参数
typedef struct tagNET_DEVSTATE_GET_BYPASS
{
    DWORD               dwSize;
    int                 nLocalCount;            // 本地报警输入通道个数
    int*                pnLocal;                // 本地报警输入通道号    
    int                 nExtendedCount;         // 扩展模块报警输入通道个数
    int*                pnExtended;             // 扩展模块报警输入通道号
    NET_BYPASS_MODE*    pemLocal;               // 本地报警输入通道状态
    NET_BYPASS_MODE*    pemExtended;            // 扩展模块报警输入通道状态
}NET_DEVSTATE_GET_BYPASS;

// CLIENT_QueryDevState接口的 DH_DEVSTATE_BURNERDOOR 命令参数
typedef struct tagNET_DEVSTATE_BURNERDOOR
{
    DWORD               dwSize;
    const char*         szBurnerName;            // 光盘名称，如“/dev/sda”
    bool                bEjected;                // 是否已经弹出
    BYTE                Reserved[3];             // 保留
}NET_DEVSTATE_BURNERDOOR;

// CLIENT_QueryDevState接口的 DH_DEVSTATE_GET_DATA_CHECK 命令参数
typedef struct tagNET_DEVSTATE_DATA_CHECK
{
    DWORD               dwSize;                     // 结构体大小
    const char*         szBurnerName;               // 光盘名称，如“/dev/s",如果是多光盘的话，任何一个光盘都可以
    char                szState[DH_MAX_STRING_LEN]; // "NotStart":尚未开始,"Verifying":校验中,"Failed":失败,"Successed":成功
    int                 nPercent;                   // 校验百分比:0-100，state是Verifying时才有效
}NET_DEVSTATE_DATA_CHECK;

// CLIENT_ListenServer 接口回调fServiceCallBack函数支持的命令类型
enum { 
    DH_DVR_DISCONNECT=-1,                           // 验证期间设备断线回调
    DH_DVR_SERIAL_RETURN=1,                         // 设备注册携带序列号 对应 char* szDevSerial
    NET_DEV_AUTOREGISTER_RETURN,                    // 设备注册携带序列号和令牌 对应NET_CB_AUTOREGISTER
};
typedef struct tagNET_CB_AUTOREGISTER
{
    DWORD           dwSize;                          // 结构体大小
    char            szDevSerial[DH_DEV_SERIALNO_LEN];// 序列号
    char            szToken[MAX_PATH];               // 令牌
}NET_CB_AUTOREGISTER;

// 公网代理注册相关结构体
typedef struct tagCLOUDSERVICE_CONNECT_PARAM
{
    DWORD               dwSize;   
    char                szDstIp[DH_MAX_IPADDR_EX_LEN];    // 服务器IP
    int                 nDstPort;                         // 服务器端口号 
    DWORD               dwConnectType;                    // 连接类型：0表示主连接，1表示隧道连接，2数据连接, 3动态注册子连接（使用0Xb4注册）  
    char                szToken[MAX_PATH];                // 使用者自定义设备通道唯一ID令牌
}NET_CLOUDSERVICE_CONNECT_PARAM;

typedef struct tagCLOUDSERVICE_CONNECT_RESULT
{
    DWORD               dwSize;  
    DWORD               dwConnectState;                           // 当前连接状态：1成功，0失败
    char                szMessage[DH_MAX_CLOUDCONNECT_STATE_LEN]; // 连接状态信息,"Success","Password Error","Network Error","Timeout"
}NET_CLOUDSERVICE_CONNECT_RESULT;
///////////////////////////////配置相关定义///////////////////////////////

//-------------------------------设备属性---------------------------------
// 设备信息
typedef struct
{
    BYTE                sSerialNumber[DH_SERIALNO_LEN];     // 序列号
    BYTE                byAlarmInPortNum;                   // DVR报警输入个数
    BYTE                byAlarmOutPortNum;                  // DVR报警输出个数
    BYTE                byDiskNum;                          // DVR硬盘个数
    BYTE                byDVRType;                          // DVR类型，见枚举NET_DEVICE_TYPE
    union
    {
        BYTE            byChanNum;                          // DVR通道个数，登陆成功时有效
        BYTE            byLeftLogTimes;                     // 当登陆失败原因为密码错误时，通过此参数通知用户，剩余登陆次数，为0时表示此参数无效
    };
} NET_DEVICEINFO, *LPNET_DEVICEINFO;

// 设备信息扩展
typedef struct
{
    BYTE                sSerialNumber[DH_SERIALNO_LEN];     // 序列号
    int                 nAlarmInPortNum;                    // DVR报警输入个数
    int                 nAlarmOutPortNum;                   // DVR报警输出个数
    int                 nDiskNum;                           // DVR硬盘个数
    int                 nDVRType;                           // DVR类型，见枚举NET_DEVICE_TYPE
    int                 nChanNum;                           // DVR通道个数
    BYTE                byLimitLoginTime;                   // 在线超时时间，为0表示不限制登陆，非0表示限制的分钟数
    BYTE                byLeftLogTimes;                     // 当登陆失败原因为密码错误时，通过此参数通知用户，剩余登陆次数，为0时表示此参数无效
    char                Reserved[30];                       // 保留
} NET_DEVICEINFO_Ex, *LPNET_DEVICEINFO_Ex;

// 设备软件版本信息，高16位表示主版本号，低16位表示次版本号
typedef struct 
{
    DWORD               dwSoftwareVersion;
    DWORD               dwSoftwareBuildDate;
    DWORD               dwDspSoftwareVersion;
    DWORD               dwDspSoftwareBuildDate;
    DWORD               dwPanelVersion;
    DWORD               dwPanelSoftwareBuildDate;
    DWORD               dwHardwareVersion;
    DWORD               dwHardwareDate;
    DWORD               dwWebVersion;
    DWORD               dwWebBuildDate;
} DH_VERSION_INFO, *LPDH_VERSION_INFO;

// 设备软件版本信息，对应CLIENT_QueryDevState接口
typedef struct  
{
    char                szDevSerialNo[DH_DEV_SERIALNO_LEN];         // 序列号
    char                byDevType;                                  // 设备类型，见枚举NET_DEVICE_TYPE
    char                szDevType[DH_DEV_TYPE_LEN];                 // 设备详细型号，字符串格式，可能为空
    int                 nProtocalVer;                               // 协议版本号
    char                szSoftWareVersion[DH_MAX_URL_LEN];
    DWORD               dwSoftwareBuildDate;
    char                szPeripheralSoftwareVersion[DH_MAX_URL_LEN];// 从片版本信息，字符串格式，可能为空
    DWORD               dwPeripheralSoftwareBuildDate;
    char                szGeographySoftwareVersion[DH_MAX_URL_LEN]; // 地理信息定位芯片版本信息，字符串格式，可能为空
    DWORD               dwGeographySoftwareBuildDate;
    char                szHardwareVersion[DH_MAX_URL_LEN];
    DWORD               dwHardwareDate;
    char                szWebVersion[DH_MAX_URL_LEN];
    DWORD               dwWebBuildDate;
    char                reserved[256];
} DHDEV_VERSION_INFO;

// DSP能力描述，对应CLIENT_GetDevConfig接口
typedef struct 
{
    DWORD               dwVideoStandardMask;        // 视频制式掩码，按位表示设备能够支持的视频制式
    DWORD               dwImageSizeMask;            // 分辨率掩码，按位表示设备能够支持的分辨率设置
    DWORD               dwEncodeModeMask;           // 编码模式掩码，按位表示设备能够支持的编码模式设置    
    DWORD               dwStreamCap;                // 按位表示设备支持的多媒体功能，
                                                    // 第一位表示支持主码流
                                                    // 第二位表示支持辅码流1
                                                    // 第三位表示支持辅码流2
                                                    // 第五位表示支持jpg抓图
    DWORD               dwImageSizeMask_Assi[8];    // 表示主码流为各分辨率时，支持的辅码流分辨率掩码。
    DWORD               dwMaxEncodePower;           // DSP支持的最高编码能力 
    WORD                wMaxSupportChannel;         // 每块DSP支持最多输入视频通道数 
    WORD                wChannelMaxSetSync;         // DSP每通道的最大编码设置是否同步；0：不同步，1：同步
} DH_DSP_ENCODECAP, *LPDH_DSP_ENCODECAP;

// DSP能力描述，扩展类型，对应CLIENT_QueryDevState接口
typedef struct 
{
    DWORD               dwVideoStandardMask;        // 视频制式掩码，按位表示设备能够支持的视频制式
    DWORD               dwImageSizeMask;            // 分辨率掩码，按位表示设备能够支持的分辨率
    DWORD               dwEncodeModeMask;           // 编码模式掩码，按位表示设备能够支持的编码模式
    DWORD               dwStreamCap;                // 按位表示设备支持的多媒体功能，
                                                    // 第一位表示支持主码流
                                                    // 第二位表示支持辅码流1
                                                    // 第三位表示支持辅码流2
                                                    // 第五位表示支持jpg抓图
    DWORD               dwImageSizeMask_Assi[32];   // 表示主码流为各分辨率时，支持的辅码流分辨率掩码。
    DWORD               dwMaxEncodePower;           // DSP支持的最高编码能力 
    WORD                wMaxSupportChannel;         // 每块DSP支持最多输入视频通道数 
    WORD                wChannelMaxSetSync;         // DSP每通道的最大编码设置是否同步；0：不同步，1：同步
    BYTE                bMaxFrameOfImageSize[32];   // 不同分辨率下的最大采集帧率，与dwVideoStandardMask按位对应
    BYTE                bEncodeCap;                 // 标志，配置时要求符合下面条件，否则配置不能生效；
                                                    // 0：主码流的编码能力+辅码流的编码能力 <= 设备的编码能力，
                                                    // 1：主码流的编码能力+辅码流的编码能力 <= 设备的编码能力，
                                                    // 辅码流的编码能力 <= 主码流的编码能力，
                                                    // 辅码流的分辨率 <= 主码流的分辨率，
                                                    // 主码流和辅码流的帧率 <= 前端视频采集帧率
                                                    // 2：N5的计算方法
                                                    // 辅码流的分辨率 <= 主码流的分辨率
                                                    // 查询支持的分辨率和相应最大帧率
    char                reserved[95];
} DHDEV_DSP_ENCODECAP, *LPDHDEV_DSP_ENCODECAP;

// DSP扩展能力描述，对应CLIENT_QueryDevState接口
typedef struct 
{
    DWORD               dwVideoStandardMask;        // 视频制式掩码，按位表示设备能够支持的视频制式
    DWORD               dwImageSizeMask;            // 分辨率掩码，按位表示设备能够支持的分辨率
    DWORD               dwEncodeModeMask;           // 编码模式掩码，按位表示设备能够支持的编码模式
    DWORD               dwStreamCap;                // 按位表示设备支持的多媒体功能，
                                                    // 第一位表示支持主码流
                                                    // 第二位表示支持辅码流1
                                                    // 第三位表示支持辅码流2
                                                    // 第四位表示支持辅码流3
                                                    // 第五位表示支持jpg抓图
    DWORD               dwImageSizeMask_Assi[3][64];// 表示主码流为各分辨率时，支持的辅码流分辨率掩码, 数组中的0,1,2元素分别代表辅码流1,2,3
    DWORD               dwMaxEncodePower;           // DSP支持的最高编码能力 
    WORD                wMaxSupportChannel;         // 每块DSP支持最多输入视频通道数 
    WORD                wChannelMaxSetSync;         // DSP每通道的最大编码设置是否同步；0：不同步，1：同步
    BYTE                bMaxFrameOfImageSize[32];   // 不同分辨率下的最大采集帧率，与dwVideoStandardMask按位对应
    BYTE                bEncodeCap;                 // 标志，配置时要求符合下面条件，否则配置不能生效；
                                                    // 0：主码流的编码能力+辅码流的编码能力 <= 设备的编码能力，
                                                    // 1：主码流的编码能力+辅码流的编码能力 <= 设备的编码能力，
                                                    // 辅码流的编码能力 <= 主码流的编码能力，
                                                    // 辅码流的分辨率 <= 主码流的分辨率，
                                                    // 主码流和辅码流的帧率 <= 前端视频采集帧率
                                                    // 2：N5的计算方法
                                                    // 辅码流的分辨率 <= 主码流的分辨率
                                                    // 查询支持的分辨率和相应最大帧率
    BYTE                btReserve1[3];              // 字节对齐

    DWORD               dwExtraStream;              // 第0位表示主码流, 其它按位依次表示辅码流, 如第一位表示辅码流1,第二们表示辅码流2
    DWORD               dwCompression[3];           // 每一个值表示对应辅码流的编码格式支持
    
    char                reserved[108];
} DHDEV_DSP_ENCODECAP_EX, *LPDHDEV_DSP_ENCODECAP_EX;

// 系统信息
typedef struct 
{
    DWORD               dwSize;
    /* 下面是设备的只读部分 */
    DH_VERSION_INFO     stVersion;
    DH_DSP_ENCODECAP    stDspEncodeCap;                     // DSP能力描述
    BYTE                szDevSerialNo[DH_DEV_SERIALNO_LEN]; // 序列号
    BYTE                byDevType;                          // 设备类型，见枚举NET_DEVICE_TYPE
    BYTE                szDevType[DH_DEV_TYPE_LEN];         // 设备详细型号，字符串格式，可能为空
    BYTE                byVideoCaptureNum;                  // 视频口数量
    BYTE                byAudioCaptureNum;                  // 音频口数量
    BYTE                byTalkInChanNum;                    // 对讲输入接口数量
    BYTE                byTalkOutChanNum;                   // 对讲输出接口数量
    BYTE                byDecodeChanNum;                    // NSP
    BYTE                byAlarmInNum;                       // 报警输入口数
    BYTE                byAlarmOutNum;                      // 报警输出口数
    BYTE                byNetIONum;                         // 网络口数
    BYTE                byUsbIONum;                         // USB口数量
    BYTE                byIdeIONum;                         // IDE数量
    BYTE                byComIONum;                         // 串口数量
    BYTE                byLPTIONum;                         // 并口数量
    BYTE                byVgaIONum;                         // NSP
    BYTE                byIdeControlNum;                    // NSP
    BYTE                byIdeControlType;                   // NSP
    BYTE                byCapability;                       // NSP，扩展描述
    BYTE                byMatrixOutNum;                     // 视频矩阵输出口数
    /* 下面是设备的可写部分 */
    BYTE                byOverWrite;                        // 硬盘满处理方式(覆盖、停止)
    BYTE                byRecordLen;                        // 录象打包长度
    BYTE                byDSTEnable;                        // 是否实行夏令时 1-实行 0-不实行
    WORD                wDevNo;                             // 设备编号，用于遥控
    BYTE                byVideoStandard;                    // 视频制式:0-PAL,1-NTSC
    BYTE                byDateFormat;                       // 日期格式
    BYTE                byDateSprtr;                        // 日期分割符(0："."，1："-"，2："/")
    BYTE                byTimeFmt;                          // 时间格式 (0-24小时，1－12小时)
    BYTE                byLanguage;                         // 枚举值详见DH_LANGUAGE_TYPE
} DHDEV_SYSTEM_ATTR_CFG, *LPDHDEV_SYSTEM_ATTR_CFG;

// 修改设备配置返回信息
typedef struct
{
    DWORD               dwType;                     // 类型(即GetDevConfig和SetDevConfig的类型)
    WORD                wResultCode;                // 返回码；0：成功，1：失败，2：数据不合法，3：暂时无法设置，4：没有权限
    WORD                wRebootSign;                // 重启标志；0：不需要重启，1：需要重启才生效
    DWORD               dwReserved[2];              // 保留    
} DEV_SET_RESULT;

// 请求监视或回放的错误返回信息
typedef struct
{
    DWORD               dwResultCode;               // 错误返回码
                                                    // 1:无权限，2:设备不支持此操作，3:资源不足, 4:设备无法获取当前请求数据
                                                    // 11:表示高级用户抢占低级用户资源, 12:禁止入网, 13:磁盘读数据限制
                                                    // 14: 多画面预览已打开，资源不足，压缩回放失败, 15: 压缩回放功能已打开，导致失败 
    LLONG               lPlayHandle;                // 相应句柄值
    BYTE                byReserved[32];             // 保留字节                         

}DEV_PLAY_RESULT;

//DST(夏令时)配置
typedef struct  
{
    int                 nYear;                      // 年[200 - 2037]
    int                 nMonth;                     // 月[1 - 12]
    int                 nHour;                      // 小时 [0 - 23]
    int                 nMinute;                    // 分钟 [0 - 59]
    int                 nWeekOrDay;                 // [-1 - 4]0:表示使用按日期计算的方法
                                                    // 1: 按周计算: 第一周,2: 第二周,3: 第三周,4: 第四周,-1: 最后一周
    union
    {
        int             iWeekDay;                   // 周[0 - 6](nWeekOrDay：按周计算时)0:星期日, 1:星期一, 2:星期二,3:星期三,4:星期四,5:星期五,6:星期六
        int             iDay;                       // 日期[1 - 31] (nWeekOrDay：按日期计算)
    };
    
    DWORD               dwReserved[8];              // 保留    
}DH_DST_POINT;

typedef struct  
{
    DWORD               dwSize;
    int                 nDSTType;                   // 夏令时定位方式 0:按日期定位方式, 1:按周定位方式
    DH_DST_POINT        stDSTStart;                 // 开始夏令时
    DH_DST_POINT        stDSTEnd;                   // 结束夏令时
    DWORD               dwReserved[16];             // 保留    
}DHDEV_DST_CFG;


// 自动维护配置
typedef struct
{
    DWORD               dwSize;
    BYTE                byAutoRebootDay;            // 自动重启；0：从不, 1：每天，2：每星期日，3：每星期一，......
    BYTE                byAutoRebootTime;           // 0：0:00，1：1:00，......23：23:00
    BYTE                byAutoDeleteFilesTime;      // 自动删除文件；0：从不，1：24H，2：48H，3：72H，4：96H，5：ONE WEEK，6：ONE MONTH
    BYTE                reserved[13];               // 保留位
} DHDEV_AUTOMT_CFG;

// 车载中硬盘信息
typedef struct  
{
    DWORD               dwSize;                                     // 结构体大小,此属性必须初始化
    DWORD               dwVolume;                                   // 硬盘容量
    DWORD               dwFreeSpace;                                // 硬盘的剩余空间, 单位MB(B表示字节)
    BYTE                byModle[DH_MAX_HARDDISK_TYPE_LEN];          // 硬盘型号
    BYTE                bySerialNumber[DH_MAX_HARDDISK_SERIAL_LEN]; // 硬盘序列号
}DHDEV_VEHICLE_DISK;

// 车载相关的3G模块信息，最大支持DH_MAX_SIM_NUM个模块
typedef struct
{
    DWORD               dwSize;                                     // 结构体大小,此属性必须初始化
    BYTE                szIMSI[DH_MAX_SIM_LEN];                     // SIM卡的值例如460012002778636 ，前3位为国家代号MCC，4-6位为网络代号MNC,后面的为移动用户身份标识MSIN，总共不会超过15个字符
    BYTE                szMDN[DH_MAX_MDN_LEN];                      // SIM卡MDN值
}DHDEV_VEHICLE_3GMODULE;

// 车载的基本信息
typedef struct 
{
    DWORD                   dwSize;                                 // 结构体大小,此属性必须初始化
    DWORD                   dwSoftwareBuildDate;                    // 软件生成日期
    char                    szVersion[DH_MAX_VERSION_LEN];          // 软件版本
    char                    szDevSerialNo[DH_DEV_SERIALNO_LEN];     // 主板序列号
    char                    szDevType[DH_DEV_TYPE_LEN];             // 设备详细型号，字符串格式，可能为空
    DWORD                   dwDiskNum;                              // 硬盘个数
    DHDEV_VEHICLE_DISK      stuHarddiskInfo[DH_MAX_DISKNUM];        // 硬盘相关信息
    DWORD                   dw3GModuleNum;                          // 3G模块个数
    DHDEV_VEHICLE_3GMODULE  stu3GModuleInfo[DH_MAX_SIM_NUM];        // 3G模块相关信息
}DHDEV_VEHICLE_INFO;

// 网络接口，最大支持DH_MAX_NETINTERFACE_NUM个网卡
typedef struct tagDHDEV_NETINTERFACE_INFO
{
    int             dwSize;
    BOOL            bValid;                                         // 是否有效
    BOOL            bVirtual;                                       // 是否虚拟网卡
    int             nSpeed;                                         // 网卡理论速度(Mbps)
    int             nDHCPState;                                     // 0-未使能, 1-正在获取, 2-获取成功
    char            szName[DH_NETINTERFACE_NAME_LEN];               // 网口名称
    char            szType[DH_NETINTERFACE_TYPE_LEN];               // 网络类型
    char            szMAC[DH_MACADDR_LEN];                          // MAC地址
    char            szSSID[DH_MAX_SSID_LEN];                        // SSID, 只对无线网络有效(szType == "Wireless")
    char            szConnStatus[DH_MAX_CONNECT_STATUS_LEN];        // Wifi、3G的连接状态，"Inexistence" : 网络不存在 "Down"：关闭 "Disconn"：未连接 "Connecting"：正连接 "Connected"： 已连接
    int             nSupportedModeNum;                              // 实际3G支持的网络模式个数
    char            szSupportedModes[DH_MAX_MODE_NUM][DH_MAX_MODE_LEN];// 3G支持的网络模式    "TD-SCDMA", "WCDMA", "CDMA1x", "EDGE", "EVDO"
} DHDEV_NETINTERFACE_INFO;

//-----------------------------图像通道属性-------------------------------

// 时间段结构                                                                
typedef struct 
{
    int             bEnable;                        // 当表示录像时间段时，按位表示四个使能，从低位到高位分别表示动检录象、报警录象、普通录象、动检和报警同时发生才录像
    int             iBeginHour;
    int             iBeginMin;
    int             iBeginSec;
    int             iEndHour;
    int             iEndMin;
    int             iEndSec;
} DH_TSECT, *LPDH_TSECT;

// 区域；各边距按整长8192的比例
typedef struct 
{
   long             left;
   long             top;
   long             right;
   long             bottom;
} DH_RECT, *LPDH_RECT;

// 二维空间点
typedef struct 
{
   short            nx;
   short            ny;
} DH_POINT, *LPDH_POINT;

// 区域或曲线顶点信息
typedef struct
{
    int        nPointNum;                               // 顶点数
    DH_POINT   stuPoints[DH_MAX_DETECT_REGION_NUM];     // 顶点信息
}DH_POLY_POINTS;

// OSD属性结构
typedef struct  tagENCODE_WIDGET
{
    DWORD               rgbaFrontground;                // 物件的前景；按字节表示，分别为红、绿、蓝和透明度
    DWORD               rgbaBackground;                 // 物件的背景；按字节表示，分别为红、绿、蓝和透明度
    DH_RECT             rcRect;                         // 位置
    BYTE                bShow;                          // 显示使能
    BYTE                bExtFuncMask;                   // 扩展使能 ，掩码 
                                                        // bit0 表示是否显示星期几，0-不显示 1-显示 
    BYTE                byReserved[2];
} DH_ENCODE_WIDGET, *LPDH_ENCODE_WIDGET;

// 通道音视频属性
typedef struct 
{
    // 视频参数
    BYTE                byVideoEnable;                  // 视频使能；1：打开，0：关闭
    BYTE                byBitRateControl;               // 码流控制；参照常量"码流控制"定义
    BYTE                byFramesPerSec;                 // 帧率
    BYTE                byEncodeMode;                   // 编码模式；参照常量"编码模式"定义
    BYTE                byImageSize;                    // 分辨率；参照常量"分辨率"定义
    BYTE                byImageQlty:7;                  // 将byImageQlty进行扩展，若byImageQlty为0，抓图配置的ImgQlty为10/30/50/60/80/100六个值，码流配置的ImgQlty值为1-6，兼容之前的1-6档次，若//ImgQltyType为1，则ImgQlty范围为0~100
    BYTE                byImageQltyType:1;       
    WORD                wLimitStream;                   // 限码流参数
    // 音频参数
    BYTE                byAudioEnable;                  // 音频使能；1：打开，0：关闭
    BYTE                wFormatTag;                     // 音频编码类型: 0:G711A,1:PCM,2:G711U,3:AMR,4:AAC
    WORD                nChannels;                      // 声道数
    WORD                wBitsPerSample;                 // 采样深度    
    BYTE                bAudioOverlay;                  // 音频叠加使能
    BYTE                bH264ProfileRank;               // H.264 Profile等级(当编码模式为H264时此参数值有效),参照枚举类型EM_H264_PROFILE_RANK，传0，兼容以前，表示该字段无效，不需要考虑级别。
    DWORD               nSamplesPerSec;                 // 采样率
    BYTE                bIFrameInterval;                // I帧间隔帧数量，描述两个I帧之间的P帧个数，0-149
    BYTE                bScanMode;                      // NSP
    BYTE                bReserved_3;
    BYTE                bReserved_4;
} DH_VIDEOENC_OPT, *LPDH_VIDEOENC_OPT;

// 画面颜色属性
typedef struct 
{
    DH_TSECT            stSect;
    BYTE                byBrightness;                   // 亮度；0-100
    BYTE                byContrast;                     // 对比度；0-100
    BYTE                bySaturation;                   // 饱和度；0-100
    BYTE                byHue;                          // 色度；0-100
    BYTE                byGainEn;                       // 增益使能
    BYTE                byGain;                         // 增益；0-100
    BYTE                byGamma;                        // 伽马值 0-100
    BYTE                byReserved[1];
} DH_COLOR_CFG, *LPDH_COLOR_CFG;

// 图像通道属性结构体
typedef struct 
{
    WORD                dwSize;
    BYTE                bNoise;
    BYTE                bMode;                          // (车载特殊需求)模式一(画质优先):录像分辨率采用4路D1，帧率2fps，码率128kbps(每小时225MB)
                                                        // 模式二(流畅优先):录像分辨率采用4路CIF，帧率12fps，码率256kbps(每小时550MB)
                                                        // 模式三(自定义)录像分辨率可以由用户自定义，限定最大能力为4CIF/25fps
    char                szChannelName[DH_CHAN_NAME_LEN];
    DH_VIDEOENC_OPT     stMainVideoEncOpt[DH_REC_TYPE_NUM];
    DH_VIDEOENC_OPT     stAssiVideoEncOpt[DH_N_ENCODE_AUX];        
    DH_COLOR_CFG        stColorCfg[DH_N_COL_TSECT];
    DH_ENCODE_WIDGET    stTimeOSD;
    DH_ENCODE_WIDGET    stChannelOSD;
    DH_ENCODE_WIDGET    stBlindCover[DH_N_COVERS];      // 单区域遮挡
    BYTE                byBlindEnable;                  // 区域遮盖开关；0x00：不使能遮盖，0x01：仅遮盖设备本地预览，0x10：仅遮盖录像及网络预览，0x11：都遮盖
    BYTE                byBlindMask;                    // 区域遮盖掩码；第一位：设备本地预览；第二位：录像(及网络预览) */
    BYTE                bVolume;                        // 音量阀值(0~100可调)
    BYTE                bVolumeEnable;                  // 音量阀值使能
} DHDEV_CHANNEL_CFG, *LPDHDEV_CHANNEL_CFG;

// 预览图像参数
typedef struct 
{
    DWORD               dwSize;
    DH_VIDEOENC_OPT     stPreView;
    DH_COLOR_CFG        stColorCfg[DH_N_COL_TSECT];
}DHDEV_PREVIEW_CFG;

// 抓图控制配置
typedef struct _config_snap_control
{
    BYTE                bySnapState[32];                // 每个通道对应抓图开关 0:自动(则表示是否抓图，由其他配置和事件控制); 1:抓图开启; 2:抓图关闭
    BYTE                byReserved[480];
}DHDEV_SNAP_CONTROL_CFG;

enum _gps_mode
{
    GPS_OR_GLONASS_MODE,            // GPS、GLONASS混合模式(模块定位数据从GPS、GLONASS两者中获取，但具体来源于哪个系统不能确定,可能模块内部自动会处理)
    GLONASS_MODE,                   // GLONASS模式(即模块的定位数据从俄罗斯的GLONASS定位系统中获取)
    GPS_MODE,                       // GPS模式(即模块的定位数据从美国的GPS系统中获取) 
};
// DH_DEV_GPS_MODE_CFG 配置结构
typedef struct tagDHDEV_GPS_MODE_CFG
{
    BYTE                byGPSMode;                      // GPS定位模式，见
    BYTE                byRev[255];
}DHDEV_GPS_MODE_CFG;

// 图片上传配置信息 DH_DEV_SNAP_UPLOAD_CFG 配置结构
typedef struct tagDHDEV_SNAP_UPLOAD_CFG
{
    int                 nUploadInterval;                //定时抓图图片上传间隔，单位秒
    BYTE                byReserved[252];    
}DHDEV_SNAP_UPLOAD_CFG;


// DHDEV_SPEED_LIMIT_CFG 配置结构
typedef struct tagDHDEV_SPEED_LIMIT_CFG
{
    BYTE                byEnable;                       // 限速使能1：使能；0：不使能。
    BYTE                byReserved1;                    // 保留字段
    WORD                wMaxSpeed;                      // 速度上限值：单位KM/H 0表示不限速,大于0表示限速
    WORD                wMinSpeed;                      // 速度下限值：单位KM/H 0表示不限速,大于0表示限速
    BYTE                byReserved2[122];               // 保留字段
}DHDEV_SPEED_LIMIT_CFG;

// 无线路由配置
typedef struct
{
    BOOL                bEnable;                        // 使能
    char                szSSID[36];                     // SSID名称
    BOOL                bHideSSID;                      // 是否隐藏SSID
    char                szIP[DH_MAX_IPADDR_LEN];        // IP
    char                szSubMark[DH_MAX_IPADDR_LEN];   // 子网掩码
    char                szGateWay[DH_MAX_IPADDR_LEN];   // 网关
    char                szCountry[32];                  // 国家, Default默认不指定。国家名称列表参考无线路由能力信息
    int                 nSafeType;                      // 鉴权模式: 1-不加密; 2-WEP模式; 2-WPA-PSK模式; 3-WPA2-PSK模式
    int                 nEncryption;                    // 加密方式: WEP模式(1-自动 2-开放 3-共享); WPA-PSK模式/WPA2-PSK模式(4-TKIP 5-AES)
    char                szKey[32];                      // 连接密钥
    int                 nChannel;                       // 信道, 有效信道列表参考无线路由能力信息
    BOOL                bAutoChannelSelect;             // 自动选择信道    
}DHDEV_WIRELESS_ROUTING_CFG;

//-------------------------------串口属性---------------------------------

// 串口基本属性
typedef struct
{
    BYTE                byDataBit;                      // 数据位；0：5，1：6，2：7，3：8
    BYTE                byStopBit;                      // 停止位；0：1位，1：1.5位，2：2位
    BYTE                byParity;                       // 校验位；0：无校验，1：奇校验；2：偶校验; 3:标志校验; 4:空校验
    BYTE                byBaudRate;                     // 波特率；0：300，1：600，2：1200，3：2400，4：4800，
                                                        // 5：9600，6：19200，7：38400，8：57600，9：115200
} DH_COMM_PROP;

// 485解码器配置
typedef struct
{ 
    DH_COMM_PROP        struComm;
    BYTE                wProtocol;                      // 协议类型，对应"协议名列表"下标
    BYTE                bPTZType;                       // 0-兼容，本地云台 1-远程网络云台,通过能力查询(见DEV_ENCODER_CFG)。
    BYTE                wDecoderAddress;                // 解码器地址；0 - 255
    BYTE                byMartixID;                     // 矩阵号
} DH_485_CFG;

// 232串口配置
typedef struct
{
    DH_COMM_PROP        struComm;
    BYTE                byFunction;                     // 串口功能，对应"功能名列表"下标
    BYTE                byReserved[3];
} DH_RS232_CFG;

// 串口配置结构体
typedef struct
{
    DWORD               dwSize;

    DWORD               dwDecProListNum;                                        // 解码器协议个数
    char                DecProName[DH_MAX_DECPRO_LIST_SIZE][DH_MAX_NAME_LEN];   // 协议名列表
    DH_485_CFG          stDecoder[DH_MAX_DECODER_NUM];                          // 各解码器当前属性

    DWORD               dw232FuncNameNum;                                       // 232功能个数
    char                s232FuncName[DH_MAX_232FUNCS][DH_MAX_NAME_LEN];         // 功能名列表
    DH_RS232_CFG        st232[DH_MAX_232_NUM];                                  // 各232串口当前属性
} DHDEV_COMM_CFG;

// 扩展串口配置结构体
typedef struct
{
    DWORD               dwSize;
    
    DWORD               dwDecProListNum;                                        // 解码器协议个数
    char                DecProName[DH_MAX_DECPRO_LIST_SIZE][DH_MAX_NAME_LEN];   // 协议名列表
    DH_485_CFG          stDecoder[DH_MAX_DECODER_NUM];                          // 各解码器当前属性
    
    DWORD               dw232FuncNameNum;                                       // 232功能个数
    char                s232FuncName[DH_MAX_232FUNCS][DH_MAX_NAME_LEN];         // 功能名列表
    DWORD               dw232ComNum;                                            // 232串口个数   
    DH_RS232_CFG        st232[DH_MAX_232_NUM_EX];                               // 各232串口当前属性
} DHDEV_COMM_CFG_EX;

// 串口状态
typedef struct
{
    unsigned int        uBeOpened;
    unsigned int        uBaudRate;
    unsigned int        uDataBites;
    unsigned int        uStopBits;
    unsigned int        uParity;
    BYTE                bReserved[32];
} DH_COMM_STATE;

//-------------------------------录象配置---------------------------------

// 定时录象
typedef struct 
{
    DWORD               dwSize;
    DH_TSECT            stSect[DH_N_WEEKS][DH_N_REC_TSECT];
    BYTE                byPreRecordLen;                     // 预录时间，单位是s，0表示不预录
    BYTE                byRedundancyEn;                     // 录像冗余开关
    BYTE                byRecordType;                       // 录像码流类型：0-主码流 1-辅码流1 2-辅码流2 3-辅码流3
    BYTE                byReserved;
} DHDEV_RECORD_CFG, *LPDH_RECORD_CFG;

// NTP配置
typedef struct  
{
    BOOL                bEnable;                            // 是否启用
    int                 nHostPort;                          // NTP服务器默认端口为123
    char                szHostIp[32];                       // 主机IP
    char                szDomainName[128];                  // 域名
    int                 nType;                              // 不可设置，0：表示IP，1：表示域名，2：表示IP和域名
    int                 nUpdateInterval;                    // 更新时间(分钟)
    int                 nTimeZone;                          // 见DH_TIME_ZONE_TYPE
    char                reserved[128];
} DHDEV_NTP_CFG;

// FTP上传配置
typedef struct
{
    struct
    {
        DH_TSECT        struSect;                           // 该时间段内的“使能”无效，可忽略
        BOOL            bMdEn;                              // 上传动态检测录象
        BOOL            bAlarmEn;                           // 上传外部报警录象
        BOOL            bTimerEn;                           // 上传普通定时录像
        DWORD           dwRev[4];
    } struPeriod[DH_TIME_SECTION];
} DH_FTP_UPLOAD_CFG;

typedef struct
{
    DWORD               dwSize;
    BOOL                bEnable;                            // 是否启用
    char                szHostIp[DH_MAX_IPADDR_LEN];        // 主机IP
    WORD                wHostPort;                          // 主机端口
    char                szDirName[DH_FTP_MAX_PATH];         // FTP目录路径
    char                szUserName[DH_FTP_USERNAME_LEN];    // 用户名
    char                szPassword[DH_FTP_PASSWORD_LEN];    // 密码
    int                 iFileLen;                           // 文件长度
    int                 iInterval;                          // 相邻文件时间间隔(1~600),单位秒 
    DH_FTP_UPLOAD_CFG   struUploadCfg[DH_MAX_CHANNUM][DH_N_WEEKS];
    char                protocol;                           // 0-FTP 1-SMB 2-NFS，3-ISCSI
    char                NASVer;                             // 网络存储服务器版本0=老的FTP(界面上显示时间段)，1=NAS存储(界面上屏蔽时间段)
    DWORD               dwFunctionMask;                     // 功能能力掩码，按位表示，低16位(网络存储)依次表示FTP，SMB，NFS，ISCSI, 高16位(本地存储)依次为DISK，U
    BYTE                bDataType;                          // 数据类型, 0-所有类型, 1-视频, 2-图片
    BYTE                reserved[123];
} DHDEV_FTP_PROTO_CFG;

// FTP上传扩展配置(支持通道独立设置FTP存储路径，最大存储图片数等)
typedef struct 
{
    int            nMaxPictures;                             // 总存储张数，每一个通道文件夹中的图片数量可以限制，
                                                             // 超过限制就覆盖老的文件,0:表示不限制，写满为止
    char           szPreChannelName[DH_FTP_MAX_SUB_PATH];    // 图片文件名
    char           szFTPChannelPath[DH_FTP_MAX_SUB_PATH];    // ftp存储路径(存储子目录)
    char           szRev[128];                               // 保留字段
}DHDEV_FTP_CHANNEL_CFG; 


typedef struct 
{ 
    DHDEV_FTP_PROTO_CFG       stuFtpNormalSet;                     // FTP原有功能，扩展通道数
    DHDEV_FTP_CHANNEL_CFG     stuFtpChannelSet[DH_MAX_CHANNUM];    // FTP扩展功能
    char                      szRev[128];                          // 保留字段
}DHDEV_FTP_PROTO_CFG_EX;

//-------------------------------网络配置---------------------------------

// 以太网配置
typedef struct 
{
    char                sDevIPAddr[DH_MAX_IPADDR_LEN];      // DVR IP 地址
    char                sDevIPMask[DH_MAX_IPADDR_LEN];      // DVR IP 地址掩码
    char                sGatewayIP[DH_MAX_IPADDR_LEN];      // 网关地址

    /*
     * 1：10Mbps 全双工
     * 2：10Mbps 自适应
     * 3：10Mbps 半双工
     * 4：100Mbps 全双工
     * 5：100Mbps 自适应
     * 6：100Mbps 半双工
     * 7：自适应
     */
    // 为了扩展将DWORD拆成四个
    BYTE                dwNetInterface;                     // NSP
    BYTE                bTranMedia;                         // 0：有线，1：无线
    BYTE                bValid;                             // 按位表示，第一位：1：有效 0：无效；第二位：0：DHCP关闭 1：DHCP使能；第三位：0：不支持DHCP 1：支持DHCP
    BYTE                bDefaultEth;                        // 是否作为默认的网卡 1：默认 0：非默认
    char                byMACAddr[DH_MACADDR_LEN];          // MAC地址，只读
} DH_ETHERNET; 

// 远程主机配置
typedef struct 
{
    BYTE                byEnable;                           // 连接使能
    BYTE                byAssistant;                        // 目前只对于PPPoE服务器有用，0：在有线网卡拨号；1：在无线网卡上拨号
    WORD                wHostPort;                          // 远程主机 端口
    char                sHostIPAddr[DH_MAX_IPADDR_LEN];     // 远程主机 IP 地址        
    char                sHostUser[DH_MAX_HOST_NAMELEN];     // 远程主机 用户名
    char                sHostPassword[DH_MAX_HOST_PSWLEN];  // 远程主机 密码
} DH_REMOTE_HOST;

// 邮件配置
typedef struct 
{
    char                sMailIPAddr[DH_MAX_IPADDR_LEN];     // 邮件服务器IP地址
    WORD                wMailPort;                          // 邮件服务器端口
    WORD                wReserved;                          // 保留
    char                sSenderAddr[DH_MAX_MAIL_ADDR_LEN];  // 发送地址
    char                sUserName[DH_MAX_NAME_LEN];         // 用户名
    char                sUserPsw[DH_MAX_NAME_LEN];          // 用户密码
    char                sDestAddr[DH_MAX_MAIL_ADDR_LEN];    // 目的地址
    char                sCcAddr[DH_MAX_MAIL_ADDR_LEN];      // 抄送地址
    char                sBccAddr[DH_MAX_MAIL_ADDR_LEN];     // 暗抄地址
    char                sSubject[DH_MAX_MAIL_SUBJECT_LEN];  // 标题
} DH_MAIL_CFG;

// 网络配置结构体
typedef struct
{ 
    DWORD               dwSize; 
    char                sDevName[DH_MAX_NAME_LEN];          // 设备主机名
    WORD                wTcpMaxConnectNum;                  // TCP最大连接数
    WORD                wTcpPort;                           // TCP帧听端口
    WORD                wUdpPort;                           // UDP侦听端口
    WORD                wHttpPort;                          // HTTP端口号
    WORD                wHttpsPort;                         // HTTPS端口号
    WORD                wSslPort;                           // SSL端口号
    DH_ETHERNET         stEtherNet[DH_MAX_ETHERNET_NUM];    // 以太网口
    DH_REMOTE_HOST      struAlarmHost;                      // 报警服务器
    DH_REMOTE_HOST      struLogHost;                        // 日志服务器
    DH_REMOTE_HOST      struSmtpHost;                       // SMTP服务器
    DH_REMOTE_HOST      struMultiCast;                      // 多播组
    DH_REMOTE_HOST      struNfs;                            // NFS服务器
    DH_REMOTE_HOST      struPppoe;                          // PPPoE服务器
    char                sPppoeIP[DH_MAX_IPADDR_LEN];        // PPPoE注册返回的IP
    DH_REMOTE_HOST      struDdns;                           // DDNS服务器
    char                sDdnsHostName[DH_MAX_HOST_NAMELEN]; // DDNS主机名
    DH_REMOTE_HOST      struDns;                            // DNS服务器
    DH_MAIL_CFG         struMail;                           // 邮件配置
} DHDEV_NET_CFG;

// 以太网扩展配置
typedef struct 
{
    char                sDevIPAddr[DH_MAX_IPADDR_LEN];      // DVR IP 地址
    char                sDevIPMask[DH_MAX_IPADDR_LEN];      // DVR IP 地址掩码
    char                sGatewayIP[DH_MAX_IPADDR_LEN];      // 网关地址

    /*
     * 1：10Mbps 全双工
     * 2：10Mbps 自适应
     * 3：10Mbps 半双工
     * 4：100Mbps 全双工
     * 5：100Mbps 自适应
     * 6：100Mbps 半双工
     * 7：自适应
     */
    // 为了扩展将DWORD拆成四个
    BYTE                dwNetInterface;                     // NSP
    BYTE                bTranMedia;                         // 0：有线，1：无线
    BYTE                bValid;                             // 按位表示，第一位：1：有效 0：无效；第二位：0：DHCP关闭 1：DHCP使能；第三位：0：不支持DHCP 1：支持DHCP
    BYTE                bDefaultEth;                        // 是否作为默认的网卡 1：默认 0：非默认
    char                byMACAddr[DH_MACADDR_LEN];          // MAC地址，只读
    BYTE                bMode;                              // 网卡所处模式, 0:绑定模式, 1:负载均衡模式, 2:多址模式, 3:容错模式
    BYTE                bReserved[31];                      // 保留字节   
} DH_ETHERNET_EX; 

// 扩展网络配置结构体
typedef struct
{ 
    DWORD               dwSize; 
    char                sDevName[DH_MAX_NAME_LEN];          // 设备主机名
    WORD                wTcpMaxConnectNum;                  // TCP最大连接数
    WORD                wTcpPort;                           // TCP帧听端口
    WORD                wUdpPort;                           // UDP侦听端口
    WORD                wHttpPort;                          // HTTP端口号
    WORD                wHttpsPort;                         // HTTPS端口号
    WORD                wSslPort;                           // SSL端口号
    int                 nEtherNetNum;                       // 以太网口数
    DH_ETHERNET_EX      stEtherNet[DH_MAX_ETHERNET_NUM_EX]; // 以太网口
    DH_REMOTE_HOST      struAlarmHost;                      // 报警服务器
    DH_REMOTE_HOST      struLogHost;                        // 日志服务器
    DH_REMOTE_HOST      struSmtpHost;                       // SMTP服务器
    DH_REMOTE_HOST      struMultiCast;                      // 多播组
    DH_REMOTE_HOST      struNfs;                            // NFS服务器
    DH_REMOTE_HOST      struPppoe;                          // PPPoE服务器
    char                sPppoeIP[DH_MAX_IPADDR_LEN];        // PPPoE注册返回的IP
    DH_REMOTE_HOST      struDdns;                           // DDNS服务器
    char                sDdnsHostName[DH_MAX_HOST_NAMELEN]; // DDNS主机名
    DH_REMOTE_HOST      struDns;                            // DNS服务器
    DH_MAIL_CFG         struMail;                           // 邮件配置
    BYTE                bReserved[128];                     // 保留字节
} DHDEV_NET_CFG_EX;

// 多ddns配置结构体
typedef struct
{
    DWORD               dwId;                                           // ddns服务器id号
    BOOL                bEnable;                                        // 使能，同一时间只能有一个ddns服务器处于使能状态
    char                szServerType[DH_MAX_SERVER_TYPE_LEN];           // 服务器类型，希网..
    char                szServerIp[DH_MAX_DOMAIN_NAME_LEN];             // 服务器ip或者域名
    DWORD               dwServerPort;                                   // 服务器端口
    char                szDomainName[DH_MAX_DOMAIN_NAME_LEN];           // dvr域名，如jeckean.3322.org
    char                szUserName[DH_MAX_HOST_NAMELEN];                // 用户名
    char                szUserPsw[DH_MAX_HOST_PSWLEN];                  // 密码
    char                szAlias[DH_MAX_DDNS_ALIAS_LEN];                 // 服务器别名
    DWORD               dwAlivePeriod;                                  // DDNS 保活时间
    BYTE                ByMode;                                         // 域名模式:0-手动输入域名,szDomainName有效; 1-默认域名szDefaultDomainName有效。
    char                szDefaultDomainName[DH_MAX_DEFAULT_DOMAIN_LEN]; // 默认域名,只读
    BYTE                bReserved[3];                                   // 字节对齐
    char                szEmailUserName[DH_MAX_MAIL_NAME_LEN];	        // 邮箱用户名
    char                reserved[128];
} DH_DDNS_SERVER_CFG;

typedef struct
{
    DWORD                dwSize;
    DWORD                dwDdnsServerNum;    
    DH_DDNS_SERVER_CFG   struDdnsServer[DH_MAX_DDNS_NUM];    
} DHDEV_MULTI_DDNS_CFG;

// 邮件配置结构体
typedef struct 
{
    char                sMailIPAddr[DH_MAX_DOMAIN_NAME_LEN];    // 邮件服务器地址(IP或者域名)
    char                sSubMailIPAddr[DH_MAX_DOMAIN_NAME_LEN];
    WORD                wMailPort;                              // 邮件服务器端口
    WORD                wSubMailPort;
    WORD                wReserved;                              // 保留
    char                sSenderAddr[DH_MAX_MAIL_ADDR_LEN];      // 发送地址
    char                sUserName[DH_MAX_MAIL_NAME_LEN];        // 用户名
    char                sUserPsw[DH_MAX_MAIL_NAME_LEN];         // 用户密码
    char                sDestAddr[DH_MAX_MAIL_ADDR_LEN];        // 目的地址
    char                sCcAddr[DH_MAX_MAIL_ADDR_LEN];          // 抄送地址
    char                sBccAddr[DH_MAX_MAIL_ADDR_LEN];         // 暗抄地址
    char                sSubject[DH_MAX_MAIL_SUBJECT_LEN];      // 标题
    BYTE                bEnable;                                // 使能0:false,    1:true
    BYTE                bSSLEnable;                             // SSL使能
    WORD                wSendInterval;                          // 发送时间间隔,[0,3600]秒
    BYTE                bAnonymous;                             // 匿名选项[0,1], 0表示FALSE,1表示TRUE.
    BYTE                bAttachEnable;                          // 附件使能[0,1], 0表示FALSE,1表示TRUE.
    char                reserved[154];
} DHDEV_MAIL_CFG;

// DNS服务器配置
typedef struct  
{
    char                szPrimaryIp[DH_MAX_IPADDR_LEN];
    char                szSecondaryIp[DH_MAX_IPADDR_LEN];
    char                reserved[256];
} DHDEV_DNS_CFG;

// 录象下载策略配置
typedef struct
{
    DWORD               dwSize;
    BOOL                bEnable;                                // TRUE：高速下载，FALSE：普通下载
}DHDEV_DOWNLOAD_STRATEGY_CFG;

// 网络传输策略配置
typedef struct
{
    DWORD               dwSize;
    BOOL                bEnable;
    int                 iStrategy;                              // 0：画质优先，1：流畅性优先，2：自动
}DHDEV_TRANSFER_STRATEGY_CFG;

// 设置登入时的相关参数
typedef struct  
{
    int                 nWaittime;                              // 等待超时时间(毫秒为单位)，为0默认5000ms
    int                 nConnectTime;                           // 连接超时时间(毫秒为单位)，为0默认1500ms
    int                 nConnectTryNum;                         // 连接尝试次数，为0默认1次
    int                 nSubConnectSpaceTime;                   // 子连接之间的等待时间(毫秒为单位)，为0默认10ms
    int                 nGetDevInfoTime;                        // 获取设备信息超时时间，为0默认1000ms
    int                 nConnectBufSize;                        // 每个连接接收数据缓冲大小(字节为单位)，为0默认250*1024
    int                 nGetConnInfoTime;                       // 获取子连接信息超时时间(毫秒为单位)，为0默认1000ms
    int                 nSearchRecordTime;                      // 按时间查询录像文件的超时时间(毫秒为单位),为0默认为3000ms
    int                 nsubDisconnetTime;                      // 检测子链接断线等待时间(毫秒为单位)，为0默认为60000ms
    BYTE                byNetType;                              // 网络类型, 0-LAN, 1-WAN
    BYTE                byPlaybackBufSize;                      // 回放数据接收缓冲大小（M为单位），为0默认为4M
    BYTE                byReserved1[2];                         // 对齐
    int                 nPicBufSize;                            // 实时图片接收缓冲大小（字节为单位），为0默认为2*1024*1024
    BYTE                bReserved[4];                           // 保留字段字段
} NET_PARAM;

// 对应CLIENT_SearchDevices接口
typedef struct 
{
    char                szIP[DH_MAX_IPADDR_LEN];                // IP
    int                 nPort;                                  // tcp端口
    char                szSubmask[DH_MAX_IPADDR_LEN];           // 子网掩码
    char                szGateway[DH_MAX_IPADDR_LEN];           // 网关
    char                szMac[DH_MACADDR_LEN];                  // MAC地址
    char                szDeviceType[DH_DEV_TYPE_LEN];          // 设备类型
    BYTE                byManuFactory;                          // 目标设备的生产厂商,具体参考EM_IPC_TYPE类
    BYTE                byIPVersion;                            // 4: IPv4, szXXX为点分字符串形式;  6:IPv6, szXXX为128位(16字节)数值形式
    BYTE                bReserved[30];                          // 保留字节
} DEVICE_NET_INFO;

// 对应CLIENT_StartSearchDevices接口
typedef struct 
{
    int                 iIPVersion;                             // 4 for IPV4, 6 for IPV6
    char                szIP[64];                               // IP IPV4形如"192.168.0.1" IPV6形如"2008::1/64"
    int                 nPort;                                  // tcp端口
    char                szSubmask[64];                          // 子网掩码 IPV6无子网掩码
    char                szGateway[64];                          // 网关
    char                szMac[DH_MACADDR_LEN];                  // MAC地址
    char                szDeviceType[DH_DEV_TYPE_LEN];          // 设备类型
    BYTE                byManuFactory;                          // 目标设备的生产厂商,具体参考EM_IPC_TYPE类    
    BYTE                byDefinition;                           // 1-标清 2-高清
    bool                bDhcpEn;                                // Dhcp使能状态, true-开, false-关
    BYTE                byReserved1;                            // 字节对齐
    char                verifyData[88];                         // 校验数据 通过异步搜索回调获取(在修改设备IP时会用此信息进行校验)
    char                szSerialNo[DH_DEV_SERIALNO_LEN];        // 序列号
    char                szDevSoftVersion[DH_MAX_URL_LEN];       // 设备软件版本号    
    char                szDetailType[DH_DEV_TYPE_LEN];          // 设备型号
    char                szVendor[DH_MAX_STRING_LEN];            // OEM客户类型
    char                szDevName[DH_MACHINE_NAME_NUM];         // 设备名称
    char                szUserName[DH_USER_NAME_LENGTH_EX];     // 登陆设备用户名（在修改设备IP时需要填写）
    char                szPassWord[DH_USER_NAME_LENGTH_EX];     // 登陆设备密码（在修改设备IP时需要填写）
    unsigned short      nHttpPort;                              // HTTP服务端口号
    WORD                wVideoInputCh;                          // 视频输入通道数
    WORD                wRemoteVideoInputCh;                    // 远程视频输入通道数
    WORD                wVideoOutputCh;                         // 视频输出通道数
    WORD                wAlarmInputCh;                          // 报警输入通道数
    WORD                wAlarmOutputCh;                         // 报警输出通道数
    char                cReserved[244];
}DEVICE_NET_INFO_EX;

// 对应CLIENT_SearchDevicesByIPs接口
typedef struct
{
    DWORD               dwSize;                                 // 结构体大小
    int                 nIpNum;                                 // 当前搜索的IP个数
    char                szIP[DH_MAX_SAERCH_IP_NUM][64];         // 具体待搜索的IP信息
}DEVICE_IP_SEARCH_INFO;

// struct SNMP配置结构
typedef struct
{
    BOOL                bEnable;                                // SNMP使能
    int                 iSNMPPort;                              // SNMP端口
    char                szReadCommon[DH_MAX_SNMP_COMMON_LEN];   // 读共同体
    char                szWriteCommon[DH_MAX_SNMP_COMMON_LEN];  // 写共同体
    char                szTrapServer[64];                       // trap地址
    int                 iTrapPort;                              // trap端口
    BYTE                bSNMPV1;                                // 设备是否开启支持版本1格式，0不使能；1使能
    BYTE                bSNMPV2;                                // 设备是否开启支持版本2格式，0不使能；1使能
    BYTE                bSNMPV3;                                // 设备是否开启支持版本3格式，0不使能；1使能
    char                szReserve[125];
}DHDEV_NET_SNMP_CFG;

// ISCSI服务器结构定义
typedef struct
{
    char                szServerName[32];                       // 名称
    union
    { 
        BYTE            c[4];
        WORD            s[2];
        DWORD           l;
    }                   stuIP;                                  // IP地址
    int                 nPort;                                  // 端口号
    char                szUserName[32];                         // 用户名
    char                szPassword[32];                         // 密码
    BOOL                bAnonymous;                             // 是否匿名登录
}DHDEV_ISCSI_SERVER;

// ISCSI配置结构
typedef struct
{
    BOOL                bEnable;                                // 使能
    DHDEV_ISCSI_SERVER  stuServer;                              // 服务器
    char                szRemotePath[240];                      // 远程目录
    BYTE                reserved[256];
}DHDEV_ISCSI_CFG;

//-------------------------------报警属性---------------------------------

// 云台联动
typedef struct 
{
    int                 iType;
    int                 iValue;
} DH_PTZ_LINK, *LPDH_PTZ_LINK;

// 报警联动结构体
typedef struct 
{
    /* 消息处理方式，可以同时多种处理方式，包括
     * 0x00000001 - 报警上传
     * 0x00000002 - 联动录象
     * 0x00000004 - 云台联动
     * 0x00000008 - 发送邮件
     * 0x00000010 - 本地轮巡
     * 0x00000020 - 本地提示
     * 0x00000040 - 报警输出
     * 0x00000080 - Ftp上传
     * 0x00000100 - 蜂鸣
     * 0x00000200 - 语音提示
     * 0x00000400 - 抓图
    */


    DWORD               dwActionMask;                           // 当前报警所支持的处理方式，按位掩码表示 
    DWORD               dwActionFlag;                           // 触发动作，按位掩码表示，具体动作所需要的参数在各自的配置中体现 
    BYTE                byRelAlarmOut[DH_MAX_ALARMOUT_NUM];     // 报警触发的输出通道，报警触发的输出，为1表示触发该输出 
    DWORD               dwDuration;                             // 报警持续时间 
    BYTE                byRecordChannel[DH_MAX_VIDEO_IN_NUM];   // 报警触发的录象通道，为1表示触发该通道 
    DWORD               dwRecLatch;                             // 录象持续时间 
    BYTE                bySnap[DH_MAX_VIDEO_IN_NUM];            // 抓图通道 
    BYTE                byTour[DH_MAX_VIDEO_IN_NUM];            // 轮巡通道 
    DH_PTZ_LINK         struPtzLink[DH_MAX_VIDEO_IN_NUM];       // 云台联动 
    DWORD               dwEventLatch;                           // 联动开始延时时间，s为单位，范围是0~15，默认值是0 
    BYTE                byRelWIAlarmOut[DH_MAX_ALARMOUT_NUM];   // 报警触发的无线输出通道，报警触发的输出，为1表示触发该输出 
    BYTE                bMessageToNet;
    BYTE                bMMSEn;                                 // 短信报警使能
    BYTE                bySnapshotTimes;                        // 短信发送抓图张数 
    BYTE                bMatrixEn;                              // 矩阵使能 
    DWORD               dwMatrix;                               // 矩阵掩码           
    BYTE                bLog;                                   // 日志使能，目前只有在WTN动态检测中使用 
    BYTE                bSnapshotPeriod;                        // 抓图帧间隔，每隔多少帧抓一张图片，一定时间内抓拍的张数还与抓图帧率有关。0表示不隔帧，连续抓拍
    BYTE                byEmailType;                            // 0，图片附件，1，录像附件
    BYTE                byEmailMaxLength;                       // 附件录像时的最大长度，单位MB
    BYTE                byEmailMaxTime;                         // 附件是录像时最大时间长度，单位秒
    BYTE                byReserved[99];   
} DH_MSG_HANDLE;

// 外部报警
typedef struct
{
    BYTE                byAlarmType;                            // 报警器类型，0：常闭，1：常开
    BYTE                byAlarmEn;                              // 报警使能
    BYTE                byReserved[2];                        
    DH_TSECT            stSect[DH_N_WEEKS][DH_N_REC_TSECT];     //NSP
    DH_MSG_HANDLE       struHandle;                             // 处理方式
} DH_ALARMIN_CFG, *LPDHDEV_ALARMIN_CFG; 

// 动态检测报警
typedef struct 
{
    BYTE                byMotionEn;                             // 动态检测报警使能
    BYTE                byReserved;
    WORD                wSenseLevel;                            // 灵敏度
    WORD                wMotionRow;                             // 动态检测区域的行数
    WORD                wMotionCol;                             // 动态检测区域的列数
    BYTE                byDetected[DH_MOTION_ROW][DH_MOTION_COL]; // 检测区域，最多32*32块区域
    DH_TSECT            stSect[DH_N_WEEKS][DH_N_REC_TSECT];     //NSP
    DH_MSG_HANDLE       struHandle;                             //处理方式
} DH_MOTION_DETECT_CFG;

// 视频丢失报警
typedef struct
{
    BYTE                byAlarmEn;                              // 视频丢失报警使能
    BYTE                byReserved[3];
    DH_TSECT            stSect[DH_N_WEEKS][DH_N_REC_TSECT];     //NSP
    DH_MSG_HANDLE       struHandle;                             // 处理方式
} DH_VIDEO_LOST_CFG;

// 图像遮挡报警
typedef struct
{
    BYTE                byBlindEnable;                          // 使能
    BYTE                byBlindLevel;                           // 灵敏度1-6
    BYTE                byReserved[2];
    DH_TSECT            stSect[DH_N_WEEKS][DH_N_REC_TSECT];     // NSP
    DH_MSG_HANDLE       struHandle;                             // 处理方式
} DH_BLIND_CFG;

// 硬盘消息(内部报警)
typedef struct 
{
    BYTE                byNoDiskEn;                             // 无硬盘时报警
    BYTE                byReserved_1[3];
    DH_TSECT            stNDSect[DH_N_WEEKS][DH_N_REC_TSECT];   // NSP
    DH_MSG_HANDLE       struNDHandle;                           // 处理方式
    BYTE                byLowCapEn;                             // 硬盘低容量时报警
    BYTE                byLowerLimit;                           // 容量阀值，0-99
    BYTE                byReserved_2[2];
    DH_TSECT            stLCSect[DH_N_WEEKS][DH_N_REC_TSECT];   // NSP
    DH_MSG_HANDLE       struLCHandle;                           // 处理方式
    BYTE                byDiskErrEn;                            // 硬盘故障报警
    BYTE                bDiskNum;
    BYTE                byReserved_3[2];
    DH_TSECT            stEDSect[DH_N_WEEKS][DH_N_REC_TSECT];   //NSP
    DH_MSG_HANDLE       struEDHandle;                           // 处理方式
} DH_DISK_ALARM_CFG;

typedef struct
{
    BYTE                byEnable;
    BYTE                byReserved[3];
    DH_MSG_HANDLE       struHandle;
} DH_NETBROKEN_ALARM_CFG;

// 报警布防
typedef struct
{
    DWORD dwSize;
    DH_ALARMIN_CFG          struLocalAlmIn[DH_MAX_ALARM_IN_NUM];
    DH_ALARMIN_CFG          struNetAlmIn[DH_MAX_ALARM_IN_NUM];
    DH_MOTION_DETECT_CFG    struMotion[DH_MAX_VIDEO_IN_NUM];
    DH_VIDEO_LOST_CFG       struVideoLost[DH_MAX_VIDEO_IN_NUM];
    DH_BLIND_CFG            struBlind[DH_MAX_VIDEO_IN_NUM];
    DH_DISK_ALARM_CFG       struDiskAlarm;
    DH_NETBROKEN_ALARM_CFG  struNetBrokenAlarm;
} DHDEV_ALARM_SCHEDULE;

#define DECODER_OUT_SLOTS_MAX_NUM        16
#define DECODER_IN_SLOTS_MAX_NUM         16

// 报警解码器配置
typedef struct  
{
    DWORD               dwAddr;                                     // 报警解码器地址
    BOOL                bEnable;                                    // 报警解码器使能
    DWORD               dwOutSlots[DECODER_OUT_SLOTS_MAX_NUM];      // 现在只支持8个.
    int                 nOutSlotNum;                                // dwOutSlots数组有效元素个数.
    DH_TSECT            stSect[DH_N_WEEKS][DH_N_REC_TSECT];
    DH_MSG_HANDLE       struHandle[DECODER_IN_SLOTS_MAX_NUM];       // 现在只支持8个.
    int                 nMsgHandleNum;                              // stuHandle数组有效元素个数.
    BYTE                bReserved[120];
} DH_ALARMDEC_CFG;

// 报警上传的配置
typedef struct  
{
    BYTE                byEnable;                                   // 上传使能
    BYTE                bReserverd;                                 // 保留
    WORD                wHostPort;                                  // 报警中心侦听端口
    char                sHostIPAddr[DH_MAX_IPADDR_LEN];             // 报警中心IP
    int                 nByTimeEn;                                  // 定时上传使能，可以用来向中心上传IP或域名等
    int                 nUploadDay;                                 /* 设置上传日期    
                                                                       "Never = 0", "Everyday = 1", "Sunday = 2", 
                                                                       "Monday = 3", Tuesday = 4", "Wednesday = 5",
                                                                       "Thursday = 6", "Friday = 7", "Saturday = 8"*/    
    int                 nUploadHour;                                // 设置上传时间 ,[0~23]点
    DWORD               dwReserved[300];                            // 保留待扩展。
} ALARMCENTER_UP_CFG;

// 全景切换报警配置
typedef struct __DH_PANORAMA_SWITCH_CFG 
{
    BOOL                bEnable;                                    // 使能
    int                 nReserved[5];                               // 保留
    DH_TSECT            stSect[DH_N_WEEKS][DH_N_REC_TSECT];
    DH_MSG_HANDLE       struHandle;                                 // 报警联动
} DH_PANORAMA_SWITCH_CFG;

typedef struct __ALARM_PANORAMA_SWITCH_CFG 
{
    int                    nAlarmChnNum;                            // 报警通道个数
    DH_PANORAMA_SWITCH_CFG stuPanoramaSwitch[DH_MAX_VIDEO_IN_NUM];
} ALARM_PANORAMA_SWITCH_CFG;

// 失去焦点报警配置
typedef struct __DH_LOST_FOCUS_CFG
{
    BOOL                bEnable;                                    // 使能
    int                 nReserved[5];                               // 保留
    DH_TSECT            stSect[DH_N_WEEKS][DH_N_REC_TSECT];
    DH_MSG_HANDLE       struHandle;                                 // 报警联动
} DH_LOST_FOCUS_CFG;

typedef struct __ALARM_LOST_FOCUS_CFG 
{
    int                 nAlarmChnNum;                               // 报警通道个数
    DH_LOST_FOCUS_CFG   stuLostFocus[DH_MAX_VIDEO_IN_NUM];
} ALARM_LOST_FOCUS_CFG;

// IP冲突检测报警配置
typedef struct __ALARM_IP_COLLISION_CFG
{
    BOOL                bEnable;                                    // 使能
    DH_MSG_HANDLE       struHandle;                                 // 报警联动
    int                 nReserved[300];                             // 保留
} ALARM_IP_COLLISION_CFG;

// MAC冲突检测配置
typedef struct __ALARM_MAC_COLLISION_CFG
{
    BOOL                bEnable;                                    // 使能
    DH_MSG_HANDLE       struHandle;                                 // 报警联动
    int                 nReserved[300];                             // 保留
} ALARM_MAC_COLLISION_CFG;

// 232串口卡号信号、485串口卡号信号事件配置
typedef struct __COM_CARD_SIGNAL_INFO
{
    WORD                wCardStartPose;                             // 卡号起始位
    WORD                wCardLenth;                                 // 卡号长度
    char                cStartCharacter[32];                        // 开始符
    char                cEndCharacter[32];                          // 结束符
    BYTE                byReserved[28];                             // 保留字段 
}COM_CARD_SIGNAL_INFO;

// 232串口卡号信号、485串口卡号信号联动配置(在串口发过来的卡号信息满足配置的卡号信息后，将触发设备抓图)
typedef struct __COM_CARD_SIGNAL_LINK_CFG
{
    COM_CARD_SIGNAL_INFO  struCardInfo;                             // 卡号信息
    DH_MSG_HANDLE         struHandle;                               // 事件联动
    BYTE                  byReserved[24];                           // 保留字段

}COM_CARD_SIGNAL_LINK_CFG;

//------------------------------多区域遮挡--------------------------------

// 遮挡信息
typedef struct __VIDEO_COVER_ATTR
{
    DH_RECT             rcBlock;                                    // 覆盖的区域坐标
    int                 nColor;                                     // 覆盖的颜色
    BYTE                bBlockType;                                 // 覆盖方式；0：黑块，1：马赛克
    BYTE                bEncode;                                    // 编码级遮挡；1：生效，0：不生效
    BYTE                bPriview;                                   // 预览遮挡； 1：生效，0：不生效
    char                reserved[29];                               // 保留
} VIDEO_COVER_ATTR;

// 多区域遮挡配置
typedef struct __DHDEV_VIDEOCOVER_CFG 
{
    DWORD               dwSize;
    char                szChannelName[DH_CHAN_NAME_LEN];            // 只读
    BYTE                bTotalBlocks;                               // 支持的遮挡块数
    BYTE                bCoverCount;                                // 已设置的遮挡块数
    VIDEO_COVER_ATTR    CoverBlock[DH_MAX_VIDEO_COVER_NUM];         // 覆盖的区域    
    char                reserved[30];                               // 保留
}DHDEV_VIDEOCOVER_CFG;

// 设备的解码策略配置
typedef struct __DHDEV_DECODEPOLICY_CFG 
{
    int                 nMinTime;                                   // 码缓冲时间范围(只读)：最小缓冲时间(单位：ms)
    int                 nMaxTime;                                   // 码缓冲时间范围(只读)：最大缓冲时间(单位：ms)
    int                 nDeocdeBufTime;                             // 目标设备解码缓冲时间(单位：ms)
    char                reserved[128];                              // 保留
}DHDEV_DECODEPOLICY_CFG;

// 机器相关的配置
typedef struct __DHDEV_MACHINE_CFG 
{
    char                szMachineName[DH_MACHINE_NAME_NUM];         // 机器名称或编号
    char                szMachineAddress[DH_MACHINE_NAME_NUM];      // 机器部署地点
    char                reserved[128];                              // 保留
}DHDEV_MACHINE_CFG;

////////////////////////////////IPC产品支持////////////////////////////////

// 配置无线网络信息
typedef struct 
{
    int                 nEnable;                    // 无线使能
    char                szSSID[36];                 // SSID
    int                 nLinkMode;                  // 连接模式；0：auto，1：adhoc，2：Infrastructure
    int                 nEncryption;                // 加密；0：off，2：WEP64bit，3：WEP128bit, 4:WPA-PSK-TKIP, 5: WPA-PSK-CCMP
    int                 nKeyType;                   // 0：Hex，1：ASCII
    int                 nKeyID;                     // 序号
    union
    {
        char            szKeys[4][32];              // 四组密码
        char            szWPAKeys[128];             // nEncryption为4、5时使用，传128长度，不用结束符。
    };
    int                 nKeyFlag;
    BYTE                byConnectedFlag;            // 0: 无连接, 1: 连接 
    char                reserved[11];
} DHDEV_WLAN_INFO;

// 选择使用某个无线设备
typedef struct  
{
    char                szSSID[36];
    int                 nLinkMode;                  // 连接模式；0：adhoc，1：Infrastructure
    int                 nEncryption;                // 加密；0：off，2：WEP64bit，3：WEP128bit
    char                reserved[48];
} DHDEV_WLAN_DEVICE;

// 搜索到的无线设备列表
typedef struct  
{
    DWORD               dwSize;
    BYTE                bWlanDevCount;              // 搜索到的无线设备个数
    DHDEV_WLAN_DEVICE   lstWlanDev[DH_MAX_WLANDEVICE_NUM];
    char                reserved[255];
} DHDEV_WLAN_DEVICE_LIST;

// 无线设备扩展配置
typedef struct
{
    char                szSSID[36];                         // 服务名称
    char                szMacAddr[18];                      // mac地址
    BYTE                byApConnected;                      // 是否连接成功 0:没有，1: 连接成功
    BYTE                byLinkMode;                         // 连接模式 0:adhoc 1:Infrastructure;
    int                 nRSSIQuality;                       // 信号强度(dbm)
    unsigned int        unApMaxBitRate;                     // 站点的最大传输速率
    BYTE                byAuthMode;                         // 认证模式0:OPEN;1:SHARED;2:WPA;3:WPA-PSK;4:WPA2;5:WPA2-PSK;
                                                            // 6:WPA-NONE(用在adhoc网络模式),
                                                            // 7-11是混合模式，选择其中任何一种都可以进行连接 
                                                            // 7:WPA-PSK | WPA2-PSK; 8:WPA | WPA2; 9:WPA | WPA-PSK;
                                                            // 10:WPA2 | WPA2-PSK; 11:WPA | WPA-PSK |WPA2 |WPA2-PSK //12: UnKnown
    BYTE                byEncrAlgr;                         // 加密模式0:off; 2:WEP64bit; 3:WEP128bit; 4:WEP; 5:TKIP; 6:AES(CCMP)
                                                            // 7: TKIP+AES(混合模式) 8: UnKnown
    BYTE                byLinkQuality;                      // 连接强度 0~100(%)
    BYTE                byReserved[129];                    // Reserved 
}DHDEV_WLAN_DEVICE_EX;

// 搜索到的无线设备扩展配置列表
typedef struct  
{
    DWORD               dwSize;
    BYTE                bWlanDevCount;            // 搜索到的无线设备个数
    DHDEV_WLAN_DEVICE_EX  lstWlanDev[DH_MAX_WLANDEVICE_NUM_EX];
    char                reserved[255];
} DHDEV_WLAN_DEVICE_LIST_EX;

//测试设置有效性
typedef struct
{
    int                 nResult;                  // 0：表示设置成功，1：表示设置失败
    BYTE                reserved[32];
} DHDEV_FUNC_TEST;

// FTP服务器信息
typedef struct
{
    char                szServerName[32];          // 服务器名
    char                szIp[16];                  // IP地址
    int                 nPort;                     // 端口号
    char                szUserName[32];            // 用户名
    char                szPassword[32];            // 密码
    BOOL                bAnonymity;                // 是否匿名登录
    BYTE                byReserved[256];           // 保留字节
}FTP_SERVER_CFG;

// ftp服务器连接测试
typedef struct
{
    FTP_SERVER_CFG     stuFtpServerInfo;           // ftp服务器信息（由用户填写）
    DHDEV_FUNC_TEST    stuTestResult;              // ftp服务器连接状态(由设备返回)
    BYTE               byReserved[64];
}DHDEV_FTP_SERVER_TEST;

// DDNS域名信息
typedef struct
{

    char                szServerType[DH_MAX_SERVER_TYPE_LEN];   // 服务器类型，希网..
    char                szServerIp[DH_MAX_DOMAIN_NAME_LEN];     // 服务器ip或者域名
    DWORD               dwServerPort;                           // 服务器端口
    char                szDomainName[DH_MAX_DOMAIN_NAME_LEN];   // dvr域名，如jeckean.3322.org
    char                szUserName[DH_MAX_HOST_NAMELEN];        // 用户名
    char                szUserPsw[DH_MAX_HOST_PSWLEN];          // 密码
    BYTE                byReserved[256];                        // 保留字节
}DDNS_DOMAIN_INFO;


// DDNS域名是否可用测试
typedef struct
{
    DDNS_DOMAIN_INFO   stuDomainInfo;                           // DDNS域名信息（由用户填写）
    DHDEV_FUNC_TEST    stuTestResult;                           // 测试结果
    char               szMemo[128];                             // 测试结果描述
    BYTE               byReserved[64];
}DHDEV_DDNS_DOMAIN_TEST;


//表示硬盘的基本信息
typedef struct 
{
    BYTE                byModle[32];                  // 型号
    BYTE                bySerialNumber[32];           // 序列号
    BYTE                byFirmWare[32];               // 固件号
    int                 nAtaVersion;                  // ATA协议版本号
    int                 nSmartNum ;                   // smart 信息数
    INT64               Sectors;    
    int                 nStatus;                      // 磁盘状态 0-正常 1-异常
    int                 nReserved[33];                // 保留字节
} DHDEV_DEVICE_INFO;

//硬盘的smart信息，可能会有很多条，最多不超过30个　　
typedef struct
{
    BYTE    byId;               // ID
    BYTE    byCurrent;          // 属性值
    BYTE    byWorst;            // 最大出错值
    BYTE    byThreshold;        // 阈值
    char    szName[64];         // 属性名
    char    szRaw[8];           // 实际值
    int     nPredict;           // 状态
    char    reserved[128];
} DHDEV_SMART_VALUE;

//硬盘smart信息查询
typedef struct
{
    BYTE                nDiskNum;                       // 硬盘号
    BYTE                byRaidNO;                       // Raid子盘，0表示单盘
    BYTE                byReserved[2];                  // 保留字节
    DHDEV_DEVICE_INFO   deviceInfo;
    DHDEV_SMART_VALUE   smartValue[MAX_SMART_VALUE_NUM];
} DHDEV_SMART_HARDDISK;

// 各子模块信息
typedef struct
{
    char               szModuleName[64];      //  子模块名称
    char               szHardWareVersion[32]; //  子模块硬件版本号
    char               szSoftwareVersion[32]; //  子模块软件版本号
    BYTE               reserved[128]; 
} DHDEV_SUBMODELE_VALUE;

// 查询设备子模块信息
typedef struct
{
    int                    nSubModuleNum;                         //  返回子模块总数
    DHDEV_SUBMODELE_VALUE  stuSubmoduleValue[MAX_SUBMODULE_NUM];  //  子模块详细信息
    BYTE                   bReserved[256];
} DHDEV_SUBMODULE_INFO;

// 查询硬盘坏道能力
typedef struct
{
    BYTE                bDiskDamageLevel[DH_MAX_DISK_NUM];  //各磁盘坏道等级
    BYTE                bReserved[128];
} DHDEV_DISKDAMAGE_INFO;


// syslog的远程服务器配置
typedef struct 
{
    char    szServerIp[DH_MAX_IPADDR_OR_DOMAIN_LEN];    //服务器地址
    int     nServerPort;                                //服务器端口
    BYTE    bEnable;                                    //服务器使能
    BYTE    bReserved[255];                             //保留字节
}DHDEV_SYSLOG_REMOTE_SERVER;

// 视频备份配置
typedef struct
{
    BYTE    backupVideoFormat;                  // 备份文件类型, 0:dav, 1:asf
    BYTE    password[6];                        // 备份密码
    BYTE    reversed[505];
}DHDEV_BACKUP_VIDEO_FORMAT;


// 主动注册参数配置
typedef struct  
{
    char                szServerIp[32];             // 注册服务器IP
    int                 nServerPort;                // 端口号
    BYTE                byReserved[3];              // 对齐
    BYTE                bServerIpExEn;              // 注册服务器IP扩展使能,0-表示无效, 1-表示有效
    char                szServerIpEx[60];           // 注册服务器IP扩展，支持ipv4,ipv6,域名等类型的IP
} DHDEV_SERVER_INFO;

typedef struct  
{
    DWORD               dwSize;
    BYTE                bServerNum;                 // 支持的最大ip数
    DHDEV_SERVER_INFO   lstServer[DH_MAX_REGISTER_SERVER_NUM];
    BYTE                bEnable;                    // 使能
    char                szDeviceID[32];             // 设备id
    char                reserved[94];
} DHDEV_REGISTER_SERVER;

// 摄像头属性
typedef struct __DHDEV_CAMERA_INFO
{
    BYTE                bBrightnessEn;              // 亮度可调；1：可，0：不可
    BYTE                bContrastEn;                // 对比度可调
    BYTE                bColorEn;                   // 色度可调
    BYTE                bGainEn;                    // 增益可调
    BYTE                bSaturationEn;              // 饱和度可调
    BYTE                bBacklightEn;               // 背光补偿 0表示不支持背光补偿,1表示支持一级补偿（开,关），2表示支持两级补偿（关,高,低），3表示支持三级补偿（关,高,中,低）
    BYTE                bExposureEn;                // 曝光选择: 0:表示不支持曝光控制 1:表示只支持自动曝光 n:曝光的等级数(1表示支持自动曝光 2~n表示支持的手动控制曝光的等级)
    BYTE                bColorConvEn;               // 自动彩黑转换可调
    BYTE                bAttrEn;                    // 属性选项；1：可，0：不可
    BYTE                bMirrorEn;                  // 镜像；1：支持，0：不支持
    BYTE                bFlipEn;                    // 翻转；1：支持，0：不支持
    BYTE                iWhiteBalance;              // 白平衡 0-不支持白平衡，1-支持自动白平衡，2-支持预置白平衡（即情景模式） 3-支持自定义白平衡
    BYTE                iSignalFormatMask;          // 信号格式掩码，按位从低到高位分别为：0-Inside(内部输入) 1- BT656 2-720p 3-1080i  4-1080p  5-1080sF
    BYTE                bRotate90;                  // 90度旋转 0-不支持 1-支持
    BYTE                bLimitedAutoExposure;       // 是否支持带时间上下限的自动曝光
    BYTE                bCustomManualExposure;      // 是否支持用户自定义手动曝光时间
    BYTE                bFlashAdjustEn;             // 是否支持闪光灯调节
    BYTE                bNightOptions;              // 是否支持夜晚选项
    BYTE                iReferenceLevel;            // 是否支持参考电平设置
    BYTE                bExternalSyncInput;         // 是否支持外部同步信号输入，0-不支持，1-支持
    unsigned short      usMaxExposureTime;          // 自定义曝光区间最大曝光时间，单位毫秒         
    unsigned short      usMinExposureTime;          // 自定义曝光区间最小曝光时间，单位毫秒
    BYTE                bWideDynamicRange;          // 宽动态能力范围,0-表示不支持,2~n表示最大的范围值
    BYTE                bDoubleShutter;             // 双快门0不支持,1-支持双快门全帧率，即图像和视频只有快门参数不同，2-支持双快门半帧率，即图像和视频快门及白平衡参数均不同，3-支持双快门全帧率和半帧率
    BYTE                byExposureCompensation;     // 1支持， 0 不支持
    BYTE                bRev[109];                  // 保留
} DHDEV_CAMERA_INFO;

//夜晚特殊配置选项，在晚上光线较暗时自动切换到夜晚的配置参数
typedef struct __DHDEV_NIGHTOPTIONS 
{
    BYTE  bEnable;                                  // 0-不切换，1-切换 
                                                    // 大致日出和日落时间，日落之后日出之前，将采用夜晚特殊的配置。
                                                    // 00:00:00 ~23:59:59
    BYTE  bSunriseHour;
    BYTE  bSunriseMinute;
    BYTE  bSunriseSecond;
    BYTE  bSunsetHour;
    BYTE  bSunsetMinute;
    BYTE  bSunsetSecond;  
    BYTE  bWhiteBalance ;                           // 白平衡 0:Disabled,1:Auto 2:sunny 3:cloudy 4:home 5:office 6:night 7: Custom
    BYTE  bGainRed;                                 // 红色增益调节，白平衡为"Custom"模式下有效 0~100
    BYTE  bGainBlue;                                // 绿色增益调节，白平衡为"Custom"模式下有效 0~100
    BYTE  bGainGreen;                               // 蓝色增益调节，白平衡为"Custom"模式下有效 0~100
    BYTE  bGain;                                    // 0~100
    BYTE  bGainAuto;                                // 0-不自动增益 1-自动增益
    BYTE  bBrightnessThreshold ;                    // 亮度值 0~100
    BYTE  ReferenceLevel;                           // 电平参考值 0~100   
    BYTE  bExposureSpeed;                           // 取值范围取决于设备能力集：0-自动曝光 1~n-1-手动曝光等级 n-带时间上下限的自动曝光 n+1-自定义时间手动曝光 (n表示支持的曝光等级数）
    float ExposureValue1;                           // 自动曝光时间下限或者手动曝光自定义时间,毫秒为单位，取值0.1ms~80ms
    float ExposureValue2;                           // 自动曝光时间上限,毫秒为单位，取值0.1ms~80ms
    BYTE  bAutoApertureEnable;                      // 自动光圈使能,1开启,0关闭
    BYTE  bWideDynamicRange;                        // 宽动态值     取值范围由能力决定
    WORD  wNightSyncValue;                          // 夜晚相位 0~360
    WORD  wNightSyncValueMillValue;                 // 夜晚相位0~999(千分之一度),与wNightSyncValue组合构成夜晚相位值
    BYTE res[10];                                   // 保留
} DHDEV_NIGHTOPTIONS;

// 摄像头属性配置
typedef struct __DHDEV_CAMERA_CFG 
{
    DWORD                dwSize;
    BYTE                bExposure;                  // 曝光模式；取值范围取决于设备能力集：0-自动曝光，1-曝光等级1，2-曝光等级2…n-1最大曝光等级数 n带时间上下限的自动曝光 n+1自定义时间手动曝光 (n==bExposureEn）
    BYTE                bBacklight;                 // 背光补偿：背光补偿等级取值范围取决于设备能力集，0-关闭，1-背光补偿强度1，2-背光补偿强度2…n-最大背光补偿等级数 
    BYTE                bAutoColor2BW;              // 日/夜模式；3-根据时间自动切换 2：开(黑白)，1：根据亮度启动切换，0：关(彩色)
    BYTE                bMirror;                    // 镜像；1：开，0：关
    BYTE                bFlip;                      // 翻转；1：开，0：关
    BYTE                bLensEn;                    // 自动光圈功能能力: 1：支持；0 ：不支持
    BYTE                bLensFunction;              // 自动光圈功能: 1:开启自动光圈；0: 关闭自动光圈
    BYTE                bWhiteBalance;              // 白平衡 0:Disabled,1:Auto 2:sunny 3:cloudy 4:home 5:office 6:night 7: Custom
    BYTE                bSignalFormat;              // 信号格式0-Inside(内部输入) 1- BT656 2-720p 3-1080i  4-1080p  5-1080sF
    BYTE                bRotate90;                  // 0-不旋转，1-顺时针90°，2-逆时针90°
    BYTE                bReferenceLevel;            // 电平参考值 0~100  
    BYTE                byReserve;                  // 保留
    float               ExposureValue1;             // 自动曝光时间下限或者手动曝光自定义时间,毫秒为单位，取值0.1ms~80ms
    float               ExposureValue2;             // 自动曝光时间上限,毫秒为单位，取值0.1ms~80ms    
    DHDEV_NIGHTOPTIONS  stuNightOptions;            // 夜晚配置参数选项 
    BYTE                bGainRed;                   // 红色增益调节，白平衡为"Custom"模式下有效 0~100
    BYTE                bGainBlue;                  // 绿色增益调节，白平衡为"Custom"模式下有效 0~100
    BYTE                bGainGreen;                 // 蓝色增益调节，白平衡为"Custom"模式下有效 0~100
    BYTE                bFlashMode;                 // 闪光灯工作模式，0-关闭，1-始终，2-自动
    BYTE                bFlashValue;                // 闪光灯工作值, 0-0us, 1-64us, 2-128us,...15-960us
    BYTE                bFlashPole;                 // 闪光灯触发模式0-低电平 1-高电平
    BYTE                bExternalSyncPhase;         // 外部同步信号输入,0-内部同步 1-外部同步
    BYTE                bFlashInitValue;            // 闪光灯亮度预设值  区间0~100
    WORD                wExternalSyncValue ;        // 外同步的相位设置 0~360(小数点后3位数字有效)
    WORD                wExternalSyncValueMillValue;//  外同步的相位设置0~999(千分之一度),与wExternalSyncValue组合构成外同步的相位值
    BYTE                bWideDynamicRange;          //宽动态值     取值范围由能力决定
    BYTE                byExposureCompensation;     // 曝光补偿值，默认为7，范围0~14
    char                bRev[54];                   // 保留
} DHDEV_CAMERA_CFG;

#define ALARM_MAX_NAME 64
// (无线)红外报警配置
typedef struct
{
    BOOL                bEnable;                            // 报警输入使能
    char                szAlarmName[DH_MAX_ALARM_NAME];     // 报警输入名称
    int                 nAlarmInPattern;                    // 报警器输入波形
    int                 nAlarmOutPattern;                   // 报警输出波形
    char                szAlarmInAddress[DH_MAX_ALARM_NAME];// 报警输入地址
    int                 nSensorType;                        // 外部设备传感器类型常开 or 常闭
    int                 nDefendEfectTime;                   // 布撤防延时时间，在此时间后该报警输入有效
    int                 nDefendAreaType;                    // 防区类型 
    int                 nAlarmSmoothTime;                   // 报警平滑时间，即在此时间内如果只有一个报警输入连续输入两次则忽略掉后面一次
    char                reserved[128];
    DH_TSECT            stSect[DH_N_WEEKS][DH_N_REC_TSECT];
    DH_MSG_HANDLE       struHandle;                         // 处理方式
} DH_INFRARED_INFO;

// 无线遥控器配置
typedef struct 
{
    BYTE                address[ALARM_MAX_NAME];        // 遥控器地址
    BYTE                name[ALARM_MAX_NAME];           // 遥控器名称
    BYTE                reserved[32];                   // 保留字段
} DH_WI_CONFIG_ROBOT;

// 无线报警输出配置
typedef struct 
{
    BYTE                address[ALARM_MAX_NAME];        // 报警输出地址
    BYTE                name[ALARM_MAX_NAME];           // 报警输出名称
    BYTE                reserved[32];                   // 保留字段
} DH_WI_CONFIG_ALARM_OUT;

typedef struct  
{
    DWORD                   dwSize;
    BYTE                    bAlarmInNum;                // 无线报警输入数
    BYTE                    bAlarmOutNum;               // 无线报警输出数
    DH_WI_CONFIG_ALARM_OUT  AlarmOutAddr[16];           // 报警输出地址
    BYTE                    bRobotNum;                  // 遥控器个数
    DH_WI_CONFIG_ROBOT      RobotAddr[16];              // 遥控器地址
    DH_INFRARED_INFO        InfraredAlarm[16];
    char                    reserved[256];
} DH_INFRARED_CFG;

// 新音频检测报警信息
typedef struct
{
    int                 channel;                        // 报警通道号
    int                 alarmType;                      // 报警类型；0：音频值过低，1：音频值过高
    unsigned int        volume;                         // 音量值
    BYTE                byState;                        // 音频报警状态, 0: 音频报警出现, 1: 音频报警消失
    char                reserved[255];
} NET_NEW_SOUND_ALARM_STATE;

typedef struct  
{
    int                         channelcount;           // 报警的通道个数
    NET_NEW_SOUND_ALARM_STATE   SoundAlarmInfo[DH_MAX_ALARM_IN_NUM];
} DH_NEW_SOUND_ALARM_STATE;

// 抓图功能属性结构体
typedef struct 
{
    int                 nChannelNum;                // 通道号
    DWORD               dwVideoStandardMask;        // 分辨率(按位)，具体查看枚举CAPTURE_SIZE                        
    int                 nFramesCount;               // Frequence[128]数组的有效长度
    char                Frames[128];                // 帧率(按数值)
                                                    // -25：25秒1帧；-24：24秒1帧；-23：23秒1帧；-22：22秒1帧
                                                    // ……
                                                    // 0：无效；1：1秒1帧；2：1秒2帧；3：1秒3帧
                                                    // 4：1秒4帧；5：1秒5帧；17：1秒17帧；18：1秒18帧
                                                    // 19：1秒19帧；20：1秒20帧
                                                    // ……
                                                    // 25: 1秒25帧
    int                 nSnapModeCount;             // SnapMode[16]数组的有效长度
    char                SnapMode[16];               // (按数值)0：定时触发抓图，1：手动触发抓图
    int                 nPicFormatCount;            // Format[16]数组的有效长度
    char                PictureFormat[16];          // (按数值)0：BMP格式，1：JPG格式
    int                 nPicQualityCount;           // Quality[32]数组的有效长度
    char                PictureQuality[32];         // 按数值
                                                    // 100：图象质量100%；80:图象质量80%；60:图象质量60%
                                                    // 50:图象质量50%；30:图象质量30%；10:图象质量10%
    char                nReserved[128];             // 保留
} DH_QUERY_SNAP_INFO;

typedef struct 
{
    int                 nChannelCount;              // 通道个数
    DH_QUERY_SNAP_INFO  stuSnap[DH_MAX_CHANNUM];
} DH_SNAP_ATTR_EN;


/* IP过滤功能配置 */
#define DH_IPIFILTER_NUM            200             // IP
#define DH_IPIFILTER_NUM_EX         512             // IP

// IP信息
typedef struct 
{
    DWORD               dwIPNum;                                    // IP个数
    char                SZIP[DH_IPIFILTER_NUM][DH_MAX_IPADDR_LEN];  // IP
    char                byReserve[32];                              // 保留
} IPIFILTER_INFO;

// IP过滤配置结构体
typedef struct
{
    DWORD               dwSize;
    DWORD               dwEnable;                   // 使能
    DWORD               dwType;                     // 当前名单类型：0：白名单 1：黑名单（设备只能使一种名单生效，或者是白名单或者是黑名单）
    IPIFILTER_INFO      BannedIP;                   // 黑名单
    IPIFILTER_INFO      TrustIP;                    // 白名单
    char                byReserve[256];             // 保留
} DHDEV_IPIFILTER_CFG;

// IP信息扩展
typedef struct 
{
    DWORD               dwIPNum;                                        // IP个数
    char                SZIP[DH_IPIFILTER_NUM_EX][DH_MAX_IPADDR_LEN];   // IP
    char                byReserve[32];                                  // 保留
} IPIFILTER_INFO_EX;

// IP过滤配置结构体扩展
typedef struct
{
    DWORD                dwSize;
    DWORD                dwEnable;                  // 使能
    DWORD                dwType;                    // 当前名单类型：0：白名单 1：黑名单（设备只能使一种名单生效，或者是白名单或者是黑名单）
    IPIFILTER_INFO_EX    BannedIP;                  // 黑名单
    IPIFILTER_INFO_EX    TrustIP;                   // 白名单
    char                 byReserve[256];            // 保留
} DHDEV_IPIFILTER_CFG_EX;

/* MAC过滤配置 */
#define DH_MACFILTER_NUM            512             // MAC

// MAC信息
typedef struct 
{
    DWORD                dwSize;                                    // 使用时，用初始化为本结构体大小
    DWORD                dwMacNum;                                  // MAC个数
    char                 szMac[DH_MACFILTER_NUM][DH_MACADDR_LEN];   // MAC
} MACFILTER_INFO;

// MAC过滤配置结构体
typedef struct
{
    DWORD                 dwSize;                   // 使用时，用初始化为本结构体大小
    DWORD                 dwEnable;                 // 使能
    DWORD                 dwType;                   // 当前名单类型：0：白名单 1：黑名单（设备只能使一种名单生效，或者是白名单或者是黑名单）
    MACFILTER_INFO        stuBannedMac;             // 黑名单Mac
    MACFILTER_INFO        stuTrustMac;              // 白名单Mac
} DHDEV_MACFILTER_CFG;

/* MAC,IP过滤配置 */
#define DH_MACIPFILTER_NUM           512            // MAC,IP

// MAC，IP过滤信息
typedef struct
{
    DWORD       dwSize;                             // 使用时，用初始化为本结构体大小
    char        szMac[DH_MACADDR_LEN];              // mac
    char        szIp[DH_MAX_IPADDR_LEN];            // ip
}MACIP_INFO;

// MAC,IP过滤配置结构体
typedef struct
{
    DWORD                    dwSize;                                // 使用时，用初始化为本结构体大小
    DWORD                    dwEnable;                              // 使能
    DWORD                    dwType;                                // 当前名单类型：0：白名单 1：黑名单（设备只能使一种名单生效，或者是白名单或者是黑名单）
    DWORD                    dwBannedMacIpNum;                      // 黑名单MAC,IP个数(MAC,IP一一对应)
    MACIP_INFO               stuBannedMacIp[DH_MACIPFILTER_NUM];    // 黑名单Mac,IP
    DWORD                    dwTrustMacIpNum;                       // 白名单MAC,IP个数(MAC,IP一一对应)
    MACIP_INFO               stuTrustMacIp[DH_MACIPFILTER_NUM];     // 白名单Mac,IP
} DHDEV_MACIPFILTER_CFG;

typedef struct
{
    int                nCardNum;                                        // 有效卡号数
    char               cardInfo [DH_MAX_CARD_NUM][DH_MAX_CARDINFO_LEN]; // 卡号信息字符串 
    BYTE               byReserve[32];                                   // 保留字段
}DHDEV_NETCARD_CFG;

// RTSP 配置
typedef struct
{
    WORD               wPort;                  // 端口号
    BYTE               byReserved[62];         // 保留字段
}DHDEV_RTSP_CFG;

//-------------------------码流加密配置---------
// 具体密钥信息36个字节
typedef struct _ENCRYPT_KEY_INFO
{
    BYTE        byEncryptEnable;       //  是否加密0:不加密, 1:加密
    BYTE        byReserved[3]; 
    union
    {
        BYTE    byDesKey[8];           // des密钥
        BYTE    by3DesKey[3][8];       // 3des密钥
        BYTE    byAesKey[32];          // aes密钥

    };
}ENCRYPT_KEY_INFO;

// 加密算法参数
typedef struct _ALGO_PARAM_INFO
{
    WORD       wEncryptLenth;       // 密钥长度，当前为AES算法类型时，表示密钥位数(目前支持128，192，256位三种, 如: wEncryptLenth为128，则密钥信息ENCRYPT_KEY_INFO里的byAesKey[0]~[15])
                                    // 为DES算法类型时，密钥长度固定为64位
                                    // 为3DES算法类型时，表示密钥的个数(2或3个密钥)
    BYTE       byAlgoWorkMode ;     // 工作模式,参考枚举类型 EM_ENCRYPT_ALOG_WORKMODE 
    BYTE       reserved[13];        // 保留字段
}ALGO_PARAM_INFO;

// 码流加密配置信息
typedef struct _DHEDV_STREAM_ENCRYPT
{
    BYTE                    byEncrptAlgoType;           // 加密算法类型：00: AES、01:DES、02: 3DES
    BYTE                    byReserved1[3];
    ALGO_PARAM_INFO         stuEncrptAlgoparam;         // 加密算法参数
    ENCRYPT_KEY_INFO        stuEncryptKeys[32];         // 各通道的密钥信息 
    BYTE                    byEncrptPlanEnable;         // 加密计划使能
    BYTE                    byReserved3[3];
    NET_TIME                stuPreTime;                 // 加密计划的开始时间
    BYTE                    reserved2[1360];
}DHEDV_STREAM_ENCRYPT;

// 限码流配置
typedef struct _DHDEV_BIT_RATE
{
    DWORD                   nExpectCodeRate;          // 限制码流，单位kps
    BYTE                    byReserved[64];           // 保留字节
}DHDEV_LIMIT_BIT_RATE;

// 用户自定义配置
typedef struct _DHDEV_CUSTOM_CFG
{
    char                   szData[1024];            // 用户自定义配置信息
    char                   reserved[3072];          // 保留字段
}DHDEV_CUSTOM_CFG;

/*语音对讲编码配置*/
typedef struct
{
    DWORD               dwSize;
    int                 nCompression;               // 压缩格式，枚举值，相见DH_TALK_CODING_TYPE，请根据设备支持的语音对讲类型设置压缩格式。
    int                 nMode;                      // 编码模式，枚举值，为0时表示该压缩格式不支持编码模式。
                                                    // 根据压缩格式可以设置对应的编码格式，如
                                                    // AMR详见EM_ARM_ENCODE_MODE
    char                 byReserve[256];            // 保留
} DHDEV_TALK_ENCODE_CFG;

// 以下是mobile功能相关
// (事件触发多媒体彩信/短信发送)MMS配置结构体
typedef struct
{
    DWORD               dwSize;
    DWORD               dwEnable;                               // 使能
    DWORD               dwReceiverNum;                          // 短信接收者个数
    char                SZReceiver[DH_MMS_RECEIVER_NUM][32];    // 短信接收者，一般为手机号码
    BYTE                byType;                                 // 短信信息类型 0:MMS；1:SMS
    char                SZTitle[32];                            // 短信信息标题
    char                byReserve[223];                         // 保留
} DHDEV_MMS_CFG;

// (短信激活无线连接配置)
typedef struct  
{
    DWORD               dwSize;
    DWORD               dwEnable;                               // 使能
    DWORD               dwSenderNum;                            // 短信发送者个数
    char                SZSender[DH_MMS_SMSACTIVATION_NUM][32]; // 短信发送者，一般为手机号码
     char               byReserve[256];                         // 保留
}DHDEV_SMSACTIVATION_CFG;

// (拨号激活无线连接配置)
typedef struct  
{
    DWORD               dwSize;
    DWORD               dwEnable;                               // 使能
    DWORD               dwCallerNum;                            // 发送者个数
    char                SZCaller[DH_MMS_DIALINACTIVATION_NUM][32];// 发送者, 一般为手机号码
    char                byReserve[256];                         // 保留
}DHDEV_DIALINACTIVATION_CFG;
// 以上是mobile功能相关


// 无线网络信号强度结构体
typedef struct
{
    DWORD               dwSize;
    DWORD               dwTDSCDMA;                  // TD-SCDMA强度，范围：0－100
    DWORD               dwWCDMA;                    // WCDMA强度，范围：0－100
    DWORD               dwCDMA1x;                   // CDMA1x强度，范围：0－100
    DWORD               dwEDGE;                     // EDGE强度，范围：0－100
    DWORD               dwEVDO;                     // EVDO强度，范围：0－100
    int                 nCurrentType;               // 当前类型
                                                    // 0 设备不支持这一项
                                                    // 1 TD-SCDMA
                                                    // 2 WCDMA
                                                    // 3 CDMA_1x
                                                    // 4 EDGE
                                                    // 5 EVDO
                                                    // 6 TD-LTE
    DWORD               dwTDLTE;                    // TD-LTE强度，范围：0－100
    char                byReserve[248];             // 保留
} DHDEV_WIRELESS_RSS_INFO;

typedef struct _DHDEV_SIP_CFG
{
    BOOL        bUnregOnBoot;                       //Unregister on Reboot
    char        szAccoutName[64];                   //Account Name
    char        szSIPServer[128];                   //SIP Server
    char        szOutBoundProxy[128];               //Outbound Proxy
    DWORD       dwSIPUsrID;                         //SIP User ID
    DWORD       dwAuthID;                           //Authenticate ID
    char        szAuthPsw[64];                      //Authenticate Password
    char        szSTUNServer[128];                  //STUN Server
    DWORD       dwRegExp;                           //Registration Expiration
    DWORD       dwLocalSIPPort;                     //Local SIP Port
    DWORD       dwLocalRTPPort;                     //Local RTP Port
    BOOL        bEnable;                            // 使能
    char        szNotifyID[128];                    // 联动ID
    NET_TIME    stuRegTime;                         // 注册成功的时间；只读字段，设备指定。   
    BYTE        bReserved[868];                     //reserved
} DHDEV_SIP_CFG;

typedef struct _DHDEV_SIP_STATE
{
    int         nStatusNum;                         //状态信息总的个数
    BYTE        byStatus[64];                       //0:注册成功,1:未注册,2:无效,3:注册中,4:通话中
    BYTE        bReserved[64];                      //保留
}DHDEV_SIP_STATE;

typedef struct _DHDEV_HARDKEY_STATE
{
    BOOL        bState;                             // 0:未插入HardKey, 1:已插入HardKey
    BYTE        bReserved[64];                      // 保留
}DHDEV_HARDKEY_STATE;

typedef struct _DHDEV_ISCSI_PATHLIST
{
    int         nCount;
    char        szPaths[DH_MAX_ISCSI_PATH_NUM][MAX_PATH_STOR];    // 远程目录数组
} DHDEV_ISCSI_PATHLIST;

// 无线路由能力信息
typedef struct _DHDEV_WIFI_ROUTE_CAP_COUNTRY
{
    char        szCountry[32];                      // 国家
    int         nValidChnNum;                       // 有效通道数量
    int         nValideChannels[32];                // 有效通道列表
    char        reserved[64];                       // 保留
} DHDEV_WIFI_ROUTE_CAP_COUNTRY;

typedef struct _DHDEV_WIFI_ROUTE_CAP
{
    int         nCountryNum;                        // 国家数量
    DHDEV_WIFI_ROUTE_CAP_COUNTRY stuCountry[256];   // 不同国家的配置信息
    char        reserved[256];                      // 保留
} DHDEV_WIFI_ROUTE_CAP;

//  画面监控辅助信息
typedef struct _MONITOR_INFO
{
    int         nPresetObjectNum;                   // 预置应有目标数目
    int         nActualObjectNum;                   // 现场实际目标数目 
    char        reserved[64]; 
}MONITOR_INFO;

typedef struct _DHDEV_MONITOR_INFO
{
    int              nChannelNumber;
    MONITOR_INFO     stMonitorInfo[64];             //  画面监控辅助信息
    char             reserved[128];
}DHDEV_MONITOR_INFO;

// 多通道预览回放分割能力
typedef struct tagNET_MULTIPLAYBACK_SPLIT_CAP
{
    DWORD            dwSize;
    int              nSliptMode[DH_MAX_MULTIPLAYBACK_SPLIT_NUM]; // 支持的分割模式，  
    int              nModeNumber;       
}NET_MULTIPLAYBACK_SPLIT_CAP;

/***************************** 云台预制点配置 ***********************************/
typedef struct _POINTEANBLE
{
    BYTE             bPoint;                        //预制点的有效范围闭区间[1,80]，无效设置为0。
    BYTE             bEnable;                       //是否有效,0无效，1有效
    BYTE             bReserved[2];
} POINTEANBLE;

typedef struct _POINTCFG
{
    char             szIP[DH_MAX_IPADDR_LEN];       // ip
    int              nPort;                         // 端口    
    POINTEANBLE      stuPointEnable[80];            // 预制点使能
    BYTE             bReserved[256];
}POINTCFG;

typedef struct _DHDEV_POINT_CFG
{
    int              nSupportNum;                   // 只读参数，设置的时候需要返回给sdk，表示支持的预制点数
    POINTCFG         stuPointCfg[16];               // 二维下标表示通道号。要设置的点数值放在前nSupportNum个下标里面。
    BYTE             bReserved[256];                // 保留
}DHDEV_POINT_CFG;
////////////////////////////////车载DVR支持////////////////////////////////

// GPS信息(车载设备)
typedef struct _GPS_Info
{
    NET_TIME         revTime;                       // 定位时间
    char             DvrSerial[50];                 // 设备序列号
    double           longitude;                     // 经度(单位是百万分之度，范围0-360度)
    double           latidude;                      // 纬度(单位是百万分之度，范围0-180度)
    double           height;                        // 高度(米)
    double           angle;                         // 方向角(正北方向为原点，顺时针为正)
    double           speed;                         // 速度(单位是海里，speed/1000*1.852公里/小时)
    WORD             starCount;                     // 定位星数
    BOOL             antennaState;                  // 天线状态(true 好，false 坏)
    BOOL             orientationState;              // 定位状态(true 定位，false 不定位)
} GPS_Info,*LPGPS_Info;

// 报警状态信息
typedef struct 
{
    int              nAlarmCount;                   // 发生的报警事件个数
    int              nAlarmState[128];              // 发生的报警事件类型
    BYTE             byRserved[128];                // 保留字节
}ALARM_STATE_INFO;

// 抓图参数结构体
typedef struct _snap_param
{
    unsigned int     Channel;                       // 抓图的通道
    unsigned int     Quality;                       // 画质；1~6
    unsigned int     ImageSize;                     // 画面大小；0：QCIF，1：CIF，2：D1
    unsigned int     mode;                          // 抓图模式；0：表示请求一帧，1：表示定时发送请求，2：表示连续请求
    unsigned int     InterSnap;                     // 时间单位秒；若mode=1表示定时发送请求时，此时间有效
    unsigned int     CmdSerial;                     // 请求序列号
    unsigned int     Reserved[4];
} SNAP_PARAMS, *LPSNAP_PARAMS;

// 抓图功能配置
typedef struct 
{
    DWORD            dwSize;
    BYTE             bTimingEnable;                 // 定时抓图开关(报警抓图开关在各报警联动配置中体现)
    BYTE             bPicIntervalHour;              // 定时抓图时间间隔小时数
    short            PicTimeInterval;               // 定时抓图时间间隔，单位为秒,目前设备支持最大的抓图时间间隔为30分钟                           
    DH_VIDEOENC_OPT  struSnapEnc[SNAP_TYP_NUM];     // 抓图编码配置，现支持其中的分辨率、画质、帧率设置，帧率在这里是负数，表示一秒抓图的次数。
} DHDEV_SNAP_CFG;

// 抓图功能配置扩展
typedef struct 
{
    DWORD            dwSize;
    BYTE             bTimingEnable;                 // 定时抓图开关(报警抓图开关在各报警联动配置中体现)
    BYTE             bPicIntervalHour;              // 定时抓图时间间隔小时数
    short            PicTimeInterval;               // 定时抓图时间间隔，单位为秒,目前设备支持最大的抓图时间间隔为30分钟                           
    DH_VIDEOENC_OPT  struSnapEnc[SNAP_TYP_NUM];     // 抓图编码配置，现支持其中的分辨率、画质、帧率设置，帧率在这里是负数，表示一秒抓图的次数。
    DWORD            dwTrigPicIntervalSecond;       // 报警触发后每次抓图时间间隔时间 单位秒
    BYTE             byRserved[256];                // 保留字节
} DHDEV_SNAP_CFG_EX;


//车载wifi状态
typedef struct  
{
    char            szSSID[128];                    //SSID
    BOOL            bEnable;                        //是否启用wifi功能, 0:不使能 1:使能
    int             nSafeType;                      //校验类型
                                                    //0:OPEN 
                                                    //1:RESTRICTE
                                                    //2:WEP
                                                    //3:WPA
                                                    //4:WPA2
                                                    //5:WPA-PSK
                                                    //6:WPA2-PSK
    int             nEncryprion;                    //加密方式
                                                    //0:OPEN
                                                    //1:TKIP
                                                    //2:WEP
                                                    //3:AES
                                                    //4:NONE(不校验)
                                                    //5:AUTO
                                                    //6:SHARED
    int             nStrength;                      //AP站点信号
    char            szHostIP[128];                  //主机地址
    char            szHostNetmask[128];             //主机掩码
    char            szHostGateway[128];             //主机网关
    int             nPriority;                      //优先级,(1-32)
    int             nEnDHCP;                        //0：不使能; 1：使能(扫描到的dhcp默认使能打开)
    BYTE            bReserved[1016];
} DHDEV_VEHICLE_WIFI_STATE;

typedef struct
{
    char            szSSID[128];                    //SSID
    int             nPriority;                      //优先级,(1-32)
    int             nSafeType;                      //校验类型
                                                    //0:OPEN 
                                                    //1:RESTRICTE
                                                    //2:WEP
                                                    //3:WPA
                                                    //4:WPA2
                                                    //5:WPA-PSK
                                                    //6:WPA2-PSK
    int             nEncryprion;                    //加密方式
                                                    //0:OPEN
                                                    //1:TKIP
                                                    //2:WEP
                                                    //3:AES
                                                    //4:NONE(不校验)
                                                    //5:AUTO
                                                    //6:SHARED
    char            szKey[128];                     //连接密钥
    char            szHostIP[128];                  //主机地址
    char            szHostNetmask[128];             //主机掩码
    char            szHostGateway[128];             //主机网关
    int             nEnDHCP;                        //0：不使能; 1：使能(扫描到的dhcp默认使能打开)
    BYTE            byKeyIndex;                     //WEP校验类型下的密钥索引,0：不支持密钥索引 >0:密钥索引值，范围1-4
    BYTE            bReserved[1019];
} DHDEV_VEHICLE_WIFI_CONFIG;

typedef struct
{
    char    szSSID[128];                            // SSID   
    BYTE    bReserved[256];                         // 保留字节
}WIFI_CONNECT;

// IP修改配置
typedef struct __DHCTRL_IPMODIFY_PARAM
{
    int             nStructSize;
    char            szRemoteIP[DH_MAX_IPADDR_OR_DOMAIN_LEN];        // 前端设备IP
    char            szSubmask[DH_MAX_IPADDR_LEN];                   // 子网掩码
    char            szGateway[DH_MAX_IPADDR_OR_DOMAIN_LEN];         // 网关
    char            szMac[DH_MACADDR_LEN];                          // MAC地址
    char            szDeviceType[DH_DEV_TYPE_LEN];                  // 设备类型
}DHCTRL_IPMODIFY_PARAM;

typedef struct 
{
    BOOL        bIsScan;                            //0:非扫描wifi (手动添加的), 1扫描到的wifi
    char        szSSID[128];                        //SSID
    int         nSafeType;                          //校验类型
                                                    //0:OPEN 
                                                    //1:RESTRICTE
                                                    //2:WEP
                                                    //3:WPA
                                                    //4:WPA2
                                                    //5:WPA-PSK
                                                    //6:WPA2-PSK
    int        nEncryprion;                         //加密方式
                                                    //0:OPEN
                                                    //1:TKIP
                                                    //2:WEP
                                                    //3:AES
                                                    //4:NONE(不校验)
                                                    //5:AUTO
                                                    //6:SHARED
    char        szKey[128];                         //连接密钥
    int         nStrength;                          //AP站点信号
    int         nMaxBitRate;                        //AP站点的最大传输速率,带单位 只读
    int         nIsCnnted;                          //是否连接成功只读
    int         nIsSaved;                           //是否已经保存只读
    int         nPriority;                          //优先级,(1-32)
    char        szHostIP[128];                      //主机地址
    char        szHostNetmask[128];                 //主机掩码
    char        szHostGateway[128];                 //主机网关
    int         nWifiFreq;                          //无线频率，采用通道标识
    int         nEnDHCP;                            //0：不使能 1：使能(扫描到的dhcp默认使能打开)
    BYTE        byKeyIndex;                         //WEP校验类型下的密钥索引,0：不支持密钥索引 >0:密钥索引值，范围1-4
    BYTE        bReserved[1019];
}DHDEV_VEHICLE_SINGLE_WIFI_AP_CFG;

typedef struct 
{
    BOOL        bEnable;                            //是否启用wifi功能, 0:不使能 1:使能
    int         nWifiApNum;                         //DHDEV_VEHICLE_WIFI_AP_CFG结构体有效个数
    DHDEV_VEHICLE_SINGLE_WIFI_AP_CFG struWifiAp[64];//单个WIFI AP配置
    int         nReserved[512];                     //保留
}DHDEV_VEHICLE_WIFI_AP_CFG;

typedef struct  
{    
    BOOL        bEnable;                            //是否启用wifi功能, 0:不使能 1:使能
    int         nRetWifiApNum;                      //解析得到的DHDEV_VEHICLE_WIFI_AP_CFG结构体有效个数
    int         nMaxWifiApNum;                      //申请的DHDEV_VEHICLE_SINGLE_WIFI_AP_CFG个数
    DHDEV_VEHICLE_SINGLE_WIFI_AP_CFG* pWifiAp;      //单个WIFI AP配置
    int         nReserved[512];                     //保留
}DHDEV_VEHICLE_WIFI_AP_CFG_EX;

// GPS日志信息结构体
typedef struct _DH_DEVICE_GPS_LOG_ITEM
{
    DHDEVTIME       stuDevTime;             // 设备时间  
    DWORD           dwLatidude;             // 纬度(单位是百万分之度，范围0-180度)如北纬30.183382度表示为120183382
    DWORD           dwLongitude;            // 经度(单位是百万分之度，范围0-360度)如东经120.178274度表示为300178274
    DWORD           dwSpeed;                // 速度,单位是海里,speed/1000*1.852公里/小时
    DWORD           dwHight;                // 高度,米
    DWORD           dwAngle;                // 方向，角度0~360,正北方向为原点，顺时针为正
    DHDEVTIME       stuGpsTime;             // GPS时间
    BYTE            bAntStatus;             // GPS天线状态,为0表示好;不为0表示异常 
    BYTE            bOriStatus;             // 定位状态，不为0表示定位成功
    BYTE            bSatCount;              // 卫星数量
    BYTE            bGPSStatus;             // GPS状态,0,未定位 1,无差分定位信息 2,带差分定位信息
    DWORD           dwTemp;                 // 温度值(摄氏度),实际值的1000倍,如30.0摄氏度表示为30000
    DWORD           dwHumidity;             // 湿度值(%),实际值的1000倍,如30.0%表示为30000
    BYTE            bReserved[24];          // 保留字节
    
}DH_DEVICE_GPS_LOG_ITEM;

// GPS 日志查询参数结构体
typedef struct _QUERY_GPS_LOG_PARAM
{
    NET_TIME            stuStartTime;               // 查询日志的开始时间
    NET_TIME            stuEndTime;                 // 查询日志的结束时间
    int                 nStartNum;                  // 在时间段中从第几条日志开始查询，开始第一次查询可设为0
    BYTE                bReserved[20];
} QUERY_GPS_LOG_PARAM;

typedef struct _GPS_TEMP_HUMIDITY_INFO
{
    double              dTemperature;               // 温度值(摄氏度),实际值的1000倍,如30.0摄氏度表示为30000
    double              dHumidity;                  // 湿度值(%),实际值的1000倍,如30.0%表示为30000
    BYTE                bReserved[128];             // 保留字节
}GPS_TEMP_HUMIDITY_INFO;

// 电子围栏类型枚举
typedef enum
{
    ENCLOSURE_LIMITSPEED = 0x01,                    // 限速区
    ENCLOSURE_DRIVEALLOW = 0x02,                    // 驾驶区
    ENCLOSURE_FORBIDDRIVE = 0x04,                   // 禁止区
    ENCLOSURE_LOADGOODS = 0x08,                     // 装货区
    ENCLOSURE_UPLOADGOODS = 0x10,                   // 卸货区
}ENCLOSURE_TYPE;

typedef enum
{
     ENCLOSURE_ALARM_DRIVEIN ,                      // 驶入
     ENCLOSURE_ALARM_DRIVEOUT,                      // 驶出
     ENCLOSURE_ALARM_OVERSPEED,                     // 超速
     ENCLOSURE_ALARM_SPEEDCLEAR,                    // 超速消失
}ENCLOSURE_ALARM_TYPE;

typedef struct 
{
    DWORD         dwLongitude;                      // 经度(单位是百万分之度，范围0-360度)如东经120.178274度表示为300178274
    DWORD         dwLatidude;                       // 纬度(单位是百万分之度，范围0-180度)如北纬30.183382度表示为120183382
}GPS_POINT;

// 电子围栏配置
typedef struct _DHDEV_ENCLOSURE_CFG
{
    UINT          unType;                              // 电子围栏类型掩码，见 ENCLOSURE_TYPE 
    BYTE          bRegion[8];                          // 前四位分别代表国家、省、市或区、县(0-255)，后4bytes保留
    UINT          unId;                                // 一个区域以一个ID标识
    UINT          unSpeedLimit;                        // 限速，单位km/h
    UINT          unPointNum;                          // 电子围栏区域顶点数
    GPS_POINT     stPoints[128];                       // 电子围栏区域信息
    char          szStationName[DH_STATION_NAME_LEN];  // 电子围栏包围的车站站点名称
    BYTE          reserved[32];                        // 保留
}DHDEV_ENCLOSURE_CFG;

// 电子围栏版本号配置
typedef struct _DHDEV_ENCLOSURE_VERSION_CFG
{
    UINT          unType;                              // 围栏类型掩码，如LIMITSPEED | DRIVEALLOW
    UINT          unVersion[32];                       // 每个类型一个版本号,用于统一平台与设备上的围栏配置
    int           nReserved;                           // 保留    
}DHDEV_ENCLOSURE_VERSION_CFG;

// 电子围栏报警
typedef struct __ALARM_ENCLOSURE_INFO
{
    int           nTypeNumber;                          // 有效电子围栏类型个数
    BYTE          bType[16];                            // 电子围栏类型, 见ENCLOSURE_TYPE
    int           nAlarmTypeNumber;                     // 有效报警类型个数
    BYTE          bAlarmType[16];                       // 报警类型，见ENCLOSURE_ALARM_TYPE
    char          szDriverId[DH_VEHICLE_DRIVERNO_LEN];  // 司机工号
    UINT          unEnclosureId;                        // 电子围栏ID
    UINT          unLimitSpeed;                         // 限速，单位km/h
    UINT          unCurrentSpeed;                       // 当前速度
    NET_TIME      stAlarmTime;                          // 报警发生时间
    DWORD         dwLongitude;                          // 经度(单位是百万分之度，范围0-360度)如东经120.178274度表示为300178274
    DWORD         dwLatidude;                           // 纬度(单位是百万分之度，范围0-180度)如北纬30.183382度表示为120183382
    BYTE          bOffline;                             // 0-实时 1-补传 
    BYTE          byReserved[119];                      // 保留字节
}ALARM_ENCLOSURE_INFO;

// RAID异常信息
#define DH_MAX_RAID_NUM  16
typedef struct __RAID_STATE_INFO
{
    char          szName[16];                           // Raid名称
    BYTE          byType;                               // 类型 1:Jbod     2:Raid0      3:Raid1     4:Raid5
    BYTE          byStatus;                             // 状态 0:unknown ，1:active，2:degraded，3:inactive，4:recovering
    BYTE          byReserved[2];
    int           nCntMem;                              // nMember数组的有效数据个数
    int           nMember[32];                          // 1,2,3,... 组成磁盘通道,是个数组
    int           nCapacity;                            // 容量,单位G
    int           nRemainSpace;                         // 剩余容量，单位M
    int           nTank;                                // 扩展柜 0:主机，1:扩展柜1，2:扩展柜2，……
    char          reserved[32];
}RAID_STATE_INFO;

typedef struct __ALARM_RAID_INFO
{
    int              nRaidNumber;                       // 上报的RAID个数   
    RAID_STATE_INFO  stuRaidInfo[DH_MAX_RAID_NUM];      // 异常的RAID信息
    char             reserved[128];
}ALARM_RAID_INFO;

//////////////////////////////////ATM支持//////////////////////////////////

typedef struct
{
    int           Offset;                               // 标志位的位偏移
    int           Length;                               // 标志位的长度
    char          Key[16];                              // 标志位的值
} DH_SNIFFER_FRAMEID;

typedef struct 
{
    int           Offset;                       // 标志位的位偏移
    int           Offset2;                      // 目前没有应用
    int           Length;                       // 标志位的长度
    int           Length2;                      // 目前没有应用
    char          Title[12];                    // 标题的值
    char          Key[12];                      // 关键字的值
} DH_SNIFFER_CONTENT;

// 网络抓包配置
typedef struct 
{
    DH_SNIFFER_FRAMEID    snifferFrameId;                           // 每个FRAME ID 选项
    DH_SNIFFER_CONTENT    snifferContent[DH_SNIFFER_CONTENT_NUM];   // 每个FRAME对应的4个抓包内容
} DH_SNIFFER_FRAME;

// 每组抓包对应的配置结构
typedef struct
{
    char                SnifferSrcIP[DH_MAX_IPADDR_LEN];        // 抓包源地址        
    int                 SnifferSrcPort;                         // 抓包源端口
    char                SnifferDestIP[DH_MAX_IPADDR_LEN];       // 抓包目标地址
    int                 SnifferDestPort;                        // 抓包目标端口
    char                reserved[28];                           // 保留字段
    DH_SNIFFER_FRAME    snifferFrame[DH_SNIFFER_FRAMEID_NUM];   // 6个FRAME 选项
    int                 displayPosition;                        // 显示位置
    int                 recdChannelMask;                        // 通道掩码
} DH_ATM_SNIFFER_CFG;

typedef struct  
{
    DWORD               dwSize;
    DH_ATM_SNIFFER_CFG  SnifferConfig[4];
    char                reserved[256];                          // 保留字段
} DHDEV_SNIFFER_CFG;

typedef DH_SNIFFER_FRAMEID DH_SNIFFER_FRAMEID_EX;
typedef DH_SNIFFER_CONTENT DH_SNIFFER_CONTENT_EX;

// 网络抓包配置
typedef struct  
{
    DH_SNIFFER_FRAMEID    snifferFrameId;                               // 每个FRAME ID 选项
    DH_SNIFFER_CONTENT    snifferContent[DH_SNIFFER_CONTENT_NUM_EX];    // 每个FRAME对应的8个抓包内容    
} DH_SNIFFER_FRAME_EX;

// 每组抓包对应的配置结构
typedef struct
{
    char                SnifferSrcIP[DH_MAX_IPADDR_LEN];                // 抓包源地址        
    int                 SnifferSrcPort;                                 // 抓包源端口
    char                SnifferDestIP[DH_MAX_IPADDR_LEN];               // 抓包目标地址
    int                 SnifferDestPort;                                // 抓包目标端口
    DH_SNIFFER_FRAME_EX snifferFrame[DH_SNIFFER_FRAMEID_NUM];           // 6个FRAME 选项
    int                 displayPosition;                                // 显示位置
    int                 recdChannelMask;                                // 通道掩码  0  ~ 31 通道
    BOOL                bDateScopeEnable;                               // 数据来源使能
    BOOL                bProtocolEnable;                                // 协议使能
    char                szProtocolName[DH_SNIFFER_PROTOCOL_SIZE];       // 协议名字
    int                 nSnifferMode;                                   // 抓包方式，0:net,1:232.
    int                 recdChannelMask1;                               // 通道掩码  32 ~ 63 通道
    char                reserved[252];
} DH_ATM_SNIFFER_CFG_EX;

// Atm交易类型查询返回结构体
#define ATM_MAX_TRADE_TYPE_NAME    64
#define ATM_MAX_TRADE_NUM        1024

typedef struct __DH_ATM_QUERY_TRADE   
{
    int  nTradeTypeNum;                                                     // 实际交易类型数量
    int  nExceptionTypeNum;                                                 // 实际异常事件数量
    char szSupportTradeType[ATM_MAX_TRADE_NUM][ATM_MAX_TRADE_TYPE_NAME];    // 交易事件名数组
    char szSupportExceptionType[ATM_MAX_TRADE_NUM][ATM_MAX_TRADE_TYPE_NAME];// 异常事件名数组
} DH_ATM_QUERY_TRADE, *LPDH_ATM_QUERY_TRADE;

/////////////////////////////////解码器支持/////////////////////////////////
#define nEncoderID nDecoderID
#define byEncoderID byDecoderID

// 解码器信息
typedef struct __DEV_DECODER_INFO 
{
    char            szDecType[64];                      // 类型
    int             nMonitorNum;                        // TV个数
    int             nEncoderNum;                        // 解码通道个数
    BYTE            szSplitMode[16];                    // 支持的TV画面分割数，以数组形式表示，0为结尾
    BYTE            bMonitorEnable[16];                 // 各TV使能
    BYTE            bTVTipDisplay;                      // 指示是否支持TV提示信息叠加设置, 0:不支持 1:支持.
    BYTE            reserved1[3];
    BYTE            byLayoutEnable[48];                 // 各解码通道显示叠加信息使能
    DWORD           dwLayoutEnMask[2];                  // 各解码通道显示叠加信息使能掩码,从低位到高位支持64个通道,其中dwLayoutEnMask[0]是低32位
    char            reserved[4];
} DEV_DECODER_INFO, *LPDEV_DECODER_INFO;

//#define NANJINGDITIE_NVD
#ifndef NANJINGDITIE_NVD
// 连接的编码器信息
typedef struct __DEV_ENCODER_INFO 
{
    char            szDevIp[DH_MAX_IPADDR_LEN];             // 前端DVR的IP地址
    WORD            wDevPort;                               // 前端DVR的端口号
    BYTE            bDevChnEnable;                          // 解码通道使能
    BYTE            byDecoderID;                            // 对应解码通道号
    char            szDevUser[DH_USER_NAME_LENGTH_EX];      // 用户名
    char            szDevPwd[DH_USER_PSW_LENGTH_EX];        // 密码
    int             nDevChannel;                            // 通道号
    int             nStreamType;                            // 码流类型，0：主码流；1：辅码流1; 2:snap; 3: 辅码流2
    BYTE            byConnType;                             // -1: auto, 0：TCP；1：UDP；2：组播
    BYTE            byWorkMode;                             // 0：直连；1：转发
    WORD            wListenPort;                            // 指示侦听服务的端口，转发时有效
    DWORD           dwProtoType;                            // 协议类型,
                                                            // 0:兼容以前
                                                            // 1:大华二代协议
                                                            // 2:大华系统集成协议
                                                            // 3:大华DSS协议
                                                            // 4:大华rtsp协议
    char            szDevName[64];                          // 前端设备名称
    BYTE            byVideoInType;                          // 该解码通道当前视频源类型:0-标清(SD),1-高清(HD),注:设备支持高清通道才有效        
    char            szDevIpEx[DH_MAX_IPADDR_OR_DOMAIN_LEN]; // szDevIp扩展，前端DVR的IP地址(可以输入域名)
    BYTE            bySnapMode;                             // 抓图模式(nStreamType==2时有效) 0：表示请求一帧,1：表示定时发送请求
    BYTE            byManuFactory;                          // 目标设备的生产厂商,具体参考EM_IPC_TYPE类
    BYTE            byDeviceType;                           // 目标设备的设备类型,0:IPC
    BYTE            byDecodePolicy;                         // 目标设备的解码策略,0:兼容以前
                                                            // 1:实时等级高 2:实时等级中
                                                            // 3:实时等级低 4:默认等级
                                                            // 5:流畅等级高 6:流畅等级中
                                                            // 7:流畅等级低
    BYTE            bReserved[3];                           // 保留字节
    DWORD           dwHttpPort;                             // Http端口号,0-65535
    DWORD           dwRtspPort;                             // Rtsp端口号,0-65535
    char            szChnName[32];                          // 远程通道名称, 只有读取到的名称不为空时才可以修改该通道的名称
    char            reserved[4];
} DEV_ENCODER_INFO, *LPDEV_ENCODER_INFO;

#else

// 连接的编码器信息
typedef struct __DEV_ENCODER_INFO 
{
    char            szDevIp[DH_MAX_IPADDR_LEN];             // 前端DVR的IP地址
    WORD            wDevPort;                               // 前端DVR的端口号
    BYTE            bDevChnEnable;                          // 解码通道使能
    BYTE            byDecoderID;                            // 对应解码通道号
    char            szDevUser[DH_USER_NAME_LENGTH_EX];      // 用户名
    char            szDevPwd[DH_USER_PSW_LENGTH_EX];        // 密码
    int             nDevChannel;                            // 通道号
    int             nStreamType;                            // 码流类型，0：主码流；1：辅码流1; 2:snap; 3: 辅码流2
    BYTE            byConnType;                             // -1: auto, 0：TCP；1：UDP；2：组播
    BYTE            byWorkMode;                             // 0：直连；1：转发
    WORD            wListenPort;                            // 指示侦听服务的端口，转发时有效;byConnType为组播时，则作为多播端口
    DWORD            dwProtoType;                           // 协议类型,
                                                            // 0:兼容以前
                                                            // 1:大华二代协议
                                                            // 2:大华系统集成协议
                                                            // 3:大华DSS协议
                                                            // 4:大华rtsp协议
                                                            // 5:标准TS流
    char            szDevName[32];                          // 前端设备名称
    BYTE            byVideoInType;                          // 该解码通道当前视频源类型:0-标清(SD),1-高清(HD),注:设备支持高清通道才有效        
    char            szDevIpEx[DH_MAX_IPADDR_OR_DOMAIN_LEN]; // szDevIp扩展，前端DVR的IP地址(可以输入域名)
    BYTE            bySnapMode;                             // 抓图模式(nStreamType==2时有效) 0：表示请求一帧,1：表示定时发送请求
    BYTE            byManuFactory;                          // 目标设备的生产厂商,具体参考EM_IPC_TYPE类
    BYTE            byDeviceType;                           // 目标设备的设备类型,0:IPC
    BYTE            byDecodePolicy;                         // 目标设备的解码策略,0:兼容以前
                                                            // 1:实时等级高 2:实时等级中
                                                            // 3:实时等级低 4:默认等级
                                                            // 5:流畅等级高 6:流畅等级中
                                                            // 7:流畅等级低
    BYTE            bReserved[3];                           // 保留字节
    DWORD           dwHttpPort;                             // Http端口号,0-65535
    DWORD           dwRtspPort;                             // Rtsp端口号,0-65535
    char            szChnName[32];                          // 远程通道名称, 只有读取到的名称不为空时才可以修改该通道的名称
    char            szMcastIP[DH_MAX_IPADDR_LEN];           // 多播IP地址,byConnType为组播时有效
    char            reserved[128];
} DEV_ENCODER_INFO, *LPDEV_ENCODER_INFO;

#endif

// 解码器rtsp url配置
typedef struct __DHDEV_DECODER_URL_CFG
{
    DWORD           dwSize;
    char            szMainStreamUrl[MAX_PATH];          // 主码流url
    char            szExtraStreamUrl[MAX_PATH];         // 辅码流url
} DHDEV_DECODER_URL_CFG;

enum DH_SPLIT_DISPLAY_TYPE
{
    DH_SPLIT_DISPLAY_TYPE_GENERAL=1,          // 普通显示类型
    DH_SPLIT_DISPLAY_TYPE_PIP=2,              // 画中画显示类型
};

// CLIENT_CtrlDecTVScreen 接口参数
typedef struct tagDH_CTRL_DECTV_SCREEN
{
    DWORD           dwSize;                             // 结构体大小
    int             nSplitType;                         // 分割模式
    BYTE *          pEncoderChannel;                    // 显示通道,dwDisplayType=DH_SPLIT_DISPLAY_TYPE_GENERAL时有效,调用者分配的内存长度不能小于nSplitType的大小
    BYTE            byGroupNo;                          // 输入通道组号,dwDisplayType=DH_SPLIT_DISPLAY_TYPE_PIP时表示画中画显示类型下有效；
    char            reserved[3];                        // 保留字节
    DWORD           dwDisplayType;                      // 显示类型；具体见DH_SPLIT_DISPLAY_TYPE（注释各模式下显示内容由"PicInPic"决定, 各模式下显示内容按NVD旧有规则决定（即DisChn字段决定）。兼容，没有这一个项时，默认为普通显示类型,即"General"）
}DH_CTRL_DECTV_SCREEN;

// TV参数信息
typedef struct __DEV_DECODER_TV 
{
    int                 nID;                            // TV号
    BOOL                bEnable;                        // 使能，开启或关闭
    int                 nSplitType;                     // 画面分割数
    DEV_ENCODER_INFO    stuDevInfo[16];                 // 各画面编码器信息dwDisplayType=DH_SPLIT_DISPLAY_TYPE_GENERAL时有效
    BYTE                bySupportSplit[10];             // 支持的分割模式
    BYTE                byGroupNo;                      // 输入通道组号,dwDisplayType=DH_SPLIT_DISPLAY_TYPE_PIP时表示画中画显示类型下有效；
    char                reserved[1];                    // 保留字节
    DWORD               dwDisplayType;                  // 显示类型；具体见DH_SPLIT_DISPLAY_TYPE（注释各模式下显示内容由"PicInPic"决定, 各模式下显示内容按NVD旧有规则决定（即DisChn字段决定）。兼容，没有这一个项时，默认为普通显示类型,即"General"）
} DEV_DECODER_TV, *LPDEV_DECODER_TV;

// 解码器画面组合信息
typedef struct __DEC_COMBIN_INFO
{
    int             nCombinID;                          // 组合ID
    int             nSplitType;                         // 画面分割数 
    BYTE            bDisChn[16];                        // 显示通道
    char            reserved[16];
} DEC_COMBIN_INFO, *LPDEC_COMBIN_INFO;

// 解码器轮巡信息
#define DEC_COMBIN_NUM             32                   // 轮巡组合个数
typedef struct __DEC_TOUR_COMBIN 
{
    int             nTourTime;                          // 轮巡间隔(秒)
    int             nCombinNum;                         // 组合个数
    BYTE            bCombinID[DEC_COMBIN_NUM];          // 组合表
    char            reserved1[32];
    BYTE            bCombinState[DEC_COMBIN_NUM];       // 组合项的使能状态，0：关；1：开
    char            reserved2[32];
} DEC_TOUR_COMBIN, *LPDEC_TOUR_COMBIN;

// 解码器回放类型
typedef enum __DEC_PLAYBACK_MODE
{
    Dec_By_Device_File = 0,                             // 前端设备－按文件方式
    Dec_By_Device_Time,                                 // 前端设备－按时间方式
} DEC_PLAYBACK_MODE;

// 解码器回放控制类型
typedef enum __DEC_CTRL_PLAYBACK_TYPE
{
    Dec_Playback_Seek = 0,                              // 拖动
    Dec_Playback_Play,                                  // 播放
    Dec_Playback_Pause,                                 // 暂停
    Dec_Playback_Stop,                                  // 停止
} DEC_CTRL_PLAYBACK_TYPE;

//轮巡控制类型
typedef enum __DEC_CTRL_TOUR_TYPE
{
    Dec_Tour_Stop = 0,                                  // 停止
    Dec_Tour_Start,                                     // 开始
    Dec_Tour_Pause,                                     // 暂停
    Dec_Tour_Resume,                                    // 恢复
} DEC_CTRL_TOUR_TYPE;

// 按文件回放前端设备条件
typedef struct __DEC_PLAYBACK_FILE_PARAM 
{
    char            szDevIp[DH_MAX_IPADDR_LEN];         // 前端DVR的IP地址
    WORD            wDevPort;                           // 前端DVR的端口号
    BYTE            bDevChnEnable;                      // 解码通道使能
    BYTE            byDecoderID;                        // 对应解码通道号
    char            szDevUser[DH_USER_NAME_LENGTH_EX];  // 用户名
    char            szDevPwd[DH_USER_PSW_LENGTH_EX];    // 密码
    NET_RECORDFILE_INFO stuRecordInfo;                  // 录像文件信息
    char            reserved[12];
} DEC_PLAYBACK_FILE_PARAM, *LPDEC_PLAYBACK_FILE_PARAM;

// 按时间回放前端设备条件
typedef struct __DEC_PLAYBACK_TIME_PARAM 
{
    char            szDevIp[DH_MAX_IPADDR_LEN];         // 前端DVR的IP地址
    WORD            wDevPort;                           // 前端DVR的端口号
    BYTE            bDevChnEnable;                      // 解码通道使能
    BYTE            byDecoderID;                        // 对应解码通道号
    char            szDevUser[DH_USER_NAME_LENGTH_EX];  // 用户名
    char            szDevPwd[DH_USER_PSW_LENGTH_EX];    // 密码
    int             nChannelID;
    NET_TIME        startTime;
    NET_TIME        endTime;
    char            reserved[12];
} DEC_PLAYBACK_TIME_PARAM, *LPDEC_PLAYBACK_TIME_PARAM;

// 当前解码通道状态信息(包括通道状态，解码流信息等)
typedef struct __DEV_DECCHANNEL_STATE
{
    BYTE            byDecoderID;                        // 对应解码通道号
    BYTE            byChnState;                         // 当前解码通道正在操作状态:0－空闲，1－实时监视，2－回放 3 - 轮巡
    BYTE            byFrame;                            // 当前数据帧率
    BYTE            byReserved;                         // 保留
    int             nChannelFLux;                       // 解码通道数据总量
    int             nDecodeFlux;                        // 解码数据量
    char            szResolution[16];                   // 当前数据分辨率
    char            reserved[256];
} DEV_DECCHANNEL_STATE, *LPDEV_DECCHANNEL_STATE;

// 设备TV输出参数信息
typedef struct __DEV_VIDEOOUT_INFO
{
    DWORD           dwVideoStandardMask;            // NSP,视频制式掩码，按位表示设备能够支持的视频制式(暂不支持)
    int             nVideoStandard;                 // NSP,当前的制式(暂不支持，请使用DHDEV_SYSTEM_ATTR_CFG的byVideoStandard对制式读取和配置)
    DWORD           dwImageSizeMask;                // 分辨率掩码，按位表示设备能够支持的分辨率
    int             nImageSize;                     // 当前的分辨率
    char            reserved[256];
}DEV_VIDEOOUT_INFO, *LPDEV_VIDEOOUT_INFO;

// 调节TV输出
typedef struct __DEV_TVADJUST_CFG
{
    int             nTop;                           // 上测边距（0－100）
    int             nBotton;                        // 下测边距（0－100）
    int             nLeft;                          // 左测边距（0－100）
    int             nRight;                         // 右测边距（0－100）
    int             reserved[32];
}DHDEV_TVADJUST_CFG, *LPDHDEV_TVADJUST_CFG;

// 解码轮巡配置
typedef struct __DEV_DECODER_TOUR_SINGLE_CFG
{
    char        szIP[128];                          // 前端设备ip.例如"10.7.5.21". 保留对域名的支持.需要以'\0'结束.
    int         nPort;                              // 前端设备端口.(0, 65535).
    int         nPlayChn;                           // 请求前端设备通道[1, 16].
    int         nPlayType;                          // 请求前端码流类型, 0:主码流; 1:辅码流.
    char        szUserName[32];                     // 登陆前端设备的用户名,需要以'\0'结束.
    char        szPassword[32];                     // 登陆前端设备的密码,需要以'\0'结束.
    int         nInterval;                          // 轮巡间隔时间[10, 120],单位秒.
    DWORD       nManuFactory;                       // 目标设备厂商(枚举 详见IPC_TYPE)
    UINT        nHttpPport;                         // 目标设备的端口(Http端口)
    UINT        nRtspPort;                          // 目标设备的端口(Rtsp端口)
    BYTE        byServiceType;                      // 服务类型, -1: auto, 0：TCP；1：UDP；2：组播
    BYTE        bReserved[51];                      // 保留字节,留待扩展.
}DHDEV_DECODER_TOUR_SINGLE_CFG;

typedef struct __DEV_DECODER_TOUR_CFG
{
    int                             nCfgNum;        // 配置结构体数目. 现在最大支持32个.具体支持数目可以通过能力查询.
    DHDEV_DECODER_TOUR_SINGLE_CFG   tourCfg[64];    // 轮询配置数组,有效结构体个数由成员"nCfgNum"指定. 保留32个留待扩展.
    BYTE                            bReserved[256]; // 保留字节,留待扩展.
}DHDEV_DECODER_TOUR_CFG;

/////////////////////////////////智能支持/////////////////////////////////
// 物体对应图片文件信息
typedef struct  
{
    DWORD           dwOffSet;                       // 文件在二进制数据块中的偏移位置, 单位:字节
    DWORD           dwFileLenth;                    // 文件大小, 单位:字节
    WORD            wWidth;                         // 图片宽度, 单位:像素
    WORD            wHeight;                        // 图片高度, 单位:像素
    BYTE            bReserved[16];                 
}DH_PIC_INFO;

// 扩展字段中加入了int64, 强制4字节对齐
#pragma pack(push)
#pragma pack(4)
// 视频分析物体信息结构体
typedef struct 
{
    int                 nObjectID;                          // 物体ID,每个ID表示一个唯一的物体
    char                szObjectType[128];                  // 物体类型
    int                 nConfidence;                        // 置信度(0~255)，值越大表示置信度越高
    int                 nAction;                            // 物体动作:1:Appear 2:Move 3:Stay 4:Remove 5:Disappear 6:Split 7:Merge 8:Rename
    DH_RECT             BoundingBox;                        // 包围盒
    DH_POINT            Center;                             // 物体型心
    int                 nPolygonNum;                        // 多边形顶点个数
    DH_POINT            Contour[DH_MAX_POLYGON_NUM];        // 较精确的轮廓多边形
    DWORD               rgbaMainColor;                      // 表示车牌、车身等物体主要颜色；按字节表示，分别为红、绿、蓝和透明度,例如:RGB值为(0,255,0),透明度为0时, 其值为0x00ff0000.
    char                szText[128];                        // 物体上相关的带0结束符文本，比如车牌，集装箱号等等
                                                            // "ObjectType"为"Vehicle"或者"Logo"时（尽量使用Logo。Vehicle是为了兼容老产品）表示车标，支持：
                                                            // "Unknown"未知 
                                                            // "Audi" 奥迪
                                                            // "Honda" 本田
                                                            // "Buick" 别克
                                                            // "Volkswagen" 大众
                                                            // "Toyota" 丰田
                                                            // "BMW" 宝马
                                                            // "Peugeot" 标致
                                                            // "Ford" 福特
                                                            // "Mazda" 马自达
                                                            // "Nissan" 尼桑
                                                            // "Hyundai" 现代
                                                            // "Suzuki" 铃木
                                                            // "Citroen" 雪铁龙
                                                            // "Benz" 奔驰
                                                            // "BYD" 比亚迪
                                                            // "Geely" 吉利
                                                            // "Lexus" 雷克萨斯
                                                            // "Chevrolet" 雪佛兰
                                                            // "Chery" 奇瑞
                                                            // "Kia" 起亚
                                                            // "Charade" 夏利
                                                            // "DF" 东风
                                                            // "Naveco" 依维柯
                                                            // "SGMW" 五菱
                                                            // "Jinbei" 金杯

    char                szObjectSubType[64];                // 物体子类别，根据不同的物体类型，可以取以下子类型：
                                                            // Vehicle Category:"Unknown"  未知,"Motor" 机动车,"Non-Motor":非机动车,"Bus": 公交车,"Bicycle" 自行车,"Motorcycle":摩托车,"PassengerCar":客车,
                                                            // "LargeTruck":大货车,    "MidTruck":中货车,"SaloonCar":轿车,"Microbus":面包车,"MicroTruck":小货车,"Tricycle":三轮车,    "Passerby":行人                                                    
                                                            // Plate Category："Unknown" 未知,"Normal" 蓝牌黑牌,"Yellow" 黄牌,"DoubleYellow" 双层黄尾牌,"Police" 警牌"Armed" 武警牌,
                                                            // "Military" 部队号牌,"DoubleMilitary" 部队双层,"SAR" 港澳特区号牌,"Trainning" 教练车号牌
                                                            // "Personal" 个性号牌,"Agri" 农用牌,"Embassy" 使馆号牌,"Moto" 摩托车号牌,"Tractor" 拖拉机号牌,"Other" 其他号牌
                                                            // HumanFace Category:"Normal" 普通人脸,"HideEye" 眼部遮挡,"HideNose" 鼻子遮挡,"HideMouth" 嘴部遮挡
    BYTE                byReserved1[3];
    bool                bPicEnble;                          // 是否有物体对应图片文件信息
    DH_PIC_INFO         stPicInfo;                          // 物体对应图片信息
    bool                bShotFrame;                         // 是否是抓拍张的识别结果
    bool                bColor;                             // 物体颜色(rgbaMainColor)是否可用
    BYTE                byReserved2;
    BYTE                byTimeType;                         // 时间表示类型，详见EM_TIME_TYPE说明
    NET_TIME_EX         stuCurrentTime;                     // 针对视频浓缩，当前时间戳（物体抓拍或识别时，会将此识别智能帧附在一个视频帧或jpeg图片中，此帧所在原始视频中的出现时间）
    NET_TIME_EX         stuStartTime;                       // 开始时间戳（物体开始出现时）
    NET_TIME_EX         stuEndTime;                         // 结束时间戳（物体最后出现时）
    DH_RECT             stuOriginalBoundingBox;             // 包围盒(绝对坐标)
    DH_RECT             stuSignBoundingBox;                 // 车标坐标包围盒
    DWORD               dwCurrentSequence;                  // 当前帧序号（抓下这个物体时的帧）
    DWORD               dwBeginSequence;                    // 开始帧序号（物体开始出现时的帧序号）
    DWORD               dwEndSequence;                      // 结束帧序号（物体消逝时的帧序号）
    INT64               nBeginFileOffset;                   // 开始时文件偏移, 单位: 字节（物体开始出现时，视频帧在原始视频文件中相对于文件起始处的偏移）
    INT64               nEndFileOffset;                     // 结束时文件偏移, 单位: 字节（物体消逝时，视频帧在原始视频文件中相对于文件起始处的偏移）
    BYTE                byColorSimilar[NET_COLOR_TYPE_MAX]; // 物体颜色相似度，取值范围：0-100，数组下标值代表某种颜色，详见EM_COLOR_TYPE
    BYTE                byUpperBodyColorSimilar[NET_COLOR_TYPE_MAX]; // 上半身物体颜色相似度(物体类型为人时有效)
    BYTE                byLowerBodyColorSimilar[NET_COLOR_TYPE_MAX]; // 下半身物体颜色相似度(物体类型为人时有效)
    int                 nRelativeID;                        // 相关物体ID
    BYTE                byReserved[24];
} DH_MSG_OBJECT;
#pragma pack(pop)

// 抓拍信息
typedef struct
{
    short              snSpeed;                         // 当前车的速度，km/h
    short              snCarLength;                     // 当前车长,分米为单位
    float              fRedTime;                        // 当前车道红灯时间,秒.毫秒
    float              fCapTime;                        // 当前车道抓拍时间,秒.毫秒 
    BYTE               bSigSequence;                    // 当前抓拍序号
    BYTE               bType;                           // 当前车道的抓拍类型
                                                        // 0: 雷达高限速;1: 雷达低限速;2: 车检器高限速;3:车检器低限速
                                                        // 4: 逆向;5: 闯红灯;6: 红灯亮;7: 红灯灭;8: 全部抓拍或者卡口
    BYTE               bDirection;                      // 闯红灯类型:01:左转红灯;02:直行红灯;03:右转红灯
    BYTE               bLightColor;                     // 当前车道的红绿灯状态，0: 绿灯, 1: 红灯, 2: 黄灯
    BYTE               bSnapFlag[16];                   // 设备产生的抓拍标识
}DH_SIG_CARWAY_INFO;

// 车检器冗余信息
typedef struct
{
    BYTE                byRedundance[8];                // 由车检器产生抓拍信号冗余信息
    BYTE                bReserved[120];                 // 保留字段
}DH_SIG_CARWAY_INFO_EX;

// 每个车道的相关信息
typedef struct  
{
    BYTE                bCarWayID;                           // 当前车道号 
    BYTE                bReserve[2];                         // 保留字段
    BYTE                bSigCount;                           // 被触发抓拍的个数
    DH_SIG_CARWAY_INFO  stuSigInfo[DH_MAX_SNAP_SIGNAL_NUM];  // 当前车道上，被触发抓拍对应的抓拍信息    
    BYTE                bReserved[12];                       // 保留字段
}DH_CARWAY_INFO;

// 事件对应文件信息
typedef struct  
{
    BYTE               bCount;                               // 当前文件所在文件组中的文件总数
    BYTE               bIndex;                               // 当前文件在文件组中的文件编号(编号1开始)
    BYTE               bFileTag;                             // 文件标签，具体说明见枚举类型EM_EVENT_FILETAG
    BYTE               bFileType;                            // 文件类型，0-普通 1-合成 2-抠图
    NET_TIME_EX        stuFileTime;                          // 文件时间
    DWORD              nGroupId;                             // 同一组抓拍文件的唯一标识
}DH_EVENT_FILE_INFO;

// 图片分辨率
typedef struct
{
    unsigned short   snWidth;    // 宽
    unsigned short   snHight;    // 高
}DH_RESOLUTION_INFO;

// 人员信息
typedef struct tagFACERECOGNITION_PERSON_INFO
{
    char                szPersonName[DH_MAX_NAME_LEN];                  // 姓名，此参数作废                 
    WORD                wYear;                                          // 出生年，作为查询条件时，此参数填0，则表示此参数无效
    BYTE                byMonth;                                        // 出生月，作为查询条件时，此参数填0，则表示此参数无效
    BYTE                byDay;                                          // 出生日，作为查询条件时，此参数填0，则表示此参数无效
    char                szID[DH_MAX_PERSON_ID_LEN];                     // 人员唯一标示(身份证号码，工号，或其他编号)
    BYTE                bImportantRank;                                 // 人员重要等级,1~10，数值越高越重要，作为查询条件时，此参数填0，则表示此参数无效
    BYTE                bySex;                                          // 性别，1-男，2-女，作为查询条件时，此参数填0，则表示此参数无效
    WORD                wFacePicNum;                                    // 图片张数
    DH_PIC_INFO         szFacePicInfo[DH_MAX_PERSON_IMAGE_NUM];         // 当前人员对应的图片信息
    BYTE                byType;                                         // 人员类型，详见 EM_PERSON_TYPE
    BYTE                byIDType;                                       // 证件类型，详见 EM_CERTIFICATE_TYPE
    BYTE                bReserved1[2];                                  // 字节对齐  
    char                szProvince[DH_MAX_PROVINCE_NAME_LEN];           // 省份
    char                szCity[DH_MAX_CITY_NAME_LEN];                   // 城市
    char                szPersonNameEx[DH_MAX_PERSON_NAME_LEN];         // 姓名，因存在姓名过长，16字节无法存放问题，故增加此参数， 
    BYTE                bReserved[60];
}FACERECOGNITION_PERSON_INFO;

// 候选人员信息
typedef struct tagCANDIDATE_INFO
{
    FACERECOGNITION_PERSON_INFO  stPersonInfo;            // 人员信息
    BYTE                         bySimilarity;            // 和查询图片的相似度,百分比表示，1~100
    BYTE                         byRange;                 // 人员所属数据库范围，详见EM_FACE_DB_TYPE
    BYTE                         byReserved1[2];
    NET_TIME                     stTime;                  // 当byRange为历史数据库时有效，表示查询人员出现的时间
    char                         szAddress[MAX_PATH];     // 当byRange为历史数据库时有效，表示查询人员出现的地点    
    BYTE                         byReserved[128];         // 保留字节
}CANDIDATE_INFO;

// TrafficCar 交通车辆信息
typedef struct tagDEV_EVENT_TRAFFIC_TRAFFICCAR_INFO
{
    char               szPlateNumber[32];                   // 车牌号码
    char               szPlateType[32];                     // 号牌类型    参见VideoAnalyseRule中车牌类型定义
    char               szPlateColor[32];                    // 车牌颜色    "Blue","Yellow", "White","Black"
    char               szVehicleColor[32];                  // 车身颜色    "White", "Black", "Red", "Yellow", "Gray", "Blue","Green"
    int                nSpeed;                              // 速度    单位Km/H
    char               szEvent[64];                         // 触发的相关事件    参见事件列表Event List，只包含交通相关事件。
    char               szViolationCode[32];                 // 违章代码    详见TrafficGlobal.ViolationCode
    char               szViolationDesc[64];                 // 违章描述
    int                nLowerSpeedLimit;                    // 速度下限
    int                nUpperSpeedLimit;                    // 速度上限
    int                nOverSpeedMargin;                    // 限高速宽限值    单位：km/h 
    int                nUnderSpeedMargin;                   // 限低速宽限值    单位：km/h 
    int                nLane;                               // 车道    参见事件列表Event List中卡口和路口事件。
    int                nVehicleSize;                        // 车辆大小,-1表示未知，否则按位
                                                            // 第0位:"Light-duty", 小型车
                                                            // 第1位:"Medium", 中型车
                                                            // 第2位:"Oversize", 大型车
                                                            // 第3位:"Minisize", 微型车
                                                            // 第4位:"Largesize", 长车
    float              fVehicleLength;                      // 车辆长度    单位米
    int                nSnapshotMode;                       // 抓拍方式    0-未分类，1-全景，2-近景，4-同向抓拍，8-反向抓拍，16-号牌图像
    char               szChannelName[32];                   // 本地或远程的通道名称，可以是地点信息    来源于通道标题配置ChannelTitle.Name 
    char               szMachineName[256];                  // 本地或远程设备名称    来源于普通配置General.MachineName
    char               szMachineGroup[256];                 // 机器分组或叫设备所属单位    默认为空，用户可以将不同的设备编为一组，便于管理，可重复。
    char               szRoadwayNo[64];                     // 道路编号
    char               szDrivingDirection[3][DH_MAX_DRIVINGDIRECTION];      // 
                                                                            // "DrivingDirection" : ["Approach", "上海", "杭州"],行驶方向
                                                                            // "Approach"-上行，即车辆离设备部署点越来越近；"Leave"-下行，
                                                                            // 即车辆离设备部署点越来越远，第二和第三个参数分别代表上行和
                                                                            // 下行的两个地点
    char              *szDeviceAddress;                     // 设备地址,OSD叠加到图片上的,来源于配置TrafficSnapshot.DeviceAddress,'\0'结束
    char               szVehicleSign[32];                   // 车辆标识, 例如 "Unknown"-未知, "Audi"-奥迪, "Honda"-本田 ...
    DH_SIG_CARWAY_INFO_EX stuSigInfo;                       // 由车检器产生抓拍信号冗余信息
    char              *szMachineAddr;                       // 设备部署地点
    float              fActualShutter;                      // 当前图片曝光时间，单位为毫秒
    BYTE               byActualGain;                        // 当前图片增益，范围为0~100
    BYTE               byDirection;                         // 0-南向北 1-西南向东北 2-西向东 3-西北向东南 4-北向南 5-东北向西南 6-东向西 7-东南向西北 8-未知
    BYTE               byReserved[2];
    char*              szDetailedAddress;                   // 详细地址, 作为szDeviceAddress的补充
    char               szDefendCode[DH_COMMON_STRING_64];   // 图片防伪码  
    BYTE               bReserved[784];                      // 保留字节,留待扩展.
}DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO;


// 事件类型EVENT_IVS_CROSSLINEDETECTION(警戒线事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_CROSSLINE_INFO 
{
    int                 nChannelID;                         // 通道号
    char                szName[128];                        // 事件名称
    char                bReserved1[4];                      // 字节对齐
    double              PTS;                                // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                // 事件发生的时间
    int                 nEventID;                           // 事件ID
    DH_MSG_OBJECT       stuObject;                          // 检测到的物体
    DH_EVENT_FILE_INFO  stuFileInfo;                        // 事件对应文件信息
    DH_POINT            DetectLine[DH_MAX_DETECT_LINE_NUM]; // 规则检测线
    int                 nDetectLineNum;                     // 规则检测线顶点数
    DH_POINT            TrackLine[DH_MAX_TRACK_LINE_NUM];   // 物体运动轨迹
    int                 nTrackLineNum;                      // 物体运动轨迹顶点数
    BYTE                bEventAction;                       // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                bDirection;                         // 表示入侵方向, 0-由左至右, 1-由右至左
    BYTE                byReserved[1];
    BYTE                byImageIndex;                       // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                     // 抓图标志(按位)，具体见NET_RESERVED_COMMON
    int                 nSourceIndex;                       // 事件源设备上的index,-1表示数据无效,-1表示数据无效
    char                szSourceDevice[MAX_PATH];           // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    BYTE                bReserved[612];                     // 保留字节,留待扩展.

} DEV_EVENT_CROSSLINE_INFO;

// 事件类型EVENT_IVS_CROSSREGIONDETECTION(警戒区事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_CROSSREGION_INFO 
{
    int                 nChannelID;                         // 通道号
    char                szName[128];                        // 事件名称
    char                bReserved2[4];                      // 字节对齐
    double              PTS;                                // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                // 事件发生的时间
    int                 nEventID;                           // 事件ID
    DH_MSG_OBJECT       stuObject;                          // 检测到的物体
    DH_EVENT_FILE_INFO  stuFileInfo;                        // 事件对应文件信息
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM]; // 规则检测区域
    int                 nDetectRegionNum;                   // 规则检测区域顶点数
    DH_POINT            TrackLine[DH_MAX_TRACK_LINE_NUM];   // 物体运动轨迹
    int                 nTrackLineNum;                      // 物体运动轨迹顶点数
    BYTE                bEventAction;                       // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                bDirection;                         // 表示入侵方向, 0-进入, 1-离开，2-出现，3-离开
    BYTE                bActionType;                        // 表示检测动作类型,0-出现 1-消失 2-在区域内 3-穿越区域
    BYTE                byImageIndex;                       // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                     // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    int                 nSourceIndex;                       // 事件源设备上的index,-1表示数据无效
    char                szSourceDevice[MAX_PATH];           // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    BYTE                bReserved[540];                     // 保留字节,留待扩展.
    int                 nObjectNum;                         // 检测到的物体个数
    DH_MSG_OBJECT       stuObjectIDs[DH_MAX_OBJECT_LIST];   // 检测到的物体
    int                 nTrackNum;                          // 轨迹数(与检测到的物体个数对应)
    DH_POLY_POINTS      stuTrackInfo[DH_MAX_OBJECT_LIST];   // 轨迹信息(与检测到的物体对应)
} DEV_EVENT_CROSSREGION_INFO;

// 事件类型EVENT_IVS_PASTEDETECTION(贴条事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_PASTE_INFO 
{
    int                 nChannelID;                         // 通道号
    char                szName[128];                        // 事件名称
    char                bReserved1[4];                      // 字节对齐
    double              PTS;                                // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                // 事件发生的时间
    int                 nEventID;                           // 事件ID
    DH_MSG_OBJECT       stuObject;                          // 检测到的物体
    DH_EVENT_FILE_INFO  stuFileInfo;                        // 事件对应文件信息
    int                 nDetectRegionNum;                   // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM]; // 规则检测区域
    BYTE                bEventAction;                       // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                       // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                     // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    BYTE                bReserved[888];                     // 保留字节,留待扩展.

} DEV_EVENT_PASTE_INFO;

// 事件类型EVENT_IVS_LEFTDETECTION(物品遗留事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_LEFT_INFO 
{
    int                 nChannelID;                         // 通道号
    char                szName[128];                        // 事件名称
    char                bReserved1[4];                      // 字节对齐
    double              PTS;                                // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                // 事件发生的时间
    int                 nEventID;                           // 事件ID
    DH_MSG_OBJECT       stuObject;                          // 检测到的物体
    DH_EVENT_FILE_INFO  stuFileInfo;                        // 事件对应文件信息
    BYTE                bEventAction;                       // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                       // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nDetectRegionNum;                   // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM]; // 规则检测区域
    DWORD               dwSnapFlagMask;                     // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    int                 nSourceIndex;                       // 事件源设备上的index,-1表示数据无效
    char                szSourceDevice[MAX_PATH];           // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    BYTE                bReserved[624];                     // 保留字节,留待扩展.

} DEV_EVENT_LEFT_INFO;

// 事件类型EVENT_IVS_PRESERVATION(物品保全事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_PRESERVATION_INFO 
{
    int                 nChannelID;                         // 通道号
    char                szName[128];                        // 事件名称
    char                bReserved1[4];                      // 字节对齐
    double              PTS;                                // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                // 事件发生的时间
    int                 nEventID;                           // 事件ID
    DH_MSG_OBJECT       stuObject;                          // 检测到的物体
    DH_EVENT_FILE_INFO  stuFileInfo;                        // 事件对应文件信息
    BYTE                bEventAction;                       // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                       // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nDetectRegionNum;                   // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM]; // 规则检测区域
    DWORD               dwSnapFlagMask;                     // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    int                 nSourceIndex;                       // 事件源设备上的index,-1表示数据无效
    char                szSourceDevice[MAX_PATH];           // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    BYTE                bReserved[624];                     // 保留字节,留待扩展.

} DEV_EVENT_PRESERVATION_INFO;

// 事件类型EVENT_IVS_STAYDETECTION(停留事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_STAY_INFO 
{
    int                 nChannelID;                         // 通道号
    char                szName[128];                        // 事件名称
    char                bReserved1[4];                      // 字节对齐
    double              PTS;                                // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                // 事件发生的时间
    int                 nEventID;                           // 事件ID
    DH_MSG_OBJECT       stuObject;                          // 检测到的物体
    DH_EVENT_FILE_INFO  stuFileInfo;                        // 事件对应文件信息
    BYTE                bEventAction;                       // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                       // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nDetectRegionNum;                   // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM]; // 规则检测区域
    DWORD               dwSnapFlagMask;                     // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    int                 nSourceIndex;                       // 事件源设备上的index,-1表示数据无效
    char                szSourceDevice[MAX_PATH];           // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    BYTE                bReserved[624];                     // 保留字节,留待扩展.

} DEV_EVENT_STAY_INFO;

// 事件类型EVENT_IVS_WANDERDETECTION(徘徊事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_WANDER_INFO 
{
    int                 nChannelID;                         // 通道号
    char                szName[128];                        // 事件名称
    char                bReserved1[4];                      // 字节对齐
    double              PTS;                                // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                // 事件发生的时间
    int                 nEventID;                           // 事件ID
    DH_EVENT_FILE_INFO  stuFileInfo;                        // 事件对应文件信息
    BYTE                bEventAction;                       // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];                      // 保留字节
    BYTE                byImageIndex;                       // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nObjectNum;                         // 检测到的物体个数
    DH_MSG_OBJECT       stuObjectIDs[DH_MAX_OBJECT_LIST];   // 检测到的物体
    int                 nTrackNum;                          // 轨迹数(与检测到的物体个数对应)
    DH_POLY_POINTS      stuTrackInfo[DH_MAX_OBJECT_LIST];   // 轨迹信息(与检测到的物体对应)
    int                 nDetectRegionNum;                   // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
    DWORD               dwSnapFlagMask;                     // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    int                 nSourceIndex;                       // 事件源设备上的index,-1表示数据无效
    char                szSourceDevice[MAX_PATH];           // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    BYTE                bReserved[760];                     // 保留字节,留待扩展.

} DEV_EVENT_WANDER_INFO;

// 事件类型EVENT_IVS_MOVEDETECTION(移动事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_MOVE_INFO 
{
    int                 nChannelID;                         // 通道号
    char                szName[128];                        // 事件名称
    char                bReserved1[4];                      // 字节对齐
    double              PTS;                                // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                // 事件发生的时间
    int                 nEventID;                           // 事件ID
    DH_MSG_OBJECT       stuObject;                          // 检测到的物体
    DH_EVENT_FILE_INFO  stuFileInfo;                        // 事件对应文件信息
    BYTE                bEventAction;                       // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                       // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nDetectRegionNum;                   // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
    DWORD               dwSnapFlagMask;                     // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    int                 nSourceIndex;                       // 事件源设备上的index,-1表示数据无效
    char                szSourceDevice[MAX_PATH];           // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    int                 nTrackLineNum;                      // 物体运动轨迹顶点数                 
    DH_POINT            stuTrackLine[DH_MAX_TRACK_LINE_NUM];// 物体运动轨迹            
    BYTE                bReserved[540];                     // 保留字节,留待扩展.
} DEV_EVENT_MOVE_INFO;

// 事件类型EVENT_IVS_TAILDETECTION(尾随事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TAIL_INFO 
{
    int                 nChannelID;                         // 通道号
    char                szName[128];                        // 事件名称
    char                bReserved1[4];                      // 字节对齐
    double              PTS;                                // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                // 事件发生的时间
    int                 nEventID;                           // 事件ID
    DH_MSG_OBJECT       stuObject;                          // 检测到的物体
    DH_EVENT_FILE_INFO  stuFileInfo;                        // 事件对应文件信息
    BYTE                bEventAction;                       // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                       // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nDetectRegionNum;                   // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
    DWORD               dwSnapFlagMask;                     // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    int                 nSourceIndex;                       // 事件源设备上的index,-1表示数据无效
    char                szSourceDevice[MAX_PATH];           // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    BYTE                bReserved[624];                     // 保留字节,留待扩展.

} DEV_EVENT_TAIL_INFO;

// 事件类型EVENT_IVS_RIOTERDETECTION(聚众事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_RIOTER_INFO 
{
    int                 nChannelID;                         // 通道号
    char                szName[128];                        // 事件名称
    char                bReserved1[4];                      // 字节对齐
    double              PTS;                                // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                // 事件发生的时间
    int                 nEventID;                           // 事件ID
    int                 nObjectNum;                         // 检测到的物体个数
    DH_MSG_OBJECT       stuObjectIDs[DH_MAX_OBJECT_LIST];   // 检测到的物体列表
    DH_EVENT_FILE_INFO  stuFileInfo;                        // 事件对应文件信息
    BYTE                bEventAction;                       // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];                      // 保留字节
    BYTE                byImageIndex;                       // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nDetectRegionNum;                   // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域

    DWORD               dwSnapFlagMask;                     // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    int                 nSourceIndex;                       // 事件源设备上的index,-1表示数据无效
    char                szSourceDevice[MAX_PATH];           // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    BYTE                bReserved[628];                     // 保留字节,留待扩展.

} DEV_EVENT_RIOTERL_INFO;

// 事件类型EVENT_IVS_FIGHTDETECTION(斗殴事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_FIGHT_INFO 
{
    int                 nChannelID;                         // 通道号
    char                szName[128];                        // 事件名称
    char                bReserved1[4];                      // 字节对齐
    double              PTS;                                // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                // 事件发生的时间
    int                 nEventID;                           // 事件ID
    int                 nObjectNum;                         // 检测到的物体个数
    DH_MSG_OBJECT       stuObjectIDs[DH_MAX_OBJECT_LIST];   // 检测到的物体列表
    DH_EVENT_FILE_INFO  stuFileInfo;                        // 事件对应文件信息
    BYTE                bEventAction;                       // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];                      // 保留字节
    BYTE                byImageIndex;                       // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nDetectRegionNum;                   // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
    
    DWORD               dwSnapFlagMask;                     // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    int                 nSourceIndex;                       // 事件源设备上的index,-1表示数据无效
    char                szSourceDevice[MAX_PATH];           // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    BYTE                bReserved[628];                     // 保留字节,留待扩展.

} DEV_EVENT_FIGHT_INFO;

// 事件类型EVENT_IVS_FIREDETECTION(火警事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_FIRE_INFO 
{
    int                 nChannelID;                         // 通道号
    char                szName[128];                        // 事件名称
    char                bReserved1[4];                      // 字节对齐
    double              PTS;                                // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                // 事件发生的时间
    int                 nEventID;                           // 事件ID
    DH_MSG_OBJECT       stuObject;                          // 检测到的物体
    DH_EVENT_FILE_INFO  stuFileInfo;                        // 事件对应文件信息
    BYTE                bEventAction;                       // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];                      // 保留字节
    BYTE                byImageIndex;                       // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nDetectRegionNum;                   // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
    
    DWORD               dwSnapFlagMask;                     // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    int                 nSourceIndex;                       // 事件源设备上的index,-1表示数据无效
    char                szSourceDevice[MAX_PATH];           // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    BYTE                bReserved[624];                     // 保留字节,留待扩展.

} DEV_EVENT_FIRE_INFO;

// 事件类型 EVENT_IVS_FIREDETECTION(电火花事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_ELECTROSPARK_INFO 
{
    int                 nChannelID;                         // 通道号
    char                szName[128];                        // 事件名称
    char                bReserved1[4];                      // 字节对齐
    double              PTS;                                // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                // 事件发生的时间
    int                 nEventID;                           // 事件ID
    DH_MSG_OBJECT       stuObject;                          // 检测到的物体
    DH_EVENT_FILE_INFO  stuFileInfo;                        // 事件对应文件信息
    BYTE                bEventAction;                       // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                       // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                     // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    BYTE                bReserved[972];                     // 保留字节,留待扩展.
    
} DEV_EVENT_ELECTROSPARK_INFO;

// 事件类型EVENT_IVS_SMOKEDETECTION(烟雾报警事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_SMOKE_INFO 
{
    int                 nChannelID;                         // 通道号
    char                szName[128];                        // 事件名称
    char                bReserved1[4];                      // 字节对齐
    double              PTS;                                // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                // 事件发生的时间
    int                 nEventID;                           // 事件ID
    DH_MSG_OBJECT       stuObject;                          // 检测到的物体
    DH_EVENT_FILE_INFO  stuFileInfo;                        // 事件对应文件信息
    BYTE                bEventAction;                       // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                       // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                     // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    BYTE                bReserved[972];                     // 保留字节,留待扩展.

} DEV_EVENT_SMOKE_INFO;

// 事件类型EVENT_IVS_FLOWSTAT(流量统计事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_FLOWSTAT_INFO 
{
    int                 nChannelID;                         // 通道号
    char                szName[128];                        // 事件名称
    char                bReserved1[4];                      // 字节对齐
    double              PTS;                                // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                // 事件发生的时间
    int                 nEventID;                           // 事件ID
    int                 nNumberLeft;                        // 从左边穿越的人的个数
    int                 nNumberRight;                       // 从右边穿越的人的个数
    int                 nUpperLimit;                        // 设置的上限
    DH_EVENT_FILE_INFO  stuFileInfo;                        // 事件对应文件信息
    BYTE                bEventAction;                       // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                       // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                     // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    BYTE                bReserved[976];                     // 保留字节,留待扩展.

} DEV_EVENT_FLOWSTAT_INFO;

// 事件类型EVENT_IVS_NUMBERSTAT(数量统计事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_NUMBERSTAT_INFO 
{
    int                 nChannelID;                         // 通道号
    char                szName[128];                        // 事件名称
    char                bReserved2[4];                      // 字节对齐
    double              PTS;                                // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                // 事件发生的时间
    int                 nEventID;                           // 事件ID
    int                 nNumber;                            // 区域内物体的个数
    int                 nUpperLimit;                        // 设置的上限
    DH_EVENT_FILE_INFO  stuFileInfo;                        // 事件对应文件信息
    BYTE                bEventAction;                       // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                bReserved1[2];                      // 字节对齐
    BYTE                byImageIndex;                       // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nEnteredNumber;                     // 表示进入区域或者出入口的内物体的个数
    int                 nExitedNumber;                      // 表示出来区域或者出入口的内物体的个数
    DWORD               dwSnapFlagMask;                     // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    BYTE                bReserved[964];                     // 保留字节,留待扩展.

} DEV_EVENT_NUMBERSTAT_INFO;

// 事件类型EVENT_IVS_CROSSFENCEDETECTION(翻越围栏事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_CROSSFENCEDETECTION_INFO 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    int                 nUpstairsLinePointNumber;                   // 围栏上边线顶点数
    DH_POINT            stuUpstairsLine[DH_MAX_DETECT_LINE_NUM];    // 围栏上边线信息
    int                 nDownstairsLinePointNumber;                 // 围栏下边线顶点数
    DH_POINT            stuDownstairsLine[DH_MAX_DETECT_LINE_NUM];  // 围栏下边线信息  
    int                 nTrackLineNum;                              // 物体运动轨迹顶点数                 
    DH_POINT            TrackLine[DH_MAX_TRACK_LINE_NUM];           // 物体运动轨迹
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                bDirection;                                 // 表示入侵方向, 0-由左至右, 1-由右至左
    BYTE                byReserved[1];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    int                 nSourceIndex;                               // 事件源设备上的index,-1表示数据无效
    char                szSourceDevice[MAX_PATH];                   // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    BYTE                bReserved[752];                             // 保留字节,留待扩展.
    
} DEV_EVENT_CROSSFENCEDETECTION_INFO;

// 事件类型EVENT_IVS_INREGIONDETECTION(区域内检测事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_INREGIONDETECTION_INFO 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nObjectNum;                                 // 检测到的物体个数
    DH_MSG_OBJECT       stuObjectIDs[DH_MAX_OBJECT_LIST];           // 检测到的物体
    int                 nTrackNum;                                  // 轨迹数(与检测到的物体个数对应)
    DH_POLY_POINTS      stuTrackInfo[DH_MAX_OBJECT_LIST];           // 轨迹信息(与检测到的物体对应)
    int                 nDetectRegionNum;                           // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];     // 规则检测区域
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    BYTE                bReserved[1016];                            // 保留字节,留待扩展.
    
} DEV_EVENT_INREGIONDETECTION_INFO;

// 事件类型EVENT_IVS_TAKENAWAYDETECTION(物品搬移事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TAKENAWAYDETECTION_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    int                 nDetectRegionNum;                           // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];     // 规则检测区域
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    int                 nSourceIndex;                               // 事件源设备上的index,-1表示数据无效
    char                szSourceDevice[MAX_PATH];                   // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    BYTE                bReserved[752];                             // 保留字节,留待扩展.
    
} DEV_EVENT_TAKENAWAYDETECTION_INFO;

// 事件类型EVENT_IVS_VIDEOABNORMALDETECTION(视频异常事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_VIDEOABNORMALDETECTION_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                bType;                                      // 异常类型, 0-视频丢失, 1-视频冻结, 2-摄像头遮挡, 3-摄像头移动, 4-过暗, 5-过亮
    BYTE                byReserved[1];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    int                 nSourceIndex;                               // 事件源设备上的index,-1表示数据无效
    char                szSourceDevice[MAX_PATH];                   // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    BYTE                bReserved[756];                             // 保留字节,留待扩展.
    
} DEV_EVENT_VIDEOABNORMALDETECTION_INFO;

// 事件类型EVENT_IVS_PARKINGDETECTION(非法停车事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_PARKINGDETECTION_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    int                 nDetectRegionNum;                           // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];     // 规则检测区域
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    int                 nSourceIndex;                               // 事件源设备上的index,-1表示数据无效
    char                szSourceDevice[MAX_PATH];                   // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    BYTE                bReserved[752];                             // 保留字节,留待扩展.
    
} DEV_EVENT_PARKINGDETECTION_INFO;

// 事件类型EVENT_IVS_ABNORMALRUNDETECTION(异常奔跑事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_ABNORMALRUNDETECTION 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    double              dbSpeed;                                    // 物体运动速度,km/h
    double              dbTriggerSpeed;                             // 触发速度,km/h
    int                 nDetectRegionNum;                           // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];     // 规则检测区域
    int                 nTrackLineNum;                              // 物体运动轨迹顶点数                 
    DH_POINT            TrackLine[DH_MAX_TRACK_LINE_NUM];           // 物体运动轨迹
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                bRunType;                                   // 异常奔跑类型, 0-快速奔跑, 1-突然加速, 2-突然减速
    BYTE                byReserved[1];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    int                 nSourceIndex;                               // 事件源设备上的index,-1表示数据无效
    char                szSourceDevice[MAX_PATH];                   // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    BYTE                bReserved[752];                             // 保留字节,留待扩展.
    
} DEV_EVENT_ABNORMALRUNDETECTION_INFO;

// 事件类型EVENT_IVS_RETROGRADEDETECTION(人员逆行事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_RETROGRADEDETECTION_INFO 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    int                 nTrackLineNum;                              // 物体运动轨迹顶点数                 
    DH_POINT            TrackLine[DH_MAX_TRACK_LINE_NUM];           // 物体运动轨迹
    int                 nDirectionPointNum;                         // 规则里规定的方向顶点数
    DH_POINT            stuDirections[DH_MAX_DETECT_LINE_NUM];      // 规则里规定的方向
    int                 nDetectRegionNum;                           // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];     // 规则检测区域
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    int                 nSourceIndex;                               // 事件源设备上的index,-1表示数据无效
    char                szSourceDevice[MAX_PATH];                   // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    BYTE                bReserved[752];                             // 保留字节,留待扩展.
    
} DEV_EVENT_RETROGRADEDETECTION_INFO;

// 事件类型EVENT_IVS_FACERECOGNITION(人脸识别)对应的数据块描述信息
typedef struct tagDEV_EVENT_FACERECOGNITION_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    int                 nEventID;                                   // 事件ID
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    int                 nCandidateNum;                              // 当前人脸匹配到的候选对象数量
    CANDIDATE_INFO      stuCandidates[DH_MAX_CANDIDATE_NUM];        // 当前人脸匹配到的候选对象信息
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    BYTE                byReserved1[2];                             // 对齐
    BOOL                bGlobalScenePic;                            // 全景图是否存在
    DH_PIC_INFO         stuGlobalScenePicInfo;                      // 全景图片信息
    BYTE                bReserved[988];                             // 保留字节,留待扩展.
}DEV_EVENT_FACERECOGNITION_INFO;

// 事件类型EVENT_IVS_DENSITYDETECTION(人员密度检测)对应数据块描述信息
typedef struct tagDEV_EVENT_DENSITYDETECTTION_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nObjectNum;                                 // 检测到的物体个数
    DH_MSG_OBJECT       stuObjectIDs[DH_MAX_OBJECT_LIST];           // 检测到的物体列表
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];                              // 保留字节
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nDetectRegionNum;                           // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];     // 规则检测区域
    
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    int                 nSourceIndex;                               // 事件源设备上的index,-1表示数据无效
    char                szSourceDevice[MAX_PATH];                   // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    BYTE                bReserved[756];                             // 保留字节,留待扩展.
}DEV_EVENT_DENSITYDETECTION_INFO;

// 事件类型 EVENT_IVS_QUEUEDETECTION(排队检测报警事件)对应数据块描述信息
typedef struct tagDEV_EVENT_QUEUEDETECTION_INFO 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved2[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                bReserved1[2];                              // 保留字节,留待扩展.
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DH_POINT            stuDetectLine[2];                           // 规则检测线
    BYTE                bReserved[1016];                            // 保留字节,留待扩展.
}DEV_EVENT_QUEUEDETECTION_INFO;

// 事件类型EVENT_IVS_TRAFFICCONTROL(交通管制事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFICCONTROL_INFO 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    BYTE                bReserved[972];                             // 保留字节,留待扩展.

} DEV_EVENT_TRAFFICCONTROL_INFO;


// 事件类型EVENT_IVS_TRAFFICACCIDENT(交通事故事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFICACCIDENT_INFO 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nObjectNum;                                 // 检测到的物体个数
    DH_MSG_OBJECT       stuObjectIDs[DH_MAX_OBJECT_LIST];           // 检测到的物体列表
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    BYTE                bReserved[976];                             // 保留字节,留待扩展.

} DEV_EVENT_TRAFFICACCIDENT_INFO;

#define DH_EVENT_MAX_CARD_NUM       16      // 事件上报信息包含最大卡片个数
#define DH_EVENT_CARD_LEN           36      // 卡片名称长度

// 事件上报携带卡片信息
typedef struct tagEVENT_CARD_INFO
{
    char szCardNumber[DH_EVENT_CARD_LEN];           // 卡片序号字符串
    BYTE bReserved[32];                             // 保留字节,留待扩展.
}EVENT_CARD_INFO;

typedef enum tagEM_OPEN_STROBE_STATE
{
    NET_OPEN_STROBE_STATE_UNKOWN,                   // 未知状态
    NET_OPEN_STROBE_STATE_CLOSE,                    // 关闸
    NET_OPEN_STROBE_STATE_AUTO,                     // 自动开闸    
    NET_OPEN_STROBE_STATE_MANUAL,                   // 手动开闸
}EM_OPEN_STROBE_STATE;

typedef enum tagEM_VEHICLE_DIRECTION
{
    NET_VEHICLE_DIRECTION_UNKOWN,                   // 未知
    NET_VEHICLE_DIRECTION_HEAD,                     // 车头    
    NET_VEHICLE_DIRECTION_TAIL,                     // 车尾  
}EM_VEHICLE_DIRECTION;

// 事件类型EVENT_IVS_TRAFFICJUNCTION(交通路口老规则事件/视频电警上的交通卡口老规则事件)对应的数据块描述信息
// 由于历史原因，如果要处理卡口事件，DEV_EVENT_TRAFFICJUNCTION_INFO和EVENT_IVS_TRAFFICGATE要一起处理，以防止有视频电警和线圈电警同时接入平台的情况发生
// 另外EVENT_IVS_TRAFFIC_TOLLGATE只支持新卡口事件的配置
typedef struct tagDEV_EVENT_TRAFFICJUNCTION_INFO 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[2];                              // 字节对齐
    BYTE                byVehicleDirection;                         // 当前被抓拍到的车辆是车头还是车尾，具体请见 EM_VEHICLE_DIRECTION
    BYTE                byOpenStrobeState;                          // 开闸状态，具体请见 EM_OPEN_STROBE_STATE 
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    int                 nLane;                                      // 对应车道号
    DWORD               dwBreakingRule;                             // 违反规则掩码,第一位:闯红灯; 
                                                                    // 第二位:不按规定车道行驶;
                                                                    // 第三位:逆行; 第四位：违章掉头;
                                                                    // 第五位:交通堵塞; 第六位:交通异常空闲
                                                                    // 第七位:压线行驶; 否则默认为:交通路口事件

    NET_TIME_EX         RedLightUTC;                                // 红灯开始UTC时间
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    int                 nSequence;                                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    int                 nSpeed;                                     // 车辆实际速度Km/h                 
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byDirection;                                // 路口方向，1-表示正向，2-表示反向
    BYTE                byLightState;                               // LightState表示红绿灯状态:0 未知,1 绿灯,2 红灯,3 黄灯
    BYTE                byReserved;                                 // 保留字节
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    char                szRecordFile[DH_COMMON_STRING_128];         // 报警对应的原始录像文件信息
    BYTE                bReserved[344];                             // 保留字节,留待扩展.
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息
    DWORD               dwRetCardNumber;                            // 卡片个数
    EVENT_CARD_INFO     stuCardInfo[DH_EVENT_MAX_CARD_NUM];         // 卡片信息    
} DEV_EVENT_TRAFFICJUNCTION_INFO;

// 事件类型EVENT_IVS_TRAFFICGATE(交通卡口老规则事件/线圈电警上的交通卡口老规则事件)对应的数据块描述信息
// 由于历史原因，如果要处理卡口事件，DEV_EVENT_TRAFFICJUNCTION_INFO和EVENT_IVS_TRAFFICGATE要一起处理，以防止有视频电警和线圈电警同时接入平台的情况发生
// 另外EVENT_IVS_TRAFFIC_TOLLGATE只支持新卡口事件的配置
typedef struct tagDEV_EVENT_TRAFFICGATE_INFO 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    BYTE                byOpenStrobeState;                          // 开闸状态，具体请见EM_OPEN_STROBE_STATE
    char                bReserved1[3];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    int                 nLane;                                      // 对应车道号
    int                 nSpeed;                                     // 车辆实际速度Km/h
    int                 nSpeedUpperLimit;                           // 速度上限 单位：km/h
    int                 nSpeedLowerLimit;                           // 速度下限 单位：km/h 
    DWORD               dwBreakingRule;                             // 违反规则掩码,第一位:逆行; 
                                                                    // 第二位:压线行驶; 第三位:超速行驶; 
                                                                    // 第四位：欠速行驶; 第五位:闯红灯;第六位:穿过路口(卡口事件)
                                                                    // 第七位: 压黄线; 第八位: 有车占道; 第九位: 黄牌占道;否则默认为:交通卡口事件
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息    
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    BYTE                szManualSnapNo[64];                         // 手动抓拍序号                
    int                 nSequence;                                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束; 
    BYTE                byReserved[3];                              // 保留字节
    BYTE                szSnapFlag[16];                             // 设备产生的抓拍标识
    BYTE                bySnapMode;                                 // 抓拍方式，0-未分类 1-全景 2-近景 4-同向抓拍 8-反向抓拍 16-号牌图像
    BYTE                byOverSpeedPercentage;                      // 超速百分比
    BYTE                byUnderSpeedingPercentage;                  // 欠速百分比
    BYTE                byRedLightMargin;                           // 红灯容许间隔时间,单位：秒
    BYTE                byDriveDirection;                           // 行驶方向，0-上行(即车辆离设备部署点越来越近)，1-下行(即车辆离设备部署点越来越远)
    char                szRoadwayNo[32];                            // 道路编号
    char                szViolationCode[16];                        // 违章代码
    char                szViolationDesc[128];                       // 违章描述
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    char                szVehicleType[32];                          // 车辆大小类型，"Motor" 摩托车车 "Light-duty" 小型车 "Medium" 中型车 "Oversize" 大型车 "Huge" 超大车 "Other" 其他类型
    BYTE                byVehicleLenth;                             // 车辆长度, 单位米
    BYTE                byLightState;                               // LightState表示红绿灯状态:0 未知,1 绿灯,2 红灯,3 黄灯
    BYTE                byReserved1;                             // 保留字节,留待扩展
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nOverSpeedMargin;                           // 限高速宽限值    单位：km/h 
    int                 nUnderSpeedMargin;                          // 限低速宽限值    单位：km/h 
    char                szDrivingDirection[3][DH_MAX_DRIVINGDIRECTION]; //
                                                                    // "DrivingDirection" : ["Approach", "上海", "杭州"],行驶方向
                                                                    // "Approach"-上行，即车辆离设备部署点越来越近；"Leave"-下行，
                                                                    // 即车辆离设备部署点越来越远，第二和第三个参数分别代表上行和
                                                                    // 下行的两个地点，UTF-8编码
    char                szMachineName[256];                         // 本地或远程设备名称
    char                szMachineAddress[256];                      // 机器部署地点、道路编码
    char                szMachineGroup[256];                        // 机器分组、设备所属单位
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_SIG_CARWAY_INFO_EX stuSigInfo;                               // 由车检器产生抓拍信号冗余信息
    char                szFilePath[MAX_PATH];                       // 文件路径
    NET_TIME_EX         RedLightUTC;                                // 红灯开始UTC时间
    char              * szDeviceAddress;                            // 设备地址,OSD叠加到图片上的,来源于配置TrafficSnapshot.DeviceAddress,'\0'结束
    float               fActualShutter;                             // 当前图片曝光时间，单位为毫秒
    BYTE                byActualGain;                               // 当前图片增益，范围为0~100
    BYTE                byDirection;                                // 0-南向北 1-西南向东北 2-西向东 3-西北向东南 4-北向南 5-东北向西南 6-东向西 7-东南向西北 8-未知
    BYTE                bReserve;                                   // 保留字节, 字节对齐
    BYTE                bRetCardNumber;                             // 卡片个数
    EVENT_CARD_INFO     stuCardInfo[DH_EVENT_MAX_CARD_NUM];         // 卡片信息
    char               szDefendCode[DH_COMMON_STRING_64];           // 图片防伪码
    BYTE                bReserved[2504];                            // 保留字节,留待扩展.
} DEV_EVENT_TRAFFICGATE_INFO;

//事件类型EVENT_TRAFFICSNAPSHOT(交通抓拍事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFICSNAPSHOT_INFO 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    BYTE                bReserv[3];                                 // 保留字节 
    BYTE                bCarWayCount;                               // 触发抓拍的车道个数
    DH_CARWAY_INFO      stuCarWayInfo[DH_MAX_CARWAY_NUM];           // 触发抓拍的车道相关信息
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    BYTE                bReserved[344];                             // 保留字节,留待扩展
} DEV_EVENT_TRAFFICSNAPSHOT_INFO;

//事件类型EVENT_IVS_TRAFFIC_RUNREDLIGHT(交通-闯红灯事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_RUNREDLIGHT_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nLane;                                      // 对应车道号
    DH_MSG_OBJECT       stuObject;                                  // 车牌信息
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息 
    int                 nLightState;                                // 红绿灯状态 0:未知 1：绿灯 2:红灯 3:黄灯
    int                 nSpeed;                                     // 车速,km/h
    int                 nSequence;                                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    NET_TIME_EX         stRedLightUTC;                              // 红灯开始时间
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BYTE                byRedLightMargin;                           // 红灯容许间隔时间,单位：秒
    BYTE                bReserved[975];                             // 保留字节
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息
} DEV_EVENT_TRAFFIC_RUNREDLIGHT_INFO;

//事件类型EVENT_IVS_TRAFFIC_OVERLINE(交通-压线事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_OVERLINE_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nLane;                                      // 对应车道号
    DH_MSG_OBJECT       stuObject;                                  // 车牌信息
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    int                 nSequence;                                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    int                 nSpeed;                                     // 车辆实际速度,Km/h
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BYTE                bReserved[1008];                            // 保留字节
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息
} DEV_EVENT_TRAFFIC_OVERLINE_INFO;


//事件类型EVENT_IVS_TRAFFIC_RETROGRADE(交通-逆行事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_RETROGRADE_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nLane;                                      // 对应车道号
    DH_MSG_OBJECT       stuObject;                                  // 车牌信息
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    int                 nSequence;                                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    int                 nSpeed;                                     // 车辆实际速度,Km/h
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BOOL                bIsExistAlarmRecord;                        // rue:有对应的报警录像; false:无对应的报警录像
    DWORD               dwAlarmRecordSize;                          // 录像大小
    char                szAlarmRecordPath[DH_COMMON_STRING_256];    // 录像路径
    BYTE                bReserved[656];                             // 保留字节
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息
    int                 nDetectNum;                                 // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];     // 规则检测区域

} DEV_EVENT_TRAFFIC_RETROGRADE_INFO;

//事件类型EVENT_IVS_TRAFFIC_TURNLEFT(交通-违章左转)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_TURNLEFT_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nLane;                                      // 对应车道号
    DH_MSG_OBJECT       stuObject;                                  // 车牌信息
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    int                 nSequence;                                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    int                 nSpeed;                                     // 车辆实际速度,Km/h
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率

    BYTE                bReserved[1008];                            // 保留字节
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息

} DEV_EVENT_TRAFFIC_TURNLEFT_INFO;


//事件类型EVENT_IVS_TRAFFIC_TURNRIGHT(交通-违章右转)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_TURNRIGHT_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nLane;                                      // 对应车道号
    DH_MSG_OBJECT       stuObject;                                  // 车牌信息
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    int                 nSequence;                                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    int                 nSpeed;                                     // 车辆实际速度,Km/h
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率

    BYTE                bReserved[1008];                            // 保留字节
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息
} DEV_EVENT_TRAFFIC_TURNRIGHT_INFO;

//事件类型EVENT_IVS_TRAFFIC_UTURN(违章调头事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_UTURN_INFO 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nLane;                                      // 对应车道号
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    int                 nSequence;                                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    int                 nSpeed;                                     // 车辆实际速度,Km/h
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    
    BYTE                bReserved[1008];                            // 保留字节
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息
}DEV_EVENT_TRAFFIC_UTURN_INFO;

//事件类型EVENT_IVS_TRAFFIC_OVERSPEED(交通超速事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_OVERSPEED_INFO 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nLane;                                      // 对应车道号
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    int                 nSpeed;                                     // 车辆实际速度Km/h
    int                 nSpeedUpperLimit;                           // 速度上限 单位：km/h
    int                 nSpeedLowerLimit;                           // 速度下限 单位：km/h 
    int                 nSequence;                                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;    
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BYTE                bReserved[1008];                            // 保留字节
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息
}DEV_EVENT_TRAFFIC_OVERSPEED_INFO;

//事件类型EVENT_IVS_TRAFFIC_UNDERSPEED(交通欠速事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_UNDERSPEED_INFO 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved2[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nLane;                                      // 对应车道号
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    int                 nSpeed;                                     // 车辆实际速度Km/h
    int                 nSpeedUpperLimit;                           // 速度上限 单位：km/h
    int                 nSpeedLowerLimit;                           // 速度下限 单位：km/h 
    int                 nSequence;                                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                bReserved1[2];                              // 对齐
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nUnderSpeedingPercentage;                   // 欠速百分比
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BYTE                bReserved[1004];                            // 保留字节
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息

}DEV_EVENT_TRAFFIC_UNDERSPEED_INFO;

//事件类型EVENT_IVS_FACEDETECT(人脸检测事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_FACEDETECT_INFO 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                reserved[2];                                // 保留字节
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nDetectRegionNum;                           // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];     // 规则检测区域
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    BYTE                bReserved[936];                             // 保留字节,留待扩展
} DEV_EVENT_FACEDETECT_INFO;

// 事件类型EVENT_IVS_TRAFFICJAM(交通拥堵事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFICJAM_INFO 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nLane;                                      // 对应车道号
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息               
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                bJamLenght;                                 // 表示拥堵长度(总车道长度百分比）0-100
    BYTE                reserved;                                   // 保留字节
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    NET_TIME_EX         stuStartJamTime;                            // 开始停车时间
    int                 nSequence;                                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束(bEventAction=2时此参数有效)
    int                 nAlarmIntervalTime;                         // 报警时间间隔，单位:秒。(此事件为连续性事件，在收到第一个此事件之后，若在超过间隔时间后未收到此事件的后续事件，则认为此事件异常结束了)
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BYTE                bReserved[1012];                            // 保留字节,留待扩展.
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息    
} DEV_EVENT_TRAFFICJAM_INFO;

// 事件类型EVENT_IVS_TRAFFIC_PARKING(交通违章停车事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_PARKING_INFO 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    int                 nLane;                                      // 对应车道号
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息               
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                reserved[2];                                // 保留字节
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    NET_TIME_EX         stuStartParkingTime;                        // 开始停车时间
    int                 nSequence;                                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束(bEventAction=2时此参数有效)
    int                 nAlarmIntervalTime;                         // 报警时间间隔，单位:秒。(此事件为连续性事件，在收到第一个此事件之后，若在超过间隔时间后未收到此事件的后续事件，则认为此事件异常结束了)
    int                 nParkingAllowedTime;                        // 允许停车时长，单位：秒。
    int                 nDetectRegionNum;                           // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];     // 规则检测区域
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BOOL                bIsExistAlarmRecord;                        // rue:有对应的报警录像; false:无对应的报警录像
    DWORD               dwAlarmRecordSize;                          // 录像大小
    char                szAlarmRecordPath[DH_COMMON_STRING_256];    // 录像路径
    char                szFTPPath[DH_COMMON_STRING_256];            // FTP路径 
    BYTE                bReserved[404];                             // 保留字节,留待扩展.
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息
    
} DEV_EVENT_TRAFFIC_PARKING_INFO;

//事件类型EVENT_IVS_TRAFFIC_WRONGROUTE(交通违章-不按车道行驶)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_WRONGROUTE_INFO 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    int                 nLane;                                      // 对应车道号
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息               
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];           
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nSpeed;                                     // 车辆实际速度，km/h
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BYTE                bReserved[1012];                            // 保留字节,留待扩展.
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息

} DEV_EVENT_TRAFFIC_WRONGROUTE_INFO;

//事件类型EVENT_IVS_TRAFFIC_CROSSLANE(交通违章-违章变道)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_CROSSLANE_INFO 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    int                 nLane;                                      // 对应车道号
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息               
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];       
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
     int                nSpeed;                                     // 车辆实际速度，km/h
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BYTE                bReserved[1008];                            // 保留字节,留待扩展.留待扩展.
    
} DEV_EVENT_TRAFFIC_CROSSLANE_INFO;

//事件类型EVENT_IVS_TRAFFIC_OVERYELLOWLINE(交通违章-压黄线)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_OVERYELLOWLINE_INFO 
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    int                 nLane;                                      // 对应车道号
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息               
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];  
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nSpeed;                                     // 车辆实际速度，km/h
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BOOL                bIsExistAlarmRecord;                        // rue:有对应的报警录像; false:无对应的报警录像
    DWORD               dwAlarmRecordSize;                          // 录像大小
    char                szAlarmRecordPath[DH_COMMON_STRING_256];    // 录像路径
    BYTE                bReserved[664];                             // 保留字节,留待扩展.
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息

    int                 nDetectNum;                                 // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];     // 规则检测区域    
} DEV_EVENT_TRAFFIC_OVERYELLOWLINE_INFO;

//事件类型EVENT_IVS_TRAFFIC_DRIVINGONSHOULDER(交通违章-路肩行驶事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_DRIVINGONSHOULDER_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    int                 nLane;                                      // 对应车道号
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息               
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];      
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nSpeed;                                     // 车辆实际速度，km/h
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BYTE                bReserved[1008];                            // 保留字节,留待扩展.
    
} DEV_EVENT_TRAFFIC_DRIVINGONSHOULDER_INFO;

//事件类型EVENT_IVS_TRAFFIC_YELLOWPLATEINLANE(交通违章-黄牌车占道事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_YELLOWPLATEINLANE_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    int                 nLane;                                      // 对应车道号
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息               
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];     
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nSpeed;                                     // 车辆实际速度，km/h
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BYTE                bReserved[1016];                            // 保留字节,留待扩展.
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息
    
} DEV_EVENT_TRAFFIC_YELLOWPLATEINLANE_INFO;

//事件类型EVENT_IVS_TRAFFIC_NOPASSING(交通违章-禁止通行事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_NOPASSING_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[DH_EVENT_NAME_LEN];                  // 事件名称
    int                 nTriggerType;                               // TriggerType:触发类型，0车检器，1雷达，2视频
    DWORD               PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 UTCMS;                                      // 
    int                 nMark;                                      // 底层产生的触发抓拍帧标记
    int                 nSequence;                                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    BYTE                byReserved1[3];
    int                 nLane;                                      // 对应车道号
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    int                 nFrameSequence;                             // 视频分析帧序号
    int                 nSource;                                    // 视频分析的数据源地址   
    BYTE                byReserved[1024];                           // 保留字节
}DEV_EVENT_TRAFFIC_NOPASSING_INFO;

typedef struct tagDH_TRAFFICFLOWSTAT
{
    char                szMachineAddress[256];                      // 同DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO.MachineGroup
    char                szMachineName[256];                         // 同DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO.MachineName
    char                szDrivingDirection[3][32];                  // 行驶方向"Approach"-上行，即车辆离设备部署点越来越近；"Leave"-下行，即车辆离设备部署点越来越远，第二和第三个参数分别代表上行和下行的两个地点，UTF-8编码
    int                 nLane;                                      // 车道号 使用用户配置的车道编号
    NET_TIME_EX         UTC;                                        // 统计时间，转换到UTC
    int                 nPeriod;                                    // 统计周期，单位分钟
    int                 nVehicles;                                  // 通过车辆总数
    float               fAverageSpeed;                              // 平均车速，单位km/h
    float               fAverageLength;                             // 平均车长，单位米
    float               fTimeOccupyRatio;                           // 时间占有率，即单位时间内通过断面的车辆所用时间的总和占单位时间的比例
    float               fSpaceOccupyRatio;                          // 空间占有率，即按百分率计量的车辆长度总和除以时间间隔内车辆平均行驶距离
    float               fSpaceHeadway;                              // 车头间距，相邻车辆之间的距离，单位米/辆
    float               fTimeHeadway;                               // 车头时距，单位秒/辆
    float               fDensity;                                   // 车辆密度，每公里的车辆数，单位辆/km
    int                 nOverSpeedVehicles;                         // 超速车辆数
    int                 nUnderSpeedVehicles;                        // 低速车辆数
    int                 nLargeVehicles;                             // 大车数量  车辆类型判断标准参见TrafficSnapshot配置表
    int                 nMediumVehicles;                            // 中型车数量
    int                 nSmallVehicles;                             // 小车数量
    int                 nMotoVehicles;                              // 摩托车数量
    int                 nLongVehicles;                              // 超长车数量
}DH_TRAFFICFLOWSTAT; 

// 事件类型 TrafficFlowStat Info(交通流量统计事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_FLOWSTAT_INFO
{
    char                szName[128];                                // 事件名称
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nLaneCnt;                                   // 通道总数
    DH_TRAFFICFLOWSTAT  stTrafficFlowStats[DH_MAX_LANE_NUM];        //流量统计记录，是一个数组
    char                Reserved[4];                                // 保留字节对齐
}DEV_EVENT_TRAFFIC_FLOWSTAT_INFO;

//事件类型EVENT_IVS_TRAFFIC_MANUALSNAP(交通手动抓拍事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_MANUALSNAP_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nLane;                                      // 对应车道号
    BYTE                szManualSnapNo[64];                         // 手动抓拍序号 
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 检测到的车身信息
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 表示交通车辆的数据库记录
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BYTE                bReserved[1016];                            // 保留字节,留待扩展.
}DEV_EVENT_TRAFFIC_MANUALSNAP_INFO;

//事件类型 EVENT_IVS_TRAFFIC_STAY(交通滞留事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_STAY_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    int                 nLane;                                      // 对应车道号
    int                 nSequence;                                  // 抓拍序号，如3-2-1/0，1表示抓拍正常结束，0表示抓拍异常结束
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 表示交通车辆的数据库记录
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息               
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved0[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BYTE                byReserved[1012];           
}DEV_EVENT_TRAFFIC_STAY_INFO;

//事件类型 EVENT_IVS_TRAFFIC_VEHICLEINROUTE(有车占道事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_VEHICLEINROUTE_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    int                 nLane;                                      // 对应车道号
    int                 nSequence;                                  // 抓拍序号，如3-2-1/0，1表示抓拍正常结束，0表示抓拍异常结束
    int                 nSpeed;                                     // 车速
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 表示交通车辆的数据库记录
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息               
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved0[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BYTE                byReserved[1016];           
}DEV_EVENT_TRAFFIC_VEHICLEINROUTE_INFO;

// 报警事件类型 EVENT_ALARM_LOCALALARM(外部报警)，EVENT_ALARM_MOTIONALARM(动检报警)报警)
typedef struct tagDEV_EVENT_ALARM_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                Reserved[4];                                // 保留字节对齐    
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID                                                                                                                                                                                                                                                                         
}DEV_EVENT_ALARM_INFO;

// 报警事件类型 EVENT_ALARM_ANALOGALARM(模拟量报警通道报警),
typedef struct tagDEV_EVENT_ALARM_ANALOGALRM_INFO 
{
    int                 nChannelID;                                 // (视频)通道号
    char                szName[DH_COMMON_STRING_128];               // 模拟量报警通道名称
    char                Reserved[4];                                // 保留字节对齐	
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID 
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息   
    int                 nIndex;                                     // 模拟量报警通道号
    NET_SENSE_METHOD    emSensor;                                   // 传感器类型
    int                 nStatus;                                    // 数据状态, -1:未知,0:正常,1:数据无效(超过量程),
                                                                    // 2:超过阈值1,3:超过阈值2,4:超过阈值3,5:超过阈值4,
                                                                    // 6:低于阈值1,7:低于阈值2,8:低于阈值3,9:低于阈值4
    float               fValue;                                     // 探测器数值
    NET_TIME            stuCollectTime;                             // 数据采集时间(UTC)
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved2[1023];                          // 保留字节,留待扩展
}DEV_EVENT_ALARM_ANALOGALRM_INFO;

//EVENT_ALARM_VEHICLEACC(ACC断电报警)
typedef struct tagDEV_EVENT_ALARM_VEHICLEACC_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[DH_COMMON_STRING_128];               // 事件名称
    char                Reserved[4];                                // 保留字节对齐    
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID      
    NET_GPS_STATUS_INFO stGPSStatusInfo;                            // GPS信息
    int                 nACCStatus;                                 // ACC状态    0:无效(兼容用) , 1:开启 , 2:关闭    
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                bConstantElectricStatus;                    // 常电状态 , 0:无效(兼容用) , 1:连接 , 2:断开                            
    BYTE                bReserved[1022];                            // 保留字节,留待扩展.
}DEV_EVENT_ALARM_VEHICLEACC_INFO;


// 报警事件类型 EVENT_ALARM_VEHICLE_TURNOVER(车辆侧翻) , EVENT_ALARM_VEHICLE_COLLISION(车辆撞车)
typedef struct tagDEV_EVENT_VEHICEL_ALARM_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                Reserved[4];                                // 保留字节对齐    
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID  
    NET_GPS_STATUS_INFO stGPSStatusInfo;                            // GPS信息
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];                              // 字节对齐用
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BYTE                bReserved[1024];                            // 保留字节,留待扩展.
}DEV_EVENT_VEHICEL_ALARM_INFO;

// 事件类型 EVENT_IVS_PRISONERRISEDETECTION (看守所囚犯起身事件) 对应的数据块描述信息
typedef struct tagDEV_EVENT_PRISONERRISEDETECTION_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    int                 nDetectRegionNum;                           // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];     // 规则检测区域
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    double              dInitialUTC;                                // 事件初始UTC时间    UTC为事件的UTC (1970-1-1 00:00:00)秒数。
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    int                 nSourceIndex;                               // 事件源设备上的index,-1表示数据无效
    char                szSourceDevice[MAX_PATH];                   // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    BYTE                bReserved[752];                             // 保留字节,留待扩展.
}DEV_EVENT_PRISONERRISEDETECTION_INFO;

//事件类型 EVENT_IVS_TRAFFIC_PEDESTRAINPRIORITY(斑马线行人优先事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_PEDESTRAINPRIORITY_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    int                 nLane;                                      // 对应车道号
    double              dInitialUTC;                                // 事件初始UTC时间    UTC为事件的UTC (1970-1-1 00:00:00)秒数。
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 表示交通车辆的数据库记录
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BYTE                bReserved[1024];                            // 保留字节,留待扩展.
}DEV_EVENT_TRAFFIC_PEDESTRAINPRIORITY_INFO;

//事件类型 EVENT_IVS_TRAFFIC_VEHICLEINBUSROUTE(占用公交车道事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_VEHICLEINBUSROUTE_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    int                 nLane;                                      // 对应车道号
    int                 nSequence;                                  // 抓拍序号，如3-2-1/0，1表示抓拍正常结束，0表示抓拍异常结束
    int                 nSpeed;                                     // 车速，km/h
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 表示交通车辆的数据库记录
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BYTE                bReserved[1020];                            // 保留字节,留待扩展.
}DEV_EVENT_TRAFFIC_VEHICLEINBUSROUTE_INFO;

//事件类型 EVENT_IVS_TRAFFIC_BACKING(违章倒车事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_IVS_TRAFFIC_BACKING_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    int                 nLane;                                      // 对应车道号
    int                 nSequence;                                  // 抓拍序号，如3-2-1/0，1表示抓拍正常结束，0表示抓拍异常结束
    int                 nSpeed;                                     // 车速，km/h
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 表示交通车辆的数据库记录
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BYTE                bReserved[1020];                            // 保留字节,留待扩展.
}DEV_EVENT_IVS_TRAFFIC_BACKING_INFO;

//事件类型EVENT_IVS_AUDIO_ABNORMALDETECTION(声音异常检测)对应数据块描述信息
typedef struct tagDEV_EVENT_IVS_AUDIO_ABNORMALDETECTION_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    int                 nDecibel;                                   // 声音强度
    int                 nFrequency;                                 // 声音频率
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    BYTE                bReserved[1024];                            // 保留字节,留待扩展.
}DEV_EVENT_IVS_AUDIO_ABNORMALDETECTION_INFO;

//事件类型 EVENT_IVS_TRAFFIC_RUNYELLOWLIGHT(交通违章-闯黄灯事件)对应数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_RUNYELLOWLIGHT_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nLane;                                      // 对应车道号
    DH_MSG_OBJECT       stuObject;                                  // 车牌信息
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息 
    int                 nLightState;                                // 红绿灯状态 0:未知 1：绿灯 2:红灯 3:黄灯
    int                 nSpeed;                                     // 车速,km/h
    int                 nSequence;                                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    NET_TIME_EX         stYellowLightUTC;                           // 黄灯开始时间
    unsigned int        nYellowLightPeriod;                         // 黄灯周期间隔时间,单位秒
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
     BYTE               byRedLightMargin;                           // 黄灯容许间隔时间,单位：秒
    char                szSourceDevice[MAX_PATH];                   // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息
    BYTE                bReserved[1024];                            // 保留字节
} DEV_EVENT_TRAFFIC_RUNYELLOWLIGHT_INFO;

//事件类型 EVENT_IVS_LEAVEDETECTION(离岗检测事件)对应数据块描述信息
typedef struct tagDEV_EVENT_IVS_LEAVE_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    int                 nDetectRegionNum;                           // 规则检测区域顶点数
    DH_POINT            DetectRegion[DH_MAX_DETECT_REGION_NUM];     // 规则检测区域
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;    
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    BYTE                bReserved[1026];                            // 保留字节
} DEV_EVENT_IVS_LEAVE_INFO;

//事件类型 EVENT_IVS_CLIMBDETECTION(攀高检测事件)对应数据块描述信息
typedef struct tagDEV_EVENT_IVS_CLIMB_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    int                 nDetectLineNum;                             // 规则检测线顶点数
    DH_POINT            DetectLine[DH_MAX_DETECT_LINE_NUM];         // 规则检测线
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    BYTE                bReserved[1026];                            // 保留字节
}DEV_EVENT_IVS_CLIMB_INFO;

//事件类型 EVENT_IVS_MULTISCENESWITCH(多场景切换事件)对应数据块描述信息
typedef struct tagDEV_EVENT_IVS_MULTI_SCENE_SWICH_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[4];                              // 字节对齐
    double              PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;    
    BYTE                bReserved[1027];                            // 保留字节
} DEV_EVENT_IVS_MULTI_SCENE_SWICH_INFO;

//事件类型 EVENT_IVS_TRAFFIC_PARKINGONYELLOWBOX(黄网格线抓拍事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_PARKINGONYELLOWBOX_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[128];                                // 事件名称
    char                bReserved1[8];                              // 字节对齐
    DWORD               PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nLane;                                      // 对应车道号
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息

    int                 nInterval1;                                 // 第二张和第一张的延时时间，单位秒
    int                 nInterval2;                                 // 第三张和第二张的延时时间，单位秒
    int                 nFollowTime;                                // 跟随时间，如果一辆车与前一辆车进入黄网格的时间差小于此值，就认为是跟车进入，跟车进入情况下如果停车则不算违章

    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息
    BYTE                bReserved[1024];                            // 保留字节

}DEV_EVENT_TRAFFIC_PARKINGONYELLOWBOX_INFO;

//事件类型 EVENT_IVS_TRAFFIC_PARKINGSPACEPARKING(车位有车事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_PARKINGSPACEPARKING_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[DH_EVENT_NAME_LEN];                  // 事件名称
    char                bReserved1[8];                              // 字节对齐
    DWORD               PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nLane;                                      // 对应车道号
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    
    int                 nSequence;                                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束    
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息
    BYTE                bReserved[1024];                            // 保留字节
    
}DEV_EVENT_TRAFFIC_PARKINGSPACEPARKING_INFO;

//事件类型 EVENT_IVS_TRAFFIC_PARKINGSPACENOPARKING(车位无车事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_PARKINGSPACENOPARKING_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[DH_EVENT_NAME_LEN];                  // 事件名称
    char                bReserved1[8];                              // 字节对齐
    DWORD               PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nLane;                                      // 对应车道号
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    
    int                 nSequence;                                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byReserved[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;                 // 交通车辆信息
    BYTE                bReserved[1024];                            // 保留字节
    
}DEV_EVENT_TRAFFIC_PARKINGSPACENOPARKING_INFO;

// 事件类型 EVENT_IVS_TRAFFIC_PARKINGSPACEOVERLINE (车位压线事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_PARKINGSPACEOVERLINE_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[DH_EVENT_NAME_LEN];                  // 事件名称
    DWORD               PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    int                 nLane;                                      // 对应车道号
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    DH_MSG_OBJECT       stuVehicle;                                 // 车身信息
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    
    int                 nSequence;                                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    BYTE                byEventAction;                              // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    BYTE                byReserved1[2];
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stuTrafficCar;                // 交通车辆信息
    BYTE                byReserved[1024];                           // 保留字节
}DEV_EVENT_TRAFFIC_PARKINGSPACEOVERLINE_INFO;

//事件类型 EVENT_IVS_TRAFFIC_PEDESTRAIN(交通行人事件)对应数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_PEDESTRAIN_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[DH_EVENT_NAME_LEN];                  // 事件名称
    char                bReserved1[8];                              // 字节对齐
    DWORD               PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，0位:"*",1位:"Timing",2位:"Manual",3位:"Marked",4位:"Event",5位:"Mosaic",6位:"Cutout" 
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                bReserved2[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nLane;                                      // 对应车道号
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    BYTE                bReserved[1024];                            // 保留字节
}DEV_EVENT_TRAFFIC_PEDESTRAIN_INFO;

//事件类型 EVENT_IVS_TRAFFIC_THROW(交通抛洒物品事件)对应数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_THROW_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[DH_EVENT_NAME_LEN];                  // 事件名称
    char                bReserved1[8];                              // 字节对齐
    DWORD               PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，0位:"*",1位:"Timing",2位:"Manual",3位:"Marked",4位:"Event",5位:"Mosaic",6位:"Cutout" 
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                bReserved2[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nLane;                                      // 对应车道号
    DH_MSG_OBJECT       stuObject;                                  // 检测到的物体
    BYTE                bReserved[1024];                            // 保留字节
}DEV_EVENT_TRAFFIC_THROW_INFO;

//事件类型 EVENT_IVS_TRAFFIC_IDLE(交通空闲事件)对应数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_IDLE_INFO
{
    int                 nChannelID;                                 // 通道号
    char                szName[DH_EVENT_NAME_LEN];                  // 事件名称
    char                bReserved1[8];                              // 字节对齐
    DWORD               PTS;                                        // 时间戳(单位是毫秒)
    NET_TIME_EX         UTC;                                        // 事件发生的时间
    int                 nEventID;                                   // 事件ID
    DH_EVENT_FILE_INFO  stuFileInfo;                                // 事件对应文件信息
    DH_RESOLUTION_INFO  stuResolution;                              // 对应图片的分辨率
    DWORD               dwSnapFlagMask;                             // 抓图标志(按位)，0位:"*",1位:"Timing",2位:"Manual",3位:"Marked",4位:"Event",5位:"Mosaic",6位:"Cutout" 
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                bReserved2[2];
    BYTE                byImageIndex;                               // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    int                 nLane;                                      // 对应车道号
    BYTE                bReserved[1024];                            // 保留字节
}DEV_EVENT_TRAFFIC_IDLE_INFO;

#define MAX_DRIVING_DIR_NUM          16                             //  车道行驶方向最大个数

// 车辆行驶方向
typedef enum tagNET_FLOWSTAT_DIRECTION
{
    DRIVING_DIR_UNKNOW = 0 ,                                        //兼容之前
    DRIVING_DIR_APPROACH ,                                          //上行，即车辆离设备部署点越来越近
    DRIVING_DIR_LEAVE ,                                             //下行，即车辆离设备部署点越来越远
}NET_FLOWSTAT_DIRECTION;

// 道路方向
typedef enum tagNET_ROAD_DIRECTION
{
    ROAD_DIR_UNKNOW,             // 未知  
    ROAD_DIR_TURNLEFT,           // 左转 
    ROAD_DIR_TURNRIGHT,          // 右转
    ROAD_DIR_STRAIGHT,           // 直行
    ROAD_DIR_UTURU,              // 掉头
    ROAD_DIR_NUM,    
}NET_ROAD_DIRECTION;

//车辆流量统计车辆行驶方向信息 
typedef struct tagNET_TRAFFIC_FLOWSTAT_INFO_DIR
{
    NET_FLOWSTAT_DIRECTION      emDrivingDir;                       //行驶方向
    char                        szUpGoing[FLOWSTAT_ADDR_NAME];      //上行地点 
    char                        szDownGoing[FLOWSTAT_ADDR_NAME];    //下行地点 
    BYTE                        reserved[32];                       //保留字节
    
}NET_TRAFFIC_FLOWSTAT_INFO_DIR;

typedef struct tagNET_TRAFFIC_FLOW_STATE 
{
    int                             nLane;                          // 车道号
    DWORD                           dwState;                        // 状态值
                                                                    // 1- 流量过大
                                                                    // 2- 流量过大恢复
                                                                    // 3- 正常
                                                                    // 4- 流量过小
                                                                    // 5- 流量过小恢复
    DWORD                           dwFlow;                         // 流量值, 单位: 辆
    DWORD                           dwPeriod;                       // 流量值对应的统计时间
    NET_TRAFFIC_FLOWSTAT_INFO_DIR   stTrafficFlowDir;               // 车道方向信息
    int                             nVehicles;                      // 通过车辆总数
    float                           fAverageSpeed;                  // 平均车速，单位km/h
    float                           fAverageLength;                 // 平均车长，单位米
    float                           fTimeOccupyRatio;               // 时间占有率，即单位时间内通过断面的车辆所用时间的总和占单位时间的比例
    float                           fSpaceOccupyRatio;              // 空间占有率，即按百分率计量的车辆长度总和除以时间间隔内车辆平均行驶距离
    float                           fSpaceHeadway;                  // 车头间距，相邻车辆之间的距离，单位米/辆
    float                           fTimeHeadway;                   // 车头时距，单位秒/辆
    float                           fDensity;                       // 车辆密度，每公里的车辆数，单位辆/km
    int                             nOverSpeedVehicles;             // 超速车辆数
    int                             nUnderSpeedVehicles;            // 低速车辆数
    int                             nLargeVehicles;                 // 大车交通量(9米<车长<12米)，辆/单位时间
    int                             nMediumVehicles;                // 中型车交通量(6米<车长<9米)，辆/单位时间
    int                             nSmallVehicles;                 // 小车交通量(4米<车长<6米)，辆/单位时间，
    int                             nMotoVehicles;                  // 摩托交通量(微型车,车长<4米),辆/单位时间，
    int                             nLongVehicles;                  // 超长交通量(车长>=12米),辆/单位时间，
    int                             nVolume;                        // 交通量, 辆/单位时间, 某时间间隔通过车道、道路或其他通道上一点的车辆数，常以1小时计, 
    int                             nFlowRate;                      // 流率小车当量,辆/小时, 车辆通过车道、道路某一断面或某一路段的当量小时流量
    int                             nBackOfQueue;                   // 排队长度，单位：米, 从信号交叉口停车线到上游排队车辆末端之间的距离
    int                             nTravelTime;                    // 旅行时间，单位：秒, 车辆通过某一条道路所用时间。包括所有停车延误
    int                             nDelay;                         // 延误，单位：秒，驾驶员、乘客或行人花费的额外的行程时间
    BYTE                            byDirection[MAX_DRIVING_DIR_NUM]; // 车道方向，详见NET_ROAD_DIRECTION
    BYTE                            byDirectionNum;                 // 车道行驶方向个数
    BYTE                            reserved[859];                  // 保留字节
}NET_TRAFFIC_FLOW_STATE;

//事件类型 EVENT_IVS_TRAFFIC_FLOWSTATE(交通流量事件)对应数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_FLOW_STATE
{
    int                     nChannelID;                             // 通道号
    char                    szName[DH_EVENT_NAME_LEN];              // 事件名称
    char                    bReserved1[8];                          // 字节对齐
    DWORD                   PTS;                                    // 时间戳(单位是毫秒)
    NET_TIME_EX             UTC;                                    // 事件发生的时间
    int                     nEventID;                               // 事件ID
    int                     nSequence;                              // 序号
    int                     nStateNum;                              // 流量状态数量
    NET_TRAFFIC_FLOW_STATE  stuStates[DH_MAX_LANE_NUM];             // 流量状态, 每个车道对应数组中一个元素
    BYTE                    bReserved[1024];                        // 保留字节
}DEV_EVENT_TRAFFIC_FLOW_STATE;

// media文件查询条件
typedef enum __EM_FILE_QUERY_TYPE
{
    DH_FILE_QUERY_TRAFFICCAR,                           // 交通车辆信息
    DH_FILE_QUERY_ATM,                                  // ATM信息
    DH_FILE_QUERY_ATMTXN,                               // ATM交易信息 
    DH_FILE_QUERY_FACE,                                 // 人脸信息 MEDIAFILE_FACERECOGNITION_PARAM 和 MEDIAFILE_FACERECOGNITION_INFO
    DH_FILE_QUERY_FILE,                                 // 文件信息对应 NET_IN_MEDIA_QUERY_FILE 和 NET_OUT_MEDIAFILE_FILE
    DH_FILE_QUERY_TRAFFICCAR_EX,                        // 交通车辆信息, 扩展DH_FILE_QUERY_TRAFFICCAR, 支持更多的字段
    DH_FILE_QUERY_FACE_DETECTION,                       // 人脸检测事件信息 MEDIAFILE_FACE_DETECTION_PARAM 和 MEDIAFILE_FACE_DETECTION_INFO
} EM_FILE_QUERY_TYPE;

typedef enum _EM_RECORD_SNAP_FLAG_TYPE
{
    FLAG_TYPE_TIMING ,                  //定时文件
    FLAG_TYPE_MANUAL ,                  //手动文件
    FLAG_TYPE_MARKED ,                  //重要文件
    FLAG_TYPE_EVENT  ,                  //事件文件
    FLAG_TYPE_MOSAIC ,                  //合成图片
    FLAG_TYPE_CUTOUT ,                  //抠图图片
    FLAG_TYPE_LEAVE_WORD ,              //留言文件
    FLAG_TYPE_TALKBACK_LOCAL_SIDE ,     //对讲本地方文件
    FLAG_TYPE_TALKBACK_REMOTE_SIDE ,    //对讲远程方文件
    FLAG_TYPE_SYNOPSIS_VIDEO ,          //浓缩视频
    FLAG_TYPE_ORIGINAL_VIDEO ,          //原始视频
    FLAG_TYPE_PRE_ORIGINAL_VIDEO ,      //已经预处理的原始视频
    FLAG_TYPE_BLACK_PLATE ,             //黑名单图片
    FLAG_TYPE_ORIGINAL_PIC ,            //原始图片
	FLAG_TYPE_CARD,                     //卡号录像
    FLAG_TYPE_MAX = 128, 
}EM_RECORD_SNAP_FLAG_TYPE;

// ATM交易类型
typedef enum
{
    ATM_TRADE_ALL,                      // 所有类型
	ATM_TRADE_ENQUIRY,                  // 查询
	ATM_TRADE_WITHDRAW,                 // 取款
	ATM_TRADE_MODIFY_PASSWORD,          // 修改密码
	ATM_TRADE_TRANSFER,                 // 转账
	ATM_TRADE_DEPOSIT,                  // 存款
	ATM_TRADE_CARDLESS_ENQUIRY,         // 无卡查询
	ATM_TRADE_CARDLESS_DEPOSIT,         // 无卡存款
	ATM_TRADE_OTHER,                    // 其他
}EM_ATM_TRADE_TYPE;

// 卡号录像信息
typedef struct
{
    DWORD               dwSize;
    int                 nType;          // 类型, 0-Card, 1-Field
    char                szCardNo[DH_MAX_CARD_INFO_LEN]; // 卡号
    EM_ATM_TRADE_TYPE   emTradeType;    // 交易类型
    char                szAmount[DH_COMMON_STRING_64]; // 交易金额, 空字符串表示不限金额
    int                 nError;         // 错误码, 0-所有错误, 1-吞钞, 2-吞卡
    int                 nFieldCount;    // 域数量, 按域查询时有效
    char                szFields[MAX_CARD_RECORD_FIELD_NUM][DH_COMMON_STRING_256];   // 域信息, 按域查询时有效
}NET_RECORD_CARD_INFO;


#define MAX_IVS_EVENT_NUM    256

// 录像信息对应 CLIENT_FindFileEx接口的 DH_FILE_QUERY_FILE 命令 查询条件
// 目前支持通过路径查询
typedef struct  
{
    DWORD               dwSize;                 // 结构体大小
    char*               szDirs;                 // 工作目录列表,一次可查询多个目录,为空表示查询所有目录。目录之间以分号分隔，如“/mnt/dvr/sda0;/mnt/dvr/sda1”,szDirs==null 或"" 表示查询所有
    int                 nMediaType;             // 文件类型，0:查询任意类型,1:查询jpg图片,2:查询dav
    int                 nChannelID;             // 通道号从0开始，-1表示查询所有通道
    NET_TIME            stuStartTime;           // 开始时间	
    NET_TIME            stuEndTime;             // 结束时间
    int                 nEventLists[MAX_IVS_EVENT_NUM]; // 事件类型列表,参见智能分析事件类型
    int                 nEventCount;            // 事件总数
    BYTE                byVideoStream;          // 视频码流 0-未知 1-主码流 2-辅码流1 3-辅码流2 4-辅码流3 
    BYTE                bReserved[3];           // 字节对齐
    EM_RECORD_SNAP_FLAG_TYPE emFalgLists[FLAG_TYPE_MAX]; // 录像或抓图文件标志, 不设置标志表示查询所有文件
    int                 nFalgCount;             // 标志总数
	NET_RECORD_CARD_INFO stuCardInfo;           // 卡号录像信息, emFalgLists包含卡号录像时有效
}NET_IN_MEDIA_QUERY_FILE;

// 录像信息对应 CLIENT_FindFileEx接口的 DH_FILE_QUERY_FILE 命令 查询结果
typedef struct  
{
    DWORD               dwSize;                 // 结构体大小
    int                 nChannelID;             // 通道号从0开始，-1表示查询所有通道
    NET_TIME            stuStartTime;           // 开始时间    
    NET_TIME            stuEndTime;             // 结束时间
    unsigned int        nFileSize;              // 文件长度
    BYTE                byFileType;             // 文件类型 1:jpg图片, 2: dav
    BYTE                byDriveNo;              // 磁盘号
    BYTE                byPartition;            // 分区号
    BYTE                byVideoStream;          // 视频码流 0-未知 1-主码流 2-辅码流1 3-辅码流 4-辅码流 
    unsigned int        nCluster;               // 簇号
    char                szFilePath[MAX_PATH];   // 文件路径
    int                 nEventLists[MAX_IVS_EVENT_NUM]; // 关联的事件列表,事件类型列表,参见智能分析事件类型
    int                 nEventCount;            //事件总数
    EM_RECORD_SNAP_FLAG_TYPE emFalgLists[FLAG_TYPE_MAX]; // 录像或抓图文件标志 
    int                 nFalgCount;             //标志总数
}NET_OUT_MEDIA_QUERY_FILE;

// DH_MEDIA_QUERY_TRAFFICCAR对应的查询条件
typedef struct  
{
    int                 nChannelID;                     // 通道号从0开始，-1表示查询所有通道
    NET_TIME            StartTime;                      // 开始时间    
    NET_TIME            EndTime;                        // 结束时间
    int                 nMediaType;                     // 文件类型，0:任意类型, 1:jpg图片, 2:dav文件
    int                 nEventType;                     // 事件类型，详见"智能分析事件类型", 0:表示查询任意事件，此参数废弃，请使用pEventTypes
    char                szPlateNumber[32];              // 车牌号, "\0"则表示查询任意车牌号
    int                 nSpeedUpperLimit;               // 查询的车速范围; 速度上限 单位: km/h
    int                 nSpeedLowerLimit;               // 查询的车速范围; 速度下限 单位: km/h 
    BOOL                bSpeedLimit;                    // 是否按速度查询; TRUE:按速度查询,nSpeedUpperLimit和nSpeedLowerLimit有效。
    DWORD               dwBreakingRule;                 // 违章类型：
                                                        // 当事件类型为 EVENT_IVS_TRAFFICGATE时
                                                        //        第一位:逆行;  第二位:压线行驶; 第三位:超速行驶; 
                                                        //        第四位：欠速行驶; 第五位:闯红灯;
                                                        // 当事件类型为 EVENT_IVS_TRAFFICJUNCTION
                                                        //        第一位:闯红灯;  第二位:不按规定车道行驶;  
                                                        //        第三位:逆行; 第四位：违章掉头;
                                                        //        第五位:压线行驶;

    char                szPlateType[32];                // 车牌类型，"Unknown" 未知,"Normal" 蓝牌黑牌,"Yellow" 黄牌,"DoubleYellow" 双层黄尾牌,"Police" 警牌"Armed" 武警牌,
                                                        // "Military" 部队号牌,"DoubleMilitary" 部队双层,"SAR" 港澳特区号牌,"Trainning" 教练车号牌
                                                        // "Personal" 个性号牌,"Agri" 农用牌,"Embassy" 使馆号牌,"Moto" 摩托车号牌,"Tractor" 拖拉机号牌,"Other" 其他号牌
    char                szPlateColor[16];               // 车牌颜色, "Blue"蓝色,"Yellow"黄色, "White"白色,"Black"黑色
    char                szVehicleColor[16];             // 车身颜色:"White"白色, "Black"黑色, "Red"红色, "Yellow"黄色, "Gray"灰色, "Blue"蓝色,"Green"绿色
    char                szVehicleSize[16];              // 车辆大小类型:"Light-duty":小型车;"Medium":中型车; "Oversize":大型车; "Unknown": 未知
    int                 nGroupID;                       // 事件组编号(此值>=0时有效)
    short               byLane;                         // 车道号(此值>=0时表示具体车道，-1表示所有车道，即不下发此字段)
    BYTE                byFileFlag;                     // 文件标志, 0xFF-使用nFileFlagEx, 0-表示所有录像, 1-定时文件, 2-手动文件, 3-事件文件, 4-重要文件, 5-合成文件
    BYTE                byRandomAccess;                 // 是否需要在查询过程中随意跳转，0-不需要，1-需要
    int                 nFileFlagEx;                    // 文件标志, 按位表示: bit0-定时文件, bit1-手动文件, bit2-事件文件, bit3-重要文件, bit4-合成文件, bit5-黑名单图片 0xFFFFFFFF-所有录像
    int                 nDirection;                     // 车道方向（车开往的方向）    0-北 1-东北 2-东 3-东南 4-南 5-西南 6-西 7-西北 8-未知 -1-所有方向
    char*               szDirs;                         // 工作目录列表,一次可查询多个目录,为空表示查询所有目录。目录之间以分号分隔，如“/mnt/dvr/sda0;/mnt/dvr/sda1”,szDirs==null 或"" 表示查询所有
    int*                pEventTypes;                    // 待查询的事件类型数组指针,事件类型,详见"智能分析事件类型"，若为NULL则认为查询所有事件（缓冲需由用户申请）
    int                 nEventTypeNum;                  // 事件类型数组大小
    char*               pszDeviceAddress;               // 设备地址, NULL表示该字段不起作用
    char*               pszMachineAddress;              // 机器部署地点, NULL表示该字段不起作用
    char*               pszVehicleSign;                 // 车辆标识, 例如 "Unknown"-未知, "Audi"-奥迪, "Honda"-本田... NULL表示该字段不起作用
    int                 bReserved[32];                  // 保留字段
} MEDIA_QUERY_TRAFFICCAR_PARAM;

// DH_MEDIA_QUERY_TRAFFICCAR查询出来的media文件信息
typedef struct
{
    unsigned int        ch;                                 // 通道号
    char                szFilePath[128];                    // 文件路径
    unsigned int        size;                               // 文件长度
    NET_TIME            starttime;                          // 开始时间
    NET_TIME            endtime;                            // 结束时间
    unsigned int        nWorkDirSN;                         // 工作目录编号                                    
    BYTE                nFileType;                          // 文件类型  1：jpg图片
    BYTE                bHint;                              // 文件定位索引
    BYTE                bDriveNo;                           // 磁盘号
    BYTE                bReserved2;
    unsigned int        nCluster;                           // 簇号
    BYTE                byPictureType;                      // 图片类型, 0-普通, 1-合成, 2-抠图
    BYTE                bReserved[3];                       // 保留字段

    //以下是交通车辆信息
    char                szPlateNumber[32];                  // 车牌号码
    char                szPlateType[32];                    // 号牌类型"Unknown" 未知; "Normal" 蓝牌黑牌; "Yellow" 黄牌; "DoubleYellow" 双层黄尾牌
                                                            // "Police" 警牌; "Armed" 武警牌; "Military" 部队号牌; "DoubleMilitary" 部队双层
                                                            // "SAR" 港澳特区号牌; "Trainning" 教练车号牌; "Personal" 个性号牌; "Agri" 农用牌
                                                            // "Embassy" 使馆号牌; "Moto" 摩托车号牌; "Tractor" 拖拉机号牌; "Other" 其他号牌
    char                szPlateColor[16];                   // 车牌颜色:"Blue","Yellow", "White","Black"
    char                szVehicleColor[16];                 // 车身颜色:"White", "Black", "Red", "Yellow", "Gray", "Blue","Green"
    int                 nSpeed;                             // 车速,单位Km/H
    int                 nEventsNum;                         // 关联的事件个数
    int                 nEvents[32];                        // 关联的事件列表,数组值表示相应的事件，详见"智能分析事件类型"        
    DWORD               dwBreakingRule;                     // 具体违章类型掩码,第一位:闯红灯; 第二位:不按规定车道行驶;
                                                            // 第三位:逆行; 第四位：违章掉头;否则默认为:交通路口事件
    char                szVehicleSize[16];                  // 车辆大小类型:"Light-duty":小型车;"Medium":中型车; "Oversize":大型车
    char                szChannelName[DH_CHAN_NAME_LEN];    // 本地或远程的通道名称
    char                szMachineName[DH_MAX_NAME_LEN];     // 本地或远程设备名称

    int                 nSpeedUpperLimit;                   // 速度上限 单位: km/h
    int                 nSpeedLowerLimit;                   // 速度下限 单位: km/h    
    int                 nGroupID;                           // 事件里的组编号
    BYTE                byCountInGroup;                     // 一个事件组内的抓拍张数
    BYTE                byIndexInGroup;                     // 一个事件组内的抓拍序号
    BYTE                byLane;                             // 车道,参见MEDIA_QUERY_TRAFFICCAR_PARAM
    BYTE                bReserved1[45];                     // 保留
    int                 nDirection;                         // 车道方向,参见MEDIA_QUERY_TRAFFICCAR_PARAM
    char                szMachineAddress[MAX_PATH];         // 机器部署地点
} MEDIAFILE_TRAFFICCAR_INFO, *LPMEDIAFILE_TRAFFICCAR_INFO;

// DH_MEDIA_QUERY_TRAFFICCAR_EX对应的查询条件
typedef struct tagMEDIA_QUERY_TRAFFICCAR_PARAM_EX
{
    DWORD               dwSize;
    MEDIA_QUERY_TRAFFICCAR_PARAM stuParam;                  // 基本查询参数
} MEDIA_QUERY_TRAFFICCAR_PARAM_EX;

// DH_MEDIA_QUERY_TRAFFICCAR_EX查询出来的文件信息
typedef struct tagMEDIAFILE_TRAFFICCAR_INFO_EX
{
    DWORD               dwSize;
    MEDIAFILE_TRAFFICCAR_INFO stuInfo;                          // 基本信息
    char                szDeviceAddr[DH_COMMON_STRING_256];     // 设备地址
    char                szVehicleSign[DH_COMMON_STRING_32];     // 车辆标识, 例如 "Unknown"-未知, "Audi"-奥迪, "Honda"-本田...
} MEDIAFILE_TRAFFICCAR_INFO_EX;

// FINDNEXT查询输入参数
typedef struct __NET_FINDNEXT_RESERVED
{
    DWORD               dwSize;                         // 结构体大小
    
    unsigned int        nBeginNumber;                   // 查询起始序号，表示从beginNumber条记录开始查 0<=beginNumber<= totalCount-1
}NET_FINDNEXT_RESERVED;

// 查询跳转条件
typedef struct __NET_FINDING_JUMP_OPTION_INFO
{
    DWORD           dwSize;
    int             nOffset;                            // 查询结果偏移量, 是相对于当前查询的第一条查询结果的位置偏移
}NET_FINDING_JUMP_OPTION_INFO;

// DH_FILE_QUERY_FACE对应的人脸识别服务查询参数
typedef struct __MEDIAFILE_FACERECOGNITION_PARAM
{
    DWORD               dwSize;                         // 结构体大小

    // 查询过滤条件
    NET_TIME            stStartTime;                    // 开始时间
    NET_TIME            stEndTime;                      // 结束时间
    char                szMachineAddress[MAX_PATH];     // 地点，支持模糊匹配     
    int                 nAlarmType;                     // 待查询报警类型，详见 EM_FACERECOGNITION_ALARM_TYPE
}MEDIAFILE_FACERECOGNITION_PARAM;

typedef struct  tagDH_PIC_INFO_EX
{
    DWORD                dwSize;                        // 结构体大小
    DWORD                dwFileLenth;                   // 文件大小, 单位:字节
    char                 szFilePath[MAX_PATH];          // 文件路径          
}DH_PIC_INFO_EX;

typedef struct __NET_CANDIDAT_PIC_PATHS
{
    DWORD                dwSize;                        // 结构体大小
    int                  nFileCount;                    // 实际文件个数
    DH_PIC_INFO_EX       stFiles[DH_MAX_PERSON_IMAGE_NUM];//文件信息
}NET_CANDIDAT_PIC_PATHS;

// DH_FILE_QUERY_FACE对应的人脸识别服务FINDNEXT查询返回参数
typedef struct __MEDIAFILE_FACERECOGNITION_INFO
{
    DWORD                   dwSize;                                 // 结构体大小
    BOOL                    bGlobalScenePic;                        // 全景图是否存在
    DH_PIC_INFO_EX          stGlobalScenePic;                       // 全景图片文件路径
    DH_MSG_OBJECT           stuObject;                              // 目标人脸物体信息
    DH_PIC_INFO_EX          stObjectPic;                            // 目标人脸文件路径
    int                     nCandidateNum;                          // 当前人脸匹配到的候选对象数量
    CANDIDATE_INFO          stuCandidates[DH_MAX_CANDIDATE_NUM];    // 当前人脸匹配到的候选对象信息
    NET_CANDIDAT_PIC_PATHS  stuCandidatesPic[DH_MAX_CANDIDATE_NUM]; // 当前人脸匹配到的候选对象图片文件路径
    NET_TIME                stTime;                                 // 报警发生时间  
    char                    szAddress[MAX_PATH];                    // 报警发生地点
}MEDIAFILE_FACERECOGNITION_INFO;

typedef enum __EM_FACEPIC_TYPE
{
    NET_FACEPIC_TYPE_UNKOWN,            // 未知类型
    NET_FACEPIC_TYPE_GLOBAL_SENCE,      // 人脸全景大图
    NET_FACEPIC_TYPE_SMALL,             // 人脸小图
}EM_FACEPIC_TYPE;

#define  NET_MAX_FRAMESEQUENCE_NUM     2
#define  NET_MAX_TIMESTAMP_NUM         2

typedef struct __MEDIAFILE_FACE_DETECTION_DETAIL_PARAM
{
    DWORD               dwSize;
    DWORD               dwObjectId;                     // 物体ID
    DWORD               dwFrameSequence;                // 帧序号
    NET_TIME_EX         stTime;                         // 发生时间
}MEDIAFILE_FACE_DETECTION_DETAIL_PARAM;
 
// DH_FILE_QUERY_FACE_DETECTION 对应的人脸识别服务查询参数
typedef struct __MEDIAFILE_FACE_DETECTION_PARAM
{
    DWORD               dwSize;                         // 结构体大小
    
    // 查询过滤条件
    int                 nChannelID;                     // 通道号
    NET_TIME            stuStartTime;                   // 起始时间
    NET_TIME            stuEndTime;                     // 结束时间
    EM_FACEPIC_TYPE     emPicType;                      // 图片类型，详见 EM_FACEPIC_TYPE
    BOOL                bDetailEnable;                  // 是否有详细信息
    MEDIAFILE_FACE_DETECTION_DETAIL_PARAM stuDetail;    // 参数详细信息

}MEDIAFILE_FACE_DETECTION_PARAM;

// DH_FILE_QUERY_FACE_DETECTION对应的人脸识别服务FINDNEXT查询返回参数
typedef struct __MEDIAFILE_FACE_DETECTION_INFO
{
    DWORD               dwSize;                                     // 结构体大小

    unsigned int        ch;                                         // 通道号
    char                szFilePath[128];                            // 文件路径
    unsigned int        size;                                       // 文件长度
    NET_TIME            starttime;                                  // 开始时间
    NET_TIME            endtime;                                    // 结束时间
    unsigned int        nWorkDirSN;                                 // 工作目录编号                                    
    BYTE                nFileType;                                  // 文件类型  1：jpg图片
    BYTE                bHint;                                      // 文件定位索引
    BYTE                bDriveNo;                                   // 磁盘号
    BYTE                byPictureType;                              // 图片类型, 0-普通, 1-合成, 2-抠图
    unsigned int        nCluster;                                   // 簇号
    
    EM_FACEPIC_TYPE     emPicType;                                  // 图片类型，详见EM_FACE_PIC_TYPE
    DWORD               dwObjectId;                                 // 物体ID
    DWORD               dwFrameSequence[NET_MAX_FRAMESEQUENCE_NUM]; // 帧序号,数组有2个元素时，第一个表示小图，第二个表示大图
    int                 nFrameSequenceNum;                          // 帧序号个数 
    NET_TIME_EX         stTimes[NET_MAX_TIMESTAMP_NUM];             // 发生时间，数组有2个元素时，第一个表示小图，第二个表示大图
    int                 nTimeStampNum;
}MEDIAFILE_FACE_DETECTION_INFO;

// 视频浓缩相关文件查询参数
typedef struct __MEDIA_QUERY_VIDEOSYNOPSIS_PARAM
{
    DWORD               dwSize;
    NET_TIME            StartTime;                          // 开始时间    
    NET_TIME            EndTime;                            // 结束时间
    int                 nMediaType;                         // 文件类型，0:查询任意类型,1:图片,2:录像
    int                 nQueryType;                         // 查询类型，1:原始视频文件 2:浓缩后的视频文件
}MEDIA_QUERY_VIDEOSYNOPSIS_PARAM;

typedef struct __MEDIAFILE_VIDEOSYNOPSIS_INFO
{
    char                szFilePath[128];                    // 文件路径
    unsigned int        size;                               // 文件长度
    NET_TIME            starttime;                          // 开始时间
    NET_TIME            endtime;                            // 结束时间
    unsigned int        nWorkDirSN;                         // 工作目录编号                                    
    BYTE                nFileType;                          // 文件类型  1：jpg图片
    BYTE                bHint;                              // 文件定位索引
    BYTE                bDriveNo;                           // 磁盘号
    BYTE                bReserved2;
    unsigned int        nCluster;                           // 簇号
    BYTE                byPictureType;                      // 图片类型, 0-普通, 1-合成, 2-抠图
    BYTE                bReserved[3];                       // 保留字段

    // 视频源文件相关信息
    int                 nTaskID;                            // 任务ID
    char                szCurrentState[DH_MAX_SYNOPSIS_STATE_NAME]; // 视频浓缩状态
    int                 nProgress;                          // 对应浓缩状态
    int                 nObjectNum;                         // 浓缩得到的物体个数

    // 浓缩后的视频文件相关信息
    int                 nDurationTime;                      // 持续时间,单位s
}MEDIAFILE_VIDEOSYNOPSIS_INFO;

// 结构体(NET_IN_SNAPSHOT)成员 闪关灯调节控制     是一个数组，每个元素对应一个闪光灯配置
typedef struct __NET_FLASHCONTROL
{
    DWORD               dwSize;                             // 此结构体大小
    int                 nMode;                              // 工作模式    0-禁止闪光，1-始终闪光，2-自动闪光
}NET_FLASHCONTROL;

// 抓拍客户端类型
typedef enum tagSNAP_CLIENT_TYPE
{
    SNAP_CLIENT_TYPE_COMMON,                // 对应"Common"类型, 默认类型
    SNAP_CLIENT_TYPE_PARKINGSPACE,          // 对应"ParkingSpace"类型, 停车场
}SNAP_CLIENT_TYPE;

#define DH_MAX_USER_DEFINE_INFO        1024

// nTriggerType==2时 客户端触发抓拍参数
typedef struct _NET_CLIENT_SNAP_INFO
{
    DWORD               dwSize;                                         // 此结构体大小
    unsigned int        nFrameSequence;                                 // 帧序号
    double              PTS;                                            // 时间戳,64位毫秒时间戳
    char                szUserDefinedInfo[DH_MAX_USER_DEFINE_INFO];     // 字符串，客户端自定义,"\0"结尾
    SNAP_CLIENT_TYPE    emSNAP_CLIENT_TYPE;                             // 客户端类型
    DWORD               dwRetCardNumber;                                // 卡片个数
    EVENT_CARD_INFO     stuCardInfo[DH_EVENT_MAX_CARD_NUM];             // 卡片信息     
}NET_CLIENT_SNAP_INFO;

// 接口(CLIENT_TrafficSnapByNetwork)输入参数
typedef struct __NET_IN_SNAPSHOT
{
    DWORD                   dwSize;                     // 此结构体大小
    int                     nTriggerType;               // 触发类型    0-未知    1-中盟网络触发 2-客户端触发（此时只需要填写stClientInfo参数）
    int                     nLaneID;                    // 车道号
    int                     nGroupID;                   // 组序号
    int                     nGrabTimes;                 // 抓拍图片数量
    int                     nStartPicNum;               // 第一张图片开始序号
    int                     nDirection;                 // 车道方向（车开往的方向）    0-北 1-东北 2-东 3-东南 4-南 5-西南 6-西 7-西北 8-未知
    //NET_GRAB_WAITTIME     stGrabWaitTime;             // 多张图片之间抓拍间隔
    int                     nGrabWaitTime;              // pGrabWaitTime数组成员个数
    DWORD*                  pGrabWaitTime;              // 多张图片之间抓拍间隔
    int                     nLowerSpeedLimit;           // 速度下限，单位km/h
    int                     nUpperSpeedLimit;           // 速度下限，单位km/h
    int                     nSpeed;                     // 车速，单位km/h
    int                     nViolationNo;               // 违法编号    0-未违法
                                                        // 1-黑名单
                                                        // 2-超速不超过50% 
                                                        // 3-超速在50%到100%之间
                                                        // 4-超速超过100%
                                                        // 5-逆行
                                                        // 6-闯红灯
                                                        // 7-低于限速
                                                        // 8-禁行，不按车道行驶
    int                     nRedLightTime;              // 红灯时间，即红灯点亮多少时间后触发抓拍，单位秒
    //NET_FLASHCONTROL      stFlashControl;             // 闪关灯调节控制
    int                     nFlashControl;              // pFlashControl数组个数
    NET_FLASHCONTROL*       pFlashControl;              // 闪关灯调节控制
    DWORD                   dwUser;                     // 用户数据 NSP
    NET_CLIENT_SNAP_INFO    stClientInfo;               // 客户端触发时传入的抓拍参数
}NET_IN_SNAPSHOT;

// 接口(CLIENT_TrafficSnapByNetwork)输出参数
typedef struct __NET_OUT_SNAPSHOT
{
    DWORD                dwSize;                    // 此结构体大小
}NET_OUT_SNAPSHOT;

// 接口(CLIENT_TrafficForceLightState)输入参数
typedef struct __NET_IN_FORCELIGHTSTATE
{
    DWORD               dwSize;                     // 此结构体大小
    unsigned int        nDirection;                 // 按位表示：0位："Straight",1位："TurnLeft",2位："TurnRight",3位："U-Turn"
}NET_IN_FORCELIGHTSTATE;

// 接口(CLIENT_TrafficForceLightState)输出参数
typedef struct __NET_OUT_FORCELIGHTSTATE
{
    DWORD                dwSize;                    // 此结构体大小
}NET_OUT_FORCELIGHTSTATE;

// 接口(CLIENT_StartTrafficFluxStat)回调
typedef int  (CALLBACK *fFluxStatDataCallBack)(LLONG lFluxStatHandle, DWORD dwEventType, void* pEventInfo, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser, int nSequence, void *reserved);

// 接口(CLIENT_StartTrafficFluxStat)输入参数
typedef struct __NET_IN_TRAFFICFLUXSTAT
{
    DWORD                   dwSize;                 // 此结构体大小
    fFluxStatDataCallBack   cbData;                 // 回调函数指针
    LDWORD                  dwUser;                 // 用户数据
}NET_IN_TRAFFICFLUXSTAT;

// 接口(CLIENT_StartTrafficFluxStat)输出参数
typedef struct __NET_OUT_TRAFFICFLUXSTAT
{
    DWORD                dwSize;                    // 此结构体大小    
}NET_OUT_TRAFFICFLUXSTAT;

// 接口(CLIENT_StartFindFluxStat)输入参数
typedef struct __NET_IN_TRAFFICSTARTFINDSTAT
{
    DWORD               dwSize;                     // 此结构体大小
    NET_TIME            stStartTime;                // 开始时间 暂时精确到小时
    NET_TIME            stEndTime;                  // 结束时间 暂时精确到小时
    int                 nWaittime;                  // 等待接收数据的超时时间
}NET_IN_TRAFFICSTARTFINDSTAT;

// 接口(CLIENT_StartFindFluxStat)输出参数
typedef struct __NET_OUT_TRAFFICSTARTFINDSTAT
{
    DWORD               dwSize;                     // 此结构体大小
    DWORD               dwTotalCount;               // 符合此次查询条件的结果总条数                 
}NET_OUT_TRAFFICSTARTFINDSTAT;

// 接口(CLIENT_DoFindFluxStat)输入参数
typedef struct __NET_IN_TRAFFICDOFINDSTAT
{
    DWORD               dwSize;                     // 此结构体大小
    unsigned int        nCount;                     // 每次查询的流量统计条数
    int                 nWaittime;                  // 等待接收数据的超时时间
}NET_IN_TRAFFICDOFINDSTAT;

typedef struct
{
    DWORD               dwSize;                     // 此结构体大小
    int                 nStatInfo;                  // 统计信息个数
    DH_TRAFFICFLOWSTAT  *pStatInfo;                 // 统计信息指针
}DH_TRAFFICFLOWSTAT_OUT;

// 接口(CLIENT_DoFindFluxStat)输出参数
typedef struct __NET_OUT_TRAFFICDOFINDSTAT
{
    DWORD                   dwSize;                 // 此结构体大小
    DH_TRAFFICFLOWSTAT_OUT  stStatInfo;             // 统计信息指针
}NET_OUT_TRAFFICDOFINDSTAT;

// 接口(CLIENT_StartFindNumberStat)输入参数
typedef struct __NET_IN_FINDNUMBERSTAT
{
    DWORD               dwSize;                     // 此结构体大小
    int                 nChannelID;                 // 要进行查询的通道号
    NET_TIME            stStartTime;                // 开始时间 暂时精确到小时
    NET_TIME            stEndTime;                  // 结束时间 暂时精确到小时
    int                 nGranularityType;           // 查询粒度0:分钟，1:小时,2:日,3:周,4:月,5:季,6:年
    int                 nWaittime;                  // 等待接收数据的超时时间
}NET_IN_FINDNUMBERSTAT;

// 接口(CLIENT_StartFindNumberStat)输出参数
typedef struct __NET_OUT_FINDNUMBERSTAT
{
    DWORD               dwSize;                     // 此结构体大小
    DWORD               dwTotalCount;               // 符合此次查询条件的结果总条数
}NET_OUT_FINDNUMBERSTAT;

// 接口(CLIENT_DoFindNumberStat)输入参数
typedef struct __NET_IN_DOFINDNUMBERSTAT
{
    DWORD               dwSize;                     // 此结构体大小
    unsigned int        nBeginNumber;               // [0, totalCount-1], 查询起始序号，表示从beginNumber条记录开始，取count条记录返回; 
    unsigned int        nCount;                     // 每次查询的流量统计条数
    int                 nWaittime;                  // 等待接收数据的超时时间            
}NET_IN_DOFINDNUMBERSTAT;

typedef struct __DH_NUMBERSTAT
{
    DWORD    dwSize;
    int      nChannelID;                           //统计通道号
    char     szRuleName[DH_CHAN_NAME_LEN];         //规则名称
    NET_TIME stuStartTime;                         //开始时间
    NET_TIME stuEndTime;                           //结束时间
    int      nEnteredSubTotal;                     //进入人数小计
    int      nExitedSubtotal;                      //出去人数小计
    int      nAvgInside;                           //平均保有人数(除去零值)
    int      nMaxInside;                           //最大保有人数
}DH_NUMBERSTAT;

// 接口(CLIENT_DoFindNumberStat)输出参数
typedef struct __NET_OUT_DOFINDNUMBERSTAT
{
    DWORD               dwSize;                          // 此结构体大小
    int                 nCount;                          // 查询返回人数统计信息个数
    DH_NUMBERSTAT       *pstuNumberStat;                 // 返回人数统计信息数组
    int                 nBufferLen;                      // 用户申请的内存大小,以DH_NUMBERSTAT中的dwsize大小为单位
}NET_OUT_DOFINDNUMBERSTAT;

//// 智能交通车检器相关接口参数

// 接口 CLIENT_GetParkingSpaceStatus 的输入参数
typedef struct tagNET_IN_GET_PARKINGSPACE_STATUS
{
    DWORD                dwSize;                         // 此结构体大小
    DWORD                dwWaitTime;                     // 接口超时等待时间
    int                  nChannelID;                     // 通道号
    int *                pLaneID;                        // 取值范围[0,255], pLaneID==NULL表示所有车位,车位最大数同DH_PRODUCTION_DEFNITION.nMaxRoadWays
    int                  nLaneCount;                     // 申请的内存为sizeof(int)*nLaneCount
} NET_IN_GET_PARKINGSPACE_STATUS;

typedef struct tagNET_LANE_PARKINGSPACE_STATUS
{
    DWORD                dwSize;                         // 此结构体大小
    int                  nLaneID;                        // 车位号
    unsigned int         nPictureId;                     // 图片ID,用于获取图片数据
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;      // 交通车辆信息
} NET_LANE_PARKINGSPACE_STATUS;

// 接口 CLIENT_GetParkingSpaceStatus 的输出参数
typedef struct tagNET_OUT_GET_PARKINGSPACE_STATUS
{
    DWORD                dwSize;                         // 此结构体大小
    NET_LANE_PARKINGSPACE_STATUS* pStatus;               // 返回的车位状态
    int                  nMaxStatus;                     // 需要事先申请的内存为sizeof(NET_LANE_PARKINGSPACE_STATUS)*nMaxStatus，且nMaxStatus == DH_PRODUCTION_DEFNITION.nMaxRoadWays
    int                  nRetStatus;                     // 实际返回的车位状态数
} NET_OUT_GET_PARKINGSPACE_STATUS;

// 接口 CLIENT_AttachParkingSpaceData 的输入参数
typedef struct tagNET_CB_PARKINGSPACE_DATA
{
    DWORD                dwSize;                         // 此结构体大小
    void*                pPicBuffer;                     // 图片二进制数据
    unsigned int         nPicLength;                     // 图片总长度
} NET_CB_PARKINGSPACE_DATA;

// 接口 CLIENT_AttachParkingSpaceData 回调函数，pBuf是json和图片数据，nBufLen是pBuf相应长度，用于转发服务
typedef int (CALLBACK *fNotifySnapData)(LLONG lParkingHandle, NET_CB_PARKINGSPACE_DATA* pDiagnosisInfo, void* pBuf, int nBufLen, LDWORD dwUser);

// 接口 CLIENT_AttachParkingSpaceData 的输入参数
typedef struct tagNET_IN_ATTACH_PARKINGSPACE
{
    DWORD                dwSize;                         // 此结构体大小
    DWORD                dwWaitTime;                     // 接口超时等待时间
    int                  nChannelID;                     // 通道号
    unsigned int         nPictureId;                     // 图片ID,见NET_LANE_PARKINGSPACE_STATUS.nPictureId
    
    fNotifySnapData      cbNotifySnapData;               // 回调函数
    LDWORD               dwUser;                         // 用户自定义参数
} NET_IN_ATTACH_PARKINGSPACE;

// 接口 CLIENT_AttachParkingSpaceData 的输出参数
typedef struct tagNET_OUT_ATTACH_PARKINGSPACE
{
    DWORD                dwSize;                         // 此结构体大小
} NET_OUT_ATTACH_PARKINGSPACE;

// 接口 CLIENT_DetachParkingSpaceData 的输入参数
typedef struct tagNET_IN_DETACH_PARKINGSPACE
{
    DWORD                dwSize;                         // 此结构体大小
    DWORD                dwWaitTime;                     // 接口超时等待时间
    LLONG                lParkingHandle;                 // CLIENT_AttachParkingSpaceData返回的句柄
} NET_IN_DETACH_PARKINGSPACE;
// 接口 CLIENT_DetachParkingSpaceData 的输出参数
typedef struct tagNET_OUT_DETACH_PARKINGSPACE
{
    DWORD                dwSize;                         // 此结构体大小
} NET_OUT_DETACH_PARKINGSPACE;

// 文件批量下载

// 下载进度回调函数原型， nError表示在下载过程出现的错误，1-缓存不足，2-对返回数据的校验出错，3-下载当前文件失败，4-创建对应保存文件失败
typedef void (CALLBACK *fMultiFileDownLoadPosCB)(LLONG lDownLoadHandle, DWORD dwFileID, DWORD dwFileTotalSize, DWORD dwDownLoadSize, int nError, LDWORD dwUser, void* pReserved);

// CLIENT_DownLoadMultiFile 接口参数
typedef struct tagNET_DOWNLOADFILE_INFO
{
    DWORD               dwSize;
    DWORD               dwFileID;                       // 文件ID, 由用户自己分配
    int                 nFileSize;                      // 查询到的文件大小
    char                szSourceFilePath[MAX_PATH];     // 查询到的文件路径
    char                szSavedFileName[MAX_PATH];      // 文件保存路径
}NET_DOWNLOADFILE_INFO;

typedef struct tagNET_IN_DOWNLOAD_MULTI_FILE
{
    DWORD                   dwSize;
    int                     nFileCount;                 // 待下载文件数
    NET_DOWNLOADFILE_INFO*  pFileInfos;                 // 待下载文件信息
    fMultiFileDownLoadPosCB cbPosCallBack;              // 进度回调函数
    LDWORD                  dwUserData;                 // 用户数据
}NET_IN_DOWNLOAD_MULTI_FILE;

typedef struct tagNET_OUT_DOWNLOAD_MULTI_FILE
{
    DWORD               dwSize;
    LLONG               lDownLoadHandle;                // 下载句柄
}NET_OUT_DOWNLOAD_MULTI_FILE;

typedef struct __NET_VIDEOANALYSE_STATE
{
    DWORD            dwSize;
    DWORD            dwProgress;                        // 分析进度，0-100
    char             szState[DH_COMMON_STRING_64];      // 通道状态,Running"：运行，"Stop"：停止，"NoStart"：未启动，"Failed"：失败，"Successed"：成功
    char             szFailedCode[DH_COMMON_STRING_64]; // 错误码
}NET_VIDEOANALYSE_STATE;

//视频分析进度状态实时回调函数
typedef int (CALLBACK *fVideoAnalyseState)(LLONG lAttachHandle, NET_VIDEOANALYSE_STATE* pAnalyseStateInfos, LDWORD dwUser, void* pReserved);

// CLIENT_AttachVideoAnalyseState接口输入参数
typedef struct __NET_IN_ATTACH_VIDEOANALYSE_STATE 
{
    DWORD              dwSize;
    int                nChannleId;            // 通道号
    fVideoAnalyseState cbVideoAnalyseState;   // 视频分析状态回调函数
    LDWORD             dwUser;                // 用户信息 
}NET_IN_ATTACH_VIDEOANALYSE_STATE;

// CLIENT_AttachVideoAnalyseState接口输出参数
typedef struct __NET_OUT_ATTACH_VIDEOANALYSE_STATE 
{
    DWORD              dwSize;
    LLONG              lAttachHandle;         // 分析进度句柄，唯一标识某一通道的分析进度
}NET_OUT_ATTACH_VIDEOANALYSE_STATE;

///////////////////////////////// IVS 服务器视频诊断模块 /////////////////////////////////
// 视频诊断上报结果检测类型定义
#define NET_DIAGNOSIS_DITHER                    "VideoDitherDetection"                       // 视频抖动检测 对应结构体(NET_VIDEO_DITHER_DETECTIONRESULT)
#define NET_DIAGNOSIS_STRIATION                 "VideoStriationDetection"                    // 视频条纹检测 对应结构体(NET_VIDEO_STRIATION_DETECTIONRESULT)
#define NET_DIAGNOSIS_LOSS                      "VideoLossDetection"                         // 视频丢失检测 对应结构体(NET_VIDEO_LOSS_DETECTIONRESULT)
#define NET_DIAGNOSIS_COVER                     "VideoCoverDetection"                        // 视频遮挡检测 对应结构体(NET_VIDEO_COVER_DETECTIONRESULT)
#define NET_DIAGNOSIS_FROZEN                    "VideoFrozenDetection"                       // 视频冻结检测 对应结构体(NET_VIDEO_FROZEN_DETECTIONRESULT)
#define NET_DIAGNOSIS_BRIGHTNESS                "VideoBrightnessDetection"                   // 视频亮度异常检测 对应结构体(NET_VIDEO_BRIGHTNESS_DETECTIONRESULT)
#define NET_DIAGNOSIS_CONTRAST                  "VideoContrastDetection"                     // 视频对比度异常检测 对应结构体(NET_VIDEO_CONTRAST_DETECTIONRESULT)
#define NET_DIAGNOSIS_UNBALANCE                 "VideoUnbalanceDetection"                    // 视频偏色检测 对应结构体(NET_VIDEO_UNBALANCE_DETECTIONRESULT)
#define NET_DIAGNOSIS_NOISE                     "VideoNoiseDetection"                        // 视频噪声检测 对应结构体(NET_VIDEO_NOISE_DETECTIONRESULT)
#define NET_DIAGNOSIS_BLUR                      "VideoBlurDetection"                         // 视频模糊检测 对应结构体(NET_VIDEO_BLUR_DETECTIONRESULT)
#define NET_DIAGNOSIS_SCENECHANGE               "VideoSceneChangeDetection"                  // 视频场景变化检测 对应结构体(NET_VIDEO_SCENECHANGE_DETECTIONRESULT)

enum NET_STATE_TYPE
{
    NET_EM_STATE_ERR,        // 其它
    NET_EM_STATE_NORMAL,     // "Normal" 正常 
    NET_EM_STATE_WARNING,    // "Warning" 警告
    NET_EM_STATE_ABNORMAL,   // "Abnormal" 异常
};
// 视频码流类型
enum NET_STREAM_TYPE
{
    NET_EM_STREAM_ERR,                      // 其它
    NET_EM_STREAM_MAIN,                     // "Main"-主码流
    NET_EM_STREAM_EXTRA_1,                  // "Extra1"-辅码流1
    NET_EM_STREAM_EXTRA_2,                  // "Extra2"-辅码流2
    NET_EM_STREAM_EXTRA_3,                  // "Extra3"-辅码流3
    NET_EM_STREAM_SNAPSHOT,                 // "Snapshot"-抓图码流
    NET_EM_STREAM_OBJECT,                   // "Object"-物体流
    NET_EM_STREAM_AUTO,                     // "Auto"-自动选择合适码流
    NET_EM_STREAM_PREVIEW,                  // "Preview"-预览裸数据码流
    NET_EM_STREAM_NONE,                     // 无视频码流(纯音频)
};
// 视频诊断结果类型
enum NET_VIDEODIAGNOSIS_RESULT_TYPE
{
    NET_EM_ROTATION,                        // "Rotation"    -视频轮巡分析结果
    NET_EM_REAL,                            // "Real" -实时视频分析结果
    NET_EM_NR_UNKNOW,                       // 未定义
};
//视频诊断错误原因
enum NET_VIDEODIAGNOSIS_FAIL_TYPE
{
    NET_EM_NO_ERROR,                        // 诊断成功
    NET_EM_DISCONNECT,                      // "Disconnect" - 末能连接设备
    NET_EM_CH_NOT_EXIST,                    // "ChannelNotExist" - 通道不存在
    NET_EM_LOGIN_OVER_TIME,                 // "LoginOverTime" - 登录超时
    NET_EM_NO_VIDEO,                        // "NoVideo" - 登录成功无视频
    NET_EM_NO_RIGHT,                        // "NoRight" - 无操作权限
    NET_EM_PLATFROM_LOGIN_FAILED,           // "PlatformLoginFailed" - 平台登入失败
    NET_EM_PLATFROM_DISCONNECT,             // "PlatformDisconnect" - 平台断开连接
    NET_EM_GET_STREAM_OVER_TIME,            // "GetStreamOverTime" - 获取码流超时
    NET_EM_NF_UNKNOW,                       //  其他原因，详见结构体里的失败原因描述
};

// 通用变长字符串以‘\0’结束
typedef struct tagNET_ARRAY
{
    DWORD          dwSize;                  // 此结构体大小
    char*          pArray;                  // 缓冲区 目前最小260字节，调用者申请内存 填充数据保证是'\0'结束
    DWORD          dwArrayLen;              // 缓冲空间长度
}NET_ARRAY;

// 视频诊断结果上报通用数据
typedef struct tagNET_VIDEODIAGNOSIS_COMMON_INFO
{
    DWORD                           dwSize;                             // 此结构体大小
    int                             nDiagnosisID;                       // 检测通道
    NET_ARRAY                       stProject;                          // 计划名称
    NET_ARRAY                       stTask;                             // 任务名称
    NET_ARRAY                       stProfile;                          // 参数表名称
    NET_ARRAY                       stDeviceID;                         // 设备唯一标志
    NET_TIME                        stStartTime;                        // 开始时间
    NET_TIME                        stEndTime;                          // 结束时间
    int                             nVideoChannelID;                    // 视频通道号 前端设备比如DVR,IPC的通道
    NET_STREAM_TYPE                 emVideoStream;                      // 视频码流
    NET_VIDEODIAGNOSIS_RESULT_TYPE  emResultType;                       // 诊断结果类型 
    BOOL                            bCollectivityState;                 // 诊断结果
    NET_VIDEODIAGNOSIS_FAIL_TYPE    emFailedCause;                      // 失败原因
    char                            szFailedCode[DH_COMMON_STRING_64];  // 失败原因描述
}NET_VIDEODIAGNOSIS_COMMON_INFO;

// 对应检测类型(NET_DIAGNOSIS_DITHER) 视频抖动检测结果 -- 画面变化 风吹，晃动，转动包括云台转动
typedef struct tagNET_VIDEO_DITHER_DETECTIONRESULT
{
    DWORD                dwSize;                         // 此结构体大小
    int                  nValue;                         // 检测结果量化值
    NET_STATE_TYPE       emState;                        // 检测结果状态  一般小于是正常，大于是异常，中间是警告
    int                  nDuration;                      // 状态持续时间  检测项持续检测时间 暂时无用
}NET_VIDEO_DITHER_DETECTIONRESULT;
// 对应检测类型(NET_DIAGNOSIS_STRIATION)视频条纹检测结果 -- 相机受到干扰出现异常条纹
typedef struct tagNET_VIDEO_STRIATION_DETECTIONRESULT
{
    DWORD                dwSize;                         // 此结构体大小
    int                  nValue;                         // 检测结果量化值
    NET_STATE_TYPE       emState;                        // 检测结果状态
    int                  nDuration;                      // 状态持续时间
}NET_VIDEO_STRIATION_DETECTIONRESULT;
// 对应检测类型(NET_DIAGNOSIS_LOSS)视频丢失检测结果 -- 断电 断线等造成的
typedef struct tagNET_VIDEO_LOSS_DETECTIONRESULT
{
    DWORD                dwSize;                         // 此结构体大小
    NET_STATE_TYPE       emState;                        // 检测结果状态
    int                  nDuration;                      // 状态持续时间
}NET_VIDEO_LOSS_DETECTIONRESULT;
// 对应检测类型(NET_DIAGNOSIS_COVER)视频遮挡检测结果 -- 相机被遮挡了
typedef struct tagNET_VIDEO_COVER_DETECTIONRESULT
{
    DWORD                dwSize;                         // 此结构体大小
    int                  nValue;                         // 检测结果量化值
    NET_STATE_TYPE       emState;                        // 检测结果状态
    int                  nDuration;                      // 状态持续时间
}NET_VIDEO_COVER_DETECTIONRESULT;
// 对应检测类型(NET_DIAGNOSIS_FROZEN)视频冻结检测结果 -- 画面不动多久为冻结
typedef struct tagNET_VIDEO_FROZEN_DETECTIONRESULT
{
    DWORD                dwSize;                         // 此结构体大小
    NET_STATE_TYPE       emState;                        // 检测结果状态
    int                  nDuration;                      // 状态持续时间
}NET_VIDEO_FROZEN_DETECTIONRESULT;
// 对应检测类型(NET_DIAGNOSIS_BRIGHTNESS)视频亮度异常检测结果 --以下是相机配置不正确的一些现象检测
typedef struct tagNET_VIDEO_BRIGHTNESS_DETECTIONRESULT
{
    DWORD                dwSize;                         // 此结构体大小
    int                  nValue;                         // 检测结果量化值
    NET_STATE_TYPE       emState;                        // 检测结果状态
    int                  nDuration;                      // 状态持续时间
}NET_VIDEO_BRIGHTNESS_DETECTIONRESULT;
// 对应检测类型(NET_DIAGNOSIS_CONTRAST)视频对比度异常检测结果
typedef struct tagNET_VIDEO_CONTRAST_DETECTIONRESULT
{
    DWORD                dwSize;                         // 此结构体大小
    int                  nValue;                         // 检测结果量化值
    NET_STATE_TYPE       emState;                        // 检测结果状态
    int                  nDuration;                      // 状态持续时间
}NET_VIDEO_CONTRAST_DETECTIONRESULT;
// 对应检测类型(NET_DIAGNOSIS_UNBALANCE)视频偏色异常检测结果
typedef struct tagNET_VIDEO_UNBALANCE_DETECTIONRESULT
{
    DWORD                dwSize;                         // 此结构体大小
    int                  nValue;                         // 检测结果量化值
    NET_STATE_TYPE       emState;                        // 检测结果状态
    int                  nDuration;                      // 状态持续时间
}NET_VIDEO_UNBALANCE_DETECTIONRESULT;
// 对应检测类型(NET_DIAGNOSIS_NOISE)视频噪声异常检测结果
typedef struct tagNET_VIDEO_NOISE_DETECTIONRESULT
{
    DWORD                dwSize;                         // 此结构体大小
    int                  nValue;                         // 检测结果量化值
    NET_STATE_TYPE       emState;                        // 检测结果状态
    int                  nDuration;                      // 状态持续时间
}NET_VIDEO_NOISE_DETECTIONRESULT;
// 对应检测类型(NET_DIAGNOSIS_BLUR)视频模糊异常检测结果
typedef struct tagNET_VIDEO_BLUR_DETECTIONRESULT
{
    DWORD                dwSize;                         // 此结构体大小
    int                  nValue;                         // 检测结果量化值
    NET_STATE_TYPE       emState;                        // 检测结果状态
    int                  nDuration;                      // 状态持续时间
}NET_VIDEO_BLUR_DETECTIONRESULT;
// 对应检测类型(NET_DIAGNOSIS_SCENECHANGE)视频场景变化检测结果
typedef struct tagNET_VIDEO_SCENECHANGE_DETECTIONRESULT
{
    DWORD                dwSize;                         // 此结构体大小
    int                  nValue;                         // 检测结果量化值
    NET_STATE_TYPE       emState;                        // 检测结果状态
    int                  nDuration;                      // 状态持续时间
}NET_VIDEO_SCENECHANGE_DETECTIONRESULT;

typedef struct tagNET_DIAGNOSIS_RESULT_HEADER
{
    DWORD                dwSize;                         // 此结构体大小

    char                 szDiagnosisType[MAX_PATH];      // 诊断类型，详见dhnetsdk.h中"视频诊断上报结果检测类型定义" 如NET_DIAGNOSIS_DITHER
    int                  nDiagnosisTypeLen;              // 该诊断类型结构体大小
}NET_DIAGNOSIS_RESULT_HEADER;

// cbVideoDiagnosis 回调参数类型
typedef struct tagNET_REAL_DIAGNOSIS_RESULT
{
    DWORD                dwSize;                         // 此结构体大小
    NET_VIDEODIAGNOSIS_COMMON_INFO* pstDiagnosisCommonInfo;  //视频诊断通用信息
    int                  nTypeCount;                     // 诊断结果数据诊断类型个数
    void*                pDiagnosisResult;               // 一次诊断结果数据，格式如NET_DIAGNOSIS_RESULT_HEADER+诊断类型1+NET_DIAGNOSIS_RESULT_HEADER+诊断类型2+...
    DWORD                dwBufSize;                      // 缓冲长度
}NET_REAL_DIAGNOSIS_RESULT;

//视频诊断结果上报回调函数
typedef int (CALLBACK *fRealVideoDiagnosis)(LLONG lDiagnosisHandle, NET_REAL_DIAGNOSIS_RESULT* pDiagnosisInfo, void* pBuf, int nBufLen, LDWORD dwUser);

// 接口 CLIENT_StartVideoDiagnosis 的输入参数
typedef struct tagNET_IN_VIDEODIAGNOSIS
{
    DWORD                dwSize;                         // 此结构体大小
    int                  nDiagnosisID;                   // 视频诊断ID，从0开始
    DWORD                dwWaitTime;                     // 接口超时等待时间
    fRealVideoDiagnosis  cbVideoDiagnosis;               // 视频诊断结果回调函数
    LDWORD               dwUser;                         // 用户自定义参数
}NET_IN_VIDEODIAGNOSIS;

// 接口 CLIENT_StartVideoDiagnosis 的输出参数
typedef struct tagNET_OUT_ATTACH_REALDIAGNOSIS
{
    DWORD                dwSize;                         // 此结构体大小
    LLONG                lDiagnosisHandle;               // 订阅句柄
}NET_OUT_VIDEODIAGNOSIS;

// 接口 CLIENT_StartFindDiagnosisResult 的输入参数
typedef struct tagNET_IN_FIND_DIAGNOSIS
{
    DWORD                dwSize;                         // 此结构体大小
    int                  nDiagnosisID;                   // 视频诊断ID，从0开始
    DWORD                dwWaitTime;                     // 接口超时等待时间
    NET_ARRAY            stuDeviceID;                    // 设备唯一标志,pArray:NULL表示不使用设备ID查询
    NET_TIME             stuStartTime;                   // 开始时间
    NET_TIME             stuEndTime;                     // 结束时间
    int                  nVideoChannel;                  // 视频通道号,-1:所有通道号
    int                  nTypeCount;                     // 诊断类型个数,0:不使用诊断类型查询
    NET_ARRAY*           pstDiagnosisTypes;              // 诊断类型数组，表示需要查询的诊断类型
    char                 szProjectName[MAX_PATH];        // 计划名称
} NET_IN_FIND_DIAGNOSIS;

// 接口 CLIENT_StartFindDiagnosisResult 的输出参数
typedef struct tagNET_OUT_FIND_DIAGNOSIS
{
    DWORD                dwSize;                         // 此结构体大小
    LLONG                lFindHandle;                    // 查询句柄
    DWORD                dwTotalCount;                   // 符合条件的总个数
}NET_OUT_FIND_DIAGNOSIS;

// 接口 CLIENT_DoFindDiagnosisResult 的输入参数
typedef struct tagNET_IN_DIAGNOSIS_INFO
{
    DWORD                dwSize;                         // 此结构体大小
    int                  nDiagnosisID;                   // 视频诊断ID，从0开始
    DWORD                dwWaitTime;                     // 接口超时等待时间
    int                  nFindCount;                     // 每次查询的视频诊断结果条数
    int                  nBeginNumber;                   // 查询起始序号 0<=beginNumber<= totalCount-1
}NET_IN_DIAGNOSIS_INFO;

// CLIENT_StartRealTimeProject 接口输入参数
typedef struct tagNET_IN_START_RT_PROJECT_INFO
{
    DWORD                dwSize;                         // 此结构体大小
    char*                pszProjectInfo;                 // 实时计划信息，通过调用dhconfigsdk.dll中接口CLIENT_PacketData封装得到
                                                         // 对应的封装命令为 CFG_CMD_VIDEODIAGNOSIS_REALPROJECT                      
}NET_IN_START_RT_PROJECT_INFO;

// CLIENT_StartRealTimeProject 接口输出参数
typedef struct tagNET_OUT_START_RT_PROJECT_INFO
{
    DWORD                dwSize;                         // 此结构体大小
}NET_OUT_START_RT_PROJECT_INFO;

// CLIENT_StopRealTimeProject 接口输入参数
typedef struct tagNET_IN_STOP_RT_PROJECT_INFO
{
    DWORD                dwSize;                         // 此结构体大小
    char*                pszProjectNames;                // 计划名称，以&&作为名字的分割符，示例：Project1&&Project2   
}NET_IN_STOP_RT_PROJECT_INFO; 

// CLIENT_StopRealTimeProject 接口输出参数
typedef struct tagNET_OUT_STOP_RT_PROJECT_INFO
{
    DWORD                dwSize;                         // 此结构体大小
}NET_OUT_STOP_RT_PROJECT_INFO;

// 车位灯信息
typedef struct tagNET_CARPORTLIGHT_INFO
{
    DWORD               dwSize;  
    NET_CARPORTLIGHT_TYPE emType;                        // 车位灯类型
    NET_CARPORTLIGHT_MODE emMode;                        // 车位灯亮灯方式
}NET_CARPORTLIGHT_INFO;

// 车位灯状态
typedef struct tagNET_CARPORTLIGHT_STATUS
{
    DWORD                dwSize;                         // 此结构体大小
    int                  nLightNum;                      // 车位灯数 
    NET_CARPORTLIGHT_INFO stuLights[DH_MAX_CARPORTLIGHT_NUM]; // 车位灯信息,数组中emType不能重复，一个红灯和一个绿灯
    int                  nFiringTime;                    // 状态启动时间,单位秒
    int                  nHoldTime;                      // 状态保持时间,单位秒，-1表示无限保持，0表示自行控制
}NET_CARPORTLIGHT_STATUS;

// 接口CLIENT_GetCarPortLightStatus的输入参数
typedef struct tagNET_IN_GET_CARPORTLIGHT_STATUS
{
    DWORD                dwSize;                         // 此结构体大小
    int                  nChannelId;                     // 通道号
}NET_IN_GET_CARPORTLIGHT_STATUS;

// 接口CLIENT_GetCarPortLightStatus的输出参数
typedef struct tagNET_OUT_GET_CARPORTLIGHT_STATUS
{
    DWORD                   dwSize;                      // 此结构体大小
    NET_CARPORTLIGHT_STATUS stuLightStatus;              // 车位灯状态
}NET_OUT_GET_CARPORTLIGHT_STATUS;

// 接口 CLIENT_SetCarPortLightStatus 的输入参数
typedef struct tagNET_IN_SET_CARPORTLIGHT_STATUS
{
    DWORD                   dwSize;                      // 此结构体大小
    int                     nChannelId;
    NET_CARPORTLIGHT_STATUS stuLightStatus;              // 车位灯状态
}NET_IN_SET_CARPORTLIGHT_STATUS;

// 接口 CLIENT_SetCarPortLightStatus 的输出参数
typedef struct tagNET_OUT_SET_CARPORTLIGHT_STATUS
{
    DWORD                dwSize;                         // 此结构体大小
    
}NET_OUT_SET_CARPORTLIGHT_STATUS;


typedef struct tagNET_DEV_VIDEODIAGNOSIS_MULTI_INFO
{
    DWORD                dwSize;                                // 此结构体大小

    NET_VIDEODIAGNOSIS_COMMON_INFO*       pstDiagnosisCommonInfo;//视频诊断通用信息  以下结构体指针需要调用者分配
    BOOL                 abDither;                              // 用于表示此次结果中这个诊断项是否有效
    NET_VIDEO_DITHER_DETECTIONRESULT*     pstDither;            // 视频抖动检测    
    BOOL                 abStration;
    NET_VIDEO_STRIATION_DETECTIONRESULT*  pstStration;          // 视频条纹检测    
    BOOL                 abLoss;
    NET_VIDEO_LOSS_DETECTIONRESULT*       pstLoss;              // 视频丢失检测    
    BOOL                 abCover;
    NET_VIDEO_COVER_DETECTIONRESULT*      pstCover;             // 视频遮挡检测    
    BOOL                 abFrozen;
    NET_VIDEO_FROZEN_DETECTIONRESULT*     pstFrozen;            // 视频冻结检测   
    BOOL                 abBrightness;
    NET_VIDEO_BRIGHTNESS_DETECTIONRESULT* pstBrightness;        // 视频亮度异常检测    
    BOOL                 abContrast;
    NET_VIDEO_CONTRAST_DETECTIONRESULT*   pstContrast;          // 视频对比度异常检测   
    BOOL                 abUnbalance;
    NET_VIDEO_UNBALANCE_DETECTIONRESULT*  pstUnbalance;         // 视频偏色检测    
    BOOL                 abNoise;
    NET_VIDEO_NOISE_DETECTIONRESULT*      pstNoise;             // 视频噪声检测    
    BOOL                 abBlur;
    NET_VIDEO_BLUR_DETECTIONRESULT*       pstBlur;              // 视频模糊检测    
    BOOL                 abSceneChange;
    NET_VIDEO_SCENECHANGE_DETECTIONRESULT* pstSceneChange;      // 视频场景变化检测
}NET_VIDEODIAGNOSIS_RESULT_INFO;

// 接口 CLIENT_DoFindDiagnosisResult 的输出参数
typedef struct tagNET_OUT_DIAGNOSIS_INFO
{
    DWORD                dwSize;                         // 此结构体大小

    int                  nInputNum;                      // 用户分配的NET_DEV_RESULT_VIDEODIAGNOSIS_INFO个数
    int                  nReturnNum;                     // 返回结果个数
    NET_VIDEODIAGNOSIS_RESULT_INFO*  pstDiagnosisResult; // 结果数据  结构体指针需要调用者分配
}NET_OUT_DIAGNOSIS_INFO;

///////////////////////////////// 主从式设备控制模块 //////////////////////////////////////////////////////
///////////////////////////////// CLIENT_OperateMasterSlaveDevice接口参数定义 /////////////////////////////////
#define        MASTERSLAVE_CMD_START                   "masterSlaveTracker.start"                   // 开启主从式跟踪器工作
#define        MASTERSLAVE_CMD_STOP                    "masterSlaveTracker.stop"                    // 停止主从式跟踪器工作
#define        MASTERSLAVE_CMD_MANUALTRACK             "masterSlaveTracker.manualSelectObjectTrack" // 手动选定目标跟踪
#define        MASTERSLAVE_CMD_POINTTRACK              "masterSlaveTracker.selectPointTrack"        // 定点跟踪
#define        MASTERSLAVE_CMD_GETCALIBPOINTS          "masterSlaveTracker.getCalibratePoints"      // 得到所有标定点
#define        MASTERSLAVE_CMD_CALIBRATE               "masterSlaveTracker.calibrate"               // 保存标定点
#define        MASTERSLAVE_CMD_ADDCALIBPOINT           "masterSlaveTracker.addCalibratePoint"       // 增加标定点
#define        MASTERSLAVE_CMD_REMOVECALIBPOINT        "masterSlaveTracker.removeCalibratePoint"    // 删除标定点
#define        MASTERSLAVE_CMD_MARKMAXZOOM             "masterSlaveTracker.markSceneMaxZoom"        // 标定场景最大跟踪倍率, 把当前倍率作为最大倍率

// 主从式设备点对
typedef struct __NET_MS_PAIRPOINTS
{
    int                nStructSize;
    DH_POINT           stMasterPoint;    // 主相机标定点，点的坐标归一化到[0,8192]区间
    DH_POINT           stSlavePoint;     // 从相机标定点，点的坐标归一化到[0,8192]区间
}NET_MS_PAIRPOINTS;
//MASTERSLAVE_CMD_START命令的输入结构体
typedef struct __NET_IN_MS_START
{
    int                nStructSize;
}NET_IN_MS_START;

//MASTERSLAVE_CMD_START命令的输出结构体
typedef struct __NET_OUT_MS_START
{
    int                nStructSize;
}NET_OUT_MS_START;

//MASTERSLAVE_CMD_STOP命令的输入结构体
typedef struct __NET_IN_MS_STOP
{
    int                nStructSize;
}NET_IN_MS_STOP;

//MASTERSLAVE_CMD_STOP命令的输出结构体
typedef struct __NET_OUT_MS_STOP
{
    int                nStructSize;
}NET_OUT_MS_STOP;

//MASTERSLAVE_CMD_MANUALTRACK命令的输入结构体
typedef struct __NET_IN_MS_MANUALTRACK
{
    int                nStructSize;
    DWORD              dwObject;          // -1 表示整个区域的任意位置物体, >=0表示指定的物体（可以从设备返回智能帧得到）
}NET_IN_MS_MANUALTRACK;

//MASTERSLAVE_CMD_MANUALTRACK命令的输出结构体
typedef struct __NET_OUT_MS_MANUALTRACK
{
    int                nStructSize;
}NET_OUT_MS_MANUALTRACK;

//MASTERSLAVE_CMD_POINTTRACK命令的输入结构体
typedef struct __NET_IN_MS_POINTTRACK
{
    int                nStructSize;
    DH_POINT           stTrackerPoint;    // 跟踪点，点的坐标归一化到[0,8192]区间 
}NET_IN_MS_POINTTRACK;

//MASTERSLAVE_CMD_POINTTRACK命令的输出结构体
typedef struct __NET_OUT_MS_POINTTRACK
{
    int                nStructSize;
}NET_OUT_MS_POINTTRACK;

//MASTERSLAVE_CMD_GETCALIBPOINTS命令的输入结构体
typedef struct __NET_IN_MS_GETCALIBPOINTS
{
    int                nStructSize;
}NET_IN_MS_GETCALIBPOINTS;

//MASTERSLAVE_CMD_GETCALIBPOINTS命令的输出结构体
typedef struct __NET_OUT_MS_GETCALIBPOINTS
{
    int                        nStructSize;
    int                        nPointsNum;                           // 实际标定点数
    NET_MS_PAIRPOINTS          stPairPoints[MAX_CALIBPOINTS_NUM];    // 标定坐标点组
}NET_OUT_MS_GETCALIBPOINTS;

//MASTERSLAVE_CMD_CALIBRATE命令的输入结构体
typedef struct __NET_IN_MS_CALIBRATE
{
    int                nStructSize;
}NET_IN_MS_CALIBRATE;

//MASTERSLAVE_CMD_CALIBRATE命令的输出结构体
typedef struct __NET_OUT_MS_CALIBRATE
{
    int                nStructSize;      
}NET_OUT_MS_CALIBRATE;

//MASTERSLAVE_CMD_ADDCALIBPOINT命令的输入结构体
typedef struct __NET_IN_MS_ADDCALIBPOINT
{
    int                        nStructSize;
    BOOL                       bSlavePointEn;        // 从相机标定点使能位, TURE设置从相机标定点有效；FASLE则无效, 设备自己获取当前的从相机标定点。
    NET_MS_PAIRPOINTS          stPairPoints;         // 主从相机定标点对
}NET_IN_MS_ADDCALIBPOINT;

//MASTERSLAVE_CMD_ADDCALIBPOINT命令的输出结构体
typedef struct __NET_OUT_MS_ADDCALIBPOINT
{
    int                nStructSize;
    DH_POINT           stPoint;      // 从标定点
}NET_OUT_MS_ADDCALIBPOINT;


//MASTERSLAVE_CMD_REMOVECALIBPOINT命令的输入结构体
typedef struct __NET_IN_MS_REMOVECALIBPOINT
{
    int                nStructSize;
    DH_POINT           stPoint;      // 主标定点
}NET_IN_MS_REMOVECALIBPOINT;

//MASTERSLAVE_CMD_REMOVECALIBPOINT命令的输出结构体
typedef struct __NET_OUT_MS_REMOVECALIBPOINT
{
    int                nStructSize;      
}NET_OUT_MS_REMOVECALIBPOINT;

//MASTERSLAVE_CMD_MARKMAXZOOM命令输入结构体
typedef struct __NET_IN_MS_MARKMAXZOOM
{
    int                nStructSize; 
}NET_IN_MS_MARKMAXZOOM;

//MASTERSLAVE_CMD_MARKMAXZOOM命令输出结构体
typedef struct __NET_OUT_MS_MARKMAXZOOM
{
    int                nStructSize; 
}NET_OUT_MS_MARKMAXZOOM;

///////////////////////////////// CLIENT_OperateCommDevice 接口参数定义 /////////////////////////////////
#define        COMMDEV_GET_EXTERNLDATA                            "devComm.getExternalData"        //获取串口外接数据    用于第三方通用数据

#define        MAX_EXTERN_DATA_LEN                2048

//COMMDEV_GET_EXTERNLDATA 输入参数
typedef struct __COMMDEV_IN_GET_EXTERNDATA
{
    DWORD        dwSize;

}COMMDEV_IN_GET_EXTERNDATA;

//COMMDEV_GET_EXTERNLDATA 输出参数
typedef struct __COMMDEV_OUT_GET_EXTERNDATA
{
    DWORD        dwSize;
    char         szGetData[MAX_EXTERN_DATA_LEN];                //串口外接设备采集数据(数据格式根据项目自定义)
}COMMDEV_OUT_GET_EXTERNDATA;


///////////////////////////////// CLIENT_OperateVideoAnalyseDevice 接口参数定义 /////////////////////////////////
#define     NET_SET_MODULESTATE                         "devVideoAnalyse.setModuleState"                        // 设置模块状态
#define     NET_TEST_WITH_SCREENPOINTS                  "devVideoAnalyse.testCalibrateWithScreenPoints"            // 根据屏幕坐标测试景深参数，得到的是两点之间的实际距离。在测试之前，需要先完成参数设置。
#define     NET_TEST_WITH_METRICLENGTH                  "devVideoAnalyse.testCalibrateWithMetricLength"            // 根据实际长度、起始点及方向点坐标，测试景深参数
#define     NET_GET_INTERNALOPTIONS                     "devVideoAnalyse.getInternalOptions"                    // 获取内部选项
#define     NET_TUNE_INTERNALOPTIONS                    "devVideoAnalyse.tuneInternalOptions"                    // 调试内部选项
#define     NET_RESET_INTERNALOPTIONS                   "devVideoAnalyse.resetInternalOptions"                    // 复位所有调试内部选项
#define     NET_SET_PTZ_PRESET_STATUS                   "devVideoAnalyse.setPtzPresetStatus"                    // 获取预置点信息

// 线段类型
enum NET_EM_LINETYPE
{
    NET_EM_HORIZONTAL,
    NET_EM_VERTICAL,
};

//云台定位信息报警
typedef struct
{
    int     nChannelID;                 // 通道号 
    int     nPTZPan;                    // 云台水平运动位置，有效范围：[0,3600]
    int     nPTZTilt;                   // 云台垂直运动位置，有效范围：[-1800,1800]
    int     nPTZZoom;                   // 云台光圈变动位置，有效范围：[0,128]
    BYTE    bState;                     // 云台运动状态, 0-未知 1-运动 2-空闲 
    BYTE    bAction;                    // 云台动作，0-预置点，1-线扫，2-巡航，3-巡迹，4-水平旋转
    BYTE    bFocusState;                // 云台聚焦状态, 0-未知, 1-运动状态, 2-空闲
    BYTE    bEffectiveInTimeSection;    //在时间段内预置点状态是否有效
                                        //如果当前上报的预置点是时间段内的预置点，则为1，其他情况为0
    int     nPtzActionID;               // 巡航ID号
    DWORD   dwPresetID;                 // 云台所在预置点编号
    float   fFocusPosition;             // 聚焦位置
    BYTE    bZoomState;                 // 云台ZOOM状态，0-未知，1-ZOOM，2-空闲
    BYTE    bReserved[3];               // 对齐
    DWORD   dwSequence;                 // 包序号，用于校验是否丢包
    DWORD   dwUTC;                      // 对应的UTC(1970-1-1 00:00:00)秒数。
    int     reserved[249];              // 保留字段
}DH_PTZ_LOCATION_INFO;

// NET_SET_PTZ_PRESET_STATUS
typedef struct __NET_IN_PTZ_PRESET_STATUS
{
    DWORD                    dwSize;
    DH_PTZ_LOCATION_INFO     stPTZStatus;
}NET_IN_PTZ_PRESET_STATUS;

typedef struct __NET_OUT_PTZ_PRESET_STATUS
{
    DWORD    dwSize;
}NET_OUT_PTZ_PRESET_STATUS;


// NET_TEST_WITH_SCREENPOINTS
typedef struct __NET_IN_CALIBRATE_BY_POINTS
{
    DWORD               dwSize;                 // 此结构体大小

    DH_POINT            stStartPoint;           // 线段起点坐标    点的坐标坐标归一化到[0,8191]区间。
    DH_POINT            stEndPoint;             // 终止点坐标    点的坐标坐标归一化到[0,8191]区间。    
    NET_EM_LINETYPE     emType;                 // 线段类型    em_Horizontal("Horizontal") 水平线段 em_Vertical("Vertical")垂直线段
}NET_IN_CALIBRATE_BY_POINTS;
typedef struct __NET_OUT_CALIBRATE_BY_POINTS
{
    DWORD               dwSize;                 // 此结构体大小

    double              dlength;                // 两点之间的实际长度    单位为米
}NET_OUT_CALIBRATE_BY_POINTS;

// NET_TEST_WITH_METRICLENGTH
typedef struct __NET_IN_CALIBRATE_BY_LENGTH
{
    DWORD               dwSize;                 // 此结构体大小

    double              nLength;                // 两点之间的实际长度,米为单位
    DH_POINT            stStartPoint;           // 线段起点坐标,点的坐标坐标归一化到[0,8191]区间。
    DH_POINT            stDirection;            // 线段方向点坐标,只对垂直线段有效。点的坐标坐标归一化到[0,8191]区间。
    NET_EM_LINETYPE     emType;                 // 线段类型,em_Horizontal("Horizontal") 水平线段 em_Vertical("Vertical")垂直线段                
}NET_IN_CALIBRATE_BY_LENGTH;

typedef struct __NET_OUT_CALIBRATE_BY_LENGTH
{
    DWORD               dwSize;                 // 此结构体大小
    
    DH_POINT            stEndPoint;             // 线段终点屏幕坐标    点的坐标坐标归一化到[0,8191]区间。    
}NET_OUT_CALIBRATE_BY_LENGTH;

typedef struct __NET_INTERNAL_OPTION
{
    DWORD               dwSize;                 // 此结构体大小

    int                 nIndex;                 // 选项序号
    NET_ARRAY           stKey;                  // 选项名称，包括‘\0’共256字节,加密数据
    int                 nValue;                 // 选项取值
    int                 nMinValue;              // 最小值
    int                 nMaxValue;              // 最大值
}NET_INTERNAL_OPTION;

// 调试内部选项 NET_GET_INTERNALOPTIONS
typedef struct __NET_IN_GETINTERNAL_OPTIONS
{
    DWORD               dwSize;                 // 此结构体大小
}NET_IN_GETINTERNAL_OPTIONS;

typedef struct __NET_OUT_GETINTERNAL_OPTIONS
{
    DWORD                dwSize;                // 此结构体大小

    int                  nTotalOptionNum;       // 选项个数 最大值查询能力
    int                  nReturnOptionNum;      // 返回的实际选项个数
    NET_INTERNAL_OPTION* pstInternalOption;     // 选项列表 调用者分配地址
}NET_OUT_GETINTERNAL_OPTIONS;

// NET_TUNE_INTERNALOPTIONS
typedef struct __NET_IN_TUNEINTERNAL_OPTION
{
    DWORD                dwSize;                // 此结构体大小
    int                  nOptionCount;          // 选项个数
    NET_INTERNAL_OPTION* pstInternalOption;     // 选项列表 能力来体现个数
}NET_IN_TUNEINTERNAL_OPTION;
typedef struct __NET_OUT_TUNEINTERNAL_OPTION
{
    DWORD               dwSize;                 // 此结构体大小
}NET_OUT_TUNEINTERNAL_OPTION;

// NET_RESET_INTERNALOPTIONS
typedef struct __NET_IN_RESETINTERNAL_OPTION
{
    DWORD               dwSize;                 // 此结构体大小
}NET_IN_RESETINTERNAL_OPTION;
typedef struct __NET_OUT_RESETINTERNAL_OPTION
{
    DWORD               dwSize;                 // 此结构体大小
}NET_OUT_RESETINTERNAL_OPTION;

// NET_SET_MODULESTATE
enum NET_EM_MODULESTATE
{
    NET_EM_MODULESTATE_OK,
    NET_EM_MODULESTATE_PAUSE,
};
typedef struct __NET_IN_SETMODULESTATE
{
    DWORD               dwSize;                 // 此结构体大小
    NET_EM_MODULESTATE  emState;                // 0-正常工作，1-暂停，再次切换到正常后画面可能已经发生变化，需要重建背景。
    int                 nIndex;                 // 模块编号    -1指所有模块
}NET_IN_SETMODULESTATE;
typedef struct __NET_OUT_SETMODULESTATE
{
    DWORD               dwSize;                 // 此结构体大小
}NET_OUT_SETMODULESTATE;

/////////////////////////////////CLIENT_DeleteDevConfig 接口参数/////////////////////////////////
/*
 * CLIENT_DeleteDevConfig 输入输出参数
 */

enum NET_EM_CONFIGOPTION
{
    NET_EM_CONFIGOPTION_OK,
    NET_EM_CONFIGOPTION_NEEDRESTART,
    NET_EM_CONFIGOPTION_NEEDREBOOT=2,
    NET_EM_CONFIGOPTION_WRITEFILEERROR=4,
    NET_EM_CONFIGOPTION_CAPSNOTSUPPORT=8,
    NET_EM_CONFIGOPTION_VALIDATEFAILED=16,
};

typedef struct tagNET_IN_DELETECFG
{
    DWORD         dwSize;                       // 结构体大小
    char*         szCommand;                    // 配置命令
}NET_IN_DELETECFG;
typedef struct tagNET_OUT_DELETECFG
{
    DWORD         dwSize;                       // 结构体大小
    int           nError;                       // 设备返回的错误码
    int           nRestart;                     // 设备是否重启
    DWORD         dwOptionMask;                 // 选项 具体见枚举NET_EM_CONFIGOPTION
}NET_OUT_DELETECFG;

/////////////////////////////////CLIENT_GetMemberNames 接口参数/////////////////////////////////
/*
 * CLIENT_GetMemberNames 输入输出参数
 */
typedef struct tagNET_IN_MEMBERNAME
{
    DWORD         dwSize;                       // 结构体大小
    char*         szCommand;                    // 配置命令
}NET_IN_MEMBERNAME;
typedef struct tagNET_OUT_MEMBERNAME
{
    DWORD         dwSize;                       // 结构体大小
    int           nError;                       // 设备返回的错误码
    int           nRestart;                     // 设备是否重启
    int           nTotalNameCount;              // 名称个数 通过能力集得到，调用者填写
    int           nRetNameCount;                // 返回的实际名称个数
    NET_ARRAY*    pstNames;                     // 名称数组 调用者申请内存，个数是nTotalNameCount个
}NET_OUT_MEMBERNAME;

////////////////////////////////////视频浓缩相关结构体//////////////////////////////////////
// 标尺类型
enum NET_EM_STAFF_TYPE
{
    NET_EM_STAFF_TYPE_ERR,
    NET_EM_STAFF_TYPE_HORIZONTAL,               // "Horizontal" 水平线段
    NET_EM_STAFF_TYPE_VERTICAL,                 // "Vertical" 垂直线段
    NET_EM_STAFF_TYPE_ANY,                      // "Any" 任意线段
    NET_EM_STAFF_TYPE_CROSS,                    // "Cross" 垂直面交线段
};

// 区域类型
enum NET_EM_CALIBRATEAREA_TYPE
{
    NET_EM_CALIBRATEAREA_TYPE_ERR,
    NET_EM_CALIBRATEAREA_TYPE_GROUD,            // "Groud" : 地面，需要N条竖直线段+M条水平线段（（N=3，M=1）；（N=2，M=2）；今后扩展）。
    NET_EM_CALIBRATEAREA_TYPE_HORIZONTAL,       // "Horizontal"  : 水平面，需要水平面上一点到地面点的投影垂直线段。        
    NET_EM_CALIBRATEAREA_TYPE_VERTICAL,         // "Vertical" : 垂直面，需要垂直面与地面的交线。
    NET_EM_CALIBRATEAREA_TYPE_ANY,              // "Any" 任意平面，N条竖直线段，及每条长度（N=3，及今后扩展）。
};

// 浓缩后的输出资料子类型
enum NET_EM_OUTPUT_SUB_TYPE
{
    NET_EM_OUTPUT_SUB_TYPE_ERR,
    NET_EM_OUTPUT_SUB_TYPE_NORMAL,              // 普通播放速度（父类型为浓缩视频时有效）
    NET_EM_OUTPUT_SUB_TYPE_SYNOPSIS,            // 按浓缩后的播放速度（父类型为浓缩视频时有效），在没有物体时快放，在物体出现时按正常速度播放
};

// 标尺信息
typedef struct tagNET_STAFF_INFO
{
    DH_POINT            stuStartLocation;       // 起始坐标点
    DH_POINT            stuEndLocation;         // 终止坐标点
    float               nLenth;                 // 实际长度,单位米
    NET_EM_STAFF_TYPE   emType;                 // 标尺类型
}NET_STAFF_INFO;

// 标定区域,普通场景使用
typedef struct tagNET_CALIBRATEAREA_INFO
{
    int                     nLinePoint;                         // 水平方向标尺线顶点数
    DH_POINT                stuLine[DH_MAX_POLYLINE_NUM];       // 水平方向标尺线
    float                   fLenth;                             // 实际长度
    DH_POLY_POINTS          stuArea;                            // 区域
    int                     nStaffNum;                          // 垂直标尺数
    NET_STAFF_INFO          stuStaffs[DH_MAX_STAFF_NUM];        // 垂直标尺         
    NET_EM_CALIBRATEAREA_TYPE emType;                           // 区域类型
}NET_CALIBRATEAREA_INFO;

typedef struct tagNET_LOCALFILE_INFO
{
    DWORD               dwSize;
    char                szFilePath[MAX_PATH];               // 文件绝对路径
}NET_LOCALFILE_INFO;

typedef struct tagNET_REMOTEFILE_INFO
{
    DWORD               dwSize;
    char                szIP[MAX_PATH];                     // 远程设备IP
    unsigned int        nPort;                              // 远程设备端口
    char                szName[DH_MAX_NAME_LEN];            // 登陆远程设备用户名
    char                szPassword[DH_MAX_NAME_LEN];        // 登陆远程设备密码
    BYTE                byProtocolType;                     // 远程设备使用的协议类型，2-私有二代，3-私有三代
    BYTE                byReserved[3];                      // 字节对齐
    char                szFilePath[MAX_PATH];               // 文件绝对路径，byProtocolType为3时有效
    int                 nStartCluster;                      // 起始簇号，byProtocolType为2时有效
    int                 nDriverNo;                          // 盘号，byProtocolType为2时有效
}NET_REMOTEFILE_INFO;

// 文件位置信息
typedef struct tagNET_FILEPATH_INFO
{
    DWORD               dwSize;
    BOOL                bFileType;                          // TRUE: 服务器本地文件; FALSE: 远程设备文件
    NET_LOCALFILE_INFO  stuLocalFile;                       // 本地文件信息, bFileType==TRUE有效
    NET_REMOTEFILE_INFO stuRemoteFile;                      // 远程文件信息, bFileType==FALSE有效
}NET_FILEPATH_INFO;

// 全局参数
typedef struct tagNET_GLOBAL_INFO
{
    DWORD                   dwSize;
    char                    szSceneType[DH_MAX_NAME_LEN];           // 应用场景，只支持"Normal"
    int                     nStaffNum;                              // 标尺数
    NET_STAFF_INFO          stuStaffs[DH_MAX_STAFF_NUM];            // 标尺    
    int                     nCalibrateAreaNum;                      // 标定区域数
    NET_CALIBRATEAREA_INFO  stuCalibrateArea[DH_MAX_CALIBRATEBOX_NUM]; // 标定区域(若该字段不存在，则以整幅场景为标定区域)
    int                     nJitter;                                // 摄像机抖动率 : 摄像机抖动率，取值0-100，反应静止摄像机抖动程度，抖动越厉害，值越大。
    BOOL                    bDejitter;                              // 是否开启去抖动模块
}NET_GLOBAL_INFO;

// 模块参数
typedef struct tagNET_MODULE_INFO
{
    DWORD               dwSize;                                     // 该结构体大小
    BYTE                bSensitivity;                               // 灵敏度,取值1-10，值越小灵敏度越低
    BYTE                bReserved[3];
    int                 nDetectRegionPoint;                         // 检测区域顶点数
    DH_POINT            stuDetectRegion[DH_MAX_POLYGON_NUM];        // 检测区域
    int                 nExcludeRegionNum;                          // 排除区域数
    DH_POLY_POINTS      stuExcludeRegion[DH_MAX_EXCLUDEREGION_NUM]; // 排除区域
}NET_MODULE_INFO;

// 物体过滤信息
typedef struct tagNET_OBJFILTER_INFO
{
    DWORD               dwSize;                             // 该结构体大小
    NET_TIME            stuStartTime;                       // 开始时间
    NET_TIME            stuEndTime;                         // 结束时间
    char                szObjectType[DH_MAX_NAME_LEN];      // 物体类型,支持以下:
                                                            //"Unknown", "Human", "Vehicle",
                                                            //"Fire", "Smoke", "Plate", "HumanFace", "Container", "Animal", "TrafficLight", "PastePaper", "HumanHead", "Entity"
    char                szObjectSubType[64];                // 物体子类别，根据不同的物体类型，可以取以下子类型：
                                                            // Vehicle Category:"Unknown"  未知,"Motor" 机动车,"Non-Motor":非机动车,"Bus": 公交车,"Bicycle" 自行车,"Motorcycle":摩托车
                                                            // Plate Category："Unknown" 未知,"Normal" 蓝牌黑牌,"Yellow" 黄牌,"DoubleYellow" 双层黄尾牌,"Police" 警牌"Armed" 武警牌,
                                                            // "Military" 部队号牌,"DoubleMilitary" 部队双层,"SAR" 港澳特区号牌,"Trainning" 教练车号牌
                                                            // "Personal" 个性号牌,"Agri" 农用牌,"Embassy" 使馆号牌,"Moto" 摩托车号牌,"Tractor" 拖拉机号牌,"Other" 其他号牌
                                                            // HumanFace Category:"Normal" 普通人脸,"HideEye" 眼部遮挡,"HideNose" 鼻子遮挡,"HideMouth" 嘴部遮挡
    DWORD               dwRGBMainColor[DH_MAX_COLOR_NUM];   // 物体主要颜色，物体为人时表示上半身颜色；按字节表示，分别为红、绿、蓝和透明度,例如:RGB值为(0,255,0),透明度为0时, 其值为0x00ff0000
    DWORD               dwLowerBodyColor[DH_MAX_COLOR_NUM]; // 物体为人时表示下半身颜色；按字节表示，分别为红、绿、蓝和透明度,例如:RGB值为(0,255,0),透明度为0时, 其值为0x00ff0000
    int                 nMinSize;                           // 物体最小尺寸, m
    int                 nMaxSize;                           // 物体最大尺寸, m
    int                 nMinSpeed;                          // 最小速度, km/h
    int                 nMaxSpeed;                          // 最大速度, km/h
    DWORD               dwRGBMainColorNum;                  // 当物体类型为人，标志dwRGBMainColor有效的颜色种类数
    DWORD               dwLowerBodyColorNum;                // 当物体类型为人且bRGBMainColor==true，标志下半身有效的颜色种类数
    BOOL                bRGBMainColor;                      // true-dwRGBMainColor表示上半身颜色,dwLowerBodyColor表示下半身颜色; false-dwRGBMainColor表示人主要颜色,dwLowerBodyColor无效
}NET_OBJFILTER_INFO;

// 规则参数
typedef struct tagNET_VIDEOSYNOPSISRULE_INFO
{
    DWORD               dwSize;                             // 该结构体大小
    BYTE                byOutputType;                       // 浓缩后输出资料的类型,1-视频大纲(一组快照);2-浓缩视频;3-既有快照又有视频
    BYTE                byDensity;                          // 密度, 1-10, 值越大, 浓缩密度越高
    bool                bShowTime;                          // 浓缩结果是否显示时标
    bool                bShowBox;                           // 浓缩结果是否显示物标
    bool                bEnableRecordResult;                // 浓缩结果是否记录入数据库
    BYTE                byReserved[3];
    NET_OBJFILTER_INFO  stuFilter[MAX_OBJFILTER_NUM];       // 物体过滤信息
    DWORD               dwObjFilterNum;                     // 物体过滤信息数目

    // NET_OUT_QUERY_VIDEOSYNOPSIS中，按照CFG_CMD_ANALYSERULE命令调用dhconfigsdk.dll中接口CLIENT_ParseData解析，得到对应的结构体，这时要先分配足够内存
    // NET_IN_ADD_VIDEOSYNOPSIS中，按照CFG_CMD_ANALYSERULE命令调用dhconfigsdk.dll中接口CLIENT_PacketData封装，得到此信息
    char*               szAnalyseRuleInfo;                  // JSON封装规则信息
    int                 nBufferLen;                         // NET_OUT_QUERY_VIDEOSYNOPSIS用时，申请的szAnalyseRuleInfo长度
    BOOL                bCustomResolution;                  // 自定义分辨率使能, TRUE-分辨率由emResolution确定, FALSE-根据原始视频分辨率生产浓缩视频
    CAPTURE_SIZE        emResolution;                       // 分辨率, bCustomResolution为TRUE才有效
    BOOL                bEnableMaxUsedCPU;                  // 是否最大化占有需求的CPU资源
    BOOL                bEnableSmoothBorder;                // 是否平滑目标边框
    NET_EM_OUTPUT_SUB_TYPE emOutputSubType;                 // 浓缩后输出资料的子类型，详见NET_EM_OUTPUT_SUB_TYPE
    int                 nExtractFrameRate;                  // 浓缩视频的抽帧速率    1-32，值越大，抽帧速率越高，客户端呈现的播放速度越快
                                                            // 该字段仅在浓缩后的输出资料子类型(emOutputSubType)是NET_EM_OUTPUT_SUB_TYPE_SYNOPSIS有效 
}NET_VIDEOSYNOPSISRULE_INFO;

// 添加浓缩视频任务输入参数
typedef struct tagNET_IN_ADD_VIDEOSYNOPSIS
{
    DWORD                   dwSize;                         // 该结构体大小
    NET_FILEPATH_INFO*      pFilePathInfo;                  // 文件位置信息，用户分配空间
    DWORD                   dwFileCount;                    // 有效文件个数
    NET_GLOBAL_INFO         stuGlobalInfo;                  // 全局信息
    NET_MODULE_INFO         stuModuleInfo;                  // 模块信息
    NET_VIDEOSYNOPSISRULE_INFO stuRuleInfo;                 // 规则信息
    unsigned int        nWaitTime;                          // 等待超时时间，单位ms
}NET_IN_ADD_VIDEOSYNOPSIS;

// 添加浓缩视频任务输出参数
typedef struct tagNET_OUT_ADD_VIDEOSYNOPSIS
{
    DWORD               dwSize;                             // 该结构体大小
    DWORD*              pnTaskID;                           // TaskID数组，用户分配空间.按顺序一一对应添加任务的文件;等于0表示对应任务添加失败
    DWORD               nTaskIDCount;                       // TaskID个数
}NET_OUT_ADD_VIDEOSYNOPSIS;

// 暂停视频浓缩任务输入参数
typedef struct tagNET_IN_PAUSE_VIDEOSYNOPSIS
{
    DWORD               dwSize;                             // 该结构体大小
    BOOL                bPause;                             // TRUE-表示暂停任务   FALSE-表示恢复任务 
    DWORD*              pnTaskID;                           // TaskID数组，用户分配空间
    DWORD               nTaskIDCount;                       // TaskID个数
    DWORD               nWaitTime;                          // 等待超时时间，单位ms
}NET_IN_PAUSE_VIDEOSYNOPSIS;

// 移除视频浓缩任务输入参数
typedef struct tagNET_IN_REMOVE_VIDEOSYNOPSIS
{
    DWORD                dwSize;                            // 该结构体大小
    DWORD*               pnTaskID;                          // TaskID数组，用户分配空间
    DWORD                nTaskIDCount;                      // TaskID个数
    DWORD                nWaitTime;                         // 等待超时时间，单位ms
}NET_IN_REMOVE_VIDEOSYNOPSIS;

// 视频浓缩返回的物体信息
typedef struct tagNET_REAL_SYNOPSIS_OBJECT_INFO
{
    DWORD               dwSize;
    
    DWORD               dwTaskID;                       // 当前物体对应的任务ID
    DH_MSG_OBJECT       stuObjectInfo;                  // 物体具体信息
}NET_REAL_SYNOPSIS_OBJECT_INFO;

typedef struct tagNET_REAL_SYNOPSIS_STATE_INFO
{
    DWORD           dwSize;
    
    DWORD           dwTaskID;                           // 任务ID   
    int             nObjectNum;                         // 目前浓缩过程中已发现的物体数量
    int             nTaolProgress;                      // 当前浓缩源（整个过程的，含下载、准备、浓缩）的完成进度,0~100
    char            szState[DH_MAX_SYNOPSIS_STATE_NAME];// 对应视频浓缩状态,"Downloading"-正在下载","Synopsising"-正在浓缩",
                                                        // "DownloadFailed"-下载失败","DownloadSucceeded"-下载成功
                                                        // "SynopsisFailed"-浓缩失败","Succeeded"-浓缩成功
                                                        // "DownloadPause"-下载暂停,"SynopsisPause"-浓缩暂停
    int             nProgressOfCurrentState;            // 当前浓缩步骤对应的完成进度，0~100
    char            szFailedCode[DH_MAX_STRING_LEN];    // 失败码，szState="SynopsisFailed"有效
                                                        // "OutOfMemory" 内存不足;
                                                        // "TooMany_TargetInVideo"  整个视频目标数过多;
                                                        // "InvalidFilePointer" 文件指针无效;
                                                        // "InvalidFilePath" 文件路径无效;
                                                        // "CreateDirectoryFailed"  创建文件夹路径失败;
                                                        // "WriteDataFailed" 写Tube中间文件失败
                                                        // "DataSizeTooLarge" Tube文件太大
                                                        // "Detect_Nothing" 场景中无运动目标
                                                        // "OpenDataFailed" 打开中间文件失败
                                                        // "InvalidSynopsisBackgroud" 浓缩背景无效
                                                        // "ColorRetrieval" 错误的颜色检索配置
                                                        // "UnsupportRuleType" 不支持的规则类型
                                                        // "RuleNumberExceedLimit" 规则数超限
                                                        // "NoFunctionCfgInfo" 指定了相应功能但没有配置信息
                                                        // "FunctionNumberExceedLimit" 每条规则的功能数目数量超限
                                                        // "PointsExceedLimit" 线或者区域的点数超限
                                                        // "BadFunctionType" 错误的功能类型
                                                        // "RulePointNumber" 规则点数错误
                                                        // "MaskRegionNumberExceedLimit" 屏蔽区域数量超限
                                                        // "CameraSceneSwitch" 相机场景切换
                                                        // "TooManyTargeInFrame" 单帧中目标数过多
                                                        // "InalidSynopsisDesity" 浓缩密度无效
                                                        // "ExtrackColorFeatureFailed" 提取颜色特征失败
                                                        // "JpegEncodeFrameFailed" Jpeg编码失败
                                                        // "JpegParamRestFailed" Jpeg重置编码参数失败
                                                        // "JpegDecodeFrameFailed" Jpeg解码失败
                                                        // "RetrieveObjectIdInvalid" 检索目标ID无效
                                                        // "RetrieveImageInvalid" 检索图像无效
                                                        // "NetworkAnomaly" 映射盘网络异常
                                                        // "ObjectNumberLimit" 超过分析目标数目限制
                                                        // "CreateChannelFailed" 创建通道失败
                                                        // "ReadUGFileFailed" 读取UG文件失败
                                                        // "GetSynopsisInfoFailed" 获取浓缩视频信息失败
                                                        // "ObjectNumberExceedLimit" 场景中目标数目超过限制
                                                        // "RebuildBackgroudFailed" 重建背景失败
                                                        // "NotExistMiddleFile" 中间文件不存在
                                                        // "NotExistSourceFile" 原始文件不存在
                                                        // "NotDog" 没有加密狗
                                                        // "NotEnoughFreeDisk" 磁盘空间不够
                                                        // "StartDecodeFail" 开始解码失败
                                                        // "DecodeTimeOut" 解码等待超时
                                                        // "EncodeTimeOut" 编码等待超时
                                                        // "ExactTimeOut" 提取快照等待超时
                                                        // "ReadMidlleFileFail" 读取中间文件失败
                                                        // "ExactPictureFail" 提取图片失败
}NET_REAL_SYNOPSIS_STATE_INFO;

//视频浓缩物体信息实时回调函数
typedef int (CALLBACK *fVideoSynopsisObjData)(LLONG lRealLoadHandle, NET_REAL_SYNOPSIS_OBJECT_INFO* pSynopsisObjectInfo, void* pBuf, int nBufLen, LDWORD dwUser, void* pReserved);

//视频浓缩进度状态实时回调函数
typedef int (CALLBACK *fVideoSynopsisState)(LLONG lRealLoadHandle, NET_REAL_SYNOPSIS_STATE_INFO* pSynopsisStateInfos, int nInfoCount, LDWORD dwUser, void* pReserved);

// CLIENT_RealLoadObjectData接口参数定义
typedef struct tagNET_IN_REALLOAD_OBJECTDATA
{
    DWORD               dwSize;                         // 结构体大小   
    int                 nTaskIDNum;                     // 任务ID个数
    DWORD               *pTaskIDs;                      // 具体任务ID
    BOOL                bNeedPicFile;                   // 是否下载对应的图片文件 
    int                 nWaitTime;                      // 等待时间，单位ms
    fVideoSynopsisObjData cbVideoSynopsisObjData;       // 视频浓缩物体信息实时回调函数指针
    LDWORD         dwUser;
}NET_IN_REALLOAD_OBJECTDATA;

typedef struct tagNET_OUT_REALLOAD_OBJECTDATA
{
    DWORD               dwSize;                         // 结构体大小
    LLONG               lRealLoadHandle;                // 接口返回的订阅句柄，可唯一标识某个订阅
}NET_OUT_REALLOAD_OBJECTDATA;

// CLIENT_StopLoadObjectData接口参数定义
typedef struct tagNET_IN_STOPLOAD_OBJECTDATA
{
    DWORD               dwSize;
    int                 nTackIDNum;                     // 任务ID个数
    DWORD               *pTaskIDs;                      // 具体任务ID  
}NET_IN_STOPLOAD_OBJECTDATA;

// CLIENT_RealLoadSynopsisState接口参数定义
typedef struct tagNET_IN_REALLAOD_SYNOPSISSTATE
{
    DWORD               dwSize;                         // 结构体大小  
    int                 nTaskIDNum;                     // 任务ID个数
    DWORD               *pTaskIDs;                      // 具体任务ID
    int                 nWaitTime;                      // 等待时间，单位ms
    fVideoSynopsisState cbVideoSynopsisState;           // 视频浓缩物体信息实时回调函数指针
    LDWORD         dwUser;
}NET_IN_REALLAOD_SYNOPSISSTATE;

typedef struct tagNET_OUT_REALLOAD_SYNOPSISSTATE
{
    DWORD               dwSize;                         // 结构体大小    
    LLONG               lRealLoadHandle;                // 接口返回的下载句柄，可唯一标识某个下载
}NET_OUT_REALLOAD_SYNOPSISSTATE;

// CLIENT_StopLoadSynopsisState接口参数定义
typedef struct tagNET_IN_STOPLOAD_SYNOPSISSTATE
{
    DWORD               dwSize;   
    int                 nTackIDNum;                     // 任务ID个数
    DWORD               *pTaskIDs;                      // 具体任务ID  
}NET_IN_STOPLOAD_SYNOPSISSTATE;

// 浓缩视频信息的查找类型
typedef enum tagEM_VIDEOSYNOPSIS_QUERY_TYPE
{
    EM_VIDEOSYNOPSIS_TASK,                              // 任务信息
    EM_VIDEOSYNOPSIS_OBJ,                               // 物体对应的快照
}EM_VIDEOSYNOPSIS_QUERY_TYPE;

// 查询浓缩视频的任务信息的条件
typedef struct tagNET_QUERY_VSTASK_INFO
{
    DWORD                dwSize;                        // 该结构体大小
    DWORD                dwTaskID;                      // 该任务ID，为0时表示查询所有任务
}NET_QUERY_VSTASK_INFO;

// 查询浓缩视频任务中物体信息的条件
typedef struct tagNET_QUERY_VSOBJECT_INFO
{
    DWORD                dwSize;                         // 该结构体大小
    DWORD*               pdwTaskID;                      // 物体所在任务的ID，为-1表示查询所有任务
    DWORD                dwTaskIDCount;                  // 有效的任务数目
    DH_MSG_OBJECT        stuObjInfo;                     // 物体信息，objectID为非0时表示查询该任务中所有物体
}NET_QUERY_VSOBJECT_INFO;

//--CLIENT_QueryVideoSynopsisInfo接口输入参数定义
typedef struct tagNET_IN_QUERY_VIDEOSYNOPSIS
{
    DWORD                dwSize;                         // 该结构体大小
    EM_VIDEOSYNOPSIS_QUERY_TYPE emQueryType;             // 查找类型
    DWORD                dwCount;                        // 查询的条数
    DWORD                dwBeginNumber;                  // 查询起始序号    
    void*                pQueryInfo;                     // 查询条件信息，用户分配空间；
                                                         // 如果emQueryType==EM_VIDEOSYNOPSIS_TASK，对应NET_QUERY_VSTASK_INFO
                                                         // 如果emQueryType==EM_VIDEOSYNOPSIS_OBJ，对应NET_QUERY_VSOBJECT_INFO

    DWORD                dwWaitTime;                     // 等待超时时间，单位ms
}NET_IN_QUERY_VIDEOSYNOPSIS;

// 查询到的每个浓缩视频任务的信息
typedef struct tagNET_VSTASK_INFO
{
    DWORD                       dwSize;                             // 该结构体大小
    DWORD                       dwTaskID;                           // 任务ID
    NET_MODULE_INFO             stuModuleInfo;                      // 模块信息
    NET_VIDEOSYNOPSISRULE_INFO  stuRuleInfo;                        // 任务的规则信息
    NET_GLOBAL_INFO             stuGlobalInfo;                      // 全局参数
    NET_TIME                    stuCreateTime;                      // 任务的创建时间
    char                        szCurrState[DH_MAX_SYNOPSIS_STATE_NAME];  // 当前视频浓缩状态,"Downloading"-正在下载","Synopsising"-正在浓缩",
                                                                    // "DownloadFailed"-下载失败","DownloadSucceeded"-下载成功
                                                                    // "SynopsisFailed"-浓缩失败","Succeeded"-浓缩成功
                                                                    // "DownloadPause"-下载暂停,"SynopsisPause"-浓缩暂停
    char                        szCreateUser[DH_MAX_NAME_LEN];      // 创建任务的用户
    int                         nProgressOfCurrentState;            // 当前浓缩步骤对应的完成进度，0~100
    char                        szLocalFilePath[MAX_PATH];          // 本地文件路径或远端视频源文件下载后在本地的路径
    int                         nObjectNum;                         // 目前浓缩过程中已发现的物体数量
    NET_FILEPATH_INFO           stuVideoSourceFilePath;             // 源视频文件路径
    NET_FILEPATH_INFO           stuSynopsisVideoFilePath;           // 浓缩视频文件路径
    char                        szFailedCode[DH_MAX_STRING_LEN];    // 浓缩视频失败错误码，szCurrState为"SynopsisFailed"时有效
                                                                    // "OutOfMemory" 内存不足;
                                                                    // "TooMany_TargetInVideo"  整个视频目标数过多;
                                                                    // "InvalidFilePointer" 文件指针无效;
                                                                    // "InvalidFilePath" 文件路径无效;
                                                                    // "CreateDirectoryFailed"  创建文件夹路径失败;
                                                                    // "WriteDataFailed" 写Tube中间文件失败
                                                                    // "DataSizeTooLarge" Tube文件太大
                                                                    // "Detect_Nothing" 场景中无运动目标
                                                                    // "OpenDataFailed" 打开中间文件失败
                                                                    // "InvalidSynopsisBackgroud" 浓缩背景无效
                                                                    // "ColorRetrieval" 错误的颜色检索配置
                                                                    // "UnsupportRuleType" 不支持的规则类型
                                                                    // "RuleNumberExceedLimit" 规则数超限
                                                                    // "NoFunctionCfgInfo" 指定了相应功能但没有配置信息
                                                                    // "FunctionNumberExceedLimit" 每条规则的功能数目数量超限
                                                                    // "PointsExceedLimit" 线或者区域的点数超限
                                                                    // "BadFunctionType" 错误的功能类型
                                                                    // "RulePointNumber" 规则点数错误
                                                                    // "MaskRegionNumberExceedLimit" 屏蔽区域数量超限
                                                                    // "CameraSceneSwitch" 相机场景切换
                                                                    // "TooManyTargeInFrame" 单帧中目标数过多
                                                                    // "InalidSynopsisDesity" 浓缩密度无效
                                                                    // "ExtrackColorFeatureFailed" 提取颜色特征失败
                                                                    // "JpegEncodeFrameFailed" Jpeg编码失败
                                                                    // "JpegParamRestFailed" Jpeg重置编码参数失败
                                                                    // "JpegDecodeFrameFailed" Jpeg解码失败
                                                                    // "RetrieveObjectIdInvalid" 检索目标ID无效
                                                                    // "RetrieveImageInvalid" 检索图像无效
                                                                    // "NetworkAnomaly" 映射盘网络异常
                                                                    // "ObjectNumberLimit" 超过分析目标数目限制
                                                                    // "CreateChannelFailed" 创建通道失败
                                                                    // "ReadUGFileFailed" 读取UG文件失败
                                                                    // "GetSynopsisInfoFailed" 获取浓缩视频信息失败
                                                                    // "ObjectNumberExceedLimit" 场景中目标数目超过限制
                                                                    // "RebuildBackgroudFailed" 重建背景失败
                                                                    // "NotExistMiddleFile" 中间文件不存在
                                                                    // "NotExistSourceFile" 原始文件不存在
                                                                    // "NotDog" 没有加密狗
                                                                    // "NotEnoughFreeDisk" 磁盘空间不够
                                                                    // "StartDecodeFail" 开始解码失败
                                                                    // "DecodeTimeOut" 解码等待超时
                                                                    // "EncodeTimeOut" 编码等待超时
                                                                    // "ExactTimeOut" 提取快照等待超时
                                                                    // "ReadMidlleFileFail" 读取中间文件失败
                                                                    // "ExactPictureFail" 提取图片失败
}NET_VSTASK_INFO;

// 浓缩视频任务中每个物体信息
typedef struct tagNET_VSOBJECT_INFO
{
    DWORD                dwSize;                        // 该结构体大小
    DWORD                dwTaskID;                      // 物体对应任务ID
    DH_MSG_OBJECT        stuObjInfo;                    // 物体信息
    NET_FILEPATH_INFO    stuFilePathInfo;               // 物体对应的文件信息
    DWORD                dwFileLength;                  // 快照文件的字节数大小
}NET_VSOBJECT_INFO;

//--CLIENT_QueryVideoSynopsisInfo接口输出参数定义
typedef struct tagNET_OUT_QUERY_VIDEOSYNOPSIS
{
    DWORD                dwSize;                        // 该结构体大小
    DWORD                dwTotalCount;                  // 符合此次查询条件的结果总条数
    DWORD                dwFoundCount;                  // 本次查询返回的条数
    void*                pResult;                       // 返回的信息，用户分配空间
                                                        // 如果emQueryType==EM_VIDEOSYNOPSIS_TASK，对应NET_VSTASK_INFO
                                                        // 如果emQueryType==EM_VIDEOSYNOPSIS_OBJ，对应NET_VSOBJECT_INFO
    DWORD                dwMaxCount;                    // 用户希望的结果的个数
}NET_OUT_QUERY_VIDEOSYNOPSIS;

// CLIENT_FindSynopsisFile接口参数定义 
// 浓缩相关文件查询类型
enum NET_EM_QUERY_SYNOPSIS_FILE
{
    DH_FILE_QUERY_VIDEO,                                // 普通录像文件信息，对应查询结构体:NET_SYNOPSIS_QUERY_VIDEO_PARAM, 返回结果结构体:NET_SYNOPSISFILE_VIDEO_INFO
    DH_FILE_QUERY_SYNOPSISVIDEO,                        // 浓缩视频信息, 对应查询结构体:NET_QUERY_SYNOPSISVIDEO_PARAM,返回结果结构体:NET_QUERY_SYNOPSISVIDEO_INFO
};

typedef struct __NET_SYNOPSIS_QUERY_VIDEO_PARAM
{
    DWORD               dwSize;
    DWORD               dwQueryMask;                    // 查询类型掩码, 按照从低到高位，第一位按时间段、第二位按文件路径 
    NET_TIME            stuStartTime;                   // 开始时间    
    NET_TIME            stuEndTime;                     // 结束时间
    char                szFilePath[DH_MAX_SYNOPSIS_QUERY_FILE_COUNT][MAX_PATH];    // 待查询文件的绝对路径
    DWORD               dwFileCount;                    // 待查询文件的个数
}NET_SYNOPSIS_QUERY_VIDEO_PARAM;

typedef struct  
{
    DWORD               dwSize;
    int                 nTaskId;                        // 任务ID
    DWORD               dwOutPutTypeMask;               // 当前任务的输出类型，第1位.视频大纲(一组快照);第2位浓缩视频    
    char                szCurrentState[DH_MAX_SYNOPSIS_STATE_NAME]; // 当前浓缩状态
}NET_VIDEOSYNOPSIS_TASK_INFO;

// DH_FILE_QUERY_VIDEO 返回的录像文件信息
typedef struct
{
    DWORD               dwSize;
    unsigned int        nchannelId;                     // 通道号
    char                szFilePath[MAX_PATH];           // 文件路径
    unsigned int        nFileLenth;                     // 文件长度，字节为单位
    NET_TIME            stuStarttime;                   // 开始时间
    NET_TIME            stuEndtime;                     // 结束时间
    unsigned int        nWorkDirSN;                     // 工作目录编号    
    unsigned int        nCluster;                       // 簇号                        
    BYTE                bHint;                          // 文件定位索引
    BYTE                bDriveNo;                       // 磁盘号
    BYTE                bReserved[18];                  // 保留字段
    int                 nTaskInfoNum;                   // 录像文件对应的浓缩任务个数
    NET_VIDEOSYNOPSIS_TASK_INFO stuTaskInfo[16];        // 具体浓缩任务信息
}NET_SYNOPSISFILE_VIDEO_INFO;

// DH_FILE_QUERY_SYNOPSISVIDEO 浓缩视频文件查询参数
typedef struct __NET_QUERY_SYNOPSISVIDEO_PARAM
{
    DWORD               dwSize;
    int                 nTaskID;                        // 任务ID
}NET_QUERY_SYNOPSISVIDEO_PARAM;

// DH_FILE_QUERY_SYNOPSISVIDEO浓缩视频查询结果
typedef struct __NET_QUERY_SYNOPSISVIDEO_INFO
{
    DWORD               dwSize;
    char                szFilePath[MAX_PATH];           // 文件路径
    unsigned int        nFileLenth;                     // 文件长度
    int                 nDurationTime;                  // 持续时间,单位s
}NET_QUERY_SYNOPSISVIDEO_INFO;

// CLIENT_FindSynopsisFile 接口参数
typedef struct tagNET_IN_FIND_SYNOPSISFILE
{
    DWORD               dwSize;                          
    NET_EM_QUERY_SYNOPSIS_FILE emQueryType;             // 查询类型
    void*               pQueryCondition;                // 查询条件 
    int                 nWaitTime;                      // 等待超时时间，单位ms
}NET_IN_FIND_SYNOPSISFILE;

typedef struct tagNET_OUT_FIND_SYNOPSISFILE
{
    DWORD               dwSize;
    LLONG               lFindHandle;                    // 查询句柄         
}NET_OUT_FIND_SYNOPSISFILE;

// CLIENT_FindNextSynopsisFile 接口参数
typedef struct tagNET_IN_FINDNEXT_SYNOPSISFILE
{
    DWORD               dwSize;
    int                 nFileCount;                     // 待查询的文件条数
    NET_EM_QUERY_SYNOPSIS_FILE emQueryType;             // 查询类型
    void*               pSynopsisFileInfo;              // 文件信息存放缓冲 
    int                 nMaxlen;                        // 缓冲区大小
    int                 nWaitTime;                      // 等待超时时间，单位ms
}NET_IN_FINDNEXT_SYNOPSISFILE;

typedef struct tagNET_OUT_FINDNEXT_SYNOPSISFILE
{
    DWORD               dwSize;
    int                 nRetFileCount;                  // 接口实际返回的信息条数，返回值<nFileCount(输入参数)则相应时间段内的文件查询完毕
}NET_OUT_FINDNEXT_SYNOPSISFILE;

// 下载进度回调函数原形, nError表示在下载过程出现的错误，1-缓存不足，2-对返回数据的校验出错，3-下载当前文件失败，4-创建对应保存文件失败
typedef void (CALLBACK *fSynopsisFileDownLoadPosCB)(LLONG lDownLoadHandle, DWORD dwFileID, DWORD dwFileTotalSize, DWORD dwDownLoadSize, int nError, LDWORD dwUser, void* pReserved);

// CLIENT_DownLoadSynosisFile 接口参数
#define NET_SYNOPSIS_DOWNLOADFILE_INFO NET_DOWNLOADFILE_INFO

typedef struct tagNET_IN_DOWNLOAD_SYNOPSISFILE
{
    DWORD               dwSize;
    int                 nFileCount;                     // 待下载文件数
    NET_SYNOPSIS_DOWNLOADFILE_INFO* pFileInfos;         // 待下载文件信息
    fSynopsisFileDownLoadPosCB cbPosCallBack;           // 进度回调函数
    LDWORD              dwUserData;                     // 用户数据
    int                 nWaitTime;                      // 等待超时时间，单位ms
}NET_IN_DOWNLOAD_SYNOPSISFILE;

typedef struct tagNET_OUT_DOWNLOAD_SYNOPSISFILE
{
    DWORD               dwSize;
    LLONG               lDownLoadHandle;                // 下载句柄
}NET_OUT_DOWNLOAD_SYNOPSISFILE;

// 文件(夹)路径信息
typedef struct    tagNET_SET_FILEPATH_INFO
{
    DWORD               dwSize;
    char                szFilePath[MAX_PATH];           // 可以是文件夹路径，也可以是文件路径。目前浓缩视频服务器只支持dav格式的文件
}NET_SET_FILEPATH_INFO;

// CLIENT_SetFilePathInfo()接口输入参数
typedef struct tagNET_IN_SET_FILEPATHINFO
{
    DWORD                dwSize;
    DWORD                dwCount;                       // 添加的文件路径信息个数
    void*                pFilePathInfo;                 // 指向文件路径信息NET_SET_FILEPATH_INFO数组
    DWORD                dwWaitTime;                    // 等待超时时间，单位ms
}NET_IN_SET_FILEPATHINFO;


// fAddFileStateCB 参数
typedef struct tagNET_CB_ADDFILESTATE
{
    DWORD               dwSize;
    const char*         szFileName;                     // 文件名称
    const char*         szState;                        // 文件分析状态, "Successed",成功; "Failed"，失败；
}NET_CB_ADDFILESTATE;

// 刻录设备回调函数原形, 每次1条，pBuf->dwSize == nBufLen
typedef void (CALLBACK *fAddFileStateCB) (LLONG lLoginID, LLONG lAttachHandle, NET_CB_ADDFILESTATE* pBuf,  int nBufLen, LDWORD dwUser);

// CLIENT_AttacAddFileState()接口输入参数
typedef struct tagNET_IN_ADDFILE_STATE
{
    DWORD               dwSize;
    fAddFileStateCB     cbAttachState;                 // 监听增加文件状态回调
    LDWORD              dwUser;                        // 用户数据
}NET_IN_ADDFILE_STATE;
typedef struct tagNET_OUT_ADDFILE_STATE
{
    DWORD                dwSize;
}NET_OUT_ADDFILE_STATE;

///////////////////////////////////人脸识别模块相关结构体///////////////////////////////////////

// CLIENT_OperateFaceRecognitionDB接口输入参数
typedef struct __NET_IN_OPERATE_FACERECONGNITIONDB
{
    DWORD             dwSize;
    EM_OPERATE_FACERECONGNITIONDB_TYPE emOperateType;  // 操作类型
    FACERECOGNITION_PERSON_INFO        stPersonInfo;   // 人员信息 
    
    // 图片二进制数据
    char              *pBuffer;                        // 缓冲地址
    int               nBufferLen;                      // 缓冲数据长度
}NET_IN_OPERATE_FACERECONGNITIONDB;

// CLIENT_OperateFaceRecognitionDB接口输出参数
typedef struct __NET_OUT_OPERATE_FACERECONGNITIONDB
{
    DWORD               dwSize;
}NET_OUT_OPERATE_FACERECONGNITIONDB;

typedef struct __NET_FACE_MATCH_OPTIONS
{
    DWORD               dwSize;
    unsigned int        nMatchImportant;               // 人员重要等级    1~10，数值越高越重要,(查询重要等级大于等于此等级的人员)
    EM_FACE_COMPARE_MODE emMode;                       // 人脸比对模式,详见EM_FACE_COMPARE_MODE
    int                 nAreaNum;                      // 人脸区域个数
    EM_FACE_AREA_TYPE   szAreas[MAX_FACE_AREA_NUM];    // 人脸区域组合,emMode为NET_FACE_COMPARE_MODE_AREA时有效
    int                 nAccuracy;                     // 识别精度(取值1~10，随着值增大，检测精度提高，检测速度下降。最小值为1 表示检测速度优先，最大值为10表示检测精度优先。 暂时只对人脸检测有效)
    int                 nSimilarity;                   // 相似度(必须大于该相识度才报告;百分比表示，1~100)
    int                 nMaxCandidate;                 // 报告的最大候选个数(根据相似度进行排序，取相似度最大的候选人数报告)
    
}NET_FACE_MATCH_OPTIONS;

typedef struct __NET_FACE_FILTER_CONDTION
{
    DWORD               dwSize;
    NET_TIME            stStartTime;                   // 开始时间
    NET_TIME            stEndTime;                     // 结束时间
    char                szMachineAddress[MAX_PATH];    // 地点，支持模糊匹配    
    int                 nRangeNum;                     // 实际数据库个数     
    BYTE                szRange[MAX_FACE_DB_NUM];      // 待查询数据库类型，详见EM_FACE_DB_TYPE
    EM_FACERECOGNITION_FACE_TYPE emFaceType;           // 待查询人脸类型，详见 EM_FACERECOGNITION
}NET_FACE_FILTER_CONDTION;
// CLIENT_StartFindFaceRecognition接口输入参数
typedef struct __NET_IN_STARTFIND_FACERECONGNITION
{
    DWORD               dwSize;
    BOOL                bPersonEnable;                 // 人员信息查询条件是否有效
    FACERECOGNITION_PERSON_INFO stPerson;              // 人员信息查询条件
    NET_FACE_MATCH_OPTIONS stMatchOptions;             // 人脸匹配选项
    NET_FACE_FILTER_CONDTION stFilterInfo;             // 查询过滤条件
  
    // 图片二进制数据
    char                *pBuffer;                      // 缓冲地址
    int                 nBufferLen;                    // 缓冲数据长度

    int                 nChannelID;                    // 通道号         
}NET_IN_STARTFIND_FACERECONGNITION;

// CLIENT_StartFindFaceRecognition接口输出参数
typedef struct __NET_OUT_STARTFIND_FACERECONGNITION
{
    DWORD               dwSize;
    int                 nTotalCount;                   // 返回的符合查询条件的记录个数 
    LLONG               lFindHandle;                   // 查询句柄
}NET_OUT_STARTFIND_FACERECONGNITION;

#define MAX_FIND_COUNT  20

// CLIENT_DoFindFaceRecognition 接口输入参数
typedef struct __NET_IN_DOFIND_FACERECONGNITION
{
    DWORD               dwSize;
    LLONG               lFindHandle;                   // 查询句柄
    int                 nBeginNum;                     // 查询起始序号
    int                 nCount;                        // 当前想查询的记录条数 
}NET_IN_DOFIND_FACERECONGNITION;

// CLIENT_DoFindFaceRecognition接口输出参数
typedef struct __NET_OUT_FINDNEXT_FACERECONGNITION
{
    DWORD               dwSize;
    int                 nCadidateNum;                  // 实际返回的候选信息结构体个数
    CANDIDATE_INFO      stCadidateInfo[MAX_FIND_COUNT];// 候选信息数组
    
    // 图片二进制数据
    char                *pBuffer;                      // 缓冲地址
    int                 nBufferLen;                    // 缓冲数据长度
}NET_OUT_DOFIND_FACERECONGNITION;

// CLIENT_DetectFace接口输入参数
typedef struct __NET_IN_DETECT_FACE
{
    DWORD               dwSize; 
    DH_PIC_INFO         stPicInfo;                     // 大图信息

    // 图片二进制数据
    char                *pBuffer;                      // 缓冲地址
    int                 nBufferLen;                    // 缓冲数据长度
}NET_IN_DETECT_FACE;

// CLIENT_DetectFace接口输出参数
typedef struct __NET_OUT_DETECT_FACE
{
    DWORD               dwSize; 
    DH_PIC_INFO         *pPicInfo;                     // 检测出的人脸图片信息，由用户申请空间
    int                 nMaxPicNum;                    // 最大人脸图片信息个数
    int                 nRetPicNum;                    // 实际返回的人脸图片个数 
    
    // 图片二进制数据
    char                *pBuffer;                      // 缓冲地址,由用户申请空间，存放检测出的人脸图片数据
    int                 nBufferLen;                    // 缓冲数据长度
}NET_OUT_DETECT_FACE;

///////////////////////////////// 刻录上传 /////////////////////////////////

// fBurnCheckCallBack 参数
typedef struct tagNET_CB_BURN_CHECK_STATE
{
    DWORD               dwSize;
    const char*         szType;                         // 消息类型
                                                        // "Checking": 校验中
                                                        // "CheckResult": 校验结果    
    BOOL                bCheckResult;                   // 校验结果, 用于"CheckResult", TRUE-成功, FALSE-失败
    BYTE                byProgress;                     // 校验进度, 用于"Checking", 百分比, 0~100
    BYTE                reserved[3];
} NET_CB_BURN_CHECK_STATE;

// 刻录校验回调函数原形, lAttachHandle是CLIENT_AttachBurnCheckState的返回值
typedef void (CALLBACK *fBurnCheckCallBack)(LLONG lLoginID, LLONG lAttachHandle, NET_CB_BURN_CHECK_STATE* pstState, void* reserved, LDWORD dwUser);

// CLIENT_AttachBurnCheckState 接口的输入参数(监听刻录校验状态)
typedef struct tagNET_IN_ATTACH_BURN_CHECK 
{
    DWORD               dwSize;
    fBurnCheckCallBack  cbBurnCheck;                    // 刻录校验回调
    LDWORD              dwUser;                         // 用户数据
} NET_IN_ATTACH_BURN_CHECK;

// CLIENT_AttachBurnCheckState 接口的输出参数(监听刻录校验状态)
typedef struct tagNET_OUT_ATTACH_BURN_CHECK
{
    DWORD            dwSize;
} NET_OUT_ATTACH_BURN_CHECK;

///////////////////////////////// 逻辑设备 /////////////////////////////////

typedef struct tagNET_CB_CAMERASTATE
{
    DWORD               dwSize;
    int                 nChannel;             // 通道
    CONNECT_STATE       emConnectState;       // 连接状态
}NET_CB_CAMERASTATE;

// CLIENT_AttachCameraState()回调函数原形, 每次1条，pBuf->dwSize == nBufLen
typedef void (CALLBACK *fCameraStateCallBack) (LLONG lLoginID, LLONG lAttachHandle, const NET_CB_CAMERASTATE *pBuf, int nBufLen, LDWORD dwUser);

// CLIENT_AttachCameraState()输入参数
typedef struct tagNET_IN_CAMERASTATE
{
    DWORD                   dwSize;
    int *                   pChannels;              // 观察的通道号,数组元素中，有一个是-1，则观察所有通道
    int                     nChannels;              // pChannels指针长度
    fCameraStateCallBack    cbCamera;               // 状态回调函数
    LDWORD                  dwUser;                 // 用户数据
}NET_IN_CAMERASTATE;

typedef struct tagNET_OUT_CAMERASTATE
{
    DWORD                dwSize;
}NET_OUT_CAMERASTATE;

/////////////////////////////////特殊版本/////////////////////////////////

// 触发设备抓图，叠加卡号信息
typedef struct __NET_SNAP_COMMANDINFO 
{
    char                szCardInfo[16];             // 卡号信息
    char                reserved[64];               // 保留
} NET_SNAP_COMMANDINFO, LPNET_SNAP_COMMANDINFO;

typedef struct
{
    int                 nChannelNum;                // 通道号
    char                szUseType[32];              // 通道用途
    DWORD               dwStreamSize;               // 流量大小(单位：kb/s)
    char                reserved[32];               // 保留
} DHDEV_USE_CHANNEL_STATE;

typedef struct 
{
    char                szUserName[32];                     // 用户名
    char                szUserGroup[32];                    // 用户组
    NET_TIME            time;                               // 登入时间
    int                 nOpenedChannelNum;                  // 开启的通道个数
    DHDEV_USE_CHANNEL_STATE    channelInfo[DH_MAX_CHANNUM];
    char                szIpAddress[DH_MAX_IPADDR_LEN_EX];  // ip地址
    char                reserved[24];
} DHDEV_USER_NET_INFO;

// 网络运行状态信息
typedef    struct 
{
    int                 nUserCount;                      // 用户数量
    DHDEV_USER_NET_INFO stuUserInfo[32];
    char                reserved[256];
}DHDEV_TOTAL_NET_STATE;

typedef struct
{
    char                szIpAddress[DH_MAX_IPADDR_LEN];  // ip地址
    char                szUserGroup[32];                 // 用户组
    char                szUserName[32];                  // 用户名
    char                reserved[64];
}DHDEV_USER_REJECT_INFO;

// 剔除用户
typedef struct
{ 
    int                       nUserCount;                // 用户数量
    DHDEV_USER_REJECT_INFO    stuUserInfo[10];     
    char                      reserved[256];
}DHDEV_REJECT_USER;

typedef struct
{
    char                szIpAddress[DH_MAX_IPADDR_LEN];  // ip地址
    char                szUserGroup[32];                 // 用户组
    char                szUserName[32];                  // 用户名
    int                 nForbiddenTime;                  // 屏蔽时间
    char                reserved[64];
}DHDEV_USER_SHIELD_INFO;

// 屏蔽用户
typedef struct
{ 
    int                       nUserCount;                // 用户数量
    DHDEV_USER_SHIELD_INFO    stuUserInfo[10];     
    char                      reserved[256];
}DHDEV_SHIELD_USER;

// 经纬度
typedef struct
{//  经度在前，维度在后
    char                chPreLogi;        // 经度前置标志：N、S、W、E，分别表示北、南、西、东。
    char                chPreLati;        // 纬度前置标志：N、S、W、E，分别表示北、南、西、东。
    BYTE                reserved[6];      // 保留字节,对齐
    double              dbLongitude;      // 经度
    double              dbLatitude;       // 纬度
}DHDEV_LONGI_LATI;
// 导航信息和短消息
typedef struct
{
    char                szPhoneNum[DH_MAX_PHONE_NO_LEN];    // 电话号码
    NET_TIME            stMsgTime;                          // 信息发送时间
    char                szMsgType[DH_MAX_MSGTYPE_LEN];      // 信息类型（导航信息-Navigation； 短消息--SMS）
    char                szSmsContext[DH_MAX_MSG_LEN];       // 发送的信息内容
    DHDEV_LONGI_LATI    stLogiLati;                         // 起始经纬度
    unsigned int        uFlag;                              // 01：标志发来的是真实经纬度
    char                szNavigationType[16];               // TNC,为凯立德地图中心导航格式，TXZ,为天行者地图中心导航格式
    char                szAddress[32];                      // 地点信息
    char                szNavigationMode[32];               // 导航模式 有Recommend推荐，Economical经济型，Fastest 最快；Shortest 最短；
    DHDEV_LONGI_LATI    stPassLogiLati[5];                  // 经由点
    DHDEV_LONGI_LATI    stNoPassLogiLati[5];                // 不经由点
    BYTE                reserved[256];
}DHDEV_NAVIGATION_SMSS;

// 图象水印配置
typedef struct __DHDEV_WATERMAKE_CFG 
{
    DWORD               dwSize;
    int                 nEnable;                                // 使能
    int                 nStream;                                // 码流(1～n)0-所有码流
    int                 nKey;                                   // 数据类型(1-文字，2-图片)
    char                szLetterData[DH_MAX_WATERMAKE_LETTER];  //    文字
    char                szData[DH_MAX_WATERMAKE_DATA];          // 图片数据
    BYTE                bReserved[512];                         // 保留
} DHDEV_WATERMAKE_CFG;

// 存储位置设置结构体，每通道独立设置,每通道可以选择各种存储类型, 目前包括本地, 可移动, 远程存储.
typedef struct 
{
    DWORD               dwSize;
    DWORD               dwLocalMask;                            // 本地存储掩码；按位表示：
                                                                // 第一位：系统预录，第二位：定时录像，第三位：动检录像，
                                                                // 第四位：报警录像，第五位：卡号录像，第六位：手动录像
    DWORD               dwMobileMask;                           // 可移动存储掩码 存储掩码如本地存储掩码
    int                 RemoteType;                             // 远程存储类型 0: Ftp  1: Smb 
    DWORD               dwRemoteMask;                           // 远程存储掩码 存储掩码如本地存储掩码
    DWORD               dwRemoteSecondSelLocal;                 // 远程异常时本地存储掩码
    DWORD               dwRemoteSecondSelMobile;                // 远程异常时可移动存储掩码
    char                SubRemotePath[MAX_PATH_STOR];           // 远程目录, 其中长度为240
    DWORD               dwFunctionMask;                         // 功能屏蔽位，按位表示，bit0 = 1:屏蔽抓图事件触发存储位置功能
    DWORD               dwAutoSyncMask;                         // 是否同步掩码;远程存储网络故障恢复后，自动将本地存储的数据同步到远程存储。
    BYTE                bAutoSyncRange;                         // 从网络恢复的时刻开始，需要往前同步的数据时间范围，小时为单位。0:同步所有数据  1:1小时内的数据 n:n小时内的数据
    char                reserved[119];
} DH_STORAGE_STATION_CFG;

#define MAX_ALARM_DECODER_NUM 16
typedef struct  
{
    DWORD               dwAlarmDecoder;             // 现在最多支持8个报警输入口，留8位待以后扩展
    BYTE                bDecoderIndex;              // 表示第几个报警解码器
    BYTE                bReserved[3];
} ALARM_DECODER;

// 报警解码器报警
typedef struct
{
    int                 nAlarmDecoderNum;
    ALARM_DECODER       stuAlarmDecoder[MAX_ALARM_DECODER_NUM];
    BYTE                bReserved[32];
} ALARM_DECODER_ALARM;

//DSP报警
typedef struct  
{
    BOOL                bError;             //0,DSP正常 1,DSP异常
    DWORD               dwErrorMask;        //按位表示，非0表示有此错误，0表示没有。(目前每次报警只有一位有效)
                                            //bit DSP报警
                                            // 1  DSP加载失败 
                                            // 2  DSP错误
                                            // 3  制式不对 
                                            // 4  分辨率不支持
                                            // 5  数据格式不支持
                                            // 6  找不到I帧
    DWORD               dwDecChnnelMask;    //按位表示，报警的解码通道号，dwErrorMask为DSP错误，制式不对，分辨率不支持，数据格式不支持时此项有效
    DWORD               dwDecChnnelMask1;   //按位表示,33-64通道的报警的解码通道号, dwErrorMask为DSP错误，制式不对，分辨率不支持，数据格式不支持时此项有效
    BYTE                bReserved[24];
}DSP_ALARM;

// 光纤编码能力报警
typedef struct  
{
    int         nFDDINum;
    BYTE        bAlarm[256];
} ALARM_FDDI_ALARM;

#define ALARM_PTZ_LOCATION_INFO DH_PTZ_LOCATION_INFO

// 新音频检测报警配置
typedef struct
{
    BOOL                bEnable;                    // 报警输入使能
    int                 Volume_min;                 // 音量的最小值
    int                 Volume_max;                 // 音量的最大值
    char                reserved[128];    
    DH_TSECT            stSect[DH_N_WEEKS][DH_N_REC_TSECT];    
    DH_MSG_HANDLE       struHandle;                 // 处理方式
} DH_AUDIO_DETECT_INFO;

typedef struct  
{
    DWORD                   dwSize;
    int                     AlarmNum;
    DH_AUDIO_DETECT_INFO    AudioDetectAlarm[DH_MAX_AUDIO_IN_NUM];
    char                    reserved[256];
} DH_AUDIO_DETECT_CFG;

typedef struct
{
    BOOL                bTourEnable;                // 轮巡使能
    int                 nTourPeriod;                // 轮巡间隔，单位秒, 5-300 
    DWORD               dwChannelMask;              // 轮巡的通道，掩码形式表示
    char                reserved[64];
}DH_VIDEOGROUP_CFG;

// 本机矩阵控制策略配置
typedef struct
{
    DWORD               dwSize;
    int                 nMatrixNum;                 // 矩阵个数(注：不允许修改)
    DH_VIDEOGROUP_CFG   struVideoGroup[DH_MATRIX_MAXOUT];
    char                reserved[32];
} DHDEV_VIDEO_MATRIX_CFG;   

// WEB路径配置
typedef struct 
{
    DWORD               dwSize;
    BOOL                bSnapEnable;                    // 是否抓图
    int                 iSnapInterval;                  // 抓图周期
    char                szHostIp[DH_MAX_IPADDR_LEN];    // HTTP主机IP
    WORD                wHostPort;
    int                 iMsgInterval;                   // 状态消息发送间隔
    char                szUrlState[DH_MAX_URL_LEN];     // 状态消息上传URL
    char                szUrlImage[DH_MAX_URL_LEN];     // 图片上传Url
    char                szDevId[DH_MAX_DEV_ID_LEN];     // 机器的web编号
    BYTE                byReserved[2];
} DHDEV_URL_CFG;

// OEM查询
typedef struct  
{
    char                szVendor[DH_MAX_STRING_LEN];
    char                szType[DH_MAX_STRING_LEN];
    char                reserved[128];
} DHDEV_OEM_INFO;


//视频OSD叠加配置
typedef struct 
{ 
    DWORD   rgbaFrontground;            // 物件的前景；按字节表示，分别为红、绿、蓝和透明度
    DWORD   rgbaBackground;             // 物件的背景；按字节表示，分别为红、绿、蓝和透明度    
    RECT    rcRelativePos;              // 位置,物件边距与整长的比例*8191    
    BOOL    bPreviewBlend;              // 预览叠加使能    
    BOOL    bEncodeBlend;               // 编码叠加使能
    BYTE    bReserved[4];               // 保留
} DH_DVR_VIDEO_WIDGET;

typedef struct 
{
    DH_DVR_VIDEO_WIDGET     StOSD_POS;                                 // OSD叠加的位置和背景色
    char                    SzOSD_Name[DH_VIDEO_OSD_NAME_NUM];         // OSD叠加的名称
}DH_DVR_VIDEOITEM;
 
// 每个通道的OSD信息
typedef struct 
{
    DWORD                   dwSize;
    DH_DVR_VIDEOITEM        StOSDTitleOpt [DH_VIDEO_CUSTOM_OSD_NUM];    // 每个通道的OSD信息
    BYTE                    bReserved[16];                              // 保留
} DH_DVR_VIDEOOSD_CFG;

// 配置CDMA/GPRS网络信息
// 时间段结构                                                                
typedef struct 
{
    BYTE                bEnable;                  // 时间段使能，1表示该时间段有效，0表示该时间段无效。
    BYTE                bBeginHour;
    BYTE                bBeginMin;
    BYTE                bBeginSec;
    BYTE                bEndHour;
    BYTE                bEndMin;
    BYTE                bEndSec;
    BYTE                bReserved;                //保留
} DH_3G_TIMESECT, *LPDH_3G_TIMESECT;

typedef struct 
{
    DWORD               dwSize;
    BOOL                bEnable;                        // 无线模块使能标志
    DWORD               dwTypeMask;                     // 设备支持网络类型掩码;按位表示,第一位;自动选择;
                                                        // 第二位：TD-SCDMA网络；第三位：WCDMA网络;
                                                        // 第四位：CDMA 1.x网络;第五位：CDMA2000网络;第六位：GPRS网络;
                                                        // 第七位：EVDO网络;第八位：WIFI
    DWORD               dwNetType;                      // 当前的无线网络类型，为EM_GPRSCDMA_NETWORK_TYPE值
    char                szAPN[128];                     // 接入点名称
    char                szDialNum[128];                 // 拨号号码
    char                szUserName[128];                // 拨号用户名
    char                szPWD[128];                     // 拨号密码
    
    /* 下面是设备的只读部分 */
    BOOL                iAccessStat;                    // 无线网络注册状态
    char                szDevIP[16];                    // 前端设备拨号IP，字符串, 包括'\0'结束符共16byte  
    char                szSubNetMask [16];              // 前端设备拨号子网掩码，字符串, 包括'\0'结束符共16byte 
    char                szGateWay[16];                  // 前端设备拨号网关，字符串, 包括'\0'结束符共16byte 
    /* 上面是设备的只读部分 */
    int                 iKeepLive;                      // 保活时间
    DH_3G_TIMESECT      stSect[DH_N_WEEKS][DH_N_TSECT]; // 3G拨号时间段，有效时间段之内，开启拨号；有效时间段之外，关闭拨号。
    BYTE                byActivate;                     // 是否需要被语音或短信激活

    BYTE                bySimStat;                      // SIM(UIM)状态:存在1,不存在0  (只读数据) 占用Reserved的1个字节
    char                szIdentify[128];                // 鉴权方式
    bool                bPPPEnable;                     // PPP拨号,0-断开ppp连接，1-ppp拨号
    BYTE                bPPPState;                      // PPP拨号状态(只读)，具体含义见EM_MOBILE_PPP_STATE
    BYTE                bNetCardState;                  // 网卡所处状态(只读)，具体含义见EM_3GMOBILE_STATE
    char                szPhyCardNo[32];                // 物理卡号
    char                Reserved[4];                    // 保留字节，用于扩展
    BYTE                byPinShow;                      // PIN码是否显示(只读), 0-不支持, 1-显示, 2-不显示
    BYTE                byPinEnable;                    // PIN码设置使能(只读), 0-不使能, 1-使能
    BYTE                byPinCount;                     // PIN码剩余设置次数(只读), 0~3
    //-------------------------------以下字段设置dwSize后才有效------------------------------------
    char                szPinNo[16];                    // PIN码值, 字母或数字的任意组合
} DHDEV_CDMAGPRS_CFG;

// 录像打包长度配置
typedef struct  
{
    DWORD               dwSize;
    int                 nType;                          // 0:按时间，1：按大小
    int                 nValue;                         // nType = 0时:单位分钟，nType = 1时:单位KB
    char                Reserved[128];                  // 保留字节，用于扩展
} DHDEV_RECORD_PACKET_CFG;

// (定向)主动注册服务器信息
typedef struct __DEV_AUTOREGISTER_INFO 
{
    LONG            lConnectionID;                      // 连接ID
    char            szServerIp[DH_MAX_IPADDR_LEN];      // 主动注册服务器的IP
    int             nPort;                              // 主动注册服务器端口0- 65535
    int             nState;                             // 服务器的状态：0－注册失败；1-注册成功; 2-连接失败
    char            reserved[16];
} DEV_AUTOREGISTER_INFO;

typedef struct __DEV_SERVER_AUTOREGISTER 
{
    DWORD                    dwSize;
    int                      nRegisterSeverCount;                                            // 主动注册服务器个数
    DEV_AUTOREGISTER_INFO    stuDevRegisterSeverInfo[DH_CONTROL_AUTO_REGISTER_NUM];            // 各主动注册服务器信息
    char                     reserved[256];
} DEV_SERVER_AUTOREGISTER, *LPDEV_SERVER_AUTOREGISTER;

// 附件刻录附件上传
typedef struct
{
    DWORD               dwSize;        
    char                szSourFile[MAX_PATH_STOR];    // 源文件路径
    int                 nFileSize;                    // 源文件大小，如果小于等于0，sdk自行计算文件大小.
    char                szBurnFile[MAX_PATH_STOR];    // 刻录后的文件名
    BYTE                bReserved[64];
} DHDEV_BURNFILE_TRANS_CFG;

// 升级文件上传
typedef struct
{
    char                 szFile[MAX_PATH_STOR];      // 升级文件路径
    int                  nFileSize;                  // 升级文件大小 
    BYTE                 byChannelId;                // 通道号
    BYTE                 byManufactryType;           // 厂商类型，详见EM_IPC_TYPE
    BYTE                 byReserved[126];            // 保留      
}DHDEV_UPGRADE_FILE_INFO;

// 黑白名单上传
typedef struct  
{
    char                 szFile[MAX_PATH_STOR];     // 黑白名单文件路径
    int                  nFileSize;                 // 升级文件大小
    BYTE                 byFileType;                // 当前文件类型，0-黑名单，1-白名单 
    BYTE                 byAction;                  // 动作，0-覆盖，1-追加
    BYTE                 byReserved[126];           // 保留
}DHDEV_BLACKWHITE_LIST_INFO;

// 黑白名单下载
typedef struct
{
    char                 szFile[MAX_PATH_STOR];     // 黑白名单文件保存路径
    BYTE                 byFileType;                // 当前文件类型，0-黑名单，1-白名单
    BYTE                 byReserved[127];           // 保留
}DHDEV_LOAD_BLACKWHITE_LIST_INFO;

// 郑州威科姆EC_U视频数据叠加使能配置
typedef struct 
{
    BOOL                bEnable;                    // 使能
    int                 nPort;                      // 端口
    BYTE                bReserved[64];
} DHDEV_OSD_ENABLE_CFG;

// 车载相关配置:北京公交使用配置
typedef struct    
{
    BOOL                bAutoBootEnable;                //自动开机使能
    DWORD               dwAutoBootTime;                 //每天自动开机时间点, 单位秒,从0算起.[0,82800]
    BOOL                bAutoShutDownEnable;            //自动关机使能
    DWORD               dwAutoShutDownTime;             //每天自动关机时间点, 单位秒,从0算起.[0,82800]
    DWORD               dwShutDownDelayTime;            //延时关机时间,单位秒.
    BYTE                bEventNoDisk;                   //1,(Ignore:忽略); 2,(Reboot:重起系统)
    BYTE                bWifiEnable;                    //是否支持车载无线模块.
    BYTE                bUpperSpeedEnable;              //是否使用超速判断
    BYTE                bLowerSpeedEnable;              //是否使用低速判断
    DWORD               dwUpperSpeedValue;              //超速值开区间(1,1000).公里/小时
    DWORD               dwLowerSpeedValue;              //低速值开区间(1,1000).公里/小时
    DWORD               dwUpperSpeedDelayTime;          //设置超速持续值
    DWORD               dwLowerSpeedDelayTime;          //设置低速持续值
    DWORD               dwAlarmMaskEnable;              //查询/设置叠加报警信息使能,0:关闭,1:打开, 每一位从低到高表示各个外部报警通道0-N使能
    BOOL                bSpeedOverAlarmRecordEnable;    // 超速报警联动录像使能
    BOOL                bSpeedLowAlarmRecordEnable;     // 低速报警联动录像使能 
    BYTE                bReserved[480];                 //reserved byte.
} DHDEV_ABOUT_VEHICLE_CFG;

// atm:查询叠加相关能力信息
typedef struct  
{
    DWORD               dwDataSource;                   //按位, 位0:Net(网络), 位1:Com(串口), 位2:Com422(串口422)
    char                szProtocol[32][33];             //协议名字,最大长度32(保留一个结束符).
    BYTE                bReserved[256];
} DHDEV_ATM_OVERLAY_GENERAL;
 
// atm:配置叠加设置
typedef struct 
{
    DWORD               dwDataSource;                   // 1:Net(网络), 2:Com(串口), 3:Com422(串口422)
    char                szProtocol[33];                 // 协议名字，由DHDEV_ATM_OVERLAY_GENERAL返回
    BYTE                bReserved_1[3];
    DWORD               dwChannelMask;                  // 叠加的通道号，掩码表示。
    BYTE                bMode;                          // 1:Preview(预览叠加), 2:Encode(编码叠加), 3:Preview&Encode(预览和编码叠加)
    BYTE                bLocation;                      // 1:LeftTop(左上), 2:LeftBottom(左下), 3:RightTop(右上), 4:RightBottom(右下)
    BYTE                bReserved_3[2];           
    int                 nLatchTime;                     // 叠加显示延迟时间,卡号录像延时关闭时间,0~65535s
    BYTE                bReserved_4[3];
    BYTE                bRecordSrcKeyNum;               // 关键字个数  
    int                 nRecordSrcKey[32];              // 各视频通道对应数据源关键字(不同通道可以对应不同的数据源)  
    BYTE                bReserved_2[120];
} DHDEV_ATM_OVERLAY_CONFIG;


// atm:配置叠加设置
typedef struct 
{
    DWORD               dwSize;                         // 结构体大小
    DWORD               dwDataSource;                   // 1:Net(网络), 2:Com(串口), 3:Com422(串口422)
    char                szProtocol[33];                 // 协议名字，
    BYTE                bReserved_1[3];
    DWORD               dwChannelMask[8];               // 叠加的通道号，掩码表示, dwChannelMask[0]表示0-31通道，依此类推。
    BYTE                bMode;                          // 1:Preview(预览叠加), 2:Encode(编码叠加), 3:Preview&Encode(预览和编码叠加)
    BYTE                bLocation;                      // 1:LeftTop(左上), 2:LeftBottom(左下), 3:RightTop(右上), 4:RightBottom(右下)
    BYTE                bReserved_3[2];           
    int                 nLatchTime;                     // 叠加显示延迟时间,卡号录像延时关闭时间,0~65535s
    BYTE                bReserved_4[3];
    BYTE                bRecordSrcKeyNum;               // 关键字个数  
    int                 nRecordSrcKey[256];             // 各视频通道对应数据源关键字(不同通道可以对应不同的数据源)  
} DHDEV_ATM_OVERLAY_CONFIG_EX;

#define DH_MAX_BACKUPDEV_NUM            16
#define DH_MAX_BACKUP_NAME              32

// 备份设备列表
typedef struct 
{
    int                 nBackupDevNum;                                // 实际的备份设备数量
    char                szBackupDevNames[DH_MAX_BACKUPDEV_NUM][DH_MAX_BACKUP_NAME]; // 备份设备的名称
} DHDEV_BACKUP_LIST, *LPDHDEV_BACKUP_LIST;

// 备份设备介质类型
typedef enum __BACKUP_TYPE
{
    BT_DHFS = 0,                            // 私有文件系统
    BT_DISK,                                // 移动硬盘
    BT_CDRW                                 // 光盘刻录
} DHDEV_BACKUP_TYPE;    

// 备份设备接口类型
typedef enum __BACKUP_BUS
{
    BB_USB = 0,                             // usb接口
    BB_1394,                                // 1394接口
    BB_IDE,                                 // ide接口
    BB_ESATA,                               // esata接口
} DHDEV_BACKUP_BUS;    

typedef struct 
{
    char                szName[32];                     // 设备名 
    BYTE                byType;                         // 备份设备的介质类型 枚举值见BACKUP_TYPE
    BYTE                byBus;                          // 备份设备的接口类型 枚举值见BACKUP_BUS
    UINT                nCapability;                    // 总容量, 以kBytes为单位
    UINT                nRemain;                        // 剩余容量,以kBytes为单位
    char                szDirectory[128];               // 远程备份的目录
} DHDEV_BACKUP_INFO, *LPDHDEV_BACKUP_INFO;

typedef struct 
{
    char                szName[32];                     // 设备名 
    UINT                nCapability;                    // 总容量, 以kBytes为单位
    UINT                nRemain;                        // 当前备份剩余容量,以kBytes为单位
} DHDEV_BACKUP_FEEDBACK, *LPDHDEV_BACKUP_FEEDBACK;

#define  DH_MAX_BACKUPRECORD_NUM 1024

typedef struct  
{
    char                szDeviceName[DH_MAX_BACKUP_NAME];            //备份设备名称
    int                 nRecordNum;                                  //备份记录数量
    NET_RECORDFILE_INFO stuRecordInfo[DH_MAX_BACKUPRECORD_NUM];      //备份记录信息
} BACKUP_RECORD, *LPBACKUP_RECORD;

// 多通道打开视频输入
typedef struct
{
    int                 iChannelID;      // 通道号
    DH_RealPlayType     realplayType;    // 视频类型
    char                reserve[32];
}DHDEV_IN_MULTIPLAY_PARAM;

// 多通道打开视频输出
typedef struct
{
    int                 iChannelID;      // 通道号
    LLONG               lRealHandle;     // 实时监视句柄
    char                reserve[32];
}DHDEV_OUT_MULTIPLAY_PARAM;


/////////////////////////////////平台接入/////////////////////////////////

// 平台接入配置 － U网通
typedef struct
{
    BOOL                bChnEn;
    char                szChnId[DH_INTERVIDEO_UCOM_CHANID];
} DH_INTERVIDEO_UCOM_CHN_CFG;

typedef struct
{
    DWORD               dwSize;
    BOOL                bFuncEnable;                            // 接入功能使能
    BOOL                bAliveEnable;                           // 心跳使能
    DWORD               dwAlivePeriod;                          // 心跳周期，单位秒，0-3600
    char                szServerIp[DH_MAX_IPADDR_LEN];          // CMS的IP
    WORD                wServerPort;                            // CMS的Port
    char                szRegPwd[DH_INTERVIDEO_UCOM_REGPSW];    // 注册密码
    char                szDeviceId[DH_INTERVIDEO_UCOM_DEVID];   // 设备id
    char                szUserName[DH_INTERVIDEO_UCOM_USERNAME];
    char                szPassWord[DH_INTERVIDEO_UCOM_USERPSW];
    DH_INTERVIDEO_UCOM_CHN_CFG  struChnInfo[DH_MAX_CHANNUM];    // 通道id,en
} DHDEV_INTERVIDEO_UCOM_CFG;

// 平台接入配置 － 阿尔卡特
typedef struct
{
    DWORD               dwSize;
    unsigned short      usCompanyID[2];             // 公司ID，数值，不同的第三方服务公司，考虑4字节对齐，目前只用数组第一个
    char                szDeviceNO[32];             // 前端设备序列号，字符串，包括'\0'结束符共32byte
    char                szVSName[32];               // 前端设备名称，字符串，包括'\0'结束符共16byte
    char                szVapPath[32];              // VAP路径
    unsigned short      usTcpPort;                  // TCP端口，数值：数值 1~65535 
    unsigned short      usUdpPort;                  // UDP端口，数值：数值 1~65535
    bool                bCsEnable[4];               // 中心服务器使能标志，数值：true使能，false不使能，考虑4字节对齐，目前只用数组第一个
    char                szCsIP[16];                 // 中心服务器IP地址，字符串，包括'\0'结束符共16byte
    unsigned short      usCsPort[2];                // 中心服务器端口，数值：数值 1~65535，考虑4字节对齐，目前只用数组第一个
    bool                bHsEnable[4];               // 心跳服务器使能标志，数值：true使能，false不使能，考虑4字节对齐，目前只用数组第一个
    char                szHsIP[16];                 // 心跳服务器IP地址，字符串，包括'\0'结束符共16byte
    unsigned short      usHsPort[2];                // 心跳服务器端口，数值：数值 1~65535，考虑4字节对齐，目前只用数组第一个
    int                 iHsIntervalTime;            // 心跳服务器间隔周期，数值(单位:秒)
    bool                bRsEnable[4];               // 注册服务器使能标志，数值：true使能，false不使能，考虑4字节对齐，目前只用数组第一个
    char                szRsIP[16];                 // 注册服务器IP地址，字符串，包括'\0'结束符共16byte
    unsigned short      usRsPort[2];                // 注册服务器端口，数值：数值 1~65535，考虑4字节对齐，目前只用数组第一个
    int                 iRsAgedTime;                // 注册服务器有效时间，数值(单位:小时)
    char                szAuthorizeServerIp[16];    // 鉴权服务器IP
    unsigned short      usAuthorizePort[2];         // 鉴权服务器端口，考虑4字节对齐，目前只用数组第一个
    char                szAuthorizeUsername[32];    // 鉴权服务器帐号
    char                szAuthorizePassword[36];    // 鉴权服务器密码
    
    char                szIpACS[16];                // ACS(自动注册服务器) IP
    unsigned short      usPortACS[2];               // ACS Port，考虑4字节对齐，目前只用数组第一个
    char                szUsernameACS[32];          // ACS用户名
    char                szPasswordACS[36];          // ACS密码
    bool                bVideoMonitorEnabled[4];    // DVS是否定期上报前端视频信号监控信息，数值：true使能，false不使能
    int                 iVideoMonitorInterval;      // 上报周期(分钟)
    
    char                szCoordinateGPS[64];        // GPS坐标
    char                szPosition[32];             // 设备位置
    char                szConnPass[36];             // 设备接入码
} DHDEV_INTERVIDEO_BELL_CFG;

// 平台接入配置 － 中兴力维
typedef struct  
{
    DWORD               dwSize;
    unsigned short      nSevPort;                               // 服务器端口，数值，数值1~65535
    char                szSevIp[DH_INTERVIDEO_NSS_IP];          // 服务器IP地址，字符串，包括'\0'结束符共32byte
    char                szDevSerial[DH_INTERVIDEO_NSS_SERIAL];  // 前端设备序列号，字符串，包括'\0'结束符共32byte
    char                szUserName[DH_INTERVIDEO_NSS_USER];
    char                szPwd[DH_INTERVIDEO_NSS_PWD];
} DHDEV_INTERVIDEO_NSS_CFG;

// 平台接入配置 － 天地阳光
typedef struct  
{
    char               szDevSerial[DH_INTERVIDEO_AMP_DEVICESERIAL];                  //前端设备序列号,即编码器的序列号,该参数只读
    char               szDevName[DH_INTERVIDEO_AMP_DEVICENAME];                      //前端设备名称,编码器的名称,该参数只读
    char               szRegUserName[DH_INTERVIDEO_AMP_USER];                        //注册服务器用户名
    char               szRegPwd[DH_INTERVIDEO_AMP_PWD];                              //注册服务器密码
    BYTE               bReserved[128];
} DHDEV_INTERVIDEO_AMP_CFG;  
////////////////////////////////HDVR专用//////////////////////////////////
// 报警联动扩展结构体
typedef struct 
{
    /* 消息处理方式，可以同时多种处理方式，包括
     * 0x00000001 - 报警上传
     * 0x00000002 - 联动录象
     * 0x00000004 - 云台联动
     * 0x00000008 - 发送邮件
     * 0x00000010 - 本地轮巡
     * 0x00000020 - 本地提示
     * 0x00000040 - 报警输出
     * 0x00000080 - Ftp上传
     * 0x00000100 - 蜂鸣
     * 0x00000200 - 语音提示
     * 0x00000400 - 抓图
    */

    /* 当前报警所支持的处理方式，按位掩码表示 */
    DWORD               dwActionMask;

    /* 触发动作，按位掩码表示，具体动作所需要的参数在各自的配置中体现 */
    DWORD               dwActionFlag;
    
    /* 报警触发的输出通道，报警触发的输出，为1表示触发该输出 */ 
    BYTE                byRelAlarmOut[DH_MAX_ALARMOUT_NUM_EX];
    DWORD               dwDuration;                                 /* 报警持续时间 */

    /* 联动录象 */
    BYTE                byRecordChannel[DH_MAX_VIDEO_IN_NUM_EX];    /* 报警触发的录象通道，为1表示触发该通道 */
    DWORD               dwRecLatch;                                 /* 录象持续时间 */

    /* 抓图通道 */
    BYTE                bySnap[DH_MAX_VIDEO_IN_NUM_EX];
    /* 轮巡通道 */
    BYTE                byTour[DH_MAX_VIDEO_IN_NUM_EX];             /* 轮巡通道 0-31路*/

    /* 云台联动 */
    DH_PTZ_LINK         struPtzLink[DH_MAX_VIDEO_IN_NUM_EX];
    DWORD               dwEventLatch;                               /* 联动开始延时时间，s为单位，范围是0~15，默认值是0 */
    /* 报警触发的无线输出通道，报警触发的输出，为1表示触发该输出 */ 
    BYTE                byRelWIAlarmOut[DH_MAX_ALARMOUT_NUM_EX];
    BYTE                bMessageToNet;
    BYTE                bMMSEn;                                     /*短信报警使能*/
    BYTE                bySnapshotTimes;                            /*短信发送抓图张数 */
    BYTE                bMatrixEn;                                  /*!< 矩阵使能 */
    DWORD               dwMatrix;                                   /*!< 矩阵掩码 */            
    BYTE                bLog;                                       /*!< 日志使能，目前只有在WTN动态检测中使用 */
    BYTE                bSnapshotPeriod;                            /*!<抓图帧间隔，每隔多少帧抓一张图片，一定时间内抓拍的张数还与抓图帧率有关。0表示不隔帧，连续抓拍。*/
    BYTE                byTour2[DH_MAX_VIDEO_IN_NUM_EX];            /* 轮巡通道 32-63路*/
    BYTE                byEmailType;                                /*<0，图片附件，1，录像附件>*/
    BYTE                byEmailMaxLength;                           /*<附件录像时的最大长度，单位MB>*/
    BYTE                byEmailMaxTime;                             /*<附件是录像时最大时间长度，单位秒>*/
    BYTE                byReserved[475];   
} DH_MSG_HANDLE_EX;

// 外部报警扩展
typedef struct
{
    BYTE                byAlarmType;                        // 报警器类型，0：常闭，1：常开
    BYTE                byAlarmEn;                          // 报警使能
    BYTE                byReserved[2];                        
    DH_TSECT            stSect[DH_N_WEEKS][DH_N_REC_TSECT]; //NSP
    DH_MSG_HANDLE_EX    struHandle;                         // 处理方式
} DH_ALARMIN_CFG_EX, *LPDHDEV_ALARMIN_CFG_EX; 

// 动态检测报警
typedef struct 
{
    BYTE                byMotionEn;                         // 动态检测报警使能
    BYTE                byReserved;
    WORD                wSenseLevel;                        // 灵敏度
    WORD                wMotionRow;                         // 动态检测区域的行数
    WORD                wMotionCol;                         // 动态检测区域的列数
    BYTE                byDetected[DH_MOTION_ROW][DH_MOTION_COL]; // 检测区域，最多32*32块区域
    DH_TSECT            stSect[DH_N_WEEKS][DH_N_REC_TSECT]; //NSP
    DH_MSG_HANDLE_EX        struHandle;                     //处理方式
} DH_MOTION_DETECT_CFG_EX;


// 火警报警
typedef struct
{
    BOOL                byFireEn;              // 火警报警时能；
    DH_MSG_HANDLE_EX    struHandle;            // 处理方式
    BYTE                byReserved[128];
}DHDEV_FIRE_ALARM_CFG;

// 静态检测报警 
typedef struct 
{
    BYTE                byStaticEn;                         // 静态检测报警使能
    BYTE                byLatch;                            // 检测延时(范围0-127，若超出范围则用nLatch)    
    WORD                wSenseLevel;                        // 灵敏度
    WORD                wStaticRow;                         // 静态检测区域的行数
    WORD                wStaticCol;                         // 静态检测区域的列数
    BYTE                byDetected[DH_STATIC_ROW][DH_STATIC_COL]; // 检测区域，最多32*32块区域
    DH_TSECT            stSect[DH_N_WEEKS][DH_N_REC_TSECT]; // NSP
    DH_MSG_HANDLE_EX    struHandle;                         // 处理方式
    int                 nLatch;                             // 检测延时
    BYTE                bReserved[64];                      // 保留字段
} DH_STATIC_DETECT_CFG_EX;

// ACC断线报警事件配置
typedef struct _DHDEV_ACC_POWEROFF_CFG
{
    BOOL                bEnable;               // ACC断线报警使能
    int                 nDelayTime;            // ACC断线报警延时时间,单位分钟
    DH_MSG_HANDLE_EX    struHandle;            // 处理方式
    BYTE                Reserved[128];         // 保留字段
}DHDEV_ACC_POWEROFF_CFG;

// 防爆盒报警事件配置
typedef struct _DHDEV_EXPLOSION_PROOF_CFG
{
    BOOL                bEnable;               // 防爆盒报警使能
    DH_MSG_HANDLE_EX    struHandle;            // 处理方式
    BYTE                Reserved[128];         // 保留字段
}DHDEV_EXPLOSION_PROOF_CFG;

// Raid事件配置
typedef struct _DHDEV_RAID_EVENT_CFG
{
    BOOL                bEnable;               // Raid事件使能
    DH_MSG_HANDLE_EX    struHandle;            // 处理方式
    BYTE                Reserved[128];         // 保留字段
}DHDEV_RAID_EVENT_CFG;

// 视频丢失报警
typedef struct
{
    BYTE                byAlarmEn;                          // 视频丢失报警使能
    BYTE                byReserved[3];
    DH_TSECT            stSect[DH_N_WEEKS][DH_N_REC_TSECT]; // NSP
    DH_MSG_HANDLE_EX    struHandle;                         // 处理方式
} DH_VIDEO_LOST_CFG_EX;

// 图像遮挡报警
typedef struct
{
    BYTE                byBlindEnable;                      // 使能
    BYTE                byBlindLevel;                       // 灵敏度1-6
    BYTE                byReserved[2];
    DH_TSECT            stSect[DH_N_WEEKS][DH_N_REC_TSECT]; // NSP
    DH_MSG_HANDLE_EX    struHandle;                         // 处理方式
} DH_BLIND_CFG_EX;

// 硬盘消息(内部报警)
typedef struct 
{
    BYTE                byNoDiskEn;                         // 无硬盘时报警
    BYTE                byReserved_1[3];
    DH_TSECT            stNDSect[DH_N_WEEKS][DH_N_REC_TSECT]; //NSP
    DH_MSG_HANDLE_EX    struNDHandle;                       // 处理方式
    BYTE                byLowCapEn;                         // 硬盘低容量时报警
    BYTE                byLowerLimit;                       // 容量阀值，0-99
    BYTE                byReserved_2[2];
    DH_TSECT            stLCSect[DH_N_WEEKS][DH_N_REC_TSECT]; //NSP
    DH_MSG_HANDLE_EX    struLCHandle;                       // 处理方式
    BYTE                byDiskErrEn;                        // 硬盘故障报警
    BYTE                bDiskNum;
    BYTE                byReserved_3[2];
    DH_TSECT            stEDSect[DH_N_WEEKS][DH_N_REC_TSECT]; //NSP
    DH_MSG_HANDLE_EX    struEDHandle;                       // 处理方式
} DH_DISK_ALARM_CFG_EX;

typedef struct
{
    BYTE                byEnable;
    BYTE                byReserved[3];
    DH_MSG_HANDLE_EX    struHandle;
} DH_NETBROKEN_ALARM_CFG_EX;

// 前端接入配置参数信息
typedef struct __DEV_ENCODER_CFG 
{
    int                 nChannels;                  // 数字通道个数
    DEV_ENCODER_INFO    stuDevInfo[32];             // 各数字通道的前端编码器信息
    BYTE                byHDAbility;                // 数字通道中最多可支持高清视频个数(为0表示不支持高清设置)
                                                    // 注：如果支持高清设置，高清通道为0~N-1，若将N之后的数字通道设置为高清，有可能保存不成功
    BYTE                bTVAdjust;                  // 设备是否支持TV调节, 0:不支持 1:支持.
    BYTE                bDecodeTour;                // 设备是否支持解码轮巡, 0:不支持 大于0:表示前端支持轮巡最大设备数.
    BYTE                bRemotePTZCtl;              // 指示是否支持远程云台控制。

    char                reserved[12];
} DEV_ENCODER_CFG, *LPDEV_ENCODER_CFG;

// 前端接入配置参数信息扩展
typedef struct __DEV_ENCODER_CFG_EX 
{
    int                 nChannels;                  // 数字通道个数
    DEV_ENCODER_INFO    stuDevInfo[128];            // 各数字通道的前端编码器信息
    BYTE                byHDAbility;                // 数字通道中最多可支持高清视频个数(为0表示不支持高清设置)
    // 注：如果支持高清设置，高清通道为0~N-1，若将N之后的数字通道设置为高清，有可能保存不成功
    BYTE                bTVAdjust;                  // 设备是否支持TV调节, 0:不支持 1:支持.
    BYTE                bDecodeTour;                // 设备是否支持解码轮巡, 0:不支持 大于0:表示前端支持轮巡最大设备数.
    BYTE                bRemotePTZCtl;              // 指示是否支持远程云台控制。
    char                reserved[256];
} DEV_ENCODER_CFG_EX, *LPDEV_ENCODER_CFG_EX;

// struct 控制器
typedef struct tagDHCONFIG_CONTROLER{
    DH_COMM_PROP        struComm;                        // 串口属性
    BYTE                bLightGroup[DH_MAX_LIGHT_NUM];   // 受控灯数组（灯序号从1开始计数，比如[1,3,8,0…0]表示控制序号为1,3,8的灯
    BYTE                bDeviceAddr;                     // 控制器地址
    BYTE                bComPortType;                    // 串口类型 0:485串口, 1:232串口
    BYTE                bReserved[6];                    // 保留
} DH_CONFIG_CONTROLER;

// 灯光控制配置
typedef struct __DHDEV_LIGHTCONTROL_CFG
{
    DH_CONFIG_CONTROLER    struControlers[DH_MAX_CONTROLER_NUM];  // 控制配置
    BYTE                   bControlerNum;                         // 有效控制器数目
    BYTE                   bReserved[1023];                       // 保留
} DHDEV_LIGHTCONTROL_CFG, *LPDHDEV_LIGHTCONTROL_CFG;

// 3G流量信息配置
typedef struct
{
    int                 nStrategy;       //流量使用策略, 0:按流量包月 1:按时间包月
    int                 nUpLimit;        //流量使用上限, 按流量: 单位MB 按时间: 单位小时
    int                 nreserved[22];   //保留字节
}DHDEV_3GFLOW_INFO_CFG;

// IPv6配置
typedef struct 
{
    char               szLinkAddr[44];      // 链路地址: 字符串, 长度为44;(局域网内每台主机拥有唯一的链路地址，只读)
    char               szHostIP[40];        // 主机IP
    DWORD              dwPreFix;            // 网络前缀（范围：1-128，可读可写）
    char               szGateWay[40];       // 默认网关
    BOOL               bAutoGet;            // 自动获取使能
    char               szPrimaryDns[40];    // 首选DNS
    char               szSecondDns[40];     // 备选DNS
    char               cReserved[256];      // 保留字段
}DHDEV_IPV6_CFG;

//紧急存储配置
typedef struct __DEV_URGENCY_RECORD_CFG
{
    DWORD   dwSize;             // 结构体大小
    BOOL    bEnable;            // 是否使能，1使能，0不使能
    UINT    nMaxRecordTime;     // 最大录像时间，单位秒
}DHDEV_URGENCY_RECORD_CFG;

// 电梯运行参数配置
typedef struct __DEV_ELEVATOR_ATTRI_CFG
{
    DWORD   dwSize;             // 结构体大小
    UINT    nMAXFloorNum;       //最大楼层 最小2
    UINT    nFloorDelayTime;    //停靠判断时间,5-60；保持此时间长度认为是电梯停靠此楼层。
    UINT    nIntervalTime;      //电梯上行或下行经过一层的最大时间，如果超过此时间，则认为电梯故障，轿厢停止了两层之间。
}DHDEV_ELEVATOR_ATTRI_CFG;

// 虚拟摄像头状态查询
typedef struct tagDHDEV_VIRTUALCAMERA_STATE_INFO
{
    DWORD              nStructSize;                  // 结构体大小
    int                nChannelID;                   // 通道号
    CONNECT_STATE      emConnectState;               // 连接状态
    UINT               uiPOEPort;                    // 此虚拟摄像头所连接的POE端口号，0表示不是POE连接 
    char               szDeviceName[64];             // 设备名称
    char               szDeviceType[128];            // 设备类型
    char               szSystemType[128];            // 系统版本
    char               szSerialNo[DH_SERIALNO_LEN];  // 序列号
    int                nVideoInput;                  // 视频输入
    int                nAudioInput;                  // 音频输入
    int                nAlarmOutput;                 // 外部报警
}DHDEV_VIRTUALCAMERA_STATE_INFO;

// 设备工作视频/线圈模式状态等信息查询
typedef struct tagDHDEV_TRAFFICWORKSTATE_INFO
{
    DWORD                nStructSize;      // 结构体大小
    int                  nChannelID;       // 通道号
    DH_TRAFFIC_SNAP_MODE emSnapMode;       // 抓拍模式
}DHDEV_TRAFFICWORKSTATE_INFO;

/////////////////////////////////智能交通图片订阅接口参数/////////////////////////////////
typedef struct RESERVED_DATA_INTEL_BOX
{
    DWORD  dwEventCount;        //事件个数
    DWORD* dwPtrEventType;      //指向连续的事件类型的值。空间由用户自己申请。
    DWORD  dwInternalTime;      // 图片上传间隔时间，单位：s
    BYTE   bReserved[1020];     //保留字节
}ReservedDataIntelBox;

#define RESERVED_TYPE_FOR_INTEL_BOX 0x00000001
typedef struct RESERVED_PARA
{
    DWORD   dwType;         //pData的数据类型
                            //当[dwType]为RESERVED_TYPE_FOR_INTEL_BOX 时，pData 对应为结构体ReservedDataIntelBox的地址                    
                            //当[dwType]为...时，[pData]对应...
    void*   pData;          //数据
}ReservedPara;

#define RESERVED_TYPE_FOR_COMMON   0x00000010
typedef struct tagNET_RESERVED_COMMON
{
    DWORD                   dwStructSize;
    ReservedDataIntelBox*   pIntelBox;          // 兼容RESERVED_TYPE_FOR_INTEL_BOX
    DWORD                   dwSnapFlagMask;     // 抓图标志(按位)，0位:"*",1位:"Timing",2位:"Manual",3位:"Marked",4位:"Event",5位:"Mosaic",6位:"Cutout"
}NET_RESERVED_COMMON;

/////////////////////////////////智能球控制接口参数/////////////////////////////////
// 场景结构信息
typedef struct 
{
    DWORD       dwSize;
    int         nScene;     //场景编号
}DHDEV_INTELLI_SCENE_INFO;
// 场景边界限位信息
typedef struct 
{
    DWORD       dwSize;
    int         nScene;     //场景编号
    int         nType;      //0:上边界限位，1:下边界限位，2:左边界，3:右边界
}DHDEV_INTELLI_SCENELIMIT_INFO;
// 手动跟踪目标结构体信息
typedef struct
{
    DWORD       dwSize;
    int         nObjectID;   // 物体ID，-1 表示web上框选的是智能帧上传框外任意位置物体，>=0表示框选的是智能帧上传的物体
    RECT        stuBound;    // 矩形范围，点的坐标归一化到[0,8192]区间
}DHDEV_INTELLI_TRACKOBJECT_INFO;

typedef enum __TRACKCONTROL_TYPE
{
        DH_TRACK_MARKSCENE,        // 标定场景, 对应于DHDEV_INTELLI_SCENE_INFO结构体
        DH_TRACK_GOTOSCENE,        // 转动到场景,对应于DHDEV_INTELLI_SCENE_INFO结构体
        DH_TRACK_MARKSCENELIMIT,   // 标定场景边界限位,对应于DHDEV_INTELLI_SCENELIMIT_INFO结构体
        DH_TRACK_GOTOSCENELIMIT,   // 转动到场景边界限位处,对应于DHDEV_INTELLI_SCENELIMIT_INFO结构体
        DH_TRACK_MARKSCENEMAXZOOM, // 标定场景最大跟踪倍率, 对应于DHDEV_INTELLI_SCENE_INFO结构体
        DH_TRACK_OBJECT,           // 选中场景中的跟踪目标,对应于DHDEV_INTELLI_TRACKOBJECT_INFO机构体
        DH_TRACK_START,            // 开始智能跟踪，无需指定参数信息
        DH_TRACK_STOP,             // 停止智能跟踪，无需指定参数信息
        DH_TRACK_TYPE_NUM,
}DH_TRACKCONTROL_TYPE;
//智能球机控制输入参数
typedef struct tagNET_IN_CONTROL_INTELLITRACKER
{
    DWORD       dwSize;
    int         nChannelID;            // 通道ID
    DH_TRACKCONTROL_TYPE emCtrlType;   // 控制类型
    void*       pCtrlInfo;             // 控制类型对应控制信息结构体指针，参见DH_TRACKCONTROL_TYPE定义。
    int         nMaxLen;               // 控制信息结构体大小
    int         nWaittime;             // 等待超时时间
}NET_IN_CONTROL_INTELLITRACKER;
//智能球机控制输出参数
typedef struct tagNET_OUT_CONTROL_INTELLITRACKER
{
    DWORD       dwSize;
}NET_OUT_CONTROL_INTELLITRACKER;

/////////////////////////////////淘汰类型/////////////////////////////////

// 查询设备工作状态通道信息，相关接口已淘汰，请不要使用
typedef struct
{
    BYTE                byRecordStatic;             // 通道是否在录像；0：不录像，1：手动录像，2：自动录象
    BYTE                bySignalStatic;             // 连接的信号状态；0：正常，1：信号丢失
    BYTE                byHardwareStatic;           // 通道硬件状态；0：正常，1：异常，例如DSP死掉
    char                reserve;
    DWORD               dwBitRate;                  // 实际码率
    DWORD               dwLinkNum;                  // 客户端连接的个数
    DWORD               dwClientIP[DH_MAX_LINK];    // 客户端的IP地址
} NET_DEV_CHANNELSTATE, *LPNET_DEV_CHANNELSTATE;

// 查询设备工作状态，相关接口已淘汰，请不要使用
typedef struct
{
    DWORD                dwDeviceStatic;                    // 设备的状态；0x00：正常，0x01：CPU占用过高，0x02：硬件错误
    NET_DEV_DISKSTATE    stHardDiskStatic[DH_MAX_DISKNUM]; 
    NET_DEV_CHANNELSTATE stChanStatic[DH_MAX_CHANNUM];      //通道的状态
    BYTE                 byAlarmInStatic[DH_MAX_ALARMIN];   //报警端口的状态；0：没有报警，1：有报警
    BYTE                 byAlarmOutStatic[DH_MAX_ALARMOUT]; //报警输出端口的状态；0：没有输出，1：有报警输出
    DWORD                dwLocalDisplay;                    // 本地显示状态；0：正常，1：不正常
} NET_DEV_WORKSTATE, *LPNET_DEV_WORKSTATE;

// 协议信息
typedef struct 
{
    char                 protocolname[12];        // 协议名
    unsigned int         baudbase;                // 波特率
    unsigned char        databits;                // 数据位
    unsigned char        stopbits;                // 停止位
    unsigned char        parity;                  // 校验位
    unsigned char        reserve;
} PROTOCOL_INFO, *LPPROTOCOL_INFO;

// 语音对讲参数配置
typedef struct 
{
    // 音频输入参数
    BYTE                byInFormatTag;            // 编码类型，如PCM
    BYTE                byInChannels;             // 声道数
    WORD                wInBitsPerSample;         // 采样深度                    
    DWORD               dwInSamplesPerSec;        // 采样率

    // 音频输出参数
    BYTE                byOutFormatTag;           // 编码类型，如PCM
    BYTE                byOutChannels;            // 声道数
    WORD                wOutBitsPerSample;        // 采样深度                
    DWORD               dwOutSamplesPerSec;       // 采样率
} DHDEV_TALK_CFG, *LPDHDEV_TALK_CFG;


/////////////////////////////////// 矩阵 ///////////////////////////////////////

#define DH_MATRIX_INTERFACE_LEN         16          // 信号接口名称长度
#define DH_MATRIX_MAX_CARDS             128         // 矩阵子卡最大数量
#define DH_SPLIT_PIP_BASE               1000        // 分割模式画中画的基础值
#define DH_MAX_SPLIT_MODE_NUM           64          // 最大分割模式数
#define DH_MATRIX_MAX_CHANNEL_IN        1500        // 矩阵最大输入通道数
#define DH_MATRIX_MAX_CHANNEL_OUT       256         // 矩阵最大输出通道数
#define DH_DEVICE_NAME_LEN              64          // 设备名称长度
#define DH_MAX_CPU_NUM                  16          // 最大CPU数量
#define DH_MAX_FAN_NUM                  16          // 最大风扇数量
#define DH_MAX_POWER_NUM                16          // 最大电源数量
#define DH_MAX_BATTERY_NUM              16          // 最大电池数量
#define DH_MAX_TEMPERATURE_NUM          32          // 最大温度传感器数量
#define DH_MAX_ISCSI_NAME_LEN           128         // ISCSI名称长度
#define DH_VERSION_LEN                  64          // 版本信息长度
#define DH_MAX_STORAGE_PARTITION_NUM    32          // 存储分区最大数量
#define DH_STORAGE_MOUNT_LEN            64          // 挂载点长度
#define DH_STORAGE_FILE_SYSTEM_LEN      16          // 文件系统名称长度
#define DH_MAX_MEMBER_PER_RAID          32          // RAID成员最大数量
#define DH_DEV_ID_LEN_EX                128         // 设备ID最大长度
#define DH_MAX_BLOCK_NUM                32          // 最大区块数量
#define DH_MAX_SPLIT_WINDOW             128         // 最大分割窗口数量
#define DH_FILE_TYPE_LEN                64          // 文件类型长度
#define DH_DEV_ID_LEN                   128         // 设备ID最大长度
#define DH_DEV_NAME_LEN                 128         // 设备名称最大长度
#define DH_TSCHE_DAY_NUM                8           // 时间表第一维大小, 表示天数
#define DH_TSCHE_SEC_NUM                6           // 时间表第二维大小, 表示时段数
#define DH_SPLIT_INPUT_NUM              256         // 司法设备二级切换时第一级split支持的输入通道数

#define DH_DEVICE_ID_LOCAL              "Local"     // 本地设备ID
#define DH_DEVICE_ID_REMOTE             "Remote"    // 远程设备ID
#define DH_DEVICE_ID_UNIQUE             "Unique"    // 设备内统一编号

// 分割模式
typedef enum tagDH_SPLIT_MODE
{
    DH_SPLIT_1 = 1,                                 // 1画面
    DH_SPLIT_2 = 2,                                 // 2画面
    DH_SPLIT_4 = 4,                                 // 4画面
    DH_SPLIT_6 = 6,                                 // 6画面
    DH_SPLIT_8 = 8,                                 // 8画面
    DH_SPLIT_9 = 9,                                 // 9画面
    DH_SPLIT_12 = 12,                               // 12画面
    DH_SPLIT_16 = 16,                               // 16画面
    DH_SPLIT_20 = 20,                               // 20画面
    DH_SPLIT_25 = 25,                               // 25画面
    DH_SPLIT_36 = 36,                               // 36画面
    DH_SPLIT_64 = 64,                               // 64画面
    DH_SPLIT_144 = 144,                             // 144画面
    DH_PIP_1 = DH_SPLIT_PIP_BASE + 1,               // 画中画模式, 1个全屏大画面+1个小画面窗口
    DH_PIP_3 = DH_SPLIT_PIP_BASE + 3,               // 画中画模式, 1个全屏大画面+3个小画面窗口
    DH_SPLIT_FREE = DH_SPLIT_PIP_BASE * 2,          // 自由开窗模式，可以自由创建、关闭窗口，自由设置窗口位置和Z轴次序
    DH_COMPOSITE_SPLIT_1 = DH_SPLIT_PIP_BASE * 3 + 1,    // 融合屏成员1分割
    DH_COMPOSITE_SPLIT_4 = DH_SPLIT_PIP_BASE * 3 + 4,    // 融合屏成员4分割
} DH_SPLIT_MODE;

#define DH_PROTOCOL_DAHUA2 DH_PROTOCOL_PRIVATE2
#define DH_PROTOCOL_DAHUA3 DH_PROTOCOL_PRIVATE3

// 设备协议类型
typedef enum tagDH_DEVICE_PROTOCOL
{
    DH_PROTOCOL_PRIVATE2,                   // 私有2代协议
    DH_PROTOCOL_PRIVATE3,                   // 私有3代协议
    DH_PROTOCOL_ONVIF,                      // Onvif    
    DH_PROTOCOL_VNC,                        // 虚拟网络计算机
    DH_PROTOCOL_TS,                         // 标准TS
    
    DH_PROTOCOL_PRIVATE = 100,              // 私有协议        
    DH_PROTOCOL_AEBELL,                     // 美电贝尔        
    DH_PROTOCOL_PANASONIC,                  // 松下        
    DH_PROTOCOL_SONY,                       // 索尼        
    DH_PROTOCOL_DYNACOLOR,                  // Dynacolor        
    DH_PROTOCOL_TCWS,                       // 天城威视        
    DH_PROTOCOL_SAMSUNG,                    // 三星        
    DH_PROTOCOL_YOKO,                       // YOKO        
    DH_PROTOCOL_AXIS,                       // 安讯视        
    DH_PROTOCOL_SANYO,                      // 三洋               
    DH_PROTOCOL_BOSH,                       // Bosch        
    DH_PROTOCOL_PECLO,                      // Peclo        
    DH_PROTOCOL_PROVIDEO,                   // Provideo        
    DH_PROTOCOL_ACTI,                       // ACTi        
    DH_PROTOCOL_VIVOTEK,                    // Vivotek        
    DH_PROTOCOL_ARECONT,                    // Arecont        
    DH_PROTOCOL_PRIVATEEH,                  // PrivateEH            
    DH_PROTOCOL_IMATEK,                     // IMatek        
    DH_PROTOCOL_SHANY,                      // Shany        
    DH_PROTOCOL_VIDEOTREC,                  // 动力盈科        
    DH_PROTOCOL_URA,                        // Ura        
    DH_PROTOCOL_BITICINO,                   // Bticino         
    DH_PROTOCOL_ONVIF2,                     // Onvif协议类型, 同DH_PROTOCOL_ONVIF    
    DH_PROTOCOL_SHEPHERD,                   // 视霸        
    DH_PROTOCOL_YAAN,                       // 亚安        
    DH_PROTOCOL_AIRPOINT,                   // Airpop        
    DH_PROTOCOL_TYCO,                       // TYCO        
    DH_PROTOCOL_XUNMEI,                     // 讯美        
    DH_PROTOCOL_HIKVISION,                  // 海康        
    DH_PROTOCOL_LG,                         // LG        
    DH_PROTOCOL_AOQIMAN,                    // 奥奇曼        
    DH_PROTOCOL_BAOKANG,                    // 宝康            
    DH_PROTOCOL_WATCHNET,                   // Watchnet        
    DH_PROTOCOL_XVISION,                    // Xvision        
    DH_PROTOCOL_FUSITSU,                    // 富士通        
    DH_PROTOCOL_CANON,                      // Canon        
    DH_PROTOCOL_GE,                         // GE        
    DH_PROTOCOL_Basler,                     // 巴斯勒        
    DH_PROTOCOL_Patro,                      // 帕特罗        
    DH_PROTOCOL_CPKNC,                      // CPPLUS K系列        
    DH_PROTOCOL_CPRNC,                      // CPPLUS R系列        
    DH_PROTOCOL_CPUNC,                      // CPPLUS U系列        
    DH_PROTOCOL_CPPLUS,                     // CPPLUS IPC    
    DH_PROTOCOL_XunmeiS,                    // 讯美s,实际协议为Onvif        
    DH_PROTOCOL_GDDW,                       // 广东电网        
    DH_PROTOCOL_PSIA,                       // PSIA        
    DH_PROTOCOL_GB2818,                     // GB2818            
    DH_PROTOCOL_GDYX,                       // GDYX        
    DH_PROTOCOL_OTHER,                      // 由用户自定义   
} DH_DEVICE_PROTOCOL;

// 一屏幕的分割模式信息
typedef struct tagDH_SPLIT_MODE_INFO
{
    DWORD               dwSize;
    DH_SPLIT_MODE       emSplitMode;            // 分割模式
    int                 nGroupID;               // 分组序号
    DWORD               dwDisplayType;          // 显示类型；具体见DH_SPLIT_DISPLAY_TYPE（注释各模式下显示内容由"PicInPic"决定, 各模式下显示内容按NVD旧有规则决定（即DisChn字段决定）。兼容，没有这一个项时，默认为普通显示类型,即"General"）
} DH_SPLIT_MODE_INFO;

// 分割能力
typedef struct tagDH_SPLIT_CAPS 
{
    DWORD               dwSize;
    int                 nModeCount;                             // 支持的分割模式数量
    DH_SPLIT_MODE       emSplitMode[DH_MAX_SPLIT_MODE_NUM];     // 支持的分割模式
    int                 nMaxSourceCount;                        // 最大显示源配置数
    int                 nFreeWindowCount;                       // 支持的最大自由开窗数目
    BOOL                bCollectionSupported;                   // 是否支持区块收藏
    DWORD               dwDisplayType;                          // 掩码表示多个显示类型，具体见DH_SPLIT_DISPLAY_TYPE（注释各模式下显示内容由"PicInPic"决定, 各模式下显示内容按NVD旧有规则决定（即DisChn字段决定）。兼容，没有这一个项时，默认为普通显示类型,即"General"）
    int                 nPIPModeCount;                          // 画中画支持的分割模式数量
    DH_SPLIT_MODE       emPIPSplitMode[DH_MAX_SPLIT_MODE_NUM];  // 画中画支持的分割模式
    int                 nInputChannels[DH_SPLIT_INPUT_NUM];     // 支持的输入通道
    int                 nInputChannelCount;                     // 支持的输入通道个数, 0表示没有输入通道限制
} DH_SPLIT_CAPS;

// 级联权限验证信息
typedef struct tagDH_CASCADE_AUTHENTICATOR
{
    DWORD               dwSize;
    char                szUser[DH_NEW_USER_NAME_LENGTH];        // 用户名
    char                szPwd[DH_NEW_USER_PSW_LENGTH];          // 密码
    char                szSerialNo[DH_SERIALNO_LEN];            // 设备序列号
} DH_CASCADE_AUTHENTICATOR;

// 显示源
typedef struct tagDH_SPLIT_SOURCE
{
    DWORD               dwSize;
    BOOL                bEnable;                                // 使能
    char                szIp[DH_MAX_IPADDR_LEN];                // IP, 空表示没有设置
    char                szUser[DH_USER_NAME_LENGTH];            // 用户名
    char                szPwd[DH_USER_PSW_LENGTH];              // 密码
    int                 nPort;                                  // 端口
    int                 nChannelID;                             // 通道号
    int                 nStreamType;                            // 视频码流, -1-自动, 0-主码流, 1-辅码流1, 2-辅码流2, 3-辅码流3, 4-snap, 5-预览
    int                 nDefinition;                            // 清晰度, 0-标清, 1-高清
    DH_DEVICE_PROTOCOL  emProtocol;                             // 协议类型
    char                szDevName[DH_DEVICE_NAME_LEN];          // 设备名称
    int                 nVideoChannel;                          // 视频输入通道数
    int                 nAudioChannel;                          // 音频输入通道数
    //--------------------------------------------------------------------------------------
    // 以下只对解码器有效
    BOOL                bDecoder;                               // 是否是解码器
    BYTE                byConnType;                             // -1: auto, 0：TCP；1：UDP；2：组播
    BYTE                byWorkMode;                             // 0：直连；1：转发
    WORD                wListenPort;                            // 指示侦听服务的端口，转发时有效; byConnType为组播时，则作为多播端口
    char                szDevIpEx[DH_MAX_IPADDR_OR_DOMAIN_LEN]; // szDevIp扩展，前端DVR的IP地址(可以输入域名)
    BYTE                bySnapMode;                             // 抓图模式(nStreamType==4时有效) 0：表示请求一帧,1：表示定时发送请求
    BYTE                byManuFactory;                          // 目标设备的生产厂商, 具体参考EM_IPC_TYPE类
    BYTE                byDeviceType;                           // 目标设备的设备类型, 0:IPC
    BYTE                byDecodePolicy;                         // 目标设备的解码策略, 0:兼容以前
                                                                // 1:实时等级高 2:实时等级中
                                                                // 3:实时等级低 4:默认等级
                                                                // 5:流畅等级高 6:流畅等级中
                                                                // 7:流畅等级低
    //--------------------------------------------------------------------------------------
    DWORD               dwHttpPort;                             // Http端口号, 0-65535
    DWORD               dwRtspPort;                             // Rtsp端口号, 0-65535
    char                szChnName[DH_DEVICE_NAME_LEN];          // 远程通道名称, 只有读取到的名称不为空时才可以修改该通道的名称
    char                szMcastIP[DH_MAX_IPADDR_LEN];           // 多播IP地址, byConnType为组播时有效
    char                szDeviceID[DH_DEV_ID_LEN_EX];           // 设备ID, ""-null, "Local"-本地通道, "Remote"-远程通道, 或者填入具体的RemoteDevice中的设备ID
    BOOL                bRemoteChannel;                         // 是否远程通道(只读)
    unsigned int        nRemoteChannelID;                       // 远程通道ID(只读), bRemoteChannel=TRUE时有效
    char                szDevClass[DH_DEV_TYPE_LEN];            // 设备类型, 如IPC, DVR, NVR等
    char                szDevType[DH_DEV_TYPE_LEN];             // 设备具体型号, 如IPC-HF3300
    char                szMainStreamUrl[MAX_PATH];              // 主码流url地址, byManuFactory为DH_IPC_OTHER时有效
    char                szExtraStreamUrl[MAX_PATH];             // 辅码流url地址, byManuFactory为DH_IPC_OTHER时有效
    int                 nUniqueChannel;                         // 设备内统一编号的唯一通道号, 只读
    DH_CASCADE_AUTHENTICATOR stuCascadeAuth;                    // 级联认证信息, 设备ID为"Local/Cascade/SerialNo"时有效, 其中SerialNo是设备序列号
} DH_SPLIT_SOURCE;

// 视频输出能力集
typedef struct tagDH_VIDEO_OUT_CAPS 
{
    DWORD               dwSize;
    BOOL                bColor;                                 // 是否支持输出颜色设置
    BOOL                bMargin;                                // 是否支持边界设置
    int                 nLayers;                                // 支持同时显示的图层数
    BOOL                bPowerMode;                             // 是否支持电源控制
    int                 bSplitMode;                             // 支持的画面分割模式, 0-单画面, 1-'#'字型模式(包括单画面), 2-任意模式
} DH_VIDEO_OUT_CAPS;

// 颜色RGBA
typedef struct tagDH_COLOR_RGBA
{
    int                 nRed;                       // 红
    int                 nGreen;                     // 绿
    int                 nBlue;                      // 蓝
    int                 nAlpha;                     // 透明
} DH_COLOR_RGBA;

// 颜色BCSH
typedef struct tagDH_COLOR_BCSH 
{
    int                 nBirghtness;                // 亮度
    int                 nContrast;                  // 对比度
    int                 nSaturation;                // 饱和度
    int                 nHue;                       // 色调
} DH_COLOR_BCSH;

// 尺寸
typedef struct tagDH_SIZE 
{
    int                 nWidth;                     // 宽度
    int                 nHeight;                    // 高度
} DH_SIZE;

// 热拔插模式
typedef struct tagDH_HOT_PLUG_MODE
{
    DWORD               dwSize;
    int                 nMode;                      // 热拔插模式, 0-热插拔模式, 1-强制输出模式
} DH_HOT_PLUG_MODE;

// 视频输出选项
typedef struct tagDH_VIDEO_OUT_OPT
{
    DWORD               dwSize;
    DH_RECT*            pstuMargin;                 // 边界范围
    DH_COLOR_BCSH*      pstuColor;                  // 输出颜色
    DH_COLOR_RGBA*      pstuBackground;             // 背景色
    DH_SIZE*            pstuSize;                   // 输出尺寸
    DH_HOT_PLUG_MODE*   pstuHotPlugMode;            // 热拔插模式
} DH_VIDEO_OUT_OPT;

// 产品定义
typedef struct tagDH_PRODUCTION_DEFNITION
{
    DWORD               dwSize;
    int                 nVideoInChannel;                        // 视频输入通道数
    int                 nVideoOutChannel;                       // 视频输出通道数
    int                 nRemoteDecChannel;                      // 远程解码通道数
    char                szDevType[DH_DEV_TYPE_LEN];             // 设备类型
    char                szVendor[DH_MAX_NAME_LEN];              // OEM客户
    int                 nOEMVersion;                            // OEM版本
    int                 nMajorVerion;                           // 主版本号
    int                 nMinorVersion;                          // 次版本号
    int                 nRevision;                              // 修订版本
    char                szWebVerion[DH_MAX_NAME_LEN];           // Web版本
    char                szDefLanguage[DH_MAX_NAME_LEN];         // 默认语言
    NET_TIME            stuBuildDateTime;                       // 发布时间, 精确到秒
    int                 nAudioInChannel;                        // 音频输入通道数
    int                 nAudioOutChannel;                       // 音频输出通道数
    BOOL                bGeneralRecord;                         // 是否支持定时存储
    BOOL                bLocalStore;                            // 是否支持本地存储
    BOOL                bRemoteStore;                           // 是否支持网络存储
    BOOL                bLocalurgentStore;                      // 是否支持紧急存储到本地
    BOOL                bRealtimeCompress;                      // 是否支持实时压缩存储
    DWORD               dwVideoStandards;                       // 支持的视频制式列表, bit0-PAL, bit1-NTSC
    int                 nDefVideoStandard;                      // 默认视频制式, 0-PAL, 1-NTSC
    int                 nMaxExtraStream;                        // 最大辅码流路数
    int                 nRemoteRecordChannel;                   // 远程录像通道数
    int                 nRemoteSnapChannel;                     // 远程抓图通道数
    int                 nRemoteVideoAnalyseChannel;             // 远程视频分析通道数
    int                 nRemoteTransmitChannel;                 // 远程实时流转发最大通道数
    int                 nRemoteTransmitFileChannel;             // 远程文件流竹筏通道通道数
    int                 nStreamTransmitChannel;                 // 最大网络传输通道总数
    int                 nStreamReadChannel;                     // 最大读文件流通道总数
    int                 nMaxStreamSendBitrate;                  // 最大码流网络发送能力, kbps
    int                 nMaxStreamRecvBitrate;                  // 最大码流网络接口能力, kbps
    BOOL                bCompressOldFile;                       // 是否压缩旧文件, 去除P帧, 保留I帧
    BOOL                bRaid;                                  // 是否支持RAID
    int                 nMaxPreRecordTime;                      // 最大预录时间, s
    BOOL                bPtzAlarm;                              // 是否支持云台报警
    BOOL                bPtz;                                   // 是否支持云台
    BOOL                bATM;                                   // 是否显示ATM相关功能
    BOOL                b3G;                                    // 是否支持3G模块
    BOOL                bNumericKey;                            // 是否带数字键
    BOOL                bShiftKey;                              // 是否带Shift键
    BOOL                bCorrectKeyMap;                         // 数字字母映射表是否正确
    BOOL                bNewATM;                                // 新的二代ATM前面板
    BOOL                bDecoder;                               // 是否是解码器
    DEV_DECODER_INFO    stuDecoderInfo;                         // 解码器信息, bDecoder=true时有效
    int                 nVideoOutputCompositeChannels;          // 融合屏输出通道上限
    BOOL                bSupportedWPS;                          // 是否支持WPS功能
    int                 nVGAVideoOutputChannels;                // VGA视频输出通道数
    int                 nTVVideoOutputChannels;                 // TV视频输出通道数
    int                 nMaxRemoteInputChannels;                // 最大远程通道数
    int                 nMaxMatrixInputChannels;                // 最大矩阵通道数
    int                 nMaxRoadWays;                           // 智能交通最大车道数 1~6
    int                 nMaxParkingSpaceScreen;                 // 和相机对接最多支持的区域屏个数 0~20

    int                 nPtzHorizontalAngleMin;                 // 云台水平最小角度, [0-360]
    int                 nPtzHorizontalAngleMax;                 // 云台水平最大角度, [0-360]
    int                 nPtzVerticalAngleMin;                   // 云台垂直最小角度, [-90,90]
    int                 nPtzVerticalAngleMax;                   // 云台垂直最大角度, [-90,90]
    BOOL                bPtzFunctionMenu;                       // 是否支持云台功能菜单
    BOOL                bLightingControl;                       // 是否支持灯光控制
    DWORD               dwLightingControlMode;                  // 手动灯光控制模式, 按位, 见NET_LIGHTING_CTRL_ON_OFF
    int                 nNearLightNumber;                       // 近光灯组数量, 0表示不支持
    int                 nFarLightNumber;                        // 远光灯组数量, 0表示不支持
    BOOL                bFocus;                                 // 是否支持控制聚焦
    BOOL                bIris;                                  // 是否支持控制光圈
    char                szPtzProtocolList[DH_COMMON_STRING_1024];// 云台支持的协议列表, 可以是多个, 每个用';'分隔
    BOOL                bRainBrushControl;                      // 是否支持雨刷控制
    int                 nBrushNumber;                           // 雨刷数量, 为0时表示不支持
    int                 nLowerMatrixInputChannels[DH_MAX_LOWER_MITRIX_NUM]; // 下位矩阵视频输入通道, 下标对应矩阵编号
    int                 nLowerMatrixOutputChannels[DH_MAX_LOWER_MITRIX_NUM];// 下位矩阵视频输出通道, 下标对应矩阵编号
} DH_PRODUCTION_DEFNITION;

// 手动灯光控制模式
#define NET_LIGHTING_CTRL_ON_OFF                0x01            // 直接开关模式
#define NET_LIGHTING_CTRL_ADJUST_BRIGHTNESS     0x02            // 手动调节亮度模式
#define NET_LIGHTING_CTRL_ZOOM_PRIO             0x04            // 倍率优先


// 矩阵子卡类型, 多种类型可以组合
#define DH_MATRIX_CARD_MAIN                 0x10000000          // 主卡
#define DH_MATRIX_CARD_INPUT                0x00000001          // 输入卡
#define DH_MATRIX_CARD_OUTPUT               0x00000002          // 输出卡
#define DH_MATRIX_CARD_ENCODE               0x00000004          // 编码卡
#define DH_MATRIX_CARD_DECODE               0x00000008          // 解码卡
#define DH_MATRIX_CARD_CASCADE              0x00000010          // 级联卡
#define DH_MATRIX_CARD_INTELLIGENT          0x00000020          // 智能卡
#define DH_MATRIX_CARD_ALARM                0x00000040          // 报警卡

// 矩阵子卡信息
typedef struct tagDH_MATRIX_CARD
{
    DWORD               dwSize;
    BOOL                bEnable;                                // 是否有效
    DWORD               dwCardType;                             // 子卡类型
    char                szInterface[DH_MATRIX_INTERFACE_LEN];   // 信号接口类型, "CVBS", "VGA", "DVI"...
    char                szAddress[DH_MAX_IPADDR_OR_DOMAIN_LEN]; // 设备ip或域名, 无网络接口的子卡可以为空
    int                 nPort;                                  // 端口号, 无网络接口的子卡可以为0
    int                 nDefinition;                            // 清晰度, 0=标清, 1=高清
    int                 nVideoInChn;                            // 视频输入通道数
    int                 nAudioInChn;                            // 音频输入通道数
    int                 nVideoOutChn;                           // 视频输出通道数
    int                 nAudioOutChn;                           // 音频输出通道数
    int                 nVideoEncChn;                           // 视频编码通道数
    int                 nAudioEncChn;                           // 音频编码通道数
    int                 nVideoDecChn;                           // 视频解码通道数
    int                 nAudioDecChn;                           // 音频解码通道数
    int                 nStauts;                                // 状态: -1-未知, 0-正常, 1-无响应, 2-网络掉线, 3-冲突, 4-正在升级, 5-链路状态异常, 6-子板背板未插好
    int                 nCommPorts;                             // 串口数
    int                 nVideoInChnMin;                         // 视频输入通道号最小值
    int                 nVideoInChnMax;                         // 视频输入通道号最大值
    int                 nAudioInChnMin;                         // 音频输入通道号最小值
    int                 nAudioInChnMax;                         // 音频输入通道号最大值
    int                 nVideoOutChnMin;                        // 视频输出通道号最小值
    int                 nVideoOutChnMax;                        // 视频输出通道号最大值
    int                 nAudioOutChnMin;                        // 音频输出通道号最小值
    int                 nAudioOutChnMax;                        // 音频输出通道号最大值    
    int                 nVideoEncChnMin;                        // 视频编码通道号最小值
    int                 nVideoEncChnMax;                        // 视频编码通道号最大值
    int                 nAudioEncChnMin;                        // 音频编码通道号最小值
    int                 nAudioEncChnMax;                        // 音频编码通道号最大值
    int                 nVideoDecChnMin;                        // 视频解码通道号最小值
    int                 nVideoDecChnMax;                        // 视频解码通道号最大值
    int                 nAudioDecChnMin;                        // 音频解码通道号最小值
    int                 nAudioDecChnMax;                        // 音频解码通道号最大值
    int                 nCascadeChannels;                       // 级联通道数
    int                 nCascadeChannelBitrate;                 // 级联通道带宽, 单位Mbps
    int                 nAlarmInChnCount;                       // 报警输入通道数
    int                 nAlarmInChnMin;                         // 报警输入通道号最小值
    int                 nAlarmInChnMax;                         // 报警输入通道号最大值
    int                 nAlarmOutChnCount;                      // 报警输出通道数
    int                 nAlarmOutChnMin;                        // 报警输入通道号最小值
    int                 nAlarmOutChnMax;                        // 报警输入通道号最大值
    int                 nVideoAnalyseChnCount;                  // 智能分析通道数
    int                 nVideoAnalyseChnMin;                    // 智能分析通道号最小值
    int                 nVideoAnalyseChnMax;                    // 智能分析通道号最大值
    int                 nCommPortMin;                           // 串口号最小值
    int                 nCommPortMax;                           // 串口号最大值
    char                szVersion[DH_COMMON_STRING_32];         // 版本信息
    NET_TIME            stuBuildTime;                           // 编译时间
} DH_MATRIX_CARD;

// 矩阵子卡列表
typedef struct tagDH_MATRIX_CARD_LIST 
{
    DWORD               dwSize;
    int                 nCount;                                 // 子卡数量
    DH_MATRIX_CARD      stuCards[DH_MATRIX_MAX_CARDS];          // 子卡列表
} DH_MATRIX_CARD_LIST;

// 视频输出窗口
typedef struct tagDH_VIDEO_OUT_WINDOW
{
    DWORD               dwSize;
    int                 nBackboardID;               // 背板号
    int                 nScreenID;                  // 屏幕号
    int                 nWindowID;                  // 窗口号
} DH_VIDEO_OUT_WINDOW;

// CLIENT_GetISCSITargets接口输入参数
typedef struct tagDH_IN_ISCSI_TARGETS
{
    DWORD               dwSize;
    const char*         pszAddress;                 // 服务器地址
    int                 nPort;                      // 端口
    const char*         pszUser;                    // 用户名
    const char*         pszPwd;                     // 密码
} DH_IN_ISCSI_TARGETS;

// ISCSI Target信息
typedef struct tagDH_ISCSI_TARGET 
{
    DWORD               dwSize;
    char                szName[DH_MAX_ISCSI_NAME_LEN];              // 名称
    char                szAddress[DH_MAX_IPADDR_OR_DOMAIN_LEN];     // 服务器地址
    char                szUser[DH_NEW_USER_NAME_LENGTH];            // 用户名
    int                 nPort;                                      // 端口
    UINT                nStatus;                                    // 状态, 0-未知, 1-已连接, 2-未连接, 3-连接失败, 4-认证失败, 5-连接超时    
} DH_ISCSI_TARGET;

// CLIENT_GetISCSITargets接口输出参数
typedef struct tagDH_OUT_ISCSI_TARGETS
{
    DWORD               dwSize;
    DH_ISCSI_TARGET*    pstuTargets;                // iscsi数组
    int                 nMaxCount;                  // iscsi数组大小
    int                 nRetCount;                  // 获取到的iscsi信息数
} DH_OUT_ISCSI_TARGETS;

typedef enum tagDH_BITMAP_ACCURACY
{
    BA_DAY ,            //天 
    BA_HOUR ,           //小时
    BA_5MIN ,           //5分钟
}DH_BITMAP_ACCURACY;

#define DH_MAX_BITMAPS        256                        // 位图字节数，DH_MAX_BITMAPS*8位
#define DH_MAX_CHN_NUM        256                        // 最大通道数
//CLIENT_GetBitmap接口输入参数
typedef struct tagDH_IN_BITMAP
{
    DWORD               dwSize;
    NET_TIME            stuStartTime;                   // 开始时间, 精确到秒
    NET_TIME            stuEndTime;                     // 结束时间, 精确到秒
    int                 nChnList[DH_MAX_CHN_NUM];       // [1, …, 10]    通道号列表,-1表示全部通道,0表示列表结束
    DH_BITMAP_ACCURACY  emAccuracy;                     // 位图精度    
}DH_IN_BITMAP;

typedef struct tagDH_BITMAP_INFO
{
    DWORD               dwSize;
    int                 nChnID;                         //通道号，通道号位0，表示列表结束
    BYTE                bBitmap[DH_MAX_BITMAPS];        //位图(每一比特位表示一个查询刻度，由低位向高位填充)
                                                        //支持DH_MAX_BITMAPS * 8个刻度
    int                 nBitNum;                        //获取的位图位数
}DH_BITMAP_INFO;

//CLIENT_GetBitmap接口输出参数
typedef struct tagDH_OUT_BITMAP
{
    DWORD               dwSize;
    DH_BITMAP_INFO      *pstBitmapInfos;
    int                 nGetBitmapInfo;
    int                 nMaxBitmapInfo;    
}DH_OUT_BITMAP;

// 存储设备名称
typedef struct tagDH_STORAGE_DEVICE_NAME 
{
    DWORD               dwSize;
    char                szName[DH_STORAGE_NAME_LEN];
} DH_STORAGE_DEVICE_NAME;

// RAID状态
#define DH_RAID_STATE_ACTIVE            0x00000001
#define DH_RAID_STATE_INACTIVE          0x00000002
#define DH_RAID_STATE_CLEAN             0x00000004
#define DH_RAID_STATE_FAILED            0x00000008
#define DH_RAID_STATE_DEGRADED          0x00000010
#define DH_RAID_STATE_RECOVERING        0x00000020
#define DH_RAID_STATE_RESYNCING         0x00000040
#define DH_RAID_STATE_RESHAPING         0x00000080
#define DH_RAID_STATE_CHECKING          0x00000100
#define DH_RAID_STATE_NOTSTARTED        0x00000200

// RAID成员信息
typedef struct tagNET_RAID_MEMBER_INFO 
{
    DWORD               dwSize;
    DWORD               dwID;                                       // 磁盘号, 可用于描述磁盘在磁柜的槽位
    BOOL                bSpare;                                     // 是否局部热备, true-局部热备, false-RAID子盘
} NET_RAID_MEMBER_INFO;

// RAID信息
typedef struct tagDH_STORAGE_RAID
{
    DWORD               dwSize;
    int                 nLevel;                                     // 等级    
    int                 nState;                                     // RAID状态组合, 如DH_RAID_STATE_ACTIVE | DH_RAID_STATE_DEGRADED
    int                 nMemberNum;                                 // 成员数量
    char                szMembers[DH_MAX_MEMBER_PER_RAID][DH_STORAGE_NAME_LEN];    // RAID成员
    float               fRecoverPercent;                            // 同步百分比, 0~100, RAID状态中有"Recovering"或"Resyncing"时有效
    float               fRecoverMBps;                               // 同步速度, 单位MBps, RAID状态中有"Recovering"或"Resyncing"时有效
    float               fRecoverTimeRemain;                         // 同步剩余时间, 单位分钟, RAID状态中有"Recovering"或"Resyncing"时有效
    NET_RAID_MEMBER_INFO stuMemberInfos[DH_MAX_MEMBER_PER_RAID];    // RAID成员信息
} DH_STORAGE_RAID;

// 存储分区信息
typedef struct tagDH_STORAGE_PARTITION
{
    DWORD               dwSize;
    char                szName[DH_STORAGE_NAME_LEN];                // 名称
    INT64               nTotalSpace;                                // 总空间, byte
    INT64               nFreeSpace;                                 // 剩余空间, byte
    char                szMountOn[DH_STORAGE_MOUNT_LEN];            // 挂载点
    char                szFileSystem[DH_STORAGE_FILE_SYSTEM_LEN];   // 文件系统
    int                 nStatus;                                    // 分区状态, 0-LV不可用, 1-LV可用
} DH_STORAGE_PARTITION;

// 扩展柜信息
typedef struct tagDH_STORAGE_TANK 
{
    DWORD               dwSize;
    int                 nLevel;                                     // 级别, 主机是第0级，其它下属级别类推
    int                 nTankNo;                                    // 同一级扩展柜内的扩展口编号, 从0开始
} DH_STORAGE_TANK;

// 存储设备状态
#define NET_STORAGE_DEV_OFFLINE                 0                   // 物理硬盘脱机状态
#define NET_STORAGE_DEV_RUNNING                 1                   // 物理硬盘运行状态
#define NET_STORAGE_DEV_ACTIVE                  2                   // RAID活动
#define NET_STORAGE_DEV_SYNC                    3                   // RAID同步
#define NET_STORAGE_DEV_SPARE                   4                   // RAID热备(局部)
#define NET_STORAGE_DEV_FAULTY                  5                   // RAID失效
#define NET_STORAGE_DEV_REBUILDING              6                   // RAID重建
#define NET_STORAGE_DEV_REMOVED                 7                   // RAID移除
#define NET_STORAGE_DEV_WRITE_ERROR             8                   // RAID写错误
#define NET_STORAGE_DEV_WANT_REPLACEMENT        9                   // RAID需要被替换
#define NET_STORAGE_DEV_REPLACEMENT             10                  // RAID是替代设备
#define NET_STORAGE_DEV_GLOBAL_SPARE            11                  // 全局热备
#define NET_STORAGE_DEV_ERROR                   12                  // 错误, 部分分区可用
#define NET_STORAGE_DEV_RAIDSUB                 13                  // 该盘目前是单盘, 原先是块Raid子盘, 有可能在重启后自动加入Raid

// 存储设备信息
typedef struct tagDH_STORAGE_DEVICE 
{
    DWORD               dwSize;
    char                szName[DH_STORAGE_NAME_LEN];                    // 名称
    INT64               nTotalSpace;                                    // 总空间, byte
    INT64               nFreeSpace;                                     // 剩余空间, byte
    BYTE                byMedia;                                        // 介质, 0-DISK, 1-CDROM, 2-FLASH
    BYTE                byBUS;                                          // 总线, 0-ATA, 1-SATA, 2-USB, 3-SDIO, 4-SCSI
    BYTE                byVolume;                                       // 卷类型, 0-物理卷, 1-Raid卷, 2-VG虚拟卷, 3-ISCSI
    BYTE                byState;                                        // 物理硬盘状态, 取值为NET_STORAGE_DEV_OFFLINE和NET_STORAGE_DEV_RUNNING等
    int                 nPhysicNo;                                      // 同类设备存储接口的物理编号
    int                 nLogicNo;                                       // 同类设备存储接口的逻辑编号
    char                szParent[DH_STORAGE_NAME_LEN];                  // 上级存储组名称
    char                szModule[DH_STORAGE_NAME_LEN];                  // 设备模块
    char                szSerial[DH_SERIALNO_LEN];                      // 设备序列号
    char                szFirmware[DH_VERSION_LEN];                     // 固件版本
    int                 nPartitionNum;                                  // 分区数
    DH_STORAGE_PARTITION stuPartitions[DH_MAX_STORAGE_PARTITION_NUM];   // 分区信息
    DH_STORAGE_RAID     stuRaid;                                        // RAID信息, 只对RAID有效(byVolume == 1)
    DH_ISCSI_TARGET     stuISCSI;                                       // ISCSI信息, 只对ISCSI盘有效(byVolume == 3)
    BOOL                abTank;                                         // 扩展柜使能
    DH_STORAGE_TANK     stuTank;                                        // 硬盘所在扩展柜信息, abTank为TRUE时有效
} DH_STORAGE_DEVICE;

// 分割窗口OSD信息
typedef struct tagNET_SPLIT_OSD 
{
    DWORD               dwSize;
    BOOL                bEnable;                    // 使能
    DH_COLOR_RGBA       stuFrontColor;              // 前景颜色
    DH_COLOR_RGBA       stuBackColor;               // 背景颜色
    DH_RECT             stuFrontRect;               // 前景区域
    DH_RECT             stuBackRect;                // 背景区域
    BOOL                bRoll;                      // 是否滚动显示, 只对文本有效
    BYTE                byRollMode;                 // 滚动模式, 只对文本有效, 0-从左往右, 1-从右往左
    BYTE                byRoolSpeed;                // 滚动速率, 只对文本有效, 0~4, 数值越大滚动越快
    BYTE                byFontSize;                 // 字体大小, 只对文本有效
    BYTE                byTextAlign;                // 对齐方式, 0-靠左, 1-居中, 2-靠右
    BYTE                byType;                     // OSD类型, 0-文本, 1-图标
    BYTE                Reserved[3];                // 保留字节
    char                szContent[MAX_PATH];        // OSD内容, 若类型为图标, 内容为图标名称
} NET_SPLIT_OSD;

// CLIENT_GetSplitOSD 接口输入参数(获取解码窗口输出OSD信息)
typedef struct tagDH_IN_SPLIT_GET_OSD
{
    DWORD               dwSize;
    int                 nChannel;                   // 通道号
    int                 nWindow;                    // 窗口号
} DH_IN_SPLIT_GET_OSD;

// CLIENT_GetSplitOSD 接口输出参数(获取解码窗口输出OSD信息)
typedef struct tagDH_OUT_SPLIT_GET_OSD
{
    DWORD               dwSize;
    int                 nOSDNum;                            // OSD数量
    NET_SPLIT_OSD       stuOSD[DH_VIDEO_CUSTOM_OSD_NUM];    // OSD信息
} DH_OUT_SPLIT_GET_OSD;

// CLIENT_SetSplitOSD 接口输入参数(设置解码窗口输出OSD信息)
typedef struct tagDH_IN_SPLIT_SET_OSD
{
    DWORD               dwSize;
    int                 nChannel;                           // 通道号
    int                 nWindow;                            // 窗口号
    int                 nOSDNum;                            // OSD数量
    NET_SPLIT_OSD       stuOSD[DH_VIDEO_CUSTOM_OSD_NUM];    // OSD信息
} DH_IN_SPLIT_SET_OSD;

// CLIENT_SetSplitOSD 接口输出参数(设置解码窗口输出OSD信息)
typedef struct tagDH_OUT_SPLIT_SET_OSD
{
    DWORD               dwSize;
} DH_OUT_SPLIT_SET_OSD;

// 视频输出控制方式
typedef enum
{
    EM_VIDEO_OUT_CTRL_CHANNEL,              // 逻辑通道号控制方式, 对物理屏和拼接屏都有效
    EM_VIDEO_OUT_CTRL_COMPOSITE_ID,         // 拼接屏ID控制方式, 只对拼接屏有效
} EM_VIDEO_OUT_CTRL_TYPE;

// CLIENT_SetSplitSourceEx 接口的输入参数
typedef struct tagNET_IN_SET_SPLIT_SOURCE 
{
    DWORD                   dwSize;
    EM_VIDEO_OUT_CTRL_TYPE  emCtrlType;         // 视频输出控制方式
    int                     nChannel;           // 视频输出逻辑通道号, emCtrlType为EM_VIDEO_OUT_CTRL_CHANNEL时有效
    const char*             pszCompositeID;     // 拼接屏ID, emCtrlType为EM_VIDEO_OUT_CTRL_COMPOSITE_ID时有效
    int                     nWindow;            // 窗口号, -1表示当前分割模式下的所有窗口
    DH_SPLIT_SOURCE*        pstuSources;        // 视频源信息, 当nWindow=-1时, 视频源是个数组, 且数量与窗口数一致
    int                     nSourceCount;       // 视频源数量
} NET_IN_SET_SPLIT_SOURCE;

// 设置视频源的返回结果
typedef struct tagNET_SET_SPLIT_SOURCE_RESULT 
{
    DWORD                   dwSize;
    int                     nPushPort;          // 推流模式的设备端监听端口号
} NET_SET_SPLIT_SOURCE_RESULT;

// CLIENT_SetSplitSourceEx 接口的输出参数
typedef struct tagNET_OUT_SET_SPLIT_SOURCE
{
    DWORD                   dwSize;
    NET_SET_SPLIT_SOURCE_RESULT* pstuResults;   // 设置成功后的返回值, 对应NET_IN_SET_SPLIT_SOURCE中的窗口数组, 用户分配内存, 如果不需要可以为NULL
    int                     nMaxResultCount;    // pstuResults数组的大小
    int                     nRetCount;          // 返回的数量
} NET_OUT_SET_SPLIT_SOURCE;

// CLIENT_MatrixSwitch 输入参数
typedef struct tagNET_IN_MATRIX_SWITCH
{
    DWORD           dwSize;
    DH_SPLIT_MODE   emSplitMode;                // 分割模式
    int*            pnOutputChannels;           // 输出通道, 可同时指定多个输出通道一起切换, 内容一致
    int             nOutputChannelCount;        // 输出通道数
    int*            pnInputChannels;            // 输入通道, 每个分割窗口一个对应一个输入通道
    int             nInputChannelCount;         // 输入通道数
} NET_IN_MATRIX_SWITCH;

// CLIENT_MatrixSwitch 输出参数
typedef struct tagNET_OUT_MATRIX_SWITCH 
{
    DWORD            dwSize;
} NET_OUT_MATRIX_SWITCH;

// CLIENT_SplitSetMultiSource 接口的输入参数
typedef struct tagNET_IN_SPLIT_SET_MULTI_SOURCE 
{
    DWORD                   dwSize;
    EM_VIDEO_OUT_CTRL_TYPE  emCtrlType;         // 视频输出控制方式
    int                     nChannel;           // 视频输出逻辑通道号, emCtrlType为EM_VIDEO_OUT_CTRL_CHANNEL时有效
    const char*             pszCompositeID;     // 拼接屏ID, emCtrlType为EM_VIDEO_OUT_CTRL_COMPOSITE_ID时有效
    BOOL                    bSplitModeEnable;   // 是否改变分割模式
    DH_SPLIT_MODE           emSplitMode;        // 分割模式, bSplitModeEnable=TRUE时有效
    int                     nGroupID;           // 分割分组号, bSplitModeEnable=TRUE时有效
    int*                    pnWindows;          // 窗口号数组
    int                     nWindowCount;       // 窗口数量
    DH_SPLIT_SOURCE*        pstuSources;        // 视频源信息, 分别对应每个窗口, 数量同窗口数
} NET_IN_SPLIT_SET_MULTI_SOURCE;

// CLIENT_SplitSetMultiSource 接口的输出参数
typedef struct tagNET_OUT_SPLIT_SET_MULTI_SOURCE 
{
    DWORD                   dwSize;
} NET_OUT_SPLIT_SET_MULTI_SOURCE;

// 视频分割操作类型
typedef enum tagNET_SPLIT_OPERATE_TYPE
{
    NET_SPLIT_OPERATE_SET_BACKGROUND,           // 设置背景图片, 对应 NET_IN_SPLIT_SET_BACKGROUND 和 NET_OUT_SPLIT_SET_BACKBROUND
    NET_SPLIT_OPERATE_GET_BACKGROUND,           // 获取背景图片, 对应 NET_IN_SPLIT_GET_BACKGROUND 和 NET_OUT_SPLIT_GET_BACKGROUND
    NET_SPLIT_OPERATE_SET_PREPULLSRC,           // 设置预拉流源, 对应 NET_IN_SPLIT_SET_PREPULLSRC 和 NET_OUT_SPLIT_SET_PREPULLSRC
    NET_SPLIT_OPERATE_SET_HIGHLIGHT,            // 设置源边框高亮使能开关, 对应 NET_IN_SPLIT_SET_HIGHLIGHT 和 NET_OUT_SPLIT_SET_HIGHLIGHT
} NET_SPLIT_OPERATE_TYPE;

// 设置源边框高亮使能开关输入参数
typedef struct tagNET_IN_SPLIT_SET_HIGHLIGHT
{
    DWORD           dwSize; 
    int             nChannel;                   // 视频输出通道
    int             nWindow;                    // 窗口号
    BOOL            bHighLightEn;               // 边框高亮使能,TRUE-表示高亮
    DH_COLOR_RGBA   stuColor;                   // 边框颜色 
}NET_IN_SPLIT_SET_HIGHLIGHT;

// 设置源边框高亮使能开关输出参数
typedef struct tagNET_OUT_SPLIT_SET_HIGHLIGHT
{
    DWORD           dwSize;
}NET_OUT_SPLIT_SET_HIGHLIGHT;

// 设置预拉流源输入参数
typedef struct tagNET_IN_SPLIT_SET_PREPULLSRC 
{
    DWORD           dwSize;
    int             nChannel;                   // 视频输出通道
    int             nWindow;                    // 窗口号
    int             nSrcCount;                  // 预拉流源数量
    DH_SPLIT_SOURCE* pSources;                  // 预拉流源信息
} NET_IN_SPLIT_SET_PREPULLSRC;

// 设置预拉流源的返回结果
typedef struct tagNET_SPLIT_SET_PREPULLSRC_RESULT 
{
    DWORD           dwSize;
    BOOL            bResult;                    // 设置结果, TRUE-成功, FALSE-失败
    DWORD           dwErrorCode;                // 失败错误码
} NET_SPLIT_SET_PREPULLSRC_RESULT;

// 设置预拉流源输出参数
typedef struct tagNET_OUT_SPLIT_SET_PREPULLSRC 
{
    DWORD           dwSize;
    int             nResultCount;               // 结果数量, 与预拉流源数量相同
    NET_SPLIT_SET_PREPULLSRC_RESULT* pResults;  // 结果
} NET_OUT_SPLIT_SET_PREPULLSRC;

// 设置视频输出背景图输入参数
typedef struct tagNET_IN_SPLIT_SET_BACKGROUND
{
    DWORD            dwSize;
    int              nChannel;                   // 视频输出通道号
    BOOL             bEnable;                    // 使能
    const char*      pszFileName;                // 背景图名称
} NET_IN_SPLIT_SET_BACKGROUND;

// 设置视频输出背景图输出参数
typedef struct tagNET_OUT_SPLIT_SET_BACKGROUND 
{
    DWORD            dwSize;
} NET_OUT_SPLIT_SET_BACKGROUND;

// 获取视频输出背景图输入参数
typedef struct tagNET_IN_SPLIT_GET_BACKGROUND 
{
    DWORD            dwSize;
    int              nChannel;                   // 视频输出通道号
} NET_IN_SPLIT_GET_BACKGROUND;

// 获取视频输出背景图输出参数
typedef struct tagNET_OUT_SPLIT_GET_BACKGROUND 
{
    DWORD            dwSize;
    BOOL             bEnable;                            // 使能
    char             szFileName[DH_COMMON_STRING_256];   // 背景图名称
} NET_OUT_SPLIT_GET_BACKGROUND;

////////////////////////////////// 系统状态 ////////////////////////////////////////

// CPU信息
typedef struct tagDH_CPU_INFO
{
    DWORD               dwSize;
    int                 nUsage;                         // CPU利用率
} DH_CPU_INFO;

// CPU状态
typedef struct tagDH_CPU_STATUS
{
    DWORD               dwSize;
    BOOL                bEnable;                        // 查询是否成功
    int                 nCount;                         // CPU数量
    DH_CPU_INFO         stuCPUs[DH_MAX_CPU_NUM];        // CPU信息
} DH_CPU_STATUS;

// 内存信息
typedef struct tagDH_MEMORY_INFO
{
    DWORD               dwSize;
    DWORD               dwTotal;                        // 总内存, M
    DWORD               dwFree;                         // 剩余内存, M
} DH_MEMORY_INFO;

// 内存状态
typedef struct tagDH_MEMORY_STATUS 
{
    DWORD               dwSize;
    BOOL                bEnable;                        // 查询是否成功
    DH_MEMORY_INFO      stuMemory;                      // 内存信息
} DH_MEMORY_STATUS;

// 风扇信息
typedef struct tagDH_FAN_INFO
{
    DWORD               dwSize;
    char                szName[DH_DEVICE_NAME_LEN];     // 名称
    DWORD               nSpeed;                         // 速度
} DH_FAN_INFO;

// 风扇状态
typedef struct tagDH_FAN_STATUS
{
    DWORD               dwSize;
    BOOL                bEnable;                        // 查询是否成功
    int                 nCount;                         // 风扇数量
    DH_FAN_INFO         stuFans[DH_MAX_FAN_NUM];        // 风扇状态
} DH_FAN_STATUS;

// CLIENT_QueryDevState接口的 DH_DEVSTATE_POWER_STATE 命令参数
// 电源信息
typedef struct tagDH_POWER_INFO
{
    DWORD               dwSize;
    BOOL                bPowerOn;                       // 电源状态, 0-关闭, 1-打开, 2-打开但有故障
} DH_POWER_INFO;

// 电池信息
typedef struct tagDH_BATTERY_INFO
{
    DWORD               dwSize;
    int                 nPercent;                       // 电池容量百分比
    BOOL                bCharging;                      // 是否真正充电
} DH_BATTERY_INFO;

// 电源状态
typedef struct tagDH_POWER_STATUS
{
    DWORD               dwSize;
    BOOL                bEnable;                            // 查询是否成功
    int                 nCount;                             // 电源数量
    DH_POWER_INFO       stuPowers[DH_MAX_POWER_NUM];        // 电源状态
    int                 nBatteryNum;                        // 电池数量
    DH_BATTERY_INFO     stuBatteries[DH_MAX_BATTERY_NUM];   // 电池状态
} DH_POWER_STATUS;

// 温度信息
typedef struct tagDH_TEMPERATURE_INFO
{
    DWORD               dwSize;
    char                szName[DH_DEVICE_NAME_LEN];         // 传感器名称
    float               fTemperature;                       // 温度
} DH_TEMPERATURE_INFO;

// 温度状态
typedef struct tagDH_TEMPERATURE_STATUS
{
    DWORD               dwSize;
    BOOL                bEnable;                            // 查询是否成功
    int                 nCount;                             // 温度数量
    DH_TEMPERATURE_INFO stuTemps[DH_MAX_TEMPERATURE_NUM];   // 温度信息 
} DH_TEMPERATURE_STATUS;

// 系统状态
typedef struct tagDH_SYSTEM_STATUS
{
    DWORD                   dwSize;
    DH_CPU_STATUS*          pstuCPU;                        // CPU状态
    DH_MEMORY_STATUS*       pstuMemory;                     // 内存状态
    DH_FAN_STATUS*          pstuFan;                        // 风扇状态
    DH_POWER_STATUS*        pstuPower;                      // 电源状态
    DH_TEMPERATURE_STATUS*  pstuTemp;                       // 温度状态
} DH_SYSTEM_STATUS;

// 对应CLIENT_QueryDevState()接口的 DH_DEVSTATE_ALL_ALARM_CHANNELS_STATE命令参数
// 获取报警通道状态
enum NET_ALARM_CHANNEL_TYPE
{
    NET_ALARM_CHANNEL_TYPE_ALL,                             // 所有通道（包含以下所有）
    NET_ALARM_CHANNEL_TYPE_ALARMIN,                         // 报警输入通道
    NET_ALARM_CHANNEL_TYPE_ALARMOUT,                        // 报警输出通道
    NET_ALARM_CHANNEL_TYPE_ALARMBELL,                       // 警号通道
    NET_ALARM_CHANNEL_TYPE_EXALARMIN,                       // 扩展模块报警输入通道
    NET_ALARM_CHANNEL_TYPE_EXALARMOUT,                      // 扩展模块报警输出通道
};

typedef struct tagNET_CLIENT_ALARM_CHANNELS_STATE
{
    DWORD                       dwSize;
    NET_ALARM_CHANNEL_TYPE      emType;                     // 查询报警通道的类型                                                                                                                                
    int                         nAlarmInCount;              // 报警输入个数，由用户指定
    int                         nAlarmInRetCount;           // 报警输入返回个数
    BOOL*                       pbAlarmInState;             // 报警输入状态数组，由用户分配内存，每个元素表示一个通道状态,TRUE为有输入,FALSE为无输入
    int                         nAlarmOutCount;             // 报警输出个数，由用户指定
    int                         nAlarmOutRetCount;          // 报警输出个数
    BOOL*                       pbAlarmOutState;            // 报警输出状态数组，由用户分配内存，每个元素表示一个通道状态,TRUE为有输出,FALSE为输出
    int                         nAlarmBellCount;            // 警号个数，由用户指定
    int                         nAlarmBellRetCount;         // 警号返回个数
    BOOL*                       pbAlarmBellState;           // 警号状态数组，由用户分配内存，每个元素表示一个通道状态,TRUE为有输出,FALSE为无输出
    int                         nExAlarmInCount;            // 扩展模块报警输入个数，由用户指定
    int                         nExAlarmInRetCount;         // 扩展模块报警输入返回个数
    BOOL*                       pbExAlarmInState;           // 扩展模块报警输入状态数组，由用户分配内存，每个元素表示一个通道状态,TRUE为有输出,FALSE为无输出
    int*                        pnExAlarmInDestionation;    // 扩展模块报警输入有效通道的位置
    int                         nExAlarmOutCount;           // 扩展模块报警输出个数，由用户指定
    int                         nExAlarmOutRetCount;        // 扩展模块报警输出个数
    BOOL*                       pbExAlarmOutState;          // 扩展模块报警输出状态数组，由用户分配内存，每个元素表示一个通道状态,TRUE为有输出,FALSE为无输出
    int*                        pnExAlarmOutDestionation;   // 扩展模块报警输出有效通道的位置
}NET_CLIENT_ALARM_CHANNELS_STATE;


// 串口上连接的报警键盘数
typedef struct tagNET_ALARMKEYBOARD_COUNT
{
    DWORD               dwSize;
    int                 nAlarmKeyboardCount;        // 连接着的报警键盘数目
}NET_ALARMKEYBOARD_COUNT;

////////////////////////////////// 大屏控制 ////////////////////////////////////////
// CLIENT_OpenSplitWindow接口输入参数(开窗)
typedef struct tagDH_IN_SPLIT_OPEN_WINDOW
{
    DWORD               dwSize;
    int                 nChannel;                   // 通道号(屏号)
    DH_RECT             stuRect;                    // 窗口位置, 0~8192
    BOOL                bDirectable;                // 坐标是否满足直通条件, 直通是指拼接屏方式下，此窗口区域正好为物理屏区域
} DH_IN_SPLIT_OPEN_WINDOW;

// CLIENT_OpenSplitWindow接口输出参数(开窗)
typedef struct tagDH_OUT_SPLIT_OPEN_WINDOW
{
    DWORD               dwSize;
    unsigned int        nWindowID;                  // 窗口序号
    unsigned int        nZOrder;                    // 窗口次序        
} DH_OUT_SPLIT_OPEN_WINDOW;

// CLIENT_CloseSplitWindow接口输入参数(关窗)
typedef struct tagDH_IN_SPLIT_CLOSE_WINDOW
{
    DWORD               dwSize;
    int                 nChannel;                   // 通道号(屏号)
    UINT                nWindowID;                  // 窗口序号
} DH_IN_SPLIT_CLOSE_WINDOW;

// CLIENT_CloseSplitWindow接口输出参数(关窗)
typedef struct tagDH_OUT_SPLIT_CLOSE_WINDOW
{
    DWORD               dwSize;
} DH_OUT_SPLIT_CLOSE_WINDOW;

// CLIENT_SetSplitWindowRect输入参数(设置窗口位置)
typedef struct tagDH_IN_SPLIT_SET_RECT
{
    DWORD               dwSize;
    int                 nChannel;                   // 通道号(屏号)
    UINT                nWindowID;                  // 窗口序号
    DH_RECT             stuRect;                    // 窗口位置, 0~8192
    BOOL                bDirectable;                // 坐标是否满足直通条件, 直通是指拼接屏方式下，此窗口区域正好为物理屏区域
} DH_IN_SPLIT_SET_RECT;

// CLIENT_SetSplitWindowRect接口输出参数(设置窗口位置)
typedef struct tagDH_OUT_SPLIT_SET_RECT
{
    DWORD               dwSize;
} DH_OUT_SPLIT_SET_RECT;

// CLIENT_GetSplitWindowRect接口输入参数(获取窗口位置)
typedef struct tagDH_IN_SPLIT_GET_RECT
{
    DWORD               dwSize;
    int                 nChannel;                  // 通道号(屏号)
    UINT                nWindowID;                 // 窗口序号
} DH_IN_SPLIT_GET_RECT;

// CLIENT_GetSplitWindowRect接口输出参数(获取窗口位置)
typedef struct tagDH_OUT_SPLIT_GET_RECT
{
    DWORD               dwSize;    
    DH_RECT             stuRect;                   // 窗口位置, 0~8192
} DH_OUT_SPLIT_GET_RECT;

// 窗口层叠次序
typedef struct tagDH_WND_ZORDER
{
    DWORD               dwSize;
    unsigned int        nWindowID;                 // 窗口序号
    unsigned int        nZOrder;                   // Z次序
} DH_WND_ZORDER;

// CLIENT_SetSplitWindowLevels接口输入参数(设置窗口次序)
typedef struct tagDH_IN_SPLIT_SET_TOP_WINDOW
{
    DWORD               dwSize;
    int                 nChannel;                  // 通道号(屏号)
    int                 nWindowID;                 // 窗口序号
} DH_IN_SPLIT_SET_TOP_WINDOW;

// CLIENT_SetSplitWindowLevels接口输出参数(设置窗口次序)
typedef struct tagDH_OUT_SPLIT_SET_TOP_WINDOW
{
    DWORD               dwSize;
    DH_WND_ZORDER*      pZOders;                   // 窗口次序数组
    int                 nMaxWndCount;              // 窗口次序数组大小
    int                 nWndCount;                 // 返回的窗口数量
} DH_OUT_SPLIT_SET_TOP_WINDOW;

// CLIENT_SetDisplayMode接口输入参数(电视墙显示模式设置)
typedef struct tagDH_IN_WM_SET_DISPLAY_MODE 
{
    DWORD               dwSize;
    int                 nMonitorWallID;             // 电视墙序号
    const char*         pszBlockID;                 // 区块ID, NULL/""-所有区块
    int                 nTVID;                      // 显示单元序号, -1表示区块中所有显示单元
    UINT                nDisplayMode;               // 显示模式, 0-标准, 1-高亮, 2-节能
} DH_IN_WM_SET_DISPLAY_MODE;

// CLIENT_SetDisplayMode接口输出参数(电视墙显示模式设置)
typedef struct tagDH_OUT_WM_SET_DISPLAY_MODE
{
    DWORD               dwSize;
} DH_OUT_WM_SET_DISPLAY_MODE;

// 区块中所有显示单元的显示模式
typedef struct tagDH_BLOCK_DISPLAY_MODE
{
    DWORD               dwSize;
    int*                pTVModes;                   // TV显示模式数组
    int                 nMaxTVCount;                // TV显示模式数组大小
    int                 nRetTVCount;                // 实际TV数量
} DH_BLOCK_DISPLAY_MODE;

// CLIENT_GetDisplayMode接口的输入参数(获取电视墙显示模式)
typedef struct tagDH_IN_WM_GET_DISPLAY_MODE 
{
    DWORD               dwSize;
    int                 nMonitorWallID;             // 电视墙序号
    const char*         pszBlockID;                 // 区块ID, NULL/""-所有区块
    int                 nTVID;                      // 显示单元序号, -1表示区块中所有显示单元
} DH_IN_WM_GET_DISPLAY_MODE;

// CLIENT_GetDisplayMode接口的输出参数(获取电视墙显示模式)
typedef struct tagDH_OUT_WM_GET_DISPLAY_MODE
{
    DWORD                   dwSize;
    DH_BLOCK_DISPLAY_MODE*  pBlockModes;            // 区块显示模式数组
    int                     nMaxBlockCount;         // 区块显示模式数组大小
    int                     nRetBlockCount;         // 实际区块数量
} DH_OUT_WM_GET_DISPLAY_MODE;

// CLIENT_PowerControl接口输入参数(电视墙电源控制)
typedef struct tagDH_IN_WM_POWER_CTRL 
{
    DWORD               dwSize;
    int                 nMonitorWallID;             // 电视墙序号
    const char*         pszBlockID;                 // 区块ID, NULL/""-所有区块
    int                 nTVID;                      // 显示单元序号, -1表示区块中所有显示单元
    BOOL                bPowerOn;                   // 是否打开电源
} DH_IN_WM_POWER_CTRL;

// CLIENT_PowerControl接口输出参数(电视墙电源控制)
typedef struct tagDH_OUT_WM_POWER_CTRL
{
    DWORD               dwSize;
} DH_OUT_WM_POWER_CTRL;

// CLIENT_LoadMonitorWallCollection接口输入参数(载入电视墙预案)
typedef struct tagDH_IN_WM_LOAD_COLLECTION 
{
    DWORD               dwSize;
    int                 nMonitorWallID;             // 电视墙序号
    const char*         pszName;                    // 预案名称
} DH_IN_WM_LOAD_COLLECTION;

// CLIENT_LoadMonitorWallCollection接口输出参数(载入电视墙预案)
typedef struct tagDH_OUT_WM_LOAD_COLLECTION 
{
    DWORD               dwSize;
} DH_OUT_WM_LOAD_COLLECTION;

// CLIENT_SaveMonitorWallCollection接口输入参数(保存电视墙预案)
typedef struct tagDH_IN_WM_SAVE_COLLECTION 
{
    DWORD               dwSize;
    int                 nMonitorWallID;             // 电视墙序号
    const char*         pszName;                    // 预案名称
} DH_IN_WM_SAVE_COLLECTION;

// CLIENT_SaveMonitorWallCollection接口输出参数(保存电视墙预案)
typedef struct tagDH_OUT_WM_SAVE_COLLECTION 
{
    DWORD               dwSize;
} DH_OUT_WM_SAVE_COLLECTION;

// CLIENT_RenameMonitorWallCollection接口输入参数(预案重命名)
typedef struct tagDH_IN_WM_RENAME_COLLECTION 
{
    DWORD               dwSize;
    int                 nMonitorWallID;                // 电视墙序号
    const char*         pszOldName;                    // 原名称
    const char*         pszNewName;                    // 新名称
} DH_IN_WM_RENAME_COLLECTION;

// CLIENT_RenameMonitorWallCollection接口输出参数(预案重命名)
typedef struct tagDH_OUT_WM_RENAME_COLLECTION
{
    DWORD                dwSize;
} DH_OUT_WM_RENAME_COLLECTION;

// 区块窗口信息
typedef struct tagDH_WINDOW_COLLECTION
{
    DWORD               dwSize;
    int                 nWindowID;                      // 窗口ID
    BOOL                bWndEnable;                     // 窗口是否有效
    DH_RECT             stuRect;                        // 窗口区域, 自由分割模式下有效
    BOOL                bDirectable;                    // 坐标是否满足直通条件
    int                 nZOrder;                        // 窗口Z次序
    BOOL                bSrcEnable;                     // 显示源是否有效
    char                szDeviceID[DH_DEV_ID_LEN_EX];   // 设备ID
    int                 nVideoChannel;                  // 视频通道号
    int                 nVideoStream;                   // 视频码流类型
    int                 nAudioChannel;                  // 音频通道
    int                 nAudioStream;                   // 音频码流类型
    int                 nUniqueChannel;                 // 设备内统一编号的唯一通道号
} DH_WINDOW_COLLECTION;

// 区块收藏
typedef struct tagDH_BLOCK_COLLECTION 
{
    DWORD                dwSize;
    DH_SPLIT_MODE        emSplitMode;                   // 分割模式
    DH_WINDOW_COLLECTION stuWnds[DH_MAX_SPLIT_WINDOW];  // 窗口信息数组
    int                  nWndsCount;                    // 窗口数量
    char                 szName[DH_DEVICE_NAME_LEN];    // 收藏夹名称
    int                  nScreen;                       // 输出通道号, 包括拼接屏
} DH_BLOCK_COLLECTION;

// 电视墙预案
typedef struct tagDH_MONITORWALL_COLLECTION 
{
    DWORD                dwSize;
    char                 szName[DH_DEVICE_NAME_LEN];    // 电视墙预案名称
    DH_BLOCK_COLLECTION  stuBlocks[DH_MAX_BLOCK_NUM];   // 区块数组
    int                  nBlocksCount;                  // 区块数量
    char                 szControlID[DH_DEV_ID_LEN_EX]; // 控制ID
} DH_MONITORWALL_COLLECTION;

// CLIENT_GetMonitorWallCollections接口输入参数(获取电视墙预案信息)
typedef struct tagDH_IN_WM_GET_COLLECTIONS 
{
    DWORD                dwSize;
    int                  nMonitorWallID;                // 电视墙ID
} DH_IN_WM_GET_COLLECTIONS;

// CLIENT_GetMonitorWallCollections接口输出参数(获取电视墙预案信息)
typedef struct tagDH_OUT_WM_GET_COLLECTIONS 
{
    DWORD                       dwSize;    
    DH_MONITORWALL_COLLECTION*  pCollections;           // 电视墙预案数组
    int                         nMaxCollectionsCount;   // 电视墙预案数组大小
    int                         nCollectionsCount;      // 电视墙预案数量
} DH_OUT_WM_GET_COLLECTIONS;

// CLIENT_GetSplitWindowsInfo接口输入参数
typedef struct tagDH_IN_SPLIT_GET_WINDOWS 
{
    DWORD              dwSize;
    int                nChannel;                        // 通道号
} DH_IN_SPLIT_GET_WINDOWS;

// CLIENT_GetSplitWindowsInfo接口输出参数
typedef struct tagDH_OUT_SPLIT_GET_WINDOWS 
{
    DWORD                   dwSize;
    DH_BLOCK_COLLECTION     stuWindows;                 // 窗口信息
} DH_OUT_SPLIT_GET_WINDOWS;

// CLIENT_LoadSplitCollection接口输入参数(载入收藏)
typedef struct tagDH_IN_SPLIT_LOAD_COLLECTION 
{
    DWORD             dwSize;
    int               nChannel;                 // 输出通道号
    const char*       pszName;                  // 收藏夹名称
} DH_IN_SPLIT_LOAD_COLLECTION;

// CLIENT_LoadSplitCollection接口输出参数(载入收藏)
typedef struct tagDH_OUT_SPLIT_LOAD_COLLECTION 
{
    DWORD             dwSize;
} DH_OUT_SPLIT_LOAD_COLLECTION;

// CLIENT_SaveSplitCollection接口输入参数(保存收藏)
typedef struct tagDH_IN_SPLIT_SAVE_COLLECTION 
{
    DWORD             dwSize;
    int               nChannel;                 // 输出通道号
    const char*       pszName;                  // 收藏夹名称
} DH_IN_SPLIT_SAVE_COLLECTION;

// CLIENT_SaveSplitCollection接口输出参数(保存收藏)
typedef struct tagDH_OUT_SPLIT_SAVE_COLLECTION 
{
    DWORD             dwSize;
} DH_OUT_SPLIT_SAVE_COLLECTION;

// CLIENT_RenameSplitCollection接口输入参数(收藏重命名)
typedef struct tagDH_IN_SPLIT_RENAME_COLLECTION 
{
    DWORD             dwSize;
    int               nChannel;                 // 输出通道号
    const char*       pszOldName;               // 原名称
    const char*       pszNewName;               // 新名称
} DH_IN_SPLIT_RENAME_COLLECTION;

// CLIENT_RenameSplitCollection接口输出参数(收藏重命名)
typedef struct tagDH_OUT_SPLIT_RENAME_COLLECTION
{
    DWORD             dwSize;
} DH_OUT_SPLIT_RENAME_COLLECTION;

// CLIENT_GetSplitCollections接口输入参数(获取收藏夹信息)
typedef struct tagDH_IN_SPLIT_GET_COLLECTIONS 
{
    DWORD             dwSize;
    int               nChannel;                // 输出通道号
} DH_IN_SPLIT_GET_COLLECTIONS;

// CLIENT_GetSplitCollections接口输出参数(获取收藏夹信息)
typedef struct tagDH_OUT_SPLIT_GET_COLLECTIONS 
{
    DWORD                dwSize;    
    DH_BLOCK_COLLECTION* pCollections;                  // 收藏夹数组
    int                  nMaxCollectionsCount;          // 收藏夹数组大小
    int                  nCollectionsCount;             // 返回的收藏夹数量
} DH_OUT_SPLIT_GET_COLLECTIONS;

// CLIENT_DeleteSplitCollection接口的输入参数(删除收藏夹)
typedef struct tagDH_IN_SPLIT_DELETE_COLLECTION 
{
    DWORD                dwSize;
    int                  nChannel;                      // 输出通道号
    const char**         ppszNames;                     // 收藏夹名称数组
    int                  nNameCount;                    // 收藏夹名称数组大小
} DH_IN_SPLIT_DELETE_COLLECTION;

// CLIENT_DeleteSplitCollection接口的输出参数(删除收藏夹)
typedef struct tagDH_OUT_SPLIT_DELETE_COLLECTION 
{
    DWORD                dwSize;
} DH_OUT_SPLIT_DELETE_COLLECTION;

// 融合屏通道信息
typedef struct tagDH_COMPOSITE_CHANNEL
{
    DWORD               dwSize;
    char                szMonitorWallName[DH_DEVICE_NAME_LEN];  // 电视墙名称
    char                szCompositeID[DH_DEV_ID_LEN_EX];        // 融合屏ID
    int                 nVirtualChannel;                        // 虚拟通道号
} DH_COMPOSITE_CHANNEL;

// 轮巡使能配置
typedef struct tagDHDEV_TOUR_ENABLE
{
    DWORD               dwSize;
    BOOL                bEnable;                    // 轮巡使能
    BOOL                bStart;                     // 是否正在轮巡(只读). 轮巡使能打开但没有配置轮巡输入源时, bStart=FALSE
} DHDEV_TOUR_ENABLE_CFG;

// CLIENT_SetDecodePolicy接口输入参数(设置解码策略)
typedef struct tagDH_IN_SET_DEC_POLICY 
{
    DWORD               dwSize;
    int                 nChannel;               // 通道号
    int                 nWindow;                // 窗口号, -1表示通道内所有窗口
    int                 nPolicyLevel;           // 解码策略等级, 共5档(-2, -1, 0, 1, 2), 值越大越流畅但延迟越大
                                                // -2表示实时性最好, 2表示流畅性最好, 0默认
} DH_IN_SET_DEC_POLICY;

// CLIENT_SetDecodePolicy接口输出参数(设置解码策略)
typedef struct tagDH_OUT_SET_DEC_POLICY 
{
    DWORD                dwSize;
} DH_OUT_SET_DEC_POLICY;

// CLIENT_GetDecodePolicy接口输入参数(获取解码策略)
typedef struct tagDH_IN_GET_DEC_POLICY 
{
    DWORD                dwSize;
    int                  nChannel;              // 通道号
    int                  nWindow;               // 窗口号, -1表示通道内所有窗口
} DH_IN_GET_DEC_POLICY;

// CLIENT_GetDecodePolicy接口输出参数(获取解码策略)
typedef struct tagDH_OUT_GET_DEC_POLICY 
{
    DWORD                dwSize;
    int                  nPolicyLevel;          // 解码策略等级, 共5档(-2, -1, 0, 1, 2), 值越大越流畅但延迟越大
                                                // -2表示实时性最好, 2表示流畅性最好, 0默认
} DH_OUT_GET_DEC_POLICY;

// 音频输出模式
typedef enum
{
    DH_AUDIO_AUTO,                              // 自动切换音频输出
    DH_AUDIO_DISABLE,                           // 禁止所有音频输出 
    DH_AUDIO_FORCE,                             // 强制输出用户指定的某个窗口的音频
} DH_AUDIO_OUTPUT_MODE;

// CLIENT_SetSplitAudioOuput接口输入参数(设置音频输出模式)
typedef struct tagDH_IN_SET_AUDIO_OUTPUT 
{
    DWORD                dwSize;
    int                  nChannel;              // 通道号
    DH_AUDIO_OUTPUT_MODE emMode;                // 音频输出模式
    int                  nWindow;               // 输出窗口号, emMode为DH_AUDIO_FORCE时有效
} DH_IN_SET_AUDIO_OUTPUT;

// CLIENT_SetSplitAudioOuput接口输出参数(设置音频输出模式)
typedef struct tagDH_OUT_SET_AUDIO_OUTPUT
{
    DWORD                dwSize;
} DH_OUT_SET_AUDIO_OUTPUT;

// CLIENT_GetSplitAudioOuput接口输入参数(获取音频输出模式)
typedef struct tagDH_IN_GET_AUDIO_OUTPUT
{
    DWORD                dwSize;
    int                  nChannel;              // 通道号
} DH_IN_GET_AUDIO_OUTPUT;

// CLIENT_GetSplitAudioOuput接口输出参数(获取音频输出模式)
typedef struct tagDH_OUT_GET_AUDIO_OUTPUT
{
    DWORD                dwSize;
    DH_AUDIO_OUTPUT_MODE emMode;                // 音频输出模式
    int                  nWindow;               // 输出窗口号, emMode为DH_AUDIO_FORCE时有效
} DH_OUT_GET_AUDIO_OUTPUT;

// CLIENT_GetEncodePlan 接口输入参数(获取刻录光盘时使用的编码参数)
typedef struct tagDH_IN_GET_ENCODE_PLAN
{
    DWORD               dwSize;
    unsigned int        nChannel;               // 指定要获取的编码通道号
    unsigned int        nExpectTime;            // 业务预期时长     整型,单位：分钟
    unsigned int        nCapacity;              // 可用的设备容量,整型,单位:M
}DH_IN_GET_ENCODE_PLAN;
// CLIENT_GetEncodePlan 接口输出参数(获取刻录光盘时使用的编码参数)
typedef struct tagDH_OUT_GET_ENCODE_PLAN
{
    DWORD               dwSize;
    int                 nResolutionType;        // emResolutionTypes成员个数 
    CAPTURE_SIZE        emResolutionTypes[DH_MAX_CAPTURE_SIZE_NUM];// 视频分辨率范围
    CAPTURE_SIZE        emResolution;           // 推荐视频分辨率
    unsigned int        nBitRate;               // 视频固定码流值
}DH_OUT_GET_ENCODE_PLAN;

// 组织目录逻辑对象
typedef struct tagDH_ORGANIZATION_NODE_LOGIC_OBJECT 
{
    DWORD               dwSize;
    char                szName[DH_NODE_NAME_LEN];       // 名称
    char                szType[DH_DEV_TYPE_LEN];        // 类型
    char                szDevID[DH_DEV_ID_LEN_EX];      // 设备ID
    char                szControlID[DH_DEV_ID_LEN_EX];  // 控制ID, 只读
    int                 nChannel;                       // 通道号
} DH_ORGANIZATION_NODE_LOGIC_OBJECT;

// 组织目录
typedef struct tagDH_ORGANIZATION_NODE_DIRECTORY
{
    DWORD               dwSize;
    char                szName[DH_NODE_NAME_LEN];       // 名称
    char                szControlID[DH_DEV_ID_LEN_EX];  // 控制ID
} DH_ORGANIZATION_NODE_DIRECTORY;

// 组织目录节点信息
typedef struct tagDH_ORGANIZATION_NODE 
{
    DWORD               dwSize;
    int                 nNodeType;                        // 节点类型, 0-逻辑对象, 1-目录
    DH_ORGANIZATION_NODE_LOGIC_OBJECT    stuLogicObject;  // 逻辑对象, nNodeType==0时有效
    DH_ORGANIZATION_NODE_DIRECTORY       stuDirectory;    // 目录, nNodeType==1时有效        
} DH_ORGANIZATION_NODE;

// 增加节点参数
typedef struct tagDH_ORGANIZATION_ADD_NODE_PARAM
{
    DWORD                dwSize;
    int                  nPosition;                     // 插入位置, -1-开始, -2-末尾, 0~n
    DH_ORGANIZATION_NODE stuNode;                       // 节点信息
} DH_ORGANIZATION_ADD_NODE_PARAM;

// CLIENT_OrganizationAddNodes接口的输入参数(增加节点)
typedef struct tagDH_IN_ORGANIZATION_ADD_NODES
{
    DWORD                dwSize;
    char*                pszPath;                       // 路径
    DH_ORGANIZATION_ADD_NODE_PARAM* pstuNodes;          // 节点信息数组指针
    int                  nNodeCount;                    // 节点数量
} DH_IN_ORGANIZATION_ADD_NODES;

// 增加节点的结果
typedef struct tagDH_ORGANIZATION_ADD_NODE_RESULT
{
    DWORD               dwSize;
    BOOL                bResult;                        // 结果
    char                szPath[MAX_PATH];               // 路径, 成功返回node路径，失败返回添加node时的路径
} DH_ORGANIZATION_ADD_NODE_RESULT;

// CLIENT_OrganizationAddNodes接口的输出参数(增加节点)
typedef struct tagDH_OUT_ORGANIZATION_ADD_NODES
{
    DWORD               dwSize;
    DH_ORGANIZATION_ADD_NODE_RESULT* pstuResults;       // 结果数组指针
    int                 nMaxResultCount;                // 结果数组大小
    int                 nRetResultCount;                // 返回的结果数量
} DH_OUT_ORGANIZATION_ADD_NODES;

// 节点路径
typedef struct tagDH_ORGANIZATION_NODE_PATH 
{
    DWORD               dwSize;
    char                szPath[MAX_PATH];               // 路径
} DH_ORGANIZATION_NODE_PATH;

// CLIENT_OrganizationDeleteNodes接口的输入参数(删除节点)
typedef struct tagDH_IN_ORGANIZATION_DELETE_NODES
{
    DWORD               dwSize;
    DH_ORGANIZATION_NODE_PATH*  pstuPath;               // 节点路径数组
    int                 nPathCount;                     // 节点数量
} DH_IN_ORGANIZATION_DELETE_NODES;

// CLIENT_OrganizationDeleteNodes接口的输出参数(删除节点)
typedef struct tagDH_OUT_ORGANIZATION_DELETE_NODES 
{
    DWORD               dwSize;
} DH_OUT_ORGANIZATION_DELETE_NODES;

// CLIENT_OrganizationGetNodes接口的输入参数(获取节点信息)
typedef struct tagDH_IN_ORGANIZATION_GET_NODES 
{
    DWORD               dwSize;
    char*               pszPath;                        // 路径
    int                 nLevel;                         // 级别, 0-本级, 1-下一级
} DH_IN_ORGANIZATION_GET_NODES;

// CLIENT_OrganizationGetNodes接口的输出参数(获取节点信息)
typedef struct tagDH_OUT_ORGANIZATION_GET_NODES 
{
    DWORD                   dwSize;
    DH_ORGANIZATION_NODE*   pstuNodes;                  // 节点数组, 用户分配内存
    int                     nMaxNodeCount;              // 节点数组大小
    int                     nRetNodeCount;              // 返回的节点数量
} DH_OUT_ORGANIZATION_GET_NODES;

// CLIENT_OrganizationSetNode接口的输入参数(设置节点)
typedef struct tagDH_IN_ORGANIZATION_SET_NODE 
{
    DWORD                dwSize;
    char*                pszPath;                    // 路径
    DH_ORGANIZATION_NODE stuNode;                    // 节点信息
} DH_IN_ORGANIZATION_SET_NODE;

// CLIENT_OrganizationSetNode接口的输出参数(设置节点)
typedef struct tagDH_OUT_ORGANIZATION_SET_NODE 
{
    DWORD               dwSize;
} DH_OUT_ORGANIZATION_SET_NODE;

// 视频输入通道信息
typedef struct tagDH_VIDEO_INPUTS
{
    DWORD               dwSize;
    char                szChnName[DH_DEVICE_NAME_LEN];      // 通道名称
    BOOL                bEnable;                            // 使能
    char                szControlID[DH_DEV_ID_LEN_EX];      // 控制ID
    char                szMainStreamUrl[MAX_PATH];          // 主码流url地址 
    char                szExtraStreamUrl[MAX_PATH];         // 辅码流url地址
} DH_VIDEO_INPUTS;

typedef struct tagDH_REMOTE_DEVICE 
{
    DWORD               dwSize;
    BOOL                bEnable;                            // 使能
    char                szIp[DH_MAX_IPADDR_LEN];            // IP
    char                szUser[DH_USER_NAME_LENGTH];        // 用户名
    char                szPwd[DH_USER_PSW_LENGTH];          // 密码
    int                 nPort;                              // 端口
    int                 nDefinition;                        // 清晰度, 0-标清, 1-高清
    DH_DEVICE_PROTOCOL  emProtocol;                         // 协议类型
    char                szDevName[DH_DEVICE_NAME_LEN];      // 设备名称
    int                 nVideoInputChannels;                // 视频输入通道数
    int                 nAudioInputChannels;                // 音频输入通道数
    char                szDevClass[DH_DEV_TYPE_LEN];        // 设备类型, 如IPC, DVR, NVR等
    char                szDevType[DH_DEV_TYPE_LEN];         // 设备具体型号, 如IPC-HF3300
    int                 nHttpPort;                          // Http端口
    int                 nMaxVideoInputCount;                // 视频输入通道最大数
    int                 nRetVideoInputCount;                // 返回实际通道个数
    DH_VIDEO_INPUTS*    pstuVideoInputs;                    // 视频输入通道信息
    char                szMachineAddress[DH_MAX_CARD_INFO_LEN]; // 设备部署地
    char                szSerialNo[DH_SERIALNO_LEN];        // 设备序列号
    int                 nRtspPort;                          // Rtsp端口
} DH_REMOTE_DEVICE;

typedef enum tagNET_LOGIC_CHANNEL_TYPE
{
    LOGIC_CHN_UNKNOWN,              // 未知
    LOGIC_CHN_LOCAL,                // 本地通道
    LOGIC_CHN_REMOTE,               // 远程通道
    LOGIC_CHN_COMPOSE,              // 合成通道, 对于司法设备包含画中画通道和混音通道
    LOGIC_CHN_MATRIX,               // 矩阵通道，包含模拟矩阵和数字矩阵
} NET_LOGIC_CHN_TYPE;

// 可用的显示源信息
typedef struct tagDH_MATRIX_CAMERA_INFO
{
    DWORD               dwSize;
    char                szName[DH_DEV_ID_LEN_EX];           // 名称
    char                szDevID[DH_DEV_ID_LEN_EX];          // 设备ID
    char                szControlID[DH_DEV_ID_LEN_EX];      // 控制ID
    int                 nChannelID;                         // 通道号, DeviceID设备内唯一
    int                 nUniqueChannel;                     // 设备内统一编号的唯一通道号
    BOOL                bRemoteDevice;                      // 是否远程设备
    DH_REMOTE_DEVICE    stuRemoteDevice;                    // 远程设备信息
    NET_STREAM_TYPE     emStreamType;                       // 视频码流类型
    NET_LOGIC_CHN_TYPE  emChannelType;                      // 通道类型
} DH_MATRIX_CAMERA_INFO;

// CLIENT_MatrixGetCameras接口的输入参数
typedef struct tagDH_IN_MATRIX_GET_CAMERAS 
{
    DWORD               dwSize;
} DH_IN_MATRIX_GET_CAMERAS;

// CLIENT_MatrixGetCameras接口的输出参数
typedef struct tagDH_OUT_MATRIX_GET_CAMERAS 
{
    DWORD                   dwSize;
    DH_MATRIX_CAMERA_INFO*  pstuCameras;                    // 显示源信息数组, 用户分配内存
    int                     nMaxCameraCount;                // 显示源数组大小
    int                     nRetCameraCount;                // 返回的显示源数量
} DH_OUT_MATRIX_GET_CAMERAS;

// CLIENT_MatrixSetCameras接口的输入参数
typedef struct tagDH_IN_MATRIX_SET_CAMERAS 
{
    DWORD                   dwSize;
    DH_MATRIX_CAMERA_INFO*  pstuCameras;                    // 显示源信息数组, 用户分配内存
    int                     nCameraCount;                   // 显示源数组大小
} DH_IN_MATRIX_SET_CAMERAS;

// CLIENT_MatrixSetCameras接口的输出参数
typedef struct tagDH_OUT_MATRIX_SET_CAMERAS 
{
    DWORD                   dwSize;
} DH_OUT_MATRIX_SET_CAMERAS;

// 电视墙显示单元
typedef struct tagDH_MONITORWALL_OUTPUT 
{
    DWORD               dwSize;
    char                szDeviceID[DH_DEV_ID_LEN];          // 设备ID, 本机时为""
    int                 nChannel;                           // 通道号
    char                szName[DH_DEV_NAME_LEN];            // 屏幕名称
} DH_MONITORWALL_OUTPUT;

// 电视墙显示区块
typedef struct tagDH_MONITORWALL_BLOCK
{
    DWORD                   dwSize;
    char                    szName[DH_DEV_NAME_LEN];        // 区块名称
    char                    szCompositeID[DH_DEV_ID_LEN];   // 拼接屏ID
    char                    szControlID[DH_DEV_ID_LEN];     // 控制ID
    int                     nSingleOutputWidth;             // 单个显示单元所占的网格列数
    int                     nSingleOutputHeight;            // 单个显示单元所占的网格行数
    DH_RECT                 stuRect;                        // 区域坐标
    DH_TSECT                stuPowerSchedule[DH_TSCHE_DAY_NUM][DH_TSCHE_SEC_NUM]; // 开机时间表, 第一维各元素表示周日~周六和节假日
    DH_MONITORWALL_OUTPUT*  pstuOutputs;                    // 显示单元数组, 用户分配内存
    int                     nMaxOutputCount;                // 显示单元数组大小, 用户填写
    int                     nRetOutputCount;                // 返回的显示单元数量
} DH_MONITORWALL_BLOCK;

// 电视墙配置
typedef struct tagDH_MONITORWALL 
{
    DWORD                   dwSize;
    char                    szName[DH_DEV_NAME_LEN];        // 名称
    int                     nGridLine;                      // 网格行数
    int                     nGridColume;                    // 网格列数
    DH_MONITORWALL_BLOCK*   pstuBlocks;                     // 显示区块数组, 用户分配内存
    int                     nMaxBlockCount;                 // 显示区块数组大小, 用户填写
    int                     nRetBlockCount;                 // 返回的显示区块数量
} DH_MONITORWALL;

// 窗口显示源信息
typedef struct tagDH_SPLIT_WND_SOURCE 
{
    DWORD                   dwSize;
    BOOL                    bEnable;                        // 显示源是否有效
    char                    szDeviceID[DH_DEV_ID_LEN];      // 设备ID
    char                    szControlID[DH_DEV_ID_LEN];     // 控制ID
    int                     nVideoChannel;                  // 视频通道号
    int                     nVideoStream;                   // 视频码流类型
    int                     nAudioChannel;                  // 音频通道
    int                     nAudioStream;                   // 音频码流类型
    int                     nUniqueChannel;                 // 设备内统一编号的唯一通道号, 只读
    BOOL                    bRemoteDevice;                  // 是否远程设备
    DH_REMOTE_DEVICE        stuRemoteDevice;                // 远程设备信息
} DH_SPLIT_WND_SOURCE;

// 分割窗口信息
typedef struct tagDH_SPLIT_WINDOW 
{
    DWORD                   dwSize;
    BOOL                    bEnable;                        // 窗口是否有视频源
    int                     nWindowID;                      // 窗口ID
    char                    szControlID[DH_DEV_ID_LEN];     // 控制ID
    DH_RECT                 stuRect;                        // 窗口区域, 自由分割模式下有效
    BOOL                    bDirectable;                    // 坐标是否满足直通条件
    int                     nZOrder;                        // 窗口Z次序
    DH_SPLIT_WND_SOURCE     stuSource;                      // 显示信息
} DH_SPLIT_WINDOW;

// 拼接屏场景
typedef struct tagDH_SPLIT_SCENE 
{
    DWORD                   dwSize;
    char                    szCompositeID[DH_DEV_ID_LEN];   // 拼接屏ID
    char                    szControlID[DH_DEV_ID_LEN];     // 控制ID
    DH_SPLIT_MODE           emSplitMode;                    // 分割模式
    DH_SPLIT_WINDOW*        pstuWnds;                       // 窗口信息数组, 用户分配内存
    int                     nMaxWndCount;                   // 窗口信息数组大小, 用户填写
    int                     nRetWndCount;                   // 返回的窗口数量
} DH_SPLIT_SCENE;

// 电视墙场景
typedef struct tagDH_MONITORWALL_SCENE
{
    DWORD                   dwSize;
    char                    szName[DH_DEV_NAME_LEN];        // 当前预案名称
    char                    szControlID[DH_DEV_ID_LEN];     // 控制ID
    DH_MONITORWALL          stuMonitorWall;                 // 电视墙配置    
    DH_SPLIT_SCENE*         pstuSplitScene;                 // 拼接屏场景信息数组, 用户分配内存
    int                     nMaxSplitSceneCount;            // 拼接屏场景数组大小, 用户填写
    int                     nRetSplitSceneCount;            // 返回的拼接屏场景数量
} DH_MONITORWALL_SCENE;

// CLIENT_MonitorWallGetScene接口输入参数(获取电视墙场景)
typedef struct tagDH_IN_MONITORWALL_GET_SCENE 
{
    DWORD                   dwSize;
    int                     nMonitorWallID;                 // 电视墙序号
} DH_IN_MONITORWALL_GET_SCENE;

// CLIENT_MonitorWallGetScene接口输出参数(获取电视墙场景)
typedef struct tagDH_OUT_MONITORWALL_GET_SCENE 
{
    DWORD                   dwSize;
    char                    szName[DH_DEV_NAME_LEN];        // 当前预案名称, 可以为空
    DH_MONITORWALL_SCENE    stuScene;                       // 电视墙场景
} DH_OUT_MONITORWALL_GET_SCENE;

// CLIENT_MonitorWallSetScene接口输入参数(设置电视墙场景)
typedef struct tagDH_IN_MONITORWALL_SET_SCENE 
{
    DWORD                   dwSize;
    int                     nMonitorWallID;                 // 电视墙序号
    DH_MONITORWALL_SCENE    stuScene;                       // 电视墙场景
} DH_IN_MONITORWALL_SET_SCENE;

// CLIENT_MonitorWallSetScene接口输出参数(设置电视墙场景)
typedef struct tagDH_OUT_MONITORWALL_SET_SCENE 
{
    DWORD                   dwSize;
} DH_OUT_MONITORWALL_SET_SCENE;

//CLIENT_QueryNetStat接口,查询类型为NET_APP_DATA_STAT时的输入参数(获取协议栈统计数据)
typedef struct tagNET_IN_NETAPP_NET_DATA_STAT
{
    DWORD       dwSize;    
    char        szEthName[DH_MAX_ETH_NAME];                //网卡名
}NET_IN_NETAPP_NET_DATA_STAT;

//接收相关统计数据,意义与ifconfig同
typedef struct tagNET_NETAPP_RECEIVE_STAT
{
    DWORD        dwSize;
    DWORD        dwPackets;
    DWORD        dwBytes;
    DWORD        dwErrors;
    DWORD        dwDroped;
    DWORD        dwOverruns;
    DWORD        dwFrame;
}NET_NETAPP_RECEIVE_STAT;

//传输相关统计数据,意义与ifconfig同
typedef struct tagNET_NETAPP_TRANSMIT_STAT
{
    DWORD        dwSize;
    DWORD        dwPackets;
    DWORD        dwBytes;
    DWORD        dwErrors;
    DWORD        dwDroped;
    DWORD        dwOverruns;
    DWORD        dwCarrier;
    DWORD        dwCollisions;
    DWORD        dwTxQueue;
}NET_NETAPP_TRANSMIT_STAT;

//CLIENT_QueryNetStat接口,查询类型为NET_APP_DATA_STAT时的输出参数(获取协议栈统计数据)
typedef struct tagNET_OUT_NETAPP_NET_DATA_STAT
{                    
    DWORD                        dwSize;
    NET_NETAPP_RECEIVE_STAT      stuReceiveStat;        // 接收相关统计数据，意义与ifconfig同
    NET_NETAPP_TRANSMIT_STAT     stuTransmitStat;       // 传输相关统计数据，意义与ifconfig同
    int                          nSpeed;                // 网卡速度，单位Mbps
}NET_OUT_NETAPP_NET_DATA_STAT;

//CLIENT_QueryNetStat接口,查询类型为NET_APP_LINK_STAT 时的输入参数(获取物理链路状态)
typedef struct tagNET_IN_NETAPP_LINK_STATUS
{
    DWORD       dwSize;
    char        szEthName[DH_MAX_ETH_NAME];             //网卡名
}NET_IN_NETAPP_LINK_STATUS;

//CLIENT_QueryNetStat接口,查询类型为NET_APP_LINK_STAT 时的输出参数(获取物理链路状态)
typedef struct tagNET_OUT_NETAPP_LINK_STATUS
{
    DWORD       dwSize;
    BOOL        bWorking;               // 是否正在工作 
    BOOL        bIPConflict;            // IP是否冲突
}NET_OUT_NETAPP_LINK_STATUS;

// 输入信号类型
#define DH_VIDEO_SIGNAL_CVBS        0x0001
#define DH_VIDEO_SIGNAL_SDI         0x0002
#define DH_VIDEO_SIGNAL_VGA         0x0004 
#define DH_VIDEO_SIGNAL_DVI         0x0008
#define DH_VIDEO_SIGNAL_HDMI        0x0010 
#define DH_VIDEO_SIGNAL_YPBPR       0x0020 
#define DH_VIDEO_SIGNAL_SFP         0x0040 
#define DH_VIDEO_SIGNAL_HDCVI       0x0080 
#define DH_VIDEO_SIGNAL_DUAL_LINK   0x0100 

// 视频输入能力集
typedef struct tagDH_VIDEO_IN_CAPS 
{
    DWORD            dwSize;
    DWORD            dwSignalType;                  // 输入信号类型
    BOOL             bAutoFocusPeak;                // 是否支持聚焦峰值计算
    BOOL             bElectricFocus;                // 是否支持电动调焦
    BOOL             bSyncFocus;                    // 是否支持同步对焦
    BOOL             bSetColor;                     // 是否支持视频颜色设置
} DH_VIDEO_IN_CAPS;

// CLIENT_GetVideoInCaps接口输入参数
typedef struct tagDH_IN_GET_VIDEO_IN_CAPS 
{
    DWORD            dwSize;
    int              nChannel;                      // 视频输入通道号
} DH_IN_GET_VIDEO_IN_CAPS;

// CLIENT_GetVideoInCaps接口输出参数
typedef struct tagDH_OUT_GET_VIDEO_IN_CAPS 
{
    DWORD            dwSize;
    DH_VIDEO_IN_CAPS stuCaps;                       // 能力
} DH_OUT_GET_VIDEO_IN_CAPS;

// 视频输出模式
typedef struct tagDH_VIDEO_OUT_MODE 
{
    DWORD            dwSize;
    int              nWidth;                        // 水平分辨率
    int              nHeight;                       // 垂直分辨率
    int              nBPP;                          // 颜色深度
    int              nFormat;                       // 输出信号模式, 0-Auto, 1-TV, 2-VGA, 3-DVI
    int              nRefreshRate;                  // 刷新频率
    int              nPhysicalPort;                 // 物理输出口, VGA, TV, DVI各自独立编号, 各自从0开始
    int              nScanFormat;                   // 扫描模式, 0-逐行, 1-隔行
} DH_VIDEO_OUT_MODE;

// CLIENT_EnumVideoOutModes接口输入参数
typedef struct tagDH_IN_ENUM_VIDEO_OUT_MODES 
{
    DWORD            dwSize;
    int              nChannel;
} DH_IN_ENUM_VIDEO_OUT_MODES;

// CLIENT_EnumVideoOutModes接口输出参数
typedef struct tagDH_OUT_ENUM_VIDEO_OUT_MODES 
{
    DWORD               dwSize;
    DH_VIDEO_OUT_MODE*  pstuModes;                  // 模式数组, 用户分配内存
    int                 nMaxModeCount;              // 模式数组大小, 用户填写
    int                 nRetModeCount;              // 返回的模式数量
} DH_OUT_ENUM_VIDEO_OUT_MODES;

// 电视墙屏幕能力类型
typedef enum tagDH_OUTPUT_ATTRIBUTE_TYPE
{
    DH_OUTPUT_ATTRIBUTE_VIDEO, 
    DH_OUTPUT_ATTRIBUTE_YPBPR, 
    DH_OUTPUT_ATTRIBUTE_VGA, 
    DH_OUTPUT_ATTRIBUTE_DVI, 
    DH_OUTPUT_ATTRIBUTE_MENU, 
} DH_OUTPUT_ATTRIBUTE_TYPE;

// 电视墙显示单元屏幕调节能力集(DH_OUTPUT_ATTRIBUTE_CAPS) Video能力
#define    DH_ATTR_VIDEO_BRIGHTNESS     0X00000001
#define    DH_ATTR_VIDEO_CONTRAST       0X00000002
#define    DH_ATTR_VIDEO_SATURATION     0X00000004
#define    DH_ATTR_VIDEO_SHAPENESS      0X00000008
#define    DH_ATTR_VIDEO_DENOISE        0X00000010

// 电视墙显示单元屏幕调节能力集(DH_OUTPUT_ATTRIBUTE_CAPS) YPbPr能力
#define    DH_ATTR_YPBPR_BRIGHTNESS     0X00000001
#define    DH_ATTR_YPBPR_CONTRAST       0X00000002
#define    DH_ATTR_YPBPR_SATURATION     0X00000004
#define    DH_ATTR_YPBPR_SHAPENESS      0X00000008
#define    DH_ATTR_YPBPR_DENOISE        0X00000010

// 电视墙显示单元屏幕调节能力集(DH_OUTPUT_ATTRIBUTE_CAPS) VGA能力
#define    DH_ATTR_VGA_BRIGHTNESS       0X00000001
#define    DH_ATTR_VGA_CONTRAST         0X00000002
#define    DH_ATTR_VGA_HORPOSITION      0X00000004
#define    DH_ATTR_VGA_VERPOSITION      0X00000008
#define    DH_ATTR_VGA_CLOCK            0X00000010

// 电视墙显示单元屏幕调节能力集(DH_OUTPUT_ATTRIBUTE_CAPS) DVI能力
#define    DH_ATTR_DVI_BRIGHTNESS       0X00000001
#define    DH_ATTR_DVI_CONTRAST         0X00000002
#define    DH_ATTR_DVI_HORPOSITION      0X00000004
#define    DH_ATTR_DVI_VERPOSITION      0X00000008
#define    DH_ATTR_DVI_CLOCK            0X00000010

// 电视墙显示单元屏幕调节能力集(DH_OUTPUT_ATTRIBUTE_CAPS) Menu能力
#define    DH_ATTR_MENU_MENU            0X00000001
#define    DH_ATTR_MENU_UP              0X00000002
#define    DH_ATTR_MENU_DOWN            0X00000004
#define    DH_ATTR_MENU_LEFT            0X00000008
#define    DH_ATTR_MENU_RIGHT           0X00000010
#define    DH_ATTR_MENU_FACTORYMENU     0X00000020

// 电视墙显示单元屏幕调节能力集
typedef struct tagDH_OUTPUT_ATTRIBUTE_CAPS
{
    DWORD           dwSize;
    BOOL            abVideo;                // Video能力是否有效
    DWORD           dwVideo;                // Video能力, 按位表示, 具体见DH_ATTR_VIDEO_BRIGHTNESS等
    BOOL            abYPbPr;                // YPbPr能力是否有效
    DWORD           dwYPbPr;                // YPbPr能力, 按位表示, 具体见DH_ATTR_VGA_BRIGHTNESS等
    BOOL            abVGA;                  // VGA能力是否有效
    DWORD           dwVGA;                  // VGA能力, 按位表示, 具体见DH_ATTR_VGA_BRIGHTNESS等
    BOOL            abDVI;                  // DVI能力是否有效
    DWORD           dwDVI;                  // DVI能力, 按位表示, 具体见DH_ATTR_DVI_BRIGHTNESS
    BOOL            abMenu;                 // Menu能力是否有效
    DWORD           dwMemu;                 // Menu能力, 按位表示, 具体见DH_ATTR_MENU_MENU等
} DH_OUTPUT_ATTRIBUTE_CAPS;

// CLIENT_MonitorWallGetAttributeCaps 接口输入参数
typedef struct tagDH_IN_MONITORWALL_GET_ARRT_CAPS
{
    DWORD               dwSize;
    int                 nMonitorWallID;             // 电视墙序号
    const char*         pszCompositeID;             // 拼接屏ID
    int                 nOutputID;                  // 显示单元序号
} DH_IN_MONITORWALL_GET_ARRT_CAPS;

// CLIENT_MonitorWallGetAttributeCaps 接口输出参数
typedef struct tagDH_OUT_MONITORWALL_GET_ARRT_CAPS
{
    DWORD                       dwSize;
    DH_OUTPUT_ATTRIBUTE_CAPS    stuCaps;            // 属性能力集
} DH_OUT_MONITORWALL_GET_ARRT_CAPS;


// CLIENT_MonitorWallAutoAdjust 接口输入参数
typedef struct tagDH_IN_MONITORWALL_AUTO_ADJUST
{
    DWORD           dwSize;
    int             nMonitorWallID;                 // 电视墙序号
    const char*     pszCompositeID;                 // 拼接屏ID
    int*            pOutputs;                       // 显示单元序号数组指针, 数组元素是显示单元ID, 用户申请内存
    int             nOutputCount;                   // 显示单元数量, pOutputs元素数量
} DH_IN_MONITORWALL_AUTO_ADJUST;

// CLIENT_MonitorWallAutoAdjust 接口输出参数
typedef struct tagDH_OUT_MONITORWALL_AUTO_ADJUST
{
    DWORD           dwSize;
} DH_OUT_MONITORWALL_AUTO_ADJUST;

// 显示单元属性键值对
typedef struct tagDH_ATTR_PAIR
{
    DWORD       dwKey;                      // 属性键
                                            // 类型为DH_OUTPUT_ATTRIBUTE_VIDEO时, 使用宏DH_ATTR_VIDEO_BRIGHTNESS等
                                            // 类型为DH_OUTPUT_ATTRIBUTE_YPBPR时, 使用宏DH_ATTR_YPBPR_BRIGHTNESS等
                                            // 其他的类型以此类推
    int         nValue;                     // 属性值, 0-减少 1-增加, 2-不变
} DH_ATTR_PAIR;

// CLIENT_MonitorWallSetAttribute 接口输入参数
typedef struct tagDH_IN_MONITORWALL_SET_ATTR
{
    DWORD                    dwSize;
    int                      nMonitorWallID;                    // 电视墙序号
    const char*              pszCompositeID;                    // 拼接屏ID
    int                      nOutputID;                         // 显示单元序号
    DH_OUTPUT_ATTRIBUTE_TYPE emAttrType;                        // 属性类型, 类型不同时, 对应的属性(stuAttrs)也不同
    DH_ATTR_PAIR             stuAttrs[DH_MAX_ATTR_NUM];         // 属性值
} DH_IN_MONITORWALL_SET_ATTR;

// CLIENT_MonitorWallSetAttribute 接口输出参数
typedef struct tagDH_OUT_MONITORWALL_SET_ATTR
{
    DWORD            dwSize;
} DH_OUT_MONITORWALL_SET_ATTR;

// CLIENT_MonitorWallSetBackLight 接口输入参数
typedef struct tagDH_IN_MONITORWALL_SET_BACK_LIGHT
{
    DWORD               dwSize;
    int                 nMonitorWallID;                     // 电视墙序号
    const char*         pszCompositeID;                     // 拼接屏ID
    int                 nOutputID;                          // 显示单元序号
    int                 nMode;                              // 背光模式, 0-循环设置背光模式，1-非循环模式
} DH_IN_MONITORWALL_SET_BACK_LIGHT;

// CLIENT_MonitorWallSetBackLight 接口输出参数
typedef struct tagDH_OUT_MONITORWALL_SET_BACK_LIGHT
{
    DWORD               dwSize;
} DH_OUT_MONITORWALL_SET_BACK_LIGHT;


// CLIENT_MonitorWallGetPowerSchedule 接口输入参数
typedef struct tagNET_IN_WM_GET_POWER_SCHEDULE
{
    DWORD               dwSize;
    int                 nMonitorWallID;                     // 电视墙序号
    const char*         pszCompositeID;                     // 拼接屏ID
} NET_IN_MW_GET_POWER_SCHEDULE;

// CLIENT_MonitorWallGetPowerSchedule 接口输出参数
typedef struct tagNET_OUT_MW_GET_POWER_SCHEDULE
{
    DWORD               dwSize;
    DH_TSECT            stuPowerSchedule[DH_TSCHE_DAY_NUM][DH_TSCHE_SEC_NUM];    // 开机时间表, 第一维各元素表示周日~周六和节假日
} NET_OUT_MW_GET_POWER_SCHEDULE;

// CLIENT_MonitorWallSetPowerSchedule 接口输入参数
typedef struct tagNET_IN_MW_SET_POWER_SCHEDULE
{
    DWORD               dwSize;
    int                 nMonitorWallID;                     // 电视墙序号
    const char*         pszCompositeID;                     // 拼接屏ID, NULL表示所有屏
    DH_TSECT            stuPowerSchedule[DH_TSCHE_DAY_NUM][DH_TSCHE_SEC_NUM];    // 开机时间表, 第一维各元素表示周日~周六和节假日
} NET_IN_MW_SET_POWER_SCHEDULE;

// CLIENT_MonitorWallSetPowerSchedule 接口输出参数
typedef struct tagNET_OUT_MW_SET_POWER_SCHEDULE
{
    DWORD               dwSize;
} NET_OUT_MW_SET_POWER_SCHEDULE;

// CLIENT_MonitorWallGetScrnCtrlParam 接口输入参数
typedef struct tagNET_IN_MW_GET_SCRN_CTRL_PARAM
{
    DWORD               dwSize;
    int                 nMonitorWallID;                     // 电视墙序号
    const char*         pszCompositeID;                     // 拼接屏ID
} NET_IN_MW_GET_SCRN_CTRL_PARAM;

#define DH_MAX_SCREEN_PORT_NUM        16                    // 最大屏幕输入端口数
#define DH_MAX_COMPSITE_SCREEN_NUM    256                   // 最大拼接屏数量

// 屏幕输入端口信息
typedef struct tagNET_SCREEN_PORT_INFO
{
    DWORD               dwSize;
    char                szType[DH_COMMON_STRING_16];        // 端口类型, "DVI", "VGA", "HDMI"等, 允许存在相同类型的多个端口
    char                szAddress[DH_COMMON_STRING_16];     // 端口地址
    char                szDeviceID[DH_DEV_ID_LEN_EX];       // 绑定的视频输出设备号
    int                 nOutputChannel;                     // 视频输出通道号
} NET_SCREEN_PORT_INFO;


typedef struct tagNET_SCREEN_PORT_GROUP 
{
    DWORD                dwSize;
    int                  nPortNum;                          // 端口数
    NET_SCREEN_PORT_INFO stuPorts[DH_MAX_SCREEN_PORT_NUM];  // 端口信息
} NET_SCREEN_PORT_GROUP;

// 电视墙屏幕控制参数
typedef struct tagNET_WM_SCRN_CTRL_PARAM
{
    DWORD                   dwSize;
    int                     nCommPort;                                  // 串口号
    DH_COMM_PROP            stuCommProp;                                // 串口属性
    char                    szProtocol[DH_COMMON_STRING_32];            // 串口协议
    int                     nResolutionNum;                             // 分辨率数量
    CAPTURE_SIZE            emResolutions[DH_MAX_CAPTURE_SIZE_NUM];     // 视频分辨率列表
    int                     nScreenCodeNum;                             // 屏幕编码数
    char                    szScreenCode[DH_MAX_COMPSITE_SCREEN_NUM][DH_COMMON_STRING_16];    // 屏幕编码, 串口命令寻址用, 该编码由用户配置, 可以相同
    int                     nScreenPortsNum;                            // 屏幕输入端口信息数量
    NET_SCREEN_PORT_GROUP   stuScreenPorts[DH_MAX_COMPSITE_SCREEN_NUM]; // 屏幕输入端口信息    
} NET_WM_SCRN_CTRL_PARAM;

// CLIENT_MonitorWallGetScrnCtrlParam 接口输入参数
typedef struct tagNET_OUT_MW_GET_SCRN_CTRL_PARAM
{
    DWORD                   dwSize;
    NET_WM_SCRN_CTRL_PARAM  stuScrnCtrlParam;           // 屏幕控制参数
} NET_OUT_MW_GET_SCRN_CTRL_PARAM;

// CLIENT_MonitorWallSetScrnCtrlParam 接口输入参数
typedef struct tagNET_IN_MW_SET_SCRN_CTRL_PARAM
{
    DWORD                   dwSize;
    int                     nMonitorWallID;             // 电视墙序号
    const char*             pszCompositeID;             // 拼接屏ID
    NET_WM_SCRN_CTRL_PARAM  stuScrnCtrlParam;           // 屏幕控制参数
} NET_IN_MW_SET_SCRN_CTRL_PARAM;

// CLIENT_MonitorWallSetScrnCtrlParam 接口输出参数
typedef struct tagNET_OUT_MW_SET_SCRN_CTRL_PARAM
{
    DWORD           dwSize;
} NET_OUT_MW_SET_SCRN_CTRL_PARAM;

// CLIENT_MonitorWallGetBackgroudColor 接口输入参数
typedef struct tagNET_IN_MW_GET_BACKGROUDND_COLOR
{
    DWORD           dwSize;
    int             nMonitorWallID;             // 电视墙序号
} NET_IN_MW_GET_BACKGROUDND_COLOR;

// CLIENT_MonitorWallGetBackgroudColor 接口输出参数
typedef struct tagNET_OUT_MW_GET_BACKGROUDND_COLOR
{
    DWORD           dwSize;
    DH_COLOR_RGBA   stuScreenColor;             // 屏幕背景色
    DH_COLOR_RGBA   stuWindowColor;             // 窗口背景色
} NET_OUT_MW_GET_BACKGROUDND_COLOR;

// CLIENT_MonitorWallSetBackgroudColor 接口输入参数
typedef struct tagNET_IN_MW_SET_BACKGROUD_COLOR 
{
    DWORD           dwSize;
    int             nMonitorWallID;             // 电视墙序号
    DH_COLOR_RGBA   stuScreenColor;             // 屏幕背景色
    DH_COLOR_RGBA   stuWindowColor;             // 窗口背景色
} NET_IN_MW_SET_BACKGROUD_COLOR;

// CLIENT_MonitorWallSetBackgroudColor 接口输出参数
typedef struct tagNET_OUT_MW_SET_BACKGROUD_COLOR 
{
    DWORD           dwSize;
} NET_OUT_MW_SET_BACKGROUD_COLOR;

// 电视墙操作类型
typedef enum tagNET_MONITORWALL_OPERATE_TYPE
{
    NET_MONITORWALL_OPERATE_ADD,            // 添加电视墙, 对应 NET_IN_MONITORWALL_ADD 和 NET_OUT_MONITORWALL_ADD
    NET_MONITORWALL_OPERATE_CTRL_TOUR,      // 预案轮巡控制, 对应 NET_IN_CTRL_COLLECTIONTOUR 和 NET_OUT_CTRL_COLLECTIONTOUR
    NET_MONITORWALL_OPERATE_GET_STATUS,     // 获取矩阵当前状态, 对应 NET_IN_MONITORWALL_GET_STATUS 和 NET_OUT_MONITORWALL_GET_STATUS
} NET_MONITORWALL_OPERATE_TYPE;

// 添加电视墙输入参数
typedef struct tagNET_IN_MONITORWALL_ADD
{
    DWORD dwSize;
    DH_MONITORWALL stuMonitorWall; // 电视墙信息
} NET_IN_MONITORWALL_ADD;

// 添加电视墙输出参数
typedef struct tagNET_OUT_MONITORWALL_ADD
{
    DWORD dwSize;
    unsigned int nMonitorWallID; // 电视墙ID
} NET_OUT_MONITORWALL_ADD;

// CLIENT_OperateMonitorWall接口输入参数=>NET_MONITORWALL_OPERATE_CTRL_TOUR
typedef struct tagNET_IN_CTRL_COLLECTIONTOUR 
{
    DWORD              dwSize;
    int                nChannel;                       // 通道号
    int                nAction;                        // 轮巡动作, 0:结束, 1:开始
} NET_IN_CTRL_COLLECTIONTOUR;

// CLIENT_OperateMonitorWall接口输出参数=>NET_MONITORWALL_OPERATE_CTRL_TOUR
typedef struct tagNET_OUT_CTRL_COLLECTIONTOUR 
{
    DWORD                   dwSize;
} NET_OUT_CTRL_COLLECTIONTOUR;

// 矩阵运行状态
typedef enum tagNET_MATRIX_STATUS
{
    MATRIX_STATUS_UNKNOWN,              // 未知
    MATRIX_STATUS_TOUR,                 // 预案轮巡
    MATRIX_STATUS_NORMAL,               // 普通预览
} NET_MATRIX_STATUS;

#define DH_MAX_COLLECTION_NUM   64      // 最大预案数
// 矩阵状态信息
typedef struct tagNET_MONITORWALL_STATUS_INFO
{
    DWORD       dwSize;
    int         nInterval;                      // 轮巡时间间隔
    int         nCollectionNum;                 // 预案轮巡数
    char        szCollections[DH_MAX_COLLECTION_NUM][DH_DEVICE_NAME_LEN];         // 预案轮巡组内容
    char        szName[DH_DEVICE_NAME_LEN];     // 当前显示的预案名称
} NET_MONITORWALL_STATUS_INFO;

// // CLIENT_OperateMonitorWall接口输入参数=>NET_MONITORWALL_OPERATE_GET_STATUS
typedef struct tagNET_IN_MONITORWALL_GET_STATUS 
{
    DWORD              dwSize;
    int                nChannel;                        // 通道号
} NET_IN_MONITORWALL_GET_STATUS;

// CLIENT_OperateMonitorWall接口输出参数=>NET_MONITORWALL_OPERATE_GET_STATUS
typedef struct tagNET_OUT_MONITORWALL_GET_STATUS
{
    DWORD                           dwSize;
    NET_MATRIX_STATUS               emMatrixStatus;     // 运行状态
    NET_MONITORWALL_STATUS_INFO     stuStatusInfo;      // 状态信息
} NET_OUT_MONITORWALL_GET_STATUS;

/************************************************************************/
/*  							U盘抓包									*/
/************************************************************************/

// CLIENT_StartSniffer 接口输入参数
typedef struct tagDH_IN_START_SNIFFER 
{
    DWORD           dwSize;
    const char*     pszNetInterface;            // 网卡名称
    const char*     pszPath;                    // 抓包存储文件名, 空表示保存到默认路径
    int             nSaveType;                  // 文件类型, 0-Wireshark/Tcpdump
    const char*     pszFilter;                  // 过滤条件, 如"host 172.9.88.200 and port 8080 and tcp"
} DH_IN_START_SNIFFER;

// CLIENT_StartSniffer 接口输出参数
typedef struct tagDH_OUT_START_SNIFFER 
{
    DWORD           dwSize;
} DH_OUT_START_SNIFFER;

// 抓包信息
typedef struct tagDH_SNIFFER_INFO
{
    DWORD           dwSize;
    DWORD           nSnifferID;                 // 抓包ID
} DH_SNIFFER_INFO;

// CLIENT_GetSnifferInfo 接口输入参数
typedef struct tagDH_IN_GET_SNIFFER_INFO
{
    DWORD           dwSize;
    const char*     pszNetInterface;
} DH_IN_GET_SNIFFER_INFO;

// CLIENT_GetSnifferInfo 接口输入参数
typedef struct tagDH_OUT_GET_SNIFFER_INFO
{
    DWORD               dwSize;
    DH_SNIFFER_INFO*    pstuSniffers;           // 抓包信息数组, 用户分配内存
    int                 nMaxSnifferCount;       // 抓包信息数组大小, 用户填写
    int                 nRetSnifferCount;       // 返回的抓包信息数量
} DH_OUT_GET_SNIFFER_INFO;

/************************************************************************/
/*  							文件管理								*/
/************************************************************************/

// 格式化分区信息
typedef struct tagDH_FORMAT_PATITION 
{
    DWORD               dwSize;
    const char*         pszStorageName;         // 存储设备名称
    const char*         pszPatitionName;        // 分区名
} DH_FORMAT_PATITION;

// CLIENT_CreateRemoteFile 接口输入参数
typedef struct tagDH_IN_CREATE_REMOTE_FILE
{
    DWORD               dwSize;
    const char*         pszPath;                // 文件名
    BOOL                bDirectory;             // 是否文件夹
} DH_IN_CREATE_REMOTE_FILE;

// CLIENT_CreateRemoteFile 接口输出参数
typedef struct tagDH_OUT_CREATE_REMOTE_FILE 
{
    DWORD               dwSize;
} DH_OUT_CREATE_REMOTE_FILE;

// CLIENT_RemoveRemoteFiles 接口输入参数
typedef struct tagDH_IN_REMOVE_REMOTE_FILES
{
    DWORD               dwSize;
    const char**        pszPath;                // 文件路径数组指针
    int                 nFileCount;             // 文件路径数量
} DH_IN_REMOVE_REMOTE_FILES;

// CLIENT_RemoveRemoteFiles 接口输出参数
typedef struct tagDH_OUT_REMOVE_REMOTE_FILES 
{
    DWORD               dwSize;
} DH_OUT_REMOVE_REMOTE_FILES;

// CLIENT_RenameRemoteFile 接口输入参数
typedef struct tagDH_IN_RENAME_REMOTE_FILE
{
    DWORD               dwSize;
    const char*         pszOldPath;             // 旧文件名
    const char*         pszNewPath;             // 新文件名
} DH_IN_RENAME_REMOTE_FILE;

// CLIENT_RenameRemoteFile 接口输出参数
typedef struct tagDH_OUT_RENAME_REMOTE_FILE 
{
    DWORD               dwSize;
} DH_OUT_RENAME_REMOTE_FILE;

// 文件/目录信息
typedef struct tagDH_REMOTE_FILE_INFO 
{
    DWORD               dwSize;
    BOOL                bDirectory;                     // 是否文件夹
    char                szPath[MAX_PATH];               // 路径
    NET_TIME            stuCreateTime;                  // 创建时间
    NET_TIME            stuModifyTime;                  // 修改时间
    INT64               nFileSize;                      // 文件大小
    char                szFileType[DH_FILE_TYPE_LEN];   // 文件类型
} DH_REMOTE_FILE_INFO;

// CLIENT_ListRemoteFile 接口输入参数
typedef struct tagDH_IN_LIST_REMOTE_FILE
{
    DWORD               dwSize;
    const char*         pszPath;                        // 路径
    BOOL                bFileNameOnly;                  // 只获取文件名称, 不返回文件夹信息, 文件信息中只有文件名有效
} DH_IN_LIST_REMOTE_FILE;

// CLIENT_ListRemoteFile 接口输出参数
typedef struct tagDH_OUT_LIST_REMOTE_FILE 
{
    DWORD                   dwSize;
    DH_REMOTE_FILE_INFO*    pstuFiles;                  // 文件信息数组, 用户分配内存
    int                     nMaxFileCount;              // 文件信息数组大小, 用户填写
    int                     nRetFileCount;              // 返回的文件数量
} DH_OUT_LIST_REMOTE_FILE;

// 手动弹出存储设备
typedef struct tagDH_EJECT_STORAGE_DEVICE
{
    DWORD               dwSize;    
    const char*         pszStorageName;                 // 存储设备名称
} DH_EJECT_STORAGE_DEVICE;

// 手动装载存储设备
typedef struct tagDH_LOAD_STORAGE_DEVICE 
{
    DWORD               dwSize;
    const char*         pszStorageName;                 // 存储设备名称
} DH_LOAD_STORAGE_DEVICE;

// CLIENT_UploadRemoteFile 接口输入参数(上传文件到设备)
typedef struct tagDH_IN_UPLOAD_REMOTE_FILE
{
    DWORD               dwSize;
    const char*         pszFileSrc;                     // 源文件路径
    const char*         pszFileDst;                     // 目标文件路径
} DH_IN_UPLOAD_REMOTE_FILE;

// CLIENT_UploadRemoteFile 接口输出参数(上传文件到设备)
typedef struct tagDH_OUT_UPLOAD_REMOTE_FILE
{
    DWORD               dwSize;
} DH_OUT_UPLOAD_REMOTE_FILE;

// CLIENT_DownloadRemoteFile 接口输入参数(文件下载)
typedef struct tagDH_IN_DOWNLOAD_REMOTE_FILE
{
    DWORD               dwSize;
    const char*         pszFileName;                    // 需要下载的文件名
    const char*         pszFileDst;                     // 存放文件路径
} DH_IN_DOWNLOAD_REMOTE_FILE;

// CLIENT_DownloadRemoteFile 接口输出参数(文件下载)
typedef struct tagDH_OUT_DOWNLOAD_REMOTE_FILE
{
    DWORD               dwSize;
} DH_OUT_DOWNLOAD_REMOTE_FILE;

/************************************************************************/
/* 								级联设备								*/
/************************************************************************/
// 级联设备搜索条件
typedef struct tagDH_IN_SEARCH_CONDITON
{
    DWORD               dwSize;
    const char*         pMachineName;                   // 设备名称或编号
    const char*         pMachineAddr;                   // 设备部署地点(如：滨江区.江南大道.伟业路口)
    const char*         pSerialNo;                      // 设备序列号
    const char*         pChannelName;                   // 视频输入通道名
} DH_MATRIX_SEARCH_CONDITON;

// CLIENT_MatrixSearch 接口输入参数(搜索级联设备)
typedef struct tagDH_IN_MATIRX_SEARCH
{
    DWORD                       dwSize;
    const char*                 pSerialNo;              // 搜索设备序列号,"Local"-本设备，"Root"-根设备，其它设备以设备的序列号表示
    DH_MATRIX_SEARCH_CONDITON   stuCondition;           // 搜索条件, 可以为单一条件或组合
} DH_IN_MATRIX_SEARCH;

// CLIENT_MatrixSearch 接口输出参数(搜索级联设备)
typedef struct tagDH_OUT_MATRIX_SEARCH
{
    DWORD               dwSize;
    DH_REMOTE_DEVICE*   pstuRemoteDevices;              // 设备列表, 用户分配内存
    int                 nMaxDeviceCount;                // 设备列表最大值, 用户填写
    int                 nRetDeviceCount;                // 实际返回设备个数
} DH_OUT_MATRIX_SEARCH;

// CLIENT_GetMatrixTree 接口输入参数
typedef struct tagDH_IN_GET_MATRIX_TREE
{
    DWORD               dwSize;
    const char*         pSerialNo;                      // 搜索设备序列号,"Local"-本设备，"Root"-根设备，其它设备以设备的序列号表示
    int                 nLevel;                         // 获得几级设备信息，0-整个设备树，1-本级设备，2-本级设备+本设备级联下一级设备，
                                                        // 3-本级设备+本设备级联下一级设备+下一级设备的下一级设备
} DH_IN_GET_MATRIX_TREE;

// 级联设备信息
typedef struct tagDH_CASCADE_DEVICE_INFO
{
    DWORD               dwSize;
    int                 nLevel;                         // 当前设备所属级数
    char                szPath[MAX_PATH];               // 设备所属路径，格式：name1.name2.name3...
    DH_REMOTE_DEVICE    stuDeviceInfo;                  // 设备详细信息
} DH_CASCADE_DEVICE_INFO;

// CLIENT_GetMatrixTree 接口输出参数
typedef struct tagDH_OUT_GET_MATRIX_TREE
{
    DWORD                   dwSize;
    DH_CASCADE_DEVICE_INFO* pstuRemoteDevices;          // 级联设备信息
    int                     nMaxDeviceCount;            // 级联设备信息最大值
    int                     nRetDeviceCount;            // 返回的实际设备个数
} DH_OUT_GET_MATRIX_TREE;

// CLIENT_GetSuperiorMatrixList 接口输入参数
typedef struct tagDH_IN_GET_SUPERIOR_MATRIX_LIST
{
    DWORD                   dwSize;
} DH_IN_GET_SUPERIOR_MATRIX_LIST;

// CLIENT_GetSuperiorMatrixList 接口输出参数
typedef struct tagDH_OUT_GET_SUPERIOR_MATRIX_LIST
{
    DWORD                   dwSize;
    DH_REMOTE_DEVICE*       pstuRemoteDevices;          // 设备列表, 用户分配内存
    int                     nMaxDeviceCount;            // 设备列表最大值, 用户填写
    int                     nRetDeviceCount;            // 实际返回设备个数
} DH_OUT_GET_SUPERIOR_MATRIX_LIST;

////////////////////////////////////录像备份恢复//////////////////////////////////////

// 录像备份恢复任务信息
typedef struct tagDH_RECORD_BACKUP_RESTORE_TASK
{
    DWORD               dwSize;
    unsigned int        nTaskID;                        // 任务ID
    char                szDeviceID[DH_DEV_ID_LEN_EX];   // 设备ID
    int                 nChannelID;                     // 通道号
    NET_TIME            stuStartTime;                   // 开始时间
    NET_TIME            stuEndTime;                     // 结束时间
    int                 nState;                         // 当前备份状态, 0-等待, 1-进行中, 2-完成, 3-失败
} DH_REC_BAK_RST_TASK;

// CLIENT_AddRecordBackupRestoreTask接口输入参数
typedef struct tagDH_IN_ADD_RECORD_BACKUP_RESTORE_TASK
{
    DWORD               dwSize;
    const char*         pszDeviceID;                    // 设备ID
    int*                pnChannels;                     // 通道数组
    int                 nChannelCount;                  // 通道数组大小
    NET_TIME            stuStartTime;                   // 起始时间
    NET_TIME            stuEndTime;                     // 结束时间
} DH_IN_ADD_REC_BAK_RST_TASK;

// CLIENT_RemoveRecordBackupRestoreTask接口输入参数
typedef struct tagDH_IN_REMOVE_RECORD_BACKUP_RESTORE_TASK
{
    DWORD               dwSize;
    unsigned int*       pnTaskIDs;                      // 任务ID数组
    int                 nTaskCount;                     // 任务数量
} DH_IN_REMOVE_REC_BAK_RST_TASK;

// CLIENT_QueryRecordBackupRestoreTask接口输入参数
typedef struct tagDH_IN_QUERY_RECORD_BACKUP_RESTORE_TASK
{
    DWORD               dwSize;
} DH_IN_QUERY_REC_BAK_RST_TASK;

// CLIENT_QueryRecordBackupRestoreTask接口输出参数
typedef struct tagDH_OUT_QUERY_RECORD_BACKUP_RESTORE_TASK
{
    DWORD                   dwSize;
    DH_REC_BAK_RST_TASK*    pTasks;                     // 任务数组
    int                     nMaxCount;                  // 数组大小
    int                     nReturnCount;               // 返回的任务数量
} DH_OUT_QUERY_REC_BAK_RST_TASK;

typedef struct tagDH_LOGIC_DEVICE_ADD_CAMERA_PARAM
{
    DWORD                   dwSize;
    const char*             pszDeviceID;                // 设备ID
    int                     nChannel;                   // 通道号
} DH_LOGIC_DEVICE_ADD_CAMERA_PARAM;

typedef struct tagDH_LOGIC_DEVICE_ADD_CAMERA_RESULT
{
    DWORD                   dwSize;
    char                    szDeviceID[DH_DEV_ID_LEN];  // 设备ID
    int                     nChannel;                   // 通道号
    int                     nUniqueChannel;             // 统一编号
    int                     nFailedCode;                // 失败码, 0-成功，1-Unique地址空间用完 2-已经添加
} DH_LOGIC_DEVICE_ADD_CAMERA_RESULT;

// CLIENT_AddLogicDeviceCamera 接口输入参数
typedef struct tagDH_IN_ADD_LOGIC_DEVICE_CAMERA
{
    DWORD                   dwSize;
    DH_LOGIC_DEVICE_ADD_CAMERA_PARAM* pCameras;         // 视频源信息数组
    int                     nCameraCount;               // 视频源信息数量
} DH_IN_ADD_LOGIC_DEVICE_CAMERA;

// CLIENT_AddLogicDeviceCamera 接口输出参数
typedef struct tagDH_OUT_ADD_LOGIC_DEVICE_CAMERA 
{
    DWORD                   dwSize;
    DH_LOGIC_DEVICE_ADD_CAMERA_RESULT* pResults;        // 添加视频源结果数组, 用户分配内存
    int                     nMaxResultCount;            // 结果数组大小, 用户填写
    int                     nRetResultCount;            // 实际结果数量
} DH_OUT_ADD_LOGIC_DEVICE_CAMERA;

/************************************************************************/
/*                         数据库记录操作                               */
/************************************************************************/
typedef struct tagNET_AUTHORITY_TYPE
{
  DWORD                       dwSize; 
  EM_NET_AUTHORITY_TYPE       emAuthorityType;                          //权限类型
  BOOL                        bAuthorityEnable;                         //权限使能
}NET_AUTHORITY_TYPE;

// 交通黑白名单记录信息
typedef struct tagNET_TRAFFIC_LIST_RECORD
{
  DWORD                      dwSize; 
  int                        nRecordNo;                                 // 之前查询到的记录号
  char                       szMasterOfCar[DH_MAX_NAME_LEN];            // 车主姓名
  char                       szPlateNumber[DH_MAX_PLATE_NUMBER_LEN];    // 车牌号码 
  EM_NET_PLATE_TYPE          emPlateType;                               // 车牌类型
  EM_NET_PLATE_COLOR_TYPE    emPlateColor;                              // 车牌颜色 
  EM_NET_VEHICLE_TYPE        emVehicleType;                             // 车辆类型 
  EM_NET_VEHICLE_COLOR_TYPE  emVehicleColor;                            // 车身颜色
  NET_TIME                   stBeginTime;                               // 开始时间
  NET_TIME                   stCancelTime;                              // 撤销时间
  int                        nAuthrityNum;                              // 权限个数
  NET_AUTHORITY_TYPE         stAuthrityTypes[DH_MAX_AUTHORITY_LIST_NUM];// 权限列表 , 白名单仅有
  EM_NET_TRAFFIC_CAR_CONTROL_TYPE emControlType;                        // 布控类型 ，黑名单仅有
}NET_TRAFFIC_LIST_RECORD;

// 交通黑白名单账户记录查询条件
typedef struct
{
    DWORD                    dwSize;
    char                     szPlateNumber[DH_MAX_PLATE_NUMBER_LEN];      // 车牌号
    char                     szPlateNumberVague[DH_MAX_PLATE_NUMBER_LEN]; // 车牌号码模糊查询
    int                      nQueryResultBegin;                           // 第一个条返回结果在查询结果中的偏移量 
    BOOL                     bRapidQuery;                                 // 是否快速查询, TRUE:为快速，快速查询时不等待所有增、删、改操作完成。默认为非快速查询
}FIND_RECORD_TRAFFICREDLIST_CONDITION;

// 刻录案件记录查询条件
typedef struct
{
    DWORD                    dwSize;
    NET_TIME                 stuStartTime;                      // 起始时间
    NET_TIME                 stuEndTime;                        // 结束时间
}FIND_RECORD_BURN_CASE_CONDITION;


// 门禁卡记录查询条件
typedef struct tagFIND_RECORD_ACCESSCTLCARD_CONDITION
{
    DWORD                    dwSize;
    char                     szCardNo[DH_MAX_CARDNO_LEN];      // 卡号
    char                     szUserID[DH_MAX_USERID_LEN];      // 用户ID
    BOOL                     bIsValid;                         // 是否有效, TRUE:有效,FALSE:无效
}FIND_RECORD_ACCESSCTLCARD_CONDITION;

// 门禁密码记录查询条件
typedef struct tagFIND_RECORD_ACCESSCTLPWD_CONDITION
{
    DWORD                     dwSize;
    char                      szUserID[DH_MAX_USERID_LEN];      // 用户ID
}FIND_RECORD_ACCESSCTLPWD_CONDITION;

// 门禁出入记录查询条件
typedef struct tagFIND_RECORD_ACCESSCTLCARDREC_CONDITION
{
    DWORD                     dwSize;
    char                      szCardNo[DH_MAX_CARDNO_LEN];      // 卡号
    NET_TIME                  stStartTime;                      // 起始时间
    NET_TIME                  stEndTime;                        // 结束时间
}FIND_RECORD_ACCESSCTLCARDREC_CONDITION;

// 假日记录集查询条件
typedef struct tagFIND_RECORD_ACCESSCTLHOLIDAY_CONDITION
{
    DWORD                     dwSize;
}FIND_RECORD_ACCESSCTLHOLIDAY_CONDITION;

// CLIENT_FindRecord接口输入参数
typedef struct _NET_IN_FIND_RECORD_PARAM
{
    DWORD                     dwSize;          // 结构体大小
    EM_NET_RECORD_TYPE        emType;          // 待查询记录类型
    void*                     pQueryCondition; // 查询类型对应的查询条件 
}NET_IN_FIND_RECORD_PARAM;

// CLIENT_FindRecord接口输出参数
typedef struct _NET_OUT_FIND_RECORD_PARAM
{
    DWORD                     dwSize;          // 结构体大小
    LLONG                     lFindeHandle;    // 查询记录句柄，唯一标识某次查询
}NET_OUT_FIND_RECORD_PARAM;

// CLIENT_FindNextRecord接口输入参数
typedef struct _NET_IN_FIND_NEXT_RECORD_PARAM
{
    DWORD                     dwSize;          // 结构体大小
    LLONG                     lFindeHandle;    // 查询句柄
    int                       nFileCount;      // 当前想查询的记录条数
}NET_IN_FIND_NEXT_RECORD_PARAM;

// CLIENT_FindNextRecord接口输出参数
typedef struct _NET_OUT_FIND_NEXT_RECORD_PARAM
{
    DWORD                     dwSize;          // 结构体大小
    void*                     pRecordList;     // 记录列表，用户分配内存
    int                       nMaxRecordNum;   // 列表记录数
    int                       nRetRecordNum;   // 查询到的记录条数，当查询到的条数小于想查询的条数时，查询结束
}NET_OUT_FIND_NEXT_RECORD_PARAM;

typedef struct tagNET_INSERT_RECORD_INFO
{
    DWORD                     dwSize;
    NET_TRAFFIC_LIST_RECORD   *pRecordInfo;    // 记录内容信息                
}NET_INSERT_RECORD_INFO;

typedef struct tagNET_UPDATE_RECORD_INFO
{
    DWORD                     dwSize;
    NET_TRAFFIC_LIST_RECORD   *pRecordInfo;    // 记录内容信息                
}NET_UPDATE_RECORD_INFO;

typedef struct tagNET_REMOVE_RECORD_INFO
{
    DWORD                     dwSize;
    int                       nRecordNo;       // 之前查询到的记录号    
}NET_REMOVE_RECORD_INFO;

typedef struct tagNET_IN_OPERATE_TRAFFIC_LIST_RECORD
{
    DWORD                     dwSize;
    
    EM_RECORD_OPERATE_TYPE    emOperateType;
    EM_NET_RECORD_TYPE        emRecordType;    // 要操作的记录类型
    void                      *pstOpreateInfo;
    
}NET_IN_OPERATE_TRAFFIC_LIST_RECORD;

//现阶段实现的操作接口中，只有返回nRecordNo的操作，stRetRecord暂时不可用
typedef struct tagNET_OUT_OPERATE_TRAFFIC_LIST_RECORD
{
    DWORD                     dwSize;
    int                       nRecordNo;        //记录号    
}NET_OUT_OPERATE_TRAFFIC_LIST_RECORD;

//云台控制坐标单元
typedef struct tagPTZ_SPEED_UNIT
{
    float                  fPositionX;           //云台水平方向速率，归一化到-1~1
    float                  fPositionY;           //云台垂直方向速率，归一化到-1~1
    float                  fZoom;                //云台光圈放大倍率，归一化到 0~1
    char                   szReserve[32];        //预留32字节
}PTZ_SPEED_UNIT;

//云台控制坐标单元
typedef struct tagPTZ_SPACE_UNIT
{
    int                    nPositionX;           //云台水平运动位置，有效范围：[0,3600]
    int                    nPositionY;           //云台垂直运动位置，有效范围：[-1800,1800]
    int                    nZoom;                //云台光圈变动位置，有效范围：[0,128]
    char                   szReserve[32];        //预留32字节
}PTZ_SPACE_UNIT;

//持续控制云台对应结构
typedef struct tagPTZ_Control_Continuously
{
    PTZ_SPEED_UNIT         stuSpeed;              //云台运行速度
    int                    nTimeOut;              //连续移动超时时间，单位为秒
    char                   szReserve[64];         //预留64字节
}PTZ_CONTROL_CONTINUOUSLY;

//绝对控制云台对应结构
typedef struct tagPTZ_Control_Absolutely
{
    PTZ_SPACE_UNIT         stuPosition;           //云台绝对速度
    PTZ_SPEED_UNIT         stuSpeed;              //云台运行速度
    char                   szReserve[64];         //预留64字节
}PTZ_CONTROL_ABSOLUTELY;

// 报警输入通道信息
typedef struct tagNET_ALARM_IN_CHANNEL
{
    DWORD                   dwSize;
    BOOL                    bValid;                             // 是否有效, FALSE表示该报警通道没有使用
    int                     nChannel;                           // 报警通道号
    char                    szDeviceID[DH_DEV_ID_LEN];          // 设备ID, 本地报警通道: "Local", 远程设备: 使用uuid表示
    char                    szName[DH_DEV_NAME_LEN];            // 报警通道名称
}NET_ALARM_IN_CHANNEL;

// 报警通道数
typedef struct tagNET_ALARM_CHANNEL_COUNT 
{
    DWORD                   dwSize;
    int                     nLocalAlarmIn;                      // 本地报警输入通道数
    int                     nLocalAlarmOut;                     // 本地报警输出通道数
    int                     nRemoteAlarmIn;                     // 远程报警输入通道数
    int                     nRemoteAlarmOut;                    // 远程报警输出通道数
}NET_ALARM_CHANNEL_COUNT;

//带速度转动到预置位点云台控制对应结构
typedef struct tagPTZ_Control_GotoPreset
{
    int                     nPresetIndex;           //预置位索引
    PTZ_SPEED_UNIT          stuSpeed;               //云台运行速度
    char                    szReserve[64];          //预留64字节
}PTZ_CONTROL_GOTOPRESET;

// CLIENT_SetTourSource 接口输入参数(设置窗口轮巡显示源)
typedef struct tagNET_IN_SET_TOUR_SOURCE 
{
    DWORD                   dwSize;
    int                     nChannel;               // 输出通道号
    int                     nWindow;                // 窗口号
    DH_SPLIT_SOURCE*        pstuSrcs;               // 显示源数组, 可进行窗口轮巡
    int                     nSrcCount;              // 显示源数量
} NET_IN_SET_TOUR_SOURCE;

// CLIENT_SetTourSource 接口输出参数(设置窗口轮巡显示源)
typedef struct tagNET_OUT_SET_TOUR_SOURCE
{
    DWORD                   dwSize;
} NET_OUT_SET_TOUR_SOURCE;

// fAttachRecordInfoCB 参数, 上报的录像文件信息
typedef struct tagNET_CB_RECORD_INFO
{
    DWORD                   dwSize;
    int                     nChannel;               // 通道号
    char                    szFileName[MAX_PATH];   // 录像名称
    DWORD                   dwType;                 // 录像类型, 按位定义如下：
                                                    // Bit0-定时录像
                                                    // Bit1-动态检测录像
                                                    // Bit2-报警录像
                                                    // Bit3-卡号录像
    DWORD                   dwState;                // 录像状态, 0-打包, 1-删除
} NET_CB_RECORD_INFO;

// 录像更新回调函数原形，lAttachHandle是CLIENT_AttachRecordInfo的返回值, 每次n条，pBuf->dwSize * n == nBufLen
typedef void (CALLBACK *fAttachRecordInfoCB)(LLONG lLoginID, LLONG lAttachHandle, NET_CB_RECORD_INFO* pBuf, int nBufLen, LDWORD dwUser);

// CLIENT_AttachRecordInfo 输入参数
typedef struct tagNET_IN_ATTACH_RECORD_INFO
{
    DWORD                   dwSize;
    int                     nInterval;              // 时间间隔, 设备每隔nInterval秒, 发送录像信息
    int                     nDelay;                 // 上报延时, 设备在1和nDelay值间选择随机数后，延迟上报录像状态, nDelay必须小于nInterval
    fAttachRecordInfoCB     cbAttachRecordInfo;     // 录像更新回调函数
    LDWORD                  dwUser;                 // 用户数据
} NET_IN_ATTACH_RECORD_INFO;

typedef struct tagNET_OUT_ATTACH_RECORD_INFO
{
    DWORD                   dwSize;
} NET_OUT_ATTACH_RECORD_INFO;


//订阅云台元数据接口回调函数原型
//pBuf 现阶段主要为 DH_PTZ_LOCATION_INFO 类型
typedef void (CALLBACK *fPTZStatusProcCallBack)(LLONG lLoginID, LLONG lAttachHandle, void* pBuf, int nBufLen, LDWORD dwUser);

// 订阅云台元数据接口输入参数
typedef struct tagNET_IN_PTZ_STATUS_PROC
{
    DWORD                   dwSize;
    int                     nChannel;              // 云台通道
    fPTZStatusProcCallBack  cbPTZStatusProc;       // 状态回调函数
    LDWORD                  dwUser;                // 用户数据
}NET_IN_PTZ_STATUS_PROC;

// 订阅云台元数据接口输输出参数
typedef struct tagNET_OUT_PTZ_STATUS_PROC
{
    DWORD                   dwSize;
}NET_OUT_PTZ_STATUS_PROC;

// 云台可视域状态结构
typedef struct tagDH_OUT_PTZ_VIEW_RANGE_STATUS
{
    DWORD      dwSize;
    double     dbDistance;                         // 可视距离, 单位:米
    int        nAngelH;                            // 水平可视角度, 0~1800, 单位:度
    int        nAzimuthH;                          // 水平方位角度, 0~3600, 单位:度
}DH_OUT_PTZ_VIEW_RANGE_STATUS;

//订阅云台可视域回调函数原型
typedef void (CALLBACK *fViewRangeStateCallBack)(LLONG lLoginID, LLONG lAttachHandle, DH_OUT_PTZ_VIEW_RANGE_STATUS* pBuf, int nBufLen, LDWORD dwUser);

// 订阅可视域输入参数
typedef struct tagNET_IN_VIEW_RANGE_STATE
{
    DWORD                   dwSize;
    int                     nChannel;              // 云台通道
    fViewRangeStateCallBack cbViewRange;           // 状态回调函数
    LDWORD                  dwUser;                // 用户数据
}NET_IN_VIEW_RANGE_STATE;

// 订阅可视域输出参数
typedef struct tagNET_OUT_VIEW_RANGE_STATE
{
    DWORD                   dwSize;
}NET_OUT_VIEW_RANGE_STATE;

//设置云台可视域信息
typedef struct tagPTZ_VIEW_RANGE_INFO
{
    int                     nStructSize;
    int                     nAzimuthH;              // 水平方位角度, 0~3600, 单位:度
}PTZ_VIEW_RANGE_INFO;

// 通道数量信息
typedef struct tagNET_CHN_COUNT_INFO
{
    DWORD                   dwSize;
    int                     nMaxTotal;              // 设备总通道数(所有有效通道数之和)
    int                     nCurTotal;              // 已配置的通道数
    int                     nMaxLocal;              // 最大本地通道数, 含主板和可插拔子卡通道
    int                     nCurLocal;              // 已配置本地通道数
    int                     nMaxRemote;             // 最大远程通道数
    int                     nCurRemote;             // 已配置远程通道数
} NET_CHN_COUNT_INFO;

// 设备通道数量信息
typedef struct tagNET_DEV_CHN_COUNT_INFO
{
    DWORD                   dwSize;
    NET_CHN_COUNT_INFO      stuVideoIn;             // 视频输入通道
    NET_CHN_COUNT_INFO      stuVideoOut;            // 视频输出通道
} NET_DEV_CHN_COUNT_INFO;

// 录像状态详细信息
typedef struct tagNET_RECORD_STATE_DETAIL 
{
    DWORD                   dwSize;
    BOOL                    bMainStream;            // 主码流, TRUE-正在录像, FALSE-没在录像
    BOOL                    bExtraStream1;          // 辅码流1, TRUE-正在录像, FALSE-没在录像
    BOOL                    bExtraStream2;          // 辅码流2, TRUE-正在录像, FALSE-没在录像
    BOOL                    bExtraStream3;          // 辅码流3, TRUE-正在录像, FALSE-没在录像
} NET_RECORD_STATE_DETAIL;

// OSN接口返回状态码
typedef enum{
    EM_OSN_OK,                                      // 操作成功
    EM_OSN_OK_P2P,                                  // 操作成功,创建映射类型P2P
    EM_OSN_OK_RELAYED,                              // 操作成功,创建映射类型RALAYED
    EM_OSN_ERROR_API_NOT_INITIALIZED,               // 初始化失败
    EM_OSN_ERROR_NO_NETWORK,                        // 无可用网络
    EM_OSN_ERROR_CANNOT_CONNECT_TO_AGENT,           // 无法连接到指定主机
    EM_OSN_ERROR_LOCAL_PORT_ALREADY_USED,           // 本地端口已使用
    EM_OSN_ERROR_AGENT_RESOURCES_LIMIT_REACHED,     // 无法连接，连接数达到上限
    EM_OSN_ERROR_INVALID_DEVICE_ID,                 // 设备ID非法
    EM_OSN_ERROR_INVALID_SERVICE_PORT,              // 服务端口非法
    EM_OSN_ERROR_INVALID_LOCAL_PORT,                // 本地端口非法
    EM_OSN_ERROR_INVALID_TUNNEL,                    // 映射信息非法(删除映射时)
    EM_OSN_ERROR                                    // 未知错误
}EM_OSN_STATUS;

// 建立映射输入参数
typedef struct {
    unsigned int             servicePort;           // 服务端口 (例如, 80,9000,1025 或 23)
    unsigned int             localPort;             // 本地端口 1024 - 65536，0表示自动分配
    const char*              pdeviceId;             // 设备ID
    BYTE                     Reserved[64];          // 保留
}OSN_IN_CREATE_TUNNEL_PARAM, *LOSN_IN_CREATE_TUNNEL_PARAM;

// 建立映射输出参数
typedef struct {
    unsigned int             servicePort;           // 服务端口 (例如, 80,9000,1025 或 23)
    unsigned int             localPort;             // 本地端口 1024 - 65536，0表示自动分配
    EM_OSN_STATUS            tunnelStatus;
    const char*              pdeviceId;             // 设备ID
    BYTE                     Reserved[64];          // 保留
}OSN_OUT_CREATE_TUNNEL_PARAM, *LOSN_OUT_CREATE_TUNNEL_PARAM;

// 删除映射输入参数
typedef struct {
    unsigned int             servicePort;           // 服务端口 (例如, 80,9000,1025 或 23)
    unsigned int             localPort;             // 本地端口 1024 - 65536，0表示自动分配
    EM_OSN_STATUS            tunnelStatus;
    const char*              pdeviceId;             // 设备ID
    BYTE                     Reserved[64];          // 保留
}OSN_IN_DESTROY_TUNNEL_PARAM, *LOSN_IN_DESTROY_TUNNEL_PARAM;

//云台绝对聚焦对应结构
typedef struct tagPTZ_Focus_Absolutely
{
    DWORD                    dwValue;               //云台聚焦位置,取值范围(0~8191)
    DWORD                    dwSpeed;               //云台聚焦速度,取值范围(0~7)
    char                     szReserve[64];         //预留64字节
}PTZ_FOCUS_ABSOLUTELY;

// CLIENT_PlayAudioFile 接口输入参数
typedef struct tagNET_IN_PLAY_AUDIO_FILE
{
    DWORD                   dwSize;
    const char*             pszFilePath;            // 文件路径
    DWORD                   dwOutput;               // 输出途径, 可以是多种输出, 按位表示, bit0-mic, bit1-speaker
} NET_IN_PLAY_AUDIO_FILE;

// CLIENT_PlayAudioFile 接口输出参数
typedef struct tagNET_OUT_PLAY_FILE_STREAM
{
    DWORD                   dwSize;
} NET_OUT_PLAY_AUDIO_FILE;

// RTSP URL信息列表结构
typedef struct tagNET_DEV_RTSPURL_LIST
{
    DWORD                   dwSize;
    int                     nChannelID;                                 // 通道号(用户输入参数)
    int                     nUrlNum;                                    // Url地址个数
    char                    szURLList[DH_MAX_URL_NUM][DH_MAX_URL_LEN];  // Url地址列表
}NET_DEV_RTSPURL_LIST;

// 云台控制-扇扫对应结构
typedef struct tagPTZ_Control_SectorScan
{
    int             nBeginAngle;                    //起始角度,范围:[-180,180]
    int             nEndAngle;                      //结束角度,范围:[-180,180]
    int             nSpeed;                         //速度,范围:[0,255]
    char            szReserve[64];                  //预留64字节
}PTZ_CONTROL_SECTORSCAN;

// CLIENT_TransmitInfoForWeb 接口扩展参数
typedef struct tagNET_TRANSMIT_EXT_INFO
{
    DWORD           dwSize;
    unsigned char*  pInBinBuf;                      // 二进制输入数据缓冲
    DWORD           dwInBinBufSize;                 // 二进制输入数据长度
} NET_TRANSMIT_EXT_INFO;

// 监听CAN总线数据
// fAttachProxyCB 参数
typedef struct tagNET_CB_CANDATA
{
    DWORD           dwSize;
    int             nDataLength;                    // 普通数据长度
    unsigned char*  pDataContent;                   // 普通数据内容
}NET_CB_CANDATA;

// 监听CAN总线数据回调函数原形，lAttachHandle是CLIENT_AttachCAN返回值
typedef void (CALLBACK *fAttachCANCB) (LLONG lLoginID, LLONG lAttachHandle, NET_CB_CANDATA* pBuf, LDWORD dwUser);

// CLIENT_AttachCAN()输入参数
typedef struct tagNET_IN_ATTACH_CAN
{
    DWORD          dwSize;
    int            nChannel;                        // 监听的CAN通道号
    fAttachCANCB   cbAttachCAN;                     // 注册视频电话状态变化回调
    LDWORD         dwUser;                          // 用户数据
}NET_IN_ATTACH_CAN;

// CLIENT_AttachCAN()输出参数
typedef struct tagNET_OUT_ATTACH_CAN
{
    DWORD          dwSize;
}NET_OUT_ATTACH_CAN;

// 订阅透明串口数据回调fAttachDevCommCB 参数
typedef struct tagNET_CB_DEVCOMMDATA
{
    DWORD           dwSize;
    int             nDataLength;                    // 普通数据长度
    unsigned char*  pDataContent;                   // 普通数据内容
}NET_CB_DEVCOMMDATA;

// 监听透明串口数据回调函数原形，lAttachHandle是CLIENT_AttachDevComm返回值
typedef void (CALLBACK *fAttachDevCommCB) (LLONG lLoginID, LLONG lAttachHandle, NET_CB_DEVCOMMDATA* pBuf, LDWORD dwUser);

// CLIENT_AttachDevComm()输入参数
typedef struct tagNET_IN_ATTACH_DEVCOMM
{
    DWORD               dwSize;
    int                 nChannel;                        // 监听的透明串口号
    fAttachDevCommCB    cbAttachDevComm;                 // 注册透明串口数据回调
    LDWORD              dwUser;                          // 用户数据
}NET_IN_ATTACH_DEVCOMM;

// CLIENT_AttachDevComm()输出参数
typedef struct tagNET_OUT_ATTACH_DEVCOMM
{
    DWORD          dwSize;
}NET_OUT_ATTACH_DEVCOMM;

// 获取当前设备串口个数，对应CLIENT_QueryDevState()接口的 DH_DEVSTATE_GET_COMM_COUNT 命令参数
typedef struct tagNET_GET_COMM_COUNT
{
    DWORD          dwSize;
    int            nChannelCout;                    // 获取到的串口数
}NET_GET_COMM_COUNT;

// CLIENT_ExChangeData 接口输入结构体
typedef struct tagNET_IN_EXCHANGEDATA
{
    DWORD           dwSize;
    int             nChannel;                       // 串口号
    BOOL            bFlag;                          // TRUE 为发送数据并等待回复，FALSE 只是采集数据
    int             nCollectTime;                   // 串口采集时长(单位：毫秒)
    int             nSendDataLength;                // 发送数据长度，bFlag = TRUE 有效
    unsigned char*  pSendData;                      // 发送数据内容，bFlag = TRUE 有效
}NET_IN_EXCHANGEDATA;

// CLIENT_ExChangeData 接口输出结构体
typedef struct tagNET_OUT_EXCHANGEDATA
{
    DWORD           dwSize;
}NET_OUT_EXCHANGEDATA;

// 云台预置点
typedef struct tagNET_PTZ_PRESET 
{
    int                     nIndex;                         // 编号
    char                    szName[PTZ_PRESET_NAME_LEN];    // 名称
    char                    szReserve[64];                  // 预留64字节
} NET_PTZ_PRESET;

// 云台预置点列表
typedef struct tagNET_PTZ_PRESET_LIST 
{
    DWORD                   dwSize;
    DWORD                   dwMaxPresetNum;                 // 预置点最大个数
    DWORD                   dwRetPresetNum;                 // 返回预置点个数
    NET_PTZ_PRESET          *pstuPtzPorsetList;             // 预置点列表(入参需要根据最大个数申请内存)
} NET_PTZ_PRESET_LIST;

// 事件类型 EVENT_IVS_TRAFFIC_RESTRICTED_PLATE (受限车牌事件)对应的数据块描述信息
typedef struct tagDEV_EVENT_TRAFFIC_RESTRICTED_PLATE
{
    int                     nChannelID;                     // 通道号
    char                    szName[DH_EVENT_NAME_LEN];      // 事件名称
    int                     nTriggerType;                   // TriggerType:触发类型，0车检器，1雷达，2视频
    DWORD                   PTS;                            // 时间戳(单位是毫秒)
    NET_TIME_EX             UTC;                            // 事件发生的时间
    int                     nEventID;                       // 事件ID
    int                     nSequence;                      // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    BYTE                    byEventAction;                  // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                    byImageIndex;                   // 图片的序号, 同一时间内(精确到秒)可能有多张图片, 从0开始
    BYTE                    byReserved1[2];
    int                     nLane;                          // 对应车道号
    DH_MSG_OBJECT           stuObject;                      // 检测到的物体
    DH_MSG_OBJECT           stuVehicle;                     // 车身信息
    DH_EVENT_FILE_INFO      stuFileInfo;                    // 事件对应文件信息
    int                     nMark;                          // 底层产生的触发抓拍帧标记
    int                     nFrameSequence;                 // 视频分析帧序号
    int                     nSource;                        // 视频分析的数据源地址
    DWORD                   dwSnapFlagMask;                 // 抓图标志(按位)，具体见NET_RESERVED_COMMON    
    DH_RESOLUTION_INFO      stuResolution;                  // 对应图片的分辨率
    DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stuTrafficCar;        // 交通车辆信息
    BYTE                    byReserved[1024];               // 保留字节
}DEV_EVENT_TRAFFIC_RESTRICTED_PLATE;

// 冗余电源异常报警
typedef struct tagALARM_POWER_ABNORMAL_INFO
{
    DWORD                   dwSize;
    int                     nChannelID;                     // 通道号
    NET_TIME                stuTime;                        // 时间
    DWORD                   dwAction;                       // 事件动作, 0:Start, 1:Stop
}ALARM_POWER_ABNORMAL_INFO;


#define UPDATE_VERSION_LEN        64

// 获取设备升级状态对应结构体
typedef struct tagDHDEV_UPGRADE_STATE_INFO
{
    int                  nState;                            // 0:None-没有检测到更新, 默认状态; 1:Regular-一般升级; 
                                                            // 2:Emergency-强制升级; 3:Upgrading-升级中
    
    char                szOldVersion[UPDATE_VERSION_LEN];   // 旧版本
    char                szNewVersion[UPDATE_VERSION_LEN];   // 新版本
    DWORD               dwProgress;                         // 升级进度
    int                 reserved[256];                      // 保留字段
}DHDEV_UPGRADE_STATE_INFO;


///////////////////////////////// 刻录会话 /////////////////////////////////////////

// CLIENT_StartBurnSession 接口输入参数
typedef struct tagNET_IN_START_BURN_SESSION 
{
    DWORD               dwSize;
    unsigned int        nSessionID;                         // 会话ID
} NET_IN_START_BURN_SESSION;

typedef struct tagNET_OUT_START_BURN_SESSION 
{
    DWORD               dwSize;
} NET_OUT_START_BURN_SESSION;

// 刻录模式
typedef enum tagNET_BURN_MODE
{
    BURN_MODE_SYNC,                     // 同步
    BURN_MODE_TURN,                     // 轮流
    BURN_MODE_CYCLE,                    // 循环
} NET_BURN_MODE;

// 刻录流格式
typedef enum tagNET_BURN_RECORD_PACK
{
    BURN_PACK_DHAV,                     // DHAV
    BURN_PACK_PS,                       // PS
    BURN_PACK_ASF,                      // ASF
    BURN_PACK_MP4,                      // MP4
    BURN_PACK_TS,                       // TS
} NET_BURN_RECORD_PACK;

// CLIENT_StartBurn 接口输入参数
typedef struct tagNET_IN_START_BURN 
{
    DWORD                dwSize;
    DWORD                dwDevMask;                             // 刻录设备掩码, 按位表示多个刻录设备组合
    int                  nChannels[DH_MAX_BURN_CHANNEL_NUM];    // 刻录通道数组
    int                  nChannelCount;                         // 刻录通道数
    NET_BURN_MODE        emMode;                                // 刻录模式
    NET_BURN_RECORD_PACK emPack;                                // 刻录流格式
} NET_IN_START_BURN;

// CLIENT_StartBurn 接口输出参数
typedef struct tagNET_OUT_START_BURN 
{
    DWORD               dwSize;
} NET_OUT_START_BURN;

// CLIENT_BurnMarkTag 接口输入参数
typedef struct tagNET_IN_BURN_MAAK_TAG
{
    DWORD               dwSize;
    const char*         pszDescInfo;                            // 标记描述信息
} NET_IN_BURN_MARK_TAG;

// CLIENT_BurnMarkTag 接口输出参数
typedef struct tagNET_OUT_BURN_MAAK_TAG
{
    DWORD               dwSize;
} NET_OUT_BURN_MARK_TAG;

// CLIENT_BurnChangeDisk 接口输入参数
typedef struct tagNET_IN_BURN_CHANGE_DISK
{
    DWORD               dwSize;
    BOOL                nAction;                                // 换盘动作, 0-开始, 1-结束
} NET_IN_BURN_CHANGE_DISK;

// CLIENT_BurnChangeDisk 接口输出参数
typedef struct tagNET_OUT_BURN_CHANGE_DISK
{
    DWORD               dwSize;
} NET_OUT_BURN_CHANGE_DISK;

// 刻录状态
typedef enum tagNET_BURN_STATE
{
    BURN_STATE_STOP,                    // 停止
    BURN_STATE_STOPING,                 // 停止中
    BURN_STATE_INIT,                    // 初始化
    BURN_STATE_BURNING,                 // 刻录中
    BURN_STATE_PAUSE,                   // 暂停
    BURN_STATE_CHANGE_DISK,             // 换盘中
    BURN_STATE_PREPARE_EXTRA_FILE,      // 附件初始化
    BURN_STATE_WAIT_EXTRA_FILE,         // 等待附件刻录
    BURN_STATE_UPLOAD_FILE_START,       // 附件刻录中
    BURN_STATE_CHECKING_DISK,           // 检测光盘中
    BURN_STATE_DISK_READY,              // 光盘准备就绪
} NET_BURN_STATE;

// 刻录错误码
typedef enum tagNET_BURN_ERROR_CODE
{
    BURN_CODE_NORMAL,                   // 正常
    BURN_CODE_UNKNOWN_ERROR,            // 未知错误
    BURN_CODE_SPACE_FULL,               // 刻录满
    BURN_CODE_START_ERROR,              // 开始刻录出错
    BURN_CODE_STOP_ERROR,               // 正常
    BURN_CODE_WRITE_ERROR,              // 刻录出错
} NET_BURN_ERROR_CODE;

// CLIENT_BurnGetState 接口输入参数
typedef struct tagNET_IN_BURN_GET_STATE
{
    DWORD                dwSize;
} NET_IN_BURN_GET_STATE;

// 刻录设备状态
typedef struct tagNET_BURN_DEV_STATE 
{
    DWORD                dwSize;
    int                  nDeviceID;                             // 光驱设备ID
    char                 szDevName[DH_BURNING_DEV_NAMELEN];     // 光驱设备名称
    DWORD                dwTotalSpace;                          // 光驱总容量, 单位KB
    DWORD                dwRemainSpace;                         // 光驱剩余容量, 单位KB
} NET_BURN_DEV_STATE;

// CLIENT_BurnGetState 接口输出参数
typedef struct tagNET_OUT_BURN_GET_STATE
{
    DWORD                dwSize;
    NET_BURN_STATE       emState;                               // 刻录状态
    NET_BURN_ERROR_CODE  emErrorCode;                           // 错误码
    DWORD                dwDevMask;                             // 刻录设备掩码, 按位表示多个刻录设备组合
    int                  nChannels[DH_MAX_BURN_CHANNEL_NUM];    // 刻录通道数组
    int                  nChannelCount;                         // 刻录通道数
    NET_BURN_MODE        emMode;                                // 刻录模式
    NET_BURN_RECORD_PACK emPack;                                // 刻录流格式
    int                  nFileIndex;                            // 当前刻录文件编号
    NET_TIME             stuStartTime;                          // 刻录开始时间
    NET_BURN_DEV_STATE   stuDevState[DH_MAX_BURNING_DEV_NUM];   // 刻录设备状态
} NET_OUT_BURN_GET_STATE;

// fAttachBurnStateCB 参数
typedef struct tagNET_CB_BURNSTATE
{
    DWORD               dwSize;
    const char*         szState;                        // 消息类型
                                                        //"UploadFileStart"：可以开始附件上传
                                                        //"InitBurnDevice":初始化刻录设备
                                                        //"Burning":刻录中
                                                        //"BurnExtraFileStop"：刻录停止
                                                        //"BurnFilePause":刻录暂停
                                                        //"SpaceFull":刻录空间满
                                                        //"BurnFileError":刻录出错    
    const char*         szFileName;                     // 当前刻录附件文件名,用于"UploadFileStart"开始附件上传消息
    unsigned int        dwTotalSpace;                   // 总容量,单位KB，用于"Burning"刻录中，显示容量或计算进度
    unsigned int        dwRemainSpace;                  // 剩余容量,单位KB，用于"Burning"刻录中
    const char*         szDeviceName;                   // 刻录设备名称,用于区分不同的刻录设备
}NET_CB_BURNSTATE;

// 刻录设备回调函数原形，lAttachHandle是CLIENT_AttachBurnState返回值, 每次1条，pBuf->dwSize == nBufLen
typedef void (CALLBACK *fAttachBurnStateCB) (LLONG lLoginID, LLONG lAttachHandle, NET_CB_BURNSTATE* pBuf, int nBufLen, LDWORD dwUser);

// 刻录设备回调扩展函数原形
typedef void (CALLBACK *fAttachBurnStateCBEx)(LLONG lLoginID, LLONG lAttachHandle, NET_OUT_BURN_GET_STATE* pBuf, int nBufLen, LDWORD dwUser);

// CLIENT_AttachBurnState()输入参数
typedef struct tagNET_IN_ATTACH_STATE
{
    DWORD                   dwSize;
    const char*             szDeviceName;                   // 光盘名称，如"/dev/sda"
    fAttachBurnStateCB      cbAttachState;                  // 刻录监听回调
    LDWORD                  dwUser;                         // 用户数据
    LLONG                   lBurnSession;                   // 刻录会话句柄, CLIENT_StartBurnSession的返回值. 该值为0时, szDeviceName有效, 此时按刻录设备订阅刻录状态
    fAttachBurnStateCBEx    cbAttachStateEx;                // 扩展刻录监听回调
    LDWORD                  dwUserEx;                       // 扩展刻录监听回调用户数据
}NET_IN_ATTACH_STATE;

// CLIENT_AttachBurnState 输出参数
typedef struct tagNET_OUT_ATTACH_STATE
{
    DWORD                   dwSize;
}NET_OUT_ATTACH_STATE;

// 刻录设备回调函数原形，lUploadHandle是CLIENT_StartUploadFileBurned返回值
typedef void (CALLBACK *fBurnFileCallBack) (LLONG lLoginID, LLONG lUploadHandle, int nTotalSize, int nSendSize, LDWORD dwUser);

// CLIENT_StartUploadFileBurned()输入参数
typedef struct tagNET_IN_FILEBURNED_START
{
    DWORD                   dwSize;
    const char*             szMode;                        // 文件上传方式"append",追加模式,此时刻录文件名固定为" FILE.zip ",filename被忽略
    const char*             szDeviceName;                  // 光盘名称，如“/dev/sda”
    const char*             szFilename;                    // 本地文件名称
    fBurnFileCallBack       cbBurnPos;                     // 刻录进度回调
    LDWORD                  dwUser;                        // 用户数据
    LLONG                   lBurnSession;                  // 刻录句柄, CLIENT_StartBurnSession的返回值. 该值为0时, szDeviceName有效, 此时按刻录设备订阅刻录状态
}NET_IN_FILEBURNED_START;

// CLIENT_StartUploadFileBurned 输出参数
typedef struct tagNET_OUT_FILEBURNED_START
{
    DWORD                   dwSize;
    char                    szState[DH_MAX_NAME_LEN];      // "start"：系统准备就绪,可以开始上传; "busy"：系统忙,稍后在试。"error"：系统未在刻录中,返回出错,请求失败
}NET_OUT_FILEBURNED_START;

// 刻录案件信息
typedef struct tagNET_BURN_CASE_INFO
{
    DWORD       dwSize;
    int         nChannel;                                   // 通道号
    NET_TIME    stuStartTime;                               // 刻录起始时间
    NET_TIME    stuEndTime;                                 // 刻录结束时间
    int         nIndex;                                     // 序号
    int         nCode;                                      // 编号
    int         nDiscNum;                                   // 光盘编号        
    char        szName[DH_COMMON_STRING_128];               // 名称
    char        szPlace[DH_COMMON_STRING_128];              // 办案地点
    char        szInvestigator[DH_MAX_CASE_PERSON_NUM][DH_COMMON_STRING_32]; // 办案人员
    char        szSuspects[DH_MAX_CASE_PERSON_NUM][DH_COMMON_STRING_32];     // 涉案人员
    char        szMemo[DH_COMMON_STRING_256];               // 备注
    char        szVideoName[DH_COMMON_STRING_128];          // 录像名称
    char        szRecorder[DH_COMMON_STRING_32];            // 刻录人
} NET_BURN_CASE_INFO;

// 刻录设备回调函数原形，lAttachHandle是CLIENT_AttachBurnCase返回值
typedef void (CALLBACK *fBurnCaseCallBack) (LLONG lAttachHandle, NET_BURN_CASE_INFO* pBuf, DWORD dwBufLen, void* pReserved, LDWORD dwUser);

// CLIENT_AttachBurnCase 接口输入参数
typedef struct tagNET_IN_ATTACH_BURN_CASE
{
    DWORD                dwSize;
    fBurnCaseCallBack    cbBurnCase;                        // 案件信息回调函数
    LDWORD               dwUser;                            // 用户数据
} NET_IN_ATTACH_BURN_CASE;

// CLIENT_AttachBurnCase 接口输出参数
typedef struct tagNET_OUT_ATTACH_BURN_CASE
{
    DWORD                dwSize;
} NET_OUT_ATTACH_BURN_CASE;

/////////////////////////////////// Storage ///////////////////////////////////////

// 远程存储写入结果
typedef enum tagNET_STORAGE_WRITE_STATE
{
    NS_WRITE_UNKNOWN,                                   // 未知
    NS_WRITE_OK,                                        // 成功
    NS_WRITE_DISK_IO_ERROR,                             // 磁盘IO错误
    NS_WRITE_DISK_NOT_READY,                            // 磁盘未准备好
    NS_WRITE_DISK_FAULT,                                // 磁盘故障
    NS_WRITE_STREAM_NOT_EXIST,                          // 数据流ID不存在
    NS_WRITE_MOUNT_DISK_ERROR,                          // 磁盘挂载错误
} NET_STORAGE_WRITE_STATE;

// 远程区块信息
typedef struct tagNET_STORAGE_BLOCK 
{
    DWORD                   dwSize;
    unsigned int            nID;                        // CQFS块ID
    unsigned int            nStreamID;                  // 数据流唯一标识
    unsigned int            nRecycleTimestamp;          // CQFS回收时间戳
    unsigned int            nBeginTimestamp;            // 块内数据开始时间戳
    unsigned int            nEndTimestamp;              // 块内数据结束时间戳
    unsigned int            nLockCount;                 // 锁定计数值, 0表示未锁定
    char                    szDiskUUID[DH_COMMON_STRING_64]; // 磁盘UUID
} NET_STORAGE_BLOCK;

// 远程存储的信息状态
typedef struct tagNET_STORAGE_WRITE_INFO
{
    DWORD                    dwSize;
    NET_STORAGE_WRITE_STATE  emState;                   // 写入结果
    int                      nBlockCount;               // 块数量
    NET_STORAGE_BLOCK        stuBlocks[DH_MAX_NET_STRORAGE_BLOCK_NUM]; // 块信息
} NET_STORAGE_WRITE_INFO;

//////////////////////////////////////////////////////////////////////////
/// \fn 订阅写入远程存储的信息状态回调函数
/// \brief 
/// \author yang_xiuqing
/// \param  LLONG lAttachHandle [OUT] 订阅句柄, CLIENT_NetStorageAttachWriteInfo的返回值 
/// \param  NET_STORAGE_WRITE_INFO * pBuf [OUT] 远程存储的信息状态
/// \param  int nBufLen [OUT] 状态信息长度
/// \param  LDWORD dwUser 用户数据
/// \return 无
///////////////////////////////////////////////////////////////////////////
typedef void (CALLBACK *fNetStorageAttachWriteInfoCB)(LLONG lAttachHandle, NET_STORAGE_WRITE_INFO* pBuf, int nBufLen, LDWORD dwUser);

// CLIENT_NetStorageAttachWriteInfo 接口输入参数
typedef struct tagNET_IN_STORAGE_ATTACH_WRITE_INFO
{
    DWORD                           dwSize;
    const char*                     pszName;                // 远程存储名称, 值从NAS配置中获取
    fNetStorageAttachWriteInfoCB    cbISCSIBlcok;           // 回调函数
    LDWORD                          dwUser;                 // 用户数据
} NET_IN_STORAGE_ATTACH_WRITE_INFO;

// CLIENT_NetStorageAttachWriteInfo 接口输出参数
typedef struct tagNET_OUT_STORAGE_ATTACH_WRITE_INFO
{
    DWORD                       dwSize;
} NET_OUT_STORAGE_ATTACH_WRITE_INFO;

// CLIENT_NetStorageGetWriteInfo 接口输入参数
typedef struct tagNET_IN_STORAGE_GET_WRITE_INFO 
{
    DWORD                       dwSize;
    const char*                 pszName;                    // 远程存储名称
} NET_IN_STORAGE_GET_WRITE_INFO;

// CLIENT_NetStorageGetWriteInfo 接口输出参数
typedef struct tagNET_OUT_STORAGE_GET_WRITE_INFO 
{
    DWORD                       dwSize;    
    int                         nBlockCount;                // 块数量
    NET_STORAGE_BLOCK           stuBlocks[DH_MAX_NET_STRORAGE_BLOCK_NUM]; // 块信息
} NET_OUT_STORAGE_GET_WRITE_INFO;

// RAID操作类型
typedef enum tagNET_RAID_OPERATE_TYPE
{
    NET_RAID_OPERATE_ADD,                    // 添加RAID, 对应结构体 NET_IN_RAID_ADD 和 NET_OUT_RAID_ADD
    NET_RAID_OPERATE_REMOVE,                 // 删除RAID, 对应结构体 NET_IN_RAID_REMOVE 和 NET_OUT_RAID_REMOVE
    NET_RAID_OPERATE_GET_SUBDEVICE,          // 获取RAID子设备信息, 对应结构体 NET_IN_RAID_GET_SUBDEVICE 和 NET_OUT_RAID_GET_SUBDEVICE
    NET_RAID_OPERATE_GET_SUBSMART,           // 获取RAID子设备SMART信息, 对应结构体 NET_IN_RAID_GET_SUBSMART 和 NET_OUT_RAID_GET_SUBSMART
} NET_RAID_OPERATE_TYPE;

// RAID信息
typedef struct tagNET_RAID_INFO 
{
    DWORD                dwSize;
    char                 szName[DH_COMMON_STRING_64];     // 名称, 为空时名称由设备返回
    char                 szLevel[DH_COMMON_STRING_16];    // 等级, 例如"RAID0", "RAID5"等
    int                  nMemberNum;                      // 成员数量
    char                 szMembers[DH_MAX_MEMBER_PER_RAID][DH_COMMON_STRING_64]; // 成员信息
} NET_RAID_INFO;

// 添加RAID的返回结果
typedef struct tagNET_RAID_ADD_RESULT 
{
    DWORD                dwSize;
    BOOL                 bResult;
    DWORD                dwErrorCode;                    // 失败错误码
    char                 szName[DH_COMMON_STRING_64];    // 名称
} NET_RAID_ADD_RESULT;

// 添加RAID输入参数
typedef struct tagNET_IN_RAID_ADD 
{
    DWORD                dwSize;
    int                    nRaidNun;                        // RAID数量
    NET_RAID_INFO        stuRaids[DH_MAX_RAID_NUM];         // RAID信息
} NET_IN_RAID_ADD;

// 添加RAID输出参数
typedef struct tagNET_OUT_RAID_ADD 
{
    DWORD                dwSize;
    int                  nResultNum;                        // 结果数
    NET_RAID_ADD_RESULT  stuResults[DH_MAX_RAID_NUM];       // RAID操作的结果
} NET_OUT_RAID_ADD;

// 删除RAID的返回结果
typedef struct tagNET_RAID_REMOVE_RESULT 
{
    DWORD                dwSize;
    BOOL                 bResult;
    DWORD                dwErrorCode;                       // 失败错误码
} NET_RAID_REMOVE_RESULT;

// 删除RAID输入参数
typedef struct tagNET_IN_RAID_REMOVE 
{
    DWORD                dwSize;
    int                  nRaidNum;                         // RAID数量
    char                 szRaids[DH_MAX_RAID_NUM][DH_COMMON_STRING_64];    // RAID名称数组
} NET_IN_RAID_REMOVE;

// 删除RAID输出参数
typedef struct tagNET_OUT_RAID_REMOVE
{
    DWORD                dwSize;
    int                  nResultNum;                       // 结果数
    NET_RAID_REMOVE_RESULT stuResults[DH_MAX_RAID_NUM];    // RAID操作的结果
} NET_OUT_RAID_REMOVE;

// 获取RAID子设备信息输入参数
typedef struct tagNET_IN_RAID_GET_SUBDEVICE 
{
    DWORD                dwSize;
    const char*          pszRaidName;                    // RAID名称
} NET_IN_RAID_GET_SUBDEVICE;

// 获取RAID子设备信息输出参数
typedef struct tagNET_OUT_RAID_GET_SUBDEVICE 
{
    DWORD                dwSize;
    int                  nSubDeviceNum;                  // 子设备数量
    DH_STORAGE_DEVICE    stuSubDevices[DH_MAX_MEMBER_PER_RAID]; // 子设备信息
} NET_OUT_RAID_GET_SUBDEVICE;

// RAID子设备SMART信息
typedef struct tagNET_RAID_SMART_INFO 
{
    DWORD                dwSize;
    unsigned int         nID;                            // 属性ID
    char                 szName[DH_COMMON_STRING_64];    // 属性名
    int                  nCurrent;                       // 属性值
    int                  nWorst;                         // 最大出错值
    int                  nThreshold;                     // 阈值
    int                  nPredict;                       // 状态
    char                 szRaw[DH_COMMON_STRING_16];     // 实际值
} NET_RAID_SMART_INFO;

// 获取RAID子设备SMART信息输入参数
typedef struct tagNET_IN_RAID_GET_SUBSMART
{
    DWORD                dwSize;
    const char*          pszSubDevName;                  // RAID子设备名称
} NET_IN_RAID_GET_SUBSMART;

// 获取RAID子设备SMART信息输出参数
typedef struct tagNET_OUT_RAID_GET_SUBSMART
{
    DWORD                dwSize;
    int                  nSmartNum;                          // SMART信息数
    NET_RAID_SMART_INFO  stuSmartInfos[MAX_SMART_VALUE_NUM]; // SMART信息
} NET_OUT_RAID_GET_SUBSMART;

//////////////////////////////// 外部设备 //////////////////////////////////////////

// 外接设备类型
typedef enum tagNET_EXT_DEV_TYPE
{
    EXT_DEV_UNKNOWN,                    // 未知
    EXT_DEV_PROJECTOR,                  // 投影仪
    EXT_DEV_SEQUENCE_POWER,            // 电源序列器
} NET_EXT_DEV_TYPE;

// 外接设备信息
typedef struct tagNET_EXTERNAL_DEVICE 
{
    DWORD               dwSize;
    NET_EXT_DEV_TYPE    emType;                             // 设备类型
    char                szDevID[DH_DEV_ID_LEN_EX];          // 设备ID, 唯一编号
    char                szDevName[DH_DEV_ID_LEN_EX];        // 设备名称
} NET_EXTERNAL_DEVICE;

// 电源时序器控制参数
typedef struct tagNET_CTRL_SEQPOWER_PARAM
{
    DWORD               dwSize;
    const char*         pszDeviceID;                        // 设备ID
    int                 nChannel;                           // 输出口或输出组序号
} NET_CTRL_SEQPOWER_PARAM;

// 投影仪控制参数
typedef struct tagNET_CTRL_PROJECTOR_PARAM 
{
    DWORD               dwSize;
    const char*         pszDeviceID;                        // 设备ID
} NET_CTRL_PROJECTOR_PARAM;

// 红外按键
typedef struct tagNET_CTRL_INFRARED_KEY_PARAM 
{
    DWORD               dwSize;
    int                 nChannel;                           // 红外控制通道号
    unsigned int        nKey;                               // 红外按键ID
} NET_CTRL_INFRARED_KEY_PARAM;

// 无硬盘报警
typedef struct tagALARM_NO_DISK_INFO
{
    DWORD               dwSize;
    NET_TIME            stuTime;                            // 时间
    DWORD               dwAction;                           // 事件动作, 0:Start, 1:Stop
}ALARM_NO_DISK_INFO;
//防护舱状态枚举
typedef enum __EM_CAPSULE_STATE
{
    CAPSULE_STATE_UNKNOW ,      //未定义
    CAPSULE_STATE_NORMAL ,      //正常
    CAPSULE_STATE_TIME_OUT ,    //超时
    CAPSULE_STATE_EMERGENCY_CALL,   //紧急呼叫
}EM_CAPSULE_STATE;

//防护舱事件
typedef struct tagALARM_PROTECTIVE_CAPSULE_INFO
{
    DWORD               dwSize;
    EM_CAPSULE_STATE    emCapsuleState; //防护舱状态
    DWORD               nLock;          //0:未锁，1:上锁; 仅在emCapsuleState为CAPSULE_STATE_NORMAL时有效
    DWORD               nInfrared;      //0:闲置(无人),1:触发(有人);仅在emCapsuleState为CAPSULE_STATE_NORMAL时有效
}ALARM_PROTECTIVE_CAPSULE_INFO;

// 设备能力类型, 对应CLIENT_GetDevCaps接口
#define NET_DEV_CAP_SEQPOWER            0x01                // 电源时序器能力, pInBuf=NET_IN_CAP_SEQPOWER*, pOutBuf=NET_OUT_CAP_SEQPOWER*
#define NET_ENCODE_CFG_CAPS             0x02                // 设备编码配置对应能力, pInBuf=NET_IN_ENCODE_CFG_CAPS*, pOutBuf= NET_OUT_ENCODE_CFG_CAPS*

// 获取电源时序器能力输入参数
typedef struct tagNET_IN_CAP_SEQPOWER 
{
    DWORD                dwSize;
    const char*          pszDeviceID;                       // 设备ID
} NET_IN_CAP_SEQPOWER;

// 获取电源时序器能力输出参数
typedef struct tagNET_OUT_CAP_SEQPOWER
{
    DWORD                dwSize;
    int                  nChannelNum;                       // 通道数
} NET_OUT_CAP_SEQPOWER;

// 获取设备编码配置对应能力输入参数
typedef struct tagNET_IN_ENCODE_CFG_CAPS
{
    DWORD               dwSize;           
    int                 nChannelId;                         // 通道号    
    int                 nStreamType;                        // 码流类型，0：主码流；1：辅码流1；2：辅码流2；3：辅码流3；4：抓图码流
    char*               pchEncodeJson;                      // Encode配置，通过调用dhconfigsdk.dll中接口CLIENT_PacketData封装得到
                                                            // 对应的封装命令为 CFG_CMD_ENCODE                 
}NET_IN_ENCODE_CFG_CAPS;

// 码流配置对应能力
typedef struct tagNET_STREAM_CFG_CAPS
{
    DWORD               dwSize;
    int                 nAudioCompressionTypes[DH_MAX_AUDIO_ENCODE_TYPE]; // 支持的音频编码类型，详见DH_TALK_CODING_TYPE
    int                 nAudioCompressionTypeNum;                   // 音频压缩格式个数
    int                 dwEncodeModeMask;                           // 视频编码模式掩码，详见"编码模式"
    DH_RESOLUTION_INFO  stuResolutionTypes[DH_MAX_CAPTURE_SIZE_NUM];// 支持的视频分辨率
    int                 nResolutionFPSMax[DH_MAX_CAPTURE_SIZE_NUM]; // 不同分辨率下帧率最大值，下标与nResolutionTypes对应 
    int                 nResolutionTypeNum;                         // 视频分辨率个数
    int                 nMaxBitRateOptions;                         // 最大视频码流(kbps) 
    int                 nMinBitRateOptions;                         // 最小视频码流(kbps)
    BYTE                bH264ProfileRank[DH_PROFILE_HIGH];          // 支持的H.264 Profile等级，参照枚举类型 EM_H264_PROFILE_RANK;  
    int                 nH264ProfileRankNum;                        // 支持的H.264 Profile等级个数
    int                 nCifPFrameMaxSize;                          // 当分辨率为cif时最大p帧(Kbps)
    int                 nCifPFrameMinSize;                          // 当分辨率为cif时最小p帧(Kbps)
    int                 nFPSMax;                                    // 视频帧率最大值，为0时，以nResolutionFPSMax为准
}NET_STREAM_CFG_CAPS;

// 获取设备编码配置对应能力输出参数
typedef struct tagNET_OUT_ENCODE_CFG_CAPS
{
    DWORD               dwSize;
    NET_STREAM_CFG_CAPS stuMainFormatCaps[DH_REC_TYPE_NUM];         // 主码流配置对应能力
    NET_STREAM_CFG_CAPS stuExtraFormatCaps[DH_N_ENCODE_AUX];        // 辅码流配置对应能力
    NET_STREAM_CFG_CAPS stuSnapFormatCaps[SNAP_TYP_NUM];            // 辅码流配置对应能力
}NET_OUT_ENCODE_CFG_CAPS;

// 跌落事件类型
typedef struct tagALARM_FALLING_INFO
{
    DWORD               dwStructSize;                               // 结构体大小
    BYTE                bEventAction;                               // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    BYTE                byRserved[3];                               // 对齐                                                                                                                                                                                                                                                                        
}ALARM_FALLING_INFO;

// 扩展模块报警通道信息
typedef struct tagNET_EXALARMCHANNELS_INFO
{
    DWORD               dwSize;
    int                 nExAlarmBoxNum;                             // 扩展报警盒通道号
    int                 nChannelNum;                                // 该通道在扩展报警盒上的通道号
    char                szChannelName[DH_MAX_EXALARMCHANNEL_NAME_LEN];// 报警通道名称
} NET_EXALARMCHANNELS_INFO;

// CLIENT_QueryDevState 接口输入参数
typedef struct tagNET_EXALARMCHANNELS
{
    DWORD                       dwSize;
    int                         nExAlarmInCount;                    // 扩展模块报警输入通道个数，需用户指定查询个数
    int                         nRetExAlarmInCount;                 // 扩展模块报警输入通道返回个数
    NET_EXALARMCHANNELS_INFO*   pstuExAlarmInInfo;                  // 扩展模块报警输入通道信息

    int                         nExAlarmOutCount;                   // 扩展模块报警输出通道个数，需用户指定查询个数
    int                         nRetExAlarmOutCount;                // 扩展模块报警输出通道返回个数
    NET_EXALARMCHANNELS_INFO*   pstuExAlarmOutInfo;                 // 扩展模块报警输出通道信息
} NET_EXALARMCHANNELS;

// 激活的防区信息
typedef struct tagNET_ACTIVATEDDEFENCEAREA_INFO
{
    DWORD                       dwSize;
    int                         nChannel;                           // 防区通道号
    NET_TIME                    stuActivationTime;                  // 防区激活时间 
}NET_ACTIVATEDDEFENCEAREA_INFO;
// CLIENT_QueryDevState 接口输入参数
typedef struct tagNET_ACTIVATEDEFENCEAREA
{
    DWORD                       dwSize;
    int                         nAlarmInCount;                      // 查询本地报警输入通道激活个数，需用户指定个数
    int                         nRetAlarmInCount;                   // 本地报警输入通道实际激活个数
    NET_ACTIVATEDDEFENCEAREA_INFO* pstuAlarmInDefenceAreaInfo;      // 本地报警输入通道信息

    int                         nExAlarmInCount;                    // 查询扩展模块报警输入通道个数，需用户指定个数
    int                         nRetExAlarmInCount;                 // 扩展模块报警输入通道实际激活个数
    NET_ACTIVATEDDEFENCEAREA_INFO* pstuExAlarmInDefenceAreaInfo;    // 扩展模块报警输入通道信息
}NET_ACTIVATEDDEFENCEAREA;

// 门禁状态类型
typedef enum tagEM_NET_DOOR_STATUS_TYPE
{
    EM_NET_DOOR_STATUS_UNKNOWN,
    EM_NET_DOOR_STATUS_OPEN,
    EM_NET_DOOR_STATUS_CLOSE,
}EM_NET_DOOR_STATUS_TYPE;

// 门禁状态信息(CLIENT_QueryDevState 接口输入参数)
typedef struct tagNET_DOOR_STATUS_INFO
{
    DWORD                       dwSize;
    int                         nChannel;               // 门禁通道号
    EM_NET_DOOR_STATUS_TYPE     emStateType;            // 门禁状态信息
}NET_DOOR_STATUS_INFO;

// CLIENT_QueryRecordCount接口输入参数
typedef struct _NET_IN_QUEYT_RECORD_COUNT_PARAM
{
    DWORD                       dwSize;                 // 结构体大小
    LLONG                       lFindeHandle;           // 查询句柄
}NET_IN_QUEYT_RECORD_COUNT_PARAM;

// CLIENT_QueryRecordCount接口输出参数
typedef struct _NET_OUT_QUEYT_RECORD_COUNT_PARAM
{
    DWORD                       dwSize;                 // 结构体大小
    int                         nRecordCount;           // 设备返回的记录条数
}NET_OUT_QUEYT_RECORD_COUNT_PARAM;

// 模拟量报警输入通道信息
typedef struct tagNET_ANALOGALARM_CHANNELS_INFO 
{
    DWORD               dwSize;
    int                 nSlot;                          // 根地址, 0表示本地通道, 1表示连接在第一个串口上的扩展通道, 2、3...以此类推
    int                 nLevel1;                        // 第一级级联地址, 表示连接在第nSlot串口上的第nLevel1个探测器, 从0开始
    int                 nLevel2;                        // 第二级级联地址, 表示连接在第nLevel1节点上的第nLevel2个探测器,从0开始,-1表示不存在该节点,
    char                szName[DH_COMMON_STRING_128];   // 通道名称
}NET_ANALOGALARM_CHANNELS_INFO;

// 模拟量报警输入通道映射关系(对应DH_DEVSTATE_ANALOGALARM_CHANNELS命令)
typedef struct tagNET_ANALOGALARM_CHANNELS 
{
    DWORD                          dwSize;
    int                            nMaxAnalogAlarmChannels; // 最大通道数
    int                            nRetAnalogAlarmChannels; // 返回的通道数
    NET_ANALOGALARM_CHANNELS_INFO* pstuChannelInfo;         // 通道信息，用户分配内存
}NET_ANALOGALARM_CHANNELS;

// 传感器数据信息
typedef struct tagNET_ANALOGALARM_SENSE_INFO 
{
    DWORD                   dwSize;
    int                     nChannelID;                     // 通道号(从0开始)
    NET_SENSE_METHOD        emSense;                        // 传感器类型
    float                   fData;                          // 传感器数值
    NET_TIME                stuTime;                        // 采集时间
    int                     nStatus;                        // 数据状态, -1:未知,0:正常,1:数据无效(超过量程),
                                                            // 2:超过阈值1,3:超过阈值2,4:超过阈值3,5:超过阈值4,
                                                            // 6:低于阈值1,7:低于阈值2,8:低于阈值3,9:低于阈值4
}NET_ANALOGALARM_SENSE_INFO;

//订阅模拟量报警通道数据回调函数原型
typedef void (CALLBACK *fAnalogAlarmDataCallBack)(LLONG lLoginID, LLONG lAttachHandle, NET_ANALOGALARM_SENSE_INFO* pInfo, int nBufLen, LDWORD dwUser);

// CLIENT_AttachAnalogAlarmData()接口输入参数
typedef struct tagNET_IN_ANALOGALARM_DATA 
{
    DWORD                       dwSize;
    int                         nChannelId;                 // 从0开始, -1表示全部通道
    fAnalogAlarmDataCallBack    cbCallBack;                 // 数据回调函数
    LDWORD                      dwUser;                     // 用户定义参数
}NET_IN_ANALOGALARM_DATA;

// CLIENT_AttachAnalogAlarmData()接口输出参数
typedef struct tagNET_OUT_ANALOGALARM_DATA 
{
    DWORD    dwSize;
}NET_OUT_ANALOGALARM_DATA;


// 查询设备支持的传感器设备类型 
// CLIENT_QueryDevState接口的 DH_DEVSTATE_GET_SENSORLIST  命令参数
#define MAX_SUPPORT_SENSORTYPE_NUM    128                   // 最大支持传感器设备类型个数

typedef struct tagNET_SENSOR_LIST 
{
    DWORD       dwSize;
    int         nSupportSensorNum;                          // 返回支持传感器设备类型个数
    char        szSensorList[MAX_SUPPORT_SENSORTYPE_NUM][DH_COMMON_STRING_64];
}NET_SENSOR_LIST;

// CLIENT_QueryDevLogCount获取日志条数输入参数
typedef struct tagNET_IN_GETCOUNT_LOG_PARAM
{
    DWORD                       dwSize;
    QUERY_DEVICE_LOG_PARAM      stuQueryCondition;          // 查询记录数条件
} NET_IN_GETCOUNT_LOG_PARAM;

// CLIENT_QueryDevLogCount获取日志条数输出参数
typedef struct tagNET_OUT_GETCOUNT_LOG_PARAM
{
    DWORD                       dwSize;
    int                         nLogCount;                  // 日志数(设备返回)
} NET_OUT_GETCOUNT_LOG_PARAM;


// SDK全局日志打印信息
typedef struct tagLogSetPrintInfo
{
    DWORD           dwSize;
    BOOL            bSetFilePath;                           // 是否重设日志路径
    char            szLogFilePath[MAX_LOG_PATH_LEN];        // 日志路径(默认"./sdk_log/sdk_log.log")
    BOOL            bSetFileSize;                           // 是否重设日志文件大小
    unsigned int    nFileSize;                              // 每个日志文件的大小(默认大小10240), 单位:比特
    BOOL            bSetFileNum;                            // 是否重设日志文件个数
    unsigned int    nFileNum;                               // 绕接日志文件个数(默认大小10)
    BOOL            bSetPrintStrategy;                      // 是否重设日志打印输出策略
    unsigned int    nPrintStrategy;                         // 日志输出策略, 0:输出到文件(默认); 1:输出到窗口
}LOG_SET_PRINT_INFO;


// 获取当前子系统启用状态(对应DH_DEVSTATE_GET_ALARM_SUBSYSTEM_ACTIVATESTATUS命令)
typedef struct tagNET_GET_ALARM_SUBSYSTEM_ACTIVATE_STATUES
{
	DWORD				dwSize;
	int					nChannelId;			// 子系统号
	BOOL				bActive;			// 子系统启用状态, TRUE 表示启用,FALSE表示不启用
}NET_GET_ALARM_SUBSYSTEM_ACTIVATE_STATUES;

// 报警子系统激活设置参数(对应DH_CTRL_ALARM_SUBSYSTEM_ACTIVE_SET命令)
typedef struct tagNET_CTRL_ALARM_SUBSYSTEM_SETACTIVE 
{
	DWORD				dwSize;
	int					nChannelId;			// 子系统号
	BOOL				bActive;			// 子系统启用状态,TRUE 表示启用,FALSE表示不启用
}NET_CTRL_ALARM_SUBSYSTEM_SETACTIVE;

// 禁止开闸参数(对应 DH_CTRL_FORBID_OPEN_STROBE)
typedef struct tagNET_CTRL_FORBID_OPEN_STROBE
{
    DWORD               dwSize;             
    int                 nChannelID;        // 通道号    
    int                 nTime;             // 禁止开闸的持续时间，单位:s，即在此操作之后的对应时间内不允许设备开闸 
}NET_CTRL_FORBID_OPEN_STROBE;

#define MAX_PLATENUMBER_LEN    64           // 最大车牌号码长度
// 开启道闸参数(对应DH_CTRL_OPEN_STROBE命令)
typedef struct tagNET_CTRL_OPEN_STROBE
{
	DWORD				dwSize;
	int				nChannelId;			                // 通道号
	char				szPlateNumber[MAX_PLATENUMBER_LEN];		// 车牌号码
}NET_CTRL_OPEN_STROBE;

// 回放拒绝接听参数(对应DH_CTRL_TALKING_REFUSE命令)
typedef struct tagNET_CTRL_TALKING_REFUSE 
{
    DWORD           dwSize;
    int             nChannelID;                 // 对讲通道号
}NET_CTRL_TALKING_REFUSE;

////////////////////////////////系统任务订阅//////////////////////////////////////////
// 分区状态
typedef struct __NET_PARTITION_STATE
{
    DWORD             dwSize;
    int               nStatus;                  // 分区状态，0-正常，1-错误 
    double            dbTotalSize;              // 分区总容量，字节为单位
    double            dbRemainSize;             // 剩余容量，字节为单位
    
}NET_PARTITION_STATE;

// 硬盘状态
typedef struct __NET_HDD_STATE
{
    DWORD             dwSize; 
    int               nState;                   // 硬盘状态，0-正常，1-错误   
    double            dbTotalSize;              // 硬盘总容量，字节为单位
    NET_PARTITION_STATE stuPartitions[DH_MAX_STORAGE_PARTITION_NUM]; // 分区状态
    int               nPartitionNum;              // 分区数
}NET_HDD_STATE;

// 通道状态
typedef struct __NET_CHANNLE_STATE
{
    DWORD             dwSize;
    BYTE              byRecState;               // 录像状态，1-录像，0-关闭
    BYTE              byVideoInState;           // 视频输入状态，1-有视频接入，0-无视频  
    BYTE              byReserved[2];            // 字节对齐
}NET_CHANNLE_STATE;

// 设备自检信息
typedef struct __NET_SELFCHECK_INFO
{
    DWORD             dwSize;
    int               nAlarmIn;                 // 报警输入通道数
    int               nAlarmOut;                // 报警输出通道数  
    NET_TIME          stuTime;                  // 上报时间
    char              szPlateNo[DH_MAX_PLATE_NUMBER_LEN]; // 车牌
    char              szICCID[DH_MAX_SIM_LEN];  // SIM卡号
    BYTE              byOrientation;            // 定位状态，0-未定位，1-定位 
    BYTE              byACCState;               // ACC 状态，0-关闭，1-打开
    BYTE              byConstantElecState;      // 常电状态，0-正常连接，1-断开，2-欠压，3-高压
    BYTE              byAntennaState;           // 通信信号状态，0-正常，1-未知故障，2-未接，3-短路
    
    // 外部设备状态
    BYTE              byReportStation;          // 报站器状态，0-未接，1-正常，2-异常
    BYTE              byControlScreen;          // 调度屏状态，0-未接，1-正常，2-异常
    BYTE              byPOS;                    // POS机状态，0-未接，1-正常，2-异常
    BYTE              byCoinBox;                // 投币箱状态，0-未接，1-正常，2-异常
    
    // 能力集
    BOOL              bTimerSnap;               // 定时抓图，TRUE-支持，FALSE-不支持
    BOOL              bElectronEnclosure;       // 电子围栏，TRUE-支持，FALSE-不支持
    BOOL              bTeleUpgrade;             // 远程升级，TRUE-支持，FALSE-不支持   
    
    NET_HDD_STATE     stuHddStates[DH_MAX_DISKNUM]; // 硬盘状态
    int               nHddNum;                  // 硬盘个数
    
    NET_CHANNLE_STATE* pChannleState;           // 通道状态，是一个数组， 内存由sdk内部申请，释放也由sdk内部释放
    int               nChannleNum;              // 通道个数
}NET_SELFCHECK_INFO;

typedef void (CALLBACK *fMissionInfoCallBack)(LLONG lAttachHandle, DWORD dwType, void* pMissionInfo, void* pReserved, LDWORD dwUserData);

typedef enum EM_MISSION_TYPE
{
    NET_MISSION_TYPE_UNKOWN,                    // 未知
        NET_MISSION_TYPE_SELFCHECK,                 // 设备自检，对应结构体 NET_SELFCHECK_INFO
}EM_MISSION_TYPE;

//CLIENT_AttachMission接口输入参数
typedef struct __NET_IN_ATTACH_MISSION_PARAM
{
    DWORD             dwSize;
    EM_MISSION_TYPE   emMissionType;            // 任务类型
    fMissionInfoCallBack cbMissionInfofunc;     // 任务信息回调函数
    LDWORD            dwUser;                   // 用户数据 
}NET_IN_ATTACH_MISSION_PARAM;

// CLIENT_DetachMission接口输出参数
typedef struct NET_OUT_ATTACH_MISSION_PARAM
{
    DWORD             dwSize;
    LLONG             lAttachHandle;           // 订阅句柄
}NET_OUT_ATTACH_MISSION_PARAM;

// CLIENT_StartQueryLog 输入参数
typedef struct tagNET_IN_START_QUERYLOG
{
    DWORD               dwSize;
} NET_IN_START_QUERYLOG;

// CLIENT_StartQueryLog 输出参数
typedef struct tagNET_OUT_START_QUERYLOG
{
    DWORD               dwSize;
}NET_OUT_START_QUERYLOG;

// 日志详细信息
typedef struct tagNET_LOG_MESSAGE
{
    DWORD               dwSize;
    char				szLogMessage[DH_COMMON_STRING_1024];    // 日志内容
} NET_LOG_MESSAGE;

// 日志信息
typedef struct tagNET_LOG_INFO
{
    DWORD               dwSize;
    NET_TIME            stuTime;                        // 时间 
    char                szUserName[DH_COMMON_STRING_32];// 操作者
    char                szLogType[DH_COMMON_STRING_128];// 类型
    NET_LOG_MESSAGE	    stuLogMsg;                      // 日志信息
} NET_LOG_INFO;

// CLIENT_QueryNextLog 输入参数
typedef struct tagNET_IN_QUERYNEXTLOG
{
    DWORD               dwSize;
    int                 nGetCount;      // 需要查询的日志条数
}NET_IN_QUERYNEXTLOG;

// CLIENT_QueryNextLog 输出参数
typedef struct tagNET_OUT_QUERYNEXTLOG
{
    DWORD               dwSize;
    int                 nMaxCount;      // 用户指定分配结构体个数，需大于等于NET_IN_GETNEXTLOG的nGetCount
    NET_LOG_INFO*       pstuLogInfo;    // 返回日志信息,缓存大小由用户指定,大小为nMaxCount*sizeof(NET_LOG_INFO)
    int                 nRetCount;      // 实际返回日志条数
}NET_OUT_QUERYNEXTLOG;

/***********************************************************************
 ** 回调函数定义
 ***********************************************************************/

// 网络连接断开回调函数原形
typedef void (CALLBACK *fDisConnect)(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);

// 网络连接恢复回调函数原形
typedef void (CALLBACK *fHaveReConnect)(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);

// 动态子连接断开回调函数原形
typedef void (CALLBACK *fSubDisConnect)(EM_INTERFACE_TYPE emInterfaceType, BOOL bOnline, LLONG lOperateHandle, LLONG lLoginID, LDWORD dwUser);

// 视频监视断开回调函数原形, 
typedef void (CALLBACK *fRealPlayDisConnect)(LLONG lOperateHandle, EM_REALPLAY_DISCONNECT_EVENT_TYPE dwEventType, void* param, LDWORD dwUser);

// 实时监视数据回调函数原形
typedef void (CALLBACK *fRealDataCallBack)(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser);

// 实时监视数据回调函数原形--扩展
typedef void (CALLBACK *fRealDataCallBackEx)(LLONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LONG param, LDWORD dwUser);

// 屏幕叠加回调函数原形
typedef void (CALLBACK *fDrawCallBack)(LLONG lLoginID, LLONG lPlayHandle, HDC hDC, LDWORD dwUser);

// 回放进度回调函数原形
typedef void (CALLBACK *fDownLoadPosCallBack)(LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, LDWORD dwUser);

// 按时间回放进度回调函数原形
typedef void (CALLBACK *fTimeDownLoadPosCallBack) (LLONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, int index, NET_RECORDFILE_INFO recordfileinfo, LDWORD dwUser);

// 消息回调函数原形
typedef BOOL (CALLBACK *fMessCallBack)(LONG lCommand, LLONG lLoginID, char *pBuf, DWORD dwBufLen, char *pchDVRIP, LONG nDVRPort, LDWORD dwUser);

// 侦听服务器回调函数原形
typedef int (CALLBACK *fServiceCallBack)(LLONG lHandle, char *pIp, WORD wPort, LONG lCommand, void *pParam, DWORD dwParamLen, LDWORD dwUserData);

// 语音对讲的音频数据回调函数原形
typedef void (CALLBACK *pfAudioDataCallBack)(LLONG lTalkHandle, char *pDataBuf, DWORD dwBufSize, BYTE byAudioFlag, LDWORD dwUser);

// 升级设备程序回调函数原形
typedef void (CALLBACK *fUpgradeCallBack) (LLONG lLoginID, LLONG lUpgradechannel, int nTotalSize, int nSendSize, LDWORD dwUser);

// 透明串口回调函数原形
typedef void (CALLBACK *fTransComCallBack) (LLONG lLoginID, LLONG lTransComChannel, char *pBuffer, DWORD dwBufSize, LDWORD dwUser);

// 查询设备日志数据回调函数原形
typedef void (CALLBACK *fLogDataCallBack)(LLONG lLoginID, char *pBuffer, DWORD dwBufSize, DWORD nTotalSize, BOOL bEnd, LDWORD dwUser);

// 抓图回调函数原形
typedef void (CALLBACK *fSnapRev)(LLONG lLoginID, BYTE *pBuf, UINT RevLen, UINT EncodeType, DWORD CmdSerial, LDWORD dwUser);

// GPS信息订阅回调
typedef void (CALLBACK *fGPSRev)(LLONG lLoginID, GPS_Info GpsInfo, LDWORD dwUserData);

// GPS信息订阅回调--扩展
typedef void (CALLBACK *fGPSRevEx)(LLONG lLoginID, GPS_Info GpsInfo, ALARM_STATE_INFO stAlarmInfo, LDWORD dwUserData, void *reserved);

// GPS温湿度信息订阅回调
typedef void (CALLBACK *fGPSTempHumidityRev)(LLONG lLoginID, GPS_TEMP_HUMIDITY_INFO GpsTHInfo, LDWORD dwUserData);

// 异步数据回调
typedef void (CALLBACK *fMessDataCallBack)(LLONG lCommand, LPNET_CALLBACK_DATA lpData, LDWORD dwUser);

// 文件传输回调
typedef void (CALLBACK *fTransFileCallBack)(LLONG lHandle, int nTransType, int nState, int nSendSize, int nTotalSize, LDWORD dwUser);

// 智能分析数据回调;nSequence表示上传的相同图片情况，为0时表示是第一次出现，为2表示最后一次出现或仅出现一次，为1表示此次之后还有
// int nState = (int*) reserved 表示当前回调数据的状态, 为0表示当前数据为实时数据，为1表示当前回调数据是离线数据，为2时表示离线数据传送结束
typedef int  (CALLBACK *fAnalyzerDataCallBack)(LLONG lAnalyzerHandle, DWORD dwAlarmType, void* pAlarmInfo, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser, int nSequence, void *reserved);

// 异步搜索设备回调
typedef void (CALLBACK *fSearchDevicesCB)(DEVICE_NET_INFO_EX *pDevNetInfo, void* pUserData);

// 异步注册设备回调函数原形
typedef void (CALLBACK *fHaveLogin)(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort, BOOL bOnline, NET_DEVICEINFO_Ex stuDeviceInfo, int nError, LDWORD dwUser, void *reserved);

// 回放YUV数据回调函数
typedef void (CALLBACK *fYUVDataCallBack)(LLONG lPlaybackHandle, BYTE *pBuffer, DWORD dwBufSize, LONG param, LDWORD dwUser, void *reserved);

/************************************************************************
 ** 接口定义
 ***********************************************************************/

// SDK初始化
CLIENT_API BOOL CALL_METHOD CLIENT_Init(fDisConnect cbDisConnect, LDWORD dwUser);

// SDK退出清理
CLIENT_API void CALL_METHOD CLIENT_Cleanup();

//------------------------------------------------------------------------

// 设置断线重连成功回调函数，设置后SDK内部断线自动重连
CLIENT_API void CALL_METHOD CLIENT_SetAutoReconnect(fHaveReConnect cbAutoConnect, LDWORD dwUser);

// 设置动态子连接断线回调函数，目前SVR设备的监视和回放是短连接的。
CLIENT_API void CALL_METHOD CLIENT_SetSubconnCallBack(fSubDisConnect cbSubDisConnect, LDWORD dwUser);

// 返回函数执行失败代码
CLIENT_API DWORD CALL_METHOD CLIENT_GetLastError(void);

// 设置连接设备超时时间和尝试次数
CLIENT_API void CALL_METHOD CLIENT_SetConnectTime(int nWaitTime, int nTryTimes);

// 设置登陆网络环境
CLIENT_API void CALL_METHOD CLIENT_SetNetworkParam(NET_PARAM *pNetParam);

// 获取SDK的版本信息
CLIENT_API DWORD CALL_METHOD CLIENT_GetSDKVersion();

//------------------------------------------------------------------------

// 向设备注册
CLIENT_API LLONG CALL_METHOD CLIENT_Login(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, LPNET_DEVICEINFO lpDeviceInfo, int *error = 0);

// 扩展接口；nSpecCap = 0为TCP方式下的登入，nSpecCap = 2为主动注册的登入，nSpecCap = 3为组播方式下的登入，
//             nSpecCap = 4为UDP方式下的登入，nSpecCap = 6为只建主连接下的登入，nSpecCap = 7为SSL加密
//             nSpecCap = 8为成都佳发登陆
//             nSpecCap = 9为登录远程设备，这个时候void* pCapParam填入远程设备的名字的字符串
//           nSpecCap = 12为LDAP方式登录
//           nSpecCap = 13为AD方式登录
//           nSpecCap = 14为Radius登录方式 
//             nSpecCap = 15为Socks5登陆方式，这个时候void* pCapParam填入Socks5服务器的IP&&port&&ServerName&&ServerPassword字符串
//             nSpecCap = 16为代理登陆方式，这个时候void* pCapParam填入SOCKET值
//             nSpecCap = 19为web私网穿透登陆方式
//             nSpecCap = 20为手机客户端登入
CLIENT_API LLONG CALL_METHOD CLIENT_LoginEx(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, int nSpecCap, void* pCapParam, LPNET_DEVICEINFO lpDeviceInfo, int *error = 0);

// 异步向设备注册 
// nSpecCap = 0为TCP方式下的登入,nSpecCap = 6为只建主连接下的登入
// nSpecCap = 19为私网穿透登录
CLIENT_API LLONG CALL_METHOD CLIENT_StartLogin(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, int nSpecCap, void* pCapParam, fHaveLogin cbLogin, LDWORD dwUser);

// 停止向设备注册
CLIENT_API BOOL CALL_METHOD CLIENT_StopLogin(LLONG lLoginID);

// 向设备注销
CLIENT_API BOOL CALL_METHOD CLIENT_Logout(LLONG lLoginID);


//------------------------------------------------------------------------

// 开始实时监视
CLIENT_API LLONG CALL_METHOD CLIENT_RealPlay(LLONG lLoginID, int nChannelID, HWND hWnd);

// 开始实时监视--扩展
// 多画面预览时nChannelID NVR设备填视频输出通道号
CLIENT_API LLONG CALL_METHOD CLIENT_RealPlayEx(LLONG lLoginID, int nChannelID, HWND hWnd, DH_RealPlayType rType = DH_RType_Realplay);

//打开实时监视，若返回0表示打开失败
CLIENT_API LLONG CALL_METHOD CLIENT_StartRealPlay(LLONG lLoginID, int nChannelID, HWND hWnd, DH_RealPlayType rType, fRealDataCallBackEx cbRealData, fRealPlayDisConnect cbDisconnect, LDWORD dwUser, DWORD dwWaitTime = 10000);

// 多画面实时预览
CLIENT_API LLONG CALL_METHOD CLIENT_MultiPlay(LLONG lLoginID, HWND hWnd);

// 停止多画面实时预览
CLIENT_API BOOL CALL_METHOD CLIENT_StopMultiPlay(LLONG lMultiHandle);

// 抓图；hPlayHandle为监视或回放句柄
CLIENT_API BOOL CALL_METHOD CLIENT_CapturePicture(LLONG hPlayHandle, const char *pchPicFileName);
CLIENT_API BOOL CALL_METHOD CLIENT_CapturePictureEx(LLONG hPlayHandle, const char *pchPicFileName, NET_CAPTURE_FORMATS eFormat);

// 设置实时监视数据回调
CLIENT_API BOOL CALL_METHOD CLIENT_SetRealDataCallBack(LLONG lRealHandle, fRealDataCallBack cbRealData, LDWORD dwUser);

// 设置实时监视数据回调--扩展
CLIENT_API BOOL CALL_METHOD CLIENT_SetRealDataCallBackEx(LLONG lRealHandle, fRealDataCallBackEx cbRealData, LDWORD dwUser, DWORD dwFlag);

// 设置图象流畅性
CLIENT_API BOOL    CALL_METHOD CLIENT_AdjustFluency(LLONG lRealHandle, int nLevel);

// 保存数据为文件
CLIENT_API BOOL CALL_METHOD CLIENT_SaveRealData(LLONG lRealHandle, const char *pchFileName);

// 结束保存数据为文件
CLIENT_API BOOL CALL_METHOD CLIENT_StopSaveRealData(LLONG lRealHandle);

// 设置图像属性
CLIENT_API BOOL CALL_METHOD CLIENT_ClientSetVideoEffect(LLONG lPlayHandle, unsigned char nBrightness, unsigned char nContrast, unsigned char nHue, unsigned char nSaturation);

// 获取图像属性
CLIENT_API BOOL CALL_METHOD CLIENT_ClientGetVideoEffect(LLONG lPlayHandle, unsigned char *nBrightness, unsigned char *nContrast, unsigned char *nHue, unsigned char *nSaturation);

// 设置屏幕叠加回调
CLIENT_API void CALL_METHOD CLIENT_RigisterDrawFun(fDrawCallBack cbDraw, LDWORD dwUser);

// 打开声音
CLIENT_API BOOL CALL_METHOD CLIENT_OpenSound(LLONG hPlayHandle);

// 设置音量；lPlayHandle为监视或回放句柄
CLIENT_API BOOL CALL_METHOD CLIENT_SetVolume(LLONG lPlayHandle, int nVolume);

// 是否启用高清图像内部调整策略，默认启用。该策略启用时，在快放4倍速以上时，只播放I帧，不启用时，则每帧都播放
CLIENT_API BOOL CALL_METHOD CLIENT_PlayEnableLargePicAdjustment(LLONG lPlayHandle, BOOL bEnable);

// 关闭声音
CLIENT_API BOOL CALL_METHOD CLIENT_CloseSound();

// 停止实时预览
CLIENT_API BOOL CALL_METHOD CLIENT_StopRealPlay(LLONG lRealHandle);

// 停止实时预览--扩展
CLIENT_API BOOL CALL_METHOD CLIENT_StopRealPlayEx(LLONG lRealHandle);

//------------------------------------------------------------------------

// 通用云台控制
CLIENT_API BOOL CALL_METHOD CLIENT_PTZControl(LLONG lLoginID, int nChannelID, DWORD dwPTZCommand, DWORD dwStep, BOOL dwStop);

// 私有云台控制
CLIENT_API BOOL CALL_METHOD CLIENT_DHPTZControl(LLONG lLoginID, int nChannelID, DWORD dwPTZCommand, unsigned char param1, unsigned char param2, unsigned char param3, BOOL dwStop,void* param4=NULL);

// 私有云台控制扩展接口，支持三维快速定位
CLIENT_API BOOL CALL_METHOD CLIENT_DHPTZControlEx(LLONG lLoginID, int nChannelID, DWORD dwPTZCommand, LONG lParam1, LONG lParam2, LONG lParam3, BOOL dwStop);

//------------------------------------------------------------------------
// 查询某月的各天是否存在录像文件
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRecordStatus(LLONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmMonth, char* pchCardid, LPNET_RECORD_STATUS pRecordStatus, int waittime=1000);
// 查询时间段内是否有录像文件
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRecordTime(LLONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmStart, LPNET_TIME tmEnd, char* pchCardid, BOOL *bResult, int waittime=1000);
// 查询时间段内的所有录像文件
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRecordFile(LLONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmStart, LPNET_TIME tmEnd, char* pchCardid, LPNET_RECORDFILE_INFO nriFileinfo, int maxlen, int *filecount, int waittime=1000, BOOL bTime = FALSE);

// 异步查询时间段内的所有录像文件
CLIENT_API BOOL CALL_METHOD CLIENT_StartQueryRecordFile(LLONG lLoginID, NET_IN_START_QUERY_RECORDFILE *pInParam, NET_OUT_START_QUERY_RECORDFILE *pOutParam);

// 快速查询时间段内的录像文件，如果时间段内录像超过16条时，只返回时间最早的16段录像。
CLIENT_API BOOL CALL_METHOD CLIENT_QuickQueryRecordFile(LLONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmStart, LPNET_TIME tmEnd, char* pchCardid, LPNET_RECORDFILE_INFO nriFileinfo, int maxlen, int *filecount, int waittime=1000, BOOL bTime = FALSE);

// 查询最早录像时间
CLIENT_API BOOL CALL_METHOD CLIENT_QueryFurthestRecordTime(LLONG lLoginID, int nRecordFileType, char *pchCardid, NET_FURTHEST_RECORD_TIME* pFurthrestTime, int nWaitTime);

// 开始查找录像文件
CLIENT_API LLONG    CALL_METHOD CLIENT_FindFile(LLONG lLoginID, int nChannelId, int nRecordFileType, char* cardid, LPNET_TIME time_start, LPNET_TIME time_end, BOOL bTime, int waittime);

// 查找录像文件
CLIENT_API int    CALL_METHOD CLIENT_FindNextFile(LLONG lFindHandle,LPNET_RECORDFILE_INFO lpFindData);

// 结束录像文件查找
CLIENT_API BOOL CALL_METHOD CLIENT_FindClose(LLONG lFindHandle);

// 按文件方式回放
CLIENT_API LLONG CALL_METHOD CLIENT_PlayBackByRecordFile(LLONG lLoginID, LPNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwUserData);

// 按文件方式回放--扩展
CLIENT_API LLONG CALL_METHOD CLIENT_PlayBackByRecordFileEx(LLONG lLoginID, LPNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser, fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser);

// 按文件方式回放--回调回放中断事件
CLIENT_API LLONG CALL_METHOD CLIENT_StartPlayBackByRecordFile(LLONG lLoginID,  LPNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, 
                                                             fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser, 
                                                             fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser, 
                                                             fRealPlayDisConnect fDisConnectCallBack, LDWORD dwDisUser, DWORD dwWaitTime = 10000);

//按文件方式回放--抽帧播放(带宽不够时可以使用)
CLIENT_API LLONG CALL_METHOD CLIENT_FramCotrolPlayBackByRecordFile(LLONG lLoginID, LPNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, 
                                                                   fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser, 
                                                                   fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser, unsigned int nCutFrameRate);

// 按时间方式回放
CLIENT_API LLONG CALL_METHOD CLIENT_PlayBackByTime(LLONG lLoginID, int nChannelID, LPNET_TIME lpStartTime, LPNET_TIME lpStopTime, HWND hWnd, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser);

// 按时间方式回放--扩展
CLIENT_API LLONG CALL_METHOD CLIENT_PlayBackByTimeEx(LLONG lLoginID, int nChannelID, LPNET_TIME lpStartTime, LPNET_TIME lpStopTime, HWND hWnd, 
                                                     fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser, 
                                                     fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser);

// 按时间方式回放--回调回放中断事件
CLIENT_API LLONG CALL_METHOD CLIENT_StartPlayBackByTime(LLONG lLoginID, int nChannelID, 
                                                       LPNET_TIME lpStartTime, LPNET_TIME lpStopTime, HWND hWnd, 
                                                       fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser,
                                                       fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser, 
                                                       fRealPlayDisConnect fDisConnectCallBack, LDWORD dwDisUser, DWORD dwWaitTime = 10000);

//按时间方式回放--抽帧播放(带宽不够时可以使用)
CLIENT_API LLONG CALL_METHOD CLIENT_FramCotrolPlayBackByTime(LLONG lLoginID, int nChannelID, LPNET_TIME lpStartTime, LPNET_TIME lpStopTime, HWND hWnd, 
                                                             fDownLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser, 
                                                             fDataCallBack fDownLoadDataCallBack, LDWORD dwDataUser, unsigned int nCutFrameRate);

//视频浓缩文件回放
CLIENT_API LLONG CALL_METHOD CLIENT_PlayBackBySynopsisFile(LLONG lLoginID, 
                                                            LPNET_SYNOPSISFILE_INFO lpRecordFile, 
                                                            HWND hWnd, 
                                                            fDownLoadPosCallBack cbDownLoadPos,
                                                            LDWORD dwPosUser, 
                                                            fDataCallBack fDownLoadDataCallBack,
                                                            LDWORD dwDataUser,
                                                            LDWORD dwUser);
                                                            
// 多通道预览回放
CLIENT_API LLONG CALL_METHOD CLIENT_MultiPlayBack(LLONG lLoginID, NET_MULTI_PLAYBACK_PARAM *pParam);

// 定位录像回放起始点
CLIENT_API BOOL CALL_METHOD CLIENT_SeekPlayBack(LLONG lPlayHandle, unsigned int offsettime, unsigned int offsetbyte);

// 暂停或恢复录像回放
CLIENT_API BOOL CALL_METHOD CLIENT_PausePlayBack(LLONG lPlayHandle, BOOL bPause);

// 快进录像回放
CLIENT_API BOOL CALL_METHOD CLIENT_FastPlayBack(LLONG lPlayHandle);

// 慢进录像回放
CLIENT_API BOOL CALL_METHOD CLIENT_SlowPlayBack(LLONG lPlayHandle);

// 步进录像回放
CLIENT_API BOOL CALL_METHOD CLIENT_StepPlayBack(LLONG lPlayHandle, BOOL bStop);

// 控制播放方向--正放或者倒放
CLIENT_API BOOL CALL_METHOD CLIENT_PlayBackControlDirection(LLONG lPlayHandle, BOOL bBackward);

// 设置回放帧速
CLIENT_API BOOL CALL_METHOD CLIENT_SetFramePlayBack(LLONG lPlayHandle, int framerate);

// 获取回放帧速
CLIENT_API BOOL CALL_METHOD CLIENT_GetFramePlayBack(LLONG lPlayHandle, int *fileframerate, int *playframerate);

// 恢复正常回放速度
CLIENT_API BOOL CALL_METHOD CLIENT_NormalPlayBack(LLONG lPlayHandle);

// 智能检索回放
CLIENT_API BOOL CALL_METHOD CLIENT_SmartSearchPlayBack(LLONG lPlayHandle, LPIntelligentSearchPlay lpPlayBackParam);

// 获取回放OSD时间
CLIENT_API BOOL CALL_METHOD CLIENT_GetPlayBackOsdTime(LLONG lPlayHandle, LPNET_TIME lpOsdTime, LPNET_TIME lpStartTime, LPNET_TIME lpEndTime);

// 停止录像回放
CLIENT_API BOOL CALL_METHOD CLIENT_StopPlayBack(LLONG lPlayHandle);

// 下载录像文件
CLIENT_API LLONG CALL_METHOD CLIENT_DownloadByRecordFile(LLONG lLoginID,LPNET_RECORDFILE_INFO lpRecordFile, char *sSavedFileName, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwUserData);

// 通过时间下载录像
CLIENT_API LLONG CALL_METHOD CLIENT_DownloadByTime(LLONG lLoginID, int nChannelId, int nRecordFileType, LPNET_TIME tmStart, LPNET_TIME tmEnd, char *sSavedFileName, fTimeDownLoadPosCallBack cbTimeDownLoadPos, LDWORD dwUserData);

// 查询录像下载进度
CLIENT_API BOOL CALL_METHOD CLIENT_GetDownloadPos(LLONG lFileHandle, int *nTotalSize, int *nDownLoadSize);

// 停止录像下载
CLIENT_API BOOL CALL_METHOD CLIENT_StopDownload(LLONG lFileHandle);

//局部放大
CLIENT_API BOOL CALL_METHOD CLIENT_SetDisplayRegion(LLONG lPlayHandle,DWORD nRegionNum, DH_DISPLAYRREGION *pSrcRect, HWND hDestWnd, BOOL bEnable);

// 开始查找录像文件帧信息
CLIENT_API BOOL    CALL_METHOD CLIENT_FindFrameInfo(LLONG lLoginID, NET_IN_FIND_FRAMEINFO_PRAM *pInParam, NET_OUT_FIND_FRAMEINFO_PRAM* pOutParam, int nWaitTime);

// 查找录像文件帧信息，按指定信息条数查询
CLIENT_API BOOL    CALL_METHOD CLIENT_FindNextFrameInfo(LLONG lFindHandle, NET_IN_FINDNEXT_FRAMEINFO_PRAM *pInParam, NET_OUT_FINDNEXT_FRAMEINFO_PRAM* pOutParam, int nWaitTime);

// 结束录像文件查找
CLIENT_API BOOL CALL_METHOD CLIENT_FindFrameInfoClose(LLONG lFindHandle);

//------------------------------------------------------------------------

// 设置报警回调函数
CLIENT_API void CALL_METHOD CLIENT_SetDVRMessCallBack(fMessCallBack cbMessage,LDWORD dwUser);

// 向设备订阅报警
CLIENT_API BOOL CALL_METHOD CLIENT_StartListen(LLONG lLoginID);

// 向设备订阅报警--扩展
CLIENT_API BOOL CALL_METHOD CLIENT_StartListenEx(LLONG lLoginID);

// 停止订阅报警
CLIENT_API BOOL CALL_METHOD CLIENT_StopListen(LLONG lLoginID);

// 报警复位
CLIENT_API BOOL CALL_METHOD CLIENT_AlarmReset(LLONG lLoginID, DWORD dwAlarmType, int nChannel, void* pReserved = NULL, int nWaitTime = 1000);

//------------------------------------------------------------------------
 
// 主动注册功能，启动服务；nTimeout参数已无效
CLIENT_API LLONG CALL_METHOD CLIENT_ListenServer(char* ip, WORD port, int nTimeout, fServiceCallBack cbListen, LDWORD dwUserData);

// 停止服务
CLIENT_API BOOL CALL_METHOD CLIENT_StopListenServer(LLONG lServerHandle);

// 响应设备的注册请求
CLIENT_API BOOL CALL_METHOD CLIENT_ResponseDevReg(char *devSerial, char* ip, WORD port, BOOL bAccept);

//------------------------------------------------------------------------

// 报警上传功能，启动服务；dwTimeOut参数已无效
CLIENT_API LLONG CALL_METHOD CLIENT_StartService(WORD wPort, char *pIp = NULL, fServiceCallBack pfscb = NULL, DWORD dwTimeOut = 0xffffffff, LDWORD dwUserData = 0);

// 停止服务
CLIENT_API BOOL CALL_METHOD CLIENT_StopService(LLONG lHandle);

//------------------------------------------------------------------------

// 设置语音对讲模式，客户端方式还是服务器方式
CLIENT_API BOOL CALL_METHOD CLIENT_SetDeviceMode(LLONG lLoginID, EM_USEDEV_MODE emType, void* pValue);

// 打开语音对讲
CLIENT_API LLONG CALL_METHOD CLIENT_StartTalkEx(LLONG lLoginID, pfAudioDataCallBack pfcb, LDWORD dwUser);

// 开始PC端录音
CLIENT_API BOOL CALL_METHOD CLIENT_RecordStart();

// 结束PC端录音
CLIENT_API BOOL CALL_METHOD CLIENT_RecordStop();


// 开始PC端录音(对CLIENT_RecordStart()扩展)
CLIENT_API BOOL CALL_METHOD CLIENT_RecordStartEx(LLONG lLoginID);

// 结束PC端录音(对CLIENT_RecordStop()扩展)
CLIENT_API BOOL CALL_METHOD CLIENT_RecordStopEx(LLONG lLoginID);


// 发送语音数据到设备
CLIENT_API LONG  CALL_METHOD CLIENT_TalkSendData(LLONG lTalkHandle, char *pSendBuf, DWORD dwBufSize);

// 解码音频数据
CLIENT_API void CALL_METHOD CLIENT_AudioDec(char *pAudioDataBuf, DWORD dwBufSize);
CLIENT_API BOOL CALL_METHOD CLIENT_AudioDecEx(LLONG lTalkHandle, char *pAudioDataBuf, DWORD dwBufSize);

// 设置语音对讲的音量
CLIENT_API BOOL CALL_METHOD CLIENT_SetAudioClientVolume(LLONG lTalkHandle, WORD wVolume);

// 停止语音对讲
CLIENT_API BOOL CALL_METHOD CLIENT_StopTalkEx(LLONG lTalkHandle);

// 添加设备到广播组
CLIENT_API BOOL CALL_METHOD CLIENT_AudioBroadcastAddDev(LLONG lLoginID);

// 从广播组中删除设备
CLIENT_API BOOL CALL_METHOD CLIENT_AudioBroadcastDelDev(LLONG lLoginID);

// 音频编码--初始化(特定标准格式->私有格式)
CLIENT_API int  CALL_METHOD CLIENT_InitAudioEncode(DH_AUDIO_FORMAT aft);

// 音频编码--数据编码
CLIENT_API int    CALL_METHOD    CLIENT_AudioEncode(LLONG lTalkHandle, BYTE *lpInBuf, DWORD *lpInLen, BYTE *lpOutBuf, DWORD *lpOutLen);

// 音频编码--完成退出
CLIENT_API int    CALL_METHOD    CLIENT_ReleaseAudioEncode();

//------------------------------------------------------------------------

// 查询设备日志
CLIENT_API BOOL CALL_METHOD CLIENT_QueryLog(LLONG lLoginID, char *pLogBuffer, int maxlen, int *nLogBufferlen, int waittime=3000);

// 查询设备日志，以分页方式查询
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDeviceLog(LLONG lLoginID, QUERY_DEVICE_LOG_PARAM *pQueryParam, char *pLogBuffer, int nLogBufferLen, int *pRecLogNum, int waittime=3000);

// 查询设备日志条数
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDevLogCount(LLONG lLoginID, NET_IN_GETCOUNT_LOG_PARAM *pInParam, NET_OUT_GETCOUNT_LOG_PARAM* pOutParam , int waittime=3000);

// 查道通道录像状态
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRecordState(LLONG lLoginID, char *pRSBuffer, int maxlen, int *nRSBufferlen, int waittime=1000);

// 查道辅码流通道录像状态（返回字节数与通道数对应, 每个字节表示对应通道的辅码流录像控制状态，0-关闭,1-手动,2-自动）
CLIENT_API BOOL CALL_METHOD CLIENT_QueryExtraRecordState(LLONG lLoginID, char *pRSBuffer, int maxlen, int *nRSBufferlen, void *pReserved, int waittime=1000);

// 查询设备状态
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDevState(LLONG lLoginID, int nType, char *pBuf, int nBufLen, int *pRetLen, int waittime=1000);

// 查询远程设备状态,nType为DH_DEVSTATE_ALARM_FRONTDISCONNECT时，通道号从1开始
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRemotDevState(LLONG lLoginID, int nType, int nChannelID, char *pBuf, int nBufLen, int *pRetLen, int waittime=1000);

// 查询系统能力信息
CLIENT_API BOOL CALL_METHOD CLIENT_QuerySystemInfo(LLONG lLoginID, int nSystemType, char *pSysInfoBuffer, int maxlen, int *nSysInfolen, int waittime=1000);

// 新系统能力查询接口，查询系统能力信息(以Json格式，具体见配置SDK)
CLIENT_API BOOL CALL_METHOD CLIENT_QueryNewSystemInfo(LLONG lLoginID, char* szCommand, int nChannelID, char* szOutBuffer, DWORD dwOutBufferSize, int *error, int waittime=1000);

// 获取通道码流
CLIENT_API LONG  CALL_METHOD CLIENT_GetStatiscFlux(LLONG lLoginID, LLONG  lPlayHandle);

// 获取云台信息
CLIENT_API BOOL  CALL_METHOD CLIENT_GetPtzOptAttr(LLONG lLoginID,DWORD dwProtocolIndex,LPVOID lpOutBuffer,DWORD dwBufLen,DWORD *lpBytesReturned,int waittime=500);

// 获取设备能力
CLIENT_API BOOL  CALL_METHOD CLIENT_GetDevCaps(LLONG lLoginID, int nType, void* pInBuf, void* pOutBuf, int nWaitTime);

//------------------------------------------------------------------------

// 重启设备
CLIENT_API BOOL CALL_METHOD CLIENT_RebootDev(LLONG lLoginID);

// 关闭设备
CLIENT_API BOOL CALL_METHOD CLIENT_ShutDownDev(LLONG lLoginID);

// 设备控制
CLIENT_API BOOL CALL_METHOD CLIENT_ControlDevice(LLONG lLoginID, CtrlType type, void *param, int waittime = 1000);

// 设置通道录像状态
CLIENT_API BOOL CALL_METHOD CLIENT_SetupRecordState(LLONG lLoginID, char *pRSBuffer, int nRSBufferlen);

// 设置通道辅码流录像状态
CLIENT_API BOOL CALL_METHOD CLIENT_SetupExtraRecordState(LLONG lLoginID, char *pRSBuffer, int nRSBufferlen, void* pReserved);

// 查询IO状态
CLIENT_API BOOL CALL_METHOD CLIENT_QueryIOControlState(LLONG lLoginID, DH_IOTYPE emType, 
                                           void *pState, int maxlen, int *nIOCount, int waittime=1000);

// IO控制
CLIENT_API BOOL CALL_METHOD CLIENT_IOControl(LLONG lLoginID, DH_IOTYPE emType, void *pState, int maxlen);

// 强制I帧；nChannelID：通道号，nSubChannel：码流类型(0：主，1：子码流1)
CLIENT_API BOOL CALL_METHOD CLIENT_MakeKeyFrame(LLONG lLoginID, int nChannelID, int nSubChannel=0);

// 公网代理注册
typedef void (CALLBACK *fConnectMessCallBack)(LLONG lConnectHandle, NET_CLOUDSERVICE_CONNECT_RESULT* pConnectResult, void* pReserved, LDWORD dwUser);

CLIENT_API LLONG CALL_METHOD CLIENT_ConnectCloudService(LLONG lLoginID, NET_CLOUDSERVICE_CONNECT_PARAM* pConnectParm, fConnectMessCallBack pConnectMessCB, LDWORD dwUser, void* pReserved);
//------------------------------------------------------------------------

// 查询用户信息
CLIENT_API BOOL CALL_METHOD CLIENT_QueryUserInfo(LLONG lLoginID, USER_MANAGE_INFO *info, int waittime=1000);

// 查询用户信息--扩展
CLIENT_API BOOL CALL_METHOD CLIENT_QueryUserInfoEx(LLONG lLoginID, USER_MANAGE_INFO_EX *info, int waittime=1000);

// 查询用户信息--最大支持64通道设备
CLIENT_API BOOL CALL_METHOD CLIENT_QueryUserInfoNew(LLONG lLoginID, USER_MANAGE_INFO_NEW *info, void* pReserved, int waittime = 1000);

// 操作设备用户
CLIENT_API BOOL CALL_METHOD CLIENT_OperateUserInfo(LLONG lLoginID, int nOperateType, void *opParam, void *subParam, int waittime=1000);

// 操作设备用户--扩展
CLIENT_API BOOL CALL_METHOD CLIENT_OperateUserInfoEx(LLONG lLoginID, int nOperateType, void *opParam, void *subParam, int waittime=1000);

// 操作设备用户--最大支持64通道设备
CLIENT_API BOOL CALL_METHOD CLIENT_OperateUserInfoNew(LLONG lLoginID, int nOperateType, void *opParam, void *subParam, void* pReserved, int waittime = 1000);

//------------------------------------------------------------------------

// 创建透明串口通道,TransComType高2个字节表示串口序号，低2个字节表示串口类型，目前类型支持0：串口，1:485
CLIENT_API LLONG CALL_METHOD CLIENT_CreateTransComChannel(LLONG lLoginID, int TransComType, unsigned int baudrate, unsigned int databits, unsigned int stopbits, unsigned int parity, fTransComCallBack cbTransCom, LDWORD dwUser);

// 透明串口发送数据
CLIENT_API BOOL CALL_METHOD CLIENT_SendTransComData(LLONG lTransComChannel, char *pBuffer, DWORD dwBufSize);

// 释放通明串口通道
CLIENT_API BOOL CALL_METHOD CLIENT_DestroyTransComChannel(LLONG lTransComChannel);

// 查询透明串口状态
CLIENT_API BOOL   CALL_METHOD CLIENT_QueryTransComParams(LLONG lLoginID, int TransComType, DH_COMM_STATE* pCommState, int nWaitTime = 500);

//------------------------------------------------------------------------

// 开始升级设备程序
CLIENT_API LLONG CALL_METHOD CLIENT_StartUpgrade(LLONG lLoginID, char *pchFileName, fUpgradeCallBack cbUpgrade, LDWORD dwUser);

// 开始升级设备程序--扩展
CLIENT_API LLONG CALL_METHOD CLIENT_StartUpgradeEx(LLONG lLoginID, EM_UPGRADE_TYPE emType, char *pchFileName, fUpgradeCallBack cbUpgrade, LDWORD dwUser);

// 发送数据
CLIENT_API BOOL CALL_METHOD CLIENT_SendUpgrade(LLONG lUpgradeID);

// 结束升级设备程序
CLIENT_API BOOL CALL_METHOD CLIENT_StopUpgrade(LLONG lUpgradeID);

//------------------------------------------------------------------------

// 查询配置信息
CLIENT_API BOOL  CALL_METHOD CLIENT_GetDevConfig(LLONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned,int waittime=500);

// 设置配置信息
CLIENT_API BOOL  CALL_METHOD CLIENT_SetDevConfig(LLONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize, int waittime=500);

// 新配置接口，查询配置信息(以Json格式，具体见配置SDK)
CLIENT_API BOOL CALL_METHOD CLIENT_GetNewDevConfig(LLONG lLoginID, char* szCommand, int nChannelID, char* szOutBuffer, DWORD dwOutBufferSize, int *error, int waittime=500);

// 新配置接口，设置配置信息(以Json格式，具体见配置SDK)
CLIENT_API BOOL CALL_METHOD CLIENT_SetNewDevConfig(LLONG lLoginID, char* szCommand, int nChannelID, char* szInBuffer, DWORD dwInBufferSize, int *error, int *restart, int waittime=500);

// 删除配置接口(Json格式)
CLIENT_API BOOL CALL_METHOD CLIENT_DeleteDevConfig(LLONG lLoginID, NET_IN_DELETECFG* pInParam, NET_OUT_DELETECFG* pOutParam, int waittime=500);

// 获取配置成员名称接口(Json格式)
CLIENT_API BOOL CALL_METHOD CLIENT_GetMemberNames(LLONG lLoginID, NET_IN_MEMBERNAME* pInParam, NET_OUT_MEMBERNAME* pOutParam, int waittime=500);

// 获取网卡信息
CLIENT_API BOOL CALL_METHOD CLIENT_QueryNetStat(LLONG lLoginID , EM_NET_QUERY_TYPE emType , void *lpInParam , int nInParamLen , void *lpOutParam , int nOutParamLen , int *pError = NULL , int nWaitTime=1000);

//------------------------------------------------------------------------

// 查询设备通道名称
CLIENT_API BOOL CALL_METHOD CLIENT_QueryChannelName(LLONG lLoginID, char *pChannelName, int maxlen, int *nChannelCount, int waittime=1000);

// 设置设备通道名称
CLIENT_API BOOL  CALL_METHOD CLIENT_SetupChannelName(LLONG lLoginID,char *pbuf, int nbuflen);

// 设置设备通道字符叠加
CLIENT_API BOOL  CALL_METHOD CLIENT_SetupChannelOsdString(LLONG lLoginID, int nChannelNo, DH_CHANNEL_OSDSTRING* struOsdString, int nbuflen);

// 查询设备当前时间
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDeviceTime(LLONG lLoginID, LPNET_TIME pDeviceTime, int waittime=1000);

// 设置设备当前时间
CLIENT_API BOOL CALL_METHOD CLIENT_SetupDeviceTime(LLONG lLoginID, LPNET_TIME pDeviceTime);

// 设置设备限制码流
CLIENT_API BOOL CALL_METHOD CLIENT_SetMaxFlux(LLONG lLoginID, WORD wFlux);

//------------------------------------------------------------------------

// 导入配置文件
CLIENT_API LLONG CALL_METHOD CLIENT_ImportConfigFile(LLONG lLoginID, char *szFileName, fDownLoadPosCallBack cbUploadPos, LDWORD dwUserData, DWORD param=0);

// 停止导入配置文件
CLIENT_API BOOL CALL_METHOD CLIENT_StopImportCfgFile(LLONG lImportHandle);

// 导出配置文件
CLIENT_API LLONG CALL_METHOD CLIENT_ExportConfigFile(LLONG lLoginID, DH_CONFIG_FILE_TYPE emConfigFileType, char *szSavedFilePath, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwUserData);

// 停止导出配置文件
CLIENT_API BOOL CALL_METHOD CLIENT_StopExportCfgFile(LLONG lExportHandle);

//------------------------------------------------------------------------

// 通过设备名字或者设备序列号向DDNS服务器查询设备IP
CLIENT_API BOOL CALL_METHOD CLIENT_GetDVRIPByResolveSvr(char *pchDVRIP, WORD wDVRPort, BYTE *sDVRName, WORD wDVRNameLen, BYTE *sDVRSerialNumber, WORD wDVRSerialLen, char* sGetIP);

// 搜索局域网内IPC、NVS等设备
CLIENT_API BOOL CALL_METHOD CLIENT_SearchDevices(char* szBuf, int nBufLen, int* pRetLen, DWORD dwSearchTime, char* szLocalIp=NULL);

// 异步搜索局域网内IPC、NVS等设备
CLIENT_API LLONG CALL_METHOD CLIENT_StartSearchDevices(fSearchDevicesCB cbSearchDevices, void* pUserData, char* szLocalIp=NULL);

// 停止异步搜索局域网内IPC、NVS等设备
CLIENT_API BOOL CALL_METHOD CLIENT_StopSearchDevices(LLONG lSearchHandle);

// 修改设备IP
CLIENT_API BOOL CALL_METHOD CLIENT_ModifyDevice(DEVICE_NET_INFO_EX *pDevNetInfo, DWORD dwWaitTime, int *iError = NULL, char* szLocalIp = NULL, void *reserved = NULL);

// 跨网段搜索设备IP
CLIENT_API BOOL CALL_METHOD CLIENT_SearchDevicesByIPs(DEVICE_IP_SEARCH_INFO* pIpSearchInfo, fSearchDevicesCB cbSearchDevices, LDWORD dwUserData, char* szLocalIp, DWORD dwWaitTime);
//------------------------------------------------------------------------

// 平台接入接口
CLIENT_API BOOL CALL_METHOD CLIENT_GetPlatFormInfo(LLONG lLoginID, DWORD dwCommand, int nSubCommand, int nParam, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned,int waittime=500);
CLIENT_API BOOL CALL_METHOD CLIENT_SetPlatFormInfo(LLONG lLoginID, DWORD dwCommand, int nSubCommand, int nParam, LPVOID lpInBuffer, DWORD dwInBufferSize, int waittime=500);

// 镜头聚焦控制
//    dwFocusCommand = 0为聚焦调节
//    dwFocusCommand = 1为连续聚焦调节
//    dwFocusCommand = 2为自动聚焦调节，调节焦点至最佳位置。nFocus和nZoom无效。
CLIENT_API BOOL CALL_METHOD CLIENT_FocusControl(LLONG lLoginID, int nChannelID, DWORD dwFocusCommand, double nFocus, double nZoom, void *reserved = NULL, int waittime=500);

///////////////////////////////车载设备接口///////////////////////////////

// 设置抓图回调函数
CLIENT_API void CALL_METHOD CLIENT_SetSnapRevCallBack(fSnapRev OnSnapRevMessage, LDWORD dwUser);

// 抓图请求
CLIENT_API BOOL CALL_METHOD CLIENT_SnapPicture(LLONG lLoginID, SNAP_PARAMS par);

// 抓图请求扩展接口
CLIENT_API BOOL CALL_METHOD CLIENT_SnapPictureEx(LLONG lLoginID, SNAP_PARAMS *par, int *reserved = 0);

// 设置GPS订阅回调函数
CLIENT_API void CALL_METHOD CLIENT_SetSubcribeGPSCallBack(fGPSRev OnGPSMessage, LDWORD dwUser);

// 设置GPS订阅回调函数--扩展
CLIENT_API void CALL_METHOD CLIENT_SetSubcribeGPSCallBackEX(fGPSRevEx OnGPSMessage, LDWORD dwUser);

// GPS信息订阅
CLIENT_API BOOL CALL_METHOD CLIENT_SubcribeGPS (LLONG lLoginID, BOOL bStart, LONG KeepTime, LONG InterTime);

// 设置GPS温湿度订阅回调函数
CLIENT_API void CALL_METHOD CLIENT_SetSubcribeGPSTHCallBack(fGPSTempHumidityRev OnGPSMessage, LDWORD dwUser);

// GPS温湿度信息订阅
CLIENT_API BOOL CALL_METHOD CLIENT_SubcribeGPSTempHumidity (LLONG lLoginID, BOOL bStart,    int InterTime, void* Reserved);

//GPS日志信息查询
CLIENT_API BOOL CALL_METHOD CLIENT_QueryGPSLog(LLONG lLoginID,QUERY_GPS_LOG_PARAM *pQueryParam, char *pLogBuffer, int nLogBufferLen, int *pRecLogNum, BOOL *bContinue, int waittime);

// 订阅任务
CLIENT_API BOOL CALL_METHOD CLIENT_AttachMission(LLONG lLoginID, NET_IN_ATTACH_MISSION_PARAM *pInParam, NET_OUT_ATTACH_MISSION_PARAM *pOutParam, int nWaitTime);

// 取消任务订阅
CLIENT_API BOOL CALL_METHOD CLIENT_DetachMission(LLONG lAttachHandle);


//////////////////////////////解码器设备接口//////////////////////////////

// 查询解码器信息
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDecoderInfo(LLONG lLoginID, LPDEV_DECODER_INFO lpDecInfo, int waittime=1000);

// 查询解码器当前TV信息
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDecoderTVInfo(LLONG lLoginID, int nMonitorID, LPDEV_DECODER_TV lpMonitorInfo, int waittime=1000);

// 查询解码通道信息
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDecEncoderInfo(LLONG lLoginID, int nDecoderID, LPDEV_ENCODER_INFO lpEncoderInfo, int waittime=1000);

// 设置解码器TV输出使能
CLIENT_API BOOL CALL_METHOD CLIENT_SetDecTVOutEnable(LLONG lLoginID, BYTE *pDecTVOutEnable, int nBufLen, int waittime=1000);

// 设置解码器显示叠加信息使能，通道号从0开始
CLIENT_API BOOL CALL_METHOD CLIENT_SetDecLayOutEnable(LLONG lLoginID, BYTE bDecLayOutEnable, int nChannel, int waittime=1000);
// 获取解码器显示叠加信息使能，通道号从0开始
CLIENT_API BOOL CALL_METHOD CLIENT_GetDecLayOutEnable(LLONG lLoginID, BYTE *pDecLayOutEnable, int nChannel, int waittime=1000);
//------------------------------------------------------------------------

// 设置异步回调函数
CLIENT_API BOOL CALL_METHOD CLIENT_SetOperateCallBack(LLONG lLoginID, fMessDataCallBack cbMessData, LDWORD dwUser);

// 控制解码器TV画面分割，接口为异步方式 nSplitType=-1时，pEncoderChannel为结构体DH_CTRL_DECTV_SCREEN指针
CLIENT_API LLONG CALL_METHOD CLIENT_CtrlDecTVScreen(LLONG lLoginID, int nMonitorID, BOOL bEnable, int nSplitType, BYTE *pEncoderChannel, int nBufLen, void* userdata=NULL);

// 解码器TV画面切换，接口为异步方式
//   
CLIENT_API LLONG CALL_METHOD CLIENT_SwitchDecTVEncoder(LLONG lLoginID, int nDecoderID, LPDEV_ENCODER_INFO lpEncoderInfo, void* userdata=NULL);

//------------------------------------------------------------------------

// 增加画面组合
CLIENT_API int CALL_METHOD CLIENT_AddTourCombin(LLONG lLoginID, int nMonitorID, int nSplitType, BYTE *pEncoderChannnel, int nBufLen, int waittime=1000);

// 删除画面组合
CLIENT_API BOOL CALL_METHOD CLIENT_DelTourCombin(LLONG lLoginID, int nMonitorID, int nCombinID, int waittime=1000);

// 修改画面组合
CLIENT_API BOOL CALL_METHOD CLIENT_SetTourCombin(LLONG lLoginID, int nMonitorID, int nCombinID, int nSplitType, BYTE *pEncoderChannel, int nBufLen, int waittime=1000);

// 查询画面组合，nCombinID范围0～32
CLIENT_API BOOL CALL_METHOD CLIENT_QueryTourCombin(LLONG lLoginID, int nMonitorID, int nCombinID, LPDEC_COMBIN_INFO lpDecCombinInfo, int waittime=1000);

// 设置轮巡操作
CLIENT_API BOOL CALL_METHOD CLIENT_SetDecoderTour(LLONG lLoginID, int nMonitorID, LPDEC_TOUR_COMBIN lpDecTourInfo, int waittime=1000);

// 查询轮巡操作
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDecoderTour(LLONG lLoginID, int nMonitorID, LPDEC_TOUR_COMBIN lpDecTourInfo, int waittime=1000);

// 查询当前解码通道流信息
CLIENT_API BOOL CALL_METHOD CLIENT_QueryDecChannelFlux(LLONG lLoginID, int nDecoderID, LPDEV_DECCHANNEL_STATE lpChannelStateInfo, int waittime=1000);

// 解码器控制轮巡
CLIENT_API BOOL CALL_METHOD CLIENT_CtrlDecoderTour(LLONG lLoginID, int nMonitorID, DEC_CTRL_TOUR_TYPE emActionParam, int waittime = 1000);
//------------------------------------------------------------------------

typedef void (CALLBACK *fDecPlayBackPosCallBack)(LLONG lLoginID, int nEncoderID, DWORD dwTotalSize, DWORD dwPlaySize, LDWORD dwUser);

// 设置回放进度回调函数
CLIENT_API BOOL CALL_METHOD CLIENT_SetDecPlaybackPos(LLONG lLoginID, fDecPlayBackPosCallBack cbPlaybackPos, LDWORD dwUser);

// 解码器TV画面回放，接口为异步方式
CLIENT_API LLONG CALL_METHOD CLIENT_DecTVPlayback(LLONG lLoginID, int nDecoderID, DEC_PLAYBACK_MODE emPlaybackMode, LPVOID lpInBuffer, DWORD dwInBufferSize, void* userdata=NULL);

// 解码器TV画面回放控制
CLIENT_API BOOL CALL_METHOD CLIENT_CtrlDecPlayback(LLONG lLoginID, int nDecoderID, DEC_CTRL_PLAYBACK_TYPE emCtrlType, int nValue, int waittime=1000);

///////////////////////////////智能设备接口///////////////////////////////

// 实时上传智能分析数据－图片
CLIENT_API LLONG CALL_METHOD CLIENT_RealLoadPicture(LLONG lLoginID, int nChannelID, DWORD dwAlarmType, fAnalyzerDataCallBack cbAnalyzerData, LDWORD dwUser);

// 实时上传智能分析数据－图片(扩展接口，bNeedPicFile表示是否订阅图片文件,Reserved类型为RESERVED_PARA) 
CLIENT_API LLONG CALL_METHOD CLIENT_RealLoadPictureEx(LLONG lLoginID, int nChannelID, 
                                                     DWORD dwAlarmType, 
                                                     BOOL bNeedPicFile, 
                                                     fAnalyzerDataCallBack cbAnalyzerData, 
                                                     LDWORD dwUser, 
                                                     void* Reserved);

// 停止上传智能分析数据－图片
CLIENT_API BOOL CALL_METHOD CLIENT_StopLoadPic(LLONG lAnalyzerHandle);

// 按查询条件查询文件
CLIENT_API LLONG    CALL_METHOD CLIENT_FindFileEx(LLONG lLoginID, EM_FILE_QUERY_TYPE emType, void* pQueryCondition, void *reserved, int waittime=1000);    

// 查找文件:nFilecount:需要查询的条数, 返回值为媒体文件条数 返回值<nFilecount则相应时间段内的文件查询完毕
CLIENT_API int    CALL_METHOD CLIENT_FindNextFileEx(LLONG lFindHandle, int nFilecount, void* pMediaFileInfo, int maxlen, void *reserved, int waittime=1000);

// 结束录像文件查找
CLIENT_API BOOL CALL_METHOD CLIENT_FindCloseEx(LLONG lFindHandle);

// 获取符合查询条件的文件总数
CLIENT_API BOOL CALL_METHOD CLIENT_GetTotalFileCount(LLONG lFindHandle, int* pTotalCount, void *reserved, int waittime=1000);

// 设置查询跳转条件
CLIENT_API BOOL CALL_METHOD CLIENT_SetFindingJumpOption(LLONG lFindHandle, NET_FINDING_JUMP_OPTION_INFO* pOption, void *reserved, int waittime=1000);

// 下载指定的智能分析数据 - 图片
CLIENT_API LLONG CALL_METHOD CLIENT_DownloadMediaFile(LLONG lLoginID,EM_FILE_QUERY_TYPE emType, void* lpMediaFileInfo, char *sSavedFileName, fDownLoadPosCallBack cbDownLoadPos, LDWORD dwUserData,  void *reserved);

// 停止下载数据
CLIENT_API BOOL CALL_METHOD CLIENT_StopDownloadMediaFile(LLONG lFileHandle);

// 批量下载文件
CLIENT_API BOOL CALL_METHOD CLIENT_DownLoadMultiFile(LLONG lLoginID, NET_IN_DOWNLOAD_MULTI_FILE *pstInParam, NET_OUT_DOWNLOAD_MULTI_FILE *pstOutParam, int waittime=1000);

// 停止下载
CLIENT_API BOOL CALL_METHOD CLIENT_StopLoadMultiFile(LLONG lDownLoadHandle);

// 下载离线智能分析数据－图片
CLIENT_API LLONG CALL_METHOD CLIENT_LoadOffLineFile(LLONG lLoginID, int nChannelID, DWORD dwAlarmType, LPNET_TIME_EX lpStartTime, LPNET_TIME_EX lpEndTime, fAnalyzerDataCallBack cbAnalyzerData, LDWORD dwUser);

//暂停智能分析数据下载(bPause=TRUE 表示暂停下载, bPause=FALSE 表示恢复下载)
CLIENT_API BOOL CALL_METHOD CLIENT_PauseLoadPic(LLONG lLoadHadle, BOOL bPause);

// 交通抓拍--网络触发方式
CLIENT_API BOOL CALL_METHOD CLIENT_TrafficSnapByNetwork(LLONG lLoginID, int nChannelID, NET_IN_SNAPSHOT* pstInParam, NET_OUT_SNAPSHOT* pstOutParam);

// 交通控制--强制红灯
CLIENT_API BOOL CALL_METHOD CLIENT_TrafficForceLightState(LLONG lLoginID, int nChannelID, NET_IN_FORCELIGHTSTATE* pstInParam, NET_OUT_FORCELIGHTSTATE* pstOutParam, int waittime=1000);

//  黑白名单操作
CLIENT_API BOOL CALL_METHOD CLIENT_OperateTrafficList(LLONG lLoginID ,  NET_IN_OPERATE_TRAFFIC_LIST_RECORD* pstInParam , NET_OUT_OPERATE_TRAFFIC_LIST_RECORD *pstOutParam = NULL ,  int waittime = 1000);

// 交通流量统计
CLIENT_API LLONG CALL_METHOD CLIENT_StartTrafficFluxStat(LLONG lLoginID, NET_IN_TRAFFICFLUXSTAT* pstInParam,NET_OUT_TRAFFICFLUXSTAT* pstOutParam);

// 结束流量统计
CLIENT_API BOOL CALL_METHOD CLIENT_StopTrafficFluxStat(LLONG lFluxStatHandle);

// 获取流量统计信息
CLIENT_API LLONG CALL_METHOD CLIENT_StartFindFluxStat(LLONG lLoginID, NET_IN_TRAFFICSTARTFINDSTAT* pstInParam, NET_OUT_TRAFFICSTARTFINDSTAT* pstOutParam);

// 继续查询流量统计
CLIENT_API int    CALL_METHOD CLIENT_DoFindFluxStat(LLONG lFindHandle, NET_IN_TRAFFICDOFINDSTAT* pstInParam,NET_OUT_TRAFFICDOFINDSTAT* pstOutParam);

// 结束查询流量统计
CLIENT_API BOOL CALL_METHOD CLIENT_StopFindFluxStat(LLONG lFindHandle);

// 获取人数统计信息
CLIENT_API LLONG CALL_METHOD CLIENT_StartFindNumberStat(LLONG lLoginID, NET_IN_FINDNUMBERSTAT* pstInParam, NET_OUT_FINDNUMBERSTAT* pstOutParam);

// 继续查询人数统计
CLIENT_API int    CALL_METHOD CLIENT_DoFindNumberStat(LLONG lFindHandle, NET_IN_DOFINDNUMBERSTAT* pstInParam, NET_OUT_DOFINDNUMBERSTAT* pstOutParam);

// 结束查询人数统计
CLIENT_API BOOL CALL_METHOD CLIENT_StopFindNumberStat(LLONG lFindHandle);
// 视频分析设备的方法调用
CLIENT_API BOOL CALL_METHOD CLIENT_OperateVideoAnalyseDevice(LLONG lLoginID, int nChannelID, char* szCmd, void *pstInParam, void *pstOutParam, int waittime=1000);

// 串口设备的方法调用
CLIENT_API BOOL CALL_METHOD CLIENT_OperateCommDevice(LLONG lLoginID, int nChannelID, char* szCmd, void *pstInParam, void *pstOutParam, int waittime=1000);

// 智能跟踪球控制接口
CLIENT_API BOOL CALL_METHOD CLIENT_ControlIntelliTracker(LLONG lLoginID, NET_IN_CONTROL_INTELLITRACKER* pstInParam, NET_OUT_CONTROL_INTELLITRACKER* pstOutParam);

// 主从式设备的方法调用,具体参数参见上面定义CLIENT_OperateMasterSlaveDevice接口参数定义
CLIENT_API BOOL CALL_METHOD CLIENT_OperateMasterSlaveDevice(LLONG lLoginID, int nChannelID, char* szCmd, void *pstInParam, void *pstOutParam, int waittime=1000);

////  视频诊断

// 实时获取视频诊断结果
CLIENT_API BOOL CALL_METHOD CLIENT_StartVideoDiagnosis(LLONG lLoginID, NET_IN_VIDEODIAGNOSIS *pstInParam, NET_OUT_VIDEODIAGNOSIS *pstOutParam);

// 停止视频诊断结果上报
CLIENT_API BOOL CALL_METHOD CLIENT_StopVideoDiagnosis(LLONG hDiagnosisHandle);

// 开始视频诊断结果查询
CLIENT_API BOOL CALL_METHOD CLIENT_StartFindDiagnosisResult(LLONG lLoginID, NET_IN_FIND_DIAGNOSIS* pstInParam, NET_OUT_FIND_DIAGNOSIS* pstOutParam);

// 获取视频诊断结果信息
CLIENT_API BOOL CALL_METHOD CLIENT_DoFindDiagnosisResult(LLONG hFindHandle,NET_IN_DIAGNOSIS_INFO* pstInParam, NET_OUT_DIAGNOSIS_INFO* pstOutParam);

// 结束视频诊断结果查询
CLIENT_API BOOL CALL_METHOD CLIENT_StopFindDiagnosis(LLONG hFindHandle);

// 启动实时诊断计划
CLIENT_API BOOL CALL_METHOD CLIENT_StartRealTimeProject(LLONG lLoginID,NET_IN_START_RT_PROJECT_INFO* pstInParam, NET_OUT_START_RT_PROJECT_INFO* pstOutParam, int nWaitTime);

// 停止实时诊断计划
CLIENT_API BOOL CALL_METHOD CLIENT_StopRealTimeProject(LLONG lLoginID,NET_IN_STOP_RT_PROJECT_INFO* pstInParam, NET_OUT_STOP_RT_PROJECT_INFO* pstOutParam, int nWaitTime);

// 获取智能交通车位状态
CLIENT_API BOOL CALL_METHOD CLIENT_GetParkingSpaceStatus(LLONG lLoginID, NET_IN_GET_PARKINGSPACE_STATUS* pstInParam, NET_OUT_GET_PARKINGSPACE_STATUS* pstOutParam);

// 订阅指定的车位图片信息
CLIENT_API LLONG CALL_METHOD CLIENT_AttachParkingSpaceData(LLONG lLoginID, NET_IN_ATTACH_PARKINGSPACE* pstInParam, NET_OUT_ATTACH_PARKINGSPACE* pstOutParam);

// 取消订阅指定的车位图片信息
CLIENT_API BOOL CALL_METHOD CLIENT_DetachParkingSpaceData(NET_IN_DETACH_PARKINGSPACE* pstInParam, NET_OUT_DETACH_PARKINGSPACE* pstOutParam);

// 获取车位灯状态
CLIENT_API BOOL CALL_METHOD CLIENT_GetCarPortLightStatus(LLONG lLoginID, NET_IN_GET_CARPORTLIGHT_STATUS* pstInParam, NET_OUT_GET_CARPORTLIGHT_STATUS* pstOutParam, int waittime=1000);

// 设置车位灯状态
CLIENT_API BOOL CALL_METHOD CLIENT_SetCarPortLightStatus(LLONG lLoginID, NET_IN_SET_CARPORTLIGHT_STATUS* pstInParam, NET_OUT_SET_CARPORTLIGHT_STATUS* pstOutParam, int waittime=1000);

// 订阅智能分析进度（适用于视频分析源为录像文件时）
CLIENT_API BOOL CALL_METHOD CLIENT_AttachVideoAnalyseState(LLONG lLoginID, NET_IN_ATTACH_VIDEOANALYSE_STATE* pstInParam, NET_OUT_ATTACH_VIDEOANALYSE_STATE* pstOutParam, int nWaittime=1000);

// 停止订阅
CLIENT_API BOOL CALL_METHOD CLIENT_DetachVideoAnalyseState(LLONG lAttachHandle);

////////////////////////////////视频浓缩接口////////////////////////////////

// 添加视频浓缩任务
CLIENT_API BOOL CALL_METHOD CLIENT_AddVideoSynopsisTask(LLONG lLoginID,    NET_IN_ADD_VIDEOSYNOPSIS* pstInParam, NET_OUT_ADD_VIDEOSYNOPSIS* pstOutParam);

// 暂停视频浓缩任务
CLIENT_API BOOL CALL_METHOD CLIENT_PauseVideoSynopsisTask(LLONG lLoginID, NET_IN_PAUSE_VIDEOSYNOPSIS* pstInParam);

// 移除视频浓缩任务
CLIENT_API BOOL CALL_METHOD CLIENT_RemoveVideoSynopsisTask(LLONG lLoginID, NET_IN_REMOVE_VIDEOSYNOPSIS* pstInParam);

// 订阅实时浓缩视频物体信息
CLIENT_API BOOL CALL_METHOD CLIENT_RealLoadObjectData(LLONG lLoginID, NET_IN_REALLOAD_OBJECTDATA* pstInParam, NET_OUT_REALLOAD_OBJECTDATA* pstOutParam);

// 停止订阅实时浓缩视频物体信息
CLIENT_API BOOL CALL_METHOD CLIENT_StopLoadObjectData(LLONG lRealLoadHandle, NET_IN_STOPLOAD_OBJECTDATA* pstInParam);

// 订阅实时浓缩视频进度信息
CLIENT_API BOOL CALL_METHOD CLIENT_RealLoadSynopsisState(LLONG lLoginID, NET_IN_REALLAOD_SYNOPSISSTATE* pstInParam, NET_OUT_REALLOAD_SYNOPSISSTATE* pstOutParam);

// 停止订阅实时浓缩视频进度信息
CLIENT_API BOOL CALL_METHOD CLIENT_StopLoadSynopsisState(LLONG lRealLoadHandle, NET_IN_STOPLOAD_SYNOPSISSTATE* pstInParam);

// 查询浓缩视频任务相关信息接口
CLIENT_API BOOL CALL_METHOD CLIENT_QueryVideoSynopsisInfo(LLONG lLoginID, NET_IN_QUERY_VIDEOSYNOPSIS* pstInParam, NET_OUT_QUERY_VIDEOSYNOPSIS* pstuOutParam);

// 按查询条件查询视频浓缩文件
CLIENT_API BOOL    CALL_METHOD CLIENT_FindSynopsisFile(LLONG lLoginID, NET_IN_FIND_SYNOPSISFILE *pstInParam, NET_OUT_FIND_SYNOPSISFILE *pstOutParam);    

// 查找视频浓缩文件
CLIENT_API BOOL    CALL_METHOD CLIENT_FindNextSynopsisFile(LLONG lFindHandle, NET_IN_FINDNEXT_SYNOPSISFILE *pstInParam, NET_OUT_FINDNEXT_SYNOPSISFILE *pstOutParam);

// 结束视频浓缩文件查找
CLIENT_API BOOL CALL_METHOD CLIENT_SynopsisFindClose(LLONG lFindHandle);

// 下载视频浓缩相关文件
CLIENT_API BOOL CALL_METHOD CLIENT_DownLoadSynosisFile(LLONG lLoginID, NET_IN_DOWNLOAD_SYNOPSISFILE *pstInParam, NET_OUT_DOWNLOAD_SYNOPSISFILE *pstOutParam);

// 停止下载
CLIENT_API BOOL CALL_METHOD CLIENT_StopLoadSynosisFile(LLONG lDownLoadHandle);

// 请求浓缩视频服务器根据文件(夹)路径，生成文件信息
CLIENT_API BOOL    CALL_METHOD    CLIENT_SetFilePathInfo(LLONG lLoginID, NET_IN_SET_FILEPATHINFO* pstInParam);

// 监听添加文件信息状态
CLIENT_API LLONG CALL_METHOD CLIENT_AttachAddFileState(LLONG lLoginID, const NET_IN_ADDFILE_STATE* pstInParam, NET_OUT_ADDFILE_STATE *pstOutParam, int nWaitTime = 1000);

// 取消监听添加文件信息状, lAttachHandle是CLIENT_AttacAddFileState返回值
CLIENT_API LLONG CALL_METHOD CLIENT_DetachAddFileState(LLONG lAttachHandle);

/////////////////////////////////人脸识别接口/////////////////////////////////////////
// 人脸识别数据库信息操作（包括添加和删除）
CLIENT_API BOOL CALL_METHOD CLIENT_OperateFaceRecognitionDB(LLONG lLoginID, const NET_IN_OPERATE_FACERECONGNITIONDB* pstInParam, NET_OUT_OPERATE_FACERECONGNITIONDB *pstOutParam, int nWaitTime = 1000);

// 按条件查询人脸识别结果 
CLIENT_API BOOL CALL_METHOD CLIENT_StartFindFaceRecognition(LLONG lLoginID, const NET_IN_STARTFIND_FACERECONGNITION* pstInParam, NET_OUT_STARTFIND_FACERECONGNITION *pstOutParam, int nWaitTime = 1000);

// 查找人脸识别结果:nFilecount:需要查询的条数, 返回值为媒体文件条数 返回值<nFilecount则相应时间段内的文件查询完毕(每次最多只能查询20条记录)
CLIENT_API BOOL CALL_METHOD CLIENT_DoFindFaceRecognition(const NET_IN_DOFIND_FACERECONGNITION* pstInParam, NET_OUT_DOFIND_FACERECONGNITION *pstOutParam, int nWaitTime = 1000);

// 结束查询
CLIENT_API BOOL CALL_METHOD CLIENT_StopFindFaceRecognition(LLONG lFindHandle);

// 人脸检测(输入一张大图，输入大图中被检测出来的人脸图片)
CLIENT_API BOOL CALL_METHOD CLIENT_DetectFace(LLONG lLoginID, const NET_IN_DETECT_FACE* pstInParam, NET_OUT_DETECT_FACE *pstOutParam, int nWaitTime = 1000);

//////////////////////////////// 刻录上传接口 /////////////////////////////////

// 打开刻录会话, 返回刻录会话句柄
CLIENT_API LLONG CALL_METHOD CLIENT_StartBurnSession(LLONG lLoginID, const NET_IN_START_BURN_SESSION* pstInParam, NET_OUT_START_BURN_SESSION *pstOutParam, int nWaitTime);

// 关闭刻录会话
CLIENT_API BOOL CALL_METHOD CLIENT_StopBurnSession(LLONG lBurnSession);

// 开始刻录
CLIENT_API BOOL CALL_METHOD CLIENT_StartBurn(LLONG lBurnSession, const NET_IN_START_BURN* pstInParam, NET_OUT_START_BURN *pstOutParam, int nWaitTime);

// 停止刻录
CLIENT_API BOOL CALL_METHOD CLIENT_StopBurn(LLONG lBurnSession);

// 暂停/恢复刻录
CLIENT_API BOOL CALL_METHOD CLIENT_PauseBurn(LLONG lBurnSession, BOOL bPause);

// 重点标记
CLIENT_API BOOL CALL_METHOD CLIENT_BurnMarkTag(LLONG lBurnSession, const NET_IN_BURN_MARK_TAG* pstInParam, NET_OUT_BURN_MARK_TAG *pstOutParam, int nWaitTime);

// 换盘
CLIENT_API BOOL CALL_METHOD CLIENT_BurnChangeDisk(LLONG lBurnSession, const NET_IN_BURN_CHANGE_DISK* pstInParam, NET_OUT_BURN_CHANGE_DISK *pstOutParam, int nWaitTime);

// 获取刻录状态
CLIENT_API BOOL CALL_METHOD CLIENT_BurnGetState(LLONG lBurnSession, const NET_IN_BURN_GET_STATE* pstInParam, NET_OUT_BURN_GET_STATE *pstOutParam, int nWaitTime);

// 监听刻录状态
CLIENT_API LLONG CALL_METHOD CLIENT_AttachBurnState(LLONG lLoginID, const NET_IN_ATTACH_STATE* pstInParam, NET_OUT_ATTACH_STATE *pstOutParam, int nWaitTime = 1000);

// 取消监听刻录状态，lAttachHandle是CLIENT_AttachBurnState返回值
CLIENT_API BOOL CALL_METHOD CLIENT_DetachBurnState(LLONG lAttachHandle);

// 刻录上传开始 返回此次上传操作句柄, 注意以下接口不能在fAttachBurnStateCB回调函数里面调用
CLIENT_API LLONG CALL_METHOD CLIENT_StartUploadFileBurned(LLONG lLoginID, const NET_IN_FILEBURNED_START* pstInParam, NET_OUT_FILEBURNED_START *pstOutParam, int nWaitTime = 1000);

// 刻录上传文件，lUploadHandle是CLIENT_StartUploadFileBurned返回值
CLIENT_API BOOL CALL_METHOD CLIENT_SendFileBurned(LLONG lUploadHandle);

// 刻录上传停止，lUploadHandle是CLIENT_StartUploadFileBurned返回值,此接口不能在fBurnFileCallBack回调函数中调用
CLIENT_API BOOL CALL_METHOD CLIENT_StopUploadFileBurned(LLONG lUploadHandle);

// 监听刻录校验状态
CLIENT_API LLONG CALL_METHOD CLIENT_AttachBurnCheckState(LLONG lLoginID, const NET_IN_ATTACH_BURN_CHECK* pstInParam, NET_OUT_ATTACH_BURN_CHECK* pstOutParam, int nWaitTime = 1000);

// 取消监听刻录校验状态，lAttachHandle是CLIENT_AttachBurnCheckState返回值
CLIENT_API BOOL CALL_METHOD CLIENT_DetachBurnCheckState(LLONG lAttachHandle);

// 订阅刻录案件信息
CLIENT_API LLONG CALL_METHOD CLIENT_AttachBurnCase(LLONG lLoginID, const NET_IN_ATTACH_BURN_CASE* pInParam, NET_OUT_ATTACH_BURN_CASE* pOutParam, int nWaitTime);

// 取消订阅刻录案件信息，lAttachHandle是CLIENT_AttachBurnCase返回值
CLIENT_API BOOL CALL_METHOD CLIENT_DetachBurnCase(LLONG lAttachHandle);

//////////////////////////////// 逻辑设备 /////////////////////////////////////////

// 订阅摄像头状态
CLIENT_API LLONG CALL_METHOD CLIENT_AttachCameraState(LLONG lLoginID, const NET_IN_CAMERASTATE* pstInParam, NET_OUT_CAMERASTATE *pstOutParam, int nWaitTime = 3000);

// 停止订阅摄像头状态，lAttachHandle是CLIENT_AttachCameraState返回值
CLIENT_API BOOL CALL_METHOD CLIENT_DetachCameraState(LLONG lAttachHandle);

// 获取所有有效显示源
CLIENT_API BOOL CALL_METHOD CLIENT_MatrixGetCameras(LLONG lLoginID, const DH_IN_MATRIX_GET_CAMERAS* pInParam, DH_OUT_MATRIX_GET_CAMERAS* pOutParam, int nWaitTime = 1000);

// 添加逻辑设备
CLIENT_API BOOL CALL_METHOD CLIENT_MatrixAddCameras(LLONG lLoginID, const DH_IN_ADD_LOGIC_DEVICE_CAMERA* pInParam, DH_OUT_ADD_LOGIC_DEVICE_CAMERA* pOutParam, int nWaitTime = 1000);

//////////////////////////////// 矩阵接口 /////////////////////////////////

// 查询产品定义
CLIENT_API BOOL CALL_METHOD CLIENT_QueryProductionDefinition(LLONG lLoginID, DH_PRODUCTION_DEFNITION* pstuProdDef, int nWaitTime = 1000);

// 查询矩阵子卡信息
CLIENT_API BOOL CALL_METHOD CLIENT_QueryMatrixCardInfo(LLONG lLoginID, DH_MATRIX_CARD_LIST* pstuCardList, int nWaitTime = 1000);

// 查询系统状态
CLIENT_API BOOL CALL_METHOD CLIENT_QuerySystemStatus(LLONG lLoginID, DH_SYSTEM_STATUS* pstuStatus, int nWaitTime = 1000);

// 查询分割能力
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitCaps(LLONG lLoginID, int nChannel, DH_SPLIT_CAPS* pstuCaps, int nWaitTime = 1000);

// 查询/设置显示源
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitSource(LLONG lLoginID, int nChannel, int nWindow, DH_SPLIT_SOURCE* pstuSplitSrc, int nMaxCount, int* pnRetCount, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_SetSplitSource(LLONG lLoginID, int nChannel, int nWindow, const DH_SPLIT_SOURCE* pstuSplitSrc, int nSrcCount, int nWaitTime = 1000);
// 设置显示源, 支持输出参数
CLIENT_API BOOL CALL_METHOD CLIENT_SetSplitSourceEx(LLONG lLoginID, const NET_IN_SET_SPLIT_SOURCE* pInparam, NET_OUT_SET_SPLIT_SOURCE* pOutParam, int nWaitTime = 1000);

// 查询/设置分割模式
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitMode(LLONG lLoginID, int nChannel, DH_SPLIT_MODE_INFO* pstuSplitInfo, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_SetSplitMode(LLONG lLoginID, int nChannel, const DH_SPLIT_MODE_INFO* pstuSplitInfo, int nWaitTime = 1000);

// 查询分割分组数量
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitGroupCount(LLONG lLoginID, int nChannel, DH_SPLIT_MODE emSplitMode, int* pnGroupCount, int nWaitTime = 1000);

// 查询视频输出能力
CLIENT_API BOOL CALL_METHOD CLIENT_GetVideoOutCaps(LLONG lLoginID, int nChannel, DH_VIDEO_OUT_CAPS* pstuCaps, int nWaitTime = 1000);

// 设置视频输出选项
CLIENT_API BOOL CALL_METHOD CLIENT_SetVideoOutOption(LLONG lLoginID, int nChannel, const DH_VIDEO_OUT_OPT* pstuVideoOut, int nWaitTime = 1000);

// 查询视频输入通道目前在哪个窗口输出显示
CLIENT_API BOOL CALL_METHOD CLIENT_QueryVideoOutWindows(LLONG lLoginID, int nChannel, DH_VIDEO_OUT_WINDOW* pstuWnds, int nMaxWndCount, int* pnRetWndCount, int nWaitTime = 1000);

// 设置窗口位置
CLIENT_API BOOL CALL_METHOD CLIENT_SetSplitWindowRect(LLONG lLoginID, const DH_IN_SPLIT_SET_RECT* pInParam, DH_OUT_SPLIT_SET_RECT* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitWindowRect(LLONG lLoginID, const DH_IN_SPLIT_GET_RECT* pInParam, DH_OUT_SPLIT_GET_RECT* pOutParam, int nWaitTime = 1000);

// 开窗/关窗
CLIENT_API BOOL CALL_METHOD CLIENT_OpenSplitWindow(LLONG lLoginID, const DH_IN_SPLIT_OPEN_WINDOW* pInParam, DH_OUT_SPLIT_OPEN_WINDOW* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_CloseSplitWindow(LLONG lLoginID, const DH_IN_SPLIT_CLOSE_WINDOW* pInParam, DH_OUT_SPLIT_CLOSE_WINDOW* pOutParam, int nWaitTime = 1000);

// 设置窗口次序
CLIENT_API BOOL CALL_METHOD CLIENT_SetSplitTopWindow(LLONG lLoginID, const DH_IN_SPLIT_SET_TOP_WINDOW* pInParam, DH_OUT_SPLIT_SET_TOP_WINDOW* pOutParam, int nWaitTime = 1000);

// 获取当前显示的窗口信息
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitWindowsInfo(LLONG lLoginID, const DH_IN_SPLIT_GET_WINDOWS* pInParam, DH_OUT_SPLIT_GET_WINDOWS* pOutParam, int nWaitTime = 1000);

// 载入/保存收藏夹
CLIENT_API BOOL CALL_METHOD CLIENT_LoadSplitCollection(LLONG lLoginID, const DH_IN_SPLIT_LOAD_COLLECTION* pInParam, DH_OUT_SPLIT_LOAD_COLLECTION* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_SaveSplitCollection(LLONG lLoginID, const DH_IN_SPLIT_SAVE_COLLECTION* pInParam, DH_OUT_SPLIT_SAVE_COLLECTION* pOutParam, int nWaitTime = 1000);

// 获取收藏夹信息
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitCollections(LLONG lLoginID, const DH_IN_SPLIT_GET_COLLECTIONS* pInParam, DH_OUT_SPLIT_GET_COLLECTIONS* pOutParam, int nWaitTime = 1000);

// 重命名收藏夹
CLIENT_API BOOL CALL_METHOD CLIENT_RenameSplitCollection(LLONG lLoginID, const DH_IN_SPLIT_RENAME_COLLECTION* pInParam, DH_OUT_SPLIT_RENAME_COLLECTION* pOutParam, int nWaitTime = 1000);

// 删除收藏夹
CLIENT_API BOOL CALL_METHOD CLIENT_DeleteSplitCollection(LLONG lLoginID, const DH_IN_SPLIT_DELETE_COLLECTION* pInParam, DH_OUT_SPLIT_DELETE_COLLECTION* pOutParam, int nWaitTime = 1000);

// 解码策略
CLIENT_API BOOL CALL_METHOD CLIENT_SetDecodePolicy(LLONG lLoginID, const DH_IN_SET_DEC_POLICY* pInParam, DH_OUT_SET_DEC_POLICY* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_GetDecodePolicy(LLONG lLoginID, const DH_IN_GET_DEC_POLICY* pInParam, DH_OUT_GET_DEC_POLICY* pOutParam, int nWaitTime = 1000);

// 音频输出模式
CLIENT_API BOOL CALL_METHOD CLIENT_SetSplitAudioOuput(LLONG lLoginID, const DH_IN_SET_AUDIO_OUTPUT* pInParam, DH_OUT_SET_AUDIO_OUTPUT* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitAudioOuput(LLONG lLoginID, const DH_IN_GET_AUDIO_OUTPUT* pInParam, DH_OUT_GET_AUDIO_OUTPUT* pOutParam, int nWaitTime = 1000);

// 设置显示源
CLIENT_API BOOL CALL_METHOD CLIENT_MatrixSetCameras(LLONG lLoginID, const DH_IN_MATRIX_SET_CAMERAS* pInParam, DH_OUT_MATRIX_SET_CAMERAS* pOutParam, int nWaitTime = 1000);

// 获取视频输入能力
CLIENT_API BOOL CALL_METHOD CLIENT_GetVideoInCaps(LLONG lLoginID, const DH_IN_GET_VIDEO_IN_CAPS* pInParam, DH_OUT_GET_VIDEO_IN_CAPS* pOutParam, int nWaitTime = 1000);

// 获取视频输出模式
CLIENT_API BOOL CALL_METHOD CLIENT_EnumVideoOutModes(LLONG lLoginID, const DH_IN_ENUM_VIDEO_OUT_MODES* pInParam, DH_OUT_ENUM_VIDEO_OUT_MODES* pOutParam, int nWaitTime = 1000);

// 获取/设置解码窗口输出OSD信息
CLIENT_API BOOL CALL_METHOD CLIENT_GetSplitOSD(LLONG lLoginID, const DH_IN_SPLIT_GET_OSD* pInParam, DH_OUT_SPLIT_GET_OSD* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_SetSplitOSD(LLONG lLoginID, const DH_IN_SPLIT_SET_OSD* pInParam, DH_OUT_SPLIT_SET_OSD* pOutParam, int nWaitTime = 1000);

// 设置窗口轮巡显示源
CLIENT_API BOOL CALL_METHOD CLIENT_SetTourSource(LLONG lLoginID, const NET_IN_SET_TOUR_SOURCE* pInParam, NET_OUT_SET_TOUR_SOURCE* pOutParam, int nWaitTime = 1000);

// 下位矩阵切换
CLIENT_API BOOL CALL_METHOD CLIENT_MatrixSwitch(LLONG lLoginID, const NET_IN_MATRIX_SWITCH* pInParam, NET_OUT_MATRIX_SWITCH* pOutParam, int nWaitTime);

// 设置显示源, 支持同时设置多个窗口
CLIENT_API BOOL CALL_METHOD CLIENT_SplitSetMultiSource(LLONG lLoginID, const NET_IN_SPLIT_SET_MULTI_SOURCE* pInParam, NET_OUT_SPLIT_SET_MULTI_SOURCE* pOutParam, int nWaitTime);

// 视频分割操作
CLIENT_API BOOL CALL_METHOD CLIENT_OperateSplit(LLONG lLoginID, NET_SPLIT_OPERATE_TYPE emType, void* pInParam, void* pOutParam, int nWaitTime);


//////////////////////////////////// 电视墙控制 //////////////////////////////////////

// 电源控制
CLIENT_API BOOL CALL_METHOD CLIENT_PowerControl(LLONG lLoginID, const DH_IN_WM_POWER_CTRL* pInParam, DH_OUT_WM_POWER_CTRL* pOutParam, int nWaitTime = 1000);

// 获取/设置显示模式
CLIENT_API BOOL CALL_METHOD CLIENT_SetDisplayMode(LLONG lLoginID, const DH_IN_WM_SET_DISPLAY_MODE* pInParam, DH_OUT_WM_SET_DISPLAY_MODE* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_GetDisplayMode(LLONG lLoginID, const DH_IN_WM_GET_DISPLAY_MODE* pInParam, DH_OUT_WM_GET_DISPLAY_MODE* pOutParam, int nWaitTime = 1000);

// 载入/保存预案
CLIENT_API BOOL CALL_METHOD CLIENT_LoadMonitorWallCollection(LLONG lLoginID, const DH_IN_WM_LOAD_COLLECTION* pInParam, DH_OUT_WM_LOAD_COLLECTION* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_SaveMonitorWallCollection(LLONG lLoginID, const DH_IN_WM_SAVE_COLLECTION* pInParam, DH_OUT_WM_SAVE_COLLECTION* pOutParam, int nWaitTime = 1000);

// 获取电视墙预案
CLIENT_API BOOL CALL_METHOD CLIENT_GetMonitorWallCollections(LLONG lLoginID, const DH_IN_WM_GET_COLLECTIONS* pInParam, DH_OUT_WM_GET_COLLECTIONS* pOutParam, int nWaitTime = 1000);

// 电视墙预案重命名
CLIENT_API BOOL CALL_METHOD CLIENT_RenameMonitorWallCollection(LLONG lLoginID, const DH_IN_WM_RENAME_COLLECTION* pInParam, DH_OUT_WM_RENAME_COLLECTION* pOutParam, int nWaitTime = 1000);

// 获取/设置电视墙场景
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallGetScene(LLONG lLoginID, const DH_IN_MONITORWALL_GET_SCENE* pInParam, DH_OUT_MONITORWALL_GET_SCENE* pOutParam, int nWaitTime = 1000);
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallSetScene(LLONG lLoginID, const DH_IN_MONITORWALL_SET_SCENE* pInParam, DH_OUT_MONITORWALL_SET_SCENE* pOutParam, int nWaitTime = 1000);

// 获取电视墙显示单元能力集
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallGetAttributeCaps(LLONG lLoginID, const DH_IN_MONITORWALL_GET_ARRT_CAPS* pInParam, DH_OUT_MONITORWALL_GET_ARRT_CAPS* pOutParam, int nWaitTime = 1000);

// 电视墙显示单元自动调节
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallAutoAdjust(LLONG lLoginID, const DH_IN_MONITORWALL_AUTO_ADJUST* pInParam, DH_OUT_MONITORWALL_AUTO_ADJUST* pOutParam, int nWaitTime = 1000);

// 设置电视墙显示单元属性
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallSetAttribute(LLONG lLoginID, const DH_IN_MONITORWALL_SET_ATTR* pInParam, DH_OUT_MONITORWALL_SET_ATTR* pOutParam, int nWaitTime = 1000);

// 设置背光模式
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallSetBackLight(LLONG lLoginID, const DH_IN_MONITORWALL_SET_BACK_LIGHT* pInParam, DH_OUT_MONITORWALL_SET_BACK_LIGHT* pOutParam, int nWaitTime = 1000);

// 查询/设置屏幕开关计划
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallGetPowerSchedule(LLONG lLoginID, const NET_IN_MW_GET_POWER_SCHEDULE* pInParam, NET_OUT_MW_GET_POWER_SCHEDULE* pOutParam, int nWaitTime);
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallSetPowerSchedule(LLONG lLoginID, const NET_IN_MW_SET_POWER_SCHEDULE* pInParam, NET_OUT_MW_SET_POWER_SCHEDULE* pOutParam, int nWaitTime);

// 查询/设置屏幕控制参数
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallGetScrnCtrlParam(LLONG lLoginID, const NET_IN_MW_GET_SCRN_CTRL_PARAM* pInParam, NET_OUT_MW_GET_SCRN_CTRL_PARAM* pOutParam, int nWaitTime);
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallSetScrnCtrlParam(LLONG lLoginID, const NET_IN_MW_SET_SCRN_CTRL_PARAM* pInParam, NET_OUT_MW_SET_SCRN_CTRL_PARAM* pOutParam, int nWaitTime);

// 查询/设置屏幕和窗口背景颜色
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallGetBackgroudColor(LLONG lLoginID, const NET_IN_MW_GET_BACKGROUDND_COLOR* pInParam, NET_OUT_MW_GET_BACKGROUDND_COLOR* pOutParam, int nWaitTime);
CLIENT_API BOOL CALL_METHOD CLIENT_MonitorWallSetBackgroudColor(LLONG lLoginID, const NET_IN_MW_SET_BACKGROUD_COLOR* pInParam, NET_OUT_MW_SET_BACKGROUD_COLOR* pOutParam, int nWaitTime);

// 电视墙操作
CLIENT_API BOOL CALL_METHOD CLIENT_OperateMonitorWall(LLONG lLoginID, NET_MONITORWALL_OPERATE_TYPE emType, void* pInParam, void* pOutParam, int nWaitTime);

///////////////////////////////// 组织目录管理 /////////////////////////////////////////

// 组织目录管理-添加节点
CLIENT_API BOOL CALL_METHOD CLIENT_OrganizationAddNodes(LLONG lLoginID, const DH_IN_ORGANIZATION_ADD_NODES* pInParam, DH_OUT_ORGANIZATION_ADD_NODES* pOutParam, int nWaitTime = 1000);

// 组织目录管理-删除节点
CLIENT_API BOOL CALL_METHOD CLIENT_OrganizationDeleteNodes(LLONG lLoginID, const DH_IN_ORGANIZATION_DELETE_NODES* pInParam, DH_OUT_ORGANIZATION_DELETE_NODES* pOutParam, int nWaitTime = 1000);

// 组织目录管理-获取节点信息
CLIENT_API BOOL CALL_METHOD CLIENT_OrganizationGetNodes(LLONG lLoginID, const DH_IN_ORGANIZATION_GET_NODES* pInParam, DH_OUT_ORGANIZATION_GET_NODES* pOutParam, int nWaitTime = 1000);

// 组织目录管理-设置节点
CLIENT_API BOOL CALL_METHOD CLIENT_OrganizationSetNode(LLONG lLoginID, const DH_IN_ORGANIZATION_SET_NODE* pInParam, DH_OUT_ORGANIZATION_SET_NODE* pOutParam, int nWaitTime = 1000);


//////////////////////////////// 网络抓包 /////////////////////////////////

// 开始抓包
CLIENT_API LLONG CALL_METHOD CLIENT_StartSniffer(LLONG lLoginID, const DH_IN_START_SNIFFER* pInParam, DH_OUT_START_SNIFFER* pOutParam, int nWaitTime = 1000);

// 停止抓包
CLIENT_API BOOL CALL_METHOD CLIENT_StopSniffer(LLONG lLoginID, LLONG lSnifferID);

// 获取抓包状态
CLIENT_API BOOL CALL_METHOD CLIENT_GetSnifferInfo(LLONG lLoginID, const DH_IN_GET_SNIFFER_INFO* pInParam, DH_OUT_GET_SNIFFER_INFO* pOutParam, int nWaitTime = 1000);


//////////////////////////////// 远程文件管理 /////////////////////////////////

// 新建文件
CLIENT_API BOOL CALL_METHOD CLIENT_CreateRemoteFile(LLONG lLoginID, const DH_IN_CREATE_REMOTE_FILE* pInParam, DH_OUT_CREATE_REMOTE_FILE* pOutParam, int nWaitTime = 1000);

// 删除文件或目录
CLIENT_API BOOL CALL_METHOD CLIENT_RemoveRemoteFiles(LLONG lLoginID, const DH_IN_REMOVE_REMOTE_FILES* pInParam, DH_OUT_REMOVE_REMOTE_FILES* pOutParam, int nWaitTime = 1000);

// 重命名
CLIENT_API BOOL CALL_METHOD CLIENT_RenameRemoteFile(LLONG lLoginID, const DH_IN_RENAME_REMOTE_FILE* pInParam, DH_OUT_RENAME_REMOTE_FILE* pOutParam, int nWaitTime = 1000);

// 显示目录中文件和子目录
CLIENT_API BOOL CALL_METHOD CLIENT_ListRemoteFile(LLONG lLoginID, const DH_IN_LIST_REMOTE_FILE* pInParam, DH_OUT_LIST_REMOTE_FILE* pOutParam, int nWaitTime = 1000);

// 同步文件上传, 只适用于小文件
CLIENT_API BOOL CALL_METHOD CLIENT_UploadRemoteFile(LLONG lLoginID, const DH_IN_UPLOAD_REMOTE_FILE* pInParam, DH_OUT_UPLOAD_REMOTE_FILE* pOutParam, int nWaitTime = 1000);

// 远程投放, 在设备端播放音频文件
CLIENT_API BOOL CALL_METHOD CLIENT_PlayAudioFile(LLONG lLoginID, const NET_IN_PLAY_AUDIO_FILE* pInParam, NET_OUT_PLAY_AUDIO_FILE* pOutParam, int nWaitTime = 1000);

// 文件下载, 只适用于小文件
CLIENT_API BOOL CALL_METHOD CLIENT_DownloadRemoteFile(LLONG lLoginID, const DH_IN_DOWNLOAD_REMOTE_FILE* pInParam, DH_OUT_DOWNLOAD_REMOTE_FILE* pOutParam, int nWaitTime = 1000);

////////////////////////////////// 存储设备管理 ////////////////////////////////////////

// 获取ISCSI Target列表, pInParam == NULL获取所有targets
CLIENT_API BOOL CALL_METHOD    CLIENT_GetISCSITargets(LLONG lLoginID, const DH_IN_ISCSI_TARGETS* pInParam, DH_OUT_ISCSI_TARGETS* pOutParam, int nWaitTime = 1000);

CLIENT_API BOOL CALL_METHOD CLIENT_GetBitmap(LLONG lLoginID , const DH_IN_BITMAP* pInParam, DH_OUT_BITMAP* pOutParam, int nWaitTime = 1000);

// 获取存储设备名称列表
CLIENT_API BOOL CALL_METHOD    CLIENT_GetStorageDeviceNames(LLONG lLoginID, DH_STORAGE_DEVICE_NAME* pstuNames, int nMaxCount, int* pnRetCount, int nWaitTime = 1000);

// 获取存储设备信息
CLIENT_API BOOL CALL_METHOD    CLIENT_GetStorageDeviceInfo(LLONG lLoginID, const char* pszDevName, DH_STORAGE_DEVICE* pDevice, int nWaitTime = 1000);

// 订阅录像文件更新信息
CLIENT_API LLONG CALL_METHOD CLIENT_AttachRecordInfo(LLONG lLoginID, const NET_IN_ATTACH_RECORD_INFO* pInParam, NET_OUT_ATTACH_RECORD_INFO* pOutParam, int nWaitTime = 1000);

// 取消订阅录像文件更新信息，lAttachHandle是CLIENT_AttachRecordInfo的返回值
CLIENT_API BOOL CALL_METHOD CLIENT_DetachRecordInfo(LLONG lAttachHandle);

// 订阅写入远程存储的信息状态
CLIENT_API LLONG CALL_METHOD CLIENT_NetStorageAttachWriteInfo(LLONG lLoginID, const NET_IN_STORAGE_ATTACH_WRITE_INFO* pInParam, NET_OUT_STORAGE_ATTACH_WRITE_INFO* pOutParam, int nWaitTime);

// 取消写入远程设备信息，lAttachHandle是CLIENT_NetStorageAttachWriteInfo的返回值
CLIENT_API BOOL CALL_METHOD CLIENT_NetStorageDetachWriteInfo(LLONG lAttachHandle);

// 查询远程存储的写入信息状态
CLIENT_API BOOL CALL_METHOD CLIENT_NetStorageGetWriteInfo(LLONG lLoginID, const NET_IN_STORAGE_GET_WRITE_INFO* pInParam, NET_OUT_STORAGE_GET_WRITE_INFO* pOutParam, int nWaitTime);

// RAID操作, 不同操作类型对应不同的结构体
CLIENT_API BOOL CALL_METHOD CLIENT_OperateRaid(LLONG lLoginID, NET_RAID_OPERATE_TYPE emType, void* pInBuf, void* pOutBuf, int nWaitTime);

/////////////////////////////////// 级联设备 ///////////////////////////////////////

// 搜索级联视频源
CLIENT_API BOOL CALL_METHOD CLIENT_MatrixSearch(LLONG lLoginID, const DH_IN_MATRIX_SEARCH* pInParam, DH_OUT_MATRIX_SEARCH* pOutParam, int nWaitTime = 1000);

// 获取本级级联树列表
CLIENT_API BOOL CALL_METHOD CLIENT_GetMatrixTree(LLONG lLoginID, const DH_IN_GET_MATRIX_TREE* pInParam, DH_OUT_GET_MATRIX_TREE* pOutParam, int nWaitTime = 1000);

// 获取级联上级设备列表信息
CLIENT_API BOOL CALL_METHOD CLIENT_GetSuperiorMatrixList(LLONG lLoginID, const DH_IN_GET_SUPERIOR_MATRIX_LIST* pInParam, DH_OUT_GET_SUPERIOR_MATRIX_LIST* pOutParam, int nWaitTime = 1000);

/************************************************************************/
/*                            录像备份回传								*/
/************************************************************************/

// 开始录像备份恢复
CLIENT_API LLONG CALL_METHOD CLIENT_StartRecordBackupRestore(LLONG lLoginID);

// 停止录像备份恢复
CLIENT_API void CALL_METHOD CLIENT_StopRecordBackupRestore(LLONG lRestoreID);

// 添加录像备份恢复任务
CLIENT_API BOOL CALL_METHOD CLIENT_AddRecordBackupRestoreTask(LLONG lRestoreID, const DH_IN_ADD_REC_BAK_RST_TASK* pInParam, int nWaitTime = 1000);

// 删除录像备份恢复任务
CLIENT_API BOOL CALL_METHOD CLIENT_RemoveRecordBackupRestoreTask(LLONG lRestoreID, const DH_IN_REMOVE_REC_BAK_RST_TASK* pInParam, int nWaitTime = 1000);

// 获取录像备份恢复任务信息
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRecordBackupRestoreTask(LLONG lRestoreID, const DH_IN_QUERY_REC_BAK_RST_TASK* pInParam, DH_OUT_QUERY_REC_BAK_RST_TASK* pOutParam, int nWaitTime = 1000);

//////////////////////////////// Encode Manager  ////////////////////////////////
// 司法刻录中获取编码计划参数
CLIENT_API BOOL CALL_METHOD CLIENT_GetEncodePlan(LLONG lLoginID, const DH_IN_GET_ENCODE_PLAN* pInParam, DH_OUT_GET_ENCODE_PLAN* pOutParam, int nWaitTime = 1000);

/************************************************************************/
/*                           数据库记录相关操作                         */
/************************************************************************/
// 按查询条件查询记录
CLIENT_API BOOL    CALL_METHOD CLIENT_FindRecord(LLONG lLoginID, NET_IN_FIND_RECORD_PARAM* pInParam, NET_OUT_FIND_RECORD_PARAM* pOutParam, int waittime=1000);    

// 查找记录:nFilecount:需要查询的条数, 返回值为媒体文件条数 返回值<nFilecount则相应时间段内的文件查询完毕
CLIENT_API int    CALL_METHOD CLIENT_FindNextRecord(NET_IN_FIND_NEXT_RECORD_PARAM* pInParam, NET_OUT_FIND_NEXT_RECORD_PARAM* pOutParam, int waittime=1000);

// 查找记录条数
CLIENT_API BOOL    CALL_METHOD CLIENT_QueryRecordCount(NET_IN_QUEYT_RECORD_COUNT_PARAM* pInParam, NET_OUT_QUEYT_RECORD_COUNT_PARAM* pOutParam, int waittime=1000);

// 结束记录查找
CLIENT_API BOOL CALL_METHOD CLIENT_FindRecordClose(LLONG lFindHandle);

/************************************************************************/
/*                            云台元数据接口订阅						*/
/************************************************************************/
// 订阅云台元数据接口
CLIENT_API LLONG CALL_METHOD CLIENT_AttachPTZStatusProc(LLONG lLoginID, NET_IN_PTZ_STATUS_PROC *pstuInPtzStatusProc,  NET_OUT_PTZ_STATUS_PROC *pstuOutPtzStatusProc, int nWaitTime = 3000);

// 停止订阅云台元数据接口，lAttachHandle是CLIENT_AttachPTZStatusProc返回值
CLIENT_API BOOL    CALL_METHOD    CLIENT_DetachPTZStatusProc(LLONG lAttachHandle);

/************************************************************************/
/*                            云台可视域订阅							*/
/************************************************************************/
// 订阅云台可视域
CLIENT_API LLONG CALL_METHOD CLIENT_AttachViewRangeState(LLONG lLoginID, NET_IN_VIEW_RANGE_STATE *pstuInViewRange, NET_OUT_VIEW_RANGE_STATE *pstuOutViewRange, int nWaitTime = 3000);

// 停止订阅云台可视域，lAttachHandle是CLIENT_AttachViewRangeState返回值
CLIENT_API BOOL    CALL_METHOD    CLIENT_DetachViewRangeState(LLONG lAttachHandle);

/************************************************************************/
/*                            模拟量报警通道数据订阅					*/
/************************************************************************/

// 订阅模拟量报警通道数据
CLIENT_API LLONG CALL_METHOD CLIENT_AttachAnalogAlarmData(LLONG lLoginID, const NET_IN_ANALOGALARM_DATA* pInParam, NET_OUT_ANALOGALARM_DATA* pOutParam, int nWaitTime);

// 停止订阅模拟量报警通道数据
CLIENT_API BOOL CALL_METHOD CLIENT_DetachAnalogAlarmData(LLONG lAttachHandle);

///////////////////////////////特殊版本接口///////////////////////////////
// 打开日志功能
CLIENT_API BOOL CALL_METHOD CLIENT_LogOpen(LOG_SET_PRINT_INFO *pstLogPrintInfo);

// 关闭日志功能
CLIENT_API BOOL CALL_METHOD CLIENT_LogClose();

// 查询设备日志--扩展
CLIENT_API BOOL CALL_METHOD CLIENT_QueryLogEx(LLONG lLoginID, DH_LOG_QUERY_TYPE logType, char *pLogBuffer, int maxlen, int *nLogBufferlen, void* reserved, int waittime=3000);

// 开始查询日志(目前只支持门禁BSC系列)
CLIENT_API LLONG CALL_METHOD CLIENT_StartQueryLog(LLONG lLoginID, const NET_IN_START_QUERYLOG* pInParam, NET_OUT_START_QUERYLOG* pOutParam, int nWaitTime);

// 获取日志(目前只支持门禁BSC系列)
CLIENT_API BOOL CALL_METHOD CLIENT_QueryNextLog(LLONG lLogID, NET_IN_QUERYNEXTLOG* pInParam, NET_OUT_QUERYNEXTLOG* pOutParam, int nWaitTime);

// 结束查询日志(目前只支持门禁BSC系列)
CLIENT_API BOOL CALL_METHOD CLIENT_StopQueryLog(LLONG lLogID);

// 主动注册重定向功能，建立定向连接
CLIENT_API LONG CALL_METHOD CLIENT_ControlConnectServer(LLONG lLoginID, char* RegServerIP, WORD RegServerPort, int TimeOut=3000);

// 连接主动注册
CLIENT_API BOOL CALL_METHOD CLIENT_ControlRegisterServer(LLONG lLoginID, LONG ConnectionID, int waittime=1000);

// 断开定向连接
CLIENT_API BOOL CALL_METHOD CLIENT_ControlDisconnectRegServer(LLONG lLoginID, LONG ConnectionID);

// 查询设备上主动注册服务器信息
CLIENT_API BOOL CALL_METHOD CLIENT_QueryControlRegServerInfo(LLONG lLoginID, LPDEV_SERVER_AUTOREGISTER lpRegServerInfo, int waittime=2000);

// 文件上传接口
CLIENT_API LLONG CALL_METHOD CLIENT_FileTransmit(LLONG lLoginID, int nTransType, char* szInBuf, int nInBufLen, fTransFileCallBack cbTransFile, LDWORD dwUserData, int waittime);

// web信息上传接口
CLIENT_API BOOL  CALL_METHOD CLIENT_TransmitInfoForWeb(LLONG lLoginID, char* szInBuffer, DWORD dwInBufferSize, char* szOutBuffer, DWORD dwOutBufferSize, void* pExtData, int waittime=500);

// 水印检测, *nResult = 0-表示当前图片未被修改 *nResult = 1-表示当前图片已被修改
CLIENT_API BOOL  CALL_METHOD CLIENT_WatermarkVerifyForPicture(char* szFilePath, int* nResult, void* pReserved);

// 多通道组合打开监视
CLIENT_API BOOL  CALL_METHOD CLIENT_MultiRealPlay(LLONG lLoginID, DHDEV_IN_MULTIPLAY_PARAM* pInBuf, int nInBufLen, DHDEV_OUT_MULTIPLAY_PARAM* pOutBuf, int nOutBufLen, int* pRetLen);
 
// 多通道停止监视
CLIENT_API BOOL  CALL_METHOD CLIENT_StopMultiRealPlay(LLONG* lRealHandles, int nNumOfHandles);

// 设置回放的YUV数据回调接口，当hwnd不为空时有效
CLIENT_API BOOL CALL_METHOD CLIENT_SetPlaybackYUVCallBack(LLONG lPlayHandle, fYUVDataCallBack cYUVData, LDWORD dwUser);

// web获取配置
CLIENT_API BOOL CALL_METHOD CLIENT_GetNewDevConfigForWeb(LLONG lLoginID, char* szCommand, int nChannelID, char* szOutBuffer, DWORD dwOutBufferSize, int *error, int waittime=500);

// web设置配置
CLIENT_API BOOL CALL_METHOD CLIENT_SetNewDevConfigForWeb(LLONG lLoginID, char* szCommand, int nChannelID, char* szInBuffer, DWORD dwInBufferSize, int *error, int *restart, int waittime=500);

// 建立端口映射
CLIENT_API int CALL_METHOD CLIENT_CreateOneTunnel(LOSN_IN_CREATE_TUNNEL_PARAM pInParam, LOSN_OUT_CREATE_TUNNEL_PARAM pOutParam, int waittime=1000);

// 删除端口映射
CLIENT_API int CALL_METHOD CLIENT_DestroyOneTunnel(LOSN_IN_DESTROY_TUNNEL_PARAM pInParam);

// 设置播放策略参数，只对实时流有效
CLIENT_API BOOL CALL_METHOD CLIENT_SetPlayMethod(LLONG lRealHandle, int nStartTime, int nSlowTime, int nFastTime, int nFailedTime);

// 关闭设备主动注册上来的链接
CLIENT_API BOOL CALL_METHOD CLIENT_CloseRegConnect(LLONG lHandle, char *pIp, WORD wPort, void *pParam);

//////上海BUS//////

#ifdef SHANGHAIBUS
// 串口数据交互接口,异步获取数据
CLIENT_API LLONG CALL_METHOD CLIENT_ExChangeData(LLONG lLoginId, NET_IN_EXCHANGEDATA* pInParam, NET_OUT_EXCHANGEDATA* pOutParam, int nWaittime = 5000);

// 监听CAN总线数据
CLIENT_API LLONG CALL_METHOD CLIENT_AttachCAN(LLONG lLoginID, const NET_IN_ATTACH_CAN* pstInParam, NET_OUT_ATTACH_CAN* pstOutParam, int nWaitTime = 3000);

// 取消监听CAN总线数据，lAttachHandle是CLIENT_AttachCAN返回值
CLIENT_API BOOL CALL_METHOD CLIENT_DetachCAN(LLONG lAttachHandle);

// 监听透明串口数据
CLIENT_API LLONG CALL_METHOD CLIENT_AttachDevComm(LLONG lLoginID, const NET_IN_ATTACH_DEVCOMM* pstInParam, NET_OUT_ATTACH_DEVCOMM* pstOutParam, int nWaitTime = 3000);

// 取消监听透明串口数据，lAttachHandle是CLIENT_AttachDevComm返回值
CLIENT_API BOOL CALL_METHOD CLIENT_DetachDevComm(LLONG lAttachHandle);

#endif

// RPC能力查询
CLIENT_API BOOL CALL_METHOD CLIENT_QueryRpcMethod(LLONG lLoginID, const char* pszMethod, BOOL* pResult, int nWaitTime);

/////////////////////////////////淘汰接口/////////////////////////////////

// 查询系统服务器配置；该接口已淘汰，请使用CLIENT_GetDevConfig
CLIENT_API BOOL CALL_METHOD CLIENT_QueryConfig(LLONG lLoginID, int nConfigType, char *pConfigbuf, int maxlen, int *nConfigbuflen, int waittime=1000);

// 设置系统服务器配置；该接口已淘汰，请使用CLIENT_SetDevConfig
CLIENT_API BOOL CALL_METHOD CLIENT_SetupConfig(LLONG lLoginID, int nConfigType, char *pConfigbuf, int nConfigbuflen, int waittime=1000);

// 该接口已淘汰，请不要使用
CLIENT_API BOOL CALL_METHOD CLIENT_Reset(LLONG lLoginID, BOOL bReset);

// 查询串口协议 － 该接口已淘汰，请使用CLIENT_GetDevConfig
CLIENT_API BOOL CALL_METHOD CLIENT_QueryComProtocol(LLONG lLoginID, int nProtocolType, char *pProtocolBuffer, int maxlen, int *nProtocollen, int waittime=1000);

// 开始对讲；该接口已淘汰，请使用CLIENT_StartTalkEx
CLIENT_API BOOL CALL_METHOD CLIENT_StartTalk(LLONG lRealHandle, BOOL bCustomSend=false);

// 结束对讲；该接口已淘汰，请使用CLIENT_StopTalkEx
CLIENT_API BOOL CALL_METHOD CLIENT_StopTalk(LLONG lRealHandle);

// 发送自定义对讲数据；该接口已淘汰，请使用CLIENT_TalkSendData
CLIENT_API BOOL CALL_METHOD CLIENT_SendTalkData_Custom(LLONG lRealHandle, char *pBuffer, DWORD dwBufSize);

// 设置实时预览缓冲大小
CLIENT_API BOOL CALL_METHOD CLIENT_SetPlayerBufNumber(LLONG lRealHandle, DWORD dwBufNum);

// 通过时间下载文件
CLIENT_API BOOL CALL_METHOD CLIENT_GetFileByTime(LLONG lLoginID, int nChannelID, LPNET_TIME lpStartTime, LPNET_TIME lpStopTime, char *sSavedFileName);

// 网络回放控制
CLIENT_API BOOL CALL_METHOD CLIENT_PlayBackControl(LLONG lPlayHandle, DWORD dwControlCode, DWORD dwInValue, DWORD *lpOutValue);

// 查询设备工作状态 该接口已淘汰，请使用CLIENT_QueryDevState
CLIENT_API BOOL CALL_METHOD CLIENT_GetDEVWorkState(LLONG lLoginID, LPNET_DEV_WORKSTATE lpWorkState, int waittime=1000);

// 异步查询设备日志
CLIENT_API BOOL CALL_METHOD CLIENT_QueryLogCallback(LLONG lLoginID, fLogDataCallBack cbLogData, LDWORD dwUser);


#ifdef __cplusplus
}
#endif
#endif // DHNETSDK_H





