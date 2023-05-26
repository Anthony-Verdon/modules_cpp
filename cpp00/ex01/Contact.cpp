/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:48:56 by averdon           #+#    #+#             */
/*   Updated: 2023/03/07 10:37:52 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName(void)
{
	return (this->_firstName);
}

std::string Contact::getLastName(void)
{
	return (this->_lastName);
}

std::string Contact::getNickname(void)
{
	return (this->_nickname);
}

std::string Contact::getPhoneNumber(void)
{
	return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void)
{
	return (this->_darkestSecret);
}

void	add_one_informations(std::string information, std::string *category)
{
	std::cout << information << ": ";
	while (std::getline(std::cin, *category))
	{
		if (*category != "")
			break ;
		std::cout << "error, please rewrite ";
		std::cout << information << ": ";
	}
}
Contact Contact::create(void)
{
	Contact 	new_contact;

	add_one_informations("first name", &new_contact._firstName);
	add_one_informations("last name", &new_contact._lastName);
	add_one_informations("nickname", &new_contact._nickname);
	add_one_informations("phone number", &new_contact._phoneNumber);
	add_one_informations("darkest secret", &new_contact._darkestSecret);
	return (new_contact);
}
