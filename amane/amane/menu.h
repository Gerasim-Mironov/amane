#pragma once
#include"aqua.h"
#include"participants.h"

class menu
{
private:
	User Ul;
	Admin mt;
public:
	menu() = default;
	void entrance();

	void logIn();
	void signIn();
};