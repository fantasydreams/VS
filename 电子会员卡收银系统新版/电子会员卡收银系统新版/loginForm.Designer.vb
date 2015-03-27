<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Login
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Login))
        Me.PictureBox1 = New System.Windows.Forms.PictureBox()
        Me.IDPic = New System.Windows.Forms.PictureBox()
        Me.IDCODE = New System.Windows.Forms.PictureBox()
        Me.loginButton = New System.Windows.Forms.Label()
        Me.ID = New System.Windows.Forms.TextBox()
        Me.key = New System.Windows.Forms.TextBox()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.IDPic, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.IDCODE, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'PictureBox1
        '
        Me.PictureBox1.Image = CType(resources.GetObject("PictureBox1.Image"), System.Drawing.Image)
        Me.PictureBox1.Location = New System.Drawing.Point(200, 35)
        Me.PictureBox1.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(235, 115)
        Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.PictureBox1.TabIndex = 0
        Me.PictureBox1.TabStop = False
        '
        'IDPic
        '
        Me.IDPic.Image = CType(resources.GetObject("IDPic.Image"), System.Drawing.Image)
        Me.IDPic.Location = New System.Drawing.Point(135, 170)
        Me.IDPic.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.IDPic.Name = "IDPic"
        Me.IDPic.Size = New System.Drawing.Size(400, 55)
        Me.IDPic.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.IDPic.TabIndex = 1
        Me.IDPic.TabStop = False
        '
        'IDCODE
        '
        Me.IDCODE.Image = CType(resources.GetObject("IDCODE.Image"), System.Drawing.Image)
        Me.IDCODE.Location = New System.Drawing.Point(135, 250)
        Me.IDCODE.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.IDCODE.Name = "IDCODE"
        Me.IDCODE.Size = New System.Drawing.Size(400, 55)
        Me.IDCODE.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.IDCODE.TabIndex = 2
        Me.IDCODE.TabStop = False
        '
        'loginButton
        '
        Me.loginButton.Font = New System.Drawing.Font("微软雅黑", 23.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.loginButton.ForeColor = System.Drawing.Color.White
        Me.loginButton.Location = New System.Drawing.Point(135, 350)
        Me.loginButton.Name = "loginButton"
        Me.loginButton.Size = New System.Drawing.Size(400, 55)
        Me.loginButton.TabIndex = 3
        Me.loginButton.Text = "登录"
        Me.loginButton.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'ID
        '
        Me.ID.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.ID.Font = New System.Drawing.Font("微软雅黑", 20.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.ID.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.ID.Location = New System.Drawing.Point(190, 179)
        Me.ID.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.ID.Name = "ID"
        Me.ID.Size = New System.Drawing.Size(340, 36)
        Me.ID.TabIndex = 4
        '
        'key
        '
        Me.key.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.key.Font = New System.Drawing.Font("微软雅黑", 20.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.key.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.key.Location = New System.Drawing.Point(190, 260)
        Me.key.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.key.Name = "key"
        Me.key.Size = New System.Drawing.Size(340, 36)
        Me.key.TabIndex = 5
        '
        'Login
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(7.0!, 17.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(650, 470)
        Me.Controls.Add(Me.key)
        Me.Controls.Add(Me.ID)
        Me.Controls.Add(Me.loginButton)
        Me.Controls.Add(Me.IDCODE)
        Me.Controls.Add(Me.IDPic)
        Me.Controls.Add(Me.PictureBox1)
        Me.DoubleBuffered = True
        Me.Font = New System.Drawing.Font("微软雅黑", 9.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.KeyPreview = True
        Me.Margin = New System.Windows.Forms.Padding(3, 4, 3, 4)
        Me.Name = "Login"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.IDPic, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.IDCODE, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents PictureBox1 As System.Windows.Forms.PictureBox
    Friend WithEvents IDPic As System.Windows.Forms.PictureBox
    Friend WithEvents IDCODE As System.Windows.Forms.PictureBox
    Friend WithEvents loginButton As System.Windows.Forms.Label
    Friend WithEvents ID As System.Windows.Forms.TextBox
    Friend WithEvents key As System.Windows.Forms.TextBox

End Class
