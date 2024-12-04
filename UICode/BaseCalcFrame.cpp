#include "BaseCalcFrame.h"

#include "calculator.h"
#include <wx/wx.h>
#undef byte


BaseCalcFrame::BaseCalcFrame() : wxFrame(nullptr, 1502, "Calculator") {
	SetMinSize(wxSize(700, 700));
	SetMaxSize(wxSize(700, 700));	

	// create sizers and grid for components
	auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer2 = new wxBoxSizer(wxHORIZONTAL);

    mainText = new wxStaticText(this, wxID_ANY, "");
    box_sizer2->Add(mainText, wxSizerFlags().Border(wxALL));

    box_sizer->Add(box_sizer2, wxSizerFlags().Expand().Border(wxALL));

    auto* grid_sizer = new wxGridSizer(5, 4, 0, 0);

	// exponent button
    exponent = new wxButton(this, 1115, "^");
    grid_sizer->Add(exponent, wxSizerFlags().Border(wxLEFT | wxRIGHT | wxTOP, wxSizerFlags::GetDefaultBorder()));

	// divide button
    divide = new wxButton(this, 1114, "/");
    grid_sizer->Add(divide, wxSizerFlags().Border(wxALL));

	// multiply button
    multiply = new wxButton(this, 1113, "*");
    grid_sizer->Add(multiply, wxSizerFlags().Border(wxALL));
	
	// square root button
    square_root = new wxButton(this, 1116, "root");
    grid_sizer->Add(square_root, wxSizerFlags().Border(wxALL));

	// 7 button
    btn_7 = new wxButton(this, 1107, "7");
    grid_sizer->Add(btn_7, wxSizerFlags().Border(wxALL));

	// 8 button
    btn_8 = new wxButton(this, 1108, "8");
    grid_sizer->Add(btn_8, wxSizerFlags().Border(wxALL));

	// 9 button
    btn_9 = new wxButton(this, 1109, "9");
    grid_sizer->Add(btn_9, wxSizerFlags().Border(wxALL));

	// subtract button
    subtract = new wxButton(this, 1112, "-");
    grid_sizer->Add(subtract, wxSizerFlags().Border(wxALL));

	// 4 button
    btn_4 = new wxButton(this, 1104, "4");
    grid_sizer->Add(btn_4, wxSizerFlags().Border(wxALL));

	// 5 button
    btn_5 = new wxButton(this, 1105, "5");
    grid_sizer->Add(btn_5, wxSizerFlags().Border(wxALL));

	// 6 button
    btn_6 = new wxButton(this, 1106, "6");
    grid_sizer->Add(btn_6, wxSizerFlags().Border(wxALL));
	
	// add button
    addition = new wxButton(this, 1111, "+");
    grid_sizer->Add(addition, wxSizerFlags().Border(wxALL));

	// 1 button
    btn_1 = new wxButton(this, 1101, "1");
    grid_sizer->Add(btn_1, wxSizerFlags().Border(wxALL));

	// 2 button
    btn_2 = new wxButton(this, 1102, "2");
    grid_sizer->Add(btn_2, wxSizerFlags().Border(wxALL));

	// 3 button
    btn_3 = new wxButton(this, 1103, "3");
    grid_sizer->Add(btn_3, wxSizerFlags().Border(wxALL));

	// clear button
    clearField = new wxButton(this, 1121, "Clear");
    grid_sizer->Add(clearField, wxSizerFlags().Border(wxALL));

	// 0 button
    btn_0 = new wxButton(this, 1100, "0");
    grid_sizer->Add(btn_0, wxSizerFlags().Border(wxALL));

	// decimal button
    addDecimal = new wxButton(this, 1110, ".");
    grid_sizer->Add(addDecimal, wxSizerFlags().Border(wxALL));

	// calculate button
    calculate = new wxButton(this, 1120, "Calculate");
    grid_sizer->Add(calculate, wxSizerFlags().Border(wxALL, 0));

    box_sizer->Add(grid_sizer, wxSizerFlags().Border(wxALL));

    SetSizerAndFit(box_sizer);
	SetMaxSize(GetBestSize());
	
	// Bind functions for buttons
	Bind(wxEVT_BUTTON, &BaseCalcFrame::OnTextButton, this, 1100, 1115);
	Bind(wxEVT_BUTTON, &BaseCalcFrame::OnCalculate, this, 1120);
	Bind(wxEVT_BUTTON, &BaseCalcFrame::OnTextClear, this, 1121);
	Bind(wxEVT_BUTTON, &BaseCalcFrame::OnSqRoot, this, 1116);

	// Hide window instead of destroying objects so modules window doesn't have null pointers
	Bind(wxEVT_CLOSE_WINDOW, &BaseCalcFrame::OnClose, this, 1502);

	Show(false);
}

void BaseCalcFrame::OnClose(wxCloseEvent &evt) {
	Show(false); // Hide window instead of destroying it
}

void BaseCalcFrame::OnTextButton(wxCommandEvent &evt) {
	char x = ' '; // character to append
	switch (evt.GetId()) { // get button id and assign character based on it
		case 1100:
			x = '0';
			break;
		case 1101:
			x = '1';
			break;
		case 1102:
			x = '2';
			break;
		case 1103:
			x = '3';
			break;
		case 1104:
			x = '4';
			break;
		case 1105:
			x = '5';
			break;
		case 1106:
			x = '6';
			break;
		case 1107:
			x = '7';
			break;
		case 1108:
			x = '8';
			break;
		case 1109:
			x = '9';
			break;
		case 1110:
			x = '.';
			break;
		case 1111:
			x = '+';
			break;
		case 1112:
			x = '-';
			break;
		case 1113:
			x = '*';
			break;
		case 1114:
			x = '/';
			break;
		case 1115:
			x = '^';
			break;
	}
	wxString prev = mainText->GetLabel(); // get label text
	if(prev == "Err") prev.Empty(); // Clear it if error
	prev.Append(x); // append x value
	mainText->SetLabel(prev); // set label text to new value
}

void BaseCalcFrame::OnTextClear(wxCommandEvent &evt) {
	mainText->SetLabel(wxEmptyString); // clear text
}

void BaseCalcFrame::OnSqRoot(wxCommandEvent &evt) {
	Calculator* c = new Calculator(); // new calculator
	wxString s = wxASCII_STR("s"); // add operation
	s.Append(mainText->GetLabel()); // add value
	float result = c->Calculate(s.ToStdString()); // perform calculation
	mainText->SetLabel(wxString::FromDouble(result)); // set calculated value
}

void BaseCalcFrame::OnCalculate(wxCommandEvent &evt) {
	Calculator* c = new Calculator(); 
	wxString eq = mainText->GetLabel(); // get equation
	float result = c->Calculate(eq.ToStdString()); // calculate equation
	eq = wxString::FromDouble(result); // get result and set label with it
	mainText->SetLabel(eq);
}
