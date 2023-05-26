/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:57:14 by averdon           #+#    #+#             */
/*   Updated: 2023/03/08 16:36:58 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form
{
	 public:
		Form();
		Form(std::string name, int gradeSign, int gradeExec);
		~Form();
		Form (const Form &copy);
		Form &operator=(const Form& instance);

		class GradeTooLow : public std::exception
		{
			const char *what(void) const throw();
		};
		class GradeTooHigh : public std::exception
		{
			const char *what(void) const throw();
		};

		const std::string	getName() const;
		bool 				getSigned() const;
		int 				getGradeToSign() const;
		int				 	getGradeToExec() const;
		void				beSigned(Bureaucrat& instance);
	 private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExec;
		bool				_isSigned;
		
};

std::ostream & operator << (std::ostream & os, const Form & instance);

#endif
