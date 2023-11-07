#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;




void write_ini_file(int opt_bg, bool vis_effects, bool snd_effects, bool snd_mChoice, bool snd_keyTap, bool snd_winOrLoose, bool menu_music)
{
	ofstream write_ini;

	write_ini.open("Data/options.ini");
	write_ini << opt_bg << '\n' << vis_effects << '\n' << snd_effects << '\n' << snd_mChoice << '\n' << snd_keyTap << '\n' << snd_winOrLoose << '\n' << menu_music;
	write_ini.close();
}