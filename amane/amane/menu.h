#pragma once
#include"aqua.h"
#include"participants.h"
#include"tests.hpp"

class menu
{
private:
	User mt;
	Test sl;
public:
	menu() = default;
	void entrance();

	void logIn();
	void signIn();

	void intermediate();
};