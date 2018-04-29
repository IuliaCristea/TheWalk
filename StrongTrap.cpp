#include "StrongTrap.hpp"



void StrongTrap::getInTrap(SmartRobot &smR)
{
	std::cout << "Strong Trap cannot affect you!\n";
}

void StrongTrap::getInTrap(StrongRobot &stR)
{
	
	int nrItems = stR.getNrOfItems();
	if (nrItems)
	{
		stR.UpdateNoOfItems(nrItems--);
		std::cout << "Oh, no! Now you have only " << nrItems << " Strong Items!\n" << std::endl;
	}
	else
	{
		stR.move(0, 0);
		std::cout << "Well, that's bad. You are now at the beginning.\n" << std::endl;
	}
	

}

void StrongTrap::getInTrap(ComplexRobot &cR)
{
	std::cout << "Strong Trap cannot affect you!\n";
}



