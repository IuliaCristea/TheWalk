#include "GameEngine.h"


GameEngine* GameEngine::_instance = new GameEngine();

GameEngine::GameEngine() :
	_map(20, 20),
	_robot(NULL)
{
	_map.makeMap();

}

GameEngine::~GameEngine()
{
	delete _robot;
}



void GameEngine::play()
{
	int answer;
	while(true)
	{
		_map.showMap(_robot->getPosition());
		std::cout << "Do you want to go further with the game? (0 / 1)\n";
		std::cin >> answer;
		if (answer == 0)
			break;
		
		Map submap = _map.subMap(_robot->getPosition().first,
			_robot->getPosition().second,
			_robot->getView());
		submap.showMap();
		Position newPos = _robot->makeDecision(submap);

		_robot->move(newPos.first, newPos.second);

		if (newPos == _map.getDestination())
		{
			std::cout << "GG boss, u won this time! \n";
			break;
		}

		if (_map[newPos.first][newPos.second].hasItem())
		{
			_robot->useItem(_map[newPos.first][newPos.second].getItem());
		}
		
		if (_map[newPos.first][newPos.second].hasTrap())
		{
			_robot->getInTrap(_map[newPos.first][newPos.second].getTrap());
		}

		if (_robot->gameOver())
		{
			std::cout << "Game OVER!\n";
			break;
		}

	}

}

void GameEngine::setRobot(Robot* robot)
{
	_robot = robot;
}