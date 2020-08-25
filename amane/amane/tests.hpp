#pragma once
#include"aqua.h"

class Test
{
private:
	std::vector<std::string> question;
	std::map<std::string, bool> ans;

	const int maxMark = 12;
	float avMark;
public:
	void testMe();
	void saveResults();

	void makeTest();
	void checkStats();
};