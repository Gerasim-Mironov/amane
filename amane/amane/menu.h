#pragma once
#include"aqua.h"
#include"participants.h"

class menu
{
private:
	User mt;
public:
	menu() = default;
	void entrance();

	void logIn();
	void signIn();

	void intermediate();
};