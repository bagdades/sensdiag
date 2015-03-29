#include "myframe.h"

MyFrame::MyFrame( wxWindow* parent )
	:
		MyFrameBase( parent )
{
	SetIcon(wxIcon(wxT("config.ico")));
	wxDateTime now = wxDateTime::Now();
	now.SetCountry(wxDateTime::UK);
	wxString date;
	date = now.Format(wxT("%X"));
	m_statusBar->SetStatusText(date,3);
	for( int i = 0 ; i < 16 ; i++ )
	{
		for( int j = 0 ; j < 31 ; j++ )
		{
			paramCoef[i][j][0] = 0;
			paramCoef[i][j][1] = 1;
			paramCoef[i][j][2] = 1;
			paramCoef[i][j][3] = 0;
			paramCoef[i][j][4] = 0;
			timerCoef[i][j][0] = 0;
			timerCoef[i][j][1] = 1;
			timerCoef[i][j][2] = 1;
			timerCoef[i][j][3] = 0;
			timerCoef[i][j][4] = 0;
			analogCoef[i][j][0] = 0;
			analogCoef[i][j][1] = 1;
			analogCoef[i][j][2] = 1;
			analogCoef[i][j][3] = 0;
			analogCoef[i][j][4] = 3;
			paramName[i][j] = wxT("");
			paramAddr[i][j][0] = 0;
			paramAddr[i][j][1] = 0;
			timerName[i][j] = wxT("");
			timerAddr[i][j][0] = 0;
			timerAddr[i][j][1] = 0;
			analogName[i][j] = wxT("");
			analogAddr[i][j][0] = 0;
			analogAddr[i][j][1] = 0;
			if(j < 17) { dataSet[i][j] = 0;}
		}
		flags[i][0] = 0;
		flags[i][1] = 0;
		flags[i][2] = 0;
	}
	for( int i = 0 ; i < 17 ; i++ )
	{
		data[i] = 0;
		timer[i] = 0;
		analog[i] = 0;
	}
	//---------- M1.5.4 (17)-----------------------------------------------------------
	paramName[1][1] = wxT("Температура ОР (°C)");
	paramName[1][2] = wxT("Коеф.кор.СО"); paramCoef[1][2][4] = 2;
	paramName[1][3] = wxT("Положення ДЗ (%)"); paramCoef[1][3][4] = 1;
	paramName[1][4] = wxT("Оберти (об/хв)");
	paramName[1][5] = wxT("Оберти ХХ (об/хв)");
	paramName[1][6] = wxT("Бажане полож. РХХ");
	paramName[1][7] = wxT("Поточне полож. РХХ");
	paramName[1][8] = wxT("Корекція впорскування"); paramCoef[1][8][4] = 2;
	paramName[1][9] = wxT("УОЗ (°пкв)"); paramCoef[1][9][4] = 1;
	paramName[1][10] = wxT("Швидкість (км/год)");
	paramName[1][11] = wxT("Напруга БС (В)"); paramCoef[1][11][4] = 1;
	paramName[1][12] = wxT("Бажані обер.ХХ(об/хв)");
	paramName[1][13] = wxT("Паливоподача (мс)"); paramCoef[1][13][4] = 2;
	paramName[1][14] = wxT("Розхід повітря (кг/год)"); paramCoef[1][14][4] = 2;
	paramName[1][15] = wxT("Цикл.розх.пов..(мг/год)"); paramCoef[1][15][4] = 2;
	paramName[1][16] = wxT("Годинний розхід (л/год)"); paramCoef[1][16][4] = 2;
	paramName[1][17] = wxT("Шляховий розхід (л/100км)"); paramCoef[1][17][4] = 2;
	paramAddr[1][0][0] = 17;
	paramAddr[1][0][1] = 38;
	paramAddr[1][1][0] = 9; paramAddr[1][1][1] = 9;
	paramAddr[1][2][0] = 10; paramAddr[1][2][1] = 10;
	paramAddr[1][3][0] = 11; paramAddr[1][3][1] = 11;
	paramAddr[1][4][0] = 12; paramAddr[1][4][1] = 12;
	paramAddr[1][5][0] = 13; paramAddr[1][5][1] = 13;
	paramAddr[1][6][0] = 14; paramAddr[1][6][1] = 14;
	paramAddr[1][7][0] = 15; paramAddr[1][7][1] = 15;
	paramAddr[1][8][0] = 16; paramAddr[1][8][1] = 16;
	paramAddr[1][9][0] = 17; paramAddr[1][9][1] = 17;
	paramAddr[1][10][0] = 18; paramAddr[1][10][1] = 18;
	paramAddr[1][11][0] = 19; paramAddr[1][11][1] = 19;
	paramAddr[1][12][0] = 20; paramAddr[1][12][1] = 20;
	paramAddr[1][13][0] = 21; paramAddr[1][13][1] = 22;
	paramAddr[1][14][0] = 23; paramAddr[1][14][1] = 24;
	paramAddr[1][15][0] = 25; paramAddr[1][15][1] = 26;
	paramAddr[1][16][0] = 27; paramAddr[1][16][1] = 28;
	paramAddr[1][17][0] = 29; paramAddr[1][17][1] = 30;
	paramCoef[1][1][3] = -40;
	paramCoef[1][2][0] = -128; paramCoef[1][2][2] = 256; paramCoef[1][2][3] = -0.5;
	paramCoef[1][4][1] = 40;
	paramCoef[1][5][1] = 10;
	paramCoef[1][8][0] = 128; paramCoef[1][8][2] = 256;
	paramCoef[1][9][2] = 2;
	paramCoef[1][11][2] = 20; paramCoef[1][11][3] = 5.2;
	paramCoef[1][12][1] = 10;
	paramCoef[1][13][2] = 125;
	paramCoef[1][14][2] = 10;
	paramCoef[1][15][2] = 6;
	paramCoef[1][16][2] = 50;
	paramCoef[1][17][2] = 128;
	analogName[1][1] = wxT("Датчик детонації");
	analogName[1][2] = wxT("Температура ОР");
	analogName[1][3] = wxT("Датчик розх.пов.");
	analogName[1][4] = wxT("Напруга БС");
	analogName[1][5] = wxT("Потенціометер СО");
	analogName[1][6] = wxT("Положення ДЗ");
	analogAddr[1][0][0] = 6;
	analogAddr[1][1][0] = 1; analogAddr[1][1][1] = 1;
	analogAddr[1][2][0] = 2; analogAddr[1][2][1] = 2;
	analogAddr[1][3][0] = 3; analogAddr[1][3][1] = 3;
	analogAddr[1][4][0] = 4; analogAddr[1][4][1] = 4;
	analogAddr[1][5][0] = 5; analogAddr[1][5][1] = 5;
	analogAddr[1][6][0] = 6; analogAddr[1][6][1] = 6;
	analogCoef[1][1][1] = 5; analogCoef[1][1][2] = 256;
	analogCoef[1][2][1] = 5; analogCoef[1][2][2] = 256;
	analogCoef[1][3][1] = 5; analogCoef[1][3][2] = 256;
	analogCoef[1][4][1] = 5 * 0.287; analogCoef[1][4][2] = 256;
	analogCoef[1][5][1] = 5; analogCoef[1][5][2] = 256;
	analogCoef[1][6][1] = 5; analogCoef[1][6][2] = 256;

	flags[1][0] = 5; flags[1][1] = 8; flags[1][2] = 255;
	//---------- M1.5.4(N) (18)-----------------------------------------------------------
	for (int i = 1; i < 13; i++)
	{
		paramName[2][i] = paramName[1][i];
		paramCoef[2][i][0] = paramCoef[1][i][0];
		paramCoef[2][i][1] = paramCoef[1][i][1];
		paramCoef[2][i][2] = paramCoef[1][i][2];
		paramCoef[2][i][3] = paramCoef[1][i][3];
		paramCoef[2][i][4] = paramCoef[1][i][4];
	}
	paramName[2][2] = wxT("Повітря/пальне");
	paramName[2][13] = wxT("Напруга ДК (В)");
	for (int i = 13; i < 18; i++)
	{
		paramName[2][i + 1] = paramName[1][i];
		paramCoef[2][i + 1][0] = paramCoef[1][i][0];
		paramCoef[2][i + 1][1] = paramCoef[1][i][1];
		paramCoef[2][i + 1][2] = paramCoef[1][i][2];
		paramCoef[2][i + 1][3] = paramCoef[1][i][3];
		paramCoef[2][i + 1][4] = paramCoef[1][i][4];
	}
	paramAddr[2][0][0] = 18;
	paramAddr[2][0][1] = 40;
	analogAddr[2][0][0] = 6;
	for (int i = 1; i < 18; i++)
	{
		analogName[2][i] = analogName[1][i];
		analogAddr[2][i][0] = analogAddr[1][i][0];
		analogAddr[2][i][1] = analogAddr[1][i][1];
		analogCoef[2][i][1] = analogCoef[1][i][1];
		analogCoef[2][i][2] = analogCoef[1][i][2];
		paramAddr[2][i][0] = paramAddr[1][i][0];
		paramAddr[2][i][1] = paramAddr[1][i][1];
	}
	analogName[2][5] = wxT("Датчик кисню");
	paramCoef[2][13][4] = 2;
	paramAddr[2][13][1] = paramAddr[2][13][0];
	paramAddr[2][18][1] = 34; paramAddr[2][18][0] = 33;
	paramCoef[2][2][0] = 128; paramCoef[2][2][1] = 14.7; paramCoef[2][2][2] = 256;
	paramCoef[2][13][1] = 1.25; paramCoef[2][13][2] = 256;
	flags[2][0] = 5; flags[2][1] = 8; flags[2][2] = 255;

	//---------- Микас 10.3 (28)-----------------------------------------------------------
	paramName[3][1] = wxT("Оберти (об/хв)");
	paramName[3][2] = wxT("Положення ДЗ (%)"); paramCoef[3][2][4] = 1;
	paramName[3][3] = wxT("УОЗ (°пкв)"); paramCoef[3][3][4] = 1;
	paramName[3][4] = wxT("Паливоподача (мс)"); paramCoef[3][4][4] = 2;
	paramName[3][5] = wxT("Тиск кол.(мм.рт.ст.)");
	paramName[3][6] = wxT("Напруга БС (В)"); paramCoef[3][6][4] = 1;
	paramName[3][7] = wxT("Напруга ДК (В)"); paramCoef[3][7][4] = 2;
	paramName[3][8] = wxT("Коеф. L-регулятора"); paramCoef[3][8][4] = 2;
	paramName[3][9] = wxT("Температура ОР (°C)");
	paramName[3][10] = wxT("Температура АТМ (°C)");
	paramName[3][11] = wxT("Похідн. по оберотам");
	paramName[3][12] = wxT("Дин. добавка до пал."); paramCoef[3][12][4] = 2;
	paramName[3][13] = wxT("Положення РХХ");
	paramName[3][14] = wxT("Швидкість (км/год)");
	paramName[3][15] = wxT("Поправка УОЗ по дет.(°пкв)"); paramCoef[3][15][4] = 1;
	paramName[3][16] = wxT("Коеф. пал. по Тож"); paramCoef[3][16][4] = 2;
	paramName[3][17] = wxT("Коеф. пал. по Татм"); paramCoef[3][17][4] = 2;
	paramName[3][18] = wxT("Коеф. пал. по Ратм"); paramCoef[3][18][4] = 2;
	paramName[3][19] = wxT("Коеф. пал. по потужності."); paramCoef[3][19][4] = 2;
	paramName[3][20] = wxT("Добавка по напряж.(мс)"); paramCoef[3][20][4] = 2;
	paramName[3][21] = wxT("Атм.тиск(мм.рт.ст.)");
	paramName[3][22] = wxT("Баз. паливопод.ХХ(мс)"); paramCoef[3][22][4] = 2;
	paramName[3][23] = wxT("Поправка УОЗ по Тож(°пкв)"); paramCoef[3][23][4] = 1;
	paramName[3][24] = wxT("Заданні обер. ХХ");
	paramName[3][25] = wxT("УОЗ накоплен."); paramCoef[3][25][4] = 1;
	paramName[3][26] = wxT("Баз. паливоподача(мс)"); paramCoef[3][26][4] = 2;
	paramName[3][27] = wxT("Годинний розхід (л/год)"); paramCoef[3][27][4] = 2;
	paramName[3][28] = wxT("Шляховий розхід (л/100км)"); paramCoef[3][28][4] = 2;
	paramAddr[3][0][0] = 28;
	paramAddr[3][0][1] = 47;
	paramAddr[3][1][0] = 2; paramAddr[3][1][1] = 1;
	paramAddr[3][2][0] = 4; paramAddr[3][2][1] = 3;
	paramAddr[3][3][0] = 6; paramAddr[3][3][1] = 5;
	paramAddr[3][4][0] = 8; paramAddr[3][4][1] = 7;
	paramAddr[3][5][0] = 10; paramAddr[3][5][1] = 9;
	paramAddr[3][6][0] = 14; paramAddr[3][6][1] = 13;
	paramAddr[3][7][0] = 16; paramAddr[3][7][1] = 15;
	paramAddr[3][8][0] = 18; paramAddr[3][8][1] = 17;
	paramAddr[3][9][0] = 19; paramAddr[3][9][1] = 19;
	paramAddr[3][10][0] = 20; paramAddr[3][10][1] = 20;
	paramAddr[3][11][0] = 26; paramAddr[3][11][1] = 25;
	paramAddr[3][12][0] = 30; paramAddr[3][12][1] = 29;
	paramAddr[3][13][0] = 32; paramAddr[3][13][1] = 31;
	paramAddr[3][14][0] = 36; paramAddr[3][14][1] = 35;
	paramAddr[3][15][0] = 38; paramAddr[3][15][1] = 37;
	paramAddr[3][16][0] = 48; paramAddr[3][16][1] = 47;
	paramAddr[3][17][0] = 50; paramAddr[3][17][1] = 49;
	paramAddr[3][18][0] = 52; paramAddr[3][18][1] = 51;
	paramAddr[3][19][0] = 54; paramAddr[3][19][1] = 53;
	paramAddr[3][20][0] = 56; paramAddr[3][20][1] = 55;
	paramAddr[3][21][0] = 58; paramAddr[3][21][1] = 57;
	paramAddr[3][22][0] = 60; paramAddr[3][22][1] = 59;
	paramAddr[3][23][0] = 62; paramAddr[3][23][1] = 61;
	paramAddr[3][24][0] = 66; paramAddr[3][24][1] = 65;
	paramAddr[3][25][0] = 68; paramAddr[3][25][1] = 67;
	paramAddr[3][26][0] = 74; paramAddr[3][26][1] = 73;
	paramAddr[3][27][0] = 80; paramAddr[3][27][1] = 79;
	paramAddr[3][28][0] = 82; paramAddr[3][28][1] = 81;
	paramCoef[3][2][2] = 10;
	paramCoef[3][3][2] = 10;
	paramCoef[3][4][2] = 100;
	paramCoef[3][6][2] = 10;
	paramCoef[3][7][1] = 5; paramCoef[3][7][2] = 1024;
	paramCoef[3][8][2] = 10000;
	paramCoef[3][9][0] = -40;
	paramCoef[3][10][0] = -40;
	paramCoef[3][12][2] = 100;
	paramCoef[3][15][2] = 10;
	paramCoef[3][16][2] = 1000;
	paramCoef[3][17][2] = 1000;
	paramCoef[3][18][2] = 1000;
	paramCoef[3][19][2] = 1000;
	paramCoef[3][20][2] = 100;
	paramCoef[3][22][2] = 100;
	paramCoef[3][23][2] = 10;
	paramCoef[3][25][2] = 10;
	paramCoef[3][26][2] = 100;
	paramCoef[3][27][2] = 100;
	paramCoef[3][28][2] = 10;
	flags[3][0] = 24; flags[3][1] = 24; flags[3][2] = 4;
	timerName[3][1] = wxT("Час роботи (с)");
	timerName[3][2] = wxT("Загальний пробіг (км)"); timerCoef[3][2][4] = 1;
	timerName[3][3] = wxT("Час перекрута (с)");
	timerName[3][4] = wxT("Час перегріву (с)");
	timerName[3][5] = wxT("Час детонації (с)");
	timerName[3][6] = wxT("Час <1000 об/хв (с)");
	timerName[3][7] = wxT("Час 1000-2000 (с)");
	timerName[3][8] = wxT("Час 2000-3000 (с)");
	timerName[3][9] = wxT("Час 3000-4000 (с)");
	timerName[3][10] = wxT("Час 4000-5000 (с)");
	timerName[3][11] = wxT("Час 5000-6000 (с)");
	timerName[3][12] = wxT("Час 6000-7000 (с)");
	timerName[3][13] = wxT("Час >7000 об/хв (с)");
	timerName[3][14] = wxT("Час Sport (с)");
	timerName[3][15] = wxT("Час проп.запал. (с)");
	timerAddr[3][0][0] = 15;
	timerAddr[3][1][0] = 5; timerAddr[3][1][1] = 2;
	timerAddr[3][2][0] = 9; timerAddr[3][2][1] = 6;
	timerAddr[3][3][0] = 13; timerAddr[3][3][1] = 10;
	timerAddr[3][4][0] = 17; timerAddr[3][4][1] = 14;
	timerAddr[3][5][0] = 21; timerAddr[3][5][1] = 18;
	timerAddr[3][6][0] = 25; timerAddr[3][6][1] = 22;
	timerAddr[3][7][0] = 29; timerAddr[3][7][1] = 26;
	timerAddr[3][8][0] = 33; timerAddr[3][8][1] = 30;
	timerAddr[3][9][0] = 37; timerAddr[3][9][1] = 34;
	timerAddr[3][10][0] = 41; timerAddr[3][10][1] = 38;
	timerAddr[3][11][0] = 45; timerAddr[3][11][1] = 42;
	timerAddr[3][12][0] = 49; timerAddr[3][12][1] = 46;
	timerAddr[3][13][0] = 53; timerAddr[3][13][1] = 50;
	timerAddr[3][14][0] = 57; timerAddr[3][14][1] = 54;
	timerAddr[3][15][0] = 61; timerAddr[3][15][1] = 58;
	timerCoef[3][2][2] = 100;
	analogName[3][1] = wxT("Датчик детонації");
	analogName[3][2] = wxT("Бортова мережа");
	analogName[3][3] = wxT("Датчик дороги");
	analogName[3][4] = wxT("Температура атм.");
	analogName[3][5] = wxT("Температура ОР");
	analogName[3][6] = wxT("Датчик кисню.1");
	analogName[3][7] = wxT("Датчик тиску");
	analogName[3][8] = wxT("Датчик кисню.2");
	analogName[3][9] = wxT("Положення дрос.");
	analogName[3][10] = wxT("Розхід повітря");
	analogAddr[3][0][0] = 10;
	analogAddr[3][1][0] = 2; analogAddr[3][1][1] = 1;
	analogAddr[3][2][0] = 4; analogAddr[3][2][1] = 3;
	analogAddr[3][3][0] = 6; analogAddr[3][3][1] = 5;
	analogAddr[3][4][0] = 10; analogAddr[3][4][1] = 9;
	analogAddr[3][5][0] = 12; analogAddr[3][5][1] = 11;
	analogAddr[3][6][0] = 14; analogAddr[3][6][1] = 13;
	analogAddr[3][7][0] = 16; analogAddr[3][7][1] = 15;
	analogAddr[3][8][0] = 18; analogAddr[3][8][1] = 17;
	analogAddr[3][9][0] = 20; analogAddr[3][9][1] = 19;
	analogAddr[3][10][0] = 24; analogAddr[3][10][1] = 23;
	for (int i = 1; i < 17; i++)
	{
		analogCoef[3][i][1] = 5;
		analogCoef[3][i][2] = 1024;
	}

	//---------- Микас 7.6 (28)-----------------------------------------------------------
	for (int i = 1; i < 29; i++)
	{
		paramName[4][i] = paramName[3][i];
		paramAddr[4][i][0] = paramAddr[3][i][0];
		paramAddr[4][i][1] = paramAddr[3][i][1];
		paramCoef[4][i][0] = paramCoef[3][i][0];
		paramCoef[4][i][1] = paramCoef[3][i][1];
		paramCoef[4][i][2] = paramCoef[3][i][2];
		paramCoef[4][i][3] = paramCoef[3][i][3];
		paramCoef[4][i][4] = paramCoef[3][i][4];
		timerName[4][i] = timerName[3][i];
		timerAddr[4][i][0] = timerAddr[3][i][0];
		timerAddr[4][i][1] = timerAddr[3][i][1];
		timerCoef[4][i][0] = timerCoef[3][i][0];
		timerCoef[4][i][1] = timerCoef[3][i][1];
		timerCoef[4][i][2] = timerCoef[3][i][2];
		timerCoef[4][i][3] = timerCoef[3][i][3];
		timerCoef[4][i][4] = timerCoef[3][i][4];
		analogCoef[4][i][0] = analogCoef[3][i][0];
		analogCoef[4][i][1] = analogCoef[3][i][1];
		analogCoef[4][i][2] = analogCoef[3][i][2];
		analogCoef[4][i][3] = analogCoef[3][i][3];
	}
	analogAddr[4][0][0] = 11;
	analogName[4][1] = wxT("Напруга БС");
	analogName[4][2] = wxT("Температура пов..");
	analogName[4][3] = wxT("Положення дросс.");
	analogName[4][4] = wxT("Температура ОР");
	analogName[4][5] = wxT("Клапан рециркул.");
	analogName[4][6] = wxT("Датчик абс.давл.");
	analogName[4][7] = wxT("Датчик детонації");
	analogName[4][8] = wxT("Сигнал диагн.запал.");
	analogName[4][9] = wxT("Сигнал ДК1");

	analogName[4][10] = wxT("Потенціометер СО");
	analogName[4][11] = wxT("Подогреватель 1");
	analogAddr[4][1][0] = 4; analogAddr[4][1][1] = 3;
	analogAddr[4][2][0] = 6; analogAddr[4][2][1] = 5;
	analogAddr[4][3][0] = 8; analogAddr[4][3][1] = 7;
	analogAddr[4][4][0] = 10; analogAddr[4][4][1] = 9;
	analogAddr[4][5][0] = 12; analogAddr[4][5][1] = 11;
	analogAddr[4][6][0] = 14; analogAddr[4][6][1] = 13;
	analogAddr[4][7][0] = 16; analogAddr[4][7][1] = 15;
	analogAddr[4][8][0] = 20; analogAddr[4][8][1] = 19;
	analogAddr[4][9][0] = 22; analogAddr[4][9][1] = 21;
	analogAddr[4][10][0] = 24; analogAddr[4][10][1] = 23;
	analogAddr[4][11][0] = 26; analogAddr[4][11][1] = 25;
	timerAddr[4][0][0] = 15;
	paramAddr[4][0][0] = 28;
	paramAddr[4][0][1] = 57;
	flags[4][0] = 24; flags[4][1] = 24; flags[4][2] = 4;

	//---------- Микас 11(Е2) (26)-----------------------------------------------------------
	paramName[5][1] = wxT("Оберти (об/хв)");
	paramName[5][2] = wxT("Температура ОР (°C)");
	paramName[5][3] = wxT("Тепература АТМ (°C)");
	paramName[5][4] = wxT("Положення ДЗ (%)"); paramCoef[5][4][4] = 1;
	paramName[5][5] = wxT("Коефіцієнт альфа"); paramCoef[5][5][4] = 2;
	paramName[5][6] = wxT("Цикл.розх.пов..рез.(мг/ц)"); paramCoef[5][6][4] = 2;
	paramName[5][7] = wxT("Цикл.нап.по дрос.и РХХ"); paramCoef[5][7][4] = 2;
	paramName[5][8] = wxT("Цикл.паливопод.(мг/ц)"); paramCoef[5][8][4] = 2;
	paramName[5][9] = wxT("Паливоподача (мс)"); paramCoef[5][9][4] = 2;
	paramName[5][10] = wxT("Год.розх.пального(л/год)"); paramCoef[5][10][4] = 2;
	paramName[5][11] = wxT("Мас.розх.повітря(кг/год)"); paramCoef[5][11][4] = 2;
	paramName[5][12] = wxT("Цикл.розх.повітря"); paramCoef[5][12][4] = 2;
	paramName[5][13] = wxT("Факт.положен. РХХ");
	paramName[5][14] = wxT("Установка адсорбера(%)");
	paramName[5][15] = wxT("Пот.нагріву ДК1(%)");
	paramName[5][16] = wxT("Баж.Оберти ХХ(об/хв)");
	paramName[5][17] = wxT("Адапт.утеч.повітря(кг/год)"); paramCoef[5][17][4] = 2;
	paramName[5][18] = wxT("Швидкість (км/год)");
	paramName[5][19] = wxT("Кор.пального по ДК1"); paramCoef[5][19][4] = 2;
	paramName[5][20] = wxT("Кор.неучт.підсосу"); paramCoef[5][20][4] = 2;
	paramName[5][21] = wxT("Кор.форсунок по ДК1"); paramCoef[5][21][4] = 2;
	paramName[5][22] = wxT("Режим роботи двиг.");
	paramName[5][23] = wxT("УОЗ (°пкв)"); paramCoef[5][23][4] = 1;
	paramName[5][24] = wxT("Кор.УОЗ на ХХ(°пкв)"); paramCoef[5][24][4] = 1;
	paramName[5][25] = wxT("Детонація"); paramCoef[5][25][4] = 2;
	paramName[5][26] = wxT("Кількість помилок");
	paramAddr[5][0][0] = 26;
	paramAddr[5][0][1] = 68;
	paramAddr[5][1][0] = 1; paramAddr[5][1][1] = 2;
	paramAddr[5][2][0] = 3; paramAddr[5][2][1] = 4;
	paramAddr[5][3][0] = 5; paramAddr[5][3][1] = 6;
	paramAddr[5][4][0] = 7; paramAddr[5][4][1] = 8;
	paramAddr[5][5][0] = 9; paramAddr[5][5][1] = 10;
	paramAddr[5][6][0] = 11; paramAddr[5][6][1] = 12;
	paramAddr[5][7][0] = 13; paramAddr[5][7][1] = 14;
	paramAddr[5][8][0] = 15; paramAddr[5][8][1] = 16;
	paramAddr[5][9][0] = 17; paramAddr[5][9][1] = 18;
	paramAddr[5][10][0] = 19; paramAddr[5][10][1] = 20;
	paramAddr[5][11][0] = 21; paramAddr[5][11][1] = 22;
	paramAddr[5][12][0] = 23; paramAddr[5][12][1] = 24;
	paramAddr[5][13][0] = 25; paramAddr[5][13][1] = 26;
	paramAddr[5][14][0] = 27; paramAddr[5][14][1] = 28;
	paramAddr[5][15][0] = 34; paramAddr[5][15][1] = 35;
	paramAddr[5][16][0] = 36; paramAddr[5][16][1] = 37;
	paramAddr[5][17][0] = 38; paramAddr[5][17][1] = 39;
	paramAddr[5][18][0] = 40; paramAddr[5][18][1] = 41;
	paramAddr[5][19][0] = 43; paramAddr[5][19][1] = 44;
	paramAddr[5][20][0] = 45; paramAddr[5][20][1] = 46;
	paramAddr[5][21][0] = 47; paramAddr[5][21][1] = 48;
	paramAddr[5][22][0] = 51; paramAddr[5][22][1] = 51;
	paramAddr[5][23][0] = 52; paramAddr[5][23][1] = 53;
	paramAddr[5][24][0] = 54; paramAddr[5][24][1] = 55;
	paramAddr[5][25][0] = 56; paramAddr[5][25][1] = 56;
	paramAddr[5][26][0] = 61; paramAddr[5][26][1] = 61;
	paramCoef[5][1][2] = 2;
	paramCoef[5][2][2] = 128;
	paramCoef[5][3][2] = 128;
	paramCoef[5][4][2] = 128;
	paramCoef[5][5][2] = 1024;
	paramCoef[5][6][2] = 16;
	paramCoef[5][7][2] = 16;
	paramCoef[5][8][2] = 128;
	paramCoef[5][9][1] = 5.332; paramCoef[5][9][2] = 1000;
	paramCoef[5][10][2] = 256;
	paramCoef[5][11][2] = 16;
	paramCoef[5][12][1] = 1.22; paramCoef[5][12][2] = 10000;
	paramCoef[5][13][2] = 128;
	paramCoef[5][14][2] = 128;
	paramCoef[5][15][2] = 16;
	paramCoef[5][16][2] = 2;
	paramCoef[5][17][2] = 16;
	paramCoef[5][19][2] = 1024;
	paramCoef[5][20][1] = 1.22; paramCoef[5][20][2] = 10000;
	paramCoef[5][21][1] = 1.22; paramCoef[5][21][2] = 10000;
	paramCoef[5][23][1] = 3; paramCoef[5][23][2] = 4;
	paramCoef[5][24][1] = 3; paramCoef[5][24][2] = 4;
	flags[5][0] = 61; flags[5][1] = 61; flags[5][2] = 255;
	timerName[5][1] = wxT("Загальний пробіг (км)"); timerCoef[5][1][4] = 1;
	timerName[5][2] = wxT("Колич.израсх.пального(л)"); timerCoef[5][2][4] = 1;
	timerName[5][3] = wxT("Час роботи (хв)");
	timerName[5][4] = wxT("Час перегріву (с)");
	timerName[5][5] = wxT("Час детонації (хв)");
	timerName[5][6] = wxT("Число пусків");
	timerName[5][7] = wxT("Число успішних пусків");
	timerName[5][8] = wxT("Час перекрута (хв)");
	timerName[5][9] = wxT("Перевищ.швид.обкатки1(хв)");
	timerName[5][10] = wxT("Перевищ.швид.обкатки2(хв)");
	timerName[5][11] = wxT("Час с невик.дат.швид.");
	timerName[5][12] = wxT("Число откл. питания ЭБУ");
	timerName[5][13] = wxT("Час пропуск.запалювання");
	timerName[5][14] = wxT("Час с невик.дат.детон.");
	timerName[5][15] = wxT("Час с невик.дат.кисл.");
	timerName[5][16] = wxT("Час с включ.CheckEngine");
	timerAddr[5][0][0] = 16;
	timerAddr[5][1][0] = 42; timerAddr[5][1][1] = 45;
	timerAddr[5][2][0] = 46; timerAddr[5][2][1] = 49;
	timerAddr[5][3][0] = 50; timerAddr[5][3][1] = 53;
	timerAddr[5][4][0] = 54; timerAddr[5][4][1] = 55;
	timerAddr[5][5][0] = 56; timerAddr[5][5][1] = 57;
	timerAddr[5][6][0] = 58; timerAddr[5][6][1] = 59;
	timerAddr[5][7][0] = 60; timerAddr[5][7][1] = 61;
	timerAddr[5][8][0] = 62; timerAddr[5][8][1] = 63;
	timerAddr[5][9][0] = 64; timerAddr[5][9][1] = 65;
	timerAddr[5][10][0] = 66; timerAddr[5][10][1] = 67;
	timerAddr[5][11][0] = 68; timerAddr[5][11][1] = 69;
	timerAddr[5][12][0] = 70; timerAddr[5][12][1] = 71;
	timerAddr[5][13][0] = 72; timerAddr[5][13][1] = 73;
	timerAddr[5][14][0] = 74; timerAddr[5][14][1] = 75;
	timerAddr[5][15][0] = 76; timerAddr[5][15][1] = 77;
	timerAddr[5][16][0] = 78; timerAddr[5][16][1] = 79;
	timerCoef[5][1][2] = 10;
	timerCoef[5][2][2] = 100;
	analogName[5][1] = wxT("Бортова мережа");
	analogName[5][2] = wxT("Температура ОР");
	analogName[5][3] = wxT("Температура атм.");
	analogName[5][4] = wxT("Розхід повітря");
	analogName[5][5] = wxT("Положення дросс.");
	analogName[5][6] = wxT("Датчик детонації");
	analogName[5][7] = wxT("Датчик кисню.1");
	analogName[5][8] = wxT("Нагрівач ДК1");
	analogAddr[5][0][0] = 8;
	analogAddr[5][1][0] = 1; analogAddr[5][1][1] = 2;
	analogAddr[5][2][0] = 1; analogAddr[5][2][1] = 2;
	analogAddr[5][3][0] = 1; analogAddr[5][3][1] = 2;
	analogAddr[5][4][0] = 1; analogAddr[5][4][1] = 2;
	analogAddr[5][5][0] = 1; analogAddr[5][5][1] = 2;
	analogAddr[5][6][0] = 1; analogAddr[5][6][1] = 2;
	analogAddr[5][7][0] = 1; analogAddr[5][7][1] = 2;
	analogAddr[5][8][0] = 1; analogAddr[5][8][1] = 2;
	analogCoef[3][1][2] = 256;
	for (int i = 2; i < 12; i++)
	{
		analogCoef[3][i][1] = 5;
		analogCoef[3][i][2] = 1024;
	}
	analogCoef[3][8][1] = 4;

	//---------- Микас 11(Е3) (26)-----------------------------------------------------------
	for (int i = 1; i < 27; i++)
	{
		paramName[6][i] = paramName[5][i];
		paramAddr[6][i][0] = paramAddr[5][i][0];
		paramAddr[6][i][1] = paramAddr[5][i][1];
		paramCoef[6][i][0] = paramCoef[5][i][0];
		paramCoef[6][i][1] = paramCoef[5][i][1];
		paramCoef[6][i][2] = paramCoef[5][i][2];
		paramCoef[6][i][3] = paramCoef[5][i][3];
		paramCoef[6][i][4] = paramCoef[5][i][4];
		timerName[6][i] = timerName[5][i];
		timerAddr[6][i][0] = timerAddr[5][i][0];
		timerAddr[6][i][1] = timerAddr[5][i][1];
		timerCoef[6][i][0] = timerCoef[5][i][0];
		timerCoef[6][i][1] = timerCoef[5][i][1];
		timerCoef[6][i][2] = timerCoef[5][i][2];
		timerCoef[6][i][3] = timerCoef[5][i][3];
		timerCoef[6][i][4] = timerCoef[5][i][4];
		analogName[6][i] = analogName[5][i];
		analogAddr[6][i][0] = analogAddr[5][i][0];
		analogAddr[6][i][1] = analogAddr[5][i][1];
		analogCoef[6][i][0] = analogCoef[5][i][0];
		analogCoef[6][i][1] = analogCoef[5][i][1];
		analogCoef[6][i][2] = analogCoef[5][i][2];
		analogCoef[6][i][3] = analogCoef[5][i][3];
	}
	analogAddr[6][0][0] = 11;
	analogName[6][9] = wxT("Датчик кисню.2");
	analogName[6][10] = wxT("Нагрівач ДК2");
	analogName[6][11] = wxT("Датчик дороги");
	analogAddr[6][9][0] = 17; analogAddr[6][9][1] = 18;
	analogAddr[6][10][0] = 19; analogAddr[6][10][1] = 20;
	analogAddr[6][11][0] = 25; analogAddr[6][11][1] = 26;
	analogCoef[6][10][1] = 4;
	analogAddr[6][0][0] = 11;
	timerAddr[6][0][0] = 16;
	paramAddr[6][0][0] = 26;
	paramAddr[6][0][1] = 71;
	flags[6][0] = 61; flags[6][1] = 61; flags[6][2] = 255;

	//---------- М7.9.7(E2) (27)-----------------------------------------------------------
	paramName[7][1] = wxT("Кіл.помилок");
	paramName[7][2] = wxT("Температура ОР (°C)");
	paramName[7][3] = wxT("Температура АТМ (°C)");
	paramName[7][4] = wxT("Напруга БС (В)"); paramCoef[7][4][4] = 1;
	paramName[7][5] = wxT("Швидкість (км/год)");
	paramName[7][6] = wxT("Положення ДЗ (%)"); paramCoef[7][6][4] = 1;
	paramName[7][7] = wxT("Оберти (об/хв)");
	paramName[7][8] = wxT("Розхід повітря(кг/год)"); paramCoef[7][8][4] = 2;
	paramName[7][9] = wxT("УОЗ (°пкв)"); paramCoef[7][9][4] = 1;
	paramName[7][10] = wxT("Кор.УОЗ по детон.(°пкв)"); paramCoef[7][10][4] = 1;
	paramName[7][11] = wxT("Параметр нагруз.(%)");
	paramName[7][12] = wxT("Паливоподача (мс)"); paramCoef[7][12][4] = 2;
	paramName[7][13] = wxT("Бажані обер.ХХ(об/хв)");
	paramName[7][14] = wxT("Положення РХХ");
	paramName[7][15] = wxT("Напруга ДК1 (В)"); paramCoef[7][15][4] = 2;
	paramName[7][16] = wxT("Коеф.пального по ДК1"); paramCoef[7][16][4] = 2;
	paramName[7][17] = wxT("Задн.значен.лямда"); paramCoef[7][17][4] = 2;
	paramName[7][18] = wxT("Сигнал детонації (В)"); paramCoef[7][18][4] = 2;
	paramName[7][19] = wxT("Неравн.обер. КВ (об/с2)");
	paramName[7][20] = wxT("Ліч.проп.восп. в 1ц.");
	paramName[7][21] = wxT("Ліч.проп.восп. в 2ц.");
	paramName[7][22] = wxT("Ліч.проп.восп. в 3ц.");
	paramName[7][23] = wxT("Ліч.проп.восп. в 4ц.");
	paramName[7][24] = wxT("Сумарн.Ліч.проп.восп.");
	paramName[7][25] = wxT("Годинний розхід(л/100км)"); paramCoef[7][25][4] = 2;
	paramName[7][26] = wxT("Потребн.рег.ХХ.I-годть(%)");
	paramName[7][27] = wxT("Потребн.рег.ХХ.PD-годть(%)");
	paramAddr[7][0][0] = 27;
	paramAddr[7][0][1] = 72;
	paramAddr[7][1][0] = 1; paramAddr[7][1][1] = 1;
	paramAddr[7][2][0] = 3; paramAddr[7][2][1] = 3;
	paramAddr[7][3][0] = 4; paramAddr[7][3][1] = 4;
	paramAddr[7][4][0] = 5; paramAddr[7][4][1] = 5;
	paramAddr[7][5][0] = 6; paramAddr[7][5][1] = 6;
	paramAddr[7][6][0] = 7; paramAddr[7][6][1] = 7;
	paramAddr[7][7][0] = 8; paramAddr[7][7][1] = 8;
	paramAddr[7][8][0] = 10; paramAddr[7][8][1] = 9;
	paramAddr[7][9][0] = 11; paramAddr[7][9][1] = 11;
	paramAddr[7][10][0] = 12; paramAddr[7][10][1] = 12;
	paramAddr[7][11][0] = 14; paramAddr[7][11][1] = 13;
	paramAddr[7][12][0] = 18; paramAddr[7][12][1] = 17;
	paramAddr[7][13][0] = 19; paramAddr[7][13][1] = 19;
	paramAddr[7][14][0] = 20; paramAddr[7][14][1] = 20;
	paramAddr[7][15][0] = 25; paramAddr[7][15][1] = 25;
	paramAddr[7][16][0] = 27; paramAddr[7][16][1] = 26;
	paramAddr[7][17][0] = 29; paramAddr[7][17][1] = 28;
	paramAddr[7][18][0] = 32; paramAddr[7][18][1] = 31;
	paramAddr[7][19][0] = 34; paramAddr[7][19][1] = 33;
	paramAddr[7][20][0] = 38; paramAddr[7][20][1] = 37;
	paramAddr[7][21][0] = 40; paramAddr[7][21][1] = 39;
	paramAddr[7][22][0] = 42; paramAddr[7][22][1] = 41;
	paramAddr[7][23][0] = 44; paramAddr[7][23][1] = 43;
	paramAddr[7][24][0] = 46; paramAddr[7][24][1] = 45;
	paramAddr[7][25][0] = 52; paramAddr[7][25][1] = 51;
	paramAddr[7][26][0] = 55; paramAddr[7][26][1] = 54;
	paramAddr[7][27][0] = 57; paramAddr[7][27][1] = 56;
	paramCoef[7][2][1] = 3; paramCoef[7][2][2] = 4; paramCoef[7][2][3] = -48;
	paramCoef[7][3][1] = 3; paramCoef[7][3][2] = 4; paramCoef[7][3][3] = -48;
	paramCoef[7][4][1] = 7.35; paramCoef[7][4][2] = 100;
	paramCoef[7][5][1] = 1.25;
	paramCoef[7][6][1] = 3.92; paramCoef[7][6][2] = 10;
	paramCoef[7][7][1] = 40;
	paramCoef[7][8][2] = 10;
	paramCoef[7][9][1] = 3; paramCoef[7][9][2] = 4;
	paramCoef[7][10][1] = 3; paramCoef[7][10][2] = 4;
	paramCoef[7][11][1] = 2.345; paramCoef[7][11][2] = 100;
	paramCoef[7][12][2] = 75;
	paramCoef[7][13][1] = 10;
	paramCoef[7][15][1] = 5.22; paramCoef[7][15][2] = 1000; paramCoef[7][15][3] = -0.2;
	paramCoef[7][16][1] = 2.45; paramCoef[7][16][2] = 10000;
	paramCoef[7][17][1] = 2.45; paramCoef[7][17][2] = 10000;
	paramCoef[7][18][1] = 5; paramCoef[7][18][2] = 256;
	paramCoef[7][19][1] = 5.755; paramCoef[7][19][2] = 10;
	paramCoef[7][25][1] = 2.15; paramCoef[7][25][2] = 1000;
	paramCoef[7][26][1] = 3.05; paramCoef[7][26][2] = 1000;
	paramCoef[7][27][1] = 3.05; paramCoef[7][27][2] = 1000;
	flags[7][0] = 1; flags[7][1] = 1; flags[7][2] = 255;
	for (int i = 1; i < 28; i++)
	{
		timerName[7][i] = timerName[5][i];
		timerAddr[7][i][0] = timerAddr[5][i][0];
		timerAddr[7][i][1] = timerAddr[5][i][1];
		timerCoef[7][i][0] = timerCoef[5][i][0];
		timerCoef[7][i][1] = timerCoef[5][i][1];
		timerCoef[7][i][2] = timerCoef[5][i][2];
		timerCoef[7][i][3] = timerCoef[5][i][3];
		timerCoef[7][i][4] = timerCoef[5][i][4];
	}
	timerAddr[7][0][0] = 16;
	analogName[7][1] = wxT("Бортова мережа");
	analogName[7][2] = wxT("Температура ОР");
	analogName[7][3] = wxT("Розхід повітря");
	analogName[7][4] = wxT("Положення дросс.");
	analogName[7][5] = wxT("Датчик кисню.1");
	analogName[7][6] = wxT("Температура атм.");
	analogName[7][7] = wxT("Нагрівач ДК1");
	analogName[7][8] = wxT("Датчик прискорення");
	analogAddr[7][0][0] = 8;
	analogAddr[7][1][0] = 2; analogAddr[7][1][1] = 1;
	analogAddr[7][2][0] = 3; analogAddr[7][2][1] = 3;
	analogAddr[7][3][0] = 5; analogAddr[7][3][1] = 4;
	analogAddr[7][4][0] = 6; analogAddr[7][4][1] = 6;
	analogAddr[7][5][0] = 9; analogAddr[7][5][1] = 8;
	analogAddr[7][6][0] = 10; analogAddr[7][6][1] = 10;
	analogAddr[7][7][0] = 14; analogAddr[7][7][1] = 13;
	analogAddr[7][8][0] = 15; analogAddr[7][8][1] = 15;
	analogCoef[7][1][1] = 1.76; analogCoef[7][1][2] = 100;
	analogCoef[7][2][1] = 5; analogCoef[7][2][2] = 256;
	analogCoef[7][3][1] = 5; analogCoef[7][3][2] = 1024;
	analogCoef[7][4][1] = 1.9531; analogCoef[7][4][2] = 100;
	analogCoef[7][5][1] = 5; analogCoef[7][5][2] = 1024;
	analogCoef[7][6][1] = 1.9531; analogCoef[7][6][2] = 100;
	analogCoef[7][7][1] = 2;
	analogCoef[7][8][1] = 4.902; analogCoef[7][8][2] = 10; analogCoef[7][8][3] = -6.27;

	//---------- М7.9.7(E3) (30)-----------------------------------------------------------
	for (int i = 1; i < 28; i++)
	{
		paramName[8][i] = paramName[7][i];
		paramAddr[8][i][0] = paramAddr[7][i][0];
		paramAddr[8][i][1] = paramAddr[7][i][1];
		paramCoef[8][i][0] = paramCoef[7][i][0];
		paramCoef[8][i][1] = paramCoef[7][i][1];
		paramCoef[8][i][2] = paramCoef[7][i][2];
		paramCoef[8][i][3] = paramCoef[7][i][3];
		paramCoef[8][i][4] = paramCoef[7][i][4];
		timerName[8][i] = timerName[5][i];
		timerAddr[8][i][0] = timerAddr[5][i][0];
		timerAddr[8][i][1] = timerAddr[5][i][1];
		timerCoef[8][i][0] = timerCoef[5][i][0];
		timerCoef[8][i][1] = timerCoef[5][i][1];
		timerCoef[8][i][2] = timerCoef[5][i][2];
		timerCoef[8][i][3] = timerCoef[5][i][3];
		timerCoef[8][i][4] = timerCoef[5][i][4];
		analogName[8][i] = analogName[5][i];
		analogAddr[8][i][0] = analogAddr[5][i][0];
		analogAddr[8][i][1] = analogAddr[5][i][1];
		analogCoef[8][i][0] = analogCoef[5][i][0];
		analogCoef[8][i][1] = analogCoef[5][i][1];
		analogCoef[8][i][2] = analogCoef[5][i][2];
		analogCoef[8][i][3] = analogCoef[5][i][3];
	}
	timerAddr[8][0][0] = 16;
	paramName[8][28] = wxT("Напруга ДК2 (В)"); paramCoef[8][28][4] = 2;
	paramName[8][29] = wxT("Період сигналу ДК2(сек)"); paramCoef[8][29][4] = 2;
	paramName[8][30] = wxT("Сигнал нерівн.дороги(g)"); paramCoef[8][30][4] = 2;
	paramAddr[8][0][0] = 30;
	paramAddr[8][0][1] = 79;
	paramAddr[8][28][0] = 67; paramAddr[8][28][1] = 67;
	paramAddr[8][29][0] = 68; paramAddr[8][29][1] = 68;
	paramAddr[8][30][0] = 72; paramAddr[8][30][1] = 71;
	paramCoef[8][28][1] = 5.22; paramCoef[7][28][2] = 1000; paramCoef[7][28][3] = -0.2;
	paramCoef[8][29][1] = 4; paramCoef[7][29][2] = 100;
	paramCoef[8][30][1] = 1.9; paramCoef[7][30][2] = 10000; paramCoef[7][30][3] = 6.25;
	flags[8][0] = 1; flags[8][1] = 1; flags[8][2] = 255;
	analogAddr[8][0][0] = 10;
	analogName[8][9] = wxT("Датчик кисню.2");
	analogName[8][10] = wxT("Нагрівач ДК2");
	analogAddr[8][9][0] = 12; analogAddr[8][9][1] = 11;
	analogAddr[8][10][0] = 19; analogAddr[8][10][1] = 18;
	analogCoef[8][9][1] = 5; analogCoef[8][9][2] = 1024;
	analogCoef[8][10][1] = 2;

	//---------- Январь 7 (19)-----------------------------------------------------------
	for (int i = 1; i < 19; i++)
	{
		paramName[9][i] = paramName[2][i];
		paramCoef[9][i][0] = paramCoef[2][i][0];
		paramCoef[9][i][1] = paramCoef[2][i][1];
		paramCoef[9][i][2] = paramCoef[2][i][2];
		paramCoef[9][i][3] = paramCoef[2][i][3];
		paramCoef[9][i][4] = paramCoef[2][i][4];
		analogName[9][i] = analogName[2][i];
		analogAddr[9][i][0] = analogAddr[2][i][0];
		analogAddr[9][i][1] = analogAddr[2][i][1];
		analogCoef[9][i][1] = analogCoef[2][i][1];
		analogCoef[9][i][2] = analogCoef[2][i][2];
		paramAddr[9][i][0] = paramAddr[2][i][0];
		paramAddr[9][i][1] = paramAddr[2][i][1];
	}
	paramName[9][19] = wxT("Температура АТМ (°C)");
	paramAddr[9][19][0] = 35;
	paramAddr[9][19][1] = 35;
	paramCoef[1][19][3] = -40;
	paramAddr[9][0][0] = 19;
	paramAddr[9][0][1] = 43;
	analogAddr[9][0][0] = 6;
	paramCoef[9][2][0] = 128; paramCoef[2][2][1] = 14.7; paramCoef[2][2][2] = 256;
	paramCoef[9][13][1] = 1.25; paramCoef[2][13][2] = 256;
	flags[9][0] = 5; flags[9][1] = 8; flags[9][2] = 255;

	//---------- МE1 7.9.7 (30)-----------------------------------------------------------
	paramName[10][1] = wxT("Оберти (об/хв)"); paramCoef[10][1][4] = 1;
	paramName[10][2] = wxT("Бажані обер.ХХ(об/хв)"); paramCoef[10][2][4] = 1;
	paramName[10][3] = wxT("Нерівн.обер.на ХХ(об/м)"); paramCoef[10][3][4] = 1;
	paramName[10][4] = wxT("Температура ОР (°C)"); paramCoef[10][4][4] = 1;
	paramName[10][5] = wxT("Температура АТМ (°C)"); paramCoef[10][5][4] = 1;
	paramName[10][6] = wxT("УОЗ (°пкв)"); paramCoef[10][6][4] = 1;
	paramName[10][7] = wxT("Час нак.запал.(мс)");
	paramName[10][8] = wxT("Розхід повітря(кг/год)"); paramCoef[10][8][4] = 1;
	paramName[10][9] = wxT("Підсос повітря(кг/год)"); paramCoef[10][9][4] = 1;
	paramName[10][10] = wxT("Полож.педалі уск.(%)"); paramCoef[10][10][4] = 1;
	paramName[10][11] = wxT("Положення ДЗ(%)"); paramCoef[10][11][4] = 1;
	paramName[10][12] = wxT("Час впорскування(мс)"); paramCoef[10][12][4] = 1;
	paramName[10][13] = wxT("Цикл.нап.пов.."); paramCoef[10][13][4] = 1;
	paramName[10][14] = wxT("Цикл.нап.пал.(%)"); paramCoef[10][14][4] = 1;
	paramName[10][15] = wxT("Контр.склад суміші"); paramCoef[10][15][4] = 1;
	paramName[10][16] = wxT("Баж.склад суміші"); paramCoef[10][16][4] = 1;
	paramName[10][17] = wxT("Кор.суміші по ДК1"); paramCoef[10][17][4] = 1;
	paramName[10][18] = wxT("Відкр.клап.адсор(%)"); paramCoef[10][18][4] = 1;
	paramName[10][19] = wxT("Напруга БС (В)"); paramCoef[10][19][4] = 1;
	paramName[10][20] = wxT("Швидкість (км/год)");
	paramName[10][21] = wxT("Кор.УОЗ по детон.(°пкв)"); paramCoef[10][21][4] = 1;
	paramName[10][22] = wxT("Напруга ДК1 (В)"); paramCoef[10][22][4] = 2;
	paramName[10][23] = wxT("Напруга ДК2 (В)"); paramCoef[10][23][4] = 2;
	paramName[10][24] = wxT("Період сигн.ДК1"); paramCoef[10][24][4] = 2;
	paramName[10][25] = wxT("Ліч.проп.восп. в 1ц.");
	paramName[10][26] = wxT("Ліч.проп.восп. в 2ц.");
	paramName[10][27] = wxT("Ліч.проп.восп. в 3ц.");
	paramName[10][28] = wxT("Ліч.проп.восп. в 4ц.");
	paramName[10][29] = wxT("Сигнал детонації (В)"); paramCoef[10][29][4] = 2;
	paramName[10][30] = wxT("Годинний розхід(л/ч)"); paramCoef[10][30][4] = 2;

	paramAddr[10][0][0] = 30;
	paramAddr[10][0][1] = 72;
	paramAddr[10][1][0] = 2; paramAddr[10][1][1] = 1;
	paramAddr[10][2][0] = 4; paramAddr[10][2][1] = 3;
	paramAddr[10][3][0] = 6; paramAddr[10][3][1] = 5;
	paramAddr[10][4][0] = 8; paramAddr[10][4][1] = 7;
	paramAddr[10][5][0] = 10; paramAddr[10][5][1] = 10;
	paramAddr[10][6][0] = 12; paramAddr[10][6][1] = 12;
	paramAddr[10][7][0] = 17; paramAddr[10][7][1] = 16;
	paramAddr[10][8][0] = 19; paramAddr[10][8][1] = 18;
	paramAddr[10][9][0] = 21; paramAddr[10][9][1] = 20;
	paramAddr[10][10][0] = 23; paramAddr[10][10][1] = 22;
	paramAddr[10][11][0] = 25; paramAddr[10][11][1] = 24;
	paramAddr[10][12][0] = 27; paramAddr[10][12][1] = 26;
	paramAddr[10][13][0] = 29; paramAddr[10][13][1] = 28;
	paramAddr[10][14][0] = 31; paramAddr[10][14][1] = 30;
	paramAddr[10][15][0] = 37; paramAddr[10][15][1] = 36;
	paramAddr[10][16][0] = 40; paramAddr[10][16][1] = 40;
	paramAddr[10][17][0] = 42; paramAddr[10][17][1] = 41;
	paramAddr[10][18][0] = 46; paramAddr[10][18][1] = 45;
	paramAddr[10][19][0] = 48; paramAddr[10][19][1] = 48;
	paramAddr[10][20][0] = 108; paramAddr[10][20][1] = 107;
	paramAddr[10][21][0] = 85; paramAddr[10][21][1] = 85;
	paramAddr[10][22][0] = 59; paramAddr[10][22][1] = 59;
	paramAddr[10][23][0] = 60; paramAddr[10][23][1] = 60;
	paramAddr[10][24][0] = 62; paramAddr[10][24][1] = 62;
	paramAddr[10][25][0] = 78; paramAddr[10][25][1] = 77;
	paramAddr[10][26][0] = 80; paramAddr[10][26][1] = 79;
	paramAddr[10][27][0] = 82; paramAddr[10][27][1] = 81;
	paramAddr[10][28][0] = 84; paramAddr[10][28][1] = 83;
	paramAddr[10][29][0] = 90; paramAddr[10][29][1] = 89;
	paramAddr[10][30][0] = 110; paramAddr[10][30][1] = 109;

	paramCoef[10][1][2] = 4;
	paramCoef[10][2][2] = 4;
	paramCoef[10][3][2] = 4;
	paramCoef[10][4][1] = 3; paramCoef[10][4][2] = 4; paramCoef[10][4][3] = -48;
	paramCoef[10][5][1] = 3; paramCoef[10][5][2] = 4; paramCoef[10][5][3] = -48;
	paramCoef[10][6][1] = 3; paramCoef[10][6][2] = 4;

	paramCoef[10][8][2] = 10;
	paramCoef[10][9][2] = 10;

	paramCoef[10][13][1] = 0.02345;

	paramCoef[10][16][2] = 256; paramCoef[10][16][3] = 0.5;

	paramCoef[10][19][2] = 10;
	paramCoef[10][20][2] = 128;
	paramCoef[10][21][1] = 3; paramCoef[10][21][2] = 4;

	paramCoef[10][24][2] = 100;



	flags[10][0] = 116; flags[10][1] = 116; flags[10][2] = 255;

	timerName[10][1] = wxT("Загальний пробіг (км)");
	timerName[10][2] = wxT("Число циклів прогр.");
	timerName[10][3] = wxT("Ліч.перевищ.обер.<50т.км.");
	timerName[10][4] = wxT("Ліч.перевищ.обер.>50т.км.");
	timerName[10][5] = wxT("Ліч.перевищ.темп.<50т.км.");
	timerName[10][6] = wxT("Ліч.перевищ.темп.>50т.км.");
	timerName[10][7] = wxT("Ліч.перевищ.детон.<50т.км.");
	timerName[10][8] = wxT("Ліч.перевищ.детон.>50т.км.");
	timerName[10][9] = wxT("Ліч.невик.форсун.<50т.км.");
	timerName[10][10] = wxT("Ліч.невик.форсун.>50т.км.");
	timerName[10][11] = wxT("Ліч.перевищ.проп.восп.<50т.км.");
	timerName[10][12] = wxT("Ліч.перевищ.проп.восп.>50т.км.");
	timerName[10][13] = wxT("Ліч.перенапр.БС<50т.км.");
	timerName[10][14] = wxT("Ліч.перенапр.БС>50т.км.");
	timerName[10][15] = wxT("Запис серв.дан.акив.>200т.км.");
	timerAddr[10][1][0] = 4; timerAddr[10][1][1] = 1;
	timerAddr[10][2][0] = 7; timerAddr[10][2][1] = 7;
	timerAddr[10][3][0] = 9; timerAddr[10][3][1] = 8;
	timerAddr[10][4][0] = 11; timerAddr[10][4][1] = 10;
	timerAddr[10][5][0] = 13; timerAddr[10][5][1] = 12;
	timerAddr[10][6][0] = 15; timerAddr[10][6][1] = 14;
	timerAddr[10][7][0] = 17; timerAddr[10][7][1] = 16;
	timerAddr[10][8][0] = 19; timerAddr[10][8][1] = 18;
	timerAddr[10][9][0] = 21; timerAddr[10][9][1] = 20;
	timerAddr[10][10][0] = 23; timerAddr[10][10][1] = 22;
	timerAddr[10][11][0] = 25; timerAddr[10][11][1] = 24;
	timerAddr[10][12][0] = 27; timerAddr[10][12][1] = 26;
	timerAddr[10][13][0] = 29; timerAddr[10][13][1] = 28;
	timerAddr[10][14][0] = 31; timerAddr[10][14][1] = 30;
	timerAddr[10][15][0] = 32; timerAddr[10][15][1] = 32;
	timerAddr[10][0][0] = 15;

	//---------- МP 7.0(E2) (22)-----------------------------------------------------------
	paramName[11][1] = wxT("Оберти (об/хв)");
	paramName[11][2] = wxT("Бажані обер.ХХ(об/хв)");
	paramName[11][3] = wxT("Оберти на ХХ(об/хв)");
	paramName[11][4] = wxT("Температура ОР (°C)");
	paramName[11][5] = wxT("УОЗ (°пкв)"); paramCoef[11][5][4] = 1;
	paramName[11][6] = wxT("кор.УОЗ по детон.(°пкв)"); paramCoef[11][6][4] = 1;
	paramName[11][7] = wxT("Адапт.розх.пов..на ХХ");
	paramName[11][8] = wxT("Баж.розх.пов..на ХХ(к/ч)"); paramCoef[11][8][4] = 1;
	paramName[11][9] = wxT("Розхід повітря(кг/год)"); paramCoef[11][9][4] = 1;
	paramName[11][10] = wxT("Напруга ДМРВ(В)"); paramCoef[11][10][4] = 2;
	paramName[11][11] = wxT("Кор.розх.пов..на ХХ");
	paramName[11][12] = wxT("Положення ДЗ(%)"); paramCoef[11][12][4] = 1;
	paramName[11][13] = wxT("Час впорскування(мс)"); paramCoef[11][13][4] = 1;
	paramName[11][14] = wxT("Напруга ДК1 (В)"); paramCoef[11][14][4] = 2;
	paramName[11][15] = wxT("Напруга ДК2 (В)"); paramCoef[11][15][4] = 2;
	paramName[11][16] = wxT("Кор.впорскування по ДК"); paramCoef[11][16][4] = 1;
	paramName[11][17] = wxT("Рассогл.роботи ДК"); paramCoef[11][17][4] = 2;
	paramName[11][18] = wxT("Відкр.клап.адсор(%)"); paramCoef[11][18][4] = 1;
	paramName[11][19] = wxT("Положення РХХ");
	paramName[11][20] = wxT("Парам.нагруз.двиг."); paramCoef[11][20][4] = 2;
	paramName[11][21] = wxT("Напруга БС (В)"); paramCoef[11][21][4] = 1;
	paramName[11][22] = wxT("Швидкість (км/год)");

	paramAddr[11][0][0] = 22;
	paramAddr[11][0][1] = 72;
	paramAddr[11][1][0] = 16; paramAddr[11][1][1] = 16;
	paramAddr[11][2][0] = 23; paramAddr[11][2][1] = 23;
	paramAddr[11][3][0] = 20; paramAddr[11][3][1] = 20;
	paramAddr[11][4][0] = 11; paramAddr[11][4][1] = 11;
	paramAddr[11][5][0] = 12; paramAddr[11][5][1] = 12;
	paramAddr[11][6][0] = 13; paramAddr[11][6][1] = 13;
	paramAddr[11][7][0] = 22; paramAddr[11][7][1] = 22;
	paramAddr[11][8][0] = 24; paramAddr[11][8][1] = 24;
	paramAddr[11][9][0] = 25; paramAddr[11][9][1] = 25;
	paramAddr[11][10][0] = 8; paramAddr[11][10][1] = 8;
	paramAddr[11][11][0] = 21; paramAddr[11][11][1] = 21;
	paramAddr[11][12][0] = 14; paramAddr[11][12][1] = 14;
	paramAddr[11][13][0] = 18; paramAddr[11][13][1] = 17;
	paramAddr[11][14][0] = 26; paramAddr[11][14][1] = 26;
	paramAddr[11][15][0] = 34; paramAddr[11][15][1] = 34;
	paramAddr[11][16][0] = 27; paramAddr[11][16][1] = 27;
	paramAddr[11][17][0] = 35; paramAddr[11][17][1] = 35;
	paramAddr[11][18][0] = 30; paramAddr[11][18][1] = 30;
	paramAddr[11][19][0] = 19; paramAddr[11][19][1] = 19;
	paramAddr[11][20][0] = 9; paramAddr[11][20][1] = 9;
	paramAddr[11][21][0] = 10; paramAddr[11][21][1] = 10;
	paramAddr[11][22][0] = 15; paramAddr[11][22][1] = 15;

	paramCoef[11][1][1] = 40;
	paramCoef[11][2][1] = 10;
	paramCoef[11][3][1] = 10;
	paramCoef[11][4][1] = 3; paramCoef[11][4][2] = 4; paramCoef[11][4][3] = -48;
	paramCoef[11][5][1] = -3; paramCoef[11][5][2] = 4; paramCoef[11][5][3] = 108;
	paramCoef[11][6][1] = 3; paramCoef[11][6][2] = 4;
	paramCoef[11][7][3] = -128;
	paramCoef[11][8][2] = 4;
	paramCoef[11][9][2] = 4;
	paramCoef[11][10][2] = 512;
	paramCoef[11][12][1] = 100; paramCoef[11][12][2] = 256;
	paramCoef[11][13][1] = 9; paramCoef[11][13][2] = 375;
	paramCoef[11][14][1] = 0.00443;
	paramCoef[11][15][1] = 0.00443;
	paramCoef[11][16][2] = 128;
	paramCoef[11][17][2] = 256;
	paramCoef[11][18][1] = 100; paramCoef[11][18][2] = 256;
	paramCoef[11][20][2] = 20;
	paramCoef[11][21][1] = 0.0943;
	flags[11][0] = 32; flags[11][1] = 32; flags[11][2] = 1;


	//---------- МP 7.0(E3) (22)-----------------------------------------------------------
	for (int i = 1; i < 23; i++)
	{
		paramName[12][i] = paramName[11][i];
		paramCoef[12][i][0] = paramCoef[11][i][0];
		paramCoef[12][i][1] = paramCoef[11][i][1];
		paramCoef[12][i][2] = paramCoef[11][i][2];
		paramCoef[12][i][3] = paramCoef[11][i][3];
		paramCoef[12][i][4] = paramCoef[11][i][4];
		paramAddr[12][i][0] = paramAddr[11][i][0];
		paramAddr[12][i][1] = paramAddr[11][i][1];
	}
	flags[12][0] = 32; flags[12][1] = 32; flags[12][2] = 1;
	paramAddr[12][0][0] = 22;
	paramAddr[12][0][1] = 72;

	//---------- Lanos 1.5 SOCH (17)-----------------------------------------------------------
	paramName[13][1] = wxT("Температура ОР (°C)"); paramCoef[13][1][4] = 1;
	paramName[13][2] = wxT("Температура АТМ (°C)"); paramCoef[13][2][4] = 1;
	paramName[13][3] = wxT("Тиск в колл.(кП)"); paramCoef[13][3][4] = 2;
	paramName[13][4] = wxT("Положення ДЗ(%)"); paramCoef[13][4][4] = 1;
	paramName[13][5] = wxT("Оберти (об/хв)");
	paramName[13][6] = wxT("Напруга ДК1 (В)"); paramCoef[13][6][4] = 2;
	paramName[13][7] = wxT("Швидкість (км/год)");
	paramName[13][8] = wxT("Напруга БС (В)"); paramCoef[13][8][4] = 1;
	paramName[13][9] = wxT("УОЗ (°пкв)"); paramCoef[13][9][4] = 1;
	paramName[13][10] = wxT("Полож.РХХ Бажане");
	paramName[13][11] = wxT("Полож.РХХ реальне");
	paramName[13][12] = wxT("Баж.обер.ХХ(об/хв)");
	paramName[13][13] = wxT("Паливоподача (мс)"); paramCoef[13][13][4] = 2;
	paramName[13][14] = wxT("Пов./пал.(Бажане)"); paramCoef[13][14][4] = 1;
	paramName[13][15] = wxT("Навчальний множник");
	paramName[13][16] = wxT("Обуч.множник CELL");
	paramName[13][17] = wxT("Знач.інтегратора ОС");

	paramAddr[13][0][0] = 17;
	paramAddr[13][0][1] = 64;
	paramAddr[13][1][0] = 7; paramAddr[13][1][1] = 7;
	paramAddr[13][2][0] = 8; paramAddr[13][2][1] = 8;
	paramAddr[13][3][0] = 9; paramAddr[13][3][1] = 9;
	paramAddr[13][4][0] = 12; paramAddr[13][4][1] = 12;
	paramAddr[13][5][0] = 13; paramAddr[13][5][1] = 13;
	paramAddr[13][6][0] = 14; paramAddr[13][6][1] = 14;
	paramAddr[13][7][0] = 15; paramAddr[13][7][1] = 15;
	paramAddr[13][8][0] = 20; paramAddr[13][8][1] = 20;
	paramAddr[13][9][0] = 23; paramAddr[13][9][1] = 22;
	paramAddr[13][10][0] = 24; paramAddr[13][10][1] = 24;
	paramAddr[13][11][0] = 25; paramAddr[13][11][1] = 25;
	paramAddr[13][12][0] = 26; paramAddr[13][12][1] = 26;
	paramAddr[13][13][0] = 38; paramAddr[13][13][1] = 37;
	paramAddr[13][14][0] = 39; paramAddr[13][14][1] = 39;
	paramAddr[13][15][0] = 40; paramAddr[13][15][1] = 40;
	paramAddr[13][16][0] = 41; paramAddr[13][16][1] = 41;
	paramAddr[13][17][0] = 42; paramAddr[13][17][1] = 42;

	paramCoef[13][1][1] = 3; paramCoef[13][1][2] = 4; paramCoef[13][1][3] = -40;
	paramCoef[13][2][1] = 3; paramCoef[13][2][2] = 4; paramCoef[13][2][3] = -40;
	paramCoef[13][3][1] = 0.37; paramCoef[13][3][3] = 10.34;
	paramCoef[13][4][1] = 100; paramCoef[13][4][2] = 255;
	paramCoef[13][5][1] = 25;
	paramCoef[13][6][1] = 4.34;
	paramCoef[13][7][1] = 1.086464;
	paramCoef[13][8][2] = 10;
	paramCoef[13][9][2] = 2.83329;
	paramCoef[13][12][1] = 6.25;
	paramCoef[13][13][1] = 500; paramCoef[13][13][2] = 65535;
	paramCoef[13][14][2] = 10;

	flags[13][0] = 3; flags[13][1] = 6; flags[13][2] = 255;

	//---------- Lanos 1.6 DOCH (23)-----------------------------------------------------------
	paramName[14][1] = wxT("Температура ОР (°C)"); paramCoef[14][1][4] = 1;
	paramName[14][2] = wxT("Температура АТМ (°C)"); paramCoef[14][2][4] = 1;
	paramName[14][3] = wxT("Тиск в колл.(кП)"); paramCoef[14][3][4] = 2;
	paramName[14][4] = wxT("Абс.тиск(кП)"); paramCoef[14][4][4] = 2;
	paramName[14][5] = wxT("Положення ДЗ(%)"); paramCoef[14][5][4] = 1;
	paramName[14][6] = wxT("Оберти (об/хв)");
	paramName[14][7] = wxT("Напруга ДК1 (мВ)");
	paramName[14][8] = wxT("Швидкість (км/год)");
	paramName[14][9] = wxT("A/C тиск (кП)");
	paramName[14][10] = wxT("Time ref.");
	paramName[14][11] = wxT("Charge temperature"); paramCoef[14][11][4] = 1;
	paramName[14][17] = wxT("Напруга БС (В)"); paramCoef[14][17][4] = 1;
	paramName[14][13] = wxT("Напруга СО (В)"); paramCoef[14][13][4] = 2;
	paramName[14][20] = wxT("УОЗ (°пкв)"); paramCoef[14][20][4] = 1;
	paramName[14][15] = wxT("Полож.РХХ бажане");
	paramName[14][16] = wxT("Полож.РХХ реальне");
	paramName[14][12] = wxT("Баж.обер.ХХ(об/хв)");
	paramName[14][18] = wxT("Розхід пального(г/с)");
	paramName[14][19] = wxT("Паливоподача (мс)"); paramCoef[14][19][4] = 2;
	paramName[14][14] = wxT("Пов./пал.(Бажане)"); paramCoef[14][14][4] = 1;
	paramName[14][21] = wxT("Навчальний множник");
	paramName[14][22] = wxT("Номер комірки BLM");
	paramName[14][23] = wxT("Знач.інтегратора ОС");
	paramName[14][24] = wxT("Октанове число");
	paramName[14][25] = wxT("Навчання дозволено");
	paramName[14][26] = wxT("Суміш Богат./Бідн.");
	paramName[14][27] = wxT("Пал.Насос Вкл/Викл");
	paramName[14][28] = wxT("Солен.Конд.Вкл/Викл");
	paramName[14][29] = wxT("Холостий хід");
	paramName[14][30] = wxT("Дроссель закритий");



	paramAddr[14][0][0] = 30;
	paramAddr[14][0][1] = 64;
	paramAddr[14][1][0] = 9; paramAddr[14][1][1] = 9;
	paramAddr[14][2][0] = 10; paramAddr[14][2][1] = 10;
	paramAddr[14][3][0] = 11; paramAddr[14][3][1] = 11;
	paramAddr[14][4][0] = 12; paramAddr[14][4][1] = 12;
	paramAddr[14][5][0] = 13; paramAddr[14][5][1] = 13;
	paramAddr[14][6][0] = 14; paramAddr[14][6][1] = 14;
	paramAddr[14][7][0] = 15; paramAddr[14][7][1] = 15;
	paramAddr[14][8][0] = 17; paramAddr[14][8][1] = 16;
	paramAddr[14][9][0] = 18; paramAddr[14][9][1] = 18;
	paramAddr[14][10][0] = 19; paramAddr[14][10][1] = 19;
	paramAddr[14][11][0] = 20; paramAddr[14][11][1] = 20;
	paramAddr[14][17][0] = 21; paramAddr[14][17][1] = 21;
	paramAddr[14][13][0] = 22; paramAddr[14][13][1] = 22;
	paramAddr[14][20][0] = 24; paramAddr[14][20][1] = 23;
	paramAddr[14][15][0] = 25; paramAddr[14][15][1] = 25;
	paramAddr[14][16][0] = 26; paramAddr[14][16][1] = 26;
	paramAddr[14][12][0] = 27; paramAddr[14][12][1] = 27;
	paramAddr[14][18][0] = 35; paramAddr[14][18][1] = 34;
	paramAddr[14][19][0] = 38; paramAddr[14][19][1] = 37;
	paramAddr[14][14][0] = 39; paramAddr[14][14][1] = 39;
	paramAddr[14][21][0] = 40; paramAddr[14][21][1] = 40;
	paramAddr[14][22][0] = 41; paramAddr[14][22][1] = 41;
	paramAddr[14][23][0] = 42; paramAddr[14][23][1] = 42;
	paramAddr[14][24][0] = 60; paramAddr[14][24][1] = 60;
	paramAddr[14][25][0] = 53; paramAddr[14][25][1] = 53;
	paramAddr[14][26][0] = 53; paramAddr[14][26][1] = 53;
	paramAddr[14][27][0] = 52; paramAddr[14][27][1] = 52;
	paramAddr[14][28][0] = 48; paramAddr[14][28][1] = 48;
	paramAddr[14][29][0] = 56; paramAddr[14][29][1] = 56;
	paramAddr[14][30][0] = 52; paramAddr[14][30][1] = 52;

	paramCoef[14][1][1] = 3; paramCoef[14][1][2] = 4; paramCoef[14][1][3] = -40;
	paramCoef[14][2][1] = 3; paramCoef[14][2][2] = 4; paramCoef[14][2][3] = -40;
	paramCoef[14][3][1] = 0.37; paramCoef[14][3][3] = 10.34;
	paramCoef[14][4][1] = 0.37; paramCoef[14][4][3] = 10.34;
	paramCoef[14][5][1] = 0.49504; paramCoef[14][5][3] = -14.85;
	paramCoef[14][6][1] = 25;
	paramCoef[14][7][1] = 4.43;
	paramCoef[14][8][1] = 0.004244;
	paramCoef[14][9][1] = 12.82051; paramCoef[14][9][3] = -128.205;
	paramCoef[14][10][1] = 30.90625;
	paramCoef[14][11][1] = 3; paramCoef[14][11][2] = 4; paramCoef[14][11][3] = -40;
	paramCoef[14][17][2] = 10;
	paramCoef[14][13][1] = 5; paramCoef[14][13][2] = 255;
	paramCoef[14][20][1] = 0.351562;
	paramCoef[14][12][1] = 12.5;
	paramCoef[14][19][1] = 500; paramCoef[14][19][2] = 65535;
	paramCoef[14][14][2] = 10;
	paramCoef[14][24][2] = 160;
	paramCoef[14][25][2] = 8;
	paramCoef[14][26][2] = 64;
	paramCoef[14][27][2] = 4;
	paramCoef[14][28][2] = 16;
	paramCoef[14][29][2] = 4;
	paramCoef[14][30][2] = 1;
	resetError = FALSE;

	flags[14][0] = 3; flags[14][1] = 8; flags[14][2] = 255;
	wxFile* datFile = new wxFile;
	if(datFile->Exists("sensdiag.dat"))
	{
		printf("File exist.\n");
		datFile->Open("sensdiag.dat");
		if( datFile->IsOpened() )
		{
			datBuf = new char;
			for( int i = 0 ; i < 16 ; i++ )
			{
				for( int j = 1 ; j < 17 ; j++ )
				{
					if( i < 1 )
					{
						if( j == 1)
						{
							datFile->Read(datBuf, 1);
							carType = (int)datBuf[0];
						}
						else
						{
							if( j == 15)
							{
								datFile->Read(datBuf, 1);
								adapter = (int)datBuf[0];
							}
							else
							{
								if( j == 16)
								{
									datFile->Read(datBuf, 1);
									ioPort = (int)datBuf[0];
								}
								else
								{
									datFile->Read(datBuf, 1);
									dataGraph[j - 1] = (int)datBuf[0];
								}
							}
						}
					}
					else
					{
						datFile->Read(datBuf, 1);
						dataSet[i][j] = (int)datBuf[0];
					}
				}
			}
			datFile->Close();
			delete datFile;
			delete datBuf;
		}
	}
	else
	{
		wxMessageBox("File - sensdiag.dat not exist!");
		Destroy();
	}
	m_comboBoxSelectEBC->SetSelection(carType);
	m_comboBoxSelectPort->SetSelection(ioPort);
	if(adapter) m_checkBoxAdapter->SetValue(TRUE);
	else m_checkBoxAdapter->SetValue(false);
	LoadEBC();
	if( carType == 0 )
	{
		wxMessageDialog* dlg = new wxMessageDialog(NULL, wxT("Деякі блоки автоматично не визначаються.\nЯкщо ви знаєте тип ЕБК, виберіть його вручну."), wxT("Message."), wxOK);
		dlg->ShowModal();
	}
	timerPeriod = 200;
	sysTimerPeriod = 500;
	ScanPort();
	outData = new char[512];
	inData = new char[512];
	inDataCount = 0;
	outDataCount = 0;
	dataOkCount = 0;
	dataOk = FALSE;
	uprVar = 0;
	uprZap = FALSE;
	uprData = 0;
	uprSend = FALSE;
	resetError = FALSE;
	uprClose = FALSE;
	idZapros = 0;
	inStr = "";
	init = FALSE;
	m_statusBar->SetStatusText(_("EBC: ") + m_comboBoxSelectEBC->GetValue(), 0);
	m_statusBar->SetStatusText(_("Port: ") + m_comboBoxSelectPort->GetValue(), 1);
}

