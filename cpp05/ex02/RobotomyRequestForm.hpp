/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:06:27 by averdon           #+#    #+#             */
/*   Updated: 2023/03/09 15:22:51 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	 public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm (const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm&);
		
		void	execute(Bureaucrat const & executor);
	 private:
		
};

#endif
