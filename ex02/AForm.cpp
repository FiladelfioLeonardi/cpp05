/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 20:01:10 by fefo              #+#    #+#             */
/*   Updated: 2026/05/27 23:11:54 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string const& name, int signGrade, int execGrade)
: name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}

const std::string& AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getSignGrade() const { return signGrade; }
int AForm::getExecGrade() const { return execGrade; }

AForm::~AForm() 
{    
}

void    AForm::setIsSigned()
{
    this->isSigned = true;
}

void AForm::beSigned(Bureaucrat const& b)
{
    if (b.getGrade() > signGrade)
        throw GradeTooLowException();
    setIsSigned();
}