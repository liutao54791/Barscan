//---------------------------------------------------------------------------

#ifndef UnitTypeBaseH
#define UnitTypeBaseH
//---------------------------------------------------------------------------

#include "TypeDef.h"
#include "UnitIterable.h"

using namespace tccpplib;

class TTcpIpAddress
{
public:
	TTcpIpAddress();
	TTcpIpAddress(const TTcpIpAddress& tiaAddress);
	TTcpIpAddress(TStdString strIp,TWord nPort);
	TTcpIpAddress(TStdString strAddress);

	TTcpIpAddress& operator = (const TTcpIpAddress& tiaAddress);

	~TTcpIpAddress();
public:
	TVoid SetAddress(TStdString strIp,TWord nPort);
	TStdString GetIp();
	TWord GetPort();
	TStdString ToString();
private:
	TStdString m_strIp;
	TWord m_nPort;
};

class TCommMessage
{
public:
	TCommMessage();
	TCommMessage(TTcpIpAddress tiaAddress,TByte* pbMsg,TWord nMsgLen);
	TCommMessage(const TCommMessage& cmMsg);

	TCommMessage& operator = (const TCommMessage& cmMsg);
	~TCommMessage();
public:
	enum TMessageDir {mdIn,mdOut};
public:
	TByte* GetMsg();
	TWord GetMsgLength();
	TTcpIpAddress GetAddress();

	TVoid SetMsg(TByte* pbMsg,TWord nMsgLen);
	TVoid SetAddress(TTcpIpAddress tiaAddress);

	TVoid SetMessageDir(TMessageDir mdDir);
	TMessageDir GetMessageDir();
private:
	TMessageDir m_mdDir;
	TByte* m_pbMsg;
	TWord m_nMsgLen;
	TTcpIpAddress m_tiaAddress;
};

class TMessageBuffer : public IIterable<TCommMessage>
{
public:
	TMessageBuffer();
	TMessageBuffer(TWord nCapability);
	~TMessageBuffer();
public:
	TUnsignedInteger Size() const;
	TCommMessage* GetItem(TUnsignedInteger nIndex) const;
	TIterator<TCommMessage>* CreateIterator() const;

	bool IsEmpty();
	bool IsFull();
	TWord AddMessage(TCommMessage* pcmMsg);
	TCommMessage* PeekMsg();
	TVoid Clear();
private:
	std::vector<TCommMessage*> m_vMsgBuffer;
	TWord m_nCapability;
};


#endif
