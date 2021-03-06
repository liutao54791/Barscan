//---------------------------------------------------------------------------

#ifndef UnitFormProgressbarH
#define UnitFormProgressbarH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "cxContainer.hpp"
#include "cxControls.hpp"
#include "cxEdit.hpp"
#include "cxGroupBox.hpp"
#include "cxLookAndFeelPainters.hpp"
#include "cxProgressBar.hpp"
#include <ExtCtrls.hpp>
#include "cxGraphics.hpp"
#include "cxLookAndFeels.hpp"
#include "dxSkinBlack.hpp"
#include "dxSkinBlue.hpp"
#include "dxSkinBlueprint.hpp"
#include "dxSkinCaramel.hpp"
#include "dxSkinCoffee.hpp"
#include "dxSkinDarkRoom.hpp"
#include "dxSkinDarkSide.hpp"
#include "dxSkinDevExpressDarkStyle.hpp"
#include "dxSkinDevExpressStyle.hpp"
#include "dxSkinFoggy.hpp"
#include "dxSkinGlassOceans.hpp"
#include "dxSkinHighContrast.hpp"
#include "dxSkiniMaginary.hpp"
#include "dxSkinLilian.hpp"
#include "dxSkinLiquidSky.hpp"
#include "dxSkinLondonLiquidSky.hpp"
#include "dxSkinMcSkin.hpp"
#include "dxSkinMoneyTwins.hpp"
#include "dxSkinOffice2007Black.hpp"
#include "dxSkinOffice2007Blue.hpp"
#include "dxSkinOffice2007Green.hpp"
#include "dxSkinOffice2007Pink.hpp"
#include "dxSkinOffice2007Silver.hpp"
#include "dxSkinOffice2010Black.hpp"
#include "dxSkinOffice2010Blue.hpp"
#include "dxSkinOffice2010Silver.hpp"
#include "dxSkinPumpkin.hpp"
#include "dxSkinsCore.hpp"
#include "dxSkinsDefaultPainters.hpp"
#include "dxSkinSeven.hpp"
#include "dxSkinSevenClassic.hpp"
#include "dxSkinSharp.hpp"
#include "dxSkinSharpPlus.hpp"
#include "dxSkinSilver.hpp"
#include "dxSkinSpringTime.hpp"
#include "dxSkinStardust.hpp"
#include "dxSkinSummer2008.hpp"
#include "dxSkinTheAsphaltWorld.hpp"
#include "dxSkinValentine.hpp"
#include "dxSkinVS2010.hpp"
#include "dxSkinWhiteprint.hpp"
#include "dxSkinXmas2008Blue.hpp"
#include "dxSkinMetropolis.hpp"
#include "dxSkinMetropolisDark.hpp"
#include "dxSkinOffice2013DarkGray.hpp"
#include "dxSkinOffice2013LightGray.hpp"
#include "dxSkinOffice2013White.hpp"
#include "dxSkinOffice2016Colorful.hpp"
#include "dxSkinOffice2016Dark.hpp"
#include "dxSkinVisualStudio2013Blue.hpp"
#include "dxSkinVisualStudio2013Dark.hpp"
#include "dxSkinVisualStudio2013Light.hpp"
//---------------------------------------------------------------------------
class TFormProgressbar : public TForm
{
__published:	// IDE-managed Components
    TcxGroupBox *cxGroupBoxMain;
    TcxProgressBar *cxProgressBarMain;
private:	// User declarations
public:		// User declarations
    __fastcall TFormProgressbar(TComponent* Owner);

public:
	void SetTitile(AnsiString strTitle)
    {
        cxGroupBoxMain->Caption = strTitle;
    }
    void SetMax(double nMax)
    {
		cxProgressBarMain->Properties->Max = nMax;
    }
    void InitPosition(double nPosition)
    {
        cxProgressBarMain->Position = nPosition;
	}
    void AddPosition(int nStep = 1)
    {
        cxProgressBarMain->Position = cxProgressBarMain->Position + nStep;
    }
    double GetCurPosition()
    {
		return cxProgressBarMain->Position;
    }
    void ShowProgressbar(AnsiString strTitle,double nMax,double nPosition)
    {
        cxGroupBoxMain->Caption = strTitle;
		cxProgressBarMain->Properties->Max = nMax;
        cxProgressBarMain->Position = nPosition;
        this->Show();
    }
    void CloseProgressbar()
    {
        cxProgressBarMain->Properties->Max = 0;
        cxProgressBarMain->Position = 0;
        this->Close();
    } 
};
//---------------------------------------------------------------------------
extern PACKAGE TFormProgressbar *FormProgressbar;
//---------------------------------------------------------------------------
#endif
