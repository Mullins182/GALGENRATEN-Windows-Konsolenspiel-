#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;





string charCheck(string compareString, char inputChar)
{

	string buildWord;

	int n = 0;
	
	while (n < compareString.size())
	{
		if (compareString[n] == inputChar)
		{
			buildWord += inputChar;
		}
		else
		{
			buildWord.append("_");
		}
		n++;
	}	

	return buildWord;
}