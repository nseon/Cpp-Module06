/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:46:47 by nseon             #+#    #+#             */
/*   Updated: 2026/01/15 09:33:14 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"
#include "data.hpp"

int main()
{
	Data d = {"test", 5};
	uintptr_t p = Serializer::serialize(&d);
	Data *d2 = Serializer::deserialize(p);
	
	std::cout << p << std::endl;
	std::cout << d2->name << " | " << d2->i << std::endl;
	return (0);
}
