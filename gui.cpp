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
	
	m_menuControl = new wxMenu();
	wxMenuItem* m_menuItemConvolution;
	m_menuItemConvolution = new wxMenuItem( m_menuControl, wxID_ANY, wxString( wxT("Convolution XX(RAW)") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuControl->Append( m_menuItemConvolution );
	
	m_menubar->Append( m_menuControl, wxT("Control") ); 
	
	m_menuHelp = new wxMenu();
	wxMenuItem* m_menuItemHelpAbout;
	m_menuItemHelpAbout = new wxMenuItem( m_menuHelp, wxID_ABOUT, wxString( wxT("&About") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuHelp->Append( m_menuItemHelpAbout );
	
	m_menubar->Append( m_menuHelp, wxT("&Help") ); 
	
	this->SetMenuBar( m_menubar );
	
	m_statusBar = this->CreateStatusBar( 4, wxST_SIZEGRIP, wxID_ANY );
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
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
	gSizer1->Add( m_staticText_Dat1, 0, wxALL, 5 );
	
	m_staticTextDat2 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat2->Wrap( -1 );
	gSizer1->Add( m_staticTextDat2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat2 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat2->Wrap( -1 );
	gSizer1->Add( m_staticText_Dat2, 0, wxALL, 5 );
	
	m_staticTextDat3 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat3->Wrap( -1 );
	gSizer1->Add( m_staticTextDat3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat3 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat3->Wrap( -1 );
	gSizer1->Add( m_staticText_Dat3, 0, wxALL, 5 );
	
	m_staticTextDat4 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat4->Wrap( -1 );
	gSizer1->Add( m_staticTextDat4, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat4 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat4->Wrap( -1 );
	gSizer1->Add( m_staticText_Dat4, 0, wxALL, 5 );
	
	m_staticTextDat5 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat5->Wrap( -1 );
	gSizer1->Add( m_staticTextDat5, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat5 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat5->Wrap( -1 );
	gSizer1->Add( m_staticText_Dat5, 0, wxALL, 5 );
	
	m_staticTextDat6 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat6->Wrap( -1 );
	gSizer1->Add( m_staticTextDat6, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat6 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat6->Wrap( -1 );
	gSizer1->Add( m_staticText_Dat6, 0, wxALL, 5 );
	
	m_staticTextDat7 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat7->Wrap( -1 );
	gSizer1->Add( m_staticTextDat7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat7 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat7->Wrap( -1 );
	gSizer1->Add( m_staticText_Dat7, 0, wxALL, 5 );
	
	m_staticTextDat8 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat8->Wrap( -1 );
	gSizer1->Add( m_staticTextDat8, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat8 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat8->Wrap( -1 );
	gSizer1->Add( m_staticText_Dat8, 0, wxALL, 5 );
	
	m_staticTextDat9 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat9->Wrap( -1 );
	gSizer1->Add( m_staticTextDat9, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat9 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat9->Wrap( -1 );
	gSizer1->Add( m_staticText_Dat9, 0, wxALL, 5 );
	
	m_staticTextDat10 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat10->Wrap( -1 );
	gSizer1->Add( m_staticTextDat10, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat10 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat10->Wrap( -1 );
	gSizer1->Add( m_staticText_Dat10, 0, wxALL, 5 );
	
	m_staticTextDat11 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat11->Wrap( -1 );
	gSizer1->Add( m_staticTextDat11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat11 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat11->Wrap( -1 );
	gSizer1->Add( m_staticText_Dat11, 0, wxALL, 5 );
	
	m_staticTextDat12 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat12->Wrap( -1 );
	gSizer1->Add( m_staticTextDat12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat12 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat12->Wrap( -1 );
	gSizer1->Add( m_staticText_Dat12, 0, wxALL, 5 );
	
	m_staticTextDat13 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat13->Wrap( -1 );
	gSizer1->Add( m_staticTextDat13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat13 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat13->Wrap( -1 );
	gSizer1->Add( m_staticText_Dat13, 0, wxALL, 5 );
	
	m_staticTextDat14 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat14->Wrap( -1 );
	gSizer1->Add( m_staticTextDat14, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat14 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat14->Wrap( -1 );
	gSizer1->Add( m_staticText_Dat14, 0, wxALL, 5 );
	
	m_staticTextDat15 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat15->Wrap( -1 );
	gSizer1->Add( m_staticTextDat15, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat15 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat15->Wrap( -1 );
	gSizer1->Add( m_staticText_Dat15, 0, wxALL, 5 );
	
	m_staticTextDat16 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDat16->Wrap( -1 );
	gSizer1->Add( m_staticTextDat16, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText_Dat16 = new wxStaticText( m_panelDiagnostic, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText_Dat16->Wrap( -1 );
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
	
	wxBoxSizer* bSizer221;
	bSizer221 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextAn1 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn1->Wrap( -1 );
	bSizer221->Add( m_staticTextAn1, 0, wxALL, 5 );
	
	
	bSizer201->Add( bSizer221, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer231;
	bSizer231 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextAn2 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn2->Wrap( -1 );
	bSizer231->Add( m_staticTextAn2, 0, wxALL, 5 );
	
	
	bSizer201->Add( bSizer231, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer241;
	bSizer241 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextAn3 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn3->Wrap( -1 );
	bSizer241->Add( m_staticTextAn3, 0, wxALL, 5 );
	
	
	bSizer201->Add( bSizer241, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer251;
	bSizer251 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextAn4 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn4->Wrap( -1 );
	bSizer251->Add( m_staticTextAn4, 0, wxALL, 5 );
	
	
	bSizer201->Add( bSizer251, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextAn5 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn5->Wrap( -1 );
	bSizer26->Add( m_staticTextAn5, 0, wxALL, 5 );
	
	
	bSizer201->Add( bSizer26, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextAn6 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn6->Wrap( -1 );
	bSizer27->Add( m_staticTextAn6, 0, wxALL, 5 );
	
	
	bSizer201->Add( bSizer27, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextAn7 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn7->Wrap( -1 );
	bSizer28->Add( m_staticTextAn7, 0, wxALL, 5 );
	
	
	bSizer201->Add( bSizer28, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextAn8 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn8->Wrap( -1 );
	bSizer29->Add( m_staticTextAn8, 0, wxALL, 5 );
	
	
	bSizer201->Add( bSizer29, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextAn9 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn9->Wrap( -1 );
	bSizer30->Add( m_staticTextAn9, 0, wxALL, 5 );
	
	
	bSizer201->Add( bSizer30, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextAn10 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn10->Wrap( -1 );
	bSizer31->Add( m_staticTextAn10, 0, wxALL, 5 );
	
	
	bSizer201->Add( bSizer31, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextAn11 = new wxStaticText( m_panelADC, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextAn11->Wrap( -1 );
	bSizer32->Add( m_staticTextAn11, 0, wxALL, 5 );
	
	
	bSizer201->Add( bSizer32, 0, wxEXPAND, 5 );
	
	
	m_panelADC->SetSizer( bSizer201 );
	m_panelADC->Layout();
	bSizer201->Fit( m_panelADC );
	m_notebook2->AddPage( m_panelADC, wxT("АЦП"), false );
	m_panelOsciloscop = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
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
	
	
	m_panelOsciloscop->SetSizer( bSizer91 );
	m_panelOsciloscop->Layout();
	bSizer91->Fit( m_panelOsciloscop );
	m_notebook2->AddPage( m_panelOsciloscop, wxT("Осцилограф"), false );
	m_panelTimes = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextT1 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT1->Wrap( -1 );
	bSizer34->Add( m_staticTextT1, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer34, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer341;
	bSizer341 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextT2 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT2->Wrap( -1 );
	bSizer341->Add( m_staticTextT2, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer341, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer342;
	bSizer342 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextT3 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT3->Wrap( -1 );
	bSizer342->Add( m_staticTextT3, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer342, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer343;
	bSizer343 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextT4 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT4->Wrap( -1 );
	bSizer343->Add( m_staticTextT4, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer343, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer344;
	bSizer344 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextT5 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT5->Wrap( -1 );
	bSizer344->Add( m_staticTextT5, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer344, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer345;
	bSizer345 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextT6 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT6->Wrap( -1 );
	bSizer345->Add( m_staticTextT6, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer345, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer346;
	bSizer346 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextT7 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT7->Wrap( -1 );
	bSizer346->Add( m_staticTextT7, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer346, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer347;
	bSizer347 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextT8 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT8->Wrap( -1 );
	bSizer347->Add( m_staticTextT8, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer347, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer348;
	bSizer348 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextT9 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT9->Wrap( -1 );
	bSizer348->Add( m_staticTextT9, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer348, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer349;
	bSizer349 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextT10 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT10->Wrap( -1 );
	bSizer349->Add( m_staticTextT10, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer349, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3410;
	bSizer3410 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextT11 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT11->Wrap( -1 );
	bSizer3410->Add( m_staticTextT11, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer3410, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3411;
	bSizer3411 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextT12 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT12->Wrap( -1 );
	bSizer3411->Add( m_staticTextT12, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer3411, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3412;
	bSizer3412 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextT13 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT13->Wrap( -1 );
	bSizer3412->Add( m_staticTextT13, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer3412, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3413;
	bSizer3413 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextT14 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT14->Wrap( -1 );
	bSizer3413->Add( m_staticTextT14, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer3413, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3414;
	bSizer3414 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextT15 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT15->Wrap( -1 );
	bSizer3414->Add( m_staticTextT15, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer3414, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3415;
	bSizer3415 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticTextT16 = new wxStaticText( m_panelTimes, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextT16->Wrap( -1 );
	bSizer3415->Add( m_staticTextT16, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer3415, 0, wxEXPAND, 5 );
	
	
	m_panelTimes->SetSizer( bSizer33 );
	m_panelTimes->Layout();
	bSizer33->Fit( m_panelTimes );
	m_notebook2->AddPage( m_panelTimes, wxT("Часові параметри"), false );
	m_panelIdentification = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer73;
	bSizer73 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer74;
	bSizer74 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText60 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("Ідентифікатор:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText60->Wrap( -1 );
	bSizer74->Add( m_staticText60, 0, wxALL, 5 );
	
	
	bSizer74->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextID1 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextID1->Wrap( -1 );
	bSizer74->Add( m_staticTextID1, 0, wxALL, 5 );
	
	
	bSizer73->Add( bSizer74, 0, 0, 5 );
	
	wxBoxSizer* bSizer741;
	bSizer741 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText61 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("Код запчастин:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	bSizer741->Add( m_staticText61, 0, wxALL, 5 );
	
	
	bSizer741->Add( 0, 0, 0, wxEXPAND, 5 );
	
	m_staticTextID2 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextID2->Wrap( -1 );
	bSizer741->Add( m_staticTextID2, 0, wxALL, 5 );
	
	
	bSizer73->Add( bSizer741, 0, 0, 5 );
	
	wxBoxSizer* bSizer742;
	bSizer742 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText62 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("Код програми ЕБП:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText62->Wrap( -1 );
	bSizer742->Add( m_staticText62, 0, wxALL, 5 );
	
	
	bSizer742->Add( 0, 0, 0, 0, 5 );
	
	m_staticTextID3 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextID3->Wrap( -1 );
	bSizer742->Add( m_staticTextID3, 0, wxALL, 5 );
	
	
	bSizer73->Add( bSizer742, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer743;
	bSizer743 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText63 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("Заводський номер:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText63->Wrap( -1 );
	bSizer743->Add( m_staticText63, 0, wxALL, 5 );
	
	
	bSizer743->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextID4 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextID4->Wrap( -1 );
	bSizer743->Add( m_staticTextID4, 0, wxALL, 5 );
	
	
	bSizer73->Add( bSizer743, 0, 0, 5 );
	
	wxBoxSizer* bSizer744;
	bSizer744 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText64 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("Дата прошивки:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText64->Wrap( -1 );
	bSizer744->Add( m_staticText64, 0, wxALL, 5 );
	
	
	bSizer744->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextID5 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextID5->Wrap( -1 );
	bSizer744->Add( m_staticTextID5, 0, wxALL, 5 );
	
	
	bSizer73->Add( bSizer744, 0, 0, 5 );
	
	wxBoxSizer* bSizer745;
	bSizer745 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText65 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("Назва системи:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText65->Wrap( -1 );
	bSizer745->Add( m_staticText65, 0, wxALL, 5 );
	
	
	bSizer745->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextID6 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextID6->Wrap( -1 );
	bSizer745->Add( m_staticTextID6, 0, wxALL, 5 );
	
	
	bSizer73->Add( bSizer745, 0, 0, 5 );
	
	wxBoxSizer* bSizer746;
	bSizer746 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText66 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("Код ЕБП:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText66->Wrap( -1 );
	bSizer746->Add( m_staticText66, 0, wxALL, 5 );
	
	
	bSizer746->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextID7 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextID7->Wrap( -1 );
	bSizer746->Add( m_staticTextID7, 0, wxALL, 5 );
	
	
	bSizer73->Add( bSizer746, 0, 0, 5 );
	
	wxBoxSizer* bSizer747;
	bSizer747 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText67 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("Модель автомобіля:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText67->Wrap( -1 );
	bSizer747->Add( m_staticText67, 0, wxALL, 5 );
	
	
	bSizer747->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticTextID8 = new wxStaticText( m_panelIdentification, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextID8->Wrap( -1 );
	bSizer747->Add( m_staticTextID8, 0, wxALL, 5 );
	
	
	bSizer73->Add( bSizer747, 0, 0, 5 );
	
	
	m_panelIdentification->SetSizer( bSizer73 );
	m_panelIdentification->Layout();
	bSizer73->Fit( m_panelIdentification );
	m_notebook2->AddPage( m_panelIdentification, wxT("Ідентифікація"), false );
	
	bSizer15->Add( m_notebook2, 1, wxALL|wxEXPAND, 5 );
	
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
	sbSizer1->Add( m_comboBoxSelectEBC, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	sbSizer1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Port:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	sbSizer1->Add( m_staticText3, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_comboBoxSelectPort = new wxComboBox( this, wxID_ANY, wxT("/dev/ttyS0"), wxDefaultPosition, wxSize( 165,-1 ), 0, NULL, 0 );
	m_comboBoxSelectPort->Append( wxT("/dev/ttyS0") );
	m_comboBoxSelectPort->Append( wxT("/dev/ttyUSB0") );
	m_comboBoxSelectPort->Append( wxT("/dev/ttyUSB1") );
	m_comboBoxSelectPort->SetSelection( 0 );
	sbSizer1->Add( m_comboBoxSelectPort, 0, wxTOP|wxBOTTOM|wxRIGHT, 5 );
	
	
	sbSizer1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_checkBoxAdapter = new wxCheckBox( this, wxID_ANY, wxT("Adapter"), wxDefaultPosition, wxDefaultSize, 0 );
	m_checkBoxAdapter->SetValue(true); 
	sbSizer1->Add( m_checkBoxAdapter, 0, wxALL, 5 );
	
	m_checkBoxLog = new wxCheckBox( this, wxID_ANY, wxT("Log Protocol"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_checkBoxLog, 0, wxALL, 5 );
	
	
	bSizer2->Add( sbSizer1, 1, wxEXPAND|wxBOTTOM|wxRIGHT, 5 );
	
	m_buttonStart = new wxButton( this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_buttonStart, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	bSizer15->Add( bSizer2, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer15 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyFrameBase::OnClose ) );
	this->Connect( m_menuItemFileStart->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::OnStart ) );
	this->Connect( m_menuItemFileExit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::OnExit ) );
	this->Connect( m_menuItemHelpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::OnAbout ) );
	m_buttonResetError->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrameBase::OnResetError ), NULL, this );
	m_comboBoxSelectEBC->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrameBase::OnSelectEBC ), NULL, this );
	m_comboBoxSelectPort->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrameBase::OnSelectPort ), NULL, this );
	m_checkBoxAdapter->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameBase::OnCheckAdapter ), NULL, this );
	m_checkBoxLog->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameBase::OnCheckLogProtocol ), NULL, this );
	m_buttonStart->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrameBase::OnStart ), NULL, this );
}

MyFrameBase::~MyFrameBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyFrameBase::OnClose ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::OnStart ) );
	this->Disconnect( wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::OnExit ) );
	this->Disconnect( wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrameBase::OnAbout ) );
	m_buttonResetError->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrameBase::OnResetError ), NULL, this );
	m_comboBoxSelectEBC->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrameBase::OnSelectEBC ), NULL, this );
	m_comboBoxSelectPort->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( MyFrameBase::OnSelectPort ), NULL, this );
	m_checkBoxAdapter->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameBase::OnCheckAdapter ), NULL, this );
	m_checkBoxLog->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrameBase::OnCheckLogProtocol ), NULL, this );
	m_buttonStart->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrameBase::OnStart ), NULL, this );
	
}
