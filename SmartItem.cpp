#include "SmartItem.hpp"



void SmartItem::useItem(SmartRobot &smR)
{
	std::cout << "Smart Robot gained 3 visual power"<<std::endl;
	smR.setVisual(4);
	smR.isItemActive(true);
}

void SmartItem::useItem(StrongRobot &stR)
{
	std::cout << "Strong Robot cannot use Smart Item" << std::endl;
}

void SmartItem::useItem(ComplexRobot &cR)
{
	std::cout << "Complex Robot cannot use Smart Item"<<std::endl;
}



