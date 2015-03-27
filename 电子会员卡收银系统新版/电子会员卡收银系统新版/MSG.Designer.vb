<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class MSG
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(MSG))
        Me.msgP = New System.Windows.Forms.Label()
        Me.warn = New System.Windows.Forms.PictureBox()
        Me.head = New System.Windows.Forms.Label()
        Me.X = New System.Windows.Forms.Label()
        Me.col = New System.Windows.Forms.PictureBox()
        CType(Me.warn, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.col, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'msgP
        '
        Me.msgP.Font = New System.Drawing.Font("幼圆", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.msgP.ForeColor = System.Drawing.SystemColors.ActiveCaptionText
        Me.msgP.Location = New System.Drawing.Point(103, 78)
        Me.msgP.Name = "msgP"
        Me.msgP.Size = New System.Drawing.Size(257, 85)
        Me.msgP.TabIndex = 9
        Me.msgP.Text = "测试消息"
        Me.msgP.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'warn
        '
        Me.warn.Image = CType(resources.GetObject("warn.Image"), System.Drawing.Image)
        Me.warn.Location = New System.Drawing.Point(20, 78)
        Me.warn.Name = "warn"
        Me.warn.Size = New System.Drawing.Size(85, 85)
        Me.warn.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize
        Me.warn.TabIndex = 8
        Me.warn.TabStop = False
        '
        'head
        '
        Me.head.BackColor = System.Drawing.Color.Transparent
        Me.head.Font = New System.Drawing.Font("微软雅黑", 15.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.head.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.head.Location = New System.Drawing.Point(20, 0)
        Me.head.Name = "head"
        Me.head.Size = New System.Drawing.Size(340, 40)
        Me.head.TabIndex = 7
        Me.head.Text = "标题测试"
        Me.head.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'X
        '
        Me.X.BackColor = System.Drawing.Color.Transparent
        Me.X.Font = New System.Drawing.Font("微软雅黑", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.X.ForeColor = System.Drawing.Color.Red
        Me.X.Location = New System.Drawing.Point(360, 0)
        Me.X.Name = "X"
        Me.X.Size = New System.Drawing.Size(40, 40)
        Me.X.TabIndex = 6
        Me.X.Text = "X"
        Me.X.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'col
        '
        Me.col.Image = CType(resources.GetObject("col.Image"), System.Drawing.Image)
        Me.col.Location = New System.Drawing.Point(0, 0)
        Me.col.Name = "col"
        Me.col.Size = New System.Drawing.Size(400, 40)
        Me.col.TabIndex = 5
        Me.col.TabStop = False
        '
        'MSG
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(400, 200)
        Me.Controls.Add(Me.msgP)
        Me.Controls.Add(Me.warn)
        Me.Controls.Add(Me.head)
        Me.Controls.Add(Me.X)
        Me.Controls.Add(Me.col)
        Me.DoubleBuffered = True
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.KeyPreview = True
        Me.MaximizeBox = False
        Me.MinimizeBox = False
        Me.Name = "MSG"
        Me.ShowInTaskbar = False
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        CType(Me.warn, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.col, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents msgP As System.Windows.Forms.Label
    Friend WithEvents warn As System.Windows.Forms.PictureBox
    Friend WithEvents head As System.Windows.Forms.Label
    Friend WithEvents X As System.Windows.Forms.Label
    Friend WithEvents col As System.Windows.Forms.PictureBox

End Class