void MyFrame::OnClose( wxCloseEvent& event )
{
	// wxMessageDialog* dlg = new wxMessageDialog(NULL,wxT("Are you sure?"),_("Question."),wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION);
	// int ret = dlg->ShowModal();
	// if(ret == wxID_YES)
	// {
	SaveSetting();
	Destroy();
	// }
	// else
	// 	event.Veto();
}

void MyFrame::OnStart( wxCommandEvent& event )
{
	int check = 0;
	// MyPort serialPort;
	if( m_buttonStart->GetLabel() == wxT("Start") )
	{
		wxString portName = m_comboBoxSelectPort->GetValue();
		if( adapter > 0 )
		{
			check = serialPort.Open(portName, 1115000);
			init = TRUE;
		}
		else
		{
			if( carType > 12 )
			{
				check = serialPort.Open(portName, 8192);
				init = TRUE;
				timerPeriod = 200;
			}
			else
			{
				check = serialPort.Open(portName, 10400);
				init = TRUE;
				timerPeriod = 200;
				// timerPeriod = 50;
			}
		}
		if( check < 0 )
		{
			wxMessageDialog* dlg = new wxMessageDialog(NULL, wxT("Port busy or not present.\nPlease select enother port."), wxT("Message."), wxOK);
			dlg->ShowModal();
			return;
		}
		m_buttonStart->SetLabel(wxT("Stop"));
		m_menuItemFileStart->SetItemLabel(wxT("Stop"));
		m_timerWork.Start(timerPeriod, wxTIMER_ONE_SHOT);
		m_comboBoxSelectEBC->Disable();
		m_comboBoxSelectPort->Disable();
		m_buttonScanPort->Disable();
		m_checkBoxAdapter->Disable();
		m_checkBoxLog->Disable();
		if( m_comboBoxControl->GetSelection() != 0 && m_notebook2->GetSelection() == 0 )
		{
			m_buttonControlPlus->Enable();
			m_buttonControlMinus->Enable();
		}
		else
		{
			m_buttonControlPlus->Disable();
			m_buttonControlMinus->Disable();
		}
	}
	else
	{
		m_buttonStart->SetLabel(wxT("Start"));
		m_menuItemFileStart->SetItemLabel(wxT("Start"));
		m_timerWork.Stop();
		m_comboBoxSelectEBC->Enable();
		m_comboBoxSelectPort->Enable();
		m_buttonScanPort->Enable();
		m_checkBoxAdapter->Enable();
		m_checkBoxLog->Enable();
		serialPort.Close();
		m_buttonControlPlus->Disable();
		m_buttonControlMinus->Disable();
	}
}

