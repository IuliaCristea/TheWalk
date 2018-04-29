#pragma once
#include "Map.hpp"
#include "Strategy.hpp"
#include "Robot.hpp"

class GameEngine
{
public:
	typedef std::pair<int, int> Position;

private:

	Map _map;
	Robot* _robot;
	static GameEngine* _instance;

	GameEngine();
	~GameEngine();
public:
	void play();
	void setRobot(Robot *);

	static GameEngine *instance()
	{
		return _instance;
	}
};