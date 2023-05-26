/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:27:22 by averdon           #+#    #+#             */
/*   Updated: 2023/02/28 15:20:03 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA created\n";
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA destroyed\n";
}

void HumanA::attack(void)
{
	std::cout << this->_name << "attack with their " << this->_weapon.getType() << "\n";
}

