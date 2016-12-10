#ifndef ASSIGNMENT1_ROOT_DWELLER_H
#define ASSIGNMENT1_ROOT_DWELLER_H

#include "Vec2D.h"
#include "Weapon.h"
#include "Outfit.h"

class Dweller : public GameObject
{
public:
	Dweller(const std::string& dwellerName, const int& specialValue);
	~Dweller();

	const int getSPECIAL();
	const int getCurrentHealth();
	const int getCurrentRadDamage();
	const int getAttackDmg();

	void setPosition(const Vec2D&);
	const Vec2D getPosition();

	void receiveHealthDamage(const int& hpDamage);
	void receiveRadDamage(const int& radDamage);
	void receiveEquipmentDamage(const int& eqDamage);
	
	void addStimpak(const int& numStimpak);
	void addRadAway(const int& numRadAway);

	void useStimpak();
	void useRadAway();

	Outfit* assignOutfit(Outfit * outfitPtr);
	Weapon* assignWeapon(Weapon * wpnPtr);

	bool isDead();

protected:
	Vec2D position_;
	int SPECIAL_;
	int health_;
	int radiation_;
	int stimpak_;
	int radaway_;
	Outfit *outfit_;
	Weapon *weapon_;

};
#endif // !DWELLER_H