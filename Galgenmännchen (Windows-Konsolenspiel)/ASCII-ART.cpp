#include<iostream>
#include<iomanip>
#include<Windows.h>

using namespace std;



void mainmenu_art()
{

	cout << "\t\t\t\t               _        __   ___           _          __              \n";
	cout << "\t\t\t\t       /\\  /\\ /_\\    /\\ \\ \\ / _ \\ /\\/\\    /_\\    /\\  / /   \n";
	cout << "\t\t\t\t      / /_/ ///_ \\  /  \\/ // /_\\//    \\  //_\\\\  /  \\/ /        \n";
	cout << "\t\t\t\t     / __  //  _  \\/ /\\  // /_ \\/ /\\/\\ \\/  _  \\/ /\\  /        \n";
	cout << "\t\t\t\t     \\/ /_/ \\_/ \\_/\\_\\ \\/ \\____/\\/    \\/\\_/ \\_/\\_\\ \\/   \n";
	cout << "\t\t\t\t                                                                      \n";


}

void hangman_art()
{
		cout << " ___________.._______         \n";
		cout << "| .__________))______|        \n";
		cout << "| | / /      ||               \n";
		cout << "| |/ /       ||               \n";
		cout << "| | /        ||.-''.          \n";
		cout << "| |/         |/  _  \\        \n";
		cout << "| |          ||  `/,|         \n";
		cout << "| |          (\\`_.'          \n";
		cout << "| |         .-`--'.           \n";
		cout << "| |        /Y . . Y\\         \t\t\t[SPACE] NEUES SPIEL STARTEN\n";
		cout << "| |       // |   | \\\\       \n";
		cout << "| |      //  | . |  \\\\      \t\t\t       [H] HIGHSCORE\n";
		cout << "| |     ')   |   |   (`	   \n";
		cout << "| |          ||'||		      [P] PROFILE VERWALTEN [O] OPTIONEN [Q] BEENDEN\n";
		cout << "| |          || ||            \n";
		cout << "| |          || ||            \n";
		cout << "| |          || ||            \n";
		cout << "| |_______  / | | \\  ___     \n";
		cout << "| |_______|_`-' `-' |___|     \n";
		cout << "| |_______\\ \\       '_|_|   \n";

}

void winner_art()
{
	unsigned int a = 20;

	Sleep(a);
	cout << " ___________.._______      \n";
	Sleep(a);
	cout << "| .__________))______|     \n";
	Sleep(a);
	cout << "| | / /                    \n";
	Sleep(a);
	cout << "| |/ /                     \n";
	Sleep(a);
	cout << "| | /                      \n";
	Sleep(a);
	cout << "| |/           ,,,         \n";
	Sleep(a);
	cout << "| |           /   \\       \n";
	Sleep(a);
	cout << "| |          ( ^ ^ )       \n";
	Sleep(a);
	cout << "| |      ('   \\ U /   ')  \n";
	Sleep(a);
	cout << "| |       \\\\   | |   //  \n";
	Sleep(a);
	cout << "| |        \\\\.-`-- .//   \n";
	Sleep(a);
	cout << "| |         \\Y . . Y/     \n";
	Sleep(a);
	cout << "| |          \\     /      \n";
	Sleep(a);
	cout << "| |           \\ ' /        \n";
	Sleep(a);
	cout << "| |           |   |        \n";
	Sleep(a);
	cout << "| |           ||'||        \n";
	Sleep(a);
	cout << "| |          _|| ||_       \n";
	Sleep(a);
	cout << "| |_________(__|_|__)_____ \n";
	Sleep(a);
	cout << "| |_______|___________|___|\n";
	Sleep(a);
	cout << "| |___________________'_|_|\n";
}

void hangman_build_1()
{
	cout << "                           \n";
	cout << "                           \n";
	cout << "                           \n";
	cout << "                           \n";
	cout << "                           \n";
	cout << "                           \n";
	cout << "                           \n";
	cout << "                           \n";
	cout << "                           \n";
	cout << "                           \n";
	cout << "                           \n";
	cout << "                           \n";
	cout << "                           \n";
	cout << "                           \n";
	cout << "                           \n";
	cout << "                           \n";
	cout << "                           \n";
	cout << "   _______             ___ \n";
	cout << "   _______|___________|___|\n";
	cout << "   ___________________'_|_|\n";

}

void hangman_build_2()
{
	cout << " _                         \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |_______             ___ \n";
	cout << "| |_______|___________|___|\n";
	cout << "| |___________________'_|_|\n";
}

void hangman_build_3()
{
	cout << " _    __                   \n";
	cout << "| |  / /                   \n";
	cout << "| | / /                    \n";
	cout << "| |/ /                     \n";
	cout << "| | /                      \n";
	cout << "| |/                       \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |_______             ___ \n";
	cout << "| |_______|___________|___|\n";
	cout << "| |___________________'_|_|\n";
}

void hangman_build_4()
{
	cout << " ___________.._______      \n";
	cout << "| .__________))______|     \n";
	cout << "| | / /                    \n";
	cout << "| |/ /                     \n";
	cout << "| | /                      \n";
	cout << "| |/                       \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |_______             ___ \n";
	cout << "| |_______|___________|___|\n";
	cout << "| |___________________'_|_|\n";
}

