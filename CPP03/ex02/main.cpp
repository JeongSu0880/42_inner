#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	FragTrap FragTrap1("A");
    ScavTrap ScavTrap1("B");

    // 공격 시도 -> 객체를 받는 게 아니기 때문에 실제 포인트가 줄지는 않는다..
    FragTrap1.attack("B");
    ScavTrap1.attack("A");

    FragTrap1.takeDamage(10);
    ScavTrap1.takeDamage(10);

    FragTrap1.beRepaired(15);
    ScavTrap1.beRepaired(15);

    // 이미 데미지를 충분히 받아서 0인 경우
	FragTrap1.takeDamage(100);
	ScavTrap1.takeDamage(100);

	ScavTrap1.beRepaired(100);
	FragTrap1.beRepaired(100);

    FragTrap1.takeDamage(50);
    ScavTrap1.takeDamage(50);

	/*둘 다 energy -2*/
	std::cout << "FragTrap :: " << FragTrap1.getEnergyPoint() << std::endl;
	std::cout << "ScavTrap :: " << ScavTrap1.getEnergyPoint() << std::endl;

	FragTrap1.highFivesGuys();

    return 0;
}