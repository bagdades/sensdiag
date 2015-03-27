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
	m_timerSystem.Start(sysTimerPeriod, wxTIMER_CONTINUOUS);
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
				init = FALSE;
			}
			else
			{
				check = serialPort.Open(portName, 10400);
				init = TRUE;
				timerPeriod = 50;
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
		m_timer1.Start(timerPeriod, wxTIMER_ONE_SHOT);
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
		m_timer1.Stop();
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
	// TODO: Implement OnCheckLogProtocol
}

void MyFrame::OnTimerTick( wxTimerEvent& event )
{
	// TODO: Implement OnTimerTick
}

void MyFrame::OnSysTimerTick( wxTimerEvent& event )
{
	wxDateTime now = wxDateTime::Now();
	now.SetCountry(wxDateTime::UK);
	wxString date;
	date = now.Format(wxT("%X"));
	m_statusBar->SetStatusText(date,3);
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

