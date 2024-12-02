#include <wx/sizer.h>

#include "calc_base.h"

bool CalcBase::Create(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style,
    const wxString& name)
{

    if (!wxPanel::Create(parent, id, pos, size, style, name))
        return false;

    auto* box_sizer = new wxBoxSizer(wxVERTICAL);

    auto* box_sizer2 = new wxBoxSizer(wxHORIZONTAL);

    m_static_text = new wxStaticText(this, wxID_ANY, "MyLabel");
    box_sizer2->Add(m_static_text, wxSizerFlags().Border(wxALL));

    box_sizer->Add(box_sizer2, wxSizerFlags().Expand().Border(wxALL));

    auto* grid_sizer = new wxGridSizer(5, 4, 0, 0);

    exponent = new wxButton(this, wxID_ANY, "^");
    grid_sizer->Add(exponent, wxSizerFlags().Border(wxLEFT | wxRIGHT | wxTOP, wxSizerFlags::GetDefaultBorder()));

    divide = new wxButton(this, wxID_ANY, "/");
    grid_sizer->Add(divide, wxSizerFlags().Border(wxALL));

    multiply = new wxButton(this, wxID_ANY, "*");
    grid_sizer->Add(multiply, wxSizerFlags().Border(wxALL));

    square_root = new wxButton(this, wxID_ANY, "root");
    grid_sizer->Add(square_root, wxSizerFlags().Border(wxALL));

    btn_7 = new wxButton(this, wxID_ANY, "7");
    grid_sizer->Add(btn_7, wxSizerFlags().Border(wxALL));

    btn_8 = new wxButton(this, wxID_ANY, "8");
    grid_sizer->Add(btn_8, wxSizerFlags().Border(wxALL));

    btn_9 = new wxButton(this, wxID_ANY, "9");
    grid_sizer->Add(btn_9, wxSizerFlags().Border(wxALL));

    subtract = new wxButton(this, wxID_ANY, "-");
    grid_sizer->Add(subtract, wxSizerFlags().Border(wxALL));

    btn_4 = new wxButton(this, wxID_ANY, "4");
    grid_sizer->Add(btn_4, wxSizerFlags().Border(wxALL));

    btn_5 = new wxButton(this, wxID_ANY, "5");
    grid_sizer->Add(btn_5, wxSizerFlags().Border(wxALL));

    btn_6 = new wxButton(this, wxID_ANY, "6");
    grid_sizer->Add(btn_6, wxSizerFlags().Border(wxALL));

    addition = new wxButton(this, wxID_ANY, "+");
    grid_sizer->Add(addition, wxSizerFlags().Border(wxALL));

    btn_1 = new wxButton(this, wxID_ANY, "1");
    grid_sizer->Add(btn_1, wxSizerFlags().Border(wxALL));

    btn_2 = new wxButton(this, wxID_ANY, "2");
    grid_sizer->Add(btn_2, wxSizerFlags().Border(wxALL));

    btn_3 = new wxButton(this, wxID_ANY, "3");
    grid_sizer->Add(btn_3, wxSizerFlags().Border(wxALL));

    m_btn16 = new wxButton(this, wxID_ANY, "MyButton");
    m_btn16->Enable(false);
    m_btn16->Hide();
    grid_sizer->Add(m_btn16, wxSizerFlags().Border(wxALL));

    clearField = new wxButton(this, wxID_ANY, "Clear");
    grid_sizer->Add(clearField, wxSizerFlags().Border(wxALL));

    btn_0 = new wxButton(this, wxID_ANY, "0");
    grid_sizer->Add(btn_0, wxSizerFlags().Border(wxALL));

    addDecimal = new wxButton(this, wxID_ANY, ".");
    grid_sizer->Add(addDecimal, wxSizerFlags().Border(wxALL));

    calculate = new wxButton(this, wxID_ANY, "Calculate");
    grid_sizer->Add(calculate, wxSizerFlags().Border(wxALL, 0));

    box_sizer->Add(grid_sizer, wxSizerFlags().Border(wxALL));

    SetSizerAndFit(box_sizer);

    return true;
}
