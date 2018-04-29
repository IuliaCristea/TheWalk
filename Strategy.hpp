#pragma once
#include <iostream>
#include "Map.hpp"

class Strategy
{
public:
	typedef std::pair<int, int> Position;
	
private:
	
	Position itemOrFinal(const Map &submap,const Robot* robot);
	Position calculateNextPosition(const Map &subMap,const Robot * const robot,const Position &destination);
	Position calculateEasyNextPosition(const Map &subMap, const Robot * const robot, const Position &destination);
	static Strategy* _instance;
public:
	
	Position makeDecision(const Map &subMap,const SmartRobot &smartR);
	Position makeDecision(const Map &subMap, const StrongRobot &strongR);
	Position makeDecision(const Map &subMap, const ComplexRobot &complexR);
	static Strategy* instance();
};

