/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:25:29 by averdon           #+#    #+#             */
/*   Updated: 2023/03/02 19:16:55 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap instance1;
	FragTrap instance2("Bobby");
	FragTrap instance3(instance2);
	FragTrap instance4 = instance3;


	std::cout << "\n[ATTACK]\n";
	for (int i = 0; i < 101; i++)
		instance2.attack("Ybbob");
	std::cout << "\n[BE REPAIRED]\n";
	for (int i = 0; i < 101; i++)
		instance3.beRepaired(10);
	std::cout << "\n[HIGH FIVES]\n";
	for (int i = 0; i < 101; i++)
		instance1.highFivesGuys();
	std::cout << "\n[CLAPTRAP DIED]\n";
	instance4.takeDamage(100);
	instance4.beRepaired(10);
	std::cout << "\n";
	return (0);
}
