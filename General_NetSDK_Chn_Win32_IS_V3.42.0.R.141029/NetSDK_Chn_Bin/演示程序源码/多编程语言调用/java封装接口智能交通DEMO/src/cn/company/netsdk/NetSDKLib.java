public package cn.company.netsdk;

import com.sun.jna.win32.StdCallLibrary;
import com.sun.jna.Native;
import com.sun.jna.NativeLong;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
/**
 * SDK JNA接口封装
 */
public interface NetSDKLib extends StdCallLibrary{
	
	NetSDKLib INSTANCE = (NetSDKLib) Native.loadLibrary("netsdk",
			NetSDKLib.class);
    
	/************************************************************************
	 ** 常量定义
	 ***********************************************************************/
	public static final int MAX_PATH              = 260; // 通用字符串长度
	public static final int DH_SERIALNO_LEN       = 48;  // 设备序列号字符长度
	public static final int DH_MAX_DISKNUM        = 256;  // 最大硬盘个数
	public static final int DH_MAX_SDCARDNUM      = 32;  // 最大SD卡个数
	public static final int DH_MAX_BURNING_DEV_NUM    = 32;  // 最大刻录设备个数
	public static final int DH_BURNING_DEV_NAMELEN    = 32;  // 刻录设备名字最大长度
	public static final int DH_MAX_LINK         = 6;
	public static final int DH_MAX_CHANNUM        = 16;  // 最大通道个数
	public static final int DH_MAX_DECODER_CHANNUM    = 64;  // 解码器最大通道数
	public static final int DH_MAX_ALARMIN        = 128;  // 最大报警输入个数
	public static final int DH_MAX_ALARMOUT       = 64;  // 最大报警输出个数
	public static final int DH_MAX_RIGHT_NUM      = 100;  // 用户权限个数上限
	public static final int DH_MAX_GROUP_NUM      = 20;  // 用户组个数上限
	public static final int DH_MAX_USER_NUM       = 200;  // 用户个数上限
	public static final int DH_RIGHT_NAME_LENGTH    = 32;  // 权限名长度
	public static final int DH_USER_NAME_LENGTH     = 8;  // 用户名长度
	public static final int DH_USER_PSW_LENGTH      = 8;  // 用户密码长度
	public static final int DH_MEMO_LENGTH        = 32;  // 备注长度
	public static final int DH_MAX_STRING_LEN     = 128;
	public static final int DH_DVR_SERIAL_RETURN    = 1;  // 设备发送序列号回调
	public static final int DH_DVR_DISCONNECT     = -1;  // 验证期间设备断线回调
	public static final int MAX_STRING_LINE_LEN     = 6;  // 最多六行
	public static final int MAX_PER_STRING_LEN      = 20;  // 每行最大长度
	public static final int DH_MAX_MAIL_NAME_LEN    = 64;  // 新的邮件结构体支持的用户名长度
	public static final int DH_MAX_MAIL_PSW_LEN     = 64;  // 新的邮件结构体支持的密码长度
	public static final int DH_SPEEDLIMIT_TYPE_LEN      = 32;  // 限速类型字符串长度
	public static final int DH_VEHICLE_TYPE_LEN         = 32;  // 车载自定义信息类型字符串长度
	public static final int DH_VEHICLE_INFO_LEN         = 32;  // 车载自定义信息字符串长度
	public static final int DH_VEHICLE_DRIVERNO_LEN     = 32;  // 车载自定义信息司机工号字符串长度
	public static final int DH_MAX_CROSSING_NUM         = 128;  // 最大点位
	public static final int DH_MAX_CROSSING_ID          = 32;  // 路口序列号最大长度
	public static final int DH_MAX_CARD_INFO_LEN    = 256;  // 卡号信息最大长度
	public static final int DH_MAX_CHANNUM_EX           = 32;  // 最大通道数扩展  
	public static final int DH_MAX_SAERCH_IP_NUM        = 256;  // 最大搜索IP个数
	public static final int DH_MAX_HARDDISK_TYPE_LEN  = 32;  // 硬盘型号最大长度
	public static final int DH_MAX_HARDDISK_SERIAL_LEN  = 32;  // 硬盘序列号最大长度
	public static final int DH_MAX_SIM_LEN        = 16;  // SIM卡的值的最大长度
	public static final int DH_MAX_SIM_NUM        = 10;  // 车载SIM卡最大个数
	public static final int DH_MAX_VERSION_LEN      = 32;  // 软件版本号最大长度
	public static final int DH_MAX_MDN_LEN        = 36;  // MDN的值的最大长度
	public static final int DH_MAX_NETINTERFACE_NUM     = 64;  // 支持的网卡个数
	public static final int DH_EVENT_NAME_LEN     = 128;  // 事件名称长度
	public static final int DH_STORAGE_NAME_LEN     = 128;  // 存储设备名称长度


	// 远程配置结构体相关常量
	public static final int DH_MAX_MAIL_ADDR_LEN    = 128;  // 邮件发(收)地址最大长度
	public static final int DH_MAX_MAIL_SUBJECT_LEN   = 64;  // 邮件主题最大长度
	public static final int DH_MAX_IPADDR_LEN     = 16;  // IP地址字符串长度
	public static final int DH_MACADDR_LEN        = 40;  // MAC地址字符串长度
	public static final int DH_MAX_URL_LEN        = 128;  // URL字符串长度
	public static final int DH_MAX_DEV_ID_LEN     = 48;  // 机器编号最大长度
	public static final int DH_MAX_HOST_NAMELEN     = 64;  // 主机名长度，
	public static final int DH_MAX_HOST_PSWLEN      = 32;  // 密码长度
	public static final int DH_MAX_NAME_LEN       = 16;  // 通用名字字符串长度
	public static final int DH_MAX_ETHERNET_NUM     = 2;  // 以太网口最大个数
	public static final int DH_MAX_ETHERNET_NUM_EX      = 10;  // 扩展以太网口最大个数
	public static final int DH_DEV_SERIALNO_LEN     = 48;  // 序列号字符串长度
	public static final int DH_DEV_TYPE_LEN       = 32;  // 设备类型字符串长度
	public static final int DH_N_WEEKS          = 7;  // 一周的天数 
	public static final int DH_N_TSECT          = 6;  // 通用时间段个数
	public static final int DH_N_REC_TSECT        = 6;  // 录像时间段个数
	public static final int DH_N_COL_TSECT        = 2;  // 颜色时间段个数 
	public static final int DH_CHAN_NAME_LEN      = 32;  // 通道名长度，DVR DSP能力限制，最多32字节    
	public static final int DH_N_ENCODE_AUX       = 3;  // 扩展码流个数 
	public static final int DH_N_TALK         = 1;  // 最多对讲通道个数
	public static final int DH_N_COVERS         = 1;  // 遮挡区域个数 
	public static final int DH_N_CHANNEL        = 16;  // 最大通道个数 
	public static final int DH_N_ALARM_TSECT      = 2;  // 报警提示时间段个数
	public static final int DH_MAX_ALARMOUT_NUM     = 16;  // 报警输出口个数上限
	public static final int DH_MAX_AUDIO_IN_NUM     = 16;  // 音频输入口个数上限
	public static final int DH_MAX_VIDEO_IN_NUM     = 16;  // 视频输入口个数上限
	public static final int DH_MAX_ALARM_IN_NUM     = 16;  // 报警输入口个数上限
	public static final int DH_MAX_DISK_NUM       = 16;  // 硬盘个数上限，暂定为16
	public static final int DH_MAX_DECODER_NUM      = 16;  // 解码器(485)个数上限  
	public static final int DH_MAX_232FUNCS       = 10;  // 232串口功能个数上限
	public static final int DH_MAX_232_NUM        = 2;  // 232串口个数上限
	public static final int DH_MAX_232_NUM_EX           = 16;  // 扩展串口配置个数上限          
	public static final int DH_MAX_DECPRO_LIST_SIZE   = 100;  // 解码器协议列表个数上限
	public static final int DH_FTP_MAXDIRLEN      = 240;  // FTP文件目录最大长度
	public static final int DH_MATRIX_MAXOUT      = 16;  // 矩阵输出口最大个数
	public static final int DH_TOUR_GROUP_NUM     = 6;  // 矩阵输出组最大个数
	public static final int DH_MAX_DDNS_NUM       = 10;  // 设备支持的ddns服务器最大个数
	public static final int DH_MAX_SERVER_TYPE_LEN    = 32;  // ddns服务器类型，最大字符串长度
	public static final int DH_MAX_DOMAIN_NAME_LEN    = 256;  // ddns域名，最大字符串长度
	public static final int DH_MAX_DDNS_ALIAS_LEN   = 32;  // ddns服务器别名，最大字符串长度
	public static final int DH_MAX_DEFAULT_DOMAIN_LEN = 60;  // ddns默认域名，最大字符串长度   
	public static final int DH_MOTION_ROW       = 32;  // 动态检测区域的行数
	public static final int DH_MOTION_COL       = 32;  // 动态检测区域的列数
	public static final int DH_STATIC_ROW       = 32;  // 静态检测区域的行数
	public static final int DH_STATIC_COL         = 32;  // 静态检测区域的列数
	public static final int DH_FTP_USERNAME_LEN     = 64;  // FTP配置，用户名最大长度
	public static final int DH_FTP_PASSWORD_LEN     = 64;  // FTP配置，密码最大长度
	public static final int DH_TIME_SECTION       = 2;  // FTP配置，每天时间段个数
	public static final int DH_FTP_MAX_PATH       = 240;  // FTP配置，文件路径名最大长度
	public static final int DH_FTP_MAX_SUB_PATH     = 128;  // FTP配置，文件路径名最大长度
	public static final int DH_INTERVIDEO_UCOM_CHANID = 32;  // 平台接入配置，U网通通道ID
	public static final int DH_INTERVIDEO_UCOM_DEVID  = 32;  // 平台接入配置，U网通设备ID
	public static final int DH_INTERVIDEO_UCOM_REGPSW = 16;  // 平台接入配置，U网通注册密码
	public static final int DH_INTERVIDEO_UCOM_USERNAME = 32;  // 平台接入配置，U网通用户名
	public static final int DH_INTERVIDEO_UCOM_USERPSW  = 32;  // 平台接入配置，U网通密码
	public static final int DH_INTERVIDEO_NSS_IP    = 32;  // 平台接入配置，中兴力维IP
	public static final int DH_INTERVIDEO_NSS_SERIAL  = 32;  // 平台接入配置，中兴力维serial
	public static final int DH_INTERVIDEO_NSS_USER    = 32;  // 平台接入配置，中兴力维user
	public static final int DH_INTERVIDEO_NSS_PWD   = 50;  // 平台接入配置，中兴力维password
	public static final int DH_MAX_VIDEO_COVER_NUM    = 16;  // 遮挡区域最大个数
	public static final int DH_MAX_WATERMAKE_DATA   = 4096;  // 水印图片数据最大长度
	public static final int DH_MAX_WATERMAKE_LETTER   = 128;  // 水印文字最大长度
	public static final int DH_MAX_WLANDEVICE_NUM   = 10;  // 最多搜索出的无线设备个数
	public static final int DH_MAX_WLANDEVICE_NUM_EX  = 32;  // 最多搜索出的无线设备个数
	public static final int DH_MAX_ALARM_NAME     = 64;  // 地址长度
	public static final int DH_MAX_REGISTER_SERVER_NUM  = 10;  // 主动注册服务器个数
	public static final int DH_SNIFFER_FRAMEID_NUM    = 6;  // 6个FRAME ID 选项
	public static final int DH_SNIFFER_CONTENT_NUM    = 4;  // 每个FRAME对应的4个抓包内容
	public static final int DH_SNIFFER_CONTENT_NUM_EX = 8;  // 每个FRAME对应的8个抓包内容
	public static final int DH_SNIFFER_PROTOCOL_SIZE  = 20;  // 协议名字长度
	public static final int DH_MAX_PROTOCOL_NAME_LENGTH = 20;
	public static final int DH_SNIFFER_GROUP_NUM    = 4;  // 4组抓包设置
	public static final int MAX_PATH_STOR       = 240;  // 远程目录的长度
	public static final int DH_ALARM_OCCUR_TIME_LEN   = 40;  // 新的报警上传时间的长度
	public static final int DH_VIDEO_OSD_NAME_NUM   = 64;  // 叠加的名称长度，目前支持32个英文，16个中文
	public static final int DH_VIDEO_CUSTOM_OSD_NUM   = 8;  // 支持的自定义叠加的数目，不包含时间和通道
	public static final int DH_CONTROL_AUTO_REGISTER_NUM = 100;  // 支持定向主动注册服务器的个数
	public static final int DH_MMS_RECEIVER_NUM          = 100;  // 支持短信接收者的个数
	public static final int DH_MMS_SMSACTIVATION_NUM     = 100;  // 支持短信发送者的个数
	public static final int DH_MMS_DIALINACTIVATION_NUM  = 100;  // 支持拨号发送者的个数
	public static final int DH_MAX_ALARMOUT_NUM_EX     = 32;  // 报警输出口个数上限扩展
	public static final int DH_MAX_VIDEO_IN_NUM_EX     = 32;  // 视频输入口个数上限扩展
	public static final int DH_MAX_ALARM_IN_NUM_EX     = 32;  // 报警输入口个数上限
	public static final int DH_MAX_IPADDR_OR_DOMAIN_LEN  = 64;  // IP地址字符串长度
	public static final int DH_MAX_OBJECT_LIST       = 16;  // 智能分析设备检测到的物体ID个数上限 
	public static final int DH_MAX_RULE_LIST       = 16;  // 智能分析设备规则个数上限
	public static final int DH_MAX_POLYGON_NUM       = 16;  // 多边形最大顶点个数
	public static final int DH_MAX_DETECT_LINE_NUM       = 20;  // 规则检测线最大顶点数
	public static final int DH_MAX_DETECT_REGION_NUM     = 20;  // 规则检测区域最大顶点数
	public static final int DH_MAX_TRACK_LINE_NUM        = 20;  // 物体运动轨迹最大顶点数
	public static final int DH_MAX_CANDIDATE_NUM         = 50;  // 人脸识别最大匹配数
	public static final int DH_MAX_PERSON_IMAGE_NUM      = 48;  // 每个人员对应的最大人脸图片数
	public static final int DH_MAX_FENCE_LINE_NUM        = 2;  // 围栏最大曲线数
	public static final int MAX_SMART_VALUE_NUM          = 30;  // 最多的smart信息个数
	public static final int DH_MACHINE_NAME_NUM      = 64;  // 机器名称长度
	public static final int DH_INTERVIDEO_AMP_DEVICESERIAL    = 48;  // 平台接入配置，天地阳光 设备序列号字符串长度
	public static final int DH_INTERVIDEO_AMP_DEVICENAME      = 16;  // 平台接入配置，天地阳光 设备名称字符串长度
	public static final int DH_INTERVIDEO_AMP_USER            = 32;  // 平台接入配置，天地阳光 注册用户名字符串长度
	public static final int DH_INTERVIDEO_AMP_PWD             = 32;  // 平台接入配置，天地阳光 注册密码字符串长度
	public static final int MAX_SUBMODULE_NUM            = 32;  // 最多子模块信息个数
	public static final int DH_MAX_CARWAY_NUM            = 8;  // 交通抓拍，最大车道数
	public static final int DH_MAX_SNAP_SIGNAL_NUM       = 3;  // 一个车道的最大抓拍张数
	public static final int DH_MAX_CARD_NUM              = 128;  // 卡号的最大个数
	public static final int DH_MAX_CARDINFO_LEN          = 32;  // 每条卡号最长字符数
	public static final int DH_MAX_CONTROLER_NUM         = 64;  // 最大支持控制器数目
	public static final int DH_MAX_LIGHT_NUM             = 32;  // 最多控制灯组数
	public static final int DH_MAX_SNMP_COMMON_LEN       = 64;  // snmp 读写数据长度
	public static final int DH_MAX_DDNS_STATE_LEN        = 128;  // DDNS 状态信息长度
	public static final int DH_MAX_PHONE_NO_LEN          = 16;  // 电话号码长度
	public static final int DH_MAX_MSGTYPE_LEN           = 32;  // 导航类型或短信息类型长度
	public static final int DH_MAX_MSG_LEN               = 256;  // 导航和短信息长度
	public static final int DH_MAX_DRIVINGDIRECTION      = 256;  // 行驶方向字符串长度
	public static final int DH_MAX_GRAB_INTERVAL_NUM     = 4;  // 多张图片抓拍个数
	public static final int DH_MAX_FLASH_NUM       = 5;  // 最多支持闪光灯个数
	public static final int DH_MAX_LANE_NUM              = 8;  // 视频分析设备每个通道对应车道数上限
	public static final int DH_MAX_ISCSI_PATH_NUM    = 64;  // ISCSI远程目录最大数量
	public static final int DH_MAX_WIRELESS_CHN_NUM    = 256;  // 无线路由最大信道数
	public static final int DH_PROTOCOL3_BASE      = 100;  // 三代协议版本基数
	public static final int DH_PROTOCOL3_SUPPORT     = 11;  // 只支持3代协议
	public static final int DH_MAX_CHANMASK              = 64;  // 通道掩码最大值
	public static final int DH_MAX_STAFF_NUM       = 20;  // 浓缩视频配置信息中标尺数上限
	public static final int DH_MAX_CALIBRATEBOX_NUM    = 10;  // 浓缩视频配置信息中标定区域数上限
	public static final int DH_MAX_EXCLUDEREGION_NUM   = 10;  // 浓缩视频配置信息中排除区域数上限
	public static final int DH_MAX_POLYLINE_NUM      = 20;  // 浓缩视频配置信息中标尺线数
	public static final int DH_MAX_COLOR_NUM       = 16;  // 最大颜色数目
	public static final int MAX_OBJFILTER_NUM      = 16;  // 最大过滤种类个数
	public static final int DH_MAX_SYNOPSIS_STATE_NAME   = 64;  // 视频浓缩状态字符串长度
	public static final int DH_MAX_SYNOPSIS_QUERY_FILE_COUNT  = 10;  // 视频浓缩相关原始文件按照路径查找时文件个数上限
	public static final int DH_MAX_SSID_LEN              = 36;  // SSID长度
	public static final int DH_MAX_APPIN_LEN             = 16;  // PIN码长度
	public static final int DH_NETINTERFACE_NAME_LEN     = 260;  // 网口名称长度
	public static final int DH_NETINTERFACE_TYPE_LEN     = 260;  // 网络类型长度
	public static final int DH_MAX_CONNECT_STATUS_LEN    = 260;  // 连接状态字符串长度
	public static final int DH_MAX_MODE_LEN              = 64;  // 3G支持的网络模式长度
	public static final int DH_MAX_MODE_NUM              = 64;  // 3G支持的网络模式个数
	public static final int DH_MAX_CAPTURE_SIZE_NUM      = 64;  // 视频分辨率个数
	public static final int DH_NODE_NAME_LEN       = 64;  // 组织结构节点名称长度
	public static final int MAX_CALIBPOINTS_NUM          = 256;  // 支持最大标定点数

