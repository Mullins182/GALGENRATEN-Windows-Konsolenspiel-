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
	int getString = 0;

	readProfiles.open("profiles.dat");

	if (!readProfiles)
	{
		system("cls");

		cout << "\n\n\n\n\n\n\n\n\t\tFEHLER ... KANN KEIN AKTUELLES PROFIL FINDEN ... BITTE ERSTELLE ERST EIN PROFIL !";
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

		cout << setfill('°') << setw(121) << "°\n";
		cout << "\t\t\t\t\t\t   H I G H S C O R E\n";
		//cout << setfill('°') << setw(121) << "°\n";
		
		for (size_t i = 0; i < profileData.size(); i++)
		{			
			if (getString == i)
			{
				cout << setfill('_') << setw(121) << "_\n";
				cout << "\t" << profileData[i] << ": \n";
				cout << "\t\t\t\t    [" << profileData[i + 1] << "] Runden gewonnen UND [" << profileData[i + 2] << "] Runden verloren !\n" << flush;
				getString = (i + 3);
			}			
		}

		cout << setfill(' ') << "\t\t\t\t\t\t\t\t\t\t\t\t  DRÜCKE [BACKSPACE <--]";

		while (choice != "\b")
		{
			choice = _getch();
		}
	}
}