//==========================================================
//
// Title:     Final Project
// Course:    CSC2110
// Author:    Group 2
// Date:       
//
//==========================================================
#include <cstdlib>	// For several general-purpose functions
#include <fstream>	// For file handling
#include <iomanip>	// For formatted output
#include <iostream> // For cin, cout, and system
#include <string>	// For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

#include "Hero.h"
#include "Monster.h"
#include "Item.h"
#include "Room.h"
#include "Game.h"

int main()
{
	cout << "Welcome to Star Wing!" << endl;
	Game StarWing;
	StarWing.run();

	return 0;
}

// Instructions on how to play sounds
// 1. Under Solution Explorer tab, right click on project file
// 2. Select Properties
// 3. Select Configuration Properties
// 4. Select Linker
// 5. Select Input, then under Additional Dependencies, click the drop-down tab to <Edit...>
// 6. In the new window's text box, type in "Winmm.lib" (without the quotations), then press ok

// That should enable the user to hear the sound files, if not...
// 1. Do steps 1-3
// 2. Select System
// 3. Make sure SubSystem is selected to Console (/SUBSYSTEM:CONSOLE)