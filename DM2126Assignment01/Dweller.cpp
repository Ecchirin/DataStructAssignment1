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

	outfit_ = NULL;
	weapon_ = NULL;
}

const int Dweller::getSPECIAL()
{
	if ((outfit_ != NULL) && (outfit_->getDurability() > 0))
	{
		int tempValue = 0;
		int finaleValue = 0;
		int outfitSpecial;
		int dwellerSpecial;

		for (outfitSpecial = outfit_->getSPECIAL(), dwellerSpecial = SPECIAL_; dwellerSpecial > 0; outfitSpecial /= 10, dwellerSpecial /= 10)
		{
			if (((outfitSpecial % 10) + (dwellerSpecial % 10)) >= 9)
			{
				tempValue += 9;
			}
			else
			{
				tempValue += ((outfitSpecial % 10) + (dwellerSpecial % 10));
			}

			tempValue *= 10;
		}

		for (int reverseTempValue = tempValue; reverseTempValue > 0; reverseTempValue /= 10)
		{
			finaleValue += (reverseTempValue % 10);

			if ((reverseTempValue / 10) > 0)
			{
				finaleValue *= 10;
			}
		}
		return finaleValue;
	}
	else
	{
		return SPECIAL_;
	}
}

const int Dweller::getCurrentHealth()
{
	if ( ((100 - radiation_) <= 0) || (health_ <= 0) )
	{
		return 0;
	}
	else
	{
		return health_;
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
		if (health_ >= (100 - radiation_))
		{
			health_ = (100 - radiation_);
		}
	}
}

void Dweller::receiveEquipmentDamage(const int& eqDamage)
{
	if (outfit_ != NULL)
	{
		outfit_->receiveDamage(eqDamage);
	}

	if (weapon_ != NULL)
	{
		weapon_->receiveDamage(eqDamage);
	}
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
	if ((getCurrentHealth() < (100 - radiation_)) && (stimpak_ > 0))
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
	if ((radiation_ > 0) && (radaway_ > 0))
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
	outfit_ = outfitPtr;

	return outfit_;
}

Weapon* Dweller::assignWeapon(Weapon *wpnPtr)
{
	weapon_ = wpnPtr;

	return weapon_;
}

bool Dweller::isDead()
{
	if (getCurrentHealth() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}