// TabUserManageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AlarmDevice.h"
#include "TabUserManageDlg.h"
#include "AddUserInfo.h"
#include "ModifyUserInfo.h"
#include "ModifyPwd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabUserManageDlg dialog


CTabUserManageDlg::CTabUserManageDlg(CWnd* pParent /* = NULL */, LLONG nLoginId /* = 0 */, NET_DEVICE_TYPE emDevType /* = NET_PRODUCT_NONE */)
	: CDialog(CTabUserManageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTabUserManageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hLoginID = nLoginId;
	m_emDevType = emDevType;
	m_pstuUsersInfo = new USER_MANAGE_INFO_NEW;
	assert(m_pstuUsersInfo != NULL);
	memset(m_pstuUsersInfo, 0, sizeof(USER_MANAGE_INFO_NEW));
	m_pstuUsersInfo->dwSize = sizeof(USER_MANAGE_INFO_NEW);
	for(int i =0; i < DH_MAX_GROUP_NUM; ++i)
	{
		m_pstuUsersInfo->groupListEx[i].dwSize = sizeof(USER_GROUP_INFO_EX2);
	}
}

CTabUserManageDlg::~CTabUserManageDlg()
{
	delete m_pstuUsersInfo;
	m_pstuUsersInfo = NULL;
}

void CTabUserManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTabUserManageDlg)
	DDX_Control(pDX, IDC_USERMANAGE_TREE_LEVELS, m_treeLevels);
	DDX_Control(pDX, IDC_USERMANAGE_TREE_USERS, m_treeUsers);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CTabUserManageDlg, CDialog)
	//{{AFX_MSG_MAP(CTabUserManageDlg)
	ON_NOTIFY(TVN_SELCHANGED, IDC_USERMANAGE_TREE_USERS, OnSelchangedTreeUsers)
	ON_BN_CLICKED(IDC_USERMANAGE_ADD_USER, OnAddUser)
	ON_BN_CLICKED(IDC_USERMANAGE_MODIFY_USER, OnModifyUser)
	ON_BN_CLICKED(IDC_USERMANAGE_DELETE_USER, OnDeleteUser)
	ON_BN_CLICKED(IDC_USERMANAGE_MODIFY_PSW, OnModifyPsw)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabUserManageDlg message handlers

//To be called by CClientDemo1Dlg. Clear dialogue box information after log off the device. 
void CTabUserManageDlg::CleanUserManageInfo()
{
	//Clear tree 
	m_treeUsers.DeleteAllItems();
	m_treeLevels.DeleteAllItems();
}

//Generate tree 
void CTabUserManageDlg::InitTree()
{
	//Clear tree 
	m_treeUsers.DeleteAllItems();
	m_treeLevels.DeleteAllItems();
	USER_MANAGE_INFO_NEW& stuUserInfo = *m_pstuUsersInfo;

	//User information 
	for(int i = 0; i < (int)stuUserInfo.dwGroupNum; i++)
	{
		HTREEITEM hRoot = NULL;

		{
			//Add user group 
			hRoot = m_treeUsers.InsertItem(stuUserInfo.groupListEx[i].name,TVI_ROOT,TVI_LAST);
			m_treeUsers.SetItemData(hRoot,(DWORD)&(stuUserInfo.groupListEx[i]));
		}

		{
			//Add user 
			for(int j = 0; j < (int)stuUserInfo.dwUserNum; j++)
			{
				if(stuUserInfo.userList[j].dwGroupID == stuUserInfo.groupListEx[i].dwID)
				{
// 					char szNameBuf[20] = {0};
// 					memcpy(szNameBuf, m_usersInfo.userList[j].name, 16);
					HTREEITEM hLeaf = m_treeUsers.InsertItem(stuUserInfo.userList[j].name, hRoot, TVI_LAST);

					// ���û��������±�
					m_treeUsers.SetItemData(hLeaf, (DWORD)j);
				}
			}
		}

		m_treeUsers.Expand(hRoot, TVE_EXPAND);
	}

	//Right information 
	for(int k = 0; k < (int)stuUserInfo.dwRightNum; k++)
	{
		CString str;
		str.Format("%d: %s",stuUserInfo.rightList[k].dwID,stuUserInfo.rightList[k].name);
// 		str.Format("%d: %s : %s",m_usersInfo.rightList[k].dwID,m_usersInfo.rightList[k].name,
// 			m_usersInfo.rightList[k].memo);
		HTREEITEM hRoot = m_treeLevels.InsertItem(str, TVI_ROOT, TVI_LAST);

		// �󶨾���Ȩ�޵�id
		m_treeLevels.SetItemData(hRoot, stuUserInfo.rightList[k].dwID);
	}

	//Select one node
	HTREEITEM hSelItem = m_treeUsers.GetRootItem();
	if(hSelItem != NULL)
	{
		m_treeUsers.SelectItem(hSelItem);
		m_treeUsers.SetFocus();
		//Refresh right list according to the user. 
		RefreshLevelList();
	}
}

