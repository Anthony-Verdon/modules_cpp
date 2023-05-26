/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:15:40 by averdon           #+#    #+#             */
/*   Updated: 2023/03/15 15:25:45 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	choose_instructions(void)
{
	std::string	instructions;

	std::cout << "\nHERE IS YOUR OPTIONS :\n\n";
	std::cout << "ADD: REGISTER A NEW CONTACT\n";
	std::cout << "SEARCH: DISPLAY ALL YOUR CONTACTS\n";
	std::cout << "EXIT: EXIT THE PHONEBOOK\n";
}

int	main(void)
{
	std::string	instructions;
	PhoneBook	phone_book;
	Contact		contact;
	int			nb_register;

	std::cout << "WELCOME TO YOUR PHONEBOOK\n";
	nb_register = 0;
	choose_instructions();
	while (std::getline(std::cin, instructions))
	{
		if (instructions.compare("ADD") == 0)
		{
			phone_book.set_contact(nb_register % 8, contact.create());
			nb_register += 1;
		}
		else if (instructions.compare("SEARCH") == 0)
		{
			phone_book.display_directory(nb_register);
			phone_book.display_one_contact(nb_register);
		}
		else if (instructions.compare("EXIT") == 0)
			break ;
		else
			std::cout << "DIDN'T UNDERSTAND\n";
		choose_instructions();
	}
}
