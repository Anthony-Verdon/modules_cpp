/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:26:20 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 11:14:44 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->_name = "Unknown";
	this->_HitPoints = 10;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " created\n";
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_HitPoints = 10;
	this->_EnergyPoints = 10;
	this->_AttackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " created\n";
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " destroyed\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy){
	this->_name = copy._name;
	this->_HitPoints = copy._HitPoints;
	this->_EnergyPoints = copy._EnergyPoints;
	this->_AttackDamage = copy._AttackDamage;
	std::cout << "ClapTrap " << this->_name << " created from a copy\n";
}

ClapTrap & ClapTrap::operator=(const ClapTrap &copy){
	if (&copy != this)
	{
		this->_name = copy._name;
		this->_HitPoints = copy._HitPoints;
		this->_EnergyPoints = copy._EnergyPoints;
		this->_AttackDamage = copy._AttackDamage;
	std::cout << "ClapTrap " << this->_name << " created from a copy\n";
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_HitPoints > 0 && this->_EnergyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_AttackDamage << " points of damage\n";
		this->_EnergyPoints -= 1;
	}
	else if (this->_HitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " has no HitPoints to attack\n";
	else if (this->_EnergyPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " has no EnergyPoints to attack\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " lost " << amount << " points of hits\n";
	this->_HitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_HitPoints > 0 && this->_EnergyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " repaired " << amount << " points of hits\n";
		this->_EnergyPoints -= 1;
		this->_HitPoints += amount;
	}
	else if (this->_HitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " has no HitPoints to be repaired\n";
	else if (this->_EnergyPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " has no EnergyPoints to be repaired\n";
}
