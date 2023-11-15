#include<iostream>
#include<iomanip>
#include<conio.h>
#include<windows.h>
#include<string>
#include<vector>
#include<cstdio>
#include<fstream>
#include"functions.h"

using namespace std;



void createProfile()
{	
	ifstream		readProfile;
	ofstream		writeProfile, writeActiveProfile;
	string			name;
	string			sBuffer;
	size_t			actProfile	= 0;
	vector <string> profilesData{};																

	readProfile.open("Data/profiles.dat");

	if (!readProfile)
	{

	}
	else
	{
		while (!readProfile.eof())
		{
			readProfile >> sBuffer;
			profilesData.push_back(sBuffer);
		}
		readProfile.close();

		if (profilesData.size() > 26)
		{
			cout << "\n\n\n\n\n\t\t\t\tDIE MAXIMALE ANZAHL AN PROFILEN IST ERREICHT ... \n\n\t\t\t\tLÖSCHE ZUNÄCHST EIN ODER MEHRERE PROFILE BEVOR DU NEUE PROFILE ANLEGST";
			Sleep(7300);

			return;
		}
	}

	system("cls");

	set_cursor(true);

	while (name != "\b")
	{
		size_t found = 0;
		
		system("cls");

		cout << "\n\n\n\n\n\n\n\n\n\n\tGIB EINEN PROFILNAMEN EIN : ";

		getline(cin, name);

		found = name.find(" ");

		if (found != string::npos)
		{
			cout << "\n\n\n\nBITTE GIB EINEN PROFILNAMEN EIN DER KEINE LEERZEICHEN ENTHÄLT !\n\n";
			cout << "Du kannst aber Unterstriche [_] oder Bindestriche [-] verwenden, wenn Du möchtest ...\n\n\n\n\n\n";
			cout << "DRÜCKE EINE BELIEBIGE TASTE UM EINEN NEUEN NAMEN FESTZULEGEN ...";
			name = _getch();
		}
		else
		{
			profilesData.push_back(name);
			profilesData.push_back("0");
			profilesData.push_back("0");
						
			writeProfile.open("Data/profiles.dat");
			
			for (size_t i = 0; i < profilesData.size(); i++)
			{
				writeProfile << "\n" << profilesData[i];
				actProfile = (i - 2);
			}
			
			writeProfile.close();

			readProfile.open("Data/profiles.dat");

			set_cursor(false);

			if (!readProfile)
			{
				cout << "\n\n\n" << "\tFEHLER BEIM ERSTELLEN DES PROFILS !";
			}
			else
			{
				cout << "\n\n\n" << "\tPROFIL ERFOLGREICH ERSTELLT !";
			}

			readProfile.close();

			writeActiveProfile.open("Data/activeProfile.ini");
			writeActiveProfile << actProfile;
			writeActiveProfile.close();

			name = "\b";
			Sleep(3000);
		}
	}	
}

void changeProfile()
{
	ifstream readProfiles;
	ofstream writeActiveProfile;
	vector <string> profiles{};
	size_t select = 0;
	size_t getString = 0;
	bool success = false;
		
	while (success != true)
	{
		system("cls");

		cout << "\n\n\t\t\t\t   WÄHLE DAS PROFIL WELCHES AKTIVIERT WERDEN SOLL ...\n\n\n";

		readProfiles.open("Data/profiles.dat");

		if (!readProfiles)
		{
			cout << "\t\t\t\t\t  KANN profiles.dat NICHT ÖFFNEN !!!";

			Sleep(4000);

			return;
		}
		else
		{
			string readBuffer;

			for (size_t i = 0; !readProfiles.eof(); i++)
			{
				readProfiles >> readBuffer;

				if (getString == i)
				{
					profiles.push_back(readBuffer);
					getString = (i + 3);
				}
			}

			readProfiles.close();

			for (size_t i = 0; i < profiles.size(); i++)							// Ausgabe der verfügbaren Profile !
			{
				cout << "\t\t\t\t\t\t[" << (i + 1) << "] " << profiles[i] << "\n";
			}

			select = _getch();

			if (select < 49 || select > profiles.size() + 48)
			{
				cout << "\n\n\n\tDU HAST KEIN GÜLTIGES PROFIL GEWÄHLT ...";

				Sleep(1550);
			}
			else if (select == 49)
			{
				select -= 49;

				writeActiveProfile.open("Data/activeProfile.ini");
				writeActiveProfile << select;
				writeActiveProfile.close();

				cout << "\n\n\n\n\t\t\t\t\t     AKTIVES PROFIL GEÄNDERT";

				success = true;
			}
			else
			{
				select = ((select - 49) * 3);

				writeActiveProfile.open("Data/activeProfile.ini");
				writeActiveProfile << select;
				writeActiveProfile.close();

				cout << "\n\n\n\n\t\t\t\t\t     AKTIVES PROFIL GEÄNDERT";

				success = true;
			}

			Sleep(3300);
		}
	}
}

