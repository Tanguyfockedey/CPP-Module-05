/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:58:55 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/05 16:48:48 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <time.h>
#include <stdlib.h>

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		
	public:
		/* constr */
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);

		/* destr */
		~RobotomyRequestForm();

		/* overload */
		RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

		/* members */
		void beExecuted(Bureaucrat const &Bureaucrat) const;
};
