#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern(){
    std::cout << "Default Constructor" << std::endl;
}
Intern::Intern(const Intern& other) 
{
    std::cout << "Copy Constructor" << std::endl;
    *this = other;
}
Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Copy Destructor" << std::endl;
}
AForm *Intern::makeForm(const std::string& name, const std::string & target)
{
    std::string arr[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    for(int i = 0; i < 3;i++)
    {
        if(name == arr[i])
        {
            std::cout << "Create from" << std::endl;
            if(i == 0)
            {
                return new ShrubberyCreationForm();
            }
            else if(i == 1)
            {
                return new RobotomyRequestForm();
            }
            else if(i == 2)
                return new PresidentialPardonForm();
        }
    }
    std::cout << "Intern cannot create form" << std::endl;
    return NULL;
}
