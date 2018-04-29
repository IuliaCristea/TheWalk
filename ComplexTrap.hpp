#pragma once
#include "SmartRobot.hpp"
#include "StrongRobot.hpp"
#include "ComplexRobot.hpp"

class ComplexTrap : public Trap
{
public:
	virtual void getInTrap(SmartRobot &smR);
	virtual void getInTrap(StrongRobot &stR);
	virtual void getInTrap(ComplexRobot &cR);
};

