VERSION 5.00
Begin VB.Form Form1 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Form1"
   ClientHeight    =   3885
   ClientLeft      =   45
   ClientTop       =   435
   ClientWidth     =   12645
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3885
   ScaleWidth      =   12645
   StartUpPosition =   3  'Windows Default
   Begin VB.ComboBox Combo2 
      Height          =   315
      Left            =   6720
      TabIndex        =   29
      Top             =   3360
      Width           =   1335
   End
   Begin VB.ComboBox Combo1 
      Height          =   315
      Left            =   4800
      TabIndex        =   28
      Top             =   3360
      Width           =   1575
   End
   Begin VB.CommandButton Command6 
      Caption         =   "打开预览"
      Height          =   495
      Left            =   8400
      TabIndex        =   27
      Top             =   3240
      Width           =   855
   End
   Begin VB.TextBox Text4 
      Height          =   285
      Left            =   240
      TabIndex        =   24
      Text            =   "Text4"
      Top             =   0
      Visible         =   0   'False
      Width           =   855
   End
   Begin VB.CommandButton Command3 
      Caption         =   "停止(监视/预览)"
      Height          =   495
      Left            =   9600
      TabIndex        =   21
      Top             =   3240
      Width           =   1575
   End
   Begin VB.Frame Frame2 
      Caption         =   "消息回调的参数"
      Height          =   2655
      Left            =   9600
      TabIndex        =   14
      Top             =   240
      Width           =   3015
      Begin VB.TextBox Text3 
         Height          =   375
         Left            =   1080
         TabIndex        =   20
         Text            =   "Text3"
         Top             =   2160
         Width           =   1695
      End
      Begin VB.TextBox Text2 
         Height          =   375
         Left            =   1080
         TabIndex        =   18
         Text            =   "Text2"
         Top             =   1440
         Width           =   1695
      End
      Begin VB.TextBox Text1 
         Height          =   375
         Left            =   1080
         TabIndex        =   16
         Text            =   "Text1"
         Top             =   600
         Width           =   1695
      End
      Begin VB.Label ChDVRIP 
         AutoSize        =   -1  'True
         Caption         =   "ChDVRIP"
         Height          =   195
         Left            =   240
         TabIndex        =   19
         Top             =   2280
         Width           =   690
      End
      Begin VB.Label Buf 
         AutoSize        =   -1  'True
         Caption         =   "Buf"
         Height          =   195
         Left            =   480
         TabIndex        =   17
         Top             =   1560
         Width           =   240
      End
      Begin VB.Label LoginID 
         AutoSize        =   -1  'True
         Caption         =   "LoginID"
         Height          =   195
         Left            =   240
         TabIndex        =   15
         Top             =   720
         Width           =   555
      End
   End
   Begin VB.TextBox SdevCH 
      Height          =   375
      Left            =   5760
      TabIndex        =   12
      Text            =   "Text1"
      Top             =   2640
      Width           =   2415
   End
   Begin VB.Frame Frame1 
      Caption         =   "登录设备"
      Height          =   2295
      Left            =   4680
      TabIndex        =   3
      Top             =   240
      Width           =   4695
      Begin VB.CommandButton Command5 
         Caption         =   "登出"
         Height          =   615
         Left            =   3720
         TabIndex        =   23
         Top             =   1320
         Width           =   855
      End
      Begin VB.CommandButton Command4 
         Caption         =   "登陆"
         Height          =   615
         Left            =   3720
         TabIndex        =   22
         Top             =   360
         Width           =   855
      End
      Begin VB.TextBox SdevPwd 
         Height          =   375
         IMEMode         =   3  'DISABLE
         Left            =   1080
         PasswordChar    =   "*"
         TabIndex        =   11
         Text            =   "Text3"
         Top             =   1680
         Width           =   2535
      End
      Begin VB.TextBox SdevName 
         Height          =   375
         Left            =   1080
         TabIndex        =   10
         Text            =   "Text3"
         Top             =   1200
         Width           =   2535
      End
      Begin VB.TextBox SdevIP 
         Height          =   375
         Left            =   1080
         TabIndex        =   9
         Text            =   "Text3"
         Top             =   240
         Width           =   2535
      End
      Begin VB.TextBox SdevPort 
         Height          =   375
         Left            =   1080
         TabIndex        =   8
         Text            =   "Text3"
         Top             =   720
         Width           =   2535
      End
      Begin VB.Label Label8 
         AutoSize        =   -1  'True
         Caption         =   "密码"
         Height          =   195
         Left            =   240
         TabIndex        =   7
         Top             =   1800
         Width           =   360
      End
      Begin VB.Label Label7 
         AutoSize        =   -1  'True
         Caption         =   "用户名"
         Height          =   195
         Left            =   240
         TabIndex        =   6
         Top             =   1320
         Width           =   540
      End
      Begin VB.Label Label5 
         AutoSize        =   -1  'True
         Caption         =   "设备端口号"
         Height          =   195
         Left            =   120
         TabIndex        =   5
         Top             =   840
         Width           =   900
      End
      Begin VB.Label Label6 
         AutoSize        =   -1  'True
         Caption         =   "设备IP"
         Height          =   195
         Left            =   240
         TabIndex        =   4
         Top             =   360
         Width           =   510
      End
   End
   Begin VB.PictureBox Picture1 
      Height          =   3375
      Left            =   240
      ScaleHeight     =   3315
      ScaleWidth      =   4275
      TabIndex        =   2
      Top             =   360
      Width           =   4335
   End
   Begin VB.CommandButton Command2 
      Caption         =   "退出系统"
      Height          =   495
      Left            =   11280
      TabIndex        =   1
      Top             =   3240
      Width           =   1215
   End
   Begin VB.CommandButton Command1 
      Caption         =   "实时监视"
      Height          =   495
      Left            =   8400
      TabIndex        =   0
      Top             =   2640
      Width           =   855
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "包括哪个通道"
      Height          =   195
      Left            =   6720
      TabIndex        =   26
      Top             =   3120
      Width           =   1320
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "几画面预览"
      Height          =   195
      Left            =   4920
      TabIndex        =   25
      Top             =   3120
      Width           =   1260
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "通道号"
      Height          =   195
      Left            =   4920
      TabIndex        =   13
      Top             =   2760
      Width           =   540
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

