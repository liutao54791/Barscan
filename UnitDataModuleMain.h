//---------------------------------------------------------------------------

#ifndef UnitDataModuleMainH
#define UnitDataModuleMainH
//---------------------------------------------------------------------------
/* -- usr -- */

/*-- sys -- */
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------

typedef struct tagOPERATOR_INFO
{
	int nOperatorId;
	int nRoleId;
}OPERATOR_INFO,*POPERATOR_INFO;

class TDataModuleMain : public TDataModule
{
__published:	// IDE-managed Components
	TADOConnection *ADOConnectionMain;
	void __fastcall DataModuleCreate(TObject *Sender);
	void __fastcall DataModuleDestroy(TObject *Sender);
public:
	enum TDatabaseType {dtMsAccess,dtMySQL,dtMsSQL,dtOracle};
public:		// User declarations
	__fastcall TDataModuleMain(TComponent* Owner);
public:
	OPERATOR_INFO m_oiOperatorInfo;
private:	// User declarations
	String GetConnectionString();
	String GetMDConnectionString(String& strDBName);
private:
	String m_strConnection;
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModuleMain *DataModuleMain;
//---------------------------------------------------------------------------
#endif
