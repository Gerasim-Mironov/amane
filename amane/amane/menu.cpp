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
	if (mt.getToKnow() == false)
	{
		std::ofstream wr;
		wr.open(mt.getRoute());

		wr << mt.getLogin();

		mt.enterPassword();
		wr << mt.getPassword();

		mt.enterFIO();
		wr << mt.getName();

		mt.enterEmail();
		wr << mt.getMail();

		mt.enterPNum();
		wr << mt.getNum();
		wr.close();
	}

	system("cls");
	this->intermediate();
}

void Menu::signIn()
{
	system("cls");
	mt.enterLogin();
	if (mt.getLogin() == "Admin\r")
	{
		while (true)
		{
			mt.enterPassword();
			if (mt.getPassword() == "HiddenLeaf\r")
			{
				mt.changleAngle();
				system("cls");
				this->intermediate();
			}
		}
	}
	std::ifstream re;
	re.open(mt.getRoute());
	if (re.is_open())
	{
		std::string ruby;
		while (!re.eof())
		{
			ruby = "";
			std::getline(re, ruby);
			if (ruby==mt.getLogin())
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
	int num = 0;
	if (mt.getToKnow() == false)
	{
		std::cout << "1->пройти тесты\n2->аккаунт\n3->уйти\n";
		char ch = _getch();
		switch (ch)
		{
		case '1': 
		{
			loadTests();
			std::cout << "введите номер теста(наобум)\n";
			sl[num].getTested(mt);
			num++;
			this->intermediate();
		}break;
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
		case '1': {
			loadTests();
			
			sl[num].getTested(mt);
			num++;
			this->intermediate();
		}break;
		case '2': {
			Test temple;

			system("cls");
			
			temple.makeTest();
			temple.saveTest();
			sl.push_back(temple);
			
			system("cls");

			this->intermediate(); 
		}break;
		case '3': 
		{
			std::ifstream vh;
			vh.open("UserStats.txt");
			while (!vh.eof())
			{
				std::string germ = "";
				std::getline(vh, germ);

				std::cout << germ << "\n";
			}
			vh.close();
			this->intermediate(); 
		}break;
		case '4': {mt.accountSettings(); this->intermediate(); }break;
		case '5': {exit(EXIT_SUCCESS); }
		default: {system("cls"); this->intermediate(); }
		}
	}
}

void Menu::loadTests()
{
	int counter = 0;

	std::ifstream re;
	re.open("TestRoots.txt");
	while (!re.eof())
	{
		std::string ruby = "";
		std::getline(re, ruby);
		sl[counter].loadTest(ruby);
		
		counter++;
	}
}
