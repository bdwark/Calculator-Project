//#include "./UnitConversionFrame.h"
//#include "./GrapherFrame.h"
#include "./ModulesFrame.h"

#include <wx/wx.h>

// main app
class CalculatorApp : public wxApp {
	public:
		bool OnInit() override;
};

wxIMPLEMENT_APP(CalculatorApp);

bool CalculatorApp::OnInit() {
	// until switch menu is created, run one frame or the other
	auto modulesFrame = new ModulesFrame();
	modulesFrame->Show(true);
	//auto unitConversionFrame = new UnitConversionFrame();
	//unitConversionFrame->Show(true);	
	//auto grapherFrame = new GrapherFrame();
	//grapherFrame->Show(true);
	
	SetTopWindow(modulesFrame);
	return true;
}
