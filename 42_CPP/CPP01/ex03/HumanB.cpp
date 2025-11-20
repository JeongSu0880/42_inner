#include "HumanB.hpp"

HumanB::HumanB(std::string name) : mName(name), mWeapon(NULL) {}

HumanB::~HumanB() {}

void	HumanB::attack()
{
	if (mWeapon == NULL)
	{
		std::cout << mName << " has no Weapon " << std::endl;
		return ;
	}
	std::cout << mName << " attacks with their " << mWeapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	mWeapon = &weapon;
}
