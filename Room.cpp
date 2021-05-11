#include <cstdlib>	// For several general-purpose functions
#include <fstream>	// For file handling
#include <iomanip>	// For formatted output
#include <iostream> // For cin, cout, and system
#include <string>	// For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"
#include "Room.h"

void Room::setName(string n)
{
	name = n;
}

string Room::getName() const
{
	return name;
}

void Room::setEastRoom(Room* e)
{
	east = e;
}

void Room::setWestRoom(Room* w)
{
	west = w;
}

void Room::setNorthRoom(Room* n)
{
	north = n;
}

void Room::setSouthRoom(Room* s)
{
	south = s;
}

Room* Room::getEastRoom() const
{
	return east;
}

Room* Room::getWestRoom() const
{
	return west;
}

Room* Room::getNorthRoom() const
{
	return north;
}

Room* Room::getSouthRoom() const
{
	return south;
}

void Room::setRoomMonster(Monster* m)
{
	roomMonster = m;
}

Monster* Room::getRoomMonster() const
{
	return roomMonster;
}

void Room::setRoomItem(Item* i)
{
	roomItem = i;
}

Item* Room::getRoomItem() const
{
	return roomItem;
}

bool Room::isExit()
{
	return exit;
}

bool Room::isStart()
{
	return start;
}

Room::Room(string y, Room* n, Room* s, Room* e, Room* w, Item* i, Monster* m)
{
	name = y;
	exit = false;
	start = false;
	north = n;
	south = s;
	east = e;
	west = w;
	roomItem = i;
	roomMonster = m;
}

Room::Room(string y, Room* n, Room* s, Room* e, Room* w, Item* i)
{
	name = y;
	exit = false;
	start = false;
	north = n;
	south = s;
	east = e;
	west = w;
	roomItem = i;
	roomMonster = nullptr;
}

Room::Room(string y, Room* n, Room* s, Room* e, Room* w, Monster* m)
{
	name = y;
	exit = false;
	start = false;
	north = n;
	south = s;
	east = e;
	west = w;
	roomItem = nullptr;
	roomMonster = m;
}

Room::Room(string y, Room* n, Room* s, Room* e, Room* w, bool x, bool z)
{
	name = y;
	exit = x;
	start = z;
	north = n;
	south = s;
	east = e;
	west = w;
	roomItem = nullptr;
	roomMonster = nullptr;
	
}

Room::Room(string y, Room* n, Room* s, Room* e, Room* w, bool x)
{
	name = y;
	exit = x;
	north = n;
	south = s;
	east = e;
	west = w;
	roomItem = nullptr;
	roomMonster = nullptr;

}