//		color:						Normale Farbe
//b		bright color:				Helle Farbe

/*
 * ANSI escape color codes :

Name            FG  BG
Black           30  40
Red             31  41
Green           32  42
Yellow          33  43
Blue            34  44
Magenta         35  45
Cyan            36  46
White           37  47
Bright Black    90  100
Bright Red      91  101
Bright Green    92  102
Bright Yellow   93  103
Bright Blue     94  104
Bright Magenta  95  105
Bright Cyan     96  106
Bright White    97  107
*/

//Normal Colors

#include <iostream>
#include <string>

using namespace std;

void resetColor()
{
	printf("\033[0m");
}

void textColor(string input)
{

	if (input == "black")
	{
		printf("\x1B[30m");
	}

	if (input == "red")
	{
		printf("\x1B[31m");
	}

	if (input == "green")
	{
		printf("\x1B[32m");
	}

	if (input == "yellow")
	{
		printf("\x1B[33m");
	}

	if (input == "blue")
	{
		printf("\x1B[34m");
	}

	if (input == "magenta")
	{
		printf("\x1B[35m");
	}

	if (input == "cyan")
	{
		printf("\x1B[36m");
	}

	if (input == "white")
	{
		printf("\x1B[37m");
	}

	//Bright Colors

	if (input == "bblack")
	{
		printf("\x1B[90m");
	}

	if (input == "bred")
	{
		printf("\x1B[91m");
	}

	if (input == "bgreen")
	{
		printf("\x1B[92m");
	}

	if (input == "byellow")
	{
		printf("\x1B[93m");
	}

	if (input == "bblue")
	{
		printf("\x1B[94m");
	}

	if (input == "bmagenta")
	{
		printf("\x1B[95m");
	}

	if (input == "bcyan")
	{
		printf("\x1B[96m");
	}

	if (input == "bwhite")
	{
		printf("\x1B[97m");
	}
}


void bgColor(string input)
{
	//Normal Background Colors

	if (input == "black")
	{
		printf("\x1B[40m");
	}

	if (input == "red")
	{
		printf("\x1B[41m");
	}

	if (input == "green")
	{
		printf("\x1B[42m");
	}

	if (input == "yellow")
	{
		printf("\x1B[43m");
	}

	if (input == "blue")
	{
		printf("\x1B[44m");
	}

	if (input == "magenta")
	{
		printf("\x1B[45m");
	}

	if (input == "cyan")
	{
		printf("\x1B[46m");
	}

	if (input == "white")
	{
		printf("\x1B[47m");
	}

	//Bright Background Colors

	if (input == "bblack")
	{
		printf("\x1B[100m");
	}

	if (input == "bred")
	{
		printf("\x1B[101m");
	}

	if (input == "bgreen")
	{
		printf("\x1B[102m");
	}

	if (input == "byellow")
	{
		printf("\x1B[103m");
	}

	if (input == "bblue")
	{
		printf("\x1B[104m");
	}

	if (input == "bmagenta")
	{
		printf("\x1B[105m");
	}

	if (input == "bcyan")
	{
		printf("\x1B[106m");
	}

	if (input == "bwhite")
	{
		printf("\x1B[107m");
	}

}