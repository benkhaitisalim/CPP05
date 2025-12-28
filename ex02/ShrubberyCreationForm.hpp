#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>
#include "Bureaucrat.hpp"
class ShrubberyCreationForm : public AForm
{
    private :
    std::string target;
    public :
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm & other);
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm& other);
    virtual ~ShrubberyCreationForm();
    virtual void execute(const Bureaucrat& boss) const;
    class GradeTooLowExceptions : public std::exception
    {
        public :
        virtual const char * what() const throw();
    };
};
#endif