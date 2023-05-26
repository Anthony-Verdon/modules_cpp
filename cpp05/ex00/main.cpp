/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:24:09 by averdon           #+#    #+#             */
/*   Updated: 2023/03/08 15:00:37 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try 
	{
		Bureaucrat a;
	}
	catch (const std::exception & e)
	{
		std::cout <<  e.what() << "\n";
	}
	try 
	{
		Bureaucrat b("Charles", 0);
	}
	catch (const std::exception & e)
	{
		std::cout <<  e.what() << "\n";
	}
	try
	{
		Bureaucrat c("Ezekiel", 1);
		for (int i = 0; i < 151; i++)
			c.decrementGrade();
	}
	catch (const std::exception & e)
	{
		std::cout <<  e.what() << "\n";
	}
	try
	{
		Bureaucrat a;
		Bureaucrat d("Bobby", 150);
		
		std::cout << d;
		d = a;
		std::cout << d;
		
		for (int i = 0; i < 150; i++)
			d.incrementGrade();
	}
	catch (const std::exception & e)
	{
		std::cout <<  e.what() << "\n";
	}
	try
	{
		Bureaucrat e("Hugo", 151);
	}
	catch (const std::exception & e)
	{
		std::cout <<  e.what() << "\n";
	}
	return (0);
}
