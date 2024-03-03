#include<iostream>
#include<fstream>
#include<Windows.h>
#include"functions.h"

using namespace std;


string randomWordGenerating()							// Funktion zur zufälligen Auswahl eines Wortes aus der Datenbank
{
	ifstream words("Data/data.dat");
	unsigned int choice		= 0;
	unsigned int loops		= 0;
	string word;
	
	for (int i = 13; i >= 0; i--)
	{
		loops = random(11, 59);
	}

	for (; loops > 0; loops--)
	{
		choice = random(1, 444);					// Achtung !!! Bei Änderung der Wortlistendateigröße auch game.cpp Zeile 116 anpassen !
		Sleep(50);
	}
	
	for (; choice > 0; choice--)
	{
		words >> word;
	}

	words.close();

	return word;
}
