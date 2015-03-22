<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class GetCash
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(GetCash))
        Me.F5 = New System.Windows.Forms.Label()
        Me.F4 = New System.Windows.Forms.Label()
        Me.Esc = New System.Windows.Forms.Label()
        Me.column = New System.Windows.Forms.PictureBox()
        CType(Me.column, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'F5
        '
        Me.F5.BackColor = System.Drawing.Color.Transparent
        Me.F5.Font = New System.Drawing.Font("幼圆", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.F5.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.F5.Location = New System.Drawing.Point(250, 0)
        Me.F5.Name = "F5"
        Me.F5.Size = New System.Drawing.Size(130, 40)
        Me.F5.TabIndex = 10
        Me.F5.Text = "F5撤销"
        Me.F5.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'F4
        '
        Me.F4.BackColor = System.Drawing.Color.Transparent
        Me.F4.Font = New System.Drawing.Font("幼圆", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.F4.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.F4.Location = New System.Drawing.Point(150, 0)
        Me.F4.Name = "F4"
        Me.F4.Size = New System.Drawing.Size(100, 40)
        Me.F4.TabIndex = 9
        Me.F4.Text = "F4重置"
        Me.F4.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Esc
        '
        Me.Esc.BackColor = System.Drawing.Color.Transparent
        Me.Esc.Font = New System.Drawing.Font("幼圆", 15.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Esc.ForeColor = System.Drawing.SystemColors.ControlDarkDark
        Me.Esc.Location = New System.Drawing.Point(0, 0)
        Me.Esc.Name = "Esc"
        Me.Esc.Size = New System.Drawing.Size(150, 40)
        Me.Esc.TabIndex = 8
        Me.Esc.Text = "ESC 返回"
        Me.Esc.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'column
        '
        Me.column.BackColor = System.Drawing.Color.Gray
        Me.column.Image = CType(resources.GetObject("column.Image"), System.Drawing.Image)
        Me.column.Location = New System.Drawing.Point(0, 0)
        Me.column.Name = "column"
        Me.column.Size = New System.Drawing.Size(1366, 40)
        Me.column.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.column.TabIndex = 7
        Me.column.TabStop = False
        '
        'GetCash
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.SystemColors.ActiveCaptionText
        Me.ClientSize = New System.Drawing.Size(1366, 700)
        Me.Controls.Add(Me.F5)
        Me.Controls.Add(Me.F4)
        Me.Controls.Add(Me.Esc)
        Me.Controls.Add(Me.column)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None
        Me.Name = "GetCash"
        Me.Opacity = 0.5R
        Me.ShowInTaskbar = False
        Me.StartPosition = System.Windows.Forms.FormStartPosition.Manual
        Me.Text = "GetCash"
        Me.TopMost = True
        CType(Me.column, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents F5 As System.Windows.Forms.Label
    Friend WithEvents F4 As System.Windows.Forms.Label
    Friend WithEvents Esc As System.Windows.Forms.Label
    Friend WithEvents column As System.Windows.Forms.PictureBox
End Class