	// 查询类型，对应CLIENT_QueryDevState接口
	public static final int DH_DEVSTATE_COMM_ALARM   = 0x0001;  // 查询普通报警状态(包括外部报警，视频丢失，动态检测)
	public static final int DH_DEVSTATE_SHELTER_ALARM= 0x0002;  // 查询遮挡报警状态
	public static final int DH_DEVSTATE_RECORDING  = 0x0003;  // 查询录象状态
	public static final int DH_DEVSTATE_DISK     = 0x0004;  // 查询硬盘信息
	public static final int DH_DEVSTATE_RESOURCE   = 0x0005;  // 查询系统资源状态
	public static final int DH_DEVSTATE_BITRATE    = 0x0006;  // 查询通道码流
	public static final int DH_DEVSTATE_CONN     = 0x0007;  // 查询设备连接状态
	public static final int DH_DEVSTATE_PROTOCAL_VER = 0x0008;  // 查询网络协议版本号，pBuf = int*
	public static final int DH_DEVSTATE_TALK_ECTYPE  = 0x0009;  // 查询设备支持的语音对讲格式列表，见结构体DHDEV_TALKFORMAT_LIST
	public static final int DH_DEVSTATE_SD_CARD    = 0x000A;  // 查询SD卡信息(IPC类产品)
	public static final int DH_DEVSTATE_BURNING_DEV  = 0x000B;  // 查询刻录机信息
	public static final int DH_DEVSTATE_BURNING_PROGRESS= 0x000C;  // 查询刻录进度
	public static final int DH_DEVSTATE_PLATFORM   = 0x000D;  // 查询设备支持的接入平台
	public static final int DH_DEVSTATE_CAMERA     = 0x000E;  // 查询摄像头属性信息(IPC类产品)，pBuf = DHDEV_CAMERA_INFO *，可以有多个结构体
	public static final int DH_DEVSTATE_SOFTWARE   = 0x000F;  // 查询设备软件版本信息
	public static final int DH_DEVSTATE_LANGUAGE       = 0x0010;  // 查询设备支持的语音种类
	public static final int DH_DEVSTATE_DSP      = 0x0011;  // 查询DSP能力描述(对应结构体DHDEV_DSP_ENCODECAP)
	public static final int DH_DEVSTATE_OEM      = 0x0012;  // 查询OEM信息
	public static final int DH_DEVSTATE_NET      = 0x0013;  // 查询网络运行状态信息
	public static final int DH_DEVSTATE_TYPE     = 0x0014;  // 查询设备类型
	public static final int DH_DEVSTATE_SNAP     = 0x0015;  // 查询功能属性(IPC类产品)
	public static final int DH_DEVSTATE_RECORD_TIME  = 0x0016;  // 查询最早录像时间和最近录像时间
	public static final int DH_DEVSTATE_NET_RSSI       = 0x0017;  // 查询无线网络信号强度，见结构体DHDEV_WIRELESS_RSS_INFO
	public static final int DH_DEVSTATE_BURNING_ATTACH = 0x0018;  // 查询附件刻录选项
	public static final int DH_DEVSTATE_BACKUP_DEV   = 0x0019;  // 查询备份设备列表
	public static final int DH_DEVSTATE_BACKUP_DEV_INFO= 0x001a;  // 查询备份设备详细信息
	public static final int DH_DEVSTATE_BACKUP_FEEDBACK= 0x001b;  // 备份进度反馈
	public static final int DH_DEVSTATE_ATM_QUERY_TRADE = 0x001c;  // 查询ATM交易类型
	public static final int DH_DEVSTATE_SIP      = 0x001d;  // 查询sip状态
	public static final int DH_DEVSTATE_VICHILE_STATE= 0x001e;  // 查询车载wifi状态
	public static final int DH_DEVSTATE_TEST_EMAIL     = 0x001f;  // 查询邮件配置是否成功
	public static final int DH_DEVSTATE_SMART_HARD_DISK= 0x0020;  // 查询硬盘smart信息
	public static final int DH_DEVSTATE_TEST_SNAPPICTURE= 0x0021;  // 查询抓图设置是否成功
	public static final int DH_DEVSTATE_STATIC_ALARM   = 0x0022;  // 查询静态报警状态
	public static final int DH_DEVSTATE_SUBMODULE_INFO = 0x0023;  // 查询设备子模块信息
	public static final int DH_DEVSTATE_DISKDAMAGE     = 0x0024;  // 查询硬盘坏道能力 
	public static final int DH_DEVSTATE_IPC            = 0x0025;  // 查询设备支持的IPC能力, 见结构体DH_DEV_IPC_INFO
	public static final int DH_DEVSTATE_ALARM_ARM_DISARM= 0x0026;  // 查询报警布撤防状态
	public static final int DH_DEVSTATE_ACC_POWEROFF_ALARM= 0x0027;  // 查询ACC断电报警状态(返回一个DWORD, 1表示断电，0表示通电)
	public static final int DH_DEVSTATE_TEST_FTP_SERVER= 0x0028;  // 测试FTP服务器连接
	public static final int DH_DEVSTATE_3GFLOW_EXCEED  = 0x0029;  // 查询3G流量超出阈值状态,(见结构体DHDEV_3GFLOW_EXCEED_STATE_INFO)
	public static final int DH_DEVSTATE_3GFLOW_INFO    = 0x002a;  // 查询3G网络流量信息,见结构体DH_DEV_3GFLOW_INFO
	public static final int DH_DEVSTATE_VIHICLE_INFO_UPLOAD = 0x002b;  // 车载自定义信息上传(见结构体ALARM_VEHICLE_INFO_UPLOAD)
	public static final int DH_DEVSTATE_SPEED_LIMIT    = 0x002c;  // 查询限速报警状态(见结构体ALARM_SPEED_LIMIT)
	public static final int DH_DEVSTATE_DSP_EX         = 0x002d;  // 查询DSP扩展能力描述(对应结构体DHDEV_DSP_ENCODECAP_EX)
	public static final int DH_DEVSTATE_3GMODULE_INFO   = 0x002e;  // 查询3G模块信息(对应结构体DH_DEV_3GMODULE_INFO)
	public static final int DH_DEVSTATE_MULTI_DDNS     = 0x002f;  // 查询多DDNS状态信息(对应结构体DH_DEV_MULTI_DDNS_INFO)
	public static final int DH_DEVSTATE_CONFIG_URL     = 0x0030;  // 查询设备配置URL信息(对应结构体DH_DEV_URL_INFO)
	public static final int DH_DEVSTATE_HARDKEY       = 0x0031;  // 查询HardKey状态（对应结构体DHDEV_HARDKEY_STATE)
	public static final int DH_DEVSTATE_ISCSI_PATH   = 0x0032;  // 查询ISCSI路径列表(对应结构体DHDEV_ISCSI_PATHLIST)
	public static final int DH_DEVSTATE_DLPREVIEW_SLIPT_CAP  = 0x0033;  // 查询设备本地预览支持的分割模式(对应结构体DEVICE_LOCALPREVIEW_SLIPT_CAP)
	public static final int DH_DEVSTATE_WIFI_ROUTE_CAP = 0x0034;  // 查询无线路由能力信息(对应结构体DHDEV_WIFI_ROUTE_CAP)
	public static final int DH_DEVSTATE_ONLINE         = 0x0035;  // 查询设备的在线状态(返回一个DWORD, 1表示在线, 0表示断线)
	public static final int DH_DEVSTATE_PTZ_LOCATION   = 0x0036;  // 查询云台状态信息(对应结构体DH_PTZ_LOCATION_INFO)
	public static final int DH_DEVSTATE_MONITOR_INFO   = 0x0037;  // 画面监控辅助信息(对应结构体DHDEV_MONITOR_INFO)
	public static final int DH_DEVSTATE_SUBDEVICE  = 0x0300;  // 查询子设备(电源, 风扇等)状态(对应结构体CFG_DEVICESTATUS_INFO)
	public static final int DH_DEVSTATE_RAID_INFO      = 0x0038;  // 查询RAID状态(对应结构体ALARM_RAID_INFO)  
	public static final int DH_DEVSTATE_TEST_DDNSDOMAIN= 0x0039;  // 测试DDNS域名是否可用
	public static final int DH_DEVSTATE_VIRTUALCAMERA  = 0x003a;  // 查询虚拟摄像头状态(对应DHDEV_VIRTUALCAMERA_STATE_INFO)
	public static final int DH_DEVSTATE_TRAFFICWORKSTATE= 0x003b;  // 获取设备工作视频/线圈模式状态等(对应DHDEV_TRAFFICWORKSTATE_INFO)
	public static final int DH_DEVSTATE_ALARM_CAMERA_MOVE= 0x003c;  // 获取摄像机移位报警事件状态(对应ALARM_CAMERA_MOVE_INFO)
	public static final int DH_DEVSTATE_ALARM          = 0x003e;  // 获取外部报警状态(对应 NET_CLIENT_ALARM_STATE) 
	public static final int DH_DEVSTATE_VIDEOLOST      = 0x003f;  // 获取视频丢失报警状态(对应 NET_CLIENT_VIDEOLOST_STATE) 
	public static final int DH_DEVSTATE_MOTIONDETECT  = 0x0040;  // 获取动态监测报警状态(对应 NET_CLIENT_MOTIONDETECT_STATE)
	public static final int DH_DEVSTATE_DETAILEDMOTION= 0x0041;  // 获取详细的动态监测报警状态(对应 NET_CLIENT_DETAILEDMOTION_STATE)
	public static final int DH_DEVSTATE_VEHICLE_INFO  = 0x0042;  // 获取车载自身各种硬件信息(对应 DHDEV_VEHICLE_INFO)
	public static final int DH_DEVSTATE_VIDEOBLIND    = 0x0043;  // 获取视频遮挡报警状态(对应 NET_CLIENT_VIDEOBLIND_STATE)
	public static final int DH_DEVSTATE_3GSTATE_INFO  = 0x0044;  // 查询3G模块相关信息(对应结构体DHDEV_VEHICLE_3GMODULE)
	public static final int DH_DEVSTATE_NETINTERFACE  = 0x0045;  // 查询网络接口信息(对应 DHDEV_NETINTERFACE_INFO)
	public static final int DH_DEVSTATE_PICINPIC_CHN = 0x0046;  // 查询画中画通道号(对应DWORD数组)
	public static final int DH_DEVSTATE_COMPOSITE_CHN= 0x0047;  // 查询融合屏通道信息(对应DH_COMPOSITE_CHANNEL数组)
	public static final int DH_DEVSTATE_WHOLE_RECORDING= 0x0048;  // 查询设备整体录像状态(对应BOOL), 只要有一个通道在录像，即为设备整体状态为录像
	public static final int DH_DEVSTATE_WHOLE_ENCODING = 0x0049;  // 查询设备整体编码状态(对应BOOL), 只要有一个通道在编码，即为设备整体状态为编码
	public static final int DH_DEVSTATE_DISK_RECORDE_TIME= 0x004a;  // 查询设备硬盘录像时间信息(pBuf = DEV_DISK_RECORD_TIME*，可以有多个结构体)

	// 查询类型，对应CLIENT_QueryRemotDevState接口
	public static final int DH_DEVSTATE_ALARM_REMOTE  = 0x1000;  // 获取远程设备外部报警(对应 ALARM_REMOTE_ALARM_INFO)
	public static final int DH_DEVSTATE_ALARM_FRONTDISCONNECT= 0x1001;  // 获取前端IPC断网报警(对应结构体ALARM_FRONTDISCONNET_INFO)

	// 配置类型，对应CLIENT_GetDevConfig和CLIENT_SetDevConfig接口
	public static final int DH_DEV_DEVICECFG     = 0x0001;  // 设备属性配置
	public static final int DH_DEV_NETCFG      = 0x0002;  // 网络配置
	public static final int DH_DEV_CHANNELCFG    = 0x0003;  // 图象通道配置
	public static final int DH_DEV_PREVIEWCFG      = 0x0004;  // 预览参数配置
	public static final int DH_DEV_RECORDCFG     = 0x0005;  // 录像配置
	public static final int DH_DEV_COMMCFG       = 0x0006;  // 串口属性配置
	public static final int DH_DEV_ALARMCFG      = 0x0007;  // 报警属性配置
	public static final int DH_DEV_TIMECFG       = 0x0008;  // DVR时间配置
	public static final int DH_DEV_TALKCFG       = 0x0009;  // 对讲参数配置
	public static final int DH_DEV_AUTOMTCFG     = 0x000A;  // 自动维护配置   
	public static final int DH_DEV_VEDIO_MARTIX    = 0x000B;  // 本机矩阵控制策略配置 
	public static final int DH_DEV_MULTI_DDNS    = 0x000C;  // 多ddns服务器配置
	public static final int DH_DEV_SNAP_CFG      = 0x000D;  // 抓图相关配置
	public static final int DH_DEV_WEB_URL_CFG     = 0x000E;  // HTTP路径配置
	public static final int DH_DEV_FTP_PROTO_CFG   = 0x000F;  // FTP上传配置
	public static final int DH_DEV_INTERVIDEO_CFG  = 0x0010;  // 平台接入配置，此时channel参数代表平台类型，
	;  // channel=4： 代表贝尔阿尔卡特；channel=10：代表中兴力维；channel=11：代表U网通；channel=51：代表天地阳光
	public static final int DH_DEV_VIDEO_COVER     = 0x0011;  // 区域遮挡配置
	public static final int DH_DEV_TRANS_STRATEGY  = 0x0012;  // 传输策略配置，画质优先\流畅性优先
	public static final int DH_DEV_DOWNLOAD_STRATEGY = 0x0013;  // 录象下载策略配置，高速下载\普通下载
	public static final int DH_DEV_WATERMAKE_CFG   = 0x0014;  // 图象水印配置
	public static final int DH_DEV_WLAN_CFG      = 0x0015;  // 无线网络配置
	public static final int DH_DEV_WLAN_DEVICE_CFG   = 0x0016;  // 搜索无线设备配置
	public static final int DH_DEV_REGISTER_CFG    = 0x0017;  // 主动注册参数配置
	public static final int DH_DEV_CAMERA_CFG    = 0x0018;  // 摄像头属性配置
	public static final int DH_DEV_INFRARED_CFG    = 0x0019;  // 红外报警配置
	public static final int DH_DEV_SNIFFER_CFG     = 0x001A;  // Sniffer抓包配置
	public static final int DH_DEV_MAIL_CFG      = 0x001B;  // 邮件配置
	public static final int DH_DEV_DNS_CFG       = 0x001C;  // DNS服务器配置
	public static final int DH_DEV_NTP_CFG       = 0x001D;  // NTP配置
	public static final int DH_DEV_AUDIO_DETECT_CFG  = 0x001E;  // 音频检测配置
	public static final int DH_DEV_STORAGE_STATION_CFG = 0x001F;  // 存储位置配置
	public static final int DH_DEV_PTZ_OPT_CFG     = 0x0020;  // 云台操作属性(已经废除，请使用CLIENT_GetPtzOptAttr获取云台操作属性)
	public static final int DH_DEV_DST_CFG       = 0x0021;  // 夏令时配置
	public static final int DH_DEV_ALARM_CENTER_CFG  = 0x0022;  // 报警中心配置
	public static final int DH_DEV_VIDEO_OSD_CFG       = 0x0023;  // 视频OSD叠加配置
	public static final int DH_DEV_CDMAGPRS_CFG        = 0x0024;  // CDMA\GPRS网络配置

	public static final int DH_DEV_IPFILTER_CFG        = 0x0025;  // IP过滤配置
	public static final int DH_DEV_TALK_ENCODE_CFG     = 0x0026;  // 语音对讲编码配置
	public static final int DH_DEV_RECORD_PACKET_CFG  = 0x0027;  // 录像打包长度配置
	public static final int DH_DEV_MMS_CFG            = 0x0028;  // 短信MMS配置 
	public static final int DH_DEV_SMSACTIVATION_CFG= 0x0029;  // 短信激活无线连接配置
	public static final int DH_DEV_DIALINACTIVATION_CFG = 0x002A;  // 拨号激活无线连接配置
	public static final int DH_DEV_SNIFFER_CFG_EX  = 0x0030;  // 网络抓包配置
	public static final int DH_DEV_DOWNLOAD_RATE_CFG = 0x0031;  // 下载速度限制
	public static final int DH_DEV_PANORAMA_SWITCH_CFG = 0x0032;  // 全景切换报警配置
	public static final int DH_DEV_LOST_FOCUS_CFG  = 0x0033;  // 失去焦点报警配置
	public static final int DH_DEV_ALARM_DECODE_CFG  = 0x0034;  // 报警解码器配置
	public static final int DH_DEV_VIDEOOUT_CFG        = 0x0035;  // 视频输出参数配置
	public static final int DH_DEV_POINT_CFG     = 0x0036;  // 预制点使能配置
	public static final int DH_DEV_IP_COLLISION_CFG    = 0x0037;  // Ip冲突检测报警配置
	public static final int DH_DEV_OSD_ENABLE_CFG  = 0x0038;  // OSD叠加使能配置
	public static final int DH_DEV_LOCALALARM_CFG    = 0x0039;  // 本地报警配置(结构体DH_ALARMIN_CFG_EX)
	public static final int DH_DEV_NETALARM_CFG    = 0x003A;  // 网络报警配置(结构体DH_ALARMIN_CFG_EX)
	public static final int DH_DEV_MOTIONALARM_CFG   = 0x003B;  // 动检报警配置(结构体DH_MOTION_DETECT_CFG_EX)
	public static final int DH_DEV_VIDEOLOSTALARM_CFG  = 0x003C;  // 视频丢失报警配置(结构体DH_VIDEO_LOST_CFG_EX)
	public static final int DH_DEV_BLINDALARM_CFG    = 0x003D;  // 视频遮挡报警配置(结构体DH_BLIND_CFG_EX)
	public static final int DH_DEV_DISKALARM_CFG   = 0x003E;  // 硬盘报警配置(结构体DH_DISK_ALARM_CFG_EX)
	public static final int DH_DEV_NETBROKENALARM_CFG  = 0x003F;  // 网络中断报警配置(结构体DH_NETBROKEN_ALARM_CFG_EX)
	public static final int DH_DEV_ENCODER_CFG         = 0x0040;  // 数字通道的前端编码器信息（混合DVR使用，结构体DEV_ENCODER_CFG）
	public static final int DH_DEV_TV_ADJUST_CFG       = 0x0041;  // TV调节配置（channel代表TV号(0开始)，类型结构体）
	public static final int DH_DEV_ABOUT_VEHICLE_CFG = 0x0042;  // 车载相关配置，北京公交使用
	public static final int DH_DEV_ATM_OVERLAY_ABILITY = 0x0043;  // 获取atm叠加支持能力信息
	public static final int DH_DEV_ATM_OVERLAY_CFG   = 0x0044;  // atm叠加配置，新atm特有
	public static final int DH_DEV_DECODER_TOUR_CFG  = 0x0045;  // 解码器解码轮巡配置
	public static final int DH_DEV_SIP_CFG       = 0x0046;  // SIP配置
	public static final int DH_DEV_VICHILE_WIFI_AP_CFG = 0x0047;  // wifi ap配置
	public static final int DH_DEV_STATICALARM_CFG     = 0x0048;  // 静态报警配置 
	public static final int DH_DEV_DECODE_POLICY_CFG   = 0x0049;  // 设备的解码策略配置(结构体DHDEV_DECODEPOLICY_CFG，channel为解码通道0开始) 
	public static final int DH_DEV_MACHINE_CFG     = 0x004A;  // 机器相关的配置(结构体DHDEV_MACHINE_CFG)
	public static final int DH_DEV_MAC_COLLISION_CFG   = 0x004B;  // MAC冲突检测配置(结构体ALARM_MAC_COLLISION_CFG)
	public static final int DH_DEV_RTSP_CFG            = 0x004C;  // RTSP配置(对应结构体DHDEV_RTSP_CFG)
	public static final int DH_DEV_232_COM_CARD_CFG    = 0x004E;  // 232串口卡号信号事件配置(对应结构体COM_CARD_SIGNAL_LINK_CFG)
	public static final int DH_DEV_485_COM_CARD_CFG    = 0x004F;  // 485串口卡号信号事件配置(对应结构体COM_CARD_SIGNAL_LINK_CFG)
	public static final int DH_DEV_FTP_PROTO_CFG_EX  = 0x0050;  // FTP上传扩展配置(对应结构体DHDEV_FTP_PROTO_CFG_EX)
	public static final int DH_DEV_SYSLOG_REMOTE_SERVER= 0x0051;  // SYSLOG 远程服务器配置(对应结构体DHDEV_SYSLOG_REMOTE_SERVER)
	public static final int DH_DEV_COMMCFG_EX          = 0x0052;  // 扩展串口属性配置(对应结构体DHDEV_COMM_CFG_EX)            
	public static final int DH_DEV_NETCARD_CFG         = 0x0053;  // 卡口信息配置(对应结构体DHDEV_NETCARD_CFG)
	public static final int DH_DEV_BACKUP_VIDEO_FORMAT = 0x0054;  // 视频备份格式配置(对应结构体DHDEV_BACKUP_VIDEO_FORMAT)
	public static final int DH_DEV_STREAM_ENCRYPT_CFG  = 0x0055;  // 码流加密配置(对应结构体DHEDV_STREAM_ENCRYPT)
	public static final int DH_DEV_IPFILTER_CFG_EX     = 0x0056;  // IP过滤配置扩展(对应结构体DHDEV_IPIFILTER_CFG_EX)
	public static final int DH_DEV_CUSTOM_CFG          = 0x0057;  // 用户自定义配置(对应结构体DHDEV_CUSTOM_CFG)
	public static final int DH_DEV_WLAN_DEVICE_CFG_EX  = 0x0058;  // 搜索无线设备扩展配置(对应结构体DHDEV_WLAN_DEVICE_LIST_EX)
	public static final int DH_DEV_ACC_POWEROFF_CFG    = 0x0059;  // ACC断线事件配置(对应结构体DHDEV_ACC_POWEROFF_CFG)
	public static final int DH_DEV_EXPLOSION_PROOF_CFG = 0x005a;  // 防爆盒报警事件配置(对应结构体DHDEV_EXPLOSION_PROOF_CFG)
	public static final int DH_DEV_NETCFG_EX     = 0x005b;  // 网络扩展配置(对应结构体DHDEV_NET_CFG_EX)
	public static final int DH_DEV_LIGHTCONTROL_CFG    = 0x005c;  // 灯光控制配置(对应结构体DHDEV_LIGHTCONTROL_CFG)
	public static final int DH_DEV_3GFLOW_CFG          = 0x005d;  // 3G流量信息配置(对应结构体DHDEV_3GFLOW_INFO_CFG)
	public static final int DH_DEV_IPV6_CFG            = 0x005e;  // IPv6配置(对应结构体DHDEV_IPV6_CFG)
	public static final int DH_DEV_SNMP_CFG           = 0x005f;  // Snmp配置(对应结构体DHDEV_NET_SNMP_CFG), 设置完成后需要重启设备
	public static final int DH_DEV_SNAP_CONTROL_CFG    = 0x0060;  // 抓图开关配置(对应结构体DHDEV_SNAP_CONTROL_CFG)
	public static final int DH_DEV_GPS_MODE_CFG       = 0x0061;  // GPS定位模式配置(对应结构体DHDEV_GPS_MODE_CFG)
	public static final int DH_DEV_SNAP_UPLOAD_CFG    = 0x0062;  // 图片上传配置信息(对应结构体 DHDEV_SNAP_UPLOAD_CFG)
	public static final int DH_DEV_SPEED_LIMIT_CFG     = 0x0063;  // 限速配置信息(对应结构体DHDEV_SPEED_LIMIT_CFG)
	public static final int DH_DEV_ISCSI_CFG     = 0x0064;  // iSCSI配置(对应结构体DHDEV_ISCSI_CFG), 设置完成后需要重启设备
	public static final int DH_DEV_WIRELESS_ROUTING_CFG= 0x0065;  // 无线路由配置(对应结构体DHDEV_WIRELESS_ROUTING_CFG)
	public static final int DH_DEV_ENCLOSURE_CFG       = 0x0066;  // 电子围栏配置(对应结构体DHDEV_ENCLOSURE_CFG)
	public static final int DH_DEV_ENCLOSURE_VERSION_CFG= 0x0067;  // 电子围栏版本号配置(对应结构体DHDEV_ENCLOSURE_VERSION_CFG)
	public static final int DH_DEV_RIAD_EVENT_CFG       = 0x0068;  // Raid事件配置(对应结构体DHDEV_RAID_EVENT_CFG)
	public static final int DH_DEV_FIRE_ALARM_CFG       = 0x0069;  // 火警报警配置(对应结构体DHDEV_FIRE_ALARM_CFG)
	public static final int DH_DEV_LOCALALARM_NAME_CFG  = 0x006a;  // 本地名称报警配置(对应Name1&&name2&&name3...格式字符串)
	public static final int DH_DEV_URGENCY_RECORD_CFG   = 0x0070;  // 紧急存储配置(对应结构体DHDEV_URGENCY_RECORD_CFG)
	public static final int DH_DEV_ELEVATOR_ATTRI_CFG   = 0x0071;  // 电梯运行参数配置(对应结构体DHDEV_ELEVATOR_ATTRI_CFG)
	public static final int DH_DEV_ATM_OVERLAY_CFG_EX = 0x0072;  // atm叠加配置，新atm特有,支持大于32通道的设备(对应结构体DHDEV_ATM_OVERLAY_CONFIG_EX)
	public static final int DH_DEV_MACFILTER_CFG    = 0x0073;  // MAC过滤配置(对应结构体DHDEV_MACFILTER_CFG)
	public static final int DH_DEV_MACIPFILTER_CFG    = 0x0074;  // MAC,IP过滤(要求ip,mac是一一对应的)配置(对应结构体DHDEV_MACIPFILTER_CFG)
	public static final int DH_DEV_STREAM_ENCRYPT_TIME_CFG= 0x0075;  // 码流加密(加密计划)配置(对应结构体DHEDV_STREAM_ENCRYPT)
	public static final int DH_DEV_LIMIT_BIT_RATE_CFG   = 0x0076;  // 限码流配置(对应结构体 DHDEV_LIMIT_BIT_RATE) 
	public static final int DH_DEV_SNAP_CFG_EX      = 0x0077;  // 抓图相关配置扩展(对应结构体 DHDEV_SNAP_CFG_EX)
	public static final int DH_DEV_DECODER_URL_CFG   = 0x0078;  // 解码器url配置(对应结构体DHDEV_DECODER_URL_CFG)
	public static final int DH_DEV_TOUR_ENABLE_CFG   = 0x0079;  // 轮巡使能配置(对应结构体DHDEV_TOUR_ENABLE_CFG)
	public static final int DH_DEV_VICHILE_WIFI_AP_CFG_EX= 0x007a;  // wifi ap配置扩展(对应结构体DHDEV_VEHICLE_WIFI_AP_CFG_EX)
	public static final int DH_DEV_USER_END_CFG     =1000;