void MyFrame::OnExit( wxCommandEvent& event )
{
	Close();
}

void MyFrame::OnSaveLog( wxCommandEvent& event )
{
	wxFileDialog* dlg = new wxFileDialog(this, wxT("Save log"), wxT("File"), 
			wxT(""), wxT("*.*"), wxFD_SAVE);
	dlg->ShowModal();
}

void MyFrame::OnAbout( wxCommandEvent& event )
{
	wxMessageDialog* dlg = new wxMessageDialog(NULL, wxT("Programm for testing EBC vehicle.\nBy Vovan."), _("About."), wxOK);
	dlg->ShowModal();
}

void MyFrame::OnPageChange( wxNotebookEvent& event )
{
	if( m_comboBoxControl->GetSelection() != 0 && m_notebook2->GetSelection() == 0 && serialPort.IsOpen() )
	{
		m_buttonControlPlus->Enable();
		m_buttonControlMinus->Enable();
	}
	else
	{
		m_buttonControlPlus->Disable();
		m_buttonControlMinus->Disable();
	}
}

void MyFrame::OnResetError( wxCommandEvent& event )
{
	m_textCtrlErrors->SetValue(_("No Errors."));
	resetError = TRUE;
}

void MyFrame::OnComboboxSelectControl( wxCommandEvent& event )
{
	if( m_comboBoxControl->GetSelection() != 0 && m_notebook2->GetSelection() == 0 && serialPort.IsOpen() )
	{
		m_buttonControlPlus->Enable();
		m_buttonControlMinus->Enable();
	}
	else
	{
		m_buttonControlPlus->Disable();
		m_buttonControlMinus->Disable();
	}
}

