package cn.company.netsdk.demo;

import com.sun.jna.NativeLong;
import com.sun.jna.Pointer;

import cn.company.netsdk.*;

import java.io.BufferedOutputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.lang.Class;
import java.lang.Object;
import java.lang.reflect.Field;

// 断线回调
class fDisConnectCB implements NetSDKLib.fDisConnect{
	public int invoke(NativeLong lLoginID, String pchDVRIP, int nDVRPort, NativeLong dwUser){
		System.out.printf("断线回调：%s:%d lLoginID is %d, dwUser is %d !\n",pchDVRIP, nDVRPort, lLoginID.longValue(), dwUser.longValue() );
		return 0;
	}	
}

// 网络连接恢复回调函数原形
class fHaveReConnectCB implements NetSDKLib.fHaveReConnect{
 public int invoke(NativeLong lLoginID, String pchDVRIP, int nDVRPort, NativeLong dwUser){
	 // 停止订阅用于释放资源
	 GetRealPic.StopRealPic();
	 // 重新订阅
	 GetRealPic.getRealPic();
	 return 0;
 }
}

// 智能实时信息及图片回调接口
class fAnalyzerDataCallBackCB implements NetSDKLib.fAnalyzerDataCallBack{
	public int invoke(NativeLong lAnalyzerHandle, int dwAlarmType, Pointer pAlarmInfo, Pointer pBuffer, int dwBufSize, NativeLong dwUser, int nSequence, Pointer reserved){

		System.out.printf("receive traffic picture !!!  handle:0x%x dwAlarmType:0x%x dwBufSize:%d dwUser:0x%x !\n",
				lAnalyzerHandle.longValue(),dwAlarmType, dwBufSize, dwUser.longValue());
		
		if (null == pAlarmInfo || null == pBuffer || 0 == dwBufSize)
		{
			return 0;
		}
		
        switch(dwAlarmType)
		{
		case NetSDKLib.EVENT_IVS_TRAFFIC_MANUALSNAP:
			GetRealPic.event_ivs_traffic_manualsnap_func(pAlarmInfo, pBuffer, dwBufSize);
			break;
		case NetSDKLib.EVENT_IVS_TRAFFIC_RUNREDLIGHT:
			GetRealPic.event_ivs_traffic_runredlight_func(pAlarmInfo, pBuffer, dwBufSize);
			break;
		case NetSDKLib.EVENT_IVS_TRAFFICGATE:
			GetRealPic.event_ivs_trafficgate_func(pAlarmInfo, pBuffer, dwBufSize);
			break;
		case NetSDKLib.EVENT_IVS_TRAFFICJUNCTION:
			GetRealPic.event_ivs_trafficjunction_func(pAlarmInfo, pBuffer, dwBufSize);
			break;
		default:
			return 0;
		}
		return 0;
	}	
}

// 订阅图片流程
public class GetRealPic{
	
	public static final String sDstPath = new String("./img/");
	
