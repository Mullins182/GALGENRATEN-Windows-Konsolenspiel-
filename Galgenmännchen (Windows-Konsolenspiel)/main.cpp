#include<iostream>
#include<iomanip>
#include<conio.h>
#include<string>
#include<vector>
#include<Windows.h>
#include<mmsystem.h>
#include<strsafe.h>
#include<tchar.h>
#include<random>
#include<time.h>
#include<fstream>
#include"functions.h"
#pragma comment(lib, "Winmm.lib")									// Für Soundwiedergabe erforderlich !																			

using namespace std;

int main()										// Galgenraten (Hangman) Konsolenspiel created by Mullins182 ...
{	
	ifstream read_ini, read_profiles;
	ofstream write_ini, writeActiveProfile;
	vector <string>	profiles{};
	int				colors				= 0;
	bool			effects				= true;
	bool			snd_effects			= true;
	bool			snd_menu			= true;
	bool			snd_keys			= true;
	bool			snd_winLoose		= true;
	bool			menu_music			= true;
	bool			musicPlaying		= false;
	string			gameVersion			= "Version 4.0";
	int				activeProfile		= 0;
	char			choose				= 'x';
	string			activeProfileName;
	string			readBuffer;
	string			music_set;
	
	system("chcp 1252");

	TCHAR szOldTitle[MAX_PATH];										// Verändern des Konsolenfenster-Titels
	TCHAR szNewTitle[MAX_PATH];

	// Save current console title.

	if (GetConsoleTitle(szOldTitle, MAX_PATH))
	{
		// Build new console title string.

		StringCchPrintf(szNewTitle, MAX_PATH, TEXT("H A N G M A N"));

		// Set console title to new title
		if (!SetConsoleTitle(szNewTitle))
		{
			_tprintf(TEXT("SetConsoleTitle failed (%d)\n"), GetLastError());
			return 1;
		}
		else
		{
			_tprintf(TEXT("SetConsoleTitle succeeded.\n"));
		}
	}																// Verändern des Konsolenfenster-Titels ENDE !

	while (choose != 'q')
	{
		profiles.clear();
		
		read_ini.open("Data/options.ini");
		
		if (!read_ini)																							
		{
			write_ini.open("Data/options.ini");
			write_ini << '4' << '\n' << 1 << '\n' << 1 << '\n' << 1 << '\n' << 1 << '\n' << 1 << '\n' << 1;		// Standard Initialisierung der Optionen
			write_ini.close();
			read_ini.open("Data/options.ini");
		}

		read_ini >> colors >> effects >> snd_effects >> snd_menu >> snd_keys >> snd_winLoose >> menu_music;
		read_ini.close();

		Sleep(666);
				
		set_cursor(false);																						// Cursor verstecken

		if (menu_music == true)
		{			
			if (!musicPlaying)
			{
				read_ini.open("Data/music.ini");

				if (!read_ini)
				{
					read_ini.close();
					write_ini.open("Data/music.ini");
					write_ini << "Data/Audio/Music/Honolulu.wav";
					write_ini.close();
					read_ini.open("Data/music.ini");
					read_ini >> music_set;
					musicPlaying = sndPlaySound(music_set.c_str(), SND_FILENAME | SND_ASYNC | SND_LOOP);			// Hintergrundmusik
				}
				else
				{
					read_ini >> music_set;
					musicPlaying = sndPlaySound(music_set.c_str(), SND_FILENAME | SND_ASYNC | SND_LOOP);			// Hintergrundmusik
				}

				read_ini.close();
			}			
		}
		else
		{
			sndPlaySound(NULL, SND_FILENAME | SND_ASYNC);											// Musikunterbrecher
			musicPlaying = false;
		}
		
		if (colors == 1)
		{
			bgColor("black");
			system("cls");
			textColor("bwhite");
		}
		else if (colors == 2)
		{
			bgColor("white");
			system("cls");
			textColor("black");
		}
		else if (colors == 3)
		{
			bgColor("bwhite");
			system("cls");
			textColor("black");
		}
		else if (colors == 4)
		{
			bgColor("byellow");
			system("cls");
			textColor("black");
		}						
		else if (colors == 5)																					
		{
			bgColor("blue");
			system("cls");
			textColor("byellow");
		}																										// Initialisierung ENDE !!!

		read_profiles.open("Data/profiles.dat");															// Profil-Initialisierung

		if (!read_profiles)
		{
			activeProfileName = "KEIN PROFIL ERSTELLT !";
		}
		else
		{
			while (!read_profiles.eof())
			{
				read_profiles >> readBuffer;
				profiles.push_back(readBuffer);
			}

			read_profiles.close();
			read_ini.open("Data/activeProfile.ini");															

			if (!read_ini)
			{
				writeActiveProfile.open("Data/activeProfile.ini");
				writeActiveProfile << "0";
				writeActiveProfile.close();

				read_ini >> activeProfile;
			}
			else
			{
				read_ini >> activeProfile;
			}

			read_ini.close();
			activeProfileName = profiles[activeProfile];
		}

		cout << "Profil geladen: " << activeProfileName << "\n";									// Profil Initialisierung ENDE !!!

		mainmenu_art();
		cout << "\t\t\t\t\t\t\t" << gameVersion << "\n";
		hangman_art();

		choose = _getch();

		switch (choose)
		{

		case 'p':

			profileManagement();

					break;

		case 'h':

			highscore(activeProfile);

			break;
		
		case ' ':

			read_profiles.open("Data/profiles.dat");

			if (!read_profiles)
			{
				cout << "\t\t\t       BITTE ERSTELLE ZUERST EIN PROFIL BEVOR DU MIT DEM SPIEL BEGINNST";

				Sleep(5300);
			}
			else
			{
				read_profiles.close();

				if (snd_menu == true)
				{
					sndPlaySound("Data/Audio/SndEffects/menu_option.wav", SND_FILENAME | SND_ASYNC);
				}



				Sleep(1800);

				musicPlaying = false;

				hangman(gameVersion, colors, effects, snd_effects, snd_keys, snd_winLoose, activeProfile);
			}
	
					break;

		case 'o':

			if (snd_menu == true)
			{
				sndPlaySound("Data/Audio/SndEffects/menu_option.wav", SND_FILENAME | SND_ASYNC);
			}

			musicPlaying = false;

				options();

					break;
		
		case 'q':

			if (snd_menu == true)
			{
				sndPlaySound("Data/Audio/SndEffects/menu_option.wav", SND_FILENAME | SND_ASYNC);
			}

			cout << "\t\t\t\t\t\t" << "Spiel wird beendet";
			
			for (int i = 0; i < 10; i++)
			{
				Sleep(180);
				cout << ". ";
			}

					break;

		default: cout << "\t\t\t\t\t\t   FALSCHE EINGABE !!!"; Sleep(1200);
		}
		
	}

	return 0;
}

// ASCII Art by www.patorjk.com (ASCII-Art Generator)

//   _   _    __    __  __  ____  ____  __  __  ____  _  _  __  __ 
//  ( )_( )  /__\  (  )(  )(  _ \(_  _)(  \/  )( ___)( \( )(  )(  )
//   ) _ (  /(__)\  )(__)(  )___/  )(   )    (  )__)  )  (  )(__)( 
//  (_) (_)(__)(__)(______)(__)   (__) (_/\/\_)(____)(_)\_)(______)
