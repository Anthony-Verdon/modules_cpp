/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:06:47 by averdon           #+#    #+#             */
/*   Updated: 2023/03/09 15:23:28 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Unknown", 25, 5)
{
	this->setTarget("Unknown");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardon", 25, 5)
{
	this->setTarget(target);
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec())

{
	this->setSign(copy.getSigned());
	this->setTarget(copy.getTarget());
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &copy){
	if (&copy != this)
	{
		this->~PresidentialPardonForm();
		new (this) PresidentialPardonForm(copy);
	}
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor)
{
	if (this->getSigned() == false)
		throw (NotSign());
	else if (this->getGradeToExec() < executor.getGrade())
		throw (Bureaucrat::GradeTooHigh());
	else
		std::cout << this->getTarget() << " has been forvigen by Zaphod Beeblebrox.\n";
}
