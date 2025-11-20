#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() { 
	std::cout << "ScavTrap " << this->name << " has been created!" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name, 100, 50, 20) {
	std::cout << "ScavTrap " << this->name << " has been created!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name << " has been destroyed!" << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &original) {
	std::cout << "ScavTrap " << this->name << " has been copied!" << std::endl;
	*this = original;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &original) {
	if (this != &original) {
		this->name = original.getName();
		this->hitPoint = original.getHitPoint();
		this->energyPoint = original.getEnergyPoint();
		this->attackDamage = original.getAttackDamage();
		this->maxHit = original.maxHit;
	}

	return *this;
}

void	ScavTrap::attack(const std::string &target) {

	if (this->energyPoint <= MIN) {
		std::cout << this->getName() << " has failed to attack. " << "Out of energy!" << std::endl;
		return;
	}

	--(this->energyPoint);

	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
	if (this->energyPoint <= MIN || this->hitPoint <= MIN) {
		return;
	}
	std::cout << "ScavTrap " << name << " is now in Gatekeeper mode!" << std::endl;
}