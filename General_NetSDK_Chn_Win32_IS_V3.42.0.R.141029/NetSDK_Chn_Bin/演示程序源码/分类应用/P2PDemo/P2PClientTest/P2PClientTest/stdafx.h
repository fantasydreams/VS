// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#ifndef _WIN32_WINNT		// ����ʹ���ض��� Windows XP ����߰汾�Ĺ��ܡ�
#define _WIN32_WINNT 0x0501	// ����ֵ����Ϊ��Ӧ��ֵ���������� Windows �������汾��
#endif						

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>

#if 1
#include "./headfiles/ProxyClientCWrap.h"
#pragma comment(lib, "./depends/TouProxy.lib")
#pragma comment(lib, "./depends/P2PSDK.lib")
#pragma comment(lib, "./depends/NATTraver.lib")
#pragma comment(lib, "./depends/litepi.lib")
#pragma comment(lib, "./depends/Infra.lib")
#endif

#include "./headfiles/dhnetsdk.h"
#pragma comment(lib, "./depends/dhnetsdk.lib")

// TODO: �ڴ˴����ó�����Ҫ������ͷ�ļ�
