; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CConfigFaceRule
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Video Analyse Configuration.h"

ClassCount=17
Class1=CVideoAnalyseConfigurationApp
Class2=CVideoAnalyseConfigurationDlg
Class3=CAboutDlg

ResourceCount=16
Resource1=IDD_CONFIG_MODULE
Resource2=IDR_MAINFRAME
Resource3=IDD_CONFIG_TRAFFICGATE
Class4=CConfigTraffic
Resource4=IDD_COFNIG_CROSSLINE_RULE
Class5=CConfigModule
Resource5=IDD_CONFIG_PASTE_RULE
Class6=CConfigRules
Resource6=IDD_ABOUTBOX
Class7=CConfigTrafficGateRule
Resource7=IDD_SCENESHOW_DIALOG
Resource8=IDD_CONFIG_RULES
Class8=CSceneShow
Resource9=IDD_CONFIG_TRAFFICSCENE
Class9=CConfigCrossLineRule
Resource10=IDD_VIDEOANALYSECONFIGURATION_DIALOG
Class10=CConfigFaceRule
Resource11=IDD_CONFIG_RIOTER_RULE
Class11=CConfigRuleBase
Class12=CConfigCrossRegion
Resource12=IDD_PICTURE_SHOW
Class13=CConfigWanderRule
Resource13=IDD_CONFIG_CROSSREGION_RULE
Class14=CConfigRioterRule
Resource14=IDD_COFNIG_FACEDETECT_RULE
Class15=CConfigPasteRule
Class16=CConfigAtmScene
Resource15=IDD_CONFIG_WANDER_RULE
Class17=CConfigFaceScene
Resource16=IDD_CONFIG_ATM_SCENE

[CLS:CVideoAnalyseConfigurationApp]
Type=0
HeaderFile=Video Analyse Configuration.h
ImplementationFile=Video Analyse Configuration.cpp
Filter=N

[CLS:CVideoAnalyseConfigurationDlg]
Type=0
HeaderFile=Video Analyse ConfigurationDlg.h
ImplementationFile=Video Analyse ConfigurationDlg.cpp
Filter=D
LastObject=IDC_TAB_ATTRIBUTE
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=Video Analyse ConfigurationDlg.h
ImplementationFile=Video Analyse ConfigurationDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_VIDEOANALYSECONFIGURATION_DIALOG]
Type=1
Class=CVideoAnalyseConfigurationDlg
ControlCount=13
Control1=IDC_STATIC,button,1342177287
Control2=IDC_EDIT_IP,edit,1350631552
Control3=IDC_EDIT_PORT,edit,1350631552
Control4=IDC_EDIT_USERNAME,edit,1350631552
Control5=IDC_EDIT_PASSWORD,edit,1350631584
Control6=IDC_BUTTON_LOGIN,button,1342242816
Control7=IDC_BUTTON_LOGOUT,button,1476460544
Control8=IDC_TAB_ATTRIBUTE,SysTabControl32,1342177280
Control9=IDC_STATIC,static,1342308354
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,button,1342177287

[CLS:CConfigTraffic]
Type=0
HeaderFile=ConfigTraffic.h
ImplementationFile=ConfigTraffic.cpp
BaseClass=CDialog
Filter=D
LastObject=CConfigTraffic

[DLG:IDD_CONFIG_MODULE]
Type=1
Class=CConfigModule
ControlCount=36
Control1=IDC_STATIC,static,1342308354
Control2=IDC_COMBO_CHANNEL_M,combobox,1344339971
Control3=IDC_STATIC,static,1342177287
Control4=IDC_STATIC,static,1342308354
Control5=IDC_CHECK_SNAP_M,button,1476460547
Control6=IDC_STATIC,static,1342308354
Control7=IDC_COMBO_FILTERTYPE_M,combobox,1344339971
Control8=IDC_STATIC,static,1342308354
Control9=IDC_EDIT_MINSX_M,edit,1350631552
Control10=IDC_STATIC,static,1342308354
Control11=IDC_EDIT_MINSY_M,edit,1350631552
Control12=IDC_STATIC,static,1342308354
Control13=IDC_EDIT_MAXSX_M,edit,1350631552
Control14=IDC_STATIC,static,1342308354
Control15=IDC_EDIT_MAXSY_M,edit,1350631552
Control16=IDC_STATIC,static,1342177287
Control17=IDC_BUTTON_SAVE_M,button,1342242816
Control18=IDC_BUTTON_REFRESH_M,button,1342242816
Control19=IDC_COMBO_OBJTYPE,combobox,1344339971
Control20=IDC_STATIC,button,1342177287
Control21=IDC_BUTTON_ADDMOD,button,1342242816
Control22=IDC_BUTTON_DELETSELMOD,button,1342242816
Control23=IDC_STATIC,static,1342308354
Control24=IDC_EDIT_MINSA_M,edit,1350631552
Control25=IDC_STATIC,static,1342308354
Control26=IDC_EDIT_MAXSA_M,edit,1350631552
Control27=IDC_TREE_MODULE,SysTreeView32,1350631463
Control28=IDC_STATIC,static,1342308352
Control29=IDC_STATIC,static,1342308352
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352
Control32=IDC_BUTTON_SET_DETECTREGION,button,1342242816
Control33=IDC_STATIC,static,1342308353
Control34=IDC_STATIC,static,1342308353
Control35=IDC_STATIC_ROADID,static,1342308354
Control36=IDC_STATIC,button,1342177287

