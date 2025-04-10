/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:26:04 by tafocked          #+#    #+#             */
/*   Updated: 2025/04/10 15:32:53 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():
	_name("Default"), _signed(false), _gradeSign(1), _gradeExec(150)
{
	std::cout << "Forn constructor called" << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec):
	_name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw (GradeTooHighException());
	if (gradeSign > 150 || gradeExec > 150)
		throw (GradeTooLowException());
	std::cout << "Form constructor called" << std::endl;
}

Form::Form( const Form &copy):
	_name(copy._name), _signed(copy._signed),
	_gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
{
	std::cout << "Form copy called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(const Form &copy)
{
	this->_signed = copy._signed;
	std::cout << "Assignment operator called" << std::endl;
	return (*this);
}

const std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeSign() const
{
	return (_gradeSign);
}

int Form::getGradeExec() const
{
	return (_gradeExec);
}

void Form::beSigned(Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw (GradeTooLowException());
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &str, const Form &form)
{
	return (str << form.getName() <<
		" | GradeSign : " << form.getGradeSign() <<
		" | GradeExec : " << form.getGradeExec() <<
		" | Signed : " << form.getSigned());
}
