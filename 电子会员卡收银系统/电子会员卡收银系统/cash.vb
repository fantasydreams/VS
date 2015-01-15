Imports MySql.Data.MySqlClient

Public Class PURCHASE

    Dim reader As MySql.Data.MySqlClient.MySqlDataReader
    Dim Command As MySql.Data.MySqlClient.MySqlCommand
    Dim comstr As String
    Public lineNum As Integer = 1



    Private Sub cash_Keydown(sender As Object, e As KeyPressEventArgs) Handles P_id_I_B.KeyPress
        If Char.IsDigit(e.KeyChar) Or e.KeyChar = "." Or e.KeyChar = Chr(13) Or e.KeyChar = ChrW(27) Or e.KeyChar = ChrW(8) Then
            If e.KeyChar = ChrW(27) And P_id_I_B.Text.ToString() = "" Then
                Message.Msg.Text = "即将退出系统，确定退出吗？"
                If Message.ShowDialog = vbOK Then
                    Me.Close()
                    Login.conn.Close()
                    Login.Close()
                End If
            End If
            If e.KeyChar = ChrW(13) Then
                If P_id_I_B.Text = "" Then
                    If AllMoney.Text = "0" Then
                    Else
                        code.Show()
                    End If
                Else
                    selectData()
                End If
            End If
        Else
            e.Handled = True
        End If
    End Sub


    Private Sub selectData()
        If Login.conn.State = ConnectionState.Broken Then
            Connect()
        Else
            For i = 0 To Data.Rows.Count - 1
                If Data.Rows(i).Cells(1).Value.ToString() = P_id_I_B.Text.ToString() Then
                    Data.Rows(i).Cells(4).Value += 1
                    Data.Rows(i).Cells(6).Value = Data.Rows(i).Cells(5).Value * Data.Rows(i).Cells(4).Value
                    p_id_p.Text = Data.Rows(i).Cells(1).Value
                    P_Name.Text = Data.Rows(i).Cells(2).Value
                    P_Num.Text = Data.Rows(i).Cells(4).Value
                    changeMoney()
                    calculatePronum()
                    P_id_I_B.Text = ""
                    Exit Sub
                End If
            Next
            selectFromBaseData()
        End If

    End Sub

    Private Sub Connect()
        Dim connStr As String
        If Not Login.conn Is Nothing Then Login.conn.Close()
        connStr = String.Format("server={0};user id={1}; password={2}; database=mysql; pooling=false;charset=utf8", _
        Login.Server.Text, Login.userNameI.Text, Login.passwdI.Text)
        Try
            Login.conn = New MySqlConnection(connStr)
            Login.conn.Open()
            'If conn.State = ConnectionState.Broken Then
            'MsgBox("开")
            'Else
            'MsgBox("关")
            'End If
            Dim str As String = "use " + Login.database.Text
            Dim Dr As MySqlCommand = New MySqlCommand(str, Login.conn)
            Dr.CommandType = CommandType.Text
            Dr.BeginExecuteNonQuery()
        Catch ex As MySqlException
            MessageBox.Show("Error connecting to the server: " + ex.Message)
        End Try
    End Sub

    Private Sub selectFromBaseData()
        If P_id_I_B.Text = "" Then
        Else
            Dim str As String = "select name ,shopID,price from goods where id = " + P_id_I_B.Text.ToString()
            Dim Dr As MySqlCommand = New MySqlCommand(str, Login.conn)
            Dr.CommandType = CommandType.Text
            Dim MR As MySqlDataReader
            MR = Dr.ExecuteReader()
            Dim temp As String
            Dim flag As Boolean = False
            If MR.HasRows Then
                flag = True
                MR.Read()   '一次读取一行
                Data.Rows.Add()
                Data.Rows(lineNum - 1).Cells(0).Value = lineNum
                Data.Rows(lineNum - 1).Cells(1).Value = P_id_I_B.Text.ToString()
                Data.Rows(lineNum - 1).Cells(2).Value = MR.Item(0)
                Data.Rows(lineNum - 1).Cells(4).Value = 1
                Data.Rows(lineNum - 1).Cells(5).Value = MR.Item(2)
                Data.Rows(lineNum - 1).Cells(6).Value = MR.Item(2)
                p_id_p.Text = Data.Rows(lineNum - 1).Cells(1).Value
                P_Name.Text = Data.Rows(lineNum - 1).Cells(2).Value
                P_Num.Text = Data.Rows(lineNum - 1).Cells(4).Value
                temp = MR.Item(1)
                lineNum += 1
                P_id_I_B.Text = ""
            End If
            MR.Close()
            If flag = True Then
                Data.Rows(lineNum - 2).Cells(3).Value = getshopName(temp) '名称
                changeMoney()
                calculatePronum()
            End If
        End If

    End Sub

    Private Function getshopName(ByVal Id As String)
        Dim str As String = "select name from shop where id = " + Id
        Dim Dr As MySqlCommand = New MySqlCommand(str, Login.conn)
        Dr.CommandType = CommandType.Text
        Dim MR As MySqlDataReader
        MR = Dr.ExecuteReader()
        If MR.HasRows Then
            MR.Read()
            getshopName = MR.Item(0)
        Else
            getshopName = ""
        End If
        MR.Close()
    End Function

    Private Sub data_RowsAdded(ByVal sender As Object, ByVal e As DataGridViewRowsAddedEventArgs) Handles Data.RowsAdded
        changeMoney()
        calculatePronum()
    End Sub


    Private Sub changeMoney()
        Dim money As Integer = 0
        For i = 0 To Data.Rows.Count - 1
            money += Data.Rows(i).Cells(6).Value
        Next
        AllMoney.Text = money
    End Sub


    Private Sub calculatePronum()
        Dim Num As Integer = 0
        For i = 0 To Data.Rows.Count - 1
            Num += Data.Rows(i).Cells(4).Value
        Next
        AllNum.Text = Num
    End Sub
    Private Sub data_RowsAdded(ByVal sender As Object, ByVal e As DataGridViewCellEventArgs) Handles Data.CellEndEdit
        Data.Rows(Data.CurrentCell.RowIndex).Cells(6).Value = Integer.Parse(Data.Rows(Data.CurrentCell.RowIndex).Cells(4).Value) * Double.Parse(Data.Rows(Data.CurrentCell.RowIndex).Cells(5).Value)
        P_Num.Text = Data.Rows(Data.CurrentCell.RowIndex).Cells(4).Value

        changeMoney()
        calculatePronum()

    End Sub

    Public EditCell As DataGridViewTextBoxEditingControl

    Private Sub DataGridView1_EditingControlShowing(ByVal sender As Object, ByVal e As System.Windows.Forms.DataGridViewEditingControlShowingEventArgs) Handles Data.EditingControlShowing
        EditCell = CType(e.Control, DataGridViewTextBoxEditingControl)
        EditCell.SelectAll()
        AddHandler EditCell.KeyPress, AddressOf Cells_KeyPress
    End Sub

    Private Sub Cells_KeyPress(ByVal sender As System.Object, ByVal e As KeyPressEventArgs)
        If e.KeyChar <> Chr(8) And e.KeyChar <> Chr(13) And (e.KeyChar < Chr(48) Or e.KeyChar > Chr(57)) Then
            Beep()
            Beep()
            e.KeyChar = Chr(0)
        End If
    End Sub

End Class