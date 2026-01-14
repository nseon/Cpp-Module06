/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:30:45 by nseon             #+#    #+#             */
/*   Updated: 2026/01/14 14:55:25 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "ScalarConverter.hpp"

// FPL stand for Float Pseudo Literals
static bool isFPL(std::string input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return (true);
	return (false);
}

// DPL stand for Double Pseudo Literals
static bool isDPL(std::string input)
{
	if (input == "-inf" || input == "+inf" || input == "nan")
		return (true);
	return (false);
}

int detectType(std::string input)
{
	size_t i;

	if (input.length() == 1 && input.find_first_of(C_PRINT) != std::string::npos)
		return (CHAR);
	i = input.find_first_not_of(NUMS);
	if (i == 0 && input[i] == '-')
		i = input.find_first_not_of(NUMS, i + 1);
	if (i == std::string::npos)
		return (INT);
	if (input[i] == '.')
		i = input.find_first_not_of(NUMS, i + 1);
	if (i == std::string::npos || isDPL(input))
		return (DOUBLE);
	if (input[i] == 'f')
		i = input.find_first_not_of(NUMS, i + 1);
	if (i == std::string::npos || isFPL(input))
		return (FLOAT);
	return (NONE);
}

bool isNanOrInff(std::string input)
{
	if (input == "-inff" || input == "-inf" || input == "+inff" || input == "+inf" || input == "nanf" || input == "nan")
		return (1);
	return (0);
}
