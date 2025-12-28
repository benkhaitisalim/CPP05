/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:32:31 by bsalim            #+#    #+#             */
/*   Updated: 2025/12/28 03:03:28 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 53);
        ShrubberyCreationForm form("ana");
        RobotomyRequestForm aform("nta");

        PresidentialPardonForm aaaform("hwa");

        bob.signForm(form);
        bob.executeForm(form);
        bob.signForm(aform);
        bob.executeForm(aform);
        bob.signForm(aaaform);
        bob.executeForm(aaaform);

        std::cout << "ShrubberyCreationForm EXECUTED SUCCESSFULY" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
