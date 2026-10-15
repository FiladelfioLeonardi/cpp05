/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 20:59:00 by fileonar              #+#    #+#             */
/*   Updated: 2026/10/15 20:59:00 by fileonar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    
	try {
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("intern", 150);

			std::cout << "==== Test 1: ShrubberyCreationForm ====" << std::endl;
			try {
				ShrubberyCreationForm tree("Tree");
				boss.signForm(tree);
				boss.executeForm(tree); // Should create the Baum_shrubbery file
			} catch (const std::exception& e) {
				std::cout << e.what() << std::endl;
			}

			std::cout << "\n==== Test 2: RobotomyRequestForm ====" << std::endl;
			try {
				RobotomyRequestForm robot("Magyar Robot");
				boss.signForm(robot);
				boss.executeForm(robot); // Drilling noise and 50% success
				boss.executeForm(robot); // Once more
			} catch (const std::exception& e) {
				std::cout << e.what() << std::endl;
			}

			std::cout << "\n==== Test 3: PresidentialPardonForm ====" << std::endl;
			try {
				PresidentialPardonForm pardon("Mr President");
				boss.signForm(pardon);
				boss.executeForm(pardon);
			} catch (const std::exception& e) {
				std::cout << e.what() << std::endl;
			}

			std::cout << "\n==== Test 4: Permission check (Error) ====" << std::endl;
			try {
				PresidentialPardonForm pardon("everyone");
				// Try to execute without a signature
				intern.executeForm(pardon);

				// Try to sign with a grade that is too low
				intern.signForm(pardon);
				intern.executeForm(pardon);
			} catch (const std::exception& e) {
				std::cout << "Main caught: " << e.what() << std::endl;
			}

			std::cout << "\n==== Test 5: Can sign but cannot execute ====" << std::endl;
			try {
				Bureaucrat mid("50 Cent", 50);
				RobotomyRequestForm mrRobot("mrRobot");
				mid.signForm(mrRobot);
				mid.executeForm(mrRobot);
			} catch (const std::exception& e) {
				std::cout << e.what() << std::endl;
			}
			
		} catch (const std::exception& e) {
			std::cout << "Fatal: " << e.what() << std::endl;
			return 1;
		}
		
	return 0;
}
