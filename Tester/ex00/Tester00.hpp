/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tester00.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 15:49:30 by fefo              #+#    #+#             */
/*   Updated: 2026/08/14 09:45:16 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER00_HPP
# define TESTER00_HPP

#include "../../ex00/Bureaucrat.hpp"
#include "../common.hpp"
// #include <sstream>
// #include <iostream>
#include <string>
// #include <stdexcept>
#include <unistd.h>

int mainHub00();
Bureaucrat  makeBureaucrat();
void changeGrade(Bureaucrat* current);

#endif