#if !defined(AFX_DAYTIMEPICKSDK_H__C5FD15DB_5FC1_4879_BC67_4B4E4B88B119__INCLUDED_)
#define AFX_DAYTIMEPICKSDK_H__C5FD15DB_5FC1_4879_BC67_4B4E4B88B119__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CDayTimePickSDK wrapper class

class CDayTimePickSDK : public CWnd
{
protected:
	DECLARE_DYNCREATE(CDayTimePickSDK)
public:
	CLSID const& GetClsid()
	{
		static CLSID const clsid
			= { 0x239852ba, 0xedb9, 0x4a43, { 0x9d, 0xac, 0x43, 0xa5, 0x85, 0xe1, 0xa1, 0x30 } };
		return clsid;
	}
	virtual BOOL Create(LPCTSTR lpszClassName,
		LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect,
		CWnd* pParentWnd, UINT nID,
		CCreateContext* pContext = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID); }

    BOOL Create(LPCTSTR lpszWindowName, DWORD dwStyle,
		const RECT& rect, CWnd* pParentWnd, UINT nID,
		CFile* pPersist = NULL, BOOL bStorage = FALSE,
		BSTR bstrLicKey = NULL)
	{ return CreateControl(GetClsid(), lpszWindowName, dwStyle, rect, pParentWnd, nID,
		pPersist, bStorage, bstrLicKey); }

// Attributes
public:

// Operations
public:
	void AboutBox();
	long AddTimeBlock(long nStartSecondOfOneDay, long nEndSecondOfOneDay, long nRGBColor);
	long ClearTimeBlock();
	long SetCurrentTime(long nStartSecondOfOneDay);
	long GetCurrentTimeOfSecond();
	long SetColor(long textColor, long bkColor, long lineColor, long timeBolckColor, long timeTextColor);
	long IsTimeExist(long nHour, long nMinute, long nSecond);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAYTIMEPICKSDK_H__C5FD15DB_5FC1_4879_BC67_4B4E4B88B119__INCLUDED_)
