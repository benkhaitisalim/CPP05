#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>
#include "Bureaucrat.hpp"
class PresidentialPardonForm : public AForm
{
    private :
    std::string target;
    public :
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm & other);
    PresidentialPardonForm(const std::string &file);
    PresidentialPardonForm &operator=(const PresidentialPardonForm& other);
    virtual ~PresidentialPardonForm();
    virtual void execute(const Bureaucrat& boss) const;
    class GradeTooLowExceptions : public std::exception
    {
        public :
        virtual const char * what() const throw();
    };
};
#endif