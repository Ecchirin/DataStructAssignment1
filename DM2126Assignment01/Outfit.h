#ifndef OUTFIT_H
#define OUTFIT_H

#include "Item.h"

class Outfit : public Item
{
public:
	Outfit(const std::string&, const int&, const int&);
	~Outfit();

	void receiveDamage(const int & damage);

	const int getSPECIAL();

protected:
	const int kSPECIAL;
};
#endif // !OUTFIT_H