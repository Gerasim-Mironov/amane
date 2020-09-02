#pragma once
#include"aqua.h"

class User
{
private:
	std::string login;
	std::string password;
	std::string fio;
	std::string email;
	std::string pNum;

	std::string filePath;
	bool Admin=false;

	bool checkEmail()
	{
		for (auto i = this->email.begin(); i != this->email.end(); i++)
		{
			if ((const char)*i == '@')
				return true;
		}
		return false;
	}
	bool checkPNum()
	{
		for (auto i = this->pNum.begin(); i != this->pNum.end(); i++)
			if ((const char)*i == '+')
				return true;
		return false;
	}
public:
	void enterLogin();
	void enterPassword();
	void enterFIO();
	void enterEmail();
	void enterPNum();

	void accountSettings();

	std::string getRoute();

	std::string getLogin()
	{
		return this->login;
	}
	std::string getPassword()
	{
		return this->password;
	}
	std::string getName()
	{
		return this->fio;
	}
	std::string getMail()
	{
		return this->email;
	}
	std::string getNum()
	{
		return this->pNum;
	}

	bool getToKnow()
	{
		return this->Admin;
	}
	void changleAngle()
	{
		if (this->getToKnow() == true)
			this->Admin = false;
		else
			this->Admin = true;
	}
};