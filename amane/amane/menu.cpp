#include "menu.h"

void Menu::entrance()
{
	std::cout << "1->������������������\n2->�����\n3->����\n";
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
				std::cout << "������������ � ����� ������ ��� ���������������, �����?\n1->��\n2->���\n";
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

		wr << mt.getLogin()<<"\n";

		mt.enterPassword();
		wr << mt.getPassword() << "\n";

		mt.enterFIO();
		wr << mt.getName()<<"\n";

		mt.enterEmail();
		wr << mt.getMail()<<"\n";

		mt.enterPNum();
		wr << mt.getNum()<<"\n";
		wr.close();
	}

	system("cls");
	this->intermediate();
}

void Menu::signIn()
{
	system("cls");
	mt.enterLogin();
	if (mt.getLogin() == "Admin")
	{
		while (true)
		{
			mt.enterPassword();
			if (mt.getPassword() == "HiddenLeaf")
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
	std::cout << "�� ���� �� ������\n";
	this->entrance();
}

void Menu::intermediate()
{
	if (mt.getToKnow() == false)
	{
		std::cout << "1->������ �����\n2->�������\n3->����\n";
		char ch = _getch();
		switch (ch)
		{
		case '1': 
		{
			loadTests();
			sl[chrono].getTested(mt);
			chrono++;
			this->intermediate();
		}break;
		case '2': {mt.accountSettings(); this->intermediate(); }break;
		case '3': {exit(EXIT_SUCCESS); }
		default: {system("cls"); this->intermediate(); }
		}
	}
	else
	{

		std::cout << "1->������ ����\n2->������� ����\n3->����������� ����������\n4->�������\n5->����\n";
		char ch = _getch();
		switch (ch)
		{
		case '1': {
			loadTests();
			sl[chrono].getTested(mt);
			chrono++;
			this->intermediate();
		}break;
		case '2': {
			system("cls");
			
			sl[chrono].makeTest();
			sl[chrono].saveTest();
			
			
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

	std::string ruby = "";
	while (!re.eof())
	{
		ruby.clear();
		std::getline(re, ruby);
		sl[counter].loadTest(ruby);
		
		counter++;
	}
}
