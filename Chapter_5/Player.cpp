#include "Player.h"
#include "Random.h"
#include <iostream>
using namespace std;

Player::Player()
{
	mName = "Default";
	mClassName = "Default";
	mAccuracy = 0;
	mHitPoints = 0;
	mMaxHitPoints = 0;
	mExpPoints = 0;
	mNextLevelExp = 0;
	mLevel = 0;
	mArmor = 0;
	mWeapon.mName = "Default Weapon Name";
	mWeapon.mDamageRange.mLow = 0;
	mWeapon.mDamageRange.mHigh = 0;
	mGold = 0;
}

bool Player::isDead()
{
	return mHitPoints <= 0;
}

int Player::getArmor()
{
	return mArmor;
}

void Player::takeDamage(int damage)
{
	mHitPoints -= damage;
}

void Player::createClass()
{
	std::cout << "CHARACTER CLASS GENERATION" << endl;
	std::cout << "==========================" << endl;

	std::cout << "Enter your character's name: ";
	getline(cin,mName);

	std::cout << "Please select a character class number..." << endl;
	std::cout << "1) Warrior 2) Mage 3) Priest 4) Rogue : ";
	int characterNum = 1;
	cin >> characterNum;

	std::cout << "Please select a race: " << endl;
	std::cout << "1) Dwarf 2) Human 3) Elf 4) Halfling" << endl;
	int characterRace = 1;
	cin >> characterRace;

	switch(characterNum)
	{
	case 1:
		// Warrior
		mClassType = 1;
		mClassName = "Warrior";
		mAccuracy = 10;
		mMaxHitPoints = 20;
		mExpPoints =0;
		mNextLevelExp = 1000;
		mMaxMagic = 0;
		mLevel = 1;
		mArmor = 4;
		mWeapon.mName = "Long Sword";
		mWeapon.mDamageRange.mLow = 1;
		mWeapon.mDamageRange.mHigh = 8;
		break;

	case 2:
		// Mage
		mClassType = 2;
		mClassName = "Mage";
		mAccuracy = 5;
		mMaxHitPoints = 10;
		mExpPoints = 0;
		mNextLevelExp = 1000;
		mMaxMagic = 25;
		mLevel = 1;
		mArmor = 1;
		mArmor = 1;
		mWeapon.mName = "Staff";
		mWeapon.mDamageRange.mLow = 1;
		mWeapon.mDamageRange.mHigh = 4;

		mSpell1.mName = "Fireball";
		mSpell1.mDamageRange.mLow = 1;
		mSpell1.mDamageRange.mHigh = 5;
		mSpell1.mMagicRequired = 1;

		mSpell2.mName = "Magic Mage";
		mSpell2.mDamageRange.mLow = 6;
		mSpell2.mDamageRange.mHigh = 10;
		mSpell2.mMagicRequired = 10;

		mSpell1.mName = "Drink";
		mSpell3.mDamageRange.mLow = 0;
		mSpell3.mDamageRange.mHigh = 0;
		mSpell3.mMagicRequired = 0;
		break;

	case 3:
		// Priest
		mClassType = 2;
		mClassName = "Priest";
		mAccuracy = 8;
		mMaxHitPoints = 15;
		mExpPoints = 0;
		mNextLevelExp = 1000;
		mMaxMagic = 25;
		mLevel = 1;
		mArmor = 3;
		mWeapon.mName = "Flail";
		mWeapon.mDamageRange.mLow = 1;
		mWeapon.mDamageRange.mHigh = 6;

		mSpell1.mName = "Smite";
		mSpell1.mDamageRange.mLow = 2;
		mSpell1.mDamageRange.mHigh = 7;
		mSpell1.mMagicRequired = 1;

		mSpell2.mName = "Holy Pain";
		mSpell2.mDamageRange.mLow = 8;
		mSpell2.mDamageRange.mHigh = 9;
		mSpell2.mMagicRequired = 15;

		mSpell3.mName = "Innervate";
		mSpell3.mDamageRange.mLow = 0;
		mSpell3.mDamageRange.mHigh = 0;
		mSpell3.mMagicRequired = 0;
		break;

	default:
		// Rogue
		mClassType = 1;
		mClassName = "Rogue";
		mAccuracy = 7;
		mMaxHitPoints = 12;
		mExpPoints = 0;
		mNextLevelExp = 1000;
		mMaxMagic = 0;
		mLevel = 1;
		mArmor = 2;
		mWeapon.mName = "Short Sword";
		mWeapon.mDamageRange.mLow = 1;
		mWeapon.mDamageRange.mHigh = 6;
		break;
	}

	switch (characterRace)
	{
	case 1:
		// Dwarf
		mRaceName = "Dwarf";
		mNextLevelExp *= 0.8;
		mWeapon.mDamageRange.mHigh = 4;
		break;
	case 2:
		// Human
		mRaceName = "Human";
		mMaxHitPoints *= 1.2;
		mNextLevelExp *= 1.2;
		break;
	case 3:
		// Elf
		mRaceName = "Elf";
		mWeapon.mDamageRange.mLow += 2;
		mWeapon.mDamageRange.mHigh += 2;
		mMaxHitPoints *= 0.8;
		break;
	case 4:
		// Halfling
		mRaceName = "Halfling";
		mArmor *= 1.5;
		mMaxHitPoints *= 0.9;
		break;
	}

	mMagic = mMaxMagic;
	mHitPoints = mMaxHitPoints;

}

