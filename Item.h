#pragma once
#include <cstdlib>	// For several general-purpose functions
#include <fstream>	// For file handling
#include <iomanip>	// For formatted output
#include <iostream> // For cin, cout, and system
#include <string>	// For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

class Item
{
private:
    int type; // 0 - hp, 1 - defense
    int value;

public:
    bool isHP() const;
    bool isDefense() const;
    int getValue() const;
    Item(int type, int value);
};