	// 报警类型，对应CLIENT_StartListen接口
	public static final int DH_COMM_ALARM      = 0x1100;  // 常规报警(包括外部报警，视频丢失，动态检测)
	public static final int DH_SHELTER_ALARM     = 0x1101;  // 视频遮挡报警
	public static final int DH_DISK_FULL_ALARM     = 0x1102;  // 硬盘满报警
	public static final int DH_DISK_ERROR_ALARM    = 0x1103;  // 硬盘故障报警
	public static final int DH_SOUND_DETECT_ALARM  = 0x1104;  // 音频检测报警
	public static final int DH_ALARM_DECODER_ALARM   = 0x1105;  // 报警解码器报警

	// 扩展报警类型，对应CLIENT_StartListenEx接口
	public static final int DH_ALARM_ALARM_EX    = 0x2101;  // 外部报警
	public static final int DH_MOTION_ALARM_EX     = 0x2102;  // 动态检测报警
	public static final int DH_VIDEOLOST_ALARM_EX  = 0x2103;  // 视频丢失报警
	public static final int DH_SHELTER_ALARM_EX    = 0x2104;  // 视频遮挡报警
	public static final int DH_SOUND_DETECT_ALARM_EX = 0x2105;  // 音频检测报警
	public static final int DH_DISKFULL_ALARM_EX   = 0x2106;  // 硬盘满报警
	public static final int DH_DISKERROR_ALARM_EX  = 0x2107;  // 坏硬盘报警
	public static final int DH_ENCODER_ALARM_EX    = 0x210A;  // 编码器报警
	public static final int DH_URGENCY_ALARM_EX    = 0x210B;  // 紧急报警
	public static final int DH_WIRELESS_ALARM_EX   = 0x210C;  // 无线报警
	public static final int DH_NEW_SOUND_DETECT_ALARM_EX= 0x210D;  // 新音频检测报警，报警信息的结构体见DH_NEW_SOUND_ALARM_STATE；
	public static final int DH_ALARM_DECODER_ALARM_EX= 0x210E;  // 报警解码器报警
	public static final int DH_DECODER_DECODE_ABILITY= 0x210F;  // 解码器：解码能力报警
	public static final int DH_FDDI_DECODER_ABILITY  = 0x2110;  // 光纤编码器状态报警
	public static final int DH_PANORAMA_SWITCH_ALARM_EX= 0x2111;  // 切换场景报警
	public static final int DH_LOSTFOCUS_ALARM_EX  = 0x2112;  // 失去焦点报警
	public static final int DH_OEMSTATE_EX       = 0x2113;  // oem报停状态
	public static final int DH_DSP_ALARM_EX      = 0x2114;  // DSP报警
	public static final int DH_ATMPOS_BROKEN_EX    = 0x2115;  // atm和pos机断开报警， 0：连接断开 1：连接正常
	public static final int DH_RECORD_CHANGED_EX   = 0x2116;  // 录像状态变化报警
	public static final int DH_CONFIG_CHANGED_EX   = 0x2117;  // 配置发生变化报警
	public static final int DH_DEVICE_REBOOT_EX    = 0x2118;  // 设备重启报警
	public static final int DH_WINGDING_ALARM_EX       = 0x2119;  // 线圈/车检器故障报警
	public static final int DH_TRAF_CONGESTION_ALARM_EX= 0x211A;  // 交通阻塞报警(车辆出现异常停止或者排队)
	public static final int DH_TRAF_EXCEPTION_ALARM_EX = 0x211B;  // 交通异常报警(交通流量趋于0或异常空闲)
	public static final int DH_EQUIPMENT_FILL_ALARM_EX = 0x211C;  // 补光设备故障报警
	public static final int DH_ALARM_ARM_DISARM_STATE= 0x211D;  // 报警布撤防状态
	public static final int DH_ALARM_ACC_POWEROFF      = 0x211E;  // ACC断电报警
	public static final int DH_ALARM_3GFLOW_EXCEED     = 0x211F;  // 3G流量超出阈值报警(报警信息的结构体见结构体DHDEV_3GFLOW_EXCEED_STATE_INFO)
	public static final int DH_ALARM_SPEED_LIMIT       = 0x2120;  // 限速报警
	public static final int DH_ALARM_VEHICLE_INFO_UPLOAD = 0x2121;  // 车载自定义信息上传 
	public static final int DH_STATIC_ALARM_EX         = 0x2122;  // 静态检测报警
	public static final int DH_PTZ_LOCATION_EX         = 0x2123;  // 云台定位信息
	public static final int DH_ALARM_CARD_RECORD_UPLOAD= 0x2124;  // 卡号录像信息上传(对应结构体 ALARM_CARD_RECORD_INFO_UPLOAD)
	public static final int DH_ALARM_ATM_INFO_UPLOAD = 0x2125;  // ATM交易信息上传(对应结构体 ALARM_ATM_INFO_UPLOAD)
	public static final int DH_ALARM_ENCLOSURE         = 0x2126;  // 电子围栏报警(对应结构体ALARM_ENCLOSURE_INFO)
	public static final int DH_ALARM_SIP_STATE         = 0x2127;  // SIP状态报警(对应结构体ALARM_SIP_STATE)
	public static final int DH_ALARM_RAID_STATE        = 0x2128;  // RAID异常报警(对应结构体ALARM_RAID_INFO)
	public static final int DH_ALARM_CROSSING_SPEED_LIMIT= 0x2129;  // 路口限速报警(对应结构体ALARM_SPEED_LIMIT)
	public static final int DH_ALARM_OVER_LOADING        = 0x212A;  // 超载报警(对应结构体ALARM_OVER_LOADING)
	public static final int DH_ALARM_HARD_BRAKING        = 0x212B;  // 急刹车报警(对应机构体ALARM_HARD_BRAKING)
	public static final int DH_ALARM_SMOKE_SENSOR        = 0x212C;  // 烟感报警(对应结构体ALARM_SMOKE_SENSOR)
	public static final int DH_ALARM_TRAFFIC_LIGHT_FAULT= 0x212D;  // 交通灯故障报警(对应结构体ALARM_TRAFFIC_LIGHT_FAULT) 
	public static final int DH_ALARM_TRAFFIC_FLUX_STAT  = 0x212E;  // 交通流量统计报警(对应结构体ALARM_TRAFFIC_FLUX_LANE_INFO)
	public static final int DH_ALARM_CAMERA_MOVE        = 0x212F;  // 摄像机移位报警事件(对应结构体ALARM_CAMERA_MOVE_INFO)
	public static final int DH_ALARM_DETAILEDMOTION     = 0x2130;  // 详细动检报警上报信息(对应结构体ALARM_DETAILEDMOTION_CHNL_INFO)
	public static final int DH_ALARM_STORAGE_FAILURE     = 0x2131;  // 存储异常报警(对应结构体ALARM_STORAGE_FAILURE数组)
	public static final int DH_ALARM_FRONTDISCONNECT    = 0x2132;  // 前端IPC断网报警(对应结构体ALARM_FRONTDISCONNET_INFO)
	public static final int DH_ALARM_ALARM_EX_REMOTE    = 0x2133;  // 远程外部报警(对应结构体 ALARM_REMOTE_ALARM_INFO)
	public static final int DH_ALARM_BATTERYLOWPOWER    = 0x2134;  // 电池电量低报警(对应结构体ALARM_BATTERYLOWPOWER_INFO)
	public static final int DH_ALARM_TEMPERATURE        = 0x2135;  // 温度过高报警(对应结构体ALARM_TEMPERATURE_INFO)
	public static final int DH_ALARM_TIREDDRIVE         = 0x2136;  // 疲劳驾驶报警(对应结构体ALARM_TIREDDRIVE_INFO)
	public static final int DH_ALARM_LOST_RECORD        = 0x2137;  // 丢录像事件报警(对应结构体ALARM_LOST_RECORD)
	public static final int DH_ALARM_HIGH_CPU           = 0x2138;  // CPU占用率过高事件报警(对应结构体ALARM_HIGH_CPU)
	public static final int DH_ALARM_LOST_NETPACKET     = 0x2139;  // 网络发送数据丢包事件报警(对应结构体ALARM_LOST_NETPACKET)
	public static final int DH_ALARM_HIGH_MEMORY        = 0x213A;  // 内存占用率过高事件报警(对应结构体ALARM_HIGH_MEMORY)
	public static final int DH_LONG_TIME_NO_OPERATION = 0x213B;  // WEB用户长时间无操作事件（无扩展信息）
	public static final int DH_BLACKLIST_SNAP           = 0x213C;  // 黑名单车辆抓拍事件(对应结构体DH_BLACKLIST_SNAP_INFO)         
	public static final int DH_ALARM_DISK       = 0x213E;  // 硬盘报警(对应ALARM_DISK_INFO数组)
	public static final int DH_ALARM_FILE_SYSTEM    = 0x213F;  // 文件系统报警(对应ALARM_FILE_SYSTEM_INFO数组)
	public static final int DH_ALARM_IVS                = 0x2140;  // 智能报警事件(对应结构体ALARM_IVS_INFO)
	public static final int DH_ALARM_GOODS_WEIGHT_UPLOAD= 0x2141;  // 货重信息上报(对应ALARM_GOODS_WEIGHT_UPLOAD_INFO)
	public static final int DH_ALARM_GOODS_WEIGHT   = 0x2142;  // 货重信息报警(对应ALARM_GOODS_WEIGHT_INFO)
	public static final int DH_GPS_STATUS               = 0x2143;  // GPS定位信息(对应 NET_GPS_STATUS_INFO)
	public static final int DH_ALARM_DISKBURNED_FULL    = 0x2144;  // 硬盘刻录满报警(对应 ALARM_DISKBURNED_FULL_INFO)
	public static final int DH_ALARM_STORAGE_LOW_SPACE  = 0x2145;  // 存储容量不足事件(对应ALARM_STORAGE_LOW_SPACE_INFO)

	// 事件类型
	public static final int DH_CONFIG_RESULT_EVENT_EX= 0x3000;  // 修改配置的返回码；返回结构见DEV_SET_RESULT
	public static final int DH_REBOOT_EVENT_EX     = 0x3001;  // 设备重启事件；如果未发送重启命令，当前修改的配置不会立即生效
	public static final int DH_AUTO_TALK_START_EX  = 0x3002;  // 设备主动邀请开始语音对讲
	public static final int DH_AUTO_TALK_STOP_EX   = 0x3003;  // 设备主动停止语音对讲
	public static final int DH_CONFIG_CHANGE_EX    = 0x3004;  // 设备配置发生改变
	public static final int DH_IPSEARCH_EVENT_EX       = 0x3005;  // IP搜索事件, 返回字符串格式如下:DevName::Manufacturer::MAC::IP::Port::DevType::POEPort::SubMask::GateWay&&DevName::Manufacturer::MAC::IP::Port::DevType::POEPort::SubMask::GateWay &&…
	public static final int DH_AUTO_RECONNECT_FAILD    = 0x3006;  // 自动重连失败事件
	public static final int DH_REALPLAY_FAILD_EVENT    = 0x3007;  // 监视失败事件,返回结构体DEV_PLAY_RESULT
	public static final int DH_PLAYBACK_FAILD_EVENT    = 0x3008;  // 回放失败事件,返回结构体DEV_PLAY_RESULT   
	public static final int DH_IVS_TRAFFIC_REALFLOWINFO= 0x3009;  // 交通实时流量信息事件ALARM_IVS_TRAFFIC_REALFLOW_INFO


	// 报警上传功能的报警类型，对应CLIENT_StartService接口、NEW_ALARM_UPLOAD结构体.
	public static final int DH_UPLOAD_ALARM      = 0x4000;  // 外部报警   
	public static final int DH_UPLOAD_MOTION_ALARM   = 0x4001;  // 动态检测报警
	public static final int DH_UPLOAD_VIDEOLOST_ALARM= 0x4002;  // 视频丢失报警
	public static final int DH_UPLOAD_SHELTER_ALARM  = 0x4003;  // 视频遮挡报警
	public static final int DH_UPLOAD_SOUND_DETECT_ALARM= 0x4004;  // 音频检测报警
	public static final int DH_UPLOAD_DISKFULL_ALARM = 0x4005;  // 硬盘满报警
	public static final int DH_UPLOAD_DISKERROR_ALARM= 0x4006;  // 坏硬盘报警
	public static final int DH_UPLOAD_ENCODER_ALARM  = 0x4007;  // 编码器报警
	public static final int DH_UPLOAD_DECODER_ALARM  = 0x400B;  // 报警解码器报警
	public static final int DH_UPLOAD_EVENT      = 0x400C;  // 定时上传的
	public static final int DH_UPLOAD_IVS      = 0x400D;  // 智能报警, 对讲结构体ALARM_UPLOAD_IVS_INFO

	// 异步接口回调类型
	public static final int RESPONSE_DECODER_CTRL_TV = 0x00000001;  // 对应CLIENT_CtrlDecTVScreen接口
	public static final int RESPONSE_DECODER_SWITCH_TV = 0x00000002;  // 对应CLIENT_SwitchDecTVEncoder接口
	public static final int RESPONSE_DECODER_PLAYBACK= 0x00000003;  // 对应CLIENT_DecTVPlayback接口

	// CLIENT_FileTransmit接口传输文件类型
	public static final int DH_DEV_UPGRADEFILETRANS_START= 0x0000;  // 开始升级文件上传(对应结构体 DHDEV_UPGRADE_FILE_INFO)
	public static final int DH_DEV_UPGRADEFILETRANS_SEND = 0x0001;  // 发送升级文件  
	public static final int DH_DEV_UPGRADEFILETRANS_STOP = 0x0002;  // 停止发送升级文件
	public static final int DH_DEV_BLACKWHITETRANS_START = 0x0003;  // 开始发送黑白名单(对应结构体DHDEV_BLACKWHITE_LIST_INFO)
	public static final int DH_DEV_BLACKWHITETRANS_SEND  = 0x0004;  // 发送黑白名单
	public static final int DH_DEV_BLACKWHITETRANS_STOP  = 0x0005;  // 停止发送黑白名单 
	public static final int DH_DEV_BLACKWHITE_LOAD       = 0x0006;  // 下载黑白名单(对应结构体DHDEV_LOAD_BLACKWHITE_LIST_INFO)
	public static final int DH_DEV_BLACKWHITE_LOAD_STOP  = 0x0007;  // 停止下载黑白名单
	public static final int DH_DEV_FILETRANS_STOP    = 0x002B;  // 停止文件上传
	public static final int DH_DEV_FILETRANS_BURN    = 0x002C;  // 刻录文件上传


	// 分辨率列表，用于与分辨率掩码进行与、或操作
	public static final int DH_CAPTURE_SIZE_D1     = 0x00000001;
	public static final int DH_CAPTURE_SIZE_HD1    = 0x00000002;
	public static final int DH_CAPTURE_SIZE_BCIF   = 0x00000004;
	public static final int DH_CAPTURE_SIZE_CIF    = 0x00000008;
	public static final int DH_CAPTURE_SIZE_QCIF   = 0x00000010;
	public static final int DH_CAPTURE_SIZE_VGA    = 0x00000020;
	public static final int DH_CAPTURE_SIZE_QVGA   = 0x00000040;
	public static final int DH_CAPTURE_SIZE_SVCD   = 0x00000080;
	public static final int DH_CAPTURE_SIZE_QQVGA  = 0x00000100;
	public static final int DH_CAPTURE_SIZE_SVGA   = 0x00000200;
	public static final int DH_CAPTURE_SIZE_XVGA   = 0x00000400;
	public static final int DH_CAPTURE_SIZE_WXGA   = 0x00000800;
	public static final int DH_CAPTURE_SIZE_SXGA   = 0x00001000;
	public static final int DH_CAPTURE_SIZE_WSXGA  = 0x00002000;
	public static final int DH_CAPTURE_SIZE_UXGA   = 0x00004000;
	public static final int DH_CAPTURE_SIZE_WUXGA      = 0x00008000;
	public static final int DH_CAPTURE_SIZE_LFT        = 0x00010000;
	public static final int DH_CAPTURE_SIZE_720      = 0x00020000;
	public static final int DH_CAPTURE_SIZE_1080   = 0x00040000;
	public static final int DH_CAPTURE_SIZE_1_3M   = 0x00080000;
	public static final int DH_CAPTURE_SIZE_2M     = 0x00100000;
	public static final int DH_CAPTURE_SIZE_5M     = 0x00200000;
	public static final int DH_CAPTURE_SIZE_3M     = 0x00400000;
	public static final int DH_CAPTURE_SIZE_5_0M       = 0x00800000;
	public static final int DH_CPTRUTE_SIZE_1_2M   = 0x01000000;
	public static final int DH_CPTRUTE_SIZE_1408_1024  = 0x02000000;
	public static final int DH_CPTRUTE_SIZE_8M         = 0x04000000;
	public static final int DH_CPTRUTE_SIZE_2560_1920  = 0x08000000;
	public static final int DH_CAPTURE_SIZE_960H       = 0x10000000;
	public static final int DH_CAPTURE_SIZE_960_720    = 0x20000000;

