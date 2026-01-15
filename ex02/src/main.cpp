/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:38:29 by nseon             #+#    #+#             */
/*   Updated: 2026/01/15 15:42:48 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static Base * generate(void)
{
	int random = std::rand() % 3;
	
	if (random == 0)
		return (new (A));
	if (random == 1)
		return (new (B));
	return (new (C));
}

static void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Base is of type A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Base is of type B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Base is of type C" << std::endl;
	else
		std::cout << "unrecognized type" << std::endl;
}

static void identify(Base& p)
{
	try {
		dynamic_cast<A &>(p);
		std::cout << "Base is of type A" << std::endl;
	}
	catch (...) {
		try {
			dynamic_cast<B &>(p);
			std::cout << "Base is of type B" << std::endl;
		}
		catch (...) {
			try {
				dynamic_cast<C &>(p);
				std::cout << "Base is of type C" << std::endl;
			}
			catch (...) {
				std::cout << "unrecognized type" << std::endl;
			}
		}
	}
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Base *b1 = generate();
	Base *b2 = generate();
	Base &bref = *b2;
	
	identify(b1);
	identify(b2);
	identify(bref);
	return (0);
}
