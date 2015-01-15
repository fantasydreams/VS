// ConfigAlarmMotionArea.cpp : implementation file
//

#include "stdafx.h"
#include "ClientDemo5.h"
#include "ConfigAlarmMotionArea.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConfigAlarmMotionArea dialog


CConfigAlarmMotionArea::CConfigAlarmMotionArea(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigAlarmMotionArea::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConfigAlarmMotionArea)
	m_nAreaThreshold = 0;
	m_nSensitivity = 0;
	//}}AFX_DATA_INIT
	m_bDrawing = FALSE;
	m_blckWid = 0;
	m_blckHght = 0;
	m_stpoint.x = -1;
	m_stpoint.y = -1;
	m_lastpoint.y = -1;
	m_lastpoint.y = -1;

	m_wRows = DH_MOTION_ROW;
	m_wCols = DH_MOTION_COL;

	m_bNewPro = FALSE;
	m_pMotionInfo = NULL;
}


void CConfigAlarmMotionArea::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConfigAlarmMotionArea)
	DDX_Text(pDX, IDC_EDIT_AREATHRESHOLD, m_nAreaThreshold);
	DDV_MinMaxInt(pDX, m_nAreaThreshold, -1, 100);
	DDX_Text(pDX, IDC_EDIT_SENSITIVITY, m_nSensitivity);
	DDV_MinMaxInt(pDX, m_nSensitivity, -1, 100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CConfigAlarmMotionArea, CDialog)
	//{{AFX_MSG_MAP(CConfigAlarmMotionArea)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON_ADDRECT, OnButtonAddrect)
	ON_BN_CLICKED(IDC_BUTTON_DELRECT, OnButtonDelrect)
	ON_EN_CHANGE(IDC_EDIT_AREATHRESHOLD, OnChangeEditAreathreshold)
	ON_EN_CHANGE(IDC_EDIT_SENSITIVITY, OnChangeEditSensitivity)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConfigAlarmMotionArea message handlers

void CConfigAlarmMotionArea::OnOK() 
{
	// TODO: Add extra validation here
	if (m_bNewPro)
	{
		m_pMotionInfo->nWindowCount = 0;
		memset(m_pMotionInfo, 0, sizeof(m_pMotionInfo->stuWindows[0]) * MAX_MOTION_WINDOW);

		int i = 0;
		std::list<CFG_MOTION_WINDOW*> lsMotionWnd = m_dlgAreaDraw.GetMotionWndList();

		while(lsMotionWnd.size())
		{
			CFG_MOTION_WINDOW* p = lsMotionWnd.front();
			memcpy(&m_pMotionInfo->stuWindows[i], p, sizeof(m_pMotionInfo->stuWindows[i]));
			m_pMotionInfo->nWindowCount = i + 1;
			lsMotionWnd.pop_front();
			i++;
		}
	} 
	else
	{
		for (int i = 0; i < DH_MOTION_ROW; i++)
		{
			for (int j = 0; j < DH_MOTION_COL; j++)
			{
				m_myArea[i][j] = m_block[i][j].IsSeleted()?1:0;
			}
		}
	}
	
	CDialog::OnOK();
}

BOOL CConfigAlarmMotionArea::OnInitDialog() 
{
	CDialog::OnInitDialog();
	g_SetWndStaticText(this);
	// TODO: Add extra initialization here

	if (m_bNewPro)
	{
		m_dlgAreaDraw.InitDlg(m_pMotionInfo);

		m_dlgAreaDraw.Create(CAreaDraw::IDD, this);

		CRect rt;
		GetDlgItem(IDC_AREA_BOARD)->GetWindowRect(&rt);
		ScreenToClient(&rt);
		m_dlgAreaDraw.MoveWindow(&rt);
		m_dlgAreaDraw.ShowWindow(SW_SHOW);

		GetDlgItem(IDC_BUTTON_ADDRECT)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON_DELRECT)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_AREATHRESHOLD)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_SENSITIVITY)->EnableWindow(TRUE);
		SetDlgItemInt(IDC_EDIT_AREATHRESHOLD, -1, TRUE);
		SetDlgItemInt(IDC_EDIT_SENSITIVITY, -1, TRUE);
	}
	else
	{

		CRect m_rect;
		GetDlgItem(IDC_AREA_BOARD)->GetClientRect(&m_rect);
		GetDlgItem(IDC_AREA_BOARD)->ClientToScreen(&m_rect);
		ScreenToClient(&m_rect);
		
	
		int blckWid = 0;
		if(0 != m_wCols)
		{
			blckWid = (m_rect.Width()-m_wCols+1)/m_wCols;
		}

		m_blckWid = blckWid;
	
		int blckHght = 0;
		if(0 != m_wRows)
		{
			blckHght = (m_rect.Height()-m_wRows+1)/m_wRows;
		}
		m_blckHght = blckHght;


		for (int i = 0; i < m_wRows; i++)
		{
			for (int j = 0; j < m_wCols; j++)
			{
				m_block[i][j].Create(
					NULL, 
					NULL, 
					WS_VISIBLE | WS_CHILD,
					CRect(m_rect.left+j*blckWid+j, m_rect.top+i*blckHght+i, m_rect.left+(j+1)*blckWid+j, m_rect.top+(i+1)*blckHght+i),
					this,
					1979,
					NULL);
				m_block[i][j].PostMessage(MSG_SHOW);
				m_block[i][j].SetPos(i,j);
			}
		}

		GetDlgItem(IDC_BUTTON_ADDRECT)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON_DELRECT)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_AREATHRESHOLD)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_SENSITIVITY)->EnableWindow(FALSE);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CConfigAlarmMotionArea::SetArea(BYTE *area, WORD wRows, WORD wCols)
{
	if (!area)
	{
		return;
	}
	memcpy(m_myArea, area, DH_MOTION_COL*DH_MOTION_ROW);
	m_wRows = wRows;
	m_wCols = wCols;
	
	for (int i = 0; i < wRows; i++)
	{
		for (int j = 0; j < wCols; j++)
		{
			m_block[i][j].SetStatus(m_myArea[i][j]);
		}
	}

	m_bNewPro = FALSE;
}

