#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<cctype>
#include<string>
#include<vector>
#include<conio.h>
#include<Windows.h>
#include"functions.h"

using namespace std;

void hangman(string gameVersion, int colors, bool effects, bool snd_effects, bool snd_keys, bool snd_winLoose, size_t activeProfile)
{
	sndPlaySound("Data/Audio/SndEffects/silence.wav", SND_FILENAME | SND_NODEFAULT);

	set_cursor(false);

	vector <string> usedRandomWords{ "XXXXXXXxxxxxxxXXXXXX" };
	vector <string> profiles{};
	ofstream writeToProfile;
	ifstream readProfiles;
	string activeProfileName;
	string input				= "a";
	unsigned int won			= 0;
	unsigned int lost			= 0;
	unsigned int profileWon		= 0;
	unsigned int profileLost	= 0;

	while (input != "\b")
	{
		input					= "";
		unsigned int countdown	= 11;
		size_t posWord				= 0;
		int dummy				= 0;
		string readBuffer;
		string searchedWord		= "";
		string foundChars;
		char charInput			= ' ';
		string actualWord;
		string bg_color;
		string txt_color;


		readProfiles.open("Data/profiles.dat");

		if (!readProfiles)
		{
			activeProfileName = "KEIN PROFIL ERSTELLT !";
		}
		else
		{
			while (!readProfiles.eof())
			{
				readProfiles >> readBuffer;
				profiles.push_back(readBuffer);
			}

			readProfiles.close();

			activeProfileName = profiles[activeProfile];
			profileWon	= stoi(profiles[activeProfile + 1]);
			profileLost = stoi(profiles[activeProfile + 2]);

		}

			if (colors == 1)												// Farbgebung !
			{
				bg_color = "black";
				txt_color = "bwhite";
				bgColor("black");
				system("cls");
				textColor("bwhite");
			}
			else if (colors == 2)
			{
				bg_color = "white";
				txt_color = "black";
				bgColor("white");
				system("cls");
				textColor("black");
			}
			else if (colors == 3)
			{
				bg_color = "bwhite";
				txt_color = "black";
				bgColor("bwhite");
				system("cls");
				textColor("black");
			}
			else if (colors == 4)
			{
				bg_color = "byellow";
				txt_color = "black";
				bgColor("byellow");
				system("cls");
				textColor("black");
			}
			else if (colors == 5)
			{
				bg_color = "blue";
				txt_color = "byellow";
				bgColor("blue");
				system("cls");
				textColor("byellow");
			}

			cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\t    BITTE WARTEN ...";
			
			// Methode zur Verhinderung das das gleiche Wort in einer Spielrunde zweimal gesucht wird !
			JumpBack:
			searchedWord = randomWordGenerating();								// Funktion zur zufälligen Auswahl eines Wortes aus der Wortlistendatei

			for (int i = 0; i < usedRandomWords.size(); i++)
			{
				if (usedRandomWords.at(i) == searchedWord)
				{
					goto JumpBack;
				}
				else
				{

				}
			}

			usedRandomWords.push_back(searchedWord);

			// -----------------  ENDE dieser Methode -------------------

			for (int i = 0; i < searchedWord.size(); i++)
			{
				actualWord.append("_");
			}

			while (charInput != '\b')
			{
				//bgColor("byellow");

				system("cls");

				//textColor("bblack");

				cout << gameVersion << "\t\t" << "Aktives Profil: " << activeProfileName << " | Gewonnene Runden: " << won << " | Verloren: " << lost << "\n";

				if (searchedWord.find(charInput) != string::npos)				// Char in String finden. Wenn find CharInput nicht npos, wurde der Char im String gefunden !
				{
					countdown = countdown;
				}
				else
				{
					countdown -= 1;
				}

				//textColor("black");

				if (countdown == 10)
				{
					hangman_build_1();
				}
				else if (countdown == 9)
				{
					hangman_build_2();
				}
				else if (countdown == 8)
				{
					hangman_build_3();
				}
				else if (countdown == 7)
				{
					hangman_build_4();
				}
				else if (countdown == 6)
				{
					hangman_build_5();
				}
				else if (countdown == 5)
				{
					hangman_build_6();
				}
				else if (countdown == 4)
				{
					hangman_build_7();
				}
				else if (countdown == 3)
				{
					hangman_build_8();
				}
				else if (countdown == 2)
				{
					hangman_build_9();
				}
				else if (countdown == 1)
				{
					hangman_build_10();
				}
				else if (countdown == 0)
				{
					hangman_build_11();
				}

				//textColor("bred");

				//cout << searchedWord << " : " << countdown;

				foundChars = charCheck(searchedWord, charInput);	// Abgleich charInput mit Chars des gesuchten Wortes und Rückgabe String mit treffern

				for (int n = 0; n < foundChars.size(); n++)
				{
					if (foundChars[n] == '_')
					{
						dummy += 1;
					}
					else
					{
						actualWord[n] = foundChars[n];
					}
				}

				posWord = ((size_t)60 - searchedWord.size());											// Zentrierte Ausgabe der Eingabemaske für gesuchtes Wort !

				cout << setw(posWord);

				for (int n = 0; n < actualWord.size(); n++)
				{
					if (actualWord == searchedWord)
					{
						textColor("green");
						cout << actualWord[n] << " ";
					}
					else
					{
						cout << actualWord[n] << " ";
					}
				}

				if (actualWord == searchedWord)
				{
					won++;
					profileWon++;

					Sleep(100);

					if (effects == true)
					{
						if (snd_winLoose == true)
						{
							sndPlaySound("Data/Audio/SndEffects/win.wav", SND_FILENAME | SND_ASYNC);
						}

						for (int n = 2; n > 0; n--)
						{
							bgColor("bgreen");
							system("cls");
							Sleep(35);
							bgColor("black");
							system("cls");
							Sleep(35);
							bgColor("bgreen");
							system("cls");
							Sleep(35);
							bgColor("bwhite");
							system("cls");
							Sleep(15);
							bgColor("bgreen");
							system("cls");
							Sleep(35);
							bgColor("black");
							system("cls");
							Sleep(35);
							bgColor("green");
							system("cls");
							Sleep(35);
						}

						Sleep(500);
					}

					readProfiles.open("Data/profiles.dat");							// Code zum Prüfen ob Profildatei vorhanden und ggf. schreiben der win/lost Daten in Profildatei !

					if (!readProfiles)
					{
						readProfiles.close();
					}
					else
					{
						readProfiles.close();

						for (size_t i = 0; i < profiles.size(); i++)
						{
							if (profiles[i] == activeProfileName)
							{
								profiles[i + 1] = to_string(profileWon);
							}
						}

						writeToProfile.open("Data/profiles.dat");

						for (size_t i = 0; i < profiles.size(); i++)
						{
							writeToProfile << "\n" << profiles[i];
						}

						writeToProfile.close();
						profiles.clear();
					}

					bgColor(bg_color);

					system("cls");

					textColor("bblack");
					cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t    " << gameVersion << "\n";

					textColor(txt_color);

					if (snd_winLoose == true)
					{
						sndPlaySound("Data/Audio/SndEffects/triumph.wav", SND_FILENAME | SND_ASYNC);
					}

					winner_art();																		// ASCI-Art ausgabe des gewinner ASCI-Art !

					Sleep(800);

					//bgColor("bgreen");

					cout << setw(posWord) << " ";

					cout << "  ";

					for (int n = 0; n < searchedWord.length(); n++)										// Ausgabe gesuchtes Wort wenn gewonnen !
					{
						cout << searchedWord[n];
						cout << " ";
						Sleep(115);
					}

					cout << " ";

					cout << "\n\n\n\n\n\t";

					Sleep(800);

					cout << "\t\t\t\t<<< DU HAST DAS GESUCHTE WORT GEFUNDEN !!! >>>\n";

					Sleep(1000);

					cout << "\n\t <<< Drücke die [SPACE] Taste für eine neue Runde, oder [BACKSPACE <--] um zum Hauptmenü zurückzukehren >>>";

					while (input != " " && input != "\b")
					{
						input = _getch();																	// Eingabe gesuchter Buchstabe (charInput)
					}

					charInput = '\b';
				}
				else
				{
					if (countdown > 0)
					{
						textColor(txt_color);

						cout << "\n\n\n\n\n\t";

						cout << "Gib einen Buchstaben ein um zu spielen, oder drücke [BACKSPACE <--] um zum Hauptmenü zurückzukehren";

						charInput = _getch();																// Eingabe gesuchter Buchstabe (charInput)

						if (charInput == '\b')
						{
							input = "\b";
						}

						if (charInput == 'ä' || charInput == 'ö' || charInput == 'ü')						// Umwandlung von Umlauten in 'upper-case'
						{
							charInput += -32;
						}

						//mciSendString("play mp3 wait", NULL, 0, NULL);									// Sound wiedergabe Funktion (Play file till the end)
						//PlaySound("keyboard.mp3", GetModuleHandle(NULL), SND_FILENAME | SND_ASYNC);
						//or
						if (snd_keys == true)
						{
							sndPlaySound("Data/Audio/SndEffects/keyboard_oneTip_edit.wav", SND_FILENAME | SND_ASYNC);
						}

						charInput = toupper(charInput);														// Umwandlung von Char in Großbuchstaben
					}
					else
					{
						lost++;
						profileLost++;

						Sleep(300);

						if (effects == true)
						{
							if (snd_winLoose == true)
							{
								sndPlaySound("Data/Audio/SndEffects/lost.wav", SND_FILENAME | SND_ASYNC);
							}

							for (int n = 2; n > 0; n--)
							{
								bgColor("bred");
								system("cls");
								Sleep(35);
								bgColor("black");
								system("cls");
								Sleep(35);
								bgColor("bred");
								system("cls");
								Sleep(35);
								bgColor("bwhite");
								system("cls");
								Sleep(15);
								bgColor("red");
								system("cls");
								Sleep(35);
								bgColor("black");
								system("cls");
								Sleep(35);
								bgColor("red");
								system("cls");
								Sleep(35);
							}

							Sleep(500);
						}

						readProfiles.open("Data/profiles.dat");							// Code zum Prüfen ob Profildatei vorhanden und ggf. schreiben der win/lost Daten in Profildatei !

						if (!readProfiles)
						{
							readProfiles.close();
						}
						else
						{
							readProfiles.close();
																					
							for (size_t i = 0; i < profiles.size(); i++)
							{
								if (profiles[i] == activeProfileName)
								{
									profiles[i + 2] = to_string(profileLost);
								}
							}

							writeToProfile.open("Data/profiles.dat");

							for (size_t i = 0; i < profiles.size(); i++)
							{
								writeToProfile << "\n" << profiles[i];
							}

							writeToProfile.close();
							profiles.clear();
						}

						bgColor(bg_color);

						system("cls");

						textColor("bblack");
						cout << "\n\t\t\t\t\t\t\t\t\t\t\t\t\t    " << gameVersion << "\n";

						textColor(txt_color);

						if (snd_winLoose == true)
						{
							sndPlaySound("Data/Audio/SndEffects/death_drums.wav", SND_FILENAME | SND_ASYNC);
						}

						hangman_build_11();																// ASCI-Art ausgabe des verlierer ASCI-Art !

						cout << setw(posWord) << " ";

						Sleep(800);

						//bgColor("red");

						cout << "  ";

						for (int n = 0; n < searchedWord.size(); n++)									// Ausgabe gesuchtes Wort wenn verloren !
						{
							cout << searchedWord[n];
							cout << " ";
							Sleep(115);
						}

						cout << " ";

						cout << "\n\n\n\n\n\t";

						cout << "\t\t     <<< DU HÄNGST AM GALGEN UND KANNST NICHT MEHR WEITER SPIELEN !!! >>>\n\n";

						Sleep(1000);

						cout << "\t     Drücke die [SPACE] Taste für eine neue Runde, oder [BACKSPACE <--] um zum Hauptmenü zurückzukehren";

						while (input != " " && input != "\b")
						{
							input = _getch();
						}

						charInput = '\b';
					}
				}
			}
		}
		Sleep(750);
}
