/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:56:27 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/07 15:31:27 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):
Form("RobotomyRequestForm", 72, 45), target("") {srand(time(0)); }

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
Form("RobotomyRequestForm", 72, 45), target(target) { srand(time(0)); }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):
Form("RobotomyRequestForm", 72, 45), target(copy.getTarget()) { srand(time(0)); }

RobotomyRequestForm::~RobotomyRequestForm(void) { }

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	this->target = copy.getTarget();
	return (*this);
}

const std::string &RobotomyRequestForm::getTarget(void) const {
	return (this->target);
}

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (check_exec(executor)) {
		std::cout << "* Loud drilling noises *" << std::endl;
		if (rand() % 2)
			std::cout << target << " has been robotomized successfully" << std::endl;
		else 
			std::cout << "The robotomy on " << target << " has failed" << std::endl;
		return (true);
	}
	return (false);
}