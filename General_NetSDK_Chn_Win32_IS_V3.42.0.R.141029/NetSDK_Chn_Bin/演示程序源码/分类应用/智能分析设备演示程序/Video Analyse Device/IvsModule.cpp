#include "StdAfx.h"
#include "IvsModule.h"

#include <math.h>

CRITICAL_SECTION CIvsModule::m_cs;
std::map<int,IvsDecodeInfo> CIvsModule::m_decode_info_map;		// ����˿ں� ==> ������Ϣ
std::list<IvsChnlInfo>	CIvsModule::m_chnl_info_list;			// ͨ����Ϣ��

HANDLE CIvsModule::m_hIvsHeap = 0;
 
BOOL CIvsModule::Init()
{
	InitializeCriticalSection(&m_cs);

	m_hIvsHeap = HeapCreate(0,1 * 1024 * 1024,0);
	if (m_hIvsHeap)
	{
		return TRUE;
	}
	else
		return FALSE;
}

BOOL CIvsModule::UnInit()
{
	DeleteCriticalSection(&m_cs);

	if (NULL != m_hIvsHeap)
	{
		HeapDestroy(m_hIvsHeap);
	}
	return 0;
}

void* CIvsModule::AllocateMemory(UINT nSize)
{
	return HeapAlloc(m_hIvsHeap,0,nSize);
}

void CIvsModule::FreeMemory(void* pMem)
{
	HeapFree(m_hIvsHeap,0,pMem);
}

//************************************
// ����:	public static CIvsLogic::OnOpenDeviceRealplay
// ժҪ:	���豸ͨ����Ƶʱ,��¼�����ܷ���������Ϣ�ͽ�����Ϣ
// ����:
//		int
// ����:
//		LONG lDevHandle			�豸���
//		LONG lDevId				�豸ID
//		int nChnlIdx			ͨ�����
//		int nDecoderPort		����˿ں�
//		HWND hwnd				��Ƶ��ʾ����
//************************************
int CIvsModule::OnOpenDeviceRealplay(LONG lDevHandle,int nChnlIdx,
									int nDecoderPort,HWND hwnd,int nChnlCnt)
{
	int nRetVal = -1;
	
	ReloadIvsRuleReq* pReq = (ReloadIvsRuleReq*)AllocateMemory(sizeof(ReloadIvsRuleReq));
	
	if (NULL != pReq)
	{
		pReq->devHandle	= lDevHandle;
		pReq->nChnlIdx	= nChnlIdx;
		pReq->bReloadCfg= false;
		pReq->bAddNew	= true;
		pReq->nDecPort	= nDecoderPort;
		pReq->hVideoWnd	= hwnd;
		pReq->nChnlCnt = nChnlCnt;
		
		ReloadIvsRuleProc(pReq);
		
		FreeMemory(pReq);
	}
	
	return nRetVal;
}
// ���¶�ȡͨ�������ܷ�������
void CIvsModule::ReloadIvsRuleProc(ReloadIvsRuleReq* pReq)
{
	
	DEV_INFO devInfo;
	memset((void*)&devInfo,0x0,sizeof(devInfo));
	
	devInfo.m_ChannelCount = pReq->nChnlCnt;
	devInfo.m_LoginHandle = pReq->devHandle;
	int iRet = GetDeviceIvsConfig(devInfo);
	if (iRet == -1)
	{
		AfxMessageBox("��ȡIVS��������ʧ��!");
		return;
	}
	
	if (0 != pReq->devHandle)
	{
		ReloadChannelIvsRule(pReq->devHandle,devInfo,pReq->nChnlIdx,pReq->bAddNew,pReq->nDecPort);
		
		if (pReq->nDecPort >= 0)
		{
			IvsDecodeInfo decode_info;
			
			decode_info.dev_id		= pReq->devHandle;
			decode_info.chnl_idx	= pReq->nChnlIdx;
			decode_info.decoder_id	= pReq->nDecPort;
			decode_info.hwnd		= pReq->hVideoWnd;
			
			decode_info.bShowRule	= true;
			decode_info.bShowObj	= true;
			decode_info.bShowLocus	= true;
			
			m_decode_info_map.insert(std::make_pair(pReq->nDecPort,decode_info));
		}
	}
}

// ��ȡ�豸���ܷ�������
int CIvsModule::GetDeviceIvsConfig(DEV_INFO& devInfo)
{
	if (NULL == devInfo.m_LoginHandle)
	{
		return -1;
	}
	
	CFG_CAP_ANALYSE_INFO *pchnl_cap = new CFG_CAP_ANALYSE_INFO;
	char szOutBuffer[32*1024] = {0};
	int nError = 0;
	
	// ͨ�����ܷ�������
	for(int i = 0 ; i < devInfo.m_ChannelCount; ++i)
	{
		ZeroMemory(pchnl_cap,sizeof(*pchnl_cap));
		
		BOOL bSuccess = CLIENT_QueryNewSystemInfo(devInfo.m_LoginHandle,
			CFG_CAP_CMD_VIDEOANALYSE,i,
			szOutBuffer,sizeof(szOutBuffer),&nError);
		
		if (bSuccess)
		{
			int nRetLen = 0;
			
			BOOL bRet = CLIENT_ParseData(CFG_CAP_CMD_VIDEOANALYSE,szOutBuffer,
				(char*)pchnl_cap,sizeof(CFG_CAP_ANALYSE_INFO),
				&nRetLen);
			
			if (bRet && (pchnl_cap->nSupportedRulesNum > 0) && (pchnl_cap->nMaxRules > 0))
			{
				devInfo.m_Channel[i].m_bSupportIvs = TRUE;
				devInfo.m_Channel[i].m_bEnableIvs  = TRUE;
				devInfo.m_Channel[i].m_bAtmIvs = FALSE;
				
				int nMaxRuleStructSize = GetRulesMaxStructSize(pchnl_cap->dwRulesType, pchnl_cap->nSupportedRulesNum);
				devInfo.m_Channel[i].m_nMaxRuleStructSize = nMaxRuleStructSize;
				devInfo.m_Channel[i].m_nMaxRuleNum = pchnl_cap->nMaxRules;
			}
		}
	}
	
	delete pchnl_cap;
	pchnl_cap = NULL;
	return 0;
}

int CIvsModule::GetRulesMaxStructSize(DWORD *pRulesTypes, int nRuleNum)
{
	int nMaxSize = 0;
	int nSize = 0;
	for (int i = 0; i < nRuleNum; i++)
	{
		if (EVENT_IVS_CROSSLINEDETECTION == pRulesTypes[i])  //������
		{
			nSize = sizeof(CFG_CROSSLINE_INFO);
		}
		else if (EVENT_IVS_CROSSREGIONDETECTION == pRulesTypes[i])  //������
		{
			nSize = sizeof(CFG_CROSSREGION_INFO);
		}
		else if (EVENT_IVS_PASTEDETECTION == pRulesTypes[i])  //ATM����
		{
			nSize = sizeof(CFG_PASTE_INFO);
		}
		else if (EVENT_IVS_LEFTDETECTION == pRulesTypes[i])  //��������
		{
			nSize = sizeof(CFG_LEFT_INFO);
		}
		else if (EVENT_IVS_STAYDETECTION == pRulesTypes[i])  // ͣ���¼�
		{
			nSize = sizeof(CFG_STAY_INFO);
		}
		else if (EVENT_IVS_WANDERDETECTION == pRulesTypes[i]) //�ǻ�
		{
			nSize = sizeof(CFG_WANDER_INFO);
		}
		else if (EVENT_IVS_PRESERVATION == pRulesTypes[i]) // ��Ʒ��ȫ�¼�
		{
			nSize = sizeof(CFG_PRESERVATION_INFO);
		}
		else if (EVENT_IVS_MOVEDETECTION == pRulesTypes[i]) // �ƶ��¼�
		{
			nSize = sizeof(CFG_MOVE_INFO);
		}
		else if (EVENT_IVS_TAILDETECTION == pRulesTypes[i]) //β�� ��δʵ�֣�
		{
			nSize = sizeof(CFG_TAIL_INFO);
		}
		else if (EVENT_IVS_RIOTERDETECTION == pRulesTypes[i])  //�ۼ�
		{
			nSize = sizeof(CFG_RIOTER_INFO);
		}
		else if (EVENT_IVS_FIREDETECTION == pRulesTypes[i]) // ���¼���δʵ�֣�
		{
			nSize = sizeof(CFG_FIRE_INFO);
		}
		else if (EVENT_IVS_SMOKEDETECTION == pRulesTypes[i]) // �������¼���δʵ�֣�
		{
			nSize = sizeof(CFG_SMOKE_INFO);
		}
		else if (EVENT_IVS_FIGHTDETECTION == pRulesTypes[i]) // ��Ź�¼���δʵ�֣�
		{
			nSize = sizeof(CFG_FIGHT_INFO);
		}
		else if (EVENT_IVS_FLOWSTAT == pRulesTypes[i]) // ����ͳ���¼�
		{
			nSize = sizeof(CFG_FLOWSTAT_INFO);
		}
		else if (EVENT_IVS_NUMBERSTAT == pRulesTypes[i])	// ����ͳ���¼�
		{
			nSize = sizeof(CFG_NUMBERSTAT_INFO);
		}
		else if (EVENT_IVS_TRAFFICCONTROL == pRulesTypes[i]) 
		{
			nSize = sizeof(CFG_TRAFFICCONTROL_INFO);
		}
		else if (EVENT_IVS_TRAFFICACCIDENT == pRulesTypes[i])
		{
			nSize = sizeof(CFG_TRAACCIDENT_INFO);
		}
		else if (EVENT_IVS_TRAFFICJUNCTION == pRulesTypes[i])
		{
			nSize = sizeof(CFG_TRAJUNCTION_INFO);
		}
		else if (EVENT_IVS_TRAFFICGATE == pRulesTypes[i])
		{
			nSize = sizeof(CFG_TRAFFICGATE_INFO);
		}
		else if (EVENT_IVS_FACEDETECT == pRulesTypes[i])	//�������
		{
			nSize = sizeof(CFG_FACEDETECT_INFO);
		}
		else if (EVENT_IVS_ELECTROSPARKDETECTION == pRulesTypes[i]) // ����¼� 
		{
			nSize = sizeof(DEV_EVENT_ELECTROSPARK_INFO);   
		}
		else if (EVENT_IVS_TRAFFIC_PEDESTRAINPRIORITY == pRulesTypes[i]) // ��ͨ-��������������
		{
			nSize = sizeof(DEV_EVENT_TRAFFIC_PEDESTRAINPRIORITY_INFO);   
		}
		
		if (nSize > nMaxSize)
		{
			nMaxSize = nSize;
		}
	}
	
	return nMaxSize;
}

//************************************
// ����:	protected CIvsLogic::ReloadChannelIvsRule
// ժҪ:	  ���¶�ȡ�豸ͨ�����ܷ�������
// ����:
//		int		0: �ɹ�		-1: ʧ��
// ����:
//		LONG lDevHandle		�豸���
//		LONG lDevId			�豸ID
//		int nChnlIdx		ͨ�����
//		bool bAddNew		�����û�����ͨ����¼,�Ƿ�����µļ�¼(true: ����/���¼�¼   false: �����¼�¼)
//************************************
int CIvsModule::ReloadChannelIvsRule(LONG lDevHandle,DEV_INFO &devInfo,int nChnlIdx,
									bool bAddNew /* = true */,
									int  nDecPort/*= -1 */)
{
	// ��֧�����ܷ�������
	if (!devInfo.m_Channel[nChnlIdx].m_bSupportIvs)
	{
		return -1;
	}

	/*============================================
		ȡ�豸���ܷ�������
	=============================================*/
 	CFG_ANALYSERULES_INFO cfg_rule = {0};
 	IvsRule* pivs_rule = new IvsRule;
	if (pivs_rule == NULL)
	{
		return -1;
	}

 	char szBuffer[64 * 1024] = {0};
 	int  nError;
 	BOOL bSuccess;

	bSuccess = CLIENT_GetNewDevConfig(lDevHandle,CFG_CMD_ANALYSERULE,
									nChnlIdx,szBuffer,sizeof(szBuffer),&nError,3000);

	if (bSuccess)
	{
		int nMaxRuleStructSize = devInfo.m_Channel[nChnlIdx].m_nMaxRuleStructSize;
		int nMaxRuleNum = devInfo.m_Channel[nChnlIdx].m_nMaxRuleNum;
		int nBufLen = (sizeof(CFG_RULE_INFO) + nMaxRuleStructSize) * nMaxRuleNum;
		cfg_rule.pRuleBuf = new char[nBufLen];
		cfg_rule.nRuleLen = nBufLen;
		bSuccess = CLIENT_ParseData(CFG_CMD_ANALYSERULE,szBuffer,
									(char*)&cfg_rule,sizeof(cfg_rule),&nError);
	}
	DWORD dwErr = CLIENT_GetLastError();

	if (!bSuccess)
	{
		return -1;
	}

	/*============================================
		����������򵽹�����Ϣ����
	=============================================*/
	IvsChnlInfo* pIvsChnl;
	IvsChnlInfo chnl_info;
	int nRuleIdx;

	chnl_info.dev_id = lDevHandle;
	chnl_info.chnl_idx = nChnlIdx;
 	chnl_info.bEnableIvs = (0 != devInfo.m_Channel[nChnlIdx].m_bEnableIvs);
 	chnl_info.bAtm = devInfo.m_Channel[nChnlIdx].m_bAtmIvs;
	chnl_info.bPreset = 0;
	chnl_info.live_dec_id = nDecPort;

	pIvsChnl = &chnl_info;

	int nLenIndex = 0;
	for(nRuleIdx = 0; nRuleIdx < cfg_rule.nRuleCount && nLenIndex < cfg_rule.nRuleLen; ++nRuleIdx)
	{
		IvsRuleInfo rule = {0};
		CopyMemory(&rule.stuRuleInfo, cfg_rule.pRuleBuf + nLenIndex, sizeof(CFG_RULE_INFO));
		nLenIndex += sizeof(CFG_RULE_INFO);

		switch(rule.stuRuleInfo.dwRuleType)
		{
			//������
			case EVENT_IVS_CROSSLINEDETECTION:
			{
				if (rule.stuRuleInfo.nRuleSize == sizeof(CFG_CROSSLINE_INFO))
				{
					CopyMemory(&rule.ruleEvent.stuCrossLineCfg, cfg_rule.pRuleBuf + nLenIndex, sizeof(CFG_CROSSLINE_INFO));
					nLenIndex += sizeof(CFG_CROSSLINE_INFO);
					rule.bRuleEnable = rule.ruleEvent.stuCrossLineCfg.bRuleEnable;
					strncpy(rule.szRuleName, rule.ruleEvent.stuCrossLineCfg.szRuleName, MAX_NAME_LEN);
				}
				break;
			}
			//������
			case EVENT_IVS_CROSSREGIONDETECTION:
			{
				if (rule.stuRuleInfo.nRuleSize == sizeof(CFG_CROSSREGION_INFO))
				{
					CopyMemory(&rule.ruleEvent.stuCrossRegionCfg, cfg_rule.pRuleBuf + nLenIndex, sizeof(CFG_CROSSREGION_INFO));
					nLenIndex += sizeof(CFG_CROSSREGION_INFO);
					rule.bRuleEnable = rule.ruleEvent.stuCrossRegionCfg.bRuleEnable;
					strncpy(rule.szRuleName, rule.ruleEvent.stuCrossRegionCfg.szRuleName, MAX_NAME_LEN);
				}
				break;
			}
			//ATM����
			case EVENT_IVS_PASTEDETECTION:
			{
				if (rule.stuRuleInfo.nRuleSize == sizeof(CFG_PASTE_INFO))
				{
					CopyMemory(&rule.ruleEvent.stuPasteCfg, cfg_rule.pRuleBuf + nLenIndex, sizeof(CFG_PASTE_INFO));
					nLenIndex += sizeof(CFG_PASTE_INFO);
					rule.bRuleEnable = rule.ruleEvent.stuPasteCfg.bRuleEnable;
					strncpy(rule.szRuleName, rule.ruleEvent.stuPasteCfg.szRuleName, MAX_NAME_LEN);
				}
				break;
			}
			//��Ʒ����
			case EVENT_IVS_LEFTDETECTION:
			{
				if (rule.stuRuleInfo.nRuleSize == sizeof(CFG_LEFT_INFO))
				{
					CopyMemory(&rule.ruleEvent.stuLetfCfg, cfg_rule.pRuleBuf + nLenIndex, sizeof(CFG_LEFT_INFO));
					nLenIndex += sizeof(CFG_LEFT_INFO);
					rule.bRuleEnable = rule.ruleEvent.stuLetfCfg.bRuleEnable;
					strncpy(rule.szRuleName, rule.ruleEvent.stuLetfCfg.szRuleName, MAX_NAME_LEN);
				}
				break;
			}
			//�������
			case EVENT_IVS_FACEDETECT:
			{
				if (rule.stuRuleInfo.nRuleSize == sizeof(CFG_FACEDETECT_INFO))
				{
					CopyMemory(&rule.ruleEvent.stuFaceDetectCfg, cfg_rule.pRuleBuf + nLenIndex, sizeof(CFG_FACEDETECT_INFO));
					nLenIndex += sizeof(CFG_FACEDETECT_INFO);
					rule.bRuleEnable = rule.ruleEvent.stuFaceDetectCfg.bRuleEnable;
					strncpy(rule.szRuleName, rule.ruleEvent.stuFaceDetectCfg.szRuleName, MAX_NAME_LEN);
				}
				break;
			}
			//�ǻ�
			case EVENT_IVS_WANDERDETECTION:
			{
				if (rule.stuRuleInfo.nRuleSize == sizeof(CFG_WANDER_INFO))
				{
					CopyMemory(&rule.ruleEvent.stuWanderCfg, cfg_rule.pRuleBuf + nLenIndex, sizeof(CFG_WANDER_INFO));
					nLenIndex += sizeof(CFG_WANDER_INFO);
					rule.bRuleEnable = rule.ruleEvent.stuWanderCfg.bRuleEnable;
					strncpy(rule.szRuleName, rule.ruleEvent.stuWanderCfg.szRuleName, MAX_NAME_LEN);
				}
				break;
			}
			//�ۼ�
			case EVENT_IVS_RIOTERDETECTION:
			{
				if (rule.stuRuleInfo.nRuleSize == sizeof(CFG_RIOTER_INFO))
				{
					CopyMemory(&rule.ruleEvent.stuRioterCfg, cfg_rule.pRuleBuf + nLenIndex, sizeof(CFG_RIOTER_INFO));
					nLenIndex += sizeof(CFG_RIOTER_INFO);
					rule.bRuleEnable = rule.ruleEvent.stuRioterCfg.bRuleEnable;
					strncpy(rule.szRuleName, rule.ruleEvent.stuRioterCfg.szRuleName, MAX_NAME_LEN);
				}
				break;
			}
			case EVENT_IVS_STAYDETECTION:// ͣ���¼�
			{
				if (rule.stuRuleInfo.nRuleSize == sizeof(CFG_STAY_INFO))
				{
					CopyMemory(&rule.ruleEvent.stuStayCfg, cfg_rule.pRuleBuf + nLenIndex, sizeof(CFG_STAY_INFO));
					nLenIndex += sizeof(CFG_STAY_INFO);
					rule.bRuleEnable = rule.ruleEvent.stuStayCfg.bRuleEnable;
					strncpy(rule.szRuleName, rule.ruleEvent.stuStayCfg.szRuleName, MAX_NAME_LEN);
				}
			}
			break;
			case EVENT_IVS_PRESERVATION:// ��Ʒ��ȫ�¼�
			{
				if (rule.stuRuleInfo.nRuleSize == sizeof(CFG_PRESERVATION_INFO))
				{
					CopyMemory(&rule.ruleEvent.stuPreseRvationCfg, cfg_rule.pRuleBuf + nLenIndex, sizeof(CFG_PRESERVATION_INFO));
					nLenIndex += sizeof(CFG_PRESERVATION_INFO);
					rule.bRuleEnable = rule.ruleEvent.stuPreseRvationCfg.bRuleEnable;
					strncpy(rule.szRuleName, rule.ruleEvent.stuPreseRvationCfg.szRuleName, MAX_NAME_LEN);
				}
			}
			break;
			case EVENT_IVS_MOVEDETECTION:// �ƶ��¼�
			{
				if (rule.stuRuleInfo.nRuleSize == sizeof(CFG_MOVE_INFO))
				{
					CopyMemory(&rule.ruleEvent.stuMoveCfg, cfg_rule.pRuleBuf + nLenIndex, sizeof(CFG_MOVE_INFO));
					nLenIndex += sizeof(CFG_MOVE_INFO);
					rule.bRuleEnable = rule.ruleEvent.stuMoveCfg.bRuleEnable;
					strncpy(rule.szRuleName, rule.ruleEvent.stuMoveCfg.szRuleName, MAX_NAME_LEN);
				}
			}
			break;	
		}


		if (rule.bRuleEnable)
		{
			pivs_rule->rule_id = nRuleIdx;
			pivs_rule->trigger_cnt = 0;
			CopyMemory(&pivs_rule->ruleInfo,&rule,sizeof(rule));

			pIvsChnl->rule_map.insert(std::make_pair(nRuleIdx,pivs_rule));
		}
	}
	delete[] cfg_rule.pRuleBuf;

	/*============================================
		�����豸ͨ����Ϣ,�����ڴ��е��豸ͨ��(����)��Ϣ��
	=============================================*/
	std::list<IvsChnlInfo>::iterator	itor;
	bool bFound = false;

	itor = m_chnl_info_list.begin();

	for(; itor != m_chnl_info_list.end(); itor++)
	{
		if ((itor->dev_id == devInfo.m_ID) && (itor->chnl_idx == nChnlIdx))
		{
			bFound = true;
			break;
		}
	}

	if (bFound)
	{
		int nOldDecPort = itor->live_dec_id;

		*itor = *pIvsChnl;

		if (nOldDecPort >= 0)
		{
			itor->live_dec_id = nOldDecPort;
		}
		else if (nDecPort >= 0)
		{
			itor->live_dec_id = nDecPort;
		}

		return 0;
	}
	else if (bAddNew)
	{
		m_chnl_info_list.push_back(chnl_info);
		return 0;
	}
	else
	{
		return -1;
	}
}


