/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:13:22 by tafocked          #+#    #+#             */
/*   Updated: 2025/01/14 19:22:25 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat alice ("Alice", 1);
		Bureaucrat alice2(alice);
		Bureaucrat alice3;
		alice3 = alice2;
		std::cout << alice << std::endl;
		std::cout << alice2 << std::endl;
		std::cout << alice3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "----\n\n";

	try
	{
		Bureaucrat alice("Alice", 1);
		std::cout << alice << std::endl;
		Bureaucrat bob("Bob", 151);
		std::cout << bob << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "----\n\n";

	try
	{
		Bureaucrat alice("Alice", 1);
		std::cout << alice << std::endl;
		alice.incGrade();
		Bureaucrat alice2(alice);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "----\n\n";
}
