//---------------------------------------------------------------------------

#ifndef UnitCommEventSinkH
#define UnitCommEventSinkH
//---------------------------------------------------------------------------
/* -- sys -- */
#include <Vcl.OleCtrls.hpp>
/* -- usr -- */
#include "CommLib_TLB.h"

typedef void (__closure (*FnOnRead))(IUnknown* pSender,BYTE* pbData,ULONG nLength);
typedef void (__closure (*FnOnStatus))(IUnknown* pSender,ULONG nErrorCode,BSTR strErrorInfo);

class TSerialPortEventSink : public TEventDispatcher<TSerialPortEventSink,
	&DIID__ISerialPortEvents>
{
public:
	TSerialPortEventSink();
	virtual ~TSerialPortEventSink();
public:
	void Connect(IUnknown* pSender);
	void DisConnect();
protected:
	HRESULT InvokeEvent(DISPID diId,TVariant* pvParams);
public:
	FnOnRead OnRead;
	FnOnStatus OnStatus;
private:
	IUnknown* m_pSender;
};

#endif
