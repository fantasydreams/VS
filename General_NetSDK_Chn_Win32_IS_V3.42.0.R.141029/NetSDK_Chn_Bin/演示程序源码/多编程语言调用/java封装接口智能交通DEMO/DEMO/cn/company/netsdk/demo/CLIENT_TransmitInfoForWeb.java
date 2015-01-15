/**
 * 
 */
package cn.company.netsdk.demo;

import cn.company.netsdk.NetSDKLib;

import com.sun.jna.NativeLong;
import com.sun.jna.Pointer;

/**
 * @author 12728
 *
 */
public class CLIENT_TransmitInfoForWeb {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// 打印版本信息
		NetSDKLibObj.CLIENT_GetSDKVersion();
		
		// 初始化
		NetSDKLibObj.CLIENT_Init(null, new NativeLong(0));
		System.out.println("dhnetsdk Init ok !");
		if ((args.length) > 0 && (!args[0].isEmpty()))
		{
			Login(args[0]);
		}
		else
		{
			Login(null);
		}

		if (0 != m_lNativeLoginID.longValue())
		{
			String szInBuffer = new String("{ \"id\" : 5, \"method\" : \"trafficSnap.getDeviceStatus\", \"object\" : 1, \"params\" : null, \"session\" : 1761480148 }");
			int dwInBufferSize = szInBuffer.length();
			System.out.println(new String(szInBuffer));
			
			int dwOutBufferSize = 1024;
			byte[] szOutBuffer = new byte[dwOutBufferSize];
			
			Pointer pReserved = null;
			int waittime = 5000;
			boolean bRet = NetSDKLibObj.CLIENT_TransmitInfoForWeb(m_lNativeLoginID, szInBuffer, dwInBufferSize, szOutBuffer, dwOutBufferSize, pReserved, waittime);
			if(false == bRet)
			{
				System.out.printf("CLIENT_TransmitInfoForWeb return failure, CLIENT_GetLastError is 0x%x !\n", NetSDKLibObj.CLIENT_GetLastError());
			}
			else
			{
				System.out.println(new String(szOutBuffer));
			}
		
		Logout();
		}
		NetSDKLibObj.CLIENT_Cleanup();
		System.out.println("dhnetsdk clean up ok !");
	}
	
	// SDK库实例
	static NetSDKLib NetSDKLibObj = NetSDKLib.INSTANCE;
	
	// 常量
	private static NetSDKLib.NET_DEVICEINFO m_stDeviceInfo ;
	private static NativeLong m_lNativeLoginID = new NativeLong(0);
	
	// 登陆接口封装
	public static void Login(String sIP) {
		if (0 != m_lNativeLoginID.longValue())
		{
			Logout();
		}
		m_stDeviceInfo = new NetSDKLib.NET_DEVICEINFO();
		//String m_strIP = new String("10.36.45.241");
		String m_strIP = new String("10.45.3.51");
		short m_sPort = (short)37777;
		String m_strUserName = new String("admin");
		String m_strUserPwd = new String("admin");
		int nSpecCap = 0;
		Pointer pCapParam = null;
		if ((sIP != null) && (!sIP.isEmpty()))
		{
			m_strIP = sIP;
		}
		int nError[] = {0};
		m_lNativeLoginID = NetSDKLibObj.CLIENT_LoginEx(m_strIP, m_sPort, m_strUserName,m_strUserPwd,nSpecCap,pCapParam, m_stDeviceInfo,nError);
		
		System.out.printf("[%d],%s:%d login %s, device type is %d, channal num is %d , err: %d, CLIENT_GetLastError:%d !\n",
				m_lNativeLoginID.longValue(),m_strIP,m_sPort,m_lNativeLoginID.longValue()>0?"ok":"failure",m_stDeviceInfo.byDVRType, m_stDeviceInfo.byChanNum, nError[0], NetSDKLibObj.CLIENT_GetLastError());
		if(0 == m_lNativeLoginID.longValue())
		{
			System.out.println("login return failure !");
		}
	}

	// 登出接口封装
	public static void Logout() {
		if (0 == m_lNativeLoginID.longValue())
		{
			System.out.println("login handle is error !");
			return ;
		}
		boolean bRet = NetSDKLibObj.CLIENT_Logout(m_lNativeLoginID);
		m_lNativeLoginID = new NativeLong(0);
		if(false == bRet)
		{
			System.out.println("logout out return failure !");
		}
		else
		{
			System.out.println("logout ok !");
		}
	}
}