void deleteProfile()												// Funktion für das Löschen des aktuellen Profils
{
	system("cls");
	set_cursor(false);

	ifstream readProfilesData;
	ofstream writeProfilesData;
	vector <string> profilesData{};
	vector <string> profileSelectData{};
	string buffer;
	string authorize;
	size_t getString = 0;
	size_t delVlinesBegin = 0;
	size_t delVlinesEnd = 0;
	size_t choice = 0;


	readProfilesData.open("Data/profiles.dat");

	if (!readProfilesData)
	{
		cout << "FEHLER >>> KANN PROFILDATENDATEI NICHT FINDEN ODER ÖFFNEN ! <<<";
		Sleep(5500);
	}
	else
	{

		for (size_t i = 0; !readProfilesData.eof(); i++)
		{
			readProfilesData >> buffer;
			profilesData.push_back(buffer);

			if (getString == i)
			{
				profileSelectData.push_back(buffer);
				getString = (i + 3);
			}
		}

		readProfilesData.close();

		cout << "\n\n\n\n\n\t\t\t\t\tWELCHES PROFIL SOLL GELÖSCHT WERDEN ?\n\n\n";

		for (size_t i = 0; i < profileSelectData.size(); i++)
		{
			cout << "\t\t\t\t\t\t[" << (i + 1) << "] " << profileSelectData[i] << "\n";
		}

		choice = _getch();

		if ((choice - 49) > profileSelectData.size() - 1)
		{
			cout << "\n\n\n\t\t\t\t\t\t  FALSCHE EINGABE ...";

			Sleep(3300);

			return;
		}
		else
		{
			cout << "\n\n\tPROFIL " << profileSelectData[choice - 49] << " WIRKLICH LÖSCHEN ?   [j] | [n]";

			set_cursor(true);

			authorize = _getch();

			set_cursor(false);

			if (authorize == "j")
			{
				if (profilesData.size() < 4)
				{
					remove("Data/profiles.dat");									// Anweisung zum löschen einer bestimmten Datei !!!
					remove("Data/activeProfile.ini");

					Sleep(650);

					readProfilesData.open("Data/profiles.dat");

					if (!readProfilesData)
					{
						system("cls");

						cout << "\n\n\n\n\n\t\t\t\t\t   ";
						cout << "P ";
						Sleep(50);
						cout << "R ";
						Sleep(50);
						cout << "O ";
						Sleep(50);
						cout << "F ";
						Sleep(50);
						cout << "I ";
						Sleep(50);
						cout << "L ";
						Sleep(50);
						cout << "  ";
						Sleep(50);
						cout << "G ";
						Sleep(50);
						cout << "E ";
						Sleep(50);
						cout << "L ";
						Sleep(50);
						cout << "Ö ";
						Sleep(50);
						cout << "S ";
						Sleep(50);
						cout << "C ";
						Sleep(50);
						cout << "H ";
						Sleep(50);
						cout << "T ";
						Sleep(50);
						cout << "  ";
						Sleep(50);
						cout << "! ";
						Sleep(3300);
					}
					else
					{
						cout << "\n\n\n\tFEHLER BEIM LÖSCHEN DER PROFILDATEI !";
						Sleep(3300);

						return;
					}

					readProfilesData.close();
				}
				else
				{
					if (choice == 49)
					{
						delVlinesBegin = (choice - 49);
					}
					else if (choice == 50)
					{
						delVlinesBegin = (choice - 49) + 2;
					}
					else if (choice == 51)
					{
						delVlinesBegin = (choice - 49) + 4;
					}
					else if (choice == 52)
					{
						delVlinesBegin = (choice - 49) + 6;
					}
					else if (choice == 53)
					{
						delVlinesBegin = (choice - 49) + 8;
					}
					else if (choice == 54)
					{
						delVlinesBegin = (choice - 49) + 10;
					}
					else if (choice == 55)
					{
						delVlinesBegin = (choice - 49) + 12;
					}
					else if (choice == 56)
					{
						delVlinesBegin = (choice - 49) + 14;
					}
					else if (choice == 57)
					{
						delVlinesBegin = (choice - 49) + 16;
					}

					Sleep(1000);

					remove("Data/profiles.dat");									// Anweisung zum löschen einer bestimmten Datei !!!

					Sleep(350);

					readProfilesData.open("Data/profiles.dat");

					if (!readProfilesData)
					{
						system("cls");

						cout << "\n\n\n\n\n\t\t\t\t\t   ";
						cout << "P ";
						Sleep(50);
						cout << "R ";
						Sleep(50);
						cout << "O ";
						Sleep(50);
						cout << "F ";
						Sleep(50);
						cout << "I ";
						Sleep(50);
						cout << "L ";
						Sleep(50);
						cout << "  ";
						Sleep(50);
						cout << "G ";
						Sleep(50);
						cout << "E ";
						Sleep(50);
						cout << "L ";
						Sleep(50);
						cout << "Ö ";
						Sleep(50);
						cout << "S ";
						Sleep(50);
						cout << "C ";
						Sleep(50);
						cout << "H ";
						Sleep(50);
						cout << "T ";
						Sleep(50);
						cout << "  ";
						Sleep(50);
						cout << "! ";
						Sleep(3300);
					}
					else
					{
						cout << "\n\n\n\tFEHLER BEIM LÖSCHEN UND NEUERSTELLEN DER PROFILDATEI !";
						Sleep(3300);
						return;
					}

					readProfilesData.close();

					profilesData.erase(next(profilesData.begin(), delVlinesBegin), next(profilesData.begin(), (delVlinesBegin + 3)));

					Sleep(500);

					writeProfilesData.open("Data/profiles.dat");

					for (int i = 0; i < profilesData.size(); i++)
					{
						writeProfilesData << "\n" << profilesData[i];
					}

					writeProfilesData.close();

					changeProfile();
				}

			}
			else
			{
				cout << "\n\n\n\n\n\t\t\t\t\tABBRUCH UND ZURÜCK ZUM MENÜ ...\n\n";
				Sleep(3300);
			}
		}
	}

	//ifstream	check, getProfileName;
	//ofstream	writeProfileName;
	//string		name;
	//string		authorise;

	//getProfileName.open("activeProfile.ini");

	//getProfileName >> name;
	//getProfileName.close();
	//name.append(".dat");

	//check.open(name);

	//if (!check)
	//{
	//	cout << name;
	//	cout << "\n\n\n\n\n\n\tPROFIL-DATEI NICHT GEFUNDEN !!!";
	//	Sleep(3300);
	//}
	//else
	//{
	//	cout << "\n\n\n\n\n\n\tBIST DU SICHER DAS DU DIE PROFIL-DATEI [ " << name << " ] LÖSCHEN WILLST ?\n\n" << "\t[J] eingeben zum Löschen der Datei, [N] um abzubrechen: "; cin >> authorise;

	//	if (authorise == "j")
	//	{
	//		check.close();
	//		Sleep(450);
	//		remove(name.c_str());									// Anweisung zum löschen einer bestimmten Datei !!!
	//		check.open(name);

	//		if (!check)
	//		{
	//			cout << "\n\n\n\tLÖSCHEN WAR ERFOLGREICH !";
	//			writeProfileName.open("activeProfile.dat");
	//			writeProfileName << "KEIN_PROFIL_GEWÄHLT";
	//			writeProfileName.close();
	//			Sleep(3000);
	//		}
	//		else
	//		{
	//			cout << "\n\n\n\tFEHLER BEIM LÖSCHEN DER DATEI !";
	//			Sleep(3000);
	//		}
	//	}
	//	else
	//	{
	//		cout << "\n\n\n\tABBRUCH !!!";
	//		Sleep(3000);
	//	}
	//}	

	//check.close();
	//set_cursor(false);
}

void profileManagement()
{	

	set_cursor(false);
	
	char input = ' ';

	while (input != '\b')
	{
		system("cls");

		cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t[N] NEUES PROFIL ANLEGEN\n\n";
		cout << "\t\t\t\t\t[W] AKTUELLES PROFIL WECHSELN\n\n";
		cout << "\t\t\t\t\t[L] EIN PROFIL LÖSCHEN\n\n\n";
		cout << "\t\t\t\t\t[BACKSPACE <--] ZURÜCK ZUM HAUPTMENÜ";

		input = _getch();

		switch (input)
		{
		case 'n':
		{
			createProfile();
		}
		break;
		case 'w':
		{
			changeProfile();
		}
		break;
		case 'l':
		{
			deleteProfile();
		}
		break;
		case '\b':
		{

		}
		break;

		default: cout << "\n\n\n\t\t\t\t\t\tFALSCHE EINGABE !!!"; Sleep(800);
		}
	}
}