/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:56:08 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/03 13:21:49 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):
Form("PresidentialPardonForm", 25, 5), target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
Form("PresidentialPardonForm", 25, 5), target(target) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):
Form("PresidentialPardonForm", 25, 5), target(copy.getTarget()) { }

PresidentialPardonForm::~PresidentialPardonForm(void) { }

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	this->target = copy.getTarget();
	return (*this);
}

const std::string &PresidentialPardonForm::getTarget(void) const {
	return (this->target);
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (check_exec(executor)) {
		std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		return (true);
	}
	return (false);
}