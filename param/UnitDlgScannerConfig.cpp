﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitDlgScannerConfig.h"
#include "UnitDlgGroupEdit.h"
#include "UnitDlgScannerEdit.h"
#include "UnitDlgBarcodeHeaderEdit.h"
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
#pragma link "cxControls"
#pragma link "cxCustomData"
#pragma link "cxData"
#pragma link "cxDataStorage"
#pragma link "cxDBData"
#pragma link "cxEdit"
#pragma link "cxFilter"
#pragma link "cxGrid"
#pragma link "cxGridCustomTableView"
#pragma link "cxGridCustomView"
#pragma link "cxGridDBTableView"
#pragma link "cxGridLevel"
#pragma link "cxGridTableView"
#pragma link "cxNavigator"
#pragma link "cxStyles"
#pragma link "dxLayoutContainer"
#pragma link "dxLayoutControl"
#pragma link "dxLayoutControlAdapters"
#pragma link "dxLayoutLookAndFeels"
#pragma link "dxSkinscxPCPainter"
#pragma resource "*.dfm"
TDlgScannerConfig *DlgScannerConfig;
//---------------------------------------------------------------------------
__fastcall TDlgScannerConfig::TDlgScannerConfig(TComponent* Owner)
	: TDialogBase(Owner)
{
	ADOQueryGroup->Connection = DataModuleMain->ADOConnectionMain;
	ADOQueryScanner->Connection = DataModuleMain->ADOConnectionMain;
	ADOQueryBarcode->Connection = DataModuleMain->ADOConnectionMain;
}
//---------------------------------------------------------------------------
void TDlgScannerConfig::LoadGroups()
{
	String strSQL = "SELECT GROUP_ID,GROUP_NAME,NOTE FROM SCANNER_GROUP \
		ORDER BY GROUP_ID";

	ADOQueryGroup->Close();
	ADOQueryGroup->SQL->Text = strSQL;
	ADOQueryGroup->Open();
}
//---------------------------------------------------------------------------
void TDlgScannerConfig::LoadScanners()
{
	String strSQL = "SELECT SCANNER_ID,GROUP_ID,SCANNER_TAG,SCANNER_NAME, \
		SCANNER_PARAM,NOTE \
		FROM SCANNER \
		ORDER BY GROUP_ID,SCANNER_ID";

	ADOQueryScanner->Close();
	ADOQueryScanner->SQL->Text = strSQL;
	ADOQueryScanner->Open();
}
//---------------------------------------------------------------------------
void TDlgScannerConfig::LoadBarcodes()
{
	String strSQL = "SELECT SCANNER_ID,HEADER_ID,HEADER_NAME,BARCODE_ORDER,NOTE \
		FROM BARCODE_HEADER \
		ORDER BY SCANNER_ID,HEADER_ID";

	ADOQueryBarcode->Close();
	ADOQueryBarcode->SQL->Text = strSQL;
	ADOQueryBarcode->Open();
}
//---------------------------------------------------------------------------
void TDlgScannerConfig::LoadBarcodes(int nScannerId)
{
	ADOQueryBarcode->Filtered = false;
	ADOQueryBarcode->Filter = "SCANNER_ID = " + String(nScannerId);
	ADOQueryBarcode->Filtered = true;
}
//---------------------------------------------------------------------------
void __fastcall TDlgScannerConfig::cxButtonAddScannerClick(TObject *Sender)
{
	if (cxGridScanner->FocusedView == cxGridScannerDBTableViewGroup)
	{
		SCANNER_GROUP sgGroup;
		sgGroup.nGroupIndex = 0;

		TDlgGroupEdit* pdlgGroup = new TDlgGroupEdit(NULL);
		pdlgGroup->SetGroupInfo(sgGroup);
		if (pdlgGroup->ShowModal() == mrOk)
		{
			LoadGroups();
		}
		delete pdlgGroup;
	}
	else
	{
		SCANNER sScanner;
		sScanner.nScannerIndex = 0;
		TcxGridDBDataController* pdcControl = cxGridScannerDBTableViewGroup->DataController;
		int nRowIndex = pdcControl->FocusedRowIndex;
		int nColIndex = cxGridScannerDBTableViewGroupGROUP_ID->Index;
		sScanner.nGroupIndex = pdcControl->DisplayTexts[nRowIndex][nColIndex].ToInt();
		nColIndex = cxGridScannerDBTableViewGroupGROUP_NAME->Index;
		sScanner.strGroupName = pdcControl->DisplayTexts[nRowIndex][nColIndex];

		TDlgScannerEdit* pdlgScanner = new TDlgScannerEdit(NULL);
		pdlgScanner->SetScannerInfo(sScanner);
		if (pdlgScanner->ShowModal() == mrOk)
		{
			LoadScanners();
		}
		delete pdlgScanner;
	}
}

