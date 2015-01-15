
#pragma once
#include "include/dhnetsdk.h"
#include <map>
#include <string>


inline std::string ConvertStr(char* szKeyName)
{
	using namespace std;
	static bool bFirstTime = true;
	static map<std::string, std::string> g_text;
	//��һ�ε�ʱ�������װ�ص�map��
	if ( bFirstTime )
	{
		bFirstTime = false;
		const int MAX_ALL_KEY_SIZE = 1024*50;
		const int MAX_SINGLE_KEY_SIZE = 1024;
		const int MAX_SINGLE_VAL_SIZE = 1024;
		char szKeys[MAX_ALL_KEY_SIZE] = {0};
		DWORD dwRet = GetPrivateProfileString("String",
							NULL,
							NULL,
							szKeys,
							MAX_ALL_KEY_SIZE,
							"./langchn.ini");
		if (dwRet != 0)
		{
			char* szKey = szKeys;
			char szVal[MAX_SINGLE_VAL_SIZE]; 
			DWORD dwProcessCount = 0;
			while(true)
			{
				memset(szVal, 0, MAX_SINGLE_VAL_SIZE);
				GetPrivateProfileString("String",
								szKey,
								szKey,
								szVal,
								MAX_SINGLE_VAL_SIZE,
								"./langchn.ini");
				g_text.insert(pair<std::string, std::string>(szKey, szVal));

				szKey += (strlen(szKey) + 1);
				int nCount = szKey - szKeys;
				if (nCount >= dwRet)
				{
					break;
				}
			}
		}
	}



	//��map�ж�ȡ
	
	string strRet = g_text[szKeyName];
	if (strRet.size() != 0)
	{
		return strRet;
	}
	else
	{
		return string(szKeyName);
	}

	
}


/************************************************************************/
/* ��ȡģ�����ڵľ���·��                                               */
/************************************************************************/
inline bool GetModulePath(const char* szDllName, char* szModuleDir)
{
	HMODULE hModule = NULL;
	if (szDllName != NULL)
	{
		hModule = ::GetModuleHandle(szDllName);
		if (hModule == NULL)
		{
			return false;
		}
	}
	char szFullDllPath[_MAX_PATH] = {0};
	::GetModuleFileName(hModule, szFullDllPath, _MAX_PATH);
	char* lastBackslash = strrchr(szFullDllPath, '\\');
	int lastBackslashPos = lastBackslash - szFullDllPath + 1;
	strncpy(szModuleDir, szFullDllPath, lastBackslashPos);
	return true;
}

/************************************************************************/
/* ��ȡģ�����ڵľ���·��                                               */
/************************************************************************/
inline bool GetModulePath(const char* szDllName, std::string& strModuleDir)
{
	char buf[MAX_PATH] = {0};
	bool bRet = GetModulePath(szDllName, buf);
	if (bRet)
	{
		strModuleDir = std::string(buf);
		return true;
	}
	return false;
}

/************************************************************************/
/* GUID to std::string                                                  */
/************************************************************************/
inline std::string GuidToString(const GUID &guid)
{
    char buf[64] = {0};
	sprintf(
		buf,
		"{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
		guid.Data1, guid.Data2, guid.Data3,
		guid.Data4[0], guid.Data4[1],
		guid.Data4[2], guid.Data4[3],
		guid.Data4[4], guid.Data4[5],
		guid.Data4[6], guid.Data4[7]);
	return std::string(buf);
}

/************************************************************************/
/* NET_TIME to char                                                     */
/************************************************************************/
inline void NetTime2Str(NET_TIME& netTime, char* buf)
{
	sprintf(buf, "%d-%d-%d %d:%d:%d", 
		netTime.dwYear,
		netTime.dwMonth,
		netTime.dwDay,
		netTime.dwHour,
		netTime.dwMinute,
		netTime.dwSecond);
}

inline std::string D2Str(const double v)
{
	char szVal[20] = {0};
	sprintf(szVal, "%lf", v);
	return std::string(szVal);
}

inline std::string I2Str(const int v)
{
	char szVal[10] = {0};
	itoa(v, szVal, 10);
	return std::string(szVal);
}

