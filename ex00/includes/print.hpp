/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 17:34:00 by nseon             #+#    #+#             */
/*   Updated: 2026/01/15 09:56:09 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

void print_none();
void print_from_int(std::string const &input, int i);
void print_from_char(std::string const &input, char c);
void print_from_float(std::string const &input, float f);
void print_from_double(std::string const &input, double d);
