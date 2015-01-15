// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__A42990E7_D06C_4F9F_BA2E_5A2CEFE35AB1__INCLUDED_)
#define AFX_STDAFX_H__A42990E7_D06C_4F9F_BA2E_5A2CEFE35AB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include "include/dhnetsdk.h"
#include "include/dhconfigsdk.h"
#pragma comment(lib, "include/dhnetsdk.lib")
#pragma comment(lib, "include/dhconfigsdk.lib")

///////////////////////////////////////////////////////
// �궨��
#define SAFE_DELETE(p) if(0!=p) {delete p;p=0;}
#define SAFE_DELETE_A(p) if(0!=p) {delete[] p;p=0;}

///////////////////////////////////////////////////////
// ȥ��STL����
#pragma warning(disable:4786)// ��ʶ�����ȳ���256���ַ�

///////////////////////////////////////////////////////
// ȫ�ֺ���
void ClearComboBox(CComboBox &stComboBox);

CString ConvertString(CString strText);

void g_SetWndStaticText(CWnd * pWnd);

#define AfxMessageBox(S) ::MessageBox(NULL, S,ConvertString("Prompt"), 0);

#include "vld/vld.h"

// ��ö������䶯����dhnetsdk.h��ҲӦ����Ӧ�䶯 linjy-2006-12-16
enum DhServerType
{
	VIDEO_PRODUCT_NONE = 0,
	VIDEO_DVR_NONREALTIME_MACE,	// ��ʵʱMACE
	VIDEO_DVR_NONREALTIME,			// ��ʵʱ
	VIDEO_NVS_MPEG1,				// ������Ƶ������
	VIDEO_DVR_MPEG1_2,				// MPEG1��·¼���
	VIDEO_DVR_MPEG1_8,				// MPEG1��·¼���
	VIDEO_DVR_MPEG4_8,				// MPEG4��·¼���
	VIDEO_DVR_MPEG4_16,			// MPEG4ʮ��·¼���
	VIDEO_DVR_MPEG4_SX2,			// MPEG4����ʮ��·¼���
	VIDEO_DVR_MEPG4_ST2,			// MPEG4��ͨ¼���
	VIDEO_DVR_MEPG4_SH2,			// MPEG4�Ӻ�¼���
	VIDEO_DVR_MPEG4_GBE,			// MPEG4��ͨ������ǿ��¼���
	VIDEO_DVR_MPEG4_NVSII,			// MPEG4������Ƶ������II��
	VIDEO_DVR_STD_NEW,				// �±�׼����Э��
	VIDEO_DVR_DDNS,				// DDNS������
	VIDEO_DVR_ATM,					// ATM��
	VIDEO_NB_SERIAL,				// ������ʵʱNBϵ�л���
	VIDEO_LN_SERIAL,				// LNϵ�в�Ʒ
	VIDEO_BAV_SERIAL,				// BAVϵ�в�Ʒ
	VIDEO_SDIP_SERIAL,				// SDIPϵ�в�Ʒ
	VIDEO_IPC_SERIAL,				// IPCϵ�в�Ʒ
	VIDEO_NVS_B,					// NVS Bϵ��
	VIDEO_NVS_C,					// NVS Hϵ��
	VIDEO_NVS_S,					// NVS Sϵ��
	VIDEO_NVS_E,					// NVS Eϵ��
	VIDEO_DVR_NEW_PROTOCOL,		// ��Э��
	VIDEO_NVD_SERIAL,				// ������
	VIDEO_DVR_N5,					// N5
	VIDEO_DVR_MIX_DVR,				// ���DVR
	VIDEO_SVR_SERIAL,				// SVR
	VIDEO_SVR_BS,					// SVR-BS
	VIDEO_NVR_SERIAL,				// NVR
	VIDEO_DVR_N51,                 // N51
	VIDEO_ITSE_SERIAL,				// ITSE ���ܷ�����
	VIDEO_ITC_SERIAL,              // ���ܽ�ͨ����豸
	VIDEO_ITC_HWS,                 // �״������HWS
	VIDEO_PVR_SERIAL,              // ��Яʽ����Ƶ¼���
	VIDEO_IVS_SERIAL,              // IVS��������Ƶ������ϵ�У�
	VIDEO_IVS_B,                   // ͨ��������Ƶ��������
	VIDEO_IVS_F,                   // ����ʶ�������
	VIDEO_IVS_V,                   // ��Ƶ������Ϸ�����	
	VIDEO_MATRIX_SERIAL,			// ����
	VIDEO_DVR_N52,					// N52
	VIDEO_DVR_N56,                 // n56
	VIDEO_ESS_SERIAL,              // ESS
	VIDEO_IVS_PC,                  // ���ܽ�ͨ����ͳ�Ʒ�����
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__A42990E7_D06C_4F9F_BA2E_5A2CEFE35AB1__INCLUDED_)
