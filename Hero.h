#pragma once
#include <cstdlib>	// For several general-purpose functions
#include <fstream>	// For file handling
#include <iomanip>	// For formatted output
#include <iostream> // For cin, cout, and system
#include <string>	// For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"
#include "Item.h"
#include "Character.h"
#include "Monster.h"

class Hero : public Character
{
private:
    int defensePower;
    int retreatCount;

public:
    Item* bag[3];
    int getDefensePower() const;
    void setDefensePower(int);
    void decreaseDefensePower();
    int getRetreatCount() const;
    void setRetreatCount(int);
    void decreaseRetreatCount();
    bool anyItems()const;
    bool isAlive() const;
    int operator * (Monster& m);
    Hero(int hp, int attackPower, int defPow, int retreatCount);
    void setHP(int x);
    int getHP() const;
    void setAttackPower(int x);
    int getAttackPower() const;
    Hero();
};