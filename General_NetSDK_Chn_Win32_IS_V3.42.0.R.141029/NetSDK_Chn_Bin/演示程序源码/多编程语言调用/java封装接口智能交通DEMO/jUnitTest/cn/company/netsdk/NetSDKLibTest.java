package cn.company.netsdk;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import cn.company.netsdk.NetSDKLib;

import com.sun.jna.NativeLong;
import com.sun.jna.Pointer;

class fAnalyzerDataCallBackCB implements NetSDKLib.fAnalyzerDataCallBack{
	public int invoke(NativeLong lAnalyzerHandle, int dwAlarmType, Pointer pAlarmInfo, Pointer pBuffer, int dwBufSize, NativeLong dwUser, int nSequence, Pointer reserved){
		System.out.println("fAnalyzerDataCallBackCB called.");
		return 0;
	}
}
public class NetSDKLibTest{
	static NetSDKLib NetSDKLibObj = NetSDKLib.INSTANCE;
	
	private NetSDKLib.NET_DEVICEINFO m_stDeviceInfo ;
	private static NativeLong m_lNativeLoginID = new NativeLong(0);
	private static NativeLong m_lNativeRealPicHandle = new NativeLong(0);
    
	public class fDisConnectCB implements NetSDKLib.fDisConnect{
		public int invoke(NativeLong lLoginID, String pchDVRIP, int nDVRPort, NativeLong dwUser){
    		return 0;
		}	
    }

	@Before
	public void setUp() throws Exception {
		// JNA调用动态库配置
		NetSDKLibObj.CLIENT_Init(new fDisConnectCB(), new NativeLong(0));
		System.out.println("dhnetsdk Init ok !");
		Login();
	}

	@After
	public void tearDown() throws Exception {
		StopRealPic();
		Logout();
		NetSDKLibObj.CLIENT_Cleanup();
		System.out.println("dhnetsdk clean up ok !");
	}
	
	public final void Login() {
		m_stDeviceInfo = new NetSDKLib.NET_DEVICEINFO();
		String m_strIP = new String("10.45.3.51");
		int m_sPort = (int)37777;
		String m_strUserName = new String("admin");
		String m_strUserPwd = new String("admin");
		int nSpecCap = 0;
		Pointer pCapParam = null;
		int nError[] = {0};
		m_lNativeLoginID = NetSDKLibObj.CLIENT_LoginEx(m_strIP, (short)m_sPort, m_strUserName,m_strUserPwd,nSpecCap,pCapParam, m_stDeviceInfo,nError);
		
		if(0 == m_lNativeLoginID.longValue())
		{
			fail("login return failure !");
		}
		else
		{
			System.out.printf("%s:%d login ok, device type is %d, channal num is %d !\n",
					m_strIP,(int)m_sPort,m_stDeviceInfo.byDVRType, m_stDeviceInfo.byChanNum);
		}
	}

	public final void Logout() {
		if (0 == m_lNativeLoginID.longValue())
		{
			fail("login handle is error !");
		}
		boolean bRet = NetSDKLibObj.CLIENT_Logout(m_lNativeLoginID);
		if(false == bRet)
		{
			fail("logout out return failure !");
		}
		else
		{
			System.out.println("logout ok !");
		}
	}
	
	public final void StopRealPic(){
		if (0 != m_lNativeRealPicHandle.longValue())
		{
			NetSDKLibObj.CLIENT_StopLoadPic(m_lNativeRealPicHandle);
			System.out.println("stop real load picture ok !");
		}
	}

	@Test
	public final void getRealPic()
	{
		int nChannelID = 0;
		int dwAlarmType = 0;
		boolean bNeedPicFile = true;
		NativeLong dwUser = new NativeLong(0);
		Pointer Reserved = null;
		
		m_lNativeRealPicHandle = NetSDKLibObj.CLIENT_RealLoadPictureEx(
				m_lNativeLoginID,
				nChannelID,
				dwAlarmType,
				bNeedPicFile,
				new fAnalyzerDataCallBackCB(),
				dwUser,
				Reserved
				);
		
		if (0 == m_lNativeRealPicHandle.longValue())
		{
			fail("real load picture failure !");
		}
		else
		{
			System.out.println("real load picture ok !");
		}
	}
}
