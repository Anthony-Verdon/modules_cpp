/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:24:09 by averdon           #+#    #+#             */
/*   Updated: 2023/03/08 17:34:12 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	{
		std::cout << "[TEST EX00]\n";
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
			for (int i = 0; i < 150; i++)
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
	}
	{
		std::cout << "\n[TEST EX01]\n\n[EXCEPTION]\n";
		try
		{
			Form f1("boup boup", 151, 100);
		}
		catch (const std::exception & e)
		{
			std::cout <<  e.what() << "\n";
		}
		try
		{
			Form f2("puob puob", 100, 0);
		}
		catch (const std::exception & e)
		{
			std::cout <<  e.what() << "\n";
		}
		try
		{
			Form f3("boup boup", 100, 151);
		}
		catch (const std::exception & e)
		{
			std::cout <<  e.what() << "\n";
		}
		try
		{
			Form f4("puob puob", 0, 100);
		}
		catch (const std::exception & e)
		{
			std::cout <<  e.what() << "\n";
		}
		try
		{
			Form f5("boup boup", 151, 151);
		}
		catch (const std::exception & e)
		{
			std::cout <<  e.what() << "\n";
		}
		try
		{
			Form f6("puob puob", 0, 0);
		}
		catch (const std::exception & e)
		{
			std::cout <<  e.what() << "\n";
		}
		std::cout << std::endl;
	}
	{
		std::cout << "[SIGN FORM]\n";
		try
		{
			Form f1("Blabla", 1, 1);
			Form f2("beep beep", 100, 100);
			Bureaucrat b1("Bobby", 1);
			try
			{
				b1.signForm(f1);
			}
			catch (const std::exception & e)
			{
				std::cout <<  e.what() << "\n";
			}
			try
			{
				b1.signForm(f2);
			}
			catch (const std::exception & e)
			{
				std::cout <<  e.what() << "\n";
			}
			try
			{
				b1.signForm(f2);
			}
			catch (const std::exception & e)
			{
				std::cout <<  e.what() << "\n";
			}
			try
			{
				Form f3 = f1;
				Form f4(f2);
				std::cout << f3 << f4;
			}
			catch (const std::exception & e)
			{
				std::cout <<  e.what() << "\n";
			}
		}
		catch (const std::exception & e)
		{
			std::cout <<  e.what() << "\n";
		}

		std::cout << std::endl;
	}
	return (0);
}
