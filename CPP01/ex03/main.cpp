#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

// void leaks()
// {
// 	system("leaks ex03");
// }

// int main()
// {
// 	// atexit(leaks);

// 	Weapon gun = Weapon("gun");
// 	Weapon defaultWeapon = Weapon();

// 	HumanA humanA = HumanA("A", gun);
// 	HumanB humanB = HumanB("B");

// 	humanA.attack();
// 	humanB.attack();

// 	humanB.setWeapon(defaultWeapon);
// 	humanB.attack();
// 	defaultWeapon.setType("luxury knife");
// 	humanB.attack();

// }

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}