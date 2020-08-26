#pragma once
#include"aqua.h"
#include"participants.h"
#include"tests.h"

class Menu
{
private:
	User mt;
	Test sl;
public:
	Menu() = default;
	void entrance();

	void logIn();
	void signIn();

	void intermediate();
};