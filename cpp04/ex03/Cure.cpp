/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:34:12 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 14:04:48 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
}

Cure::~Cure(void){
}

Cure::Cure(const Cure &copy) : AMateria(copy._type){
}

Cure & Cure::operator=(const Cure &copy){
	if (&copy != this)
	{
		this->~Cure();
		new(this) Cure(copy);
	}
	return (*this);
}

Cure*	Cure::clone(void) const
{
	return (new Cure);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals  " << target.getName() << " 's wounds *\n";
}
