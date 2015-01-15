#pragma once


// CTargetFilterPreview

class CTargetFilterPreview : public CWnd
{
	DECLARE_DYNAMIC(CTargetFilterPreview)

public:
	CTargetFilterPreview();
	virtual ~CTargetFilterPreview();

	static void _stdcall DrawTargetFilterCfgProc(long nPort, HDC hDc, LONG dwUser);

	void SetModuleInfo(CFG_OBJECT_SIZEFILTER_INFO* pObjectFilter, int nChannel);

	CRITICAL_SECTION	m_cs;
	// ��ʾ�Ƿ񻭣����ε��ĸ��ǵ�С��
	bool m_bDrawboxBig;
	// ��ʾ�����������ʱ�Ƿ��ڴ��box��
	bool m_bClickBoxBig;
	// ��ʾ�����������ʱ�Ƿ���С��box��
	bool m_bClickBoxSmall;
	// ��ʾ�����box���Ǹ��ǣ�1(����),2(����),3(����),4(����)
	BYTE m_byPosBig;

protected:
	DECLARE_MESSAGE_MAP()

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

private:
	
	CFG_OBJECT_SIZEFILTER_INFO* m_pObjectFilter;
	int m_nChannel;
	int m_nCenterPointIndex;
	// ������ʱ����
	POINT m_pointDown;
	// ��ʾ�����box���Ǹ��ǣ�1(����),2(����),3(����),4(����)
	BYTE m_byPosSmall;
};


