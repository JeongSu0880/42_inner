#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), mTarget("default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), mTarget(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &original) : AForm(original), mTarget(original.mTarget) {
	*this = original;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &original) {
	if (this != &original) {
		AForm::operator=(original);
		mTarget = original.mTarget;
	}
	return (*this);
}

const char *ShrubberyCreationForm::FileNotOpenException::what() const throw() {
	return "File not open.";
}

void ShrubberyCreationForm::execute(const Bureaucrat &b) const {
	if (getSignedStatus() == false) {
		throw FormNotSignedException();
	}

	if (b.getGrade() > getExecutedGrade()) {
		throw GradeTooLowException();
	}

	std::ofstream file(mTarget + "_shrubbery");
	
	if (!file.is_open()) {
		throw FileNotOpenException();
	}

	file << "        *        " << std::endl;
	file << "       ***       " << std::endl;
	file << "      *****      " << std::endl;
	file << "     *******     " << std::endl;
	file << "    *********    " << std::endl;
	file << "   ***********   " << std::endl;
	file << "  *************  " << std::endl;
	file << " *************** " << std::endl;
	file << "*****************" << std::endl;
	file << "        |        " << std::endl;

	file.close();
	std::cout << "File is successfully written." << std::endl;
}