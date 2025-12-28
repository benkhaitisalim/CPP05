#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <stdexcept>
#include <string>
class Bureaucrat;
class Form{
    private :
    std::string name;
    bool  isSigned;
    const int requiredGrade;
    const int requiredGradeToexecute;
    public :
    Form();
    Form(const Form& other);
    Form(const std::string& name,int requiredGradeToexecute,bool  isSigned,int requiredGrade);
    Form &operator=(const Form& other);
    ~Form();
    const std::string getName()const;
    bool GetisSigned()const;
    int GetRequiredGrade()const;
    int GetrequiredGradeToexecute()const;

    void beSigned(const Bureaucrat& boss);

    class GradeTooHighException : public std::exception
    {
        public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
        virtual const char* what() const throw();
    };
};
std::ostream& operator<<(std::ostream& os, Form& x);
#endif