'屏蔽主窗体的关闭按钮
Private Declare Function RemoveMenu Lib "user32" (ByVal hMenu As Long, ByVal nPosition As Long, ByVal wFlags As Long) As Long
Private Declare Function GetSystemMenu Lib "user32" (ByVal hwnd As Long, ByVal bRevert As Long) As Long
Private Const MF_BYPOSITION = &H1000&
Private Const SC_CLOSE = &HF060 '关闭
Private Const SC_MAXIMIZE = &HF030 '最大化
Private Const SC_MINIMIZE = &HF020 '最小化

Private bInited, bout As Boolean
Private hLoginId, hMonitorId As Long
Private error As NET_RET_ERROR
Private devInfo As NET_DEVICEINFO
Private dd, longinid As Long



Private Sub Form_Load() '窗体加载
 
On Error GoTo loaderror

RemoveMenu GetSystemMenu(Me.hwnd, 0), SC_CLOSE, MF_BYPOSITION '关闭按钮不可用
 
SdevIP.Text = "10.12.2.60"
SdevPort.Text = "37777"
SdevName.Text = "admin"
SdevPwd.Text = "admin"
SdevCH.Text = "1"
Text1.Text = ""
Text2.Text = ""
Text3.Text = ""
Combo1.AddItem "1", 0
Combo1.AddItem "4", 1
Combo1.AddItem "8", 2
Combo1.AddItem "9", 3
Combo1.AddItem "16", 4
Combo2.AddItem "1", 0
Combo2.AddItem "2", 1
Combo2.AddItem "3", 2
Combo2.AddItem "4", 3
Combo2.AddItem "5", 4
Combo2.AddItem "6", 5
Combo2.AddItem "7", 6
Combo2.AddItem "8", 7
Combo2.AddItem "9", 8
Combo2.AddItem "10", 9
Combo2.AddItem "11", 10
Combo2.AddItem "12", 11
Combo2.AddItem "13", 12
Combo2.AddItem "14", 13
Combo2.AddItem "15", 14
Combo2.AddItem "16", 15

Exit Sub

loaderror:
MsgBox "系统出错1"

