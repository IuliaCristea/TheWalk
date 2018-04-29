#pragma once
#include "Cell.hpp"
#include <ctime>
#include <utility>

class Map
{
public:
	typedef std::pair<int, int> Position;
protected:
	Cell** _map;
	Position _destination;
	int _row;
	int _column;
	Position _leftUp;
	Position _rightDown;
public:

	Map(int row, int column);
	Map(const Map &toCopy);
	Map operator = (const Map &toCopy);
	void makeMap();
	void showMap(Map::Position pos);
	void showMap();
	int getRow()const;
	int getColumn()const;
	std::pair<int, int> getDestination()const;
	Map subMap(int row, int column, int visual);
	Position getLeftUp()const;
	Position getRightDown() const;
	Cell* operator [](int row)const;
	~Map();
};

