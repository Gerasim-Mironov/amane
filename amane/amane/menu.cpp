#include "menu.h"

void menu::entrance()
{
	std::cout << "1->зарегистрироваться\n2->войти\n3->уйти";
	char ch;
	do
	{
		ch = _getch();
	} while (ch != '1' || ch != '2' || ch != '3');
	switch (ch)
	{
	case '1': logIn(); break;
	case '2': signIn(); break;
	case '3': exit(EXIT_FAILURE);
	}
}

void menu::logIn()
{
}

void menu::signIn()
{
}
