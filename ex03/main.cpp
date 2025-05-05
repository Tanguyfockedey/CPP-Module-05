/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:55:28 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/05 21:03:07 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main(void)
{
	Intern alice;
	AForm *form;

	try
	{
		form = alice.makeForm("RobotomyRequestForm", "Blender");
		delete form;
		form = alice.makeForm("ShrubberyCreationForm", "Yard");
		delete form;
		form = alice.makeForm("Ice", "rain");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
