//---------------------------------------------------------------------------

#pragma hdrstop

#include "UnitCommEventSink.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//=========================TSerialPortEventSink===============================
TSerialPortEventSink::TSerialPortEventSink()
{
	m_pSender = NULL;
	OnRead = NULL;
	OnStatus = NULL;
}

TSerialPortEventSink::~TSerialPortEventSink()
{

}

void TSerialPortEventSink::Connect(IUnknown* pSender)
{
	if (pSender != m_pSender)
		m_pSender = pSender;
	if (NULL != m_pSender)
		ConnectEvents(m_pSender);
}

void TSerialPortEventSink::DisConnect()
{
	if (NULL != m_pSender)
	{
		DisconnectEvents(m_pSender);
		m_pSender = NULL;
	}
}
HRESULT TSerialPortEventSink::InvokeEvent(DISPID diId,TVariant* pvParams)
{
	switch (diId)
	{
	case 1:
		if (OnRead)
		{
			IUnknown* pSender = pvParams[0];
			BYTE* pbData = pvParams[1];
			ULONG nLength = pvParams[2];
			OnRead(pSender,pbData,nLength);
		}
		break;
	case 2:
		if (OnStatus)
		{
        	IUnknown* pSender = pvParams[0];
			ULONG nErrorCode = pvParams[1];
			BSTR strErrorInfo = pvParams[2];
			OnStatus(pSender,nErrorCode,strErrorInfo);
		}
	default:
		;

	}
	return S_OK;
}