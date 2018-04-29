#include "ComplexTrap.hpp"



void ComplexTrap::getInTrap(SmartRobot &smR)
{
	std::cout << "Complex Trap cannot affect you!\n";
}

void ComplexTrap::getInTrap(StrongRobot &stR)
{
	std::cout << "Complex Trap cannot affect you!\n";
}

void ComplexTrap::getInTrap(ComplexRobot &cR)
{
	cR.isItemActive(false);
	cR.setGameOver(1);
}
