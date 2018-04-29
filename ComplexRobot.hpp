#pragma once
#include "Item.hpp"
#include "Trap.hpp"

class ComplexRobot : public Robot
{

public:
	ComplexRobot(std::string name);
	virtual void useItem(Item* item);
	virtual void getInTrap(Trap* trap);
	virtual Position makeDecision(const Map &subMap);
};

