#include "./ModulesFrame.h"

#include <wx/wx.h>

// main app
class CalculatorApp : public wxApp {
	public:
		bool OnInit() override;
};

//This macro instantiates the wxApp and handles the memory
wxIMPLEMENT_APP(CalculatorApp);

bool CalculatorApp::OnInit() {
	// Instantiate the module window and show it
	auto modulesFrame = new ModulesFrame();
	modulesFrame->Show(true);
	
	// Set it as the top window so all windows close when it's closed
	SetTopWindow(modulesFrame);
	return true;
}
