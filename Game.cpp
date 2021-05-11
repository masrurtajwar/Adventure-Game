#include <cstdlib>	// For several general-purpose functions
#include <fstream>	// For file handling
#include <iomanip>	// For formatted output
#include <iostream> // For cin, cout, and system
#include <string>	// For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

#include "Game.h"
#include "Room.h"

void Game::createMap()
{
	//Creating monsters
	Monster* m1 = new Monster(6, 2);
	Monster* m2 = new Monster(10, 6);
	Monster* m3 = new Monster(7, 9);
	Monster* m4 = new Monster(11, 12);

	//Creating items
	Item* i1 = new Item(1, 2);
	Item* i2 = new Item(0, 4);
	Item* i3 = new Item(1, 6);
	Item* i4 = new Item(0, 7);
	Item* i5 = new Item(1, 9);

	//Creating map w connected rooms
	//          7
	//          |
	//          6
	//          |
	//  1 - 2 - 5 - 8
	//      |       |
	//      3       9 (exit)
	//      |
	//      4

	Room* r1 = new Room("Room 1", nullptr, nullptr, nullptr, nullptr, false, true); //start room
	Room* r2 = new Room("Room 2", nullptr, nullptr, nullptr, nullptr, i1);
	Room* r3 = new Room("Room 3", nullptr, nullptr, nullptr, nullptr, false);
	Room* r4 = new Room("Room 4", nullptr, nullptr, nullptr, nullptr, i2, m1);
	Room* r5 = new Room("Room 5", nullptr, nullptr, nullptr, nullptr, i3, m2);
	Room* r6 = new Room("Room 6", nullptr, nullptr, nullptr, nullptr, i4);
	Room* r7 = new Room("Room 7", nullptr, nullptr, nullptr, nullptr, i5, m3);
	Room* r8 = new Room("Room 8", nullptr, nullptr, nullptr, nullptr, m4);
	Room* r9 = new Room("Room 9", nullptr, nullptr, nullptr, nullptr, true); //exit room

	r1->setEastRoom(r2);
	r2->setWestRoom(r1);
	r2->setSouthRoom(r3);
	r3->setNorthRoom(r2);
	r3->setSouthRoom(r4);
	r4->setNorthRoom(r3);
	r2->setEastRoom(r5);
	r5->setWestRoom(r2);
	r5->setNorthRoom(r6);
	r6->setSouthRoom(r5);
	r6->setNorthRoom(r7);
	r7->setSouthRoom(r6);
	r5->setEastRoom(r8);
	r8->setWestRoom(r5);
	r8->setSouthRoom(r9);
	r9->setNorthRoom(r8);

	this->currentRoom = r1;
}

