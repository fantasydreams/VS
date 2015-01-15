// DemoIVSPCDlg.h : header file
//

#if !defined(AFX_DEMOIVSPCDLG_H__FCB9A603_26B7_43E9_8657_752A8CD527BB__INCLUDED_)
#define AFX_DEMOIVSPCDLG_H__FCB9A603_26B7_43E9_8657_752A8CD527BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPreview;
class CConfig;
class CDlgQuery;

class CLogo;

struct DeviceDisConnectData 
{
	LONG lLoginID;
	char pchDVRIP[40];
	LONG nDVRPort;
};
/////////////////////////////////////////////////////////////////////////////
// CDemoIVSPCDlg dialog

class CDemoIVSPCDlg : public CDialog
{
// Construction
public:
	CDemoIVSPCDlg(CWnd* pParent = NULL);	// standard constructor
	~CDemoIVSPCDlg();

	//���õ�ǰ�鿴��ͼ���ͨ����
	inline void SetCurrentChannel(int nChannel){m_nCurrentChn = nChannel;}
	inline int GetCurrentChannel(){return m_nCurrentChn;}

	//��ȡ/���õ�¼���
	inline LONG GetLoginHandle(){return m_lLoginHandle;}
	inline void SetLoginHandel(LONG lLoginHandle){m_lLoginHandle = lLoginHandle;}

	//��ȡ/����Ԥ�����
	inline LONG GetRealPlayHandle(){return m_lRealPlayHandle;}
	inline void SetRealPlayHandel(LONG lRealPlayHandle){m_lRealPlayHandle = lRealPlayHandle;}

	//��ȡ�豸��Ϣ�ṹ��
	inline NET_DEVICEINFO* GetDevInfo(){return &m_stuDeviceInfo;}

	//�����ڴ��������Ϣ
	BOOL NewConfigInfo(int nChnCount);

	//�ͷ�������Ϣ���ڴ�ռ�
	void DeleteConfigInfo();

	//��ȡĳͨ��������������
	CFG_CAP_ANALYSE_INFO* GetCapAnalyseInfo(int nChannel);

	//��ȡĳͨ����ȫ��������Ϣ
	CFG_ANALYSEGLOBAL_INFO* GetAnalyseGlobalInfo(int nChannel);

	//��ȡĳͨ����ģ��������Ϣ
	CFG_ANALYSEMODULES_INFO* GetAnalyseModuleInfo(int nChannel);

	//��ȡĳͨ���Ĺ���������Ϣ
	CFG_ANALYSERULES_INFO* GetAnalyseRulesInfo(int nChannel);

	//��ȡ��ͨ����ǰ���������
	int GetScenceSeqOfCurChn(CFG_CAP_ANALYSE_INFO* pCapAnalyseInfo, CFG_ANALYSEGLOBAL_INFO* pAnalyseGlobalInfo);

	//��ȡ����������Ϣ�����ͷָ��
	lsRuleList* GetRuleList(int nChannel);

	void EnableLoginWindow(LoginState emState);

	void RefreshModuleInfo();
	void RefreshGlobalInfo();
	void RefreshRuleInfo();

	CConfig*	m_pdlgConfig;


// Dialog Data
	//{{AFX_DATA(CDemoIVSPCDlg)
	enum { IDD = IDD_DEMOIVSPC_DIALOG };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoIVSPCDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDemoIVSPCDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnPreview();
	afx_msg void OnBtnConfig();
	afx_msg void OnDestroy();
	afx_msg void OnMainBtnLogout();
	afx_msg void OnBnClickedMainBtnQuery();
	afx_msg LRESULT DeviceDisConnect(WPARAM wpara, LPARAM lpara);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	//����SDK�ӿڻ�ȡ������������Ϣ
	BOOL GetCap(int nChannel, CFG_CAP_ANALYSE_INFO* pCfgCapAnalyseInfo);

	//����SDK�ӿڻ�ȡȫ������
	BOOL GetGlobal(int nChannel, CFG_ANALYSEGLOBAL_INFO* pCfgAnalyseGlobalInfo);

	//����SDK�ӿڻ�ȡģ������
	BOOL GetModule(int nChannel, CFG_ANALYSEMODULES_INFO* pCfgAnalyseModulesInfo);

	//����SDK�ӿڻ�ȡ��������
	BOOL GetRule(int nChannel, CFG_ANALYSERULES_INFO* pCfgAnalyseRulesInfo);

	//��ȡĳͨ��֧�ֵ����й����У����Ĺ���ṹ��Ĵ�С
	// 	int getMaxStuSize(DWORD* pRuleType, int nRuleNum);
	int GetMaxStuSize(SCENE_SUPPORT_RULE* pRuleType, int nRuleNum);

	void PutRuleInfoIntoList(int nChnCount);

private:
	typedef enum DlgType
	{
		dlgNone = 0,
		dlgPreview,
		dlgConfig,
		dlgQuery,
	};

	void ShowDlg(enum DlgType dlgTYPE);

	CLogo* m_pdlgLogo;

	//��¼���
	LONG m_lLoginHandle;

	//���ž��
	LONG m_lRealPlayHandle;

	//�������
	LONG m_lAnalyzerHandle;

	//ʵ�ʵ��豸ͨ����
	int m_nChnCount;
		
	//�豸��Ϣ��ÿ���豸��Ӧһ���ṹ��
	NET_DEVICEINFO m_stuDeviceInfo;
	
	//������������ÿ��ͨ����Ӧһ���ṹ��
	CFG_CAP_ANALYSE_INFO* m_pStuCfgCapAnalyseInfo;
	
	//ȫ�����ã�ÿ��ͨ����Ӧһ���ṹ��
	CFG_ANALYSEGLOBAL_INFO* m_pStuCfgAnalyseGlobalInfo;
	
	//ģ�����ã�ÿ��ͨ����Ӧһ���ṹ�壬ÿ��ͨ����Ӧ���ģ��������Ϣ
	CFG_ANALYSEMODULES_INFO* m_pStuCfgAnalyseModuleInfo;
	
	//�������ã�ÿ��ͨ����Ӧһ���ṹ�壬ÿ��ͨ����Ӧ�������������Ϣ
	CFG_ANALYSERULES_INFO* m_pStuCfgAnalyseRuleInfo;

	//����ͨ���ľ�������б�
	lsRuleList* m_pRuleList;
	
	DlgType		m_currentDlg;
	int			m_nCurrentChn;
	BOOL		m_bIsSwitchOn;
	CPreview*	m_pdlgPreview;
	CDlgQuery*  m_pdlgQuery;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOIVSPCDLG_H__FCB9A603_26B7_43E9_8657_752A8CD527BB__INCLUDED_)
