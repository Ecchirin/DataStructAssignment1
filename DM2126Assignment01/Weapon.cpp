#include "Weapon.h"

Weapon::Weapon(const std::string& objName, const int& duraValue, const int& wpnDamage) : Item::Item(objName, duraValue), kAttackDmg(wpnDamage)
{

}

Weapon::~Weapon()
{
	std::cout << this->getName << " is deleted.\n";
}

const int Weapon::getAttackDmg()
{
	return kAttackDmg;
}