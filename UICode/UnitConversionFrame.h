#ifndef UNIT_CONVERSION_FRAME
#define UNIT_CONVERSION_FRAME

#include <wx/wx.h>
#include <wx/valnum.h>

// Main frame from unit conversion
class UnitConversionFrame : public wxFrame {
	public:
		UnitConversionFrame();
	private:
		void OnConvert(wxCommandEvent &event);
		void OnTypeChange(wxCommandEvent &event);
		void OnClose(wxCloseEvent &evt);
		
		wxPanel *panel;
		wxChoice *unitType;
		wxChoice *inUnit;
		wxChoice *outUnit;
		wxTextCtrl *inUnitText;
		wxStaticText *outputLabel;
};

#endif
