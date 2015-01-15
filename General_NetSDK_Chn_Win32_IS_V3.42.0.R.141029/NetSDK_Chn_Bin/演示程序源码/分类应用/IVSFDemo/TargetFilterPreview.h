#pragma once


// CTargetFilterPreview

class CTargetFilterPreview : public CWnd
{
	DECLARE_DYNAMIC(CTargetFilterPreview)

public:
	CTargetFilterPreview();
	virtual ~CTargetFilterPreview();

protected:
	DECLARE_MESSAGE_MAP()

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

public:
	static void _stdcall DrawTargetFilterCfgProc(long nPort, HDC hDc, LONG dwUser);

	CRITICAL_SECTION	m_cs;
	inline CFG_ANALYSEMODULES_INFO* GetModuleInfo(){return m_pAnalyseModulesInfo;};
	void SetModuleInfo(CFG_ANALYSEMODULES_INFO* pAnalyseModulesInfo, int nChannel);

	CFG_ANALYSEMODULES_INFO* m_pAnalyseModulesInfo;
	int m_nChannel;
	
	bool m_bDrawboxBig;// ��ʾ�Ƿ񻭣����ε��ĸ��ǵ�С��
	POINT m_pointDown;// ������ʱ����
	bool m_bClickBoxBig;// ��ʾ�����������ʱ�Ƿ��ڴ��box��
	BYTE m_byPosBig;// ��ʾ�����box���Ǹ��ǣ�1(����),2(����),3(����),4(����)
	bool m_bClickBoxSmall;// ��ʾ�����������ʱ�Ƿ���С��box��
	BYTE m_byPosSmall;// ��ʾ�����box���Ǹ��ǣ�1(����),2(����),3(����),4(����)

	
	BOOL				m_bDrawDetectRegion;
	BOOL				m_bDrawFilter;
	BOOL				m_bDragging;
};