[CLS:CConfigModule]
Type=0
HeaderFile=ConfigModule.h
ImplementationFile=ConfigModule.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON_SET_TRACKREGION
VirtualFilter=dWC

[DLG:IDD_CONFIG_RULES]
Type=1
Class=CConfigRules
ControlCount=12
Control1=IDC_STATIC,static,1342177287
Control2=IDC_BUTTON_SAVE_R,button,1342242816
Control3=IDC_BUTTON_REFRESH_R,button,1342242816
Control4=IDC_STATIC,static,1342308354
Control5=IDC_COMBO_CHANNEL_R,combobox,1344339971
Control6=IDC_STATIC,static,1342177287
Control7=IDC_BUTTON_ADDRULE_R,button,1342242816
Control8=IDC_BUTTON_DELETRULE_R,button,1342242816
Control9=IDC_TREE_RULES,SysTreeView32,1350631463
Control10=IDC_STATIC_VEDIO,static,1342177287
Control11=IDC_EDIT_RULENAME,edit,1350631552
Control12=IDC_STATIC,static,1342308354

[CLS:CConfigRules]
Type=0
HeaderFile=ConfigRules.h
ImplementationFile=ConfigRules.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_COMBO_CHANNEL_R

[DLG:IDD_CONFIG_TRAFFICGATE]
Type=1
Class=CConfigTrafficGateRule
ControlCount=20
Control1=IDC_STATIC,static,1342308354
Control2=IDC_EDIT_RULENAME_TG,edit,1350631552
Control3=IDC_CHECK_ENABLE_TG,button,1342242819
Control4=IDC_LIST_OBJTYPE_TG,SysListView32,1350631425
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_SPEEDWGT_TG,edit,1484849280
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_SPEEDUL_TG,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_SPEEDLL_TG,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT_METRICDIS,edit,1484849280
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDIT_CARWAYID_TG,edit,1350631552
Control16=IDC_STATIC,static,1342308353
Control17=IDC_STATIC,static,1342308353
Control18=IDC_STATIC,static,1342308354
Control19=IDC_BUTTON_SET_RULELINES_TG,button,1342242816
Control20=IDC_STATIC,button,1342177287

[CLS:CConfigTrafficGateRule]
Type=0
HeaderFile=ConfigTrafficGateRule.h
ImplementationFile=ConfigTrafficGateRule.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_RULENAME_TG
VirtualFilter=dWC

[DLG:IDD_CONFIG_TRAFFICSCENE]
Type=1
Class=CConfigTraffic
ControlCount=40
Control1=IDC_STATIC,static,1342308354
Control2=IDC_COMBO_CHANNEL_T,combobox,1344339971
Control3=IDC_STATIC,static,1342177287
Control4=IDC_STATIC,static,1342308354
Control5=IDC_STATIC,static,1342308354
Control6=IDC_EDIT_CAMERAH_T,edit,1350631552
Control7=IDC_STATIC,static,1342308354
Control8=IDC_EDIT_CAMERAD_T,edit,1350631552
Control9=IDC_STATIC,static,1342308354
Control10=IDC_EDIT_NDPX_T,edit,1350631552
Control11=IDC_STATIC,static,1342308354
Control12=IDC_EDIT_NDPY_T,edit,1350631552
Control13=IDC_STATIC,static,1342308354
Control14=IDC_EDIT_NDPTCD_T,edit,1350631552
Control15=IDC_STATIC,static,1342308354
Control16=IDC_STATIC,static,1342308354
Control17=IDC_EDIT_FDPX_T,edit,1350631552
Control18=IDC_STATIC,static,1342308354
Control19=IDC_EDIT_FDPY_T,edit,1350631552
Control20=IDC_STATIC,static,1342308354
Control21=IDC_EDIT_FDPTCD_T,edit,1350631552
Control22=IDC_STATIC,static,1342308354
Control23=IDC_STATIC,static,1342177287
Control24=IDC_BUTTON_SAVE_T,button,1342242816
Control25=IDC_BUTTON_REFRESH_T,button,1342242816
Control26=IDC_COMBO_SCENE_T,combobox,1344339971
Control27=IDC_STATIC,static,1342308352
Control28=IDC_STATIC,static,1342308352
Control29=IDC_STATIC,static,1342308352
Control30=IDC_STATIC,static,1342308352
Control31=IDC_STATIC,static,1342308352
Control32=IDC_STATIC,static,1342308352
Control33=IDC_STATIC,static,1342308352
Control34=IDC_STATIC,button,1342177287
Control35=IDC_STATIC,button,1342177287
Control36=IDC_LIST_ROAD,SysListView32,1350631425
Control37=IDC_BUTTON_ADDROAD,button,1342242816
Control38=IDC_BUTTON_DELETROAD,button,1342242816
Control39=IDC_BUTTON_CHANGEROAD,button,1342242816
Control40=IDC_STATIC,static,1342308352

