#include "Monster.h"
#include "Player.h"
#include <iostream>
#include "Random.h"
using namespace std;

Monster::Monster(const std::string& name, int hp, int acc, int xpReward, int armor, const std::string& weaponName, int lowDamage, int highDamage)
{
	mName = name;
	mHitPoints = hp;
	mAccuracy = acc;
	mArmor = armor;
	mExpReward = xpReward;
	mWeapon.mName = weaponName;
	mWeapon.mDamageRange.mLow = lowDamage;
	mWeapon.mDamageRange.mHigh = highDamage;
}

bool Monster::isDead()
{
	return mHitPoints <= 0;
}

int Monster::getXPReward()
{
	return mExpReward;
}

std::string Monster::getName()
{
	return mName;
}

int Monster::getArmor()
{
	return mArmor;
}

void Monster::attack(Player& player)
{

	cout << "A " << mName << " attacks you "
		<< "with a " << mWeapon.mName << endl;

	if (Random(0,20) < mAccuracy)
	{
		int damage = Random(mWeapon.mDamageRange);

		int totalDamage = damage - player.getArmor();

		if (totalDamage <=0)
		{
			cout << "The monster's attack failed to "
				<< "penetrate your armor." << endl;
		}
		else
		{
			cout << "You are hit for " << totalDamage << " damage!" << endl;

			player.takeDamage(totalDamage);

		}
	}
	else
	{
		cout << "The " << mName << " missed!" << endl;
	}
	cout << endl;

}

void Monster::takeDamage(int damage)
{
	mHitPoints -= damage;
}
void Monster::displayHitPoints()
{
	cout << mName << "'s hitpoints = " << mHitPoints << endl;
}