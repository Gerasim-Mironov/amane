#include "tests.h"


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

void Answear::printOptions()
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
	std::ofstream wr;
	wr.open(getRoute());
	wr << title << "\n";
	std::cout << "������� ���� �����: \n";
	getchTyping(this->topic);
	wr << topic << "\n";
	std::string slick;
	while (0x29a)
	{
		slick = "";
		Answear instance;
		getchTyping(slick);
		wr << slick << "\n";
		questions.push_back(slick);
		instance.addOptions();
		ar.push_back(instance);
		std::cout << "����������?\n 0-��\n1->���\n";
		char ch = getch();
		switch (ch)
		{
		case'0':continue; break;
		case'1':break;
		default:exit(EXIT_FAILURE);
		}
	}
}



void Test::getTested()
{
	for (size_t i = 0; i < questions.size(); i++)
	{
		std::cout << questions[i]<<"\n";
		ar[i].printOptions();
		tryToAnswear(i);
	}
	int mt = currentMark / (maxMark / 100);
	system("cls");
	std::cout << "�������� ���� ������, ���� ������ ���������� " << currentMark << " ��� ��������" << mt << " ���������� �� ������ ����������\n";
}

void Test::tryToAnswear(const int eucalyptus)
{
	char c = _getch();
	if (c != '1' || c != '2' || c != '3')
		tryToAnswear(eucalyptus);
	int temp = 0;
	for (auto& re : ar[eucalyptus].options)
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
