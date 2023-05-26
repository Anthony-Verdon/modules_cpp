/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:24:09 by averdon           #+#    #+#             */
/*   Updated: 2023/03/09 15:29:30 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
		std::cout << "[EX02]\n";
		try
		{
			Bureaucrat one("one", 1);
			AForm *FormS = new ShrubberyCreationForm("Target1");
			AForm *FormR = new RobotomyRequestForm("Target1");
			AForm *FormP = new PresidentialPardonForm("Target1");
			try
			{
				one.signForm(*FormS);
				one.executeForm(*FormS);
			}
			catch (const std::exception & e)
			{
				std::cout <<  e.what() << "\n";
			}
			try
			{
				one.signForm(*FormR);
				one.executeForm(*FormR);
			}
			catch (const std::exception & e)
			{
				std::cout <<  e.what() << "\n";
			}
			try
			{
				one.signForm(*FormP);
				one.executeForm(*FormP);
			}
			catch (const std::exception & e)
			{
				std::cout <<  e.what() << "\n";
			}
			delete FormP;
			delete FormR;
			delete FormS;
			std::cout << "\n";
		}
		catch (const std::exception & e)
		{
			std::cout <<  e.what() << "\n";
		}
	}
	{
		try
		{
			Bureaucrat two("two", 75);

			AForm *FormS = new ShrubberyCreationForm("Target2");
			AForm *FormR = new RobotomyRequestForm("Target2");
			AForm *FormP = new PresidentialPardonForm("Target2");
			try
			{
				two.signForm(*FormS);
				two.executeForm(*FormS);
			}
			catch (const std::exception & e)
			{
				std::cout <<  e.what() << "\n";
			}
			try
			{
				two.signForm(*FormR);
				two.executeForm(*FormR);
			}
			catch (const std::exception & e)
			{
				std::cout <<  e.what() << "\n";
			}
			try
			{
				two.signForm(*FormP);
				two.executeForm(*FormP);
			}
			catch (const std::exception & e)
			{
				std::cout <<  e.what() << "\n";
			}
			delete FormP;
			delete FormR;
			delete FormS;
			std::cout << "\n";
		}
		catch (const std::exception & e)
		{
			std::cout <<  e.what() << "\n";
		}
	}
	{
		try
		{
			Bureaucrat three("three", 150);

			AForm *FormS = new ShrubberyCreationForm("Target3");
			AForm *FormR = new RobotomyRequestForm("Target3");
			AForm *FormP = new PresidentialPardonForm("Target3");
			try
			{
				three.signForm(*FormS);
				three.executeForm(*FormS);
			}
			catch (const std::exception & e)
			{
				std::cout <<  e.what() << "\n";
			}
			try
			{
				three.signForm(*FormR);
				three.executeForm(*FormR);
			}
			catch (const std::exception & e)
			{
				std::cout <<  e.what() << "\n";
			}
			try
			{
				three.signForm(*FormP);
				three.executeForm(*FormP);
			}
			catch (const std::exception & e)
			{
				std::cout <<  e.what() << "\n";
			}
			delete FormP;
			delete FormR;
			delete FormS;
			std::cout << "\n";
		}
		catch (const std::exception & e)
		{
			std::cout <<  e.what() << "\n";
		}
	}
	return (0);
}
