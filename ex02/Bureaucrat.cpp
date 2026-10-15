/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:20:59 by fefo              #+#    #+#             */
/*   Updated: 2026/05/26 16:44:37 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int Bureaucrat::checkGrade(int grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    if (grade < 1)
        throw GradeTooHighException();
    return grade;
}

Bureaucrat::Bureaucrat() : name("Bureaucrat"), final_grade(150)
{
    checkGrade(final_grade);
    std::cout << "Bureaucrat Got created with a grade of " << final_grade << std::endl; 
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), final_grade(grade)
{
    checkGrade(final_grade);
    std::cout << name << " Got Created, with a grade of " << grade << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bye bye Mr. " << name << " :(" <<std::endl;
}

void Bureaucrat::setGrade(int grade)
{
    checkGrade(grade);
    this->final_grade = grade;
}

const std::string& Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const 
{
    return final_grade;
}

void Bureaucrat::incrementGrade(int increment)
{
    int final_grade = getGrade() - increment;
    setGrade(final_grade);
    std::cout << "Grade incremented by " << increment << "." << std::endl;
}

void Bureaucrat::decrementGrade(int decrement)
{
    int final_grade = getGrade() + decrement;
    setGrade(final_grade);
    std::cout << "Grade decremented by " << decrement << "." << std::endl;
}

void    Bureaucrat::signForm(AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << name << " couldn't sign " << form.getName()
            << " because " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const& form) const
{
    try
    {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << name << " couldn't execute " << form.getName()
            << " because " << e.what() << std::endl;
    }
}


std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}
