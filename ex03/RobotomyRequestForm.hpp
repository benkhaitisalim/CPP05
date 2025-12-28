#ifndef ROBOTOMYREQUESTFORM_HPP 
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>
#include "Bureaucrat.hpp"
class RobotomyRequestForm : public AForm
{
    private :
    std::string target;
    public :
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm & other);
    RobotomyRequestForm(const std::string &file);
    RobotomyRequestForm &operator=(const RobotomyRequestForm& other);
    virtual ~RobotomyRequestForm();
    virtual void execute(const Bureaucrat& boss) const;
    class GradeTooLowExceptions : public std::exception
    {
        public :
        virtual const char * what() const throw();
    };
};
#endif