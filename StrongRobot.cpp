#pragma once
#include "StrongRobot.hpp"
#include "Strategy.hpp"

StrongRobot::StrongRobot(std::string name):Robot(name)
{
	_nrOfItems = 0;
	_foundItems = 0;
	_view = 2;
}

void StrongRobot::useItem(Item* item)
{
	item->useItem(*this);
}

void StrongRobot::getInTrap(Trap* trap)
{
	trap->getInTrap(*this);
}


int StrongRobot::getNrOfItems()const
{
	return _nrOfItems;
}

void StrongRobot::UpdateNoOfItems(int nr)
{
	_nrOfItems ++;
}

int StrongRobot::getNoOfFoundItems()const
{
	return _foundItems;
}

void StrongRobot::IncreaseNoOfFoundIntems()
{
	_nrOfItems++;
}

Robot::Position StrongRobot::makeDecision(const Map &subMap) {

	return Strategy::instance()->makeDecision(subMap, *this);
}