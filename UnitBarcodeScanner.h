//---------------------------------------------------------------------------

#ifndef UnitBarcodeScannerH
#define UnitBarcodeScannerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <vector>

#include "UnitCommEventSink.h"

#define WM_BARCODE_SCANNED WM_USER + 1

using std::vector;

typedef struct _tagBARCODE
{
	int nTag;
	String strValue;
}BARCODE,*PBARCODE;

typedef struct _tagSCANNER_INFO
{
	int nId;
	int nTag;
	String strParam;
}SCANNER_INFO,*PSCANNER_INFO;

class TBarcodeScanner
{
public:
	TBarcodeScanner();
	virtual ~TBarcodeScanner();
public:
	int Init();
	int Scan();
	void Stop();
	void SetHandle(HWND hWnd);

	virtual void AddScanner(SCANNER_INFO siScanner) = 0;
	virtual void RemoveScanner(SCANNER_INFO siScanner) = 0;
	virtual void ClearScanners() = 0;
protected:
	void UploadBarcode(BARCODE bBarcode);
	bool IsValidBarcode(String strBarcode,int nIndex);
private:
	virtual int OpenScanners() = 0;
	virtual void CloseScanners() = 0;
	virtual void StartScanBarcode(int nIndex) = 0;
	virtual void StartScanBarcode() = 0;;
protected:
	vector<int> m_vBarcodeLength;
	TStringList* m_pslBarcodeList;
	int m_nScannedCount;

	HWND m_hWnd;
};

class THoneyWellBarcodeScanner : public TBarcodeScanner
{
public:
	THoneyWellBarcodeScanner();
	~THoneyWellBarcodeScanner();
public:
	void AddScanner(SCANNER_INFO siScanner);
	void RemoveScanner(SCANNER_INFO siScanner);
	void ClearScanners();
private:
	int OpenScanners();
	void CloseScanners();
	void StartScanBarcode(int nIndex);
	void StartScanBarcode();
private:
	void OnRead(IUnknown* Sender,BYTE* pbData,ULONG nLength);
private:
	TList* m_plSerialPortList;
	vector<TSerialPortEventSink*> m_vEventSink;
	TCriticalSection* m_pcsMutex;
};

#endif
