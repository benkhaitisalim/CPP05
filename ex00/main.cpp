/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsalim <bsalim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:32:31 by bsalim            #+#    #+#             */
/*   Updated: 2025/12/23 19:53:31 by bsalim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat ok("salim",5);
        std::cout << ok.getName() << " Before bureaucrat grade " << ok.getGrade() << std::endl;
        ok.decrement();
        std::cout << ok.getName() << " after bureaucrat grade " << ok.getGrade() << std::endl;
        ok.increment();
        std::cout << ok.getName() << " after bureaucrat grade " << ok.getGrade() << std::endl;
        Bureaucrat c("1337",1);
        std::cout << c.getName() << " befor bureaucrat grade " << c.getGrade() << std::endl;
        c.increment();
        std::cout << c.getName() << " after bureaucrat grade " << c.getGrade() << std::endl;
    }
    catch (std::exception& e)
    {
      std::cout << "Exception : " << e.what()  << std::endl;
    }
    return 0;
    
}