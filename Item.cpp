#include <cstdlib>	// For several general-purpose functions
#include <fstream>	// For file handling
#include <iomanip>	// For formatted output
#include <iostream> // For cin, cout, and system
#include <string>	// For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"
#include "Item.h"

bool Item::isHP() const
{
	if (type == 0)
		return true;
	else
		return false;
}

bool Item::isDefense() const
{
	if (type == 1)
		return true;
	else
		return false;
}

int Item::getValue() const
{
	return value;
}

Item::Item(int type, int value)
{
	this->type = type;
	this->value = value;
}