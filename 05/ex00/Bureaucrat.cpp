/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:10:24 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/05 14:00:59 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name(""), grade(150) { check_grade(); }
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade) { check_grade(); }
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade) { check_grade(); }
Bureaucrat::~Bureaucrat(void) { }

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy) {
	this->grade = copy.getGrade();
	check_grade();
	return (*this);
}

void	Bureaucrat::incrementGrade(int amount) {
	grade -= amount;
	check_grade();
}

void	Bureaucrat::decrementGrade(int amount) {
	grade += amount;
	check_grade();
}

void Bureaucrat::check_grade(void) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const std::string&	Bureaucrat::getName(void) const {
	return (this->name);
}

int	Bureaucrat::getGrade(void) const {
	return (this->grade);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat::GradeTooHighException : The grade you set is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat::GradeTooLowException : The grade you set is too low");
}

std::ostream& operator<<(std::ostream & stream, const Bureaucrat& bureaucrat) {
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() <<  std::endl;
	return (stream);
}
