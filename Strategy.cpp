#include "Strategy.hpp"
#include <algorithm>
#include <utility>

Strategy* Strategy::_instance = new Strategy();

Strategy::Position Strategy::itemOrFinal(const Map &submap, const Robot*  robot)
{
	Strategy::Position dest = submap.getDestination();
	if (submap.getLeftUp().first <= dest.first && 
		dest.first <= submap.getRightDown().first && 
		 submap.getLeftUp().second <= dest.second && 
		dest.second <= submap.getRightDown().second)
	{
		return dest;
	}
	else
	{
		Strategy::Position robotPos = robot->getPosition();
		int  distMin(INT_MAX);
		int vision = robot->getView();
		int iRobot = submap.getRow() - vision;
		int jRobot = submap.getColumn() - vision;
		if (robotPos.first - submap.getLeftUp().first < vision)
			iRobot = submap.getRow() - vision;
		if (submap.getRightDown().first - robotPos.first < vision)
			iRobot = vision;
		if (robotPos.second - submap.getLeftUp().second < vision)
			jRobot = submap.getColumn();
		if (submap.getRightDown().second - robotPos.second < vision)
			jRobot = vision;
		Strategy::Position closestItemPos(iRobot + submap.getRightDown().first,
										  jRobot + submap.getLeftUp().second);
		bool sem(false);
		for (int i = 0; i < submap.getRow(); i++)
		{
			for (int j = 0; j < submap.getColumn(); j++)
			{
				if (submap[i][j].hasItem())
				{
					sem = true;
					if(i != iRobot || j != jRobot){
						if (abs(iRobot - i) + abs(jRobot - j) < distMin)
						{
							distMin = abs(iRobot - i) + abs(jRobot - j);
							closestItemPos.first = i + submap.getLeftUp().first;
							closestItemPos.second = j + submap.getRightDown().second;
						}
					}
				}
			}
		}
		return sem ? closestItemPos : submap.getDestination();
	}
}



Strategy::Position Strategy::calculateEasyNextPosition(const Map &subMap,
	const Robot* const robot,
	const Position &destination)
{

	Strategy::Position robotPos = robot->getPosition();
	int vision = robot->getView();
	int roboI = subMap.getRow() - vision;
	int robotJ = subMap.getColumn() - vision;
	if (robotPos.first - subMap.getLeftUp().first < vision)
		roboI = subMap.getRow() - vision;
	if (subMap.getRightDown().first - robotPos.first < vision)
		roboI = vision;
	if (robotPos.second - subMap.getLeftUp().second < vision)
		robotJ = subMap.getColumn();
	if (subMap.getRightDown().second - robotPos.second < vision)
		robotJ = vision;


	Strategy::Position robotSubmapPos(roboI, robotJ);
	if (robotPos.first < destination.first)
	{
		return std::make_pair(robotPos.first + 1, robotPos.second);
	}
	else
		if (robotPos.first > destination.first)
		{
			return std::make_pair(robotPos.first - 1, robotPos.second);
		}
		else
			if (robotPos.second > destination.second)
			{
				return std::make_pair(robotPos.first, robotPos.second - 1);
			}
			else
			{
				return std::make_pair(robotPos.first, robotPos.second + 1);
			}
}


