#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm",25,5),target("default_shrubbery")
{

}
PresidentialPardonForm::PresidentialPardonForm(const std::string &file):AForm("PresidentialPardonForm",145,137),target(file)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):AForm(other),target(other.target){}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::execute(const Bureaucrat& boss) const
{
	if(!getisSigned())
	{
		throw GradeTooLowException();
	}
	if(boss.getGrade() > getRequiredGradeToExecute())
	{
		throw GradeTooLowException();
	}
    std::cout << "Informs that " << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

const char *PresidentialPardonForm::GradeTooLowExceptions::what() const throw()
{
	return "grade not enogh";
}
