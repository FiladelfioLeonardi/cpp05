/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:20:52 by fefo              #+#    #+#             */
/*   Updated: 2026/10/15 20:59:54 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main()
{
    std::cout << "---------EX 1---------" << std::endl;
    Bureaucrat b1("John", 1);
    std::cout << b1 << std::endl;
    try
    {
        b1.decrementGrade(20);
        std::cout << b1 << std::endl;
        b1.incrementGrade(1);
        std::cout << b1 << std::endl;
        b1.incrementGrade(1);
        std::cout << b1 << std::endl;
        b1.incrementGrade(200);
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl << "---------EX 2---------" << std::endl;
    try
    {
        Bureaucrat b2;
        b2.decrementGrade(200);
        std::cout << b2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}