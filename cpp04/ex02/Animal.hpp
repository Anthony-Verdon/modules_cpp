/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:44:37 by averdon           #+#    #+#             */
/*   Updated: 2023/03/03 19:36:30 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	 public:
		Animal(void);
		Animal(const std::string type);
		virtual ~Animal(void);
		Animal (const Animal &copy);
		Animal &operator=(const Animal&);

		std::string 		getType(void) const;
		virtual	void		makeSound(void) const;

	 protected:
		std::string _type;
		
};

#endif
