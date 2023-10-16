#include<iostream>
#include<fstream>
#include<conio.h>
#include<Windows.h>
#include<vector>
#include<iomanip>
#include"functions.h"

using namespace std;





void highscore(size_t profile)
{
	
	ifstream readProfiles;
	vector <string> profileData{};
	string buffer;
	string choice;

	readProfiles.open("profiles.dat");

	if (!readProfiles)
	{
		system("cls");

		cout << "\n\n\n\n\n\n\n\n\t\t\tFEHLER ... KANN KEIN AKTUELLES PROFIL FINDEN ... BITTE ERSTELLE ERST EIN PROFIL !";
		Sleep(5500);
	}
	else
	{
		while (!readProfiles.eof())
		{
			readProfiles >> buffer;
			profileData.push_back(buffer);
		}

		readProfiles.close();

		set_cursor(false);
		
		system("cls");

		cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t      H I G H S C O R E";
		cout << "\n\n\n";
		cout << "\t\t\tHALLO " << profileData[profile] << "." << " DU hast bisher insgesamt " << profileData[profile + 1] << " mal gewonnen und " << profileData[profile + 2] << " mal verloren !";
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "DRÜCKE [BACKSPACE <--] UM ZUM HAUPTMENÜ ZURÜCKZUKEHREN";

		while (choice != "\b")
		{
			choice = _getch();
		}
	}
}