#ifndef ASSIGNMENT1_ROOT_ITEM_H
#define ASSIGNMENT1_ROOT_ITEM_H

#include "GameObject.h"

class Item : public GameObject
{
public:
	Item(const std::string& objName, const int& duraValue);
	virtual ~Item();

	virtual void receiveDamage(const int &damage) = 0;
	const int getDurability();

protected:
	int durability_;
};
#endif // !ITEM_H