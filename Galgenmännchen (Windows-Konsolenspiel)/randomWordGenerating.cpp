#include<iostream>
#include<fstream>
#include<Windows.h>
#include"functions.h"

using namespace std;


string randomWordGenerating()													// Funktion zur zufälligen Auswahl eines Wortes aus der Datenbank
{
	ifstream words("data.dat");
	unsigned int choice = 0;
	unsigned int loops = 0;
	string word;
	
	loops = random(1, 51);

	for (int i = loops; i > 0; i--)
	{
		choice = random(1, 362);
		Sleep(50);
	}
	
	for (int i = choice; i > 0; i--)
	{
		words >> word;
	}

	words.close();

	return word;
}
