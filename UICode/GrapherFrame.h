#ifndef GRAPHER_FRAME
#define GRAPHER_FRAME

#include "../GraphingCode/Polyfunc.h"

#include <vector>
#include <wx/wx.h>

// wxPanel derived class that implements custom rendering to plot points
class GraphDrawPane : public wxPanel {
	public:
		GraphDrawPane(wxFrame *parent);
		void paintEvent(wxPaintEvent &evt);
		void paintNow();
		void render(wxDC &dc);		

		void setEquation(double a, double b, double c, double leftX, double rightX);
	private:
		std::vector<Polyfunc> points;		

		double a, b, c, leftX, rightX;
};


// Main frame for the graphing window
class GrapherFrame : public wxFrame {
	public: 
		GrapherFrame();
	private:
		void OnSettingTextChange(wxCommandEvent &evt);
		void OnClose(wxCloseEvent &evt);
		wxTextCtrl *aText, *bText, *cText, *leftXText, *rightXText;		
		GraphDrawPane *drawPane;
};


#endif
