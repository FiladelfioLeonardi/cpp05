/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tester02.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:06:59 by fefo              #+#    #+#             */
/*   Updated: 2026/05/27 22:24:51 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
# define TESTER_HPP

#include "../../ex02/Bureaucrat.hpp"
#include "../../ex02/Form.hpp"
#include "../../ex02/AForm.hpp"
#include "../common.hpp"
#include <sstream>

int MainHub02(Bureaucrat* b, Form* f, AForm* af);
Bureaucrat makeBureaucrat();
Form makeForm();
Form changeFormGrade(Form* f, int grade);
void changeGrade(Bureaucrat* b);


#endif