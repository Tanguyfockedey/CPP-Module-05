/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:08:03 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/07 15:16:21 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm::AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
	AForm::AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm called" <<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):
	AForm::AForm(copy), _target(copy._target)
{
	std::cout << "PresidentialPardonForm copy called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	std::cout << "Presidential assignment called" << std::endl;
	return (*this);
}

const std::string &PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::beExecuted(const Bureaucrat &executor) const
{
	(void)executor;
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox !" << std::endl;
}

AForm *PresidentialPardonForm::makeForm(AForm *form, const std::string &type, const std::string &target)
{
	if (form == NULL && type == "PresidentialPardonForm")
		return (new PresidentialPardonForm(target));
	return (form);
}
