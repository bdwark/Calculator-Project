#include <wx/wx.h>
#include <wx/valnum.h>

class StatFrame : public wxFrame {
	public:
		StatFrame();
	private:
		wxPanel* panel;
		wxTextCtrl* valuesInput;
		wxButton* computeButton;
		wxStaticText* resultText;
		void OnCompute(wxCommandEvent &evt);
		void OnClose(wxCloseEvent &evt);
};