	// 编码模式列表，用于与编码模式掩码进行与、或操作
	public static final int DH_CAPTURE_COMP_DIVX_MPEG4 = 0x00000001;
	public static final int DH_CAPTURE_COMP_MS_MPEG4 = 0x00000002;
	public static final int DH_CAPTURE_COMP_MPEG2  = 0x00000004;
	public static final int DH_CAPTURE_COMP_MPEG1  = 0x00000008;
	public static final int DH_CAPTURE_COMP_H263   = 0x00000010;
	public static final int DH_CAPTURE_COMP_MJPG   = 0x00000020;
	public static final int DH_CAPTURE_COMP_FCC_MPEG4= 0x00000040;
	public static final int DH_CAPTURE_COMP_H264   = 0x00000080;

	// 报警联动动作，用于与报警联动动作掩码进行与、或操作
	public static final int DH_ALARM_UPLOAD      = 0x00000001;
	public static final int DH_ALARM_RECORD      = 0x00000002;
	public static final int DH_ALARM_PTZ       = 0x00000004;
	public static final int DH_ALARM_MAIL      = 0x00000008;
	public static final int DH_ALARM_TOUR      = 0x00000010;
	public static final int DH_ALARM_TIP       = 0x00000020;
	public static final int DH_ALARM_OUT       = 0x00000040;
	public static final int DH_ALARM_FTP_UL      = 0x00000080;
	public static final int DH_ALARM_BEEP      = 0x00000100;
	public static final int DH_ALARM_VOICE       = 0x00000200;
	public static final int DH_ALARM_SNAP      = 0x00000400;

	// "恢复默认配置"掩码，可进行与、或操作
	public static final int DH_RESTORE_COMMON    = 0x00000001;  // 普通设置
	public static final int DH_RESTORE_CODING    = 0x00000002;  // 编码设置
	public static final int DH_RESTORE_VIDEO     = 0x00000004;  // 录像设置
	public static final int DH_RESTORE_COMM      = 0x00000008;  // 串口设置
	public static final int DH_RESTORE_NETWORK     = 0x00000010;  // 网络设置
	public static final int DH_RESTORE_ALARM     = 0x00000020;  // 报警设置
	public static final int DH_RESTORE_VIDEODETECT   = 0x00000040;  // 视频检测
	public static final int DH_RESTORE_PTZ       = 0x00000080;  // 云台控制
	public static final int DH_RESTORE_OUTPUTMODE  = 0x00000100;  // 输出模式
	public static final int DH_RESTORE_CHANNELNAME   = 0x00000200;  // 通道名称
	public static final int DH_RESTORE_VIDEOINOPTIONS  = 0x00000400;  // 摄像头属性
	public static final int DH_RESTORE_CPS             = 0x00000800;  // 智能交通
	public static final int DH_RESTORE_INTELLIGENT     = 0x00001000;  // 视频分析
	public static final int DH_RESTORE_REMOTEDEVICE    = 0x00002000;  // 远程设备配置
	public static final int DH_RESTORE_DECODERVIDEOOUT = 0x00004000;  // 解码轮巡
	public static final int DH_RESTORE_LINKMODE        = 0x00008000;  // 连接模式
	public static final int DH_RESTORE_COMPOSITE       = 0x00010000;  // 融合屏    
	public static final int DH_RESTORE_ALL       = 0x80000000;  // 全部重置

	// 云台属性列表
	// 低四个字节掩码
	public static final int PTZ_DIRECTION      = 0x00000001;  // 方向
	public static final int PTZ_ZOOM         = 0x00000002;  // 变倍
	public static final int PTZ_FOCUS        = 0x00000004;  // 聚焦
	public static final int PTZ_IRIS         = 0x00000008;  // 光圈
	public static final int PTZ_ALARM        = 0x00000010;  // 报警功能
	public static final int PTZ_LIGHT        = 0x00000020;  // 灯光
	public static final int PTZ_SETPRESET      = 0x00000040;  // 设置预置点
	public static final int PTZ_CLEARPRESET      = 0x00000080;  // 清除预置点
	public static final int PTZ_GOTOPRESET       = 0x00000100;  // 转至预置点
	public static final int PTZ_AUTOPANON      = 0x00000200;  // 水平开始
	public static final int PTZ_AUTOPANOFF       = 0x00000400;  // 水平结束
	public static final int PTZ_SETLIMIT       = 0x00000800;  // 设置边界
	public static final int PTZ_AUTOSCANON       = 0x00001000;  // 自动扫描开始
	public static final int PTZ_AUTOSCANOFF      = 0x00002000;  // 自动扫描开停止
	public static final int PTZ_ADDTOUR        = 0x00004000;  // 增加巡航点
	public static final int PTZ_DELETETOUR       = 0x00008000;  // 删除巡航点
	public static final int PTZ_STARTTOUR      = 0x00010000;  // 开始巡航
	public static final int PTZ_STOPTOUR       = 0x00020000;  // 结束巡航
	public static final int PTZ_CLEARTOUR      = 0x00040000;  // 删除巡航
	public static final int PTZ_SETPATTERN       = 0x00080000;  // 设置模式
	public static final int PTZ_STARTPATTERN     = 0x00100000;  // 开始模式
	public static final int PTZ_STOPPATTERN      = 0x00200000;  // 停止模式
	public static final int PTZ_CLEARPATTERN     = 0x00400000;  // 清除模式
	public static final int PTZ_POSITION       = 0x00800000;  // 快速定位
	public static final int PTZ_AUX          = 0x01000000;  // 辅助开关
	public static final int PTZ_MENU         = 0x02000000;  // 球机菜单
	public static final int PTZ_EXIT         = 0x04000000;  // 退出球机菜单
	public static final int PTZ_ENTER        = 0x08000000;  // 确认
	public static final int PTZ_ESC          = 0x10000000;  // 取消
	public static final int PTZ_MENUUPDOWN       = 0x20000000;  // 菜单上下操作
	public static final int PTZ_MENULEFTRIGHT    = 0x40000000;  // 菜单左右操作
	public static final int PTZ_OPT_NUM        = 0x80000000;  // 操作的个数
	// 高四个字节掩码
	public static final int PTZ_DEV          = 0x00000001;  // 云台控制
	public static final int PTZ_MATRIX         = 0x00000002;  // 矩阵控制

	// 抓图视频编码类型
	public static final int CODETYPE_MPEG4        =0;
	public static final int CODETYPE_H264       =1;
	public static final int CODETYPE_JPG        =2;

	// 码流控制列表
	public static final int DH_CAPTURE_BRC_CBR      =0;
	public static final int DH_CAPTURE_BRC_VBR     =1;
	
	// 错误类型代号，对应CLIENT_GetLastError接口的返回值
	public static final int NET_NOERROR        = 0;     // 没有错误
	public static final int NET_ERROR         =-1;    // 未知错误
	public static final int NET_SYSTEM_ERROR      = (0x80000000|1);		// Windows系统出错
	public static final int NET_NETWORK_ERROR     = (0x80000000|2);		// 网络错误，可能是因为网络超时
	public static final int NET_DEV_VER_NOMATCH     = (0x80000000|3);		// 设备协议不匹配
	public static final int NET_INVALID_HANDLE      = (0x80000000|4);		// 句柄无效
	public static final int NET_OPEN_CHANNEL_ERROR    = (0x80000000|5);		// 打开通道失败
	public static final int NET_CLOSE_CHANNEL_ERROR   = (0x80000000|6);		// 关闭通道失败
	public static final int NET_ILLEGAL_PARAM     = (0x80000000|7);		// 用户参数不合法
	public static final int NET_SDK_INIT_ERROR      = (0x80000000|8);		// SDK初始化出错
	public static final int NET_SDK_UNINIT_ERROR    = (0x80000000|9);		// SDK清理出错
	public static final int NET_RENDER_OPEN_ERROR   = (0x80000000|10);		// 申请render资源出错
	public static final int NET_DEC_OPEN_ERROR      = (0x80000000|11);		// 打开解码库出错
	public static final int NET_DEC_CLOSE_ERROR     = (0x80000000|12);		// 关闭解码库出错
	public static final int NET_MULTIPLAY_NOCHANNEL   = (0x80000000|13);    // 多画面预览中检测到通道数为0
	public static final int NET_TALK_INIT_ERROR     = (0x80000000|14);		// 录音库初始化失败
	public static final int NET_TALK_NOT_INIT     = (0x80000000|15);		// 录音库未经初始化
	public static final int NET_TALK_SENDDATA_ERROR   = (0x80000000|16);		// 发送音频数据出错
	public static final int NET_REAL_ALREADY_SAVING   = (0x80000000|17);		// 实时数据已经处于保存状态
	public static final int NET_NOT_SAVING        = (0x80000000|18);		// 未保存实时数据
	public static final int NET_OPEN_FILE_ERROR     = (0x80000000|19);		// 打开文件出错
	public static final int NET_PTZ_SET_TIMER_ERROR   = (0x80000000|20);		// 启动云台控制定时器失败
	public static final int NET_RETURN_DATA_ERROR   = (0x80000000|21);		// 对返回数据的校验出错
	public static final int NET_INSUFFICIENT_BUFFER   = (0x80000000|22);		// 没有足够的缓存
	public static final int NET_NOT_SUPPORTED     = (0x80000000|23);		// 当前SDK未支持该功能
	public static final int NET_NO_RECORD_FOUND     = (0x80000000|24);		// 查询不到录象
	public static final int NET_NOT_AUTHORIZED      = (0x80000000|25);		// 无操作权限
	public static final int NET_NOT_NOW         = (0x80000000|26);		// 暂时无法执行
	public static final int NET_NO_TALK_CHANNEL     = (0x80000000|27);		// 未发现对讲通道
	public static final int NET_NO_AUDIO        = (0x80000000|28);		// 未发现音频
	public static final int NET_NO_INIT         = (0x80000000|29);		// 网络SDK未经初始化
	public static final int NET_DOWNLOAD_END      = (0x80000000|30);		// 下载已结束
	public static final int NET_EMPTY_LIST        = (0x80000000|31);		// 查询结果为空
	public static final int NET_ERROR_GETCFG_SYSATTR  = (0x80000000|32);		// 获取系统属性配置失败
	public static final int NET_ERROR_GETCFG_SERIAL   = (0x80000000|33);		// 获取序列号失败
	public static final int NET_ERROR_GETCFG_GENERAL  = (0x80000000|34);		// 获取常规属性失败
	public static final int NET_ERROR_GETCFG_DSPCAP   = (0x80000000|35);		// 获取DSP能力描述失败
	public static final int NET_ERROR_GETCFG_NETCFG   = (0x80000000|36);		// 获取网络配置失败
	public static final int NET_ERROR_GETCFG_CHANNAME = (0x80000000|37);		// 获取通道名称失败
	public static final int NET_ERROR_GETCFG_VIDEO    = (0x80000000|38);		// 获取视频属性失败
	public static final int NET_ERROR_GETCFG_RECORD   = (0x80000000|39);		// 获取录象配置失败
	public static final int NET_ERROR_GETCFG_PRONAME  = (0x80000000|40);		// 获取解码器协议名称失败
	public static final int NET_ERROR_GETCFG_FUNCNAME = (0x80000000|41);		// 获取232串口功能名称失败
	public static final int NET_ERROR_GETCFG_485DECODER = (0x80000000|42);		// 获取解码器属性失败
	public static final int NET_ERROR_GETCFG_232COM   = (0x80000000|43);		// 获取232串口配置失败
	public static final int NET_ERROR_GETCFG_ALARMIN  = (0x80000000|44);		// 获取外部报警输入配置失败
	public static final int NET_ERROR_GETCFG_ALARMDET = (0x80000000|45);		// 获取动态检测报警失败
	public static final int NET_ERROR_GETCFG_SYSTIME  = (0x80000000|46);		// 获取设备时间失败
	public static final int NET_ERROR_GETCFG_PREVIEW  = (0x80000000|47);		// 获取预览参数失败
	public static final int NET_ERROR_GETCFG_AUTOMT   = (0x80000000|48);		// 获取自动维护配置失败
	public static final int NET_ERROR_GETCFG_VIDEOMTRX  = (0x80000000|49);		// 获取视频矩阵配置失败
	public static final int NET_ERROR_GETCFG_COVER    = (0x80000000|50);		// 获取区域遮挡配置失败
	public static final int NET_ERROR_GETCFG_WATERMAKE  = (0x80000000|51);		// 获取图象水印配置失败
	public static final int NET_ERROR_SETCFG_GENERAL  = (0x80000000|55);		// 修改常规属性失败
	public static final int NET_ERROR_SETCFG_NETCFG   = (0x80000000|56);		// 修改网络配置失败
	public static final int NET_ERROR_SETCFG_CHANNAME = (0x80000000|57);		// 修改通道名称失败
	public static final int NET_ERROR_SETCFG_VIDEO    = (0x80000000|58);		// 修改视频属性失败
	public static final int NET_ERROR_SETCFG_RECORD   = (0x80000000|59);		// 修改录象配置失败
	public static final int NET_ERROR_SETCFG_485DECODER = (0x80000000|60);		// 修改解码器属性失败
	public static final int NET_ERROR_SETCFG_232COM   = (0x80000000|61);		// 修改232串口配置失败
	public static final int NET_ERROR_SETCFG_ALARMIN  = (0x80000000|62);		// 修改外部输入报警配置失败
	public static final int NET_ERROR_SETCFG_ALARMDET = (0x80000000|63);		// 修改动态检测报警配置失败
	public static final int NET_ERROR_SETCFG_SYSTIME  = (0x80000000|64);		// 修改设备时间失败
	public static final int NET_ERROR_SETCFG_PREVIEW  = (0x80000000|65);		// 修改预览参数失败
	public static final int NET_ERROR_SETCFG_AUTOMT   = (0x80000000|66);		// 修改自动维护配置失败
	public static final int NET_ERROR_SETCFG_VIDEOMTRX  = (0x80000000|67);		// 修改视频矩阵配置失败
	public static final int NET_ERROR_SETCFG_COVER    = (0x80000000|68);		// 修改区域遮挡配置失败
	public static final int NET_ERROR_SETCFG_WATERMAKE  = (0x80000000|69);		// 修改图象水印配置失败
	public static final int NET_ERROR_SETCFG_WLAN   = (0x80000000|70);		// 修改无线网络信息失败
	public static final int NET_ERROR_SETCFG_WLANDEV  = (0x80000000|71);		// 选择无线网络设备失败
	public static final int NET_ERROR_SETCFG_REGISTER = (0x80000000|72);		// 修改主动注册参数配置失败
	public static final int NET_ERROR_SETCFG_CAMERA   = (0x80000000|73);		// 修改摄像头属性配置失败
	public static final int NET_ERROR_SETCFG_INFRARED = (0x80000000|74);		// 修改红外报警配置失败
	public static final int NET_ERROR_SETCFG_SOUNDALARM = (0x80000000|75);		// 修改音频报警配置失败
	public static final int NET_ERROR_SETCFG_STORAGE    = (0x80000000|76);		// 修改存储位置配置失败
	public static final int NET_AUDIOENCODE_NOTINIT   = (0x80000000|77);		// 音频编码接口没有成功初始化
	public static final int NET_DATA_TOOLONGH     = (0x80000000|78);		// 数据过长
	public static final int NET_UNSUPPORTED       = (0x80000000|79);		// 设备不支持该操作
	public static final int NET_DEVICE_BUSY       = (0x80000000|80);		// 设备资源不足
	public static final int NET_SERVER_STARTED      = (0x80000000|81);		// 服务器已经启动
	public static final int NET_SERVER_STOPPED      = (0x80000000|82);		// 服务器尚未成功启动
	public static final int NET_LISTER_INCORRECT_SERIAL = (0x80000000|83);		// 输入序列号有误
	public static final int NET_QUERY_DISKINFO_FAILED = (0x80000000|84);		// 获取硬盘信息失败
	public static final int NET_ERROR_GETCFG_SESSION  = (0x80000000|85);		// 获取连接Session信息
	public static final int NET_USER_FLASEPWD_TRYTIME = (0x80000000|86);		// 输入密码错误超过限制次数
	public static final int NET_LOGIN_ERROR_PASSWORD  = (0x80000000|100);		// 密码不正确
	public static final int NET_LOGIN_ERROR_USER    = (0x80000000|101);		// 帐户不存在
	public static final int NET_LOGIN_ERROR_TIMEOUT   = (0x80000000|102);		// 等待登录返回超时
	public static final int NET_LOGIN_ERROR_RELOGGIN  = (0x80000000|103);		// 帐号已登录
	public static final int NET_LOGIN_ERROR_LOCKED    = (0x80000000|104);		// 帐号已被锁定
	public static final int NET_LOGIN_ERROR_BLACKLIST = (0x80000000|105);		// 帐号已被列为黑名单
	public static final int NET_LOGIN_ERROR_BUSY    = (0x80000000|106);		// 资源不足，系统忙
	public static final int NET_LOGIN_ERROR_CONNECT   = (0x80000000|107);		// 登录设备超时，请检查网络并重试
	public static final int NET_LOGIN_ERROR_NETWORK   = (0x80000000|108);		// 网络连接失败
	public static final int NET_LOGIN_ERROR_SUBCONNECT  = (0x80000000|109);		// 登录设备成功，但无法创建视频通道，请检查网络状况
	public static final int NET_LOGIN_ERROR_MAXCONNECT  = (0x80000000|110);		// 超过最大连接数
	public static final int NET_LOGIN_ERROR_PROTOCOL3_ONLY = (0x80000000|111);		// 只支持3代协议
	public static final int NET_LOGIN_ERROR_UKEY_LOST = (0x80000000|112);		// 未插入U盾或U盾信息错误
	public static final int NET_LOGIN_ERROR_NO_AUTHORIZED = (0x80000000|113);		// 客户端IP地址没有登录权限  
	public static final int NET_RENDER_SOUND_ON_ERROR = (0x80000000|120);		// Render库打开音频出错
	public static final int NET_RENDER_SOUND_OFF_ERROR  = (0x80000000|121);		// Render库关闭音频出错
	public static final int NET_RENDER_SET_VOLUME_ERROR = (0x80000000|122);		// Render库控制音量出错
	public static final int NET_RENDER_ADJUST_ERROR   = (0x80000000|123);		// Render库设置画面参数出错
	public static final int NET_RENDER_PAUSE_ERROR    = (0x80000000|124);		// Render库暂停播放出错
	public static final int NET_RENDER_SNAP_ERROR   = (0x80000000|125);		// Render库抓图出错
	public static final int NET_RENDER_STEP_ERROR   = (0x80000000|126);		// Render库步进出错
	public static final int NET_RENDER_FRAMERATE_ERROR  = (0x80000000|127);		// Render库设置帧率出错
	public static final int NET_RENDER_DISPLAYREGION_ERROR  = (0x80000000|128); // Render库设置显示区域出错
	public static final int NET_GROUP_EXIST       = (0x80000000|140);		// 组名已存在
	public static final int NET_GROUP_NOEXIST     = (0x80000000|141);		// 组名不存在
	public static final int NET_GROUP_RIGHTOVER     = (0x80000000|142);		// 组的权限超出权限列表范围
	public static final int NET_GROUP_HAVEUSER      = (0x80000000|143);		// 组下有用户，不能删除
	public static final int NET_GROUP_RIGHTUSE      = (0x80000000|144);		// 组的某个权限被用户使用，不能出除
	public static final int NET_GROUP_SAMENAME      = (0x80000000|145);		// 新组名同已有组名重复
	public static final int NET_USER_EXIST        = (0x80000000|146);		// 用户已存在
	public static final int NET_USER_NOEXIST      = (0x80000000|147);		// 用户不存在
	public static final int NET_USER_RIGHTOVER      = (0x80000000|148);		// 用户权限超出组权限
	public static final int NET_USER_PWD        = (0x80000000|149);		// 保留帐号，不容许修改密码
	public static final int NET_USER_FLASEPWD     = (0x80000000|150);		// 密码不正确
	public static final int NET_USER_NOMATCHING     = (0x80000000|151);		// 密码不匹配
	public static final int NET_USER_INUSE        = (0x80000000|152);		// 账号正在使用中
	public static final int NET_ERROR_GETCFG_ETHERNET = (0x80000000|300);		// 获取网卡配置失败
	public static final int NET_ERROR_GETCFG_WLAN   = (0x80000000|301);		// 获取无线网络信息失败
	public static final int NET_ERROR_GETCFG_WLANDEV  = (0x80000000|302);		// 获取无线网络设备失败
	public static final int NET_ERROR_GETCFG_REGISTER = (0x80000000|303);		// 获取主动注册参数失败
	public static final int NET_ERROR_GETCFG_CAMERA   = (0x80000000|304);		// 获取摄像头属性失败
	public static final int NET_ERROR_GETCFG_INFRARED = (0x80000000|305);		// 获取红外报警配置失败
	public static final int NET_ERROR_GETCFG_SOUNDALARM = (0x80000000|306);		// 获取音频报警配置失败
	public static final int NET_ERROR_GETCFG_STORAGE    = (0x80000000|307);		// 获取存储位置配置失败
	public static final int NET_ERROR_GETCFG_MAIL   = (0x80000000|308);		// 获取邮件配置失败
	public static final int NET_CONFIG_DEVBUSY      = (0x80000000|309);		// 暂时无法设置
	public static final int NET_CONFIG_DATAILLEGAL    = (0x80000000|310);		// 配置数据不合法
	public static final int NET_ERROR_GETCFG_DST        = (0x80000000|311);		// 获取夏令时配置失败
	public static final int NET_ERROR_SETCFG_DST        = (0x80000000|312);		// 设置夏令时配置失败
	public static final int NET_ERROR_GETCFG_VIDEO_OSD  = (0x80000000|313);		// 获取视频OSD叠加配置失败
	public static final int NET_ERROR_SETCFG_VIDEO_OSD  = (0x80000000|314);		// 设置视频OSD叠加配置失败
	public static final int NET_ERROR_GETCFG_GPRSCDMA   = (0x80000000|315);		// 获取CDMA\GPRS网络配置失败
	public static final int NET_ERROR_SETCFG_GPRSCDMA   = (0x80000000|316);		// 设置CDMA\GPRS网络配置失败
	public static final int NET_ERROR_GETCFG_IPFILTER   = (0x80000000|317);		// 获取IP过滤配置失败
	public static final int NET_ERROR_SETCFG_IPFILTER   = (0x80000000|318);		// 设置IP过滤配置失败
	public static final int NET_ERROR_GETCFG_TALKENCODE = (0x80000000|319);		// 获取语音对讲编码配置失败
	public static final int NET_ERROR_SETCFG_TALKENCODE = (0x80000000|320);		// 设置语音对讲编码配置失败
	public static final int NET_ERROR_GETCFG_RECORDLEN  = (0x80000000|321);		// 获取录像打包长度配置失败
	public static final int NET_ERROR_SETCFG_RECORDLEN  = (0x80000000|322);		// 设置录像打包长度配置失败
	public static final int NET_DONT_SUPPORT_SUBAREA  = (0x80000000|323);		// 不支持网络硬盘分区
	public static final int NET_ERROR_GET_AUTOREGSERVER = (0x80000000|324);		// 获取设备上主动注册服务器信息失败
	public static final int NET_ERROR_CONTROL_AUTOREGISTER    = (0x80000000|325);		// 主动注册重定向注册错误
	public static final int NET_ERROR_DISCONNECT_AUTOREGISTER = (0x80000000|326);		// 断开主动注册服务器错误
	public static final int NET_ERROR_GETCFG_MMS        = (0x80000000|327);		// 获取mms配置失败
	public static final int NET_ERROR_SETCFG_MMS        = (0x80000000|328);		// 设置mms配置失败
	public static final int NET_ERROR_GETCFG_SMSACTIVATION      = (0x80000000|329);		// 获取短信激活无线连接配置失败
	public static final int NET_ERROR_SETCFG_SMSACTIVATION      = (0x80000000|330);		// 设置短信激活无线连接配置失败
	public static final int NET_ERROR_GETCFG_DIALINACTIVATION = (0x80000000|331);		// 获取拨号激活无线连接配置失败
	public static final int NET_ERROR_SETCFG_DIALINACTIVATION = (0x80000000|332);		// 设置拨号激活无线连接配置失败
	public static final int NET_ERROR_GETCFG_VIDEOOUT           = (0x80000000|333);		// 查询视频输出参数配置失败
	public static final int NET_ERROR_SETCFG_VIDEOOUT     = (0x80000000|334);		// 设置视频输出参数配置失败
	public static final int NET_ERROR_GETCFG_OSDENABLE      = (0x80000000|335);		// 获取osd叠加使能配置失败
	public static final int NET_ERROR_SETCFG_OSDENABLE      = (0x80000000|336);		// 设置osd叠加使能配置失败
	public static final int NET_ERROR_SETCFG_ENCODERINFO        = (0x80000000|337);		// 设置数字通道前端编码接入配置失败
	public static final int NET_ERROR_GETCFG_TVADJUST       = (0x80000000|338);		// 获取TV调节配置失败
	public static final int NET_ERROR_SETCFG_TVADJUST     = (0x80000000|339);		// 设置TV调节配置失败