void MyFrame::OnClickControlPlus( wxCommandEvent& event )
{
	// TODO: Implement OnClickControlPlus
}

void MyFrame::OnClickContolMinus( wxCommandEvent& event )
{
	// TODO: Implement OnClickContolMinus
}

void MyFrame::OnSelectEBC( wxCommandEvent& event )
{
	carType = m_comboBoxSelectEBC->GetSelection();
	m_statusBar->SetStatusText(_("EBC: ") + m_comboBoxSelectEBC->GetValue(), 0);
	LoadEBC();
}

void MyFrame::OnSelectPort( wxCommandEvent& event )
{
	ioPort = m_comboBoxSelectPort->GetSelection();
	m_statusBar->SetStatusText(_("Port: ") + m_comboBoxSelectPort->GetValue(), 1);
}

void MyFrame::OnScanPort( wxCommandEvent& event )
{
	ScanPort();
}

void MyFrame::OnCheckAdapter( wxCommandEvent& event )
{
	if(m_checkBoxAdapter->IsChecked()) adapter = TRUE;
	else adapter = FALSE;
	SaveSetting();
}

void MyFrame::OnCheckLogProtocol( wxCommandEvent& event )
{
	SaveSetting();
}

void MyFrame::OnTimerTick( wxTimerEvent& event )
{
	if( m_checkBoxLog->IsChecked() )
	{
		logFile = new wxTextFile(wxT("log.txt"));
		if( logFile->Exists() )
			logFile->Open();
		else logFile->Create();
	}
	int inDB = 0;
	if( serialPort.IsOpen() == TRUE )
	{
           /* Read serial port and check crc */
		int cb = 0;
		unsigned char b = 0;
		cb = serialPort.BytesToRead();
		if( cb > 0 ) /* if receive data */
		{
			for( int i = 0 ; i < cb ; i++ )
			{
				inData[inDataCount] = (char)serialPort.ReadByte();
				if( !(inDataCount == 0 && inData[inDataCount] != outData[0] ))
				{
					inStr += wxString::Format("0x%02X", (unsigned char)inData[inDataCount]);
					inStr += " ";
					inDataCount++;
					if( carType > 12 )
					{
						if( inDataCount > (outDataCount + 1) )
						{
							b = (unsigned char)(inData[outDataCount + 1] - 85);
							if( (inDataCount - outDataCount) == (b + 3) )
							{
								dataOk = TRUE;
							}
						}
					}
					else
					{
						if( inDataCount > outDataCount )
						{
							b = inData[outDataCount];
							b -= 0x80;
							if(b == 0)
								b = (unsigned char)(inData[outDataCount + 3] + 1);
							if( (inDataCount - outDataCount) == (b + 4))
							{
								b = 0;
								for( int j = outDataCount ; j < (inDataCount - 1) ; j++ )
								{
									b += (unsigned char)inData[j];
								}
								if(b == inData[inDataCount - 1]) /* Check CRC */
									dataOk = TRUE;
							}
						}
					}
				}
			}
		}
		if( m_timerWork.GetInterval() == 200 )
		{
			if( m_checkBoxLog->IsChecked() && logFile->IsOpened() )
			{
				// logFile->Open();
				logFile->AddLine(inStr);
				logFile->Write();
				logFile->Close();
				inStr.Clear();
			}
			if( dataOk == TRUE && outDataCount > 0 )
			{
				printf("Data ok\n");
				init = FALSE;
				dataOk = FALSE;
				if( carType > 12 )
				{
					//TODO
				}
				else
				{
					unsigned char b = (unsigned char)inData[outDataCount];
					b -= 0x80;
					if( b == 0)
						b = (unsigned char)inData[outDataCount + 3];
					inDB = inDataCount - 1 - b;
					if( carType == 0 && inData[inDB] != 0x7F )
					{
						for( int i = 1 ; i < 13 ; i++ )
						{
							if(paramAddr[i][0][1] == (inDataCount - outDataCount))
								carType = i;
						}
						if( carType == 0 )
						{
							wxString str;
							str.Printf("%i", (inDataCount - outDataCount));
							wxMessageBox("Ваш ЕБК не впізнано, виберіть тип вручну. Код - " + 
									str);
						}
						else
						{
							LoadEBC();
							wxString En = "";
							switch ( carType )
							{
								case 1 : En = "M1.5.4 or Januery5"; break;
								case 2 : En = "M1.5.4(N) or Januery5(E2)"; break;
								case 3 : En = "Mikas 10,3"; break;
								case 4 : En = "Mikas 7.6"; break;
								case 5 : En = "Mikas 11(E2)"; break;
								case 6 : En = "Mikas 11(E3)"; break;
								case 7 : En = "M7.9.7(E2)"; break;
								case 8 : En = "M7.9.7(E3)"; break;
								case 9 : En = "Januery 7.X"; break;
								case 10 : En = "ME1 7.9.7"; break;
								case 11 : En = "MP 7.0 (E2)"; break;
								case 12 : En = "MP 7.0 (E3)"; break;
							}
						wxMessageBox("Ваш ЕБК розпізнано як: " + En);
						}
					}
					else
					{
						if( m_notebook2->GetSelection() == 1 ) /* Page 1 */
						{
							int errCount = inData[inDB + 1];
							inDB += 2;
							int errCode = 0;
							wxString Error = _("Невідома помилка.");
							bool errEnable = FALSE;
							if( errCount > 0 )
							{
								m_textCtrlErrors->Clear();
								for( int i = 0 ; i < errCount ; i++ )
								{
									errCode = (inData[inDB + i * 3] & 0xFF) << 8;
									errCode |= inData[inDB + i * 3 + 1] & 0xFF;
									switch(errCode)
									{
										case 0x0030: Error = _("Неисправность цепи нагревателя датчика кислорода № 1"); break;
										case 0x0031: Error = _("Обрыв или замыкание на Массу цепи  нагревателя датчика кислорода № 1"); break;
										case 0x0032: Error = _("Короткое замыкание на Бортсеть цепи нагревателя датчика кислорода № 1"); break;
										case 0x0036: Error = _("Неисправность цепи нагревателя датчика кислорода № 2"); break;
										case 0x0037: Error = _("Обрыв или замыкание на Массу цепи нагревателя датчика кислорода № 2"); break;
										case 0x0038: Error = _("Короткое замыкание на Бортсеть цепи нагревателя датчика кислорода № 2"); break;
										case 0x0100: Error = _("Низкий или высокий уровень сигнала с датчика расхода воздуха."); break;
										case 0x0101: Error = _("Выход сигнала датчика массового расхода воздуха за допустимый диапазон"); break;
										case 0x0102: Error = _("Низкий уровень сигнала датчика массового расхода воздуха (ДМРВ)"); break;
										case 0x0103: Error = _("Высокий уровень сигнала датчика массового расхода воздуха (ДМРВ)"); break;
										case 0x0104: Error = _("Mass or Volume Air Flow Circuit Intermittent "); break;
										case 0x0105: Error = _("Некорректный сигнал в цепи датчика абсолютного давления воздуха"); break;
										case 0x0106: Error = _("Выход сигнала датчика абсолютного давления воздуха за допустимый диапазон"); break;
										case 0x0107: Error = _("Низкий уровень сигнала цепи датчика абсолютного давления воздуха"); break;
										case 0x0108: Error = _("Высокий уровень сигнала цепи датчика абсолютного давления воздуха"); break;
										case 0x0109: Error = _("Manifold Absolute Pressure/Barometric Pressure Circuit Intermittent "); break;
										case 0x0110: Error = _("Низкий или высокий уровень сигнала с датчика температуры воздуха."); break;
										case 0x0111: Error = _("Intake Air Temperature Circuit Range/Performance Problem "); break;
										case 0x0112: Error = _("Низкий уровень сигнала датчика температуры впускного коллектора (ДТВ)"); break;
										case 0x0113: Error = _("Высокий уровень сигнала датчика температуры впускного коллектора (ДТВ)"); break;
										case 0x0114: Error = _("Intake Air Temperature Circuit Intermittent "); break;
										case 0x0115: Error = _("Выход сигнала датчика температуры охлаждающей жидкости (ДТОЖ) за допустимый диапазон"); break;
										case 0x0116: Error = _("Выход сигнала датчика температуры охлаждающей жидкости (ДТОЖ) за допустимый диапазон"); break;
										case 0x0117: Error = _("Низкий уровень сигнала датчика температуры охлаждающей жидкости (ДТОЖ)"); break;
										case 0x0118: Error = _("Высокий уровень сигнала датчика температуры охлаждающей жидкости (ДТОЖ)"); break;
										case 0x0119: Error = _("Engine Coolant Temperature Circuit Intermittent "); break;
										case 0x0120: Error = _("Низкий или высокий уровень сигнала с датчика положения дросселя."); break;
										case 0x0121: Error = _("Некорректный сигнал датчика № 1 положения дроссельной заслонки"); break;
										case 0x0122: Error = _("Низкий уровень сигнала датчика положения дроссельной заслонки (ДПДЗ)"); break;
										case 0x0123: Error = _("Высокий уровень сигнала датчика положения дроссельной заслонки (ДПДЗ)"); break;
										case 0x0124: Error = _("Throttle Position Sensor/Switch A Circuit Intermittent "); break;
										case 0x0125: Error = _("Insufficient Coolant Temperature for Closed Loop Fuel Control; ECT Excessive Time to Closed Loop Fuel Control"); break;
										case 0x0126: Error = _("Insufficient Coolant Temperature for Stable Operation "); break;
										case 0x0128: Error = _("Coolant Thermostat Malfunction "); break;
										case 0x0129: Error = _("Barometric Pressure Too Low "); break;
										case 0x0130: Error = _("Неисправность сигнальной цепи или потеря активности датчика кислорода № 1 (до нейтрализатора)"); break;
										case 0x0131: Error = _("Низкий уровень сигнал датчика кислорода № 1 (до нейтрализатора)"); break;
										case 0x0132: Error = _("Высокий уровень сигнала датчика кислорода № 1 (до нейтрализатора)"); break;
										case 0x0133: Error = _("Медленный отклик датчика кислорода № 1 (до нейтрализатора) на изменение состава смеси"); break;
										case 0x0134: Error = _("Потеря активности или обрыв цепи датчика кислорода № 1 (до нейтрализатора)"); break;
										case 0x0135: Error = _("Неисправность цепи нагревателя датчика кислорода № 1 (до нейтрализатора)"); break;
										case 0x0136: Error = _("Неисправность или замыкание на массу сигнальной цепи датчика кислорода № 2 (после нейтрализатора)"); break;
										case 0x0137: Error = _("Низкий уровень сигнала датчика кислорода № 2 (после нейтрализатора)"); break;
										case 0x0138: Error = _("Высокий уровень сигнала датчика кислорода № 2 (после нейтрализатора)"); break;
										case 0x0139: Error = _("Медленный отклик датчика кислорода № 2 (после нейтрализатора) на изменение состава смеси"); break;
										case 0x0140: Error = _("Потеря активности или обрыв цепи датчика кислорода № 2 (после нейтрализатора)"); break;
										case 0x0141: Error = _("Неисправность нагревателя датчика кислорода № 2 (после нейтрализатора)"); break;
										case 0x0142: Error = _("O2 Sensor Circuit Malfunction (Bank 1 Sensor 3) "); break;
										case 0x0143: Error = _("O2 Sensor Circuit Low Voltage (Bank 1 Sensor 3) "); break;
										case 0x0144: Error = _("O2 Sensor Circuit High Voltage (Bank 1 Sensor 3) "); break;
										case 0x0145: Error = _("O2 Sensor Circuit Slow Response (Bank 1 Sensor 3) "); break;
										case 0x0146: Error = _("O2 Sensor Circuit No Activity Detected (Bank 1 Sensor 3) "); break;
										case 0x0147: Error = _("O2 Sensor Heater Circuit Malfunction (Bank 1 Sensor 3) "); break;
										case 0x0150: Error = _("O2 Sensor Circuit Malfunction (Bank 2 Sensor 1) "); break;
										case 0x0151: Error = _("O2 Sensor Circuit Low Voltage (Bank 2 Sensor 1) "); break;
										case 0x0152: Error = _("O2 Sensor Circuit High Voltage (Bank 2 Sensor 1) "); break;
										case 0x0153: Error = _("O2 Sensor Circuit Slow Response (Bank 2 Sensor 1) "); break;
										case 0x0154: Error = _("O2 Sensor Circuit No Activity Detected (Bank 2 Sensor 1) "); break;
										case 0x0155: Error = _("O2 Sensor Heater Circuit Malfunction (Bank 2 Sensor 1) "); break;
										case 0x0156: Error = _("O2 Sensor Circuit Malfunction (Bank 2 Sensor 2) "); break;
										case 0x0157: Error = _("O2 Sensor Circuit Low Voltage (Bank 2 Sensor 2) "); break;
										case 0x0158: Error = _("O2 Sensor Circuit High Voltage (Bank 2 Sensor 2) "); break;
										case 0x0159: Error = _("O2 Sensor Circuit Slow Response (Bank 2 Sensor 2) "); break;
										case 0x0160: Error = _("O2 Sensor Circuit No Activity Detected (Bank 2 Sensor 2) "); break;
										case 0x0161: Error = _("O2 Sensor Heater Circuit Malfunction (Bank 2 Sensor 2) "); break;
										case 0x0162: Error = _("O2 Sensor Circuit Malfunction (Bank 2 Sensor 3) "); break;
										case 0x0163: Error = _("O2 Sensor Circuit Low Voltage (Bank 2 Sensor 3) "); break;
										case 0x0164: Error = _("O2 Sensor Circuit High Voltage (Bank 2 Sensor 3) "); break;
										case 0x0165: Error = _("O2 Sensor Circuit Slow Response (Bank 2 Sensor 3) "); break;
										case 0x0166: Error = _("O2 Sensor Circuit No Activity Detected (Bank 2 Sensor 3) "); break;
										case 0x0167: Error = _("O2 Sensor Heater Circuit Malfunction (Bank 2 Sensor 3) "); break;
										case 0x0170: Error = _("Fuel Trim Malfunction (Bank 1) "); break;
										case 0x0171: Error = _("Система топливоподачи слишком бедная при ее максимальном обогащении"); break;
										case 0x0172: Error = _("Система топливоподачи слишком богатая при ее максимальном обеднении"); break;
										case 0x0173: Error = _("Fuel Trim Malfunction (Bank 2) "); break;
										case 0x0174: Error = _("Fuel Trim too Lean (Bank 2) "); break;
										case 0x0175: Error = _("Fuel Trim too Rich (Bank 2) "); break;
										case 0x0176: Error = _("Fuel Composition Sensor Circuit Malfunction "); break;
										case 0x0177: Error = _("Fuel Composition Sensor Circuit Range/Performance "); break;
										case 0x0178: Error = _("Fuel Composition Sensor Circuit Low Input "); break;
										case 0x0179: Error = _("Fuel Composition Sensor Circuit High Input "); break;
										case 0x0180: Error = _("Fuel Temperature Sensor A Circuit Malfunction "); break;
										case 0x0181: Error = _("Fuel Temperature Sensor A Circuit Range/Performance "); break;
										case 0x0182: Error = _("Fuel Temperature Sensor A Circuit Low Input "); break;
										case 0x0183: Error = _("Fuel Temperature Sensor A Circuit High Input "); break;
										case 0x0184: Error = _("Fuel Temperature Sensor A Circuit Intermittent "); break;
										case 0x0185: Error = _("Fuel Temperature Sensor B Circuit Malfunction "); break;
										case 0x0186: Error = _("Fuel Temperature Sensor B Circuit Range/Performance "); break;
										case 0x0187: Error = _("Fuel Temperature Sensor B Circuit Low Input "); break;
										case 0x0188: Error = _("Fuel Temperature Sensor B Circuit High Input "); break;
										case 0x0189: Error = _("Fuel Temperature Sensor B Circuit Intermittent "); break;
										case 0x0190: Error = _("Fuel Rail Pressure Sensor Circuit Malfunction "); break;
										case 0x0191: Error = _("Fuel Rail Pressure Sensor Circuit Range/Performance "); break;
										case 0x0192: Error = _("Fuel Rail Pressure Sensor Circuit Low Input "); break;
										case 0x0193: Error = _("Fuel Rail Pressure Sensor Circuit High Input "); break;
										case 0x0194: Error = _("Fuel Rail Pressure Sensor Circuit Intermittent "); break;
										case 0x0195: Error = _("Engine Oil Temperature Sensor Malfunction "); break;
										case 0x0196: Error = _("Engine Oil Temperature Sensor Range/Performance "); break;
										case 0x0197: Error = _("Engine Oil Temperature Sensor Low "); break;
										case 0x0198: Error = _("Engine Oil Temperature Sensor High "); break;
										case 0x0199: Error = _("Engine Oil Temperature Sensor Intermittent "); break;
										case 0x0200: Error = _("Цепь управления форсунками неисправна"); break;
										case 0x0201: Error = _("Неисправность или обрыв цепи управления форсункой 1"); break;
										case 0x0202: Error = _("Неисправность или обрыв цепи управления форсункой 2"); break;
										case 0x0203: Error = _("Неисправность или обрыв цепи управления форсункой 3"); break;
										case 0x0204: Error = _("Неисправность или обрыв цепи управления форсункой 4"); break;
										case 0x0205: Error = _("Injector Circuit Malfunction - Cylinder 5 "); break;
										case 0x0206: Error = _("Injector Circuit Malfunction - Cylinder 6 "); break;
										case 0x0207: Error = _("Injector Circuit Malfunction - Cylinder 7 "); break;
										case 0x0208: Error = _("Injector Circuit Malfunction - Cylinder 8 "); break;
										case 0x0209: Error = _("Injector Circuit Malfunction - Cylinder 9 "); break;
										case 0x0210: Error = _("Injector Circuit Malfunction - Cylinder 10 "); break;
										case 0x0211: Error = _("Injector Circuit Malfunction - Cylinder 11 "); break;
										case 0x0212: Error = _("Injector Circuit Malfunction - Cylinder 12 "); break;
										case 0x0213: Error = _("Cold Start Injector 1 Malfunction "); break;
										case 0x0214: Error = _("Cold Start Injector 2 Malfunction "); break;
										case 0x0215: Error = _("Engine Shutoff Solenoid Malfunction "); break;
										case 0x0216: Error = _("Injection Timing Control Circuit Malfunction "); break;
										case 0x0217: Error = _("Перегрев системы охлаждения двигателя"); break;
										case 0x0218: Error = _("Transmission Over Temperature Condition "); break;
										case 0x0219: Error = _("Превышение допустимой частоты вращения двигателя"); break;
										case 0x0220: Error = _("Throttle/Petal Position Sensor/Switch B Circuit Malfunction "); break;
										case 0x0221: Error = _("Throttle/Petal Position Sensor/Switch B Circuit Range/Performance Problem "); break;
										case 0x0222: Error = _("Низкий уровень сигнала цепи датчика № 2 положения дроссельной заслонки"); break;
										case 0x0223: Error = _("Высокий уровень сигнала цепи датчика № 2 положения дроссельной заслонки"); break;
										case 0x0224: Error = _("Throttle/Petal Position Sensor/Switch B Circuit Intermittent "); break;
										case 0x0225: Error = _("Throttle/Petal Position Sensor/Switch C Circuit Malfunction "); break;
										case 0x0226: Error = _("Throttle/Petal Position Sensor/Switch C Circuit Range/Performance Problem "); break;
										case 0x0227: Error = _("Throttle/Petal Position Sensor/Switch C Circuit Low Input "); break;
										case 0x0228: Error = _("Throttle/Petal Position Sensor/Switch C Circuit High Input "); break;
										case 0x0229: Error = _("Throttle/Petal Position Sensor/Switch C Circuit Intermittent "); break;
										case 0x0230: Error = _("Неисправность цепи управления реле электробензонасоса"); break;
										case 0x0231: Error = _("Fuel Pump Secondary Circuit Low "); break;
										case 0x0232: Error = _("Fuel Pump Secondary Circuit High "); break;
										case 0x0233: Error = _("Fuel Pump Secondary Circuit Intermittent "); break;
										case 0x0234: Error = _("Engine Overboost Condition "); break;
										case 0x0235: Error = _("Turbocharger Boost Sensor A Circuit Malfunction "); break;
										case 0x0236: Error = _("Turbocharger Boost Sensor A Circuit Range/Performance "); break;
										case 0x0237: Error = _("Turbocharger Boost Sensor A Circuit Low "); break;
										case 0x0238: Error = _("Turbocharger Boost Sensor A Circuit High "); break;
										case 0x0239: Error = _("Turbocharger Boost Sensor B Malfunction "); break;
										case 0x0240: Error = _("Turbocharger Boost Sensor B Circuit Range/Performance "); break;
										case 0x0241: Error = _("Turbocharger Boost Sensor B Circuit Low "); break;
										case 0x0242: Error = _("Turbocharger Boost Sensor B Circuit High "); break;
										case 0x0243: Error = _("Turbocharger Wastegate Solenoid A Malfunction "); break;
										case 0x0244: Error = _("Turbocharger Wastegate Solenoid A Range/Performance "); break;
										case 0x0245: Error = _("Turbocharger Wastegate Solenoid A Low "); break;
										case 0x0246: Error = _("Turbocharger Wastegate Solenoid A High "); break;
										case 0x0247: Error = _("Turbocharger Wastegate Solenoid B Malfunction "); break;
										case 0x0248: Error = _("Turbocharger Wastegate Solenoid B Range/Performance "); break;
										case 0x0249: Error = _("Turbocharger Wastegate Solenoid B Low "); break;
										case 0x0250: Error = _("Turbocharger Wastegate Solenoid B High "); break;
										case 0x0251: Error = _("Injection Pump Fuel Metering Control A Malfunction (Cam/Rotor/Injector)"); break;
										case 0x0252: Error = _("Injection Pump Fuel Metering Control A Range/Performance (Cam/Rotor/Injector)"); break;
										case 0x0253: Error = _("Injection Pump Fuel Metering Control A Low (Cam/Rotor/Injector)"); break;
										case 0x0254: Error = _("Injection Pump Fuel Metering Control A High (Cam/Rotor/Injector)"); break;
										case 0x0255: Error = _("Injection Pump Fuel Metering Control A Intermittent (Cam/Rotor/Injector)"); break;
										case 0x0256: Error = _("Injection Pump Fuel Metering Control B Malfunction (Cam/Rotor/Injector)"); break;
										case 0x0257: Error = _("Injection Pump Fuel Metering Control B Range/Performance (Cam/Rotor/Injector)"); break;
										case 0x0258: Error = _("Injection Pump Fuel Metering Control B Low (Cam/Rotor/Injector)"); break;
										case 0x0259: Error = _("Injection Pump Fuel Metering Control B High (Cam/Rotor/Injector)"); break;
										case 0x0260: Error = _("Injection Pump Fuel Metering Control B Intermittent (Cam/Rotor/Injector)"); break;
										case 0x0261: Error = _("Обрыв или короткое замыкание на Массу цепи управления форсункой 1"); break;
										case 0x0262: Error = _("Короткое замыкание на Бортсеть цепи управления форсункой 1"); break;
										case 0x0263: Error = _("Предельное падение крутящего момента в цилиндре 1 или неисправность драйвера форсунки 1"); break;
										case 0x0264: Error = _("Короткое замыкание на Массу цепи управления форсункой 2"); break;
										case 0x0265: Error = _("Короткое замыкание на Бортсеть цепи управления форсункой 2"); break;
										case 0x0266: Error = _("Предельное падение крутящего момента в цилиндре 2 или неисправность драйвера форсунки 2"); break;
										case 0x0267: Error = _("Короткое замыкание на Массу цепи управления форсункой 3"); break;
										case 0x0268: Error = _("Короткое замыкание на Бортсеть цепи управления форсункой 3"); break;
										case 0x0269: Error = _("Предельное падение крутящего момента в цилиндре 3 или неисправность драйвера форсунки 3"); break;
										case 0x0270: Error = _("Короткое замыкание на Массу цепи управления форсункой 4"); break;
										case 0x0271: Error = _("Короткое замыкание на Бортсеть цепи управления форсункой 4"); break;
										case 0x0272: Error = _("Предельное падение крутящего момента в цилиндре 4 или неисправность драйвера форсунки 4"); break;
										case 0x0273: Error = _("Cylinder 5 Injector Circuit Low "); break;
										case 0x0274: Error = _("Cylinder 5 Injector Circuit High "); break;
										case 0x0275: Error = _("Cylinder 5 Contribution/Balance Fault "); break;
										case 0x0276: Error = _("Cylinder 6 Injector Circuit Low "); break;
										case 0x0277: Error = _("Cylinder 6 Injector Circuit High "); break;
										case 0x0278: Error = _("Cylinder 6 Contribution/Balance Fault "); break;
										case 0x0279: Error = _("Cylinder 7 Injector Circuit Low "); break;
										case 0x0280: Error = _("Cylinder 7 Injector Circuit High "); break;
										case 0x0281: Error = _("Cylinder 7 Contribution/Balance Fault "); break;
										case 0x0282: Error = _("Cylinder 8 Injector Circuit Low "); break;
										case 0x0283: Error = _("Cylinder 8 Injector Circuit High "); break;
										case 0x0284: Error = _("Cylinder 8 Contribution/Balance Fault "); break;
										case 0x0285: Error = _("Cylinder 9 Injector Circuit Low "); break;
										case 0x0286: Error = _("Cylinder 9 Injector Circuit High "); break;
										case 0x0287: Error = _("Cylinder 9 Contribution/Balance Fault "); break;
										case 0x0288: Error = _("Cylinder 10 Injector Circuit Low "); break;
										case 0x0289: Error = _("Cylinder 10 Injector Circuit High "); break;
										case 0x0290: Error = _("Cylinder 10 Contribution/Balance Fault "); break;
										case 0x0291: Error = _("Cylinder 11 Injector Circuit Low "); break;
										case 0x0292: Error = _("Cylinder 11 Injector Circuit High "); break;
										case 0x0293: Error = _("Cylinder 11 Contribution/Balance Fault "); break;
										case 0x0294: Error = _("Cylinder 12 Injector Circuit Low "); break;
										case 0x0295: Error = _("Cylinder 12 Injector Circuit High "); break;
										case 0x0296: Error = _("Cylinder 12 Contribution/Range Fault "); break;
										case 0x0297: Error = _("Превышение допустимой скорости автомобиля"); break;
										case 0x0300: Error = _("Обнаружены случайные/множественные пропуски зажигания"); break;
										case 0x0301: Error = _("Пропуски воспламенения в цилиндре 1"); break;
										case 0x0302: Error = _("Пропуски воспламенения в цилиндре 2"); break;
										case 0x0303: Error = _("Пропуски воспламенения в цилиндре 3"); break;
										case 0x0304: Error = _("Пропуски воспламенения в цилиндре 4"); break;
										case 0x0305: Error = _("Cylinder 5 Misfire Detected "); break;
										case 0x0306: Error = _("Cylinder 6 Misfire Detected "); break;
										case 0x0307: Error = _("Cylinder 7 Misfire Detected "); break;
										case 0x0308: Error = _("Cylinder 8 Misfire Detected "); break;
										case 0x0309: Error = _("Cylinder 9 Misfire Detected "); break;
										case 0x0310: Error = _("Cylinder 10 Misfire Detected "); break;
										case 0x0311: Error = _("Cylinder 11 Misfire Detected "); break;
										case 0x0312: Error = _("Cylinder 12 Misfire Detected "); break;
										case 0x0320: Error = _("Ignition/Distributor Engine Speed Input Circuit Malfunction "); break;
										case 0x0321: Error = _("Ignition/Distributor Engine Speed Input Circuit Range/Performance "); break;
										case 0x0322: Error = _("Ignition/Distributor Engine Speed Input Circuit No Signal "); break;
										case 0x0323: Error = _("Ignition/Distributor Engine Speed Input Circuit Intermittent "); break;
										case 0x0325: Error = _("Неисправность или обрыв цепи датчика детонации"); break;
										case 0x0326: Error = _("Knock Sensor 1 Circuit Range/Performance (Bank 1 or Single Sensor) "); break;
										case 0x0327: Error = _("Низкий уровень сигнала датчика детонации (ДД)"); break;
										case 0x0328: Error = _("Высокий уровень сигнала датчика детонации (ДД)"); break;
										case 0x0329: Error = _("Knock Sensor 1 Circuit Intermittent (Bank 1 or Single Sensor) "); break;
										case 0x0330: Error = _("Knock Sensor 2 Circuit Malfunction (Bank 2) "); break;
										case 0x0331: Error = _("Knock Sensor 2 Circuit Range/Performance (Bank 2) "); break;
										case 0x0332: Error = _("Knock Sensor 2 Circuit Low Input (Bank 2) "); break;
										case 0x0333: Error = _("Knock Sensor 2 Circuit High Input (Bank 2) "); break;
										case 0x0334: Error = _("Knock Sensor 2 Circuit Intermittent (Bank 2) "); break;
										case 0x0335: Error = _("Неисправность или обрыв цепи датчика положения коленчатого вала (ДПКВ)"); break;
										case 0x0336: Error = _("Сигнал датчика положения коленчатого вала (ДПКВ) выходит за допустимые пределы"); break;
										case 0x0337: Error = _("Короткое замыкание на Массу цепи датчика положения коленчатого вала"); break;
										case 0x0338: Error = _("Обрыв цепи датчика положения коленчатого вала"); break;
										case 0x0339: Error = _("Ошибка синхронизации датчика положения коленчатого вала"); break;
										case 0x0340: Error = _("Неисправность цепи датчика положения распределительного вала (датчика фазы)"); break;
										case 0x0341: Error = _("Ошибка синхронизации датчика положения распределительного вала (датчика фазы)"); break;
										case 0x0342: Error = _("Низкий уровень сигнала цепи датчика положения распределительного вала (датчика фазы)"); break;
										case 0x0343: Error = _("Высокий уровень сигнала цепи датчика положения распределительного вала (датчика фазы)"); break;
										case 0x0344: Error = _("Camshaft Position Sensor Circuit Intermittent "); break;
										case 0x0350: Error = _("Замыкание цепи катушки зажигания."); break;
										case 0x0351: Error = _("Обрыв первичной цепи катушки зажигания 1 (1/4)"); break;
										case 0x0352: Error = _("Обрыв первичной цепи катушки зажигания 2 (2/3)"); break;
										case 0x0353: Error = _("Обрыв первичной цепи катушки зажигания 3"); break;
										case 0x0354: Error = _("Обрыв первичной цепи катушки зажигания 4"); break;
										case 0x0355: Error = _("Ignition Coil E Primary/Secondary Circuit Malfunction "); break;
										case 0x0356: Error = _("Ignition Coil F Primary/Secondary Circuit Malfunction "); break;
										case 0x0357: Error = _("Ignition Coil G Primary/Secondary Circuit Malfunction "); break;
										case 0x0358: Error = _("Ignition Coil H Primary/Secondary Circuit Malfunction "); break;
										case 0x0359: Error = _("Ignition Coil I Primary/Secondary Circuit Malfunction "); break;
										case 0x0360: Error = _("Ignition Coil J Primary/Secondary Circuit Malfunction "); break;
										case 0x0361: Error = _("Ignition Coil K Primary/Secondary Circuit Malfunction "); break;
										case 0x0362: Error = _("Ignition Coil L Primary/Secondary Circuit Malfunction "); break;
										case 0x0370: Error = _("Timing Reference High Resolution Signal A Malfunction "); break;
										case 0x0371: Error = _("Timing Reference High Resolution Signal A Too Many Pulses "); break;
										case 0x0372: Error = _("Timing Reference High Resolution Signal A Too Few Pulses "); break;
										case 0x0373: Error = _("Timing Reference High Resolution Signal A Intermittent/Erratic Pulses "); break;
										case 0x0374: Error = _("Timing Reference High Resolution Signal A No Pulses "); break;
										case 0x0375: Error = _("Timing Reference High Resolution Signal B Malfunction "); break;
										case 0x0376: Error = _("Timing Reference High Resolution Signal B Too Many Pulses "); break;
										case 0x0377: Error = _("Timing Reference High Resolution Signal B Too Few Pulses "); break;
										case 0x0378: Error = _("Timing Reference High Resolution Signal B Intermittent/Erratic Pulses "); break;
										case 0x0379: Error = _("Timing Reference High Resolution Signal B No Pulses "); break;
										case 0x0380: Error = _("Glow Plug/Heater Circuit A Malfunction"); break;
										case 0x0381: Error = _("Glow Plug/Heater Indicator Circuit Malfunction "); break;
										case 0x0382: Error = _("Exhaust Gas Recirculation Flow Malfunction "); break;
										case 0x0385: Error = _("Crankshaft Position Sensor B Circuit Malfunction "); break;
										case 0x0386: Error = _("Crankshaft Position Sensor B Circuit Range/Performance "); break;
										case 0x0387: Error = _("Crankshaft Position Sensor B Circuit Low Input "); break;
										case 0x0388: Error = _("Crankshaft Position Sensor B Circuit High Input "); break;
										case 0x0389: Error = _("Crankshaft Position Sensor B Circuit Intermittent "); break;
										case 0x0400: Error = _("Exhaust Gas Recirculation Flow Malfunction "); break;
										case 0x0401: Error = _("Exhaust Gas Recirculation Flow Insufficient Detected"); break;
										case 0x0402: Error = _("Exhaust Gas Recirculation Flow Excessive Detected "); break;
										case 0x0403: Error = _("Обрыв или замыкание цепи клапана рециркуляции."); break;
										case 0x0404: Error = _("Exhaust Gas Recirculation Circuit Range/Performance "); break;
										case 0x0405: Error = _("Низкий или высокий уровень сигнала с датчика положения клапана рециркуляции."); break;
										case 0x0406: Error = _("Exhaust Gas Recirculation Sensor A Circuit High "); break;
										case 0x0407: Error = _("Exhaust Gas Recirculation Sensor B Circuit Low "); break;
										case 0x0408: Error = _("Exhaust Gas Recirculation Sensor B Circuit High "); break;
										case 0x0410: Error = _("Secondary Air Injection System Malfunction "); break;
										case 0x0411: Error = _("Secondary Air Injection System Incorrect Flow Detected "); break;
										case 0x0412: Error = _("Secondary Air Injection System Switching Valve A Circuit Malfunction "); break;
										case 0x0413: Error = _("Secondary Air Injection System Switching Valve A Circuit Open "); break;
										case 0x0414: Error = _("Secondary Air Injection System Switching Valve A Circuit Shorted "); break;
										case 0x0415: Error = _("Secondary Air Injection System Switching Valve B Circuit Malfunction "); break;
										case 0x0416: Error = _("Secondary Air Injection System Switching Valve B Circuit Open "); break;
										case 0x0417: Error = _("Secondary Air Injection System Switching Valve B Circuit Shorted "); break;
										case 0x0418: Error = _("Secondary Air Injection System Relay A Circuit Malfunction"); break;
										case 0x0419: Error = _("Secondary Air Injection System Relay B Circuit Malfunction"); break;
										case 0x0420: Error = _("Эффективность нейтрализатора ниже допустимой нормы"); break;
										case 0x0421: Error = _("Warm Up Catalyst Efficiency Below Threshold (Bank 1) "); break;
										case 0x0422: Error = _("Эффективность нейтрализатора ниже допустимой нормы"); break;
										case 0x0423: Error = _("Heated Catalyst Efficiency Below Threshold (Bank 1) "); break;
										case 0x0424: Error = _("Heated Catalyst Temperature Below Threshold (Bank 1) "); break;
										case 0x0426: Error = _("Catalyst Temperature Sensor Range/Performance (Bank 1) "); break;
										case 0x0427: Error = _("Catalyst Temperature Sensor Low Input (Bank 1) "); break;
										case 0x0428: Error = _("Catalyst Temperature Sensor High Input (Bank 1) "); break;
										case 0x0430: Error = _("Catalyst System Efficiency Below Threshold (Bank 2) "); break;
										case 0x0431: Error = _("Warm Up Catalyst Efficiency Below Threshold (Bank 2) "); break;
										case 0x0432: Error = _("Main Catalyst Efficiency Below Threshold (Bank 2) "); break;
										case 0x0433: Error = _("Heated Catalyst Efficiency Below Threshold (Bank 2) "); break;
										case 0x0434: Error = _("Heated Catalyst Temperature Below Threshold (Bank 2) "); break;
										case 0x0436: Error = _("Catalyst Temperature Sensor Range/Performance (Bank 2) "); break;
										case 0x0437: Error = _("Catalyst Temperature Sensor Low Input (Bank 2) "); break;
										case 0x0438: Error = _("Catalyst Temperature Sensor High Input (Bank 2) "); break;
										case 0x0440: Error = _("Evaporative Emission Control System Malfunction "); break;
										case 0x0441: Error = _("Некорректный расход воздуха через клапан продувки адсорбера"); break;
										case 0x0442: Error = _("Evaporative Emission Control System Leak Detected (small leak) "); break;
										case 0x0443: Error = _("Неисправность цепи управления клапаном продувки адсорбера"); break;
										case 0x0444: Error = _("Короткое замыкание на источник бортовой сети (или обрыв) цепи управления клапаном продувки адсорбера"); break;
										case 0x0445: Error = _("Короткое замыкание на массу цепи управления клапаном продувки адсорбера"); break;
										case 0x0446: Error = _("Обрыв или замыкание цепи клапана продувки адсорбера."); break;
										case 0x0447: Error = _("Evaporative Emission Control System Vent Control Circuit Open "); break;
										case 0x0448: Error = _("Evaporative Emission Control System Vent Control Circuit Shorted "); break;
										case 0x0449: Error = _("Evaporative Emission Control System Vent Valve/Solenoid Circuit Malfunction "); break;
										case 0x0450: Error = _("Evaporative Emission Control System Pressure Sensor Malfunction "); break;
										case 0x0451: Error = _("Evaporative Emission Control System Pressure Sensor Range/Performance "); break;
										case 0x0452: Error = _("Evaporative Emission Control System Pressure Sensor Low Input "); break;
										case 0x0453: Error = _("Evaporative Emission Control System Pressure Sensor High Input "); break;
										case 0x0454: Error = _("Evaporative Emission Control System Pressure Sensor Intermittent "); break;
										case 0x0455: Error = _("Evaporative Emission Control System Leak Detected (gross leak) "); break;
										case 0x0460: Error = _("Fuel Level Sensor Circuit Malfunction "); break;
										case 0x0461: Error = _("Fuel Level Sensor Circuit Range/Performance "); break;
										case 0x0462: Error = _("Fuel Level Sensor Circuit Low Input "); break;
										case 0x0463: Error = _("Fuel Level Sensor Circuit High Input "); break;
										case 0x0464: Error = _("Fuel Level Sensor Circuit Intermittent "); break;
										case 0x0465: Error = _("Purge Flow Sensor Circuit Malfunction "); break;
										case 0x0466: Error = _("Purge Flow Sensor Circuit Range/Performance "); break;
										case 0x0467: Error = _("Purge Flow Sensor Circuit Low Input "); break;
										case 0x0468: Error = _("Purge Flow Sensor Circuit High Input "); break;
										case 0x0469: Error = _("Purge Flow Sensor Circuit Intermittent "); break;
										case 0x0470: Error = _("Exhaust Pressure Sensor Malfunction "); break;
										case 0x0471: Error = _("Exhaust Pressure Sensor Range/Performance "); break;
										case 0x0472: Error = _("Exhaust Pressure Sensor Low "); break;
										case 0x0473: Error = _("Exhaust Pressure Sensor High "); break;
										case 0x0474: Error = _("Exhaust Pressure Sensor Intermittent "); break;
										case 0x0475: Error = _("Exhaust Pressure Control Valve Malfunction "); break;
										case 0x0476: Error = _("Exhaust Pressure Control Valve Range/Performance "); break;
										case 0x0477: Error = _("Exhaust Pressure Control Valve Low "); break;
										case 0x0478: Error = _("Exhaust Pressure Control Valve High "); break;
										case 0x0479: Error = _("Exhaust Pressure Control Valve Intermittent "); break;
										case 0x0480: Error = _("Неисправность цепи управления реле вентилятора № 1 охлаждения"); break;
										case 0x0481: Error = _("Неисправность цепи управления реле вентилятора № 2 охлаждения"); break;
										case 0x0482: Error = _("Cooling Fan 3 Control Circuit Malfunction "); break;
										case 0x0483: Error = _("Cooling Fan Rationality Check Malfunction "); break;
										case 0x0484: Error = _("Cooling Fan Circuit Over Current "); break;
										case 0x0485: Error = _("Cooling Fan Power/Ground Circuit Malfunction "); break;
										case 0x0500: Error = _("Неисправность цепи или нет сигнала от датчика скорости автомобиля"); break;
										case 0x0501: Error = _("Неисправность цепи датчика скорости автомобиля"); break;
										case 0x0502: Error = _("Vehicle Speed Sensor Low Input "); break;
										case 0x0503: Error = _("Прерывающийся сигнал датчика скорости автомобиля"); break;
										case 0x0504: Error = _("Некорректный сигнал выключателей педали тормоза"); break;
										case 0x0505: Error = _("Неисправность регулятора холостого хода. Обрыв или замыкание цепи РХХ. Перегрев драйвера РХХ."); break;
										case 0x0506: Error = _("Низкие обороты холостого хода (регулятор холостого хода заблокирован)"); break;
										case 0x0507: Error = _("Высокие обороты холостого хода (регулятор холостого хода заблокирован)"); break;
										case 0x0508: Error = _("Короткое замыкание на Массу цепи управления шаговым регулятором холостого хода"); break;
										case 0x0509: Error = _("Короткое замыкание на Бортсеть цепи управления шаговым регулятором холостого хода"); break;
										case 0x0510: Error = _("Closed Throttle Position Switch Malfunction "); break;
										case 0x0511: Error = _("Обрыв цепи управления шаговым регулятором холостого хода"); break;
										case 0x0520: Error = _("Engine Oil Pressure Sensor/Switch Circuit Malfunction "); break;
										case 0x0521: Error = _("Engine Oil Pressure Sensor/Switch Circuit Range/Performance "); break;
										case 0x0522: Error = _("Engine Oil Pressure Sensor/Switch Circuit Low Voltage "); break;
										case 0x0523: Error = _("Engine Oil Pressure Sensor/Switch Circuit High Voltage "); break;
										case 0x0530: Error = _("A/C Refrigerant Pressure Sensor Circuit Malfunction "); break;
										case 0x0531: Error = _("A/C Refrigerant Pressure Sensor Circuit Range/Performance "); break;
										case 0x0532: Error = _("A/C Refrigerant Pressure Sensor Circuit Low Input "); break;
										case 0x0533: Error = _("A/C Refrigerant Pressure Sensor Circuit High Input "); break;
										case 0x0534: Error = _("Air Conditioner Refrigerant Charge Loss"); break;
										case 0x0550: Error = _("Power Steering Pressure Sensor Circuit Malfunction"); break;
										case 0x0551: Error = _("Power Steering Pressure Sensor Circuit Range/Performance"); break;
										case 0x0552: Error = _("Power Steering Pressure Sensor Circuit Low Input"); break;
										case 0x0553: Error = _("Power Steering Pressure Sensor Circuit High Input"); break;
										case 0x0554: Error = _("Power Steering Pressure Sensor Circuit Intermittent"); break;
										case 0x0560: Error = _("Напряжение бортовой сети ниже порога работоспособности системы"); break;
										case 0x0561: Error = _("System Voltage Unstable"); break;
										case 0x0562: Error = _("Пониженное напряжение бортовой сети"); break;
										case 0x0563: Error = _("Повышенное напряжение бортовой сети"); break;
										case 0x0565: Error = _("Cruise Control On Signal Malfunction"); break;
										case 0x0566: Error = _("Cruise Control Off Signal Malfunction"); break;
										case 0x0567: Error = _("Cruise Control Resume Signal Malfunction"); break;
										case 0x0568: Error = _("Cruise Control Set Signal Malfunction"); break;
										case 0x0569: Error = _("Cruise Control Coast Signal Malfunction"); break;
										case 0x0570: Error = _("Cruise Control Accel Signal Malfunction"); break;
										case 0x0571: Error = _("Cruise Control/Brake Switch A Circuit Malfunction"); break;
										case 0x0572: Error = _("Cruise Control/Brake Switch A Circuit Low"); break;
										case 0x0573: Error = _("Cruise Control/Brake Switch A Circuit High"); break;
										case 0x0600: Error = _("Serial Communication Link Malfunction "); break;
										case 0x0601: Error = _("Неисправность ПЗУ контроллера (ошибка контрольной суммы)"); break;
										case 0x0602: Error = _("Неисправность ОЗУ контроллера"); break;
										case 0x0603: Error = _("Ошибка записи/чтения внешнего ОЗУ контроллера"); break;
										case 0x0604: Error = _("Ошибка записи/чтения внутреннего ОЗУ контроллера"); break;
										case 0x0605: Error = _("Неисправность флэш-ПЗУ контроллера (ошибка контрольной суммы)"); break;
										case 0x0606: Error = _("Неисправность контроллера или ошибка при его инициализации"); break;
										case 0x0607: Error = _("Неверный сигнал канала детонации контроллера"); break;
										case 0x0608: Error = _("Control Module VSS Output A Malfunction"); break;
										case 0x0609: Error = _("Control Module VSS Output B Malfunction"); break;
										case 0x0615: Error = _("Обрыв цепи управления дополнительным реле стартера"); break;
										case 0x0616: Error = _("Короткое замыкание на Массу цепи управления дополнительным реле стартера"); break;
										case 0x0617: Error = _("Короткое замыкание на Бортсеть цепи управления дополнительным реле стартера"); break;
										case 0x0618: Error = _("Неисправность внешнего EEPROM контроллера"); break;
										case 0x0620: Error = _("Generator Control Circuit Malfunction "); break;
										case 0x0621: Error = _("Generator Lamp L Control Circuit Malfunction"); break;
										case 0x0622: Error = _("Generator Field F Control Circuit Malfunction"); break;
										case 0x0627: Error = _("Обрыв цепи управления реле электробензонасоса"); break;
										case 0x0628: Error = _("Короткое замыкание на Массу цепи управления реле электробензонасоса"); break;
										case 0x0629: Error = _("Короткое замыкание на Бортсеть цепи управления реле электробензонасоса"); break;
										case 0x0630: Error = _("Некорректная запись или отсутствие VIN-код автомобиля"); break;
										case 0x0645: Error = _("Обрыв цепи управления реле муфты кондиционера"); break;
										case 0x0646: Error = _("Обрыв или короткое замыкание на Массу цепи реле муфты кондиционера"); break;
										case 0x0647: Error = _("Короткое замыкание на Бортсеть цепи реле муфты кондиционера"); break;
										case 0x0650: Error = _("Неисправность цепи управления лампой MIL (Check engine)"); break;
										case 0x0654: Error = _("Неисправность цепи управления тахометром панели приборов"); break;
										case 0x0655: Error = _("Engine Hot Lamp Output Control Circuit Malfucntion "); break;
										case 0x0656: Error = _("Fuel Level Output Circuit Malfunction "); break;
										case 0x0657: Error = _("Неисправность цепи управления расходомером или указателем температуры"); break;
										case 0x0685: Error = _("Обрыв цепи управления главным реле"); break;
										case 0x0687: Error = _("Короткое замыкание на Бортсеть цепи управления главным реле"); break;
										case 0x0688: Error = _("Обрыв силовой цепи с выхода главного реле"); break;
										case 0x0690: Error = _("Короткое замыкание на Бортсеть силовой цепи главного реле"); break;
										case 0x0691: Error = _("Обрыв или короткое замыкание на Массу цепи управления реле электровентилятора № 1"); break;
										case 0x0692: Error = _("Короткое замыкание на Бортсеть цепи управления реле электровентилятора № 1"); break;
										case 0x0693: Error = _("Обрыв или короткое замыкание на Массу цепи управления реле электровентилятора № 2 "); break;
										case 0x0694: Error = _("Короткое замыкание на Бортсеть цепи управления реле электровентилятора № 2"); break;
										case 0x0700: Error = _("Transmission Control System Malfunction "); break;
										case 0x0701: Error = _("Transmission Control System Range/Performance "); break;
										case 0x0702: Error = _("Transmission Control System Electrical "); break;
										case 0x0703: Error = _("Torque Converter/Brake Switch B Circuit Malfunction "); break;
										case 0x0704: Error = _("Clutch Switch Input Circuit Malfunction "); break;
										case 0x0705: Error = _("Transmission Range Sensor Circuit malfunction (PRNDL Input) "); break;
										case 0x0706: Error = _("Transmission Range Sensor Circuit Range/Performance "); break;
										case 0x0707: Error = _("Transmission Range Sensor Circuit Low Input "); break;
										case 0x0708: Error = _("Transmission Range Sensor Circuit High Input "); break;
										case 0x0709: Error = _("Transmission Range Sensor Circuit Intermittent "); break;
										case 0x0710: Error = _("Transmission Fluid Temperature Sensor Circuit Malfunction "); break;
										case 0x0711: Error = _("Transmission Fluid Temperature Sensor Circuit Range/Performance "); break;
										case 0x0712: Error = _("Transmission Fluid Temperature Sensor Circuit Low Input "); break;
										case 0x0713: Error = _("Transmission Fluid Temperature Sensor Circuit High Input "); break;
										case 0x0714: Error = _("Transmission Fluid Temperature Sensor Circuit Intermittent "); break;
										case 0x0715: Error = _("Input/Turbine Speed Sensor Circuit Malfunction "); break;
										case 0x0716: Error = _("Input/Turbine Speed Sensor Circuit Range/Performance "); break;
										case 0x0717: Error = _("Input/Turbine Speed Sensor Circuit No Signal "); break;
										case 0x0718: Error = _("Input/Turbine Speed Sensor Circuit Intermittent "); break;
										case 0x0719: Error = _("Torque Converter/Brake Switch B Circuit Low "); break;
										case 0x0720: Error = _("Output Speed Sensor Circuit Malfunction "); break;
										case 0x0721: Error = _("Output Speed Sensor Range/Performance "); break;
										case 0x0722: Error = _("Output Speed Sensor No Signal "); break;
										case 0x0723: Error = _("Output Speed Sensor Intermittent "); break;
										case 0x0724: Error = _("Torque Converter/Brake Switch B Circuit High "); break;
										case 0x0725: Error = _("Engine Speed input Circuit Malfunction "); break;
										case 0x0726: Error = _("Engine Speed Input Circuit Range/Performance "); break;
										case 0x0727: Error = _("Engine Speed Input Circuit No Signal "); break;
										case 0x0728: Error = _("Engine Speed Input Circuit Intermittent "); break;
										case 0x0730: Error = _("Incorrect Gear Ratio "); break;
										case 0x0731: Error = _("Gear 1 Incorrect ratio "); break;
										case 0x0732: Error = _("Gear 2 Incorrect ratio "); break;
										case 0x0733: Error = _("Gear 3 Incorrect ratio "); break;
										case 0x0734: Error = _("Gear 4 Incorrect ratio "); break;
										case 0x0735: Error = _("Gear 5 Incorrect ratio "); break;
										case 0x0736: Error = _("Reverse incorrect gear ratio "); break;
										case 0x0740: Error = _("Torque Converter Clutch Circuit Malfuction "); break;
										case 0x0741: Error = _("Torque Converter Clutch Circuit Performance or Stuck Off "); break;
										case 0x0742: Error = _("Torque Converter Clutch Circuit Stuck On "); break;
										case 0x0743: Error = _("Torque Converter Clutch Circuit Electrical "); break;
										case 0x0744: Error = _("Torque Converter Clutch Circuit Intermittent "); break;
										case 0x0745: Error = _("Pressure Control Solenoid Malfunction "); break;
										case 0x0746: Error = _("Pressure Control Solenoid Performance or Stuck Off "); break;
										case 0x0747: Error = _("Pressure Control Solenoid Stuck On "); break;
										case 0x0748: Error = _("Pressure Control Solenoid Electrical "); break;
										case 0x0749: Error = _("Pressure Control Solenoid Intermittent "); break;
										case 0x0750: Error = _("Shift Solenoid A Malfunction "); break;
										case 0x0751: Error = _("Shift Solenoid A Performance or Stuck Off/1 - 2 Shift Solenoid Valve Performance "); break;
										case 0x0752: Error = _("Shift Solenoid A Stuck On "); break;
										case 0x0753: Error = _("Shift Solenoid A Electrical/1 - 2 Shift Solenoid Circuit Electrical "); break;
										case 0x0754: Error = _("Shift Solenoid A Intermittent "); break;
										case 0x0755: Error = _("Shift Solenoid B Malfunction "); break;
										case 0x0756: Error = _("Shift Solenoid B Performance or Stuck Off/2 - 3 Shift Solenoid Valve Performance "); break;
										case 0x0757: Error = _("Shift Solenoid B Stuck On "); break;
										case 0x0758: Error = _("Shift Solenoid B Electrical/2 - 3 Shift Solenoid Circuit Electrical "); break;
										case 0x0759: Error = _("Shift Solenoid B Intermittent "); break;
										case 0x0760: Error = _("Shift Solenoid C Malfunction "); break;
										case 0x0761: Error = _("Shift Solenoid C Performance or Stuck Off "); break;
										case 0x0762: Error = _("Shift Solenoid C Stuck On "); break;
										case 0x0763: Error = _("Shift Solenoid C Electrical "); break;
										case 0x0764: Error = _("Shift Solenoid C Intermittent "); break;
										case 0x0765: Error = _("Shift Solenoid D Malfunction "); break;
										case 0x0766: Error = _("Shift Solenoid D Performance or Stuck Off "); break;
										case 0x0767: Error = _("Shift Solenoid D Stuck On "); break;
										case 0x0768: Error = _("Shift Solenoid D Electrical "); break;
										case 0x0769: Error = _("Shift Solenoid D Intermittent "); break;
										case 0x0770: Error = _("Shift Solenoid E Malfunction "); break;
										case 0x0771: Error = _("Shift Solenoid E Performance or Stuck Off "); break;
										case 0x0772: Error = _("Shift Solenoid E Stuck On "); break;
										case 0x0773: Error = _("Shift Solenoid E Electrical "); break;
										case 0x0774: Error = _("Shift Solenoid E Intermittent "); break;
										case 0x0775: Error = _("Pressure Control Solenoid B Malfunction"); break;
										case 0x0776: Error = _("Pressure Control Solenoid B Performance "); break;
										case 0x0777: Error = _("Pressure Control Solenoid B Stuck On "); break;
										case 0x0778: Error = _("Pressure Control Solenoid B Electrical "); break;
										case 0x0779: Error = _("Pressure Control Solenoid B Intermittent "); break;
										case 0x0780: Error = _("Shift Malfunction "); break;
										case 0x0781: Error = _("1 - 2 Shift Malfunction "); break;
										case 0x0782: Error = _("2 - 3 Shift Malfunction "); break;
										case 0x0783: Error = _("3 - 4 Shift Malfunction "); break;
										case 0x0784: Error = _("4 - 5 Shift Malfunction "); break;
										case 0x0785: Error = _("Shift/Timing Solenoid Malfunction/ 3 - 2 Shift Solenoid Circuit Electrical "); break;
										case 0x0786: Error = _("Shift/Timing Solenoid Range/Performance "); break;
										case 0x0787: Error = _("Shift/Timing Solenoid Low "); break;
										case 0x0788: Error = _("Shift/Timing Solenoid High "); break;
										case 0x0789: Error = _("Shift/Timing Solenoid Intermittent "); break;
										case 0x0790: Error = _("Normal/Performance Switch Circuit Malfunction"); break;
										case 0x0801: Error = _("Reverse Inhibit Control Circuit Malfunction "); break;
										case 0x0803: Error = _("1 - 4 Upshift (Skip Shift) Solenoid Control Circuit Malfunction "); break;
										case 0x0804: Error = _("1 - 4 Upshift (Skip Shift) Lamp Control Circuit Malfunction"); break;
										case 0x1102: Error = _("Низкое сопротивление нагревателя датчика кислорода № 1 до нейтрализатора"); break;
										case 0x1115: Error = _("Неисправность цепи управления нагревом датчика кислорода № 1 до нейтрализатора"); break;
										case 0x1123: Error = _("Смесь богатая - аддитивная коррекция топливно-воздушной смеси по воздуху превышает установленный порог"); break;
										case 0x1124: Error = _("Смесь бедная - аддитивная коррекция топливно-воздушной смеси по воздуху превышает установленный порог"); break;
										case 0x1127: Error = _("Смесь богатая - мультипликативная коррекция состава топливно-воздушной смеси превышает установленный порог"); break;
										case 0x1128: Error = _("Смесь бедная - мультипликативная коррекция состава топливно-воздушной смеси превышает установленный порог"); break;
										case 0x1135: Error = _("Неисправность цепи нагревателя датчика кислорода № 1"); break;
										case 0x1136: Error = _("Смесь богатая - аддитивная коррекция топливно-воздушной смеси по топливу превышает установленный порог"); break;
										case 0x1137: Error = _("Смесь бедная - аддитивная коррекция топливно-воздушной смеси по топливу превышает установленный порог"); break;
										case 0x1140: Error = _("Неверный сигнал датчика массового расхода воздуха (ДМРВ), измеренный параметр нагрузки отличается от расчетного"); break;
										case 0x1141: Error = _("Неисправность цепи нагревателя датчика кислорода № 2"); break;
										case 0x1170: Error = _("Низкий или высокий уровень сигнала с потенциометра коррекции СО."); break;
										case 0x1171: Error = _("Низкий уровень сигнала цепи СО-потенциометра"); break;
										case 0x1172: Error = _("Высокий уровень сигнала цепи СО-потенциометра"); break;
										case 0x1230: Error = _("Неисправность цепи управления главным реле"); break;
										case 0x1335: Error = _("Положение дроссельной заслонки вне допустимого диапазона"); break;
										case 0x1336: Error = _("Недопустимое расхождение показаний датчиков № 1 и № 2 положения дроссельной заслонки"); break;
										case 0x1351: Error = _("Короткое замыкание в первичной цепи катушки зажигания цилиндров 1 и 4"); break;
										case 0x1352: Error = _("Короткое замыкание в первичной цепи катушки зажигания цилиндров 2 и 3"); break;
										case 0x1386: Error = _("Ошибка при выполнении внутреннего теста канала детонации"); break;
										case 0x1388: Error = _("Положение педали ускорения вне допустимого диапазона"); break;
										case 0x1389: Error = _("Частота вращения двигателя вне допустимого диапазона"); break;
										case 0x1390: Error = _("Необратимое ограничение впрыска топлива в связи с неисправностями систем"); break;
										case 0x1391: Error = _("Ошибка при выполнении программы мониторинга систем двигателя"); break;
										case 0x1410: Error = _("Неисправность или короткое замыкание на источник бортовой сети цепи управления клапаном продувки адсорбера"); break;
										case 0x1425: Error = _("Неисправность или короткое замыкание на массу цепи управления клапаном продувки адсорбера"); break;
										case 0x1426: Error = _("Неисправность или обрыв цепи управления клапаном продувки адсорбера"); break;
										case 0x1427: Error = _("Неисправность цепи управления клапаном продувки адсорбера"); break;
										case 0x1500: Error = _("Обрыв цепи управления реле электробензонасоса"); break;
										case 0x1501: Error = _("Короткое замыкание на массу цепи управления реле электробензонасоса"); break;
										case 0x1502: Error = _("Короткое замыкание на источник бортовой сети цепи управления реле электробензонасоса"); break;
										case 0x1509: Error = _("Перегрузка цепи управления регулятором холостого хода (РХХ)"); break;
										case 0x1513: Error = _("Короткое замыкание на массу цепи управления регулятором холостого хода (РХХ)"); break;
										case 0x1514: Error = _("Короткое замыкание на источник бортовой сети (или обрыв) цепи управления регулятором холостого хода (РХХ)"); break;
										case 0x1530: Error = _("Неисправность цепи управления реле муфты кондиционера"); break;
										case 0x1541: Error = _("Обрыв цепи управления реле электробензонасоса"); break;
										case 0x1545: Error = _("Положение дроссельной заслонки вне допустимого диапазона"); break;
										case 0x1558: Error = _("Начальное положение дроссельной заслонки вне допустимого диапазона"); break;
										case 0x1559: Error = _("Недостоверное значение массового расхода воздуха через дроссель"); break;
										case 0x1564: Error = _("Нарушение адаптации дросселя в связи с пониженным напряжением питания"); break;
										case 0x1570: Error = _("Нет ответа от автомобильной противоугонной системы (АПС) или обрыв цепи"); break;
										case 0x1571: Error = _("Использован незарегистрированный электронный ключ"); break;
										case 0x1572: Error = _("Обрыв цепи или неисправность приемопередающей антенны иммобилайзера"); break;
										case 0x1573: Error = _("Внутренняя неисправность блока АПС (иммобилайзера)"); break;
										case 0x1574: Error = _("Попытка разблокирования  АПС (иммобилайзера)"); break;
										case 0x1575: Error = _("Доступ к  АПС (иммобилайзеру) заблокирован контроллером"); break;
										case 0x1578: Error = _("Недостоверность результатов переобучения дроссельной заслонки"); break;
										case 0x1579: Error = _("Аварийное прекращение адаптации привода дроссельной заслонки в связи с внешними условиями"); break;
										case 0x1600: Error = _("Нет связи с автомобильной противоугонной системой (АПС) или обрыв цепи (иммобилайзером)"); break;
										case 0x1601: Error = _("Нет связи с автомобильной противоугонной системой (АПС) или обрыв цепи (иммобилайзером)"); break;
										case 0x1602: Error = _("Пропадание напряжение бортовой сети в контроллере"); break;
										case 0x1603: Error = _("Неисправность энергонезависимой памяти (EEPROM) контроллера"); break;
										case 0x1606: Error = _("Низкий уровень или неверный сигнал в цепи датчика неровной дороги"); break;
										case 0x1607: Error = _("Высокий уровень сигнала в цепи датчика неровной дороги"); break;
										case 0x1612: Error = _("Несанкционированный сброс контроллера в рабочем состоянии"); break;
										case 0x1616: Error = _("Низкий уровень сигнала датчика неровной дороги"); break;
										case 0x1617: Error = _("Высокий уровень сигнала датчика неровной дороги"); break;
										case 0x1620: Error = _("Неисправность ПЗУ контроллера"); break;
										case 0x1621: Error = _("Неисправность ОЗУ контроллера"); break;
										case 0x1622: Error = _("Неисправность энергонезависимой памяти (EEPROM) контроллера"); break;
										case 0x1632: Error = _("Неисправность канала № 1 управления электроприводом дроссельной заслонки"); break;
										case 0x1633: Error = _("Неисправность канала № 2 управления электроприводом дроссельной заслонки"); break;
										case 0x1634: Error = _("Неисправность электропривода дроссельной заслонки в стартовом положении"); break;
										case 0x1635: Error = _("Неисправность электропривода дроссельной заслонки в закрытом положении"); break;
										case 0x1636: Error = _("Неисправность электропривода дроссельной заслонки в обесточенном положении"); break;
										case 0x1640: Error = _("Ошибка записи/чтения внутреннего флэш-ОЗУ (EEPROM) контроллера"); break;
										case 0x1689: Error = _("Ошибочные значения кодов в памяти неисправностей контроллера"); break;
										case 0x1750: Error = _("Короткое замыкание на Бортсеть цепи № 1 управления моментным регулятором холостого хода"); break;
										case 0x1751: Error = _("Обрыв цепи № 1 управления моментным регулятором холостого хода"); break;
										case 0x1752: Error = _("Короткое замыкание на Массу цепи № 1 управления моментным регулятором холостого хода"); break;
										case 0x1753: Error = _("Короткое замыкание на Бортсеть цепи № 2 управления моментным регулятором холостого хода"); break;
										case 0x1754: Error = _("Обрыв цепи № 2 управления моментным регулятором холостого хода"); break;
										case 0x1755: Error = _("Короткое замыкание на Массу цепи № 2 управления моментным регулятором холостого хода"); break;
										case 0x2100: Error = _("Обрыв цепи управления электроприводом дроссельной заслонки"); break;
										case 0x2102: Error = _("Короткое замыкание на Массу цепи управления электроприводом дроссельной заслонки"); break;
										case 0x2103: Error = _("Короткое замыкание на Бортсеть цепи управления электроприводом дроссельной заслонки"); break;
										case 0x2104: Error = _("Ограничение электропривода дроссельной заслонки режимом холостого хода"); break;
										case 0x2105: Error = _("Ограничение электропривода дроссельной заслонки блокированием работы двигателя"); break;
										case 0x2106: Error = _("Ограничение мощности электропривода дроссельной заслонки или неисправность цепи"); break;
										case 0x2110: Error = _("Ограничение электропривода дроссельной заслонки предельной частотой вращения двигателя"); break;
										case 0x2111: Error = _("Ошибка управления электроприводом дросселя заслонки при открытии"); break;
										case 0x2112: Error = _("Ошибка управления электроприводом дросселя заслонки при закрытии"); break;
										case 0x2120: Error = _("Неисправность цепи датчика № 1 положения  педали ускорения"); break;
										case 0x2122: Error = _("Низкий уровень сигнала в цепи датчика № 1 положения педали ускорения"); break;
										case 0x2123: Error = _("Высокий уровень сигнала в цепи датчика № 1 положения педали ускорения"); break;
										case 0x2127: Error = _("Низкий уровень сигнала в цепи датчика № 2 положения педали ускорения"); break;
										case 0x2128: Error = _("Высокий уровень сигнала в цепи датчика № 2 положения педали ускорения"); break;
										case 0x2135: Error = _("Несовпадение показаний датчиков № 1 и 2 положения дроссельной заслонки"); break;
										case 0x2138: Error = _("Несовпадение показаний датчиков № 1 и 2 положения педали ускорения"); break;
										case 0x2173: Error = _("Высокий расход воздуха при управлении дроссельной заслонкой"); break;
										case 0x2175: Error = _("Низкий расход воздуха при управлении дроссельной заслонкой"); break;
										case 0x2187: Error = _("Система топливоподачи дрейфует от средней к бедной области на холостом ходу"); break;
										case 0x2188: Error = _("Система топливоподачи дрейфует от средней к богатой области на холостом ходу"); break;
										case 0x2195: Error = _("Нет совпадения сигналов датчиков кислорода № 1 и № 2"); break;
										case 0x2270: Error = _("Сигнал датчика кислорода № 2 находится в состоянии бедно"); break;
										case 0x2271: Error = _("Сигнал датчика кислорода № 2 находится в состоянии богато"); break;
										case 0x2299: Error = _("Несоответствие сигналов выключателей педали тормоза и датчиков положения педали ускорения"); break;
										case 0x2301: Error = _("Короткое замыкание на Бортсеть цепи катушки зажигания 1(1/4)"); break;
										case 0x2303: Error = _("Короткое замыкание на Бортсеть цепи катушки зажигания 2(2/3)"); break;
										case 0x2304: Error = _("Короткое замыкание на Бортсеть цепи катушки зажигания 2(2/3)"); break;
										case 0x2305: Error = _("Короткое замыкание на Бортсеть цепи катушки зажигания 3(2/3)"); break;
										case 0x2307: Error = _("Короткое замыкание на Бортсеть цепи катушки зажигания 3(2/3) или 4(1/4)"); break;
										case 0x2310: Error = _("Короткое замыкание на Бортсеть цепи катушки зажигания 4"); break;
										default: Error = _("Невідома помилка."); break;
									}
									m_textCtrlErrors->AppendText("P" + wxString::Format("%04X", errCode) + " - " + Error + "\n");
									errEnable = TRUE;
								}
							}
						}
						if( m_notebook2->GetSelection() == 0 || m_notebook2->GetSelection() == 3 )
						{
							if( inData[inDB] ==  0x61 && (inData[inDB + 1] == 0xE1 || inData[inDB + 1] == 1) )
							{
								int16_t var = 0;
								inDB += 1;
								for( int i = 1 ; i < 17 ; i++ )
								{
									if( paramAddr[carType][dataSet[carType][i]][0] == paramAddr[carType][dataSet[carType][i]][1] )
									{
										var = (int16_t)(inData[inDB + paramAddr[carType][dataSet[carType][i]][0]]);
									}
									else
									{
										var = (int16_t)(inData[inDB + paramAddr[carType][dataSet[carType][i]][1]] * 256 + inData[inDB + paramAddr[carType][dataSet[carType][i]][0]]);
									}
									data[i] = ((var + paramCoef[carType][dataSet[carType][i]][0]) * paramCoef[carType][dataSet[carType][i]][1]) / paramCoef[carType][dataSet[carType][i]][2] + paramCoef[carType][dataSet[carType][i]][3];
								}
								DataShow();
								int Err = 0;
								for( int i = flags[carType][0] ; i <= flags[carType][1] ; i++ )
								{
									Err = Err | ((int)inData[inDB + 1] & flags[carType][2]);
								}
								if( Err > 0 )
								{
									;
									//TODO
								}
							}
						}
					}
				}
			}
		}

/*-----------------------------------------------------------------------------
 *  Transmit data
 *-----------------------------------------------------------------------------*/
		if( carType > 12 )
		{
			init = FALSE;
			outData[0] = 0xF4; //244
			outData[1] = 0x57; //87
			outData[2] = 1;
			outData[3] = 0;
			outDataCount = 4;
			if( resetError )
			{
				uprSend = TRUE;
				uprVar = 10;
				resetError = FALSE;
			}
		}
		else
		{
			outDataCount = 0;
			outData[0] = 0x80; //128 
			outData[1] = 0x10; //16 target address
			if(carType == 11 || carType == 12)
				outData[1] = 0x11; //17 source address 
			outData[2] = 0xF1; //241 source address 
			if( inData[inDB] == 0x7F || init ) //if receive error answer
			{
				outData[3] = 0x81; //129 Start communication
				outDataCount = 4;
			}
			else
			{
				if( carType == 0 )
				{
					outData[3] = 0x21; //33 read data by local identifier
					outData[4] = 1; //after sales service record local identifier
					outDataCount = 5;
				}
				else
				{
					if( m_notebook2->GetSelection() == 0 )
					{
						if( uprZap == TRUE )
						{
							outData[3] = 0x30; //48 input output control by local identifier
							switch ( uprVar )
							{
								case 1 : outData[4] = 0x42; break;  //66 idle engine speed adjust
								case 2 : outData[4] = 0x61; break;  //97 CO Trimming
								case 3 : outData[4] = 0x63; break;  //99
								case 4 : outData[4] = 0x0A; break;  //10 cooling sytem fan relay
								case 5 : outData[4] = 0x0B; break;  //11 air condition relay
								case 6 : outData[4] = 0x0E; break;  //14
								case 7 : outData[4] = 0x0C; break;  //12 indication lamp control
								case 8 : outData[4] = 0x09; break;  //9 fuel pump relay control
							}
							if(uprVar > 3)
								outData[5] = 0; //return control to ECU
							else
								outData[5] = 1; //report current state
							outData[6] = 0;
							outData[7] = 0;
							outDataCount = 8;
							//TODO
						}
						else 
						{
							if( uprClose )
							{
								uprClose = false;
								outData[3] = 0x30; // input output control by local identifier
								outData[4] = 0;
								outDataCount = 5;
							}
							else
							{
								outData[3] = 0x21; //read data by local identifier
								outData[4] = 0xE1;
								if((carType < 3) || carType > 4)
									outData[4] = 1;
								outDataCount = 5;
							}
						}
					}
					if( m_notebook2->GetSelection() == 1 )
					{
						if( resetError )
						{
							outData[3] = 0x14; //Clear diagnostic information
							outData[4] = 0;
							outData[5] = 0;
							outDataCount = 6;
						}
						else
						{
							outData[3] = 0x18; //read Diagnostic information
							outData[4] = 0;
							outData[5] = 0;
							outData[6] = 0;
							outDataCount = 7;
						}
						resetError = FALSE;
					}
					if( m_notebook2->GetSelection() == 2 )
					{
						outData[3] = 0x21;
						outData[4] = 0xE2;
						if(carType < 3 || carType > 4)
							outData[4] = 3;
						outDataCount = 5;
					}
					if( m_notebook2->GetSelection() == 3 )
					{
						outData[3] = 0x21;
						outData[4] = 0xE1;
						if(carType < 3 || carType > 4)
							outData[4] = 1;
						outDataCount = 5;
					}
					if( m_notebook2->GetSelection() == 4 )
					{
						outData[3] = 0x21;
						outData[4] = 0xF3;
						if(carType < 3 || carType > 4)
							outData[4] = 5;
						outDataCount = 5;
					}
					if( m_notebook2->GetSelection() == 5 )
					{
						if( idZapros < 8 )
						{
							outData[3] = 0x1A;
							switch (idZapros)
							{
								case 0: outData[4] = 0x90; break;
								case 1: outData[4] = 0x91; break;
								case 2: outData[4] = 0x92; break;
								case 3: outData[4] = 0x94; break;
								case 4: outData[4] = 0x97; break;
								case 5: outData[4] = 0x98; break;
								case 6: outData[4] = 0x99; break;
								case 7: outData[4] = 0x9A; break;
							}
							idZapros++;
						}
						else
						{
							outData[3] = 0x21;
							outData[4] = 0xE1;
						}
						outDataCount = 5;
					}
				}
			}
			outData[0] += (unsigned char)(outDataCount - 3); //0x80 + data length
			outData[outDataCount] = 0;
			for( int i = 0 ; i < outDataCount ; i++ )
			{
				outData[outDataCount] += outData[i];
			}
		}
		inDataCount = 0;
		outDataCount++; //number bytes to send in function write
		serialPort.Write(outData, outDataCount);
	}
	else
	{
		outDataCount = 0;
	}
	m_timerWork.Start(timerPeriod, wxTIMER_ONE_SHOT);
}

