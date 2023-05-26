/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:20:53 by averdon           #+#    #+#             */
/*   Updated: 2023/03/16 13:43:20 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <iostream>

void	function1(std::string &str)
{
	str = "NON"; 
}

void	test1(void)
{
	std::string	array[5] = {"Bonjour", "Salut", "Coucou", "Au revoir", "Bye"};
	iter(array, 5, function1);
	for (int i = 0; i < 5; i++)
		std::cout << array[i] << "\n";
}

void	function2(int &i)
{
	i = -1; 
}

void	test2(void)
{
	int	array[5] = {1, 2, 3, 4, 5};
	iter(array, 5, function2);
	for (int i = 0; i < 5; i++)
		std::cout << array[i] << "\n";
}

void	test3(void)
{
	int	array[5] = {1, 2, 3, 4, 5};
	iter(array, 6, function2);
	for (int i = 0; i < 5; i++)
		std::cout << array[i] << "\n";
}

void	test4(void)
{
	int	array[5] = {1, 2, 3, 4, 5};
	iter(array, -1, function2);
	for (int i = 0; i < 5; i++)
		std::cout << array[i] << "\n";
}

int	main(void)
{
	test1();
	test2();
	test3();
	test4();
	return (0);
}
