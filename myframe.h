#ifndef __myframe__
#define __myframe__

/**
@file
Subclass of MyFrameBase, which is generated by wxFormBuilder.
*/

#include "gui.h"

//// end generated include
#include <wx/msgdlg.h>
#include "myport.h"

#define SOURCE_ADDRESS								0xF1
#define DESTINATION_ADDRESS							0x10

/** Implementing MyFrameBase */
class MyFrame : public MyFrameBase
{
	protected:
		// Handlers for MyFrameBase events.
		void OnClose( wxCloseEvent& event );
		void OnStart( wxCommandEvent& event );
		void OnExit( wxCommandEvent& event );
		void OnSaveLog( wxCommandEvent& event );
		void OnClearLog( wxCommandEvent& event );
		void OnAbout( wxCommandEvent& event );
		void OnPageChange( wxNotebookEvent& event );
		void OnResetError( wxCommandEvent& event );
		void OnComboboxSelectControl( wxCommandEvent& event );
		void OnClickControlPlus( wxCommandEvent& event );
		void OnClickContolMinus( wxCommandEvent& event );
		void OnSelectEBC( wxCommandEvent& event );
		void OnSelectPort( wxCommandEvent& event );
		void OnScanPort( wxCommandEvent& event );
		void OnCheckAdapter( wxCommandEvent& event );
		void OnCheckLogProtocol( wxCommandEvent& event );
		void OnTimerTick( wxTimerEvent& event );
	public:
		/** Constructor */
		MyFrame( wxWindow* parent );
	//// end generated class members
		void LoadEBC(void);
		void SaveSetting(void);
		void ScanPort(void);
		void DataShow(void);
		void TimerShow(void);
		void AnalogShow(void);
		int carType;
		int panelNom;
		int adapter;
		int ioPort;
		wxString paramName[16][31];
		int paramAddr[16][31][2];
		double data[17];
		double paramCoef[16][31][5];
		int dataSet[16][17];
		int dataGraph[17];
		int flags[16][3];
		wxString timerName[16][31];
		int timerAddr[16][31][2];
		double timerCoef[16][31][5];
		wxString analogName[16][31];
		int analogAddr[16][31][2];
		double analogCoef[16][31][5];
		double timer[17];
		double analog[17];
		char* datBuf;
		MyPort serialPort;
		int timerPeriod;
		int sysTimerPeriod;
		char* outData;
		char* inData;
		int inDataCount;
		int outDataCount;
		int dataOkCount;
		bool dataOk;
		int uprVar;
		bool uprZap;
		int uprData;
		bool uprSend;
		bool resetError;
		int idZapros;
		bool uprClose;
		wxString inStr;
		bool init;
		wxTextFile* logFile;

};

#endif // __myframe__
