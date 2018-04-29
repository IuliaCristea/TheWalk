#pragma once
#include "Item.hpp"
#include "Trap.hpp"

class SmartRobot : public Robot
{
public:
	SmartRobot(std::string name);
	virtual void useItem(Item* item);
	virtual void getInTrap(Trap* trap);
	void setVisual(int nr);
	Robot::Position makeDecision(const Map &subMap);
};


