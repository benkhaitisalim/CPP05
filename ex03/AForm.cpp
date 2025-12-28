#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* Orthodox Canonical Form */

AForm::AForm()
    : name("Default"), isSigned(false), requiredGrade(150), requiredGradeToExecute(150)
{
}

AForm::AForm(const AForm& other)
    : name(other.name),
      isSigned(other.isSigned),
      requiredGrade(other.requiredGrade),
      requiredGradeToExecute(other.requiredGradeToExecute)
{
    if (requiredGrade > 150 || requiredGradeToExecute > 150)
        throw GradeTooLowException();
    if (requiredGrade < 1 || requiredGradeToExecute < 1)
        throw GradeTooHighException();
}

AForm::AForm(const std::string& name, int requiredGrade, int requiredGradeToExecute)
    : name(name),
      isSigned(false),
      requiredGrade(requiredGrade),
      requiredGradeToExecute(requiredGradeToExecute)
{
    if (requiredGrade > 150 || requiredGradeToExecute > 150)
        throw GradeTooLowException();
    if (requiredGrade < 1 || requiredGradeToExecute < 1)
        throw GradeTooHighException();
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

AForm::~AForm()
{
}

/* Getters */

const std::string AForm::getName() const
{
    return name;
}

bool AForm::getisSigned() const
{
    return isSigned;
}

int AForm::getRequiredGrade() const
{
    return requiredGrade;
}

int AForm::getRequiredGradeToExecute() const
{
    return requiredGradeToExecute;
}

/* Operator overload */

std::ostream& operator<<(std::ostream& os, const AForm& x)
{
    os << x.getName()
       << " signed: " << (x.getisSigned() ? "true" : "false")
       << ", required grade: " << x.getRequiredGrade()
       << ", required grade to execute: " << x.getRequiredGradeToExecute();
    return os;
}

/* Exceptions */

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade too low";
}

/* Member functions */

void AForm::beSigned(const Bureaucrat& boss)
{
    if (boss.getGrade() > requiredGrade)
        throw GradeTooLowException();
    isSigned = true;
}
