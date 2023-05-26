/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:23:18 by averdon           #+#    #+#             */
/*   Updated: 2023/03/15 14:51:26 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		i;
	int		N;
	Zombie	*horde;

	i = 0;
	N = 5;
	horde = zombieHorde(N, "Bob");
	if (!horde)
		return (1);
	while (i < N)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return (0);
}
