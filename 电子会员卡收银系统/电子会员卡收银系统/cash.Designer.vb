<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class PURCHASE
    Inherits System.Windows.Forms.Form

    'Form 重写 Dispose，以清理组件列表。
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Windows 窗体设计器所必需的
    Private components As System.ComponentModel.IContainer

    '注意:  以下过程是 Windows 窗体设计器所必需的
    '可以使用 Windows 窗体设计器修改它。  
    '不要使用代码编辑器修改它。
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Dim DataGridViewCellStyle1 As System.Windows.Forms.DataGridViewCellStyle = New System.Windows.Forms.DataGridViewCellStyle()
        Dim DataGridViewCellStyle2 As System.Windows.Forms.DataGridViewCellStyle = New System.Windows.Forms.DataGridViewCellStyle()
        Dim DataGridViewCellStyle3 As System.Windows.Forms.DataGridViewCellStyle = New System.Windows.Forms.DataGridViewCellStyle()
        Dim DataGridViewCellStyle4 As System.Windows.Forms.DataGridViewCellStyle = New System.Windows.Forms.DataGridViewCellStyle()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(PURCHASE))
        Me.tips = New System.Windows.Forms.Label()
        Me.P_id = New System.Windows.Forms.Label()
        Me.P_id_I_B = New System.Windows.Forms.TextBox()
        Me.p_id_p = New System.Windows.Forms.Label()
        Me.P_Name = New System.Windows.Forms.Label()
        Me.P_Num = New System.Windows.Forms.Label()
        Me.All_P_Num = New System.Windows.Forms.Label()
        Me.AllNum = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.AllMoney = New System.Windows.Forms.Label()
        Me.Data = New System.Windows.Forms.DataGridView()
        Me.line = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.num = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.names = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.company = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.number = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.price = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.Money = New System.Windows.Forms.DataGridViewTextBoxColumn()
        CType(Me.Data, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'tips
        '
        Me.tips.Font = New System.Drawing.Font("新宋体", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.tips.ForeColor = System.Drawing.SystemColors.MenuHighlight
        Me.tips.Location = New System.Drawing.Point(0, 0)
        Me.tips.Name = "tips"
        Me.tips.Size = New System.Drawing.Size(434, 34)
        Me.tips.TabIndex = 0
        Me.tips.Text = "  esc 返回 F4 重置 F5 恢复"
        Me.tips.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'P_id
        '
        Me.P_id.BackColor = System.Drawing.SystemColors.ScrollBar
        Me.P_id.Font = New System.Drawing.Font("宋体", 42.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.P_id.ForeColor = System.Drawing.SystemColors.HotTrack
        Me.P_id.Location = New System.Drawing.Point(0, 40)
        Me.P_id.Name = "P_id"
        Me.P_id.Size = New System.Drawing.Size(180, 70)
        Me.P_id.TabIndex = 1
        Me.P_id.Text = "编码"
        Me.P_id.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'P_id_I_B
        '
        Me.P_id_I_B.Font = New System.Drawing.Font("宋体", 42.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.P_id_I_B.Location = New System.Drawing.Point(180, 40)
        Me.P_id_I_B.Name = "P_id_I_B"
        Me.P_id_I_B.Size = New System.Drawing.Size(1185, 71)
        Me.P_id_I_B.TabIndex = 2
        '
        'p_id_p
        '
        Me.p_id_p.BackColor = System.Drawing.Color.White
        Me.p_id_p.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.p_id_p.Font = New System.Drawing.Font("宋体", 36.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.p_id_p.Location = New System.Drawing.Point(2, 567)
        Me.p_id_p.Name = "p_id_p"
        Me.p_id_p.Size = New System.Drawing.Size(375, 50)
        Me.p_id_p.TabIndex = 3
        Me.p_id_p.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'P_Name
        '
        Me.P_Name.BackColor = System.Drawing.Color.White
        Me.P_Name.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.P_Name.Font = New System.Drawing.Font("宋体", 36.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.P_Name.Location = New System.Drawing.Point(399, 567)
        Me.P_Name.Name = "P_Name"
        Me.P_Name.Size = New System.Drawing.Size(375, 50)
        Me.P_Name.TabIndex = 4
        Me.P_Name.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'P_Num
        '
        Me.P_Num.BackColor = System.Drawing.Color.White
        Me.P_Num.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.P_Num.Font = New System.Drawing.Font("宋体", 36.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.P_Num.Location = New System.Drawing.Point(850, 567)
        Me.P_Num.Name = "P_Num"
        Me.P_Num.Size = New System.Drawing.Size(375, 50)
        Me.P_Num.TabIndex = 5
        Me.P_Num.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'All_P_Num
        '
        Me.All_P_Num.Font = New System.Drawing.Font("宋体", 24.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.All_P_Num.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.All_P_Num.Location = New System.Drawing.Point(574, 671)
        Me.All_P_Num.Name = "All_P_Num"
        Me.All_P_Num.Size = New System.Drawing.Size(200, 40)
        Me.All_P_Num.TabIndex = 6
        Me.All_P_Num.Text = "合计数量"
        Me.All_P_Num.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'AllNum
        '
        Me.AllNum.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.AllNum.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.AllNum.Font = New System.Drawing.Font("宋体", 26.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.AllNum.ForeColor = System.Drawing.Color.Red
        Me.AllNum.Location = New System.Drawing.Point(792, 671)
        Me.AllNum.Name = "AllNum"
        Me.AllNum.Size = New System.Drawing.Size(97, 40)
        Me.AllNum.TabIndex = 7
        Me.AllNum.Text = "0"
        Me.AllNum.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Label2
        '
        Me.Label2.Font = New System.Drawing.Font("宋体", 24.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Label2.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.Label2.Location = New System.Drawing.Point(958, 671)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(99, 40)
        Me.Label2.TabIndex = 8
        Me.Label2.Text = "金额"
        Me.Label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'AllMoney
        '
        Me.AllMoney.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.AllMoney.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.AllMoney.Font = New System.Drawing.Font("宋体", 26.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.AllMoney.ForeColor = System.Drawing.Color.Red
        Me.AllMoney.Location = New System.Drawing.Point(1063, 671)
        Me.AllMoney.Name = "AllMoney"
        Me.AllMoney.Size = New System.Drawing.Size(228, 40)
        Me.AllMoney.TabIndex = 9
        Me.AllMoney.Text = "0"
        Me.AllMoney.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        'Data
        '
        Me.Data.AllowUserToAddRows = False
        Me.Data.AllowUserToDeleteRows = False
        Me.Data.BackgroundColor = System.Drawing.SystemColors.ButtonFace
        DataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter
        DataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Control
        DataGridViewCellStyle1.Font = New System.Drawing.Font("宋体", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        DataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.WindowText
        DataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight
        DataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText
        DataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.[True]
        Me.Data.ColumnHeadersDefaultCellStyle = DataGridViewCellStyle1
        Me.Data.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize
        Me.Data.Columns.AddRange(New System.Windows.Forms.DataGridViewColumn() {Me.line, Me.num, Me.names, Me.company, Me.number, Me.price, Me.Money})
        DataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter
        DataGridViewCellStyle2.BackColor = System.Drawing.SystemColors.Window
        DataGridViewCellStyle2.Font = New System.Drawing.Font("宋体", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        DataGridViewCellStyle2.ForeColor = System.Drawing.SystemColors.ControlText
        DataGridViewCellStyle2.SelectionBackColor = System.Drawing.SystemColors.Highlight
        DataGridViewCellStyle2.SelectionForeColor = System.Drawing.SystemColors.HighlightText
        DataGridViewCellStyle2.WrapMode = System.Windows.Forms.DataGridViewTriState.[False]
        Me.Data.DefaultCellStyle = DataGridViewCellStyle2
        Me.Data.Location = New System.Drawing.Point(2, 125)
        Me.Data.Name = "Data"
        DataGridViewCellStyle3.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter
        DataGridViewCellStyle3.BackColor = System.Drawing.SystemColors.Control
        DataGridViewCellStyle3.Font = New System.Drawing.Font("宋体", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        DataGridViewCellStyle3.ForeColor = System.Drawing.SystemColors.WindowText
        DataGridViewCellStyle3.SelectionBackColor = System.Drawing.SystemColors.Highlight
        DataGridViewCellStyle3.SelectionForeColor = System.Drawing.SystemColors.HighlightText
        DataGridViewCellStyle3.WrapMode = System.Windows.Forms.DataGridViewTriState.[True]
        Me.Data.RowHeadersDefaultCellStyle = DataGridViewCellStyle3
        DataGridViewCellStyle4.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter
        Me.Data.RowsDefaultCellStyle = DataGridViewCellStyle4
        Me.Data.RowTemplate.Height = 23
        Me.Data.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.CellSelect
        Me.Data.Size = New System.Drawing.Size(1363, 430)
        Me.Data.TabIndex = 10
        '
        'line
        '
        Me.line.HeaderText = "行号"
        Me.line.Name = "line"
        Me.line.ReadOnly = True
        Me.line.Width = 180
        '
        'num
        '
        Me.num.HeaderText = "销售码"
        Me.num.Name = "num"
        Me.num.Resizable = System.Windows.Forms.DataGridViewTriState.[False]
        Me.num.Width = 210
        '
        'names
        '
        Me.names.HeaderText = "名称"
        Me.names.Name = "names"
        Me.names.ReadOnly = True
        Me.names.Width = 210
        '
        'company
        '
        Me.company.HeaderText = "单位"
        Me.company.Name = "company"
        Me.company.ReadOnly = True
        Me.company.Width = 180
        '
        'number
        '
        Me.number.HeaderText = "数量"
        Me.number.Name = "number"
        Me.number.Width = 180
        '
        'price
        '
        Me.price.HeaderText = "单价"
        Me.price.Name = "price"
        Me.price.ReadOnly = True
        Me.price.Width = 180
        '
        'Money
        '
        Me.Money.HeaderText = "金额"
        Me.Money.Name = "Money"
        Me.Money.ReadOnly = True
        Me.Money.Width = 180
        '
        'PURCHASE
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(1366, 768)
        Me.Controls.Add(Me.Data)
        Me.Controls.Add(Me.AllMoney)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.AllNum)
        Me.Controls.Add(Me.All_P_Num)
        Me.Controls.Add(Me.P_Num)
        Me.Controls.Add(Me.P_Name)
        Me.Controls.Add(Me.p_id_p)
        Me.Controls.Add(Me.P_id_I_B)
        Me.Controls.Add(Me.P_id)
        Me.Controls.Add(Me.tips)
        Me.DoubleBuffered = True
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.Name = "PURCHASE"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "cash"
        Me.WindowState = System.Windows.Forms.FormWindowState.Maximized
        CType(Me.Data, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents tips As System.Windows.Forms.Label
    Friend WithEvents P_id As System.Windows.Forms.Label
    Friend WithEvents P_id_I_B As System.Windows.Forms.TextBox
    Friend WithEvents p_id_p As System.Windows.Forms.Label
    Friend WithEvents P_Name As System.Windows.Forms.Label
    Friend WithEvents P_Num As System.Windows.Forms.Label
    Friend WithEvents All_P_Num As System.Windows.Forms.Label
    Friend WithEvents AllNum As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents AllMoney As System.Windows.Forms.Label
    Friend WithEvents Data As System.Windows.Forms.DataGridView
    Friend WithEvents line As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents num As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents names As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents company As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents number As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents price As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents Money As System.Windows.Forms.DataGridViewTextBoxColumn
End Class
