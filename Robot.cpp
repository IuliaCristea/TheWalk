#include "Robot.hpp"

Robot::Robot(std::string name)
{
	_name = name;
	_position.first = 0;
	_position.second = 0;
	_gameOver = false;
	_isItemActive = false;
}

void Robot::move(int row, int column)
{
	_position.first = row;
	_position.second = column;
}

int Robot::getView() const
{
	return _view;
}

std::pair<int, int> Robot::getPosition() const
{
	return _position;
}

bool Robot::gameOver() const
{
	return _gameOver;
}

void Robot::setGameOver(bool go)
{
	_gameOver = go;
}

std::string Robot::getName() const
{
	return _name;
}

void Robot::setDestination(int row, int column)
{
	_destination.first = row;
	_destination.second = column;
}

std::pair<int, int> Robot::getDestionation() const
{
	return _destination;
}