inline std::string Hex2Str(BYTE* v,int nlen)
{
	std::string s;
	char szVal[10] = {0};
	for (int i=0;i<nlen;i++)
	{
		sprintf(szVal,"%d,",v[i]);
		s.append(szVal);
	}
	return s;
}

inline std::string DWORDFlag2Str(const DWORD &dwSnapFlagMask)
{
	std::string s;
	char *szTmp[]={"*","Timing","Manual","Marked","Event","Mosaic","Cutout"};
	for (int i=0;i<sizeof(szTmp)/sizeof(szTmp[0]); i++)
	{
		if (dwSnapFlagMask & (1 << i))
		{
			s.append(szTmp[i]);
			s.append(" ");
		}
		else
		{
			continue;
		}
	}
	return s;
}
inline std::string MakeColorStr(DWORD dwColorRGBA)
{
	BYTE* byV = (BYTE*)(&dwColorRGBA);
	char szV[25] = {0};
	
	DWORD dwTest = 0x00000001;
	BYTE* byPoint = (BYTE*)(&dwTest);
	if (byPoint[3] == 0x01)
	{
		sprintf(szV, "R=%d,G=%d,B=%d,A=%d", byV[0], byV[1], byV[2], byV[3]);
	}
	else
	{
		sprintf(szV, "R=%d,G=%d,B=%d,A=%d", byV[3], byV[2], byV[1], byV[0]);
	}

	return std::string(szV);
}



inline std::string MakePointer(DH_POINT pV)
{
	char* szText = new char[1024*5];
	sprintf(szText, "{X=%d,Y=%d}", pV.nx, pV.ny);
	std::string strRet(szText);
	delete[] szText;
	return strRet;
}

inline std::string MakePointers(DH_POINT* pV, int nPointCount)
{
	std::string strRet;
// 	if (nPointCount > 128)
// 	{
// 		return strRet;
// 	}
	for (int i = 0; i < nPointCount; i++)
	{
		strRet.append(MakePointer(*(pV + i)));
	}
	return strRet;
}



inline std::string MakeRect(DH_RECT rectV)
{
	char szText[128] = {0};
	sprintf(szText, "Left=%d,Top=%d,Right=%d,Bottom=%d", rectV.left, rectV.top, rectV.right, rectV.bottom);
	return std::string(szText);
}


// ���嶯��:1:Appear 2:Move 3:Stay 4:Remove 5:Disappear 6:Split 7:Merge 8:Rename
inline std::string MakeActionStr(int nV)
{
	switch (nV)
	{
	case 1:
		return ConvertStr("Appear");
	case 2:
		return ConvertStr("Move");
	case 3:
		return ConvertStr("Stay");
	case 4:
		return ConvertStr("Remove");
	case 5:
		return ConvertStr("Disappear");
	case 6:
		return ConvertStr("Split");
	case 7:
		return ConvertStr("Merge");
	case 8:
		return ConvertStr("Rename");
	default:
		return ConvertStr("Unknow");
	}
}

inline std::string MakeSnapTypeStr(BYTE byV)
{
	switch (byV)
	{
	case 0:
		return ConvertStr("Radar upper limit");
	case 1:
		return ConvertStr("Radar lower limit");
	case 2:
		return ConvertStr("Vehicle inspection device upper limit");
	case 3:
		return ConvertStr("Vehicle inspection device lower limit");
	case 4:
		return ConvertStr("Reverse");
	case 5:
		return ConvertStr("Cross red light");
	case 6:
		return ConvertStr("Red light turn on");
	case 7:
		return ConvertStr("Red light turn off");
	case 8:
		return ConvertStr("All or gate");
	default:
		return ConvertStr("Unknow");
	}
}


inline std::string MakeRedLightDirStr(BYTE byV)
{
   if (byV == 0)
   {
	   return ConvertStr("Left");
   }
   else if (byV == 1)
   {
	   return ConvertStr("Straight");
   }
   else if (byV == 2)
   {
	   return ConvertStr("Right");
   }
   return std::string("Unknow");
}


