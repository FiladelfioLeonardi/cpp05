/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:39:19 by fefo              #+#    #+#             */
/*   Updated: 2026/05/26 13:54:33 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int gradeSignValue, int gradeExecValue) : name(name), gradeSign(gradeSignValue), gradeExec(gradeExecValue) 
{
    checkGrade(gradeExecValue);
    checkGrade(gradeSignValue);
    std::cout << "Form " << name << " got created. \nSignature Value: " <<
     gradeSignValue << "\nExecute Value: " << gradeExecValue << std::endl;
}
Form::Form() : gradeExec(1), gradeSign(1)
{
    std::cout << "Form created with default values.\nSignature value = 1\nExecute value: 1" << std::endl;
}

Form::~Form()
{
    std::cout << "Form destroyed..." << std::endl;
}

int Form::checkGrade(int grade)
{
    if (grade < 1)
        throw (GradeTooHighException());
    if (grade > 150)
        throw (GradeTooLowException());
    return grade;
}

void    Form::setIsSigned()
{
    this->isSigned = true;
}

void    Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > getGradeSign())
    {
        std::cout << b.getName() << " couldn't sign " << getFormName() << " because grade is lower" << std::endl;
        throw(GradeTooLowException());
    }
    setIsSigned();
    std::cout << b.getName() << " signed " << getFormName() << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Form& b)
{
    out << b.getFormName() << ", Form grade for signing: " << b.getGradeSign() << "\nGrade for exec: " << b.getGradeExect();
    return out;
}