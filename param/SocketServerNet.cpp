#pragma hdrstop

#include "SocketServerNet.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
/*
SocketServerNet.cpp
*/
#include "SocketServerNet.h"

#include "ServerThread.h"
#include "workengine_TLB.h"
#include "UnitDataModuleMain.h"

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

DWORD WINAPI FunDataProc(LPVOID lpParameter);
int DataLen = 0;
char Recv_Buffer [1024] = {0};
HANDLE hThread;
HANDLE hEvent;
TCustomWinSocket * ConmSocket = NULL;

DWORD WINAPI FunDataProc(LPVOID lpParameter)
{
    while(true)
    {
        WaitForSingleObject(hEvent,INFINITE);//INFINITE wait for all time
        switch (Recv_Buffer[0])
        {
            case 0x12:
            {
                break;
            }
            default:
            break;
        }
        if (Recv_Buffer[1] == 0x23)
        {
            if (ConmSocket->Connected)
            {
                ConmSocket->SendBuf(Recv_Buffer,DataLen);
            }
        }
    }
}

CServerNet::CServerNet():SocketServer(NULL)
,ConNum(0)
{
    hThread = CreateThread(NULL,0,FunDataProc,NULL,0,NULL);
    hEvent = CreateEvent(NULL,false,false,NULL);
}

CServerNet::~CServerNet()
{
    CloseHandle(hThread);
    CloseHandle(hEvent);
    Stop();
    delete SocketServer;
    delete ConmSocket;
}

SocketStatus CServerNet::Init(int port )
{
    SocketStatus rlt = SocketError;

    SocketServer = new TServerSocket(Application);
    SocketServer->Port = port;  
    //SocketServer->ServerType = stThreadBlocking; /**********************阻塞模式*****************/
    SocketServer->ThreadCacheSize = ServerConnectionSize;
    SocketServer->OnClientConnect = ServerClientConnect;
    SocketServer->OnClientDisconnect = ServerClientDisconnect;
    SocketServer->OnClientRead = ServerRead;
    //SocketServer->OnGetThread = GetThread;      /**********************阻塞模式*****************/

    rlt = SocketOk;

    return SocketOk;
}

void CServerNet::Run()
{

    SocketServer->Open();
}

void CServerNet::Stop()
{

    SocketServer->Close();
}

void __fastcall CServerNet::ServerRead (TObject* Sender, TCustomWinSocket * Socket)
{
    ConmSocket = Socket;
    DataLen = Socket->ReceiveLength();
    //String RecevieString = Socket->ReceiveText();
    memset(Recv_Buffer,0,1024);
    Socket->ReceiveBuf(Recv_Buffer,DataLen);
    SetEvent(hEvent);
}

void __fastcall CServerNet::ServerClientConnect (TObject* Sender, TCustomWinSocket * Socket)
{
    ConNum ++;
}

void __fastcall CServerNet::ServerClientDisconnect (TObject* Sender, TCustomWinSocket * Socket)
{
    if (ConNum > 0)
    {
        ConNum --;
    }
}

void __fastcall CServerNet::SendMesToAllConnect (char* Buffer, int Len)
{
    for (int i = 0; i < ConNum; i++)
    {
        SocketServer->Socket->Connections[i]->SendBuf(Buffer,Len);
    }
}

/**********************阻塞模式*****************/
void __fastcall CServerNet::GetThread(TObject* Sender, TServerClientWinSocket* ClientSocket,TServerClientThread* &SocketThread)
{
    SocketThread = new TServerThread(false,ClientSocket);
}



TidServerNet::TidServerNet():IdTCPServer(NULL)
{
    WORD wVersionRequested;
    WSADATA wsadata;
    int err;
    wVersionRequested = MAKEWORD(1,1);
    err = WSAStartup(wVersionRequested,&wsadata);
    if (err!=0)
     return;
}

TidServerNet::~TidServerNet()
{
    WSACleanup(); 
    delete IdTCPServer;
}

SocketStatus TidServerNet::Init(int port)
{
    if (IdTCPServer == NULL)
    {
        IdTCPServer = new  TIdTCPServer();
        IdTCPServer->DefaultPort = port;
        IdTCPServer->OnExecute = IdTCPServerMExecute;
        IdTCPServer->MaxConnections = 10;
        if (IdTCPServer->Active == false)
        {
            return SocketOk;
        }
        else if (IdTCPServer->Active == true)
        {
            return SocketError;
        }
    }
    if (IdTCPServer != NULL && IdTCPServer->Active == true)
    {
        return SocketError;
    }
}

void TidServerNet::Run()
{
    if (IdTCPServer->Active == false)
    {
        IdTCPServer->Active = true;
    }
    
}

void TidServerNet::Stop()
{
    if (IdTCPServer->Active == true)
    {
        IdTCPServer->Active = false;
    }
}

void __fastcall TidServerNet::IdTCPServerMExecute(TIdContext *AContext)
{
    TBytes buf;
    int RecLen =  AContext->Connection->IOHandler->InputBuffer->Size;
    String peerIP = AContext->Binding->PeerIP;
    int peerport = AContext->Binding->PeerPort;
    if(RecLen > 0)
    {
       AContext->Connection->IOHandler->ReadBytes(buf,RecLen,false);
    }
    char* DataBuf;
    for (int i = 0; i < RecLen; i++)
    {
        DataBuf[i] = buf[i];
    }
    WideString strMessage((char*)DataBuf,RecLen);
    delete DataBuf;

    TCOMICommonMessage pcmMessage = CoCommonMessage::Create();
    BSTR strXmlMessage = strMessage.c_bstr();
    pcmMessage->set_XmlMessage(strXmlMessage);

    /* get Type */
    BSTR strPath = ::SysAllocString(L"CommonMessage/Header/Type");
    BSTR strText = pcmMessage->GetNodeText(strPath);
    WideString strType = strText;
    int nCommandType = strType.ToInt();
    ::SysFreeString(strPath);
    ::SysFreeString(strText);

    /* get SenderId */
    strPath = ::SysAllocString(L"CommonMessage/Header/SenderId");
    strText = pcmMessage->GetNodeText(strPath);
    WideString strSenderId = strText;
    ::SysFreeString(strPath);
    ::SysFreeString(strText);

    /* get ProductId */
    strPath = ::SysAllocString(L"CommonMessage/Content/ProductId");
    strText = pcmMessage->GetNodeText(strPath);
    WideString strProductId = strText;
    ::SysFreeString(strPath);
    ::SysFreeString(strText);

    /* get ProcedureId */
    strPath = ::SysAllocString(L"CommonMessage/Content/ProcedureId");
    strText = pcmMessage->GetNodeText(strPath);
    WideString strProcedureId = strText;
    int nProcedureId = strProcedureId.ToInt();
    ::SysFreeString(strPath);
    ::SysFreeString(strText);

    TADOQuery* pADOQuery = new TADOQuery(NULL);
    pADOQuery->Connection = DataModuleMain->ADOConnectionMain;
    String strSQL ="SELECT HEADER_ID,BAR_VALUE,SCANNER_ID \
        FROM BARCODE_VALUE \
        WHERE PROCESS_ID = " + strProcedureId;

    switch(nCommandType)
    {
        case 1:
        {
            break;
        }
        case 2:
        {
            break;
        }
        default:
        break;

    }

    AContext->Connection->IOHandler->Write(buf);

}
//---------------------------------------------------------------------------
