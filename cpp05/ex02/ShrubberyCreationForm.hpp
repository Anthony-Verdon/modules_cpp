/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:06:12 by averdon           #+#    #+#             */
/*   Updated: 2023/03/09 15:26:58 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include"AForm.hpp"
class ShrubberyCreationForm : public AForm
{
	 public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm (const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm&);

		void	execute(Bureaucrat const & executor);
	 private:
		
};

#endif
