#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<conio.h>
#include<fstream>

#include"functions.h"

using namespace std;


void options()
{
	system("chcp 1252");
	ifstream read_ini;
	int o = 0;
	int opt_bg = 0;
	bool vis_effects = true;
	bool snd_effects = true;
	bool snd_mChoice = true;
	bool snd_winOrLoose = true;
	bool snd_keyTap = true;
	bool menu_music = true;
	string effects;
	string sndEffects;
	string sndWinLoose;
	string sndMenuChoice;
	string sndKeyTap;
	string music;

	while (o != 56)
	{
		//sndPlaySound("opt_select.wav", SND_FILENAME | SND_ASYNC);

		read_ini.open("options.ini");
		read_ini >> opt_bg >> vis_effects >> snd_effects >> snd_mChoice >> snd_keyTap >> snd_winOrLoose >> menu_music;
		read_ini.close();
		system("cls");

		if (vis_effects == true)
		{
			effects = "AN";
		}
		else
		{
			effects = "AUS";
		}

		if (snd_effects == true)
		{
			sndEffects = "AN";
		}
		else
		{
			sndEffects = "AUS";
		}

		if (snd_mChoice == true)
		{
			sndMenuChoice = "AN";
		}
		else
		{
			sndMenuChoice = "AUS";
		}

		if (snd_winOrLoose == true)
		{
			sndWinLoose = "AN";
		}
		else
		{
			sndWinLoose = "AUS";
		}

		if (snd_keyTap == true)
		{
			sndKeyTap = "AN";
		}
		else
		{
			sndKeyTap = "AUS";
		}

		if (menu_music == true)
		{
			music = "AN";
		}
		else
		{
			music = "AUS";
		}

		cout << "\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t  [1] Hintergrundfarbe ändern\n\n";
		cout << "\t\t\t\t  [2] Effekte (Blinken bei Sieg oder Niederlage)\t: " << effects << "\n\n";
		cout << "\t\t\t\t  [3] Soundeffekte\t\t\t\t\t: " << sndEffects << "\n\n";
		if (snd_effects == true)
		{
			cout << "\t\t\t\t  [4] Soundeffekt Menüauswahl-Sound\t\t\t: " << sndMenuChoice << "\n\n";
			cout << "\t\t\t\t  [5] Soundeffekt Tastendruck-Sound beim Spielen\t: " << sndKeyTap << "\n\n";
			cout << "\t\t\t\t  [6] Soundeffekt wenn Gewonnen oder Verloren\t\t: " << sndWinLoose << "\n\n";
		}
		cout << "\t\t\t\t  [7] Hauptmenü-Musik\t\t\t\t\t: " << music << "\n\n";
		cout << "\n\t\t\t\t  [8] Zurück zum Hauptmenu ...\n\n";

		o = _getch();

		switch (o)
		{
		case 49:
			
			if (snd_mChoice == true)
			{
				sndPlaySound("opt_select.wav", SND_FILENAME | SND_ASYNC);
			}

			if (opt_bg == 1)
			{
				bgColor("white");
				system("cls");
				textColor("black");
				opt_bg = 2;
				write_ini_file(opt_bg, vis_effects, snd_effects, snd_mChoice, snd_keyTap, snd_winOrLoose, menu_music);
			}
			else if (opt_bg == 2)
			{
				bgColor("bwhite");
				system("cls");
				textColor("black");
				opt_bg = 3;
				write_ini_file(opt_bg, vis_effects, snd_effects, snd_mChoice, snd_keyTap, snd_winOrLoose, menu_music);
			}
			else if (opt_bg == 3)
			{
				bgColor("byellow");
				system("cls");
				textColor("black");
				opt_bg = 4;
				write_ini_file(opt_bg, vis_effects, snd_effects, snd_mChoice, snd_keyTap, snd_winOrLoose, menu_music);
			}
			else if (opt_bg == 4)
			{
				bgColor("blue");
				system("cls");
				textColor("byellow");
				opt_bg = 5;
				write_ini_file(opt_bg, vis_effects, snd_effects, snd_mChoice, snd_keyTap, snd_winOrLoose, menu_music);
			}
			else if (opt_bg == 5)
			{
				bgColor("black");
				system("cls");
				textColor("bwhite");
				opt_bg = 1;
				write_ini_file(opt_bg, vis_effects, snd_effects, snd_mChoice, snd_keyTap, snd_winOrLoose, menu_music);
			}

			break;

		case 50:

			if (snd_mChoice == true)
			{
				sndPlaySound("opt_select.wav", SND_FILENAME | SND_ASYNC);
			}

			if (vis_effects == true)
			{
				vis_effects = false;
				write_ini_file(opt_bg, vis_effects, snd_effects, snd_mChoice, snd_keyTap, snd_winOrLoose, menu_music);
			}
			else
			{
				vis_effects = true;
				write_ini_file(opt_bg, vis_effects, snd_effects, snd_mChoice, snd_keyTap, snd_winOrLoose, menu_music);
			}

			break;

		case 51:

			if (snd_mChoice == true)
			{
				sndPlaySound("opt_select.wav", SND_FILENAME | SND_ASYNC);
			}

			if (snd_effects == true)
			{
				snd_effects		= false;
				snd_mChoice		= false;
				snd_keyTap		= false;
				snd_winOrLoose	= false;
				write_ini_file(opt_bg, vis_effects, snd_effects, snd_mChoice, snd_keyTap, snd_winOrLoose, menu_music);
			}
			else
			{
				snd_effects		= true;
				snd_mChoice		= true;
				snd_keyTap		= true;
				snd_winOrLoose	= true;
				write_ini_file(opt_bg, vis_effects, snd_effects, snd_mChoice, snd_keyTap, snd_winOrLoose, menu_music);
			}

			break;

		case 52:

			if (snd_effects == true)
			{
				if (snd_mChoice == true)
				{
					sndPlaySound("opt_select.wav", SND_FILENAME | SND_ASYNC);

					snd_mChoice = false;
					write_ini_file(opt_bg, vis_effects, snd_effects, snd_mChoice, snd_keyTap, snd_winOrLoose, menu_music);
				}
				else
				{
					snd_mChoice = true;
					write_ini_file(opt_bg, vis_effects, snd_effects, snd_mChoice, snd_keyTap, snd_winOrLoose, menu_music);
				}
			}

			break;

		case 53:

			if (snd_effects == true)
			{
				if (snd_mChoice == true)
				{
					sndPlaySound("opt_select.wav", SND_FILENAME | SND_ASYNC);
				}

				if (snd_keyTap == true)
				{
					snd_keyTap = false;
					write_ini_file(opt_bg, vis_effects, snd_effects, snd_mChoice, snd_keyTap, snd_winOrLoose, menu_music);
				}
				else
				{
					snd_keyTap = true;
					write_ini_file(opt_bg, vis_effects, snd_effects, snd_mChoice, snd_keyTap, snd_winOrLoose, menu_music);
				}
			}			

			break;

		case 54:

			if (snd_effects == true)
			{
				if (snd_mChoice == true)
				{
					sndPlaySound("opt_select.wav", SND_FILENAME | SND_ASYNC);
				}

				if (snd_winOrLoose == true)
				{
					snd_winOrLoose = false;
					write_ini_file(opt_bg, vis_effects, snd_effects, snd_mChoice, snd_keyTap, snd_winOrLoose, menu_music);
				}
				else
				{
					snd_winOrLoose = true;
					write_ini_file(opt_bg, vis_effects, snd_effects, snd_mChoice, snd_keyTap, snd_winOrLoose, menu_music);
				}
			}			

			break;

		case 55:

			if (snd_mChoice == true)
			{
				sndPlaySound("opt_select.wav", SND_FILENAME | SND_ASYNC);
			}

			if (menu_music == true)
			{
				menu_music = false;
				write_ini_file(opt_bg, vis_effects, snd_effects, snd_mChoice, snd_keyTap, snd_winOrLoose, menu_music);
			}
			else
			{
				menu_music = true;
				write_ini_file(opt_bg, vis_effects, snd_effects, snd_mChoice, snd_keyTap, snd_winOrLoose, menu_music);
			}

			break;

		case 56:

			if (snd_mChoice == true)
			{
				sndPlaySound("opt_select.wav", SND_FILENAME | SND_ASYNC);
			}

			cout << "\n\n\t\t\t\t\t  Zurück zum Hauptmenu ...";

			Sleep(1000);

			break;

		default: cout << "\t\t\t\t\t\t   Falsche Eingabe !!!"; Sleep(1200);

		}
	}
}