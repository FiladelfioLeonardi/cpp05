/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tester01.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 15:06:59 by fefo              #+#    #+#             */
/*   Updated: 2026/05/27 16:51:52 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_HPP
# define TESTER_HPP

#include "../../ex01/Bureaucrat.hpp"
#include "../../ex01/Form.hpp"
#include "../common.hpp"
#include <sstream>

int MainHub01(Bureaucrat* b, Form* f);
Bureaucrat makeBureaucrat();
Form makeForm();
Form changeFormGrade(Form* f, int grade);
void changeGrade(Bureaucrat* b);


#endif