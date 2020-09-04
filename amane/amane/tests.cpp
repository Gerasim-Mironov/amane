#include "tests.h"

void testNode::printNode()
{
	std::cout << question << "\n";
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << options[i] << "\n";
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
	currentMark = 0;
	onePiece = as.size()/maxMark;

	for (size_t i = 1; i!=as.size(); i++)
	{
		system("cls");

		as[i].printNode();

		char mz = _getch();
		if (mz == '1' || mz == '2' || mz == '3')
		{
			if (as[i].truth[static_cast<int>(mz)-48] == true)
			{
				currentMark += onePiece;
			}
		}
		else
		{
			std::cout << "не тот вариант- баллов не получишь\n";
		}
	}

	std::ofstream wr;
	wr.open("UserStats.txt", std::ios::app);
	wr << "пользователь" << ul.getLogin() << " получил" << currentMark << " баллов, что является" << currentMark / maxMark * 100
		<<"процентами от его потенциала в тесте "<<title<<" по теме "<<topic<<"\n";
	wr.close();
}

void Test::makeTest()
{
	while (0x29a)
	{
		testNode toulouse;
		std::string mari = "";
		std::cout << "название: ";
		std::cin >> mari;
		title = mari;

		mari = "";

		std::cout << "тема: ";
		std::cin.get();
		std::cin >> mari;
		topic = mari;

		mari = "";

		std::cout << "введите вопрос:\n";
		std::cin >> mari;
		toulouse.setQuestion(mari);

		for (size_t i = 0; i < 3; i++)
		{
			mari = "";
			mari += (const char)&i;
			mari += '.';

			std::string temp;
			std::cout << "введите вариант ответа:\n";
			std::cin >> temp;
			mari += temp;
			toulouse.setOption(mari, i);

			std::cout << "он правильный?.\n1->нет\n0->да\n";
			char key = _getch();
			switch (key)
			{
			case'1':
			{
				toulouse.setTruth(false, i);
			}break;
			case '0':
			{
				toulouse.setTruth(true, i);
			}break;
			default:exit(3);
			}
		}
		as.push_back(toulouse);
		std::cout << "это всё?.\n1->да\n0->нет\n";
		char ch = _getch();
		switch (ch)
		{
		case'1':
		{
			std::ofstream wr;
			wr.open("TestRoots.txt", std::ios::app);
			wr << getRoute() << "\n";
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
	wr << title << "\n";
	wr << topic << "\n\n";
	for (size_t i = 0; i < as.size(); i++)
	{
		wr << as[i].getQuestion() << "\n";
		wr << as[i].getOption(0) << " " << as[i].getTruth(0)<<"\n";
		wr << as[i].getOption(1) << " " << as[i].getTruth(1) << "\n";
		wr << as[i].getOption(2) << " " << as[i].getTruth(2) << "\n";
	}

	wr.close();
	return true;
}

void Test::loadTest(std::string root)
{
	int count = 0;
	int intCount = 0;

	std::ifstream re;
	re.open(root);
	while (!re.eof())
	{
		testNode temp;

		std::string germ = "";
		std::getline(re, germ);
		
		if (count == 0)
			title = germ;
		if (count == 1)
			topic = germ;

		if (count % 4 == 0)
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
			intCount++;
		}

		as.push_back(temp);
		count++;
	}
	
	re.close();
}
