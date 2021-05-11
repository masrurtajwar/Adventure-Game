#include <cstdlib>	// For several general-purpose functions
#include <fstream>	// For file handling
#include <iomanip>	// For formatted output
#include <iostream> // For cin, cout, and system
#include <string>	// For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"
#include "Character.h"

// Character class implementation
void Character::setHP(int HP)
{
	hp = HP;
}

int Character::getHP() const
{
	return hp;
}

void Character::setAttackPower(int attackPower)
{
	this->attackPower = attackPower;
}

int Character::getAttackPower() const
{
	return attackPower;
}