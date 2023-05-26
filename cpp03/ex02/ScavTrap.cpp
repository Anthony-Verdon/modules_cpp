/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:57:22 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 13:14:52 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " created\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 50;
	this->_AttackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " created\n";
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " destroyed\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy._name)
{
	this->_name = copy._name;
	this->_HitPoints = copy._HitPoints;
	this->_EnergyPoints = copy._EnergyPoints;
	this->_AttackDamage = copy._AttackDamage;
	this->_inGuardGate = copy._inGuardGate;
	std::cout << "ScavTrap " << this->_name << " created from a copy\n";
}

ScavTrap & ScavTrap::operator=(const ScavTrap &copy){
	if (&copy != this)
	{
		this->_name = copy._name;
		this->_HitPoints = copy._HitPoints;
		this->_EnergyPoints = copy._EnergyPoints;
		this->_AttackDamage = copy._AttackDamage;
		this->_inGuardGate = copy._inGuardGate;
		std::cout << "ScavTrap " << this->_name << " created from a copy\n";
	}
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_HitPoints > 0 && this->_EnergyPoints > 0)
	{
		if (this->_inGuardGate == false)
		{
			std::cout << "ScavTrap " << this->_name << " attacks " << target;
			std::cout << ", causing " << this->_AttackDamage << " points of damage\n";
			this->_EnergyPoints -= 1;
		}
		else
			std::cout << "ScavTrap " << this->_name << " can't attack in Gate Keeper mode\n";
	}
	else if (this->_HitPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " has no HitPoints to attack\n";
	else if (this->_EnergyPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " has no EnergyPoints to attack\n";
}

void	ScavTrap::guardGate(void)
{
	if (this->_HitPoints > 0 && this->_EnergyPoints > 0)
	{
		if (this->_inGuardGate)
		{
			std::cout << "ScavTrap " << this->_name << " quitted Gate Keeper mode\n";
			this->_EnergyPoints -= 1;
			this->_inGuardGate = false;
		}
		else
		{
			std::cout << "ScavTrap " << this->_name << " entered Gate Keeper mode\n";
			this->_EnergyPoints -= 1;
			this->_inGuardGate = true;
		}
	}
	else if (this->_HitPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " has no HitPoints to enter Gate Keeper mode\n";
	else if (this->_EnergyPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " has no EnergyPoints to enter Gate Keeper mode\n";
}
