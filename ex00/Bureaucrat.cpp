/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:11:41 by bsalim            #+#    #+#             */
/*   Updated: 2025/12/23 19:53:17 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("Default"),grade(150)
{
    // std::cout << "This is Default Constructor" << std::endl;
}
Bureaucrat::Bureaucrat(const std::string &n, size_t g):name(n),grade(g)
{
    if(g > 150)
    {
        throw GradeToLowExceptions();
    }
    if(g < 1) 
    {
        throw GradeToHighExceptions();
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
size_t Bureaucrat::getGrade() const
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
        throw GradeToHighExceptions();
    }
    --grade;   
}
void Bureaucrat::decrement()
{
    if(grade >= 150)
    {
        throw GradeToLowExceptions();
    }
    ++grade;
}

const char* Bureaucrat::GradeToLowExceptions::what() const throw()
{
    return "GradeToLowExceptions";
}
const char* Bureaucrat::GradeToHighExceptions::what() const throw()
{
    return "GradeToHighExceptions";
}