	public static final int NET_ERROR_CONNECT_FAILED      = (0x80000000|340);		// 请求建立连接失败
	public static final int NET_ERROR_SETCFG_BURNFILE     = (0x80000000|341);		// 请求刻录文件上传失败
	public static final int NET_ERROR_SNIFFER_GETCFG      = (0x80000000|342);		// 获取抓包配置信息失败
	public static final int NET_ERROR_SNIFFER_SETCFG      = (0x80000000|343);		// 设置抓包配置信息失败
	public static final int NET_ERROR_DOWNLOADRATE_GETCFG   = (0x80000000|344);		// 查询下载限制信息失败
	public static final int NET_ERROR_DOWNLOADRATE_SETCFG   = (0x80000000|345);		// 设置下载限制信息失败
	public static final int NET_ERROR_SEARCH_TRANSCOM     = (0x80000000|346);		// 查询串口参数失败
	public static final int NET_ERROR_GETCFG_POINT        = (0x80000000|347);		// 获取预制点信息错误
	public static final int NET_ERROR_SETCFG_POINT        = (0x80000000|348);		// 设置预制点信息错误
	public static final int NET_SDK_LOGOUT_ERROR        = (0x80000000|349);		// SDK没有正常登出设备
	public static final int NET_ERROR_GET_VEHICLE_CFG     = (0x80000000|350);		// 获取车载配置失败
	public static final int NET_ERROR_SET_VEHICLE_CFG     = (0x80000000|351);		// 设置车载配置失败
	public static final int NET_ERROR_GET_ATM_OVERLAY_CFG   = (0x80000000|352);		// 获取atm叠加配置失败
	public static final int NET_ERROR_SET_ATM_OVERLAY_CFG   = (0x80000000|353);		// 设置atm叠加配置失败
	public static final int NET_ERROR_GET_ATM_OVERLAY_ABILITY = (0x80000000|354);		// 获取atm叠加能力失败
	public static final int NET_ERROR_GET_DECODER_TOUR_CFG    = (0x80000000|355);		// 获取解码器解码轮巡配置失败
	public static final int NET_ERROR_SET_DECODER_TOUR_CFG    = (0x80000000|356);		// 设置解码器解码轮巡配置失败
	public static final int NET_ERROR_CTRL_DECODER_TOUR     = (0x80000000|357);		// 控制解码器解码轮巡失败
	public static final int NET_GROUP_OVERSUPPORTNUM      = (0x80000000|358);		// 超出设备支持最大用户组数目
	public static final int NET_USER_OVERSUPPORTNUM       = (0x80000000|359);		// 超出设备支持最大用户数目
	public static final int NET_ERROR_GET_SIP_CFG       = (0x80000000|368);		// 获取SIP配置失败
	public static final int NET_ERROR_SET_SIP_CFG       = (0x80000000|369);		// 设置SIP配置失败
	public static final int NET_ERROR_GET_SIP_ABILITY     = (0x80000000|370);		// 获取SIP能力失败
	public static final int NET_ERROR_GET_WIFI_AP_CFG     = (0x80000000|371);		// 获取WIFI ap配置失败
	public static final int NET_ERROR_SET_WIFI_AP_CFG     = (0x80000000|372);		// 设置WIFI ap配置失败
	public static final int NET_ERROR_GET_DECODE_POLICY       = (0x80000000|373);		// 获取解码策略配置失败
	public static final int NET_ERROR_SET_DECODE_POLICY     = (0x80000000|374);		// 设置解码策略配置失败
	public static final int NET_ERROR_TALK_REJECT       = (0x80000000|375);		// 拒绝对讲
	public static final int NET_ERROR_TALK_OPENED       = (0x80000000|376);		// 对讲被其他客户端打开
	public static final int NET_ERROR_TALK_RESOURCE_CONFLICIT   = (0x80000000|377);		// 资源冲突
	public static final int NET_ERROR_TALK_UNSUPPORTED_ENCODE   = (0x80000000|378);		// 不支持的语音编码格式
	public static final int NET_ERROR_TALK_RIGHTLESS      = (0x80000000|379);		// 无权限
	public static final int NET_ERROR_TALK_FAILED       = (0x80000000|380);		// 请求对讲失败
	public static final int NET_ERROR_GET_MACHINE_CFG     = (0x80000000|381);		// 获取机器相关配置失败
	public static final int NET_ERROR_SET_MACHINE_CFG     = (0x80000000|382);		// 设置机器相关配置失败
	public static final int NET_ERROR_GET_DATA_FAILED     = (0x80000000|383);		// 设备无法获取当前请求数据
	public static final int NET_ERROR_MAC_VALIDATE_FAILED       = (0x80000000|384);		// MAC地址验证失败 
	public static final int NET_ERROR_GET_INSTANCE              = (0x80000000|385);		// 获取服务器实例失败
	public static final int NET_ERROR_JSON_REQUEST              = (0x80000000|386);		// 生成的jason字符串错误
	public static final int NET_ERROR_JSON_RESPONSE             = (0x80000000|387);		// 响应的jason字符串错误
	public static final int NET_ERROR_VERSION_HIGHER            = (0x80000000|388);		// 协议版本低于当前使用的版本
	public static final int NET_SPARE_NO_CAPACITY       = (0x80000000|389);		// 热备操作失败, 容量不足
	public static final int NET_ERROR_SOURCE_IN_USE       = (0x80000000|390);		// 显示源被其他输出占用
	public static final int NET_ERROR_REAVE                     = (0x80000000|391);		// 高级用户抢占低级用户资源
	public static final int NET_ERROR_NETFORBID                 = (0x80000000|392);		// 禁止入网 
	public static final int NET_ERROR_GETCFG_MACFILTER      = (0x80000000|393);		// 获取MAC过滤配置失败
	public static final int NET_ERROR_SETCFG_MACFILTER      = (0x80000000|394);		// 设置MAC过滤配置失败
	public static final int NET_ERROR_GETCFG_IPMACFILTER    = (0x80000000|395);		// 获取IP/MAC过滤配置失败
	public static final int NET_ERROR_SETCFG_IPMACFILTER    = (0x80000000|396);		// 设置IP/MAC过滤配置失败
	public static final int NET_ERROR_OPERATION_OVERTIME        = (0x80000000|397);		// 当前操作超时 
	public static final int NET_ERROR_SENIOR_VALIDATE_FAILED    = (0x80000000|398);		// 高级校验失败 
	 
	public static final int NET_ERROR_DEVICE_ID_NOT_EXIST   = (0x80000000|399);		// 设备ID不存在
	public static final int NET_ERROR_UNSUPPORTED               = (0x80000000|400);		// 不支持当前操作

	public static final int NET_ERROR_PROXY_DLLLOAD       = (0x80000000|401);		// 代理库加载失败
	public static final int NET_ERROR_PROXY_ILLEGAL_PARAM   = (0x80000000|402);		// 代理用户参数不合法
	public static final int NET_ERROR_PROXY_INVALID_HANDLE    = (0x80000000|403);		// 代理句柄无效
	public static final int NET_ERROR_PROXY_LOGIN_DEVICE_ERROR  = (0x80000000|404);		// 代理登入前端设备失败
	public static final int NET_ERROR_PROXY_START_SERVER_ERROR  = (0x80000000|405);		// 启动代理服务失败
	
	// 智能事件类型常量
	public static final int EVENT_IVS_ALL                             = 0x00000001;        // 订阅所有事件
	public static final int EVENT_IVS_CROSSLINEDETECTION              = 0x00000002;        // 警戒线事件
	public static final int EVENT_IVS_CROSSREGIONDETECTION            = 0x00000003;        // 警戒区事件
	public static final int EVENT_IVS_PASTEDETECTION                  = 0x00000004;        // 贴条事件
	public static final int EVENT_IVS_LEFTDETECTION                   = 0x00000005;        // 物品遗留事件
	public static final int EVENT_IVS_STAYDETECTION                   = 0x00000006;        // 停留事件
	public static final int EVENT_IVS_WANDERDETECTION                 = 0x00000007;        // 徘徊事件
	public static final int EVENT_IVS_PRESERVATION                    = 0x00000008;        // 物品保全事件
	public static final int EVENT_IVS_MOVEDETECTION                   = 0x00000009;        // 移动事件
	public static final int EVENT_IVS_TAILDETECTION                   = 0x0000000A;        // 尾随事件
	public static final int EVENT_IVS_RIOTERDETECTION                 = 0x0000000B;        // 聚众事件
	public static final int EVENT_IVS_FIREDETECTION                   = 0x0000000C;        // 火警事件
	public static final int EVENT_IVS_SMOKEDETECTION                  = 0x0000000D;        // 烟雾报警事件
	public static final int EVENT_IVS_FIGHTDETECTION                  = 0x0000000E;        // 斗殴事件
	public static final int EVENT_IVS_FLOWSTAT                        = 0x0000000F;        // 流量统计事件
	public static final int EVENT_IVS_NUMBERSTAT                      = 0x00000010;        // 数量统计事件
	public static final int EVENT_IVS_CAMERACOVERDDETECTION           = 0x00000011;        // 摄像头覆盖事件
	public static final int EVENT_IVS_CAMERAMOVEDDETECTION            = 0x00000012;        // 摄像头移动事件
	public static final int EVENT_IVS_VIDEOABNORMALDETECTION          = 0x00000013;        // 视频异常事件
	public static final int EVENT_IVS_VIDEOBADDETECTION               = 0x00000014;        // 视频损坏事件
	public static final int EVENT_IVS_TRAFFICCONTROL                  = 0x00000015;        // 交通管制事件
	public static final int EVENT_IVS_TRAFFICACCIDENT                 = 0x00000016;        // 交通事故事件
	public static final int EVENT_IVS_TRAFFICJUNCTION                 = 0x00000017;        // 交通路口事件----老规则
	public static final int EVENT_IVS_TRAFFICGATE                     = 0x00000018;        // 交通卡口事件----老规则
	public static final int EVENT_TRAFFICSNAPSHOT                     = 0x00000019;        // 交通抓拍事件
	public static final int EVENT_IVS_FACEDETECT                      = 0x0000001A;        // 人脸检测事件 
	public static final int EVENT_IVS_TRAFFICJAM                      = 0x0000001B;        // 交通拥堵事件
	public static final int EVENT_IVS_TRAFFIC_RUNREDLIGHT             = 0x00000100;        // 交通违章-闯红灯事件
	public static final int EVENT_IVS_TRAFFIC_OVERLINE                = 0x00000101;        // 交通违章-压车道线事件
	public static final int EVENT_IVS_TRAFFIC_RETROGRADE              = 0x00000102;        // 交通违章-逆行事件
	public static final int EVENT_IVS_TRAFFIC_TURNLEFT                = 0x00000103;        // 交通违章-违章左转
	public static final int EVENT_IVS_TRAFFIC_TURNRIGHT               = 0x00000104;        // 交通违章-违章右转
	public static final int EVENT_IVS_TRAFFIC_UTURN                   = 0x00000105;        // 交通违章-违章掉头
	public static final int EVENT_IVS_TRAFFIC_OVERSPEED               = 0x00000106;        // 交通违章-超速
	public static final int EVENT_IVS_TRAFFIC_UNDERSPEED              = 0x00000107;        // 交通违章-低速
	public static final int EVENT_IVS_TRAFFIC_PARKING                 = 0x00000108;        // 交通违章-违章停车
	public static final int EVENT_IVS_TRAFFIC_WRONGROUTE              = 0x00000109;        // 交通违章-不按车道行驶
	public static final int EVENT_IVS_TRAFFIC_CROSSLANE               = 0x0000010A;        // 交通违章-违章变道
	public static final int EVENT_IVS_TRAFFIC_OVERYELLOWLINE          = 0x0000010B;        // 交通违章-压黄线 
	public static final int EVENT_IVS_TRAFFIC_DRIVINGONSHOULDER       = 0x0000010C;        // 交通违章-路肩行驶事件   
	public static final int EVENT_IVS_TRAFFIC_YELLOWPLATEINLANE       = 0x0000010E;        // 交通违章-黄牌车占道事件
	public static final int EVENT_IVS_TRAFFIC_PEDESTRAINPRIORITY      = 0x0000010F;        // 交通违章-斑马线行人优先事件
	public static final int EVENT_IVS_CROSSFENCEDETECTION             = 0x0000011F;        // 翻越围栏事件
	public static final int EVENT_IVS_ELECTROSPARKDETECTION           = 0x00000110;        // 电火花事件
	public static final int EVENT_IVS_TRAFFIC_NOPASSING               = 0x00000111;        // 交通违章-禁止通行事件
	public static final int EVENT_IVS_ABNORMALRUNDETECTION            = 0x00000112;        // 异常奔跑事件
	public static final int EVENT_IVS_RETROGRADEDETECTION             = 0x00000113;        // 人员逆行事件
	public static final int EVENT_IVS_INREGIONDETECTION               = 0x00000114;        // 区域内检测事件
	public static final int EVENT_IVS_TAKENAWAYDETECTION              = 0x00000115;        // 物品搬移事件
	public static final int EVENT_IVS_PARKINGDETECTION                = 0x00000116;        // 非法停车事件
	public static final int EVENT_IVS_FACERECOGNITION                 = 0x00000117;        // 人脸识别事件
	public static final int EVENT_IVS_TRAFFIC_MANUALSNAP              = 0x00000118;        // 交通手动抓拍事件
	public static final int EVENT_IVS_TRAFFIC_FLOWSTATE               = 0x00000119;        // 交通流量统计事件
	public static final int EVENT_IVS_TRAFFIC_STAY                    = 0x0000011A;        // 交通滞留事件
	public static final int EVENT_IVS_TRAFFIC_VEHICLEINROUTE          = 0x0000011B;        // 有车占道事件
	public static final int EVENT_ALARM_MOTIONDETECT                  = 0x0000011C;        // 视频移动侦测事件
	public static final int EVENT_ALARM_LOCALALARM                    = 0x0000011D;        // 外部报警事件
	public static final int EVENT_IVS_PRISONERRISEDETECTION           = 0x0000011E;        // 看守所囚犯起身事件
	public static final int EVENT_IVS_TRAFFIC_TOLLGATE                = 0x00000120;        // 交通违章-卡口事件----新规则
	public static final int EVENT_IVS_DENSITYDETECTION                = 0x00000121;        // 人员密集度检测
	public static final int EVENT_IVS_VIDEODIAGNOSIS                  = 0x00000122;        // 视频诊断结果事件
	public static final int EVENT_IVS_QUEUEDETECTION                  = 0x00000123;        // 排队检测报警事件
	public static final int EVENT_IVS_TRAFFIC_VEHICLEINBUSROUTE       = 0x00000124;        // 占用公交车道事件
	public static final int EVENT_IVS_TRAFFIC_BACKING                 = 0x00000125;        // 违章倒车事件
	public static final int EVENT_IVS_AUDIO_ABNORMALDETECTION         = 0x00000126;        // 声音异常检测
	public static final int EVENT_IVS_TRAFFIC_RUNYELLOWLIGHT          = 0x00000127;        // 交通违章-闯黄灯事件
	public static final int EVENT_IVS_CLIMBDETECTION                  = 0x00000128;        // 攀高检测事件
	public static final int EVENT_IVS_LEAVEDETECTION                  = 0x00000129;        // 离岗检测事件
	public static final int EVENT_IVS_TRAFFIC_ALL                     = 0x000001FF;        // 所有以traffic开头的事件，目前指的是智能分析事件类型
                                                                                         // EVENT_IVS_TRAFFICCONTROL -> EVENT_TRAFFICSNAPSHOT
	/************************************************************************
	 ** 结构体
	 ***********************************************************************/
	// 设置登入时的相关参数
	public static class NET_PARAM  extends Structure
	{
		public int					nWaittime;				// 等待超时时间(毫秒为单位)，为0默认5000ms
		public int					nConnectTime;			// 连接超时时间(毫秒为单位)，为0默认1500ms
		public int					nConnectTryNum;			// 连接尝试次数，为0默认1次
		public int					nSubConnectSpaceTime;	// 子连接之间的等待时间(毫秒为单位)，为0默认10ms
		public int					nGetDevInfoTime;		// 获取设备信息超时时间，为0默认1000ms
		public int					nConnectBufSize;		// 每个连接接收数据缓冲大小(字节为单位)，为0默认250*1024
		public int					nGetConnInfoTime;		// 获取子连接信息超时时间(毫秒为单位)，为0默认1000ms
		public int                 nSearchRecordTime;      // 按时间查询录像文件的超时时间(毫秒为单位),为0默认为3000ms
		public int                 nsubDisconnetTime;      // 检测子链接断线等待时间(毫秒为单位)，为0默认为60000ms
		public byte				byNetType;				// 网络类型, 0-LAN, 1-WAN
		public byte                byPlaybackBufSize;      // 回放数据接收缓冲大小（M为单位），为0默认为4M
		public byte[]                byReserved1 = new byte[2];         // 对齐
		public int                 nPicBufSize;            // 实时图片接收缓冲大小（字节为单位），为0默认为2*1024*1024
		public byte[]				bReserved = new byte[4];			// 保留字段字段
	}
	