[DLG:IDD_PICTURE_SHOW]
Type=1
Class=CConfigCrossRegion
ControlCount=0

[DLG:IDD_SCENESHOW_DIALOG]
Type=1
Class=CSceneShow
ControlCount=13
Control1=IDC_RADIO1,button,1073872905
Control2=IDC_RADIO2,button,1073741833
Control3=IDC_RADIO3,button,1073741833
Control4=IDC_RADIO4,button,1073741833
Control5=IDC_RADIO5,button,1073741833
Control6=IDOK,button,1342242817
Control7=IDCANCEL,button,1342242816
Control8=IDC_STATIC_SHOW,static,1342177287
Control9=IDC_STATIC_ROADID,static,1073872898
Control10=IDC_EDIT_ROADID,edit,1082196096
Control11=IDC_STATIC_DIRECTION,static,1073872898
Control12=IDC_COMBO_DIRECTION,combobox,1075904514
Control13=IDC_BUTTON_REPAINT,button,1342242816

[CLS:CSceneShow]
Type=0
HeaderFile=SceneShow.h
ImplementationFile=SceneShow.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CSceneShow

[DLG:IDD_COFNIG_CROSSLINE_RULE]
Type=1
Class=CConfigCrossLineRule
ControlCount=12
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_RULENAME_TG,edit,1350631552
Control4=IDC_CHECK_ENABLE_TG,button,1342242819
Control5=IDC_STATIC,button,1342177287
Control6=IDC_LIST_OBJTYPE_TG,SysListView32,1350631425
Control7=IDC_BUTTON_SET_RULELINES_TG,button,1342242816
Control8=IDC_STATIC_DIRECTION,static,1342308352
Control9=IDC_COMBO_DIRECT,combobox,1344339971
Control10=IDC_STATIC_TriggerPosition,static,1342308352
Control11=IDC_COMBO_TriggerPosition,combobox,1344339971
Control12=IDC_STATIC,static,1342308352

[CLS:CConfigCrossLineRule]
Type=0
HeaderFile=ConfigCrossLineRule.h
ImplementationFile=ConfigCrossLineRule.cpp
BaseClass=CDialog
Filter=D
LastObject=CConfigCrossLineRule
VirtualFilter=dWC

[CLS:CConfigFaceRule]
Type=0
HeaderFile=ConfigFaceRule.h
ImplementationFile=ConfigFaceRule.cpp
BaseClass=CDialog
Filter=D
LastObject=CConfigFaceRule
VirtualFilter=dWC

[DLG:IDD_COFNIG_FACEDETECT_RULE]
Type=1
Class=CConfigRuleBase
ControlCount=8
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC1,static,1342308352
Control3=IDC_EDIT_RULENAME_TG,edit,1350631552
Control4=IDC_CHECK_ENABLE_TG,button,1342242819
Control5=IDC_STATIC,button,1342177287
Control6=IDC_LIST_OBJTYPE_TG,SysListView32,1350631425
Control7=IDC_BUTTON_SET_RULELINES_TG,button,1342242816
Control8=IDC_STATIC,static,1342308352

[CLS:CConfigRuleBase]
Type=0
HeaderFile=ConfigRuleBase.h
ImplementationFile=ConfigRuleBase.cpp
BaseClass=CDialog
Filter=D

