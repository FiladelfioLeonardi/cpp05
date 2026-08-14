/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:46:51 by fefo              #+#    #+#             */
/*   Updated: 2026/08/14 10:23:29 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tester00.hpp"

void changeGrade(Bureaucrat* current)
{
    print_msg(current->getName() + " Grade: " + to_str(current->getGrade()) + "\n");
    while(1)
    {
        print_msg("New Grade: ");
        
        int i;
        if (!(std::cin >> i))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            print_msg("Wrong input... Try again...\n");
            continue ;
        }
        current->setGrade(i);
        print_msg("New Grade Set: " + to_str(current->getGrade()) + '\n');
        return ;
    }

}


Bureaucrat  makeBureaucrat(bool hasCurrent)
{
    int choice;
    while(1)
    {
        print_msg("Choose Bureaucrat\n");
        print_msg("1. Default Bureaurat\n");
        print_msg("2. Custom Bureaucrat\n");
        print_msg("3. Back\n\n");
        
        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            print_msg("Wrong input... Try again...\n");
            continue ;
        }
        if (choice > 3 && choice < 1)
        {
            print_msg("Choose between 1 and 3\n");
            continue ;
        }
        if (choice == 1)
            return Bureaucrat();
        if (choice == 2)
        {
            std::string name;
            int         grade;
            print_msg  ("Bureaucrat name: ");
            std::cin >> name;
            
            while (1)
            {
                print_msg("Bureaucrat grade: ");
                if (!(std::cin >> grade))
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    print_msg("invalid input, try numbers\n");
                    continue ;
                }
                try
                {
                    return Bureaucrat(name, grade);                    
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
        }
        else
        {
            if (hasCurrent == false)
            {
                print_msg("U tried to exit without making a Bureaucrat...\n");
                print_msg("Making a default Bureaucrat before leaving\n");
                try
                {
                    return Bureaucrat();
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
        }
    } 
}

int mainHub00()
{
    Bureaucrat Current;
    bool hasCurrent = true;
    
    while (1)
    {
        print_msg("\n1. Make a New Bureaucrat\n");
        print_msg("2. Change Bureaucrat Grade\n");
        print_msg("3. Exit\n\n");
        
        int i = 0;
        if (!(std::cin >> i))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue ;            
        }
        if (i == 1)
        {
            try
            {
                
                Bureaucrat New = makeBureaucrat(hasCurrent);
                Current.setGrade(New.getGrade());
                hasCurrent = true;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }
        else if (i == 2)
        {
            if (!hasCurrent)
            {
                print_msg("Make a Bureaucrat first...\n");
                continue ;
            }
            try
            {
                changeGrade(&Current);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
        }
        else if (i == 3)
        {
            return -2;
        }
    }
    return -2;
}
