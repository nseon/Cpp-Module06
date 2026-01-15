/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:49:56 by nseon             #+#    #+#             */
/*   Updated: 2026/01/15 09:55:39 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <stdlib.h>

#include "ScalarConverter.hpp"
#include "parse.hpp"
#include "print.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const &)
{
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &)
{
	return (*this);
}

ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::convert(std::string const &input)
{
	int res = detectType(input);
	std::stringstream ss(input);
	
	if (res == NONE)
		print_none();
	else if (res == CHAR)
	{
		char c;
		ss >> c;
		if (ss.fail())
		{
			std::cout << "Char input is overflowed" << std::endl;
			return ;
		}
		print_from_char(input, c);
	}
	else if (res == INT)
	{
		int i;
		ss >> i;
		if (ss.fail())
		{
			std::cout << "Int input is overflowed" << std::endl;
			return ;
		}
		print_from_int(input, i);
	}
	else if (res == FLOAT)
	{
		float f;
		
		if (isNanOrInff(input))
			f = 0;
		else
			ss >> f;
		if (ss.fail())
		{
			std::cout << "Float input is overflowed" << std::endl;
			return ;
		}
		print_from_float(input, f);
	}
	else if (res == DOUBLE)
	{
		double d;
		
		if (isNanOrInff(input))
			d = 0;
		else
			ss >> d;
		if (ss.fail())
		{
			std::cout << "Double input is overflowed" << std::endl;
			return ;
		}
		print_from_double(input, d);
	}
}