[DLG:IDD_CONFIG_CROSSREGION_RULE]
Type=1
Class=CConfigFaceRule
ControlCount=20
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_RULENAME_TG,edit,1350631552
Control4=IDC_CHECK_ENABLE_TG,button,1342242819
Control5=IDC_STATIC,button,1342177287
Control6=IDC_LIST_OBJTYPE_TG,SysListView32,1350631425
Control7=IDC_BUTTON_SET_RULELINES_TG,button,1342242816
Control8=IDC_COMBO_ACTIONTYPE_TG,combobox,1342242819
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC_DIRECTION,static,1342308352
Control11=IDC_COMBO_DIRECT,combobox,1344339971
Control12=IDC_EDIT_MinTargets,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_EDIT_MaxTargets,edit,1350631552
Control16=IDC_STATIC,static,1342308352
Control17=IDC_EDIT_MinDuration,edit,1350631552
Control18=IDC_STATIC,static,1342308352
Control19=IDC_EDIT_ReportInterval,edit,1350631552
Control20=IDC_STATIC,static,1342308352

[CLS:CConfigCrossRegion]
Type=0
HeaderFile=ConfigCrossRegion.h
ImplementationFile=ConfigCrossRegion.cpp
BaseClass=CDialog
Filter=D
LastObject=CConfigCrossRegion
VirtualFilter=dWC

[DLG:IDD_CONFIG_WANDER_RULE]
Type=1
Class=CConfigWanderRule
ControlCount=15
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_RULENAME_TG,edit,1350631552
Control4=IDC_CHECK_ENABLE_TG,button,1342242819
Control5=IDC_STATIC,button,1342177287
Control6=IDC_LIST_OBJTYPE_TG,SysListView32,1350631425
Control7=IDC_BUTTON_SET_RULELINES_TG,button,1342242816
Control8=IDC_STATIC_TriggerPosition,static,1342308352
Control9=IDC_COMBO_TriggerPosition,combobox,1344339971
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_TriggerTargetsNumber,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=IDC_EDIT_ReportInterval,edit,1350631552
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352

[CLS:CConfigWanderRule]
Type=0
HeaderFile=ConfigWanderRule.h
ImplementationFile=ConfigWanderRule.cpp
BaseClass=CDialog
Filter=D
LastObject=CConfigWanderRule
VirtualFilter=dWC

[DLG:IDD_CONFIG_RIOTER_RULE]
Type=1
Class=CConfigRioterRule
ControlCount=12
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_RULENAME_TG,edit,1350631552
Control4=IDC_CHECK_ENABLE_TG,button,1342242819
Control5=IDC_STATIC,button,1342177287
Control6=IDC_LIST_OBJTYPE_TG,SysListView32,1350631425
Control7=IDC_BUTTON_SET_RULELINES_TG,button,1342242816
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_AreaPercent,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_MinDuration,edit,1350631552
Control12=IDC_STATIC,static,1342308352

[CLS:CConfigRioterRule]
Type=0
HeaderFile=ConfigRioterRule.h
ImplementationFile=ConfigRioterRule.cpp
BaseClass=CDialog
Filter=D
LastObject=CConfigRioterRule
VirtualFilter=dWC

[DLG:IDD_CONFIG_PASTE_RULE]
Type=1
Class=CConfigPasteRule
ControlCount=8
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_RULENAME_TG,edit,1350631552
Control4=IDC_CHECK_ENABLE_TG,button,1342242819
Control5=IDC_STATIC,button,1342177287
Control6=IDC_LIST_OBJTYPE_TG,SysListView32,1350631425
Control7=IDC_BUTTON_SET_RULELINES_TG,button,1342242816
Control8=IDC_STATIC,static,1342308352

[CLS:CConfigPasteRule]
Type=0
HeaderFile=ConfigPasteRule.h
ImplementationFile=ConfigPasteRule.cpp
BaseClass=CDialog
Filter=D
LastObject=CConfigPasteRule
VirtualFilter=dWC

[CLS:CConfigAtmScene]
Type=0
HeaderFile=ConfigAtmScene.h
ImplementationFile=ConfigAtmScene.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_COMBO_CHANNEL_T

[DLG:IDD_CONFIG_ATM_SCENE]
Type=1
Class=CConfigAtmScene
ControlCount=8
Control1=IDC_BUTTON_SAVE_T,button,1342242816
Control2=IDC_BUTTON_REFRESH_T,button,1342242816
Control3=IDC_STATIC,static,1342308354
Control4=IDC_COMBO_CHANNEL_T,combobox,1344339971
Control5=IDC_STATIC,static,1342177287
Control6=IDC_STATIC,static,1342177287
Control7=IDC_STATIC,static,1342308354
Control8=IDC_COMBO_SCENE_T,combobox,1344339971

[CLS:CConfigFaceScene]
Type=0
HeaderFile=ConfigFaceScene.h
ImplementationFile=ConfigFaceScene.cpp
BaseClass=CDialog
Filter=D
LastObject=CConfigFaceScene
VirtualFilter=dWC

