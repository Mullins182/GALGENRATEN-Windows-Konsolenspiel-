#pragma once

using namespace std;

/*Show Cursor ON or OFF function*/
void set_cursor(bool);
/*random number generating function*/
int random(int, int);
/*Profile-Management Functions*/
void profileManagement();
/*Game-Routine-Function*/
void hangman(string, int, bool, bool, bool, bool, size_t);
/*Game Options*/
void options();
/*H I G H S C O R E  Function*/
void highscore(size_t);
/*Function for creating and writing values to INI-File*/
void write_ini_file(int, bool, bool, bool, bool, bool, bool);
/*Function for choosing a random word from wordlist*/
string randomWordGenerating();
/*input char check if char is part of random chosen word*/
string charCheck(string, char);
/*Change Font-Color Function*/
void textColor(string);
/*Changing Colors Of Console Function*/
void bgColor(string);
/*Resetting Color Changes to Console*/
void resetColor();
/*ASCI-Art generating function*/
void hangman_art();
/*ASCI-Art generating function*/
void winner_art();
/*ASCI-Art generating function*/
void mainmenu_art();
/*ASCI-Art generating function*/
void hangman_build_1();
/*ASCI-Art generating function*/
void hangman_build_2();
/*ASCI-Art generating function*/
void hangman_build_3();
/*ASCI-Art generating function*/
void hangman_build_4();
/*ASCI-Art generating function*/
void hangman_build_5();
/*ASCI-Art generating function*/
void hangman_build_6();
/*ASCI-Art generating function*/
void hangman_build_7();
/*ASCI-Art generating function*/
void hangman_build_8();
/*ASCI-Art generating function*/
void hangman_build_9();
/*ASCI-Art generating function*/
void hangman_build_10();
/*ASCI-Art generating function*/
void hangman_build_11();