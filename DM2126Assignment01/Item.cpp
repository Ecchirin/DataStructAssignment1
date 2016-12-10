#include "Item.h"

Item::Item(const std::string& objName, const int& duraValue) : GameObject::GameObject(objName)
{
	durability_ = duraValue;
}

Item::~Item()
{
	durability_ = 0;
	std::cout << this->getName << " is deleted.\n";
}

const int Item::getDurability()
{
	return durability_;
}