#ifndef MODULES_FRAME
#define MODULES_FRAME

#include <wx/wx.h>

class ModulesFrame : public wxFrame {
	public:
		ModulesFrame();
	private:
		void OnClose(wxCloseEvent &evt);
};

#endif
