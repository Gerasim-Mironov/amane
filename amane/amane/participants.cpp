#include "participants.h"

void User::enterLogin()
{
	std::cout << "Введите логин: ";
		bool As = false;
		while (As != true)
		{
			char key = _getch();
			if (key == 13)
				As = true;
			std::cout << key;
			this->login += key;
		}
	std::cout << "\n";
}

void User::enterPassword()
{
	std::cout << "Введите пароль: ";
	bool As = false;
	while (As != true)
	{
		char key = _getch();
		if (key == 13)
			As = true;
		std::cout << "*";
		this->password += key;
	}
	std::cout << "\n";
}

void User::enterFIO()
{
	std::cout << "Имя и фамилия: ";
	bool As = false;
	while (As != true)
	{
		char key = _getch();
		if (key == 13)
			As = true;
		std::cout << key;
		this->fio += key;
	}
	std::cout << "\n";
}

void User::enterEmail()
{
	do {
		std::cout << "Эл. Почта: ";
		bool As = false;
		while (As != true)
		{
			char key = _getch();
			if (key == 13)
				As = true;
			std::cout << key;
			this->email += key;
		}
		std::cout << "\n";
	} while (this->checkEmail() != true);
}

void User::enterPNum()
{
	while (this->checkPNum() == false)
	{
		std::cout << "номер телефона? ";
		bool As = false;
		unsigned int count = 0;
		while (As != true)
		{
			char key = _getch();
			count++;
			if (key == 13)
				As = true;
			if (count == 4 || count == 7 || count == 10)
				std::cout << " ";
			std::cout << key;
			this->pNum += key;
		}
		std::cout << "\n";
	}	
}

void User::accountSettings()
{
	std::cout << "ваш пароль: " << this->password << "\n";
	std::cout << "1->изменить\n2->оставить\n";
	char ch = _getch();
	while (ch != '1' || ch != '2')
	{
		switch (ch)
		{
		case '1': {this->enterPassword(); }break;
		case '2': continue;
		}
	}

	std::cout << "\nваше имя: " << this->fio << "\n";
	std::cout << "1->изменить\n2->оставить\n";
	ch = _getch();
	while (ch != '1' || ch != '2')
	{
		switch (ch)
		{
		case '1': {this->enterFIO(); }break;
		case '2': continue;
		}
	}

	std::cout << "\nваша почта: " << this->email << "\n";
	std::cout << "1->изменить\n2->оставить\n";
	ch = _getch();
	while (ch != '1' || ch != '2')
	{
		switch (ch)
		{
		case '1': {this->enterEmail(); }break;
		case '2': continue;
		}
	}

	std::cout << "\nваш номер телефона: " << this->pNum << "\n";
	std::cout << "1->изменить\n2->оставить\n";
	ch = _getch();
	while (ch != '1' || ch != '2')
	{
		switch (ch)
		{
		case '1': {this->enterPNum(); }break;
		case '2': continue;
		}
	}
	//надо как-то сохранить
	std::cout << "изменения сохранены\n";
}
