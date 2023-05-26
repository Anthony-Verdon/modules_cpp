/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:39:24 by averdon           #+#    #+#             */
/*   Updated: 2023/03/09 15:54:34 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){
}

Intern::~Intern(){
}

Intern::Intern(const Intern &copy){
	(void)copy;
}

Intern & Intern::operator=(const Intern &copy){
	if (&copy != this)
	{

	}
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string formName[NB_FORM] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm		*formInstance[NB_FORM] = {new PresidentialPardonForm(name), new RobotomyRequestForm(name), new ShrubberyCreationForm(name)};
	for (int i = 0; i < NB_FORM; i++)
	{
		if (formName[i] == name)
		{
			std::cout << "Intern creates " << formName[i] << "\n";
			for (int j = i + 1; j < NB_FORM; j++)
				delete formInstance[j];
			formInstance[i]->setTarget(target);
			return (formInstance[i]) ;
		}
		else
			delete formInstance[i];
	}
	std::cout << name << " form doesn't exist.\n";
	return (NULL);
}
