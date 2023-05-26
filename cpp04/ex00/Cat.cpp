/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:48:31 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 11:26:53 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat created\n";
}

Cat::~Cat(void)
{
	std::cout << "Cat destroyed\n";
}

Cat::Cat(const Cat &copy) : Animal("Cat"){
	this->_type = copy._type;
}

Cat & Cat::operator=(const Cat &copy){
	if (&copy != this)
	{
		this->_type = copy._type;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow Meow\n";
}
