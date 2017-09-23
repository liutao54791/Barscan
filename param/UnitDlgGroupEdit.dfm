inherited DlgGroupEdit: TDlgGroupEdit
  Caption = #25195#30721#26538#32452#32534#36753
  ClientHeight = 191
  ClientWidth = 432
  ExplicitWidth = 438
  ExplicitHeight = 219
  PixelsPerInch = 96
  TextHeight = 12
  inherited PanelButton: TPanel
    Top = 150
    Width = 432
    ExplicitTop = 150
    ExplicitWidth = 432
    inherited cxButtonOk: TcxButton
      Left = 112
      Top = 6
      OnClick = cxButtonOkClick
      ExplicitLeft = 112
      ExplicitTop = 6
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 432
    Height = 150
    Align = alClient
    TabOrder = 1
    object cxTextEditGroup: TcxTextEdit
      Left = 136
      Top = 17
      TabOrder = 0
      Width = 249
    end
    object cxLabel1: TcxLabel
      Left = 42
      Top = 18
      Caption = #25195#30721#26538#32452#21517#31216#65306
      Properties.Alignment.Horz = taRightJustify
      AnchorX = 130
    end
    object cxMemoNote: TcxMemo
      Left = 136
      Top = 43
      TabOrder = 2
      Height = 89
      Width = 249
    end
    object cxLabel2: TcxLabel
      Left = 90
      Top = 67
      Caption = #22791#27880#65306
      Properties.Alignment.Horz = taRightJustify
      AnchorX = 130
    end
  end
end
