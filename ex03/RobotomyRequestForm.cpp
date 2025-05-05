/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:59:08 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/05 22:04:25 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm():
	AForm::AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
	AForm::AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):
	AForm::AForm(copy), _target(copy._target)
{
	std::cout << "RobotomyRequestForm copy called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestFrom destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	std::cout << "Robotomy assignment called" << std::endl;
	return (*this);
}

const std::string &RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::beExecuted(const Bureaucrat &executor) const
{
	srand(time(0));
	std::cout << "Drilling noises ... ";
	if (rand() % 2)
		std::cout << _target << " has been robotomized by " << executor.getName() << std::endl;
	else
		std::cout << _target << " has NOT been robotomized !" << std::endl;
}

AForm *RobotomyRequestForm::makeForm(AForm *form, const std::string &type, const std::string &target)
{
	if (form == NULL && type == "RobotomyRequestForm")
		return (new RobotomyRequestForm(target));
	return (form);
}
