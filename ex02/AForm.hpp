/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:26:06 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/05 22:21:25 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExec;

	public:
		/* Constr */
		AForm();
		AForm(std::string name, int gradeSign, int gradeExec);
		AForm(const AForm &copy);

		/* Destr */
		virtual ~AForm();

		/* Operator overload */
		AForm &operator=(const AForm &copy);

		/* Member functions */
		const std::string	getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;

		void execute(const Bureaucrat &executor) const;
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void beExecuted(const Bureaucrat &executor) const = 0;

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

		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &str, AForm const &form);
