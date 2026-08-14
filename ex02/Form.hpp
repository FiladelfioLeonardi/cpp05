/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 15:39:26 by fefo              #+#    #+#             */
/*   Updated: 2026/05/27 16:54:20 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool  isSigned = false;
        const int gradeSign;
        const int gradeExec;
    public:
        Form(const std::string& name, int gradeSignValue, int gradeExecValue);
        Form();
        ~Form();

        const std::string& getFormName() const { return name; };
        bool               getIsSigned() const { return isSigned; };
        int                getGradeSign() const {return gradeSign; };
        int                getGradeExect() const { return gradeExec; };
        int                checkGrade(int grade);
        void               setIsSigned();
        void               beSigned(const Bureaucrat& b);
        
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




#endif