End Sub


Private Sub Command3_Click() '停止

On Error Resume Next

If hMonitorId <> 0 Then
    Call CLIENT_StopRealPlayEx(hMonitorId)
    Picture1.Refresh
End If

End Sub
Private Sub Command5_Click() '登出

On Error Resume Next

If hMonitorId <> 0 Then
    Call CLIENT_StopRealPlayEx(hMonitorId)
    Picture1.Refresh
End If

 If hLoginId <> 0 Then
    bout = CLIENT_Logout(hLoginId)
    Call CLIENT_Cleanup
End If

If bout = False Then
    MsgBox "登出设备失败"
    Exit Sub
End If

MsgBox "登出设备成功"

End Sub

Private Sub Command4_Click() '登陆

On Error GoTo loaderror

If SdevIP.Text = "" Then

   MsgBox "请输入IP"
   SdevIP.SetFocus
   Exit Sub
   
End If

If SdevPort.Text = "" Then

   MsgBox "请输入端口"
  SdevPort.SetFocus
   Exit Sub
   
End If

If SdevName.Text = "" Then

   MsgBox "请输入用户名"
   SdevName.SetFocus
   Exit Sub
   
End If

If SdevCH.Text = "" Then

   MsgBox "请输入通道号"
   SdevCH.SetFocus
   Exit Sub
   
End If
   

bInited = CLIENT_Init(PtrToLong(AddressOf IniFunc), 0) '初始化SDK

On Error Resume Next

If (bInited = False) Then
    MsgBox "初始化失败"
    Exit Sub
End If

    hLoginId = CLIENT_Login(SdevIP.Text, SdevPort.Text, SdevName.Text, SdevPwd.Text, devInfo, error) '登陆
     
If (hLoginId = 0) Then
    MsgBox "登陆失败"
    Exit Sub
End If

Text4.Text = hLoginId
MsgBox "登陆成功"

Exit Sub

loaderror:
MsgBox "系统出错2"
   
End Sub

Private Sub Command6_Click() '预览

On Error Resume Next

Dim hMonitorCha As Long
hMonitorCha = 6

If Combo1.Text = "" Then
    MsgBox "请选择预览的画面"
    Exit Sub
End If

If Combo2.Text = "" Then
    MsgBox "请选择预览的通道"
    Exit Sub
End If

If Combo1.Text = 1 Then
    hMonitorCha = 6
End If

If Combo1.Text = 4 Then
    hMonitorCha = 7
End If

If Combo1.Text = 8 Then
    hMonitorCha = 8
End If

If Combo1.Text = 9 Then
    hMonitorCha = 9
End If

If Combo1.Text = 16 Then
    hMonitorCha = 10
End If

If (hMonitorId <> 0) Then
    Call CLIENT_StopRealPlayEx(hMonitorId)
    Picture1.Refresh
End If

If (Text4.Text > 0) Then
    hMonitorId = CLIENT_RealPlayEx(Text4.Text, Combo2.Text, Picture1.hwnd, hMonitorCha)   '实时预览
End If

If (hMonitorId = 0) Then
    MsgBox "实时预览失败"
    Exit Sub
End If

End Sub


Private Sub Command1_Click() '监视


  On Error Resume Next
     
If (Text4.Text > 0) Then
    
    If (hMonitorId <> 0) Then
         Call CLIENT_StopRealPlayEx(hMonitorId)
         Picture1.Refresh
    End If

    hMonitorId = CLIENT_RealPlayEx(Text4.Text, SdevCH.Text, Picture1.hwnd, 0) '实时监视
        
    ElseIf (Text4.Text = 0) Then
    MsgBox "实时监视失败"
    
End If

Call CLIENT_StartListen(hLoginId) '侦听
Call CLIENT_SetDVRMessCallBack(PtrToLong(AddressOf MessFunc), 0) '消息回调
    


End Sub

Private Sub Command2_Click() '退出

On Error Resume Next

If hMonitorId <> 0 Then
    Call CLIENT_StopRealPlayEx(hMonitorId)
    Picture1.Refresh
End If

 If hLoginId <> 0 Then
    Call CLIENT_Logout(hLoginId)
    Call CLIENT_Cleanup
End If


End

End Sub