void MyFrame::ScanPort(void)
{
	int n;
	MyPort serialPort;
	wxArrayString strArr;
	strArr = serialPort.GetComList();
	m_comboBoxSelectPort->Clear();
	n = strArr.GetCount();
	if( n == 0 )
	{
		wxMessageDialog* dlg = new  wxMessageDialog(NULL, _("In system not present serial port."), _("Warning."), wxOK);
		dlg->ShowModal();
		return;
	}
	else
	{
		for( int i = 0 ; i < n ; i++ )
		{
			m_comboBoxSelectPort->Append(strArr.Item(i));
		}
		m_comboBoxSelectPort->SetSelection(0);
	}
}

void MyFrame::SaveSetting(void)
{
	wxFile* file = new wxFile;
	datBuf = new char;
	file->Create("sensdiag.dat",TRUE);
	if( file->IsOpened() )
	{
		for( int i = 0 ; i < 16 ; i++ )
		{
			for( int j = 1 ; j < 17 ; j++ )
			{
				if( i < 1 )
				{
					if( j == 1 )
					{
						datBuf[0] = (char)carType;
						file->Write(datBuf, 1);
					}
					else
					{
						if( j == 15 )
						{
							datBuf[0] = (char)adapter;
							file->Write(datBuf, 1);
						}
						else
						{
							if( j == 16 )
							{
								datBuf[0] = (char)ioPort;
								file->Write(datBuf, 1);
							}
							else
							{
								datBuf[0] = (char)dataGraph[j - 1];
								file->Write(datBuf, 1);
							}
						}
					}
				}
				else
				{
					datBuf[0] = (char)dataSet[i][j];
					file->Write(datBuf, 1);
				}
			}
		}
	}
	file->Close();
	delete file;
	delete datBuf;
}

