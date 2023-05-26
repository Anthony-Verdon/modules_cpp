/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:57:08 by averdon           #+#    #+#             */
/*   Updated: 2023/03/09 15:10:35 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char *AForm::GradeTooLow::what(void) const throw()
{
	return ("Form::GradeTooLowException");
}
const char *AForm::GradeTooHigh::what(void) const throw()
{
	return ("Form::GradeTooHighException");
}
const char *AForm::NotSign::what(void) const throw()
{
	return ("Form::NotSignException");
}

AForm::AForm(): _name("Unknown"), _gradeToSign(1), _gradeToExec(1){
	this->_isSigned = false;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeToSign(gradeSign), _gradeToExec(gradeExec){
	
	if (gradeSign > 150 || gradeExec > 150)
		throw (AForm::GradeTooLow());
	else if (gradeSign < 1 || gradeExec < 1)
		throw (AForm::GradeTooHigh());
	else
	{
		this->_isSigned = false;
	}
}

AForm::~AForm(){
}

AForm::AForm(const AForm &copy) : _name(copy._name), _target(copy._target), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec){
}

AForm & AForm::operator=(const AForm &copy){
	if (&copy != this)
	{
	}
	return (*this);
}


void	AForm::beSigned(Bureaucrat& instance)
{
	if (instance.getGrade() < this->_gradeToSign)
		this->_isSigned = true;
	else
		throw (AForm::GradeTooHigh());
}

const std::string AForm::getTarget() const
{
	return (this->_target);
}

const std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_isSigned);
}

int	AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}

void	AForm::setTarget(std::string new_target)
{
	this->_target = new_target;
}
void	AForm::setSign(bool new_sign)
{
	this->_isSigned = new_sign;
}

std::ostream & operator << (std::ostream & os, const AForm & instance)
{
	std::cout << "Form " << instance.getName() << ", ";
	if (instance.getSigned() == true)
		std::cout << "signed, ";
	else
		std::cout << " not signed, ";
	std::cout << "require a grade " << instance.getGradeToSign() << " to be signed and a grade " << instance.getGradeToExec() << " to be executed\n"; 
	return (os);
}
