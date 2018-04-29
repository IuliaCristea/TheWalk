#pragma once

#include "SmartItem.hpp"
#include "ComplexItem.hpp"
#include "StrongItem.hpp"
#include "SmartTrap.hpp"
#include "StrongTrap.hpp"
#include "ComplexTrap.hpp"

class Cell
{
protected:
	bool _hasItem;
	Item* _item;
	bool _hasTrap;
	Trap* _trap;
	bool _isDestination;

public:
	Cell();
	Cell(const Cell &newCell);
	Cell& operator =(const Cell &newCell);
	bool hasItem();
	void setHasItem(bool hasItem);
	Item* getItem();
	void setItemType(int itemNr);
	void setItemDefault();
	bool hasTrap();
	void setHasTrap(bool hasTrap);
	Trap* getTrap();
	void setTrapType(int trapNr);
	void setTrapDefault();
	void setIsDestionation(bool dest);
	bool isDestination();
	~Cell();
};

