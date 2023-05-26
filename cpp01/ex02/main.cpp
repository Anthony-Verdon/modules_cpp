/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <averdon@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:47:36 by averdon           #+#    #+#             */
/*   Updated: 2023/02/22 18:12:10 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string	stringBASIC;
	std::string	*stringPTR;
	std::string	&stringREF = stringBASIC;

	stringBASIC = "HI THIS IS BRAIN";
	stringPTR = &stringBASIC;

	std::cout << &stringBASIC << "\n";
	std::cout << stringPTR << "\n";
	std::cout << &stringREF << "\n";
	
	std::cout << stringBASIC << "\n";
	std::cout << *stringPTR << "\n";
	std::cout << stringREF << "\n";
}
