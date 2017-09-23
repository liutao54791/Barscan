//---------------------------------------------------------------------------

#ifndef UnitDlgBarcodeHeaderEditH
#define UnitDlgBarcodeHeaderEditH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "cxButtons.hpp"
#include "cxClasses.hpp"
#include "cxControls.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "dxLayoutContainer.hpp"
#include "dxLayoutControl.hpp"
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
#include "dxSkinscxPCPainter.hpp"
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
#include "cxContainer.hpp"
#include "cxEdit.hpp"
#include "cxTextEdit.hpp"
#include "dxLayoutcxEditAdapters.hpp"
#include <Vcl.Samples.Spin.hpp>
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxMemo.hpp"
#include "cxSpinEdit.hpp"
//---------------------------------------------------------------------------
typedef struct _tagBARCODE_HEADER
{
	int nScannerIndex;
	int nHeaderIndex;
	int nBarcodeOrder;
	String strBarcodeTitle;
	String strNote;
}BARCODE_HEADER,*PBARCODE_HEADER;
//---------------------------------------------------------------------------
class TDlgBarcodeHeaderEdit : public TDialogBase
{
__published:	// IDE-managed Components
	TdxLayoutGroup *dxLayoutControl1Group_Root;
	TdxLayoutControl *dxLayoutControl1;
	TcxTextEdit *cxTextEditBarcodeHeader;
	TdxLayoutItem *dxLayoutItem2;
	TcxMemo *cxMemoNote;
	TdxLayoutItem *dxLayoutItem4;
	TcxSpinEdit *cxSpinEditOrder;
	TdxLayoutItem *dxLayoutItem1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cxButtonOkClick(TObject *Sender);
private:	// User declarations
	void LoadBarcodeHeaderInfo();
	void SaveBarcodeHeaderInfo();
public:		// User declarations
	__fastcall TDlgBarcodeHeaderEdit(TComponent* Owner);

	void SetBarcodeHeaderInfo(BARCODE_HEADER bhHeader);

private:
	BARCODE_HEADER m_bhHeader;
};
//---------------------------------------------------------------------------
extern PACKAGE TDlgBarcodeHeaderEdit *DlgBarcodeHeaderEdit;
//---------------------------------------------------------------------------
#endif
