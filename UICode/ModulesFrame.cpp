#include "ModulesFrame.h"

#include "./UnitConversionFrame.h"
#include "./GrapherFrame.h"

#include <wx/wx.h>

class FrameLaunchButton : public wxButton {
	public:
		FrameLaunchButton(wxWindow *parent, wxWindowID id, const wxString &label, const wxPoint &pos, const wxString &name, wxFrame *launchFrame);
	private:
		wxFrame *launchFrame;
		void OnClick(wxCommandEvent &evt);
};

FrameLaunchButton::FrameLaunchButton(wxWindow *parent, wxWindowID id, const wxString &label, const wxPoint &pos, const wxString &name, wxFrame *launchFrame) : wxButton(parent, id, label, pos, wxDefaultSize, 0, wxDefaultValidator, name) {
	this->launchFrame = launchFrame;
	Bind(wxEVT_BUTTON, &FrameLaunchButton::OnClick, this, id);
}

void FrameLaunchButton::OnClick(wxCommandEvent &evt) {
	launchFrame->Show(true);
}

ModulesFrame::ModulesFrame() : wxFrame(nullptr, 1000, "Module List") {
	auto pane = new wxPanel(this, wxID_ANY);
	
	auto unitConversionFrame = new UnitConversionFrame();
	auto grapherFrame = new GrapherFrame();
	unitConversionFrame->Show(true);
	grapherFrame->Show(true);

	auto unitConvButton = new FrameLaunchButton(pane, 101, wxASCII_STR("Unit Converter"), wxPoint(0,0), wxASCII_STR("UNITCONVBTN"), unitConversionFrame);
	auto graphButton = new FrameLaunchButton(pane, 102, wxASCII_STR("Grapher"), wxPoint(0,40), wxASCII_STR("GRAPHBTN"), grapherFrame);

	
	Bind(wxEVT_CLOSE_WINDOW, &ModulesFrame::OnClose, this, 1000);
}

void ModulesFrame::OnClose(wxCloseEvent &evt) {
	wxTheApp->ExitMainLoop();
}
