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
        Me.col = New System.Windows.Forms.PictureBox()
        Me.X = New System.Windows.Forms.Label()
        Me.head = New System.Windows.Forms.Label()
        CType(Me.col, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'col
        '
        Me.col.Image = CType(resources.GetObject("col.Image"), System.Drawing.Image)
        Me.col.Location = New System.Drawing.Point(0, 0)
        Me.col.Name = "col"
        Me.col.Size = New System.Drawing.Size(400, 40)
        Me.col.TabIndex = 0
        Me.col.TabStop = False
        '
        'X
        '
        Me.X.BackColor = System.Drawing.Color.Transparent
        Me.X.Font = New System.Drawing.Font("微软雅黑", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.X.ForeColor = System.Drawing.Color.Red
        Me.X.Location = New System.Drawing.Point(360, 0)
        Me.X.Name = "X"
        Me.X.Size = New System.Drawing.Size(40, 40)
        Me.X.TabIndex = 1
        Me.X.Text = "X"
        Me.X.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'head
        '
        Me.head.BackColor = System.Drawing.Color.Transparent
        Me.head.Font = New System.Drawing.Font("微软雅黑", 15.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.head.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.head.Location = New System.Drawing.Point(24, 0)
        Me.head.Name = "head"
        Me.head.Size = New System.Drawing.Size(336, 40)
        Me.head.TabIndex = 2
        Me.head.Text = "标题测试"
        Me.head.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'MSG
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(400, 175)
        Me.Controls.Add(Me.head)
        Me.Controls.Add(Me.X)
        Me.Controls.Add(Me.col)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.Name = "MSG"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "MSG"
        CType(Me.col, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents col As System.Windows.Forms.PictureBox
    Friend WithEvents X As System.Windows.Forms.Label
    Friend WithEvents head As System.Windows.Forms.Label
End Class