//************************************
// ����:	protected static CIvsLogic::DrawIvsRuleProc
// ժҪ:	  ����Ƶ�����ϻ������ܷ�������
// ����:
//		int
// ����:
//		IvsChnlInfo * pChnlInfo		����ͨ����Ϣ
//		HDC hdc						�豸����
//************************************
int CIvsModule::DrawIvsRuleProc(IvsChnlInfo* pChnlInfo,HDC hdc)
{
	const int nLineWidth = 2;
	IvsRuleMap::iterator itor_rule;
	IvsRule* pIvsRule;

	itor_rule = pChnlInfo->rule_map.begin();

	for(; itor_rule != pChnlInfo->rule_map.end(); ++itor_rule)
	{
		pIvsRule = itor_rule->second;

		if (pIvsRule->ruleInfo.bRuleEnable)
		{
			if (pIvsRule->trigger_cnt > 0)
			{
				--pIvsRule->trigger_cnt;

				if (0 == pIvsRule->trigger_cnt % 5)
				{
					continue;
				}
				else
				{
					SetDCPenColor(hdc,Color_RuleAlarm);
					SetTextColor(hdc,Color_RuleAlarm);
				}
			}
			else
			{
				SetDCPenColor(hdc,Color_RuleNormal);
				SetTextColor(hdc,Color_RuleNormal);
			}

			DrawIvsRule(pIvsRule,hdc);
		}
	}

	return 0;
}

//************************************
// ����:	protected static CIvsLogic::DrawIvsRule
// ժҪ:	  �������ܷ�������
// ����:
// ����:
//		IvsRule * pIvsRule		������Ϣ
//		HDC hdc					�豸����
//************************************
void CIvsModule::DrawIvsRule(IvsRule* pIvsRule,HDC hdc)
{
	IvsRuleInfo& rule = pIvsRule->ruleInfo;
	int nRuleType = pIvsRule->ruleInfo.stuRuleInfo.dwRuleType;

	CFG_POLYLINE* pRulePoint = NULL;
	int nPtCnt =0 ,nPtIdx;

	CFG_POLYLINE* pRulePoint2 = NULL;  //Χ����Ҫʹ��
	int nPtCnt2 =0 ;

	bool bRuleEnable = false;
	switch(nRuleType)
	{
		// ������
	case EVENT_IVS_CROSSLINEDETECTION:
		nPtCnt = rule.ruleEvent.stuCrossLineCfg.nDetectLinePoint;
		pRulePoint = rule.ruleEvent.stuCrossLineCfg.stuDetectLine;
		break;

		// ������
	case EVENT_IVS_CROSSREGIONDETECTION:
		nPtCnt = rule.ruleEvent.stuCrossRegionCfg.nDetectRegionPoint;
		pRulePoint = (CFG_POLYLINE*)(rule.ruleEvent.stuCrossRegionCfg.stuDetectRegion);
		break;

		// ATM����
	case EVENT_IVS_PASTEDETECTION:
		nPtCnt = rule.ruleEvent.stuPasteCfg.nDetectRegionPoint;
		pRulePoint = (CFG_POLYLINE*)(rule.ruleEvent.stuPasteCfg.stuDetectRegion);
		break;

		//��Ʒ����
	case EVENT_IVS_LEFTDETECTION:
		nPtCnt = rule.ruleEvent.stuLetfCfg.nDetectRegionPoint;
		pRulePoint = (CFG_POLYLINE*)(rule.ruleEvent.stuLetfCfg.stuDetectRegion);
		break;

		//�������
	case EVENT_IVS_FACEDETECT:
		nPtCnt = rule.ruleEvent.stuFaceDetectCfg.nDetectRegionPoint;
		pRulePoint = (CFG_POLYLINE*)(rule.ruleEvent.stuFaceDetectCfg.stuDetectRegion);
		break;

		//�ǻ�
	case EVENT_IVS_WANDERDETECTION:
		nPtCnt = rule.ruleEvent.stuWanderCfg.nDetectRegionPoint;
		pRulePoint = (CFG_POLYLINE*)(rule.ruleEvent.stuWanderCfg.stuDetectRegion);
		break;

		//�ۼ�
	case EVENT_IVS_RIOTERDETECTION:
		nPtCnt = rule.ruleEvent.stuRioterCfg.nDetectRegionPoint;
		pRulePoint = (CFG_POLYLINE*)(rule.ruleEvent.stuRioterCfg.stuDetectRegion);
		break;
	case EVENT_IVS_STAYDETECTION:
		nPtCnt = rule.ruleEvent.stuStayCfg.nDetectRegionPoint;
		pRulePoint = (CFG_POLYLINE*)(rule.ruleEvent.stuStayCfg.stuDetectRegion);
		break;
	case EVENT_IVS_PRESERVATION:// ��Ʒ��ȫ�¼�
		nPtCnt = rule.ruleEvent.stuPreseRvationCfg.nDetectRegionPoint;
		pRulePoint = (CFG_POLYLINE*)(rule.ruleEvent.stuPreseRvationCfg.stuDetectRegion);
		break;
	case EVENT_IVS_MOVEDETECTION:// �ƶ��¼�
		nPtCnt = rule.ruleEvent.stuMoveCfg.nDetectRegionPoint;
		pRulePoint = (CFG_POLYLINE*)(rule.ruleEvent.stuMoveCfg.stuDetectRegion);
		break;
	case EVENT_IVS_VIDEOABNORMALDETECTION:// ��Ƶ�쳣�¼�
		nPtCnt = 0;
		pRulePoint = NULL;
		break;
	}

	if ((NULL == pRulePoint) || (nPtCnt <= 1))
	{
		return;
	}

	/*============================================
		���Ӷ������ĸ�����
	=============================================*/

	MoveToEx(hdc,pRulePoint[0].nX,pRulePoint[0].nY,NULL);

	for(nPtIdx = 1; nPtIdx < nPtCnt; ++nPtIdx)
	{
		LineTo(hdc,pRulePoint[nPtIdx].nX,pRulePoint[nPtIdx].nY);
	}

	switch(nRuleType)
	{
	case EVENT_IVS_CROSSLINEDETECTION://������: ���Ʒ����ʶ
		{
			if(nPtCnt >= 2 && pRulePoint != NULL)
			{
				POINT ptStart,ptEnd;

				int nDirection = rule.ruleEvent.stuCrossLineCfg.nDirection;
				for(nPtIdx = 0; nPtIdx < nPtCnt -1 ; ++nPtIdx)
				{
					ptStart.x = pRulePoint[nPtIdx].nX;
					ptStart.y = pRulePoint[nPtIdx].nY;

					ptEnd.x = pRulePoint[(nPtIdx + 1) % nPtCnt].nX;
					ptEnd.y = pRulePoint[(nPtIdx + 1) % nPtCnt].nY;

					int nDistance = sqrt((double)((ptEnd.x - ptStart.x) * (ptEnd.x - ptStart.x) + (ptEnd.y - ptStart.y) * (ptEnd.y - ptStart.y)));
					if (nDistance > Min_Distance)
					{
						DrawDirectionArrow(hdc,ptStart,ptEnd,nDirection);
					}
				}

			}

		}
		break;
	case EVENT_IVS_CROSSREGIONDETECTION: //������: ��ÿһ�����ϻ��Ʒ����ʶ
		{
			LineTo(hdc,pRulePoint[0].nX,pRulePoint[0].nY);
			int nDirection = rule.ruleEvent.stuCrossRegionCfg.nDirection;
			HRGN hrgn = CreatePolygonRgn((const POINT*)pRulePoint,nPtCnt,WINDING);
			POINT ptStart,ptEnd;
			if(hrgn != NULL)
			{
				for(nPtIdx = 0; nPtIdx < nPtCnt; ++nPtIdx)
				{
					ptStart.x = pRulePoint[nPtIdx].nX;
					ptStart.y = pRulePoint[nPtIdx].nY;

					ptEnd.x = pRulePoint[(nPtIdx + 1) % nPtCnt].nX;
					ptEnd.y = pRulePoint[(nPtIdx + 1) % nPtCnt].nY;

					int nDistance = sqrt((double)((ptEnd.x - ptStart.x) * (ptEnd.x - ptStart.x) + (ptEnd.y - ptStart.y) * (ptEnd.y - ptStart.y)));
					if (nDistance > Min_Distance)
					{
						DrawDirectionArrow(hdc,ptStart,ptEnd,nDirection,hrgn);
					}
				}
				DeleteObject(hrgn);
			}


		}
		break;
	default:
		LineTo(hdc,pRulePoint[0].nX,pRulePoint[0].nY);
		break;
	}

	TextOutA(hdc,pRulePoint[0].nX,pRulePoint[0].nY,
		pIvsRule->ruleInfo.szRuleName,lstrlenA(pIvsRule->ruleInfo.szRuleName));
}

