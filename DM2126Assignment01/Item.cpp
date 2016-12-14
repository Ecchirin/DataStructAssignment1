#include "Item.h"

Item::Item(const std::string& objName, const int& duraValue) : GameObject(objName)
{
	durability_ = duraValue;
}

Item::~Item()
{
	durability_ = 0;
}

const int Item::getDurability()
{
	return durability_;
}