void Game::run()
{
	Item* i1Copy, *i2Copy, *i3Copy;
	cout << "Hero Information\n=================\n";
	cout << "HP: " << HeroName.getHP() << endl;
	cout << "Attack Power: " << HeroName.getAttackPower() << endl;
	cout << "Defense Power: " << HeroName.getDefensePower() << endl;
	cout << "Retreat Count: " << HeroName.getRetreatCount() << endl;

	Room* previousRoom = nullptr;
	while (HeroName.isAlive() && !this->currentRoom->isExit())
	{
		//display current position
		cout << "\nCurrent room: " << this->currentRoom->getName() << endl;

		//if hero wants to retreat - still needs work
		if (HeroName.getRetreatCount() > 0 && !(this->currentRoom->isStart()))
		{
			string c1;
			cout << "Do you want to retreat? Y/N: ";
			cin >> c1;
			if (c1 == "Y")
			{
				this->currentRoom = previousRoom;
				HeroName.setRetreatCount(HeroName.getRetreatCount() - 1);
			}
			cout << "Hero retreat count: " << this->HeroName.getRetreatCount() << endl;
			cout << "\nCurrent room: " << this->currentRoom->getName() << endl;
		}

		//if hero has items and wants to use it
		if (HeroName.anyItems())
		{
			string c2;
			cout << "You have items in bag. Want to use one? Y/N: ";
			cin >> c2;
			if (c2 == "Y")
			{
				cout << "\nHero HP: " << HeroName.getHP() << endl;
				cout << "Hero defense power: " << HeroName.getDefensePower();
				cout << "\nBag Contents\n============\n";
				if (HeroName.bag[0] != nullptr)
				{
					cout << "Pocket 1 = ";
					if (HeroName.bag[0]->isHP())
						cout << "Type: HP, Value: " << HeroName.bag[0]->getValue() << endl;
					else
						cout << "Type: Defense, Value: " << HeroName.bag[0]->getValue() << endl;
				}
				else cout << "Pocket 1 Empty\n";

				if (HeroName.bag[1] != nullptr)
				{
					cout << "Pocket 2 = ";
					if (HeroName.bag[1]->isHP())
						cout << "Type: HP, Value: " << HeroName.bag[1]->getValue() << endl;
					else
						cout << "Type: Defense, Value: " << HeroName.bag[1]->getValue() << endl;
				}
				else cout << "Pocket 2 Empty\n";

				if (HeroName.bag[2] != nullptr)
				{
					cout << "Pocket 3 = ";
					if (HeroName.bag[2]->isHP())
						cout << "Type: HP, Value: " << HeroName.bag[2]->getValue() << endl;
					else
						cout << "Type: Defense, Value: " << HeroName.bag[2]->getValue() << endl;
				}
				else cout << "Pocket 3 Empty\n";

				int c3;
				cout << "Which one? 1/2/3: ";
				cin >> c3;
				PlaySound(TEXT("item_used.wav"), NULL, SND_SYNC);
				switch (c3)
				{
				case 1:
					if (HeroName.bag[0]->isHP())
					{
						HeroName.setHP(HeroName.getHP() + HeroName.bag[0]->getValue());
						cout << "\nItem used! Hero HP: " << HeroName.getHP() << endl;
						HeroName.bag[0] = nullptr;
						break;
					}
					else
					{
						HeroName.setDefensePower(HeroName.getDefensePower() + HeroName.bag[0]->getValue());
						cout << "\nItem used! Hero defense power: " << HeroName.getDefensePower() << endl;
						HeroName.bag[0] = nullptr;
						break;
					}
				case 2:
					if (HeroName.bag[1]->isHP())
					{
						HeroName.setHP(HeroName.getHP() + HeroName.bag[1]->getValue());
						cout << "\nItem used! Hero HP: " << HeroName.getHP() << endl;
						HeroName.bag[1] = nullptr;
						break;
					}
					else
					{
						HeroName.setDefensePower(HeroName.getDefensePower() + HeroName.bag[1]->getValue());
						cout << "\nItem used! Hero defense power: " << HeroName.getDefensePower() << endl;
						HeroName.bag[1] = nullptr;
						break;
					}
				case 3:
					if (HeroName.bag[2]->isHP())
					{
						HeroName.setHP(HeroName.getHP() + HeroName.bag[2]->getValue());
						cout << "\nItem used! Hero HP: " << HeroName.getHP() << endl;
						HeroName.bag[2] = nullptr;
						break;
					}
					else
					{
						HeroName.setDefensePower(HeroName.getDefensePower() + HeroName.bag[2]->getValue());
						cout << "\nItem used! Hero defense power: " << HeroName.getDefensePower() << endl;
						HeroName.bag[2] = nullptr;
						break;
					}
				}
				
			}
		}

		//displays if monster is in the room
		if (this->currentRoom->getRoomMonster() != nullptr)
		{
			cout << "\nMonster is found! Fight!\n========================\n";
			//Fight sequence
			int attackResult = 0;
			while (attackResult == 0)
			{
				cout << "Monster HP: " << this->currentRoom->getRoomMonster()->getHP() << endl;
				cout << "Hero HP: " << HeroName.getHP() << endl;
				cout << "Hero defense power: " << HeroName.getDefensePower() << endl << endl;
				attackResult = HeroName * *(this->currentRoom->getRoomMonster());
			}
			if (attackResult == -1)
			{
				HeroName.setHP(0);
				HeroName.isAlive();
				cout << "Monster HP: " << this->currentRoom->getRoomMonster()->getHP() << endl;
				cout << "Hero HP: " << HeroName.getHP() << endl;
				cout << "Hero defense power: " << HeroName.getDefensePower() << endl << endl;
				cout << "Hero has died. Game Over." << endl;
				exit(0);
			}
			else if (attackResult == 1)
			{
				cout << "Monster HP: " << this->currentRoom->getRoomMonster()->getHP() << endl;
				cout << "Hero HP: " << HeroName.getHP() << endl;
				cout << "Hero defense power: " << HeroName.getDefensePower() << endl << endl;
				cout << "Monster is dead. Good job!" << endl << endl;
				this->currentRoom->setRoomMonster(nullptr);
			}
			PlaySound(TEXT("beast_roar.wav"), NULL, SND_SYNC);
		}

		//displays if an item is in the room and initiate move process
		if (HeroName.isAlive())
		{
			if (this->currentRoom->getRoomItem() != nullptr)
			{
				PlaySound(TEXT("item_found.wav"), NULL, SND_SYNC);
				cout << "\nItem is found.\n";
				if (this->currentRoom->getRoomItem()->isHP())
					cout << "Type: HP, Value: " << this->currentRoom->getRoomItem()->getValue();
				else
					cout << "Type: Defense, Value: " << this->currentRoom->getRoomItem()->getValue();

				cout << "\nDo you want to pick up? Y/N: ";
				string c4;
				cin >> c4;
				if (c4 == "Y")
				{
					cout << "\nBag Contents\n============\n";
					if (HeroName.bag[0] != nullptr)
					{
						cout << "Pocket 1 = ";
						if (HeroName.bag[0]->isHP())
							cout << "Type: HP, Value: " << HeroName.bag[0]->getValue() << endl;
						else
							cout << "Type: Defense, Value: " << HeroName.bag[0]->getValue() << endl;
					}
					else cout << "Pocket 1 Empty\n";

					if (HeroName.bag[1] != nullptr)
					{
						cout << "Pocket 2 = ";
						if (HeroName.bag[1]->isHP())
							cout << "Type: HP, Value: " << HeroName.bag[1]->getValue() << endl;
						else
							cout << "Type: Defense, Value: " << HeroName.bag[1]->getValue() << endl;
					}
					else cout << "Pocket 2 Empty\n";

					if (HeroName.bag[2] != nullptr)
					{
						cout << "Pocket 3 = ";
						if (HeroName.bag[2]->isHP())
							cout << "Type: HP, Value: " << HeroName.bag[2]->getValue() << endl;
						else
							cout << "Type: Defense, Value: " << HeroName.bag[2]->getValue() << endl;
					}
					else cout << "Pocket 3 Empty\n";

					cout << "Which pocket to use? 1/2/3: ";
					int c5;
					cin >> c5;
					switch (c5)
					{
					case 1:
						if (HeroName.bag[0] == nullptr)
						{
							i1Copy = this->currentRoom->getRoomItem();
							HeroName.bag[0] = i1Copy;
							this->currentRoom->setRoomItem(nullptr);
							break;
						}
						else
						{
							HeroName.bag[0] = nullptr;
							i1Copy = this->currentRoom->getRoomItem();
							HeroName.bag[0] = i1Copy;
							this->currentRoom->setRoomItem(nullptr);
							break;
						}
					case 2:
						if (HeroName.bag[1] == nullptr)
						{
							i2Copy = this->currentRoom->getRoomItem();
							HeroName.bag[1] = i2Copy;
							this->currentRoom->setRoomItem(nullptr);
							break;
						}
						else
						{
							HeroName.bag[1] = nullptr;
							i2Copy = this->currentRoom->getRoomItem();
							HeroName.bag[1] = i2Copy;
							this->currentRoom->setRoomItem(nullptr);
							break;
						}
					case 3:
						if (HeroName.bag[2] == nullptr)
						{
							i3Copy = this->currentRoom->getRoomItem();
							HeroName.bag[2] = i3Copy;
							this->currentRoom->setRoomItem(nullptr);
							break;
						}
						else
						{
							HeroName.bag[2] = nullptr;
							i3Copy = this->currentRoom->getRoomItem();
							HeroName.bag[2] = i3Copy;
							this->currentRoom->setRoomItem(nullptr);
							break;
						}
					}
					PlaySound(TEXT("bag_zipping.wav"), NULL, SND_SYNC);
					cout << "\nItem bagged!\n";
				}
			}
		}

		//ask user where to go
		cout << endl;
		if (this->currentRoom->getNorthRoom() != nullptr)
			cout << "N) " << this->currentRoom->getNorthRoom()->getName() << endl;
		if (this->currentRoom->getSouthRoom() != nullptr)
			cout << "S) " << this->currentRoom->getSouthRoom()->getName() << endl;
		if (this->currentRoom->getEastRoom() != nullptr)
			cout << "E) " << this->currentRoom->getEastRoom()->getName() << endl;
		if (this->currentRoom->getWestRoom() != nullptr)
			cout << "W) " << this->currentRoom->getWestRoom()->getName() << endl;

		cout << "Where to next? ";
		char choice;
		cin >> choice;
		switch (choice)
		{
		case 'N': previousRoom = this->currentRoom;
			this->currentRoom = this->currentRoom->getNorthRoom();
			break;
		case 'S': previousRoom = this->currentRoom;
			this->currentRoom = this->currentRoom->getSouthRoom();
			break;
		case 'E': previousRoom = this->currentRoom;
			this->currentRoom = this->currentRoom->getEastRoom();
			break;
		case 'W': previousRoom = this->currentRoom;
			this->currentRoom = this->currentRoom->getWestRoom();
			break;
		}

		//exit dialogue
		if (this->currentRoom->isExit())
			cout << "\nCongratulations! You made it to the end.\n";

	}
}

Game::Game()
{
	//initialize Hero characteristics
	HeroName.setHP(5);
	HeroName.setAttackPower(5);
	HeroName.setDefensePower(5);
	HeroName.setRetreatCount(5);

	//create map
	createMap();
}
