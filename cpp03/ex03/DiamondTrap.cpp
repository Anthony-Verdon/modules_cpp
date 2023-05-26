/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:48:09 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 13:15:21 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Unknown_clap_name"), FragTrap(), ScavTrap()
{
	this->_name = "Unknown";
	this->_HitPoints = this->FragTrap::_HitPoints;
	this->_EnergyPoints = this->ScavTrap::_EnergyPoints;
	this->_AttackDamage = this->FragTrap::_AttackDamage;
	std::cout << "DiamondTrap " << this->_name << " created\n";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) 
{
	this->ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_HitPoints = this->FragTrap::_HitPoints;
	this->_EnergyPoints = this->ScavTrap::_EnergyPoints;
	this->_AttackDamage = this->FragTrap::_AttackDamage;
	std::cout << "DiamondTrap " << this->_name << " created\n";
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_name << " destroyed\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy._name + "_clap_name"), FragTrap(copy._name), ScavTrap(copy._name){
	this->_name = copy._name;
	this->_HitPoints = copy._HitPoints;
	this->_EnergyPoints = copy._EnergyPoints;
	this->_AttackDamage = copy._AttackDamage;
	std::cout << "DiamondTrap " << this->_name << " created from a copy\n";
}

DiamondTrap & DiamondTrap::operator=(const DiamondTrap &copy){
	if (&copy != this)
	{
		this->ClapTrap::_name = copy._name + "_clap_name";
		this->_name = copy._name;
		this->_HitPoints = copy._HitPoints;
		this->_EnergyPoints = copy._EnergyPoints;
		this->_AttackDamage = copy._AttackDamage;
		std::cout << "DiamondTrap " << this->_name << " created from a copy\n";
	}
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << this->_name << " The DiamondTrap and his ClapTrap " << this->ClapTrap::_name << "\n";
}
