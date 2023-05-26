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
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
	{
	Intern someRandomIntern;
	AForm* rrf;
	try
	{
		Bureaucrat bureaucrat = Bureaucrat("Bureaucrat", 1);
		rrf = someRandomIntern.makeForm("attack", "Bender");
		if (rrf)
		{
			try
			{
				bureaucrat.signForm(*rrf);
				bureaucrat.executeForm(*rrf);
			}
			catch (std::exception & e)
			{
				std::cout << e.what() << "\n";
			}
			delete rrf;
		}
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			RobotomyRequestForm test;
			RobotomyRequestForm test2(test);
			test = test2;
			try
			{
				bureaucrat.signForm(*rrf);
				bureaucrat.executeForm(*rrf);
			}
			catch (std::exception & e)
			{
				std::cout << e.what() << "\n";
			}
			delete rrf;
		}
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		if (rrf)
		{
			try
			{
				bureaucrat.signForm(*rrf);
				bureaucrat.executeForm(*rrf);
			}
			catch (std::exception & e)
			{
				std::cout << e.what() << "\n";
			}
			delete rrf;
		}
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
		if (rrf)
		{
			try
			{
				bureaucrat.signForm(*rrf);
				bureaucrat.executeForm(*rrf);
			}
			catch (std::exception & e)
			{
				std::cout << e.what() << "\n";
			}
			delete rrf;
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << "\n";
	}
	return (0);
}
