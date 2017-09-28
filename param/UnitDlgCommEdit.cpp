﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream.h>

#include "UnitDlgCommEdit.h"

#include "SocketServerNet.h"

#include <System.IniFiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "cxMaskEdit"
#pragma link "cxSpinEdit"
#pragma link "cxTextEdit"
#pragma link "dxLayoutContainer"
#pragma link "dxLayoutControl"
#pragma link "dxLayoutcxEditAdapters"
#pragma link "dxLayoutLookAndFeels"
#pragma link "dxSkinBlack"
#pragma link "dxSkinBlue"
#pragma link "dxSkinBlueprint"
#pragma link "dxSkinCaramel"
#pragma link "dxSkinCoffee"
#pragma link "dxSkinDarkRoom"
#pragma link "dxSkinDarkSide"
#pragma link "dxSkinDevExpressDarkStyle"
#pragma link "dxSkinDevExpressStyle"
#pragma link "dxSkinFoggy"
#pragma link "dxSkinGlassOceans"
#pragma link "dxSkinHighContrast"
#pragma link "dxSkiniMaginary"
#pragma link "dxSkinLilian"
#pragma link "dxSkinLiquidSky"
#pragma link "dxSkinLondonLiquidSky"
#pragma link "dxSkinMcSkin"
#pragma link "dxSkinMetropolis"
#pragma link "dxSkinMetropolisDark"
#pragma link "dxSkinMoneyTwins"
#pragma link "dxSkinOffice2007Black"
#pragma link "dxSkinOffice2007Blue"
#pragma link "dxSkinOffice2007Green"
#pragma link "dxSkinOffice2007Pink"
#pragma link "dxSkinOffice2007Silver"
#pragma link "dxSkinOffice2010Black"
#pragma link "dxSkinOffice2010Blue"
#pragma link "dxSkinOffice2010Silver"
#pragma link "dxSkinOffice2013DarkGray"
#pragma link "dxSkinOffice2013LightGray"
#pragma link "dxSkinOffice2013White"
#pragma link "dxSkinOffice2016Colorful"
#pragma link "dxSkinOffice2016Dark"
#pragma link "dxSkinPumpkin"
#pragma link "dxSkinsCore"
#pragma link "dxSkinscxPCPainter"
#pragma link "dxSkinsDefaultPainters"
#pragma link "dxSkinSeven"
#pragma link "dxSkinSevenClassic"
#pragma link "dxSkinSharp"
#pragma link "dxSkinSharpPlus"
#pragma link "dxSkinSilver"
#pragma link "dxSkinSpringTime"
#pragma link "dxSkinStardust"
#pragma link "dxSkinSummer2008"
#pragma link "dxSkinTheAsphaltWorld"
#pragma link "dxSkinValentine"
#pragma link "dxSkinVisualStudio2013Blue"
#pragma link "dxSkinVisualStudio2013Dark"
#pragma link "dxSkinVisualStudio2013Light"
#pragma link "dxSkinVS2010"
#pragma link "dxSkinWhiteprint"
#pragma link "dxSkinXmas2008Blue"
#pragma link "UnitDialogBase"
#pragma link "dxScreenTip"
#pragma resource "*.dfm"   //#pragma resource "*.dfm"表示把*.dfm文件中的资源加入工程。*.dfm中包括窗体外观的定义。
TDlgCommEdit *DlgCommEdit;

//---------------------------------------------------------------------------
__fastcall TDlgCommEdit::TDlgCommEdit(TComponent* Owner)
	: TDialogBase(Owner)
{

}

//---------------------------------------------------------------------------
void TDlgCommEdit::LoadConfigure()
{
	String strFileName = ChangeFileExt(ParamStr(0),".ini");
	TIniFile* pifReader = new TIniFile(strFileName);

	cxTextEditIp->Text = pifReader->ReadString("DEVICE","IP","");
	cxSpinEditPort->Value = pifReader->ReadInteger("DEVICE","PORT",11240);

	cxTextEditUDPIp->Text = pifReader->ReadString("UDPSERVER","IP","");
	cxSpinEditUDPPort->Value = pifReader->ReadInteger("UDPSERVER","PORT",11260);

	char    Buffer[64];
	HOSTENT FAR *pHost;
	String  IPAddress;

	gethostname(Buffer, 64);
	pHost  = gethostbyname(Buffer);
	IPAddress = inet_ntoa(*(struct in_addr*)pHost->h_addr_list[0]);

	cxTextTCPServerIP->Text = IPAddress;
	delete pifReader;
}
//---------------------------------------------------------------------------
void TDlgCommEdit::SaveConfigure()
{
	String strFileName = ChangeFileExt(ParamStr(0),".ini");
	TIniFile* pifWriter = new TIniFile(strFileName);

	pifWriter->WriteString("DEVICE","IP",cxTextEditIp->Text );
	pifWriter->WriteInteger("DEVICE","PORT",cxSpinEditPort->Value);

	pifWriter->WriteString("UDPSERVER","IP",cxTextEditUDPIp->Text );
	pifWriter->WriteInteger("UDPSERVER","PORT",cxSpinEditUDPPort->Value);

	delete pifWriter;
}

void __fastcall TDlgCommEdit::cxButtonOkClick(TObject *Sender)
{
	SaveConfigure();

	static TidServerNet* ServerNet = NULL;
	if (ServerNet == NULL)
	{
		ServerNet = new TidServerNet();
		if (ServerNet->Init(cxSpinEditTCPServerPort->Value) == SocketOk)
		{
			ServerNet->Run();
			
		}
	}else
	{
		ShowMessage(cxTextEditUDPIp->Text.c_str());
		ShowMessage("TCP Server Already Run");
	}

}
//---------------------------------------------------------------------------
void __fastcall TDlgCommEdit::FormShow(TObject *Sender)
{
	LoadConfigure();
}
//---------------------------------------------------------------------------




