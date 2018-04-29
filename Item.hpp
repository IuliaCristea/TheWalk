#pragma once
#include "Robot.hpp"


class SmartRobot;
class StrongRobot;
class ComplexRobot;

class Item
{
public:
	virtual void useItem(SmartRobot &smR) = 0;
	virtual void useItem(StrongRobot &stR) = 0;
	virtual void useItem(ComplexRobot &cR) = 0;
	
};