<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>DEMO</title>

    <script language="javascript" type="text/javascript">
// <!CDATA[

function btRealPlay_onclick() 
{
    if(!IsValid())
    {
        alert("Input is empty!");
    }
    else
    {
        var strDvrIP = document.getElementById('tbDvrIP').value;
        var nPort = parseInt(document.getElementById('tbPort').value);
        var strUserName = document.getElementById('tbUserName').value;
        var strPwd = document.getElementById('tbPwd').value;
        var nChannel = parseInt(document.getElementById('tbChannel').value);
        var axRealPlayX = document.getElementById('AV_RealPlayX');
        var bSuccess = axRealPlayX.SetDeviceInfo(strDvrIP, nPort, nChannel, strUserName, strPwd);
        if (bSuccess)
        {
            bSuccess = axRealPlayX.StartPlay();
        }
    }
}

function onunload() 
{
    document.all('AV_RealPlayX').StopPlay();
}

function IsValid()
{
    var bValid = true;
    var strDvrIP = document.getElementById('tbDvrIP').value;
    var strPort = document.getElementById('tbPort').value;
    var strUserName = document.getElementById('tbUserName').value;
    var strChannel = document.getElementById('tbChannel').value;
    if(strDvrIP == "" || strPort == "" || strUserName == "" || strChannel == "")
    {
        bValid = false;
    }
    return bValid;
}

// ]]>
    </script>

</head>
<body onunload="onunload()">
    <form id="form1" runat="server">
        <div>
            <div style="margin: 0px auto; width: 591px; height: 478px; border: solid 2px blue;">
                <object id="AV_RealPlayX" style="width: 100%; height: 100%;" classid="CLSID:30209FBC-57EB-4F87-BF3E-740E3D8019D2">
                    <param name="_Version" value="65536" />
                    <param name="_ExtentX" value="22357" />
                    <param name="_ExtentY" value="16589" />
                    <param name="_StockProps" value="0" />
                </object>
            </div>
            <div style="margin: 0px auto; width: 591px; height: 100px; border-bottom: solid 2px blue;
                border-left: solid 2px blue; border-right: solid 2px blue; background-color: #7183B0;">
                <table cellpadding="0" cellspacing="0" style="margin: 0px auto; width: 590px;">
                    <tr align="center" style="height: 40px;">
                        <td align="right" style="width: 70px;">
                            IP:</td>
                        <td align="left" style="width: 100px;">
                            <input id="tbDvrIP" type="text" style="width: 100px" value="10.12.2.80" />
                        </td>
                        <td align="right" style="width: 70px;">
                            Port:</td>
                        <td align="left" style="width: 50px;">
                            <input id="tbPort" type="text" style="width: 50px" value="37777" />
                        </td>
                        <td align="right" style="width: 70px;">
                            User:</td>
                        <td align="left" style="width: 50px;">
                            <input id="tbUserName" type="text" style="width: 50px" value="admin" />
                        </td>
                        <td align="right" style="width: 50px;">
                            Password:</td>
                        <td align="left" style="width: 50px;">
                            <input id="tbPwd" type="text" style="width: 50px" value="admin" />
                        </td>
                    </tr>
                    <tr align="center" style="height: 40px;">
                        <td align="right" style="width: 70px;">
                            No:</td>
                        <td align="left" style="width: 100px;">
                            <input id="tbChannel" type="text" style="width: 100px" value="0" />
                        </td>
                        <td align="center" colspan="2" style="width: 120px;">
                            <input id="btRealPlay" type="button" value="Play" style="width: 65px" onclick="return btRealPlay_onclick()" />
                        </td>
                        <td align="right" style="width: 70px;">
                        </td>
                        <td align="left" style="width: 50px;">
                        </td>
                        <td align="right" style="width: 50px;">
                        </td>
                        <td align="left" style="width: 50px;">
                        </td>
                    </tr>
                </table>
            </div>
        </div>
    </form>
</body>
</html>
