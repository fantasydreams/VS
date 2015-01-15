
Imports MySql.Data.MySqlClient

Public Class Login

    Public User, Password As String
    Public conn As New MySqlConnection
    Dim flag As Boolean
    Public data As String
    Private Sub Login_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Server.Hide()
        database.Hide()
        flag = False
    End Sub
    Public Sub connect()
        Dim connStr As String
        If Not conn Is Nothing Then conn.Close()
        connStr = String.Format("server={0};user id={1}; password={2}; database=mysql; pooling=false;charset=utf8", _
        Server.Text, userNameI.Text, passwdI.Text)
        Try
            conn = New MySqlConnection(connStr)
            conn.Open()
            'If conn.State = ConnectionState.Broken Then
            'MsgBox("开")
            'Else
            'MsgBox("关")
            'End If
            chooseDatabase()
        Catch ex As MySqlException
            MessageBox.Show("Error connecting to the server: " + ex.Message)
        End Try
    End Sub

    Private Sub Mon_Click(sender As Object, e As EventArgs) Handles Mon.Click
        User = userNameI.Text.ToString()
        Password = passwdI.Text.ToString()
        ConnectAll()
    End Sub

    Private Sub Caption_Click(sender As Object, e As EventArgs) Handles Caption.DoubleClick
        If flag = False Then
            Server.Show()
            database.Show()
            flag = True
        Else
            Server.Hide()
            database.Hide()
            flag = False
        End If
    End Sub

    Private Sub server_keyPress(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyPressEventArgs) Handles database.KeyPress
        If e.KeyChar = ChrW(13) Then
            Server.Hide()
            database.Hide()
        End If
    End Sub

    Private Sub passwdI_Keypress(sender As Object, e As KeyPressEventArgs) Handles passwdI.KeyPress
        If e.KeyChar = ChrW(13) Then
            ConnectAll()
        End If
    End Sub

    Private Sub chooseDatabase()
        Dim str As String = "show databases"
        Dim Dr As MySqlCommand = New MySqlCommand(str, conn)
        Dr.CommandType = CommandType.Text
        Dim MR As MySqlDataReader
        MR = Dr.ExecuteReader()
        If MR.HasRows Then
            Do While MR.Read()   '一次读取一行
                If MR.Item(0) = database.Text.ToString() Then
                    MR.Close()
                    ChooseBase()
                    Exit Sub
                End If
                '取出当前行的第三个字段的值显示。
            Loop
        End If
        Message.Msg.Text = "没有" + database.Text + "数据库存在!"
        Message.Show()
        MR.Close()
    End Sub

    Private Sub ConnectAll()
        If conn.State = ConnectionState.Closed Then
            connect()
        Else
            chooseDatabase()
        End If
    End Sub


    Private Sub PictureBox3_Click(sender As Object, e As EventArgs) Handles PictureBox3.Click
        User = userNameI.Text.ToString()
        Password = passwdI.Text.ToString()
        ConnectAll()
    End Sub

    Private Sub ChooseBase()
        Dim str As String = "use " + database.Text.ToString
        Dim Dr As MySqlCommand = New MySqlCommand(str, conn)
        Dr.CommandType = CommandType.Text
        Dim Mr As MySqlDataReader
        Try
            Mr = Dr.ExecuteReader()
            Mr.Close()
            Me.Hide()
            PURCHASE.Show()
            Mr.Close()
            data = database.Text.ToString()
        Catch ex As Exception
            MsgBox(ex.Message)
        End Try
    End Sub


End Class
