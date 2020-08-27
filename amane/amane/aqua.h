#ifndef AQUA
#define AQUA

#include<iostream>
#include<string>
#include<string.h>
#include<map>
#include<vector>
#include<fstream>
#include<conio.h>
#include<Windows.h>

void getchTyping(std::string mt)
{
	char c;
	while (c != 13)
	{
		c = _getch();
		std::cout << c;
		mt += c;
	}
	std::cout << "\n";
}

#endif