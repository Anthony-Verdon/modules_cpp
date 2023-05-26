/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:43:49 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 14:16:09 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void){
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name){
	this->_name = name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	
}

Character::~Character(void){
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete (this->_inventory[i]);
			this->_inventory[i] = NULL;
		}	
	}
}

Character::Character(const Character &copy){
	this->_name = copy._name;
	for (int i = 0; i < 4; i++)
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
}

Character & Character::operator=(const Character &copy){
	if (&copy != this)
	{
		this->_name = copy._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
			{
				delete (this->_inventory[i]);
				this->_inventory[i] = NULL;
			}	
			if (copy._inventory[i])
				this->_inventory[i] = copy._inventory[i]->clone();
		}
	}
	return (*this);
}

std::string	const & Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria *Materia)
{
	for (int index = 0; index < 4; index++)
	{
		if (this->_inventory[index] == NULL)
		{
			this->_inventory[index] = Materia;
			return ;
		}
	}
	std::cout << "no inventory place\n";
}

void	Character::unequip(int	index)
{
	if (index < 0 || index >= 4)
		this->_inventory[index] = NULL;
}

void	Character::use(int	index, ICharacter & target)
{
	if (index < 0 || index >= 4)
		return ;
	if (this->_inventory[index])
		this->_inventory[index]->use(target);
}

AMateria	**Character::getInventory()
{
	return (this->_inventory);
}
