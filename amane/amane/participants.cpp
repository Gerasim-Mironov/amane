#include "participants.h"
#pragma warning(disable: 4996)

void User::enterLogin()
{
	login.clear();
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

		std::string temp = "";
		for (size_t i = 0; i < login.size(); i++)
		{
			if (login[i] != '\r')
				temp += login[i];
		}

		login = temp;
	std::cout << "\n";
}

void User::enterPassword()
{
	password.clear();
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

	std::string temp = "";
	for (size_t i = 0; i < password.size(); i++)
	{
		if (password[i] != '\r')
			temp += password[i];
	}

	password = temp;
	std::cout << "\n";
}

void User::enterFIO()
{
	fio.clear();
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

	std::string temp = "";
	for (size_t i = 0; i < fio.size(); i++)
	{
		if (fio[i] != '\r')
			temp += fio[i];
	}

	fio = temp;
	std::cout << "\n";
}

void User::enterEmail()
{
	email.clear();
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

		std::string temp = "";
		for (size_t i = 0; i < email.size(); i++)
		{
			if (email[i] != '\r')
				temp += email[i];
		}

		email = temp;
		std::cout << "\n";
	} while (this->checkEmail() != true);
}

void User::enterPNum()
{
	pNum.clear();
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

		std::string temp = "";
		for (size_t i = 0; i < pNum.size(); i++)
		{
			if (pNum[i] != '\r')
				temp += pNum[i];
		}

		pNum = temp;
		std::cout << "\n";
	}	
}

void User::accountSettings()
{
	system("cls");
	std::cout << "ваш пароль: " << this->password << "\n";
	std::cout << "1->изменить\n2->оставить\n";
	char mz = _getch();
	if (mz == '1')
		this->enterPassword();
	else if (mz == '2')
		Sleep(0);
	else
	{
		std::cout << "Ты допустил фатальную ошибку\n"; 
		Sleep(2500); 
		exit(EXIT_FAILURE);
	}

	std::cout << "\nваше имя: " << this->fio << "\n";
	std::cout << "1->изменить\n2->оставить\n";
	mz = _getch();
	if (mz == '1')
		this->enterFIO();
	else if (mz == '2')
		Sleep(0);
	else
	{
		std::cout << "Ты допустил фатальную ошибку\n";
		Sleep(2500);
		exit(EXIT_FAILURE);
	}

	std::cout << "\nваша почта: " << this->email << "\n";
	std::cout << "1->изменить\n2->оставить\n";
	mz = _getch();
	if (mz == '1')
		this->enterEmail();
	else if (mz == '2')
		Sleep(0);
	else
	{
		std::cout << "Ты допустил фатальную ошибку\n";
		Sleep(2500);
		exit(EXIT_FAILURE);
	}

	std::cout << "\nваш номер телефона: " << this->pNum << "\n";
	std::cout << "1->изменить\n2->оставить\n";
	mz = _getch();
	if (mz == '1')
		this->enterPNum();
	else if (mz == '2')
		Sleep(0);
	else
	{
		std::cout << "Ты допустил фатальную ошибку\n";
		Sleep(2500);
		exit(EXIT_FAILURE);
	}
	
	std::ofstream wr;
	wr.open(this->getRoute());
	wr << this->login << "\n";
	wr << this->password << "\n";
	wr << this->fio << "\n";
	wr << this->email << "\n";
	wr << this->pNum << "\n";
	wr.close();
	std::cout << "изменения сохранены\n";
	system("cls");
}

std::string User::getRoute()
{
	filePath = "";
	for (auto i=login.begin() ; i != login.end(); i++)
	{
		if(*i!='\r')
			filePath.push_back((const char)*i);
	}
	filePath += ".txt";

	return filePath;
}
