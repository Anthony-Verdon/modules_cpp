/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:48:31 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 13:47:59 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AbstractAnimal("Cat")
{
	std::cout << "Cat created\n";
	this->_brain = new Brain();
}

Cat::~Cat(void)
{
	std::cout << "Cat destroyed\n";
	delete this->_brain;
}

Cat::Cat(const Cat &copy) : AbstractAnimal("Cat")
{	
	this->_type = copy._type;
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(i, copy._brain->getIdea(i));
}

Cat & Cat::operator=(const Cat &copy){
	if (&copy != this)
	{
		this->_type = copy._type;
		this->_brain = new Brain();
		for (int i = 0; i < 100; i++)
			this->_brain->setIdea(i, copy._brain->getIdea(i));
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow Meow Meow\n";
}
