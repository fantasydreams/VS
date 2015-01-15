#if !defined(AFX_DEVICELISTDLG_H__BC01D2F0_F536_4826_9110_DA08596F3932__INCLUDED_)
#define AFX_DEVICELISTDLG_H__BC01D2F0_F536_4826_9110_DA08596F3932__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeviceListDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeviceListDlg dialog
#include "./control/virtTree.h"
class CDeviceListDlg : public CDialog
{
// Construction
public:
	CDeviceListDlg(CWnd* pParent = NULL);   // standard constructor
	~CDeviceListDlg();

// Dialog Data
	//{{AFX_DATA(CDeviceListDlg)
	enum { IDD = IDD_DLG_DEVICE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeviceListDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDeviceListDlg)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBtnAdd();
	afx_msg void OnBtnDelete();
	virtual BOOL OnInitDialog();
	afx_msg void OnBegindragTreeDevice(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickTreeDevice(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CVirtTree    m_TreeDevices;
	CImageList   m_image;
	DWORD        m_dwDragStart;     // ������������һ�̵�ʱ��
	CImageList*  m_pDragImage;      // �϶�ʱ��ʾ��ͼ���б�
	HTREEITEM    m_hItemDrag;       // �϶������ڵ�
	BOOL         m_bDragging;       // �Ƿ��϶�

	std::map<DWORD,CFG_TAST_SOURCES*> m_mapSources;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEVICELISTDLG_H__BC01D2F0_F536_4826_9110_DA08596F3932__INCLUDED_)
