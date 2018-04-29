#pragma once
#include "SmartRobot.hpp"
#include "StrongRobot.hpp"
#include "ComplexRobot.hpp"

class SmartItem : public Item
{
public:

	virtual void useItem(SmartRobot &smR);
	virtual void useItem(StrongRobot &stR);
	virtual void useItem(ComplexRobot &cR);
};

