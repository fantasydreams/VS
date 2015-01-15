#pragma once
#include "afxwin.h"

#include "GlobalDef.h"

//struct CFG_NUMBERSTAT_INFO;

/////////////////////////////////////////////////////////////////////////////////
/// \class CIvsRulePreview IvsRulePreview.h ".\SDKInvoker.h"
/// \brief ���ƹ���������
/////////////////////////////////////////////////////////////////////////////////
class CIvsRulePreview :public CWnd
{
public:
	CIvsRulePreview(void);
	~CIvsRulePreview(void);
	int InitRuleData();
	/// ��ͼ�������ûص�
	static void _stdcall DrawIvsRuleCfgProc(long nPort, HDC hDc, LONG dwUser);
	/// ���»�����Ϣ
	void InitState(eRuleState ruleState) {m_curState = ruleState;}
	/// ��ʼ����������
	BOOL InitDarwData(int nPort, CFG_ANALYSERULES_INFO *pRuleInfo);
	/// ��ȡ��ǰ����ͳ�ƽṹ��ָ��
	inline CFG_NUMBERSTAT_INFO *GetNumberStatInfo() {return m_pNumberStatInfo;}
	inline CFG_ANALYSERULES_INFO *GetAnalysRuleInfo() { return m_pANARuleInfo; }
protected:
	/// ����״̬
	eRuleState UpdataState(CPoint &point);
	/// ���ӵ���Ϣ
	void AddPoint(int nTYpe, CPoint &point);
	/// ��������
	void UpdataRuleData(int nType);
	
	//{{AFX_MSG(CIvsModulePreview)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg int  OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	
private:
	/// \var static float s_fFactorX
	/// X�����ű���
	static float s_fFactorX;
	/// \var static float s_fFactorY
	/// Y�����ű���
	static float s_fFactorY;

	/// \var static float s_fFactorX
	/// X�����ű���
	static int s_nWidth;
	/// \var static float s_fFactorY
	/// Y�����ű���
	static int s_nHeight;

	/// \var eRuleState m_curState
	/// ��ǰ����״̬
	eRuleState m_curState;
	
	///\var int m_nPort
	/// Ҫ���Ƶĵ�ǰ��ƵԴ�˿�
	int       m_nPort;
    
	/// \var CFG_NUMBERSTAT_INFO *m_pNumberStatInfo
	/// ����ͳ�ƹ���ṹ��ָ��
	CFG_NUMBERSTAT_INFO *m_pNumberStatInfo;

	/// \var int m_nRegionIndex
	/// ������������
	int m_nRegionIndex;

	/// \var int m_nDirectIndex
	///  ������������
	int m_nDirectIndex;

	/// \var CFG_ANALYSERULES_INFO *m_pANARuleInfo
	/// ʵʱ���µĹ�����Ϣ
	CFG_ANALYSERULES_INFO *m_pANARuleInfo;

	/// \var CFG_ANALYSERULES_INFO *m_pOrgANARuleInfo
	/// ����û�и���ǰ�Ĺ�����Ϣ
	CFG_ANALYSERULES_INFO *m_pOrgANARuleInfo;



};
