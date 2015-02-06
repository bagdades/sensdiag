#include "myframe.h"

MyFrame::MyFrame( wxWindow* parent )
:
MyFrameBase( parent )
{
	SetIcon(wxIcon(wxT("config.ico")));
	wxDateTime now = wxDateTime::Now();
	now.SetCountry(wxDateTime::UK);
	wxString date;
	date = now.Format(wxT("%x"));
	m_statusBar->SetStatusText(date,3);
}
