#include "GameObject.h"

int GameObject::count_ = 0;

GameObject::GameObject(const std::string& objName) : kName(objName)
{
	count_++;
}

GameObject::~GameObject()
{
	count_--;
}

std::string GameObject::getName()
{
	return kName;
}

int GameObject::getCount()
{
	return count_;
}