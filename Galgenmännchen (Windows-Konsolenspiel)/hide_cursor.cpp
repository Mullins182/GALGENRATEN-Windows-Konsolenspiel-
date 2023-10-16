#include<iostream>
#include<iomanip>
#include<windows.h>

using namespace std;

// Cursor verstecken Funktion [ Aufruf mit set_cursor(true OR false);

void set_cursor(bool visible)
{
	CONSOLE_CURSOR_INFO info{};
	info.dwSize = 100;
	info.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}