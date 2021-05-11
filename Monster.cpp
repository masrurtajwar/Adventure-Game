#include <cstdlib>	// For several general-purpose functions
#include <fstream>	// For file handling
#include <iomanip>	// For formatted output
#include <iostream> // For cin, cout, and system
#include <string>	// For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"
#include "Monster.h"

void Monster::setHP(int x)
{
	hp = x;
}

int Monster::getHP() const
{
	return hp;
}

void Monster::setAttackPower(int x)
{
	attackPower = x;
}

int Monster::getAttackPower() const
{
	return attackPower;
}

void Monster::decreaseAttackPower() 
{ 
	if (attackPower > 1)
		attackPower = attackPower--; 
}

Monster::Monster(int hp, int attPow) 
{
	if (hp > 1)
		this->hp = hp;
	else
		this->hp = 1;
	if (attPow > 1)
		attackPower = attPow;
	else
		attackPower = 1;
}

