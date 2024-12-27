// sandbox2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <vector>
using namespace std;

// warriors
class War
{
public:
	string name;
	int health = 100;
	int str = 10;
	int spd = 10;
};

//battle
class Battle
{
	int w1dmg = 0;
	int w2dmg = 0;

	string hits[11] = {
		" punches the ", 
		" connects with the ", 
		" slams the ", 
		" strikes the ", 
		" bashes the ", 
		" kicks the ", 
		" uppercuts the ",
		" slashes the ",
		" chops the ",
		" stabs the ",
		" elbows the ",
	};

public:
	void fight(War& war1, War& war2)
	{
		while (war1.health > 0 && war2.health > 0)
		{
			int w1attack = rand() % 11;
			int w2attack = rand() % 11;

			int hits_in = rand() % 11;

			//war1 attack
			w1dmg = war1.str + w1attack - war2.spd;
			if (w1dmg < 0)
			{
				w1dmg = 0;
			}
			if (w1attack == 10)
			{
				w1dmg *= 2;
				w1dmg += 10;
				cout << endl;
				cout << war1.name << " lands a CRITICAL HIT!";
			}
			war2.health -= w1dmg;
			if (w1dmg > 0)
			{
				cout << endl;
				cout << war1.name << hits[hits_in] << war2.name << " for " << w1dmg << ".";
				cout << endl;
			}
			else
			{
				cout << endl;
				cout << war1.name << " misses " << endl;
			}
			if (war2.health < 1)
			{
				break;
			}

			//war2 attack
			w2dmg = war2.str + w2attack - war1.spd;
			if (w2dmg < 0)
			{
				w2dmg = 0;
			}
			if (w2attack == 10)
			{
				w2dmg *= 2;
				w2dmg += 10;
				cout << endl;
				cout << war2.name << " lands a CRITICAL HIT!";
			}
			war1.health -= w2dmg;
			if (w2dmg > 0)
			{
				cout << endl;
				cout << war2.name << hits[hits_in] << war1.name << " for " << w2dmg << ".";
				cout << endl;
			}
			else
			{
				cout << endl;
				cout << war2.name << " misses " << endl;
			}
		}
		if (war1.health > 0)
		{
			cout << endl;
			cout << war1.name << " is victorious!" << endl;
			cout << war1.name << " has " << war1.health << " health left." << endl;
			cout << endl;
		}
		else if (war2.health > 0)
		{
			cout << endl;
			cout << war2.name << " is victorious!" << endl;
			cout << war2.name << " has " << war2.health << " health left." << endl;
			cout << endl;
		}
	}
};



