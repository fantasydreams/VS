<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class IDScan
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(IDScan))
        Me.ID_SCAN_ZI = New System.Windows.Forms.Label()
        Me.column = New System.Windows.Forms.PictureBox()
        Me.PictureBox1 = New System.Windows.Forms.PictureBox()
        Me.PA_BACK = New System.Windows.Forms.Panel()
        Me.ID_I = New System.Windows.Forms.TextBox()
        Me.PA_BACK_P = New System.Windows.Forms.Label()
        Me.找回 = New System.Windows.Forms.Label()
        Me.Label12 = New System.Windows.Forms.Label()
        Me.PA_B_B = New System.Windows.Forms.Label()
        Me.Panel1 = New System.Windows.Forms.Panel()
        Me.User_name = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Count_B = New System.Windows.Forms.Label()
        Me.PictureBox2 = New System.Windows.Forms.PictureBox()
        CType(Me.column, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.PA_BACK.SuspendLayout()
        Me.Panel1.SuspendLayout()
        CType(Me.PictureBox2, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'ID_SCAN_ZI
        '
        Me.ID_SCAN_ZI.BackColor = System.Drawing.Color.Transparent
        Me.ID_SCAN_ZI.Font = New System.Drawing.Font("幼圆", 15.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.ID_SCAN_ZI.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.ID_SCAN_ZI.Location = New System.Drawing.Point(0, 0)
        Me.ID_SCAN_ZI.Name = "ID_SCAN_ZI"
        Me.ID_SCAN_ZI.Size = New System.Drawing.Size(223, 40)
        Me.ID_SCAN_ZI.TabIndex = 4
        Me.ID_SCAN_ZI.Text = "顾客条形码扫描"
        Me.ID_SCAN_ZI.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'column
        '
        Me.column.Image = CType(resources.GetObject("column.Image"), System.Drawing.Image)
        Me.column.Location = New System.Drawing.Point(0, 0)
        Me.column.Name = "column"
        Me.column.Size = New System.Drawing.Size(680, 40)
        Me.column.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.column.TabIndex = 3
        Me.column.TabStop = False
        '
        'PictureBox1
        '
        Me.PictureBox1.Image = CType(resources.GetObject("PictureBox1.Image"), System.Drawing.Image)
        Me.PictureBox1.Location = New System.Drawing.Point(240, 40)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(200, 190)
        Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.PictureBox1.TabIndex = 5
        Me.PictureBox1.TabStop = False
        '
        'PA_BACK
        '
        Me.PA_BACK.Controls.Add(Me.ID_I)
        Me.PA_BACK.Controls.Add(Me.PA_BACK_P)
        Me.PA_BACK.Controls.Add(Me.找回)
        Me.PA_BACK.Controls.Add(Me.Label12)
        Me.PA_BACK.Controls.Add(Me.PA_B_B)
        Me.PA_BACK.Location = New System.Drawing.Point(120, 250)
        Me.PA_BACK.Name = "PA_BACK"
        Me.PA_BACK.Size = New System.Drawing.Size(415, 48)
        Me.PA_BACK.TabIndex = 8
        '
        'ID_I
        '
        Me.ID_I.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.ID_I.Font = New System.Drawing.Font("宋体", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.ID_I.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.ID_I.Location = New System.Drawing.Point(102, 9)
        Me.ID_I.Name = "ID_I"
        Me.ID_I.Size = New System.Drawing.Size(310, 34)
        Me.ID_I.TabIndex = 8
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
        Me.找回.Text = "条形码"
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
        'Panel1
        '
        Me.Panel1.Controls.Add(Me.User_name)
        Me.Panel1.Controls.Add(Me.Label2)
        Me.Panel1.Controls.Add(Me.Label3)
        Me.Panel1.Controls.Add(Me.Count_B)
        Me.Panel1.Location = New System.Drawing.Point(120, 320)
        Me.Panel1.Name = "Panel1"
        Me.Panel1.Size = New System.Drawing.Size(415, 48)
        Me.Panel1.TabIndex = 9
        '
        'User_name
        '
        Me.User_name.BackColor = System.Drawing.Color.White
        Me.User_name.Font = New System.Drawing.Font("幼圆", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.User_name.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.User_name.Location = New System.Drawing.Point(97, 1)
        Me.User_name.Name = "User_name"
        Me.User_name.Size = New System.Drawing.Size(317, 46)
        Me.User_name.TabIndex = 7
        Me.User_name.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'Label2
        '
        Me.Label2.Font = New System.Drawing.Font("幼圆", 18.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Label2.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.Label2.Location = New System.Drawing.Point(1, 1)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(95, 46)
        Me.Label2.TabIndex = 6
        Me.Label2.Text = "账户"
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
        'Count_B
        '
        Me.Count_B.Location = New System.Drawing.Point(0, 0)
        Me.Count_B.Name = "Count_B"
        Me.Count_B.Size = New System.Drawing.Size(415, 48)
        Me.Count_B.TabIndex = 4
        '
        'PictureBox2
        '
        Me.PictureBox2.Image = CType(resources.GetObject("PictureBox2.Image"), System.Drawing.Image)
        Me.PictureBox2.Location = New System.Drawing.Point(374, 395)
        Me.PictureBox2.Name = "PictureBox2"
        Me.PictureBox2.Size = New System.Drawing.Size(160, 48)
        Me.PictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.PictureBox2.TabIndex = 10
        Me.PictureBox2.TabStop = False
        '
        'IDScan
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(680, 480)
        Me.Controls.Add(Me.PictureBox2)
        Me.Controls.Add(Me.Panel1)
        Me.Controls.Add(Me.PA_BACK)
        Me.Controls.Add(Me.PictureBox1)
        Me.Controls.Add(Me.ID_SCAN_ZI)
        Me.Controls.Add(Me.column)
        Me.DoubleBuffered = True
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.Name = "IDScan"
        Me.ShowInTaskbar = False
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "IDScan"
        CType(Me.column, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.PA_BACK.ResumeLayout(False)
        Me.PA_BACK.PerformLayout()
        Me.Panel1.ResumeLayout(False)
        CType(Me.PictureBox2, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents ID_SCAN_ZI As System.Windows.Forms.Label
    Friend WithEvents column As System.Windows.Forms.PictureBox
    Friend WithEvents PictureBox1 As System.Windows.Forms.PictureBox
    Friend WithEvents PA_BACK As System.Windows.Forms.Panel
    Friend WithEvents PA_BACK_P As System.Windows.Forms.Label
    Friend WithEvents 找回 As System.Windows.Forms.Label
    Friend WithEvents Label12 As System.Windows.Forms.Label
    Friend WithEvents PA_B_B As System.Windows.Forms.Label
    Friend WithEvents Panel1 As System.Windows.Forms.Panel
    Friend WithEvents User_name As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Count_B As System.Windows.Forms.Label
    Friend WithEvents PictureBox2 As System.Windows.Forms.PictureBox
    Friend WithEvents ID_I As System.Windows.Forms.TextBox
End Class
