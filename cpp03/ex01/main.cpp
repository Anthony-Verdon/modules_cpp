/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:25:29 by averdon           #+#    #+#             */
/*   Updated: 2023/03/02 18:37:12 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap instance1;
	ScavTrap instance2("Bobby");
	ScavTrap instance3(instance2);
	ScavTrap instance4 = instance3;


	std::cout << "\n[ATTACK]\n";
	for (int i = 0; i < 51; i++)
		instance2.attack("Ybbob");
	std::cout << "\n[BE REPAIRED]\n";
	for (int i = 0; i < 51; i++)
		instance3.beRepaired(10);
	std::cout << "\n[GUARD GATE]\n";
	for (int i = 0; i < 51; i++)
	{
		instance4.guardGate();
		instance4.attack("Yboob");
	}
	std::cout << "\n[SCAVTRAP DIED]\n";
	instance1.takeDamage(100);
	instance1.beRepaired(10);
	std::cout << "\n";
	return (0);
}
