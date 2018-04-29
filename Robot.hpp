#pragma once
#include <iostream>
#include <string>
#include <utility>

class Map;
class Item;
class Trap;
class Robot
{
public:
	typedef std::pair<int, int> Position;
protected:
	std::string _name;
	int _view;
	Position _position;
	bool _gameOver;
	Position _destination;
	bool _isItemActive;

public:

	virtual void useItem(Item* item) = 0; //pt fiecare functie in parte se va folosi fiecare item in parte
	virtual void getInTrap(Trap* trap) = 0; //same
	virtual Position makeDecision(const Map &subMap) = 0;
	Robot(std::string name);
	virtual void move(int row, int column); //modifica _position.row/column.
	virtual int getView() const;
	virtual std::pair<int,int> getPosition() const;
	virtual bool gameOver() const;
	virtual void setGameOver(bool go);
	virtual std::string getName() const;
	virtual void setDestination(int row, int column);
	virtual std::pair<int, int> getDestionation() const;
	void isItemActive(const bool toSet)
	{
		_isItemActive = toSet;
	}
	bool isItemActive() const
	{
		return _isItemActive;
	}
};