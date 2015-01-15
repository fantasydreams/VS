unit Main;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ComCtrls, ExtCtrls,AddDevice,dhnetsdk ;

type
  TForm1 = class(TForm)
    TreeView1: TTreeView;
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Panel1: TPanel;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure FormActivate(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure TreeView1Change(Sender: TObject; Node: TTreeNode);
  private
    { Private declarations }
  public
    { Public declarations }
    di:NET_DEVICEINFO;
    devHandle:LongInt;

    chnReal: LongInt;

    curChn: Byte;
  end;

var
  Form1: TForm1;

(************************************************************************
 ** 服务器断开函数
 ***********************************************************************)
procedure DisConnect (lLoginID: LongInt; strDVRIP: Pchar; nDVRPort: LongInt;  dwUser: LongWord); stdcall;

(************************************************************************
 ** SDK消息处理函数
 ***********************************************************************)
function MessCallBack (lCommand,lLoginID:LongInt; var pBuf;
			dwBufLen:LongWord; strDVRIP:Pchar; nDVRPort:LongInt; dwUser: LongWord ):LongBool;stdcall;

(************************************************************************
 ** 屏幕叠加回调处理函数
 ***********************************************************************)
procedure DrawCallBack (lLoginID,lPlayHandle:LongInt; hDC: THandle; dwUser:LongInt); stdcall;


implementation

{$R *.dfm}

(************************************************************************
 ** 服务器断开函数
 ***********************************************************************)
procedure DisConnect (lLoginID: LongInt; strDVRIP: Pchar; nDVRPort: LongInt;  dwUser: LongWord); stdcall;
begin

end;

(************************************************************************
 ** SDK消息处理函数
 ***********************************************************************)
function MessCallBack (lCommand,lLoginID:LongInt; var pBuf;
			dwBufLen:LongWord; strDVRIP:Pchar; nDVRPort:LongInt; dwUser: LongWord ):LongBool;stdcall;
begin
    Result:= True;
end;

(************************************************************************
 ** 屏幕叠加回调处理函数
 ***********************************************************************)
procedure DrawCallBack (lLoginID,lPlayHandle:LongInt; hDC: THandle; dwUser:LongInt); stdcall;
begin

end;



procedure TForm1.Button1Click(Sender: TObject);
var addform:TForm2;
var i:Byte;
var MyNode,ChildNode:TTreeNode;
var P:Pbyte;
begin
        //Application.CreateForm(TForm2,Form2);
        addform := TForm2.Create(Form1);
        addform.ShowModal();
        di := addform.di;
        devHandle := addform.devHandle;
        addform.Destroy;

        if devHandle > 0 then
        begin
                MyNode := TreeView1.Items.Add(nil,'Device');
                MyNode.Data := Ptr(-1);
                for i := 1 to di.byChanNum do
                begin
                       ChildNode := TreeView1.Items.AddChild(MyNode, Format('Channel--%d',[i]));
                       GetMem(P,Sizeof(Byte));
                       p^ := i-1;
                       ChildNode.Data := Pointer(p);
                end
        end;

        Self.SetFocus;
end;

procedure TForm1.Button2Click(Sender: TObject);
var bRet:LongBool;
begin
        bRet := CLIENT_Logout(devHandle);
        if bRet = False then
        begin
                ShowMessage('Logout device failed');
        end
        else
        begin
                ShowMessage('Logout device success');
                devHandle := 0;
        end
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
        if chnReal > 0 then
        begin
                CLIENT_StopRealPlay(chnReal);
                chnReal := 0;
        end
end;

procedure TForm1.FormActivate(Sender: TObject);
var bRet:LongBool;
begin
        bRet:= CLIENT_Init(DisConnect,0);
        if bRet = False then
        begin
                ShowMessage('Init dhnetsdk failed');
        end
        else
        begin
                ShowMessage('Init dhnetsdk success');
                CLIENT_SetConnectTime(3000,3);
        end
end;

procedure TForm1.FormClose(Sender: TObject; var Action: TCloseAction);
begin
        CLIENT_Cleanup;
end;

procedure TForm1.TreeView1Change(Sender: TObject; Node: TTreeNode);
var Chn:Byte;
begin
      if Node.Data <> Pointer(-1) then
      begin

        chn := PByte(Node.data)^;

        chnReal := CLIENT_RealPlay(devHandle,Integer(chn),Panel1.Handle);


        if (chnReal > 0) then
        begin
                //ShowMessage('open RealPlay success');
        end
        else
        begin
                ShowMessage('open RealPlay failed');
                chnReal := 0;
        end

      end
end;

end.
