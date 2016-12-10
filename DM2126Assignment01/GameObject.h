#ifndef ASSIGNMENT1_ROOT_GAMEOBJECT_H
#define ASSIGNMENT1_ROOT_GAMEOBJECT_H

#include <iostream>
#include <string>

class GameObject
{
public:
	virtual ~GameObject() = 0;

	std::string getName(void);
	static int getCount();

protected:
	const std::string kName;
	GameObject(const std::string& objName);

private:
	static int count_;
};
#endif // !GAMEOBJECT_H