void MyFrame::LoadEBC(void)
{
	m_staticTextDat1->SetLabel(paramName[carType][dataSet[carType][1]]);
	m_staticTextDat2->SetLabel(paramName[carType][dataSet[carType][2]]);
	m_staticTextDat3->SetLabel(paramName[carType][dataSet[carType][3]]);
	m_staticTextDat4->SetLabel(paramName[carType][dataSet[carType][4]]);
	m_staticTextDat5->SetLabel(paramName[carType][dataSet[carType][5]]);
	m_staticTextDat6->SetLabel(paramName[carType][dataSet[carType][6]]);
	m_staticTextDat7->SetLabel(paramName[carType][dataSet[carType][7]]);
	m_staticTextDat8->SetLabel(paramName[carType][dataSet[carType][8]]);
	m_staticTextDat9->SetLabel(paramName[carType][dataSet[carType][9]]);
	m_staticTextDat10->SetLabel(paramName[carType][dataSet[carType][10]]);
	m_staticTextDat11->SetLabel(paramName[carType][dataSet[carType][11]]);
	m_staticTextDat12->SetLabel(paramName[carType][dataSet[carType][12]]);
	m_staticTextDat13->SetLabel(paramName[carType][dataSet[carType][13]]);
	m_staticTextDat14->SetLabel(paramName[carType][dataSet[carType][14]]);
	m_staticTextDat15->SetLabel(paramName[carType][dataSet[carType][15]]);
	m_staticTextDat16->SetLabel(paramName[carType][dataSet[carType][16]]);

	m_staticTextAn1->SetLabel(analogName[carType][1]);
	m_staticTextAn2->SetLabel(analogName[carType][2]);
	m_staticTextAn3->SetLabel(analogName[carType][3]);
	m_staticTextAn4->SetLabel(analogName[carType][4]);
	m_staticTextAn5->SetLabel(analogName[carType][5]);
	m_staticTextAn6->SetLabel(analogName[carType][6]);
	m_staticTextAn7->SetLabel(analogName[carType][7]);
	m_staticTextAn8->SetLabel(analogName[carType][8]);
	m_staticTextAn9->SetLabel(analogName[carType][9]);
	m_staticTextAn10->SetLabel(analogName[carType][10]);
	m_staticTextAn11->SetLabel(analogName[carType][11]);

	if(dataGraph[1] > 0) m_staticTextG1->SetLabel(paramName[carType][dataSet[carType][dataGraph[1]]]);
	else m_staticTextG1->SetLabel(_(""));
	if(dataGraph[2] > 0) m_staticTextG2->SetLabel(paramName[carType][dataSet[carType][dataGraph[2]]]);
	else m_staticTextG2->SetLabel(_(""));
	if(dataGraph[3] > 0) m_staticTextG3->SetLabel(paramName[carType][dataSet[carType][dataGraph[3]]]);
	else m_staticTextG3->SetLabel(_(""));
	if(dataGraph[4] > 0) m_staticTextG4->SetLabel(paramName[carType][dataSet[carType][dataGraph[4]]]);
	else m_staticTextG4->SetLabel(_(""));
	if(dataGraph[5] > 0) m_staticTextG5->SetLabel(paramName[carType][dataSet[carType][dataGraph[5]]]);
	else m_staticTextG5->SetLabel(_(""));
	if(dataGraph[6] > 0) m_staticTextG6->SetLabel(paramName[carType][dataSet[carType][dataGraph[6]]]);
	else m_staticTextG6->SetLabel(_(""));

	m_staticTextT1->SetLabel(timerName[carType][1]);
	m_staticTextT2->SetLabel(timerName[carType][2]);
	m_staticTextT3->SetLabel(timerName[carType][3]);
	m_staticTextT4->SetLabel(timerName[carType][4]);
	m_staticTextT5->SetLabel(timerName[carType][5]);
	m_staticTextT6->SetLabel(timerName[carType][6]);
	m_staticTextT7->SetLabel(timerName[carType][7]);
	m_staticTextT8->SetLabel(timerName[carType][8]);
	m_staticTextT9->SetLabel(timerName[carType][9]);
	m_staticTextT10->SetLabel(timerName[carType][10]);
	m_staticTextT11->SetLabel(timerName[carType][11]);
	m_staticTextT12->SetLabel(timerName[carType][12]);
	m_staticTextT13->SetLabel(timerName[carType][13]);
	m_staticTextT14->SetLabel(timerName[carType][14]);
	m_staticTextT15->SetLabel(timerName[carType][15]);
	m_staticTextT16->SetLabel(timerName[carType][16]);

	m_staticTextID1->SetLabel(_(""));
	m_staticTextID2->SetLabel(_(""));
	m_staticTextID3->SetLabel(_(""));
	m_staticTextID4->SetLabel(_(""));
	m_staticTextID5->SetLabel(_(""));
	m_staticTextID6->SetLabel(_(""));
	m_staticTextID7->SetLabel(_(""));
	m_staticTextID8->SetLabel(_(""));
}

