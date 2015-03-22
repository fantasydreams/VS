<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class balance
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(balance))
        Me.column = New System.Windows.Forms.PictureBox()
        Me.balan = New System.Windows.Forms.Label()
        Me.ALL_M = New System.Windows.Forms.Panel()
        Me.ALL_M_P = New System.Windows.Forms.Label()
        Me.ALL_N_ZI = New System.Windows.Forms.Label()
        Me.ALL_M_ZI = New System.Windows.Forms.Label()
        Me.ALL_M_B = New System.Windows.Forms.Label()
        Me.VIP_M = New System.Windows.Forms.Panel()
        Me.VIP_M_P = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.VIP_B = New System.Windows.Forms.Label()
        Me.PA_M = New System.Windows.Forms.Panel()
        Me.Pack_M = New System.Windows.Forms.Label()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.PA_M_B = New System.Windows.Forms.Label()
        Me.AC_P = New System.Windows.Forms.Panel()
        Me.AC_P_I = New System.Windows.Forms.TextBox()
        Me.AC_P_B = New System.Windows.Forms.Label()
        Me.Label8 = New System.Windows.Forms.Label()
        Me.Label9 = New System.Windows.Forms.Label()
        Me.AC_PA_B = New System.Windows.Forms.Label()
        Me.PA_BACK = New System.Windows.Forms.Panel()
        Me.PA_BACK_P = New System.Windows.Forms.Label()
        Me.找回 = New System.Windows.Forms.Label()
        Me.Label12 = New System.Windows.Forms.Label()
        Me.PA_B_B = New System.Windows.Forms.Label()
        Me.PictureBox1 = New System.Windows.Forms.PictureBox()
        CType(Me.column, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.ALL_M.SuspendLayout()
        Me.VIP_M.SuspendLayout()
        Me.PA_M.SuspendLayout()
        Me.AC_P.SuspendLayout()
        Me.PA_BACK.SuspendLayout()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'column
        '
        Me.column.Image = CType(resources.GetObject("column.Image"), System.Drawing.Image)
        Me.column.Location = New System.Drawing.Point(0, 0)
        Me.column.Name = "column"
        Me.column.Size = New System.Drawing.Size(680, 40)
        Me.column.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.column.TabIndex = 0
        Me.column.TabStop = False
        '
        'balan
        '
        Me.balan.BackColor = System.Drawing.Color.Transparent
        Me.balan.Font = New System.Drawing.Font("幼圆", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.balan.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.balan.Location = New System.Drawing.Point(0, 0)
        Me.balan.Name = "balan"
        Me.balan.Size = New System.Drawing.Size(100, 40)
        Me.balan.TabIndex = 2
        Me.balan.Text = "结算"
        Me.balan.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'ALL_M
        '
        Me.ALL_M.Controls.Add(Me.ALL_M_P)
        Me.ALL_M.Controls.Add(Me.ALL_N_ZI)
        Me.ALL_M.Controls.Add(Me.ALL_M_ZI)
        Me.ALL_M.Controls.Add(Me.ALL_M_B)
        Me.ALL_M.Location = New System.Drawing.Point(120, 55)
        Me.ALL_M.Name = "ALL_M"
        Me.ALL_M.Size = New System.Drawing.Size(415, 48)
        Me.ALL_M.TabIndex = 3
        '
        'ALL_M_P
        '
        Me.ALL_M_P.BackColor = System.Drawing.Color.White
        Me.ALL_M_P.Font = New System.Drawing.Font("幼圆", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.ALL_M_P.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.ALL_M_P.Location = New System.Drawing.Point(97, 1)
        Me.ALL_M_P.Name = "ALL_M_P"
        Me.ALL_M_P.Size = New System.Drawing.Size(317, 46)
        Me.ALL_M_P.TabIndex = 7
        Me.ALL_M_P.Text = "0"
        Me.ALL_M_P.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'ALL_N_ZI
        '
        Me.ALL_N_ZI.Font = New System.Drawing.Font("幼圆", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.ALL_N_ZI.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.ALL_N_ZI.Location = New System.Drawing.Point(1, 1)
        Me.ALL_N_ZI.Name = "ALL_N_ZI"
        Me.ALL_N_ZI.Size = New System.Drawing.Size(95, 46)
        Me.ALL_N_ZI.TabIndex = 6
        Me.ALL_N_ZI.Text = "总价"
        Me.ALL_N_ZI.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'ALL_M_ZI
        '
        Me.ALL_M_ZI.Font = New System.Drawing.Font("幼圆", 18.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.ALL_M_ZI.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.ALL_M_ZI.Location = New System.Drawing.Point(-106, 27)
        Me.ALL_M_ZI.Name = "ALL_M_ZI"
        Me.ALL_M_ZI.Size = New System.Drawing.Size(95, 46)
        Me.ALL_M_ZI.TabIndex = 5
        Me.ALL_M_ZI.Text = "总价"
        Me.ALL_M_ZI.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'ALL_M_B
        '
        Me.ALL_M_B.Location = New System.Drawing.Point(0, 0)
        Me.ALL_M_B.Name = "ALL_M_B"
        Me.ALL_M_B.Size = New System.Drawing.Size(415, 48)
        Me.ALL_M_B.TabIndex = 4
        '
        'VIP_M
        '
        Me.VIP_M.Controls.Add(Me.VIP_M_P)
        Me.VIP_M.Controls.Add(Me.Label2)
        Me.VIP_M.Controls.Add(Me.Label3)
        Me.VIP_M.Controls.Add(Me.VIP_B)
        Me.VIP_M.Location = New System.Drawing.Point(120, 118)
        Me.VIP_M.Name = "VIP_M"
        Me.VIP_M.Size = New System.Drawing.Size(415, 48)
        Me.VIP_M.TabIndex = 4
        '
        'VIP_M_P
        '
        Me.VIP_M_P.BackColor = System.Drawing.Color.White
        Me.VIP_M_P.Font = New System.Drawing.Font("幼圆", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.VIP_M_P.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.VIP_M_P.Location = New System.Drawing.Point(97, 1)
        Me.VIP_M_P.Name = "VIP_M_P"
        Me.VIP_M_P.Size = New System.Drawing.Size(317, 46)
        Me.VIP_M_P.TabIndex = 7
        Me.VIP_M_P.Text = "0"
        Me.VIP_M_P.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'Label2
        '
        Me.Label2.Font = New System.Drawing.Font("幼圆", 18.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Label2.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.Label2.Location = New System.Drawing.Point(1, 1)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(95, 46)
        Me.Label2.TabIndex = 6
        Me.Label2.Text = "会员价"
        Me.Label2.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Label3
        '
        Me.Label3.Font = New System.Drawing.Font("幼圆", 18.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Label3.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.Label3.Location = New System.Drawing.Point(-106, 27)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(95, 46)
        Me.Label3.TabIndex = 5
        Me.Label3.Text = "总价"
        Me.Label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'VIP_B
        '
        Me.VIP_B.Location = New System.Drawing.Point(0, 0)
        Me.VIP_B.Name = "VIP_B"
        Me.VIP_B.Size = New System.Drawing.Size(416, 48)
        Me.VIP_B.TabIndex = 4
        '
        'PA_M
        '
        Me.PA_M.Controls.Add(Me.Pack_M)
        Me.PA_M.Controls.Add(Me.Label5)
        Me.PA_M.Controls.Add(Me.Label6)
        Me.PA_M.Controls.Add(Me.PA_M_B)
        Me.PA_M.Location = New System.Drawing.Point(120, 181)
        Me.PA_M.Name = "PA_M"
        Me.PA_M.Size = New System.Drawing.Size(415, 48)
        Me.PA_M.TabIndex = 5
        '
        'Pack_M
        '
        Me.Pack_M.BackColor = System.Drawing.Color.White
        Me.Pack_M.Font = New System.Drawing.Font("幼圆", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Pack_M.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.Pack_M.Location = New System.Drawing.Point(97, 1)
        Me.Pack_M.Name = "Pack_M"
        Me.Pack_M.Size = New System.Drawing.Size(317, 46)
        Me.Pack_M.TabIndex = 7
        Me.Pack_M.Text = "0"
        Me.Pack_M.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'Label5
        '
        Me.Label5.Font = New System.Drawing.Font("幼圆", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Label5.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.Label5.Location = New System.Drawing.Point(1, 1)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(95, 46)
        Me.Label5.TabIndex = 6
        Me.Label5.Text = "零钱"
        Me.Label5.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Label6
        '
        Me.Label6.Font = New System.Drawing.Font("幼圆", 18.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Label6.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.Label6.Location = New System.Drawing.Point(-106, 27)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(95, 46)
        Me.Label6.TabIndex = 5
        Me.Label6.Text = "总价"
        Me.Label6.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'PA_M_B
        '
        Me.PA_M_B.Location = New System.Drawing.Point(0, 0)
        Me.PA_M_B.Name = "PA_M_B"
        Me.PA_M_B.Size = New System.Drawing.Size(415, 48)
        Me.PA_M_B.TabIndex = 4
        '
        'AC_P
        '
        Me.AC_P.Controls.Add(Me.AC_P_I)
        Me.AC_P.Controls.Add(Me.AC_P_B)
        Me.AC_P.Controls.Add(Me.Label8)
        Me.AC_P.Controls.Add(Me.Label9)
        Me.AC_P.Controls.Add(Me.AC_PA_B)
        Me.AC_P.Location = New System.Drawing.Point(120, 244)
        Me.AC_P.Name = "AC_P"
        Me.AC_P.Size = New System.Drawing.Size(415, 48)
        Me.AC_P.TabIndex = 6
        '
        'AC_P_I
        '
        Me.AC_P_I.BackColor = System.Drawing.Color.White
        Me.AC_P_I.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.AC_P_I.Font = New System.Drawing.Font("幼圆", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.AC_P_I.Location = New System.Drawing.Point(97, 11)
        Me.AC_P_I.Name = "AC_P_I"
        Me.AC_P_I.Size = New System.Drawing.Size(316, 32)
        Me.AC_P_I.TabIndex = 8
        '
        'AC_P_B
        '
        Me.AC_P_B.BackColor = System.Drawing.Color.White
        Me.AC_P_B.Font = New System.Drawing.Font("幼圆", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.AC_P_B.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.AC_P_B.Location = New System.Drawing.Point(97, 1)
        Me.AC_P_B.Name = "AC_P_B"
        Me.AC_P_B.Size = New System.Drawing.Size(317, 46)
        Me.AC_P_B.TabIndex = 7
        Me.AC_P_B.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'Label8
        '
        Me.Label8.Font = New System.Drawing.Font("幼圆", 18.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Label8.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.Label8.Location = New System.Drawing.Point(1, 1)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(95, 46)
        Me.Label8.TabIndex = 6
        Me.Label8.Text = "实付"
        Me.Label8.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Label9
        '
        Me.Label9.Font = New System.Drawing.Font("幼圆", 18.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Label9.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.Label9.Location = New System.Drawing.Point(-106, 27)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(95, 46)
        Me.Label9.TabIndex = 5
        Me.Label9.Text = "总价"
        Me.Label9.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'AC_PA_B
        '
        Me.AC_PA_B.Location = New System.Drawing.Point(0, 0)
        Me.AC_PA_B.Name = "AC_PA_B"
        Me.AC_PA_B.Size = New System.Drawing.Size(415, 48)
        Me.AC_PA_B.TabIndex = 4
        '
        'PA_BACK
        '
        Me.PA_BACK.Controls.Add(Me.PA_BACK_P)
        Me.PA_BACK.Controls.Add(Me.找回)
        Me.PA_BACK.Controls.Add(Me.Label12)
        Me.PA_BACK.Controls.Add(Me.PA_B_B)
        Me.PA_BACK.Location = New System.Drawing.Point(120, 307)
        Me.PA_BACK.Name = "PA_BACK"
        Me.PA_BACK.Size = New System.Drawing.Size(415, 48)
        Me.PA_BACK.TabIndex = 7
        '
        'PA_BACK_P
        '
        Me.PA_BACK_P.BackColor = System.Drawing.Color.White
        Me.PA_BACK_P.Font = New System.Drawing.Font("幼圆", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.PA_BACK_P.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.PA_BACK_P.Location = New System.Drawing.Point(97, 1)
        Me.PA_BACK_P.Name = "PA_BACK_P"
        Me.PA_BACK_P.Size = New System.Drawing.Size(317, 46)
        Me.PA_BACK_P.TabIndex = 7
        Me.PA_BACK_P.Text = "0"
        Me.PA_BACK_P.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        '找回
        '
        Me.找回.Font = New System.Drawing.Font("幼圆", 18.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.找回.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.找回.Location = New System.Drawing.Point(1, 1)
        Me.找回.Name = "找回"
        Me.找回.Size = New System.Drawing.Size(95, 46)
        Me.找回.TabIndex = 6
        Me.找回.Text = "找回"
        Me.找回.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Label12
        '
        Me.Label12.Font = New System.Drawing.Font("幼圆", 18.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Label12.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.Label12.Location = New System.Drawing.Point(-106, 27)
        Me.Label12.Name = "Label12"
        Me.Label12.Size = New System.Drawing.Size(95, 46)
        Me.Label12.TabIndex = 5
        Me.Label12.Text = "总价"
        Me.Label12.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'PA_B_B
        '
        Me.PA_B_B.Location = New System.Drawing.Point(0, 0)
        Me.PA_B_B.Name = "PA_B_B"
        Me.PA_B_B.Size = New System.Drawing.Size(415, 48)
        Me.PA_B_B.TabIndex = 4
        '
        'PictureBox1
        '
        Me.PictureBox1.Image = CType(resources.GetObject("PictureBox1.Image"), System.Drawing.Image)
        Me.PictureBox1.Location = New System.Drawing.Point(376, 388)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(160, 48)
        Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.PictureBox1.TabIndex = 8
        Me.PictureBox1.TabStop = False
        '
        'balance
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(680, 480)
        Me.Controls.Add(Me.PictureBox1)
        Me.Controls.Add(Me.PA_BACK)
        Me.Controls.Add(Me.AC_P)
        Me.Controls.Add(Me.PA_M)
        Me.Controls.Add(Me.VIP_M)
        Me.Controls.Add(Me.ALL_M)
        Me.Controls.Add(Me.balan)
        Me.Controls.Add(Me.column)
        Me.DoubleBuffered = True
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.Name = "balance"
        Me.ShowInTaskbar = False
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "balance"
        CType(Me.column, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ALL_M.ResumeLayout(False)
        Me.VIP_M.ResumeLayout(False)
        Me.PA_M.ResumeLayout(False)
        Me.AC_P.ResumeLayout(False)
        Me.AC_P.PerformLayout()
        Me.PA_BACK.ResumeLayout(False)
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents column As System.Windows.Forms.PictureBox
    Friend WithEvents balan As System.Windows.Forms.Label
    Friend WithEvents ALL_M As System.Windows.Forms.Panel
    Friend WithEvents ALL_M_ZI As System.Windows.Forms.Label
    Friend WithEvents ALL_M_B As System.Windows.Forms.Label
    Friend WithEvents ALL_N_ZI As System.Windows.Forms.Label
    Friend WithEvents ALL_M_P As System.Windows.Forms.Label
    Friend WithEvents VIP_M As System.Windows.Forms.Panel
    Friend WithEvents VIP_M_P As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents VIP_B As System.Windows.Forms.Label
    Friend WithEvents PA_M As System.Windows.Forms.Panel
    Friend WithEvents Pack_M As System.Windows.Forms.Label
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents PA_M_B As System.Windows.Forms.Label
    Friend WithEvents AC_P As System.Windows.Forms.Panel
    Friend WithEvents Label8 As System.Windows.Forms.Label
    Friend WithEvents Label9 As System.Windows.Forms.Label
    Friend WithEvents AC_PA_B As System.Windows.Forms.Label
    Friend WithEvents PA_BACK As System.Windows.Forms.Panel
    Friend WithEvents PA_BACK_P As System.Windows.Forms.Label
    Friend WithEvents 找回 As System.Windows.Forms.Label
    Friend WithEvents Label12 As System.Windows.Forms.Label
    Friend WithEvents PA_B_B As System.Windows.Forms.Label
    Friend WithEvents AC_P_I As System.Windows.Forms.TextBox
    Friend WithEvents AC_P_B As System.Windows.Forms.Label
    Friend WithEvents PictureBox1 As System.Windows.Forms.PictureBox
End Class
