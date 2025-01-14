/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:37:45 by tafocked          #+#    #+#             */
/*   Updated: 2025/01/14 19:41:42 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Bureaucrat
{
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

		/* Exceptions */
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string	_name;
		int			_grade;
};

std::ostream &operator<<(std::ostream &str, Bureaucrat const &bureaucrat);
