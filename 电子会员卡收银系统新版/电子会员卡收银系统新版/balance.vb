Imports MySql.Data.MySqlClient


Public Class balance
    Public NumId As String
    Public Max As Double = 0
    Public score As Integer = 0
    Public oldPMP As Double = 0
    Public flag As Boolean = False
    Public flag1 As Boolean = False
    Private Sub balance_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Me.BackColor = Color.FromArgb(&HFFF7F7F7)
        balan.Parent = column

        ALL_M_B.BackColor = Color.FromArgb(&HFFC5C5C5)
        VIP_B.BackColor = Color.FromArgb(&HFFC5C5C5)
        PA_M_B.BackColor = Color.FromArgb(&HFFC5C5C5)
        AC_PA_B.BackColor = Color.FromArgb(&HFFC5C5C5)
        PA_B_B.BackColor = Color.FromArgb(&HFFC5C5C5)

        ALL_M_ZI.BackColor = Color.FromArgb(&HFFF4F4F4)


    End Sub


    Private Sub TextBox1_KeyPress(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyPressEventArgs) Handles AC_P_I.KeyPress
        If Char.IsDigit(e.KeyChar) Or e.KeyChar = "." Or e.KeyChar = Chr(13) Or e.KeyChar = Chr(8) Then
        Else
            e.Handled = True
        End If
        If e.KeyChar = Chr(13) Then
            If AC_P_I.Text = "" Then
            Else
                exchange()
                writetosql()
            End If
        End If
    End Sub

    Private Sub exchange()
        Dim ACPNUM As Double = Double.Parse(AC_P_I.Text.ToString())
        Dim VIPPPNUM As Double = Double.Parse(VIP_M_P.Text.ToString())
        If flag = True Then
            If ACPNUM - Double.Parse(VIP_M_P.Text.ToString()) >= 0 Then
                If oldPMP + ACPNUM - VIPPPNUM <= Max Then
                    Pack_M.Text = oldPMP + ACPNUM - VIPPPNUM
                    Pack_M.Text = "0"
                    flag1 = True
                Else
                    Dim mon As Integer
                    mon = oldPMP + ACPNUM - VIPPPNUM - Max + 1
                    Pack_M.Text = ACPNUM - VIPPPNUM - mon
                    Pack_M.Text = mon
                    flag1 = True
                End If
            Else
                If ACPNUM + oldPMP - VIPPPNUM >= 0 Then
                    Pack_M.Text = ACPNUM + oldPMP - VIPPPNUM
                Else
                    flag1 = False
                    Dim form As New MSG
                    form.head.Text = "警告"
                    form.msgP.Text = "付款金额不足！"
                    form.Show()
                    'Message.Msg.Text = "付款金额不足！"
                    'Message.Show()
                End If

            End If
        Else
            If ACPNUM - VIPPPNUM < 0 Then
                Dim form As New MSG
                form.head.Text = "警告"
                form.msgP.Text = "付款金额不足！"
                form.Show()
                'Message.Msg.Text = "付款金额不足！"
                'Message.Show()
                flag1 = False
            End If

        End If
    End Sub

    Private Sub writetosql()
        If flag = True Then
            Try
                Dim SC As String = score.ToString()
                Dim Num As String = NumId.ToString()
                Dim str As String = "update utos set changes = " + Pack_M.Text.ToString() + ", score = " + SC + " where userID = '" + Num + "'"
                Dim Dr As MySqlCommand = New MySqlCommand(str, Login.conn)
                Dr.CommandType = CommandType.Text
                Dr.BeginExecuteNonQuery()
                Me.Close()
                background.Hide()
            Catch ex As Exception
                MsgBox(ex.Message)
            End Try
        End If
        subStock()
        destory()

    End Sub


    Private Sub Yes_Click(sender As Object, e As EventArgs) Handles Yes.Click
        If flag1 = True Then
            writetosql()
        End If
    End Sub

    Private Sub destory()
        cash.lineNum = 1
        For i = 0 To cash.Data.Rows.Count - 1
            cash.Data.Rows.RemoveAt(0)
        Next
        cash.ALL_M_P.Text = ""
        cash.ALL_N_P.Text = ""
    End Sub


    Private Sub subStock()
        Dim str As String
        For i = 0 To cash.Data.Rows.Count - 1
            Try
                str = "update goods set stock = stock - " + cash.Data.Rows(0).Cells(4).Value.ToString + " where id = " + cash.Data.Rows(0).Cells(1).Value.ToString
                Dim Dr As MySqlCommand = New MySqlCommand(str, Login.conn)
                Dr.CommandType = CommandType.Text
                Dr.BeginExecuteNonQuery()
            Catch ex As Exception
                MsgBox(ex.Message)
            End Try
        Next
        Me.Close()
    End Sub


End Class