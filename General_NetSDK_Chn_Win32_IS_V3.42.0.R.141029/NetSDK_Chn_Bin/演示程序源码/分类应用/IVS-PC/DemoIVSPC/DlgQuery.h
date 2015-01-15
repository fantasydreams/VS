#ifndef __DLG_QUERY_HEADER__
#define __DLG_QUERY_HEADER__

// CDlgQuery �Ի���
class CDrawFrame;

class CDlgQuery : public CDialog
{
	DECLARE_DYNAMIC(CDlgQuery)

public:
	CDlgQuery(CWnd* pParent = NULL);   // ��׼���캯��
	CDlgQuery(int nChannelCount, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgQuery();

	void InitQueryDlg(int nChanCount);
	void UninitQueryDlg();
	void ShowListResult( NET_OUT_DOFINDNUMBERSTAT &FindNumber);
	void ShowListResultRange(NET_OUT_DOFINDNUMBERSTAT &FindNumber, int nIndex, int nCount);
	void ResizeWnd();
	void Draw(NET_OUT_DOFINDNUMBERSTAT &FindNumber,int nIndexStart, int nCount);
	void InitCommboxDate();
	void ShowPreNextEnable();

// �Ի�������
	enum { IDD = IDD_QUERY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnPreview();
	afx_msg void OnBnClickedBtnNext();
	afx_msg void OnBnClickedQueryStart();
	afx_msg LRESULT OnSelectRecord(WPARAM, LPARAM);

private:
	/// \var CDateTimeCtrl	m_dtpStartTime
	/// ��ʼʱ���ؼ�
	CDateTimeCtrl	m_dtpStartTime;
	/// \var CDateTimeCtrl	m_dtpStartDate
	/// ��ʼ���ڵ�ؼ�
	CDateTimeCtrl	m_dtpStartDate;
	/// \var CDateTimeCtrl	m_dtpEndTime
	/// ����ʱ���ؼ�
	CDateTimeCtrl	m_dtpEndTime;
	/// \var CDateTimeCtrl	m_dtpEndDate
    /// �������ڿؼ�
	CDateTimeCtrl	m_dtpEndDate;
	/// \var CComboBox	    m_cmbChannel
	/// ͨ��ѡ��ؼ�
	CComboBox	    m_cmbChannel;
	/// \var CComboBox       m_cmbTypes
	/// ����ѡ��ؼ�
	CComboBox       m_cmbTypes;
	/// \var CEdit  m_editBegin
	/// ��ѯ��ʼ��ſؼ�
	CEdit           m_editBegin;
	/// \var  CEdit m_editCount
	/// ��ѯ��Ŀ�ؼ�
	CEdit           m_editCount;
	/// \var int    m_nChannelCount
	/// �豸ͨ��������
	int             m_nChannelCount;
	/// \var CListCtrl  m_listResult
    /// ���ؽ����Ϣ
	CListCtrl       m_listResult;
	CDrawFrame * m_dlgDrawFrame;
	NET_OUT_DOFINDNUMBERSTAT m_stuDoFindNumberStat_out;
	//���������ڲ�ѯʱ����ҳ��ʾ
	int m_dwIndexStart;
	//���������ڲ�ѯʱ����ҳ��ʾ
	int m_dwIndexEnd;
	//���ڼ�¼��һ��ѡ�е���

	// ���ڱ�ʾ��ҳ�Ĵ�С
	int m_nPageNum;
};
#endif