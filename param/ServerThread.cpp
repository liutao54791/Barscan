#include <vcl.h>
#pragma hdrstop
#include "ServerThread.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall TServerThread::TServerThread(bool CreateSuspended,TServerClientWinSocket* ASocket)
 : TServerClientThread(CreateSuspended,ASocket)
{
    FreeOnTerminate=false;
}
//---------------------------------------------------------------------------
void __fastcall TServerThread::ClientExecute(void)
{   
    //创建接收数据socket
    //1.接收数据
    char buf[1024];
    while(1)
    {
        pStream = new TWinSocketStream(ClientSocket,60000);
        memset(buf,0,sizeof(buf));
        try
        {
            int len = 0;
            if (pStream != NULL)
            {
                if(pStream->WaitForData(60000))
                {
                    len = pStream->Read(buf,1024);
                    buf[len]=0;
                    if(buf[1] == 0x23)
                    {
                     ShowMessage("right");
                    }
                }
            }

        }
        catch(Exception &E)
        {

        }
         //2.发送数据
        if (ClientSocket != NULL)
        {
            ClientSocket->SendText("接收的数据为" + AnsiString(buf));
        }
        
    }

}