//---------------------------------------------------------------------------

void __fastcall TDlgScannerConfig::cxButtonEditScannerClick(TObject *Sender)
{
	TcxCustomDataController* pdcControl = cxGridScanner->FocusedView->DataController;
	if (cxGridScanner->FocusedView == cxGridScannerDBTableViewGroup)
	{
		SCANNER_GROUP sgGroup;
		int nRowIndex = pdcControl->FocusedRowIndex;
		if (nRowIndex < 0)
		{
			ShowMessage("选择要修改的扫码枪组！");
			return;
		}
		int nColIndex = cxGridScannerDBTableViewGroupGROUP_ID->Index;
		sgGroup.nGroupIndex = pdcControl->DisplayTexts[nRowIndex][nColIndex].ToInt();
		nColIndex = cxGridScannerDBTableViewGroupGROUP_NAME->Index;
		sgGroup.strGroupName = pdcControl->DisplayTexts[nRowIndex][nColIndex];
		nColIndex = cxGridScannerDBTableViewGroupNOTE->Index;
		sgGroup.strNote = pdcControl->DisplayTexts[nRowIndex][nColIndex];

		TDlgGroupEdit* pdlgGroup = new TDlgGroupEdit(NULL);
		pdlgGroup->SetGroupInfo(sgGroup);
		if (pdlgGroup->ShowModal() == mrOk)
		{
			LoadGroups();
		}
		delete pdlgGroup;
	}
	else
	{
		SCANNER sScanner;
		sScanner.nScannerIndex = 0;

		int nRowIndex = pdcControl->FocusedRowIndex;
		if (nRowIndex < 0)
		{
			ShowMessage("选择要修改的扫码枪组！");
			return;
		}
		int nColIndex = cxGridScannerDBTableViewScannerSCANNER_ID->Index;
		sScanner.nScannerIndex = pdcControl->DisplayTexts[nRowIndex][nColIndex].ToInt();
		nColIndex = cxGridScannerDBTableViewScannerSCANNER_TAG->Index;
		sScanner.nScannerTag = pdcControl->DisplayTexts[nRowIndex][nColIndex].ToInt();
		nColIndex = cxGridScannerDBTableViewScannerSCANNER_NAME->Index;
		sScanner.strScannerName = pdcControl->DisplayTexts[nRowIndex][nColIndex];
		nColIndex = cxGridScannerDBTableViewScannerSCANNER_PARAM->Index;
		sScanner.strScannerParam = pdcControl->DisplayTexts[nRowIndex][nColIndex];
		nColIndex = cxGridScannerDBTableViewScannerNOTE->Index;
		sScanner.strNote = pdcControl->DisplayTexts[nRowIndex][nColIndex];
		nColIndex = cxGridScannerDBTableViewScannerGROUP_ID->Index;
		sScanner.nGroupIndex = pdcControl->DisplayTexts[nRowIndex][nColIndex].ToInt();
		TLocateOptions loOpts;
		Variant varKey(sScanner.nGroupIndex);
		if (ADOQueryGroup->Locate("GROUP_ID",varKey,loOpts))
			sScanner.strGroupName = ADOQueryGroup->FieldByName("GROUP_NAME")->AsString;

		TDlgScannerEdit* pdlgScanner = new TDlgScannerEdit(NULL);
		pdlgScanner->SetScannerInfo(sScanner);
		if (pdlgScanner->ShowModal() == mrOk)
		{
			LoadScanners();
		}
		delete pdlgScanner;
	}
}
//---------------------------------------------------------------------------

void __fastcall TDlgScannerConfig::FormShow(TObject *Sender)
{
	LoadGroups();
	LoadScanners();
}
//---------------------------------------------------------------------------
void __fastcall TDlgScannerConfig::cxButtonAddBarcodeClick(TObject *Sender)
{
	if (cxGridScanner->FocusedView == cxGridScannerDBTableViewGroup)
	{
		ShowMessage("选中对应的扫码枪！");
		return;
	}

	TcxCustomDataController* pdcControl = cxGridScanner->FocusedView->DataController;
	int nRowIndex = pdcControl->FocusedRowIndex;
	int nColIndex = cxGridScannerDBTableViewScannerSCANNER_ID->Index;

	if (nRowIndex < 0)
	{
		ShowMessage("选中对应的扫码枪！");
		return;
	}

	BARCODE_HEADER bhHeader;
	bhHeader.nScannerIndex = pdcControl->DisplayTexts[nRowIndex][nColIndex].ToInt();
	bhHeader.nHeaderIndex = 0;

	TDlgBarcodeHeaderEdit* pdlgHeader = new TDlgBarcodeHeaderEdit(NULL);
	pdlgHeader->SetBarcodeHeaderInfo(bhHeader);
	if (pdlgHeader->ShowModal() == mrOk)
	{
		LoadBarcodes();
		LoadBarcodes(bhHeader.nScannerIndex);
	}
	delete pdlgHeader;
}
//---------------------------------------------------------------------------

