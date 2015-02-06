///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  6 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/menu.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrameBase
///////////////////////////////////////////////////////////////////////////////
class MyFrameBase : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* m_menubar;
		wxMenu* m_menuStart;
		wxMenu* m_menuOption;
		wxMenu* m_menuTypeEBC;
		wxMenu* m_menuSerialPort;
		wxMenu* m_menuLog;
		wxMenu* m_menuControl;
		wxStatusBar* m_statusBar;
		wxNotebook* m_notebook2;
		wxPanel* m_panelDiagnostic;
		wxPanel* m_panelErrors;
		wxPanel* m_panelADC;
		wxPanel* m_panelOsciloscop;
		wxPanel* m_panelTimes;
		wxPanel* m_panelIdentification;
	
	public:
		
		MyFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("SensDiag"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MyFrameBase();
	
};

#endif //__GUI_H__