void CConfigAlarmMotionArea::RecordPoint(BYTE x, BYTE y)
{
	m_stpoint.x = x;
	m_stpoint.y = y;
	m_lastpoint.x = x;
	m_lastpoint.y = y;
	m_bDrawing = TRUE;
	
	m_block[x][y].PostMessage(MSG_SELETED);
}

BOOL IsBetween(int lft, int mid, int rht)
{
	if (lft >= rht)
	{
		return (mid >= rht && mid <= lft);
	}
	else
	{
		return (mid >= lft && mid <= rht);
	}
}

void CConfigAlarmMotionArea::ReleasePoint()
{
	m_bDrawing = FALSE;
}

void CConfigAlarmMotionArea::MovePoint(DWORD dwParm, BYTE x, BYTE y)
{
	if (!m_bDrawing || !(dwParm&MK_LBUTTON) || (m_lastpoint.x == x && m_lastpoint.y == y))
	{
		return;
	}
	
	for (int i = 0; i < DH_MOTION_ROW; i++)
	{
		for (int j = 0; j < DH_MOTION_COL; j++)
		{
			if(((IsBetween(m_stpoint.x, i, x) && IsBetween(m_stpoint.y, j, y)) &&
				!(IsBetween(m_stpoint.x, i, m_lastpoint.x) && IsBetween(m_stpoint.y, j, m_lastpoint.y))) ||
				(IsBetween(m_stpoint.x, i, m_lastpoint.x) && IsBetween(m_stpoint.y, j, m_lastpoint.y)) &&
				!((IsBetween(m_stpoint.x, i, x) && IsBetween(m_stpoint.y, j, y))))
			{
				m_block[i][j].PostMessage(MSG_SELETED);
			}
		}
	}
	
	m_lastpoint.x = x;
	m_lastpoint.y = y;
}

void CConfigAlarmMotionArea::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnLButtonDown(nFlags, point);
}

void CConfigAlarmMotionArea::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_bDrawing = FALSE;
	
	CDialog::OnLButtonUp(nFlags, point);
}

HBRUSH CConfigAlarmMotionArea::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}


void CConfigAlarmMotionArea::SetAreaEx(CFG_MOTION_INFO* pMotionInfo)
{
	m_bNewPro = TRUE;

	if (pMotionInfo)
	{
		m_pMotionInfo = pMotionInfo;
	}
}

void CConfigAlarmMotionArea::OnButtonAddrect() 
{
	// TODO: Add your control notification handler code here
	CFG_MOTION_WINDOW stuWnd = {0};
	stuWnd.nThreshold = GetDlgItemInt(IDC_EDIT_AREATHRESHOLD, &stuWnd.nThreshold, FALSE);
	stuWnd.nSensitive = GetDlgItemInt(IDC_EDIT_SENSITIVITY, &stuWnd.nSensitive, FALSE);

	m_dlgAreaDraw.AddWnd(stuWnd);
}

void CConfigAlarmMotionArea::OnButtonDelrect() 
{
	// TODO: Add your control notification handler code here
	m_dlgAreaDraw.DeleteWnd();

	SetDlgItemInt(IDC_EDIT_AREATHRESHOLD, -1, TRUE);
	SetDlgItemInt(IDC_EDIT_SENSITIVITY, -1, TRUE);

	Invalidate(TRUE);
}

void CConfigAlarmMotionArea::ShowParam(const CFG_MOTION_WINDOW& stuMotionWnd)
{
	SetDlgItemInt(IDC_EDIT_AREATHRESHOLD, stuMotionWnd.nThreshold, TRUE);
	SetDlgItemInt(IDC_EDIT_SENSITIVITY, stuMotionWnd.nSensitive, TRUE);
}

void CConfigAlarmMotionArea::OnChangeEditAreathreshold() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	int nAreaThreshold = GetDlgItemInt(IDC_EDIT_AREATHRESHOLD, NULL, TRUE);
	m_dlgAreaDraw.SetAreathreshold(nAreaThreshold);
}

void CConfigAlarmMotionArea::OnChangeEditSensitivity() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	int nSensitivity = GetDlgItemInt(IDC_EDIT_SENSITIVITY, NULL, TRUE);	
	m_dlgAreaDraw.SetSensitivity(nSensitivity);
}
