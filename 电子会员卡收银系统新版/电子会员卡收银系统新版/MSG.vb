Imports System.Windows.Forms

Public Class MSG

    Private Sub OK_Button_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
        Me.DialogResult = System.Windows.Forms.DialogResult.OK
        Me.Close()
    End Sub

    Private Sub Cancel_Button_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
        Me.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.Close()
    End Sub

    Private Sub MSGBOX_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        '.BackColor = Color.FromArgb(&HFFFFFFFF)  if set backcolor be white,it looks a little strange
        X.Parent = col
        head.Parent = col

    End Sub
    Private Sub frm_KeyPress(sender As Object, e As KeyPressEventArgs) Handles Me.KeyPress
        If e.KeyChar = ChrW(13) Then   'when press key enter,return ok
            OK_Button_Click(Me, e)
        ElseIf e.KeyChar = ChrW(27) Then  'when press key esc,return cancel
            Cancel_Button_Click(Me, e)
        End If
    End Sub



End Class
