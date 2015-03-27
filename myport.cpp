/*
 * =====================================================================================
 *
 *       Filename:  searchport.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  20.02.15 21:09:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vovan (), volodumurkoval0@gmail.com
 *   Organization:  Home
 *
 * =====================================================================================
 */

#include "myport.h"

MyPort::MyPort()
{
	fd = 0;
}

int rate_to_constant(int baudrate) {
#define B(x) case x: return B##x
        switch(baudrate) {
        B(50);     B(75);     B(110);    B(134);    B(150);
        B(200);    B(300);    B(600);    B(1200);   B(1800);
        B(2400);   B(4800);   B(9600);   B(19200);  B(38400);
        B(57600);  B(115200); B(230400); B(460800); B(500000);
        B(576000); B(921600); B(1000000);B(1152000);B(1500000);
    default: return 0;
    }
#undef B
}


wxString MyPort::GetDriver(const wxString& tty)
{
	struct stat st;
	wxString deviceDir = tty;
	//Append '/device' to the tty-path
	deviceDir += wxT("/device");
	if( lstat(deviceDir.c_str(), &st) == 0 && S_ISLNK(st.st_mode) )
	{
		char buffer[1024];
		memset(buffer, 0, sizeof(buffer));
		deviceDir += "/driver";
		if( readlink(deviceDir.c_str(), buffer, sizeof(buffer)) > 0 )
		{
			return basename(buffer);
		}
	}
	return "";
}

void MyPort::RegisterComPort(wxArrayString& comList, wxArrayString& comList8250, const wxString& dir)
{
	wxString driver = GetDriver(dir);
	if( driver.size() > 0 )
	{
		wxString devFile = wxString("/dev/") + basename(dir.c_str());
		if(driver == "serial8250")
			comList8250.Add(devFile);
		else
			comList.Add(devFile);
	}
}

wxArrayString MyPort::GetComList()
{
	int n;
	struct dirent **nameList;
	wxArrayString comList;
	wxArrayString comList8250;
	const char* sysDir = "/sys/class/tty/";

	n = scandir(sysDir, &nameList, NULL, NULL);
	while( n-- )
	{
		if( strcmp(nameList[n]->d_name, "..") && strcmp(nameList[n]->d_name, ".") )
		{
			wxString deviceDir = sysDir;
			deviceDir += nameList[n]->d_name;
			RegisterComPort(comList, comList8250, deviceDir);
		}
		free(nameList[n]);
	}
	free(nameList);
	ProbeSerialPort(comList, comList8250);
	return comList;
}

void MyPort::ProbeSerialPort(wxArrayString& comList, wxArrayString& comList8250)
{
	struct serial_struct serinfo;
	for( size_t i = 0 ; i < comList8250.GetCount() ; i++ )
	{
		int fd = open(comList8250.Item(i), O_RDWR | O_NONBLOCK | O_NOCTTY );
		if( fd >= 0 )
		{
			if(ioctl(fd, TIOCGSERIAL, &serinfo) == 0)
			{
				if( serinfo.type != PORT_UNKNOWN )
				{
					comList.Add(comList8250.Item(i));
				}
			}
			close(fd);
		}
	}
	
}

int MyPort::Open(wxString& name, int rate)
{
    struct termios options;
    struct serial_struct serinfo;
    // int fd;
    int speed = 0;
    // int rate = 10400;
    /* Open and configure serial port */
    if ((fd = open(name,O_RDWR|O_NOCTTY)) == -1)
    {
        return -1;
    }

    // if you've entered a standard baud the function below will return it
    speed = rate_to_constant(rate);

    if (speed == 0) 
	{
        /* Custom divisor */
        serinfo.reserved_char[0] = 0;
        if (ioctl(fd, TIOCGSERIAL, &serinfo) < 0)
            return -1;
        serinfo.flags &= ~ASYNC_SPD_MASK;
        serinfo.flags |= ASYNC_SPD_CUST;
        serinfo.custom_divisor = (serinfo.baud_base + (rate / 2)) / rate;
        if (serinfo.custom_divisor < 1)
            serinfo.custom_divisor = 1;
        if (ioctl(fd, TIOCSSERIAL, &serinfo) < 0)
            return -1;
        // if (ioctl(fd, TIOCGSERIAL, &serinfo) < 0)
        //     return -1;
        if (serinfo.custom_divisor * rate != serinfo.baud_base) 
		{
            warnx("actual baudrate is %d / %d = %f",
                  serinfo.baud_base, serinfo.custom_divisor,
                  (float)serinfo.baud_base / serinfo.custom_divisor);
        }
    }

    fcntl(fd, F_SETFL, 0);
    tcgetattr(fd, &options);
    cfsetispeed(&options, speed ?: B38400);
    cfsetospeed(&options, speed ?: B38400);
    cfmakeraw(&options);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~CRTSCTS;
    if (tcsetattr(fd, TCSANOW, &options) != 0)
    {
        return -1;
    }
    return TRUE;
}

int MyPort::Write(void* buf, int m_size)
{
	int n = write(fd, buf, m_size);
	return n;
}

int MyPort::Read(void* buf, int nbytes)
{
	int n = read(fd, buf, nbytes);
	return n;
}

/* --------------------------------------------------------------------------*/
/**
 * @brief Number bytes to read.
 *
 * @return  number bytes to read.
 */
/* ----------------------------------------------------------------------------*/
int MyPort::BytesToRead()
{
	int n;
	ioctl(fd, FIONREAD, &n);
	return n;
}

bool MyPort::IsOpen()
{
	if(fd > 0)
		return TRUE;
	else return FALSE;
}

/* --------------------------------------------------------------------------*/
/**
 * @brief Read byte from RX bufer
 *
 * @return 
 */
/* ----------------------------------------------------------------------------*/
int MyPort::ReadByte()
{
	int b;
	int n;
	n = read(fd, &b, 1);
	if(n > 0)
		return b;
	else return 0;
}

