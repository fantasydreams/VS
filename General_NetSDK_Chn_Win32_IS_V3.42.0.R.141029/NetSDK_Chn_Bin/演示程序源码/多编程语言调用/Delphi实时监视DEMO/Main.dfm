object Form1: TForm1
  Left = 317
  Top = 147
  Width = 870
  Height = 640
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object TreeView1: TTreeView
    Left = 616
    Top = 32
    Width = 193
    Height = 329
    Indent = 19
    TabOrder = 0
    OnChange = TreeView1Change
  end
  object Button1: TButton
    Left = 640
    Top = 400
    Width = 75
    Height = 25
    Caption = 'Add Dev'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 736
    Top = 400
    Width = 75
    Height = 25
    Caption = 'Del Dev'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 640
    Top = 456
    Width = 75
    Height = 25
    Caption = 'Close Chn'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Panel1: TPanel
    Left = 32
    Top = 16
    Width = 513
    Height = 425
    TabOrder = 4
  end
end
