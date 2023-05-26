/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:06:33 by averdon           #+#    #+#             */
/*   Updated: 2023/03/09 15:28:39 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Unknown", 72, 45)
{
	this->setTarget("Unknown");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45)
{
	this->setTarget(target);
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec()){
	this->setTarget(copy.getTarget());
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &copy){
	if (&copy != this)
	{
		this->~RobotomyRequestForm();
		new (this) RobotomyRequestForm(copy);
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	static int i = 0;
	if (this->getSigned() == false)
		throw (NotSign());
	else if (this->getGradeToExec() < executor.getGrade())
		throw (Bureaucrat::GradeTooHigh());
	else
	{
		i++;
		if (i % 2 == 1)
			std::cout << this->getTarget() << " has been robotomised.\n";
		else
			std::cout << "the robotomisation has failed.\n";
	}
}
