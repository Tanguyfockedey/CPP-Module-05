/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:07:50 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/05 17:11:35 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;

	public:
		/* Constr */
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);

		/* destr */
		~PresidentialPardonForm();

		/* overload */
		PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

		/* members */
		void beExecuted(Bureaucrat const &Bureaucrat) const;
};