//************************************
// ����:	public CIvsLogic::DrawDirectionArrow
// ժҪ:	  ���ƾ����߷����ͷ
// ����:
//		void
// ����:
//		HDC hdc
//		POINT ptStart		���
//		POINT ptEnd			�յ�
//		int nDirection		����
//		HRGN hrgn			Ĭ��ֵΪNULL,��ΪNULLʱ��ʾΪ��������һ���߻��Ʒ����ͷ
//							��ʱnDireciton������ʾ����������(����������)
//************************************
void CIvsModule::DrawDirectionArrow(HDC hdc,POINT ptStart,POINT ptEnd,int nDirection,HRGN hrgn /*=NULL*/)
{
	double angle;
	XFORM xform;
	POINT ptTemp,ptA,ptB;
	SIZE szView;
	int arrow_len,tmp_len;

	if ((nDirection < 0) || (nDirection > 2))
	{
		return;
	}

	SaveDC(hdc);
	GetViewportExtEx(hdc,&szView);

	LPtoDP(hdc,&ptStart,1);
	LPtoDP(hdc,&ptEnd,1);

	SetMapMode(hdc,MM_ISOTROPIC);
	SetViewportExtEx(hdc,szView.cx,szView.cy,NULL);
	SetWindowExtEx(hdc,IVS_VIDEO_WIDTH,IVS_VIDEO_HEIGHT,NULL);
	SetViewportOrgEx(hdc,0,0,NULL);

	DPtoLP(hdc,&ptStart,1);
	DPtoLP(hdc,&ptEnd,1);

	// ��ͷ�����������ߵľ���Ϊ20�����ص�
	ptTemp.x = ptTemp.y = 20;
	DPtoLP(hdc,&ptTemp,1);
	arrow_len = ptTemp.x;

	/*
		ȡ�������е�Ϊ��������ϵԭ��,x���뾯�����غ�,������������,
		y�ᴹֱ�ھ�����.��������ϵ��תangle���Ⱥ���ҳ������ϵ�غ�.
		1 ˳ʱ����תʱ�Ƕ�Ϊ��ֵ,��ʱ����ת�Ƕ�Ϊ��ֵ.
		2 ҳ������ϵx��ˮƽ����,y�ᴹֱ����
	*/
	if (ptEnd.x != ptStart.x)
	{
		angle = atan2(1.0 * (ptEnd.y - ptStart.y),1.0 * (ptEnd.x - ptStart.x));
	}
	else if (ptEnd.y - ptStart.y >= 0)
	{
		angle = M_PI / 2;
	}
	else
	{
		angle = -M_PI / 2;
	}

	// ����ϵԭ��ƽ�Ƶ��������е�,Ȼ����תʹ��x���뾯�����غ�
	xform.eM11 = float(cos(angle));
	xform.eM12 = float(sin(angle));
	xform.eM21 = float(-sin(angle));
	xform.eM22 = float(cos(angle));
	xform.eDx  = ((ptStart.x + ptEnd.x) / 2.0f);
	xform.eDy  = ((ptStart.y + ptEnd.y) / 2.0f);

	SetGraphicsMode(hdc,GM_ADVANCED);
	SetWorldTransform(hdc,&xform);

	// ������x�ᴹֱ���߶�,��Ϊx���뾯�����غ�,���Ի��Ƴ����߶�Ҳ���뾯���ߴ�ֱ��
	MoveToEx(hdc,0,arrow_len,NULL);
	LineTo(hdc,0,-arrow_len);

	// ���Ƽ�ͷ.��ͷ��10�����ص�,��ͷ�Ƕ�60��(M_PI / 3)
	tmp_len = int(arrow_len / 2.0 * tan(M_PI / 6));

	ptA.x = 0;
	ptA.y = -arrow_len;
	ptB.x = 0;
	ptB.y = arrow_len;

	/*============================================
		Ϊ�����߻��Ʒ����ͷ
	=============================================*/
	if (NULL == hrgn)
	{
		// R --> L
		if ((1 == nDirection) || (2 == nDirection))
		{
			MoveToEx(hdc,0,-arrow_len,NULL);
			LineTo(hdc,tmp_len,-arrow_len / 2);

			MoveToEx(hdc,0,-arrow_len,NULL);
			LineTo(hdc,-tmp_len,-arrow_len / 2);
		}

		// L --> R
		if ((0 == nDirection) || (2 == nDirection))
		{
			MoveToEx(hdc,0,arrow_len,NULL);
			LineTo(hdc,tmp_len,arrow_len / 2);

			MoveToEx(hdc,0,arrow_len,NULL);
			LineTo(hdc,-tmp_len,arrow_len / 2);
		}

		RestoreDC(hdc,-1);
	}
	/*============================================
		Ϊ��������һ���߻��Ʒ����ͷ
	=============================================*/
	else
	{
		LPtoDP(hdc,&ptA,1);
		LPtoDP(hdc,&ptB,1);

		RestoreDC(hdc,-1);

		DPtoLP(hdc,&ptA,1);
		DPtoLP(hdc,&ptB,1);

		BOOL aInRgn = PtInRegion(hrgn,ptA.x,ptA.y);
		BOOL bInRgn = PtInRegion(hrgn,ptB.x,ptB.y);
		while (!aInRgn && !bInRgn)
		{
			ptA.y += 10;
			ptB.y -= 10;
			//BOOL aInRgn = PtInRegion(hrgn,ptA.x,ptA.y);
			//BOOL bInRgn = PtInRegion(hrgn,ptB.x,ptB.y);
			aInRgn = PtInRegion(hrgn,ptA.x,ptA.y);
			bInRgn = PtInRegion(hrgn,ptB.x,ptB.y);

		}

		POINT ptArrow,ptOther;

		SaveDC(hdc);

		SetMapMode(hdc,MM_ISOTROPIC);
		SetViewportExtEx(hdc,szView.cx,szView.cy,NULL);
		SetWindowExtEx(hdc,IVS_VIDEO_WIDTH,IVS_VIDEO_HEIGHT,NULL);
		SetViewportOrgEx(hdc,0,0,NULL);

		SetGraphicsMode(hdc,GM_ADVANCED);
		SetWorldTransform(hdc,&xform);

		ptA.x = 0;
		ptA.y = -arrow_len;
		ptB.x = 0;
		ptB.y = arrow_len;

		// ��������
		if ((0 == nDirection) || (2 == nDirection))
		{
			if (aInRgn)
			{
				ptArrow = ptA;
				ptOther = ptB;
			}
			else if (bInRgn)
			{
				ptArrow = ptB;
				ptOther = ptA;
			}
			//else
			//{
			//	return;
			//}
		}
		// �뿪����
		else if ((1 == nDirection) || (2 == nDirection))
		{
			if (!aInRgn)
			{
				ptArrow = ptA;
				ptOther = ptB;
			}
			else if (!bInRgn)
			{
				ptArrow = ptB;
				ptOther = ptA;
			}
			//else
			//{
			//	return;
			//}
		}

		if (ptArrow.y < 0)
		{
			arrow_len = (-1) * arrow_len;
		}

		MoveToEx(hdc,ptArrow.x,ptArrow.y,NULL);
		LineTo(hdc,tmp_len,arrow_len / 2);

		MoveToEx(hdc,ptArrow.x,ptArrow.y,NULL);
		LineTo(hdc,-tmp_len,arrow_len / 2);

		// ����/�뿪����
		if (2 == nDirection)
		{
			arrow_len = (-1) * arrow_len;

			MoveToEx(hdc,ptOther.x,ptOther.y,NULL);
			LineTo(hdc,tmp_len,arrow_len / 2);

			MoveToEx(hdc,ptOther.x,ptOther.y,NULL);
			LineTo(hdc,-tmp_len,arrow_len / 2);
		}

		RestoreDC(hdc,-1);
	}
}

