/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:37:45 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/05 17:48:03 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int			_grade;

	public:
		/* Constr */
		Bureaucrat();
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat &copy);

		/* Destr */
		~Bureaucrat();

		/* Operator overload */
		Bureaucrat &operator=(const Bureaucrat &copy);

		/* Member functions */
		std::string	getName() const;
		int			getGrade() const;
		
		void		incGrade();
		void		decGrade();
		void		signForm(AForm &form);
		void		executeForm(const AForm &form);

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

std::ostream &operator<<(std::ostream &str, Bureaucrat const &bureaucrat);
