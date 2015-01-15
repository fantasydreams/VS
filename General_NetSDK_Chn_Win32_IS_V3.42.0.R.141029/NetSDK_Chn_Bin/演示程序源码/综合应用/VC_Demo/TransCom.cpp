 // TransCom.cpp : implementation file
//

#include "StdAfx.h"
#include "netsdkdemo.h"
#include "TransCom.h"
#include "NetSDKDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTransCom dialog


CTransCom::CTransCom(CWnd* pParent /*=NULL*/)
	: CDialog(CTransCom::IDD, pParent)
{
	m_devHandle = 0;
	//{{AFX_DATA_INIT(CTransCom)
	m_recievestring = _T("");
	m_sendstring = _T("");
	//}}AFX_DATA_INIT
	m_count = 0;
}


void CTransCom::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTransCom)
	DDX_Control(pDX, IDC_COMPORT, m_comport);
	DDX_Control(pDX, IDC_COMSTOPBIT, m_stopbit);
	DDX_Control(pDX, IDC_COMSEL, m_comsel);
	DDX_Control(pDX, IDC_COMPARITY, m_parity);
	DDX_Control(pDX, IDC_COMDATABIT, m_databit);
	DDX_Control(pDX, IDC_BAUDRATE, m_baudrate);
	DDX_Text(pDX, IDC_RECIEVERANGE, m_recievestring);
	DDX_Text(pDX, IDC_EDITCOMSEND, m_sendstring);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTransCom, CDialog)
	//{{AFX_MSG_MAP(CTransCom)
	ON_BN_CLICKED(IDC_OPENCLOSE, OnOpenclose)
	ON_BN_CLICKED(IDC_COMSEND, OnComsend)
	ON_BN_CLICKED(IDC_DELETEREVICE, OnDeleterevice)
	ON_BN_CLICKED(IDC_DELETESEND, OnDeletesend)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_CHECK_COMPORT, OnCheckComport)
	ON_BN_CLICKED(IDC_QUERY_COM_STATE, OnQueryComState)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransCom message handlers
#define	 COM_PORT_NUM  10
#define  BAUDRATE_NUM  8
unsigned int Tbaudrate[BAUDRATE_NUM] = {1200,2400,4800,9600,19200,38400,57600,115200};

BOOL CTransCom::OnInitDialog() 
{
	g_SetWndStaticText(this);
	int i;
	int nIndex;
	CString strTemp;
	
	CDialog::OnInitDialog();

	//初始化com选择
	m_comsel.InsertString(0, "com");
	m_comsel.InsertString(1, "485");
	m_comsel.SetItemData(0, 0);
	m_comsel.SetItemData(1, 1);
	m_comsel.SetCurSel(0);

	//初始化波特率
	for(i = 0; i < BAUDRATE_NUM; i++)
	{
		strTemp.Format(" %d",Tbaudrate[i]);
		m_baudrate.InsertString(i, strTemp.GetBuffer(0));
		m_baudrate.SetItemData(i, i +1);   //设置值为1~8
	}
	m_baudrate.SetCurSel(3);  //默认9600

	//初始化数据位
	for(i = 0; i < 5; i ++)
	{
		strTemp.Format(" %d ",i+4);
		strTemp += ConvertString(MSG_TRANSCOM_DATABIT_BITS);
		m_databit.InsertString(i,strTemp );
		m_databit.SetItemData(i, (DWORD)(i+4));
	}
	m_databit.SetCurSel(4);

	//初始化停止位
	m_stopbit.InsertString(0, ConvertString(MSG_TRANSCOM_STOPBIT_1BIT ));
	m_stopbit.InsertString(1, ConvertString(MSG_TRANSCOM_STOPBIT_15BITS ));
	m_stopbit.InsertString(2, ConvertString(MSG_TRANSCOM_STOPBIT_2BITS ));
	m_stopbit.SetItemData(0, 1);
	m_stopbit.SetItemData(1, 2);
	m_stopbit.SetItemData(2, 3);
	m_stopbit.SetCurSel(0);


	//初始化奇偶检验
	m_parity.InsertString(0, ConvertString(MSG_TRANSCOM_PARITY_NO));
	m_parity.InsertString(1, ConvertString(MSG_TRANSCOM_PARITY_ODD));
	m_parity.InsertString(2, ConvertString(MSG_TRANSCOM_PARITY_EVEN));
	m_parity.SetItemData(0, 3);
	m_parity.SetItemData(1, 1);
	m_parity.SetItemData(2, 2);
	m_parity.SetCurSel(0);

	// 初始化串口号
	for (i = 0; i < COM_PORT_NUM; ++i)
	{
		strTemp.Format("%d", i);
		nIndex = m_comport.AddString(strTemp);
		m_comport.SetItemData(nIndex, i);
	}
	m_comport.SetCurSel(0);
	
	m_isComOpen = FALSE;
	m_comHandle = 0;

	UpdataOpenCloseState();
	
	return TRUE; 
}

void CTransCom::UpdataOpenCloseState()
{
	if(m_isComOpen)
	{
		GetDlgItem(IDC_OPENCLOSE)->SetWindowText(ConvertString(MSG_TRANSCOM_CLOSECOM));
	}
	else
	{
		GetDlgItem(IDC_OPENCLOSE)->SetWindowText(ConvertString(MSG_TRANSCOM_OPENCOM));
	}
}

