/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:51:01 by averdon           #+#    #+#             */
/*   Updated: 2023/03/14 18:36:03 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){
}

Serializer::~Serializer(){
}

Serializer::Serializer(const Serializer &copy){
	*this = copy;
}

Serializer & Serializer::operator=(const Serializer &copy){
	if (&copy != this)
	{

	}
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
