#include <iostream>
#include "GameEngine.h"


int main()
{


	std::cout << "Pentru Smart Robot, apasati introduceti 1\n";
	std::cout << "Pentru Complex Robot, apasati introduceti 2\n";
	std::cout << "Pentru Strong Robot, apasati introduceti 3\n";
	int answer;
	std::cin >> answer;
	Robot* robot = NULL;

	switch (answer)
	{
	case 1:
		robot = new SmartRobot("Ion");
		break;
	case 2:
		robot = new ComplexRobot("Ion");
		break;
	case 3:
		robot = new StrongRobot("Ion");
		break;
	default:
		std::cout << "This is not going to work mate, bye.";
	}
	
	GameEngine::instance()->setRobot(robot);
	GameEngine::instance()->play();
	return 0;
}