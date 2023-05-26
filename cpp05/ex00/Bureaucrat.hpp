/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:24:22 by averdon           #+#    #+#             */
/*   Updated: 2023/03/08 15:01:12 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <iostream>

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
		const std::string & getName() const;
		const int & 		getGrade() const ;
	 private:
		const std::string	_name;
		int					_grade;
};

std::ostream & operator << (std::ostream & os, const Bureaucrat & instance);
#endif
