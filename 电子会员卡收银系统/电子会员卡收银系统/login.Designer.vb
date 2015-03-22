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
        Me.PictureBox2 = New System.Windows.Forms.PictureBox()
        Me.Caption = New System.Windows.Forms.Label()
        Me.userName = New System.Windows.Forms.Label()
        Me.passwd = New System.Windows.Forms.Label()
        Me.userNameI = New System.Windows.Forms.TextBox()
        Me.passwdI = New System.Windows.Forms.TextBox()
        Me.Mon = New System.Windows.Forms.Button()
        Me.PictureBox3 = New System.Windows.Forms.PictureBox()
        Me.Server = New System.Windows.Forms.TextBox()
        Me.database = New System.Windows.Forms.TextBox()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.PictureBox2, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.PictureBox3, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'PictureBox1
        '
        Me.PictureBox1.Image = CType(resources.GetObject("PictureBox1.Image"), System.Drawing.Image)
        Me.PictureBox1.Location = New System.Drawing.Point(67, 90)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(29, 36)
        Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize
        Me.PictureBox1.TabIndex = 0
        Me.PictureBox1.TabStop = False
        '
        'PictureBox2
        '
        Me.PictureBox2.Image = CType(resources.GetObject("PictureBox2.Image"), System.Drawing.Image)
        Me.PictureBox2.Location = New System.Drawing.Point(67, 155)
        Me.PictureBox2.Name = "PictureBox2"
        Me.PictureBox2.Size = New System.Drawing.Size(29, 36)
        Me.PictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize
        Me.PictureBox2.TabIndex = 1
        Me.PictureBox2.TabStop = False
        '
        'Caption
        '
        Me.Caption.Font = New System.Drawing.Font("楷体", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Caption.Location = New System.Drawing.Point(127, 22)
        Me.Caption.Name = "Caption"
        Me.Caption.Size = New System.Drawing.Size(179, 36)
        Me.Caption.TabIndex = 2
        Me.Caption.Text = "收银系统"
        Me.Caption.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'userName
        '
        Me.userName.Font = New System.Drawing.Font("华文宋体", 14.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.userName.Location = New System.Drawing.Point(96, 90)
        Me.userName.Name = "userName"
        Me.userName.Size = New System.Drawing.Size(90, 36)
        Me.userName.TabIndex = 3
        Me.userName.Text = "用户名："
        Me.userName.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'passwd
        '
        Me.passwd.Font = New System.Drawing.Font("华文宋体", 14.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.passwd.Location = New System.Drawing.Point(98, 154)
        Me.passwd.Name = "passwd"
        Me.passwd.Size = New System.Drawing.Size(90, 35)
        Me.passwd.TabIndex = 4
        Me.passwd.Text = "密   码："
        Me.passwd.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'userNameI
        '
        Me.userNameI.Font = New System.Drawing.Font("华文宋体", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.userNameI.Location = New System.Drawing.Point(192, 94)
        Me.userNameI.Name = "userNameI"
        Me.userNameI.Size = New System.Drawing.Size(194, 32)
        Me.userNameI.TabIndex = 5
        '
        'passwdI
        '
        Me.passwdI.Font = New System.Drawing.Font("华文宋体", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.passwdI.Location = New System.Drawing.Point(192, 157)
        Me.passwdI.Name = "passwdI"
        Me.passwdI.PasswordChar = Global.Microsoft.VisualBasic.ChrW(8226)
        Me.passwdI.Size = New System.Drawing.Size(194, 32)
        Me.passwdI.TabIndex = 6
        '
        'Mon
        '
        Me.Mon.Font = New System.Drawing.Font("华文宋体", 14.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Mon.Location = New System.Drawing.Point(266, 216)
        Me.Mon.Name = "Mon"
        Me.Mon.Size = New System.Drawing.Size(120, 34)
        Me.Mon.TabIndex = 7
        Me.Mon.Text = "登录  "
        Me.Mon.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        Me.Mon.UseVisualStyleBackColor = True
        '
        'PictureBox3
        '
        Me.PictureBox3.Image = CType(resources.GetObject("PictureBox3.Image"), System.Drawing.Image)
        Me.PictureBox3.Location = New System.Drawing.Point(283, 223)
        Me.PictureBox3.Name = "PictureBox3"
        Me.PictureBox3.Size = New System.Drawing.Size(19, 19)
        Me.PictureBox3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize
        Me.PictureBox3.TabIndex = 8
        Me.PictureBox3.TabStop = False
        '
        'Server
        '
        Me.Server.Location = New System.Drawing.Point(67, 63)
        Me.Server.Name = "Server"
        Me.Server.Size = New System.Drawing.Size(153, 21)
        Me.Server.TabIndex = 9
        Me.Server.Text = "localhost"
        Me.Server.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'database
        '
        Me.database.Location = New System.Drawing.Point(226, 63)
        Me.database.Name = "database"
        Me.database.Size = New System.Drawing.Size(160, 21)
        Me.database.TabIndex = 10
        Me.database.Text = "member"
        Me.database.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'Login
        '
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.None
        Me.AutoSize = True
        Me.BackColor = System.Drawing.Color.WhiteSmoke
        Me.ClientSize = New System.Drawing.Size(450, 300)
        Me.Controls.Add(Me.database)
        Me.Controls.Add(Me.Server)
        Me.Controls.Add(Me.PictureBox3)
        Me.Controls.Add(Me.Mon)
        Me.Controls.Add(Me.passwdI)
        Me.Controls.Add(Me.userNameI)
        Me.Controls.Add(Me.passwd)
        Me.Controls.Add(Me.userName)
        Me.Controls.Add(Me.Caption)
        Me.Controls.Add(Me.PictureBox2)
        Me.Controls.Add(Me.PictureBox1)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.MaximizeBox = False
        Me.Name = "Login"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "登录窗口"
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.PictureBox2, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.PictureBox3, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents PictureBox1 As System.Windows.Forms.PictureBox
    Friend WithEvents PictureBox2 As System.Windows.Forms.PictureBox
    Friend WithEvents Caption As System.Windows.Forms.Label
    Friend WithEvents userName As System.Windows.Forms.Label
    Friend WithEvents passwd As System.Windows.Forms.Label
    Friend WithEvents userNameI As System.Windows.Forms.TextBox
    Friend WithEvents passwdI As System.Windows.Forms.TextBox
    Friend WithEvents Mon As System.Windows.Forms.Button
    Friend WithEvents PictureBox3 As System.Windows.Forms.PictureBox
    Friend WithEvents Server As System.Windows.Forms.TextBox
    Friend WithEvents database As System.Windows.Forms.TextBox

End Class