//************************************
// ����:	protected static CIvsLogic::DrawIvsObjectProc
// ժҪ:		����Ƶ�����ϻ����˶��켣���˶�Ŀ�����
// ����:
//		int
// ����:
//		IvsDecodeInfo * pDecodeInfo	������Ϣ
//		HDC hdc						�豸����
//************************************
int CIvsModule::DrawIvsObjectProc(IvsChnlInfo* pChnlInfo,IvsDecodeInfo* pDecInfo,HDC hdc)
{
	IvsObjectMap::iterator itor_obj;
	IvsObjectMap::iterator itor_end;
	IvsObject* pIvsObj;
	bool bNotShow;

	//add by wanglei 2011-01-11
	//�����жϹ����Ƿ���������߻��߾����������������򲻻��˶�Ŀ��켣
	IvsRuleMap::iterator itor_rule;
	bool bShowocus = false;
	itor_rule = pChnlInfo->rule_map.begin();
	for(; itor_rule != pChnlInfo->rule_map.end(); ++itor_rule)
	{
		if (EVENT_IVS_CROSSLINEDETECTION == itor_rule->second->ruleInfo.stuRuleInfo.dwRuleType 
			|| EVENT_IVS_CROSSREGIONDETECTION == itor_rule->second->ruleInfo.stuRuleInfo.dwRuleType
			/*|| EVENT_IVS_CROSSFENCEDETECTION ==itor_rule->second.ruleInfo.stuRuleInfo.dwRuleType
			|| EVENT_IVS_RETROGRADEDETECTION == itor_rule->second.ruleInfo.stuRuleInfo.dwRuleType
			|| EVENT_IVS_ABNORMALRUNDETECTION == itor_rule->second.ruleInfo.stuRuleInfo.dwRuleType*/)
		{
			bShowocus = true;
			break;
		}
	}

	// ����ÿ���˶�Ŀ��
	itor_end = pChnlInfo->mapId2Obj.end();
	itor_obj = pChnlInfo->mapId2Obj.begin();

	while(itor_obj != itor_end)
	{
		bNotShow = false;

		pIvsObj = &(itor_obj->second);

		// Ŀ�괥������
		if (pIvsObj->alarm_cnt > 0)
		{
			if (0 == pIvsObj->alarm_cnt % 5)
			{
				bNotShow = true;
			}
			else
			{
				SetDCPenColor(hdc,Color_LocusAlarm);
			}
		}
		// Ŀ�������˶�
		else
		{
			SetDCPenColor(hdc,Color_LocusNormal);
		}

		if (!bNotShow && pIvsObj->opt_type != IvsOjbOpt_HideLocus)
		{
			// ���Ƹ����˶��켣
			if (pDecInfo->bShowLocus && bShowocus)
			{
				DrawIvsObjectLocus(pIvsObj,hdc);
			}

			// �����˶�Ŀ�����
			if (pDecInfo->bShowObj)
			{
				DrawIvsObjectBoundBox(pIvsObj,hdc);
			}
		}

		// ������������ʾ��������
		if (pIvsObj->display_cnt > 0)
		{
			--pIvsObj->display_cnt;
		}

		if (pIvsObj->alarm_cnt > 0)
		{
			--pIvsObj->alarm_cnt;
		}

		if (pIvsObj->display_cnt <= 0)
		{
			itor_obj = pChnlInfo->mapId2Obj.erase(itor_obj);
		}
		else
		{
			++itor_obj;
		}
	}

	return 0;
}

