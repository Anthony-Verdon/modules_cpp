/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:33:05 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 14:07:47 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::~Ice(void){
}

Ice::Ice(const Ice &copy) : AMateria(copy._type)
{
	*this = copy;
}

Ice & Ice::operator=(const Ice &copy){
	if (&copy != this)
	{
		this->~Ice();
		new(this) Ice(copy);
	}
	return (*this);
}

Ice*	Ice::clone(void) const
{
	return (new Ice);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
