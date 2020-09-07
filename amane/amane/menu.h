#pragma once
#include"aqua.h"
#include"participants.h"
#include"tests.h"

class Menu
{
private:
	User mt;
	Test sl[32];

	int chrono = 0;
public:
	Menu() = default;
	void entrance();

	void logIn();
	void signIn();

	void intermediate();
	void loadTests();
};