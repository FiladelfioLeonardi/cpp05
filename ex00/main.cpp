/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:20:52 by fefo              #+#    #+#             */
/*   Updated: 2026/10/09 21:51:30 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "../Tester/ex00/Tester00.hpp"

int main()
{
    std::cout << "-------TEST 1: BUREAUCRATS TOO HIGH AND TOO LOW GRADE-------" << std::endl;
    try 
    {
        Bureaucrat High("high B", 0);
        Bureaucrat Low("low B", 160);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "-------TEST 2: MAKE AND CHANGE BUREAUCRATS GRADE-------" << std::endl;
    try 
    {
        Bureaucrat High("high B", 1);
        Bureaucrat Low("low B", 150);
        High.decrementGrade(2);
        Low.incrementGrade(2);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "-------TEST 3: BUREAUCRATS TOO HIGH AND TOO LOW LEVEL-------" << std::endl;
    try 
    {
        Bureaucrat High("high B", 1);
        Bureaucrat Low("low B", 150);
        High.incrementGrade(1);
        Low.decrementGrade(1);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}