void hangman_build_5()
{
	cout << " ___________.._______      \n";
	cout << "| .__________))______|     \n";
	cout << "| | / /      ||            \n";
	cout << "| |/ /       ||            \n";
	cout << "| | /        ||            \n";
	cout << "| |/         ||            \n";
	cout << "| |          ||            \n";
	cout << "| |          ||            \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |_______             ___ \n";
	cout << "| |_______|___________|___|\n";
	cout << "| |___________________'_|_|\n";
}

void hangman_build_6()
{
	cout << " ___________.._______      \n";
	cout << "| .__________))______|     \n";
	cout << "| | / /      ||            \n";
	cout << "| |/ /       ||            \n";
	cout << "| | /        ||.-''.       \n";
	cout << "| |/         |/  _  \\     \n";
	cout << "| |          ||  `/,|      \n";
	cout << "| |          (\\`_.'       \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |_______             ___ \n";
	cout << "| |_______|___________|___|\n";
	cout << "| |___________________'_|_|\n";
}

void hangman_build_7()
{
	cout << " ___________.._______      \n";
	cout << "| .__________))______|     \n";
	cout << "| | / /      ||            \n";
	cout << "| |/ /       ||            \n";
	cout << "| | /        ||.-''.       \n";
	cout << "| |/         |/  _  \\     \n";
	cout << "| |          ||  `/,|      \n";
	cout << "| |          (\\`_.'       \n";
	cout << "| |         .-`--'.        \n";
	cout << "| |        /Y . . Y\\      \n";
	cout << "| |          |   |         \n";
	cout << "| |          | . |         \n";
	cout << "| |          |   |         \n";
	cout << "| |          ||'||         \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |_______             ___ \n";
	cout << "| |_______|___________|___|\n";
	cout << "| |___________________'_|_|\n";
}

void hangman_build_8()
{
	cout << " ___________.._______      \n";
	cout << "| .__________))______|     \n";
	cout << "| | / /      ||            \n";
	cout << "| |/ /       ||            \n";
	cout << "| | /        ||.-''.       \n";
	cout << "| |/         |/  _  \\     \n";
	cout << "| |          ||  `/,|      \n";
	cout << "| |          (\\`_.'       \n";
	cout << "| |         .-`--'.        \n";
	cout << "| |        /Y . . Y\\      \n";
	cout << "| |       // |   |         \n";
	cout << "| |      //  | . |         \n";
	cout << "| |     ')   |   |         \n";
	cout << "| |          ||'||         \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |_______             ___ \n";
	cout << "| |_______|___________|___|\n";
	cout << "| |___________________'_|_|\n";
}

void hangman_build_9()
{
	cout << " ___________.._______      \n";
	cout << "| .__________))______|     \n";
	cout << "| | / /      ||            \n";
	cout << "| |/ /       ||            \n";
	cout << "| | /        ||.-''.       \n";
	cout << "| |/         |/  _  \\     \n";
	cout << "| |          ||  `/,|      \n";
	cout << "| |          (\\`_.'       \n";
	cout << "| |         .-`--'.        \n";
	cout << "| |        /Y . . Y\\      \n";
	cout << "| |       // |   | \\\\    \n";
	cout << "| |      //  | . |  \\\\   \n";
	cout << "| |     ')   |   |   (`    \n";
	cout << "| |          ||'||         \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |                        \n";
	cout << "| |_______             ___ \n";
	cout << "| |_______|___________|___|\n";
	cout << "| |___________________'_|_|\n";
}
void hangman_build_10()
{
	cout << " ___________.._______      \n";
	cout << "| .__________))______|     \n";
	cout << "| | / /      ||            \n";
	cout << "| |/ /       ||            \n";
	cout << "| | /        ||.-''.       \n";
	cout << "| |/         |/  _  \\     \n";
	cout << "| |          ||  `/,|      \n";
	cout << "| |          (\\`_.'       \n";
	cout << "| |         .-`--'.        \n";
	cout << "| |        /Y . . Y\\      \n";
	cout << "| |       // |   | \\\\    \n";
	cout << "| |      //  | . |  \\\\   \n";
	cout << "| |     ')   |   |   (`    \n";
	cout << "| |          ||'||         \n";
	cout << "| |             ||         \n";
	cout << "| |             ||         \n";
	cout << "| |             ||         \n";
	cout << "| |_______      | \\    ___\n";
	cout << "| |_______|_    `-'   |___|\n";
	cout << "| |_______\\ \\         '_|_|\n";
}

void hangman_build_11()
{
	cout << " ___________.._______         \n";
	cout << "| .__________))______|        \n";
	cout << "| | / /      ||               \n";
	cout << "| |/ /       ||               \n";
	cout << "| | /        ||.-''.          \n";
	cout << "| |/         |/  _  \\        \n";
	cout << "| |          ||  `/,|         \n";
	cout << "| |          (\\`_.'          \n";
	cout << "| |         .-`--'.           \n";
	cout << "| |        /Y . . Y\\         \n";
	cout << "| |       // |   | \\\\       \n";
	cout << "| |      //  | . |  \\\\      \n";
	cout << "| |     ')   |   |   (`       \n";
	cout << "| |          ||'||            \n";
	cout << "| |          || ||            \n";
	cout << "| |          || ||            \n";
	cout << "| |          || ||            \n";
	cout << "| |_______  / | | \\    ___     \n";
	cout << "| |_______|_`-' `-'   |___|     \n";
	cout << "| |_______\\ \\         '_|_|   \n";
}