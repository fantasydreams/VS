// AlarmVLostDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo5.h"
#include "AlarmVLostDlg.h"
#include "ClientDemo5Dlg.h"
#include "DriveRecordChn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAlarmVLostDlg dialog


CAlarmVLostDlg::CAlarmVLostDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAlarmVLostDlg::IDD, pParent)
	, m_vecAlarmName(NULL)
{
	//{{AFX_DATA_INIT(CAlarmVLostDlg)
	m_prd1EndHour = 24;
	m_prd1StartHour = 0;
	m_prd1EndMinute = 0;
	m_prd1StartMinute = 0;
	m_prd1EndSecond = 0;
	m_prd1StartSecond = 0;
	m_prd2EndHour = 24;
	m_prd2StartHour = 0;
	m_prd2StartMinute = 0;
	m_prd2EndSecond = 0;
	m_prd3EndHour = 24;
	m_prd3EndMinute = 0;
	m_prd3StartMinute = 0;
	m_prd3EndSecond = 0;
	m_prd3StartSecond = 0;
	m_prd4EndHour = 24;
	m_prd4StartHour = 0;
	m_prd4EndMinute = 0;
	m_prd4StartMinute = 0;
	m_prd4EndSecond = 0;
	m_prd4StartSecond = 0;
	m_prd2EndMinute = 0;
	m_prd5EndHour = 24;
	m_prd5StartHour = 0;
	m_prd5EndMinute = 0;
	m_prd5StartMinute = 0;
	m_prd5EndSecond = 0;
	m_prd5StartSecond = 0;
	m_prd6EndHour = 24;
	m_prd6StartHour = 0;
	m_prd6EndMinute = 0;
	m_prd6StartMinute = 0;
	m_prd6EndSecond = 0;
	m_prd6StartSecond = 0;
	m_prd2StartSecond = 0;
	m_prd3StartHour = 0;
	m_bMatrixEn = FALSE;
	m_bLog = FALSE;
	m_dwAmount = 0;
	m_dwMatrixMask = 0;
	//}}AFX_DATA_INIT
	m_nChannel = 0;
	m_nAlarmOut = 0;
	m_nCurAlarmChannel = -1;
	m_nCurWeek = -1;
//	m_bNewProtocol = FALSE;
	m_pstVideoLostInfo = NULL;
	
}


void CAlarmVLostDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAlarmVLostDlg)
	DDX_Control(pDX, IDC_EDIT_VIDEOLOST_ALARMNAME, m_editAlarmName);
	DDX_Control(pDX, IDC_CHECK_VPRD6, m_ctlPRD6);
	DDX_Control(pDX, IDC_CHECK_VPRD5, m_ctlPRD5);
	DDX_Control(pDX, IDC_CHECK_VPRD4, m_ctlPRD4);
	DDX_Control(pDX, IDC_CHECK_VPRD3, m_ctlPRD3);
	DDX_Control(pDX, IDC_CHECK_VPRD2, m_ctlPRD2);
	DDX_Control(pDX, IDC_CHECK_VPRD1, m_ctlPRD1);
	DDX_Control(pDX, IDC_CHECK_LOCALTOUR, m_chkLocalTour);
	DDX_Control(pDX, IDC_CHECK_LOCALTIP, m_chkLocalIP);
	DDX_Control(pDX, IDC_CHECK_UPLOAD, m_chkUpload);
	DDX_Control(pDX, IDC_CHECK_SENDMAIL, m_chkSendMail);
	DDX_Control(pDX, IDC_CHECK_RECORD, m_chkRecord);
	DDX_Control(pDX, IDC_CHECK_OUTPUT, m_chkOutPut);
	DDX_Control(pDX, IDC_CHECK_ENABLE, m_chkAlarmEn);
	DDX_Control(pDX, IDC_COMBO_CHANNEL, m_ctlChannel);
	DDX_Control(pDX, IDC_COMBO_ALARMWEEK, m_ctlAlarmWeek);
	DDX_Text(pDX, IDC_EDIT_VPRD1_E_HOUR, m_prd1EndHour);
	DDV_MinMaxUInt(pDX, m_prd1EndHour, 0, 24);
	DDX_Text(pDX, IDC_EDIT_VPRD1_S_HOUR, m_prd1StartHour);
	DDV_MinMaxUInt(pDX, m_prd1StartHour, 0, 24);
	DDX_Text(pDX, IDC_EDIT_VPRD1_E_MINUTE, m_prd1EndMinute);
	DDV_MinMaxUInt(pDX, m_prd1EndMinute, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD1_S_MINUTE, m_prd1StartMinute);
	DDV_MinMaxUInt(pDX, m_prd1StartMinute, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD1_E_SEC, m_prd1EndSecond);
	DDV_MinMaxUInt(pDX, m_prd1EndSecond, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD1_S_SEC, m_prd1StartSecond);
	DDV_MinMaxUInt(pDX, m_prd1StartSecond, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD2_E_HOUR, m_prd2EndHour);
	DDV_MinMaxUInt(pDX, m_prd2EndHour, 0, 24);
	DDX_Text(pDX, IDC_EDIT_VPRD2_S_HOUR, m_prd2StartHour);
	DDV_MinMaxUInt(pDX, m_prd2StartHour, 0, 24);
	DDX_Text(pDX, IDC_EDIT_VPRD2_S_MINUTE, m_prd2StartMinute);
	DDV_MinMaxUInt(pDX, m_prd2StartMinute, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD2_E_SEC, m_prd2EndSecond);
	DDV_MinMaxUInt(pDX, m_prd2EndSecond, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD3_E_HOUR, m_prd3EndHour);
	DDV_MinMaxUInt(pDX, m_prd3EndHour, 0, 24);
	DDX_Text(pDX, IDC_EDIT_VPRD3_E_MINUTE, m_prd3EndMinute);
	DDV_MinMaxUInt(pDX, m_prd3EndMinute, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD3_S_MINUTE, m_prd3StartMinute);
	DDV_MinMaxUInt(pDX, m_prd3StartMinute, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD3_E_SEC, m_prd3EndSecond);
	DDV_MinMaxUInt(pDX, m_prd3EndSecond, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD3_S_SEC, m_prd3StartSecond);
	DDV_MinMaxUInt(pDX, m_prd3StartSecond, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD4_E_HOUR, m_prd4EndHour);
	DDV_MinMaxUInt(pDX, m_prd4EndHour, 0, 24);
	DDX_Text(pDX, IDC_EDIT_VPRD4_S_HOUR, m_prd4StartHour);
	DDV_MinMaxUInt(pDX, m_prd4StartHour, 0, 24);
	DDX_Text(pDX, IDC_EDIT_VPRD4_E_MINUTE, m_prd4EndMinute);
	DDV_MinMaxUInt(pDX, m_prd4EndMinute, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD4_S_MINUTE, m_prd4StartMinute);
	DDV_MinMaxUInt(pDX, m_prd4StartMinute, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD4_E_SEC, m_prd4EndSecond);
	DDV_MinMaxUInt(pDX, m_prd4EndSecond, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD4_S_SEC, m_prd4StartSecond);
	DDV_MinMaxUInt(pDX, m_prd4StartSecond, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD2_E_MINUTE, m_prd2EndMinute);
	DDV_MinMaxUInt(pDX, m_prd2EndMinute, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD5_E_HOUR, m_prd5EndHour);
	DDV_MinMaxUInt(pDX, m_prd5EndHour, 0, 24);
	DDX_Text(pDX, IDC_EDIT_VPRD5_S_HOUR, m_prd5StartHour);
	DDV_MinMaxUInt(pDX, m_prd5StartHour, 0, 24);
	DDX_Text(pDX, IDC_EDIT_VPRD5_E_MINUTE, m_prd5EndMinute);
	DDV_MinMaxUInt(pDX, m_prd5EndMinute, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD5_S_MINUTE, m_prd5StartMinute);
	DDV_MinMaxUInt(pDX, m_prd5StartMinute, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD5_E_SEC, m_prd5EndSecond);
	DDV_MinMaxUInt(pDX, m_prd5EndSecond, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD5_S_SEC, m_prd5StartSecond);
	DDV_MinMaxUInt(pDX, m_prd5StartSecond, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD6_E_HOUR, m_prd6EndHour);
	DDV_MinMaxUInt(pDX, m_prd6EndHour, 0, 24);
	DDX_Text(pDX, IDC_EDIT_VPRD6_S_HOUR, m_prd6StartHour);
	DDV_MinMaxUInt(pDX, m_prd6StartHour, 0, 24);
	DDX_Text(pDX, IDC_EDIT_VPRD6_E_MINUTE, m_prd6EndMinute);
	DDV_MinMaxUInt(pDX, m_prd6EndMinute, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD6_S_MINUTE, m_prd6StartMinute);
	DDV_MinMaxUInt(pDX, m_prd6StartMinute, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD6_E_SEC, m_prd6EndSecond);
	DDV_MinMaxUInt(pDX, m_prd6EndSecond, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD6_S_SEC, m_prd6StartSecond);
	DDV_MinMaxUInt(pDX, m_prd6StartSecond, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD2_S_SEC, m_prd2StartSecond);
	DDV_MinMaxUInt(pDX, m_prd2StartSecond, 0, 59);
	DDX_Text(pDX, IDC_EDIT_VPRD3_S_HOUR, m_prd3StartHour);
	DDV_MinMaxUInt(pDX, m_prd3StartHour, 0, 24);
	DDX_Check(pDX, IDC_CHECK_MATRIX_EN, m_bMatrixEn);
	DDX_Check(pDX, IDC_CHECK_BLOG, m_bLog);
	DDX_Text(pDX, IDC_EDIT_AMOUNT, m_dwAmount);
	DDV_MinMaxUInt(pDX, m_dwAmount, 0, 255);
	DDX_Text(pDX, IDC_EDIT_MATRIX_MASK, m_dwMatrixMask);
	DDV_MinMaxUInt(pDX, m_dwMatrixMask, 0, 65535);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAlarmVLostDlg, CDialog)
	//{{AFX_MSG_MAP(CAlarmVLostDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_CHANNEL, OnSelchangeComboChannel)
	ON_CBN_SELCHANGE(IDC_COMBO_ALARMWEEK, OnSelchangeComboAlarmweek)
	ON_WM_CANCELMODE()
	ON_EN_CHANGE(IDC_EDIT_VIDEOLOST_ALARMNAME, OnChangeEditVideolostAlarmname)
	ON_BN_CLICKED(IDC_BTN_DRIVE_RECORD, OnBtnDriveRecord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAlarmVLostDlg message handlers

/*
 *	Function��display camera masking alarm information
 *	Input parameter��
 *	pAlarmInfo��alarm configuration structure
 *	nAlarmIn��Alarm input channel amount
 *	nAlarmOut��Alarm output channel 
 *	nChannel��Channel amount
 */
void CAlarmVLostDlg::InitDlgInfo(DHDEV_ALARM_SCHEDULE_EX *pAlarmInfo, BYTE nAlarmIn, BYTE nAlarmOut, int nChannel, vector<string>& vecAlarmName)
{
	if(pAlarmInfo != NULL)
	{
		m_vecAlarmName = &vecAlarmName;
		int i =0;
		m_nAlarmOut = nAlarmOut;
		m_nChannel = nChannel;	
		m_pstVideoLostInfo = new CFG_VIDEOLOST_INFO[CHANNEL_NUM_LIMIT];

			
		//Set channel dropdown menu
		m_ctlChannel.ResetContent();
		CString strAlarm;
		int nIndex = 0;
		for (i = 0; i < nChannel; i++)
		{
			strAlarm.Format(ConvertString("Channel %d"), i+1);
			nIndex = m_ctlChannel.AddString(strAlarm);
			m_ctlChannel.SetItemData(nIndex,i);
		}
		
		//Alarm output 
		BYTE byRelInitVal[32] = {0};
		m_chnAlarmOut.SetChnState(byRelInitVal,nAlarmOut);
		if (m_ctlChannel.GetCount() > 0)
		{
			m_ctlChannel.SetCurSel(0);	
			OnSelchangeComboChannel();
		}
	}
}

void CAlarmVLostDlg::RefreshAlarmName()
{
	g_RefreshAlarmName(m_vecAlarmName, m_nCurAlarmChannel, m_editAlarmName);
}

//Clear information
void CAlarmVLostDlg::CleanAll()
{
	m_ctlChannel.ResetContent();
	m_chkAlarmEn.SetCheck(0);
	m_chkUpload.SetCheck(0);
	m_chkLocalIP.SetCheck(0);
	m_chkLocalTour.SetCheck(0);
	m_chkSendMail.SetCheck(0);
	m_chkRecord.SetCheck(0);
	m_chkOutPut.SetCheck(0);

	BYTE byRelInitVal[32] = {0};
	m_chnAlarmOut.SetChnState(byRelInitVal,32);

	int i=0;
	m_ctlAlarmWeek.SetCurSel(-1);
	for(i=0;i<6;i++)
	{
		CFG_TIME_SECTION periodInfo = {0};
		periodInfo.nEndHour = 24;
		ShowPeriodInfo(&periodInfo,i+1);
	}
	
	m_nChannel = 0;
	m_nAlarmOut = 0;
	m_nCurAlarmChannel = -1;
	m_nCurWeek = -1;

	m_vecAlarmName = NULL;
	m_editAlarmName.EnableWindow(FALSE);
	m_editAlarmName.SetWindowText("");

	if(NULL != m_pstVideoLostInfo)
	{
		delete[] m_pstVideoLostInfo;
		m_pstVideoLostInfo = NULL;
	}

}

//Save
BOOL CAlarmVLostDlg::SaveAll()
{
	BOOL bSuccess = FALSE;
	if(-1 != m_ctlChannel.GetCurSel())
	{
		bSuccess = SaveAlarmChannelInfo(m_nCurAlarmChannel);
	}
	return bSuccess;
}

//Channel option switch
void CAlarmVLostDlg::OnSelchangeComboChannel() 
{
	// TODO: Add your control notification handler code here
	int nIndex = m_ctlChannel.GetCurSel();
	if(CB_ERR != nIndex)
	{
		int nNum = (int)m_ctlChannel.GetItemData(nIndex);
		
		//First save channel information
		SaveAlarmChannelInfo(m_nCurAlarmChannel);


		((CClientDemo5Dlg*)AfxGetMainWnd())->GetLossAlarmConfigInfo(&m_pstVideoLostInfo[nNum], nIndex);

		
		m_chkAlarmEn.SetCheck(m_pstVideoLostInfo[nNum].bEnable?1:0);
		
		if(m_pstVideoLostInfo[nNum].stuEventHandler.abMessageEnable)
		{
			GetDlgItem(IDC_CHECK_UPLOAD)->EnableWindow(TRUE);
			m_chkUpload.SetCheck(m_pstVideoLostInfo[nNum].stuEventHandler.bMessageEnable ?TRUE:FALSE);
		}
		else
		{	
			m_chkUpload.SetCheck(FALSE);
			GetDlgItem(IDC_CHECK_UPLOAD)->EnableWindow(FALSE);
		}
		
		if(m_pstVideoLostInfo[nNum].stuEventHandler.abTipEnable)
		{	
			GetDlgItem(IDC_CHECK_LOCALTIP)->EnableWindow(TRUE);
			m_chkLocalIP.SetCheck(m_pstVideoLostInfo[nNum].stuEventHandler.bTipEnable ?TRUE:FALSE);
		}
		else
		{
			GetDlgItem(IDC_CHECK_LOCALTIP)->EnableWindow(FALSE);
			m_chkLocalIP.SetCheck(FALSE);
		}
		
		if(m_pstVideoLostInfo[nNum].stuEventHandler.abTourEnable)
		{
			GetDlgItem(IDC_CHECK_LOCALTOUR)->EnableWindow(TRUE);
			m_chkLocalTour.SetCheck(m_pstVideoLostInfo[nNum].stuEventHandler.bTourEnable ?TRUE:FALSE);
		}
		else
		{
			GetDlgItem(IDC_CHECK_LOCALTOUR)->EnableWindow(FALSE);
			m_chkLocalTour.SetCheck(FALSE);
		}
		
		if(m_pstVideoLostInfo[nNum].stuEventHandler.abMailEnable)
		{
			GetDlgItem(IDC_CHECK_SENDMAIL)->EnableWindow(TRUE);
			m_chkSendMail.SetCheck(m_pstVideoLostInfo[nNum].stuEventHandler.bMailEnable?TRUE:FALSE);
		}
		else
		{
			GetDlgItem(IDC_CHECK_SENDMAIL)->EnableWindow(FALSE);
			m_chkSendMail.SetCheck(FALSE);
		}
		
		if(m_pstVideoLostInfo[nNum].stuEventHandler.abRecordEnable 
			&&m_pstVideoLostInfo[nNum].stuEventHandler.bRecordEnable)
		{
			m_chkRecord.SetCheck(TRUE);	
		}
		else
		{
			m_chkRecord.SetCheck(FALSE);
		}
		
		if(m_pstVideoLostInfo[nNum].stuEventHandler.abAlarmOutEn
			&&m_pstVideoLostInfo[nNum].stuEventHandler.bAlarmOutEn)
		{
			m_chkOutPut.SetCheck(TRUE);	
		}
		else
		{
			m_chkOutPut.SetCheck(FALSE);
		}
		m_chnAlarmOut.SetChnState(m_pstVideoLostInfo[nNum].stuEventHandler.dwAlarmOutMask[0],m_nAlarmOut);

		//Time period
		if (m_ctlAlarmWeek.GetCount() > 0)
		{
			m_ctlAlarmWeek.SetCurSel(0);
			OnSelchangeComboAlarmweek();
		}
	
		m_dwMatrixMask = (unsigned short)m_pstVideoLostInfo[nNum].stuEventHandler.dwMatrixMask[0];
		m_dwAmount     = m_pstVideoLostInfo[nNum].stuEventHandler.nSnapshotTimes;
		m_bLog		   = m_pstVideoLostInfo[nNum].stuEventHandler.bLogEnable;
		m_bMatrixEn    = m_pstVideoLostInfo[nNum].stuEventHandler.bMatrixEnable;
		UpdateData(FALSE);

		m_nCurAlarmChannel = nNum;

		RefreshAlarmName();
	}
}

//Save channel information
BOOL CAlarmVLostDlg::SaveAlarmChannelInfo(int nNum)
{
	BOOL bValid = TRUE;
	if(-1 < nNum && -1 < m_nCurWeek)
	{
		CFG_VIDEOLOST_INFO *pInfo = &m_pstVideoLostInfo[nNum];
		if(NULL != pInfo)
		{
			pInfo->bEnable    = m_chkAlarmEn.GetCheck();
			
			pInfo->stuEventHandler.bMessageEnable = m_chkUpload.GetCheck();
			
			pInfo->stuEventHandler.bTipEnable = m_chkLocalIP.GetCheck();
			
			pInfo->stuEventHandler.bTourEnable = m_chkLocalTour.GetCheck();
			
			pInfo->stuEventHandler.bMailEnable = m_chkSendMail.GetCheck();
			
			pInfo->stuEventHandler.bRecordEnable = m_chkRecord.GetCheck();
			
			pInfo->stuEventHandler.bAlarmOutEn = m_chkOutPut.GetCheck();
			
			pInfo->stuEventHandler.dwAlarmOutMask[0] = 0;
			m_chnAlarmOut.GetChnState(pInfo->stuEventHandler.dwAlarmOutMask, m_nAlarmOut);
			// ����������ͨ���й�ѡ����Ҫ��ʹ����Ϊture�������ṹ��תΪjosnʱ�ж�����
			if (0 != pInfo->stuEventHandler.dwAlarmOutMask[0])
            {
				pInfo->stuEventHandler.abAlarmOutMask = true;
            }	
			UpdateData(TRUE);
			
			pInfo->stuEventHandler.dwMatrixMask[0] = m_dwMatrixMask;
			pInfo->stuEventHandler.nSnapshotTimes  = m_dwAmount;
			pInfo->stuEventHandler.bLogEnable      = m_bLog;
			pInfo->stuEventHandler.bMatrixEnable   = m_bMatrixEn;
			
			//Save week period information 
			bValid = SaveWeekInfo(nNum,m_nCurWeek);
		}
	}
	return bValid;
}

//Save week time period information
BOOL CAlarmVLostDlg::SaveWeekInfo(int nNum, int nWeek)
{
	BOOL bValid = TRUE;
	if(-1 < nNum && -1 < nWeek)
	{
		if(UpdateData(TRUE))
		{
			CFG_TIME_SECTION *pPeriodInfo = &(m_pstVideoLostInfo[nNum].stuTimeSection[nWeek][0]);
			
			pPeriodInfo->dwRecordMask = m_ctlPRD1.GetCheck();
			pPeriodInfo->nBeginHour   = m_prd1StartHour;
			pPeriodInfo->nBeginMin    = m_prd1StartMinute;
			pPeriodInfo->nBeginSec    = m_prd1StartSecond;
			pPeriodInfo->nEndHour     = m_prd1EndHour;
			pPeriodInfo->nEndMin      = m_prd1EndMinute;
			pPeriodInfo->nEndSec      = m_prd1EndSecond;
			
			pPeriodInfo = &(m_pstVideoLostInfo[nNum].stuTimeSection[nWeek][1]);
			pPeriodInfo->dwRecordMask = m_ctlPRD2.GetCheck();
			pPeriodInfo->nBeginHour   = m_prd2StartHour;
			pPeriodInfo->nBeginMin    = m_prd2StartMinute;
			pPeriodInfo->nBeginSec    = m_prd2StartSecond;
			pPeriodInfo->nEndHour     = m_prd2EndHour;
			pPeriodInfo->nEndMin      = m_prd2EndMinute;
			pPeriodInfo->nEndSec      = m_prd2EndSecond;
			
			
			pPeriodInfo = &(m_pstVideoLostInfo[nNum].stuTimeSection[nWeek][2]);
			pPeriodInfo->dwRecordMask = m_ctlPRD3.GetCheck();
			pPeriodInfo->nBeginHour   = m_prd3StartHour;
			pPeriodInfo->nBeginMin    = m_prd3StartMinute;
			pPeriodInfo->nBeginSec    = m_prd3StartSecond;
			pPeriodInfo->nEndHour     = m_prd3EndHour;
			pPeriodInfo->nEndMin      = m_prd3EndMinute;
			pPeriodInfo->nEndSec      = m_prd3EndSecond;
			
			
			pPeriodInfo = &(m_pstVideoLostInfo[nNum].stuTimeSection[nWeek][3]);
			pPeriodInfo->dwRecordMask = m_ctlPRD4.GetCheck();
			pPeriodInfo->nBeginHour   = m_prd4StartHour;
			pPeriodInfo->nBeginMin    = m_prd4StartMinute;
			pPeriodInfo->nBeginSec    = m_prd4StartSecond;
			pPeriodInfo->nEndHour     = m_prd4EndHour;
			pPeriodInfo->nEndMin      = m_prd4EndMinute;
			pPeriodInfo->nEndSec      = m_prd4EndSecond;
			
			
			pPeriodInfo = &(m_pstVideoLostInfo[nNum].stuTimeSection[nWeek][4]);
			pPeriodInfo->dwRecordMask = m_ctlPRD5.GetCheck();
			pPeriodInfo->nBeginHour   = m_prd5StartHour;
			pPeriodInfo->nBeginMin    = m_prd5StartMinute;
			pPeriodInfo->nBeginSec    = m_prd5StartSecond;
			pPeriodInfo->nEndHour     = m_prd5EndHour;
			pPeriodInfo->nEndMin      = m_prd5EndMinute;
			pPeriodInfo->nEndSec      = m_prd5EndSecond;
			
			
			pPeriodInfo = &(m_pstVideoLostInfo[nNum].stuTimeSection[nWeek][5]);
			pPeriodInfo->dwRecordMask = m_ctlPRD6.GetCheck();
			pPeriodInfo->nBeginHour   = m_prd6StartHour;
			pPeriodInfo->nBeginMin    = m_prd6StartMinute;
			pPeriodInfo->nBeginSec    = m_prd6StartSecond;
			pPeriodInfo->nEndHour     = m_prd6EndHour;
			pPeriodInfo->nEndMin      = m_prd6EndMinute;
			pPeriodInfo->nEndSec      = m_prd6EndSecond;
		}
		else
		{
			bValid = FALSE;
		}
	}
	return bValid;
}

//Period switch 
void CAlarmVLostDlg::OnSelchangeComboAlarmweek() 
{
	// TODO: Add your control notification handler code here
	int nIndex = m_ctlChannel.GetCurSel();
	if(CB_ERR != nIndex)
	{
		int nNum = m_ctlChannel.GetItemData(nIndex);
		nIndex = m_ctlAlarmWeek.GetCurSel();
		if(CB_ERR != nIndex)
		{
			//First save week period information
			SaveWeekInfo(m_nCurAlarmChannel,m_nCurWeek);
			//Display week period information 
			for(int i=0;i<6;i++)
			{
				CFG_TIME_SECTION periodInfo = m_pstVideoLostInfo[nNum].stuTimeSection[nIndex][i];
				ShowPeriodInfo(&periodInfo,i+1);
			}
			
			m_nCurWeek = nIndex;
		}
	}
}

//Display period information
void CAlarmVLostDlg::ShowPeriodInfo(CFG_TIME_SECTION *pTSect, BYTE nNum)
{
	switch(nNum) {
	case 1:
		m_ctlPRD1.SetCheck((pTSect->dwRecordMask)?1:0);
		m_prd1StartHour = pTSect->nBeginHour;
		m_prd1StartMinute = pTSect->nBeginMin;
		m_prd1StartSecond = pTSect->nBeginSec;
		m_prd1EndHour = pTSect->nEndHour;
		m_prd1EndMinute = pTSect->nEndMin;
		m_prd1EndSecond = pTSect->nEndSec;
		break;
	case 2:
		m_ctlPRD2.SetCheck((pTSect->dwRecordMask)?1:0);
		m_prd2StartHour = pTSect->nBeginHour;
		m_prd2StartMinute = pTSect->nBeginMin;
		m_prd2StartSecond = pTSect->nBeginSec;
		m_prd2EndHour = pTSect->nEndHour;
		m_prd2EndMinute = pTSect->nEndMin;
		m_prd2EndSecond = pTSect->nEndSec;
		break;
	case 3:
		m_ctlPRD3.SetCheck((pTSect->dwRecordMask)?1:0);
		m_prd3StartHour = pTSect->nBeginHour;
		m_prd3StartMinute = pTSect->nBeginMin;
		m_prd3StartSecond = pTSect->nBeginSec;
		m_prd3EndHour = pTSect->nEndHour;
		m_prd3EndMinute = pTSect->nEndMin;
		m_prd3EndSecond = pTSect->nEndSec;
		break;
	case 4:
		m_ctlPRD4.SetCheck((pTSect->dwRecordMask)?1:0);
		m_prd4StartHour = pTSect->nBeginHour;
		m_prd4StartMinute = pTSect->nBeginMin;
		m_prd4StartSecond = pTSect->nBeginSec;
		m_prd4EndHour = pTSect->nEndHour;
		m_prd4EndMinute = pTSect->nEndMin;
		m_prd4EndSecond = pTSect->nEndSec;
		break;
	case 5:
		m_ctlPRD5.SetCheck((pTSect->dwRecordMask)?1:0);
		m_prd5StartHour = pTSect->nBeginHour;
		m_prd5StartMinute = pTSect->nBeginMin;
		m_prd5StartSecond = pTSect->nBeginSec;
		m_prd5EndHour = pTSect->nEndHour;
		m_prd5EndMinute = pTSect->nEndMin;
		m_prd5EndSecond = pTSect->nEndSec;
		break;
	case 6:
		m_ctlPRD6.SetCheck((pTSect->dwRecordMask)?1:0);
		m_prd6StartHour = pTSect->nBeginHour;
		m_prd6StartMinute = pTSect->nBeginMin;
		m_prd6StartSecond = pTSect->nBeginSec;
		m_prd6EndHour = pTSect->nEndHour;
		m_prd6EndMinute = pTSect->nEndMin;
		m_prd6EndSecond = pTSect->nEndSec;
		break;
	default:
		break;
	}
	UpdateData(FALSE);
}

BOOL CAlarmVLostDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	g_SetWndStaticText(this);
	// TODO: Add extra initialization here
	ConvertComboBox(m_ctlAlarmWeek);
	m_chnAlarmOut.Create(IDD_DIALOG_CHN, this);
	m_chnAlarmOut.Attach(IDC_STATIC_ALARMOUT, this);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAlarmVLostDlg::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void CAlarmVLostDlg::UpdateSchedule()
{
	UpdateData(TRUE);
	int nIndex = m_ctlChannel.GetCurSel();
	if(CB_ERR != nIndex)
	{
		int nNum = m_ctlChannel.GetItemData(nIndex);
		nIndex = m_ctlAlarmWeek.GetCurSel();
		if(CB_ERR != nIndex)
		{
			//Show week period information 
			for (int i = 0; i < 6; i++)
			{
				CFG_TIME_SECTION periodInfo = m_pstVideoLostInfo[nNum].stuTimeSection[nIndex][i];
				ShowPeriodInfo(&periodInfo,i+1);
			}
			
			m_nCurWeek = nIndex;
		}
	}
}


void CAlarmVLostDlg::OnChangeEditVideolostAlarmname() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	g_OnChangeEditAlarmname(m_vecAlarmName, m_nCurAlarmChannel, m_editAlarmName);
	
}

