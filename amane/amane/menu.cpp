#include "menu.h"

void menu::entrance()
{
	std::cout << "1->зарегистрироваться\n2->войти\n3->уйти\n";
	char ch = _getch();
	switch (ch)
	{
	case '1': logIn(); break;
	case '2': signIn(); break;
	case '3': exit(EXIT_FAILURE);
	default: {system("cls"); this->entrance(); }
	}
}

void menu::logIn()
{
	system("cls");
	Ul.enterLogin();
	std::ifstream re("UserLogs.txt");
	if (re.is_open())
	{
		std::string ruby;
		while (!re.eof())
		{
			ruby = "";
			std::getline(re, ruby);
			if (ruby == Ul.getLogin())
			{
				std::cout << "Пользователь с таким именем уже зарегестрирован, войти?\n1->да\n2->нет\n";
				char key = _getch();
				switch (key)
				{
				case '1': signIn(); break;
				case '2': Ul.enterLogin(); break;
				default: {std::cout << "\n"; key = _getch(); }
				}
			}
		}
	}
	std::ofstream wr("UserLogs.txt", std::ios::app);
	wr << "-------------------------------------\n";
	wr << Ul.getLogin();

	Ul.enterPassword();
	wr << Ul.getPassword();

	Ul.enterFIO();
	wr << Ul.getName();

	Ul.enterEmail();
	wr << Ul.getMail();

	Ul.enterPNum();
	wr << Ul.getNum();
	wr<< "-------------------------------------\n";
}

void menu::signIn()
{
	system("cls");
	Ul.enterLogin();
	std::ifstream re("UserLogs.txt");
	if (re.is_open())
	{
		std::string ruby;
		while (!re.eof())
		{
			ruby = "";
			std::getline(re, ruby);
			if (Ul.getLogin() == ruby)
			{

				Ul.enterPassword();
				while (!re.eof())
				{
					std::string slick="";
					std::getline(re, slick);
					if (Ul.getPassword() == slick)
					{
						//скоро будет
						std::cout << "извини, скоро мы вернём твой акк...\n";
					}
				}
			}
		}
	}
	std::cout << "Мы тебя не помним\n";
	this->entrance();
}
