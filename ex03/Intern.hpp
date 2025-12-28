#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
class Intern 
{
    private : 
    public : 
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();
    AForm *makeForm(const std::string& name, const std::string & target);

};
#endif 