#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("No name", 100, 100, 30) { 
	std::cout << "FragTrap " << this->name << " has been created!" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap " << this->name << " has been created!" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " has been destroyed!" << std::endl;
}


FragTrap::FragTrap(const FragTrap &original) {
	std::cout << "FragTrap " << this->name << " has been copied!" << std::endl;
	*this = original;
}

FragTrap &FragTrap::operator=(const FragTrap &original) {
	if (this != &original) {
		this->name = original.getName();
		this->hitPoint = original.getHitPoint();
		this->energyPoint = original.getEnergyPoint();
		this->attackDamage = original.getAttackDamage();
		this->maxHit = original.maxHit;
	}

	return *this;
}

void FragTrap::highFivesGuys() {
	if (this->energyPoint <= MIN || this->hitPoint <= MIN) {
		return;
	}
	std::cout << "FragTrap " << name << " high five!" << std::endl;
}