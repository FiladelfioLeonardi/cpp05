/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 21:04:00 by fileonar              #+#    #+#             */
/*   Updated: 2026/10/15 21:04:00 by fileonar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target;

    public:
        RobotomyRequestForm(const std::string& target);
        virtual ~RobotomyRequestForm();
        virtual void execute(Bureaucrat const& executor) const;
};

#endif
