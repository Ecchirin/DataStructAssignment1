#include "Outfit.h"

Outfit::Outfit(const std::string& objName, const int& duraValue, const int& specialValue) : Item::Item(objName, duraValue), kSPECIAL(specialValue)
{
	
}

Outfit::~Outfit()
{
	std::cout << this->getName << " is deleted.\n";
}

const int Outfit::getSPECIAL()
{
	return kSPECIAL;
}