#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(const std::string&, const int&, const int&);
	~Weapon();

	void receiveDamage(const int & damage);

	const int getAttackDmg();

protected:
	const int kAttackDmg;
};
#endif // !WEAPON_H