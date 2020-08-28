#pragma once
#include"aqua.h"
#include"participants.h"

class Answear
{
private:
	unsigned int count = 0;
public:
	std::map<std::string, bool> options;

	void addOptions();
	void printOptions();
};

class Test
{
private:
	const int maxMark = 12;
	int currentMark;
	float onePiece;

	std::vector<Answear>ar;
	std::vector<std::string> questions;

	std::string topic;
	std::string title;
public:
	void makeTest();

	void getTested();
	void tryToAnswear(const int);
	void saveInFile();
	char* getRoute()
	{
		char fPath[256];
		strcpy(fPath, title.c_str());
		strcat(fPath, "TEST.txt");

		return fPath;
	}
};