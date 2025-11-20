#include "ClapTrap.hpp"

int main() {
	ClapTrap clapTrap1("A");
    ClapTrap clapTrap2("B");

    // 공격 시도 -> 객체를 받는 게 아니기 때문에 실제 포인트가 줄지는 않는다..
    clapTrap1.attack("B");
    clapTrap2.attack("A");

    clapTrap1.takeDamage(10);
    clapTrap2.takeDamage(20);

    clapTrap1.beRepaired(15);
    clapTrap2.beRepaired(5);

    // 이미 데미지를 충분히 받아서 0인 경우
	clapTrap2.takeDamage(100);
	clapTrap2.takeDamage(100);

	//energy 포인트가 없는 경우
	clapTrap2.beRepaired(1);
    clapTrap2.attack("A");
    clapTrap2.beRepaired(1);
    clapTrap2.beRepaired(1);
    clapTrap2.beRepaired(1);
    clapTrap2.beRepaired(1);
    clapTrap2.beRepaired(1);
    clapTrap2.beRepaired(1);
    clapTrap2.beRepaired(1);
    clapTrap2.beRepaired(1);
    clapTrap2.beRepaired(1);


    clapTrap1.takeDamage(30);
    clapTrap2.takeDamage(50);

    return 0;
}