/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:47:51 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 11:26:47 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog created\n";
}

Dog::~Dog(void)
{
	std::cout << "Dog destroyed\n";
}

Dog::Dog(const Dog &copy) : Animal("Dog"){
	this->_type = copy._type;
}

Dog & Dog::operator=(const Dog &copy){
	if (&copy != this)
	{
		this->_type = copy._type;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark Bark Bark\n";
}
