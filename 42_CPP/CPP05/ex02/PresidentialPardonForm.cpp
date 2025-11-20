#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), mTarget("default") {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &original) : AForm(original), mTarget(original.mTarget) {
    *this = original;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), mTarget(target) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &original) {
	if (this != &original) {
		AForm::operator=(original);
		mTarget = original.mTarget;
	}
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &b) const {
    if (getSignedStatus() == false) {
		throw FormNotSignedException();
	}

	if (b.getGrade() > getExecutedGrade()) {
		throw GradeTooLowException();
	}

    std::cout << mTarget << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}