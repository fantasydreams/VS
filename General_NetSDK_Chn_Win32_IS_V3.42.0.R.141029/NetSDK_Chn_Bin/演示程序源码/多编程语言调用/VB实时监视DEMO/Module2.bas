Attribute VB_Name = "Module2"

Public Type NET_DEVICEINFO      '�豸�Ľṹ��
    sSerialNumber As String * 48
    byAlarmInPortNum As Byte
    byAlarmOutPortNum As Byte
    byDiskNum As Byte
    byDVRType As Byte
    byChanNum As Byte
End Type

Public Type NET_RET_ERROR
    errcode As Integer
End Type

'��ʼ���ص�����
Public Sub IniFunc(ByVal lLoginID As Long, ByVal pchDVRIP As Long, ByVal nDVRPort As Long, ByVal dwUser As Long)
Form1.Text1.Text = lLoginID
End Sub

'��Ϣ�ص�����

Public Sub MessFunc(ByVal lCommand As Long, _
  ByVal lLoginID As Long, ByVal pBuf As Long, _
  ByVal dwBufLen As Long, ByVal pchDVRIP As Long, _
  ByVal nDVRPort As Long, ByVal dwUser As Long)


    Form1.Text1.Text = lLoginID
    Form1.Text2.Text = pBuf
    Form1.Text3.Text = pchDVRIP

End Sub


'�ص�����ָ�봫��
Public Function PtrToLong(ByVal func As Long) As Long
    PtrToLong = func
End Function

