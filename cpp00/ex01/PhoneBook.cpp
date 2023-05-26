/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:48:47 by averdon           #+#    #+#             */
/*   Updated: 2023/03/15 15:21:16 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::set_contact(int index, Contact new_contact)
{
	this->_directory[index] = new_contact;
}

Contact	PhoneBook::get_contact(int index)
{
	return (this->_directory[index]);
}

void	display_information(std::string information)
{
	std::cout << std::setw(10);
	if (information.length() > 10)
	{
		std::cout << information.substr(0, 9);
		std::cout << ".";
	}
	else
		std::cout << information;
	std::cout << "|";
}

void	index_bar(void)
{
	std::cout << "\n---------------------------------------------\n|";
	display_information("index");
	display_information("first name");
	display_information("last name");
	display_information("nickname");
	std::cout << "\n---------------------------------------------\n";
}

void	PhoneBook::display_directory(int nb_register)
{
	int					x;
	std::stringstream	index;

	index_bar();
	x = 0;
	while (x < 8)
	{
		std::cout << "|";
		index.str("");
		index << x;
		display_information(index.str());
		if (x < nb_register)
		{
			display_information(this->get_contact(x).getFirstName());
			display_information(this->get_contact(x).getLastName());
			display_information(this->get_contact(x).getNickname());
		}
		else
		{
			display_information("");
			display_information("");
			display_information("");
		}
		std::cout << "\n---------------------------------------------\n";
		x++;
	}
}

void	PhoneBook::display_one_contact(int nb_register)
{
	std::string			input;
	int					index;
	const std::string	all_number = "01234567";
	
	std::cout << "ON WHICH CONTACT DO YOU WANT MORE INFORMATIONS\n";
	std::getline(std::cin, input);
	if (input.compare("") != 0 && (all_number.find(input) != std::string::npos
		&& (int)all_number.find(input) < nb_register))
	{
		std::istringstream(input) >> index;
		std::cout << this->get_contact(index).getFirstName() << "\n";
		std::cout << this->get_contact(index).getLastName() << "\n";
		std::cout << this->get_contact(index).getNickname() << "\n";
		std::cout << this->get_contact(index).getPhoneNumber() << "\n";
		std::cout << this->get_contact(index).getDarkestSecret() << "\n";
	}
	else
		std::cout << "COULDN'T FIND THIS INDEX\n";
}
