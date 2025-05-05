/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 14:55:28 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/05 17:37:17 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	/* Test Shrubbery */
	{
		try
		{
			Bureaucrat Alice("Alice", 130);
			std::cout << Alice << std::endl;
			ShrubberyCreationForm form("garden");
			std::cout << form << std::endl;
			Alice.signForm(form);
			std::cout << form << std::endl;
			form.execute(Alice);

		}
		catch(std::exception &e)
		{
			std::cout << std::endl;
			std::cerr << e.what() << std::endl;
		}
	}
			std::cout << std::endl;
			std::cout << std::endl;

	/* Test Robotomy*/
	{
		try
		{
			Bureaucrat Bob("Bob", 40);
			std::cout << Bob << std::endl;
			RobotomyRequestForm form("machine");
			std::cout << form << std::endl;
			Bob.signForm(form);
			form.execute(Bob);
		}
		catch(const std::exception& e)
		{
			std::cout << std::endl;
			std::cerr << e.what() << '\n';
		}	
	}
			std::cout << std::endl;
			std::cout << std::endl;

	/* test Presidential */
	{
		try
		{
			Bureaucrat Alice("Alice", 1);
			Bureaucrat Bob("Bob", 20);
			PresidentialPardonForm form;
			Bob.executeForm(form);
			Bob.signForm(form);
			Bob.executeForm(form);
			form.execute(Alice);
		}
		catch(const std::exception& e)
		{
			std::cout << std::endl;
			std::cerr << e.what() << '\n';
		}
		
	}
}
