/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:41:20 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/03 14:01:49 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) { }
Intern::~Intern(void) { }

Intern::Intern(const Intern &copy) {
	*this = copy;
}

Intern &Intern::operator=(const Intern &copy) {
	(void)copy;
	return (*this);
}

Form*	Intern::makeForm(const std::string &form, const std::string &target) {

	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	Form* (Intern::*formFunctions[3]) (const std::string &target) = {&Intern::makeSC, &Intern::makeRR, &Intern::makePP};

	for(int i = 0; i < 3; i++) {
		if (form == formNames[i]) {
			std::cout << "Intern creates " << form << std::endl;
			return ( (this->*formFunctions[i])(target) );
		}
	}
	std::cout << "Form : " << form << ", doesn't match any possible forms" << std::endl;
	std::cout << "Try  : shrubbery creation, robotomy request, presidential pardon" << std::endl;
	return (NULL);
}

Form*	Intern::makeSC(const std::string &target) {
	return (new ShrubberyCreationForm(target));
}

Form*	Intern::makeRR(const std::string &target) {
	return (new RobotomyRequestForm(target));
}

Form*	Intern::makePP(const std::string &target){
	return (new PresidentialPardonForm(target));
}
