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

Bureaucrat::Bureaucrat(const Bureaucrat &original) : mName(original.mName) {
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

void Bureaucrat::signForm(AForm &f) const {
	try {
		f.beSigned(*this);
		std::cout << mName << " signed " << f.getName() << std::endl;
	} 
	catch (std::exception &e) {
		std::cout << mName << " couldn't sign " << f.getName() << " because : " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &f) const {
	try {
		f.execute(*this);
		std::cout << mName << " executed " << f.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << mName << " couldn't execute " << f.getName() << " because : " << e.what() << std::endl;
	}
}