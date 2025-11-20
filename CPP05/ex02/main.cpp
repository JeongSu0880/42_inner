#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	ShrubberyCreationForm f1("S_test"); //145 137
	PresidentialPardonForm f2("P_test"); //25 5
	RobotomyRequestForm		f3("R_test"); //72 45

	Bureaucrat a("A", 72);
	a.signForm(f3);
	a.executeForm(f3);
	std::cout << "----------------" << std::endl;
	Bureaucrat b("B", 45);
	b.signForm(f3);
	b.executeForm(f3);
	std::cout << "----------------" << std::endl;
	Bureaucrat c("C", 150);
	c.signForm(f3);
	c.executeForm(f3);
}