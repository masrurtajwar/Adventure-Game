#pragma once
#include <cstdlib>	// For several general-purpose functions
#include <fstream>	// For file handling
#include <iomanip>	// For formatted output
#include <iostream> // For cin, cout, and system
#include <string>	// For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

class Character // Abstract class
{
protected:
    int hp;
    int attackPower;

public: // All functions are pure virtual functions
    virtual void setHP(int) = 0;
    virtual int getHP() const = 0;
    virtual void setAttackPower(int) = 0;
    virtual int getAttackPower() const = 0;
};