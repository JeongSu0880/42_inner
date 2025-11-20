#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &original);
	~FragTrap();

	FragTrap &operator=(const FragTrap &original);
	
	void	highFivesGuys();
};

#endif