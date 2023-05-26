/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:25:29 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 11:11:43 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap instance1;
	ClapTrap instance2("Bobby");
	ClapTrap instance3(instance2);
	ClapTrap instance4 = instance3;


	std::cout << "\n[ATTACK]\n";
	for (int i = 0; i < 11; i++)
		instance2.attack("Ybbob");
	std::cout << "\n[BE REPAIRED]\n";
	for (int i = 0; i < 11; i++)
		instance3.beRepaired(10);
	std::cout << "\n[CLAPTRAP DIED]\n";
	instance4.takeDamage(10);
	instance4.beRepaired(10);
	std::cout << "\n";
	return (0);
}