bool Player::attack(Monster& monster)
{
	int selection = 1;
	std::cout << "1) Attack 2) Run : ";
	cin >> selection;
	std::cout << endl;

	int intSpell = 1;

	switch(selection)
	{
	case 1:


		if (mClassType == 2)
		{
			std::cout << "1) " << mSpell1.mName << " 2) " << mSpell2.mName << " 3) " << mSpell3.mName << " : ";
			std::cin >> intSpell;
		}
		if (Random(0,20) < mAccuracy)
		{
			int damage = 0;
			switch(mClassType)
			{
			case 1:
				std::cout << "You attack this " << monster.getName()
					<< " with a " << mWeapon.mName << endl;
				damage = Random(mWeapon.mDamageRange);
				break;
			case 2:
				switch(intSpell)
				{
				case 1:
					std::cout << "You attack this " << monster.getName()
						<< " with a " << mSpell1.mName << endl;
					if (mMagic < mSpell1.mMagicRequired)
					{
						std::cout << "But you don't have enough magic.";
					}
					else
					{
						mMagic -= mSpell1.mMagicRequired;
						damage = Random(mSpell1.mDamageRange);
					}
					break;
				case 2:
					std::cout << "You attack this " << monster.getName()
						<< " with a " << mSpell2.mName << endl;
					if (mMagic < mSpell2.mMagicRequired)
					{
						std::cout << "But you don't have enough magic.";
					}
					else
					{
						mMagic -= mSpell2.mMagicRequired;
						damage = Random(mSpell2.mDamageRange);
					}
					break;
				case 3:
					std::cout << "You used " << mSpell3.mName << " to replenish your magic.";
					mMagic = mMaxMagic;
					break;
				}
			}

			int totalDamage = damage - monster.getArmor();

			if (totalDamage <= 0)
			{
				std::cout << "Your attack failed to penetrate "
					<< "the armor." << endl;
			}
			else
			{
				std::cout << "You attack for " << totalDamage 
					<< " damage!" << endl;

				monster.takeDamage(totalDamage);
			}
		}
		else
		{
			std::cout << "You miss!" << endl;
		}

		std::cout << endl;
		break;

	case 2:
		int roll = Random(1,4);

		if (roll > 2)
		{
			std::cout << "You run away safely!" << endl;
			return true;
		}
		else
		{
			std::cout << "Monster blocked your path!" << endl;
			break;
		}
	}
	return false;
}

void Player::levelUp()
{
	if (mExpPoints >= mNextLevelExp)
	{
		cout << "Ding! You gained a level!" << endl;

		mLevel++;

		mNextLevelExp = mLevel * mLevel * 1000;

		if (mRaceName == "Rogue")
		{
			mAccuracy += Random(2,4);
		}
		else
		{
			mAccuracy += Random(1,2);
		}

		mMaxHitPoints += Random(2,6);

		if (mRaceName == "Warrior")
		{
			mArmor += Random(2,4);
		}
		else
		{
			mArmor += Random(1,2);
		}
		if (mRaceName == "Priest" || mRaceName == "Mage")
			mMaxMagic += Random(5,10);

		mHitPoints = mMaxHitPoints;
		mMagic = mMaxMagic;

	}


}

void Player::rest()
{
	int roll = Random(1,4);

	if (roll == 4)
	{
		cout << "Unable to rest: creepy sounds are nearby"; 
	}
	else
	{
	cout << "You're resting..." << endl;

	mHitPoints = mMaxHitPoints;
	}

}

void Player::viewStats()
{
	cout << "PLAYER STATS" << endl;
	cout << "============" << endl;
	cout << endl;

	cout << "Name            = " << mName << endl;
	cout << "Class           = " << mClassName << endl;
	cout << "Race            = " << mRaceName << endl;
	cout << "Accuracy        = " << mAccuracy << endl;
	cout << "Hitpoints       = " << mHitPoints << endl;
	cout << "MaxHitPoints    = " << mMaxHitPoints << endl;
	cout << "XP              = " << mExpPoints << endl;
	cout << "XP for next lvl = " << mNextLevelExp << endl;
	cout << "Level           = " << mLevel << endl;
	cout << "Armor           = " << mArmor << endl;
	cout << "Weapon Name     = " << mWeapon.mName << endl;
	cout << "Weapon Damage   = " << mWeapon.mDamageRange.mLow << "-" << mWeapon.mDamageRange.mHigh << endl;
	cout << "Gold acquired   = " << mGold << endl;
	if (displayClassTypeNumber() == 2){
		cout << "Magic           = " << mMagic << endl;
		cout << "Maximum Magic   = " << mMaxMagic << endl;
	}
	cout << endl;
	cout << "END PLAYER STATS" << endl;
	cout << "================" << endl;
	cout << endl;
}

void Player::victory(int xp)
{
	int intGold = xp / 10;
	cout << "You won the battle!" << endl;
	cout << "You win " << xp 
		<< " experience points!" << endl;
	cout << "You win " << intGold << " gold." << endl << endl;


	mExpPoints += xp;
	mGold += intGold;
}

void Player::gameover()
{
	cout << "You died in battle..." << endl;
	cout << endl;
	cout << "==========================" << endl;
	cout << " GAME OVER " << endl;
	cout << "===========================" << endl;
	viewStats();
	cout << "Press 'q' to quit: ";
	char q = 'q';
	cin >> q;
	cout << endl;
}

void Player::displayHitPoints()
{
	cout << mName << "'s hitpoints = " << mHitPoints << " / " << mMaxHitPoints << endl;
}

void Player::displayMagicPoints()
{
	cout << mName << "'s magic = " << mMagic << " / " << mMaxMagic << endl;
}

std::string Player::displayClassType()
{
	switch (mClassType)
	{
	case 2:
		return "Ranged";
	default:
		return "Melee";
	}
}
int Player::displayClassTypeNumber()
{
	return mClassType;
}