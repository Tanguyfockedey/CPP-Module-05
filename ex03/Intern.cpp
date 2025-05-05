/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:49:14 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/05 22:00:34 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern called" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
	std::cout << "Intern copy called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

AForm *Intern::makeForm(const std::string &type, const std::string &target)
{
	AForm *form;

	form = AForm::makeForm(type, target);
	if (!form)
		throw (AForm::InvalidFormException());
	else
		std::cout << "Intern creates form: " << form->getName() << " with target: " << form->getTarget() << std::endl;
	return (form);
}
