program Project1;

uses
  Forms,
  Main in 'Main.pas' {Form1},
  dhnetsdk in 'dhnetsdk.pas',
  AddDevice in 'AddDevice.pas' {Form2};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.CreateForm(TForm2, Form2);
  Application.Run;
end.
