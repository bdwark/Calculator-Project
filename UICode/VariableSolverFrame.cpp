#include "VariableSolverFrame.h"

#include "../Variable/QuadInequalities.h"
#include "../Variable/SimplifyExpression.h"

#include <string>
#include <wx/wx.h>
#include <wx/valnum.h>

// Available modes
const wxString modes[2] = {wxASCII_STR("Simply Expression"), wxASCII_STR("Evaluate Inequality")};

// Create frame and components
VariableSolverFrame::VariableSolverFrame() : wxFrame(nullptr, 1505, "Variable Solver") {
	SetMinSize(wxSize(300, 150));
	SetMaxSize(wxSize(300, 150));
	panel = new wxPanel(this, wxID_ANY);

	modeSelector = new wxChoice(panel, wxID_ANY, wxPoint(0, 0), wxDefaultSize, 2, modes, 0, wxDefaultValidator, wxASCII_STR("Selected Mode"));

	auto textValidator = new wxTextValidator(wxFILTER_INCLUDE_CHAR_LIST, nullptr);
	textValidator->SetCharIncludes(wxASCII_STR("1234567890xy()<>=^+-"));
	equationInput = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxPoint(0, 40), wxSize(200, 30), 0, *textValidator, wxASCII_STR("Input Equation"));

	solveButton = new wxButton(panel, 900, wxASCII_STR("Solve"), wxPoint(200, 0), wxDefaultSize, 0, wxDefaultValidator, wxASCII_STR("SLVBTN"));

	resultText = new wxStaticText(panel, wxID_ANY, wxASCII_STR("Result: "), wxPoint(0, 80), wxDefaultSize, 0, wxASCII_STR("RESTXT"));

	Bind(wxEVT_BUTTON, &VariableSolverFrame::OnSolve, this, 900);	

	Bind(wxEVT_CLOSE_WINDOW, &VariableSolverFrame::OnClose, this, 1505);
}

void VariableSolverFrame::OnSolve(wxCommandEvent &evt) {
	switch (modeSelector->GetSelection()) { // Take input text, process it, then output on the label
		case 0: // Simplify
			resultText->SetLabel(simplifyExpression(equationInput->GetLineText(0).ToStdString()));
		break;
		case 1: // Inequality
			resultText->SetLabel(quadraticInequality(equationInput->GetLineText(0).ToStdString()));
		break;
	}
}

void VariableSolverFrame::OnClose(wxCloseEvent &evt) {
	Show(false);
}