void MyFrame::DataShow()
{
	wxString str;
	switch((int)paramCoef[carType][dataSet[carType][1]][4])
	{
		case 1: str.Format("%1f", data[1]);
				m_staticText_Dat1->SetLabel(str);
				break;
		case 2: str.Format("%2f", data[1]);
				m_staticText_Dat1->SetLabel(str);
				break;
		default: str.Format("%f", data[1]);
				 m_staticText_Dat1->SetLabel(str);
				 break;
	}
	switch((int)paramCoef[carType][dataSet[carType][2]][4])
	{
		case 1: str.Format("%1f", data[2]);
				m_staticText_Dat1->SetLabel(str);
				break;
		case 2: str.Format("%2f", data[2]);
				m_staticText_Dat1->SetLabel(str);
				break;
		default: str.Format("%f", data[2]);
				 m_staticText_Dat1->SetLabel(str);
				 break;
	}
	switch((int)paramCoef[carType][dataSet[carType][3]][4])
	{
		case 1: str.Format("%1f", data[3]);
				m_staticText_Dat1->SetLabel(str);
				break;
		case 2: str.Format("%2f", data[3]);
				m_staticText_Dat1->SetLabel(str);
				break;
		default: str.Format("%f", data[3]);
				 m_staticText_Dat1->SetLabel(str);
				 break;
	}
	switch((int)paramCoef[carType][dataSet[carType][4]][4])
	{
		case 1: str.Format("%1f", data[4]);
				m_staticText_Dat1->SetLabel(str);
				break;
		case 2: str.Format("%2f", data[4]);
				m_staticText_Dat1->SetLabel(str);
				break;
		default: str.Format("%f", data[4]);
				 m_staticText_Dat1->SetLabel(str);
				 break;
	}
	switch((int)paramCoef[carType][dataSet[carType][5]][4])
	{
		case 1: str.Format("%1f", data[5]);
				m_staticText_Dat1->SetLabel(str);
				break;
		case 2: str.Format("%2f", data[5]);
				m_staticText_Dat1->SetLabel(str);
				break;
		default: str.Format("%f", data[5]);
				 m_staticText_Dat1->SetLabel(str);
				 break;
	}
	switch((int)paramCoef[carType][dataSet[carType][6]][4])
	{
		case 1: str.Format("%1f", data[6]);
				m_staticText_Dat1->SetLabel(str);
				break;
		case 2: str.Format("%2f", data[6]);
				m_staticText_Dat1->SetLabel(str);
				break;
		default: str.Format("%f", data[6]);
				 m_staticText_Dat1->SetLabel(str);
				 break;
	}
	switch((int)paramCoef[carType][dataSet[carType][7]][4])
	{
		case 1: str.Format("%1f", data[7]);
				m_staticText_Dat1->SetLabel(str);
				break;
		case 2: str.Format("%2f", data[7]);
				m_staticText_Dat1->SetLabel(str);
				break;
		default: str.Format("%f", data[7]);
				 m_staticText_Dat1->SetLabel(str);
				 break;
	}
	switch((int)paramCoef[carType][dataSet[carType][8]][4])
	{
		case 1: str.Format("%1f", data[8]);
				m_staticText_Dat1->SetLabel(str);
				break;
		case 2: str.Format("%2f", data[8]);
				m_staticText_Dat1->SetLabel(str);
				break;
		default: str.Format("%f", data[8]);
				 m_staticText_Dat1->SetLabel(str);
				 break;
	}
	switch((int)paramCoef[carType][dataSet[carType][9]][4])
	{
		case 1: str.Format("%1f", data[9]);
				m_staticText_Dat1->SetLabel(str);
				break;
		case 2: str.Format("%2f", data[9]);
				m_staticText_Dat1->SetLabel(str);
				break;
		default: str.Format("%f", data[9]);
				 m_staticText_Dat1->SetLabel(str);
				 break;
	}
	switch((int)paramCoef[carType][dataSet[carType][10]][4])
	{
		case 1: str.Format("%1f", data[10]);
				m_staticText_Dat1->SetLabel(str);
				break;
		case 2: str.Format("%2f", data[10]);
				m_staticText_Dat1->SetLabel(str);
				break;
		default: str.Format("%f", data[10]);
				 m_staticText_Dat1->SetLabel(str);
				 break;
	}
	switch((int)paramCoef[carType][dataSet[carType][11]][4])
	{
		case 1: str.Format("%1f", data[11]);
				m_staticText_Dat1->SetLabel(str);
				break;
		case 2: str.Format("%2f", data[11]);
				m_staticText_Dat1->SetLabel(str);
				break;
		default: str.Format("%f", data[11]);
				 m_staticText_Dat1->SetLabel(str);
				 break;
	}
	switch((int)paramCoef[carType][dataSet[carType][12]][4])
	{
		case 1: str.Format("%1f", data[12]);
				m_staticText_Dat1->SetLabel(str);
				break;
		case 2: str.Format("%2f", data[12]);
				m_staticText_Dat1->SetLabel(str);
				break;
		default: str.Format("%f", data[12]);
				 m_staticText_Dat1->SetLabel(str);
				 break;
	}
	switch((int)paramCoef[carType][dataSet[carType][13]][4])
	{
		case 1: str.Format("%1f", data[13]);
				m_staticText_Dat1->SetLabel(str);
				break;
		case 2: str.Format("%2f", data[13]);
				m_staticText_Dat1->SetLabel(str);
				break;
		default: str.Format("%f", data[13]);
				 m_staticText_Dat1->SetLabel(str);
				 break;
	}
	switch((int)paramCoef[carType][dataSet[carType][14]][4])
	{
		case 1: str.Format("%1f", data[14]);
				m_staticText_Dat1->SetLabel(str);
				break;
		case 2: str.Format("%2f", data[14]);
				m_staticText_Dat1->SetLabel(str);
				break;
		default: str.Format("%f", data[14]);
				 m_staticText_Dat1->SetLabel(str);
				 break;
	}
	switch((int)paramCoef[carType][dataSet[carType][15]][4])
	{
		case 1: str.Format("%1f", data[15]);
				m_staticText_Dat1->SetLabel(str);
				break;
		case 2: str.Format("%2f", data[15]);
				m_staticText_Dat1->SetLabel(str);
				break;
		default: str.Format("%f", data[15]);
				 m_staticText_Dat1->SetLabel(str);
				 break;
	}
	switch((int)paramCoef[carType][dataSet[carType][16]][4])
	{
		case 1: str.Format("%1f", data[16]);
				m_staticText_Dat1->SetLabel(str);
				break;
		case 2: str.Format("%2f", data[16]);
				m_staticText_Dat1->SetLabel(str);
				break;
		default: str.Format("%f", data[16]);
				 m_staticText_Dat1->SetLabel(str);
				 break;
	}
}

