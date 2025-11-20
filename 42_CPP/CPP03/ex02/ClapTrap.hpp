#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define MIN 0

class ClapTrap
{
protected:
	std::string name;
	long long	hitPoint;
	long long	energyPoint;
	long long	attackDamage;

	long long	maxHit;

public:
	ClapTrap();
	ClapTrap(const std::string &name);
	ClapTrap(const std::string &name, long long hit, long long energy, long long damage);
	ClapTrap(const ClapTrap& original);
	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &original);

	void attack(const std:: string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	const std::string& getName() const;
	long long	getHitPoint() const;
	long long	getEnergyPoint() const;
	long long	getAttackDamage() const;

	void	setName(std::string name);
	void	setHitPoint(unsigned int point);
	void	setEnergyPoint(unsigned int point);
	void	setAttackDamage(unsigned int damage);
};

#endif
