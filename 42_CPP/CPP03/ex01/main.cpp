#include "ScavTrap.hpp"

int main() {
	ScavTrap scavTrap1("A");
    ClapTrap clapTrap1("B");

    // 공격 시도 -> 객체를 받는 게 아니기 때문에 실제 포인트가 줄지는 않는다..
    scavTrap1.attack("B");
    clapTrap1.attack("A");

    scavTrap1.takeDamage(10);
    clapTrap1.takeDamage(10);

    scavTrap1.beRepaired(10);
    clapTrap1.beRepaired(10);

    // 이미 데미지를 충분히 받아서 0인 경우
	scavTrap1.takeDamage(100);
	clapTrap1.takeDamage(100);

	scavTrap1.beRepaired(1);
	clapTrap1.beRepaired(1);

    scavTrap1.takeDamage(30);
    clapTrap1.takeDamage(30);

	std::cout << "FragTrap :: " << scavTrap1.getEnergyPoint() << std::endl;
	std::cout << "ScavTrap :: " << clapTrap1.getEnergyPoint() << std::endl;

	scavTrap1.guardGate();

    return 0;
}