#pragma once

#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/panel.h>
#include <wx/stattext.h>

class CalcBase : public wxPanel
{
public:
    CalcBase() {}
    CalcBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name = wxPanelNameStr)
    {
        Create(parent, id, pos, size, style, name);
    }

    bool Create(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name = wxPanelNameStr);

protected:

    // Class member variables

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
    wxStaticText* m_static_text;
};
