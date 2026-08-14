/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:09:31 by fefo              #+#    #+#             */
/*   Updated: 2026/08/14 10:22:23 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_HPP
# define COMMON_HPP

#include <string>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <termios.h>


template <typename T>
std::string to_str(const T& value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

void print_msg(const std::string& msg);
bool isNumber(const std::string& s);
int readInt(const std::string& prompt);

#endif