/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefo <fefo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:09:03 by fefo              #+#    #+#             */
/*   Updated: 2026/08/14 10:22:49 by fefo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"


void print_msg(const std::string& msg)
{
    for(char c : msg)
    {
        std::cout << c << std::flush;
        usleep(10000);
    }
    usleep(20000);
}

bool isNumber(const std::string& s)
{
    if (s.empty())
        return false;
    for (unsigned char c : s)
    {
        if (!std::isdigit(c))
            return false;
    }
    return true;
}

int readInt(const std::string& prompt)
{
    std::string line;
    while (1)
    {
        print_msg(prompt);
        if (!std::getline(std::cin, line))
            continue;
        if (!isNumber(line))
        {
            print_msg("Invalid input, digits only\n");
            continue;
        }
        std::istringstream iss(line);
        int value;
        iss >> value;
        return value;
    }
}