/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:32:31 by bsalim            #+#    #+#             */
/*   Updated: 2025/12/28 04:30:39 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include  "Intern.hpp"

int main()
{
    Intern someIntern;
    Bureaucrat bob("Bob", 20);

    AForm* form1 = someIntern.makeForm("ShrubberyCreationForm", "Home");
    AForm* form2 = someIntern.makeForm("RobotomyRequestForm", "Bender");
    AForm* form3 = someIntern.makeForm("PresidentialPardonForm", "Alice");
    AForm* form4 = someIntern.makeForm("unknown form", "Target");
    if(form1) std::cout << "Form1 created successfully!" << std::endl;
    if(form2) std::cout << "Form2 created successfully!" << std::endl;
    if(form3) std::cout << "Form3 created successfully!" << std::endl;
    if(!form4) std::cout << "Form4 creation failed (unknown form)." << std::endl;
    bob.signForm(*form1);
    bob.executeForm(*form1);
    bob.signForm(*form2);
    bob.executeForm(*form2);
    bob.signForm(*form3);
    bob.executeForm(*form3);

    delete form1;
    delete form2;
    delete form3;
    delete form4; 

    return 0;
}
