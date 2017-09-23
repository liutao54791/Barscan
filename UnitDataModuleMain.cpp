//---------------------------------------------------------------------------


#pragma hdrstop

#include "UnitDataModuleMain.h"

#include <System.IniFiles.hpp>
#include <Vcl.Forms.hpp>
#include <FireDAC.Stan.Def.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "System.Classes.TPersistent"
#pragma resource "*.dfm"
TDataModuleMain *DataModuleMain;
//---------------------------------------------------------------------------
__fastcall TDataModuleMain::TDataModuleMain(TComponent* Owner)
	: TDataModule(Owner)
{
	m_oiOperatorInfo.nOperatorId = 0;
	m_oiOperatorInfo.nRoleId = 0;
}
//---------------------------------------------------------------------------
String TDataModuleMain::GetConnectionString()
{
	String strFileName = ChangeFileExt(ParamStr(0),".ini");
	TIniFile* pifReader = new TIniFile(strFileName);
	TDatabaseType dtType = pifReader->ReadInteger("DBINFO","TYPE",1);
	String strServer = pifReader->ReadString("DBINFO","SRV","localhost");
	String strDbName = pifReader->ReadString("DBINFO","DB_NAME","");
	String strUID = pifReader->ReadString("DBINFO","UID","root");
	String strPwd = pifReader->ReadString("DBINFO","PWD","Topscomm");

	String strConStr;
	switch (dtType)
	{
	case dtMsAccess:
		strConStr = "Provider=Microsoft.Jet.OLEDB.4.0;\
			Password= \"" + strPwd + "\";\
			Data Source=" + strDbName + ";\
			Persist Security Info=True";
		break;
	case dtMySQL:
		strConStr = "DRIVER=MySQL ODBC 5.1 Driver;\
			SERVER=" + strServer + "; \
			DATABASE=" + strDbName + "; \
			UID=" + strUID + ";\
			PWD=" + strPwd ;//+ ";\
			//allowMultiQueries=True";
		break;
	case dtMsSQL:
		strConStr = "Provider=SQLOLEDB.1;\
			Password=" + strPwd + ";\
			Persist Security Info=True;\
			User ID=" + String(dtType) + ";\
			Initial Catalog=" + strDbName + ";\
			Data Source=" + strServer;
		break;
	case dtOracle:

		break;
	default:
		strConStr = "";
	}
	delete pifReader;
	return strConStr;
}
//---------------------------------------------------------------------------

void __fastcall TDataModuleMain::DataModuleCreate(TObject *Sender)
{
	ADOConnectionMain->ConnectionString = GetConnectionString();
	try
	{
		ADOConnectionMain->Connected = true;
	}
	catch (Exception& e)
	{
		String strMsg = "�������ݿ�ʧ�ܣ�������Ϣ��" + e.Message;
		MessageBox(Application->Handle,
				   strMsg.c_str(),
				   L"����",
				   MB_OK);
	}
}

//---------------------------------------------------------------------------

void __fastcall TDataModuleMain::DataModuleDestroy(TObject *Sender)
{
	ADOConnectionMain->Connected = false;
}
//---------------------------------------------------------------------------

