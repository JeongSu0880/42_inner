#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), mTarget("default") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), mTarget(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original) : AForm(original), mTarget(original.mTarget) {
    *this = original;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &original) {
	if (this != &original) {
		AForm::operator=(original);
		mTarget = original.mTarget;
	}
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &b) const {
    if (getSignedStatus() == false) {
		throw FormNotSignedException();
	}

	if (b.getGrade() > getExecutedGrade()) {
		throw GradeTooLowException();
	}

    std::srand(std::time(0));
    int randomN = std::rand();

    if ((randomN % 2) == 0) {
        std::cout << mTarget << " has been robotomized successfully 50% of the time." << std::endl;
    } else {
        std::cout << mTarget << " robotomize failed." << std::endl;
    }
}