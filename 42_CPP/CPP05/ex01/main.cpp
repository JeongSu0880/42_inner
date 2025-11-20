#include "Bureaucrat.hpp"

int main() {
	Bureaucrat b("B", 149);
	Form f1("form_1", 50, 60);
	Form f2("form_2", 2, 60);

	b.signForm(f1);
}