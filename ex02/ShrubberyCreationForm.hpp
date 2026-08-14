/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 21:38:45 by fefo              #+#    #+#             */
/*   Updated: 2026/05/27 21:46:29 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {    
    private:
        std::string     target;
    public:
    ShrubberyCreationForm(std::string const& target);
    virtual ~ShrubberyCreationForm();
    virtual void execute(Bureaucrat const& executor) const;
};

#endif