BOOL CTabUserManageDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	g_SetWndStaticText(this, DLG_USERMANAGER);
	// TODO: Add extra initialization here
	if (m_hLoginID == 0)
	{
		MessageBox(ConvertString("Please login first!", DLG_USERMANAGER), ConvertString("Prompt"));
	}

	BOOL bRet = CLIENT_QueryUserInfoNew(m_hLoginID, m_pstuUsersInfo, NULL, 1000 * 10);
	if (!bRet)
	{
		MessageBox(ConvertString("Get user info failed!", DLG_USERMANAGER), ConvertString("Prompt"));
	}
	else
	{
		//Create a tree 
		InitTree();
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTabUserManageDlg::OnSelchangedTreeUsers(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	//Update right list 
	RefreshLevelList();

	*pResult = 0;
}

void CTabUserManageDlg::RefreshLevelList()
{
	DWORD dwNum			= 0;
	DWORD *dwList		= NULL;
	USER_MANAGE_INFO_NEW& stuUserInfo = *m_pstuUsersInfo;

	HTREEITEM hSelItem	= m_treeUsers.GetSelectedItem();
	if(hSelItem != NULL)
	{
		// ����û�����������±�
		DWORD dwTagData = m_treeUsers.GetItemData(hSelItem);
		if(dwTagData < DH_MAX_USER_NUM)		//User
		{
			// ����û���Ȩ����Ŀ��Ȩ���б�
			dwNum	= stuUserInfo.userList[dwTagData].dwRightNum;
			dwList	= stuUserInfo.userList[dwTagData].rights;
		}
		else	//Group
		{
			USER_GROUP_INFO_EX2 *gpInfo = (USER_GROUP_INFO_EX2 *)dwTagData;
			dwNum						= gpInfo->dwRightNum;
			dwList						= gpInfo->rights;
		}
	}

	//Update right list 
	int nCountItem	= m_treeLevels.GetCount();
	HTREEITEM hItem = m_treeLevels.GetRootItem();
	int i			= 0;
	for(i = 0; i < nCountItem; i++)
	{
		m_treeLevels.SetCheck(hItem,FALSE);
		hItem = m_treeLevels.GetNextItem(hItem,TVGN_NEXT);
	}
	
	for(i = 0; i < (int)dwNum; i++)
	{
		hItem = m_treeLevels.GetRootItem();
		for(int j = 0; j < nCountItem && hItem; j++)
		{
			DWORD dwData = m_treeLevels.GetItemData(hItem);
			if(dwData == dwList[i])
			{
				m_treeLevels.SetCheck(hItem,TRUE);
				break;
			}

			hItem = m_treeLevels.GetNextItem(hItem,TVGN_NEXT);
		}
	}
}

//Add user 
void CTabUserManageDlg::OnAddUser() 
{
	// TODO: Add your control notification handler code here
	if(0 < m_hLoginID)
	{
		HTREEITEM hSelItem = m_treeUsers.GetSelectedItem();
		if(hSelItem != NULL)
		{
			DWORD dwData = m_treeUsers.GetItemData(hSelItem);
			if(dwData < DH_MAX_USER_NUM)
			{
				hSelItem = m_treeUsers.GetParentItem(hSelItem);
			}
			if(hSelItem != NULL)
			{
				dwData = m_treeUsers.GetItemData(hSelItem);
				USER_GROUP_INFO_EX2 *gpInfo = (USER_GROUP_INFO_EX2 *)dwData;
				CAddUserInfo dlg;
				dlg.InitAddUserInfoDlg(m_pstuUsersInfo, gpInfo->dwID, m_hLoginID);
				int nResponse = dlg.DoModal();
				if (nResponse == IDOK)
				{
					//To get user information 
					BOOL bRet = CLIENT_QueryUserInfoNew(m_hLoginID, m_pstuUsersInfo, NULL, 10000);
					if (!bRet)
					{
						MessageBox(ConvertString("Get user info failed!", DLG_USERMANAGER), ConvertString("Prompt"));
					}
					else
					{
						//Generate tree again
						InitTree();
					}
				}
			}
		}
		else
		{
			MessageBox(ConvertString("Please select group!", DLG_USERMANAGER), ConvertString("Prompt"));
		}
	}
	else
	{
		MessageBox(ConvertString("Please login first!", DLG_USERMANAGER), ConvertString("Prompt"));
	}
}

//Modify user 
void CTabUserManageDlg::OnModifyUser() 
{
	// TODO: Add your control notification handler code here
	if(0 < m_hLoginID)
	{
		HTREEITEM hSelItem = m_treeUsers.GetSelectedItem();
		if(hSelItem != NULL)
		{
			DWORD dwData = m_treeUsers.GetItemData(hSelItem);
			if(dwData < DH_MAX_USER_NUM)
			{
				CModifyUserInfo dlg;
				dlg.InitModifyUserInfoDlg(m_pstuUsersInfo,dwData,m_hLoginID);
				int nResponse = dlg.DoModal();
				if (nResponse == IDOK)
				{
					//Get user information 
					BOOL bRet = CLIENT_QueryUserInfoNew(m_hLoginID, m_pstuUsersInfo, NULL, 10000);
					if (!bRet)
					{
						MessageBox(ConvertString("Get user info failed!", DLG_USERMANAGER), ConvertString("Prompt"));
					}
					else
					{
						//Generate tree again 
						InitTree();
					}
				}
			}
			else
			{
				MessageBox(ConvertString("You selected group, please select user!", DLG_USERMANAGER), ConvertString("Prompt"));
			}
		}
		else
		{
			MessageBox(ConvertString("please select user!", DLG_USERMANAGER), ConvertString("Prompt"));
		}
	}
	else
	{
		MessageBox(ConvertString("Please login first!", DLG_USERMANAGER), ConvertString("Prompt"));
	}
}

//Delete tree 
void CTabUserManageDlg::OnDeleteUser() 
{
	// TODO: Add your control notification handler code here
	if(0 < m_hLoginID)
	{
		HTREEITEM hSelItem = m_treeUsers.GetSelectedItem();
		if(hSelItem != NULL)
		{
			DWORD dwData = m_treeUsers.GetItemData(hSelItem);
			if(dwData < DH_MAX_USER_NUM)
			{
				BOOL bRet = CLIENT_OperateUserInfoNew(m_hLoginID, 4, (void *)&m_pstuUsersInfo->userList[dwData], 0, 0, 10000);
				if (bRet)
				{
					//Get user information 
					BOOL bRet = CLIENT_QueryUserInfoNew(m_hLoginID, m_pstuUsersInfo, NULL, 10000);
					if (!bRet)
					{
						MessageBox(ConvertString("Get user info failed!", DLG_USERMANAGER), ConvertString("Prompt"));
					}
					else
					{
						//Generate tree again 
						InitTree();
					}
				}
				else
				{
					int nError = CLIENT_GetLastError();
					if(nError == NET_RETURN_DATA_ERROR)
					{
						MessageBox(ConvertString("checkout return data error!", DLG_USERMANAGER), ConvertString("Prompt"));
					}
					else if(nError == NET_ILLEGAL_PARAM) 
					{
						MessageBox(ConvertString("Input error!", DLG_USERMANAGER), ConvertString("Prompt"));
					}
					else if(nError == NET_USER_NOEXIST) 
					{
						MessageBox(ConvertString("the user is not existing!", DLG_USERMANAGER), ConvertString("Prompt"));
					}
					else 
					{
						MessageBox(ConvertString("remove user failed!", DLG_USERMANAGER), ConvertString("Prompt"));
					}
				}
			}
			else
			{
				MessageBox(ConvertString("You selected group, please select user!", DLG_USERMANAGER), ConvertString("Prompt"));
			}
		}
		else
		{
			MessageBox(ConvertString("please select user!", DLG_USERMANAGER), ConvertString("Prompt"));
		}
	}
	else
	{
		MessageBox(ConvertString("Please login first!", DLG_USERMANAGER), ConvertString("Prompt"));
	}
}

//Modify password 
void CTabUserManageDlg::OnModifyPsw() 
{
	// TODO: Add your control notification handler code here
	if(0 < m_hLoginID)
	{
		HTREEITEM hSelItem = m_treeUsers.GetSelectedItem();
		if(hSelItem != NULL)
		{
			DWORD dwData = m_treeUsers.GetItemData(hSelItem);
			if(dwData < DH_MAX_USER_NUM)
			{
				CModifyPwd dlg;
				dlg.InitModifyPwdInfoDlg(m_pstuUsersInfo,dwData,m_hLoginID);
				int nResponse = dlg.DoModal();
				if (nResponse == IDOK)
				{
					//Get user information 
					BOOL bRet = CLIENT_QueryUserInfoNew(m_hLoginID, m_pstuUsersInfo, NULL, 10000);
					if (!bRet)
					{
						MessageBox(ConvertString("Get user info failed!", DLG_USERMANAGER), ConvertString("Prompt"));
					}
					else
					{
						//Generate tree again 
						InitTree();
					}
				}
			}
			else
			{
				MessageBox(ConvertString("You selected group, please select user!", DLG_USERMANAGER), ConvertString("Prompt"));
			}
		}
		else
		{
			MessageBox(ConvertString("please select user!", DLG_USERMANAGER), ConvertString("Prompt"));
		}
	}
	else
	{
		MessageBox(ConvertString("Please login first!", DLG_USERMANAGER), ConvertString("Prompt"));
	}
}

