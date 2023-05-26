/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:43:28 by averdon           #+#    #+#             */
/*   Updated: 2023/03/15 14:50:35 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	randomChump(std::string	name)
{
	Zombie	new_zombie;

	new_zombie.setName(name);
	new_zombie.announce();
}
