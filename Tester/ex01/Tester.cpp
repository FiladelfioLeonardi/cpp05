/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:06:02 by fefo              #+#    #+#             */
/*   Updated: 2026/08/14 10:27:42 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tester01.hpp"

Bureaucrat makeBureaucrat()
{
    std::string Name;
    unsigned int grade = 0;
    
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    print_msg("Bureaucrat name: ");
    std::getline(std::cin, Name);
    print_msg(Name + " Grade: ");
    std::cin >> grade;
    return Bureaucrat(Name, grade);
}

Form makeForm()
{
    std::string name;
    unsigned int signGrade;
    unsigned int execGrade;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    print_msg("Form Name: ");
    std::getline(std::cin, name);
    
    signGrade = readInt("Sign Grade: ");
    execGrade = readInt("Exec Grade: ");

    return Form(name, signGrade, execGrade);
}

void changeGrade(Bureaucrat* b)
{
    int grade;
    print_msg("Current grade: " + to_str(b->getGrade()) + "\n");
    print_msg("New Grade: ");
    std::cin >> grade;
    try
    {
        b->setGrade(grade);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    print_msg(b->getName() + " new grade is " + to_str(b->getGrade()) + "\n");
}

void trySign(Bureaucrat* b, Form* f)
{
    try
    {
        b->signForm(*f);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int MainHub01(Bureaucrat* b, Form* f)
{
    int i = -1;
    while(i == -1)
    {
        print_msg("\n1. Change Bureaucrat grade\n");
        print_msg("2. Get Bureaucrat Infos\n");
        print_msg("3. Change Form\n");
        print_msg("4. See Current Form\n");
        print_msg("5. Try to Sign\n");
        print_msg("6. Exit\n\n");
        std::cin >> i;
        
        if (i == 1)
            changeGrade(b);
        else if (i == 2)
        {
            print_msg("Bureaucrat Name: " + b->getName() + "\n");
            print_msg("Bureaucrat Grade: " + to_str(b->getGrade()) + "\n");
        }
        else if (i == 3)
        {
            Form fNew = makeForm();
            MainHub01(b, &fNew);
            i = -2;
            return (i);
        }
        else if (i == 4)
        {
            print_msg("Form name: "+ f->getFormName() + "\n");
            print_msg("Sign Grade: ");
            print_msg(std::to_string(f->getGradeSign()) + "\n\n");
            print_msg("Exec Grade: ");
            print_msg(std::to_string(f->getGradeExect()) + "\n");
        }
        else if (i == 5)
            trySign(b, f);
        else if (i == 6)
            return (-2);
        i = -1;
    }
    return (i);
}
