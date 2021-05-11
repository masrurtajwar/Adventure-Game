#include <cstdlib>	// For several general-purpose functions
#include <fstream>	// For file handling
#include <iomanip>	// For formatted output
#include <iostream> // For cin, cout, and system
#include <string>	// For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"
#include "Hero.h"
#include "Monster.h"

int Hero::getDefensePower() const 
{
	return defensePower; 
}

void Hero::decreaseDefensePower() 
{ 
	if (defensePower > 1)
		defensePower = defensePower--; 
} 

void Hero::setDefensePower(int defPow) 
{ 
	if (defPow > 1)
		defensePower = defPow;
	else
		defensePower = 1;
}

int Hero::getRetreatCount() const 
{ 
	return retreatCount; 
}

void Hero::setRetreatCount(int rtrC)
{
	retreatCount = rtrC;
}

void Hero::decreaseRetreatCount() 
{ 
	if (retreatCount > 0)
		retreatCount = retreatCount--; 
}

bool Hero::anyItems() const 
{ 
	if (bag[0] == nullptr && bag[1] == nullptr && bag[2] == nullptr)
		return false; 
	else
		return true; 
}

bool Hero::isAlive() const 
{ 
	if (hp > 0)
		return true; 
	else
		return false; 
}

int Hero::operator * (Monster& m) 
{
	//sets monster HP
	m.setHP(m.getHP() - this->getAttackPower() < 0 ? 0 : m.getHP() - this->getAttackPower());
	
	//sets hero HP
	this->setHP(this->getHP() - m.getAttackPower()/this->getDefensePower());

	//decreases
	m.decreaseAttackPower();
	this->decreaseDefensePower();

	if (this->getHP() <= 0) //hero died
		return -1;
	else if (m.getHP() <= 0) //monster died
		return 1;
	else //no one died
		return 0;
}

Hero::Hero(int hp, int attackPower, int defPow, int retreatCount) 
{
	//Initialize the member variables
	if (hp > 1)
		this->hp = hp;
	else
		this->hp = 1;
	if (attackPower > 1)
		this->attackPower = attackPower;
	else
		this->attackPower = 1;
	if (defPow >= 1)
		defensePower = defPow;
	else
		defensePower = 1;
	if (retreatCount >= 0)
		this->retreatCount = retreatCount;
	else
		this->retreatCount = 0;

	//Initialize the bag with 3 null pointers
	this->bag[0] = nullptr;
	this->bag[1] = nullptr;
	this->bag[2] = nullptr;
}

void Hero::setHP(int x)
{
	hp = x;
}

int Hero::getHP() const
{
	return hp;
}

void Hero::setAttackPower(int x)
{
	attackPower = x;
}

int Hero::getAttackPower() const
{
	return attackPower;
}

Hero::Hero()
{

}