	// 设备信息
	public static class NET_DEVICEINFO extends Structure
	{
		public byte[]			sSerialNumber = new byte[DH_SERIALNO_LEN];	// 序列号
		public byte				byAlarmInPortNum;		// DVR报警输入个数
		public byte				byAlarmOutPortNum;		// DVR报警输出个数
		public byte				byDiskNum;				// DVR硬盘个数
		public byte				byDVRType;				// DVR类型, 见枚举DHDEV_DEVICE_TYPE
		public byte				byChanNum;				// DVR通道个数
	}
	// 时间
	public static class NET_TIME extends Structure 
	{
		public int				dwYear;					// 年
		public int				dwMonth;				// 月
		public int				dwDay;					// 日
		public int				dwHour;					// 时
		public int				dwMinute;				// 分
		public int				dwSecond;				// 秒
	}

	public static class NET_TIME_EX extends Structure 
	{
		public int				dwYear;					// 年
		public int				dwMonth;				// 月
		public int				dwDay;					// 日
		public int				dwHour;					// 时
		public int				dwMinute;				// 分
		public int				dwSecond;				// 秒
		public int              dwMillisecond;          // 毫秒
		public int[]            dwReserved = new int[2];          // 保留字段
		
		public String toString() {
            return "NET_TIME_EX.dwYear: " + dwYear + "\n" + "NET_TIME_EX.dwMonth: \n" + dwMonth + "\n" + "NET_TIME_EX.dwDay: \n" + dwDay + "\n" + "NET_TIME_EX.dwHour: \n" + dwHour + "\n" + "NET_TIME_EX.dwMinute: \n" + dwMinute + "\n" + "NET_TIME_EX.dwSecond: \n" + dwSecond;
        }

        //用于列表中显示
        public String toStringTime()
        {
            return  String.format("%02d/%02d/%02d%02d:%02d:%02d", dwYear, dwMonth, dwDay, dwHour, dwMinute, dwSecond);
        }

        //存储文件名使用
         public String toStringTitle()
        {
            return  String.format("Time%02d%02d%02d_%02d%02d%02d%03d", dwYear, dwMonth, dwDay, dwHour, dwMinute, dwSecond,dwMillisecond);
        }
	}


	// 时间段结构															    
	public static class DH_TSECT extends Structure 
	{
		public boolean   				bEnable;				// 当表示录像时间段时，按位表示四个使能，从低位到高位分别表示动检录象、报警录象、普通录象、动检和报警同时发生才录像
		public int					iBeginHour;
		public int					iBeginMin;
		public int					iBeginSec;
		public int					iEndHour;
		public int					iEndMin;
		public int					iEndSec;
	}

	// 区域；各边距按整长8192的比例
	public static class DH_RECT extends Structure 
	{
	   public NativeLong					left;
	   public NativeLong					top;
	   public NativeLong					right;
	   public NativeLong					bottom;
	}

	// 二维空间点
	public static class DH_POINT extends Structure 
	{
	   public short					nx;
	   public short					ny;
	}

	// 区域或曲线顶点信息
	public static class DH_POLY_POINTS extends Structure
	{
		public int        nPointNum;                           // 顶点数
		public DH_POINT[]        stuPoints = new DH_POINT[DH_MAX_DETECT_REGION_NUM];     // 顶点信息
	}

	// 物体对应图片文件信息
	public static class DH_PIC_INFO extends Structure 
	{
		public int                dwOffSet;                       // 文件在二进制数据块中的偏移位置, 单位:字节
		public int                dwFileLenth;                    // 文件大小, 单位:字节
		public short                 wWidth;                         // 图片宽度, 单位:像素
		public short                 wHeight;                        // 图片高度, 单位:像素
		public byte[]                 bReserved = new byte[16];                 
	}
	
	// 抓拍信息
	public static class DH_SIG_CARWAY_INFO extends Structure 
	{
		public short              snSpeed;                          // 当前车的速度，km/h
		public short              snCarLength;                      // 当前车长,分米为单位
		public float              fRedTime;                        // 当前车道红灯时间,秒.毫秒
		public float              fCapTime;                        // 当前车道抓拍时间,秒.毫秒 
		public byte               bSigSequence;                    // 当前抓拍序号
		public byte               bType;                           // 当前车道的抓拍类型
															// 0: 雷达高限速;1: 雷达低限速;2: 车检器高限速;3:车检器低限速
			                                                // 4: 逆向;5: 闯红灯;6: 红灯亮;7: 红灯灭;8: 全部抓拍或者卡口
		public byte               bDirection;                      // 闯红灯类型:01:左转红灯;02:直行红灯;03:右转红灯
		public byte               bLightColor;                     // 当前车道的红绿灯状态，0: 绿灯, 1: 红灯, 2: 黄灯
		public byte[]               bSnapFlag = new byte[16];                   // 设备产生的抓拍标识
	}
	
	// 车检器冗余信息
	public static class DH_SIG_CARWAY_INFO_EX extends Structure 
	{
		public byte[]                byRedundance = new byte[8];                // 由车检器产生抓拍信号冗余信息
		public byte[]                bReserved = new byte[120];                  // 保留字段
	}

	// 视频分析物体信息结构体
	public static class DH_MSG_OBJECT extends Structure  
	{
		public int					nObjectID;						// 物体ID,每个ID表示一个唯一的物体
		public byte[]				szObjectType = new byte[128];				// 物体类型
		public int					nConfidence;					// 置信度(0~255)，值越大表示置信度越高
		public int					nAction;						// 物体动作:1:Appear 2:Move 3:Stay 4:Remove 5:Disappear 6:Split 7:Merge 8:Rename
		public DH_RECT				BoundingBox;					// 包围盒
		public DH_POINT			Center;							// 物体型心
		public int					nPolygonNum;					// 多边形顶点个数
		public DH_POINT[]			Contour = new DH_POINT[DH_MAX_POLYGON_NUM];	// 较精确的轮廓多边形
		public int				rgbaMainColor;					// 表示车牌、车身等物体主要颜色；按字节表示，分别为红、绿、蓝和透明度,例如:RGB值为(0,255,0),透明度为0时, 其值为0x00ff0000.
	    public byte[]				szText = new byte[128];					// 物体上相关的带0结束符文本，比如车牌，集装箱号等等
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

		public byte[]                szObjectSubType = new byte[64];            // 物体子类别，根据不同的物体类型，可以取以下子类型：
															// Vehicle Category:"Unknown"  未知,"Motor" 机动车,"Non-Motor":非机动车,"Bus": 公交车,"Bicycle" 自行车,"Motorcycle":摩托车
															// Plate Category："Unknown" 未知,"Normal" 蓝牌黑牌,"Yellow" 黄牌,"DoubleYellow" 双层黄尾牌,"Police" 警牌"Armed" 武警牌,
															// "Military" 部队号牌,"DoubleMilitary" 部队双层,"SAR" 港澳特区号牌,"Trainning" 教练车号牌
															// "Personal" 个性号牌,"Agri" 农用牌,"Embassy" 使馆号牌,"Moto" 摩托车号牌,"Tractor" 拖拉机号牌,"Other" 其他号牌
															// HumanFace Category:"Normal" 普通人脸,"HideEye" 眼部遮挡,"HideNose" 鼻子遮挡,"HideMouth" 嘴部遮挡
		public byte[]                byReserved1 = new byte[3];
		public byte                bPicEnble;                      // 是否有物体对应图片文件信息
		public DH_PIC_INFO         stPicInfo;                      // 物体对应图片信息
		public byte				bShotFrame;						// 是否是抓拍张的识别结果
		public byte				bColor;							// 物体颜色(rgbaMainColor)是否可用
		public byte[]				byReserved2 = new byte[2];
		public NET_TIME_EX        stuCurrentTime;					// 针对视频浓缩，当前时间戳（物体抓拍或识别时，会将此识别智能帧附在一个视频帧或jpeg图片中，此帧所在原始视频中的出现时间）
		public NET_TIME_EX        stuStartTime;					// 开始时间戳（物体开始出现时）
		public NET_TIME_EX        stuEndTime;						// 结束时间戳（物体最后出现时）
		public DH_RECT				stuOriginalBoundingBox;			// 包围盒(绝对坐标)
		public DH_RECT             stuSignBoundingBox;             // 车标坐标包围盒
		public byte[]				byReserved = new byte[78];
	}

	// 每个车道的相关信息
	public static class DH_CARWAY_INFO extends Structure 
	{
		public byte                bCarWayID;                           // 当前车道号 
		public byte[]                bReserve = new byte[2];                         // 保留字段
		public byte                bSigCount;                           // 被触发抓拍的个数
		public DH_SIG_CARWAY_INFO[]  stuSigInfo = new DH_SIG_CARWAY_INFO[DH_MAX_SNAP_SIGNAL_NUM];  // 当前车道上，被触发抓拍对应的抓拍信息	
		public byte[]                bReserved = new byte[12];                       // 保留字段
	}

	// 事件对应文件信息
	public static class DH_EVENT_FILE_INFO extends Structure  
	{
		public byte               bCount;                               // 当前文件所在文件组中的文件总数
		public byte               bIndex;                               // 当前文件在文件组中的文件编号
		public byte               bFileTag;                             // 文件标签，具体说明见枚举类型EM_EVENT_FILETAG
		public byte               bFileType;                            // 文件类型，0-普通 1-合成 2-抠图
		public NET_TIME_EX        stuFileTime;                          // 文件时间
		public int                nGroupId;                             // 同一组抓拍文件的唯一标识
	}

	// 图片分辨率
	public static class DH_RESOLUTION_INFO extends Structure 
	{
		public short   snWidth;    // 宽
		public short   snHight;    // 高
	}
	
	// 人员信息
	public static class FACERECOGNITION_PERSON_INFO extends Structure 
	{
		public byte[]                szPersonName = new byte[DH_MAX_NAME_LEN];					// 姓名                 
		public short				wYear;											// 出生年
		public byte				byMonth;										// 出生月
		public byte				byDay;											// 出生日
		public byte[]                szID = new byte[32];										// 人员唯一标示(身份证号码，工号，或其他编号)
		public byte                bImportantRank;									// 人员重要等级,1~10，数值越高越重要
		public byte                bySex;											// 性别，0-男，1-女 
		public short                wFacePicNum;									// 图片张数
		public DH_PIC_INFO[]         szFacePicInfo = new DH_PIC_INFO[DH_MAX_PERSON_IMAGE_NUM];         // 当前人员对应的图片信息
		public byte[]                bReserved = new byte[256];
	}

	// 候选人员信息
	public static class CANDIDATE_INFO extends Structure
	{
		public FACERECOGNITION_PERSON_INFO  stPersonInfo;            // 人员信息
		public byte                         bySimilarity;            // 和查询图片的相似度
		public byte[]                       byReserved = new byte[127];         // 保留字节
	}
	
	public static class DH_DrivingDirection extends Structure
	{
		public byte[]    szArrJ = new byte[DH_MAX_DRIVINGDIRECTION];        
	}
    // TrafficCar 交通车辆信息
    public static class DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO extends Structure
    {
    public byte[]             szPlateNumber = new byte[32];            // 车牌号码
    public byte[]             szPlateType   = new byte[32];              // 号牌类型 参见VideoAnalyseRule中车牌类型定义
    public byte[]             szPlateColor  = new byte[32];             // 车牌颜色 "Blue","Yellow", "White","Black"
    public byte[]             szVehicleColor= new byte[32];            // 车身颜色 "White", "Black", "Red", "Yellow", "Gray", "Blue","Green"
    public int              nSpeed;                     // 速度 单位Km/H
    public byte[]             szEvent       = new byte[64];                 // 触发的相关事件 参见事件列表Event List，只包含交通相关事件。
    public byte[]             szViolationCode= new byte[32];           // 违章代码 详见TrafficGlobal.ViolationCode
    public byte[]             szViolationDesc= new byte[64];           // 违章描述
    public int              nLowerSpeedLimit;             // 速度下限
    public int              nUpperSpeedLimit;             // 速度上限
    public int              nOverSpeedMargin;             // 限高速宽限值 单位：km/h 
    public int              nUnderSpeedMargin;            // 限低速宽限值 单位：km/h 
    public int              nLane;                      // 车道 参见事件列表Event List中卡口和路口事件。
    public int              nVehicleSize;                // 车辆大小,-1表示未知，否则按位第0位:"Light-duty",第1位:"Medium",第2位:"Oversize"
    public float            fVehicleLength;               // 车辆长度 单位米
    public int              nSnapshotMode;                // 抓拍方式 0-未分类，1-全景，2-近景，4-同向抓拍，8-反向抓拍，16-号牌图像
    public byte[]             szChannelName= new byte[32];            // 本地或远程的通道名称，可以是地点信息 来源于通道标题配置ChannelTitle.Name 
    public byte[]             szMachineName= new byte[256];            // 本地或远程设备名称 来源于普通配置General.MachineName
    public byte[]             szMachineGroup= new byte[256];           // 机器分组或叫设备所属单位 默认为空，用户可以将不同的设备编为一组，便于管理，可重复。
    public byte[]             szRoadwayNo= new byte[64];              // 道路编号
    public DH_DrivingDirection[]             szDrivingDirection = new DH_DrivingDirection[3];     // 
     // "DrivingDirection" : ["Approach", "上海", "杭州"],行驶方向
     // "Approach"-上行，即车辆离设备部署点越来越近；"Leave"-下行，
     // 即车辆离设备部署点越来越远，第二和第三个参数分别代表上行和
     // 下行的两个地点
    public String             szDeviceAddress;              // 设备地址,OSD叠加到图片上的,来源于配置TrafficSnapshot.DeviceAddress,'\0'结束
     
    public byte[]             bReserved = new byte[1024];              // 保留字节,留待扩展.
    }