inline std::string MakeLightColorStr(BYTE byV)
{
	if (byV == 0)
	{
		return ConvertStr("Green");
	}
	else if (byV == 1)
	{
		return ConvertStr("Red");
	}
	else if (byV == 2)
	{
		return ConvertStr("Yellow");
	}
	return std::string("Unknow");
}

inline std::string MakeLightColorStr2(BYTE byV)
{
	if (byV == 1)
	{
		return ConvertStr("Green");
	}
	else if (byV == 2)
	{
		return ConvertStr("Red");
	}
	else if (byV == 3)
	{
		return ConvertStr("Yellow");
	}
	return std::string("Unknow");
}

/***********************************************************************/
/*��ͨ·���¼�Υ������*/
// ��һλ:�����; RunRedLight
// �ڶ�λ:�����涨������ʻ;WrongLane
// ����λ:����; Retrograde
// ����λ��Υ�µ�ͷ;U-Trun
// ����λ:��ͨ����;TrafficJam
// ����λ:��ͨ�쳣����TrafficIdle
// default: TrafficJunction
/************************************************************************/
inline std::string BR2StrForTrafficJunction(DWORD dwBR)
{
	std::string strRet;
	char* szSpliterStr = " && ";
	if (dwBR & 0x00000001)
	{
		strRet.append(ConvertStr("RunRedLight"));
	}
	if (dwBR & 0x00000002)
	{
		if (strRet.size() != 0)
		{
			strRet.append(szSpliterStr);
		}
		strRet.append(ConvertStr("WrongLane"));
	}
	if (dwBR & 0x00000004)
	{
		if (strRet.size() != 0)
		{
			strRet.append(szSpliterStr);
		}
		strRet.append(ConvertStr("Retrograde"));
	}
	if (dwBR & 0x00000008)
	{
		if (strRet.size() != 0)
		{
			strRet.append(szSpliterStr);
		}
		strRet.append(ConvertStr("U-Trun"));
	}
	if (dwBR & 0x00000010)
	{
		if (strRet.size() != 0)
		{
			strRet.append(szSpliterStr);
		}
		strRet.append(ConvertStr("TrafficJam"));
	}
	if (dwBR & 0x00000020)
	{
		if (strRet.size() != 0)
		{
			strRet.append(szSpliterStr);
		}
		strRet.append(ConvertStr("TrafficIdle"));
	}
	if (strRet.size() == 0)
	{
		strRet.append(ConvertStr("TrafficJunction"));
	}
	
	return strRet;
}

/************************************************************************/
/*�����¼���Υ������*/
//��һλ:����; Retrograde
// �ڶ�λ:ѹ����ʻ; Overline
// ����λ:������ʻ; Overspeed
// ����λ��Ƿ����ʻ;Underspeed
// ����λ:�����; RunRedLight
//����Ĭ��Ϊ: Trafficgate
/************************************************************************/
inline std::string BR2StrForTrafficGate(DWORD dwBR)
{
	std::string strRet;
	char* szSpliterStr = " && ";
	if (dwBR & 0x00000001)
	{
		strRet.append(ConvertStr("Retrograde"));
	}
	if (dwBR & 0x00000002)
	{
		if (strRet.size() != 0)
		{
			strRet.append(szSpliterStr);
		}
		strRet.append(ConvertStr("Overline"));
	}
	if (dwBR & 0x00000004)
	{
		if (strRet.size() != 0)
		{
			strRet.append(szSpliterStr);
		}
		strRet.append(ConvertStr("Overspeed"));
	}
	if (dwBR & 0x00000008)
	{
		if (strRet.size() != 0)
		{
			strRet.append(szSpliterStr);
		}
		strRet.append(ConvertStr("Underspeed"));
	}
	if (dwBR & 0x10)
	{
		if (strRet.size() != 0)
		{
			strRet.append(szSpliterStr);
		}
		strRet.append(ConvertStr("RunRedLight"));
	}
	if (dwBR & 0x20)
	{
		if (strRet.size() != 0)
		{
			strRet.append(szSpliterStr);
		}
		strRet.append(ConvertStr("Passing"));
	}
	if (dwBR & 0x40)
	{
		if (strRet.size() != 0)
		{
			strRet.append(szSpliterStr);
		}
		strRet.append(ConvertStr("OverYellowLine"));
	}
	if (dwBR & 0x80)
	{
		if (strRet.size() != 0)
		{
			strRet.append(szSpliterStr);
		}
		strRet.append(ConvertStr("WrongRunningRoute"));
	}
	if (dwBR & 0x100)
	{
		if (strRet.size() != 0)
		{
			strRet.append(szSpliterStr);
		}
		strRet.append(ConvertStr("YellowVehicleInRoute"));
	}
	if (strRet.size() == 0)
	{
		strRet.append(ConvertStr("Trafficgate"));
	}
	return strRet;
}

