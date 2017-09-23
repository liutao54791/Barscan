//---------------------------------------------------------------------------

#ifndef UnitDlgScannerConfigH
#define UnitDlgScannerConfigH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "cxButtons.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "dxSkinBlack.hpp"
#include "dxSkinBlue.hpp"
#include "dxSkinBlueprint.hpp"
#include "dxSkinCaramel.hpp"
#include "dxSkinCoffee.hpp"
#include "dxSkinDarkRoom.hpp"
#include "dxSkinDarkSide.hpp"
#include "dxSkinDevExpressDarkStyle.hpp"
#include "dxSkinDevExpressStyle.hpp"
#include "dxSkinFoggy.hpp"
#include "dxSkinGlassOceans.hpp"
#include "dxSkinHighContrast.hpp"
#include "dxSkiniMaginary.hpp"
#include "dxSkinLilian.hpp"
#include "dxSkinLiquidSky.hpp"
#include "dxSkinLondonLiquidSky.hpp"
#include "dxSkinMcSkin.hpp"
#include "dxSkinMetropolis.hpp"
#include "dxSkinMetropolisDark.hpp"
#include "dxSkinMoneyTwins.hpp"
#include "dxSkinOffice2007Black.hpp"
#include "dxSkinOffice2007Blue.hpp"
#include "dxSkinOffice2007Green.hpp"
#include "dxSkinOffice2007Pink.hpp"
#include "dxSkinOffice2007Silver.hpp"
#include "dxSkinOffice2010Black.hpp"
#include "dxSkinOffice2010Blue.hpp"
#include "dxSkinOffice2010Silver.hpp"
#include "dxSkinOffice2013DarkGray.hpp"
#include "dxSkinOffice2013LightGray.hpp"
#include "dxSkinOffice2013White.hpp"
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinPumpkin.hpp"
#include "dxSkinsCore.hpp"
#include "dxSkinsDefaultPainters.hpp"
#include "dxSkinSeven.hpp"
#include "dxSkinSevenClassic.hpp"
#include "dxSkinSharp.hpp"
#include "dxSkinSharpPlus.hpp"
#include "dxSkinSilver.hpp"
#include "dxSkinSpringTime.hpp"
#include "dxSkinStardust.hpp"
#include "dxSkinSummer2008.hpp"
#include "dxSkinTheAsphaltWorld.hpp"
#include "dxSkinValentine.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
#include "dxSkinVS2010.hpp"
#include "dxSkinWhiteprint.hpp"
#include "dxSkinXmas2008Blue.hpp"
#include "UnitDialogBase.h"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxNavigator.hpp"
#include "cxStyles.hpp"
#include "dxLayoutContainer.hpp"
#include "dxLayoutControl.hpp"
#include "dxLayoutControlAdapters.hpp"
#include "dxLayoutLookAndFeels.hpp"
#include "dxSkinscxPCPainter.hpp"
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TDlgScannerConfig : public TDialogBase
{
__published:	// IDE-managed Components
	TdxLayoutGroup *dxLayoutControl1Group_Root;
	TdxLayoutControl *dxLayoutControl1;
	TcxGridDBTableView *cxGridScannerDBTableViewScanner;
	TcxGridLevel *cxGridScannerLevel1;
	TcxGrid *cxGridScanner;
	TdxLayoutItem *dxLayoutItem2;
	TcxGridDBTableView *cxGridBarcodeDBTableViewBarcode;
	TcxGridLevel *cxGridBarcodeLevel1;
	TcxGrid *cxGridBarcode;
	TdxLayoutItem *dxLayoutItem4;
	TdxLayoutGroup *dxLayoutGroup1;
	TdxLayoutGroup *dxLayoutGroup2;
	TdxLayoutLookAndFeelList *dxLayoutLookAndFeelListLocal;
	TdxLayoutCxLookAndFeel *dxLayoutCxLookAndFeel1;
	TcxButton *cxButtonAddScanner;
	TdxLayoutItem *dxLayoutItem1;
	TcxButton *cxButtonEditScanner;
	TdxLayoutItem *dxLayoutItem5;
	TcxButton *cxButtonRemoveScanner;
	TdxLayoutItem *dxLayoutItem6;
	TdxLayoutGroup *dxLayoutGroup3;
	TcxButton *cxButtonAddBarcode;
	TdxLayoutItem *dxLayoutItem3;
	TcxButton *cxButtonEditBarcode;
	TdxLayoutItem *dxLayoutItem7;
	TcxButton *cxButtonRemoveBarcode;
	TdxLayoutItem *dxLayoutItem8;
	TdxLayoutGroup *dxLayoutGroup4;
	TcxGridDBTableView *cxGridScannerDBTableViewGroup;
	TADOQuery *ADOQueryScanner;
	TADOQuery *ADOQueryBarcode;
	TADOQuery *ADOQueryGroup;
	TDataSource *DataSourceGroup;
	TDataSource *DataSourceScanner;
	TDataSource *DataSourceBarcode;
	TIntegerField *ADOQueryGroupGROUP_ID;
	TStringField *ADOQueryGroupGROUP_NAME;
	TStringField *ADOQueryGroupNOTE;
	TIntegerField *ADOQueryScannerSCANNER_ID;
	TIntegerField *ADOQueryScannerGROUP_ID;
	TStringField *ADOQueryScannerSCANNER_NAME;
	TStringField *ADOQueryScannerSCANNER_PARAM;
	TStringField *ADOQueryScannerNOTE;
	TIntegerField *ADOQueryBarcodeSCANNER_ID;
	TIntegerField *ADOQueryBarcodeBARCODE_ID;
	TStringField *ADOQueryBarcodeBARCODE_NAME;
	TStringField *ADOQueryBarcodeNOTE;
	TcxGridLevel *cxGridScannerLevel2;
	TcxGridDBColumn *cxGridScannerDBTableViewGroupGROUP_ID;
	TcxGridDBColumn *cxGridScannerDBTableViewGroupGROUP_NAME;
	TcxGridDBColumn *cxGridScannerDBTableViewGroupNOTE;
	TcxGridDBColumn *cxGridScannerDBTableViewScannerSCANNER_ID;
	TcxGridDBColumn *cxGridScannerDBTableViewScannerGROUP_ID;
	TcxGridDBColumn *cxGridScannerDBTableViewScannerSCANNER_NAME;
	TcxGridDBColumn *cxGridScannerDBTableViewScannerSCANNER_PARAM;
	TcxGridDBColumn *cxGridScannerDBTableViewScannerNOTE;
	TIntegerField *ADOQueryScannerSCANNER_TAG;
	TcxGridDBColumn *cxGridScannerDBTableViewScannerSCANNER_TAG;
	TcxGridDBColumn *cxGridBarcodeDBTableViewBarcodeSCANNER_ID;
	TcxGridDBColumn *cxGridBarcodeDBTableViewBarcodeHEADER_ID;
	TcxGridDBColumn *cxGridBarcodeDBTableViewBarcodeHEADER_NAME;
	TcxGridDBColumn *cxGridBarcodeDBTableViewBarcodeNOTE;
	TIntegerField *ADOQueryBarcodeBARCODE_ORDER;
	TcxGridDBColumn *cxGridBarcodeDBTableViewBarcodeBARCODE_ORDER;
	void __fastcall cxButtonAddScannerClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cxButtonEditScannerClick(TObject *Sender);
	void __fastcall cxButtonAddBarcodeClick(TObject *Sender);
	void __fastcall cxButtonEditBarcodeClick(TObject *Sender);
	void __fastcall cxButtonRemoveBarcodeClick(TObject *Sender);
	void __fastcall cxGridScannerDBTableViewScannerFocusedRecordChanged(TcxCustomGridTableView *Sender,
          TcxCustomGridRecord *APrevFocusedRecord, TcxCustomGridRecord *AFocusedRecord,
          bool ANewItemRecordFocusingChanged);

private:	// User declarations
	void LoadGroups();
	void LoadScanners();
	void LoadBarcodes();
	void LoadBarcodes(int nScannerId);
public:		// User declarations
	__fastcall TDlgScannerConfig(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgScannerConfig *DlgScannerConfig;
//---------------------------------------------------------------------------
#endif
