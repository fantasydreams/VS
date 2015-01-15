#pragma once


#include "GlobalDef.h"

#define WM_MSG_SHOW WM_USER+1000

// CDrawFrame �Ի���

class CDrawFrame : public CDialog
{
	DECLARE_DYNAMIC(CDrawFrame)

public:
	CDrawFrame(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDrawFrame();

	void DrawCoordinate();
	void SetRectClient(const CRect & rect);
	void InitData(NET_OUT_DOFINDNUMBERSTAT& dataShow, DWORD dwStartIndex, DWORD dwCount, int nType);
	void DrawFrame();
	void DrawLine(bool bEnter);//bEnter:1��ʾ���룬0��ʾ��ȥ
	void DrawPointEnter(int nZoom, CString strShow);
	void DrawPointExit(int nZoom, CString strShow);
	int  GetZoom();
	bool CheckTimeLost(NET_TIME timeStart, NET_TIME timeEnd);
	void UninitData();
	inline void SetPaint(bool bPaint){m_bPaint = bPaint;};

// �Ի�������
	enum { IDD = IDD_DRAWFRAME };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

private:
	// ��ͼ��DC
	CDC*	m_pDC;

	// ��ʾ�˴��ڵĴ�С
	CRect	m_rectClient;

	// ��ʾ�����������
	CRect	m_rectRange;

	// ����
	NET_OUT_DOFINDNUMBERSTAT m_dataShow;

	// ��ʾ��m_dataShow�ĵڶ�������ʼȡ����
	DWORD	 m_dwStartIndex;

	// ��ʾҪ��m_dataShowȡ������������
	DWORD	 m_dwCount;

	// ��ʾ��ѯ�����ͣ�0�֣�1ʱ��2�죬3�ܣ�4�£�5���ȣ�6��
	int	 m_nType;

	// ����ͬ����
	CRITICAL_SECTION m_criticalSection;

	// ��ʾ�Ƿ���Ҫ�ػ�ͼ��
	bool	 m_bPaint;
	// ��ʾ�����ߵ�����y�����굽�����������¶˵ģ�y�����
	DWORD m_nMaxY;
	
};