void CALLBACK TransComCB(LONG lLoginID, LONG lTransComChannel, char *pBuffer, DWORD dwBufSize, DWORD dwUser)
{
	if(dwUser == 0)
	{
		return;
	}
	CTransCom *dlg = (CTransCom *)dwUser;
	dlg->ComRecieveData(lLoginID, lTransComChannel,pBuffer, dwBufSize);

}

void CTransCom::ComRecieveData(LONG lLoginID, LONG lTransComChannel,char *pBuffer, DWORD dwBufSize)
{
	if(lLoginID != m_devHandle || lTransComChannel != m_comHandle )
	{
		return;
	}

	char *tmp = new char[dwBufSize + 1];
	memset(tmp, 0, dwBufSize + 1);
	memcpy(tmp, pBuffer, dwBufSize);
	CString strR;
	strR.Format("%s",tmp);
	m_recievestring += strR;
	GetDlgItem(IDC_RECIEVERANGE)->SetWindowText(m_recievestring);
	if (m_recievestring.GetLength() > 255)
	{
		m_recievestring.Empty();
	}
	delete[] tmp;
}
void CTransCom::OnOpenclose() 
{
	BOOL nRet = TRUE;
	
	if(m_isComOpen)   //已打开时执行关闭
	{
		if(m_comHandle)
		{
			nRet = CLIENT_DestroyTransComChannel(m_comHandle);
			if(nRet)
			{	
				m_comHandle = 0;
			}
			else if(!nRet)
			{
				((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
			}
		}
	}
	else    //打开操作
	{
		if(m_devHandle)
		{
			int nComPort = 0;
			int nComSel = m_comsel.GetItemData(m_comsel.GetCurSel());

			if (IsDlgButtonChecked(IDC_CHECK_COMPORT))
			{
				nComPort = m_comport.GetItemData(m_comport.GetCurSel());
				nComPort = nComPort << 16 | nComSel;
			}
			else
			{
				nComPort = nComSel;
			}

			m_comHandle = CLIENT_CreateTransComChannel(m_devHandle, nComPort,
				m_baudrate.GetItemData(m_baudrate.GetCurSel()),m_databit.GetItemData(m_databit.GetCurSel()),
				m_stopbit.GetItemData(m_stopbit.GetCurSel()),m_parity.GetItemData(m_parity.GetCurSel()),
				TransComCB,(DWORD)this);
			if(m_comHandle)
			{
				nRet = TRUE;
			}
			else
			{
				((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
				MessageBox(MSG_TRANSCOM_OPENTRANSCOMFAILED);
			}
		}
	}
	if(nRet)
	{
		m_isComOpen = !m_isComOpen;
	}
	else if(!nRet)
	{
		((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
	}
	UpdataOpenCloseState();	
}

void CTransCom::SetDeviceId(LONG nDeviceId)
{
	m_devHandle = nDeviceId;
}

//发送
void CTransCom::OnComsend() 
{
	UpdateData();

	if(m_isComOpen && m_comHandle)
	{
		BOOL ret = CLIENT_SendTransComData(m_comHandle, m_sendstring.GetBuffer(0), m_sendstring.GetLength());
		if(!ret)
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
			MessageBox(ConvertString(MSG_TRANSCOM_SENDDATAFAILED));
		}
	}
}

void CTransCom::OnDeleterevice() 
{
	m_recievestring.Empty() ;
	UpdateData(FALSE);
}

void CTransCom::OnDeletesend() 
{
	m_sendstring.Empty();
	UpdateData(false);
}

void CTransCom::OnClose() 
{
	if(m_isComOpen)   //已打开时执行关闭
	{
		if(m_comHandle)
		{
			int nRet = CLIENT_DestroyTransComChannel(m_comHandle);
			if(nRet)
			{	
				m_comHandle = 0;
			}
			else if(!nRet)
			{
				((CNetSDKDemoDlg *)GetParent())->LastError();//Zhengdh 06.11.24
			}
		}
	}
	
	CDialog::OnClose();
}

void CTransCom::OnCheckComport() 
{
	m_comport.EnableWindow(IsDlgButtonChecked(IDC_CHECK_COMPORT));
}

void CTransCom::OnQueryComState() 
{
	if(m_devHandle)
	{
		int nComPort = 0;
		int nComSel = m_comsel.GetItemData(m_comsel.GetCurSel());
		
		if (IsDlgButtonChecked(IDC_CHECK_COMPORT))
		{
			nComPort = m_comport.GetItemData(m_comport.GetCurSel());
			nComPort = nComPort << 16 | nComSel;
		}
		else
		{
			nComPort = nComSel;
		}
		
		DH_COMM_STATE stuInfo = {0};
		BOOL bRet = CLIENT_QueryTransComParams(m_devHandle, nComPort, &stuInfo, 3000);
		if(bRet)
		{
			CString strMsg;
			strMsg.Format("%s: %d\r\n%s: %d\r\n%s: %d\r\n%s: %d\r\n%s: %d", 
				ConvertString("IsOpened"), stuInfo.uBeOpened, 
				ConvertString("BaundRate"), stuInfo.uBaudRate, 
				ConvertString("DataBit"), stuInfo.uDataBites, 
				ConvertString("StopBit"), stuInfo.uStopBits, 
				ConvertString("ParityBit"), stuInfo.uParity);
			MessageBox(strMsg);
		}
		else
		{
			((CNetSDKDemoDlg *)GetParent())->LastError();
			MessageBox(MSG_TRANSCOM_QUERYCOMPARAMFAILED);
		}
	}
}
