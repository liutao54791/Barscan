//---------------------------------------------------------------------------


#pragma hdrstop

#include "UnitPageControlContainer.h"
#include "UnitFormBase.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


TContainer::TContainer(TWinControl *pwcParent)
{
	m_ppcPageControl = new TcxPageControl(pwcParent);
	m_ppcPageControl->Name = "Container";
	m_ppcPageControl->Parent = pwcParent;
	m_ppcPageControl->Align = alClient;
	m_ppcPageControl->OnMouseDown = PageControlMouseDown;
	//m_ppcPageControl->Visible = false;
}
TContainer::~TContainer()
{
   CloseAllForm();
   m_ppcPageControl->Parent = NULL;
   delete m_ppcPageControl;
}
void TContainer::ShowForm(int nModuleId,AnsiString strModuleCaption,
	TFormBase *pForm)
{
	m_ppcPageControl->Visible=true;
	//如果要显示的窗口不存在（未在Pagecontrol中），则动态创建一个TabSheet，并显示dll中的form于其中
	TcxTabSheet* ptsTabSheet = (TcxTabSheet *)(m_ppcPageControl->FindChildControl("TabSheet" + IntToStr(nModuleId)));
	if(ptsTabSheet == NULL)
	{
		ptsTabSheet = new TcxTabSheet(m_ppcPageControl);
		ptsTabSheet->Parent = m_ppcPageControl;
		ptsTabSheet->PageControl = m_ppcPageControl;
		ptsTabSheet->Caption = strModuleCaption;
		ptsTabSheet->Name = "TabSheet" + AnsiString(nModuleId);
		ptsTabSheet->Tag = nModuleId;
		pForm->Parent = ptsTabSheet;
		pForm->Align = alClient;
		pForm->BorderStyle = bsNone;
		pForm->Show();

		m_mFormMap[nModuleId] = pForm;
		ptsTabSheet->OnShow = TabSheetShow;
	}
	else
	{
		delete pForm;
	}

	m_ppcPageControl->ActivePage = ptsTabSheet;
}
void __fastcall TContainer::TabSheetShow(TObject *Sender)
{
	int nTabTag = ((TTabSheet *)(Sender))->Tag;
	TForm* pCurForm = m_mFormMap[nTabTag];
	if(pCurForm && dynamic_cast<TFormBase *>(pCurForm))
	{
		((TFormBase *)pCurForm)->Show();
	}
}
//----------------------------------------------------------------------------
void TContainer::CloseAllForm()
{
	for(int i = m_ppcPageControl->PageCount - 1;i >= 0;i--)
	{
		TcxTabSheet* ptsCurPage = m_ppcPageControl->Pages[i];
		TFormBase *pfbCurForm = (TFormBase*)m_mFormMap[ptsCurPage->Tag];
		if(pfbCurForm)
		{
			pfbCurForm->Close();
			delete  pfbCurForm;
		}
		delete m_ppcPageControl->Pages[i];;
	}
	m_mFormMap.clear();
	m_ppcPageControl->Visible = false;
}
//---------------------------------------------------------------------------
void TContainer::CloseActiveForm()
{
	int i = m_ppcPageControl->PageCount;
	delete m_mFormMap[m_ppcPageControl->ActivePage->Tag];
	m_mFormMap.erase(m_mFormMap.find(m_ppcPageControl->ActivePage->Tag));
	delete m_ppcPageControl->ActivePage;
	if (i == 1)
		m_ppcPageControl->Visible = false;
}
//----------------------------------------------------------------------------
int TContainer::OpenedModuleCount()
{
	return m_ppcPageControl->PageCount;
}
void __fastcall TContainer::PageControlMouseDown(TObject *Sender,
	  TMouseButton Button, TShiftState Shift, int X, int Y)
{
	//在pagecontrol上点右键也激活相应的tabsheet
	if(Button==mbRight)
    {
		int i = m_ppcPageControl->IndexOfTabAt(X,Y);
		if(i < 0) return;
		m_ppcPageControl->ActivePage = m_ppcPageControl->Pages[i];
		TPoint *point = new TPoint;
		GetCursorPos(point);
		m_pmPopupMenu->Popup(point->x,point->y);
		delete point;
	}
}
//---------------------------------------------------------------------------
void TContainer::SetPopupMenu(TPopupMenu  *_PopupMenu)
{
	m_pmPopupMenu = _PopupMenu;
}

