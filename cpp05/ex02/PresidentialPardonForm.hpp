/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:06:51 by averdon           #+#    #+#             */
/*   Updated: 2023/03/09 15:11:33 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	 public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm (const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm&);
		
		void	execute(Bureaucrat const & executor);
	 private:
		
};

#endif