void __fastcall TDlgScannerConfig::cxButtonEditBarcodeClick(TObject *Sender)
{
	TcxGridDBDataController* pdcControl = cxGridBarcodeDBTableViewBarcode->DataController;

	BARCODE_HEADER bhHeader;

	int nRowIndex = pdcControl->FocusedRowIndex;
	int nColIndex = cxGridBarcodeDBTableViewBarcodeHEADER_ID->Index;
	bhHeader.nHeaderIndex = pdcControl->DisplayTexts[nRowIndex][nColIndex].ToInt();
	nColIndex = cxGridBarcodeDBTableViewBarcodeSCANNER_ID->Index;
	bhHeader.nScannerIndex = pdcControl->DisplayTexts[nRowIndex][nColIndex].ToInt();
	nColIndex = cxGridBarcodeDBTableViewBarcodeHEADER_NAME->Index;
	bhHeader.strBarcodeTitle = pdcControl->DisplayTexts[nRowIndex][nColIndex];
	nColIndex = cxGridBarcodeDBTableViewBarcodeBARCODE_ORDER->Index;
	bhHeader.nBarcodeOrder = pdcControl->DisplayTexts[nRowIndex][nColIndex].ToInt();
	nColIndex = cxGridBarcodeDBTableViewBarcodeNOTE->Index;
	bhHeader.strNote = pdcControl->DisplayTexts[nRowIndex][nColIndex];

	TDlgBarcodeHeaderEdit* pdlgHeader = new TDlgBarcodeHeaderEdit(NULL);
	pdlgHeader->SetBarcodeHeaderInfo(bhHeader);
	if (pdlgHeader->ShowModal() == mrOk)
	{
		LoadBarcodes();
		LoadBarcodes(bhHeader.nScannerIndex);
	}
	delete pdlgHeader;

}
//---------------------------------------------------------------------------

void __fastcall TDlgScannerConfig::cxButtonRemoveBarcodeClick(TObject *Sender)
{
	TcxGridDBDataController* pdcControl = cxGridBarcodeDBTableViewBarcode->DataController;
	int nRowIndex = pdcControl->FocusedRowIndex;
	int nColIndex = cxGridBarcodeDBTableViewBarcodeHEADER_ID->Index;

	BARCODE_HEADER bhHeader;
	bhHeader.nHeaderIndex = pdcControl->DisplayTexts[nRowIndex][nColIndex].ToInt();

	String strSQL = "DELETE FROM BARCODE_HEADER WHERE HEADER_ID = ";
	strSQL += String(bhHeader.nHeaderIndex);

	TADOQuery* pADOQuery = new TADOQuery(NULL);
	pADOQuery->Connection = DataModuleMain->ADOConnectionMain;

	try
	{
		pADOQuery->Close();
		pADOQuery->SQL->Text = strSQL;
		pADOQuery->ExecSQL();
	}
	catch (Exception& e)
	{
		ShowMessage("删除信息失败，错误：" + e.Message);
	}

	delete pADOQuery;

	LoadBarcodes();
	LoadBarcodes(bhHeader.nScannerIndex);
}
//---------------------------------------------------------------------------


void __fastcall TDlgScannerConfig::cxGridScannerDBTableViewScannerFocusedRecordChanged(TcxCustomGridTableView *Sender,
		  TcxCustomGridRecord *APrevFocusedRecord, TcxCustomGridRecord *AFocusedRecord,
          bool ANewItemRecordFocusingChanged)
{
	if (AFocusedRecord == NULL)
	{
		return;
	}

	int nColIndex = cxGridScannerDBTableViewScannerSCANNER_ID->Index;
	int nScannerId = AFocusedRecord->DisplayTexts[nColIndex].ToInt();
	LoadBarcodes();
	LoadBarcodes(nScannerId);
}
//---------------------------------------------------------------------------

