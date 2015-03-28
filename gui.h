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
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/scrolwin.h>
#include <wx/notebook.h>
#include <wx/combobox.h>
#include <wx/statbox.h>
#include <wx/checkbox.h>
#include <wx/timer.h>
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
		wxMenu* m_menuFile;
		wxMenu* m_menuLog;
		wxMenu* m_menuHelp;
		wxStatusBar* m_statusBar;
		wxNotebook* m_notebook2;
		wxPanel* m_panelDiagnostic;
		wxStaticText* m_staticTextDat1;
		wxStaticText* m_staticText_Dat1;
		wxStaticText* m_staticTextDat2;
		wxStaticText* m_staticText_Dat2;
		wxStaticText* m_staticTextDat3;
		wxStaticText* m_staticText_Dat3;
		wxStaticText* m_staticTextDat4;
		wxStaticText* m_staticText_Dat4;
		wxStaticText* m_staticTextDat5;
		wxStaticText* m_staticText_Dat5;
		wxStaticText* m_staticTextDat6;
		wxStaticText* m_staticText_Dat6;
		wxStaticText* m_staticTextDat7;
		wxStaticText* m_staticText_Dat7;
		wxStaticText* m_staticTextDat8;
		wxStaticText* m_staticText_Dat8;
		wxStaticText* m_staticTextDat9;
		wxStaticText* m_staticText_Dat9;
		wxStaticText* m_staticTextDat10;
		wxStaticText* m_staticText_Dat10;
		wxStaticText* m_staticTextDat11;
		wxStaticText* m_staticText_Dat11;
		wxStaticText* m_staticTextDat12;
		wxStaticText* m_staticText_Dat12;
		wxStaticText* m_staticTextDat13;
		wxStaticText* m_staticText_Dat13;
		wxStaticText* m_staticTextDat14;
		wxStaticText* m_staticText_Dat14;
		wxStaticText* m_staticTextDat15;
		wxStaticText* m_staticText_Dat15;
		wxStaticText* m_staticTextDat16;
		wxStaticText* m_staticText_Dat16;
		wxPanel* m_panelErrors;
		wxTextCtrl* m_textCtrlErrors;
		wxButton* m_buttonResetError;
		wxPanel* m_panelADC;
		wxStaticText* m_staticTextAn1;
		wxStaticText* m_staticText_An1;
		wxStaticText* m_staticTextAn2;
		wxStaticText* m_staticText_An2;
		wxStaticText* m_staticTextAn3;
		wxStaticText* m_staticText_An3;
		wxStaticText* m_staticTextAn4;
		wxStaticText* m_staticText_An4;
		wxStaticText* m_staticTextAn5;
		wxStaticText* m_staticText_An5;
		wxStaticText* m_staticTextAn6;
		wxStaticText* m_staticText_An6;
		wxStaticText* m_staticTextAn7;
		wxStaticText* m_staticTextA_n7;
		wxStaticText* m_staticTextAn8;
		wxStaticText* m_staticText_An8;
		wxStaticText* m_staticTextAn9;
		wxStaticText* m_staticText_An9;
		wxStaticText* m_staticTextAn10;
		wxStaticText* m_staticText_An10;
		wxStaticText* m_staticTextAn11;
		wxStaticText* m_staticText_An11;
		wxPanel* m_panelOsciloscop;
		wxScrolledWindow* m_scrolledWindow1;
		wxStaticText* m_staticTextG1;
		wxStaticText* m_staticTextG2;
		wxStaticText* m_staticTextG3;
		wxStaticText* m_staticTextG4;
		wxStaticText* m_staticTextG5;
		wxStaticText* m_staticTextG6;
		wxPanel* m_panelTimes;
		wxStaticText* m_staticTextT1;
		wxStaticText* m_staticText_T1;
		wxStaticText* m_staticTextT2;
		wxStaticText* m_staticText_T2;
		wxStaticText* m_staticTextT3;
		wxStaticText* m_staticText_T3;
		wxStaticText* m_staticTextT4;
		wxStaticText* m_staticText_T4;
		wxStaticText* m_staticTextT5;
		wxStaticText* m_staticText_T5;
		wxStaticText* m_staticTextT6;
		wxStaticText* m_staticText_T6;
		wxStaticText* m_staticTextT7;
		wxStaticText* m_staticText_T7;
		wxStaticText* m_staticTextT8;
		wxStaticText* m_staticText_T8;
		wxStaticText* m_staticTextT9;
		wxStaticText* m_staticText_T9;
		wxStaticText* m_staticTextT10;
		wxStaticText* m_staticText_T10;
		wxStaticText* m_staticTextT11;
		wxStaticText* m_staticText_T11;
		wxStaticText* m_staticTextT12;
		wxStaticText* m_staticText_T12;
		wxStaticText* m_staticTextT13;
		wxStaticText* m_staticText_T13;
		wxStaticText* m_staticTextT14;
		wxStaticText* m_staticText_T14;
		wxStaticText* m_staticTextT15;
		wxStaticText* m_staticText_T15;
		wxStaticText* m_staticTextT16;
		wxStaticText* m_staticText_T16;
		wxPanel* m_panelIdentification;
		wxStaticText* m_staticText60;
		wxStaticText* m_staticTextID1;
		wxStaticText* m_staticText61;
		wxStaticText* m_staticTextID2;
		wxStaticText* m_staticText62;
		wxStaticText* m_staticTextID3;
		wxStaticText* m_staticText63;
		wxStaticText* m_staticTextID4;
		wxStaticText* m_staticText64;
		wxStaticText* m_staticTextID5;
		wxStaticText* m_staticText65;
		wxStaticText* m_staticTextID6;
		wxStaticText* m_staticText66;
		wxStaticText* m_staticTextID7;
		wxStaticText* m_staticText67;
		wxStaticText* m_staticTextID8;
		wxStaticText* m_staticText111;
		wxComboBox* m_comboBoxControl;
		wxStaticText* m_staticControlValue;
		wxButton* m_buttonControlPlus;
		wxButton* m_buttonControlMinus;
		wxStaticText* m_staticText1;
		wxComboBox* m_comboBoxSelectEBC;
		wxStaticText* m_staticText3;
		wxComboBox* m_comboBoxSelectPort;
		wxButton* m_buttonScanPort;
		wxCheckBox* m_checkBoxAdapter;
		wxCheckBox* m_checkBoxLog;
		wxButton* m_buttonStart;
		wxTimer m_timerSystem;
		wxTimer m_timerWork;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnStart( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnExit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveLog( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnPageChange( wxNotebookEvent& event ) { event.Skip(); }
		virtual void OnResetError( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnComboboxSelectControl( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickControlPlus( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickContolMinus( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectEBC( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectPort( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnScanPort( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckAdapter( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCheckLogProtocol( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSysTimerTick( wxTimerEvent& event ) { event.Skip(); }
		virtual void OnTimerTick( wxTimerEvent& event ) { event.Skip(); }
		
	
	public:
		wxMenuItem* m_menuItemFileStart;
		
		MyFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("SensDiag"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 850,563 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MyFrameBase();
	
};

#endif //__GUI_H__
