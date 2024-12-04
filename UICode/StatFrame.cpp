#include "StatFrame.h"

#include "Stats.h"

#include <string>
#include <wx/wx.h>
#include <wx/valnum.h>

// Create frame
StatFrame::StatFrame() : wxFrame(nullptr, 1506, "Statistics") {
	SetMinSize(wxSize(300, 200));
	SetMaxSize(wxSize(300, 200));
	panel = new wxPanel(this, wxID_ANY);
	
	auto textValidator = new wxTextValidator(wxFILTER_INCLUDE_CHAR_LIST, nullptr);

	// Only allow correct characters to be typed
	textValidator->SetCharIncludes(wxASCII_STR("-1234567890.,"));
	valuesInput = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(0,0), wxSize(150, 30), 0, *textValidator, wxASCII_STR("Input values"));

	computeButton = new wxButton(panel, 800, wxASCII_STR("Compute"), wxPoint(160,0), wxDefaultSize, 0, wxDefaultValidator, wxASCII_STR("CPTBTN"));

	resultText = new wxStaticText(panel, wxID_ANY, wxASCII_STR("Results: "), wxPoint(0,40), wxDefaultSize, 0, wxASCII_STR("OUTTXT"));

	Bind(wxEVT_BUTTON, &StatFrame::OnCompute, this, 800);

	Bind(wxEVT_CLOSE_WINDOW, &StatFrame::OnClose, this, 1506);
}

void StatFrame::OnClose(wxCloseEvent &evt) {
	Show(true);
	Show(false);
}

void StatFrame::OnCompute(wxCommandEvent &evt) { // Get the input, calculate the statistics, then output them on the label
	std::string vals = valuesInput->GetLineText(0).ToStdString();
	std::string mean = std::to_string(stats(vals, 1));
	std::string median = std::to_string(stats(vals, 2));
	std::string min = std::to_string(stats(vals, 3));
	std::string max = std::to_string(stats(vals, 4));
	std::string s = std::to_string(stats(vals, 5));
	resultText->SetLabel("Mean: " + mean + "\nMedian: " + median + "\nMinimum: " + min + "\nMaximum: " + max + "\nStandard Deviation: " + s);
}
