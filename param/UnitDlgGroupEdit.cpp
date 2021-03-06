//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitDlgGroupEdit.h"
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
#pragma link "cxContainer"
#pragma link "cxControls"
#pragma link "cxEdit"
#pragma link "cxLabel"
#pragma link "cxTextEdit"
#pragma link "cxMemo"
#pragma resource "*.dfm"
TDlgGroupEdit *DlgGroupEdit;
//---------------------------------------------------------------------------
__fastcall TDlgGroupEdit::TDlgGroupEdit(TComponent* Owner)
	: TDialogBase(Owner)
{
}
//---------------------------------------------------------------------------
void TDlgGroupEdit::LoadGroupInfo()
{
	if (m_sgGroup.nGroupIndex > 0)
	{
		cxTextEditGroup->Text = m_sgGroup.strGroupName;
		cxMemoNote->Text = m_sgGroup.strNote;
	}
}
//---------------------------------------------------------------------------
void TDlgGroupEdit::SaveGroupInfo()
{
	TADOQuery* pADOQuery = new TADOQuery(NULL);
	pADOQuery->Connection = DataModuleMain->ADOConnectionMain;

	pADOQuery->Connection->BeginTrans();
	try
	{
		String strSQL = "";
		if (m_sgGroup.nGroupIndex > 0)
		{
			strSQL = "UPDATE SCANNER_GROUP SET ";
			strSQL += "GROUP_NAME='" + m_sgGroup.strGroupName + "' ";
			strSQL += ",NOTE='" + m_sgGroup.strNote + "'";
			strSQL += " WHERE GROUP_ID=" + String(m_sgGroup.nGroupIndex);
		}
		else
		{
			strSQL = "SELECT MAX(GROUP_ID) AS MAXID FROM SCANNER_GROUP";
			pADOQuery->Close();
			pADOQuery->SQL->Text = strSQL;
			pADOQuery->Open();
			m_sgGroup.nGroupIndex = pADOQuery->FieldByName("MAXID")->AsInteger + 1;

			strSQL = "INSERT INTO SCANNER_GROUP (GROUP_ID,GROUP_NAME,NOTE) \
				VALUES (" + String(m_sgGroup.nGroupIndex) + ", \
				'" + m_sgGroup.strGroupName + "',\
				'" + m_sgGroup.strNote + "')";
		}

		pADOQuery->Close();
		pADOQuery->SQL->Text = strSQL;
		pADOQuery->ExecSQL();
		pADOQuery->Connection->CommitTrans();
		delete pADOQuery;
	}
	catch (Exception& e)
	{
		pADOQuery->Connection->RollbackTrans();
		delete pADOQuery;
		throw e;
	}
}
//---------------------------------------------------------------------------
void TDlgGroupEdit::SetGroupInfo(SCANNER_GROUP sgGroup)
{
	m_sgGroup = sgGroup;
}
//---------------------------------------------------------------------------
bool TDlgGroupEdit::IsValidGroup()
{
	String strSQL = "SELECT COUNT(GROUP_ID) AS GROUP_COUNT FROM SCANNER_GROUP \
		WHERE GROUP_NAME = '" + m_sgGroup.strGroupName + "' AND \
		GROUP_ID <> " + String(m_sgGroup.nGroupIndex);

	TADOQuery* pADOQuery = new TADOQuery(NULL);
	pADOQuery->Connection = DataModuleMain->ADOConnectionMain;

	pADOQuery->Close();
	pADOQuery->SQL->Text = strSQL;
	pADOQuery->Open();

	int nCnt = pADOQuery->FieldByName("GROUP_COUNT")->AsInteger;
	delete pADOQuery;

	return nCnt == 0 ? true : false;

}
//---------------------------------------------------------------------------
void __fastcall TDlgGroupEdit::cxButtonOkClick(TObject *Sender)
{
    m_sgGroup.strGroupName = cxTextEditGroup->Text;
	m_sgGroup.strNote = cxMemoNote->Text;
	if (! IsValidGroup())
	{
    	ModalResult = mrNone;
		ShowMessage("不合法的组名称，组名称已存在！");
		return;
	}

	try
	{

		SaveGroupInfo();

		ModalResult = mrOk;
	}
	catch (Exception& e)
	{
		ModalResult = mrNone;
		ShowMessage("保存信息失败，错误：" + e.Message);
	}
}
//---------------------------------------------------------------------------

void __fastcall TDlgGroupEdit::FormShow(TObject *Sender)
{
	LoadGroupInfo();
}
//---------------------------------------------------------------------------

