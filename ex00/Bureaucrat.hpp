/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:20:56 by fefo              #+#    #+#             */
/*   Updated: 2026/05/27 21:32:26 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

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
    int getGrade() const;
    void setGrade(int grade);
    int checkGrade(int grade);
    void incrementGrade(int increment);
    void decrementGrade(int decrement);
    class GradeTooLowException : public std::exception //inherit from the exception library
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