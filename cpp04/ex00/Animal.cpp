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

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal created\n";
	this->_type = "Unknown";
}

Animal::Animal(const std::string type)
{
	std::cout << "Animal of type " << type << " created\n";
	this->_type = type;
}

Animal::~Animal(void)
{
	std::cout << "Animal destroyed\n";
}

Animal::Animal(const Animal &copy){
	this->_type = copy._type;
}

Animal & Animal::operator=(const Animal &copy){
	if (&copy != this)
	{
		this->_type = copy._type;
	}
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "unrecognizable growl\n";
}
