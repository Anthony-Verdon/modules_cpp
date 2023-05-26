/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:43:36 by averdon           #+#    #+#             */
/*   Updated: 2023/03/14 11:01:16 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		
		void announce(void);
		void setName(std::string name);
	private:
		std::string _name;

};

Zombie	*newZombie(std::string name);
void 	randomChump(std::string name);
#endif
