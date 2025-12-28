/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:11:41 by bsalim            #+#    #+#             */
/*   Updated: 2025/12/28 01:58:33 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat():name("Default"),grade(150)
{
    // std::cout << "This is Default Constructor" << std::endl;
}
Bureaucrat::Bureaucrat(const std::string &n, int g):name(n),grade(g)
{
    if(g > 150)
    {
        throw GradeTooLowExceptions();
    }
    if(g < 1) 
    {
        throw GradeTooHighExceptions();
    }
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if(this != &other)
    {
        grade = other.grade;
    }
    return *this;
}
Bureaucrat::~Bureaucrat()
{
    // std::cout << "This is Destructor" << std::endl;
}
int Bureaucrat::getGrade() const
{
    return grade;
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

std::ostream&  operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << " bureaucrat grade " << b.getGrade();
    return os;
}

void Bureaucrat::increment()
{
    if(grade <= 1)
    {
        throw GradeTooHighExceptions();
    }
    --grade;   
}
void Bureaucrat::decrement()
{
    if(grade >= 150)
    {
        throw GradeTooLowExceptions();
    }
    ++grade;
}

const char* Bureaucrat::GradeTooLowExceptions::what() const throw()
{
    return "GradeToLowExceptions";
}
const char* Bureaucrat::GradeTooHighExceptions::what() const throw()
{
    return "GradeToHighExceptions";
}
void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << getName() << " couldn’t sign " << form.getName() << "because" << e.what() << std::endl;
        
    }
}
void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << name << " couldn't execute "
                  << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
