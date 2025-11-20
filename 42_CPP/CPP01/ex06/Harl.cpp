#include "Harl.hpp"

const std::string Harl::DEBUG  = "I want L-double-cheese-triple-pickle-special-ketchup burger~";
const std::string Harl::INFO = "I cannot believe adding extra bacon costs more money.";
const std::string Harl::WARNING = "I think I deserve to have some extra bacon for free.";
const std::string Harl::ERROR = "This is unacceptable! I want to speak to the manager now.";
const int	Harl::NUMER_OF_LEVELS = 4;

Harl::Harl() {};

Harl::~Harl() {};

void	Harl::debug() {
	std::cout << DEBUG << std::endl;
}

void	Harl::info() {
	std::cout << INFO << std::endl;
}

void	Harl::warning() {
	std::cout << WARNING << std::endl;
}

void	Harl::error() {
	std::cout << ERROR << std::endl;
}

void	Harl::complain(std::string level) {
	void	(Harl::*behave[NUMER_OF_LEVELS])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levelString[NUMER_OF_LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < NUMER_OF_LEVELS; i++) {
		if (level == levelString[i]) {
			(this->*behave[i])();
			break ;
		}
	}
}

void	Harl::filter(std::string level) {
	
	std::string	levelString[NUMER_OF_LEVELS] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	idx = 0;
	while (levelString[idx] != level && idx < NUMER_OF_LEVELS) {
		idx++;
	}

	switch (idx) {
		case 0 :
			std::cout << "[" << levelString[0] << "]" << std::endl;
			debug();
			__attribute__((fallthrough));
		case 1 :
			std::cout << "[" << levelString[1] << "]" << std::endl;
			info();
			__attribute__((fallthrough));
		case 2 :
			std::cout << "[" << levelString[2] << "]" << std::endl;
			warning();
			__attribute__((fallthrough));
		case 3 :
			std::cout << "[" << levelString[3] << "]" << std::endl;
			error();
			break ;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

	}
}