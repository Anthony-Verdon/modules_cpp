/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:28:39 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 14:14:30 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("Unknown")
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::~AMateria(void)
{
}

AMateria::AMateria(const AMateria &copy)
{
	(void)copy;
}

AMateria & AMateria::operator=(const AMateria &copy)
{
	if (&copy != this)
	{

	}
	return (*this);
}

std::string const & AMateria::getType(void) const
{
	return (this->_type);
}
