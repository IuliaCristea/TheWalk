#include "Cell.hpp"



Cell::Cell() :
	_hasItem(false),
	_hasTrap(false)
{
	_item = NULL;
	_trap = NULL;
}

Cell::Cell(const Cell &newCell)
{
	*this = newCell;
}


Cell& Cell::operator =(const Cell &newCell)
{
	
	_hasItem = newCell._hasItem;
	_hasTrap = newCell._hasTrap;
	
	
	
	if (_hasItem && newCell._item != NULL)
	{
		if (dynamic_cast<SmartItem*>(newCell._item)!= NULL)
		{
			_item = new SmartItem();
		}
		else
			if (dynamic_cast<StrongItem*>(newCell._item)!= NULL)
			{
				_item = new StrongItem();
			}
			else
			{
				_item = new ComplexItem();
			}

	}
	if (_hasTrap && newCell._trap != NULL)
	{
		if (dynamic_cast<SmartTrap*>(newCell._trap)!=NULL)
		{
			_trap = new SmartTrap();
		}
		else
			if (dynamic_cast<StrongTrap*>(newCell._trap)!=NULL)
			{
				_trap = new StrongTrap();
			}
			else
			{
				_trap = new ComplexTrap();
			}
	}
	
	
	return *this;
	
}

bool Cell::hasItem()
{
	if (_hasItem)
		return true;
	return false;
}


void Cell::setItemType(int itemNr)
{
	switch (itemNr)
	{
	case 0: _item = new SmartItem();
			break;
	case 1: _item = new StrongItem();
			break;
	case 2: _item = new ComplexItem();
			break;
	default:
		_item = NULL;
	}
}

Item* Cell::getItem()
{
	_hasItem = false;
	return _item;
}

void Cell::setHasItem(bool hasItem)
{
		_hasItem = hasItem;
}

void Cell::setItemDefault()
{
	_item = NULL;
}

bool Cell::hasTrap()
{
	if (_hasTrap)
		return true;
	return false;
}



void Cell::setTrapType(int trapNr)
{
	switch (trapNr)
	{
	case 0: _trap= new SmartTrap();
		break;
	case 1: _trap = new StrongTrap();
		break;
	case 2: _trap = new ComplexTrap();
		break;
	}
}

Trap* Cell::getTrap()
{
	_hasTrap = false;
	return _trap;
}

void Cell::setHasTrap(bool hasTrap)
{
	if (hasTrap)
	{
		_hasTrap = true;
	}
	else
	{
		_hasTrap = false;
	}
}

void Cell::setTrapDefault()
{
	_trap = NULL;
}

void Cell::setIsDestionation(bool dest)
{
	_isDestination = dest;
}

bool Cell::isDestination()
{
	return _isDestination;
}

Cell::~Cell()
{
}
