Imports MySql.Data.MySqlClient

Public Class IDScan
    Dim GetUserInfoFlag As Boolean = False
    Private Sub IDScan_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Me.BackColor = Color.FromArgb(&HFFF7F7F7)
        ID_SCAN_ZI.Parent = column
        PA_B_B.BackColor = Color.FromArgb(&HFFC5C5C5)
        Count_B.BackColor = Color.FromArgb(&HFFC5C5C5)
    End Sub


    Private Sub getUserInfo()
        If Login.conn.State = ConnectionState.Broken Then
            If Login.ConcectDataIfBreak() Then
                getInfoFromDatabase()
            Else
                '这里填写错误提示信息


            End If
        Else
            getInfoFromDatabase()
        End If
    End Sub


    Private Sub getInfoFromDatabase()
        If GetUserInfoFlag = True Then
            GetUserInfoFlag = False
        End If
        Dim str As String = "select name from user where id = " + ID_I.Text.ToString()
        MsgBox(str)
        Try
            Dim Dr As MySqlCommand = New MySqlCommand(str, Login.conn)
            Dr.CommandType = CommandType.Text
            Dim MR As MySqlDataReader
            MR = Dr.ExecuteReader()
            If MR.HasRows Then
                MR.Read()
                User_name.Text = MR.Item(0).ToString
                GetUserInfoFlag = True
                Exit Sub
            Else
                '这里填写未找到相关会员的信息

                MsgBox("未找到相关会员！")

            End If
        Catch ex As Exception
            MsgBox(ex.ToString)


        End Try
    End Sub

    Private Sub ID_I_TextChanged(sender As Object, e As KeyPressEventArgs) Handles ID_I.KeyPress
        If e.KeyChar = ChrW(13) Then
            If ID_I.Text = "" Then
            Else
                If GetUserInfoFlag = False Then
                    getUserInfo()
                Else
                    Me.Hide()
                    balance.Show()
                End If
            End If



        End If
    End Sub
End Class