    // 事件类型EVENT_IVS_CROSSLINEDETECTION(警戒线事件)对应的数据块描述信息
    public static class DEV_EVENT_CROSSLINE_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
     public DH_POINT[]          DetectLine = new DH_POINT[DH_MAX_DETECT_LINE_NUM];    // 规则检测线
    public int              nDetectLineNum;                    // 规则检测线顶点数
     public DH_POINT[]          TrackLine = new DH_POINT[DH_MAX_TRACK_LINE_NUM];     // 物体运动轨迹
    public int              nTrackLineNum;                    // 物体运动轨迹顶点数
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte              bDirection;                 // 表示入侵方向, 0-由左至右, 1-由右至左
    public byte[]              byReserved = new byte[2];
    public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved= new byte[612];        // 保留字节,留待扩展.

    }

    // 事件类型EVENT_IVS_CROSSREGIONDETECTION(警戒区事件)对应的数据块描述信息
    public static class DEV_EVENT_CROSSREGION_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved2 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
    public int              nDetectRegionNum;                     // 规则检测区域顶点数
     public DH_POINT[]          TrackLine = new DH_POINT[DH_MAX_TRACK_LINE_NUM];        // 物体运动轨迹
    public int              nTrackLineNum;                        // 物体运动轨迹顶点数
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte              bDirection;                 // 表示入侵方向, 0-进入, 1-离开，2-出现，3-离开
    public byte              bActionType;                // 表示检测动作类型,0-出现 1-消失 2-在区域内 3-穿越区域
    public byte       bReserved1;        // 对齐字节
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved = new byte[540];        // 保留字节,留待扩展.
    public int              nObjectNum;                 // 检测到的物体个数
    public DH_MSG_OBJECT[]   stuObjectIDs = new DH_MSG_OBJECT[DH_MAX_OBJECT_LIST]; // 检测到的物体
    public int              nTrackNum;                     // 轨迹数(与检测到的物体个数对应)
    public DH_POLY_POINTS[]      stuTrackInfo = new DH_POLY_POINTS[DH_MAX_OBJECT_LIST];   // 轨迹信息(与检测到的物体对应)
    }


    // 事件类型EVENT_IVS_PASTEDETECTION(贴条事件)对应的数据块描述信息
    public static class DEV_EVENT_PASTE_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public int              nDetectRegionNum;      // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public byte[]       bReserved = new byte[888];         // 保留字节,留待扩展.

    }

    // 事件类型EVENT_IVS_LEFTDETECTION(物品遗留事件)对应的数据块描述信息
    public static class DEV_EVENT_LEFT_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
    public int              nDetectRegionNum;      // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved = new byte[624];         // 保留字节,留待扩展.

    }

    // 事件类型EVENT_IVS_PRESERVATION(物品保全事件)对应的数据块描述信息
    public static class DEV_EVENT_PRESERVATION_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
    public int              nDetectRegionNum;      // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved = new byte[624];         // 保留字节,留待扩展.

    }

    // 事件类型EVENT_IVS_STAYDETECTION(停留事件)对应的数据块描述信息
    public static class DEV_EVENT_STAY_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
    public int              nDetectRegionNum;      // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved = new byte[624];         // 保留字节,留待扩展.

    }

    // 事件类型EVENT_IVS_WANDERDETECTION(徘徊事件)对应的数据块描述信息
    public static class DEV_EVENT_WANDER_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];               // 保留字节
    public int              nObjectNum;                 // 检测到的物体个数
    public DH_MSG_OBJECT[]   stuObjectIDs = new DH_MSG_OBJECT[DH_MAX_OBJECT_LIST]; // 检测到的物体
    public int              nTrackNum;                  // 轨迹数(与检测到的物体个数对应)
    public DH_POLY_POINTS[]      stuTrackInfo = new DH_POLY_POINTS[DH_MAX_OBJECT_LIST];// 轨迹信息(与检测到的物体对应)
    public int              nDetectRegionNum;      // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved = new byte[760];        // 保留字节,留待扩展.

    }
    
    // 事件类型EVENT_IVS_MOVEDETECTION(移动事件)对应的数据块描述信息
    public static class DEV_EVENT_MOVE_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
    public int              nDetectRegionNum;      // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved = new byte[624];        // 保留字节,留待扩展.

    }

    // 事件类型EVENT_IVS_TAILDETECTION(尾随事件)对应的数据块描述信息
    public static class DEV_EVENT_TAIL_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
    public int              nDetectRegionNum;      // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved = new byte[624];        // 保留字节,留待扩展.

    }

    // 事件类型EVENT_IVS_RIOTERDETECTION(聚众事件)对应的数据块描述信息
    public static class DEV_EVENT_RIOTER_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public int        nObjectNum;         // 检测到的物体个数
    public DH_MSG_OBJECT[]   stuObjectIDs = new DH_MSG_OBJECT[DH_MAX_OBJECT_LIST]; // 检测到的物体列表
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];               // 保留字节
    public int              nDetectRegionNum;      // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域

     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved = new byte[628];        // 保留字节,留待扩展.

    }

    // 事件类型EVENT_IVS_FIGHTDETECTION(斗殴事件)对应的数据块描述信息
    public static class DEV_EVENT_FIGHT_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public int        nObjectNum;         // 检测到的物体个数
    public DH_MSG_OBJECT[]   stuObjectIDs = new DH_MSG_OBJECT[DH_MAX_OBJECT_LIST]; // 检测到的物体列表
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];               // 保留字节
    public int              nDetectRegionNum;      // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
     
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved = new byte[628];        // 保留字节,留待扩展.

    }

    // 事件类型EVENT_IVS_FIREDETECTION(火警事件)对应的数据块描述信息
    public static class DEV_EVENT_FIRE_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];               // 保留字节
    public int              nDetectRegionNum;      // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
     
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved = new byte[624];        // 保留字节,留待扩展.

    }

    // 事件类型 EVENT_IVS_FIREDETECTION(电火花事件)对应的数据块描述信息
    public static class DEV_EVENT_ELECTROSPARK_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public byte[]       bReserved = new byte[972];        // 保留字节,留待扩展.
     
    }

    // 事件类型EVENT_IVS_SMOKEDETECTION(烟雾报警事件)对应的数据块描述信息
    public static class DEV_EVENT_SMOKE_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public byte[]       bReserved = new byte[972];        // 保留字节,留待扩展.

    }

    // 事件类型EVENT_IVS_FLOWSTAT(流量统计事件)对应的数据块描述信息
    public static class DEV_EVENT_FLOWSTAT_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public int        nNumberLeft;        // 从左边穿越的人的个数
    public int        nNumberRight;        // 从右边穿越的人的个数
    public int        nUpperLimit;        // 设置的上限
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public byte[]       bReserved = new byte[976];        // 保留字节,留待扩展.

    }

    // 事件类型EVENT_IVS_NUMBERSTAT(数量统计事件)对应的数据块描述信息
    public static class DEV_EVENT_NUMBERSTAT_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved2 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public int        nNumber;          // 区域内物体的个数
    public int        nUpperLimit;        // 设置的上限
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]       bReserved1 = new byte[3];        // 字节对齐
    public int              nEnteredNumber;              // 表示进入区域或者出入口的内物体的个数
    public int              nExitedNumber;               // 表示出来区域或者出入口的内物体的个数
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public byte[]       bReserved = new byte[964];        // 保留字节,留待扩展.

    }

    // 事件类型EVENT_IVS_CROSSFENCEDETECTION(翻越围栏事件)对应的数据块描述信息
    public static class DEV_EVENT_CROSSFENCEDETECTION_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public int        nUpstairsLinePointNumber;               // 围栏上边线顶点数
     public DH_POINT[]       stuUpstairsLine = new DH_POINT[DH_MAX_DETECT_LINE_NUM];    // 围栏上边线信息
    public int        nDownstairsLinePointNumber;               // 围栏下边线顶点数
     public DH_POINT[]       stuDownstairsLine = new DH_POINT[DH_MAX_DETECT_LINE_NUM];    // 围栏下边线信息  
    public int              nTrackLineNum;                           // 物体运动轨迹顶点数              
     public DH_POINT[]          TrackLine = new DH_POINT[DH_MAX_TRACK_LINE_NUM];            // 物体运动轨迹
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte              bDirection;                 // 表示入侵方向, 0-由左至右, 1-由右至左
    public byte[]              byReserved = new byte[2];
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved = new byte[752];         // 保留字节,留待扩展.
     
    }

    // 事件类型EVENT_IVS_INREGIONDETECTION(区域内检测事件)对应的数据块描述信息
    public static class DEV_EVENT_INREGIONDETECTION_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public int              nObjectNum;                 // 检测到的物体个数
    public DH_MSG_OBJECT[]   stuObjectIDs = new DH_MSG_OBJECT[DH_MAX_OBJECT_LIST]; // 检测到的物体
    public int              nTrackNum;                  // 轨迹数(与检测到的物体个数对应)
    public DH_POLY_POINTS[]      stuTrackInfo = new DH_POLY_POINTS[DH_MAX_OBJECT_LIST];// 轨迹信息(与检测到的物体对应)
    public int              nDetectRegionNum;      // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public byte[]       bReserved = new byte[1016];       // 保留字节,留待扩展.
     
    }

    // 事件类型EVENT_IVS_TAKENAWAYDETECTION(物品搬移事件)对应的数据块描述信息
    public static class DEV_EVENT_TAKENAWAYDETECTION_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public int              nDetectRegionNum;      // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved = new byte[752];              // 保留字节,留待扩展.
     
    }

    // 事件类型EVENT_IVS_VIDEOABNORMALDETECTION(视频异常事件)对应的数据块描述信息
    public static class DEV_EVENT_VIDEOABNORMALDETECTION_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte              bType;                     // 异常类型, 0-视频丢失, 1-视频冻结, 2-摄像头遮挡, 3-摄像头移动, 4-过暗, 5-过亮
    public byte[]              byReserved = new byte[2];
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved = new byte[756];         // 保留字节,留待扩展.
     
    }
    
    // 事件类型EVENT_IVS_PARKINGDETECTION(非法停车事件)对应的数据块描述信息
    public static class DEV_EVENT_PARKINGDETECTION_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public int              nDetectRegionNum;      // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved = new byte[752];              // 保留字节,留待扩展.
     
    }

    // 事件类型EVENT_IVS_ABNORMALRUNDETECTION(异常奔跑事件)对应的数据块描述信息
    public static class DEV_EVENT_ABNORMALRUNDETECTION 
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public double            dbSpeed;                    // 物体运动速度,km/h
    public double            dbTriggerSpeed;              // 触发速度,km/h
    public int              nDetectRegionNum;      // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
    public int              nTrackLineNum;                    // 物体运动轨迹顶点数              
     public DH_POINT[]          TrackLine = new DH_POINT[DH_MAX_TRACK_LINE_NUM];     // 物体运动轨迹
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte              bRunType;                   // 异常奔跑类型, 0-快速奔跑, 1-突然加速, 2-突然减速
    public byte[]              byReserved = new byte[2];
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved = new byte[752];         // 保留字节,留待扩展.
     
    }

    // 事件类型EVENT_IVS_RETROGRADEDETECTION(人员逆行事件)对应的数据块描述信息
    public static class DEV_EVENT_RETROGRADEDETECTION_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public int              nTrackLineNum;                      // 物体运动轨迹顶点数              
     public DH_POINT[]          TrackLine = new DH_POINT[DH_MAX_TRACK_LINE_NUM];       // 物体运动轨迹
    public int              nDirectionPointNum;                  // 规则里规定的方向顶点数
     public DH_POINT[]          stuDirections = new DH_POINT[DH_MAX_DETECT_LINE_NUM];   // 规则里规定的方向
    public int              nDetectRegionNum;             // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];  // 规则检测区域
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved = new byte[752];         // 保留字节,留待扩展.
     
    }

    // 事件类型EVENT_IVS_FACERECOGNITION(人脸识别)对应的数据块描述信息
    public static class DEV_EVENT_FACERECOGNITION_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public int              nCandidateNum;               // 当前人脸匹配到的候选对象数量
     CANDIDATE_INFO[]      stuCandidates = new CANDIDATE_INFO[DH_MAX_CANDIDATE_NUM]; // 当前人脸匹配到的候选对象信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]       bReserved = new byte[1023];       // 保留字节,留待扩展.
    }

    // 事件类型EVENT_IVS_DENSITYDETECTION(人员密度检测)对应数据块描述信息
    public static class DEV_EVENT_DENSITYDETECTTION_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public int        nObjectNum;         // 检测到的物体个数
    public DH_MSG_OBJECT[]   stuObjectIDs = new DH_MSG_OBJECT[DH_MAX_OBJECT_LIST]; // 检测到的物体列表
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];               // 保留字节
    public int              nDetectRegionNum;      // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
     
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved = new byte[756];        // 保留字节,留待扩展.
    }

    // 事件类型 EVENT_IVS_QUEUEDETECTION(排队检测报警事件)对应数据块描述信息
    public static class DEV_EVENT_QUEUEDETECTION_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved2 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]       bReserved1 = new byte[3];          // 保留字节,留待扩展.
     public DH_POINT[]          stuDetectLine = new DH_POINT[2];            // 规则检测线
    public byte[]       bReserved = new byte[1016];       // 保留字节,留待扩展.
    }

    // 事件类型EVENT_IVS_TRAFFICCONTROL(交通管制事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFICCONTROL_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public byte[]       bReserved = new byte[972];        // 保留字节,留待扩展.

    }

    // 事件类型EVENT_IVS_TRAFFICACCIDENT(交通事故事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFICACCIDENT_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public int        nObjectNum;         // 检测到的物体个数
    public DH_MSG_OBJECT[]   stuObjectIDs = new DH_MSG_OBJECT[DH_MAX_OBJECT_LIST]; // 检测到的物体列表
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public byte[]       bReserved = new byte[976];        // 保留字节,留待扩展.

    }

    // 事件类型EVENT_IVS_TRAFFICJUNCTION(交通路口老规则事件/视频电警上的交通卡口老规则事件)对应的数据块描述信息
    // 由于历史原因，如果要处理卡口事件，DEV_EVENT_TRAFFICJUNCTION_INFO和EVENT_IVS_TRAFFICGATE要一起处理，以防止有视频电警和线圈电警同时接入平台的情况发生
    // 另外EVENT_IVS_TRAFFIC_TOLLGATE只支持新卡口事件的配置
    public static class DEV_EVENT_TRAFFICJUNCTION_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public int        nLane;            // 对应车道号
    public int      dwBreakingRule;        // 违反规则掩码,第一位:闯红灯; 
     // 第二位:不按规定车道行驶;
     // 第三位:逆行; 第四位：违章掉头;
     // 第五位:交通堵塞; 第六位:交通异常空闲
     // 第七位:压线行驶; 否则默认为:交通路口事件
    public NET_TIME_EX     RedLightUTC;        // 红灯开始UTC时间
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public int              nSequence;                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    public int              nSpeed;                    // 车辆实际速度Km/h              
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];               // 保留字节
    public DH_MSG_OBJECT      stuVehicle;                 // 车身信息
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;               // 对应图片的分辨率
    public byte[]       bReserved = new byte[472];         // 保留字节,留待扩展.
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;    // 交通车辆信息

    }


    // 事件类型EVENT_IVS_TRAFFICGATE(交通卡口老规则事件/线圈电警上的交通卡口老规则事件)对应的数据块描述信息
    // 由于历史原因，如果要处理卡口事件，DEV_EVENT_TRAFFICJUNCTION_INFO和EVENT_IVS_TRAFFICGATE要一起处理，以防止有视频电警和线圈电警同时接入平台的情况发生
    // 另外EVENT_IVS_TRAFFIC_TOLLGATE只支持新卡口事件的配置
    public static class DEV_EVENT_TRAFFICGATE_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public int        nLane;            // 对应车道号
    public int        nSpeed;           // 车辆实际速度Km/h
    public int        nSpeedUpperLimit;      // 速度上限 单位：km/h
    public int        nSpeedLowerLimit;      // 速度下限 单位：km/h 
    public int      dwBreakingRule;        // 违反规则掩码,第一位:逆行; 
     // 第二位:压线行驶; 第三位:超速行驶; 
     // 第四位：欠速行驶; 第五位:闯红灯;第六位:穿过路口(卡口事件)
     // 第七位: 压黄线; 第八位: 有车占道; 第九位: 黄牌占道;否则默认为:交通卡口事件
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息    
    public DH_MSG_OBJECT      stuVehicle;                 // 车身信息
    public byte[]              szManualSnapNo = new byte[64];           // 手动抓拍序号             
    public int              nSequence;                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束; 
    public byte[]              byReserved = new byte[3];               // 保留字节
    public byte[]              szSnapFlag = new byte[16];              // 设备产生的抓拍标识
    public byte              bySnapMode;                 // 抓拍方式，0-未分类 1-全景 2-近景 4-同向抓拍 8-反向抓拍 16-号牌图像
    public byte              byOverSpeedPercentage;        // 超速百分比
    public byte              byUnderSpeedingPercentage;     // 欠速百分比
    public byte              byRedLightMargin;            // 红灯容许间隔时间,单位：秒
    public byte              byDriveDirection;            // 行驶方向，0-上行(即车辆离设备部署点越来越近)，1-下行(即车辆离设备部署点越来越远)
    public byte[]              szRoadwayNo = new byte[32];             // 道路编号
    public byte[]              szViolationCode = new byte[16];          // 违章代码
    public byte[]              szViolationDesc = new byte[128];         // 违章描述
    public DH_RESOLUTION_INFO  stuResolution;               // 对应图片的分辨率
    public byte[]              szVehicleType = new byte[32];            // 车辆大小类型，"Motor" 摩托车车 "Light-duty" 小型车 "Medium" 中型车 "Oversize" 大型车 "Huge" 超大车 "Other" 其他类型
    public byte              byVehicleLenth;              // 车辆长度, 单位米
    public byte[]              byReserved1 = new byte[3];              // 保留字节,留待扩展
    public int              nOverSpeedMargin;            // 限高速宽限值 单位：km/h 
    public int              nUnderSpeedMargin;            // 限低速宽限值 单位：km/h 
    public DH_DrivingDirection[]             szDrivingDirection = new DH_DrivingDirection[3];     // 
     // "DrivingDirection" : ["Approach", "上海", "杭州"],行驶方向
     // "Approach"-上行，即车辆离设备部署点越来越近；"Leave"-下行，
     // 即车辆离设备部署点越来越远，第二和第三个参数分别代表上行和
     // 下行的两个地点，UTF-8编码
    public byte[]              szMachineName = new byte[256];           // 本地或远程设备名称
    public byte[]              szMachineAddress = new byte[256];        // 机器部署地点、道路编码
    public byte[]              szMachineGroup = new byte[256];          // 机器分组、设备所属单位
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_SIG_CARWAY_INFO_EX stuSigInfo;                // 由车检器产生抓拍信号冗余信息
    public byte[]              szFilePath = new byte[MAX_PATH];         // 文件路径
    public NET_TIME_EX     RedLightUTC;        // 红灯开始UTC时间
    public String            szDeviceAddress;             // 设备地址,OSD叠加到图片上的,来源于配置TrafficSnapshot.DeviceAddress,'\0'结束
    public byte[]       bReserved = new byte[3664];       // 保留字节,留待扩展.
    }

//事件类型EVENT_TRAFFICSNAPSHOT(交通抓拍事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFICSNAPSHOT_INFO extends Structure
    {
    public int        nChannelID;           // 通道号
    public byte[]       szName = new byte[128];          // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;             // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;               // 事件发生的时间
    public int        nEventID;            // 事件ID
    public byte[]              bReserv = new byte[3];                   // 保留字节 
    public byte              bCarWayCount;                 // 触发抓拍的车道个数
    public DH_CARWAY_INFO[]      stuCarWayInfo = new DH_CARWAY_INFO[DH_MAX_CARWAY_NUM]; // 触发抓拍的车道相关信息
    public DH_EVENT_FILE_INFO  stuFileInfo;          // 事件对应文件信息
    public byte              bEventAction;         // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;                // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public byte[]       bReserved = new byte[344];           // 保留字节,留待扩展
    }

//事件类型EVENT_IVS_TRAFFIC_RUNREDLIGHT(交通-闯红灯事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_RUNREDLIGHT_INFO extends Structure
    {
    public int        nChannelID;           // 通道号
    public byte[]       szName = new byte[128];          // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;             // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;                  // 事件发生的时间
    public int        nEventID;                // 事件ID
    public int        nLane;                  // 对应车道号
    public DH_MSG_OBJECT   stuObject;                    // 车牌信息
    public DH_MSG_OBJECT      stuVehicle;                   // 车身信息
    public DH_EVENT_FILE_INFO  stuFileInfo;                  // 事件对应文件信息 
    public int        nLightState;                // 红绿灯状态 0:未知 1：绿灯 2:红灯 3:黄灯
    public int        nSpeed;                   // 车速,km/h
    public int              nSequence;                    // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    public byte              bEventAction;         // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;                // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public NET_TIME_EX        stRedLightUTC;                // 红灯开始时间
    public DH_RESOLUTION_INFO  stuResolution;                // 对应图片的分辨率
    public byte              byRedLightMargin;              // 红灯容许间隔时间,单位：秒
    public byte[]       bReserved = new byte[975];                // 保留字节
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;      // 交通车辆信息
    }

//事件类型EVENT_IVS_TRAFFIC_OVERLINE(交通-压线事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_OVERLINE_INFO extends Structure
    {
    public int        nChannelID;    // 通道号
    public byte[]       szName = new byte[128];    // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;       // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;       // 事件发生的时间
    public int        nEventID;    // 事件ID
    public int        nLane;       // 对应车道号
    public DH_MSG_OBJECT   stuObject;     // 车牌信息
    public DH_MSG_OBJECT      stuVehicle;        // 车身信息
    public DH_EVENT_FILE_INFO  stuFileInfo;       // 事件对应文件信息
    public int              nSequence;        // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    public int              nSpeed;           // 车辆实际速度,Km/h
    public byte              bEventAction;   // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;    // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;     // 对应图片的分辨率
    public byte[]       bReserved = new byte[1008];  // 保留字节
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;      // 交通车辆信息
    }


//事件类型EVENT_IVS_TRAFFIC_RETROGRADE(交通-逆行事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_RETROGRADE_INFO extends Structure
    {
    public int        nChannelID;    // 通道号
    public byte[]       szName = new byte[128];    // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;       // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;       // 事件发生的时间
    public int        nEventID;    // 事件ID
    public int        nLane;       // 对应车道号
    public DH_MSG_OBJECT   stuObject;     // 车牌信息
    public DH_MSG_OBJECT      stuVehicle;        // 车身信息
    public DH_EVENT_FILE_INFO  stuFileInfo;       // 事件对应文件信息
    public int              nSequence;        // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    public int              nSpeed;           // 车辆实际速度,Km/h
    public byte              bEventAction;   // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;    // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;     // 对应图片的分辨率

    public byte[]       bReserved = new byte[1004];  // 保留字节
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;    // 交通车辆信息

    }

//事件类型EVENT_IVS_TRAFFIC_TURNLEFT(交通-违章左转)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_TURNLEFT_INFO extends Structure
    {
    public int        nChannelID;    // 通道号
    public byte[]       szName = new byte[128];    // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;       // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;       // 事件发生的时间
    public int        nEventID;    // 事件ID
    public int        nLane;       // 对应车道号
    public DH_MSG_OBJECT   stuObject;     // 车牌信息
    public DH_MSG_OBJECT      stuVehicle;        // 车身信息
    public DH_EVENT_FILE_INFO  stuFileInfo;       // 事件对应文件信息
    public int              nSequence;        // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    public int              nSpeed;           // 车辆实际速度,Km/h
    public byte              bEventAction;   // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;    // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;     // 对应图片的分辨率

    public byte[]       bReserved = new byte[1008];  // 保留字节
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;    // 交通车辆信息

    }


//事件类型EVENT_IVS_TRAFFIC_TURNRIGHT(交通-违章右转)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_TURNRIGHT_INFO extends Structure
    {
    public int        nChannelID;    // 通道号
    public byte[]       szName = new byte[128];    // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;       // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;       // 事件发生的时间
    public int        nEventID;    // 事件ID
    public int        nLane;       // 对应车道号
    public DH_MSG_OBJECT   stuObject;     // 车牌信息
    public DH_MSG_OBJECT      stuVehicle;        // 车身信息
    public DH_EVENT_FILE_INFO  stuFileInfo;       // 事件对应文件信息
    public int              nSequence;        // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    public int              nSpeed;           // 车辆实际速度,Km/h
    public byte              bEventAction;   // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;    // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;     // 对应图片的分辨率

    public byte[]       bReserved = new byte[1008];  // 保留字节
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;    // 交通车辆信息
    }

//事件类型EVENT_IVS_TRAFFIC_UTURN(违章调头事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_UTURN_INFO extends Structure
    {
    public int        nChannelID;           // 通道号
    public byte[]       szName = new byte[128];          // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;             // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;               // 事件发生的时间
    public int        nEventID;            // 事件ID
    public int        nLane;             // 对应车道号
    public DH_MSG_OBJECT   stuObject;            // 检测到的物体
    public DH_MSG_OBJECT      stuVehicle;                   // 车身信息
    public DH_EVENT_FILE_INFO  stuFileInfo;          // 事件对应文件信息
    public int              nSequence;                    // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    public int              nSpeed;                      // 车辆实际速度,Km/h
    public byte              bEventAction;              // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;                // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;                // 对应图片的分辨率
     
    public byte[]              bReserved = new byte[1008];        // 保留字节
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;      // 交通车辆信息
    }

//事件类型EVENT_IVS_TRAFFIC_OVERSPEED(交通超速事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_OVERSPEED_INFO extends Structure
    {
    public int        nChannelID;           // 通道号
    public byte[]       szName = new byte[128];          // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;             // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;               // 事件发生的时间
    public int        nEventID;            // 事件ID
    public int        nLane;             // 对应车道号
    public DH_MSG_OBJECT   stuObject;            // 检测到的物体
    public DH_MSG_OBJECT      stuVehicle;                   // 车身信息
    public DH_EVENT_FILE_INFO  stuFileInfo;          // 事件对应文件信息
     public int              nSpeed;                      // 车辆实际速度Km/h
    public int        nSpeedUpperLimit;         // 速度上限 单位：km/h
    public int        nSpeedLowerLimit;        // 速度下限 单位：km/h 
    public int              nSequence;                    // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束; 
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;                // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;                // 对应图片的分辨率

    public byte[]              bReserved = new byte[1008];        // 保留字节
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;      // 交通车辆信息
    }

//事件类型EVENT_IVS_TRAFFIC_UNDERSPEED(交通欠速事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_UNDERSPEED_INFO extends Structure
    {
    public int        nChannelID;           // 通道号
    public byte[]       szName = new byte[128];          // 事件名称
    public byte[]              bReserved2 = new byte[4];                // 字节对齐
    public double       PTS;             // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;               // 事件发生的时间
    public int        nEventID;            // 事件ID
    public int        nLane;             // 对应车道号
    public DH_MSG_OBJECT   stuObject;            // 检测到的物体
    public DH_MSG_OBJECT      stuVehicle;                   // 车身信息
    public DH_EVENT_FILE_INFO  stuFileInfo;          // 事件对应文件信息
     public int              nSpeed;                      // 车辆实际速度Km/h
    public int        nSpeedUpperLimit;         // 速度上限 单位：km/h
    public int        nSpeedLowerLimit;        // 速度下限 单位：km/h 
    public int              nSequence;                    // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    public byte              bEventAction;              // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
     public byte[]              bReserved1 = new byte[3];                // 对齐
    public int              nUnderSpeedingPercentage;        // 欠速百分比
     public int             dwSnapFlagMask;                // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;                // 对应图片的分辨率
     
    public byte[]              bReserved = new byte[1004];        // 保留字节
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;      // 交通车辆信息

    }

