#pragma once
#include "ComplexRobot.hpp"
#include "Strategy.hpp"

ComplexRobot::ComplexRobot(std::string name) :Robot(name)
{
	_view = 3;
}
void ComplexRobot::useItem(Item* item)
{
	item->useItem(*this);
}

void ComplexRobot::getInTrap(Trap* trap)
{
	trap->getInTrap(*this);
}

Robot::Position ComplexRobot::makeDecision(const Map &subMap) {

	return Strategy::instance()->makeDecision(subMap, *this);
}