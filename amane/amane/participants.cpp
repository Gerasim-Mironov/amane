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
	std::cout << "Фамилия Имя Отчество: ";
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
	do {
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
			this->password += key;
		}
		std::cout << "\n";
	} while (this->checkPNum() != true);
}
