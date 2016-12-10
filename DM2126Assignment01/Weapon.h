#ifndef ASSIGNMENT1_ROOT_WEAPON_H
#define ASSIGNMENT1_ROOT_WEAPON_H

#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(const std::string& objName, const int& duraValue, const int& wpnDamage);
	~Weapon();

	void receiveDamage(const int &damage);

	const int getAttackDmg();

protected:
	const int kAttackDmg;
};
#endif // !WEAPON_H