void MyFrame::TimerShow()
{
	wxString str;
	if( timerAddr[carType][0][0] > 0 )
	{
		switch((int)timerCoef[carType][1][4])
		{
			case 1: str.Format("%1f", timer[1]);
					m_staticText_T1->SetLabel(str);
					break;
			case 2: str.Format("%2f", timer[1]);
					m_staticText_T1->SetLabel(str);
					break;
			default:str.Format("%f", timer[1]);
					m_staticText_T1->SetLabel(str);
					break;
		}
	}
	else
		m_staticText_T1->SetLabel(wxT(""));
	if( timerAddr[carType][0][0] > 1 )
	{
		switch((int)timerCoef[carType][2][4])
		{
			case 1: str.Format("%1f", timer[2]);
					m_staticText_T2->SetLabel(str);
					break;
			case 2: str.Format("%2f", timer[2]);
					m_staticText_T2->SetLabel(str);
					break;
			default:str.Format("%f", timer[2]);
					m_staticText_T2->SetLabel(str);
					break;
		}
	}
	else
		m_staticText_T2->SetLabel(wxT(""));
	if( timerAddr[carType][0][0] > 2 )
	{
		switch((int)timerCoef[carType][3][4])
		{
			case 1: str.Format("%1f", timer[3]);
					m_staticText_T3->SetLabel(str);
					break;
			case 2: str.Format("%2f", timer[3]);
					m_staticText_T3->SetLabel(str);
					break;
			default:str.Format("%f", timer[3]);
					m_staticText_T3->SetLabel(str);
					break;
		}
	}
	else
		m_staticText_T3->SetLabel(wxT(""));
	if(timerAddr[carType][0][0] > 3){ str.Format("%f", timer[4]); m_staticText_T4->SetLabel(str);}
	else m_staticText_T4->SetLabel(wxT(""));
	if(timerAddr[carType][0][0] > 4){ str.Format("%f", timer[5]); m_staticText_T5->SetLabel(str);}
	else m_staticText_T4->SetLabel(wxT(""));
	if(timerAddr[carType][0][0] > 5){ str.Format("%f", timer[6]); m_staticText_T6->SetLabel(str);}
	else m_staticText_T4->SetLabel(wxT(""));
	if(timerAddr[carType][0][0] > 6){ str.Format("%f", timer[7]); m_staticText_T7->SetLabel(str);}
	else m_staticText_T4->SetLabel(wxT(""));
	if(timerAddr[carType][0][0] > 7){ str.Format("%f", timer[8]); m_staticText_T8->SetLabel(str);}
	else m_staticText_T4->SetLabel(wxT(""));
	if(timerAddr[carType][0][0] > 8){ str.Format("%f", timer[9]); m_staticText_T9->SetLabel(str);}
	else m_staticText_T4->SetLabel(wxT(""));
	if(timerAddr[carType][0][0] > 9){ str.Format("%f", timer[10]); m_staticText_T10->SetLabel(str);}
	else m_staticText_T4->SetLabel(wxT(""));
	if(timerAddr[carType][0][0] > 10){ str.Format("%f", timer[11]); m_staticText_T11->SetLabel(str);}
	else m_staticText_T4->SetLabel(wxT(""));
	if(timerAddr[carType][0][0] > 11){ str.Format("%f", timer[12]); m_staticText_T12->SetLabel(str);}
	else m_staticText_T4->SetLabel(wxT(""));
	if(timerAddr[carType][0][0] > 12){ str.Format("%f", timer[13]); m_staticText_T13->SetLabel(str);}
	else m_staticText_T4->SetLabel(wxT(""));
	if(timerAddr[carType][0][0] > 13){ str.Format("%f", timer[14]); m_staticText_T14->SetLabel(str);}
	else m_staticText_T4->SetLabel(wxT(""));
	if(timerAddr[carType][0][0] > 14){ str.Format("%f", timer[15]); m_staticText_T15->SetLabel(str);}
	else m_staticText_T4->SetLabel(wxT(""));
	if(timerAddr[carType][0][0] > 15){ str.Format("%f", timer[16]); m_staticText_T16->SetLabel(str);}
	else m_staticText_T4->SetLabel(wxT(""));
}

void MyFrame::AnalogShow()
{
	if(analogAddr[carType][0][0] > 0)
		m_staticText_An1->SetLabel(wxString::Format("%3f", analog[1]));
	else m_staticText_An1->SetLabelText("");
	if(analogAddr[carType][0][0] > 1)
		m_staticText_An1->SetLabel(wxString::Format("%3f", analog[2]));
	else m_staticText_An1->SetLabelText("");
	if(analogAddr[carType][0][0] > 2)
		m_staticText_An1->SetLabel(wxString::Format("%3f", analog[3]));
	else m_staticText_An1->SetLabelText("");
	if(analogAddr[carType][0][0] > 3)
		m_staticText_An1->SetLabel(wxString::Format("%3f", analog[4]));
	else m_staticText_An1->SetLabelText("");
	if(analogAddr[carType][0][0] > 4)
		m_staticText_An1->SetLabel(wxString::Format("%3f", analog[5]));
	else m_staticText_An1->SetLabelText("");
	if(analogAddr[carType][0][0] > 5)
		m_staticText_An1->SetLabel(wxString::Format("%3f", analog[6]));
	else m_staticText_An1->SetLabelText("");
	if(analogAddr[carType][0][0] > 6)
		m_staticText_An1->SetLabel(wxString::Format("%3f", analog[7]));
	else m_staticText_An1->SetLabelText("");
	if(analogAddr[carType][0][0] > 7)
		m_staticText_An1->SetLabel(wxString::Format("%3f", analog[8]));
	else m_staticText_An1->SetLabelText("");
	if(analogAddr[carType][0][0] > 8)
		m_staticText_An1->SetLabel(wxString::Format("%3f", analog[9]));
	else m_staticText_An1->SetLabelText("");
	if(analogAddr[carType][0][0] > 9)
		m_staticText_An1->SetLabel(wxString::Format("%3f", analog[10]));
	else m_staticText_An1->SetLabelText("");
	if(analogAddr[carType][0][0] > 10)
		m_staticText_An1->SetLabel(wxString::Format("%3f", analog[11]));
	else m_staticText_An1->SetLabelText("");
}

