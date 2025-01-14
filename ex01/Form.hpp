/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:26:06 by tafocked          #+#    #+#             */
/*   Updated: 2025/01/14 19:42:58 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;

	public:
		/* Constr */
		Form();
		Form(std::string name, int gradeSign, int gradeExec);
		Form(const Form &copy);

		/* Destr */
		~Form();

		/* Operator overload */
		Form &operator=(const Form &copy);

		/* Member functions */
		const std::string	getName() const;
		bool	getSigned() const;
		int	getGradeSign() const;
		int getGradeExec() const;
		void beSigned(Bureaucrat &Bureaucrat);

		/* Exceptions */
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &str, Form const &form);
