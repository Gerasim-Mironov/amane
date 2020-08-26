#include "menu.h"

void Menu::entrance()
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

void Menu::logIn()
{
	system("cls");
	mt.enterLogin();
	std::ifstream re;
	re.open(mt.getRoute());
	if (re.is_open())
	{
		std::string ruby;
		while (!re.eof())
		{
			ruby = "";
			std::getline(re, ruby);
			if (ruby == mt.getLogin())
			{
				std::cout << "Пользователь с таким именем уже зарегестрирован, войти?\n1->да\n2->нет\n";
				char key = _getch();
				switch (key)
				{
				case '1': signIn(); break;
				case '2': mt.enterLogin(); break;
				default: {std::cout << "\n"; key = _getch(); }
				}
			}
		}
	}
	re.close();

	std::ofstream wr(mt.getRoute());
	
	wr << mt.getLogin();

	mt.enterPassword();
	wr << mt.getPassword();

	mt.enterFIO();
	wr << mt.getName();

	mt.enterEmail();
	wr << mt.getMail();

	mt.enterPNum();
	wr << mt.getNum();
}

void Menu::signIn()
{
	system("cls");
	mt.enterLogin();
	if (mt.getLogin().c_str() == "Admin")
	{
		while (true)
		{
			mt.enterPassword();
			if (mt.getPassword().c_str() == "HiddenLeaf")
			{
				mt.changleAngle();
				this->intermediate();
			}
		}
	}
	std::ifstream re(mt.getRoute());
	if (re.is_open())
	{
		std::string ruby;
		while (!re.eof())
		{
			ruby = "";
			std::getline(re, ruby);
			if (mt.getLogin() == ruby)
			{
				mt.enterPassword();
				while (!re.eof())
				{
					std::string slick="";
					std::getline(re, slick);
					if (mt.getPassword() == slick)
					{
						system("cls");
						this->intermediate();
					}
				}
			}
		}
	}
	std::cout << "Мы тебя не помним\n";
	this->entrance();
}

void Menu::intermediate()
{
	if (mt.getToKnow() == false)
	{
		std::cout << "1->пройти тесты\n2->аккаунт\n3->уйти\n";
		char ch = _getch();
		switch (ch)
		{
		case '1': {sl.testMe(); this->intermediate(); }break;
		case '2': {mt.accountSettings(); this->intermediate(); }break;
		case '3': {exit(EXIT_SUCCESS); }
		default: {system("cls"); this->intermediate(); }
		}
	}
	else
	{
		std::cout << "1->пройти тест\n2->создать тест\n3->просмотреть статистику\n4->аккаунт\n5->уйти\n";
		char ch = _getch();
		switch (ch)
		{
		case '1': {sl.testMe(); this->intermediate(); }break;
		case '2': {sl.makeTest(); this->intermediate(); }break;
		case '3': {sl.checkStats(); this->intermediate(); }break;
		case '4': {mt.accountSettings(); this->intermediate(); }break;
		case '5': {exit(EXIT_SUCCESS); }
		default: {system("cls"); this->intermediate(); }
		}
	}
}
