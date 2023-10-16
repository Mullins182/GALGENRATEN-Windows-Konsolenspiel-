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
	vector <string> profilesData{};																// IN ARBEIT !!!

	readProfile.open("profiles.dat");

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
	}

	system("cls");

	set_cursor(true);

	while (name != "\b")
	{
		size_t found = 0;
		
		system("cls");

		cout << "GIB EINEN PROFILNAMEN EIN : ";

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
						
			writeProfile.open("profiles.dat");
			
			for (size_t i = 0; i < profilesData.size(); i++)
			{
				writeProfile << "\n" << profilesData[i];
				actProfile = (i - 2);
			}
			
			writeProfile.close();

			readProfile.open("profiles.dat");

			set_cursor(false);

			if (!readProfile)
			{
				cout << "\n\n\n" << "FEHLER BEIM ERSTELLEN DES PROFILS !";
			}
			else
			{
				cout << "\n\n\n" << "PROFIL ERFOLGREICH ERSTELLT !";
			}

			readProfile.close();

			writeActiveProfile.open("activeProfile.ini");
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

	system("cls");

	cout << "\n\n\t\t\t\t   WÄHLE DAS PROFIL WELCHES AKTIVIERT WERDEN SOLL ...\n\n\n";

	readProfiles.open("profiles.dat");

	if (!readProfiles)
	{
		cout << "\tKANN profiles.dat NICHT ÖFFNEN !!!";
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
			cout << "\n\n\n\tDU HAST KEINEN GÜLTIGEN EINTRAG GEWÄHLT ...";
		}
		else if (select == 49)
		{
			select -= 49;

			writeActiveProfile.open("activeProfile.ini");
			writeActiveProfile << select;
			writeActiveProfile.close();

			cout << "\n\n\n\n\t\t\t\t\t        AKTIVES PROFIL GEÄNDERT";
		}
		else
		{
			
			
			select = ((select - 49) * 3);

			writeActiveProfile.open("activeProfile.ini");
			writeActiveProfile << select;
			writeActiveProfile.close();

			cout << "\n\n\n\n\t\t\t\t\t        AKTIVES PROFIL GEÄNDERT";
		}

		Sleep(3300);
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
	size_t getString = 0;;
	string choice;

	readProfilesData.open("profiles.dat");

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
		cout << "\t\t\t\t\t[L] AKTUELLES PROFIL LÖSCHEN\n\n\n";
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