//���ƹ켣
void CIvsModule::DrawIvsObjectLocus(IvsObject* pIvsObj, HDC hdc)
{
	const int X_SCALE = IVS_VIDEO_WIDTH  / LOCUS_WIDTH;
	const int Y_SCALE = IVS_VIDEO_HEIGHT / LOCUS_HEIGHT;

	bool bFirstPoint = true;
	POINT lastPoint[2] = {{-1,-1},{-1,-1}};
	IvsLocus::iterator itor_seg;
	IvsLocusSeg::iterator itor_pt;

	itor_seg = pIvsObj->obj_locus.begin();

	// ���ƹ켣��
	for( ; itor_seg != pIvsObj->obj_locus.end(); itor_seg++)
	{
		itor_pt = itor_seg->begin();

		for (; itor_pt != itor_seg->end(); itor_pt++)
		{
			if (bFirstPoint)
			{
				MoveToEx(hdc,X_SCALE * itor_pt->nX,Y_SCALE * itor_pt->nY,NULL);
				bFirstPoint = false;
			}
			else
			{
				LineTo(hdc,X_SCALE * itor_pt->nX,Y_SCALE * itor_pt->nY);
			}

			lastPoint[1] = lastPoint[0];
			lastPoint[0].x = itor_pt->nX;
			lastPoint[0].y = itor_pt->nY;
		}
	}

	// �켣����
	/*
	if ((lastPoint[0].x >= 0) && (lastPoint[0].y >= 0)
		&& (lastPoint[1].x >= 0) && (lastPoint[1].y >= 0))
	{
		DrawLocusDirectionArrow(hdc,lastPoint[1],lastPoint[0]);
	}
	*/
}

//����Ŀ�����
void CIvsModule::DrawIvsObjectBoundBox(IvsObject* pIvsObj, HDC hdc)
{
	const int X_SCALE = IVS_VIDEO_WIDTH  / LOCUS_WIDTH;
	const int Y_SCALE = IVS_VIDEO_HEIGHT / LOCUS_HEIGHT;
	
	IvsRect& rc = pIvsObj->obj_rect;
	
	MoveToEx(hdc,	X_SCALE*rc.left,	Y_SCALE*rc.top,NULL);	// ����
	LineTo(hdc,		X_SCALE*rc.right,	Y_SCALE*rc.top);		// ==> ����
	LineTo(hdc,		X_SCALE*rc.right,	Y_SCALE*rc.bottom);		// ==> ����
	LineTo(hdc,		X_SCALE*rc.left,	Y_SCALE*rc.bottom);		// ==> ����
	LineTo(hdc,		X_SCALE*rc.left,	Y_SCALE*rc.top);		// ==> ����
}

// ����������ȡ���ܷ�����Ϣ
void __stdcall CIvsModule::GetIvsInfoProc(char* pBuf,long nKey,
										 long  nObjLen,long nTotalLen,
										 void*  nType,
										 void*  nUser)
{
	if (NULL == pBuf)
	{
		return;
	}

	EnterCriticalSection(&m_cs);
	std::map<int,IvsDecodeInfo>::iterator itor_decode;
	std::list<IvsChnlInfo>::iterator itor_chnl;
	/*============================================
		��������
	=============================================*/
	if (IVSINFOTYPE_PRESETPOS == nKey)
	{
		int nDecPort = *(int*)nType;
		DWORD dwPresetPos = *(DWORD*)pBuf;
		
		itor_decode = m_decode_info_map.find(nDecPort);
		
		if (itor_decode != m_decode_info_map.end())
		{
			itor_chnl = m_chnl_info_list.begin();
			
			for(; itor_chnl != m_chnl_info_list.end(); ++itor_chnl)
			{
				if ((itor_chnl->dev_id == itor_decode->second.dev_id)
					&& (itor_chnl->chnl_idx == itor_decode->second.chnl_idx))
				{
					break;
				}
			}
			
			if (itor_chnl != m_chnl_info_list.end())
			{
				if (itor_chnl->bPreset != (BYTE)dwPresetPos)
				{
					if (0 == nTotalLen)
					{
						itor_chnl->bPreset = 0xFF;
					}
					else
					{
						itor_chnl->bPreset = (BYTE)dwPresetPos;
					}
				}
			}
		}
	}
	/*============================================
		�˶��켣
	=============================================*/
	else if (IVSINFOTYPE_MOTINTRKS == nKey)
	{
		PRIVATE_IVS_OBJ* pIvsObj = (PRIVATE_IVS_OBJ*)pBuf;

		itor_decode = m_decode_info_map.find(pIvsObj->decode_id);

		if (itor_decode == m_decode_info_map.end())
		{
			LeaveCriticalSection(&m_cs);
			return;
		}
		else
		{
			itor_chnl = m_chnl_info_list.begin();

			for(; itor_chnl != m_chnl_info_list.end(); ++itor_chnl)
			{
				if ((itor_chnl->dev_id == itor_decode->second.dev_id)
					&& (itor_chnl->chnl_idx == itor_decode->second.chnl_idx))
				{
					break;
				}
			}

			if (itor_chnl == m_chnl_info_list.end())
			{
				LeaveCriticalSection(&m_cs);
				return;
			}
		}

		IvsChnlInfo* pChnlInfo = &(*itor_chnl);

		if (pIvsObj->decode_id != pChnlInfo->live_dec_id)
		{
			return;
		}
		// ����ͨ��IVS���ݶ�ʧ,����˶�Ŀ���б�
		else if (2 == *(int*)nType)
		{
			itor_chnl->mapId2Obj.clear();
		}
		// ���/�����˶�Ŀ����Ϣ
		else if (1 == *(int*)nType)
		{
			IvsObjectMap::iterator itor_obj;
			IvsObjectMap::iterator itor_end;
			int nIdx,nObjCnt;

			itor_end = pChnlInfo->mapId2Obj.end();

			nObjCnt = nTotalLen / nObjLen;

			for (nIdx = 0; nIdx < nObjCnt; ++nIdx)
			{
				pIvsObj = (PRIVATE_IVS_OBJ*)(pBuf + nIdx * sizeof(PRIVATE_IVS_OBJ));

				itor_obj = pChnlInfo->mapId2Obj.find(pIvsObj->obj_id);
				if (IvsOjbOpt_DelOjb == pIvsObj->operator_type)
				{
					if (itor_obj != itor_end)
					{
						//if (itor_obj->second.display_cnt <= 0)
						{
							pChnlInfo->mapId2Obj.erase(itor_obj);
							itor_end = pChnlInfo->mapId2Obj.end();
						}
					}
				}
				else
				{
					IvsLocusSeg   locus_seg;
					PRIVATE_IVS_POINT* p_last_pt = NULL;
					CFG_POLYLINE ivs_point;
					int nPointIdx;

					for(nPointIdx = 0;
						(nPointIdx < pIvsObj->trackpt_num) && (nPointIdx < MAX_TRACKPOINT_NUM);
						++nPointIdx)
					{
						ivs_point.nX = pIvsObj->track_point[nPointIdx].x;
						ivs_point.nY = pIvsObj->track_point[nPointIdx].y;
						locus_seg.push_back(ivs_point);
					}

					if (nPointIdx > 0)
					{
						p_last_pt =  &(pIvsObj->track_point[nPointIdx - 1]);
					}
					else
					{
						if (itor_obj != itor_end)
						{
							itor_obj->second.opt_type = pIvsObj->operator_type;
						}
						continue;
					}

					// ����һ���˶�Ŀ��,�����˶��켣���б��м����һ���˶��켣
					if (itor_obj == itor_end)
					{
						IvsObject ivs_obj;

						ivs_obj.object_id  = pIvsObj->obj_id;
						ivs_obj.opt_type = pIvsObj->operator_type;
						ivs_obj.alarm_cnt   = 0;
						ivs_obj.display_cnt = IVS_INFO_SHOW_FRAMES;

						ivs_obj.obj_rect.left   = p_last_pt->x - p_last_pt->xSize;
						ivs_obj.obj_rect.right  = p_last_pt->x + p_last_pt->xSize;
						ivs_obj.obj_rect.top    = p_last_pt->y - p_last_pt->ySize;
						ivs_obj.obj_rect.bottom = p_last_pt->y + p_last_pt->ySize;

						ivs_obj.obj_locus.push_back(locus_seg);

						pChnlInfo->mapId2Obj.insert(std::make_pair(pIvsObj->obj_id,ivs_obj));
						
						if (pChnlInfo->mapId2Obj.size() > MAX_IVS_OBJECT_CNT)
						{
							itor_obj = pChnlInfo->mapId2Obj.begin();
							pChnlInfo->mapId2Obj.erase(itor_obj);
						}
					}
					// �������˶�Ŀ����˶��켣���б�������һ���˶��켣
					else
					{
						itor_obj->second.opt_type = pIvsObj->operator_type;
						itor_obj->second.obj_locus.push_back(locus_seg);

						itor_obj->second.display_cnt = IVS_INFO_SHOW_FRAMES;

						itor_obj->second.obj_rect.left   = p_last_pt->x - p_last_pt->xSize;
						itor_obj->second.obj_rect.right  = p_last_pt->x + p_last_pt->xSize;
						itor_obj->second.obj_rect.top    = p_last_pt->y - p_last_pt->ySize;
						itor_obj->second.obj_rect.bottom = p_last_pt->y + p_last_pt->ySize;

						if (itor_obj->second.obj_locus.size() > MAX_IVS_LOCUS_SEG_CNT)
						{
							itor_obj->second.obj_locus.pop_front();
						}
					}
				}
			}
		}
	}

	LeaveCriticalSection(&m_cs);
}

