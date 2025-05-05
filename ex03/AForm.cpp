/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 19:26:04 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/05 18:35:09 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():
	_name("Default"), _signed(false), _gradeSign(1), _gradeExec(150)
{
	std::cout << "Forn constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec):
	_name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw (GradeTooHighException());
	if (gradeSign > 150 || gradeExec > 150)
		throw (GradeTooLowException());
	std::cout << "Form constructor called" << std::endl;
}

AForm::AForm( const AForm &copy):
	_name(copy._name), _signed(copy._signed),
	_gradeSign(copy._gradeSign), _gradeExec(copy._gradeExec)
{
	std::cout << "Form copy called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form destructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
	this->_signed = copy._signed;
	std::cout << "Assignment operator called" << std::endl;
	return (*this);
}

const std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeSign() const
{
	return (_gradeSign);
}

int AForm::getGradeExec() const
{
	return (_gradeExec);
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!_signed)
		throw (FormNotSignedException());
	else if(executor.getGrade() > _gradeExec)
		throw (GradeTooLowException());
	else
	{
		this->beExecuted(executor);
	}
}

void AForm::beSigned(const Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() <= _gradeSign)
		_signed = true;
	else
		throw (GradeTooLowException());
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed");
}

const char *AForm::InvalidFormException::what() const throw()
{
	return ("Form is invalid");
}

std::ostream &operator<<(std::ostream &str, const AForm &form)
{
	return (str << form.getName() <<
		" | GradeSign : " << form.getGradeSign() <<
		" | GradeExec : " << form.getGradeExec() <<
		" | Signed : " << form.getSigned());
}
