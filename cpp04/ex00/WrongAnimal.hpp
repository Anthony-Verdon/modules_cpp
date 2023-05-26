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

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	 public:
		WrongAnimal(void);
		WrongAnimal(const std::string type);
		virtual ~WrongAnimal(void);
		WrongAnimal (const WrongAnimal &copy);
		WrongAnimal &operator=(const WrongAnimal&);

		std::string getType(void) const;
		void		makeSound(void) const;

	 protected:
		std::string _type;
		
};

#endif
