/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 21:04:00 by fileonar              #+#    #+#             */
/*   Updated: 2026/10/15 21:04:00 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (!getIsSigned())
        throw NotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();
    std::cout << "* drilling noises *" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy of " << target << " failed" << std::endl;
}
