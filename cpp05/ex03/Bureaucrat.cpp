/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:24:19 by averdon           #+#    #+#             */
/*   Updated: 2023/03/09 15:35:11 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
			
const char *Bureaucrat::GradeTooLow::what(void) const throw()
{
	return ("Bureaucrat::GradeTooLowException");
}
const char *Bureaucrat::GradeTooHigh::what(void) const throw()
{
	return ("Bureaucrat::GradeTooHighException");
}

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLow());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHigh());
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade){
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &copy){
	if (&copy != this)
	{
		this->~Bureaucrat();
		new (this) Bureaucrat(copy);
	}
	return (*this);
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLow());
	else
		this->_grade++;
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHigh());
	else
		this->_grade--;
}

void	Bureaucrat::signForm(AForm &instance)
{
	if (this->_grade <= instance.getGradeToSign() && instance.getSigned() == false)
		std::cout << this->_name << " signed " << instance.getName() << "\n";
	else
	{
		std::cout << this->_name << " couldn't sign " << instance.getName() << " because ";
		if (instance.getSigned() ==  true)
			std::cout << "is already signed\n";
		else	
			std::cout << "grade to sign it is to high\n";
	}
	instance.beSigned(*this);

}

void	Bureaucrat::executeForm(AForm &instance)
{
	if (instance.getGradeToExec() <= this->_grade)
		throw (Bureaucrat::GradeTooLow());
	else if (instance.getSigned() == false)
		throw (AForm::NotSign());
	else
	{
		std::cout << this->_name << " executed " << instance.getName() << "\n";
		instance.execute(*this);
	}
}

const std::string & Bureaucrat::getName(void) const
{
	return (this->_name);
}

const int & Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::ostream & operator << (std::ostream & os, const Bureaucrat & instance)
{
	std::cout << instance.getName() << ", bureaucrat grade " << instance.getGrade() << ".\n";
	return (os);
}
