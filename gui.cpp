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
	m_menuStart = new wxMenu();
	m_menubar->Append( m_menuStart, _("Start") ); 
	
	m_menuOption = new wxMenu();
	m_menuTypeEBC = new wxMenu();
	wxMenuItem* m_menuTypeEBCItem = new wxMenuItem( m_menuOption, wxID_ANY, _("Type EBC"), wxEmptyString, wxITEM_NORMAL, m_menuTypeEBC );
	m_menuOption->Append( m_menuTypeEBCItem );
	
	m_menuSerialPort = new wxMenu();
	wxMenuItem* m_menuSerialPortItem = new wxMenuItem( m_menuOption, wxID_ANY, _("Serial Port"), wxEmptyString, wxITEM_NORMAL, m_menuSerialPort );
	m_menuOption->Append( m_menuSerialPortItem );
	
	wxMenuItem* m_menuItemAdapter;
	m_menuItemAdapter = new wxMenuItem( m_menuOption, wxID_ANY, wxString( _("Adapter") ) , wxEmptyString, wxITEM_CHECK );
	m_menuOption->Append( m_menuItemAdapter );
	
	wxMenuItem* m_menuItemLogProtocols;
	m_menuItemLogProtocols = new wxMenuItem( m_menuOption, wxID_ANY, wxString( _("Log Protocol's") ) , wxEmptyString, wxITEM_CHECK );
	m_menuOption->Append( m_menuItemLogProtocols );
	
	m_menubar->Append( m_menuOption, _("Option") ); 
	
	m_menuLog = new wxMenu();
	wxMenuItem* m_menuItemSaveFile;
	m_menuItemSaveFile = new wxMenuItem( m_menuLog, wxID_ANY, wxString( _("Save file") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuLog->Append( m_menuItemSaveFile );
	
	m_menubar->Append( m_menuLog, _("Log") ); 
	
	m_menuControl = new wxMenu();
	wxMenuItem* m_menuItemConvolution;
	m_menuItemConvolution = new wxMenuItem( m_menuControl, wxID_ANY, wxString( _("Convolution XX(RAW)") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuControl->Append( m_menuItemConvolution );
	
	wxMenuItem* m_menuItem11;
	m_menuItem11 = new wxMenuItem( m_menuControl, wxID_ANY, wxString( _("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuControl->Append( m_menuItem11 );
	
	wxMenuItem* m_menuItem12;
	m_menuItem12 = new wxMenuItem( m_menuControl, wxID_ANY, wxString( _("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuControl->Append( m_menuItem12 );
	
	wxMenuItem* m_menuItem13;
	m_menuItem13 = new wxMenuItem( m_menuControl, wxID_ANY, wxString( _("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuControl->Append( m_menuItem13 );
	
	wxMenuItem* m_menuItem14;
	m_menuItem14 = new wxMenuItem( m_menuControl, wxID_ANY, wxString( _("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuControl->Append( m_menuItem14 );
	
	wxMenuItem* m_menuItem15;
	m_menuItem15 = new wxMenuItem( m_menuControl, wxID_ANY, wxString( _("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuControl->Append( m_menuItem15 );
	
	wxMenuItem* m_menuItem16;
	m_menuItem16 = new wxMenuItem( m_menuControl, wxID_ANY, wxString( _("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuControl->Append( m_menuItem16 );
	
	m_menubar->Append( m_menuControl, _("Control") ); 
	
	this->SetMenuBar( m_menubar );
	
	m_statusBar = this->CreateStatusBar( 4, wxST_SIZEGRIP, wxID_ANY );
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook2 = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panelDiagnostic = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_notebook2->AddPage( m_panelDiagnostic, _("Diagnostic"), true );
	m_panelErrors = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_notebook2->AddPage( m_panelErrors, _("Errors"), false );
	m_panelADC = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_notebook2->AddPage( m_panelADC, _("ADC"), false );
	m_panelOsciloscop = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_notebook2->AddPage( m_panelOsciloscop, _("Osciloscop"), false );
	m_panelTimes = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_notebook2->AddPage( m_panelTimes, _("Times"), false );
	m_panelIdentification = new wxPanel( m_notebook2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_notebook2->AddPage( m_panelIdentification, _("Identification"), false );
	
	bSizer15->Add( m_notebook2, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( bSizer15 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

MyFrameBase::~MyFrameBase()
{
}
