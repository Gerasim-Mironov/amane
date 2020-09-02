#pragma once
#pragma warning(disable: 4996)
#include"aqua.h"
#include"participants.h"

class Answear
{
private:
	unsigned int count = 1;
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

	std::string filePath;
public:
	void makeTest();

	void getTested(User);
	void tryToAnswear(const int);
	void loadTest(std::string);
	std::string getRoute()
	{
		for (auto i = title.begin(); i != title.end(); i++)
		{
			if (*i != '\r')
				filePath.push_back((const char)*i);
		}
		filePath += ".txt";

		return filePath;
	}
	
};

static void getchTyping(std::string mt)
{
	char c;
	do
	{
		c = _getch();
		std::cout << c;
		mt += c;
	} while (c != 13);
	std::cout << "\n";
}

