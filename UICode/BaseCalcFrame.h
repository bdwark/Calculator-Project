#ifndef BASE_CALC_FRAME
#define BASE_CALC_FRAME

#include "../BaseCalculator/calculator.h"

#include <wx/wx.h>

class BaseCalcFrame : public wxFrame {
	public:
		BaseCalcFrame();
	private:
		wxButton* addDecimal;
		wxButton* addition;
		wxButton* btn_0;
		wxButton* btn_1;
		wxButton* btn_2;
		wxButton* btn_3;
		wxButton* btn_4;
		wxButton* btn_5;
		wxButton* btn_6;
		wxButton* btn_7;
		wxButton* btn_8;
		wxButton* btn_9;
		wxButton* calculate;
		wxButton* clearField;
		wxButton* divide;
		wxButton* exponent;
		wxButton* m_btn16;
		wxButton* multiply;
		wxButton* square_root;
		wxButton* subtract;
		wxStaticText* mainText;

		void OnTextButton(wxCommandEvent &evt);
		void OnCalculate(wxCommandEvent &evt);
		void OnSqRoot(wxCommandEvent &evt);
		void OnTextClear(wxCommandEvent &evt);
		void OnClose(wxCloseEvent &evt);
};

#endif
