// DemoIVSbDlg.h : header file
//

#if !defined(AFX_DEMOIVSBDLG_H__FCB9A603_26B7_43E9_8657_752A8CD527BB__INCLUDED_)
#define AFX_DEMOIVSBDLG_H__FCB9A603_26B7_43E9_8657_752A8CD527BB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPreview;
class CConfig;
class CAlarm;

class CLogo;
/////////////////////////////////////////////////////////////////////////////
// CDemoIVSbDlg dialog

class CDemoIVSbDlg : public CDialog
{
public:
	//���õ�ǰ�鿴��ͼ���ͨ����
	void setCurrentChannel(int nChannel)
	{
		m_nCurrentChn = nChannel;
	}

	int getCurrentChannel()
	{
		return m_nCurrentChn;
	}

	//��ȡ/���õ�¼���
	LLONG getLoginHandle()
	{
		return m_lLoginHandle;
	}
	void setLoginHandel(LLONG lLoginHandle)
	{
		m_lLoginHandle = lLoginHandle;
	}

	//��ȡ/����Ԥ�����
	LLONG getRealPlayHandle()
	{
		return m_lRealPlayHandle;
	}
	void setRealPlayHandel(LLONG lRealPlayHandle)
	{
		m_lRealPlayHandle = lRealPlayHandle;
	}

	//��ȡ�豸��Ϣ�ṹ��
	NET_DEVICEINFO* getDevInfo()
	{
		return &m_stuDeviceInfo;
	}


	//�����ڴ��������Ϣ
	BOOL newConfigInfo(int nChnCount);

	//�ͷ�������Ϣ���ڴ�ռ�
	void deleteConfigInfo();

	//��ȡĳͨ��������������
	CFG_CAP_ANALYSE_INFO* getCapAnalyseInfo(int nChannel);

	//��ȡĳͨ����ȫ��������Ϣ
	CFG_ANALYSEGLOBAL_INFO* getAnalyseGlobalInfo(int nChannel);

	//��ȡĳͨ����ģ��������Ϣ
	CFG_ANALYSEMODULES_INFO* getAnalyseModuleInfo(int nChannel);

	//��ȡĳͨ���Ĺ���������Ϣ
	CFG_ANALYSERULES_INFO* getAnalyseRulesInfo(int nChannel);

	//��ȡ��ͨ����ǰ���������
	int getScenceSeqOfCurChn(CFG_CAP_ANALYSE_INFO* pCapAnalyseInfo, CFG_ANALYSEGLOBAL_INFO* pAnalyseGlobalInfo);

	//���������¼����
	void startAlarmCallBack(std::list<DWORD>* plsdwChannel);

	//�رն����¼����
	BOOL stopAlarmCallBack();

	//��ȡ������Ϣ����
	lsAlarmInfo* getAlarmInfoList()
	{
		return &m_lstAlarmInfo;
	}
	
	//����SDK�ӿڻ�ȡ������������Ϣ
	BOOL getCap(int nChannel, CFG_CAP_ANALYSE_INFO* pCfgCapAnalyseInfo);
	
	//����SDK�ӿڻ�ȡȫ������
	BOOL getGlobal(int nChannel, CFG_ANALYSEGLOBAL_INFO* pCfgAnalyseGlobalInfo);
	
	//����SDK�ӿڻ�ȡģ������
	BOOL getModule(int nChannel, CFG_ANALYSEMODULES_INFO* pCfgAnalyseModulesInfo);
	
	//����SDK�ӿڻ�ȡ��������
	BOOL getRule(int nChannel, CFG_ANALYSERULES_INFO* pCfgAnalyseRulesInfo);

	//��ȡĳͨ��֧�ֵ����й����У����Ĺ���ṹ��Ĵ�С
// 	int getMaxStuSize(DWORD* pRuleType, int nRuleNum);
	int getMaxStuSize(SCENE_SUPPORT_RULE* pRuleType, int nRuleNum);

protected:
	
public:
	typedef enum DlgType
	{
		dlgNone = 0,
		dlgPreview,
		dlgConfig,
		dlgAlarm,
	};
	DlgType		m_currentDlg;
	int			m_nCurrentChn;
	BOOL		m_bIsSwitchOn;
	CPreview*	m_pdlgPreview;
	CConfig*	m_pdlgConfig;
	CAlarm*		m_pdlgAlarm;
	
	//����ͨ�����ĵ��¼������б��رձ��������
	std::list<LONG> m_lsAlarmHandle;

private:
	//
	CLogo* m_pdlgLogo;

	//��¼���
	LLONG m_lLoginHandle;

	//���ž��
	LLONG m_lRealPlayHandle;

	//�������
	LLONG m_lAnalyzerHandle;

	//ʵ�ʵ��豸ͨ����
	int m_nChnCount;

	//////////////////////////////////////////////////////////////////////////
	//�豸������Ϣ�Ľṹ����

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

	//������Ϣ�ڵ�����
	lsAlarmInfo m_lstAlarmInfo;

// Construction
public:
	CDemoIVSbDlg(CWnd* pParent = NULL);	// standard constructor

public:
	void ShowDlg(enum DlgType dlgTYPE);

	// callback for receive alarminfo
	static int  __stdcall RealLoadPicCallback (LLONG lAnalyzerHandle, DWORD dwAlarmType, void* pAlarmInfo, BYTE *pBuffer, DWORD dwBufSize, LDWORD dwUser, int nSequence, void *userdata);

	// work thread for preventing from GUI stuck when a mount of channels call CLIENT_RealLoadPic() at same time
	static DWORD _stdcall ThreadStartAlarm(void* pParam);

// Dialog Data
	//{{AFX_DATA(CDemoIVSbDlg)
	enum { IDD = IDD_DEMOIVSB_DIALOG };
	CButton	m_chkSwitch;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoIVSbDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDemoIVSbDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnPreview();
	afx_msg void OnBtnConfig();
	afx_msg void OnBtnAlarm();
	afx_msg void OnDestroy();
	afx_msg void OnMainChkSwitch();
	afx_msg void OnMainBtnLogout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	
	// respond WM_CLEARINFO msg
	LRESULT OnClearAlarmInfo(WPARAM wParam, LPARAM lParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMOIVSBDLG_H__FCB9A603_26B7_43E9_8657_752A8CD527BB__INCLUDED_)
