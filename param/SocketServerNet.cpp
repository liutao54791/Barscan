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

    SocketServer = new TServerSocket(Application);
    SocketServer->Port = port;  
    //SocketServer->ServerType = stThreadBlocking; /**********************阻塞模式*****************/
    SocketServer->ThreadCacheSize = ServerConnectionSize;
    SocketServer->OnClientConnect = ServerClientConnect;
    SocketServer->OnClientDisconnect = ServerClientDisconnect;
    SocketServer->OnClientRead = ServerRead;
    //SocketServer->OnGetThread = GetThread;      /**********************阻塞模式*****************/

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

TidServerNet* TidServerNet::getInstance()
{
    static TidServerNet* SocketServer = NULL;
    if (SocketServer == NULL)
    {
        SocketServer = new TidServerNet();
    }
    return SocketServer;
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

BSTR __fastcall TidServerNet::BuildMessage(char* Buff,int Len)
{
    BSTR Message;

    WideString strMessage((char*)Buff,Len);

    TCOMICommonMessage pcmMessage = CoCommonMessage::Create();
    BSTR strXmlMessage = strMessage.c_bstr();
    pcmMessage->set_XmlMessage(strXmlMessage);

    //get Type 
    BSTR strPath = ::SysAllocString(L"CommonMessage/Header/Type");
    BSTR strText = pcmMessage->GetNodeText(strPath);
    WideString strType = strText;
    int nCommandType = strType.ToInt();
    ::SysFreeString(strPath);
    ::SysFreeString(strText);

    // get SenderId 
    strPath = ::SysAllocString(L"CommonMessage/Header/SenderId");
    strText = pcmMessage->GetNodeText(strPath);
    WideString strSenderId = strText;
    ::SysFreeString(strPath);
    ::SysFreeString(strText);

    // get ProductId
    strPath = ::SysAllocString(L"CommonMessage/Content/ProductId");
    strText = pcmMessage->GetNodeText(strPath);
    WideString strProductId = strText;
    ::SysFreeString(strPath);
    ::SysFreeString(strText);

    // get ProcedureId
    strPath = ::SysAllocString(L"CommonMessage/Content/ProcedureId");
    strText = pcmMessage->GetNodeText(strPath);
    WideString strProcedureId = strText;
    ::SysFreeString(strPath);
    ::SysFreeString(strText);

    WideString XmlMessage; //根据Type存放回复命令

    TADOQuery* pADOQuery = new TADOQuery(NULL);
    pADOQuery->Connection = DataModuleMain->ADOConnectionMain;

    switch(nCommandType)
    {
        case 1:
        {
            String strSQL ="SELECT PROCEDURE_ID,BARCODE,TIME,STATE,AUX \
            FROM BARCODE_VALUE \
            WHERE PROCEDURE_ID  = " + strProcedureId + " AND STATE = 0 \
            ORDER BY DATE ASC";

            pADOQuery->Close();
            pADOQuery->SQL->Text = strSQL;
            pADOQuery->Open();

            pADOQuery->Last();

            XmlMessage = "<CommonMessage>"
            "<Header>"
                "<Type>255</Type>"
                "<SenderId>0</SenderId>"
            "</Header>"
            "<Content>"
                "<ProductId>1</ProductId>"
                "<ProductBarcode>20170215000001</ProductBarcode>"
                "<ProcedureId>1</ProcedureId>"
                "<Result>0</Result>"
            "</Content>"
            "</CommonMessage>";

            BSTR strTmp = XmlMessage.c_bstr();
            pcmMessage->set_XmlMessage(strTmp);

            strPath = ::SysAllocString(L"CommonMessage/Header/Type");
            strType = "255";
            pcmMessage->SetNodeText(strPath,strType.c_bstr());
        
            ::SysReAllocString(&strPath, L"CommonMessage/Header/SenderId");
            WideString strValue = strSenderId;
            pcmMessage->SetNodeText(strPath,strValue.c_bstr());
        
            //ProductID
            ::SysReAllocString(&strPath, L"CommonMessage/Content/ProductId");
            strValue = strProductId;
            pcmMessage->SetNodeText(strPath,strValue.c_bstr());
        
            //ProductBarcode
            ::SysReAllocString(&strPath, L"CommonMessage/Content/ProductBarcode");
            strValue = pADOQuery->FieldByName("BARCODE")->AsString;
            pcmMessage->SetNodeText(strPath,strValue.c_bstr());
        
            ::SysReAllocString(&strPath, L"CommonMessage/Content/ProcedureId");
            strValue = pADOQuery->FieldByName("PROCEDURE_ID")->AsString;
            pcmMessage->SetNodeText(strPath,strValue.c_bstr());
        
            ::SysReAllocString(&strPath, L"CommonMessage/Content/Result");
            WideString strResult = "0";
            pcmMessage->SetNodeText(strPath,strResult.c_bstr());
            ::SysFreeString(strPath);
            
            Message = pcmMessage->get_XmlMessage();

            pADOQuery->Connection->BeginTrans();

            strSQL = "";
            strSQL = "UPDATE BARCODE_VALUE SET ";
            strSQL += "STATE='" + String(1) + "' ";
            strSQL += " WHERE BARCODE=" + pADOQuery->FieldByName("BARCODE")->AsString + " AND PROCEDURE_ID = " + pADOQuery->FieldByName("PROCEDURE_ID")->AsString;

            pADOQuery->Close();
            pADOQuery->SQL->Text = strSQL;
            pADOQuery->ExecSQL();
            
            pADOQuery->Connection->CommitTrans();
        
            break;
        }
        case 2:
        {   

            strPath = ::SysAllocString(L"CommonMessage/Content/State");
            strText = pcmMessage->GetNodeText(strPath);
            WideString StateToUpadate = strText;
            ::SysFreeString(strPath);
            ::SysFreeString(strText);

            strPath = ::SysAllocString(L"CommonMessage/Content/ProductBarcode");
            strText = pcmMessage->GetNodeText(strPath);
            WideString BarCode = strText;

            ::SysFreeString(strPath);
            ::SysFreeString(strText);

            pADOQuery->Connection->BeginTrans();
            String strSQL = "UPDATE BARCODE_VALUE SET ";
            strSQL += "STATE='" + StateToUpadate + "' ";
            strSQL += " WHERE BARCODE=" + BarCode + " AND PROCEDURE_ID = " + strProcedureId;

            pADOQuery->Close();
            pADOQuery->SQL->Text = strSQL;
            pADOQuery->ExecSQL();
            
            pADOQuery->Connection->CommitTrans();

            XmlMessage = "<CommonMessage>"
                "<Header>"
                    "<Type>254</Type>"
                    "<SenderId>1.0.1.0.1</SenderId>"
                    "<SenderName>engine</SenderName>"
                "</Header>"
                "<Content>"
                    "<ProductId>1</ProductId>"
                    "<ProductBarcode>20170215000001</ProductBarcode>"
                    "<ProcedureId>1.0.1.2.1</ProcedureId>"
                    "<Result>0</Result>"
                "</Content>"
            "</CommonMessage>";

            BSTR strTmp = XmlMessage.c_bstr();
            pcmMessage->set_XmlMessage(strTmp);
            strPath = ::SysAllocString(L"CommonMessage/Header/Type");
            strType = "254";
            pcmMessage->SetNodeText(strPath,strType.c_bstr());
        
            ::SysReAllocString(&strPath, L"CommonMessage/Header/SenderId");
            WideString strValue = strSenderId;
            pcmMessage->SetNodeText(strPath,strValue.c_bstr());
        
            //ProductID
            ::SysReAllocString(&strPath, L"CommonMessage/Content/ProductId");
            strValue = strProductId;
            pcmMessage->SetNodeText(strPath,strValue.c_bstr());
        
            //ProductBarcode
            ::SysReAllocString(&strPath, L"CommonMessage/Content/ProductBarcode");
            strValue = BarCode;
            pcmMessage->SetNodeText(strPath,strValue.c_bstr());
        
            ::SysReAllocString(&strPath, L"CommonMessage/Content/ProcedureId");
            strValue = strProcedureId;
            pcmMessage->SetNodeText(strPath,strValue.c_bstr());
        
            ::SysReAllocString(&strPath, L"CommonMessage/Content/Result");
            WideString strResult = "0";
            pcmMessage->SetNodeText(strPath,strResult.c_bstr());
            ::SysFreeString(strPath);
        
            Message = pcmMessage->get_XmlMessage();
            break;
        }
        default:
        break;
    }

    delete pADOQuery;
    return Message;
}

void __fastcall TidServerNet::IdTCPServerMExecute(TIdContext *AContext)
{

    int RecLen =  AContext->Connection->IOHandler->InputBuffer->Size;
    if (RecLen == 0)
    {
        return;
    }

    TBytes buf;
    String peerIP = AContext->Binding->PeerIP;
    int peerport = AContext->Binding->PeerPort;

    if(RecLen > 0)
    {
       AContext->Connection->IOHandler->ReadBytes(buf,RecLen);
    }
    char* DataBuf = (char*)malloc(1024);
    for (int i = 0; i < RecLen; i++)
    {
        DataBuf[i] = buf[i];
    }
    BSTR Message = BuildMessage(DataBuf,RecLen);
    free(DataBuf);
    AContext->Connection->IOHandler->Write(Message);
}
//---------------------------------------------------------------------------
