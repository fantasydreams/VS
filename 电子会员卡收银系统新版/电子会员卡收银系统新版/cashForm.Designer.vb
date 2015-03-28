Imports SuperDataGrid.SuperDataGrid


<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class cash
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(cash))
        Dim DataGridViewCellStyle1 As System.Windows.Forms.DataGridViewCellStyle = New System.Windows.Forms.DataGridViewCellStyle()
        Dim DataGridViewCellStyle2 As System.Windows.Forms.DataGridViewCellStyle = New System.Windows.Forms.DataGridViewCellStyle()
        Dim DataGridViewCellStyle3 As System.Windows.Forms.DataGridViewCellStyle = New System.Windows.Forms.DataGridViewCellStyle()
        Dim DataGridViewCellStyle4 As System.Windows.Forms.DataGridViewCellStyle = New System.Windows.Forms.DataGridViewCellStyle()
        Dim DataGridViewCellStyle5 As System.Windows.Forms.DataGridViewCellStyle = New System.Windows.Forms.DataGridViewCellStyle()
        Me.column = New System.Windows.Forms.PictureBox()
        Me.ProIDzi = New System.Windows.Forms.Label()
        Me.Esc = New System.Windows.Forms.Label()
        Me.F4 = New System.Windows.Forms.Label()
        Me.F5 = New System.Windows.Forms.Label()
        Me.ID_Back = New System.Windows.Forms.Label()
        Me.ALLN_Back = New System.Windows.Forms.Label()
        Me.ALL_M_Back = New System.Windows.Forms.Label()
        Me.back_IS = New System.Windows.Forms.Label()
        Me.ALL_NUM = New System.Windows.Forms.Label()
        Me.ALL_Money = New System.Windows.Forms.Label()
        Me.ID_P_A_I = New System.Windows.Forms.TextBox()
        Me.ALL_NUM_zi = New System.Windows.Forms.Label()
        Me.SHU = New System.Windows.Forms.Label()
        Me.ALL_N_P = New System.Windows.Forms.Label()
        Me.ALL_M_ZI = New System.Windows.Forms.Label()
        Me.SHU1 = New System.Windows.Forms.Label()
        Me.ALL_M_P = New System.Windows.Forms.Label()
        Me.column1 = New System.Windows.Forms.PictureBox()
        Me.Data = New System.Windows.Forms.DataGridView()
        Me.List_Num = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.B_ID = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.P_Name = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.unit = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.Num = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.price = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.Money = New System.Windows.Forms.DataGridViewTextBoxColumn()
        Me.Line_num = New System.Windows.Forms.Label()
        Me.Buy_ID = New System.Windows.Forms.Label()
        Me.P_Name_ = New System.Windows.Forms.Label()
        Me.p_Unit = New System.Windows.Forms.Label()
        Me.P_NUM = New System.Windows.Forms.Label()
        Me.P_Price = New System.Windows.Forms.Label()
        Me.P_Mon = New System.Windows.Forms.Label()
        Me.Line = New System.Windows.Forms.Label()
        CType(Me.column, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.column1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Data, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'column
        '
        Me.column.BackColor = System.Drawing.SystemColors.Control
        Me.column.Image = CType(resources.GetObject("column.Image"), System.Drawing.Image)
        Me.column.Location = New System.Drawing.Point(0, 0)
        Me.column.Name = "column"
        Me.column.Size = New System.Drawing.Size(1366, 40)
        Me.column.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.column.TabIndex = 0
        Me.column.TabStop = False
        '
        'ProIDzi
        '
        Me.ProIDzi.Font = New System.Drawing.Font("幼圆", 36.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.ProIDzi.ForeColor = System.Drawing.Color.DimGray
        Me.ProIDzi.Location = New System.Drawing.Point(0, 41)
        Me.ProIDzi.Name = "ProIDzi"
        Me.ProIDzi.Size = New System.Drawing.Size(175, 95)
        Me.ProIDzi.TabIndex = 3
        Me.ProIDzi.Text = "条形码"
        Me.ProIDzi.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Esc
        '
        Me.Esc.BackColor = System.Drawing.Color.Transparent
        Me.Esc.Font = New System.Drawing.Font("幼圆", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Esc.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.Esc.Location = New System.Drawing.Point(0, 0)
        Me.Esc.Name = "Esc"
        Me.Esc.Size = New System.Drawing.Size(150, 40)
        Me.Esc.TabIndex = 4
        Me.Esc.Text = "ESC 返回"
        Me.Esc.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'F4
        '
        Me.F4.BackColor = System.Drawing.Color.Transparent
        Me.F4.Font = New System.Drawing.Font("幼圆", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.F4.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.F4.Location = New System.Drawing.Point(150, 0)
        Me.F4.Name = "F4"
        Me.F4.Size = New System.Drawing.Size(100, 40)
        Me.F4.TabIndex = 5
        Me.F4.Text = "F4重置"
        Me.F4.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'F5
        '
        Me.F5.BackColor = System.Drawing.Color.Transparent
        Me.F5.Font = New System.Drawing.Font("幼圆", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.F5.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.F5.Location = New System.Drawing.Point(250, 0)
        Me.F5.Name = "F5"
        Me.F5.Size = New System.Drawing.Size(130, 40)
        Me.F5.TabIndex = 6
        Me.F5.Text = "F5撤销"
        Me.F5.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'ID_Back
        '
        Me.ID_Back.Location = New System.Drawing.Point(175, 56)
        Me.ID_Back.Name = "ID_Back"
        Me.ID_Back.Size = New System.Drawing.Size(100, 65)
        Me.ID_Back.TabIndex = 7
        '
        'ALLN_Back
        '
        Me.ALLN_Back.Location = New System.Drawing.Point(610, 65)
        Me.ALLN_Back.Name = "ALLN_Back"
        Me.ALLN_Back.Size = New System.Drawing.Size(100, 53)
        Me.ALLN_Back.TabIndex = 8
        '
        'ALL_M_Back
        '
        Me.ALL_M_Back.Location = New System.Drawing.Point(779, 65)
        Me.ALL_M_Back.Name = "ALL_M_Back"
        Me.ALL_M_Back.Size = New System.Drawing.Size(104, 53)
        Me.ALL_M_Back.TabIndex = 9
        '
        'back_IS
        '
        Me.back_IS.BackColor = System.Drawing.SystemColors.ButtonHighlight
        Me.back_IS.Location = New System.Drawing.Point(178, 58)
        Me.back_IS.Name = "back_IS"
        Me.back_IS.Size = New System.Drawing.Size(100, 61)
        Me.back_IS.TabIndex = 10
        '
        'ALL_NUM
        '
        Me.ALL_NUM.Font = New System.Drawing.Font("宋体", 24.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.ALL_NUM.Location = New System.Drawing.Point(565, 58)
        Me.ALL_NUM.Name = "ALL_NUM"
        Me.ALL_NUM.Size = New System.Drawing.Size(95, 49)
        Me.ALL_NUM.TabIndex = 11
        Me.ALL_NUM.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'ALL_Money
        '
        Me.ALL_Money.Location = New System.Drawing.Point(726, 58)
        Me.ALL_Money.Name = "ALL_Money"
        Me.ALL_Money.Size = New System.Drawing.Size(95, 49)
        Me.ALL_Money.TabIndex = 12
        '
        'ID_P_A_I
        '
        Me.ID_P_A_I.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.ID_P_A_I.Font = New System.Drawing.Font("宋体", 26.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.ID_P_A_I.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.ID_P_A_I.Location = New System.Drawing.Point(178, 67)
        Me.ID_P_A_I.Name = "ID_P_A_I"
        Me.ID_P_A_I.Size = New System.Drawing.Size(100, 40)
        Me.ID_P_A_I.TabIndex = 13
        '
        'ALL_NUM_zi
        '
        Me.ALL_NUM_zi.BackColor = System.Drawing.Color.Transparent
        Me.ALL_NUM_zi.Font = New System.Drawing.Font("宋体", 18.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.ALL_NUM_zi.Location = New System.Drawing.Point(610, 67)
        Me.ALL_NUM_zi.Name = "ALL_NUM_zi"
        Me.ALL_NUM_zi.Size = New System.Drawing.Size(90, 50)
        Me.ALL_NUM_zi.TabIndex = 14
        Me.ALL_NUM_zi.Text = "总数量"
        Me.ALL_NUM_zi.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'SHU
        '
        Me.SHU.Location = New System.Drawing.Point(700, 65)
        Me.SHU.Name = "SHU"
        Me.SHU.Size = New System.Drawing.Size(2, 65)
        Me.SHU.TabIndex = 15
        '
        'ALL_N_P
        '
        Me.ALL_N_P.BackColor = System.Drawing.Color.White
        Me.ALL_N_P.Font = New System.Drawing.Font("宋体", 18.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.ALL_N_P.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.ALL_N_P.Location = New System.Drawing.Point(706, 67)
        Me.ALL_N_P.Name = "ALL_N_P"
        Me.ALL_N_P.Size = New System.Drawing.Size(100, 61)
        Me.ALL_N_P.TabIndex = 16
        Me.ALL_N_P.Text = "0"
        Me.ALL_N_P.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'ALL_M_ZI
        '
        Me.ALL_M_ZI.BackColor = System.Drawing.Color.Transparent
        Me.ALL_M_ZI.Font = New System.Drawing.Font("宋体", 18.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.ALL_M_ZI.Location = New System.Drawing.Point(806, 67)
        Me.ALL_M_ZI.Name = "ALL_M_ZI"
        Me.ALL_M_ZI.Size = New System.Drawing.Size(90, 50)
        Me.ALL_M_ZI.TabIndex = 17
        Me.ALL_M_ZI.Text = "总金额"
        Me.ALL_M_ZI.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'SHU1
        '
        Me.SHU1.Location = New System.Drawing.Point(915, 67)
        Me.SHU1.Name = "SHU1"
        Me.SHU1.Size = New System.Drawing.Size(2, 65)
        Me.SHU1.TabIndex = 18
        '
        'ALL_M_P
        '
        Me.ALL_M_P.BackColor = System.Drawing.Color.White
        Me.ALL_M_P.Font = New System.Drawing.Font("宋体", 18.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.ALL_M_P.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.ALL_M_P.Location = New System.Drawing.Point(944, 69)
        Me.ALL_M_P.Name = "ALL_M_P"
        Me.ALL_M_P.Size = New System.Drawing.Size(100, 61)
        Me.ALL_M_P.TabIndex = 19
        Me.ALL_M_P.Text = "0"
        Me.ALL_M_P.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'column1
        '
        Me.column1.BackColor = System.Drawing.SystemColors.Control
        Me.column1.Image = CType(resources.GetObject("column1.Image"), System.Drawing.Image)
        Me.column1.Location = New System.Drawing.Point(0, 136)
        Me.column1.Name = "column1"
        Me.column1.Size = New System.Drawing.Size(1366, 40)
        Me.column1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.column1.TabIndex = 20
        Me.column1.TabStop = False
        '
        'Data
        '
        Me.Data.AllowUserToAddRows = False
        Me.Data.AllowUserToDeleteRows = False
        Me.Data.AllowUserToResizeColumns = False
        Me.Data.AllowUserToResizeRows = False
        DataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter
        DataGridViewCellStyle1.BackColor = System.Drawing.Color.White
        DataGridViewCellStyle1.ForeColor = System.Drawing.Color.FromArgb(CType(CType(64, Byte), Integer), CType(CType(64, Byte), Integer), CType(CType(64, Byte), Integer))
        DataGridViewCellStyle1.SelectionBackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer))
        DataGridViewCellStyle1.SelectionForeColor = System.Drawing.Color.FromArgb(CType(CType(64, Byte), Integer), CType(CType(64, Byte), Integer), CType(CType(64, Byte), Integer))
        Me.Data.AlternatingRowsDefaultCellStyle = DataGridViewCellStyle1
        Me.Data.BackgroundColor = System.Drawing.Color.White
        Me.Data.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.Data.CellBorderStyle = System.Windows.Forms.DataGridViewCellBorderStyle.None
        Me.Data.ClipboardCopyMode = System.Windows.Forms.DataGridViewClipboardCopyMode.Disable
        Me.Data.ColumnHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.None
        DataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter
        DataGridViewCellStyle2.BackColor = System.Drawing.SystemColors.Control
        DataGridViewCellStyle2.Font = New System.Drawing.Font("幼圆", 18.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        DataGridViewCellStyle2.ForeColor = System.Drawing.SystemColors.WindowText
        DataGridViewCellStyle2.SelectionBackColor = System.Drawing.SystemColors.Highlight
        DataGridViewCellStyle2.SelectionForeColor = System.Drawing.SystemColors.HighlightText
        DataGridViewCellStyle2.WrapMode = System.Windows.Forms.DataGridViewTriState.[True]
        Me.Data.ColumnHeadersDefaultCellStyle = DataGridViewCellStyle2
        Me.Data.ColumnHeadersHeight = 40
        Me.Data.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.DisableResizing
        Me.Data.ColumnHeadersVisible = False
        Me.Data.Columns.AddRange(New System.Windows.Forms.DataGridViewColumn() {Me.List_Num, Me.B_ID, Me.P_Name, Me.unit, Me.Num, Me.price, Me.Money})
        DataGridViewCellStyle3.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter
        DataGridViewCellStyle3.BackColor = System.Drawing.SystemColors.Window
        DataGridViewCellStyle3.Font = New System.Drawing.Font("幼圆", 18.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        DataGridViewCellStyle3.ForeColor = System.Drawing.SystemColors.ControlText
        DataGridViewCellStyle3.SelectionBackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer), CType(CType(192, Byte), Integer))
        DataGridViewCellStyle3.SelectionForeColor = System.Drawing.SystemColors.ControlDarkDark
        DataGridViewCellStyle3.WrapMode = System.Windows.Forms.DataGridViewTriState.[False]
        Me.Data.DefaultCellStyle = DataGridViewCellStyle3
        Me.Data.GridColor = System.Drawing.Color.White
        Me.Data.Location = New System.Drawing.Point(0, 176)
        Me.Data.Name = "Data"
        Me.Data.ReadOnly = True
        Me.Data.RowHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.None
        DataGridViewCellStyle4.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter
        DataGridViewCellStyle4.BackColor = System.Drawing.SystemColors.Control
        DataGridViewCellStyle4.Font = New System.Drawing.Font("幼圆", 18.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        DataGridViewCellStyle4.ForeColor = System.Drawing.SystemColors.WindowText
        DataGridViewCellStyle4.SelectionBackColor = System.Drawing.SystemColors.Highlight
        DataGridViewCellStyle4.SelectionForeColor = System.Drawing.SystemColors.HighlightText
        DataGridViewCellStyle4.WrapMode = System.Windows.Forms.DataGridViewTriState.[True]
        Me.Data.RowHeadersDefaultCellStyle = DataGridViewCellStyle4
        Me.Data.RowHeadersWidth = 30
        Me.Data.RowHeadersWidthSizeMode = System.Windows.Forms.DataGridViewRowHeadersWidthSizeMode.DisableResizing
        DataGridViewCellStyle5.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter
        Me.Data.RowsDefaultCellStyle = DataGridViewCellStyle5
        Me.Data.RowTemplate.Height = 23
        Me.Data.ScrollBars = System.Windows.Forms.ScrollBars.Horizontal
        Me.Data.Size = New System.Drawing.Size(1366, 600)
        Me.Data.TabIndex = 21
        '
        'List_Num
        '
        Me.List_Num.HeaderText = "序号"
        Me.List_Num.Name = "List_Num"
        Me.List_Num.ReadOnly = True
        '
        'B_ID
        '
        Me.B_ID.HeaderText = "销售码"
        Me.B_ID.Name = "B_ID"
        Me.B_ID.ReadOnly = True
        '
        'P_Name
        '
        Me.P_Name.HeaderText = "品名"
        Me.P_Name.Name = "P_Name"
        Me.P_Name.ReadOnly = True
        '
        'unit
        '
        Me.unit.HeaderText = "单位"
        Me.unit.Name = "unit"
        Me.unit.ReadOnly = True
        '
        'Num
        '
        Me.Num.HeaderText = "数量"
        Me.Num.Name = "Num"
        Me.Num.ReadOnly = True
        '
        'price
        '
        Me.price.HeaderText = "单价"
        Me.price.Name = "price"
        Me.price.ReadOnly = True
        '
        'Money
        '
        Me.Money.HeaderText = "金额"
        Me.Money.Name = "Money"
        Me.Money.ReadOnly = True
        '
        'Line_num
        '
        Me.Line_num.BackColor = System.Drawing.Color.Transparent
        Me.Line_num.Font = New System.Drawing.Font("幼圆", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Line_num.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.Line_num.Location = New System.Drawing.Point(20, 0)
        Me.Line_num.Name = "Line_num"
        Me.Line_num.Size = New System.Drawing.Size(100, 40)
        Me.Line_num.TabIndex = 22
        Me.Line_num.Text = "序号"
        Me.Line_num.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Buy_ID
        '
        Me.Buy_ID.BackColor = System.Drawing.Color.Transparent
        Me.Buy_ID.Font = New System.Drawing.Font("幼圆", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Buy_ID.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.Buy_ID.Location = New System.Drawing.Point(120, 0)
        Me.Buy_ID.Name = "Buy_ID"
        Me.Buy_ID.Size = New System.Drawing.Size(366, 40)
        Me.Buy_ID.TabIndex = 23
        Me.Buy_ID.Text = "销售码"
        Me.Buy_ID.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'P_Name_
        '
        Me.P_Name_.BackColor = System.Drawing.Color.Transparent
        Me.P_Name_.Font = New System.Drawing.Font("幼圆", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.P_Name_.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.P_Name_.Location = New System.Drawing.Point(486, 0)
        Me.P_Name_.Name = "P_Name_"
        Me.P_Name_.Size = New System.Drawing.Size(200, 40)
        Me.P_Name_.TabIndex = 24
        Me.P_Name_.Text = "品名"
        Me.P_Name_.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'p_Unit
        '
        Me.p_Unit.BackColor = System.Drawing.Color.Transparent
        Me.p_Unit.Font = New System.Drawing.Font("幼圆", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.p_Unit.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.p_Unit.Location = New System.Drawing.Point(686, 0)
        Me.p_Unit.Name = "p_Unit"
        Me.p_Unit.Size = New System.Drawing.Size(160, 40)
        Me.p_Unit.TabIndex = 25
        Me.p_Unit.Text = "单位"
        Me.p_Unit.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'P_NUM
        '
        Me.P_NUM.BackColor = System.Drawing.Color.Transparent
        Me.P_NUM.Font = New System.Drawing.Font("幼圆", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.P_NUM.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.P_NUM.Location = New System.Drawing.Point(846, 0)
        Me.P_NUM.Name = "P_NUM"
        Me.P_NUM.Size = New System.Drawing.Size(160, 40)
        Me.P_NUM.TabIndex = 26
        Me.P_NUM.Text = "数量"
        Me.P_NUM.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'P_Price
        '
        Me.P_Price.BackColor = System.Drawing.Color.Transparent
        Me.P_Price.Font = New System.Drawing.Font("幼圆", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.P_Price.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.P_Price.Location = New System.Drawing.Point(1006, 0)
        Me.P_Price.Name = "P_Price"
        Me.P_Price.Size = New System.Drawing.Size(160, 40)
        Me.P_Price.TabIndex = 27
        Me.P_Price.Text = "单价"
        Me.P_Price.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'P_Mon
        '
        Me.P_Mon.BackColor = System.Drawing.Color.Transparent
        Me.P_Mon.Font = New System.Drawing.Font("幼圆", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.P_Mon.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.P_Mon.Location = New System.Drawing.Point(1166, 0)
        Me.P_Mon.Name = "P_Mon"
        Me.P_Mon.Size = New System.Drawing.Size(200, 40)
        Me.P_Mon.TabIndex = 28
        Me.P_Mon.Text = "金额"
        Me.P_Mon.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Line
        '
        Me.Line.BackColor = System.Drawing.Color.FromArgb(CType(CType(255, Byte), Integer), CType(CType(128, Byte), Integer), CType(CType(128, Byte), Integer))
        Me.Line.Location = New System.Drawing.Point(0, 136)
        Me.Line.Name = "Line"
        Me.Line.Size = New System.Drawing.Size(1366, 1)
        Me.Line.TabIndex = 29
        Me.Line.Text = "Label1"
        '
        'cash
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(1366, 726)
        Me.ControlBox = False
        Me.Controls.Add(Me.Line)
        Me.Controls.Add(Me.P_Mon)
        Me.Controls.Add(Me.P_Price)
        Me.Controls.Add(Me.P_NUM)
        Me.Controls.Add(Me.p_Unit)
        Me.Controls.Add(Me.P_Name_)
        Me.Controls.Add(Me.Buy_ID)
        Me.Controls.Add(Me.Line_num)
        Me.Controls.Add(Me.Data)
        Me.Controls.Add(Me.column1)
        Me.Controls.Add(Me.ALL_M_P)
        Me.Controls.Add(Me.SHU1)
        Me.Controls.Add(Me.ALL_M_ZI)
        Me.Controls.Add(Me.ALL_N_P)
        Me.Controls.Add(Me.SHU)
        Me.Controls.Add(Me.ALL_NUM_zi)
        Me.Controls.Add(Me.ID_P_A_I)
        Me.Controls.Add(Me.ALL_Money)
        Me.Controls.Add(Me.ALL_NUM)
        Me.Controls.Add(Me.back_IS)
        Me.Controls.Add(Me.ALL_M_Back)
        Me.Controls.Add(Me.ALLN_Back)
        Me.Controls.Add(Me.ID_Back)
        Me.Controls.Add(Me.F5)
        Me.Controls.Add(Me.F4)
        Me.Controls.Add(Me.Esc)
        Me.Controls.Add(Me.ProIDzi)
        Me.Controls.Add(Me.column)
        Me.DoubleBuffered = True
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.KeyPreview = True
        Me.Name = "cash"
        Me.ShowInTaskbar = False
        Me.StartPosition = System.Windows.Forms.FormStartPosition.Manual
        Me.Text = "cash"
        CType(Me.column, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.column1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Data, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents column As System.Windows.Forms.PictureBox
    Friend WithEvents ProIDzi As System.Windows.Forms.Label
    Friend WithEvents Esc As System.Windows.Forms.Label
    Friend WithEvents F4 As System.Windows.Forms.Label
    Friend WithEvents F5 As System.Windows.Forms.Label
    Friend WithEvents ID_Back As System.Windows.Forms.Label
    Friend WithEvents ALLN_Back As System.Windows.Forms.Label
    Friend WithEvents ALL_M_Back As System.Windows.Forms.Label
    Friend WithEvents back_IS As System.Windows.Forms.Label
    Friend WithEvents ALL_NUM As System.Windows.Forms.Label
    Friend WithEvents ALL_Money As System.Windows.Forms.Label
    Friend WithEvents ID_P_A_I As System.Windows.Forms.TextBox
    Friend WithEvents ALL_NUM_zi As System.Windows.Forms.Label
    Friend WithEvents SHU As System.Windows.Forms.Label
    Friend WithEvents ALL_N_P As System.Windows.Forms.Label
    Friend WithEvents ALL_M_ZI As System.Windows.Forms.Label
    Friend WithEvents SHU1 As System.Windows.Forms.Label
    Friend WithEvents ALL_M_P As System.Windows.Forms.Label
    Friend WithEvents column1 As System.Windows.Forms.PictureBox
    Friend WithEvents Data As System.Windows.Forms.DataGridView
    Friend WithEvents List_Num As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents B_ID As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents P_Name As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents unit As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents Num As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents price As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents Money As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents Line_num As System.Windows.Forms.Label
    Friend WithEvents Buy_ID As System.Windows.Forms.Label
    Friend WithEvents P_Name_ As System.Windows.Forms.Label
    Friend WithEvents p_Unit As System.Windows.Forms.Label
    Friend WithEvents P_NUM As System.Windows.Forms.Label
    Friend WithEvents P_Price As System.Windows.Forms.Label
    Friend WithEvents P_Mon As System.Windows.Forms.Label
    Friend WithEvents Line As System.Windows.Forms.Label
End Class
