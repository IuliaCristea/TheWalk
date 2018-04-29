#include "StrongItem.hpp"



void StrongItem::useItem(SmartRobot &smR)
{
	std::cout << "Smart Robot cannot use Strong Item.\n";
}

void StrongItem::useItem(StrongRobot &stR)
{
	stR.UpdateNoOfItems(1);
	stR.isItemActive(true);
	std::cout << "Strong Robot cannot be affected by the next trap.\n";
	
}

void StrongItem::useItem(ComplexRobot &cR)
{
	std::cout << "Complex Robot cannot use Strong Item.\n";
}

