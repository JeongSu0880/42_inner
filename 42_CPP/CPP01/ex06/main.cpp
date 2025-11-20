#include "Harl.hpp"

int main(int argc, char *argv[]) {
	Harl harl;

	// harl.complain("DEBUG");
	// harl.complain("INFO");
	// harl.complain("WARNING");
	// harl.complain("ERROR");

	if (argc != 2)
	{
		std::cerr << "Error : Invalid argument" << std::endl;
		return (-1);
	}
	harl.filter(argv[1]);
}