int main()
{
	srand(time(0));

	int xstr1;
	int xspd1;
	
	int xstr2;
	int xspd2;

	string rdy;
	string wpn;
	string choice;

	bool again = true;
	
	int round = 1;

	int reward = 0;

	int heal_count = 0;

	War war1;


	//warrior 1
	cout << "Enter the first character name: ";
	cin >> war1.name;
	cout << war1.name << "'s stats are: " << endl;
	cout << "Health: " << war1.health << endl;
	cout << "Strength: " << war1.str << endl;
	cout << "Speed: " << war1.spd << endl;
	cout << "You have 10 additional points to add to your Strength and Speed." << endl;
	cout << "How many points would you like to add to Strength? ";
	cin >> xstr1;
	war1.str += xstr1;
	war1.spd += 10 - xstr1;
	cout << xstr1 << " have been added to " << war1.name << "'s Strength." << endl;
	cout << "The remaining points have been add to " << war1.name << "'s Speed." << endl;
	cout << war1.name << "'s new stats are: " << endl;
	cout << "Health: " << war1.health << endl;
	cout << "Strength: " << war1.str << endl;
	cout << "Speed: " << war1.spd << endl;
	cout << endl;
	cout << "Choose a weapon." << endl;
	cout << "Your choices are: " << endl;
	cout << "Axe: Strength + 10" << endl;
	cout << "Sword: Speed + 10" << endl;
	cout <<	"Mace: Strength + 5, Speed + 5" << endl;
	cin >> wpn;
	if (wpn == "Axe" || wpn == "axe")
	{
		war1.str += 10;
	}
	else if (wpn == "Dagger" || wpn == "dagger")
	{
		war1.spd += 10;
	}
	else if (wpn == "Sword" || wpn == "sword")
	{
		war1.str += 5;
		war1.spd += 5;
	}
	//shhhhhh
	else if (wpn == "Katana")
	{
		war1.str += 10;
		war1.spd += 10;
	}
	else
	{
		wpn = "None";
	}
	cout << endl;
	cout << "Health: " << war1.health << endl;
	cout << "Strength: " << war1.str << endl;
	cout << "Speed: " << war1.spd << endl;
	cout << "Weapon: " << wpn << endl;


	//enemies         
	while (again == true && war1.health > 0)
	{
	War enemies[] = {
		{"Goblin", 80, 10, 15},
		{"Orc", 120, 20, 15},
		{"Dragon", 200, 25, 10},
		{"Zombie", 50, 25, 5},
		{"Imp", 70, 20, 18},
		{"Professor", 100, 5, 25},
		{"Slime", 200, 15, 15},
		{"Kobold", 50, 5, 30}
		};

	int enemy_index = rand() % 7; 
	War war2 = enemies[enemy_index];
	

	//battle
	if (round == 5)
	{
		war2 = { "Dark Elf", 100, 10, 35 };
	}
	if (round == 10)
	{
		war2 = {"Demon Lord", 70, 40, 40};
	}
	if (round == 15)
	{
		war2 = {"Fire Giant", 150, 60, 40};
	}

	if (round == 1)
	{
		cout << "Ready to battle?" << endl;
	}
	if (round > 1)
	{
		cout << "You've earned a reward!" << endl;
		cout << "You're choices are: " << endl;
		cout << "1: 5 additional stat points." << endl;
		cout << "2: Healing and +10 health." << endl;
		cout << "Choose 1 or 2." << endl;
		cin >> reward;
		if (reward == 1)
		{
			cout << "You chose 5 additional stat points." << endl;
			cout << "How many would you like to add to your strength?" << endl;
			cin >> xstr2;
			war1.str += xstr2;
			war1.spd += 5 - xstr2;
			cout << "You chose +" << xstr2 << " to Strength." << endl;
			cout << "The remaining " << 5 - xstr2 << " points have been added to your Speed." << endl;
			cout << "You're new stats are:" << endl;
			cout << "Health: " << war1.health << endl;
			cout << "Strength: " << war1.str << endl;
			cout << "Speed: " << war1.spd << endl;
		}
		else if (reward == 2)
		{
			heal_count++;
			cout << "You chose to be healed." << endl;
			war1.health = 100 + (10 * heal_count);
			cout << "Health: " << war1.health << endl;
		}
		//shhhhhh
		else if (reward == 772)
		{
			cout << "You must know my master." << endl;
			cout << "You may have both the additional stat points and healing." << endl;
			heal_count++;
			war1.health = 100 + (10 * heal_count);
			cout << "How many points of your 5 points would you like to add to your strength?" << endl;
			cin >> xstr2;
			war1.str += xstr2;
			war1.spd += 5 - xstr2;
			cout << "You chose +" << xstr2 << " to Strength." << endl;
			cout << "The remaining " << 5 - xstr2 << " have been added to your Speed." << endl;
			cout << "You're new stats are:" << endl;
			cout << "Health: " << war1.health << endl;
			cout << "Strength: " << war1.str << endl;
			cout << "Speed: " << war1.spd << endl;
		}
		else
		{
			cout << "That wasn't a choice. You get nothing." << endl;
		}
		
		cout << "Ready for round " << round << "?" << endl;
	}
		cin >> rdy;
		if (rdy == "Yes" || rdy == "yes" || rdy == "Y" || rdy == "y" || rdy == "Ready" || rdy == "ready")
		{
			again == true;
			Battle battle;
			battle.fight(war1, war2);
			round += 1;
		}
		else
		{
			again = false;
			cout << "You're a coward but you're alive.";
			cout << endl;
		}
	}
}
