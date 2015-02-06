/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06.02.15 19:54:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vovan (), volodumurkoval0@gmail.com
 *   Organization:  Home
 *
 * =====================================================================================
 */

#include "main.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
	MyFrame *win = new MyFrame(NULL);
	win->Show();
	return TRUE;
}

