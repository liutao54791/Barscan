object FormProgressbar: TFormProgressbar
  Left = 500
  Top = 288
  BorderStyle = bsDialog
  Caption = #36827#24230
  ClientHeight = 61
  ClientWidth = 363
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = #23435#20307
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 12
  object cxGroupBoxMain: TcxGroupBox
    Left = 0
    Top = 0
    Align = alClient
    Alignment = alTopCenter
    ParentFont = False
    Style.Font.Charset = GB2312_CHARSET
    Style.Font.Color = clWindowText
    Style.Font.Height = -15
    Style.Font.Name = #40657#20307
    Style.Font.Style = []
    Style.LookAndFeel.Kind = lfUltraFlat
    Style.IsFontAssigned = True
    StyleDisabled.LookAndFeel.Kind = lfUltraFlat
    StyleFocused.LookAndFeel.Kind = lfUltraFlat
    StyleHot.LookAndFeel.Kind = lfUltraFlat
    TabOrder = 0
    Height = 61
    Width = 363
    object cxProgressBarMain: TcxProgressBar
      Left = 3
      Top = 23
      Align = alTop
      ParentFont = False
      Properties.AnimationSpeed = 0
      Properties.BarStyle = cxbsAnimation
      Properties.BeginColor = 54056
      Style.Font.Charset = GB2312_CHARSET
      Style.Font.Color = clWindowText
      Style.Font.Height = -12
      Style.Font.Name = #23435#20307
      Style.Font.Style = []
      Style.LookAndFeel.Kind = lfUltraFlat
      Style.IsFontAssigned = True
      StyleDisabled.LookAndFeel.Kind = lfUltraFlat
      StyleFocused.LookAndFeel.Kind = lfUltraFlat
      StyleHot.LookAndFeel.Kind = lfUltraFlat
      TabOrder = 0
      Width = 357
    end
  end
end