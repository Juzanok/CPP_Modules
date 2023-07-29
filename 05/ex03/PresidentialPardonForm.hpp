/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarosas <jkarosas@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:50:14 by jkarosas          #+#    #+#             */
/*   Updated: 2022/11/03 00:09:10 by jkarosas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm: public Form {
private:
	std::string target;

public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	~PresidentialPardonForm(void);

	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

	const std::string &getTarget(void) const;
	virtual bool execute(Bureaucrat const & executor) const;
};

#endif