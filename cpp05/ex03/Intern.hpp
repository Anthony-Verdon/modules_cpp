/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:39:28 by averdon           #+#    #+#             */
/*   Updated: 2023/03/09 15:48:28 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	 public:
		Intern();
		~Intern();
		Intern (const Intern &copy);
		Intern &operator=(const Intern&);

		AForm *makeForm(std::string name, std::string target);
	 private:
		
};

#endif
