#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

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
	GameObject(const std::string&);

private:
	static int count_;
};
#endif // !GAMEOBJECT_H