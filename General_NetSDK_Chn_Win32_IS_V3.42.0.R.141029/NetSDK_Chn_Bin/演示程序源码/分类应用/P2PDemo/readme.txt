说明：P2P功能需要P2P服务(IP\PORT\密钥)、已连接P2P服务器（在线）的设备才能穿透访问
例如：
1.P2P库：
Defs.h ProxyClientCWrap.h
Infra.lib litepi.lib NATTraver.lib P2PSDK.lib TouProxy.lib

2.网络SDK库：
dhassistant.h dhnetsdk.h
dhnetsdk.lib

3.P2P环境（IP\PORT\密钥）：
172.23.1.120 8800 YXQ3Mahe-5H-R1Z_

4.P2P环境上已有两设备在线：
77
PZC4FA492W00413

本demo使用VC2005编写的，建议使用VC2005打开。