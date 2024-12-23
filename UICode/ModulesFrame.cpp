#include "ModulesFrame.h"

#include "./UnitConversionFrame.h"
#include "./GrapherFrame.h"
#include "./BaseCalcFrame.h"
#include "./VariableSolverFrame.h"
#include "./StatFrame.h"

#include <wx/wx.h>

// Special button to show frames when clicked
class FrameLaunchButton : public wxButton {
	public:
		FrameLaunchButton(wxWindow *parent, wxWindowID id, const wxString &label, const wxPoint &pos, const wxString &name, wxFrame *launchFrame);
	private:
		wxFrame *launchFrame;
		void OnClick(wxCommandEvent &evt);
};

// Constructor
FrameLaunchButton::FrameLaunchButton(wxWindow *parent, wxWindowID id, const wxString &label, const wxPoint &pos, const wxString &name, wxFrame *launchFrame) : wxButton(parent, id, label, pos, wxSize(150, 30), 0, wxDefaultValidator, name) {
	this->launchFrame = launchFrame; // store pointer to frame to be launched
	Bind(wxEVT_BUTTON, &FrameLaunchButton::OnClick, this, id); // bind launch function to button press
}

void FrameLaunchButton::OnClick(wxCommandEvent &evt) {
	launchFrame->Show(false); // Hide and show frame to ensure it's visible
	launchFrame->Show(true);
}

ModulesFrame::ModulesFrame() : wxFrame(nullptr, 1000, "Module List") {
	SetMinSize(wxSize(150, 200));
	SetMaxSize(wxSize(150, 200));
	auto pane = new wxPanel(this, wxID_ANY); // Main panel
	
	//wxCursor kitty_cursor("custom_cursor.xpm", wxBITMAP_TYPE_XPM, 1, 1);
	//pane->SetCursor(kitty_cursor);	

	auto unitConversionFrame = new UnitConversionFrame(); // Instantiate modules
	auto grapherFrame = new GrapherFrame();
	auto baseCalcFrame = new BaseCalcFrame();
	auto variableSolverFrame = new VariableSolverFrame();
	auto statFrame = new StatFrame();
	unitConversionFrame->Show(true); // Hide all module windows
	grapherFrame->Show(true);
	baseCalcFrame->Show(true);
	variableSolverFrame->Show(true);
	statFrame->Show(true);
	unitConversionFrame->Show(false); 
	grapherFrame->Show(false);
	baseCalcFrame->Show(false);
	variableSolverFrame->Show(false);	
	statFrame->Show(false);

	// Create buttons to show frames
	auto baseCalcButton = new FrameLaunchButton(pane, 101, wxASCII_STR("Basic Calculator"), wxPoint(0,0), wxASCII_STR("BASECALCBTN"), baseCalcFrame);
	auto unitConvButton = new FrameLaunchButton(pane, 102, wxASCII_STR("Unit Converter"), wxPoint(0,40), wxASCII_STR("UNITCONVBTN"), unitConversionFrame);
	auto graphButton = new FrameLaunchButton(pane, 103, wxASCII_STR("Grapher"), wxPoint(0,80), wxASCII_STR("GRAPHBTN"), grapherFrame);
	auto variableButton = new FrameLaunchButton(pane, 104, wxASCII_STR("Variable Solver"), wxPoint(0, 120), wxASCII_STR("VARBTN"), variableSolverFrame);
	auto statButton = new FrameLaunchButton(pane, 105, wxASCII_STR("Statistics"), wxPoint(0, 160), wxASCII_STR("STBTN"), statFrame);	

	// Bind closing window function
	Bind(wxEVT_CLOSE_WINDOW, &ModulesFrame::OnClose, this, 1000);
}

void ModulesFrame::OnClose(wxCloseEvent &evt) {
	wxTheApp->ExitMainLoop(); // Exit program and destroy windows safely
}
