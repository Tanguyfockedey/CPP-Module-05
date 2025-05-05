/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:49:11 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/05 21:49:30 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;

class Intern
{
	public:
		/* constr */
		Intern();
		Intern(const Intern &copy);

		/* destr */
		~Intern();

		/* overload */
		Intern &operator=(const Intern &copy);

		/* memebers */
		AForm *makeForm(const std::string &type, const std::string &target);
};
