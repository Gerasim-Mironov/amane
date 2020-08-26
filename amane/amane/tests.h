#pragma once
#include"aqua.h"

class Answear
{
private:
	std::map<std::string, bool> options;
public:
	bool checkAnswear();

	void addOptions();
};

class Question
{
private:
	Answear* mt;
public:
	
};

class Test
{

};