/************************************************************************/
/* NET_TIME to std::string                                              */
/************************************************************************/
inline std::string NetTime2Str(const NET_TIME& netTime)
{
	char buf[128] = {0};
	sprintf(buf, "%d-%d-%d %d:%d:%d", 
		netTime.dwYear,
		netTime.dwMonth,
		netTime.dwDay,
		netTime.dwHour,
		netTime.dwMinute,
		netTime.dwSecond);
	return std::string(buf);
}


/************************************************************************/
/* �Ƚ�����NET_TIME�Ĵ�С                                               */
/************************************************************************/
#define CMP(L, R) {if( (L) > (R) ){return 1;}else if( (L) < (R) ){return -1;}}
inline int NetTimeCmp(NET_TIME& left, NET_TIME& right)
{
	CMP(left.dwYear, right.dwYear)
	CMP(left.dwMonth, right.dwMonth)
	CMP(left.dwDay, right.dwDay)
	CMP(left.dwHour, right.dwHour)
	CMP(left.dwMinute, right.dwMinute)
	CMP(left.dwSecond, right.dwSecond)
	return 0;
}

/************************************************************************/
/* NET_TIME to std::string                                              */
/************************************************************************/
inline std::string NetTimeEx2Str(const NET_TIME_EX& netTime)
{
	char buf[128] = {0};
	sprintf(buf, "%d-%d-%d %d:%d:%d.%d", 
		netTime.dwYear,
		netTime.dwMonth,
		netTime.dwDay,
		netTime.dwHour,
		netTime.dwMinute,
		netTime.dwSecond,
		netTime.dwMillisecond
		);
	return std::string(buf);
}


/************************************************************************/
/* �Ƚ�����NET_TIME�Ĵ�С                                               */
/************************************************************************/
#define CMP(L, R) {if( (L) > (R) ){return 1;}else if( (L) < (R) ){return -1;}}
inline int NetTimeExCmp(NET_TIME_EX& left, NET_TIME_EX& right)
{
	CMP(left.dwYear, right.dwYear)
	CMP(left.dwMonth, right.dwMonth)
	CMP(left.dwDay, right.dwDay)
	CMP(left.dwHour, right.dwHour)
	CMP(left.dwMinute, right.dwMinute)
	CMP(left.dwSecond, right.dwSecond)
	CMP(left.dwMillisecond, right.dwMillisecond)
	return 0;
}


/************************************************************************/
/* �˹����״̬ 0:δ��飬1:��ȷ 2:����                                */
/************************************************************************/
const int LP_STATE_COUNT = 6;//�����˹�����״̬�ĸ���,���������״̬��ʱ��һ��Ҫ�����������
inline std::string I2State(int nState)
{
	switch(nState)
	{
	case 0:
		return ConvertStr("Not Checked");
		break;
	case 1:
		return ConvertStr("Right");
		break;
	case 2:
		return ConvertStr("Wrong");
	    break;
	case 3:
		return ConvertStr("No License Plate");
		break;
	case 4:
		return ConvertStr("Dirty License Plate");
		break;
	case 5:
		return ConvertStr("False Alarm");
		break;


		//����Ĳ���״ֵ̬
	default:
		return ConvertStr("Unknow State");
	    break;
	}
}

inline std::string MakeLP(char* szLP)
{
	if (strcmp(szLP, "") == 0)
	{
		std::string strRet = ConvertStr("No License plate");
		return strRet;
	}
	else
	{
		return std::string(szLP);
	}
}
