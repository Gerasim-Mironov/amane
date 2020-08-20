#include"aqua.h"
#include"participants.h"

int main()
{
#pragma region
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
#pragma endregion
	User amane;
	amane.enterLogin();
	amane.enterPassword();
	amane.enterFIO();
	amane.enterEmail();
	amane.enterPNum();
	
	std::cout << amane.getPassword();
	std::cout << amane.getNum();
	return 0x29a;
}