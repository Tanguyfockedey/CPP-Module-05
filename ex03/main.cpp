/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:55:28 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/07 15:15:22 by tafocked         ###   ########.fr       */
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

	std::cout << "---------" << std::endl;
	
	try
	{
		form = alice.makeForm("RobotomyRequestForm", "Blender");
		delete form;
		std::cout << "---------" << std::endl;
		form = alice.makeForm("PresidentialPardonForm", "Beeble");
		delete form;
		std::cout << "---------" << std::endl;
		form = alice.makeForm("Ice", "rain");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
