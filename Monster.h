#pragma once
#include <cstdlib>	// For several general-purpose functions
#include <fstream>	// For file handling
#include <iomanip>	// For formatted output
#include <iostream> // For cin, cout, and system
#include <string>	// For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"
#include "Character.h"

class Monster : public Character
{
public:
    void decreaseAttackPower();
    Monster(int hp, int attPow);
    void setHP(int x);
    int getHP() const;
    void setAttackPower(int x);
    int getAttackPower() const;
};