/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:05:51 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/05 15:53:53 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include "AForm.hpp"
#define TREE "    A\n   ###\n  #####\n #######\n#########\n    H\n    H"

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
		void beExecuted(Bureaucrat const &bureaucrat) const;
};
