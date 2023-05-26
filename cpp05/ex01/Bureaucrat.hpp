/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:24:22 by averdon           #+#    #+#             */
/*   Updated: 2023/03/08 16:38:56 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Form.hpp"
#include <exception>
#include <iostream>

class Form;

class Bureaucrat
{
	 public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat (const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat& instance);

		class GradeTooLow : public std::exception
		{
			const char *what(void) const throw();
		};
		class GradeTooHigh : public std::exception
		{
			const char *what(void) const throw();
		};
		
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form & instance);
		const std::string & getName() const;
		const int & 		getGrade() const ;
	 private:
		const std::string	_name;
		int					_grade;
};

std::ostream & operator << (std::ostream & os, const Bureaucrat & instance);
#endif
