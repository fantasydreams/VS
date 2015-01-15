unit AddDevice;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs,StdCtrls,dhnetsdk;

type
  TForm2 = class(TForm)
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Button1: TButton;
    Button2: TButton;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
    di:NET_DEVICEINFO;
    devHandle:LongInt;    
  end;

var
  Form2: TForm2;

implementation

{$R *.dfm}

procedure TForm2.Button1Click(Sender: TObject);
var perror:PInteger;
var error:integer;
var strIp,strUser,strPwd: array[0..254] of Char;
begin
        perror := @error;
        StrPCopy(strIp,edit1.Text);
        StrPCopy(strUser,edit2.Text);
        strPcopy(strPwd,edit3.Text);
        devHandle := CLIENT_Login(PAnsiChar(AnsiString(edit1.Text)),Word(37777),PAnsiChar(AnsiString(edit2.Text)),PAnsiChar(AnsiString(edit3.Text)),di,perror);
        //devHandle := CLIENT_Login(strIp,Word(37777),strUser,strPwd,di,perror);
        if devHandle > 0 then
        begin
                ShowMessage('Login'+edit1.Text+'success');
                Close;
        end
        else
        begin
                ShowMessage('Login'+edit1.Text+'failed');
        end
end;

procedure TForm2.Button2Click(Sender: TObject);
begin
        Close;
end;

end.
