#pragma once
#include"aqua.h"
#include"participants.h"

class Answear
{
private:
	std::map<std::string, bool> options;
	unsigned int count = 0;
public:
	const int maxMark = 12;
	int currentMark;
	float onePiece;

	bool giveAnswear();

	void addOptions();
	void printQuestions();
};

class Test
{
private:
	std::vector<Answear>ar;
	std::vector<std::string> questions;

	std::string topic;
	std::string title;
public:
	void makeTest();

	void getTested();
	char* getRoute()
	{
		char fPath[256];
		strcpy(fPath, title.c_str());
		strcat(fPath, "TEST.txt");

		return fPath;
	}
};