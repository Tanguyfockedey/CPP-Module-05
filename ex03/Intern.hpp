/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:49:11 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/05 18:08:41 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

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
