/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:49:01 by averdon           #+#    #+#             */
/*   Updated: 2023/03/15 15:17:34 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <sstream>

class PhoneBook
{
	public:
		void	display_directory(int nb_register);
		void	display_one_contact(int nb_register);
		void	set_contact(int index, Contact new_contact);
		Contact	get_contact(int index);
	private:
		Contact	_directory[8];
};
#endif