	public static void main(String[] args) throws InterruptedException{
		
		// 打印版本信息
		NetSDKLibObj.CLIENT_GetSDKVersion();
		
		// 初始化
		NetSDKLibObj.CLIENT_Init(new fDisConnectCB(), new NativeLong(0));
		System.out.println("dhnetsdk Init ok !");
		NetSDKLibObj.CLIENT_SetAutoReconnect(new fHaveReConnectCB(), new NativeLong(0));
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
		getRealPic();
		Thread.sleep(1000*60*100);
		StopRealPic();
		
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
	private static NativeLong m_lNativeRealPicHandle = new NativeLong(0);
	private static fAnalyzerDataCallBackCB cb = new fAnalyzerDataCallBackCB();
	
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
	
	// 停止订阅接口封装
	public static void StopRealPic(){
		if (0 != m_lNativeRealPicHandle.longValue())
		{
			NetSDKLibObj.CLIENT_StopLoadPic(m_lNativeRealPicHandle);
			System.out.println("stop real load picture ok !");
			m_lNativeRealPicHandle = new NativeLong(0);
		}
	}

	// 订阅接口封装
	public static void getRealPic()
	{
		if (0 != m_lNativeRealPicHandle.longValue())
		{
			System.out.println("can not be repeated subscriptions !");
			return ;
		}
		if (0 == m_lNativeLoginID.longValue())
		{
			System.out.println("please login first !");
			return ;
		}
		int nChannelID = 0; // 每次订阅一个通道的，ITC相机只有一个通道，ITS有多个通道
		int dwAlarmType = NetSDKLib.EVENT_IVS_ALL; // 默认全部报警订阅
		boolean bNeedPicFile = true; // 订阅上传图片,只要报警事件信息填false
		NativeLong dwUser = new NativeLong(0);
		Pointer Reserved = null;
		
		m_lNativeRealPicHandle = NetSDKLibObj.CLIENT_RealLoadPictureEx(
				m_lNativeLoginID,
				nChannelID,
				dwAlarmType,
				bNeedPicFile,
				cb,
				dwUser,
				Reserved
				);
		
		System.out.printf("[%d],real load picture %s, CLIENT_GetLastError:%d !\n",
				m_lNativeRealPicHandle.longValue(),m_lNativeRealPicHandle.longValue()>0?"ok":"failure",NetSDKLibObj.CLIENT_GetLastError());
		
		if (0 == m_lNativeRealPicHandle.longValue())
		{
			System.out.println("real load picture failure !");

		}
	}
	
	public static void event_ivs_traffic_runredlight_func(Pointer pAlarmInfo, Pointer pBuf, int dwBufSize)
	{
		if (null == pAlarmInfo || null == pBuf || 0 == dwBufSize)
		{
			return ;
		}
		NetSDKLib.DEV_EVENT_TRAFFIC_RUNREDLIGHT_INFO pRunRed = new NetSDKLib.DEV_EVENT_TRAFFIC_RUNREDLIGHT_INFO();
		pRunRed.write();
        Pointer pInfo = pRunRed.getPointer();
        pInfo.write(0, pAlarmInfo.getByteArray(0, pRunRed.size()) , 0, pRunRed.size());
        pRunRed.read();
        
        // print structure
        System.out.print(pRunRed.toString());
    	System.out.printf("bufsize:%d \n", dwBufSize);
       
        // save picture
    	String s = new String(sDstPath);
    	s += pRunRed.UTC.toStringTitle();
    	String sText = new String(pRunRed.stuObject.szText);
    	if (sText.indexOf(0) == 0)
    	{
    		s += String.format("_runredlight_%s_%d_%d_%d.jpg", "KongPai", pRunRed.stuFileInfo.nGroupId, pRunRed.stuFileInfo.bCount, pRunRed.stuFileInfo.bIndex);
    	}
    	else
    	{
    		s += String.format("_runredlight_%s_%d_%d_%d.jpg", new String(pRunRed.stuObject.szText), pRunRed.stuFileInfo.nGroupId, pRunRed.stuFileInfo.bCount, pRunRed.stuFileInfo.bIndex);   		
    	}
    	savePicture(pBuf, dwBufSize, s);
	}
	public static void event_ivs_traffic_manualsnap_func(Pointer pAlarmInfo, Pointer pBuf, int dwBufSize)
	{
		if (null == pAlarmInfo || null == pBuf || 0 == dwBufSize)
		{
			return ;
		}
		NetSDKLib.DEV_EVENT_TRAFFIC_MANUALSNAP_INFO pManualSnap = new NetSDKLib.DEV_EVENT_TRAFFIC_MANUALSNAP_INFO();
		
		pManualSnap.write();
        Pointer pInfo = pManualSnap.getPointer();
        pInfo.write(0, pAlarmInfo.getByteArray(0, pManualSnap.size()) , 0, pManualSnap.size());
        pManualSnap.read();
        
        // print structure
        System.out.print(pManualSnap.toString());
    	System.out.printf("bufsize:%d \n", dwBufSize);
       
        // save picture
    	String s = new String(sDstPath);
    	s += pManualSnap.UTC.toStringTitle();
    	String sText = new String(pManualSnap.stuObject.szText);
    	if (sText.indexOf(0) == 0)
    	{
    		s += String.format("_manualsnap_%s_%d_%d_%d.jpg", "KongPai",pManualSnap.stuFileInfo.nGroupId, pManualSnap.stuFileInfo.bCount, pManualSnap.stuFileInfo.bIndex);
    	}
    	else
    	{
    		s += String.format("_manualsnap_%s_%d_%d_%d.jpg", new String(pManualSnap.stuObject.szText), pManualSnap.stuFileInfo.nGroupId, pManualSnap.stuFileInfo.bCount, pManualSnap.stuFileInfo.bIndex);   		
    	}
    	savePicture(pBuf, dwBufSize, s);
	}

	public static void event_ivs_trafficgate_func(Pointer pAlarmInfo, Pointer pBuf, int dwBufSize)
	{
		if (null == pAlarmInfo || null == pBuf || 0 == dwBufSize)
		{
			return ;
		}
		NetSDKLib.DEV_EVENT_TRAFFICGATE_INFO pGate = new NetSDKLib.DEV_EVENT_TRAFFICGATE_INFO();
		pGate.write();
        Pointer pInfo = pGate.getPointer();
        pInfo.write(0, pAlarmInfo.getByteArray(0, pGate.size()) , 0, pGate.size());
        pGate.read();
        
        // print structure
        System.out.print(pGate.toString());
    	System.out.printf("bufsize:%d \n", dwBufSize);
       
        // save picture
    	String s = new String(sDstPath);
    	s += pGate.UTC.toStringTitle();
    	String sText = new String(pGate.stuObject.szText);
    	if (sText.indexOf(0) == 0)
    	{
    		s += String.format("_trafficgatet_%s_%d_%d_%d.jpg", "KongPai", pGate.stuFileInfo.nGroupId, pGate.stuFileInfo.bCount, pGate.stuFileInfo.bIndex);
    	}
    	else
    	{
    		s += String.format("_trafficgate_%s_%d_%d_%d.jpg", new String(pGate.stuObject.szText), pGate.stuFileInfo.nGroupId, pGate.stuFileInfo.bCount, pGate.stuFileInfo.bIndex);   		
    	}
    	savePicture(pBuf, dwBufSize, s);
    }

	public static void event_ivs_trafficjunction_func(Pointer pAlarmInfo, Pointer pBuf, int dwBufSize)
	{
		if (null == pAlarmInfo || null == pBuf || 0 == dwBufSize)
		{
			return ;
		}
		NetSDKLib.DEV_EVENT_TRAFFICJUNCTION_INFO pJunction = new NetSDKLib.DEV_EVENT_TRAFFICJUNCTION_INFO();
		pJunction.write();
        Pointer pInfo = pJunction.getPointer();
        pInfo.write(0, pAlarmInfo.getByteArray(0, pJunction.size()) , 0, pJunction.size());
        pJunction.read();
        
        // print structure
        System.out.print(pJunction.toString());
    	System.out.printf("bufsize:%d \n", dwBufSize);
       
        // save picture
    	String s = new String(sDstPath);
    	s += pJunction.UTC.toStringTitle();
    	String sText = new String(pJunction.stuObject.szText);
    	if (sText.indexOf(0) == 0)
    	{
    		s += String.format("_trafficjunction_%s_%d_%d_%d.jpg", "KongPai", pJunction.stuFileInfo.nGroupId, pJunction.stuFileInfo.bCount, pJunction.stuFileInfo.bIndex);
    	}
    	else
    	{
    		s += String.format("_trafficjunction_%s_%d_%d_%d.jpg", new String(pJunction.stuObject.szText), pJunction.stuFileInfo.nGroupId, pJunction.stuFileInfo.bCount, pJunction.stuFileInfo.bIndex);   		
    	}
    	savePicture(pBuf, dwBufSize, s);
	}
	
	public static void savePicture(Pointer pBuf, int dwBufSize, String sDstFile)
	{
        try
        {
        	File f = new File(sDstPath);
        	if (!f.exists()){
        		f.mkdir();
        	}
        	DataOutputStream out = new DataOutputStream(new BufferedOutputStream(new FileOutputStream(sDstFile)));
        	out.write(pBuf.getByteArray(0, dwBufSize), 0, dwBufSize);
        	out.close();
        } catch (Exception e){
        	e.printStackTrace();
        }
	}

	public static void printMethod(Object obj) throws Exception{
		// 获取这个对象的定义类
		Class<? extends Object> cz = obj.getClass();
		//cz.getFields();
		// 获取类的变量成员列表，注意，这个地方还有一个getDeclaredField方法
		for (Field f:cz.getDeclaredFields()){
			// 获取变量的值，当然你也可以获取变量的名字
			Object value = f.get(obj);
			f.setAccessible(true);
			System.out.println(value);
		}
	}
}