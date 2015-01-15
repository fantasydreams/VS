<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class code
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(code))
        Me.PictureBox1 = New System.Windows.Forms.PictureBox()
        Me.CodeI = New System.Windows.Forms.TextBox()
        Me.Yes = New System.Windows.Forms.Button()
        Me.Pic = New System.Windows.Forms.PictureBox()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Pic, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'PictureBox1
        '
        Me.PictureBox1.Image = CType(resources.GetObject("PictureBox1.Image"), System.Drawing.Image)
        Me.PictureBox1.Location = New System.Drawing.Point(55, 52)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(216, 94)
        Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox1.TabIndex = 0
        Me.PictureBox1.TabStop = False
        '
        'CodeI
        '
        Me.CodeI.Font = New System.Drawing.Font("宋体", 36.0!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.CodeI.Location = New System.Drawing.Point(55, 188)
        Me.CodeI.Multiline = True
        Me.CodeI.Name = "CodeI"
        Me.CodeI.Size = New System.Drawing.Size(425, 57)
        Me.CodeI.TabIndex = 1
        '
        'Yes
        '
        Me.Yes.Font = New System.Drawing.Font("宋体", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Yes.Location = New System.Drawing.Point(412, 291)
        Me.Yes.Name = "Yes"
        Me.Yes.Size = New System.Drawing.Size(93, 37)
        Me.Yes.TabIndex = 3
        Me.Yes.Text = "  确定"
        Me.Yes.UseVisualStyleBackColor = True
        '
        'Pic
        '
        Me.Pic.Image = CType(resources.GetObject("Pic.Image"), System.Drawing.Image)
        Me.Pic.Location = New System.Drawing.Point(416, 300)
        Me.Pic.Name = "Pic"
        Me.Pic.Size = New System.Drawing.Size(19, 19)
        Me.Pic.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize
        Me.Pic.TabIndex = 4
        Me.Pic.TabStop = False
        '
        'code
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(537, 349)
        Me.Controls.Add(Me.Pic)
        Me.Controls.Add(Me.Yes)
        Me.Controls.Add(Me.CodeI)
        Me.Controls.Add(Me.PictureBox1)
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.Name = "code"
        Me.Text = "条形码扫描"
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Pic, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents PictureBox1 As System.Windows.Forms.PictureBox
    Friend WithEvents CodeI As System.Windows.Forms.TextBox
    Friend WithEvents Yes As System.Windows.Forms.Button
    Friend WithEvents Pic As System.Windows.Forms.PictureBox
End Class
