/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseon <nseon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:38:21 by nseon             #+#    #+#             */
/*   Updated: 2026/01/15 09:29:09 by nseon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "Serializer.hpp"
#include "data.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(Serializer const &)
{}

Serializer &Serializer::operator=(Serializer const &)
{
	return (*this);
}

Serializer::~Serializer()
{}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
