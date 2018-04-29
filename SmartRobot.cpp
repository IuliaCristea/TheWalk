#include "SmartRobot.hpp"
#include "Strategy.hpp"

SmartRobot::SmartRobot(std::string name):Robot(name)
{
	_view = 1;
}

void SmartRobot::useItem(Item* item)
{
	if(item!=NULL)
		item->useItem(*this);

}

void SmartRobot::getInTrap(Trap* trap)
{
	trap->getInTrap(*this);
}

void SmartRobot::setVisual(int nr)
{
	_view = nr;
}


Robot::Position SmartRobot::makeDecision(const Map &subMap) {

	return Strategy::instance()->makeDecision(subMap, *this);
}