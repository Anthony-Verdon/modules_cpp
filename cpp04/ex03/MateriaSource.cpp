/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:42:17 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 14:16:50 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource(void){
	for (int i = 0; i < 4; i++)
		this->_source[i] = NULL;
}

MateriaSource::~MateriaSource(void){
	for (int i = 0; i < 4; i++)
	{
		if (this->_source[i])
		{
			delete (this->_source[i]);
			this->_source[i] = NULL;
		}
	}
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._source[i])
			this->_source[i] = copy._source[i]->clone();
		else
			this->_source[i] = NULL;
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource &copy){
	if (&copy != this)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_source[i])
				delete (this->_source[i]);
			if (copy._source[i])
				this->_source[i] = copy._source[i]->clone();
			else
				this->_source[i] = NULL;
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *Materia)
{
	for (int index = 0; index < 4; index++)
	{
		if (this->_source[index] == NULL)
		{
			this->_source[index] = Materia;
			return;
		}
	}
	std::cout << "this MateriaSource already know 4 Materias\n";
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	int	i;
	for (i = 0; i < 4; i++)
	{
		if (this->_source[i] && this->_source[i]->getType() == type)
			break ;
	}
	if (i == 4)
	{
		std::cout << "Unknown Materia\n";
		return (NULL);
	}
	else
		return (this->_source[i]->clone());
}

AMateria	**MateriaSource::getMateria()
{
	return (this->_source);
}
