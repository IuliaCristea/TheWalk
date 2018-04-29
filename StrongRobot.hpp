#pragma once
#include "Item.hpp"
#include "Trap.hpp"

class StrongRobot : public Robot
{
	int _nrOfItems;
	int _foundItems;
public:
	StrongRobot(std::string name);
	virtual void useItem(Item* item);
	virtual void getInTrap(Trap* trap);
	int getNrOfItems()const;
	void UpdateNoOfItems(int nr);
	void IncreaseNoOfFoundIntems();
	int getNoOfFoundItems() const;
	Robot::Position makeDecision(const Map &subMap);
};