CIvsModule::~CIvsModule()
{
	IvsChnlInfo* pChnlInfo = NULL;
	
	std::list<IvsChnlInfo>::iterator itor_chnl;
	
	itor_chnl = m_chnl_info_list.begin();
	
	for(; itor_chnl != m_chnl_info_list.end(); ++itor_chnl)
	{
		pChnlInfo = &(*itor_chnl);

		{
			std::map<int,IvsRule*>::iterator it = pChnlInfo->rule_map.begin();
			while (it != pChnlInfo->rule_map.end())
			{
				IvsRule *pIvsRule = (*it).second;
				if (pIvsRule != NULL)
				{
					delete pIvsRule;
				}
				it++;
			}
			pChnlInfo->rule_map.clear();
		}
	}	
}

//************************************
// ����:	public static CIvsLogic::DrawIvsInfoProc
// ժҪ:	  ����Ƶ�����ϻ������ܷ�����Ϣ(����,�˶�Ŀ�������˶��켣)
// ����:
//		int		0: �ɹ�		<0: ʧ��
// ����:
//		HDC hdc			�豸����
//		long nPort		������
//		LONG nUser		�û�����
//************************************
void CIvsModule::DrawIvsInfoProc(long nPort,HDC hdc,LONG nUser)
{
	//AX_Write_Guard<AX_RW_Mutex> lock_write(mutex);

	IvsChnlInfo* pChnlInfo = NULL;
	IvsDecodeInfo* pDecInfo = NULL;

	std::map<int,IvsDecodeInfo>::iterator itor_decode;
	std::list<IvsChnlInfo>::iterator itor_chnl;

	itor_decode = m_decode_info_map.find(nPort);
	if (itor_decode == m_decode_info_map.end())
	{
		return;
	}

	itor_chnl = m_chnl_info_list.begin();

	for(; itor_chnl != m_chnl_info_list.end(); ++itor_chnl)
	{
		if ((itor_chnl->dev_id == itor_decode->second.dev_id)
			&& (itor_chnl->chnl_idx == itor_decode->second.chnl_idx))
		{
			break;
		}
	}

	if (itor_chnl == m_chnl_info_list.end())
	{
		return;
	}

	pDecInfo  = &(itor_decode->second);
	pChnlInfo = &(*itor_chnl);

	if (!(pChnlInfo->bEnableIvs))
	{
		return;
	}

	/*============================================
		׼���豸����: ����ӳ��ģʽ,��������
	=============================================*/
	RECT rcVideoWnd;
	LONG nWidth,nHeight;

	FromHandle(pDecInfo->hwnd)->GetWindowRect(&rcVideoWnd);
	//GetWindowRect(pDecInfo->hwnd ,&rcVideoWnd);
	nWidth  = rcVideoWnd.right  - rcVideoWnd.left;
	nHeight = rcVideoWnd.bottom - rcVideoWnd.top;
	if ((nWidth <= 0) || (nHeight <= 0))
	{
		return;
	}

	SaveDC(hdc);

	SetBkMode(hdc,TRANSPARENT);
	SetMapMode(hdc,MM_ANISOTROPIC);
	SetViewportExtEx(hdc,nWidth,nHeight,NULL);
	SetWindowExtEx(hdc,IVS_VIDEO_WIDTH,IVS_VIDEO_HEIGHT,NULL);
	SetViewportOrgEx(hdc,0,0,NULL);
	SelectObject(hdc,GetStockObject(DC_PEN));

	// ��������ΪϵͳĬ��GUI����
	LOGFONT logfont={0};
	HFONT hFont;
	POINT pt;

	pt.x = pt.y = HIWORD(GetDialogBaseUnits());
	DPtoLP(hdc,&pt,1);

	hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);

	if (sizeof(logfont) == GetObject(hFont,sizeof(logfont),&logfont))
	{
		logfont.lfHeight = -1 * abs(pt.x);
		hFont = CreateFontIndirect(&logfont);
		SelectObject(hdc,(HGDIOBJ)hFont);
	}
	else
	{
		SelectObject(hdc,(HGDIOBJ)hFont);
		hFont = NULL;
	}

	/*============================================
		�������ܷ��������Ŀ���˶��켣�����
	=============================================*/

	if (pDecInfo->bShowRule)
	{
		DrawIvsRuleProc(pChnlInfo,hdc);
	}

	if (pDecInfo->bShowLocus || pDecInfo->bShowObj)
	{
		DrawIvsObjectProc(pChnlInfo,pDecInfo,hdc);
	}

	RestoreDC(hdc,-1);
	DeleteObject((HGDIOBJ)hFont);

	return;
}

void CIvsModule::ClearData()
{
	m_decode_info_map.clear();
	m_chnl_info_list.clear();
}