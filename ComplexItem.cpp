#include "ComplexItem.hpp"

class Map;

void ComplexItem::useItem(SmartRobot &smR)
{
	std::cout << "Smart Robot cannot use Complex Item"<<std::endl;
}

void ComplexItem::useItem(StrongRobot &smR)
{
	std::cout << "Strong Robot cannot use Complex Item"<<std::endl;
}

void ComplexItem::useItem(ComplexRobot &smR)
{
	// move closer to the destination
	std::cout << "Complex Robot has been move by his special Item" << std::endl;

	// modify this so the robot will be moves in destination's quarter
	smR.move((smR.getDestionation().first) - 3, (smR.getDestionation().second - 3));
	// now i know that my robot is 3 cells away from the destination (diagonally) 
}


