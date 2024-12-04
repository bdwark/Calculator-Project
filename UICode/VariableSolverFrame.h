#include <wx/wx.h>

class VariableSolverFrame : public wxFrame {
	public:
		VariableSolverFrame();
	private:
		wxPanel* panel;
		wxChoice* modeSelector;
		wxTextCtrl* equationInput;
		wxButton* solveButton;
		wxStaticText* resultText;
		void OnSolve(wxCommandEvent &evt);
		void OnClose(wxCloseEvent &evt);
};
