/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:59:08 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/05 18:42:56 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

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
	std::cout << "RobotomyRequestFrom copy called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	std::cout << "Robotomy assignment called" << std::endl;
	return (*this);
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
