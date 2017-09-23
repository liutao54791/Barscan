//---------------------------------------------------------------------------

#ifndef UnitServerThreadH
#define UnitServerThreadH
//---------------------------------------------------------------------------

#include <ScktComp.hpp>
#include <StdCtrls.hpp>

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class TServerThread: public TServerClientThread
{
protected:
	void __fastcall ClientExecute(void);
	int __fastcall ReadStr(char *buf);
public:
	__fastcall TServerThread(bool CreateSuspended,TServerClientWinSocket* ASocket);
private:
	TWinSocketStream *pStream;
};
#endif
