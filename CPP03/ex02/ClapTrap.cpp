#include "ClapTrap.hpp"

/*OCCF 구현부*/
ClapTrap::ClapTrap() : name("No name"), energyPoint(10), attackDamage(0), maxHit(10){
	std::cout << "ClapTrap " << name << " has been created!" << std::endl;

	this->hitPoint = maxHit;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), energyPoint(10), attackDamage(0), maxHit(10) {
	std::cout << "ClapTrap " << name << " has been created!" << std::endl;

	this->hitPoint = maxHit;
}

ClapTrap::ClapTrap(const std::string &name, long long hit, long long energy, long long damage) : name(name), energyPoint(energy), attackDamage(damage), maxHit(hit) {
	std::cout << "ClapTrap " << name << " has been created!" << std::endl;
	
	this->hitPoint = maxHit;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &original) {
	std::cout << "ClapTrap " << name << " has been copied!" << std::endl;
	*this = original;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& original) {
	if (this != &original) {
		this->name = original.getName();
		this->hitPoint = original.getHitPoint();
		this->energyPoint = original.getEnergyPoint();
		this->attackDamage = original.getAttackDamage();
		this->maxHit = original.maxHit;
	}

	return *this;	
}

/*subject 요구 함수 구현부*/
void ClapTrap::attack(const std::string& target) {
	if (this->energyPoint <= MIN || this->hitPoint <= MIN) {
		return;
	}

	--(this->energyPoint);

	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	//더 감소할 damage가 안남았을때는 그냥 return
	if (this->hitPoint == MIN || this->energyPoint <= MIN) {
		return;
	}

	long long tmpPoint = this->hitPoint - amount;
	this->hitPoint = (tmpPoint <= MIN) ? MIN : tmpPoint;

	std::cout << name << " takes " << amount << " damage! " << name << " has " << this->hitPoint << " hit points remaining." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoint <= MIN || this->hitPoint <= MIN) {
		return;
	}

	if (this->hitPoint == maxHit) {
		return;
	}

	long long tmpPoint = this->hitPoint + amount;
	this->hitPoint = (tmpPoint >= maxHit) ? maxHit : tmpPoint;

	--(this->energyPoint);

	std::cout << name << " has repaired " << amount << "! " << name << " has " << this->hitPoint << " hit points remaining." << std::endl;
}

/*getter, setter 구현부*/
const std::string &ClapTrap::getName() const {
	return this->name;
}

long long ClapTrap::getHitPoint() const {
	return this->hitPoint;
}

long long ClapTrap::getEnergyPoint() const {
	return this->energyPoint;
}

long long ClapTrap::getAttackDamage() const {
	return this->attackDamage;
}

void	ClapTrap::setName(std::string name) {
	this->name = name;
}

void	ClapTrap::setHitPoint(unsigned int point) {
	this->hitPoint = point;
}

void	ClapTrap::setEnergyPoint(unsigned int point) {
	this->energyPoint = point;
}

void	ClapTrap::setAttackDamage(unsigned int damage) {
	this->attackDamage = damage;
}