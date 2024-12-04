#include "GrapherFrame.h"

#include "Graph_calc.h"
#include "Polyfunc.h"

#include <vector>
#include <cmath>
#include <wx/wx.h>
#include <wx/valnum.h>

//unique control IDs for each element
enum GraphControlID {
	SETTINGTXT,
	PLOTBTN
};

GrapherFrame::GrapherFrame() : wxFrame(nullptr, 1500, "Grapher") {
	
	drawPane = new GraphDrawPane(this); // create pane to draw in
	drawPane->setEquation(1, -5, 7, -5, 5); //set default equation to plot
	
	// create the text boxes for each equation and graph parameter
	aText = new wxTextCtrl(drawPane, SETTINGTXT, wxEmptyString, wxPoint(0,0), wxDefaultSize, 0, wxFloatingPointValidator<float>(nullptr, wxNUM_VAL_ZERO_AS_BLANK), wxASCII_STR("ATXTBOX"));
	aText->SetHint("A");
	bText = new wxTextCtrl(drawPane, SETTINGTXT, wxEmptyString, wxPoint(0,40), wxDefaultSize, 0, wxFloatingPointValidator<float>(nullptr, wxNUM_VAL_ZERO_AS_BLANK), wxASCII_STR("BTXTBOX"));
	bText->SetHint("B");
	cText = new wxTextCtrl(drawPane, SETTINGTXT, wxEmptyString, wxPoint(0,80), wxDefaultSize, 0, wxFloatingPointValidator<float>(nullptr, wxNUM_VAL_ZERO_AS_BLANK), wxASCII_STR("CTXTBOX"));
	cText->SetHint("C");
	leftXText = new wxTextCtrl(drawPane, SETTINGTXT, wxEmptyString, wxPoint(0,120), wxDefaultSize, 0, wxFloatingPointValidator<float>(nullptr, wxNUM_VAL_ZERO_AS_BLANK), wxASCII_STR("LEFTXBOX"));
	leftXText->SetHint("Left X");
	rightXText = new wxTextCtrl(drawPane, SETTINGTXT, wxEmptyString, wxPoint(0,160), wxDefaultSize, 0, wxFloatingPointValidator<float>(nullptr, wxNUM_VAL_ZERO_AS_BLANK), wxASCII_STR("RIGHTXBOX"));
	rightXText->SetHint("Right X");

	// create the plot button and bind it to set the equation
	auto button = new wxButton(drawPane, PLOTBTN, wxASCII_STR("Plot"), wxPoint(0,200), wxDefaultSize, 0, wxDefaultValidator, wxASCII_STR("PLOTBTN"));
	Bind(wxEVT_BUTTON, &GrapherFrame::OnSettingTextChange, this, PLOTBTN);

	Bind(wxEVT_CLOSE_WINDOW, &GrapherFrame::OnClose, this, 1500);
}

void GrapherFrame::OnSettingTextChange(wxCommandEvent &evt) {
	double a, b, c, leftX, rightX; // get parameters from text boxes
	aText->GetLineText(0).ToDouble(&a);
	bText->GetLineText(0).ToDouble(&b);
	cText->GetLineText(0).ToDouble(&c);
	leftXText->GetLineText(0).ToDouble(&leftX);
	rightXText->GetLineText(0).ToDouble(&rightX);
	drawPane->setEquation(a, b, c, leftX, rightX); // update parameters
	this->Refresh(); // redraw the screen so the graph changes
}

void GrapherFrame::OnClose(wxCloseEvent &evt) {
	Show(false);
}

GraphDrawPane::GraphDrawPane(wxFrame *parent) : wxPanel(parent) {
	Bind(wxEVT_PAINT, &GraphDrawPane::paintEvent, this, wxID_ANY); //Bind the draw event to the custom screen draw function
}

void GraphDrawPane::paintEvent(wxPaintEvent &evt) {
	wxPaintDC dc(this); // render the screen using custom function
	render(dc);
}

void GraphDrawPane::paintNow() {
	wxClientDC dc(this);
	render(dc);
}

void GraphDrawPane::render(wxDC &dc) {
	dc.Clear(); // clear screen
	wxSize winSize = GetSize();
	int winWidth = winSize.GetWidth();
	int winHeight = winSize.GetHeight();
	double scale = winWidth/(rightX-leftX); //scale to convert graph units to pixels
	//draw background
	dc.DrawLine(0, winHeight/2, winWidth, winHeight/2); // axis lines
	dc.DrawLine(winWidth/2, 0, winWidth/2, winHeight);
	double limit = (winWidth/2.0)/scale;
	for (double i = 0; i <= limit; i=i+0.5) { // create tick marks
		dc.DrawLine((winWidth/2)+i*scale, (winHeight/2)+10, (winWidth/2)+i*scale, (winHeight/2)-10);
		dc.DrawLine((winWidth/2)+i*scale*-1.0, (winHeight/2)+10, (winWidth/2)+i*scale*-1.0, (winHeight/2)-10);	
		if (i !=0 && ((int)(i*10))%10 == 0) { 
			dc.DrawText(wxString::FromDouble(i, 1), (winWidth/2)+i*scale, (winHeight/2)+15);
			dc.DrawText(wxString::FromDouble(-i, 1), (winWidth/2)+i*scale*-1.0, (winHeight/2)+15);
		}
	}
	limit = (winHeight/2.0)/scale;
	for (double i = 0; i <= limit; i=i+0.5) {
		dc.DrawLine((winWidth/2)+10, (winHeight/2)+i*scale, (winWidth/2)-10, (winHeight/2)+i*scale);
		dc.DrawLine((winWidth/2)+10, (winHeight/2)+i*scale*-1, (winWidth/2)-10, (winHeight/2)+i*scale*-1);
		if (i != 0 && ((int)(i*10))%10 == 0) {
			dc.DrawText(wxString::FromDouble(-i, 1), (winWidth/2)+15, (winHeight/2)+i*scale);
			dc.DrawText(wxString::FromDouble(i, 1), (winWidth/2)+15, (winHeight/2)+i*scale*-1.0);
		}
	}
	//draw line
	points = graphCalc(a, b, c, leftX, rightX, 2*winWidth); //supersample points for nicer line
	dc.SetPen(wxPen(wxColor(255, 0, 0), 1));
	for (auto point : points) { // plot each point returned by function
		dc.DrawPoint((winWidth/2)+point.getX()*scale, (winHeight/2)-(point.getY()*scale));
	}
}

//setter function for the equation variables
void GraphDrawPane::setEquation(double a, double b, double c, double leftX, double rightX) {
	this->a = a; 
	this->b = b;
	this->c = c;
	this->leftX = leftX;
	this->rightX = rightX;
}
