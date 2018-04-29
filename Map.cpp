#pragma once
#include "Map.hpp"
#include <iostream>
#include <utility>
#include <algorithm>


Map::Map(int row, int column)
{
	_row = row;
	_column = column;
	 _map = new Cell*[_row];

	for (int i = 0; i < _row; i++)
	{
		_map[i] = new Cell[_column];
	}
	
}

Map::Map(const Map &toCopy)
{
	_destination = toCopy._destination;
	_row = toCopy._row;
	_column = toCopy._column;
	_map = new Cell*[_row];
	_leftUp = toCopy._leftUp;
	_rightDown = toCopy._rightDown;
	for (int i = 0; i < _row; i++)
	{
		_map[i] = new Cell[_column];
	}

	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _column; j++)
		{
			_map[i][j] = toCopy._map[i][j];
		}
	}
}

Map Map::operator = (const Map &toCopy)
{
	_destination = toCopy._destination;
	_row = toCopy._row;
	_column = toCopy._column;
	_map = new Cell*[_row];
	for (int i = 0; i < _row; i++)
	{
		_map[i] = new Cell[_column];
	}

	for (int i = 0; i < _row; i++)
	{
		for (int j = 0; j < _column; j++)
		{
			_map[i][j] = toCopy._map[i][j];
		}
	}
	return *this;
}

void Map::makeMap()
{
	srand(time(NULL));
	//set destination
	int rowLocation = rand() % 19;
	int columnLocation = rand() % 19;
	_destination.first = rowLocation;
	_destination.second = columnLocation;

	for (int i = 0; i < 6; i++)
	{
		//placing items over the map
		int row = rand() % 19;
		if (row == rowLocation)
		{
			while (row == rowLocation)
			{
				row = rand() % 19;
			}
		}
		int column = rand() % 19;
		if (column == columnLocation)
		{
			while (column == columnLocation)
			{
				column = rand() % 19;
			}
		}
		_map[row][column].setHasItem(true); // this cell has an item;
		int itemNr = rand() % 3; // this is the type of item on this cell; 0 is for SmartItem, 1 for StrongItem and 2 for ComplexItem
		_map[row][column].setItemType(itemNr);

		//placing traps over the map
		int rowT = rand() % 19;
		if (rowT == rowLocation || rowT == row)
		{
			while (rowT == rowLocation || rowT == row)
			{
				rowT = rand() % 19;
			}
		}
		int columnT = rand() % 19;
		if (columnT == columnLocation || columnT == column)
		{
			while (columnT == columnLocation || columnT == column)
			{
				columnT = rand() % 19;
			}
		}
		_map[rowT][columnT].setHasTrap(true); // this cell has a trap;
		int trapNr = rand() % 3; // this is the type of trap on this cell; 0 is for SmartTrap, 1 for StrongTrap and 2 for ComplexTrap
		_map[row][column].setTrapType(trapNr);
	}

	
}

void Map::showMap(Map::Position pos)
{
	
	for (int i = 0; i < _row; i++)
	{
		
		for (int j = 0; j < _column; j++)
		{
			
			if (i == pos.first && j == pos.second)
			{
				std::cout << "R ";
				continue;
			}

			if (_map[i][j].hasItem())
			{
				
				std::cout << "i" << " ";
			}
			else
				if (_map[i][j].hasTrap())
				{
					std::cout << "T" << " ";
				}
				else
					if (_destination.first == i && _destination.second == j)
					{
						std::cout << "L" << " ";
					}
					else
					{
						std::cout << 0 << " ";
					}
		}
		std::cout << std::endl;
	}
	
}


void Map::showMap()
{

	for (int i = 0; i < _row; i++)
	{

		for (int j = 0; j < _column; j++)
		{


			if (_map[i][j].hasItem())
			{

				std::cout << "i" << " ";
			}
			else
				if (_map[i][j].hasTrap())
				{
					std::cout << "T" << " ";
				}
				else
					if (_destination.first == i && _destination.second == j)
					{
						std::cout << "L" << " ";
					}
					else
					{
						std::cout << 0 << " ";
					}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

}


Map::Position Map::getDestination() const
{
	return _destination;
}

int Map::getRow() const 
{
	return _row;
}

int Map::getColumn() const
{
	return _column;
}

Map Map::subMap(int row, int column, int visual)
{

	Map::Position left_up = std::make_pair(std::max(0,row-visual),std::max(0,column-visual));
	Map::Position left_down = std::make_pair(std::min(19,row+visual),std::max(0,column-visual));
	Map::Position right_up = std::make_pair(std::max(19,row-visual),std::min(19,column+visual));
	Map::Position right_down = std::make_pair(std::min(19,row+visual),std::min(19,column+visual));
	
	Map _subMap(left_down.first - left_up.first + 1, right_up.second - left_up.second + 1);
	_subMap._destination = _destination;
	_subMap._leftUp = left_up;
	_subMap._rightDown = right_down;
	
	for(int startI = left_up.first, i = 0; startI <= left_down.first; startI++, i++)
	{
		for (int startJ = left_up.second, j = 0; startJ <= right_up.second; startJ++, j++)
		{
			_subMap._map[i][j] = _map[startI][startJ];	
		}
	}

	return _subMap;
}

Map::Position Map::getLeftUp()const
{
	return _leftUp;
}

Map::Position Map::getRightDown() const
{
	return _rightDown;
}

Cell* Map::operator[](int row)const
{
	return _map[row];
}

Map::~Map()
{
	for (int i = 0; i < _row; i++)
	{
		delete[] _map[i];
	}
	delete[] _map;
}