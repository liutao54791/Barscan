//---------------------------------------------------------------------------

#ifndef UnitPageControlContainerH
#define UnitPageControlContainerH
//---------------------------------------------------------------------------
#include "cxControls.hpp"
#include "cxPC.hpp"
#include <map>

#define WM_COMMON_MESSAGE					WM_USER + 100

using std::map;
//---------------------------------------------------------------------------
class TFormBase;

class TContainer
{
public:
	TContainer(TWinControl *pwcParent);
	~TContainer();
public:
	void ShowForm(int nModuleId,AnsiString strModuleCaption,TFormBase *pForm);       //打开窗体
	void CloseActiveForm();                                                  		//关闭当前窗体
	void CloseAllForm();                                                     		//关闭所有窗体
	void SetPopupMenu(TPopupMenu *_PopupMenu);                              		//设置容器右键菜单
	int OpenedModuleCount();
private:
	void __fastcall PageControlMouseDown(TObject *Sender,TMouseButton Button,
		TShiftState Shift, int X, int Y);
	void __fastcall TabSheetShow(TObject *Sender);
private:
	TcxPageControl* m_ppcPageControl;

	TPopupMenu* m_pmPopupMenu;
	map <int, HINSTANCE> m_mLibMap;
	map <int, TForm*> m_mFormMap;
};

#endif
