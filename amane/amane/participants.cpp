#include "participants.h"
#pragma warning(disable: 4996)

void User::enterLogin()
{
	std::cout << "������� �����: ";
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
	std::cout << "������� ������: ";
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
	std::cout << "��� � �������: ";
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
		std::cout << "��. �����: ";
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
		std::cout << "����� ��������? ";
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
	system("cls");
	std::cout << "��� ������: " << this->password << "\n";
	std::cout << "1->��������\n2->��������\n";
	char mz = _getch();
	if (mz == '1')
		this->enterPassword();
	else if (mz == '2')
		Sleep(0);
	else
	{
		std::cout << "�� �������� ��������� ������\n"; 
		Sleep(2500); 
		exit(EXIT_FAILURE);
	}

	std::cout << "\n���� ���: " << this->fio << "\n";
	std::cout << "1->��������\n2->��������\n";
	mz = _getch();
	if (mz == '1')
		this->enterFIO();
	else if (mz == '2')
		Sleep(0);
	else
	{
		std::cout << "�� �������� ��������� ������\n";
		Sleep(2500);
		exit(EXIT_FAILURE);
	}

	std::cout << "\n���� �����: " << this->email << "\n";
	std::cout << "1->��������\n2->��������\n";
	mz = _getch();
	if (mz == '1')
		this->enterEmail();
	else if (mz == '2')
		Sleep(0);
	else
	{
		std::cout << "�� �������� ��������� ������\n";
		Sleep(2500);
		exit(EXIT_FAILURE);
	}

	std::cout << "\n��� ����� ��������: " << this->pNum << "\n";
	std::cout << "1->��������\n2->��������\n";
	mz = _getch();
	if (mz == '1')
		this->enterPNum();
	else if (mz == '2')
		Sleep(0);
	else
	{
		std::cout << "�� �������� ��������� ������\n";
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
	std::cout << "��������� ���������\n";
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
