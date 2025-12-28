#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():name("Default"),isSigned(false),requiredGrade(150),requiredGradeToexecute(150){}
Form::Form(const Form& other):name(other.name),isSigned(other.isSigned),requiredGrade(other.requiredGrade),requiredGradeToexecute(other.requiredGradeToexecute)
{
    if(other.GetRequiredGrade() > 150 || requiredGradeToexecute > 150)
    {
        throw GradeTooLowException();        
    }
    else if(other.GetRequiredGrade() < 1 || requiredGradeToexecute < 1)
    {
        throw GradeTooHighException();        
    }
}

Form::Form(const std::string& name,int requiredGradeToexecute,bool  isSigned,int requiredGrade):name(name),requiredGrade(requiredGrade),requiredGradeToexecute(requiredGradeToexecute),isSigned(isSigned)
{

}

Form &Form::operator=(const Form& other)
{
    if(this != &other)
    {
        isSigned = other.isSigned;
    }
    return *this;
}
Form::~Form()
{
    
}
int Form::GetrequiredGradeToexecute() const {return requiredGradeToexecute;}
const std::string Form::getName() const {return name;}
bool Form::GetisSigned() const {return isSigned;}
int Form::GetRequiredGrade() const {return requiredGrade;}

std::ostream& operator<<(std::ostream& os, Form& x)
{
    os << x.getName() << " signed " << x.GetisSigned() << ", required grade " << x.GetRequiredGrade() << " required grade to execute: " << x.GetrequiredGradeToexecute();
    return os;
}

const char* Form::GradeTooHighException::what()const throw()
{
    return "form grade too high";
}

const char* Form::GradeTooLowException::what()const throw()
{
    return "form grade too Low";
}

void Form::beSigned(const Bureaucrat& boss)
{
    if(boss.getGrade() > requiredGrade)
    {
        throw GradeTooLowException();
    }
    isSigned = true;
}
