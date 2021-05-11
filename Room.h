#pragma once
#include <cstdlib>	// For several general-purpose functions
#include <fstream>	// For file handling
#include <iomanip>	// For formatted output
#include <iostream> // For cin, cout, and system
#include <string>	// For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"
#include "Monster.h"
#include "Item.h"

class Room
{
private:
    string name;
    Room* east;
    Room* west;
    Room* north;
    Room* south;
    Monster* roomMonster;
    Item* roomItem;
    bool exit;
    bool start;

public:
    void setName(string n);
    string getName() const;
    void setEastRoom(Room* e);
    void setWestRoom(Room* w);
    void setNorthRoom(Room* n);
    void setSouthRoom(Room* s);
    Room* getEastRoom() const;
    Room* getWestRoom() const;
    Room* getNorthRoom() const;
    Room* getSouthRoom() const;
    void setRoomMonster(Monster* m);
    Monster* getRoomMonster() const;
    void setRoomItem(Item* i);
    Item* getRoomItem() const;
    bool isExit();
    bool isStart();
    Room(string y, Room* n, Room* s, Room* e, Room* w, Item* i, Monster* m); //monster + item
    Room(string y, Room* n, Room* s, Room* e, Room* w, Item* i); //item
    Room(string y, Room* n, Room* s, Room* e, Room* w, Monster* m); //monster
    Room(string y, Room* n, Room* s, Room* e, Room* w, bool x); // no monster/item
    Room(string y, Room* n, Room* s, Room* e, Room* w, bool x, bool z); //start room
};
