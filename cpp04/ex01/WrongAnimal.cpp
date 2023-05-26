/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:45:57 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 11:26:11 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal created\n";
	this->_type = "Unknown";
}

WrongAnimal::WrongAnimal(const std::string type)
{
	std::cout << "WrongAnimal of type " << type << " created\n";
	this->_type = type;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destroyed\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy){
	this->_type = copy._type;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &copy){
	if (&copy != this)
	{
		this->_type = copy._type;
	}
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "unrecognizable growl\n";
}
