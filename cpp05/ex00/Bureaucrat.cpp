/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:24:19 by averdon           #+#    #+#             */
/*   Updated: 2023/03/08 14:56:08 by averdon          ###   ########.fr       */
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

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade){ 
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
	os << instance.getName() << ", bureaucrat grade " << instance.getGrade() << ".\n";
	return (os);
}
