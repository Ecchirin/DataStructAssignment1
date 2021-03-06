#include "Weapon.h"

Weapon::Weapon(const std::string& objName, const int& duraValue, const int& wpnDamage) : Item(objName, duraValue), kAttackDmg(wpnDamage)
{

}

Weapon::~Weapon()
{
	
}

void Weapon::receiveDamage(const int &damage)
{
	if ((Item::durability_ - (damage / 2)) <= 0)
	{
		Item::durability_ = 0;
	}
	else
	{
		Item::durability_ -= (damage / 2);
	}
}

const int Weapon::getAttackDmg()
{
	return kAttackDmg;
}