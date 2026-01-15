/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:34:11 by nseon             #+#    #+#             */
/*   Updated: 2026/01/15 09:55:29 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <stdlib.h>

#include "ScalarConverter.hpp"
#include "parse.hpp"
#include "print.hpp"

/*=========================================*/
/*================= NONE ==================*/
/*=========================================*/

void print_none()
{
	std::cout << "char: NONE\nint: NONE\nfloat: NONE\ndouble: NONE" << std::endl;
}

/*=========================================*/
/*============== PRINT_TYPE ===============*/
/*=========================================*/

static void print_char(std::string const &input, int i)
{
	char c = static_cast<char>(i);
	
	std::cout << "char: ";
	if (isNanOrInff(input))
		std::cout << "impossible";
	else if (33 <= i && i <= 126)
		std::cout << c;
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
}

static void print_int(std::string const &input, int i)
{	
	std::cout << "int: ";
	if (isNanOrInff(input))
		std::cout << "impossible";
	else
		std::cout << i;
	std::cout << std::endl;
}

static void print_float(std::string const &input, float f)
{
	std::cout << "float: ";
	if (input == "-inff" || input == "-inf")
		std::cout << std::numeric_limits<float>::infinity() * -1;
	else if (input == "+inff" || input == "+inf")
		std::cout << std::numeric_limits<float>::infinity();
	else if (input == "nanf" || input == "nan")
		std::cout << std::numeric_limits<float>::quiet_NaN();
	else
		std::cout << f;
	std::cout << 'f' << std::endl;
}

static void print_double(std::string const &input, double d)
{
	std::cout << "double: ";
	if (input == "-inff" || input == "-inf")
		std::cout << std::numeric_limits<double>::infinity() * -1;
	else if (input == "+inff" || input == "+inf")
		std::cout << std::numeric_limits<double>::infinity();
	else if (input == "nanf" || input == "nan")
		std::cout << std::numeric_limits<double>::quiet_NaN();
	else
		std::cout << d;
	std::cout << std::endl;
}

/*==============================================*/
/*============== PRINT_FROM_TYPE ===============*/
/*==============================================*/

void print_from_char(std::string const &input, char c)
{
	int i = static_cast<int>(c);
	
	print_char(input, c);
	print_int(input, i);
	print_float(input, static_cast<float>(i));
	print_double(input, static_cast<double>(i));
}

void print_from_int(std::string const &input, int i)
{
	if (std::numeric_limits<char>::min() <= i && i <= std::numeric_limits<char>::max())
		print_char(input, i);
	else
		std::cout << "char: Impossible (Overflow)" << std::endl;
	print_int(input, i);
	print_float(input, static_cast<float>(i));
	print_double(input, static_cast<double>(i));
}

void print_from_float(std::string const &input, float f)
{
	int i = static_cast<int>(f);
	
	if (std::numeric_limits<char>::min() <= f && f <= std::numeric_limits<char>::max())
		print_char(input, i);
	else
		std::cout << "char: Impossible (Overflow)" << std::endl;
	if (static_cast<float>(std::numeric_limits<int>::min()) <= f && f <= static_cast<float>(std::numeric_limits<int>::max()))
		print_int(input, i);
	else
		std::cout << "int: Impossible (Overflow)" << std::endl;
	print_float(input, f);
	print_double(input, static_cast<double>(f));
}

void print_from_double(std::string const &input, double d)
{	
	int i = static_cast<int>(d);

	if (std::numeric_limits<char>::min() <= d && d <= std::numeric_limits<char>::max())
		print_char(input, i);
	else
		std::cout << "char: Impossible (Overflow)" << std::endl;
	if (std::numeric_limits<int>::min() <= d && d <= std::numeric_limits<int>::max())
		print_int(input, i);
	else
		std::cout << "int: Impossible (Overflow)" << std::endl;
	if ((static_cast<double>(std::numeric_limits<float>::min()) <= d && d <= static_cast<double>(std::numeric_limits<float>::max())) || isNanOrInff(input))
		print_float(input, static_cast<float>(d));
	else
		std::cout << "float: Impossible (Overflow)" << std::endl;
	print_double(input, d);
}
