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

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat created\n";
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destroyed\n";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal("WrongCat"){
	this->_type = copy._type;
}

WrongCat & WrongCat::operator=(const WrongCat &copy){
	if (&copy != this)
	{
		this->_type = copy._type;
	}
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow Meow Meow\n";
}
