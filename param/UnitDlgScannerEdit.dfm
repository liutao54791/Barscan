inherited DlgScannerEdit: TDlgScannerEdit
  Caption = #25195#30721#26538#32534#36753
  ClientHeight = 259
  ClientWidth = 300
  ExplicitWidth = 306
  ExplicitHeight = 287
  PixelsPerInch = 96
  TextHeight = 12
  inherited PanelButton: TPanel
    Top = 218
    Width = 300
    ExplicitTop = 218
    ExplicitWidth = 300
    inherited cxButtonOk: TcxButton
      Left = 56
      Top = 6
      OnClick = cxButtonOkClick
      ExplicitLeft = 56
      ExplicitTop = 6
    end
    inherited cxButtonCancle: TcxButton
      Left = 169
      Top = 6
      ExplicitLeft = 169
      ExplicitTop = 6
    end
  end
  object dxLayoutControl1: TdxLayoutControl
    Left = 0
    Top = 0
    Width = 300
    Height = 218
    Align = alClient
    TabOrder = 1
    object cxTextEditScanner: TcxTextEdit
      Left = 89
      Top = 63
      Style.BorderColor = clWindowFrame
      Style.BorderStyle = ebs3D
      Style.HotTrack = False
      TabOrder = 2
      Width = 121
    end
    object cxComboBoxTag: TcxComboBox
      Left = 89
      Top = 37
      Style.BorderColor = clWindowFrame
      Style.BorderStyle = ebs3D
      Style.HotTrack = False
      Style.ButtonStyle = bts3D
      Style.PopupBorderStyle = epbsFrame3D
      TabOrder = 1
      Width = 121
    end
    object cxTextEditParam: TcxTextEdit
      Left = 89
      Top = 89
      Style.BorderColor = clWindowFrame
      Style.BorderStyle = ebs3D
      Style.HotTrack = False
      TabOrder = 3
      Width = 121
    end
    object cxMemoNote: TcxMemo
      Left = 89
      Top = 115
      Style.BorderColor = clWindowFrame
      Style.BorderStyle = ebs3D
      Style.HotTrack = False
      TabOrder = 4
      Height = 89
      Width = 185
    end
    object cxTextEditGroup: TcxTextEdit
      Left = 89
      Top = 11
      Properties.ReadOnly = True
      Style.BorderColor = clWindowFrame
      Style.BorderStyle = ebs3D
      Style.HotTrack = False
      TabOrder = 0
      Width = 121
    end
    object dxLayoutControl1Group_Root: TdxLayoutGroup
      AlignHorz = ahLeft
      AlignVert = avTop
      ButtonOptions.Buttons = <>
      Hidden = True
      ShowBorder = False
      Index = -1
    end
    object dxLayoutItem2: TdxLayoutItem
      Parent = dxLayoutControl1Group_Root
      CaptionOptions.Text = #25195#30721#26538#21517#31216#65306
      Control = cxTextEditScanner
      ControlOptions.ShowBorder = False
      Index = 2
    end
    object dxLayoutItem3: TdxLayoutItem
      Parent = dxLayoutControl1Group_Root
      AlignHorz = ahLeft
      CaptionOptions.Text = #25195#30721#26538#26631#31614#65306
      Visible = False
      Control = cxComboBoxTag
      ControlOptions.ShowBorder = False
      Index = 1
    end
    object dxLayoutItem4: TdxLayoutItem
      Parent = dxLayoutControl1Group_Root
      CaptionOptions.AlignHorz = taRightJustify
      CaptionOptions.Text = #25195#30721#26538#21442#25968#65306
      Control = cxTextEditParam
      ControlOptions.ShowBorder = False
      Index = 3
    end
    object dxLayoutItem5: TdxLayoutItem
      Parent = dxLayoutControl1Group_Root
      CaptionOptions.AlignHorz = taRightJustify
      CaptionOptions.Text = #22791#27880#65306
      Control = cxMemoNote
      ControlOptions.ShowBorder = False
      Index = 4
    end
    object dxLayoutItem1: TdxLayoutItem
      Parent = dxLayoutControl1Group_Root
      CaptionOptions.AlignHorz = taRightJustify
      CaptionOptions.Text = #25195#30721#26538#32452#65306
      Control = cxTextEditGroup
      ControlOptions.ShowBorder = False
      Index = 0
    end
  end
  object dxLayoutLookAndFeelListLocal: TdxLayoutLookAndFeelList
    Left = 264
    Top = 32
    object dxLayoutCxLookAndFeel1: TdxLayoutCxLookAndFeel
    end
  end
end
