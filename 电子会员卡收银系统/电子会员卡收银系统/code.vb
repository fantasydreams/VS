Imports MySql.Data.MySqlClient
Public Class code
    Private Sub TextBox1_TextChanged(sender As Object, e As KeyPressEventArgs) Handles CodeI.KeyPress
        If Char.IsDigit(e.KeyChar) Or e.KeyChar = "." Or e.KeyChar = Chr(13) Then
            If e.KeyChar = ChrW(13) Then
                If CodeI.Text = "" Then
                    Me.Close()
                    Pur.APP.Text = PURCHASE.AllMoney.Text
                    Pur.VIPPP.Text = Pur.APP.Text
                    Pur.PMP.Text = "0"
                    Pur.Show()
                Else
                    If chooseDatabase() = True Then
                        CalculateVipMon()
                        Me.Close()
                        Pur.Show()
                    Else
                        Message.Msg.Text = "没有此会员信息！"
                        CodeI.Text = ""
                        Message.Show()
                    End If
                End If
            End If
        Else
            e.Handled = True
        End If
    End Sub

    Private Function chooseDatabase()
        Dim str As String = "select changes,max,score from utos where userID = " + CodeI.Text
        Dim Dr As MySqlCommand = New MySqlCommand(str, Login.conn)
        Dr.CommandType = CommandType.Text
        Dim MR As MySqlDataReader
        MR = Dr.ExecuteReader()
        If MR.HasRows Then
            MR.Read()
            chooseDatabase = True
            Pur.Max = MR.Item(1)
            Pur.score = Integer.Parse(MR.Item(2).ToString) + Integer.Parse(PURCHASE.AllMoney.Text)
            Pur.PMP.Text = MR.Item(0)
            Pur.oldPMP = Double.Parse(MR.Item(0))
            Pur.NumId = CodeI.Text.ToString()
        Else
            chooseDatabase = False
        End If
        MR.Close()
    End Function

    Public Sub CalculateVipMon()
        Dim Money As Double = 0
        For i = 0 To PURCHASE.Data.Rows.Count - 1
            Dim str As String = "select discount from goods_sale where goodsID = " + PURCHASE.Data.Rows(i).Cells(1).Value.ToString
            Dim Dr As MySqlCommand = New MySqlCommand(str, Login.conn)
            Dr.CommandType = CommandType.Text
            Dim MR As MySqlDataReader
            MR = Dr.ExecuteReader()
            If MR.HasRows Then
                MR.Read()
                Money += Double.Parse(PURCHASE.Data.Rows(i).Cells(6).Value.ToString()) * Double.Parse(MR.Item(0).ToString())
            Else
                Money += Double.Parse(PURCHASE.Data.Rows(i).Cells(6).Value.ToString())
            End If
            MR.Close()
        Next
        Pur.VIPPP.Text = Money
        Pur.APP.Text = PURCHASE.AllMoney.Text
        Pur.flag = True
    End Sub

End Class