void CAlarmVLostDlg::OnBtnDriveRecord() 
{
	// TODO: Add your control notification handler code here
	int nIndex = m_ctlChannel.GetCurSel();
	if (CB_ERR == nIndex)
	{
		MessageBox(ConvertString("Please select channel!"), ConvertString("Prompt"));
		return;
	}
	if (NULL == m_pstVideoLostInfo)
	{	
		return;
	}
	int nNum = m_ctlChannel.GetItemData(nIndex);
	DriveRecordChn recordChnDlg;
	// save markinfo to dlgchannel
	BOOL bRet = recordChnDlg.SetRecordMark(m_pstVideoLostInfo[nNum].stuEventHandler.dwRecordMask, m_nChannel);
	if (!bRet)
	{
		return;
	}
	if (IDOK == recordChnDlg.DoModal())
	{
		memcpy(m_pstVideoLostInfo[nNum].stuEventHandler.dwRecordMask, 
			recordChnDlg.GetRecordMark(), MAX_CHANNEL_COUNT*sizeof(DWORD));
		for (int i = 0; i < MAX_CHANNEL_COUNT; i++)
        {
			if (0 != m_pstVideoLostInfo[nNum].stuEventHandler.dwRecordMask[i])
			{
				m_pstVideoLostInfo[nNum].stuEventHandler.abRecordMask = true;
				break;
			}
        }
	}
}
