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

	bool checkEmail()
	{
		for (auto i = this->login.begin(); i != this->login.end(); i++)
		{
			if (*i != '@')
				return true;
		}
		return false;
	}
	bool checkPNum()
	{
		for (auto i = this->pNum.begin(); i != this->login.end(); i++)
			if (*i == '+')
				return true;
			else
				return false;
	}
public:
	void enterLogin();
	void enterPassword();
	void enterFIO();
	void enterEmail();
	void enterPNum();

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
		return this->pNum;
	}
	std::string getNum()
	{
		return this->pNum;
	}
};

class Admin
{

};