#include "./ModulesFrame.h"
#include <wx/wx.h>

// Main application class
class CalculatorApp : public wxApp {
public:
    bool OnInit() override;
};

// This macro instantiates the wxApp class and handles the entry point
wxIMPLEMENT_APP(CalculatorApp);

// Manually define main() to ensure correct entry point
int main(int argc, char** argv) {
    return wxEntry(argc, argv);  // Calls wxWidgets' entry point
}

bool CalculatorApp::OnInit() {
    // Initialize the main application frame
    auto modulesFrame = new ModulesFrame();
    
    // Show the frame
    modulesFrame->Show(true);

    // Set it as the top window so all windows close when it's closed
    SetTopWindow(modulesFrame);

    return true;  // Indicate successful initialization
}
