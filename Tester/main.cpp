/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:51:07 by fefo              #+#    #+#             */
/*   Updated: 2026/08/14 10:22:23 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"


int main()
{
    std::cout << "\nWelcome to the CPP 05 tester!\n Choose an exercise" << std::endl << std::endl;
    
    while(1)
    {
        print_msg("1. Exercise 00: Bureaucrat\n");
        print_msg("2. Exercise 01: Form\n");
        print_msg("3. Exercise 02: No, you need form 28B, not 28C\n");
        print_msg("4. Exit\n");

        int choice;
        if (!(std::cin >> choice)) { std::cin.clear(); std::cin.ignore(1000, '\n'); continue; }

        if (choice == 1)
        {
            if (std::system("make re -C ../ex00") != 0) { std::cerr << "ex00 build failed\n"; continue; }
            std::system("../ex00/Bureaucrat");
        }
        else if (choice == 2)
        {
            if (std::system("make re -C ../ex01") != 0) { std::cerr << "ex01 build failed\n"; continue; }
            std::system("../ex01/Bureaucrat");
        }
        else if (choice == 3)
        {
            if (std::system("make re -C ../ex02") != 0) { std::cerr << "ex02 build failed\n"; continue; }
            std::system("../ex02/Bureaucrat");
        }
        else if (choice == 4)
        {
            print_msg("\nSee you Soon!\n");
            break;
        }
        else
            print_msg("\nInvalid input...\n");
    }
    return 0;
}