/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractAnimal.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:45:57 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 13:46:17 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AbstractAnimal.hpp"

AbstractAnimal::AbstractAnimal(void)
{
	std::cout << "Animal created\n";
}

AbstractAnimal::AbstractAnimal(const std::string type)
{
	std::cout << "Animal of type " << type << " created\n";
	this->_type = type;
}

AbstractAnimal::~AbstractAnimal(void)
{
	std::cout << "Animal destroyed\n";
}

AbstractAnimal::AbstractAnimal(const AbstractAnimal &copy){
	this->_type = copy._type;
}

AbstractAnimal & AbstractAnimal::operator=(const AbstractAnimal &copy){
	if (&copy != this)
	{
		this->_type = copy._type;
	}
	return (*this);
}

std::string	AbstractAnimal::getType(void) const
{
	return (this->_type);
}

void	AbstractAnimal::makeSound(void) const
{
	std::cout << "unrecognizable growl\n";
}
