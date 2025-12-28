#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int requiredGrade;
    const int requiredGradeToExecute;

public:
    AForm();
    AForm(const AForm& other);
    AForm(const std::string& name, int requiredGrade, int requiredGradeToExecute);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string getName() const;
    bool getisSigned() const;
    int getRequiredGrade() const;
    int getRequiredGradeToExecute() const;

    void beSigned(const Bureaucrat& boss);
    virtual void execute(const Bureaucrat& boss) const = 0;

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& x);

#endif
