#include "UnitConversionFrame.h"

#include "../ConversionsCode/AngleConversion.h"
#include "../ConversionsCode/LengthUnitConversion.h"
#include "../ConversionsCode/TempConversion.h"

#include <string>
#include <wx/wx.h>
#include <wx/valnum.h>

// String arrays with the choice-box values
const wxString angleUnits[2] = {wxASCII_STR("radians"), wxASCII_STR("degrees")};
const wxString lengthUnits[8] = {wxASCII_STR("millimeters"), wxASCII_STR("centimeters"), wxASCII_STR("meters"), wxASCII_STR("kilometers"), wxASCII_STR("inches"), wxASCII_STR("feet"), wxASCII_STR("yards"), wxASCII_STR("miles")};
const wxString tempUnits[3] = {wxASCII_STR("farenheit"), wxASCII_STR("celsius"), wxASCII_STR("kelvin")};
const wxString unitTypes[3] = {wxASCII_STR("angle"), wxASCII_STR("length"), wxASCII_STR("temperature")};

// string arrays with equivalent unit codes for conversion codes
const std::string lengthConversionTable[8] = {"mm", "cm", "m", "km", "in", "ft", "yd", "mi"};
const std::string tempConversionTable[3] = {"far", "cel", "kel"};

// unique control IDs
enum {
	IN_UNIT_ID,
	OUT_UNIT_ID,
	UNIT_TYPE_ID,
	CONVERT_BUTTON_ID
};

UnitConversionFrame::UnitConversionFrame() : wxFrame(nullptr, 1501, "Unit Converter") {
	panel = new wxPanel(this, wxID_ANY); //main panel

	// unit type selector
	unitType = new wxChoice(panel, UNIT_TYPE_ID, wxPoint(0, 120), wxDefaultSize, 3, unitTypes, 0, wxDefaultValidator, wxASCII_STR("Unit Type"));
	
	// in and out unit selectors
	inUnit = new wxChoice(panel, IN_UNIT_ID, wxPoint(100, 0), wxDefaultSize, 0, nullptr, 0, wxDefaultValidator, wxASCII_STR("In units"));
	outUnit = new wxChoice(panel, OUT_UNIT_ID, wxPoint(100, 40), wxDefaultSize, 0, nullptr, 0, wxDefaultValidator, wxASCII_STR("Out units"));

	// input text box
	inUnitText = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxFloatingPointValidator<float>(nullptr, wxNUM_VAL_ZERO_AS_BLANK), wxASCII_STR("In units"));

	// conversion output label
	outputLabel = new wxStaticText(panel, wxID_ANY, wxASCII_STR("out"), wxPoint(0, 40), wxDefaultSize, 0, wxASCII_STR("UNITOUT"));

	//start conversion button
	auto *convertButton = new wxButton(panel, CONVERT_BUTTON_ID, wxASCII_STR("Convert"), wxPoint(0, 80), wxDefaultSize, 0, wxDefaultValidator, wxASCII_STR("CONVERTBTN"));

	// Bind convert and type change events to functions
	Bind(wxEVT_BUTTON, &UnitConversionFrame::OnConvert, this, CONVERT_BUTTON_ID);
	Bind(wxEVT_CHOICE, &UnitConversionFrame::OnTypeChange, this, UNIT_TYPE_ID);
	Bind(wxEVT_CLOSE_WINDOW, &UnitConversionFrame::OnClose, this, 1501);
}

void UnitConversionFrame::OnClose(wxCloseEvent &evt) {
	Show(false);
}

void UnitConversionFrame::OnConvert(wxCommandEvent &event) {
	//if the input and output units are the same, just copy input to output	
	if(inUnit->GetSelection() == outUnit->GetSelection()) {
		outputLabel->SetLabel(inUnitText->GetLineText(0));
		return;
	}
	// get input and output unit selections
	auto inputType = inUnit->GetString(inUnit->GetSelection());
	auto outputType = outUnit->GetString(outUnit->GetSelection());
	double result;
	inUnitText->GetLineText(0).ToDouble(&result);
	switch (unitType->GetSelection()) { //check selected unit type
		case 0: //angle
			if (inputType == "degrees" && outputType == "radians") {
				result = degreesToRadians(result);
			} else if (inputType == "radians" && outputType == "degrees") {
				result = radiansToDegrees(result);
			}
			// set output
			outputLabel->SetLabel(wxString::FromDouble(result));
			break;
		case 1: //length
			// use lookup arrays to get in and out units
			result = LengthConv(result, lengthConversionTable[inUnit->GetSelection()], lengthConversionTable[outUnit->GetSelection()]);
			// set output
			outputLabel->SetLabel(wxString::FromDouble(result));
			break;
		case 2: //temperature
			if (inputType == "farenheit") {
				result = farenheitConverter(result, tempConversionTable[outUnit->GetSelection()]);
			} else if (inputType == "celsius") {
				result = celciusConverter(result, tempConversionTable[outUnit->GetSelection()]);
			} else if (inputType == "kelvin") {
				result = kelvinConverter(result, tempConversionTable[outUnit->GetSelection()]);
			}
			// set output
			outputLabel->SetLabel(wxString::FromDouble(result));
			break;
	}
}

// this runs when a new unit type is selected to change available units
void UnitConversionFrame::OnTypeChange(wxCommandEvent &event) {
	inUnit->Destroy(); // destroy old wxChoice controls since their values can't be changed after creation
	outUnit->Destroy();

	// create new ones to replace them
	switch (unitType->GetSelection()) {
		case 0: // angle
			inUnit = new wxChoice(panel, IN_UNIT_ID, wxPoint(100, 0), wxDefaultSize, 2, angleUnits, 0, wxDefaultValidator, wxASCII_STR("In units"));
			outUnit = new wxChoice(panel, OUT_UNIT_ID, wxPoint(100, 40), wxDefaultSize, 2, angleUnits, 0, wxDefaultValidator, wxASCII_STR("Out units"));
			break;
		case 1: // length
			inUnit = new wxChoice(panel, IN_UNIT_ID, wxPoint(100, 0), wxDefaultSize, 8, lengthUnits, 0, wxDefaultValidator, wxASCII_STR("In units"));
			outUnit = new wxChoice(panel, OUT_UNIT_ID, wxPoint(100, 40), wxDefaultSize, 8, lengthUnits, 0, wxDefaultValidator, wxASCII_STR("Out units"));
			break;
		case 2: // temperature
			inUnit = new wxChoice(panel, IN_UNIT_ID, wxPoint(100, 0), wxDefaultSize, 3, tempUnits, 0, wxDefaultValidator, wxASCII_STR("In units"));
			outUnit = new wxChoice(panel, OUT_UNIT_ID, wxPoint(100, 40), wxDefaultSize, 3, tempUnits, 0, wxDefaultValidator, wxASCII_STR("Out units"));	
			break;
	}
	panel->Layout(); // call layout to make sure new controls appear
}
