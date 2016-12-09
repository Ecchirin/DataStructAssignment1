#include "GameObject.h"

GameObject::GameObject(const std::string& objName) : kName(objName)
{
	count_++;
}

std::string GameObject::getName()
{
	return kName;
}

int GameObject::getCount()
{
	return count_;
}