#include "Weapon.hpp"

Weapon::Weapon() : mType("default knife")
{
}

Weapon::Weapon(std::string type) : mType(type)
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType()
{
	const std::string &rType = mType;

	return rType;
}

void	Weapon::setType(std::string type)
{
	mType = type;
}