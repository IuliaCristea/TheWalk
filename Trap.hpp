#pragma once
#include "Robot.hpp"
class SmartRobot;
class StrongRobot;
class ComplexRobot;

class Trap
{
public:
	virtual void getInTrap(SmartRobot &smR) {}
	virtual void getInTrap(StrongRobot &stR) {}
	virtual void getInTrap(ComplexRobot &cR) {}
};