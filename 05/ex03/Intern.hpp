/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:26:36 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/03 13:50:17 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
private:
	Form*	makeSC(const std::string &target);
	Form*	makeRR(const std::string &target);
	Form*	makePP(const std::string &target);

public:

	Intern(void);
	Intern(const Intern &copy);
	~Intern(void);

	Intern	&operator=(const Intern &copy);

	Form *makeForm(const std::string &form, const std::string &target);
};

#endif