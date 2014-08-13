#include "Map.h"
#include "Random.h"
#include <iostream>
using namespace std;

int Map::getPlayerXPos()
{
	return mPlayerXPos;
}
int Map::getPlayerYPos()
{
	return mPlayerYPos;
}

void Map::movePlayer()
{
	int selection = 1;
	cout << "1) North 2) East 3) South 4) West: ";
	cin >> selection;

	switch(selection)
	{
	case 1:
		// North
		mPlayerXPos++;
		break;

	case 2:
		// East
		mPlayerYPos++;
		break;
	case 3:
		// South
		mPlayerXPos--;
		break;
	default:
		// West
		mPlayerYPos--;
		break;
	}
	cout << endl;
}

Monster* Map::checkRandomEncounter()
{
	int roll = Random(0,20);

	Monster* monster = 0;

	if (roll <= 5)
	{
		return 0;
	}
	else
	{
		if (roll >= 6 && roll <= 10)
		{
			monster = new Monster("Orc",10,8,200,1,"Short Sword",2,7);
		}
		if (roll >= 11 && roll <= 15)
		{
			monster = new Monster("Goblin",6,6,100,0,"Dagger",1,5);
		}
		if (roll >= 16 && roll <= 19)
		{
			monster = new Monster("Ogre",20,12,500,2,"Club",3,8);
		}
		if (roll == 20)
		{
			monster = new Monster("Orc Overlord",25,15,2000,5,"Two Handed Sword",5,20);
		}
		cout << "You encounter this " << monster->getName() << endl;
		cout << "Prepare for battle." << endl;
		cout << endl;
	}
	return monster;
}

void Map::printPlayerPos()
{
	cout << "Player Position = (" << mPlayerXPos << ", " << mPlayerYPos << ")" << endl << endl;
}
Map::Map()
{
	mPlayerXPos = 0;
	mPlayerYPos = 0;
}