//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("param\UnitDlgGroupEdit.cpp", DlgGroupEdit);
USEFORM("param\UnitDlgScannerConfig.cpp", DlgScannerConfig);
USEFORM("param\UnitDlgBarcodeHeaderEdit.cpp", DlgBarcodeHeaderEdit);
USEFORM("param\UnitDlgCommEdit.cpp", DlgCommEdit);
USEFORM("param\UnitDlgScannerEdit.cpp", DlgScannerEdit);
USEFORM("UnitFormMain.cpp", FormMain);
USEFORM("UnitDataModuleMain.cpp", DataModuleMain); /* TDataModule: File Type */
USEFORM("base\UnitDialogBase.cpp", DialogBase);
USEFORM("base\UnitFormBase.cpp", FormBase);
USEFORM("base\UnitFormProgressbar.cpp", FormProgressbar);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TDataModuleMain), &DataModuleMain);
		Application->CreateForm(__classid(TFormMain), &FormMain);
		Application->CreateForm(__classid(TDlgScannerConfig), &DlgScannerConfig);
		Application->CreateForm(__classid(TDlgGroupEdit), &DlgGroupEdit);
		Application->CreateForm(__classid(TDlgScannerEdit), &DlgScannerEdit);
		Application->CreateForm(__classid(TDlgBarcodeHeaderEdit), &DlgBarcodeHeaderEdit);
		Application->CreateForm(__classid(TDlgCommEdit), &DlgCommEdit);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
