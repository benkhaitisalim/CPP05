/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 17:10:16 by bsalim            #+#    #+#             */
/*   Updated: 2025/12/23 21:38:34 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREACURAT
#define BUREACURAT
#include <iostream>
#include <stdexcept>
#include <string>
class Bureaucrat 
{
    private : 
    const std::string name;
    size_t grade;
    public :
    Bureaucrat();
    Bureaucrat(const std::string &name, size_t grade);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
    const std::string& getName() const;
    size_t getGrade() const;
    void increment();
    void decrement();
    class GradeToLowExceptions : public std::exception 
    {
        public:
        virtual const char* what() const throw();
    };
    class GradeToHighExceptions : public std::exception 
    {
        public:
        virtual const char* what() const throw();
    };
};

std::ostream&  operator<<(std::ostream& os, const Bureaucrat& b);
#endif