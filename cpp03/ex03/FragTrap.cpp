/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:57:22 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 13:15:34 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	std::cout << "FragTrap " << this->_name << " created\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_HitPoints = 100;
	this->_EnergyPoints = 100;
	this->_AttackDamage = 30;
	std::cout << "FragTrap " << this->_name << " created\n";
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " destroyed\n";
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy._name){
	this->_name = copy._name;
	this->_HitPoints = copy._HitPoints;
	this->_EnergyPoints = copy._EnergyPoints;
	this->_AttackDamage = copy._AttackDamage;
	std::cout << "FragTrap " << this->_name << " created from a copy\n";
}

FragTrap & FragTrap::operator=(const FragTrap &copy){
	if (&copy != this)
	{
		this->_name = copy._name;
		this->_HitPoints = copy._HitPoints;
		this->_EnergyPoints = copy._EnergyPoints;
		this->_AttackDamage = copy._AttackDamage;
		std::cout << "FragTrap " << this->_name << " created from a copy\n";
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_HitPoints > 0 && this->_EnergyPoints > 0)
	{
		std::cout << "FragTrap " << this->_name << " want to do a High Fives \n";
		this->_EnergyPoints -= 1;
	}
	else if (this->_HitPoints <= 0)
		std::cout << "FragTrap " << this->_name << " has no HitPoints to to do a High Fives\n";
	else if (this->_EnergyPoints <= 0)
		std::cout << "FragTrap " << this->_name << " has no EnergyPoints to to do a High Fives\n";
}
