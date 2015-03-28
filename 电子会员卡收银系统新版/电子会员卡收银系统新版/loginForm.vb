Imports MySql.Data.MySqlClient
Imports System.Threading
Imports System
Imports System.Xml
Imports System.Security
Imports System.IO



Public Class Login
    '定义显示器的高宽度
    Public ScreenHeight, ScreenWidth As Integer

    Public User, Password As String
    Public conn As New MySqlConnection
    Dim flag As Boolean
    Public data As String
    Dim Sqlconnect As Boolean = False
    '    Dim runThread As Thread
    Dim KeepSqlAliveThread As Thread
    Public shopID As Long = 0


    Public Sub connect()
        ScreenHeight = Screen.PrimaryScreen.Bounds.Height
        ScreenWidth = Screen.PrimaryScreen.Bounds.Width
        Dim connStr As String
        If Not conn Is Nothing Then conn.Close()
        connStr = String.Format("server={0};user id={1}; password={2}; database=member; pooling=false;charset=utf8", _
        "112.74.105.67", "ming", "18883285787")

        'connStr = String.Format("server={0};user id={1}; password={2}; database=member; pooling=false;charset=utf8", _
        '"localhost", "root", "lsw19940816")

        Try
            conn = New MySqlConnection(connStr)
            conn.Open()
            If conn.State = ConnectionState.Open Then
                Sqlconnect = True
                CashLogin1()
            End If
            '    MsgBox("开")
            'Else
            '    MsgBox("关")
            'End If

        Catch ex As MySqlException
            MessageBox.Show("Error connecting to the server: " + ex.Message)
            'runThread.Abort()
        End Try
    End Sub

    Dim temp As Object
    '主界面的加载
    Private Sub Login_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Me.BackColor = Color.FromArgb(&HFFFAFAFA)
        'Me.BackColor = Color.Blue
        'Me.TransparencyKey = Me.BackColor
        ' Me.BackColor = Me.BackColor
        loginButton.BackColor = Color.FromArgb(&HFF72B9E2)
        'key.BackColor = System.Drawing.Color.Transparent
        ID.BackColor = Color.FromArgb(&HFFF6F6F6)
        ID.Text = "请输入账号"
        key.BackColor = Color.FromArgb(&HFFF6F6F6)
        key.Text = "请输入密码"
        '.Show()
        'System.Windows.Forms.Control.CheckForIllegalCrossThreadCalls = False
        shopGet()  'getshop info
    End Sub

    Private Sub loginButton_Press(sender As Object, e As EventArgs) Handles loginButton.MouseDown
        temp = loginButton.BackColor
        loginButton.BackColor = Color.FromArgb(&HFF227FB5)
    End Sub
    Private Sub loginButton_up(sender As Object, e As EventArgs) Handles loginButton.MouseUp
        loginButton.BackColor = temp
    End Sub

    Private Sub shopGet()
        If My.Computer.FileSystem.DirectoryExists(".\config") Then
            'MsgBox("存在")
            'MsgBox(fs.ReadLine())
            'MsgBox(fs.ReadLine)
            If IO.File.Exists(".\config\data.ini") Then
                'here get shopID and shopName
                Dim fsr As New StreamReader(".\config\data.ini")
                Dim temp As String = ""
                temp = fsr.ReadLine()
                'MsgBox(temp)

                If temp = "" Then 'readid
                    Dim Msgform As New MSG
                    Msgform.head.Text = "error"
                    Msgform.msgP.Text = "配置文件丢失，请重新配置"
                    Msgform.Show()
                    Exit Sub
                Else
                    shopID = Long.Parse(temp)
                    'MsgBox(shopID.ToString)
                End If
                temp = fsr.ReadLine()
                'MsgBox(temp)
                If temp = "" Then  'readname
                    Dim Msgform As New MSG
                    Msgform.head.Text = "error"
                    Msgform.msgP.Text = "配置文件丢失，请重新配置"
                    Msgform.Show()
                    Exit Sub
                End If

            Else
                IO.File.Create(".\config\data.ini").Close()
                'save config date into file


            End If
            If IO.File.Exists(".\config\readme.txt") Then
            Else
                IO.File.Create(".\config\readme.txt").Close()
                Dim fsw As New StreamWriter(".\config\readme.txt")
                fsw.WriteLine("this folder for the application configuration,don't move or delete or rewite")
                fsw.Close()
                'save config date into file


            End If

        Else
            My.Computer.FileSystem.CreateDirectory(".\config")
            IO.File.Create(".\config\data.ini").Close()
            IO.File.Create(".\config\readme.txt").Close()
            Dim fsw As New StreamWriter(".\config\readme.txt")
            fsw.WriteLine("this folder for the application configuration,don't move or delete or rewite")
            fsw.Close()
        End If
    End Sub




    Private Sub ID_MouseCaptureChanged(sender As Object, e As EventArgs) Handles ID.MouseCaptureChanged
        If ID.Text = "请输入账号" Then
            ID.Text = ""
        End If
    End Sub

    Private Sub ID_TextChange(sender As Object, e As EventArgs) Handles ID.LostFocus
        If ID.Text = "" Then
            ID.Text = "请输入账号"
        End If

    End Sub

    Private Sub key_MouseCaptureChanged(sender As Object, e As EventArgs) Handles key.MouseCaptureChanged
        If key.Text = "请输入密码" Then
            key.Text = ""
            key.PasswordChar = "･"
        End If
    End Sub

    Private Sub key_LostFocus(sender As Object, e As EventArgs) Handles key.LostFocus
        If key.Text = "" Then
            key.Text = "请输入密码"
            key.PasswordChar = ""
        End If
    End Sub

    Private Sub key_GetFocus(sender As Object, e As EventArgs) Handles key.GotFocus
        If key.Text = "请输入密码" Then
            key.Text = ""
            key.PasswordChar = "･"
        End If
    End Sub

    '创建连接数据库的线程
    Private Sub btnThread_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles loginButton.Click
        invo()
    End Sub


    'invo
    Private Sub invo()
        If Sqlconnect = False Then
            'runThread = New Thread(AddressOf connect)
            'runThread.Start()
            BeginInvoke(New eventhandler(AddressOf connect), Nothing)
        Else
            BeginInvoke(New EventHandler(AddressOf CashLogin1), Nothing)
        End If
    End Sub


    '保持数据库连接的线程
    Private Sub keepSQLAlive()
        KeepSqlAliveThread = New Thread(AddressOf connect)
        KeepSqlAliveThread.Start()
    End Sub


    '获取显示屏的高宽度

    '
    Private Function CasherLogin()
        Dim str As String = "select id from casher where password = " + key.Text.ToString() + " and id = " + ID.Text.ToString + ";"
        Try
            Dim Dr As MySqlCommand = New MySqlCommand(str, conn)
            Dr.CommandType = CommandType.Text
            Dim MR As MySqlDataReader
            MR = Dr.ExecuteReader()
            If MR.HasRows Then
                ' MsgBox(MR.Item(0))
                MR.Close()
                CasherLogin = True
                Exit Function
            End If
            MR.Close()
            CasherLogin = False
        Catch ex As Exception
            'MsgBox(ex.ToString)
            CasherLogin = False
        End Try
    End Function


    Private Sub CashLogin1()
        If CasherLogin() = True Then
            Me.Hide()
            cash.Show()
        Else
            'MSGBOX("请检查你的用户名密码！")
            Dim form As New MSG
            form.head.Text = "检查数据"
            form.msgP.Text = "请检查你的用户名和密码"
            form.Show()
        End If
    End Sub


    Private Sub key_Keypress(sender As Object, e As KeyPressEventArgs) Handles key.KeyPress
        If e.KeyChar = ChrW(13) Then
            invo()
        End If
    End Sub


    Public Function ConcectDataIfBreak()
        Dim connStr As String
        If Not conn Is Nothing Then conn.Close()
        connStr = String.Format("server={0};user id={1}; password={2}; database=member; pooling=false;charset=utf8", _
        "112.74.105.67", "ming", "18883285787")

        'connStr = String.Format("server={0};user id={1}; password={2}; database=member; pooling=false;charset=utf8", _
        '"localhost", "root", "lsw19940816")

        Try
            conn = New MySqlConnection(connStr)
            conn.Open()
            If conn.State = ConnectionState.Open Then
                ConcectDataIfBreak = True
                Exit Function
            End If
            '    MsgBox("开")
            'Else
            '    MsgBox("关")
            'End If

        Catch ex As MySqlException
            MessageBox.Show("Error connecting to the server: " + ex.Message)
            'runThread.Abort()
            ConcectDataIfBreak = False
        End Try
        ConcectDataIfBreak = False
    End Function

    'when esc pressed,windows app close the sql connenction and close itself

    Private Sub form_key(sender As Object, e As KeyEventArgs) Handles Me.KeyDown
        If e.KeyCode = Keys.Escape Then
            Me.Close()
        End If
       
    End Sub
End Class
