#ifndef  SEARCHPORT_H_
#define  SEARCHPORT_H_

#include <wx/wx.h>
#include <wx/dir.h>
#include <wx/textfile.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <err.h>
#include <sys/ioctl.h>
#include <linux/serial.h>

#include <list>

class MyPort
{
	public:
		MyPort();
		wxArrayString GetComList();
		int Open(wxString& name, int rate);
		void Close(){ close(fd); fd = 0;}
		int Write(void* buf, int m_size);
		int Read(void* buf, int nbytes);
		int BytesToRead();
		bool IsOpen();
		int ReadByte();
	private:
		void ProbeSerialPort(wxArrayString& comList, wxArrayString& comList8250);
		/* int rate_to_constant(int baudrate);  */
		wxString GetDriver(const wxString& tty);
		void RegisterComPort(wxArrayString& comList, wxArrayString& comList8250, const wxString& dir);
		int fd;
};

#endif   /* ----- #ifndef SEARCHPORT_H_  ----- */
