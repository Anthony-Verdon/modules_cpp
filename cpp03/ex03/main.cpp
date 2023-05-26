/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:25:29 by averdon           #+#    #+#             */
/*   Updated: 2023/03/03 14:03:13 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap instance1;
	DiamondTrap instance2("Bobby");
	DiamondTrap instance3(instance2);
	DiamondTrap instance4 = instance3;
	DiamondTrap instance5("Bobbette");


	std::cout << "\n[ATTACK]\n";
	for (int i = 0; i < 51; i++)
		instance2.attack("Ybbob");
	std::cout << "\n[BE REPAIRED]\n";
	for (int i = 0; i < 51; i++)
		instance5.beRepaired(10);
	std::cout << "\n[GUARD GATE]\n";
	for (int i = 0; i < 51; i++)
	{
		instance3.guardGate();
		instance3.attack("Yboob");
	}
	std::cout << "\n[HIGH FIVES]\n";
	for (int i = 0; i < 51; i++)
		instance1.highFivesGuys();
	std::cout << "\n[CLAPTRAP DIED]\n";
	instance4.takeDamage(100);
	instance4.beRepaired(10);
	std::cout << "\n";
	return (0);
}
