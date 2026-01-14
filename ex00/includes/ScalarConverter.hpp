/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:39:48 by nseon             #+#    #+#             */
/*   Updated: 2026/01/07 17:32:08 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

#define C_PRINT " !\"#$%&'()*+,-./:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~"

#define NUMS "0123456789"

enum Type {
	NONE,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &m);
		ScalarConverter &operator=(ScalarConverter const &m);
		~ScalarConverter();
	public:
		static void convert(std::string input);
};
