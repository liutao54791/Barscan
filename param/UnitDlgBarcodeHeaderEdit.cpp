//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitDlgBarcodeHeaderEdit.h"
#include "UnitDataModuleMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxClasses"
#pragma link "cxControls"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
#pragma link "dxLayoutContainer"
#pragma link "dxLayoutControl"
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
#pragma link "cxContainer"
#pragma link "cxEdit"
#pragma link "cxTextEdit"
#pragma link "dxLayoutcxEditAdapters"
#pragma link "cxDropDownEdit"
#pragma link "cxMaskEdit"
#pragma link "cxMemo"
#pragma link "cxSpinEdit"
#pragma resource "*.dfm"
TDlgBarcodeHeaderEdit *DlgBarcodeHeaderEdit;
//---------------------------------------------------------------------------
__fastcall TDlgBarcodeHeaderEdit::TDlgBarcodeHeaderEdit(TComponent* Owner)
	: TDialogBase(Owner)
{
}
//---------------------------------------------------------------------------
void TDlgBarcodeHeaderEdit::LoadBarcodeHeaderInfo()
{
	if (m_bhHeader.nHeaderIndex > 0)
	{
		cxSpinEditOrder->Value = m_bhHeader.nBarcodeOrder;
		cxTextEditBarcodeHeader->Text = m_bhHeader.strBarcodeTitle;
		cxMemoNote->Text = m_bhHeader.strNote;
	}
}
//---------------------------------------------------------------------------
void TDlgBarcodeHeaderEdit::SaveBarcodeHeaderInfo()
{
	TADOQuery* pADOQuery = new TADOQuery(NULL);
	pADOQuery->Connection = DataModuleMain->ADOConnectionMain;

	pADOQuery->Connection->BeginTrans();
	try
	{
		String strSQL = "";
		if (m_bhHeader.nHeaderIndex > 0)
		{
			strSQL = "UPDATE BARCODE_HEADER SET ";
			strSQL += "HEADER_NAME='" + m_bhHeader.strBarcodeTitle + "' ";
			strSQL += ",BARCODE_ORDER=" + String(m_bhHeader.nBarcodeOrder);
			strSQL += ",NOTE='" + m_bhHeader.strNote + "'";
			strSQL += " WHERE HEADER_ID=" + String(m_bhHeader.nHeaderIndex);
		}
		else
		{
			strSQL = "SELECT MAX(HEADER_ID) AS MAXID FROM BARCODE_HEADER";
			pADOQuery->Close();
			pADOQuery->SQL->Text = strSQL;
			pADOQuery->Open();
			m_bhHeader.nHeaderIndex = pADOQuery->FieldByName("MAXID")->AsInteger + 1;

			strSQL = "INSERT INTO BARCODE_HEADER (HEADER_ID,SCANNER_ID,\
				BARCODE_ORDER,HEADER_NAME,NOTE) \
				VALUES (" + String(m_bhHeader.nHeaderIndex) + ", \
				" + String(m_bhHeader.nScannerIndex) + ", \
				" + String(m_bhHeader.nBarcodeOrder) + ", \
				'" + m_bhHeader.strBarcodeTitle + "',\
				'" + m_bhHeader.strNote + "')";
		}

		pADOQuery->Close();
		pADOQuery->SQL->Text = strSQL;
		pADOQuery->ExecSQL();
		pADOQuery->Connection->CommitTrans();
	}
	catch (Exception& e)
	{
		pADOQuery->Connection->RollbackTrans();
		delete pADOQuery;
		throw e;
	}
}
//---------------------------------------------------------------------------
void TDlgBarcodeHeaderEdit::SetBarcodeHeaderInfo(BARCODE_HEADER bhHeader)
{
	m_bhHeader = bhHeader;
}
//---------------------------------------------------------------------------
void __fastcall TDlgBarcodeHeaderEdit::FormShow(TObject *Sender)
{
	LoadBarcodeHeaderInfo();
}
//---------------------------------------------------------------------------
void __fastcall TDlgBarcodeHeaderEdit::cxButtonOkClick(TObject *Sender)
{
	m_bhHeader.nBarcodeOrder = cxSpinEditOrder->Value;
	m_bhHeader.strBarcodeTitle = cxTextEditBarcodeHeader->Text;
	m_bhHeader.strNote = cxMemoNote->Text;

	try
	{
		SaveBarcodeHeaderInfo();

		ModalResult = mrOk;
	}
	catch (Exception& e)
	{
		ModalResult = mrNone;
		ShowMessage("±£¥Ê–≈œ¢ ß∞‹£¨¥ÌŒÛ£∫" + e.Message);
	}
}
//---------------------------------------------------------------------------
