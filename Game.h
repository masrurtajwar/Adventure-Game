#pragma once
#include <cstdlib>	// For several general-purpose functions
#include <fstream>	// For file handling
#include <iomanip>	// For formatted output
#include <iostream> // For cin, cout, and system
#include <string>	// For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"
#include "Room.h"
#include "Hero.h"

class Game
{
private:
	Room* currentRoom;
	Hero HeroName;

public:
	void createMap();
	void run();
	Game();
};