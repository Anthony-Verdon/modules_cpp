/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:06:07 by averdon           #+#    #+#             */
/*   Updated: 2023/03/09 15:29:23 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Unknown", 145, 137)
{
	this->setTarget("Unknown");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreation", 145, 137)
{
	this->setTarget(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToSign())
{
	this->setTarget(copy.getTarget());
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy){
	if (&copy != this)
	{
		this->~ShrubberyCreationForm();
		new (this) ShrubberyCreationForm(copy);
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
		if (this->getSigned() == false)
			throw (NotSign());
		else if (this->getGradeToExec() < executor.getGrade())
			throw (Bureaucrat::GradeTooHigh());
		else
		{
			std::string filename;
			filename = this->getTarget();
			filename.append("_shrubbery");
			std::ofstream	outfile(filename.c_str());
			if (outfile.is_open())
			{
				outfile << "   *   \n  ***  \n ***** \n*******\n  ***  \n  ***  \n  ***  \n";
				outfile << "   *   \n  ***  \n ***** \n*******\n  ***  \n  ***  \n  ***  \n";
				outfile << "   *   \n  ***  \n ***** \n*******\n  ***  \n  ***  \n  ***  \n";
				outfile.close();
			}

		}
}
