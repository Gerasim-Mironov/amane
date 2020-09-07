#include "tests.h"

void testNode::printNode()
{
	std::cout << question << "\n";
	for (size_t i = 0; i < 3; i++)
	{
		secret(options[i]);
		std::cout << "\n";
	}
}

void testNode::setQuestion(std::string sa)
{
	question = sa;
}
void testNode::setOption(std::string sa, const int num)
{
	options[num] = sa;
}
void testNode::setTruth(bool sa, const int num)
{
	truth[num] = sa;
}

std::string testNode::getQuestion()
{
	return question;
}
std::string testNode::getOption(const int dv)
{
	return options[dv];
}
bool testNode::getTruth(const int dv)
{
	return truth[dv];
}


void Test::getTested(User ul)
{
	int vectorNum = 0;
	currentMark = 0;
	onePiece = maxMark / as.size();

	for (size_t i = 0; i!=as.size(); i++)
	{
		system("cls");

		as[i].printNode();

		char mz = _getch();
		if (mz == '1' || mz == '2' || mz == '3')
		{
			if (mz == '1')
			{
				if (as[vectorNum].getTruth(0) == true)
					currentMark += onePiece;
				vectorNum++;
			}
			if (mz == '2')
			{
				if (as[vectorNum].getTruth(1) == true)
					currentMark += onePiece;
				vectorNum++;
			}
			if (mz == '3')
			{
				if (as[vectorNum].getTruth(2) == true)
					currentMark += onePiece;
				vectorNum++;
			}
		}
		else
		{
			std::cout << "не тот вариант- баллов не получишь\n";
		}
	}

	std::cout << "пользователь " << ul.getLogin() << " получил " << currentMark << " баллов, что €вл€етс€ " << currentMark / maxMark * 100
		<< " процентами от его потенциала в тесте " << title << " по теме " << topic << "\n";

	std::ofstream wr;
	wr.open("UserStats.txt", std::ios::app);
	wr << "\nпользователь " << ul.getLogin() << " получил " << currentMark << " баллов, что €вл€етс€ " << currentMark / maxMark * 100
		<<" процентами от его потенциала в тесте "<<title<<" по теме "<<topic<<"\n";
	wr.close();

	Sleep(6200);
	system("cls");
}

void Test::makeTest()
{
	testNode toulouse;
	std::string mari = "";
	std::cout << "название: ";
	getchCin(mari);
	title = mari;

	mari.clear();
	std::cout << "тема: ";
	getchCin(mari);
	topic = mari;

	while (0x29a)
	{
		mari.clear();
		std::cout << "введите вопрос:\n";
		getchCin(mari);
		toulouse.setQuestion(mari);

		for (size_t i = 1; i < 4; i++)
		{
			mari.clear();

			std::cout << "введите вариант ответа:\n";
			getchCin(mari);
			toulouse.setOption(mari, i-1);

			std::cout << "он правильный?.\n1->нет\n0->да\n";
			char key = _getch();
			switch (key)
			{
			case'1':
			{
				toulouse.setTruth(false, i-1);
			}break;
			case '0':
			{
				toulouse.setTruth(true, i-1);
			}break;
			default:exit(3);
			}
		}
		as.push_back(toulouse);
		std::cout << "это всЄ?.\n1->да\n0->нет\n";
		char ch = _getch();
		switch (ch)
		{
		case'1':
		{
			std::ofstream wr;
			wr.open("TestRoots.txt", std::ios::app);
			wr <<"\n" << getRoute();
			wr.close();
			return;
		}break;
		case '0':
		{
			continue;
		}break;
		default:exit(3);
		}
	}
}

bool Test::saveTest()noexcept
{
	std::ofstream wr;
	wr.open(getRoute());
	wr << (const char)&title << "\n";
	wr << (const char)&topic << "\n\n";
	for (size_t i = 0; i < as.size(); i++)
	{
		wr << (const char)&as[i].getQuestion() << "\n";
		wr <<"1." << (const char)&as[i].getOption(0) << " " << as[i].getTruth(0)<<"\n";
		wr <<"2." << (const char)&as[i].getOption(1) << " " << as[i].getTruth(1) << "\n";
		wr <<"3." << (const char)&as[i].getOption(2) << " " << as[i].getTruth(2) << "\n";
	}

	wr.close();
	return true;
}

void Test::loadTest(std::string root)
{
	int count = 0;
	int intCount = 0;
	std::string germ = "";

	testNode temp;

	std::ifstream re;
	re.open(root);
	while (!re.eof())
	{
		germ.clear();
		std::getline(re, germ);
		
		if (count == 0)
			title = germ;
		else if (count == 1)
			topic = germ;
		else if (count == 2)
			Sleep(0);
		else
		{
			if (count == 3||count==7||count==11||count==15||count==19)
			{
				temp.setQuestion(germ);
			}
			else
			{
				temp.setOption(germ, intCount);

				if (rightOrWrong(germ) == false)
				{
					temp.setTruth(false, intCount);
				}
				else
				{
					temp.setTruth(true, intCount);
				}
				if (intCount < 2)
					intCount++;
				else
				{
					intCount = 0;
					as.push_back(temp);
				}
			}
			
		}
		count++;
	}
	re.close();
}
