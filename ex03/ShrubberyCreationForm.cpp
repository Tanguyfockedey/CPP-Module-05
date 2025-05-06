/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:06:10 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/06 23:18:17 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm::AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target):
	AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):
	AForm::AForm(copy), _target(copy._target)
{
	std::cout << "ShrubberyCreationForm copy called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	std::cout << "Shrubbery assignment called" << std::endl;
	return (*this);
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::beExecuted(const Bureaucrat &executor) const
{
	std::ofstream file;

	file.open((this->_target + "_shrubbery").c_str());
	file << TREE;
	file.close();
	std::cout << executor.getName() << " created a shrubbery tree !" << std::endl;
}

AForm *ShrubberyCreationForm::makeForm(AForm *form, const std::string &type, const std::string &target)
{
	if (form == NULL && type == "ShrubberyCreationForm")
		return (new ShrubberyCreationForm(target));
	return (form);
}
