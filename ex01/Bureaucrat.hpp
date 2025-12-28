/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:10:16 by bsalim            #+#    #+#             */
/*   Updated: 2025/12/24 00:30:36 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP 
#define BUREAUCRAT_HPP
#include <iostream>
#include <stdexcept>
#include <string>
class Form;
class Bureaucrat 
{
    private : 
    const std::string name;
    int grade;
    public :
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
    void signForm(Form &form);
    const std::string& getName() const;
    int getGrade() const;
    void increment();
    void decrement();
    class GradeTooLowExceptions : public std::exception 
    {
        public:
        virtual const char* what() const throw();
    };
    class GradeTooHighExceptions : public std::exception 
    {
        public:
        virtual const char* what() const throw();
    };
};

std::ostream&  operator<<(std::ostream& os, const Bureaucrat& b);
#endif