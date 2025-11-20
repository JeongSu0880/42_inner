#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat first("1", 149);
		Bureaucrat second("2", 1);

		first.decrementGrade();
		std::cout << first;//150
		
		// first.decrementGrade();
		// std::cout << first; // too low
		
		second.incrementGrade();
		std::cout << second; //too high
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}