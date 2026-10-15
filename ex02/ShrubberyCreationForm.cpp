/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 21:42:12 by fefo              #+#    #+#             */
/*   Updated: 2026/10/15 21:18:45 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& t)
: AForm("ShrubberyCreationForm", 145, 137), target(t) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
  if (!getIsSigned()) throw NotSignedException();
  if (executor.getGrade() > getExecGrade()) throw GradeTooLowException();

  const std::string filename = target + "_shrubbery";
  std::ofstream output(filename.c_str());
  if (!output)
    throw std::runtime_error("Could not open " + filename);
  output << "       /\\\n"
         << "      /  \\\n"
         << "      /  \\\n"
         << "     /____\\\n"
         << "       ||\n"
         << "       ||\n";
}