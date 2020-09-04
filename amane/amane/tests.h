#pragma once
#pragma warning(disable: 4996)
#include"aqua.h"
#include"participants.h"

class testNode
{	
	std::string question;
	std::string options[3];
public:
	bool truth[3];

	void printNode();
	void setQuestion(std::string);
	void setOption(std::string, const int);
	void setTruth(bool, const int);

	std::string getQuestion();
	std::string getOption(const int);
	bool getTruth(const int);
};

class Test
{
private:
	std::vector<testNode> as;

	std::string title;
	std::string topic;

	const int maxMark = 12;
	int currentMark;
	float onePiece;
	
	std::string filePath;
public:
	void getTested(User);
	void makeTest();

	bool saveTest()noexcept;
	void loadTest(std::string);

	std::string getRoute()
	{
		filePath = "";
		for (auto i = title.begin(); i != title.end(); i++)
		{
			if (*i != '\r')
				filePath.push_back((const char)*i);
		}
		filePath += "_TEST.txt";

		return filePath;
	}
};

static bool rightOrWrong(std::string mz)
{
	for (auto i = mz.end(); i != mz.begin(); i--)
	{
		if ((const char)*i == '0')
			return false;
		else
			return true;
	}
}