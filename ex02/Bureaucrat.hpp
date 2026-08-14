/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:20:56 by fefo              #+#    #+#             */
/*   Updated: 2026/05/26 14:54:04 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <unistd.h>

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int final_grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        ~Bureaucrat();
        const std::string& getName() const;
        int     getGrade() const;
        void    setGrade(int grade);
        int     checkGrade(int grade);
        void    incrementGrade(int increment);
        void    decrementGrade(int decrement);
        void    signForm(Form& form);
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade too low";
                }
        };
        
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "Grade too high";
                }
        };
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif