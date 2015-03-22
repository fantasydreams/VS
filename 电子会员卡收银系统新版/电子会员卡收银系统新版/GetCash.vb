Public Class GetCash


    Private Sub GetCash_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        Me.Width = Login.ScreenWidth
        Me.Height = Login.ScreenHeight

        ' Me.TransparencyKey = Me.BackColor

        column.Size = New Size(Me.Width, 40)
        F4.Parent = column
        F5.Parent = column
        Esc.Parent = column

        Dim str As String
        str = cash.Text
        Me.Text = cash.Text
        cash.Text = str

        Me.Show()

    End Sub
End Class