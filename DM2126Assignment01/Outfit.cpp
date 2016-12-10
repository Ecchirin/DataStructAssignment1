#include "Outfit.h"

Outfit::Outfit(const std::string& objName, const int& duraValue, const int& specialValue) : Item::Item(objName, duraValue), kSPECIAL(specialValue)
{
	
}

Outfit::~Outfit()
{
	std::cout << this->getName() << " is deleted.\n";
}

void Outfit::receiveDamage(const int &damage)
{
	if ((Item::durability_ - damage) <= 0)
	{
		Item::durability_ = 0;
	}
	else
	{
		Item::durability_ -= damage;
	}
}
const int Outfit::getSPECIAL()
{
	return kSPECIAL;
}