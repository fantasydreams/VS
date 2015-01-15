#if !defined(AFX_CONFIGFTP_H__2125E842_D8EE_4499_8210_06B356FB65EC__INCLUDED_)
#define AFX_CONFIGFTP_H__2125E842_D8EE_4499_8210_06B356FB65EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ConfigFTP.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CConfigFTP dialog

typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;							// �Ƿ�����
	char				szHostIp[DH_MAX_IPADDR_LEN];		// ����IP
	WORD				wHostPort;							// �����˿�
	char				szDirName[DH_FTP_MAX_PATH];			// FTPĿ¼·��
	char				szUserName[DH_FTP_USERNAME_LEN];	// �û���
	char				szPassword[DH_FTP_PASSWORD_LEN];	// ����
	int					iFileLen;							// �ļ�����
	int					iInterval;							// �����ļ�ʱ����(1~600),��λ�� 
	DH_FTP_UPLOAD_CFG	struUploadCfg[32][DH_N_WEEKS];
	char 				protocol;							// 0-FTP 1-SMB 2-NFS��3-ISCSI
	char				NASVer;								// ����洢�������汾0=�ϵ�FTP(��������ʾʱ���)��1=NAS�洢(����������ʱ���)
	DWORD				dwFunctionMask;						// �����������룬��λ��ʾ����16λ(����洢)���α�ʾFTP��SMB��NFS��ISCSI, ��16λ(���ش洢)����ΪDISK��U
	BYTE 				reserved[124];
} FTP_PROTO_CFG;

// FTP�ϴ���չ����(֧��ͨ����������FTP�洢·�������洢ͼƬ����)
typedef struct 
{
    int            nMaxPictures;                             // �ܴ洢������ÿһ��ͨ���ļ����е�ͼƬ�����������ƣ�
	// �������ƾ͸����ϵ��ļ�,0:��ʾ�����ƣ�д��Ϊֹ
    char           szPreChannelName[DH_FTP_MAX_SUB_PATH];    // ͼƬ�ļ���
    char           szFTPChannelPath[DH_FTP_MAX_SUB_PATH];    // ftp�洢·��(�洢��Ŀ¼)
    char           szRev[128];                               // �����ֶ�
}FTP_CHANNEL_CFG; 


typedef struct 
{ 
	FTP_PROTO_CFG       stuFtpNormalSet;                             // FTPԭ�й��ܣ���չͨ����
	FTP_CHANNEL_CFG     stuFtpChannelSet[32];           // FTP��չ����
	char                szRev[128];                                 // �����ֶ�
}FTP_PROTO_CFG_EX;


class CConfigFTP : public CDialog
{
// Construction
public:
	CConfigFTP(CWnd* pParent = NULL);   // standard constructor
	void InitFtpInfo();
	void CleanAll(void);

// Dialog Data
	//{{AFX_DATA(CConfigFTP)
	enum { IDD = IDD_CONFIG_FTP };
	CComboBox	m_cbTimePeriod;
	CComboBox	m_cbChannelNum;
	CComboBox   m_cbStorageNum;
	BOOL	m_bFriAlarm;
	BOOL	m_bFriMd;
	BOOL	m_bFriTimer;
	BOOL	m_bFTP;
	BOOL	m_bMonAlarm;
	BOOL	m_bMonMd;
	BOOL	m_bMonTimer;
	BOOL	m_bSatAlarm;
	BOOL	m_bSatMd;
	BOOL	m_bSatTimer;
	BOOL	m_bSunAlarm;
	BOOL	m_bSunMd;
	BOOL	m_bSunTimer;
	BOOL	m_bThursAlarm;
	BOOL	m_bThursMd;
	BOOL	m_bThursTimer;
	BOOL	m_bTuesAlarm;
	BOOL	m_bTuesMd;
	BOOL	m_bTuesTimer;
	BOOL	m_bWenAlarm;
	BOOL	m_bWenMd;
	BOOL	m_bWenTimer;
	
	int		m_nFileLenth;
	int		m_nFri_E1_Hour;
	int		m_nFri_E1_Minute;
	int		m_nFri_E1_Sec;
	int		m_nFri_S1_Hour;
	int		m_nFri_S1_Minute;
	int		m_nFri_S1_Sec;
	//int		m_nMaxPicNum;
	int		m_nMon_E1_Hour;
	int		m_nMon_E1_Minute;
	int		m_nMon_E1_Sec;
	int		m_nMon_S1_Hour;
	int		m_nMon_S1_Minute;
	int		m_nMon_S1_Sec;
	
	int		m_nSat_E1_Hour;
	int		m_nSat_E1_Minute;
	int		m_nSat_E1_Sec;
	int		m_nSat_S1_Hour;
	int		m_nSat_S1_Minute;
	int		m_nSat_S1_Sec;
	int		m_nSun_E1_Hour;
	int		m_nSun_E1_Minute;
	int		m_nSun_E1_Sec;
	int		m_nSun_S1_Hour;
	int		m_nSun_S1_Minute;
	int		m_nSun_S1_Sec;
	int		m_nThurs_E1_Hour;
	int		m_nThurs_E1_Minute;
	int		m_nThurs_E1_Sec;
	int		m_nThurs_S1_Hour;
	int		m_nThurs_S1_Minute;
	int		m_nThurs_S1_Sec;
	int		m_nTues_E1_Hour;
	int		m_nTues_E1_Minute;
	int		m_nTues_E1_Sec;
	int		m_nTues_S1_Hour;
	int		m_nTues_S1_Minute;
	int		m_nTues_S1_Sec;
	CString	m_strName;
	int		m_nWen_E1_Hour;
	int		m_nWen_E1_Minute;
	int		m_nWen_E1_Sec;
	int		m_nWen_S1_Hour;
	int		m_nWen_S1_Minute;
	int		m_nWen_S1_Sec;
	int     m_nInernalTime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConfigFTP)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CConfigFTP)
	afx_msg void OnButtonSaveFtp();
	afx_msg void OnButtonReadFtp();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCOMBOCHANNElNUM();
	afx_msg void OnSelchangeComboTimeperiod();
	afx_msg void OnSelchangeComboStoragenum();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	//FTP_PROTO_CFG_EX m_stuFtpInfo; 

	CFG_REMOTE_STORAGELIMIT_GROUP m_stuRemoteStorage;  // ����洢��������������
	int m_nChannelNum;           // ��Ƶͨ����
	int m_nStorageNum;           // ����洢����������
	int m_nCurrentStorageNum;    // ��ǰѡ�з�������
	int m_nCurrentChannel;       // ��ǰѡ��ͨ����
	int m_nCurrentTimePeriod;    // ����ѡ��ʱ���
	
//	CFG_NAS_INFO_EX m_stuNasInfoEx;

	void ShowConfigInfo(void);
	void SaveConfigInfo(void);

	bool IsWeekDataValid();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONFIGFTP_H__2125E842_D8EE_4499_8210_06B356FB65EC__INCLUDED_)
