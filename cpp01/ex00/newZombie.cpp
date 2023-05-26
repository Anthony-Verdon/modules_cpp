/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:43:15 by averdon           #+#    #+#             */
/*   Updated: 2023/03/15 14:50:39 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string	name)
{
	Zombie	*new_zombie;

	new_zombie = new(Zombie);
	new_zombie->setName(name);
	return (new_zombie);
}
