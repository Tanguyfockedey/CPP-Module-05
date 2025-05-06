/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:26:06 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/06 20:59:33 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

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
		virtual const std::string &getTarget() const = 0;

		void execute(const Bureaucrat &executor) const;
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void beExecuted(const Bureaucrat &executor) const = 0;
		static AForm *makeForm(const std::string &type, const std::string &target);

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

		class InvalidFormException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &str, AForm const &form);
