/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:05:51 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/05 22:04:47 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>
#define TREE "    A\n   ###\n  #####\n #######\n#########\n    H\n    H"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		/* const */
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);

		/* destr */
		~ShrubberyCreationForm();

		/* overload */
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

		/* members */
		const std::string &getTarget() const;
		void beExecuted(Bureaucrat const &executor) const;
		static AForm *makeForm(AForm *form, const std::string &type, const std::string &target);
};
