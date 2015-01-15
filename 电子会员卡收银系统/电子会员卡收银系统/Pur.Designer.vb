<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Pur
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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Pur))
        Me.price = New System.Windows.Forms.Label()
        Me.VIP = New System.Windows.Forms.Label()
        Me.pm = New System.Windows.Forms.Label()
        Me.APay = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        Me.APP = New System.Windows.Forms.Label()
        Me.VIPPP = New System.Windows.Forms.Label()
        Me.PMP = New System.Windows.Forms.Label()
        Me.PBP = New System.Windows.Forms.Label()
        Me.Pic = New System.Windows.Forms.PictureBox()
        Me.Yes = New System.Windows.Forms.Button()
        Me.ACP = New System.Windows.Forms.TextBox()
        CType(Me.Pic, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'price
        '
        Me.price.AutoSize = True
        Me.price.Font = New System.Drawing.Font("宋体", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.price.Location = New System.Drawing.Point(115, 32)
        Me.price.Name = "price"
        Me.price.Size = New System.Drawing.Size(100, 29)
        Me.price.TabIndex = 0
        Me.price.Text = "总价："
        '
        'VIP
        '
        Me.VIP.AutoSize = True
        Me.VIP.Font = New System.Drawing.Font("宋体", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.VIP.Location = New System.Drawing.Point(115, 99)
        Me.VIP.Name = "VIP"
        Me.VIP.Size = New System.Drawing.Size(129, 29)
        Me.VIP.TabIndex = 1
        Me.VIP.Text = "会员价："
        '
        'pm
        '
        Me.pm.AutoSize = True
        Me.pm.Font = New System.Drawing.Font("宋体", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.pm.Location = New System.Drawing.Point(115, 159)
        Me.pm.Name = "pm"
        Me.pm.Size = New System.Drawing.Size(100, 29)
        Me.pm.TabIndex = 2
        Me.pm.Text = "零钱："
        '
        'APay
        '
        Me.APay.AutoSize = True
        Me.APay.Font = New System.Drawing.Font("宋体", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.APay.Location = New System.Drawing.Point(115, 228)
        Me.APay.Name = "APay"
        Me.APay.Size = New System.Drawing.Size(100, 29)
        Me.APay.TabIndex = 3
        Me.APay.Text = "实付："
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Font = New System.Drawing.Font("宋体", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Label4.Location = New System.Drawing.Point(115, 296)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(100, 29)
        Me.Label4.TabIndex = 4
        Me.Label4.Text = "找回："
        '
        'APP
        '
        Me.APP.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.APP.Font = New System.Drawing.Font("宋体", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.APP.ForeColor = System.Drawing.Color.Red
        Me.APP.Location = New System.Drawing.Point(286, 29)
        Me.APP.Name = "APP"
        Me.APP.Size = New System.Drawing.Size(220, 36)
        Me.APP.TabIndex = 5
        Me.APP.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'VIPPP
        '
        Me.VIPPP.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.VIPPP.Font = New System.Drawing.Font("宋体", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.VIPPP.ForeColor = System.Drawing.Color.Red
        Me.VIPPP.Location = New System.Drawing.Point(286, 97)
        Me.VIPPP.Name = "VIPPP"
        Me.VIPPP.Size = New System.Drawing.Size(220, 36)
        Me.VIPPP.TabIndex = 6
        Me.VIPPP.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'PMP
        '
        Me.PMP.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.PMP.Font = New System.Drawing.Font("宋体", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.PMP.ForeColor = System.Drawing.Color.Red
        Me.PMP.Location = New System.Drawing.Point(286, 158)
        Me.PMP.Name = "PMP"
        Me.PMP.Size = New System.Drawing.Size(220, 36)
        Me.PMP.TabIndex = 7
        Me.PMP.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'PBP
        '
        Me.PBP.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.PBP.Font = New System.Drawing.Font("宋体", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.PBP.ForeColor = System.Drawing.Color.Red
        Me.PBP.Location = New System.Drawing.Point(286, 291)
        Me.PBP.Name = "PBP"
        Me.PBP.Size = New System.Drawing.Size(220, 36)
        Me.PBP.TabIndex = 9
        Me.PBP.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        'Pic
        '
        Me.Pic.Image = CType(resources.GetObject("Pic.Image"), System.Drawing.Image)
        Me.Pic.Location = New System.Drawing.Point(417, 359)
        Me.Pic.Name = "Pic"
        Me.Pic.Size = New System.Drawing.Size(19, 19)
        Me.Pic.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize
        Me.Pic.TabIndex = 11
        Me.Pic.TabStop = False
        '
        'Yes
        '
        Me.Yes.Font = New System.Drawing.Font("宋体", 14.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.Yes.Location = New System.Drawing.Point(413, 350)
        Me.Yes.Name = "Yes"
        Me.Yes.Size = New System.Drawing.Size(93, 37)
        Me.Yes.TabIndex = 10
        Me.Yes.Text = "  确定"
        Me.Yes.UseVisualStyleBackColor = True
        '
        'ACP
        '
        Me.ACP.Font = New System.Drawing.Font("宋体", 21.75!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(134, Byte))
        Me.ACP.Location = New System.Drawing.Point(286, 225)
        Me.ACP.Name = "ACP"
        Me.ACP.Size = New System.Drawing.Size(220, 41)
        Me.ACP.TabIndex = 12
        '
        'Pur
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(617, 410)
        Me.Controls.Add(Me.ACP)
        Me.Controls.Add(Me.Pic)
        Me.Controls.Add(Me.Yes)
        Me.Controls.Add(Me.PBP)
        Me.Controls.Add(Me.PMP)
        Me.Controls.Add(Me.VIPPP)
        Me.Controls.Add(Me.APP)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.APay)
        Me.Controls.Add(Me.pm)
        Me.Controls.Add(Me.VIP)
        Me.Controls.Add(Me.price)
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.Name = "Pur"
        Me.Text = "收银界面"
        CType(Me.Pic, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents price As System.Windows.Forms.Label
    Friend WithEvents VIP As System.Windows.Forms.Label
    Friend WithEvents pm As System.Windows.Forms.Label
    Friend WithEvents APay As System.Windows.Forms.Label
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents APP As System.Windows.Forms.Label
    Friend WithEvents VIPPP As System.Windows.Forms.Label
    Friend WithEvents PMP As System.Windows.Forms.Label
    Friend WithEvents PBP As System.Windows.Forms.Label
    Friend WithEvents Pic As System.Windows.Forms.PictureBox
    Friend WithEvents Yes As System.Windows.Forms.Button
    Friend WithEvents ACP As System.Windows.Forms.TextBox
End Class