Strategy::Position Strategy::calculateNextPosition(const Map &subMap, 
												   const Robot* const robot,
												   const Position &destination)
{
	Strategy::Position robotPos = robot->getPosition();
	int vision = robot->getView();
	
	int roboI = subMap.getRow() - vision - 1;
	int robotJ = subMap.getColumn() - vision - 1;
	if (robotPos.first - subMap.getLeftUp().first < vision)
		roboI = subMap.getRow() - vision - 1;
	if (subMap.getRightDown().first - robotPos.first < vision)
		roboI = vision  + 1;
	if (robotPos.second - subMap.getLeftUp().second < vision)
		robotJ = subMap.getColumn() - vision - 1;
	if (subMap.getRightDown().second - robotPos.second < vision)
		robotJ = vision + 1;


	Strategy::Position robotSubmapPos(roboI,robotJ);

	if (robotPos.first < destination.first)
	{
		if (!subMap[robotSubmapPos.first + 1][robotSubmapPos.second].hasTrap())
		{
			return std::make_pair(robotPos.first + 1, robotPos.second);	
		}
		else 
			if (robotPos.second > destination.second &&
				!subMap[robotSubmapPos.first][robotSubmapPos.second - 1].hasTrap())
			{
				return std::make_pair(robotPos.first, robotPos.second - 1);
			}
			else
				if (robotPos.second < destination.second &&
					!subMap[robotSubmapPos.first][robotSubmapPos.second + 1].hasTrap())
				{
					return std::make_pair(robotPos.first, robotPos.second + 1);
				}
				else
				{
					return std::make_pair(robotPos.first + 1, robotPos.second);
				}
	}
	else 
		if(robotPos.first > destination.first)
		{
			if (!subMap[robotSubmapPos.first - 1][robotSubmapPos.second].hasTrap())
			{
				return std::make_pair(robotPos.first - 1, robotPos.second);
			}
			else
				if (robotPos.second > destination.second &&
					!subMap[robotSubmapPos.first][robotSubmapPos.second - 1].hasTrap())
				{
					return std::make_pair(robotPos.first, robotPos.second - 1);
				}
				else
					if (robotPos.second < destination.second &&
						!subMap[robotSubmapPos.first][robotSubmapPos.second + 1].hasTrap())
					{
						return std::make_pair(robotPos.first, robotPos.second + 1);
					}
					else
					{
						return std::make_pair(robotPos.first - 1, robotPos.second);
					}
		}
		else
		{
			if (robotPos.second < destination.second)
			{
				if (!subMap[robotSubmapPos.first][robotSubmapPos.second + 1].hasTrap())
				{
					return std::make_pair(robotPos.first, robotPos.second + 1);
				}

				else
					if (robotPos.first != 0 &&
						!subMap[robotSubmapPos.first - 1][robotSubmapPos.second].hasTrap())
					{
						return std::make_pair(robotPos.first - 1, robotPos.second);
					}
					else
						if(robotPos.first != 19 &&
							!subMap[robotSubmapPos.first + 1][robotSubmapPos.second].hasTrap())
						{
							return std::make_pair(robotPos.first + 1, robotPos.second);
						}
						else
						{
							return std::make_pair(robotPos.first, robotPos.second + 1);
						}
			}
			else
			{
				if (!subMap[robotSubmapPos.first][robotSubmapPos.second - 1].hasTrap())
				{
					return std::make_pair(robotPos.first, robotPos.second - 1);
				}

				else
					if (robotPos.first != 0 &&
						!subMap[robotSubmapPos.first - 1][robotSubmapPos.second].hasTrap())
					{
						return std::make_pair(robotPos.first - 1, robotPos.second);
					}
					else
						if (robotPos.first != 19 &&
							!subMap[robotSubmapPos.first + 1][robotSubmapPos.second].hasTrap())
						{
							return std::make_pair(robotPos.first + 1, robotPos.second);
						}
						else
						{
							return std::make_pair(robotPos.first, robotPos.second - 1);
						}

			}
		}
}


Strategy::Position Strategy::makeDecision(const Map &subMap,const SmartRobot &smartR)
{

	Position dest = smartR.isItemActive() ? subMap.getDestination() : itemOrFinal(subMap, &smartR);
	return calculateNextPosition(subMap, &smartR, dest);

}


Strategy::Position Strategy::makeDecision(const Map &subMap, const StrongRobot &strongR)
{

	if (strongR.getNoOfFoundItems() == 2 && strongR.getNrOfItems() != 0)
	{
		return calculateEasyNextPosition(subMap, &strongR, subMap.getDestination());
	}
	else
		if(strongR.getNoOfFoundItems() == 2)
		{
			return calculateNextPosition(subMap, &strongR, subMap.getDestination());
		}
		else
		{
			Position dest = itemOrFinal(subMap, &strongR);
			return calculateNextPosition(subMap, &strongR, dest);				
		}

}

Strategy::Position Strategy::makeDecision(const Map &subMap, const ComplexRobot &complexR)
{

	Position dest = complexR.isItemActive() ? subMap.getDestination() : itemOrFinal(subMap, &complexR);
	return calculateNextPosition(subMap, &complexR, dest);

}

Strategy* Strategy::instance()
{
	return _instance;
}