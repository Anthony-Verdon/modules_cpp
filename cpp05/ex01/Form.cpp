/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:57:08 by averdon           #+#    #+#             */
/*   Updated: 2023/03/08 16:36:50 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
			
const char *Form::GradeTooLow::what(void) const throw()
{
	return ("Form::GradeTooLowException");
}

const char *Form::GradeTooHigh::what(void) const throw()
{
	return ("Form::GradeTooHighException");
}

Form::Form(): _name("Unknown"), _gradeToSign(1), _gradeToExec(1){
	this->_isSigned = false;
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeToSign(gradeSign), _gradeToExec(gradeExec){
	
	if (gradeSign > 150 || gradeExec > 150)
		throw (Form::GradeTooLow());
	else if (gradeSign < 1 || gradeExec < 1)
		throw (Form::GradeTooHigh());
	else
		this->_isSigned = false;
}

Form::~Form(){
}

Form::Form(const Form &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec){
	this->_isSigned = copy._isSigned;
}

Form & Form::operator=(const Form &copy){
	if (&copy != this)
	{
		this->~Form();
		new (this) Form(copy);
	}
	return (*this);
}


void	Form::beSigned(Bureaucrat& instance)
{
	if (instance.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
		throw (Form::GradeTooLow());
}

const std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_isSigned);
}

int	Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

std::ostream & operator << (std::ostream & os, const Form & instance)
{
	os << "Form " << instance.getName() << ", ";
	if (instance.getSigned() == true)
		os << "signed, ";
	else
		os << " not signed, ";
	os << "require a grade " << instance.getGradeToSign() << " to be signed and a grade " << instance.getGradeToExec() << " to be executed\n"; 
	return (os);
}
