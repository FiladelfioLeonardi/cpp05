/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 21:04:00 by fileonar              #+#    #+#             */
/*   Updated: 2026/10/15 21:04:00 by fileonar              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;

    public:
        PresidentialPardonForm(const std::string& target);
        virtual ~PresidentialPardonForm();
        virtual void execute(Bureaucrat const& executor) const;
};

#endif
