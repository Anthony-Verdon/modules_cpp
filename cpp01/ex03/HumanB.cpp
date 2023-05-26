/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:36:50 by averdon           #+#    #+#             */
/*   Updated: 2023/03/14 12:48:28 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	std::cout << "HumanB created\n";
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB destroyed\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack(void)
{
	if (this->_weapon)
		std::cout << this->_name << " with their " << this->_weapon->getType() << "\n";
	else
		std::cout << this->_name << " can't attack without weapon\n"; 
}

