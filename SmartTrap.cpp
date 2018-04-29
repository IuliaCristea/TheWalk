#include "SmartTrap.hpp"



void SmartTrap::getInTrap(SmartRobot &smR)
{
	
	//move back 3 cells
	std::pair<int, int> pos = smR.getPosition();
	if (pos.first > 2 && pos.second > 2)
	{
		smR.move(pos.first - 3, pos.second - 3);
	}
	else
		if (pos.first > 2 && pos.second <= 2)
		{
			// de venit aici;
		}
	{
		smR.move(0, 0);
	}
	
}

void SmartTrap::getInTrap(StrongRobot &stR)
{
	std::cout << "Smart Trap cannot affect you!\n";
}

void SmartTrap::getInTrap(ComplexRobot &cR)
{
	std::cout << "Smart Trap cannot affect you!\n";
}

