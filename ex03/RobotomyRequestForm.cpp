#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"


RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm",72,45),target("default_shrubbery")
{

}
RobotomyRequestForm::RobotomyRequestForm(const std::string &file):AForm("RobotomyRequestForm",145,137),target(file)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):AForm(other),target(other.target){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute(const Bureaucrat& boss) const
{
	if(!getisSigned())
	{
		throw GradeTooLowException();
	}
	if(boss.getGrade() > getRequiredGradeToExecute())
	{
		throw GradeTooLowException();
	}
    std::cout << "* Drilling noises *" << std::endl;
    
    if (rand() % 2)
    {
        std::cout << target
                  << " has been robotomized successfully."
                  << std::endl;
    }
    else
    {
        std::cout << "Robotomy failed on "
                  << target << "."
                  << std::endl;
    }
}

const char *RobotomyRequestForm::GradeTooLowExceptions::what() const throw()
{
	return "grade not enogh";
}
