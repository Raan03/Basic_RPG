#ifndef PLAYER_H
#define PLAYER_H

#include "Weapon.h"
#include "Monster.h"
#include "Spell.h"
#include <string>

class Player
{
public:
	Player();

	bool isDead();

	std::string _Gettnames();
	int getArmor();
	void takeDamage(int damage);

	void createClass();
	bool attack(Monster& monster);
	void levelUp();
	void rest();
	void viewStats();
	void victory(int xp);
	void gameover();
	void displayHitPoints();
	void displayMagicPoints();
	std::string displayClassType();
	int displayClassTypeNumber();
	
private:
	std::string mRaceName;
	std::string mName;
	std::string mClassName;
	int mClassType;
	int mAccuracy;
	int mHitPoints;
	int mMaxHitPoints;
	int mExpPoints;
	int mNextLevelExp;
	int mLevel;
	int mArmor;
	Weapon mWeapon;
	Spell mSpell1;
	Spell mSpell2;
	Spell mSpell3;
	int mGold;
	int mMaxMagic;
	int mMagic;
};

#endif // PLAYER_H