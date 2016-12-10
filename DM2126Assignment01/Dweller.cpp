#include "Dweller.h"

Dweller::Dweller(const std::string& dwellerName, const int& specialValue) : GameObject::GameObject(dwellerName)
{
	position_.x = 0;	position_.y = 0;

	health_ = 100;
	radiation_ = 0;
	SPECIAL_ = specialValue;

	stimpak_ = 0;
	radaway_ = 0;

	outfit_ = NULL;
	weapon_ = NULL;
}

Dweller::~Dweller()
{
	position_.x = 0;	position_.y = 0;

	health_ = 0;
	radiation_ = 0;
	SPECIAL_ = 0;

	stimpak_ = 0;
	radaway_ = 0;

	delete outfit_;
	delete weapon_;
}

const int Dweller::getSPECIAL()
{
	//todo add the names of the special values??
	return SPECIAL_;
}

const int Dweller::getCurrentHealth()
{
	if ((health_ - radiation_) <= 0)
	{
		return 0;
	}
	else
	{
		return (health_ - radiation_);
	}
}

const int Dweller::getCurrentRadDamage()
{
	return radiation_;
}

const int Dweller::getAttackDmg()
{
	if (weapon_ == NULL)
	{
		return 1;
	}
	else
	{
		if (weapon_->getDurability() == 0)
		{
			return 1;
		}
		else
		{
			return weapon_->getAttackDmg();
		}
	}
}

void Dweller::setPosition(const Vec2D& posValue)
{
	position_.x = posValue.x;	position_.y = posValue.y;
}

const Vec2D Dweller::getPosition()
{
	return position_;
}

void Dweller::receiveHealthDamage(const int& hpDamage)
{
	if ((health_ - hpDamage) <= 0)
	{
		health_ = 0;
	}
	else
	{
		health_ -= hpDamage;
	}
}

void Dweller::receiveRadDamage(const int& radDamage)
{
	if ((radiation_ + radDamage) >= 100)
	{
		radiation_ = 100;
	}
	else
	{
		radiation_ += radDamage;
	}
}

void Dweller::receiveEquipmentDamage(const int& eqDamage)
{
	outfit_->receiveDamage(eqDamage);
	weapon_->receiveDamage(eqDamage);
}

void Dweller::addStimpak(const int& numStimpak)
{
	stimpak_ += numStimpak;
}

void Dweller::addRadAway(const int& numRadAway)
{
	radaway_ += numRadAway;
}

void Dweller::useStimpak()
{
	if (getCurrentHealth() < (100 - radiation_))
	{
		stimpak_--;
		if ((health_ + 20) >= (100 - radiation_))
		{
			health_ = (100 - radiation_);
		}
		else
		{
			health_ += 20;
		}
	}
}

void Dweller::useRadAway()
{
	if (radiation_ > 0)
	{
		radaway_--;
		if ((radiation_ - 10) <= 0)
		{
			radiation_ = 0;
		}
		else
		{
			radiation_ -= 10;
		}
	}
}

Outfit* Dweller::assignOutfit(Outfit *outfitPtr)
{

}

Weapon* Dweller::assignWeapon(Weapon *wpnPtr)
{

}

bool Dweller::isDead()
{
	if (getCurrentHealth == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}