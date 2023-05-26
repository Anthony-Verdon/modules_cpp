/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:47:51 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 13:48:16 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : AbstractAnimal("Dog")
{
	std::cout << "Dog created\n";
	this->_brain = new Brain();
}

Dog::~Dog(void)
{
	std::cout << "Dog destroyed\n";
	delete this->_brain;
}

Dog::Dog(const Dog &copy) : AbstractAnimal("Dog")
{
	this->_type = copy._type;
	this->_brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->_brain->setIdea(i, copy._brain->getIdea(i));
}

Dog & Dog::operator=(const Dog &copy){
	if (&copy != this)
	{
		this->_type = copy._type;
		this->_brain = new Brain();
		for (int i = 0; i < 100; i++)
			this->_brain->setIdea(i, copy._brain->getIdea(i));

	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark Bark Bark\n";
}
