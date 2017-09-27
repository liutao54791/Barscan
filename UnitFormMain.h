//---------------------------------------------------------------------------

#ifndef UnitFormMainH
#define UnitFormMainH
//---------------------------------------------------------------------------
#include "UnitBarcodeScanner.h"

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "cxClasses.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxCustomData.hpp"
#include "cxData.hpp"
#include "cxDataStorage.hpp"
#include "cxDBData.hpp"
#include "cxEdit.hpp"
#include "cxFilter.hpp"
#include "cxGraphics.hpp"
#include "cxGrid.hpp"
#include "cxGridCustomTableView.hpp"
#include "cxGridCustomView.hpp"
#include "cxGridDBTableView.hpp"
#include "cxGridLevel.hpp"
#include "cxGridTableView.hpp"
#include "cxLabel.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxNavigator.hpp"
#include "cxStyles.hpp"
#include "dxBar.hpp"
#include "dxLayoutContainer.hpp"
#include "dxLayoutControl.hpp"
#include "dxLayoutcxEditAdapters.hpp"
#include "dxmdaset.hpp"
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
#include "dxSkinsdxBarPainter.hpp"
#include "dxSkinsdxStatusBarPainter.hpp"
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
#include "dxStatusBar.hpp"
#include <Data.DB.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "cxButtons.hpp"
#include "cxDropDownEdit.hpp"
#include "cxMaskEdit.hpp"
#include "cxTextEdit.hpp"
#include "dxLayoutControlAdapters.hpp"
#include <Vcl.Menus.hpp>
#include <Data.Win.ADODB.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdGlobal.hpp>
#include <IdSocketHandle.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPServer.hpp>
#include <System.Win.ScktComp.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
//---------------------------------------------------------------------------
class TFormMain : public TForm
{
__published:	// IDE-managed Components
	TcxLookAndFeelController *cxLookAndFeelControllerApp;
	TdxBarManager *dxBarManagerMain;
	TdxBar *dxBarManagerMainBar1;
	TdxBarSubItem *dxBarSubItem1;
	TdxBarButton *dxBarButton1;
	TdxBarSubItem *dxBarSubItem2;
	TdxBarButton *dxBarButtonScannerMgr;
	TPanel *Panel1;
	TdxLayoutGroup *dxLayoutControl1Group_Root;
	TdxLayoutControl *dxLayoutControl1;
	TcxGridDBTableView *cxGridBarcodeDBTableViewBarcode;
	TcxGridLevel *cxGridBarcodeLevel1;
	TcxGrid *cxGridBarcode;
	TdxLayoutItem *dxLayoutItem2;
	TdxMemData *dxMemDataBarcode;
	TDataSource *DataSourceBarcode;
	TdxStatusBar *dxStatusBarApp;
	TdxLayoutItem *dxLayoutItem3;
	TcxComboBox *cxComboBoxGroup;
	TdxLayoutItem *dxLayoutItem1;
	TcxComboBox *cxComboBoxMode;
	TdxLayoutItem *dxLayoutItem4;
	TcxButton *cxButtonStart;
	TdxLayoutItem *dxLayoutItem5;
	TdxLayoutGroup *dxLayoutGroup1;
	TADOQuery *ADOQueryGroups;
	TIdUDPServer *IdUDPServerDevice;
	TdxBarButton *dxBarButtonCommEdit;
	void __fastcall dxBarButtonScannerMgrClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall cxButtonStartClick(TObject *Sender);
	void __fastcall IdUDPServerDeviceUDPRead(TIdUDPListenerThread *AThread, const TIdBytes AData,
          TIdSocketHandle *ABinding);
	void __fastcall dxBarButtonCommEditClick(TObject *Sender);
public:		// User declarations
	__fastcall TFormMain(TComponent* Owner);
private:	// User declarations
	void CreateFields(TStringList* pslTag,TStringList* pslCaption);
	void ClearFields();

	void LoadGroups();
	void LoadScanners(int nGroupIndex);
	void LoadBarcodeHeaders(int nGroupIndex);

	void LoadDefaultConfigure();
	void SaveDefaultConfigure();

	void Start();
private:
	void __fastcall OnBarcodeScanned(TMessage& pmMessage);
	void __fastcall OnClientSocketConnect(TObject* Sender, TCustomWinSocket* Socket);
	void __fastcall OnClientSocketDisconnect(TObject* Sender, TCustomWinSocket* Socket);
	void __fastcall OnClientSocketRead(TObject* Sender, TCustomWinSocket* Socket);
private:
	TList* m_plScannerInfo;

	TBarcodeScanner* m_pbsScanner;
	TClientSocket* m_pcsTcpClient;

	int m_nBarcodeCount;
	int m_nCurrentBarcodeCount;

	String UdpClientIp;
	int UdpClientPort;

	String m_barode ;
	String m_AuxBarcode;
	String m_ProcedureId;

BEGIN_MESSAGE_MAP
	VCL_MESSAGE_HANDLER(WM_BARCODE_SCANNED,TMessage,OnBarcodeScanned)
END_MESSAGE_MAP(TForm)
};
//---------------------------------------------------------------------------
extern PACKAGE TFormMain *FormMain;
//---------------------------------------------------------------------------
#endif
