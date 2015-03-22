
Imports MySql.Data.MySqlClient
Public Class cash


    Public lineNum As Integer = 1
    Private Sub cash_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        'System.Windows.Forms.Control.CheckForIllegalCrossThreadCalls = False
        Me.Size = New Size(Login.ScreenWidth, Login.ScreenHeight)
        Me.BackColor = Color.FromArgb(&HFFF1F1F1)
        Esc.Parent = column
        F4.Parent = column
        F5.Parent = column

        ALL_M_Back.BackColor = Color.FromArgb(&HFFD7D7D7)
        ALL_M_Back.Size = New Size(230, 65)
        ALL_M_Back.Location = New Point(Me.Width - ALL_M_Back.Width - 10, 56)
        'Me.BackColor = Color.Red
        column.Size = New Size(Me.Width, 40)

        ALLN_Back.BackColor = Color.FromArgb(&HFFD7D7D7)
        ALLN_Back.Size = ALL_M_Back.Size
        ALLN_Back.Location = New Point(ALL_M_Back.Left - ALL_M_Back.Width - 10, 56)


        ID_Back.BackColor = Color.FromArgb(&HFFD7D7D7)
        ID_Back.Size = New Size(ALLN_Back.Left - 15 - ID_Back.Left, 65)

        back_IS.Size = New Size(ID_Back.Width - 6, ID_Back.Height - 4)


        ALL_NUM.Location = New Point(ALLN_Back.Left + 2, ALLN_Back.Top + 2)
        ALL_NUM.Size = New Size(ALL_M_Back.Width - 4, ALL_M_Back.Height - 4)
        ALL_NUM.BackColor = Color.FromArgb(&HFFF1F1F1)

        ALL_Money.BackColor = ALL_NUM.BackColor
        ALL_Money.Size = ALL_NUM.Size
        ALL_Money.Location = New Point(ALL_M_Back.Left + 2, ALL_M_Back.Top + 2)

        ID_P_A_I.BackColor = Color.White
        ID_P_A_I.Location = New Point(back_IS.Left, back_IS.Top + 13)
        ID_P_A_I.Size = New Size(back_IS.Width, ID_P_A_I.Height)

        ' ALL_NUM_zi.Parent = ALLN_Back
        ALL_NUM_zi.Size = New Size(90, ALLN_Back.Height - 4)
        ALL_NUM_zi.Location = New Point(ALLN_Back.Left + 2, ALLN_Back.Top + 2)


        SHU.Location = New Point(ALL_NUM_zi.Left + ALL_NUM_zi.Width, ALLN_Back.Top)
        SHU.Size = New Size(2, ALLN_Back.Height)
        SHU.BackColor = Color.FromArgb(&HFFD7D7D7)

        ALL_N_P.Location = New Point(SHU.Left + 2, ALL_NUM_zi.Top)
        ALL_N_P.Size = New Size(ALLN_Back.Width - ALL_NUM_zi.Width - 6, ALL_NUM_zi.Height)
        ALL_N_P.Text = "0"


        ALL_M_ZI.Size = ALL_NUM_zi.Size
        ALL_M_ZI.Location = New Point(ALL_M_Back.Left + 2, ALL_NUM_zi.Top)

        SHU1.Size = SHU.Size
        SHU1.Location = New Point(ALL_M_ZI.Left + ALL_M_ZI.Width, ALL_M_Back.Top)
        SHU1.BackColor = SHU.BackColor

        ALL_M_P.Size = ALL_N_P.Size
        ALL_M_P.Location = New Point(SHU1.Left + 2, SHU1.Top + 2)
        ALL_M_P.Text = "0"

        Line.BackColor = Color.FromArgb(&HFFD48181)
        Line.Width = Login.ScreenWidth

        Line_num.Parent = column1
        Buy_ID.Parent = column1
        P_Name_.Parent = column1
        p_Unit.Parent = column1
        P_NUM.Parent = column1
        P_Price.Parent = column1
        P_Mon.Parent = column1

        Data.Size = New Size(Login.ScreenWidth, Login.ScreenHeight - 176)
        Data.BackgroundColor = Color.White


        SetLableAndDataGridViewWith()

        'Data.Rows.Add()
        'Data.Rows(0).Cells(0).Value = 1
        'Data.Columns(0).Width = 90
        'Data.Rows(0).Height = 45
        'Data.Rows(0).DefaultCellStyle.BackColor = Color.FromArgb(&HFFF7F7F7)

    End Sub

    Private Sub Esc_Click(sender As Object, e As EventArgs) Handles Esc.Click
        background.Show()
        balance.Show()
    End Sub

    Private Sub Label2_Click(sender As Object, e As EventArgs) Handles F5.Click

    End Sub

    Private Sub F4_Click(sender As Object, e As EventArgs) Handles F4.Click
        background.Show()
        IDScan.Show()
    End Sub

    '设置data以及对应的列标签的宽度
    Private Sub SetLableAndDataGridViewWith()
        Dim rate As Double = Login.ScreenWidth / 1366
        Buy_ID.Width = 366 * rate
        P_Name_.Location = New Point(Buy_ID.Width + 120, 0)
        P_Name_.Size = New Size(200 * rate, 40)

        p_Unit.Location = New Point(P_Name_.Left + P_Name_.Width, 0)
        p_Unit.Size = New Size(160 * rate, 40)

        P_NUM.Location = New Point(p_Unit.Left + p_Unit.Width, 0)
        P_NUM.Size = p_Unit.Size

        P_Price.Location = New Point(P_NUM.Left + P_NUM.Width, 0)
        P_Price.Size = P_NUM.Size

        P_Mon.Location = New Point(P_Price.Left + P_Price.Width, 0)
        P_Mon.Size = P_Name_.Size

        Data.Columns(1).Width = Buy_ID.Width
        Data.Columns(2).Width = P_Name_.Width
        Data.Columns(3).Width = p_Unit.Width
        Data.Columns(4).Width = P_NUM.Width
        Data.Columns(5).Width = P_Price.Width
        Data.Columns(6).Width = P_Mon.Width


    End Sub

    Private Sub ID_P_A_I_TextChanged(sender As Object, e As KeyPressEventArgs) Handles ID_P_A_I.KeyPress
        If Char.IsDigit(e.KeyChar) Or e.KeyChar = "." Or e.KeyChar = Chr(13) Or e.KeyChar = ChrW(27) Or e.KeyChar = ChrW(8) Then
            If e.KeyChar = ChrW(27) And ID_P_A_I.Text.ToString() = "" Then
                'Message.Msg.Text = "即将退出系统，确定退出吗？"
                'If Message.ShowDialog = vbOK Then
                '    Me.Close()
                '    Login.conn.Close()
                '    Login.Close()
                'End If
            End If
            If e.KeyChar = ChrW(13) Then
                If ID_P_A_I.Text = "" Then
                    If ID_P_A_I.Text = "0" Then
                    Else
                        background.Show()
                        IDScan.Show()
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
                If Data.Rows(i).Cells(1).Value.ToString() = ID_P_A_I.Text.ToString() Then
                    Data.Rows(i).Cells(4).Value += 1
                    Data.Rows(i).Cells(6).Value = Data.Rows(i).Cells(5).Value * Data.Rows(i).Cells(4).Value
                    'ID_P_A_I.Text = Data.Rows(i).Cells(1).Value
                    'P_Name.Text = Data.Rows(i).Cells(2).Value
                    'P_NUM.Text = Data.Rows(i).Cells(4).Value
                    changeMoney()
                    calculatePronum()
                    ID_P_A_I.Text = ""
                    Exit Sub
                End If
            Next
            selectFromBaseData()
        End If

    End Sub


    Private Sub Connect()
        Dim connStr As String
        If Not Login.conn Is Nothing Then Login.conn.Close()
        'connStr = String.Format("server={0};user id={1}; password={2}; database=member; pooling=false;charset=utf8", _
        '"112.74.105.67", "ming", "18883285787")

        connStr = String.Format("server={0};user id={1}; password={2}; database=member; pooling=false;charset=utf8", _
        "localhost", "root", "lsw19940816")

        Try
            Login.conn = New MySqlConnection(connStr)
            Login.conn.Open()
            If Login.conn.State = ConnectionState.Open Then

                'CashLogin1()
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


    Private Sub changeMoney()
        Dim money As Integer = 0
        For i = 0 To Data.Rows.Count - 1
            money += Data.Rows(i).Cells(6).Value
        Next
        ALL_M_P.Text = money
    End Sub


    Private Sub calculatePronum()
        Dim Num As Integer = 0
        For i = 0 To Data.Rows.Count - 1
            Num += Data.Rows(i).Cells(4).Value
        Next
        ALL_N_P.Text = Num
    End Sub

    Private Sub selectFromBaseData()
        If ID_P_A_I.Text = "" Then
        Else
            Dim str As String = "select name ,shopID,price from goods where id = " + ID_P_A_I.Text.ToString()
            Dim Dr As MySqlCommand = New MySqlCommand(str, Login.conn)
            Dr.CommandType = CommandType.Text
            Dim MR As MySqlDataReader
            MR = Dr.ExecuteReader()
            Dim temp As String = ""
            Dim flag As Boolean = False
            If MR.HasRows Then
                flag = True
                MR.Read()   '一次读取一行
                Data.Rows.Add()
                Data.Rows(Data.Rows.Count - 1).Height = 45
                Data.Rows(lineNum - 1).Cells(0).Value = lineNum
                Data.Rows(lineNum - 1).Cells(1).Value = ID_P_A_I.Text.ToString()
                Data.Rows(lineNum - 1).Cells(2).Value = MR.Item(0)
                Data.Rows(lineNum - 1).Cells(4).Value = 1
                Data.Rows(lineNum - 1).Cells(5).Value = MR.Item(2)
                Data.Rows(lineNum - 1).Cells(6).Value = MR.Item(2)
                'p_id_p.Text = Data.Rows(lineNum - 1).Cells(1).Value
                'P_Name.Text = Data.Rows(lineNum - 1).Cells(2).Value
                'P_NUM.Text = Data.Rows(lineNum - 1).Cells(4).Value

                If Data.Rows.Count Mod 2 = 0 Then
                    Data.Rows(Data.Rows.Count - 1).DefaultCellStyle.BackColor = Color.FromArgb(&HFFF7F7F7)
                Else
                    Data.Rows(Data.Rows.Count - 1).DefaultCellStyle.BackColor = Color.White
                End If

                temp = MR.Item(1)
                lineNum += 1
                ID_P_A_I.Text = ""
            End If
            MR.Close()
            If flag = True Then
                Data.Rows(lineNum - 2).Cells(3).Value = getshopName(temp) '名称
                changeMoney()
                calculatePronum()
            End If
        End If

    End Sub

    '重新调整datagirdview的颜色
    Private Sub ExchageBackColor(ByVal int As Integer)
        If int >= 1 Then
            For i = int To Data.Rows.Count - 1
                If i Mod 2 = 0 Then
                    Data.Rows(Data.Rows.Count - 1).DefaultCellStyle.BackColor = Color.FromArgb(&HFFF7F7F7)
                Else
                    Data.Rows(Data.Rows.Count - 1).DefaultCellStyle.BackColor = Color.White
                End If
            Next
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



    Private Sub Data_CellContentClick(sender As Object, e As MouseEventArgs) Handles Data.MouseClick
        If Data.Rows.Count Then
            If Data.CurrentCell.ColumnIndex = 4 Then
                Select Case e.Button
                    Case Windows.Forms.MouseButtons.Left
                        Data.Rows(Data.CurrentCell.RowIndex).Cells(4).Value += 1
                        Data.Rows(Data.CurrentCell.RowIndex).Cells(6).Value = Double.Parse(Data.Rows(Data.CurrentCell.RowIndex).Cells(5).Value) * Double.Parse(Data.Rows(Data.CurrentCell.RowIndex).Cells(4).Value)
                        changeMoney()
                        calculatePronum()
                    Case Windows.Forms.MouseButtons.Right
                        If Data.Rows(Data.CurrentCell.RowIndex).Cells(4).Value >= 2 Then
                            Data.Rows(Data.CurrentCell.RowIndex).Cells(4).Value -= 1
                            Data.Rows(Data.CurrentCell.RowIndex).Cells(6).Value = Double.Parse(Data.Rows(Data.CurrentCell.RowIndex).Cells(5).Value) * Double.Parse(Data.Rows(Data.CurrentCell.RowIndex).Cells(4).Value)
                            changeMoney()
                            calculatePronum()
                            Exit Select
                        End If
                        If Data.Rows(Data.CurrentCell.RowIndex).Cells(4).Value = 1 Then
                            ExchageBackColor(Data.CurrentCell.RowIndex)
                            Data.Rows.RemoveAt(Data.CurrentCell.RowIndex)
                            lineNum -= 1
                            changeMoney()
                            calculatePronum()
                        End If
                End Select
            End If
        End If
    End Sub
End Class