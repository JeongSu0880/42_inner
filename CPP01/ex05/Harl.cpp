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
