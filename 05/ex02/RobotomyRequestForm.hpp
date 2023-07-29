/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:54:30 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/07 13:56:51 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include <time.h>
# include "Form.hpp"

class RobotomyRequestForm: public Form {
private:
	std::string target;

public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	~RobotomyRequestForm(void);

	RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

	const std::string &getTarget(void) const;
	virtual bool execute(const Bureaucrat &bureaucrat) const;

};

#endif