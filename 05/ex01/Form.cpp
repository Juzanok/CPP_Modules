/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:02:20 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/06 13:39:11 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): name(""), isSigned(false), signGrade(150), execGrade(150) { check_grade(); }
Form::Form(const Form &copy): name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), execGrade(copy.execGrade) { check_grade(); }
Form::Form(const std::string &name, int signgrade, int execgrade): name(name), isSigned(false), signGrade(signgrade), execGrade(execgrade) { check_grade(); }
Form::~Form(void) { }

Form	&Form::operator=(const Form &copy) {
	this->isSigned = copy.getIsSigned();
	return (*this);
}

bool	Form::beSigned(const Bureaucrat &bueraucrat) {
	if (bueraucrat.getGrade() <= this->signGrade && !isSigned){
		isSigned = true;
		return (true);
	}
	if (bueraucrat.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	return (false);
}

void	Form::check_grade(void) {
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

const std::string&	Form::getName(void) const {
	return (this->name);
}

int	Form::getSignGrade(void) const {
	return (this->signGrade);
}

int	Form::getExecGrade(void) const {
	return (this->execGrade);
}

bool	Form::getIsSigned(void) const {
	return (this->isSigned);
}

std::ostream& operator<<(std::ostream & stream, const Form& form) {
	stream << CYAN << "Form: " << form.getName() << " | isSigned: " << form.getIsSigned() << " | signGrade: " << form.getSignGrade() << " | execGrade: " << form.getExecGrade() << RESET << std::endl;
	return (stream);
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Form::GradeTooHighException : The grade you set is too high");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Form::GradeTooLowException : The grade you set is too low");
}