//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitDlgScannerEdit.h"
#include "UnitDataModuleMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "cxButtons"
#pragma link "cxGraphics"
#pragma link "cxLookAndFeelPainters"
#pragma link "cxLookAndFeels"
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
#pragma link "cxClasses"
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxDropDownEdit"
#pragma link "cxEdit"
#pragma link "cxMaskEdit"
#pragma link "cxTextEdit"
#pragma link "dxLayoutContainer"
#pragma link "dxLayoutControl"
#pragma link "dxLayoutcxEditAdapters"
#pragma link "dxLayoutLookAndFeels"
#pragma link "dxSkinscxPCPainter"
#pragma link "cxMemo"
#pragma resource "*.dfm"
TDlgScannerEdit *DlgScannerEdit;
//---------------------------------------------------------------------------
__fastcall TDlgScannerEdit::TDlgScannerEdit(TComponent* Owner)
	: TDialogBase(Owner)
{
}
//---------------------------------------------------------------------------
void TDlgScannerEdit::LoadScannerInfo()
{
	cxTextEditGroup->Text = m_sScanner.strGroupName;

	if (m_sScanner.nScannerIndex > 0)
	{
		//tag
		cxComboBoxTag->Text = String(m_sScanner.nScannerTag);
		//name
		cxTextEditScanner->Text = m_sScanner.strScannerName;
		//param
		cxTextEditParam->Text = m_sScanner.strScannerParam;
		//note
		cxMemoNote->Text = m_sScanner.strNote;
	}
}
//---------------------------------------------------------------------------
void TDlgScannerEdit::SaveScannerInfo()
{
	TADOQuery* pADOQuery = new TADOQuery(NULL);
	pADOQuery->Connection = DataModuleMain->ADOConnectionMain;

	pADOQuery->Connection->BeginTrans();
	try
	{
		String strSQL = "";
		if (m_sScanner.nScannerIndex > 0)
		{
			strSQL = "UPDATE SCANNER SET ";
			strSQL += "SCANNER_NAME='" + m_sScanner.strScannerName + "' ";
			strSQL += ",SCANNER_PARAM='" + m_sScanner.strScannerParam + "' ";
			strSQL += ",NOTE='" + m_sScanner.strNote + "'";
			strSQL += " WHERE SCANNER_ID=" + String(m_sScanner.nScannerIndex);
		}
		else
		{
			strSQL = "SELECT MAX(SCANNER_ID) AS MAXID FROM SCANNER";
			pADOQuery->Close();
			pADOQuery->SQL->Text = strSQL;
			pADOQuery->Open();
			m_sScanner.nScannerIndex = pADOQuery->FieldByName("MAXID")->AsInteger + 1;

			strSQL = "SELECT MAX(SCANNER_TAG) AS MAXID FROM SCANNER \
				WHERE GROUP_ID =" +  String(m_sScanner.nGroupIndex);
			pADOQuery->Close();
			pADOQuery->SQL->Text = strSQL;
			pADOQuery->Open();
			m_sScanner.nScannerTag = pADOQuery->FieldByName("MAXID")->AsInteger + 1;

			strSQL = "INSERT INTO SCANNER (SCANNER_ID,GROUP_ID,SCANNER_TAG,\
				SCANNER_NAME,SCANNER_PARAM,NOTE) \
				VALUES (" + String(m_sScanner.nScannerIndex) + ", \
				" + String(m_sScanner.nGroupIndex) + ", \
				" + String(m_sScanner.nScannerTag) + ", \
				'" + m_sScanner.strScannerName + "',\
				'" + m_sScanner.strScannerParam + "',\
				'" + m_sScanner.strNote + "')";
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
void TDlgScannerEdit::SetScannerInfo(SCANNER sScanner)
{
	m_sScanner = sScanner;
}
//---------------------------------------------------------------------------
void __fastcall TDlgScannerEdit::cxButtonOkClick(TObject *Sender)
{
	try
	{
		m_sScanner.strScannerName = cxTextEditScanner->Text;
		m_sScanner.strScannerParam = cxTextEditParam->Text;
		m_sScanner.strNote = cxMemoNote->Text;

		SaveScannerInfo();

		ModalResult = mrOk;
	}
	catch (Exception& e)
	{
		ModalResult = mrNone;
		ShowMessage("������Ϣʧ�ܣ�����" + e.Message);
	}
}
//---------------------------------------------------------------------------
void __fastcall TDlgScannerEdit::FormShow(TObject *Sender)
{
	LoadScannerInfo();
}
//---------------------------------------------------------------------------