//事件类型EVENT_IVS_FACEDETECT(人脸检测事件)对应的数据块描述信息
    public static class DEV_EVENT_FACEDETECT_INFO extends Structure
    {
    public int        nChannelID;           // 通道号
    public byte[]       szName = new byte[128];          // 事件名称
    public byte[]              bReserved1 = new byte[4];                // 字节对齐
    public double       PTS;             // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;               // 事件发生的时间
    public int        nEventID;            // 事件ID
    public DH_MSG_OBJECT   stuObject;            // 检测到的物体
    public DH_EVENT_FILE_INFO  stuFileInfo;          // 事件对应文件信息
    public byte              bEventAction;                 // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              reserved = new byte[3];                  // 保留字节
    public int              nDetectRegionNum;        // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
     public int             dwSnapFlagMask;                // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public byte[]       bReserved = new byte[936];         // 保留字节,留待扩展
    }

    // 事件类型EVENT_IVS_TRAFFICJAM(交通拥堵事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFICJAM_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public int        nLane;            // 对应车道号
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息             
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              reserved = new byte[3];                // 保留字节
    public NET_TIME_EX        stuStartJamTime;       // 开始停车时间
    public int              nSequence;                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束(bEventAction=2时此参数有效)
    public int              nAlarmIntervalTime;           // 报警时间间隔，单位:秒。(此事件为连续性事件，在收到第一个此事件之后，若在超过间隔时间后未收到此事件的后续事件，则认为此事件异常结束了)
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;               // 对应图片的分辨率
    public byte[]       bReserved = new byte[1012];       // 保留字节,留待扩展.
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;    // 交通车辆信息 
    }

    // 事件类型EVENT_IVS_TRAFFIC_PARKING(交通违章停车事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_PARKING_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_MSG_OBJECT      stuVehicle;                 // 车身信息
    public int        nLane;            // 对应车道号
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息             
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              reserved = new byte[3];                // 保留字节
    public NET_TIME_EX        stuStartParkingTime;          // 开始停车时间
    public int              nSequence;                  // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束(bEventAction=2时此参数有效)
    public int              nAlarmIntervalTime;           // 报警时间间隔，单位:秒。(此事件为连续性事件，在收到第一个此事件之后，若在超过间隔时间后未收到此事件的后续事件，则认为此事件异常结束了)
    public int              nParkingAllowedTime;          // 允许停车时长，单位：秒。
    public int              nDetectRegionNum;      // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;               // 对应图片的分辨率
    public byte[]       bReserved = new byte[924];         // 保留字节,留待扩展.
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;    // 交通车辆信息
     
    }

//事件类型EVENT_IVS_TRAFFIC_WRONGROUTE(交通违章-不按车道行驶)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_WRONGROUTE_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_MSG_OBJECT      stuVehicle;                 // 车身信息
    public int        nLane;            // 对应车道号
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息             
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];         
    public int              nSpeed;                    // 车辆实际速度，km/h
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;               // 对应图片的分辨率
    public byte[]       bReserved = new byte[1012];       // 保留字节,留待扩展.
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;    // 交通车辆信息

    }

//事件类型EVENT_IVS_TRAFFIC_CROSSLANE(交通违章-违章变道)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_CROSSLANE_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_MSG_OBJECT      stuVehicle;                 // 车身信息
    public int        nLane;            // 对应车道号
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息             
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];         
    public int              nSpeed;                    // 车辆实际速度，km/h
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;               // 对应图片的分辨率
    public byte[]       bReserved = new byte[1008];       // 保留字节,留待扩展.留待扩展.
     
    }

//事件类型EVENT_IVS_TRAFFIC_OVERYELLOWLINE(交通违章-压黄线)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_OVERYELLOWLINE_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_MSG_OBJECT      stuVehicle;                 // 车身信息
    public int        nLane;            // 对应车道号
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息             
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];         
    public int              nSpeed;                    // 车辆实际速度，km/h
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;               // 对应图片的分辨率
    public byte[]       bReserved = new byte[1012];       // 保留字节,留待扩展.
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;    // 交通车辆信息
     
    }

//事件类型EVENT_IVS_TRAFFIC_DRIVINGONSHOULDER(交通违章-路肩行驶事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_DRIVINGONSHOULDER_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_MSG_OBJECT      stuVehicle;                 // 车身信息
    public int        nLane;            // 对应车道号
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息             
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];         
    public int              nSpeed;                    // 车辆实际速度，km/h
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;               // 对应图片的分辨率
    public byte[]       bReserved = new byte[1008];       // 保留字节,留待扩展.
     
    }

//事件类型EVENT_IVS_TRAFFIC_YELLOWPLATEINLANE(交通违章-黄牌车占道事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_YELLOWPLATEINLANE_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_MSG_OBJECT      stuVehicle;                 // 车身信息
    public int        nLane;            // 对应车道号
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息             
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];         
    public int              nSpeed;                    // 车辆实际速度，km/h
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;               // 对应图片的分辨率
    public byte[]       bReserved = new byte[1016];       // 保留字节,留待扩展.
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;    // 交通车辆信息
     
    }

//事件类型EVENT_IVS_TRAFFIC_NOPASSING(交通违章-禁止通行事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_NOPASSING_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public int              UTCMS;                     // 
    public int              nMark;                     // 
    public int              nSequence;                  // 表示抓拍序号，如3-2-1/0，1表示抓拍正常结束，0表示抓拍异常结束
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;    // TrafficCar表示交通车辆的数据库记录
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;               // 对应图片的分辨率
    public byte[]       bReserved = new byte[1016];       // 保留字节,留待扩展.
    }

    public static class DH_TRAFFICFLOWSTAT
    {
    public byte[]       szMachineAddress = new byte[256];     // 同DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO.MachineGroup
    public byte[]       szMachineName = new byte[256];      // 同DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO.MachineName
    public DH_DrivingDirection[]             szDrivingDirection = new DH_DrivingDirection[3];     // 行驶方向"Approach"-上行，即车辆离设备部署点越来越近；"Leave"-下行，即车辆离设备部署点越来越远，第二和第三个参数分别代表上行和下行的两个地点，UTF-8编码
    public int        nLane;            // 车道号 使用用户配置的车道编号
    public NET_TIME_EX     UTC;            // 统计时间，转换到UTC
    public int        nPeriod;          // 统计周期，单位分钟
    public int        nVehicles;          // 通过车辆总数
    public float      fAverageSpeed;        // 平均车速，单位km/h
    public float      fAverageLength;        // 平均车长，单位米
    public float      fTimeOccupyRatio;      // 时间占有率，即单位时间内通过断面的车辆所用时间的总和占单位时间的比例
    public float      fSpaceOccupyRatio;       // 空间占有率，即按百分率计量的车辆长度总和除以时间间隔内车辆平均行驶距离
    public float      fSpaceHeadway;        // 车头间距，相邻车辆之间的距离，单位米/辆
    public float      fTimeHeadway;        // 车头时距，单位秒/辆
    public float      fDensity;         // 车辆密度，每公里的车辆数，单位辆/km
    public int        nOverSpeedVehicles;      // 超速车辆数
    public int        nUnderSpeedVehicles;     // 低速车辆数
    public int        nLargeVehicles;        // 大车数量  车辆类型判断标准参见TrafficSnapshot配置表
    public int        nMediumVehicles;       // 中型车数量
    public int        nSmallVehicles;        // 小车数量
    public int        nMotoVehicles;        // 摩托车数量
    public int        nLongVehicles;        // 超长车数量
    }
    // 事件类型 EVENT_IVS_TRAFFIC_FLOWSTATE(交通流量统计事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_FLOWSTAT_INFO extends Structure
    {
    public byte[]       szName = new byte[128];        // 事件名称
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public int        nLaneCnt;         // 通道总数
    public DH_TRAFFICFLOWSTAT[]  stTrafficFlowStats = new DH_TRAFFICFLOWSTAT[DH_MAX_LANE_NUM];//流量统计记录，是一个数组
    public byte[]       Reserved = new byte[4];        // 保留字节对齐
    }

//事件类型EVENT_IVS_TRAFFIC_MANUALSNAP(交通手动抓拍事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_MANUALSNAP_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public int        nLane;            // 对应车道号
    public byte[]              szManualSnapNo = new byte[64];           // 手动抓拍序号 
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_MSG_OBJECT      stuVehicle;                 // 检测到的车身信息
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;    // 表示交通车辆的数据库记录
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
    public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;               // 对应图片的分辨率
    public byte[]       bReserved = new byte[1016];       // 保留字节,留待扩展.
    }

//事件类型 EVENT_IVS_TRAFFIC_STAY(交通滞留事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_STAY_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_MSG_OBJECT      stuVehicle;                 // 车身信息
    public int        nLane;            // 对应车道号
    public int        nSequence;          // 抓拍序号，如3-2-1/0，1表示抓拍正常结束，0表示抓拍异常结束
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;    // 表示交通车辆的数据库记录
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息             
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved0 = new byte[3];
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;               // 对应图片的分辨率
    public byte[]              byReserved = new byte[1012];         
    }

//事件类型 EVENT_IVS_TRAFFIC_VEHICLEINROUTE(有车占道事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_VEHICLEINROUTE_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_MSG_OBJECT      stuVehicle;                 // 车身信息
    public int        nLane;            // 对应车道号
    public int        nSequence;          // 抓拍序号，如3-2-1/0，1表示抓拍正常结束，0表示抓拍异常结束
    public int        nSpeed;           // 车速
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;    // 表示交通车辆的数据库记录
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息             
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved0 = new byte[3];
     public int             dwSnapFlagMask;              // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DH_RESOLUTION_INFO  stuResolution;               // 对应图片的分辨率
    public byte[]              byReserved = new byte[1016];         
    }

    // 报警事件类型 EVENT_ALARM_LOCALALARM(外部报警)和EVENT_ALARM_MOTIONALARM(动检报警)
    public static class DEV_EVENT_ALARM_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]       Reserved = new byte[4];        // 保留字节对齐 
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID                                                                                                                                                                                                                     
    }

    // 事件类型 EVENT_IVS_PRISONERRISEDETECTION (看守所囚犯起身事件) 对应的数据块描述信息
    public static class DEV_EVENT_PRISONERRISEDETECTION_INFO extends Structure
    {
    public int        nChannelID;           // 通道号
    public byte[]       szName = new byte[128];          // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;             // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;               // 事件发生的时间
    public int        nEventID;            // 事件ID
    public DH_MSG_OBJECT   stuObject;            // 检测到的物体
    public int              nDetectRegionNum;        // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
    public DH_EVENT_FILE_INFO  stuFileInfo;                  // 事件对应文件信息
    public double       dInitialUTC;            // 事件初始UTC时间  UTC为事件的UTC (1970-1-1 00:00:00)秒数。
    public byte              bEventAction;                 // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;                // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public int              nSourceIndex;                // 事件源设备上的index,-1表示数据无效
    public byte[]              szSourceDevice = new byte[MAX_PATH];      // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public byte[]       bReserved = new byte[752];         // 保留字节,留待扩展.
    }

//事件类型 EVENT_IVS_TRAFFIC_PEDESTRAINPRIORITY(斑马线行人优先事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_PEDESTRAINPRIORITY_INFO extends Structure
    {
    public int              nChannelID;                   // 通道号
    public byte[]              szName = new byte[128];                  // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double            PTS;                        // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;                        // 事件发生的时间
    public int              nEventID;                    // 事件ID
    public DH_MSG_OBJECT   stuObject;                    // 检测到的物体
    public DH_MSG_OBJECT      stuVehicle;                   // 车身信息
    public DH_EVENT_FILE_INFO  stuFileInfo;                  // 事件对应文件信息
    public int              nLane;                       // 对应车道号
    public double       dInitialUTC;            // 事件初始UTC时间  UTC为事件的UTC (1970-1-1 00:00:00)秒数。
    public byte              bEventAction;                 // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
    public int             dwSnapFlagMask;                // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;      // 表示交通车辆的数据库记录
    public DH_RESOLUTION_INFO  stuResolution;                // 对应图片的分辨率
    public byte[]              bReserved = new byte[1024];               // 保留字节,留待扩展.
    }

//事件类型 EVENT_IVS_TRAFFIC_VEHICLEINBUSROUTE(占用公交车道事件)对应的数据块描述信息
    public static class DEV_EVENT_TRAFFIC_VEHICLEINBUSROUTE_INFO extends Structure
    {
    public int              nChannelID;                   // 通道号
    public byte[]              szName = new byte[128];                  // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double            PTS;                        // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;                        // 事件发生的时间
    public int              nEventID;                    // 事件ID
    public DH_MSG_OBJECT   stuObject;                    // 检测到的物体
    public DH_MSG_OBJECT      stuVehicle;                   // 车身信息
    public DH_EVENT_FILE_INFO  stuFileInfo;                  // 事件对应文件信息
    public int              nLane;                       // 对应车道号
    public int        nSequence;            // 抓拍序号，如3-2-1/0，1表示抓拍正常结束，0表示抓拍异常结束
    public int        nSpeed;            // 车速，km/h
    public byte              bEventAction;                 // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
    public int             dwSnapFlagMask;                // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;      // 表示交通车辆的数据库记录
    public DH_RESOLUTION_INFO  stuResolution;                // 对应图片的分辨率
    public byte[]              bReserved = new byte[1020];               // 保留字节,留待扩展.
    }

//事件类型 EVENT_IVS_TRAFFIC_BACKING(违章倒车事件)对应的数据块描述信息
    public static class DEV_EVENT_IVS_TRAFFIC_BACKING_INFO extends Structure
    {
    public int              nChannelID;                   // 通道号
    public byte[]              szName = new byte[128];                  // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double            PTS;                        // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;                        // 事件发生的时间
    public int              nEventID;                    // 事件ID
    public DH_MSG_OBJECT   stuObject;                    // 检测到的物体
    public DH_MSG_OBJECT      stuVehicle;                   // 车身信息
    public DH_EVENT_FILE_INFO  stuFileInfo;                  // 事件对应文件信息
    public int              nLane;                       // 对应车道号
    public int        nSequence;            // 抓拍序号，如3-2-1/0，1表示抓拍正常结束，0表示抓拍异常结束
    public int        nSpeed;            // 车速，km/h
    public byte              bEventAction;                 // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
    public int             dwSnapFlagMask;                // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;      // 表示交通车辆的数据库记录
    public DH_RESOLUTION_INFO  stuResolution;                // 对应图片的分辨率
    public byte[]              bReserved = new byte[1020];               // 保留字节,留待扩展.
    }

//事件类型EVENT_IVS_AUDIO_ABNORMALDETECTION(声音异常检测)对应数据块描述信息
    public static class DEV_EVENT_IVS_AUDIO_ABNORMALDETECTION_INFO extends Structure
    {
    public int              nChannelID;                   // 通道号
    public byte[]              szName = new byte[128];                  // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double            PTS;                        // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;                        // 事件发生的时间
    public int              nEventID;                    // 事件ID
    public DH_EVENT_FILE_INFO  stuFileInfo;                  // 事件对应文件信息
    public int              nDecibel;                    // 声音强度
    public int              nFrequency;                   // 声音频率
    public byte              bEventAction;                 // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
    public int             dwSnapFlagMask;                // 抓图标志(按位)，具体见NET_RESERVED_COMMON
    public DH_RESOLUTION_INFO  stuResolution;                // 对应图片的分辨率
    public byte[]              bReserved = new byte[1024];               // 保留字节,留待扩展.
    }

//事件类型 EVENT_IVS_TRAFFIC_RUNYELLOWLIGHT(交通违章-闯黄灯事件)对应数据块描述信息
    public static class DEV_EVENT_TRAFFIC_RUNYELLOWLIGHT_INFO extends Structure
    {
    public int        nChannelID;           // 通道号
    public byte[]       szName = new byte[128];          // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;             // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;                  // 事件发生的时间
    public int        nEventID;                // 事件ID
    public int        nLane;                  // 对应车道号
    public DH_MSG_OBJECT   stuObject;                    // 车牌信息
    public DH_MSG_OBJECT      stuVehicle;                   // 车身信息
    public DH_EVENT_FILE_INFO  stuFileInfo;                  // 事件对应文件信息 
    public int        nLightState;                // 红绿灯状态 0:未知 1：绿灯 2:红灯 3:黄灯
    public int        nSpeed;                   // 车速,km/h
    public int              nSequence;                    // 表示抓拍序号，如3,2,1,1表示抓拍结束,0表示异常结束
    public byte              bEventAction;         // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]              byReserved = new byte[3];
     public int             dwSnapFlagMask;                // 抓图标志(按位)，具体见NET_RESERVED_COMMON  
    public NET_TIME_EX        stYellowLightUTC;              // 黄灯开始时间
     public int       nYellowLightPeriod;            // 黄灯周期间隔时间,单位秒
    public DH_RESOLUTION_INFO  stuResolution;                // 对应图片的分辨率
    public byte              byRedLightMargin;              // 黄灯容许间隔时间,单位：秒
    public byte[]              szSourceDevice = new byte[MAX_PATH];        // 事件源设备唯一标识,字段不存在或者为空表示本地设备
    public DEV_EVENT_TRAFFIC_TRAFFICCAR_INFO stTrafficCar;      // 交通车辆信息
    public byte[]       bReserved = new byte[1024];             // 保留字节
    }

//事件类型 EVENT_IVS_LEAVEDETECTION(离岗检测事件)对应数据块描述信息
    public static class DEV_EVENT_IVS_LEAVE_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public DH_RESOLUTION_INFO  stuResolution;               // 对应图片的分辨率
    public int              nDetectRegionNum;      // 规则检测区域顶点数
     public DH_POINT[]          DetectRegion = new DH_POINT[DH_MAX_DETECT_REGION_NUM];    // 规则检测区域
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束; 
    public byte[]       bReserved = new byte[1027];            // 保留字节
    }

//事件类型 EVENT_IVS_CLIMBDETECTION(攀高检测事件)对应数据块描述信息
    public static class DEV_EVENT_IVS_CLIMB_INFO extends Structure
    {
    public int        nChannelID;         // 通道号
    public byte[]       szName = new byte[128];        // 事件名称
    public byte[]              bReserved1 = new byte[4];               // 字节对齐
    public double       PTS;            // 时间戳(单位是毫秒)
    public NET_TIME_EX     UTC;            // 事件发生的时间
    public int        nEventID;         // 事件ID
    public DH_MSG_OBJECT   stuObject;          // 检测到的物体
    public DH_EVENT_FILE_INFO  stuFileInfo;                // 事件对应文件信息
    public DH_RESOLUTION_INFO  stuResolution;               // 对应图片的分辨率
    public int              nDetectLineNum;                    // 规则检测线顶点数
     public DH_POINT[]          DetectLine = new DH_POINT[DH_MAX_DETECT_LINE_NUM];    // 规则检测线
    public byte              bEventAction;                // 事件动作，0表示脉冲事件,1表示持续性事件开始,2表示持续性事件结束;
    public byte[]       bReserved = new byte[1027];            // 保留字节
    }





	/************************************************************************
	 ** 回调
	 ***********************************************************************/
	//JNA CALLBACK方法定义,断线回调
	public interface fDisConnect extends StdCallCallback {
		public int invoke(NativeLong lLoginID, String pchDVRIP, int nDVRPort, NativeLong dwUser);
	}

	// 网络连接恢复回调函数原形
	public interface fHaveReConnect extends StdCallCallback {
	    public int invoke(NativeLong lLoginID, String pchDVRIP, int nDVRPort, NativeLong dwUser);
	}

	//JNA CALLBACK方法定义,只定义使用的CALLBACK
	public interface fAnalyzerDataCallBack extends StdCallCallback {  
	    public int invoke(NativeLong lAnalyzerHandle, int dwAlarmType, Pointer pAlarmInfo, Pointer pBuffer, int dwBufSize, NativeLong dwUser, int nSequence, Pointer reserved);  
	} 
	
	/************************************************************************
	 ** 接口
	 ***********************************************************************/
	//  JNA直接调用方法定义，cbDisConnect实际情况并不回调Java代码，仅为定义可以使用如下方式进行定义。
	public boolean CLIENT_Init(fDisConnect cbDisConnect, NativeLong dwUser);
	
	//  JNA直接调用方法定义，SDK退出清理
	public void CLIENT_Cleanup();
	
	//  JNA直接调用方法定义，设置断线重连成功回调函数，设置后SDK内部断线自动重连
	public void CLIENT_SetAutoReconnect(fHaveReConnect cbAutoConnect, NativeLong dwUser);
	
	// 返回函数执行失败代码
	public int CLIENT_GetLastError();

	// 设置连接设备超时时间和尝试次数
	public void CLIENT_SetConnectTime(int nWaitTime, int nTryTimes);

	// 设置登陆网络环境
	public void CLIENT_SetNetworkParam(NET_PARAM pNetParam);

	// 获取SDK的版本信息
	public int CLIENT_GetSDKVersion();
	
	//  JNA直接调用方法定义，登陆接口
	public NativeLong CLIENT_LoginEx(String pchDVRIP, short wDVRPort, String pchUserName, String pchPassword, int nSpecCap, Pointer pCapParam, NET_DEVICEINFO lpDeviceInfo, int[] error/*= 0*/);
	
	//  JNA直接调用方法定义，向设备注销
	public boolean CLIENT_Logout(NativeLong lLoginID);
	
	//  JNA直接调用方法定义，cbAnalyzerData实际情况需要回调Java代码，在实际调用该方法时使用CBAnalyzerData的实现类进行回调
	public NativeLong CLIENT_RealLoadPictureEx(NativeLong lLoginID, int nChannelID, int dwAlarmType, boolean bNeedPicFile, fAnalyzerDataCallBack cbAnalyzerData, NativeLong dwUser, Pointer Reserved);
	
	//  JNA直接调用方法定义，停止上传智能分析数据－图片
	public boolean CLIENT_StopLoadPic(NativeLong lAnalyzerHandle);
	
	// web信息上传接口
	public boolean  CLIENT_TransmitInfoForWeb(NativeLong lLoginID, String szInBuffer, int dwInBufferSize, byte[] szOutBuffer, int dwOutBufferSize, Pointer pReserved, int waittime/*=500*/);

}