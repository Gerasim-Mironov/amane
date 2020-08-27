#include "tests.h"


bool Answear::giveAnswear()
{
	char c = _getch();
	if (c != '1' || c != '2' || c != '3')
		giveAnswear();
	int temp = 0;
	for (auto& re : options)
    {
		if (temp == (int)c - 1)
		{
			if (re.second == true)
				currentMark += onePiece;
			break;
		}
		temp++;
	}
}

void Answear::addOptions()
{
	do {
		bool Ul;
		std::cout << "������� ������� ������:\n";
		std::string ruby;
		getchTyping(ruby);
		std::cout << "��� ���������� �����?\n 1-���\n0->��\n";
		char ch = _getch();
		switch (ch)
		{
		case '1': Ul = false; break;
		case '0': Ul = true; break;
		default:ch = _getch();
		}

		options.insert(std::make_pair(ruby, Ul));
		count++;
	} while (count < 3);
	count = 0;
}

void Answear::printQuestions()
{
	unsigned int mo = 0;
	for (auto& sa : this->options)
	{
		std::cout << mo << "." << sa.first << "\n";
		mo++;
	}
}

void Test::makeTest()
{
	std::cout << "������� �������� �����: \n";
	getchTyping(this->title);
	std::cout << "������� ���� �����: \n";
	getchTyping(this->topic);
	
	std::string slick;
	while (0x29a)
	{
		slick = "";
		Answear instance;
		getchTyping(slick);
		questions.push_back(slick);
		instance.addOptions();
		ar.push_back(instance);
		std::cout << "����������?\n 0-��\n1->���\n";
		char ch = getch();
		switch (ch)
		{
		case'0':continue; break;
		case '1':break;
		default:exit(EXIT_FAILURE);
		}
	}
}

void Test::getTested()
{
	std::cout << title << " ����: " << topic << "\n";
	for (auto mt=questions.begin(), ul=ar.begin();mt!=questions.end()&& ul!=ar.end();mt++, ul++)
	{
		std::cout << *mt << "\n";
	}
}
