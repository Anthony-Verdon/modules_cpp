/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractAnimal.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:44:37 by averdon           #+#    #+#             */
/*   Updated: 2023/03/04 17:43:56 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTANIMAL_HPP
# define ABSTRACTANIMAL_HPP

# include <iostream>

class AbstractAnimal
{
	 public:
		AbstractAnimal(void);
		AbstractAnimal(const std::string type);
		virtual ~AbstractAnimal(void);
		AbstractAnimal (const AbstractAnimal &copy);
		AbstractAnimal &operator=(const AbstractAnimal&);

		std::string 		getType(void) const;
		virtual	void		makeSound(void) const = 0;

	 protected:
		std::string _type;

	private:
		
};

#endif
