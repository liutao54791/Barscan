//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

#ifndef SocketServerNetH
#define SocketServerNetH
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#pragma once

/*
SocketServerNet.h

*/

#include <stdio.h>
//#include <winsock.h>
#include <vcl.h>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "cxButtons.hpp"
#include "cxClasses.hpp"
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGraphics.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxLookAndFeels.hpp"
#include "cxMaskEdit.hpp"
#include "cxSpinEdit.hpp"
#include "cxTextEdit.hpp"
#include "dxLayoutContainer.hpp"
#include "dxLayoutControl.hpp"
#include "dxLayoutcxEditAdapters.hpp"
#include "dxLayoutLookAndFeels.hpp"
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
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
#include <IdSocketHandle.hpp>
#include <IdContext.hpp>
#include <System.SysUtils.hpp>
#include "dxScreenTip.hpp"
#include <System.Win.ScktComp.hpp>
#pragma comment (lib,"ws2_32.lib")

#define ServerConnectionSize 10

enum SocketStatus
{
	SocketError,
	SocketOk
};

class CServerNet
{
public:
	CServerNet();
	virtual ~CServerNet();
	SocketStatus Init(int port);
    void Run();
    void Stop();
    void __fastcall ServerClientConnect (TObject* Sender, TCustomWinSocket * Socket);
	void __fastcall ServerClientDisconnect (TObject* Sender, TCustomWinSocket * Socket);
	void __fastcall SendMesToAllConnect (char* Buffer, int Len);
    void __fastcall ServerRead(TObject* Sender, TCustomWinSocket * Socket);
	void __fastcall GetThread(TObject *Sender, TServerClientWinSocket* ClientSocket,TServerClientThread* &SocketThread);
private:
    TServerSocket * SocketServer;
    int ConNum;
};

class TidServerNet
{
public:
	TidServerNet();
	virtual ~TidServerNet();
	SocketStatus Init(int port);
    void Run();
    void Stop();
	void __fastcall IdTCPServerMExecute(TIdContext *AContext);
private:
	TIdTCPServer* IdTCPServer;
    TBytes buf;
    int RecLen;
};

#endif


