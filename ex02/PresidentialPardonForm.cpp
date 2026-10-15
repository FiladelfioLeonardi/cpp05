/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 21:04:00 by fileonar              #+#    #+#             */
/*   Updated: 2026/10/15 21:04:00 by fileonar              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (!getIsSigned())
        throw NotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox"
        << std::endl;
}
