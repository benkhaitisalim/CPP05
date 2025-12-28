/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:32:31 by bsalim            #+#    #+#             */
/*   Updated: 2025/12/25 01:18:11 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 3);
        Bureaucrat jim("Jim", 3);

        Form tax("Tax Form", 3,false , 3);
        Form secret("Secret Form", 3,false, 3);

        std::cout << bob << std::endl;
        std::cout << jim << std::endl;

        std::cout << tax << std::endl;
        std::cout << secret << std::endl;

        // Bob tries to sign forms
        bob.signForm(tax);     
        bob.signForm(secret);

        // Jim tries to sign
        jim.signForm(tax);    

        std::cout << tax << std::endl;
        std::cout << secret << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
