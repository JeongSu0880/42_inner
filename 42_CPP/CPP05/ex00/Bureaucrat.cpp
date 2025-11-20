#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : mName("default"), mGrade(150) {
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : mName(name), mGrade(grade) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &original) {
	*this = original;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &original) {
	if (this != &original) {
		this->mGrade = original.mGrade;
	}
	return (*this);
}

const std::string &Bureaucrat::getName() const {
	return mName;
}

const int &Bureaucrat::getGrade() const {
	return mGrade;
}

void Bureaucrat::incrementGrade() {
	if (mGrade - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	--mGrade;
}

void Bureaucrat::decrementGrade() {
	if (mGrade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	++mGrade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return out;
}






