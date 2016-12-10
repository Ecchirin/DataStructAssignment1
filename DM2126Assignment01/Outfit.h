#ifndef ASSIGNMENT1_ROOT_OUTFIT_H
#define ASSIGNMENT1_ROOT_OUTFIT_H

#include "Item.h"

class Outfit : public Item
{
public:
	Outfit(const std::string& objName, const int& duraValue, const int& specialValue);
	~Outfit();

	void receiveDamage(const int &damage);

	const int getSPECIAL();

protected:
	const int kSPECIAL;
};
#endif // !OUTFIT_H