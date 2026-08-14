/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tester.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:06:02 by fefo              #+#    #+#             */
/*   Updated: 2026/08/14 10:30:00 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tester02.hpp"

Bureaucrat makeBureaucrat()
{
    std::string Name;
    unsigned int grade = 0;

    print_msg("Bureaucrat name: ");
    std::getline(std::cin >> std::ws, Name);
    grade = readInt(Name + " Grade: ");

    return Bureaucrat(Name, grade);
}

Form makeForm()
{
    std::string name;
    unsigned int signGrade;
    unsigned int execGrade;

    print_msg("Form Name: ");
    std::getline(std::cin >> std::ws, name);
    
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

void trySignAForm(Bureaucrat* b, AForm* af)
{
    try
    {
        af->beSigned(*b);
        print_msg(b->getName() + " signed " + af->getName() + "\n");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

void printMenu()
{
    const char* items[] = {
        "Change Bureaucrat grade",
        "Get Bureaucrat Infos",
        "Change Form",
        "See Current Form",
        "Try to Sign",
        "See AForm Details",
        "Change AForm Details",
        "Try to Sign AForm",
        "Exit"
    };
    for (int i = 0; i < 9; i++)
    {
        print_msg(to_str(i + 1) + ". ");
        if (items[i] != NULL)
            print_msg(items[i]);
        print_msg("\n");
    }
}

int MainHub02(Bureaucrat* b, Form* f, AForm* af)
{
    int i;
    while(1)
    {
        printMenu();
        print_msg("Choose between 1 and 9: ");
        if (!(std::cin >> i))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            print_msg("Invalid input...\n");
            continue ;
        }
        
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
            MainHub02(b, &fNew, af);
        }
        else if (i == 4)
        {
            print_msg(f->getFormName() + "\n");
            print_msg(to_str(f->getGradeExect()) + "\n");
            print_msg(to_str(f->getGradeSign()) + "\n\n");
        }
        else if (i == 5)
            trySign(b, f);
        else if (i == 6)
        {
            print_msg("AForm Name: " + af->getName() + "\n");
            print_msg("Sign Grade: " + to_str(af->getSignGrade()) + "\n");
            print_msg("Exec Grade: " + to_str(af->getExecGrade()) + "\n");
            print_msg("Signed: " + std::string(af->getIsSigned() ? "yes" : "no") + "\n");
        }
        else if (i == 7)
            print_msg("AForm details are const and cannot be changed at runtime.\n");
        else if (i == 8)
            trySignAForm(b, af);
        else if (i == 9)
            return (-2);
        else
            print_msg("Invalid choice, pick 1 to 9.\n");
        
    }
    return (i);
}
