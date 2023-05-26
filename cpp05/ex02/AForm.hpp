/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:57:14 by averdon           #+#    #+#             */
/*   Updated: 2023/03/09 15:10:56 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class AForm
{
	 public:
		AForm();
		AForm(std::string name, int gradeSign, int gradeExec);
		virtual	~AForm();
		AForm (const AForm &copy);
		AForm &operator=(const AForm& instance);

		class GradeTooLow : public std::exception
		{
			const char *what(void) const throw();
		};
		class GradeTooHigh : public std::exception
		{
			const char *what(void) const throw();
		};
		class NotSign : public std::exception
		{
			const char *what(void) const throw();
		};

		const std::string	getName() const;
		const std::string	getTarget() const;
		bool 				getSigned() const;
		int 				getGradeToSign() const;
		int				 	getGradeToExec() const;
		void				setTarget(std::string new_target);
		void				setSign(bool sign);
		void				beSigned(Bureaucrat& instance);
		virtual void		execute(Bureaucrat const & executor) = 0;
	 private:
		const std::string	_name;
		std::string			_target;
		bool				_isSigned;
		const int					_gradeToSign;
		const int					_gradeToExec;
		
};

std::ostream & operator << (std::ostream & os, const AForm & instance);

#endif
