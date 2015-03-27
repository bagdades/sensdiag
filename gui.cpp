///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  6 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

MyFrameBase::MyFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	m_menubar = new wxMenuBar( 0 );
	m_menuFile = new wxMenu();
	m_menuItemFileStart = new wxMenuItem( m_menuFile, wxID_ANY, wxString( wxT("Start") ) , wxT("Start diagnostic"), wxITEM_NORMAL );
	m_menuFile->Append( m_menuItemFileStart );
	
	wxMenuItem* m_menuItemFileExit;
	m_menuItemFileExit = new wxMenuItem( m_menuFile, wxID_EXIT, wxString( wxT("E&xit") ) + wxT('\t') + wxT("Exit from programm."), wxEmptyString, wxITEM_NORMAL );
	m_menuFile->Append( m_menuItemFileExit );
	
	m_menubar->Append( m_menuFile, wxT("&File") ); 
	
	m_menuLog = new wxMenu();
	wxMenuItem* m_menuItemSaveFile;
	m_menuItemSaveFile = new wxMenuItem( m_menuLog, wxID_ANY, wxString( wxT("Save file") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuLog->Append( m_menuItemSaveFile );
	
	m_menubar->Append( m_menuLog, wxT("Log") ); 
	
	m_menuHelp = new wxMenu();
	wxMenuItem* m_menuItemHelpAbout;
	m_menuItemHelpAbout = new wxMenuItem( m_menuHelp, wxID_ABOUT, wxString( wxT("&About") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuHelp->Append( m_menuItemHelpAbout );
	
	m_menubar->Append( m_menuHelp, wxT("&Help") ); 
	
	this->SetMenuBar( m_menubar );
	
	m_statusBar = this->CreateStatusBar( 4, 0, wxID_ANY );
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	m_notebook2 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panelDiagnostic = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer66;
	bSizer66 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 16, 2, 0, 30 );
	
	m_staticTextDat1 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat1->Wrap( -1 );
	gSizer1->Add( m_staticTextDat1, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat1 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat1->Wrap( -1 );
	m_staticText_Dat1->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer1->Add( m_staticText_Dat1, 0, wxALL, 5 );
	
	m_staticTextDat2 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat2->Wrap( -1 );
	gSizer1->Add( m_staticTextDat2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat2 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat2->Wrap( -1 );
	m_staticText_Dat2->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer1->Add( m_staticText_Dat2, 0, wxALL, 5 );
	
	m_staticTextDat3 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat3->Wrap( -1 );
	gSizer1->Add( m_staticTextDat3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat3 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat3->Wrap( -1 );
	m_staticText_Dat3->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer1->Add( m_staticText_Dat3, 0, wxALL, 5 );
	
	m_staticTextDat4 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat4->Wrap( -1 );
	gSizer1->Add( m_staticTextDat4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat4 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat4->Wrap( -1 );
	m_staticText_Dat4->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer1->Add( m_staticText_Dat4, 0, wxALL, 5 );
	
	m_staticTextDat5 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat5->Wrap( -1 );
	gSizer1->Add( m_staticTextDat5, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat5 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat5->Wrap( -1 );
	m_staticText_Dat5->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer1->Add( m_staticText_Dat5, 0, wxALL, 5 );
	
	m_staticTextDat6 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat6->Wrap( -1 );
	gSizer1->Add( m_staticTextDat6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat6 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat6->Wrap( -1 );
	m_staticText_Dat6->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer1->Add( m_staticText_Dat6, 0, wxALL, 5 );
	
	m_staticTextDat7 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat7->Wrap( -1 );
	gSizer1->Add( m_staticTextDat7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat7 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat7->Wrap( -1 );
	m_staticText_Dat7->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer1->Add( m_staticText_Dat7, 0, wxALL, 5 );
	
	m_staticTextDat8 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat8->Wrap( -1 );
	gSizer1->Add( m_staticTextDat8, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat8 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat8->Wrap( -1 );
	m_staticText_Dat8->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer1->Add( m_staticText_Dat8, 0, wxALL, 5 );
	
	m_staticTextDat9 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat9->Wrap( -1 );
	gSizer1->Add( m_staticTextDat9, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat9 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat9->Wrap( -1 );
	m_staticText_Dat9->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer1->Add( m_staticText_Dat9, 0, wxALL, 5 );
	
	m_staticTextDat10 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat10->Wrap( -1 );
	gSizer1->Add( m_staticTextDat10, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat10 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat10->Wrap( -1 );
	m_staticText_Dat10->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer1->Add( m_staticText_Dat10, 0, wxALL, 5 );
	
	m_staticTextDat11 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat11->Wrap( -1 );
	gSizer1->Add( m_staticTextDat11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat11 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat11->Wrap( -1 );
	m_staticText_Dat11->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer1->Add( m_staticText_Dat11, 0, wxALL, 5 );
	
	m_staticTextDat12 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat12->Wrap( -1 );
	gSizer1->Add( m_staticTextDat12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat12 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat12->Wrap( -1 );
	m_staticText_Dat12->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer1->Add( m_staticText_Dat12, 0, wxALL, 5 );
	
	m_staticTextDat13 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat13->Wrap( -1 );
	gSizer1->Add( m_staticTextDat13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat13 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat13->Wrap( -1 );
	m_staticText_Dat13->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer1->Add( m_staticText_Dat13, 0, wxALL, 5 );
	
	m_staticTextDat14 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat14->Wrap( -1 );
	gSizer1->Add( m_staticTextDat14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat14 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat14->Wrap( -1 );
	m_staticText_Dat14->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer1->Add( m_staticText_Dat14, 0, wxALL, 5 );
	
	m_staticTextDat15 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat15->Wrap( -1 );
	gSizer1->Add( m_staticTextDat15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat15 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat15->Wrap( -1 );
	m_staticText_Dat15->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer1->Add( m_staticText_Dat15, 0, wxALL, 5 );
	
	m_staticTextDat16 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat16->Wrap( -1 );
	gSizer1->Add( m_staticTextDat16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat16 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat16->Wrap( -1 );
	m_staticText_Dat16->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer1->Add( m_staticText_Dat16, 0, wxALL, 5 );
	
	
	bSizer66->Add( gSizer1, 0, 0, 5 );
	
	
	m_panelDiagnostic->SetSizer( bSizer66 );
	m_panelDiagnostic->Layout();
	bSizer66->Fit( m_panelDiagnostic );
	m_notebook2->AddPage( m_panelDiagnostic, wxT("Діагностика"), true );
	m_panelErrors = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_textCtrlErrors = new wxTextCtrl( m_panelErrors, wxID_ANY, wxT("No Errors."), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	bSizer6->Add( m_textCtrlErrors, 1, wxALL|wxEXPAND, 5 );
	
	m_buttonResetError = new wxButton( m_panelErrors, wxID_ANY, wxT("Reset Errors"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_buttonResetError, 0, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	
	m_panelErrors->SetSizer( bSizer6 );
	m_panelErrors->Layout();
	bSizer6->Fit( m_panelErrors );
	m_notebook2->AddPage( m_panelErrors, wxT("Помилки"), false );
	m_panelADC = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer201;
	bSizer201 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 0, 2, 0, 30 );
	
	m_staticTextAn1 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn1->Wrap( -1 );
	gSizer2->Add( m_staticTextAn1, 0, wxALL, 5 );
	
	m_staticText_An1 = new wxStaticText( m_panelADC, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_An1->Wrap( -1 );
	m_staticText_An1->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer2->Add( m_staticText_An1, 0, wxALL, 5 );
	
	m_staticTextAn2 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn2->Wrap( -1 );
	gSizer2->Add( m_staticTextAn2, 0, wxALL, 5 );
	
	m_staticText_An2 = new wxStaticText( m_panelADC, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_An2->Wrap( -1 );
	m_staticText_An2->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer2->Add( m_staticText_An2, 0, wxALL, 5 );
	
	m_staticTextAn3 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn3->Wrap( -1 );
	gSizer2->Add( m_staticTextAn3, 0, wxALL, 5 );
	
	m_staticText_An3 = new wxStaticText( m_panelADC, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_An3->Wrap( -1 );
	m_staticText_An3->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer2->Add( m_staticText_An3, 0, wxALL, 5 );
	
	m_staticTextAn4 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn4->Wrap( -1 );
	gSizer2->Add( m_staticTextAn4, 0, wxALL, 5 );
	
	m_staticText_An4 = new wxStaticText( m_panelADC, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_An4->Wrap( -1 );
	m_staticText_An4->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer2->Add( m_staticText_An4, 0, wxALL, 5 );
	
	m_staticTextAn5 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn5->Wrap( -1 );
	gSizer2->Add( m_staticTextAn5, 0, wxALL, 5 );
	
	m_staticText_An5 = new wxStaticText( m_panelADC, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_An5->Wrap( -1 );
	m_staticText_An5->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer2->Add( m_staticText_An5, 0, wxALL, 5 );
	
	m_staticTextAn6 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn6->Wrap( -1 );
	gSizer2->Add( m_staticTextAn6, 0, wxALL, 5 );
	
	m_staticText_An6 = new wxStaticText( m_panelADC, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_An6->Wrap( -1 );
	m_staticText_An6->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer2->Add( m_staticText_An6, 0, wxALL, 5 );
	
	m_staticTextAn7 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn7->Wrap( -1 );
	gSizer2->Add( m_staticTextAn7, 0, wxALL, 5 );
	
	m_staticTextA_n7 = new wxStaticText( m_panelADC, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextA_n7->Wrap( -1 );
	m_staticTextA_n7->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer2->Add( m_staticTextA_n7, 0, wxALL, 5 );
	
	m_staticTextAn8 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn8->Wrap( -1 );
	gSizer2->Add( m_staticTextAn8, 0, wxALL, 5 );
	
	m_staticText_An8 = new wxStaticText( m_panelADC, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_An8->Wrap( -1 );
	m_staticText_An8->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer2->Add( m_staticText_An8, 0, wxALL, 5 );
	
	m_staticTextAn9 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn9->Wrap( -1 );
	gSizer2->Add( m_staticTextAn9, 0, wxALL, 5 );
	
	m_staticText_An9 = new wxStaticText( m_panelADC, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_An9->Wrap( -1 );
	m_staticText_An9->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer2->Add( m_staticText_An9, 0, wxALL, 5 );
	
	m_staticTextAn10 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn10->Wrap( -1 );
	gSizer2->Add( m_staticTextAn10, 0, wxALL, 5 );
	
	m_staticText_An10 = new wxStaticText( m_panelADC, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_An10->Wrap( -1 );
	m_staticText_An10->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer2->Add( m_staticText_An10, 0, wxALL, 5 );
	
	m_staticTextAn11 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn11->Wrap( -1 );
	gSizer2->Add( m_staticTextAn11, 0, wxALL, 5 );
	
	m_staticText_An11 = new wxStaticText( m_panelADC, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_An11->Wrap( -1 );
	m_staticText_An11->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer2->Add( m_staticText_An11, 0, wxALL, 5 );
	
	
	bSizer201->Add( gSizer2, 0, 0, 5 );
	
	
	m_panelADC->SetSizer( bSizer201 );
	m_panelADC->Layout();
	bSizer201->Fit( m_panelADC );
	m_notebook2->AddPage( m_panelADC, wxT("АЦП"), false );
	m_panelOsciloscop = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizerOsc;
	bSizerOsc = new wxBoxSizer( wxVERTICAL );
	
	m_scrolledWindow1 = new wxScrolledWindow( m_panelOsciloscop, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow1->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxVERTICAL );
	
	
	m_scrolledWindow1->SetSizer( bSizer171 );
	m_scrolledWindow1->Layout();
	bSizer171->Fit( m_scrolledWindow1 );
	bSizerOsc->Add( m_scrolledWindow1, 1, wxEXPAND|wxBOTTOM, 5 );
	
	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer92;
	bSizer92 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextG1 = new wxStaticText( m_panelOsciloscop, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextG1->Wrap( -1 );
	m_staticTextG1->SetForegroundColour( wxColour( 240, 15, 50 ) );
	
	bSizer92->Add( m_staticTextG1, 0, wxALL, 5 );
	
	
	bSizer91->Add( bSizer92, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer921;
	bSizer921 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextG2 = new wxStaticText( m_panelOsciloscop, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextG2->Wrap( -1 );
	m_staticTextG2->SetForegroundColour( wxColour( 25, 36, 234 ) );
	
	bSizer921->Add( m_staticTextG2, 0, wxALL, 5 );
	
	
	bSizer91->Add( bSizer921, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer922;
	bSizer922 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextG3 = new wxStaticText( m_panelOsciloscop, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextG3->Wrap( -1 );
	m_staticTextG3->SetForegroundColour( wxColour( 20, 171, 25 ) );
	
	bSizer922->Add( m_staticTextG3, 0, wxALL, 5 );
	
	
	bSizer91->Add( bSizer922, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer923;
	bSizer923 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextG4 = new wxStaticText( m_panelOsciloscop, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextG4->Wrap( -1 );
	m_staticTextG4->SetForegroundColour( wxColour( 243, 79, 211 ) );
	
	bSizer923->Add( m_staticTextG4, 0, wxALL, 5 );
	
	
	bSizer91->Add( bSizer923, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer924;
	bSizer924 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextG5 = new wxStaticText( m_panelOsciloscop, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextG5->Wrap( -1 );
	m_staticTextG5->SetForegroundColour( wxColour( 117, 60, 60 ) );
	
	bSizer924->Add( m_staticTextG5, 0, wxALL, 5 );
	
	
	bSizer91->Add( bSizer924, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer925;
	bSizer925 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextG6 = new wxStaticText( m_panelOsciloscop, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextG6->Wrap( -1 );
	m_staticTextG6->SetForegroundColour( wxColour( 235, 109, 11 ) );
	
	bSizer925->Add( m_staticTextG6, 0, wxALL, 5 );
	
	
	bSizer91->Add( bSizer925, 0, wxEXPAND, 5 );
	
	
	bSizerOsc->Add( bSizer91, 0, wxEXPAND, 5 );
	
	
	m_panelOsciloscop->SetSizer( bSizerOsc );
	m_panelOsciloscop->Layout();
	bSizerOsc->Fit( m_panelOsciloscop );
	m_notebook2->AddPage( m_panelOsciloscop, wxT("Осцилограф"), false );
	m_panelTimes = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer3;
	gSizer3 = new wxGridSizer( 0, 2, 0, 30 );
	
	m_staticTextT1 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT1->Wrap( -1 );
	gSizer3->Add( m_staticTextT1, 0, wxALL, 5 );
	
	m_staticText_T1 = new wxStaticText( m_panelTimes, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_T1->Wrap( -1 );
	m_staticText_T1->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer3->Add( m_staticText_T1, 0, wxALL, 5 );
	
	m_staticTextT2 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT2->Wrap( -1 );
	gSizer3->Add( m_staticTextT2, 0, wxALL, 5 );
	
	m_staticText_T2 = new wxStaticText( m_panelTimes, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_T2->Wrap( -1 );
	m_staticText_T2->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer3->Add( m_staticText_T2, 0, wxALL, 5 );
	
	m_staticTextT3 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT3->Wrap( -1 );
	gSizer3->Add( m_staticTextT3, 0, wxALL, 5 );
	
	m_staticText_T3 = new wxStaticText( m_panelTimes, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_T3->Wrap( -1 );
	m_staticText_T3->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer3->Add( m_staticText_T3, 0, wxALL, 5 );
	
	m_staticTextT4 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT4->Wrap( -1 );
	gSizer3->Add( m_staticTextT4, 0, wxALL, 5 );
	
	m_staticText_T4 = new wxStaticText( m_panelTimes, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_T4->Wrap( -1 );
	m_staticText_T4->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer3->Add( m_staticText_T4, 0, wxALL, 5 );
	
	m_staticTextT5 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT5->Wrap( -1 );
	gSizer3->Add( m_staticTextT5, 0, wxALL, 5 );
	
	m_staticText_T5 = new wxStaticText( m_panelTimes, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_T5->Wrap( -1 );
	m_staticText_T5->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer3->Add( m_staticText_T5, 0, wxALL, 5 );
	
	m_staticTextT6 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT6->Wrap( -1 );
	gSizer3->Add( m_staticTextT6, 0, wxALL, 5 );
	
	m_staticText_T6 = new wxStaticText( m_panelTimes, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_T6->Wrap( -1 );
	m_staticText_T6->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer3->Add( m_staticText_T6, 0, wxALL, 5 );
	
	m_staticTextT7 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT7->Wrap( -1 );
	gSizer3->Add( m_staticTextT7, 0, wxALL, 5 );
	
	m_staticText_T7 = new wxStaticText( m_panelTimes, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_T7->Wrap( -1 );
	m_staticText_T7->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer3->Add( m_staticText_T7, 0, wxALL, 5 );
	
	m_staticTextT8 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT8->Wrap( -1 );
	gSizer3->Add( m_staticTextT8, 0, wxALL, 5 );
	
	m_staticText_T8 = new wxStaticText( m_panelTimes, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_T8->Wrap( -1 );
	m_staticText_T8->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer3->Add( m_staticText_T8, 0, wxALL, 5 );
	
	m_staticTextT9 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT9->Wrap( -1 );
	gSizer3->Add( m_staticTextT9, 0, wxALL, 5 );
	
	m_staticText_T9 = new wxStaticText( m_panelTimes, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_T9->Wrap( -1 );
	m_staticText_T9->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer3->Add( m_staticText_T9, 0, wxALL, 5 );
	
	m_staticTextT10 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT10->Wrap( -1 );
	gSizer3->Add( m_staticTextT10, 0, wxALL, 5 );
	
	m_staticText_T10 = new wxStaticText( m_panelTimes, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_T10->Wrap( -1 );
	m_staticText_T10->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer3->Add( m_staticText_T10, 0, wxALL, 5 );
	
	m_staticTextT11 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT11->Wrap( -1 );
	gSizer3->Add( m_staticTextT11, 0, wxALL, 5 );
	
	m_staticText_T11 = new wxStaticText( m_panelTimes, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_T11->Wrap( -1 );
	m_staticText_T11->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer3->Add( m_staticText_T11, 0, wxALL, 5 );
	
	m_staticTextT12 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT12->Wrap( -1 );
	gSizer3->Add( m_staticTextT12, 0, wxALL, 5 );
	
	m_staticText_T12 = new wxStaticText( m_panelTimes, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_T12->Wrap( -1 );
	m_staticText_T12->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer3->Add( m_staticText_T12, 0, wxALL, 5 );
	
	m_staticTextT13 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT13->Wrap( -1 );
	gSizer3->Add( m_staticTextT13, 0, wxALL, 5 );
	
	m_staticText_T13 = new wxStaticText( m_panelTimes, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_T13->Wrap( -1 );
	m_staticText_T13->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer3->Add( m_staticText_T13, 0, wxALL, 5 );
	
	m_staticTextT14 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT14->Wrap( -1 );
	gSizer3->Add( m_staticTextT14, 0, wxALL, 5 );
	
	m_staticText_T14 = new wxStaticText( m_panelTimes, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_T14->Wrap( -1 );
	m_staticText_T14->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer3->Add( m_staticText_T14, 0, wxALL, 5 );
	
	m_staticTextT15 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT15->Wrap( -1 );
	gSizer3->Add( m_staticTextT15, 0, wxALL, 5 );
	
	m_staticText_T15 = new wxStaticText( m_panelTimes, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_T15->Wrap( -1 );
	m_staticText_T15->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer3->Add( m_staticText_T15, 0, wxALL, 5 );
	
	m_staticTextT16 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT16->Wrap( -1 );
	gSizer3->Add( m_staticTextT16, 0, wxALL, 5 );
	
	m_staticText_T16 = new wxStaticText( m_panelTimes, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_T16->Wrap( -1 );
	m_staticText_T16->SetFont( wxFont( 12, 74, 90, 92, false, wxT("Sans") ) );
	
	gSizer3->Add( m_staticText_T16, 0, wxALL, 5 );
	
	
	bSizer33->Add( gSizer3, 0, 0, 5 );
	
	
	m_panelTimes->SetSizer( bSizer33 );
	m_panelTimes->Layout();
	bSizer33->Fit( m_panelTimes );
	m_notebook2->AddPage( m_panelTimes, wxT("Часові параметри"), false );
	m_panelIdentification = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer73;
	bSizer73 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer4;
	gSizer4 = new wxGridSizer( 0, 2, 0, 30 );
	
	m_staticText60 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("Ідентифікатор:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText60->Wrap( -1 );
	gSizer4->Add( m_staticText60, 0, wxALL, 5 );
	
	m_staticTextID1 = new wxStaticText( m_panelIdentification, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextID1->Wrap( -1 );
	gSizer4->Add( m_staticTextID1, 0, wxALL, 5 );
	
	m_staticText61 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("Код запчастин:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	gSizer4->Add( m_staticText61, 0, wxALL, 5 );
	
	m_staticTextID2 = new wxStaticText( m_panelIdentification, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextID2->Wrap( -1 );
	gSizer4->Add( m_staticTextID2, 0, wxALL, 5 );
	
	m_staticText62 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("Код програми ЕБП:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText62->Wrap( -1 );
	gSizer4->Add( m_staticText62, 0, wxALL, 5 );
	
	m_staticTextID3 = new wxStaticText( m_panelIdentification, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextID3->Wrap( -1 );
	gSizer4->Add( m_staticTextID3, 0, wxALL, 5 );
	
	m_staticText63 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("Заводський номер:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText63->Wrap( -1 );
	gSizer4->Add( m_staticText63, 0, wxALL, 5 );
	
	m_staticTextID4 = new wxStaticText( m_panelIdentification, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextID4->Wrap( -1 );
	gSizer4->Add( m_staticTextID4, 0, wxALL, 5 );
	
	m_staticText64 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("Дата прошивки:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText64->Wrap( -1 );
	gSizer4->Add( m_staticText64, 0, wxALL, 5 );
	
	m_staticTextID5 = new wxStaticText( m_panelIdentification, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextID5->Wrap( -1 );
	gSizer4->Add( m_staticTextID5, 0, wxALL, 5 );
	
	m_staticText65 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("Назва системи:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText65->Wrap( -1 );
	gSizer4->Add( m_staticText65, 0, wxALL, 5 );
	
	m_staticTextID6 = new wxStaticText( m_panelIdentification, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextID6->Wrap( -1 );
	gSizer4->Add( m_staticTextID6, 0, wxALL, 5 );
	
	m_staticText66 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("Код ЕБП:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText66->Wrap( -1 );
	gSizer4->Add( m_staticText66, 0, wxALL, 5 );
	
	m_staticTextID7 = new wxStaticText( m_panelIdentification, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextID7->Wrap( -1 );
	gSizer4->Add( m_staticTextID7, 0, wxALL, 5 );
	
	m_staticText67 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("Модель автомобіля:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText67->Wrap( -1 );
	gSizer4->Add( m_staticText67, 0, wxALL, 5 );
	
	m_staticTextID8 = new wxStaticText( m_panelIdentification, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextID8->Wrap( -1 );
	gSizer4->Add( m_staticTextID8, 0, wxALL, 5 );
	
	
	bSizer73->Add( gSizer4, 0, 0, 5 );
	
	
	m_panelIdentification->SetSizer( bSizer73 );
	m_panelIdentification->Layout();
	bSizer73->Fit( m_panelIdentification );
	m_notebook2->AddPage( m_panelIdentification, wxT("Ідентифікація"), false );
	
	bSizer17->Add( m_notebook2, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText111 = new wxStaticText( this, wxID_ANY, wxT("Зміна параметрів"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111->Wrap( -1 );
	bSizer18->Add( m_staticText111, 0, wxALIGN_CENTER_HORIZONTAL|wxTOP|wxRIGHT|wxLEFT, 5 );
	
	m_comboBoxControl = new wxComboBox( this, wxID_ANY, wxT("None"), wxDefaultPosition, wxDefaultSize, 0, NULL, wxCB_READONLY );
	m_comboBoxControl->Append( wxT("None") );
	m_comboBoxControl->Append( wxT("Оберти ХХ (RAW)") );
	m_comboBoxControl->Append( wxT("Баз. паливоподача ХХ (RAW)") );
	m_comboBoxControl->Append( wxT("Баз. паливоподача роб. реж. (RAW)") );
	m_comboBoxControl->Append( wxT("Реле ветилятора") );
	m_comboBoxControl->Append( wxT("Реле кондиціонера") );
	m_comboBoxControl->Append( wxT("Лампа діагностики") );
	m_comboBoxControl->Append( wxT("Паливне реле") );
	m_comboBoxControl->SetSelection( 0 );
	bSizer18->Add( m_comboBoxControl, 0, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Change Value") ), wxVERTICAL );
	
	m_staticControlValue = new wxStaticText( this, wxID_ANY, wxT("Value"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticControlValue->Wrap( -1 );
	m_staticControlValue->SetFont( wxFont( 10, 76, 90, 92, false, wxT("Liberation Mono") ) );
	
	sbSizer2->Add( m_staticControlValue, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_buttonControlPlus = new wxButton( this, wxID_ANY, wxT("+"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonControlPlus->Enable( false );
	
	sbSizer2->Add( m_buttonControlPlus, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_buttonControlMinus = new wxButton( this, wxID_ANY, wxT("-"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonControlMinus->Enable( false );
	
	sbSizer2->Add( m_buttonControlMinus, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	bSizer18->Add( sbSizer2, 0, wxEXPAND, 5 );
	
	
	bSizer17->Add( bSizer18, 0, wxEXPAND|wxTOP, 5 );
	
	
	bSizer15->Add( bSizer17, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Option") ), wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("EBC:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	sbSizer1->Add( m_staticText1, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_comboBoxSelectEBC = new wxComboBox( this, wxID_ANY, wxT("Mikas 10.3"), wxDefaultPosition, wxSize( 165,-1 ), 0, NULL, wxCB_READONLY );
	m_comboBoxSelectEBC->Append( wxT("Auto") );
	m_comboBoxSelectEBC->Append( wxT("M 1.5.4 Januery 5") );
	m_comboBoxSelectEBC->Append( wxT("M 1.5.4 (N) Januery 5.X") );
	m_comboBoxSelectEBC->Append( wxT("Mikas 10.3") );
	m_comboBoxSelectEBC->Append( wxT("Mikas 7.6") );
	m_comboBoxSelectEBC->Append( wxT("Mikas 11 (E2)") );
	m_comboBoxSelectEBC->Append( wxT("Mikas 11 (E3)") );
	m_comboBoxSelectEBC->Append( wxT("M 7.9.7 (E2)") );
	m_comboBoxSelectEBC->Append( wxT("M 7.9.7 (E3)") );
	m_comboBoxSelectEBC->Append( wxT("January 7.X") );
	m_comboBoxSelectEBC->Append( wxT("ME1 7.9.7") );
	m_comboBoxSelectEBC->Append( wxT("MP 7.0 (E2)") );
	m_comboBoxSelectEBC->Append( wxT("MP 7.0 (E3)") );
	m_comboBoxSelectEBC->Append( wxT("Lanos 1.5 SOCH") );
	m_comboBoxSelectEBC->Append( wxT("Lanos 1.6 DOCH") );
	m_comboBoxSelectEBC->SetSelection( 3 );
	sbSizer1->Add( m_comboBoxSelectEBC, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	sbSizer1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Port:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	sbSizer1->Add( m_staticText3, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_comboBoxSelectPort = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 165,-1 ), 0, NULL, 0 ); 
	m_comboBoxSelectPort->SetSelection( 0 );
	sbSizer1->Add( m_comboBoxSelectPort, 0, wxTOP|wxBOTTOM|wxRIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_buttonScanPort = new wxButton( this, wxID_ANY, wxT("Scan"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_buttonScanPort, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	sbSizer1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_checkBoxAdapter = new wxCheckBox( this, wxID_ANY, wxT("Adapter"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBoxAdapter->SetValue(true); 
	sbSizer1->Add( m_checkBoxAdapter, 0, wxALL, 5 );
	
	m_checkBoxLog = new wxCheckBox( this, wxID_ANY, wxT("Log Protocol"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_checkBoxLog, 0, wxALL, 5 );
	
	
	bSizer2->Add( sbSizer1, 1, wxEXPAND|wxBOTTOM|wxRIGHT|wxLEFT, 5 );
	
	m_buttonStart = new wxButton( this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_buttonStart, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	bSizer15->Add( bSizer2, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer15 );
	this->Layout();
	m_timer1.SetOwner( this, wxID_ANY );
	m_timerSystem.SetOwner( this, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyFrameBase::OnClose ) );
	this->Connect( m_menuItemFileStart->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::OnStart ) );
	this->Connect( m_menuItemFileExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::OnExit ) );
	this->Connect( m_menuItemSaveFile->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::OnSaveLog ) );
	this->Connect( m_menuItemHelpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::OnAbout ) );
	m_notebook2->Connect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( MyFrameBase::OnPageChange ), NULL, this );
	m_buttonResetError->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrameBase::OnResetError ), NULL, this );
	m_comboBoxControl->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrameBase::OnComboboxSelectControl ), NULL, this );
	m_buttonControlPlus->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrameBase::OnClickControlPlus ), NULL, this );
	m_buttonControlMinus->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrameBase::OnClickContolMinus ), NULL, this );
	m_comboBoxSelectEBC->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrameBase::OnSelectEBC ), NULL, this );
	m_comboBoxSelectPort->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrameBase::OnSelectPort ), NULL, this );
	m_buttonScanPort->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrameBase::OnScanPort ), NULL, this );
	m_checkBoxAdapter->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameBase::OnCheckAdapter ), NULL, this );
	m_checkBoxLog->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameBase::OnCheckLogProtocol ), NULL, this );
	m_buttonStart->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrameBase::OnStart ), NULL, this );
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( MyFrameBase::OnTimerTick ) );
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( MyFrameBase::OnSysTimerTick ) );
}

MyFrameBase::~MyFrameBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyFrameBase::OnClose ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::OnStart ) );
	this->Disconnect( wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::OnExit ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::OnSaveLog ) );
	this->Disconnect( wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::OnAbout ) );
	m_notebook2->Disconnect( wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, wxNotebookEventHandler( MyFrameBase::OnPageChange ), NULL, this );
	m_buttonResetError->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrameBase::OnResetError ), NULL, this );
	m_comboBoxControl->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrameBase::OnComboboxSelectControl ), NULL, this );
	m_buttonControlPlus->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrameBase::OnClickControlPlus ), NULL, this );
	m_buttonControlMinus->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrameBase::OnClickContolMinus ), NULL, this );
	m_comboBoxSelectEBC->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrameBase::OnSelectEBC ), NULL, this );
	m_comboBoxSelectPort->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrameBase::OnSelectPort ), NULL, this );
	m_buttonScanPort->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrameBase::OnScanPort ), NULL, this );
	m_checkBoxAdapter->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameBase::OnCheckAdapter ), NULL, this );
	m_checkBoxLog->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameBase::OnCheckLogProtocol ), NULL, this );
	m_buttonStart->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrameBase::OnStart ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( MyFrameBase::OnTimerTick ) );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( MyFrameBase::OnSysTimerTick ) );
	
}
