/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 20:01:01 by fefo              #+#    #+#             */
/*   Updated: 2026/05/27 23:11:04 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <exception>
// #include "../Tester/ex02/Tester02.hpp"
#include "../Tester/common.hpp"
#include "Form.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        bool                isSigned;
        const int           signGrade;
        const int           execGrade;
    public:
        AForm(std::string const& name, int signGrade, int execGrade);
        virtual ~AForm();

        const std::string&   getName() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;
        bool                getIsSigned() const;
        void                setIsSigned();

        
        void beSigned(Bureaucrat const& b);

        virtual void execute(Bureaucrat const& executor) const = 0;
        
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw() { return "AForm: Grade too low"; }
        };
        
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw() { return "AForm: Grade too high"; }
        };
        
        class NotSignedException : public std::exception
        {
            public:
                const char* what() const throw() { return "AForm: Form not signed"; }
        };
};

// AForm    makeAForm();

#endif

