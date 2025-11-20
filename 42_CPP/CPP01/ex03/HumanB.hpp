#ifndef HUMANB_HPP
# define HUMANB_HPP
# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private :
		std::string mName;
		Weapon 		*mWeapon;

	public :
		HumanB(std::string name);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon &weapon);

};

#endif